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
#line 855 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 316 of lalr1.cc  */
#line 955 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"

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
        case 105: /* "\"'DECIMAL'\"" */

/* Line 479 of lalr1.cc  */
#line 853 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 479 of lalr1.cc  */
#line 328 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 118: /* "\"'DOUBLE'\"" */

/* Line 479 of lalr1.cc  */
#line 852 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 479 of lalr1.cc  */
#line 337 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 143: /* "\"'INTEGER'\"" */

/* Line 479 of lalr1.cc  */
#line 851 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 479 of lalr1.cc  */
#line 346 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "VersionDecl" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 355 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "MainModule" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 364 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "LibraryModule" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 373 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "ModuleDecl" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 382 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "SIND_DeclList" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 391 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "VFO_DeclList" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 400 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "SIND_Decl" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 409 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "VFO_Decl" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 418 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "DecimalFormatDecl" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 427 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "DecimalFormatParamList" */

/* Line 479 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 479 of lalr1.cc  */
#line 436 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "DecimalFormatParam" */

/* Line 479 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 479 of lalr1.cc  */
#line 445 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "Setter" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 454 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "Import" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 463 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "NamespaceDecl" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 472 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "BoundarySpaceDecl" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 481 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "DefaultNamespaceDecl" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 490 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "OptionDecl" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 499 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "FTOptionDecl" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 508 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "OrderingModeDecl" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 517 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "EmptyOrderDecl" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 526 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "CopyNamespacesDecl" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 535 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "DefaultCollationDecl" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 544 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "BaseURIDecl" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 553 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "SchemaImport" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 562 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "URILiteralList" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 571 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "SchemaPrefix" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 580 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "ModuleImport" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 589 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "CtxItemDecl" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 598 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "CtxItemDecl2" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 607 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "CtxItemDecl3" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 616 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "CtxItemDecl4" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 625 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "VarNameAndType" */

/* Line 479 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 479 of lalr1.cc  */
#line 634 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "VarDecl" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 643 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "DeclPropertyList" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 652 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "DeclProperty" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 661 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "CollectionDecl" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 670 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "NodeModifier" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 679 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "IndexDecl" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 688 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "IndexKeyList" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 697 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "IndexKeySpec" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 706 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "IntegrityConstraintDecl" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 715 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "ConstructionDecl" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 724 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "FunctionSig" */

/* Line 479 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 479 of lalr1.cc  */
#line 733 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "BlockExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 742 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "Block" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 751 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "BlockDecls" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 760 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "BlockVarDeclList" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 769 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "BlockVarDecl" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 778 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "AssignExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 787 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "ExitExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 796 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "WhileExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 805 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "FlowCtlStatement" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 814 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "FunctionDecl" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 823 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "FunctionDecl2" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 832 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FunctionDeclSimple" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 841 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "FunctionDeclSequential" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 850 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "FunctionDeclUpdating" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 859 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "ParamList" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 868 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "Param" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 877 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "EnclosedExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "BracedExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 895 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "QueryBody" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 904 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "Expr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "ApplyExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 922 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "ConcatExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 931 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "ExprSingle" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 940 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "FLWORExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 949 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "ReturnExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 958 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "FLWORWinCond" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 967 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "WindowClause" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 976 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "CountClause" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 985 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "ForLetWinClause" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 994 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "FLWORClauseList" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1003 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "ForClause" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1012 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "VarInDeclList" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1021 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "VarInDecl" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1030 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "PositionalVar" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1039 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "FTScoreVar" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1048 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "LetClause" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1057 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "VarGetsDeclList" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1066 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "EvalVarDeclList" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1075 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "VarGetsDecl" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1084 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "WindowVarDecl" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1093 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "WindowVars" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1102 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "WindowVars3" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1111 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "WindowVars2" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1120 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "EvalVarDecl" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1129 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "WhereClause" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1138 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "GroupByClause" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1147 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "GroupSpecList" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1156 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "GroupSpec" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1165 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "GroupCollationSpec" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1174 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "OrderByClause" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1183 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "OrderSpecList" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1192 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "OrderSpec" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1201 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "OrderModifier" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1210 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "OrderDirSpec" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1219 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "OrderEmptySpec" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1228 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "OrderCollationSpec" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1237 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "QuantifiedExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1246 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "QVarInDeclList" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1255 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "QVarInDecl" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1264 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "SwitchExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1273 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "SwitchCaseClauseList" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1282 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "SwitchCaseClause" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1291 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "SwitchCaseOperandList" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1300 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "TypeswitchExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1309 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "CaseClauseList" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1318 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "CaseClause" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1327 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "IfExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1336 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "OrExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1345 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "AndExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1354 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "ComparisonExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1363 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "FTContainsExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1372 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "opt_FTIgnoreOption" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1381 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "RangeExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1390 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "AdditiveExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1399 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "MultiplicativeExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1408 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "UnionExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1417 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "IntersectExceptExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1426 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "InstanceofExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1435 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "TreatExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1444 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "CastableExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1453 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "CastExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1462 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "UnaryExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1471 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "SignList" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1480 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "ValueExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1489 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "ValueComp" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1498 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "NodeComp" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1507 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "ValidateExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1516 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "ExtensionExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1525 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "Pragma_list" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1534 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "Pragma" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1543 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "PathExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1552 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "RelativePathExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1561 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "StepExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1570 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "AxisStep" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1579 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "ForwardStep" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1588 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "ForwardAxis" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1597 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "AbbrevForwardStep" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1606 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "ReverseStep" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1615 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "ReverseAxis" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1624 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "NodeTest" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1633 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "NameTest" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1642 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "Wildcard" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1651 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "FilterExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1660 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "PredicateList" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1669 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "Predicate" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1678 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "PrimaryExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1687 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "Literal" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1696 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "NumericLiteral" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1705 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "VarRef" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1714 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "ParenthesizedExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1723 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "ContextItemExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1732 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "OrderedExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1741 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "UnorderedExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1750 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "FunctionCall" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1759 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "ArgList" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1768 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "Constructor" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1777 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "DirectConstructor" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1786 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "DirElemConstructor" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1795 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "DirElemContentList" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1804 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "DirAttributeList" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1813 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "DirAttr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1822 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "DirAttributeValue" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1831 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "opt_QuoteAttrContentList" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1840 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "QuoteAttrContentList" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1849 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "opt_AposAttrContentList" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1858 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "AposAttrContentList" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1867 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "QuoteAttrValueContent" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1876 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "AposAttrValueContent" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1885 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "DirElemContent" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1894 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "CommonContent" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1903 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "DirCommentConstructor" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1912 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "DirPIConstructor" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1921 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "CDataSection" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1930 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "ComputedConstructor" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1939 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "CompDocConstructor" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1948 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "CompElemConstructor" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1957 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "CompAttrConstructor" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1966 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "CompTextConstructor" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1975 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "CompCommentConstructor" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1984 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "CompPIConstructor" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1993 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "SingleType" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2002 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "TypeDeclaration" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2011 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "SequenceType" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2020 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "OccurrenceIndicator" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2029 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "ItemType" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2038 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "TypeList" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2047 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "AtomicType" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2056 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "KindTest" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2065 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "AnyKindTest" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2074 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "DocumentTest" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2083 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "TextTest" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2092 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "CommentTest" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2101 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "PITest" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2110 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "AttributeTest" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2119 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "SchemaAttributeTest" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2128 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "ElementTest" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2137 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "SchemaElementTest" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2146 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "TypeName" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2155 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "TypeName_WITH_HOOK" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2164 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "StringLiteral" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2173 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "AnyFunctionTest" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2182 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "TypedFunctionTest" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2191 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "InsertExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2200 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "DeleteExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2209 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "ReplaceExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2218 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "RenameExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2227 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "TransformExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2236 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "VarNameList" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2245 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "VarNameDecl" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2254 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "TryExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2263 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "CatchListExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2272 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "CatchExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2281 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "NameTestList" */

/* Line 479 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 479 of lalr1.cc  */
#line 2290 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "EvalExpr" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2299 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "FTSelection" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2308 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "FTOr" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2317 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "FTAnd" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2326 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "FTMildNot" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2335 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "FTUnaryNot" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2344 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "FTPrimaryWithOptions" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2353 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "opt_FTMatchOptions" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2362 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "FTWeight" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2371 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "FTPrimary" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2380 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "opt_FTTimes" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2389 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "FTExtensionSelection" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2398 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "FTWords" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2407 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "FTWordsValue" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2416 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "FTAnyallOption" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2425 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "FTPosFilter" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2434 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "FTOrder" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2443 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "FTWindow" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2452 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "FTDistance" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2461 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "FTUnit" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2470 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "FTMatchOptions" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2479 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "FTMatchOption" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2488 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "FTCaseOption" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2497 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "FTDiacriticsOption" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2506 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTExtensionOption" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2515 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "FTStemOption" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2524 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTThesaurusOption" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2533 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "FTThesaurusID" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2542 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* "FTStopWordOption" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2551 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* "FTStopWords" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2560 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTStopWordsInclExcl" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2569 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTLanguageOption" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2578 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTWildCardOption" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2587 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTContent" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2596 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTTimes" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2605 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTRange" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2614 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTScope" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2623 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTBigUnit" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2632 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTIgnoreOption" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2641 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "QNAME" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2650 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FUNCTION_NAME" */

/* Line 479 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1014 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 4:

/* Line 677 of lalr1.cc  */
#line 1018 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.node) = NULL; }
    break;

  case 5:

/* Line 677 of lalr1.cc  */
#line 1019 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.node) = NULL; }
    break;

  case 6:

/* Line 677 of lalr1.cc  */
#line 1020 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.node) = NULL; }
    break;

  case 7:

/* Line 677 of lalr1.cc  */
#line 1021 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.node) = NULL; }
    break;

  case 8:

/* Line 677 of lalr1.cc  */
#line 1026 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1040 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 10:

/* Line 677 of lalr1.cc  */
#line 1045 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            MainModule *mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
            mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 11:

/* Line 677 of lalr1.cc  */
#line 1052 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 12:

/* Line 677 of lalr1.cc  */
#line 1057 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            LibraryModule *lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
            lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 13:

/* Line 677 of lalr1.cc  */
#line 1068 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            std::string encoding = "utf-8";
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), encoding );
        }
    break;

  case 14:

/* Line 677 of lalr1.cc  */
#line 1073 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
        }
    break;

  case 15:

/* Line 677 of lalr1.cc  */
#line 1081 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);
          (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
        }
    break;

  case 16:

/* Line 677 of lalr1.cc  */
#line 1086 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));
          (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
        }
    break;

  case 17:

/* Line 677 of lalr1.cc  */
#line 1091 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)), static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));
          (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
        }
    break;

  case 18:

/* Line 677 of lalr1.cc  */
#line 1096 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
        }
    break;

  case 19:

/* Line 677 of lalr1.cc  */
#line 1104 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
        }
    break;

  case 20:

/* Line 677 of lalr1.cc  */
#line 1108 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
        }
    break;

  case 21:

/* Line 677 of lalr1.cc  */
#line 1113 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
        }
    break;

  case 22:

/* Line 677 of lalr1.cc  */
#line 1118 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)), static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
        }
    break;

  case 23:

/* Line 677 of lalr1.cc  */
#line 1127 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
            dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
        }
    break;

  case 24:

/* Line 677 of lalr1.cc  */
#line 1136 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
            sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = sdl;
        }
    break;

  case 25:

/* Line 677 of lalr1.cc  */
#line 1142 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 26:

/* Line 677 of lalr1.cc  */
#line 1151 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
            vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = vdl;
        }
    break;

  case 27:

/* Line 677 of lalr1.cc  */
#line 1157 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 41:

/* Line 677 of lalr1.cc  */
#line 1188 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
          delete (yysemantic_stack_[(4) - (4)].vstrpair);
        }
    break;

  case 42:

/* Line 677 of lalr1.cc  */
#line 1193 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
          delete (yysemantic_stack_[(4) - (4)].vstrpair);
        }
    break;

  case 43:

/* Line 677 of lalr1.cc  */
#line 1202 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.vstrpair) = new vector<string_pair_t>();
          (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
          delete (yysemantic_stack_[(1) - (1)].strpair);
        }
    break;

  case 44:

/* Line 677 of lalr1.cc  */
#line 1208 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
          delete (yysemantic_stack_[(2) - (2)].strpair);
          (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
        }
    break;

  case 45:

/* Line 677 of lalr1.cc  */
#line 1217 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
            (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval() );
            delete sl;
        }
    break;

  case 46:

/* Line 677 of lalr1.cc  */
#line 1225 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 47:

/* Line 677 of lalr1.cc  */
#line 1226 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 48:

/* Line 677 of lalr1.cc  */
#line 1227 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 49:

/* Line 677 of lalr1.cc  */
#line 1228 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 50:

/* Line 677 of lalr1.cc  */
#line 1229 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 51:

/* Line 677 of lalr1.cc  */
#line 1230 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 52:

/* Line 677 of lalr1.cc  */
#line 1231 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 53:

/* Line 677 of lalr1.cc  */
#line 1232 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 54:

/* Line 677 of lalr1.cc  */
#line 1233 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 55:

/* Line 677 of lalr1.cc  */
#line 1234 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 66:

/* Line 677 of lalr1.cc  */
#line 1260 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
        }
    break;

  case 67:

/* Line 677 of lalr1.cc  */
#line 1268 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::preserve_space
            );
        }
    break;

  case 68:

/* Line 677 of lalr1.cc  */
#line 1274 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::strip_space
            );
        }
    break;

  case 69:

/* Line 677 of lalr1.cc  */
#line 1284 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_element_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 70:

/* Line 677 of lalr1.cc  */
#line 1290 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_function_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 71:

/* Line 677 of lalr1.cc  */
#line 1300 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OptionDecl(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval))
            );
        }
    break;

  case 72:

/* Line 677 of lalr1.cc  */
#line 1310 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 73:

/* Line 677 of lalr1.cc  */
#line 1318 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::ordered
            );
        }
    break;

  case 74:

/* Line 677 of lalr1.cc  */
#line 1324 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::unordered
            );
        }
    break;

  case 75:

/* Line 677 of lalr1.cc  */
#line 1335 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_greatest);
        }
    break;

  case 76:

/* Line 677 of lalr1.cc  */
#line 1340 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_least);
        }
    break;

  case 77:

/* Line 677 of lalr1.cc  */
#line 1350 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 78:

/* Line 677 of lalr1.cc  */
#line 1356 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 79:

/* Line 677 of lalr1.cc  */
#line 1362 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 80:

/* Line 677 of lalr1.cc  */
#line 1368 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 81:

/* Line 677 of lalr1.cc  */
#line 1385 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
        }
    break;

  case 82:

/* Line 677 of lalr1.cc  */
#line 1393 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 83:

/* Line 677 of lalr1.cc  */
#line 1401 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
        }
    break;

  case 84:

/* Line 677 of lalr1.cc  */
#line 1405 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport(
                LOC((yyloc)),
                dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                NULL
            );
        }
    break;

  case 85:

/* Line 677 of lalr1.cc  */
#line 1414 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport(
                LOC((yyloc)),
                NULL,
                SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 86:

/* Line 677 of lalr1.cc  */
#line 1423 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport(
                LOC((yyloc)),
                dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 87:

/* Line 677 of lalr1.cc  */
#line 1436 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            URILiteralList *ull = new URILiteralList( LOC((yyloc)));
            ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.node) = ull;
        }
    break;

  case 88:

/* Line 677 of lalr1.cc  */
#line 1442 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
                ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 89:

/* Line 677 of lalr1.cc  */
#line 1453 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 90:

/* Line 677 of lalr1.cc  */
#line 1457 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
        }
    break;

  case 91:

/* Line 677 of lalr1.cc  */
#line 1465 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 92:

/* Line 677 of lalr1.cc  */
#line 1470 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 93:

/* Line 677 of lalr1.cc  */
#line 1475 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 94:

/* Line 677 of lalr1.cc  */
#line 1482 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(8) - (4)].sval)),
                            SYMTAB((yysemantic_stack_[(8) - (6)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
    }
    break;

  case 95:

/* Line 677 of lalr1.cc  */
#line 1495 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
        }
    break;

  case 96:

/* Line 677 of lalr1.cc  */
#line 1502 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
            d->type = (yysemantic_stack_[(3) - (2)].node);
            (yyval.node) = d;
        }
    break;

  case 97:

/* Line 677 of lalr1.cc  */
#line 1508 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 98:

/* Line 677 of lalr1.cc  */
#line 1515 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
            d->ext = false;
            (yyval.node) = d;
        }
    break;

  case 99:

/* Line 677 of lalr1.cc  */
#line 1521 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), NULL );
        }
    break;

  case 100:

/* Line 677 of lalr1.cc  */
#line 1525 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 101:

/* Line 677 of lalr1.cc  */
#line 1532 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 102:

/* Line 677 of lalr1.cc  */
#line 1543 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 103:

/* Line 677 of lalr1.cc  */
#line 1547 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 104:

/* Line 677 of lalr1.cc  */
#line 1555 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(5) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(5) - (5)].expr));
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 105:

/* Line 677 of lalr1.cc  */
#line 1561 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL, true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 106:

/* Line 677 of lalr1.cc  */
#line 1567 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(6) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(6) - (6)].expr), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 107:

/* Line 677 of lalr1.cc  */
#line 1576 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            DeclPropertyList *dpl = new DeclPropertyList( LOC((yyloc)) );
            dpl->addProperty(dynamic_cast<DeclProperty*>((yysemantic_stack_[(1) - (1)].node)));
            (yyval.node) = dpl;
        }
    break;

  case 108:

/* Line 677 of lalr1.cc  */
#line 1582 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
        DeclPropertyList *dpl = dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(2) - (1)].node));
        dpl->addProperty( static_cast<DeclProperty*>((yysemantic_stack_[(2) - (2)].node)) );
        (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 109:

/* Line 677 of lalr1.cc  */
#line 1591 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_const );
        }
    break;

  case 110:

/* Line 677 of lalr1.cc  */
#line 1595 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_append_only
            );
        }
    break;

  case 111:

/* Line 677 of lalr1.cc  */
#line 1601 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_queue );
        }
    break;

  case 112:

/* Line 677 of lalr1.cc  */
#line 1605 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_mutable );
        }
    break;

  case 113:

/* Line 677 of lalr1.cc  */
#line 1609 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_ordered );
        }
    break;

  case 114:

/* Line 677 of lalr1.cc  */
#line 1613 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_unordered
            );
        }
    break;

  case 115:

/* Line 677 of lalr1.cc  */
#line 1619 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_equality
            );
        }
    break;

  case 116:

/* Line 677 of lalr1.cc  */
#line 1625 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_range
            );
        }
    break;

  case 117:

/* Line 677 of lalr1.cc  */
#line 1631 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_equality
            );
        }
    break;

  case 118:

/* Line 677 of lalr1.cc  */
#line 1637 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_range
            );
        }
    break;

  case 119:

/* Line 677 of lalr1.cc  */
#line 1643 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_unique );
        }
    break;

  case 120:

/* Line 677 of lalr1.cc  */
#line 1647 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_non_unique
            );
        }
    break;

  case 121:

/* Line 677 of lalr1.cc  */
#line 1653 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_automatic
            );
        }
    break;

  case 122:

/* Line 677 of lalr1.cc  */
#line 1659 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_manual );
        }
    break;

  case 123:

/* Line 677 of lalr1.cc  */
#line 1666 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL,
                              NULL);
    }
    break;

  case 124:

/* Line 677 of lalr1.cc  */
#line 1674 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              NULL,
                              static_cast<NodeModifier*>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 125:

/* Line 677 of lalr1.cc  */
#line 1682 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              NULL,
                              NULL,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 126:

/* Line 677 of lalr1.cc  */
#line 1690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                              NULL,
                              static_cast<NodeModifier*>((yysemantic_stack_[(6) - (6)].node)),
                              static_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)));
    }
    break;

  case 127:

/* Line 677 of lalr1.cc  */
#line 1698 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 128:

/* Line 677 of lalr1.cc  */
#line 1710 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 129:

/* Line 677 of lalr1.cc  */
#line 1724 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 130:

/* Line 677 of lalr1.cc  */
#line 1738 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 131:

/* Line 677 of lalr1.cc  */
#line 1755 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 132:

/* Line 677 of lalr1.cc  */
#line 1759 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 133:

/* Line 677 of lalr1.cc  */
#line 1768 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 134:

/* Line 677 of lalr1.cc  */
#line 1772 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 135:

/* Line 677 of lalr1.cc  */
#line 1779 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                             (yysemantic_stack_[(8) - (6)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                             NULL);
    }
    break;

  case 136:

/* Line 677 of lalr1.cc  */
#line 1787 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 137:

/* Line 677 of lalr1.cc  */
#line 1805 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 138:

/* Line 677 of lalr1.cc  */
#line 1811 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 139:

/* Line 677 of lalr1.cc  */
#line 1819 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 140:

/* Line 677 of lalr1.cc  */
#line 1824 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 141:

/* Line 677 of lalr1.cc  */
#line 1831 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 142:

/* Line 677 of lalr1.cc  */
#line 1838 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 143:

/* Line 677 of lalr1.cc  */
#line 1849 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 144:

/* Line 677 of lalr1.cc  */
#line 1859 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 145:

/* Line 677 of lalr1.cc  */
#line 1869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 146:

/* Line 677 of lalr1.cc  */
#line 1880 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 147:

/* Line 677 of lalr1.cc  */
#line 1895 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_preserve
            );
        }
    break;

  case 148:

/* Line 677 of lalr1.cc  */
#line 1901 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_strip
            );
        }
    break;

  case 149:

/* Line 677 of lalr1.cc  */
#line 1912 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL );
        }
    break;

  case 150:

/* Line 677 of lalr1.cc  */
#line 1916 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 151:

/* Line 677 of lalr1.cc  */
#line 1920 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)) );
        }
    break;

  case 152:

/* Line 677 of lalr1.cc  */
#line 1924 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 153:

/* Line 677 of lalr1.cc  */
#line 1931 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
        }
    break;

  case 154:

/* Line 677 of lalr1.cc  */
#line 1938 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 155:

/* Line 677 of lalr1.cc  */
#line 1957 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
            std::auto_ptr<VFO_DeclList> vfo2( dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)) );
            if ( !(yysemantic_stack_[(3) - (1)].node) )
                vfo = new VFO_DeclList( LOC((yyloc)) );
            vfo->push_back( *vfo2.get() );
            (yyval.node) = vfo;
        }
    break;

  case 156:

/* Line 677 of lalr1.cc  */
#line 1966 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 157:

/* Line 677 of lalr1.cc  */
#line 1973 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
            vfo->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = vfo;
        }
    break;

  case 158:

/* Line 677 of lalr1.cc  */
#line 1979 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = new VFO_DeclList( LOC((yyloc)) );
            vfo->push_back((yysemantic_stack_[(2) - (2)].node));
            (yyval.node) = vfo;
        }
    break;

  case 159:

/* Line 677 of lalr1.cc  */
#line 1989 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(1) - (1)].varnametype)));
      VarDecl* vd = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL);
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 160:

/* Line 677 of lalr1.cc  */
#line 1996 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(3) - (1)].varnametype)));
      VarDecl* vd = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(3) - (3)].expr));
      vd->set_global(false);
      (yyval.node) = vd;
        }
    break;

  case 161:

/* Line 677 of lalr1.cc  */
#line 2007 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 162:

/* Line 677 of lalr1.cc  */
#line 2014 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExitExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 163:

/* Line 677 of lalr1.cc  */
#line 2021 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            BlockBody *bb = dynamic_cast<BlockBody *>((yysemantic_stack_[(5) - (5)].expr));
            if ( !bb ) {
                bb = new BlockBody( (yysemantic_stack_[(5) - (5)].expr)->get_location() );
                bb->add((yysemantic_stack_[(5) - (5)].expr));
            }
            (yyval.expr) = new WhileExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), bb );
        }
    break;

  case 164:

/* Line 677 of lalr1.cc  */
#line 2033 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::BREAK );
        }
    break;

  case 165:

/* Line 677 of lalr1.cc  */
#line 2037 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
        }
    break;

  case 166:

/* Line 677 of lalr1.cc  */
#line 2044 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            dynamic_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 167:

/* Line 677 of lalr1.cc  */
#line 2049 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 168:

/* Line 677 of lalr1.cc  */
#line 2064 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 169:

/* Line 677 of lalr1.cc  */
#line 2081 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 170:

/* Line 677 of lalr1.cc  */
#line 2085 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 171:

/* Line 677 of lalr1.cc  */
#line 2089 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 172:

/* Line 677 of lalr1.cc  */
#line 2093 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 173:

/* Line 677 of lalr1.cc  */
#line 2101 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 174:

/* Line 677 of lalr1.cc  */
#line 2112 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 175:

/* Line 677 of lalr1.cc  */
#line 2127 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 176:

/* Line 677 of lalr1.cc  */
#line 2138 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 177:

/* Line 677 of lalr1.cc  */
#line 2153 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 178:

/* Line 677 of lalr1.cc  */
#line 2164 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 179:

/* Line 677 of lalr1.cc  */
#line 2180 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            ParamList *pl = new ParamList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 180:

/* Line 677 of lalr1.cc  */
#line 2186 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
                pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 181:

/* Line 677 of lalr1.cc  */
#line 2198 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 182:

/* Line 677 of lalr1.cc  */
#line 2202 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 183:

/* Line 677 of lalr1.cc  */
#line 2213 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EnclosedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 184:

/* Line 677 of lalr1.cc  */
#line 2220 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 185:

/* Line 677 of lalr1.cc  */
#line 2228 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QueryBody( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 186:

/* Line 677 of lalr1.cc  */
#line 2243 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 187:

/* Line 677 of lalr1.cc  */
#line 2247 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            std::auto_ptr<BlockBody> blk( dynamic_cast<BlockBody*>((yysemantic_stack_[(2) - (2)].expr)) );
            BlockBody *blk2 = new BlockBody( LOC((yyloc)) );
            blk2->add( (yysemantic_stack_[(2) - (1)].expr) );

            for ( int i = 0; i < blk->size(); ++i )
                blk2->add( (*blk)[i] );

            (yyval.expr) = blk2;
        }
    break;

  case 188:

/* Line 677 of lalr1.cc  */
#line 2261 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new BlockBody( LOC((yyloc)) );
        }
    break;

  case 189:

/* Line 677 of lalr1.cc  */
#line 2265 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            BlockBody *bb = dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (1)].expr));
            bb->add( (yysemantic_stack_[(3) - (2)].expr) );
            (yyval.expr) = bb;
        }
    break;

  case 190:

/* Line 677 of lalr1.cc  */
#line 2274 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 191:

/* Line 677 of lalr1.cc  */
#line 2278 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 210:

/* Line 677 of lalr1.cc  */
#line 2319 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 211:

/* Line 677 of lalr1.cc  */
#line 2334 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 212:

/* Line 677 of lalr1.cc  */
#line 2341 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_sliding;
        }
    break;

  case 213:

/* Line 677 of lalr1.cc  */
#line 2345 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_tumbling;
        }
    break;

  case 214:

/* Line 677 of lalr1.cc  */
#line 2352 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_start;
        }
    break;

  case 215:

/* Line 677 of lalr1.cc  */
#line 2356 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_end;
        }
    break;

  case 216:

/* Line 677 of lalr1.cc  */
#line 2360 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_only_end;
        }
    break;

  case 217:

/* Line 677 of lalr1.cc  */
#line 2367 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)),
                dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr),
                (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 218:

/* Line 677 of lalr1.cc  */
#line 2375 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr),
                (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 219:

/* Line 677 of lalr1.cc  */
#line 2386 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 220:

/* Line 677 of lalr1.cc  */
#line 2396 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 221:

/* Line 677 of lalr1.cc  */
#line 2409 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 230:

/* Line 677 of lalr1.cc  */
#line 2431 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 231:

/* Line 677 of lalr1.cc  */
#line 2437 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 232:

/* Line 677 of lalr1.cc  */
#line 2446 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = NULL;
        }
    break;

  case 233:

/* Line 677 of lalr1.cc  */
#line 2450 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_ofor;
        }
    break;

  case 234:

/* Line 677 of lalr1.cc  */
#line 2458 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForClause(
                LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL
            );
        }
    break;

  case 235:

/* Line 677 of lalr1.cc  */
#line 2468 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
            vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vdl;
        }
    break;

  case 236:

/* Line 677 of lalr1.cc  */
#line 2474 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 237:

/* Line 677 of lalr1.cc  */
#line 2486 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 238:

/* Line 677 of lalr1.cc  */
#line 2490 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                         NULL,NULL,
                         (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 239:

/* Line 677 of lalr1.cc  */
#line 2498 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
                         NULL,
                         (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 240:

/* Line 677 of lalr1.cc  */
#line 2507 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
                         NULL,
                         (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 241:

/* Line 677 of lalr1.cc  */
#line 2517 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 242:

/* Line 677 of lalr1.cc  */
#line 2525 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                         NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 243:

/* Line 677 of lalr1.cc  */
#line 2534 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC ((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 244:

/* Line 677 of lalr1.cc  */
#line 2543 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC ((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                         (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 245:

/* Line 677 of lalr1.cc  */
#line 2558 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 246:

/* Line 677 of lalr1.cc  */
#line 2567 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 247:

/* Line 677 of lalr1.cc  */
#line 2577 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 248:

/* Line 677 of lalr1.cc  */
#line 2585 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 249:

/* Line 677 of lalr1.cc  */
#line 2591 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 250:

/* Line 677 of lalr1.cc  */
#line 2600 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 251:

/* Line 677 of lalr1.cc  */
#line 2606 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 252:

/* Line 677 of lalr1.cc  */
#line 2618 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 253:

/* Line 677 of lalr1.cc  */
#line 2626 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 254:

/* Line 677 of lalr1.cc  */
#line 2636 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                           (yysemantic_stack_[(4) - (4)].expr));
     }
    break;

  case 255:

/* Line 677 of lalr1.cc  */
#line 2644 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                           (yysemantic_stack_[(5) - (5)].expr));
     }
    break;

  case 256:

/* Line 677 of lalr1.cc  */
#line 2656 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 257:

/* Line 677 of lalr1.cc  */
#line 2662 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 259:

/* Line 677 of lalr1.cc  */
#line 2675 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 260:

/* Line 677 of lalr1.cc  */
#line 2679 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 261:

/* Line 677 of lalr1.cc  */
#line 2687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 262:

/* Line 677 of lalr1.cc  */
#line 2691 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 264:

/* Line 677 of lalr1.cc  */
#line 2700 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 265:

/* Line 677 of lalr1.cc  */
#line 2704 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 266:

/* Line 677 of lalr1.cc  */
#line 2708 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 267:

/* Line 677 of lalr1.cc  */
#line 2716 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)),
                           NULL, NULL,
                           new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr))),
                           VarGetsDecl::eval_var);
    }
    break;

  case 268:

/* Line 677 of lalr1.cc  */
#line 2730 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 269:

/* Line 677 of lalr1.cc  */
#line 2738 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 270:

/* Line 677 of lalr1.cc  */
#line 2745 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 271:

/* Line 677 of lalr1.cc  */
#line 2751 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 272:

/* Line 677 of lalr1.cc  */
#line 2762 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 273:

/* Line 677 of lalr1.cc  */
#line 2766 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 274:

/* Line 677 of lalr1.cc  */
#line 2775 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 275:

/* Line 677 of lalr1.cc  */
#line 2783 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 276:

/* Line 677 of lalr1.cc  */
#line 2789 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 277:

/* Line 677 of lalr1.cc  */
#line 2799 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 278:

/* Line 677 of lalr1.cc  */
#line 2805 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 279:

/* Line 677 of lalr1.cc  */
#line 2815 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 280:

/* Line 677 of lalr1.cc  */
#line 2819 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 281:

/* Line 677 of lalr1.cc  */
#line 2829 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 282:

/* Line 677 of lalr1.cc  */
#line 2835 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 283:

/* Line 677 of lalr1.cc  */
#line 2841 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 284:

/* Line 677 of lalr1.cc  */
#line 2847 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 285:

/* Line 677 of lalr1.cc  */
#line 2856 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 286:

/* Line 677 of lalr1.cc  */
#line 2865 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 287:

/* Line 677 of lalr1.cc  */
#line 2874 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 288:

/* Line 677 of lalr1.cc  */
#line 2887 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 289:

/* Line 677 of lalr1.cc  */
#line 2891 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 290:

/* Line 677 of lalr1.cc  */
#line 2899 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 291:

/* Line 677 of lalr1.cc  */
#line 2905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 292:

/* Line 677 of lalr1.cc  */
#line 2915 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 293:

/* Line 677 of lalr1.cc  */
#line 2923 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 294:

/* Line 677 of lalr1.cc  */
#line 2932 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 295:

/* Line 677 of lalr1.cc  */
#line 2945 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 296:

/* Line 677 of lalr1.cc  */
#line 2952 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 297:

/* Line 677 of lalr1.cc  */
#line 2964 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 298:

/* Line 677 of lalr1.cc  */
#line 2968 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 299:

/* Line 677 of lalr1.cc  */
#line 2980 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 300:

/* Line 677 of lalr1.cc  */
#line 2987 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 301:

/* Line 677 of lalr1.cc  */
#line 2993 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 302:

/* Line 677 of lalr1.cc  */
#line 3002 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 303:

/* Line 677 of lalr1.cc  */
#line 3009 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 304:

/* Line 677 of lalr1.cc  */
#line 3015 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 305:

/* Line 677 of lalr1.cc  */
#line 3027 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 306:

/* Line 677 of lalr1.cc  */
#line 3034 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 307:

/* Line 677 of lalr1.cc  */
#line 3047 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 308:

/* Line 677 of lalr1.cc  */
#line 3053 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 309:

/* Line 677 of lalr1.cc  */
#line 3065 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 310:

/* Line 677 of lalr1.cc  */
#line 3071 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 311:

/* Line 677 of lalr1.cc  */
#line 3083 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 312:

/* Line 677 of lalr1.cc  */
#line 3092 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 313:

/* Line 677 of lalr1.cc  */
#line 3096 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 314:

/* Line 677 of lalr1.cc  */
#line 3105 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 315:

/* Line 677 of lalr1.cc  */
#line 3109 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 316:

/* Line 677 of lalr1.cc  */
#line 3117 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 317:

/* Line 677 of lalr1.cc  */
#line 3121 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 318:

/* Line 677 of lalr1.cc  */
#line 3131 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 319:

/* Line 677 of lalr1.cc  */
#line 3138 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 320:

/* Line 677 of lalr1.cc  */
#line 3147 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 321:

/* Line 677 of lalr1.cc  */
#line 3156 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 322:

/* Line 677 of lalr1.cc  */
#line 3161 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 323:

/* Line 677 of lalr1.cc  */
#line 3170 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 324:

/* Line 677 of lalr1.cc  */
#line 3179 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 325:

/* Line 677 of lalr1.cc  */
#line 3188 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 326:

/* Line 677 of lalr1.cc  */
#line 3201 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 327:

/* Line 677 of lalr1.cc  */
#line 3205 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 328:

/* Line 677 of lalr1.cc  */
#line 3217 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 329:

/* Line 677 of lalr1.cc  */
#line 3221 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 330:

/* Line 677 of lalr1.cc  */
#line 3228 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 331:

/* Line 677 of lalr1.cc  */
#line 3232 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 332:

/* Line 677 of lalr1.cc  */
#line 3241 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 333:

/* Line 677 of lalr1.cc  */
#line 3245 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 334:

/* Line 677 of lalr1.cc  */
#line 3249 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 335:

/* Line 677 of lalr1.cc  */
#line 3258 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 336:

/* Line 677 of lalr1.cc  */
#line 3262 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 337:

/* Line 677 of lalr1.cc  */
#line 3268 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 338:

/* Line 677 of lalr1.cc  */
#line 3274 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 339:

/* Line 677 of lalr1.cc  */
#line 3280 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 340:

/* Line 677 of lalr1.cc  */
#line 3291 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 341:

/* Line 677 of lalr1.cc  */
#line 3295 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 342:

/* Line 677 of lalr1.cc  */
#line 3299 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 343:

/* Line 677 of lalr1.cc  */
#line 3307 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 344:

/* Line 677 of lalr1.cc  */
#line 3311 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 345:

/* Line 677 of lalr1.cc  */
#line 3317 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 346:

/* Line 677 of lalr1.cc  */
#line 3327 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 347:

/* Line 677 of lalr1.cc  */
#line 3331 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 348:

/* Line 677 of lalr1.cc  */
#line 3341 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 349:

/* Line 677 of lalr1.cc  */
#line 3345 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 350:

/* Line 677 of lalr1.cc  */
#line 3355 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 351:

/* Line 677 of lalr1.cc  */
#line 3359 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 352:

/* Line 677 of lalr1.cc  */
#line 3369 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 353:

/* Line 677 of lalr1.cc  */
#line 3373 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 354:

/* Line 677 of lalr1.cc  */
#line 3383 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 355:

/* Line 677 of lalr1.cc  */
#line 3387 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 356:

/* Line 677 of lalr1.cc  */
#line 3395 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 357:

/* Line 677 of lalr1.cc  */
#line 3399 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 358:

/* Line 677 of lalr1.cc  */
#line 3403 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 359:

/* Line 677 of lalr1.cc  */
#line 3407 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 360:

/* Line 677 of lalr1.cc  */
#line 3417 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 361:

/* Line 677 of lalr1.cc  */
#line 3421 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 362:

/* Line 677 of lalr1.cc  */
#line 3425 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 363:

/* Line 677 of lalr1.cc  */
#line 3433 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 364:

/* Line 677 of lalr1.cc  */
#line 3437 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 365:

/* Line 677 of lalr1.cc  */
#line 3441 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 366:

/* Line 677 of lalr1.cc  */
#line 3445 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 367:

/* Line 677 of lalr1.cc  */
#line 3449 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 368:

/* Line 677 of lalr1.cc  */
#line 3453 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 369:

/* Line 677 of lalr1.cc  */
#line 3461 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 370:

/* Line 677 of lalr1.cc  */
#line 3465 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 371:

/* Line 677 of lalr1.cc  */
#line 3469 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 372:

/* Line 677 of lalr1.cc  */
#line 3477 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 373:

/* Line 677 of lalr1.cc  */
#line 3481 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 374:

/* Line 677 of lalr1.cc  */
#line 3485 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 375:

/* Line 677 of lalr1.cc  */
#line 3489 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 376:

/* Line 677 of lalr1.cc  */
#line 3500 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 377:

/* Line 677 of lalr1.cc  */
#line 3506 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 378:

/* Line 677 of lalr1.cc  */
#line 3516 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 379:

/* Line 677 of lalr1.cc  */
#line 3522 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 380:

/* Line 677 of lalr1.cc  */
#line 3532 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 381:

/* Line 677 of lalr1.cc  */
#line 3536 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 382:

/* Line 677 of lalr1.cc  */
#line 3574 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
        }
    break;

  case 383:

/* Line 677 of lalr1.cc  */
#line 3578 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 384:

/* Line 677 of lalr1.cc  */
#line 3584 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 385:

/* Line 677 of lalr1.cc  */
#line 3590 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            RelativePathExpr *rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = !rpe ?
                (yysemantic_stack_[(1) - (1)].expr) : new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 386:

/* Line 677 of lalr1.cc  */
#line 3601 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NULL;
        }
    break;

  case 387:

/* Line 677 of lalr1.cc  */
#line 3609 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 388:

/* Line 677 of lalr1.cc  */
#line 3620 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 389:

/* Line 677 of lalr1.cc  */
#line 3626 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 390:

/* Line 677 of lalr1.cc  */
#line 3636 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:

/* Line 677 of lalr1.cc  */
#line 3640 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 392:

/* Line 677 of lalr1.cc  */
#line 3648 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 393:

/* Line 677 of lalr1.cc  */
#line 3654 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 394:

/* Line 677 of lalr1.cc  */
#line 3662 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 395:

/* Line 677 of lalr1.cc  */
#line 3668 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 396:

/* Line 677 of lalr1.cc  */
#line 3680 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 397:

/* Line 677 of lalr1.cc  */
#line 3686 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 398:

/* Line 677 of lalr1.cc  */
#line 3696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 399:

/* Line 677 of lalr1.cc  */
#line 3700 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 400:

/* Line 677 of lalr1.cc  */
#line 3704 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 401:

/* Line 677 of lalr1.cc  */
#line 3708 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 402:

/* Line 677 of lalr1.cc  */
#line 3712 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 403:

/* Line 677 of lalr1.cc  */
#line 3718 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 404:

/* Line 677 of lalr1.cc  */
#line 3724 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 405:

/* Line 677 of lalr1.cc  */
#line 3747 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 406:

/* Line 677 of lalr1.cc  */
#line 3751 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 407:

/* Line 677 of lalr1.cc  */
#line 3759 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 408:

/* Line 677 of lalr1.cc  */
#line 3763 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 409:

/* Line 677 of lalr1.cc  */
#line 3774 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 410:

/* Line 677 of lalr1.cc  */
#line 3778 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 411:

/* Line 677 of lalr1.cc  */
#line 3782 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 412:

/* Line 677 of lalr1.cc  */
#line 3788 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 413:

/* Line 677 of lalr1.cc  */
#line 3792 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 414:

/* Line 677 of lalr1.cc  */
#line 3806 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 415:

/* Line 677 of lalr1.cc  */
#line 3810 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 416:

/* Line 677 of lalr1.cc  */
#line 3818 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 417:

/* Line 677 of lalr1.cc  */
#line 3822 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 418:

/* Line 677 of lalr1.cc  */
#line 3832 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all);
    }
    break;

  case 419:

/* Line 677 of lalr1.cc  */
#line 3836 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem);
    }
    break;

  case 420:

/* Line 677 of lalr1.cc  */
#line 3840 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix);
    }
    break;

  case 421:

/* Line 677 of lalr1.cc  */
#line 3849 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 422:

/* Line 677 of lalr1.cc  */
#line 3853 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FilterExpr(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 423:

/* Line 677 of lalr1.cc  */
#line 3859 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
        }
    break;

  case 424:

/* Line 677 of lalr1.cc  */
#line 3863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
        }
    break;

  case 425:

/* Line 677 of lalr1.cc  */
#line 3871 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 426:

/* Line 677 of lalr1.cc  */
#line 3877 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 427:

/* Line 677 of lalr1.cc  */
#line 3887 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 428:

/* Line 677 of lalr1.cc  */
#line 3895 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 429:

/* Line 677 of lalr1.cc  */
#line 3899 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 430:

/* Line 677 of lalr1.cc  */
#line 3903 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 431:

/* Line 677 of lalr1.cc  */
#line 3907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 432:

/* Line 677 of lalr1.cc  */
#line 3911 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 433:

/* Line 677 of lalr1.cc  */
#line 3915 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 434:

/* Line 677 of lalr1.cc  */
#line 3919 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 435:

/* Line 677 of lalr1.cc  */
#line 3923 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 436:

/* Line 677 of lalr1.cc  */
#line 3927 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 437:

/* Line 677 of lalr1.cc  */
#line 3935 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 438:

/* Line 677 of lalr1.cc  */
#line 3939 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 439:

/* Line 677 of lalr1.cc  */
#line 3947 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 440:

/* Line 677 of lalr1.cc  */
#line 3954 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 441:

/* Line 677 of lalr1.cc  */
#line 3961 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 442:

/* Line 677 of lalr1.cc  */
#line 3972 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 443:

/* Line 677 of lalr1.cc  */
#line 3980 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 444:

/* Line 677 of lalr1.cc  */
#line 3984 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 445:

/* Line 677 of lalr1.cc  */
#line 3992 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 446:

/* Line 677 of lalr1.cc  */
#line 4000 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 447:

/* Line 677 of lalr1.cc  */
#line 4008 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 448:

/* Line 677 of lalr1.cc  */
#line 4062 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 449:

/* Line 677 of lalr1.cc  */
#line 4066 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 450:

/* Line 677 of lalr1.cc  */
#line 4079 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 451:

/* Line 677 of lalr1.cc  */
#line 4085 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 452:

/* Line 677 of lalr1.cc  */
#line 4095 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 453:

/* Line 677 of lalr1.cc  */
#line 4099 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 454:

/* Line 677 of lalr1.cc  */
#line 4107 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 455:

/* Line 677 of lalr1.cc  */
#line 4111 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 456:

/* Line 677 of lalr1.cc  */
#line 4115 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 457:

/* Line 677 of lalr1.cc  */
#line 4123 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 458:

/* Line 677 of lalr1.cc  */
#line 4133 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 459:

/* Line 677 of lalr1.cc  */
#line 4143 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 460:

/* Line 677 of lalr1.cc  */
#line 4153 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 461:

/* Line 677 of lalr1.cc  */
#line 4163 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 462:

/* Line 677 of lalr1.cc  */
#line 4173 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 463:

/* Line 677 of lalr1.cc  */
#line 4188 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 464:

/* Line 677 of lalr1.cc  */
#line 4194 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 465:

/* Line 677 of lalr1.cc  */
#line 4205 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 466:

/* Line 677 of lalr1.cc  */
#line 4211 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 467:

/* Line 677 of lalr1.cc  */
#line 4222 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 470:

/* Line 677 of lalr1.cc  */
#line 4239 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 471:

/* Line 677 of lalr1.cc  */
#line 4244 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 472:

/* Line 677 of lalr1.cc  */
#line 4253 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 473:

/* Line 677 of lalr1.cc  */
#line 4257 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 474:

/* Line 677 of lalr1.cc  */
#line 4264 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back(
                new QuoteAttrValueContent( LOC((yyloc)),std::string("\"") )
            );
            (yyval.node) = qacl;
        }
    break;

  case 475:

/* Line 677 of lalr1.cc  */
#line 4272 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 476:

/* Line 677 of lalr1.cc  */
#line 4278 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 477:

/* Line 677 of lalr1.cc  */
#line 4288 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 478:

/* Line 677 of lalr1.cc  */
#line 4300 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 479:

/* Line 677 of lalr1.cc  */
#line 4304 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 480:

/* Line 677 of lalr1.cc  */
#line 4311 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 481:

/* Line 677 of lalr1.cc  */
#line 4317 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 482:

/* Line 677 of lalr1.cc  */
#line 4323 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 483:

/* Line 677 of lalr1.cc  */
#line 4330 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 484:

/* Line 677 of lalr1.cc  */
#line 4341 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 485:

/* Line 677 of lalr1.cc  */
#line 4345 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 486:

/* Line 677 of lalr1.cc  */
#line 4355 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 487:

/* Line 677 of lalr1.cc  */
#line 4359 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 488:

/* Line 677 of lalr1.cc  */
#line 4369 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 489:

/* Line 677 of lalr1.cc  */
#line 4373 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 490:

/* Line 677 of lalr1.cc  */
#line 4377 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 491:

/* Line 677 of lalr1.cc  */
#line 4382 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 492:

/* Line 677 of lalr1.cc  */
#line 4391 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 493:

/* Line 677 of lalr1.cc  */
#line 4397 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 494:

/* Line 677 of lalr1.cc  */
#line 4403 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 495:

/* Line 677 of lalr1.cc  */
#line 4409 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 496:

/* Line 677 of lalr1.cc  */
#line 4419 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 497:

/* Line 677 of lalr1.cc  */
#line 4423 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
        }
    break;

  case 498:

/* Line 677 of lalr1.cc  */
#line 4435 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 499:

/* Line 677 of lalr1.cc  */
#line 4439 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 500:

/* Line 677 of lalr1.cc  */
#line 4451 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 501:

/* Line 677 of lalr1.cc  */
#line 4463 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 502:

/* Line 677 of lalr1.cc  */
#line 4467 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 503:

/* Line 677 of lalr1.cc  */
#line 4471 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 504:

/* Line 677 of lalr1.cc  */
#line 4475 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 505:

/* Line 677 of lalr1.cc  */
#line 4479 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 506:

/* Line 677 of lalr1.cc  */
#line 4483 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 507:

/* Line 677 of lalr1.cc  */
#line 4491 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 508:

/* Line 677 of lalr1.cc  */
#line 4499 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (1)].sval))), NULL);
        }
    break;

  case 509:

/* Line 677 of lalr1.cc  */
#line 4503 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 510:

/* Line 677 of lalr1.cc  */
#line 4507 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 511:

/* Line 677 of lalr1.cc  */
#line 4511 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 512:

/* Line 677 of lalr1.cc  */
#line 4528 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (1)].sval))), NULL );
        }
    break;

  case 513:

/* Line 677 of lalr1.cc  */
#line 4532 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 514:

/* Line 677 of lalr1.cc  */
#line 4536 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 515:

/* Line 677 of lalr1.cc  */
#line 4540 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 516:

/* Line 677 of lalr1.cc  */
#line 4548 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 517:

/* Line 677 of lalr1.cc  */
#line 4556 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 518:

/* Line 677 of lalr1.cc  */
#line 4564 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (1)].sval)), NULL );
        }
    break;

  case 519:

/* Line 677 of lalr1.cc  */
#line 4568 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 520:

/* Line 677 of lalr1.cc  */
#line 4572 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 521:

/* Line 677 of lalr1.cc  */
#line 4576 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 522:

/* Line 677 of lalr1.cc  */
#line 4584 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 523:

/* Line 677 of lalr1.cc  */
#line 4590 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 524:

/* Line 677 of lalr1.cc  */
#line 4600 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 525:

/* Line 677 of lalr1.cc  */
#line 4608 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 526:

/* Line 677 of lalr1.cc  */
#line 4612 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 527:

/* Line 677 of lalr1.cc  */
#line 4616 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 528:

/* Line 677 of lalr1.cc  */
#line 4651 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 529:

/* Line 677 of lalr1.cc  */
#line 4657 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 530:

/* Line 677 of lalr1.cc  */
#line 4663 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
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
            (yyval.node) = new ItemType( LOC((yyloc)),true );
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
#line 4696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 537:

/* Line 677 of lalr1.cc  */
#line 4702 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 538:

/* Line 677 of lalr1.cc  */
#line 4712 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 539:

/* Line 677 of lalr1.cc  */
#line 4720 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 540:

/* Line 677 of lalr1.cc  */
#line 4724 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 541:

/* Line 677 of lalr1.cc  */
#line 4728 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 542:

/* Line 677 of lalr1.cc  */
#line 4732 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 543:

/* Line 677 of lalr1.cc  */
#line 4736 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 544:

/* Line 677 of lalr1.cc  */
#line 4740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 545:

/* Line 677 of lalr1.cc  */
#line 4744 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 546:

/* Line 677 of lalr1.cc  */
#line 4748 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 547:

/* Line 677 of lalr1.cc  */
#line 4752 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 548:

/* Line 677 of lalr1.cc  */
#line 4760 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 549:

/* Line 677 of lalr1.cc  */
#line 4768 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 550:

/* Line 677 of lalr1.cc  */
#line 4772 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 551:

/* Line 677 of lalr1.cc  */
#line 4776 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 552:

/* Line 677 of lalr1.cc  */
#line 4786 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 553:

/* Line 677 of lalr1.cc  */
#line 4794 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 554:

/* Line 677 of lalr1.cc  */
#line 4802 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 555:

/* Line 677 of lalr1.cc  */
#line 4806 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 556:

/* Line 677 of lalr1.cc  */
#line 4810 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 557:

/* Line 677 of lalr1.cc  */
#line 4818 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 558:

/* Line 677 of lalr1.cc  */
#line 4822 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 559:

/* Line 677 of lalr1.cc  */
#line 4828 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 560:

/* Line 677 of lalr1.cc  */
#line 4834 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 561:

/* Line 677 of lalr1.cc  */
#line 4838 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 562:

/* Line 677 of lalr1.cc  */
#line 4848 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 563:

/* Line 677 of lalr1.cc  */
#line 4856 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 564:

/* Line 677 of lalr1.cc  */
#line 4860 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 565:

/* Line 677 of lalr1.cc  */
#line 4866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 566:

/* Line 677 of lalr1.cc  */
#line 4875 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 567:

/* Line 677 of lalr1.cc  */
#line 4884 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 568:

/* Line 677 of lalr1.cc  */
#line 4890 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 569:

/* Line 677 of lalr1.cc  */
#line 4896 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 570:

/* Line 677 of lalr1.cc  */
#line 4906 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 571:

/* Line 677 of lalr1.cc  */
#line 4923 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 572:

/* Line 677 of lalr1.cc  */
#line 4930 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 573:

/* Line 677 of lalr1.cc  */
#line 4945 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 574:

/* Line 677 of lalr1.cc  */
#line 4981 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 575:

/* Line 677 of lalr1.cc  */
#line 4985 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 576:

/* Line 677 of lalr1.cc  */
#line 4994 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
        }
    break;

  case 577:

/* Line 677 of lalr1.cc  */
#line 5003 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new InlineFunction(LOC ((yyloc)), &*(yysemantic_stack_[(3) - (2)].fnsig)->param, &*(yysemantic_stack_[(3) - (2)].fnsig)->ret, dynamic_cast<EnclosedExpr *>((yysemantic_stack_[(3) - (3)].expr)));
          delete (yysemantic_stack_[(3) - (2)].fnsig);
        }
    break;

  case 578:

/* Line 677 of lalr1.cc  */
#line 5013 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 579:

/* Line 677 of lalr1.cc  */
#line 5017 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 580:

/* Line 677 of lalr1.cc  */
#line 5026 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
        }
    break;

  case 581:

/* Line 677 of lalr1.cc  */
#line 5035 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 582:

/* Line 677 of lalr1.cc  */
#line 5039 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 583:

/* Line 677 of lalr1.cc  */
#line 5050 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 584:

/* Line 677 of lalr1.cc  */
#line 5067 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 585:

/* Line 677 of lalr1.cc  */
#line 5073 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 586:

/* Line 677 of lalr1.cc  */
#line 5079 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 587:

/* Line 677 of lalr1.cc  */
#line 5089 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 588:

/* Line 677 of lalr1.cc  */
#line 5093 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 589:

/* Line 677 of lalr1.cc  */
#line 5099 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 590:

/* Line 677 of lalr1.cc  */
#line 5105 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 591:

/* Line 677 of lalr1.cc  */
#line 5109 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 592:

/* Line 677 of lalr1.cc  */
#line 5115 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 593:

/* Line 677 of lalr1.cc  */
#line 5119 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 594:

/* Line 677 of lalr1.cc  */
#line 5125 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 595:

/* Line 677 of lalr1.cc  */
#line 5131 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 596:

/* Line 677 of lalr1.cc  */
#line 5138 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 597:

/* Line 677 of lalr1.cc  */
#line 5148 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 598:

/* Line 677 of lalr1.cc  */
#line 5153 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 599:

/* Line 677 of lalr1.cc  */
#line 5161 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 600:

/* Line 677 of lalr1.cc  */
#line 5167 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 601:

/* Line 677 of lalr1.cc  */
#line 5177 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 602:

/* Line 677 of lalr1.cc  */
#line 5199 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 603:

/* Line 677 of lalr1.cc  */
#line 5208 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 604:

/* Line 677 of lalr1.cc  */
#line 5214 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 605:

/* Line 677 of lalr1.cc  */
#line 5227 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 606:

/* Line 677 of lalr1.cc  */
#line 5241 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 607:

/* Line 677 of lalr1.cc  */
#line 5248 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 608:

/* Line 677 of lalr1.cc  */
#line 5254 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 609:

/* Line 677 of lalr1.cc  */
#line 5264 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 610:

/* Line 677 of lalr1.cc  */
#line 5269 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 611:

/* Line 677 of lalr1.cc  */
#line 5275 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 612:

/* Line 677 of lalr1.cc  */
#line 5285 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 613:

/* Line 677 of lalr1.cc  */
#line 5298 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 614:

/* Line 677 of lalr1.cc  */
#line 5304 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 615:

/* Line 677 of lalr1.cc  */
#line 5321 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new EvalExpr(LOC((yyloc)), dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)), (yysemantic_stack_[(7) - (6)].expr));
        }
    break;

  case 616:

/* Line 677 of lalr1.cc  */
#line 5325 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new EvalExpr( LOC((yyloc)), new VarGetsDeclList( LOC((yyloc)) ), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 617:

/* Line 677 of lalr1.cc  */
#line 5340 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 618:

/* Line 677 of lalr1.cc  */
#line 5348 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 619:

/* Line 677 of lalr1.cc  */
#line 5352 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 620:

/* Line 677 of lalr1.cc  */
#line 5359 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 621:

/* Line 677 of lalr1.cc  */
#line 5364 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 622:

/* Line 677 of lalr1.cc  */
#line 5372 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 623:

/* Line 677 of lalr1.cc  */
#line 5376 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 624:

/* Line 677 of lalr1.cc  */
#line 5383 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 625:

/* Line 677 of lalr1.cc  */
#line 5387 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 626:

/* Line 677 of lalr1.cc  */
#line 5394 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 627:

/* Line 677 of lalr1.cc  */
#line 5398 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 628:

/* Line 677 of lalr1.cc  */
#line 5405 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 629:

/* Line 677 of lalr1.cc  */
#line 5409 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 630:

/* Line 677 of lalr1.cc  */
#line 5418 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 631:

/* Line 677 of lalr1.cc  */
#line 5430 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 632:

/* Line 677 of lalr1.cc  */
#line 5434 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 633:

/* Line 677 of lalr1.cc  */
#line 5441 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 634:

/* Line 677 of lalr1.cc  */
#line 5445 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 635:

/* Line 677 of lalr1.cc  */
#line 5453 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 636:

/* Line 677 of lalr1.cc  */
#line 5461 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 637:

/* Line 677 of lalr1.cc  */
#line 5469 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 638:

/* Line 677 of lalr1.cc  */
#line 5473 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 639:

/* Line 677 of lalr1.cc  */
#line 5480 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 640:

/* Line 677 of lalr1.cc  */
#line 5484 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 641:

/* Line 677 of lalr1.cc  */
#line 5492 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 642:

/* Line 677 of lalr1.cc  */
#line 5503 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 643:

/* Line 677 of lalr1.cc  */
#line 5507 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 644:

/* Line 677 of lalr1.cc  */
#line 5515 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 645:

/* Line 677 of lalr1.cc  */
#line 5527 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 646:

/* Line 677 of lalr1.cc  */
#line 5533 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 647:

/* Line 677 of lalr1.cc  */
#line 5542 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 648:

/* Line 677 of lalr1.cc  */
#line 5546 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 649:

/* Line 677 of lalr1.cc  */
#line 5554 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 650:

/* Line 677 of lalr1.cc  */
#line 5558 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 651:

/* Line 677 of lalr1.cc  */
#line 5562 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 652:

/* Line 677 of lalr1.cc  */
#line 5569 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 653:

/* Line 677 of lalr1.cc  */
#line 5573 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 654:

/* Line 677 of lalr1.cc  */
#line 5580 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 655:

/* Line 677 of lalr1.cc  */
#line 5584 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 656:

/* Line 677 of lalr1.cc  */
#line 5592 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 657:

/* Line 677 of lalr1.cc  */
#line 5596 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 658:

/* Line 677 of lalr1.cc  */
#line 5600 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 659:

/* Line 677 of lalr1.cc  */
#line 5604 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 660:

/* Line 677 of lalr1.cc  */
#line 5608 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 661:

/* Line 677 of lalr1.cc  */
#line 5616 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 662:

/* Line 677 of lalr1.cc  */
#line 5624 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 663:

/* Line 677 of lalr1.cc  */
#line 5636 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 664:

/* Line 677 of lalr1.cc  */
#line 5648 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 665:

/* Line 677 of lalr1.cc  */
#line 5652 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 666:

/* Line 677 of lalr1.cc  */
#line 5656 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 667:

/* Line 677 of lalr1.cc  */
#line 5664 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 668:

/* Line 677 of lalr1.cc  */
#line 5670 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 669:

/* Line 677 of lalr1.cc  */
#line 5680 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 670:

/* Line 677 of lalr1.cc  */
#line 5684 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 671:

/* Line 677 of lalr1.cc  */
#line 5688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 672:

/* Line 677 of lalr1.cc  */
#line 5692 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 673:

/* Line 677 of lalr1.cc  */
#line 5696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 674:

/* Line 677 of lalr1.cc  */
#line 5700 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 675:

/* Line 677 of lalr1.cc  */
#line 5704 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:

/* Line 677 of lalr1.cc  */
#line 5708 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 677:

/* Line 677 of lalr1.cc  */
#line 5716 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 678:

/* Line 677 of lalr1.cc  */
#line 5720 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 679:

/* Line 677 of lalr1.cc  */
#line 5724 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 680:

/* Line 677 of lalr1.cc  */
#line 5728 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 681:

/* Line 677 of lalr1.cc  */
#line 5736 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 682:

/* Line 677 of lalr1.cc  */
#line 5742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 683:

/* Line 677 of lalr1.cc  */
#line 5752 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 684:

/* Line 677 of lalr1.cc  */
#line 5762 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 685:

/* Line 677 of lalr1.cc  */
#line 5766 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 686:

/* Line 677 of lalr1.cc  */
#line 5774 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 687:

/* Line 677 of lalr1.cc  */
#line 5784 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 688:

/* Line 677 of lalr1.cc  */
#line 5795 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 689:

/* Line 677 of lalr1.cc  */
#line 5802 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 690:

/* Line 677 of lalr1.cc  */
#line 5806 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 691:

/* Line 677 of lalr1.cc  */
#line 5813 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 692:

/* Line 677 of lalr1.cc  */
#line 5817 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(1) - (1)].thesaurus_id_list);
        }
    break;

  case 693:

/* Line 677 of lalr1.cc  */
#line 5824 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 694:

/* Line 677 of lalr1.cc  */
#line 5829 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 695:

/* Line 677 of lalr1.cc  */
#line 5838 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);
        }
    break;

  case 696:

/* Line 677 of lalr1.cc  */
#line 5842 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (2)].sval)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(5) - (4)].node)));
        }
    break;

  case 697:

/* Line 677 of lalr1.cc  */
#line 5849 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 698:

/* Line 677 of lalr1.cc  */
#line 5853 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 699:

/* Line 677 of lalr1.cc  */
#line 5861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 700:

/* Line 677 of lalr1.cc  */
#line 5870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 701:

/* Line 677 of lalr1.cc  */
#line 5877 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 702:

/* Line 677 of lalr1.cc  */
#line 5887 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 703:

/* Line 677 of lalr1.cc  */
#line 5891 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 704:

/* Line 677 of lalr1.cc  */
#line 5898 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 705:

/* Line 677 of lalr1.cc  */
#line 5904 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 706:

/* Line 677 of lalr1.cc  */
#line 5913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 707:

/* Line 677 of lalr1.cc  */
#line 5917 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 708:

/* Line 677 of lalr1.cc  */
#line 5924 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 709:

/* Line 677 of lalr1.cc  */
#line 5929 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 710:

/* Line 677 of lalr1.cc  */
#line 5941 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 711:

/* Line 677 of lalr1.cc  */
#line 5949 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 712:

/* Line 677 of lalr1.cc  */
#line 5961 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 713:

/* Line 677 of lalr1.cc  */
#line 5969 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 714:

/* Line 677 of lalr1.cc  */
#line 5973 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 715:

/* Line 677 of lalr1.cc  */
#line 5981 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 716:

/* Line 677 of lalr1.cc  */
#line 5985 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 717:

/* Line 677 of lalr1.cc  */
#line 5989 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 718:

/* Line 677 of lalr1.cc  */
#line 5997 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 719:

/* Line 677 of lalr1.cc  */
#line 6005 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 720:

/* Line 677 of lalr1.cc  */
#line 6009 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 721:

/* Line 677 of lalr1.cc  */
#line 6013 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 722:

/* Line 677 of lalr1.cc  */
#line 6017 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 723:

/* Line 677 of lalr1.cc  */
#line 6025 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 724:

/* Line 677 of lalr1.cc  */
#line 6033 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 725:

/* Line 677 of lalr1.cc  */
#line 6045 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 726:

/* Line 677 of lalr1.cc  */
#line 6049 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 727:

/* Line 677 of lalr1.cc  */
#line 6057 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 730:

/* Line 677 of lalr1.cc  */
#line 6075 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 732:

/* Line 677 of lalr1.cc  */
#line 6088 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 733:

/* Line 677 of lalr1.cc  */
#line 6089 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 734:

/* Line 677 of lalr1.cc  */
#line 6090 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 735:

/* Line 677 of lalr1.cc  */
#line 6091 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 736:

/* Line 677 of lalr1.cc  */
#line 6092 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 737:

/* Line 677 of lalr1.cc  */
#line 6093 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 738:

/* Line 677 of lalr1.cc  */
#line 6094 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 739:

/* Line 677 of lalr1.cc  */
#line 6095 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 740:

/* Line 677 of lalr1.cc  */
#line 6096 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 741:

/* Line 677 of lalr1.cc  */
#line 6097 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 742:

/* Line 677 of lalr1.cc  */
#line 6098 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 743:

/* Line 677 of lalr1.cc  */
#line 6099 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 744:

/* Line 677 of lalr1.cc  */
#line 6100 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 745:

/* Line 677 of lalr1.cc  */
#line 6101 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 746:

/* Line 677 of lalr1.cc  */
#line 6102 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 747:

/* Line 677 of lalr1.cc  */
#line 6106 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 748:

/* Line 677 of lalr1.cc  */
#line 6107 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 749:

/* Line 677 of lalr1.cc  */
#line 6108 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 750:

/* Line 677 of lalr1.cc  */
#line 6109 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 751:

/* Line 677 of lalr1.cc  */
#line 6110 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 752:

/* Line 677 of lalr1.cc  */
#line 6111 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 753:

/* Line 677 of lalr1.cc  */
#line 6112 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 754:

/* Line 677 of lalr1.cc  */
#line 6113 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 755:

/* Line 677 of lalr1.cc  */
#line 6114 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 756:

/* Line 677 of lalr1.cc  */
#line 6115 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 757:

/* Line 677 of lalr1.cc  */
#line 6116 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 758:

/* Line 677 of lalr1.cc  */
#line 6117 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 759:

/* Line 677 of lalr1.cc  */
#line 6118 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 760:

/* Line 677 of lalr1.cc  */
#line 6119 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 761:

/* Line 677 of lalr1.cc  */
#line 6120 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 762:

/* Line 677 of lalr1.cc  */
#line 6121 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 763:

/* Line 677 of lalr1.cc  */
#line 6122 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 764:

/* Line 677 of lalr1.cc  */
#line 6123 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 765:

/* Line 677 of lalr1.cc  */
#line 6124 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 766:

/* Line 677 of lalr1.cc  */
#line 6125 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 767:

/* Line 677 of lalr1.cc  */
#line 6126 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 768:

/* Line 677 of lalr1.cc  */
#line 6127 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 769:

/* Line 677 of lalr1.cc  */
#line 6128 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 770:

/* Line 677 of lalr1.cc  */
#line 6129 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 771:

/* Line 677 of lalr1.cc  */
#line 6130 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 772:

/* Line 677 of lalr1.cc  */
#line 6131 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 773:

/* Line 677 of lalr1.cc  */
#line 6132 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 774:

/* Line 677 of lalr1.cc  */
#line 6133 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 775:

/* Line 677 of lalr1.cc  */
#line 6134 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 776:

/* Line 677 of lalr1.cc  */
#line 6135 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 777:

/* Line 677 of lalr1.cc  */
#line 6136 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 778:

/* Line 677 of lalr1.cc  */
#line 6137 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 779:

/* Line 677 of lalr1.cc  */
#line 6138 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 780:

/* Line 677 of lalr1.cc  */
#line 6139 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 781:

/* Line 677 of lalr1.cc  */
#line 6140 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 782:

/* Line 677 of lalr1.cc  */
#line 6141 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 783:

/* Line 677 of lalr1.cc  */
#line 6142 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 784:

/* Line 677 of lalr1.cc  */
#line 6143 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 785:

/* Line 677 of lalr1.cc  */
#line 6144 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 786:

/* Line 677 of lalr1.cc  */
#line 6145 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 787:

/* Line 677 of lalr1.cc  */
#line 6146 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 788:

/* Line 677 of lalr1.cc  */
#line 6147 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("outer"))); }
    break;

  case 789:

/* Line 677 of lalr1.cc  */
#line 6148 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 790:

/* Line 677 of lalr1.cc  */
#line 6149 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 791:

/* Line 677 of lalr1.cc  */
#line 6150 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 792:

/* Line 677 of lalr1.cc  */
#line 6151 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 793:

/* Line 677 of lalr1.cc  */
#line 6152 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 794:

/* Line 677 of lalr1.cc  */
#line 6153 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 795:

/* Line 677 of lalr1.cc  */
#line 6154 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 796:

/* Line 677 of lalr1.cc  */
#line 6155 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 797:

/* Line 677 of lalr1.cc  */
#line 6156 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 798:

/* Line 677 of lalr1.cc  */
#line 6157 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 799:

/* Line 677 of lalr1.cc  */
#line 6158 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 800:

/* Line 677 of lalr1.cc  */
#line 6159 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 801:

/* Line 677 of lalr1.cc  */
#line 6160 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 802:

/* Line 677 of lalr1.cc  */
#line 6161 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 803:

/* Line 677 of lalr1.cc  */
#line 6162 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 804:

/* Line 677 of lalr1.cc  */
#line 6163 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 805:

/* Line 677 of lalr1.cc  */
#line 6164 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 806:

/* Line 677 of lalr1.cc  */
#line 6165 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 807:

/* Line 677 of lalr1.cc  */
#line 6166 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 808:

/* Line 677 of lalr1.cc  */
#line 6167 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 809:

/* Line 677 of lalr1.cc  */
#line 6168 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 810:

/* Line 677 of lalr1.cc  */
#line 6169 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 811:

/* Line 677 of lalr1.cc  */
#line 6170 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 812:

/* Line 677 of lalr1.cc  */
#line 6171 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 813:

/* Line 677 of lalr1.cc  */
#line 6172 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 814:

/* Line 677 of lalr1.cc  */
#line 6173 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 815:

/* Line 677 of lalr1.cc  */
#line 6174 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 816:

/* Line 677 of lalr1.cc  */
#line 6175 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 817:

/* Line 677 of lalr1.cc  */
#line 6176 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 818:

/* Line 677 of lalr1.cc  */
#line 6177 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 819:

/* Line 677 of lalr1.cc  */
#line 6178 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 820:

/* Line 677 of lalr1.cc  */
#line 6179 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 821:

/* Line 677 of lalr1.cc  */
#line 6180 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 822:

/* Line 677 of lalr1.cc  */
#line 6181 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 823:

/* Line 677 of lalr1.cc  */
#line 6182 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 824:

/* Line 677 of lalr1.cc  */
#line 6183 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 825:

/* Line 677 of lalr1.cc  */
#line 6184 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 826:

/* Line 677 of lalr1.cc  */
#line 6185 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 827:

/* Line 677 of lalr1.cc  */
#line 6186 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 828:

/* Line 677 of lalr1.cc  */
#line 6187 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 829:

/* Line 677 of lalr1.cc  */
#line 6188 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 830:

/* Line 677 of lalr1.cc  */
#line 6189 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 831:

/* Line 677 of lalr1.cc  */
#line 6190 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 832:

/* Line 677 of lalr1.cc  */
#line 6191 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 833:

/* Line 677 of lalr1.cc  */
#line 6192 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 834:

/* Line 677 of lalr1.cc  */
#line 6193 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 835:

/* Line 677 of lalr1.cc  */
#line 6194 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 836:

/* Line 677 of lalr1.cc  */
#line 6195 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 837:

/* Line 677 of lalr1.cc  */
#line 6196 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 838:

/* Line 677 of lalr1.cc  */
#line 6197 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 839:

/* Line 677 of lalr1.cc  */
#line 6198 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 840:

/* Line 677 of lalr1.cc  */
#line 6199 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 841:

/* Line 677 of lalr1.cc  */
#line 6200 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 842:

/* Line 677 of lalr1.cc  */
#line 6201 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 843:

/* Line 677 of lalr1.cc  */
#line 6202 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 844:

/* Line 677 of lalr1.cc  */
#line 6203 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 845:

/* Line 677 of lalr1.cc  */
#line 6204 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 846:

/* Line 677 of lalr1.cc  */
#line 6205 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 847:

/* Line 677 of lalr1.cc  */
#line 6206 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 848:

/* Line 677 of lalr1.cc  */
#line 6207 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 849:

/* Line 677 of lalr1.cc  */
#line 6208 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 850:

/* Line 677 of lalr1.cc  */
#line 6209 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 851:

/* Line 677 of lalr1.cc  */
#line 6210 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 852:

/* Line 677 of lalr1.cc  */
#line 6211 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 853:

/* Line 677 of lalr1.cc  */
#line 6212 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 854:

/* Line 677 of lalr1.cc  */
#line 6213 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 855:

/* Line 677 of lalr1.cc  */
#line 6214 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 856:

/* Line 677 of lalr1.cc  */
#line 6215 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 857:

/* Line 677 of lalr1.cc  */
#line 6216 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 858:

/* Line 677 of lalr1.cc  */
#line 6217 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 859:

/* Line 677 of lalr1.cc  */
#line 6218 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 860:

/* Line 677 of lalr1.cc  */
#line 6219 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 861:

/* Line 677 of lalr1.cc  */
#line 6220 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 862:

/* Line 677 of lalr1.cc  */
#line 6221 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 863:

/* Line 677 of lalr1.cc  */
#line 6222 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 864:

/* Line 677 of lalr1.cc  */
#line 6223 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 865:

/* Line 677 of lalr1.cc  */
#line 6224 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 866:

/* Line 677 of lalr1.cc  */
#line 6225 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 867:

/* Line 677 of lalr1.cc  */
#line 6226 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 868:

/* Line 677 of lalr1.cc  */
#line 6227 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 869:

/* Line 677 of lalr1.cc  */
#line 6228 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 870:

/* Line 677 of lalr1.cc  */
#line 6229 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 871:

/* Line 677 of lalr1.cc  */
#line 6230 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 872:

/* Line 677 of lalr1.cc  */
#line 6231 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 873:

/* Line 677 of lalr1.cc  */
#line 6232 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 874:

/* Line 677 of lalr1.cc  */
#line 6233 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 875:

/* Line 677 of lalr1.cc  */
#line 6234 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 876:

/* Line 677 of lalr1.cc  */
#line 6235 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 877:

/* Line 677 of lalr1.cc  */
#line 6236 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 878:

/* Line 677 of lalr1.cc  */
#line 6237 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 879:

/* Line 677 of lalr1.cc  */
#line 6238 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 880:

/* Line 677 of lalr1.cc  */
#line 6239 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 881:

/* Line 677 of lalr1.cc  */
#line 6240 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 882:

/* Line 677 of lalr1.cc  */
#line 6241 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 883:

/* Line 677 of lalr1.cc  */
#line 6242 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 884:

/* Line 677 of lalr1.cc  */
#line 6243 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 885:

/* Line 677 of lalr1.cc  */
#line 6244 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 886:

/* Line 677 of lalr1.cc  */
#line 6245 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 887:

/* Line 677 of lalr1.cc  */
#line 6246 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 888:

/* Line 677 of lalr1.cc  */
#line 6247 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("deterministic"))); }
    break;

  case 889:

/* Line 677 of lalr1.cc  */
#line 6248 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nondeterministic"))); }
    break;

  case 890:

/* Line 677 of lalr1.cc  */
#line 6249 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 891:

/* Line 677 of lalr1.cc  */
#line 6250 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 892:

/* Line 677 of lalr1.cc  */
#line 6251 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 893:

/* Line 677 of lalr1.cc  */
#line 6252 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("block"))); }
    break;

  case 894:

/* Line 677 of lalr1.cc  */
#line 6253 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 895:

/* Line 677 of lalr1.cc  */
#line 6254 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 896:

/* Line 677 of lalr1.cc  */
#line 6255 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 897:

/* Line 677 of lalr1.cc  */
#line 6256 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 898:

/* Line 677 of lalr1.cc  */
#line 6257 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 899:

/* Line 677 of lalr1.cc  */
#line 6258 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 900:

/* Line 677 of lalr1.cc  */
#line 6259 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eval"))); }
    break;

  case 901:

/* Line 677 of lalr1.cc  */
#line 6260 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 902:

/* Line 677 of lalr1.cc  */
#line 6261 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 903:

/* Line 677 of lalr1.cc  */
#line 6262 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 904:

/* Line 677 of lalr1.cc  */
#line 6263 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 905:

/* Line 677 of lalr1.cc  */
#line 6264 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 906:

/* Line 677 of lalr1.cc  */
#line 6265 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 907:

/* Line 677 of lalr1.cc  */
#line 6266 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 908:

/* Line 677 of lalr1.cc  */
#line 6267 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 909:

/* Line 677 of lalr1.cc  */
#line 6268 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 910:

/* Line 677 of lalr1.cc  */
#line 6269 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 911:

/* Line 677 of lalr1.cc  */
#line 6270 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 912:

/* Line 677 of lalr1.cc  */
#line 6271 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 913:

/* Line 677 of lalr1.cc  */
#line 6272 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 914:

/* Line 677 of lalr1.cc  */
#line 6273 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 915:

/* Line 677 of lalr1.cc  */
#line 6274 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 916:

/* Line 677 of lalr1.cc  */
#line 6275 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 917:

/* Line 677 of lalr1.cc  */
#line 6276 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 918:

/* Line 677 of lalr1.cc  */
#line 6277 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 919:

/* Line 677 of lalr1.cc  */
#line 6278 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 920:

/* Line 677 of lalr1.cc  */
#line 6279 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 921:

/* Line 677 of lalr1.cc  */
#line 6280 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 922:

/* Line 677 of lalr1.cc  */
#line 6281 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 923:

/* Line 677 of lalr1.cc  */
#line 6282 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 924:

/* Line 677 of lalr1.cc  */
#line 6283 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 925:

/* Line 677 of lalr1.cc  */
#line 6284 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 926:

/* Line 677 of lalr1.cc  */
#line 6285 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 927:

/* Line 677 of lalr1.cc  */
#line 6286 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 928:

/* Line 677 of lalr1.cc  */
#line 6287 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 929:

/* Line 677 of lalr1.cc  */
#line 6288 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 930:

/* Line 677 of lalr1.cc  */
#line 6289 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 931:

/* Line 677 of lalr1.cc  */
#line 6290 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 932:

/* Line 677 of lalr1.cc  */
#line 6291 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 933:

/* Line 677 of lalr1.cc  */
#line 6292 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 934:

/* Line 677 of lalr1.cc  */
#line 6293 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 935:

/* Line 677 of lalr1.cc  */
#line 6294 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 936:

/* Line 677 of lalr1.cc  */
#line 6295 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 937:

/* Line 677 of lalr1.cc  */
#line 6296 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 938:

/* Line 677 of lalr1.cc  */
#line 6297 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 939:

/* Line 677 of lalr1.cc  */
#line 6298 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 940:

/* Line 677 of lalr1.cc  */
#line 6299 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 941:

/* Line 677 of lalr1.cc  */
#line 6300 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 942:

/* Line 677 of lalr1.cc  */
#line 6301 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 943:

/* Line 677 of lalr1.cc  */
#line 6302 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 944:

/* Line 677 of lalr1.cc  */
#line 6303 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 945:

/* Line 677 of lalr1.cc  */
#line 6304 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 946:

/* Line 677 of lalr1.cc  */
#line 6305 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;



/* Line 677 of lalr1.cc  */
#line 11368 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1336;
  const short int
  xquery_parser::yypact_[] =
  {
      1947, -1336, -1336, -1336,  2541,  2834,  3127, -1336, -1336,  1592,
     -46, -1336, -1336,   462, -1336, -1336, -1336, -1336,   167,   205,
     466,   202,   323,   220,   282,    76, -1336,   291, -1336, -1336,
   -1336, -1336, -1336, -1336,   367, -1336,   474, -1336,   332,   350,
   -1336,   339, -1336, -1336,   419, -1336,   475, -1336,   386,   431,
   -1336,   -26, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336,   426,   469, -1336, -1336, -1336,
   -1336,   390,  8108, -1336, -1336, -1336,   491, -1336, -1336, -1336,
   -1336, -1336,   495,   499, -1336, -1336, 11240, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336,   487, -1336, -1336,   507,   519,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336,  3420, 11240, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336,   444, -1336, -1336,   525,
    8979, -1336,  9266,   532,   537, -1336, -1336, -1336,   545, -1336,
    7815, -1336, -1336, -1336, -1336, -1336, -1336,   522, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336,    25,   470, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336,   223,   521,   414, -1336,
     472,   128, -1336, -1336, -1336, -1336, -1336, -1336,   567, -1336,
     548,   468,   476,   461, -1336, -1336,   547,   551, -1336,   587,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
    2248,   703, -1336,   710,  5471, -1336, -1336,   302,   531,   533,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336,    -6, -1336, -1336, -1336, -1336,   500, 11240, -1336, -1336,
   -1336, -1336, -1336, -1336,   556,   620, -1336,   705,   477,   310,
     212,   385,   324, -1336,   675,   530,   629,   630,  5764, -1336,
   -1336, -1336,   -34, -1336, -1336,  7815, -1336,   459, -1336,   578,
    8108, -1336,   578,  8108, -1336, -1336, -1336,   484, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336,   590,   580, -1336, -1336, -1336, -1336, -1336,   554, -1336,
     555, -1336,   570,   725,   286,   369,   -63,   503, 11522,   503,
   11240,   -56,   707,   708,   709, 11240,   606,   641,   260,  8979,
   -1336, -1336,   415,   358,   524, 11240, -1336, -1336, -1336, -1336,
   -1336,   480, 11240,   473,   479,   361,   471,   404, -1336, -1336,
   -1336, -1336, -1336,  8979,  6057,   589,  6057,    23,  6057,  9830,
    6057,   490,   494, -1336,   659,   -11,   626,  6057,    62,    64,
   11240,   661,  6057,  8690, 11240, 11240, 11240, 11240,  6057,   595,
    6057,  6057, 11240,  6057,   632,   633, -1336, -1336, -1336,  6057,
   10112,   627, -1336,   631, -1336, -1336, -1336, -1336, -1336, -1336,
     634, -1336, -1336,   637, -1336, -1336, -1336, -1336, -1336,   638,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   11240, -1336, -1336, -1336,   596,   753,  6057, -1336, -1336,    46,
   -1336, -1336,   768, -1336, -1336, -1336, -1336,  6057,   584, -1336,
     770,  6057,  6057,   611,  6057,  6057,  6057,  6057,   571, 11240,
   -1336, -1336, -1336, -1336,  6057,  6057,  6057, 11240, -1336,   710,
   -1336, -1336, -1336, -1336,  1592,    76,   615,   616,  6350,  6643,
    6057, -1336,  6057,   687,   323,   291,   367,   639,   642,   643,
    6057,  6057, -1336, -1336, -1336, -1336, -1336, -1336, -1336,   700,
   -1336,   -38,  6936,  6936,  6936, -1336,  6936,  6936, -1336,  6936,
   -1336,  6936, -1336, -1336, -1336, -1336, -1336, -1336, -1336,  6936,
    6936,   736,  6936,  6936,  6936,  6936,  6936,  6936,  6936,  6936,
    6936,  6936,  6936,   582,   719,   720,   721, -1336, -1336, -1336,
    3713, -1336, -1336,  7815,  7815,  6057,   578, -1336, -1336,   578,
   -1336,  4006,   578,   669,  4299, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336,   711,   712, -1336,   220, -1336,   792,
   -1336, -1336, 11522, -1336, 11522,   660,   340, 11240,   274,   664,
     665,   660,   725,   699,   695, -1336, -1336, -1336, -1336, -1336,
      -7,   583,    -9, -1336,   535, -1336, -1336, -1336, -1336, 11240,
   11240, 11240, -1336,   697,   647, -1336,   648,   631,   350, -1336,
     646,   649,   651, -1336,   -22,    -4,   653, -1336, -1336, 11240,
      -5, 11240,   742,    21, -1336,  6057, -1336,   654,  8979,   741,
     796,  8979,   725,   746,   743, -1336,   -43, -1336,   670,   668,
   -1336,   671,   672,   677,   713,   -10, -1336,    56,   678, -1336,
     679,   680,   715, -1336,   681,  6057,  6057,   686, -1336,    27,
     141,    72, -1336, 11240,   753, -1336,   -35,   688, -1336, -1336,
   -1336,   689, -1336,   170, -1336, -1336, -1336,   -16,   101,   774,
     640,   650,    20, -1336,   732,  7229, -1336,   690,   694,   241,
   -1336, -1336, -1336,   302,   845,   698, -1336, -1336,   928, -1336,
   -1336, -1336,    -2, 11240,   716,  6057,   769, -1336, -1336,   771,
   10676,   772,  6057,   776,     2,   749,   -21,   620, -1336, -1336,
   -1336, -1336, -1336,  6936, -1336, -1336, -1336,    10,   212,   212,
     230,   385,   385,   385,   385,   324,   324, -1336, -1336, 10676,
   10676, 11240, 11240, -1336,   706, -1336, -1336,   714, -1336, -1336,
   -1336,   158, -1336, -1336,   168,   254,   265,   316, -1336,   220,
     220, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336,   660, -1336,   761, 10958,   755,  6057, -1336, -1336, -1336,
     803,   758,  6057,   725,   725,   660, -1336,   534,   725,   334,
   11240,    50,   225,   872, -1336, -1336,   617,   252, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,    -7,
     103,   375, -1336,   691,   287,     4,   605,   725, -1336, -1336,
   -1336, -1336,   751, 11240, -1336, 11240, -1336, -1336,   200,   652,
   -1336, -1336,   346,    -5,   803, 10676,   793,   817,   734,   722,
     783,   725,   759,   788,   825,   725,   809,  6057,   787,   -64,
     778, -1336, -1336, -1336, -1336,  6057,   813,  6057,  6057,   786,
   -1336,   837,   838,  6057, -1336,   762,   763,   789, 11240, -1336,
   11240, -1336,  6057,   906, -1336,     1, -1336,   110, -1336, -1336,
     915, -1336,   412,  6057,  6057,  6057,   416,  6057,  6057,  6057,
    6057,  6057,  6057,   828,  6057,  6057,   641,     3,   765,   548,
     718,   799,   830,   764,   928,  6643,   874, -1336, -1336,  6057,
     447,   849, -1336, 11240,   850, -1336, 11240,   808,   810, 10958,
     811, -1336,   -37, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
   11240, -1336, 11240,  6057,   812,  6057,  6057,    22,   821, -1336,
    6057,    10,   400,   -23, -1336,   685,    48,   717,   723, -1336,
   -1336,   524, -1336,   724,   321, -1336, -1336, -1336,   827, -1336,
   -1336, -1336,  6057, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
    6057, -1336,   355,   422, -1336,   943,   379, -1336, -1336, -1336,
    6057, -1336, -1336, -1336, -1336, -1336, -1336, -1336,   692, -1336,
   -1336,   944, -1336, -1336, -1336, -1336, -1336,   285,   949, -1336,
     463, -1336, -1336, -1336,   627,   205,   634,   332,   637,   638,
     521,   744,   -37,   756,   760,  7522,   701,   683,   103, -1336,
     766,   791,  4592,   797,   806,   851,   807,   814,  6057,   842,
   -1336,   878,   879,  6057, 11240,   330,   920, -1336, -1336, -1336,
   -1336, -1336, -1336, 10676, -1336,  6057,   725,   893, -1336, -1336,
   -1336,   725,   893, 11240, -1336,  6057,  6057,   860,  4885, -1336,
   11240, -1336, -1336,  6057,  6057,   464, -1336,   -12, 10394,   478,
   -1336,   820, -1336, -1336,  5178,   826,   829, -1336, -1336,   875,
   -1336,   264, -1336, -1336,   994, -1336, -1336, 11240, -1336, -1336,
     278, -1336, -1336, -1336,   822,   782,   785, -1336, -1336, -1336,
     794,   795, -1336, -1336, -1336, -1336, -1336,   779, 11240,   832,
   -1336,   876, -1336,   641, -1336, -1336, -1336,  8401,   718, -1336,
    6057, 11240,   845, -1336,   849, -1336,   725, -1336,   541, -1336,
     209,   912, -1336,  6057,   913,   769, -1336,  9548,   836,   841,
     843, -1336, -1336, -1336, -1336, -1336, -1336, -1336,  6057, -1336,
   -1336,  6057,   881,  6057,   840,   846, -1336,    10,   784, -1336,
   -1336,  -103, -1336,   314,   -25,   790,    10,   314,  6936, -1336,
     144, -1336, -1336, -1336, -1336, -1336, -1336,    10,   884,   754,
     583,   -25, -1336, -1336,   752,   954, -1336, -1336, -1336, -1336,
   -1336,   853, -1336, -1336, -1336,  6057, -1336, -1336, -1336, -1336,
   -1336,  1009,     7,  1014,     7,   775,   946, -1336, -1336, -1336,
   -1336,   877, 11240,   798,   744,  7522, -1336, -1336,   863, -1336,
   -1336, -1336, -1336, -1336, -1336,  6057, 11240, 11240, -1336,   378,
   -1336,  6057, -1336,   922,   951,   725,   893, -1336, -1336, -1336,
    6057, -1336,   867, -1336, -1336, -1336,   866, -1336,  6057,  6057,
   11240,   870,   -29, -1336, -1336, -1336,   869, -1336, -1336,   906,
   11240,   409, -1336,   906, 11240, -1336, -1336,  6057,  6057,  6057,
    6057,  6057, -1336,  6057,  6057, -1336, -1336,   256, -1336,   880,
   -1336, -1336, -1336, -1336,   912, -1336, -1336, -1336,   725, -1336,
   -1336,   961,   882, -1336,   178, -1336, -1336, -1336, -1336, -1336,
    6057, -1336, -1336, -1336, -1336,   883,  6936, -1336, -1336, -1336,
   -1336, -1336,    52,  6936,  6936,  -152, -1336,   717, -1336,   -13,
   -1336,   723,    10,   907, -1336, -1336,   800, -1336, -1336, -1336,
   -1336, -1336,    29, -1336,   213,   213, -1336,     7, -1336, -1336,
     189, -1336,  1032,   -25,   885,   956, -1336,  7522,   -62,   801,
   -1336,   892, -1336, -1336, -1336,  1011, -1336, -1336,  6057,   725,
   -1336, -1336, -1336,  6057, -1336, -1336,   973,  6057, 11240,  6057,
   -1336,    -3,   906, 11240,   886,   906, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336,   955,  8401, -1336, -1336, -1336, -1336, 10676,
   -1336, 10676,   977, -1336, -1336,   385,  6936,  6936,   230,   360,
   -1336, -1336, -1336, -1336, -1336, -1336,  6057, -1336, -1336, -1336,
   -1336, -1336,  1046, -1336, -1336,   816, -1336,   946,   968, -1336,
     413, 11240,   959,   859, 11240,  7522,   964, -1336,   893, -1336,
   10676, -1336,   900, -1336,    65,   157, -1336,   891,   906, -1336,
     894, 11240, -1336, -1336, -1336, 10676,   230,   230,  6936,   905,
   -1336, -1336, -1336,  7522, -1336,   912,   802, 11240,   971,   868,
     968, 11240,   908,  6057, -1336, -1336,   999,   181, -1336, -1336,
   -1336, -1336,   914,   392, -1336, -1336, -1336,   903, -1336,   199,
   -1336,   230, -1336, -1336, -1336,  6057,   804, 11240,   976, -1336,
    6057, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,   980,
     947, -1336,   818,   805, 11240, -1336, 11240, -1336,   815,  6057,
     819,   207,  7522, -1336,  7522,   982,   947, -1336,   916, 11240,
   -1336,   831,   917, 11240,   947,   889, -1336,   983, 11240,   824,
    7522, -1336
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,     8,   419,   420,     0,     0,     0,   747,   573,   838,
     847,   752,   750,   733,   839,   842,   795,   888,   756,   734,
     735,   900,   787,   848,   737,   845,   817,   797,   772,   792,
     889,   793,   843,   840,   788,   791,   739,   846,   740,   741,
     886,   902,   885,   789,   808,   802,   742,   790,   744,   743,
     887,   826,   794,   769,   912,   913,   914,   915,   916,   917,
     918,   919,   920,   921,   922,   936,   943,   816,   812,   803,
     783,   732,     0,   811,   819,   827,   937,   807,   439,   784,
     785,   841,   938,   944,   804,   821,     0,   445,   408,   441,
     814,   749,   805,   806,   834,   809,   825,   833,   942,   945,
     755,   796,   836,   440,   824,   829,   736,     0,     0,   357,
     822,   832,   837,   835,   815,   801,   890,   799,   800,   939,
       0,   356,     0,   940,   946,   830,   786,   810,   941,   386,
       0,   418,   831,   813,   820,   828,   823,   891,   777,   782,
     781,   780,   779,   778,   745,   798,     0,   748,   844,   770,
     877,   876,   878,   754,   753,   773,   883,   738,   875,   880,
     881,   872,   776,   818,   874,   884,   882,   873,   774,   879,
     893,   896,   897,   894,   895,   892,   746,   898,   899,   901,
     864,   863,   850,   768,   761,   857,   853,   771,   767,   866,
     867,   757,   758,   751,   760,   862,   861,   858,   854,   871,
     865,   860,   856,   849,   759,   870,   869,   763,   765,   764,
     855,   859,   851,   766,   852,   762,   868,   923,   924,   925,
     926,   927,   928,   904,   905,   903,   909,   910,   911,   906,
     907,   908,   775,   929,   930,   931,   932,   933,   934,   935,
       0,     0,     4,     2,     0,     9,    11,    19,     0,     0,
      24,    26,    35,    28,    29,    30,    56,    31,    40,    36,
      60,    61,    62,    57,    58,    64,    65,    34,    32,    33,
      38,    39,    59,   209,   208,   205,   206,   207,    37,    18,
     185,   186,   190,   192,   224,   230,     0,     0,   222,   223,
     193,   194,   195,   196,   197,   312,   314,   316,   326,   330,
     332,   335,   340,   343,   346,   348,   350,   352,     0,   354,
     360,   362,     0,   378,   361,   382,   385,   387,   390,   392,
       0,   397,   394,     0,   405,   415,   417,   391,   421,   428,
     437,   429,   430,   431,   434,   435,   432,   433,   452,   454,
     455,   456,   453,   501,   502,   503,   504,   505,   506,   414,
     547,   539,   546,   545,   544,   541,   543,   540,   542,   438,
     436,   574,   575,    63,   198,   199,   201,   200,   202,   203,
     204,   416,   731,   838,   847,   845,   508,   748,     0,   512,
       0,   518,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     113,   114,     0,     0,     0,     0,   109,   110,   111,   112,
     119,     0,     0,     0,     0,     0,     0,     0,   107,   166,
     169,   172,   171,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   232,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   410,   413,   400,     0,
       0,   733,   756,   735,   900,   787,   848,   737,   797,   788,
     739,   902,   808,   742,   744,   743,   826,   936,   943,   732,
     937,   938,   944,   809,   942,   945,   890,   939,   940,   946,
     941,   891,   883,   875,   881,   872,   774,   893,   896,   897,
     894,   746,   898,   901,   406,   416,   731,   398,   399,   402,
     733,   734,   735,   739,   740,   741,   742,   732,   738,   442,
       0,   404,   403,   443,     0,   468,     0,   409,   729,     0,
     730,   381,     0,   412,   411,   401,   384,     0,     0,   497,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     156,   153,   164,   165,     0,     0,     0,     0,     6,     3,
       1,     5,    10,    12,     0,     0,     0,     0,     0,     0,
       0,   188,   187,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   210,   229,   225,   231,   226,   228,   227,   234,
     235,     0,     0,     0,     0,   371,     0,     0,   369,     0,
     321,     0,   370,   363,   368,   367,   366,   365,   364,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   359,   358,   355,
       0,   379,   383,     0,     0,     0,   393,   425,   396,   395,
     407,     0,   422,     0,     0,   509,   513,   519,   728,    82,
      67,    68,   147,   148,     0,     0,   168,     0,   167,     0,
      73,    74,     0,   170,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   584,   585,   586,   116,   115,
       0,    72,   123,   120,     0,   122,   121,   118,   117,     0,
       0,     0,   108,     0,     0,   553,     0,     0,     0,   549,
       0,     0,     0,   563,     0,     0,     0,   212,   213,     0,
       0,     0,   149,     0,   179,     0,   577,     0,     0,    91,
       0,     0,     0,    83,   247,   248,     0,   233,     0,     0,
     554,     0,     0,     0,     0,     0,   295,     0,     0,   552,
       0,     0,     0,   571,     0,     0,     0,     0,   557,     0,
       0,     0,   444,   469,   468,   465,     0,     0,   499,   498,
     380,     0,   496,     0,   597,   598,   548,     0,     0,     0,
       0,     0,     0,   603,     0,     0,   162,     0,     0,     0,
     250,   267,     7,    20,    21,     0,    25,    15,   838,    27,
      16,   191,     0,     0,     0,     0,     0,   211,   268,     0,
       0,     0,     0,     0,     0,     0,     0,   313,   315,   319,
     325,   324,   323,     0,   320,   317,   318,     0,   334,   333,
     331,   337,   338,   339,   336,   341,   342,   345,   344,     0,
       0,     0,     0,   376,     0,   388,   389,     0,   426,   423,
     450,     0,   576,   448,     0,     0,     0,     0,    71,     0,
       0,    46,    48,    49,    50,    51,    53,    54,    55,    47,
      52,    42,    43,     0,     0,    99,     0,    95,    97,    98,
     102,   105,     0,     0,     0,    41,    81,     0,     0,     0,
       0,     0,     0,     0,   679,   684,     0,     0,   680,   713,
     667,   669,   670,   671,   673,   675,   674,   672,   676,     0,
       0,     0,   124,     0,     0,   127,     0,     0,   517,   507,
     550,   551,     0,     0,   567,     0,   564,   616,     0,     0,
     214,   215,     0,   220,   181,     0,     0,   150,     0,     0,
       0,     0,     0,     0,    84,     0,     0,     0,     0,     0,
       0,   556,   555,   562,   570,     0,     0,     0,     0,     0,
     516,     0,     0,     0,   372,     0,     0,     0,     0,   560,
       0,   558,     0,   468,   466,     0,   457,     0,   446,   447,
       0,    13,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   838,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   189,   221,     0,
     279,   275,   277,     0,   269,   270,     0,   848,   736,     0,
     745,   524,   525,   531,   532,   534,   578,   579,   535,   538,
       0,   237,     0,     0,     0,     0,     0,     0,     0,   322,
       0,     0,     0,     0,   645,   328,   618,   622,   624,   626,
     628,   631,   638,   639,   647,   347,   349,   351,   522,   353,
     377,   427,     0,   424,   449,    79,    80,    77,    78,   174,
       0,   173,     0,     0,    44,     0,     0,   100,   101,   103,
       0,   104,    69,    70,    75,    76,    66,   685,     0,   688,
     714,     0,   678,   677,   682,   681,   712,     0,     0,   690,
       0,   686,   689,   668,     0,     0,     0,     0,     0,     0,
       0,   125,   131,     0,     0,     0,     0,     0,     0,   128,
       0,     0,     0,     0,     0,   571,     0,     0,     0,     0,
     216,     0,     0,     0,     0,   261,     0,   258,   263,   219,
     182,   151,   180,     0,   183,     0,     0,    93,    87,    90,
      89,     0,    85,     0,   252,     0,     0,     0,     0,   161,
       0,   293,   297,     0,     0,     0,   300,     0,     0,     0,
     307,     0,   374,   373,     0,     0,     0,   294,   469,     0,
     458,     0,   492,   489,     0,   493,   494,     0,   495,   488,
       0,   463,   491,   490,     0,     0,     0,   590,   591,   587,
       0,     0,   595,   596,   592,   601,   599,     0,     0,     0,
     605,   159,   158,     0,   155,   154,   163,     0,   606,   607,
       0,     0,    22,    17,   276,   288,     0,   289,     0,   280,
     281,   282,   283,     0,   272,     0,   236,     0,     0,     0,
       0,   528,   530,   529,   526,   245,   246,   239,     0,   241,
     238,     0,     0,     0,     0,     0,   629,   642,     0,   327,
     329,     0,   661,     0,     0,     0,     0,     0,     0,   617,
     619,   620,   656,   657,   658,   660,   659,     0,     0,   633,
     632,     0,   636,   640,   654,   652,   651,   644,   648,   523,
     451,     0,   176,   175,   178,     0,    45,    96,   106,   701,
     683,     0,   706,     0,   706,   697,   691,   126,   132,   134,
     133,     0,     0,     0,   129,     0,    23,   510,     0,   568,
     569,   572,   565,   566,   256,     0,     0,     0,   218,   259,
     262,     0,   152,     0,    92,     0,    86,   249,   254,   253,
       0,   520,     0,   296,   298,   303,     0,   301,     0,     0,
       0,     0,     0,   308,   375,   514,     0,   561,   559,   468,
       0,     0,   500,   468,     0,   464,    14,     0,     0,     0,
       0,     0,   604,     0,     0,   157,   613,     0,   608,     0,
     251,   292,   290,   291,   284,   285,   286,   278,     0,   273,
     271,     0,     0,   536,     0,   533,   583,   527,   243,   240,
       0,   242,   646,   637,   643,     0,     0,   715,   716,   726,
     725,   724,     0,     0,     0,     0,   717,   623,   723,     0,
     621,   625,     0,     0,   630,   634,     0,   655,   650,   653,
     649,   184,     0,   702,     0,     0,   700,   707,   708,   704,
       0,   699,     0,   695,     0,   692,   693,     0,     0,     0,
     130,     0,   511,   257,   265,   266,   260,   217,     0,     0,
      88,   255,   521,     0,   304,   302,     0,     0,     0,     0,
     515,     0,   468,     0,     0,   468,   588,   589,   593,   594,
     600,   602,   160,     0,     0,   609,   615,   287,   274,     0,
     580,     0,     0,   244,   641,   727,     0,     0,   719,     0,
     666,   665,   664,   663,   662,   627,     0,   718,   177,   711,
     710,   709,     0,   703,   698,     0,   687,     0,   135,   137,
     139,     0,     0,     0,     0,     0,     0,   311,    94,   299,
       0,   309,     0,   305,   478,   472,   467,     0,   468,   459,
       0,     0,   614,   581,   537,     0,   721,   720,     0,     0,
     705,   696,   694,     0,   141,   140,     0,     0,     0,     0,
     136,     0,     0,     0,   486,   480,     0,   479,   481,   487,
     484,   474,     0,   473,   475,   485,   461,     0,   460,     0,
     582,   722,   635,   138,   142,     0,     0,     0,     0,   264,
       0,   306,   471,   482,   483,   470,   476,   477,   462,     0,
       0,   143,     0,     0,     0,   310,     0,   610,     0,     0,
       0,     0,     0,   145,     0,     0,     0,   144,     0,     0,
     611,     0,     0,     0,     0,     0,   612,     0,     0,     0,
       0,   146
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1336, -1336,  -203,   858, -1336,   855,   864, -1336,   862,  -231,
    -525,  -554, -1336,   439,  -727, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,  -915,
   -1336, -1336, -1336, -1336,    47,   247,   727, -1336, -1336,   702,
   -1336,     8,  -884, -1336,  -400,  -426, -1336, -1336,  -566, -1336,
    -894, -1336, -1336,   -83, -1336, -1336, -1336, -1336, -1336,   258,
     728, -1336, -1336, -1336,   201,   693, -1335,  -545,    71, -1336,
    -567,   374, -1336, -1336, -1336, -1336,   210, -1336, -1336,   839,
   -1336, -1336, -1336, -1336, -1336,   122,  -547,  -695, -1336, -1336,
   -1336,    -1, -1336, -1336,  -189,     9,   -79, -1336, -1336, -1336,
     -89, -1336, -1336,   138,   -85, -1336, -1336,   -80, -1191, -1336,
     621,     6, -1336, -1336,    -8, -1336, -1336, -1336,   -15, -1336,
   -1336,   553,   550, -1336,  -531, -1336, -1336,  -608,    54,  -607,
      53,    55, -1336, -1336, -1336, -1336, -1336,   844, -1336, -1336,
   -1336, -1336,  -810,  -310, -1071, -1336,  -117, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336,   -45, -1185, -1336, -1336,   267,   -59,
   -1336,  -792, -1336, -1336, -1336, -1336, -1336, -1336, -1336,   502,
   -1336,  -939, -1336,   -20, -1336,   394,  -750, -1336, -1336, -1336,
   -1336, -1336,  -414,  -404, -1141, -1097, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336,   322,  -725,  -811,    57,
    -804, -1336,  -157,  -774, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336,   730,   731,  -435,   245,    96, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336, -1336,
     -36, -1336, -1336,   -44, -1336, -1336,  -993, -1336, -1336, -1336,
     -93,  -102,  -246,   135, -1336, -1336, -1336, -1336, -1336, -1336,
   -1336, -1336, -1336, -1336, -1336, -1336, -1336,   -90, -1336, -1336,
   -1336,  -238,   131,   275, -1336, -1336, -1336, -1336, -1336,    83,
   -1336, -1336, -1261, -1336, -1336,  -742, -1336,  -119, -1336,  -249,
   -1336, -1336, -1336, -1336, -1214, -1336,   -78, -1336,  -380,  -382,
      44,   -72
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   861,   862,   863,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,  1137,
     722,   266,   267,   867,   868,   869,  1201,   268,   417,   418,
     269,  1101,   902,   270,  1508,  1509,   271,   272,   436,   273,
     551,   775,   987,  1202,   274,   275,   276,   277,   278,   419,
     420,   421,   422,   713,   714,  1178,  1061,   279,   280,   572,
     281,   282,   283,   582,   434,   922,   923,   284,   583,   285,
     585,   286,   287,   288,   589,   590,  1125,   805,   289,   724,
     779,   725,   710,  1126,  1127,  1128,   780,   586,   587,  1004,
    1005,  1379,   588,  1001,  1002,  1219,  1220,  1221,  1222,   290,
     735,   736,   291,  1155,  1156,  1157,   292,  1159,  1160,   293,
     294,   295,   296,   813,   297,  1249,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   609,   610,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   636,   637,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   841,
     337,   338,   339,  1180,   754,   755,   756,  1526,  1562,  1563,
    1556,  1557,  1564,  1558,  1181,  1182,   340,   341,  1183,   342,
     343,   344,   345,   346,   347,   348,  1047,   806,  1011,  1234,
    1012,  1384,  1013,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   742,  1114,   359,   360,   361,   362,  1015,
    1016,  1017,  1018,   363,   364,   365,   366,   367,   368,   772,
     773,   369,  1208,  1209,  1367,   370,  1035,  1259,  1260,  1036,
    1037,  1038,  1039,  1040,  1269,  1414,  1415,  1041,  1272,  1042,
    1395,  1043,  1044,  1277,  1278,  1420,  1418,  1261,  1262,  1263,
    1264,  1493,   681,   890,   891,   892,   893,   894,   895,  1091,
    1434,  1435,  1092,  1433,   896,  1294,  1430,  1426,  1427,  1428,
     897,   898,  1265,  1273,  1405,  1266,  1401,  1250,  1138,   529,
     371,   372
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       506,   939,   631,   649,   965,   792,   820,  1033,   821,   822,
     823,   824,   949,   536,   506,   789,   567,   674,  1045,  1046,
    1142,  1109,  1366,   787,   790,  1034,  1014,   504,  1179,  1375,
    1376,   938,  1475,     8,  1301,  1436,   506,   558,  1245,  1355,
     561,   693,   879,   786,   804,   880,   919,   800,   506,   538,
     506,  1511,   800,   758,   801,  1014,  1014,  1416,   719,   723,
    1066,   731,   697,   809,   452,   810,   811,  1402,   812,  1554,
     814,   801,  1146,  1172,   972,   378,   380,   382,   815,   816,
     913,   900,   698,  1338,  1458,   648,  1524,   648,   881,   966,
    1014,   847,   946,   937,  1108,  1206,   570,   654,   915,  1486,
     570,  1231,   711,   802,   438,  1203,  1397,   660,   423,  1024,
    1490,  1028,   655,   630,  1131,    78,   505,  1491,  1172,  1173,
    1026,   453,   983,   926,  1247,  1170,  1102,  1492,    89,   958,
     519,   570,  1232,   439,  1064,  1094,   122,  1424,   661,   612,
    1251,  1095,   697,  1023,  1398,  1069,   800,   122,  1064,  1233,
    1459,  1014,   525,   103,   967,  1512,   613,  1030,   914,  1096,
    1031,  1097,   698,  1241,   530,  1172,   532,  1339,  1283,   712,
    1098,   947,   720,  1525,   946,  1487,   916,   571,   524,  1560,
     122,   997,  1175,  1477,  1176,  1554,  1204,   454,   455,  1172,
    1171,   976,  1555,  1119,   973,   974,  1099,   948,   632,  1130,
    1425,   927,   803,   699,   920,  1229,  1498,   959,  1174,   975,
    1355,  1252,   715,  1169,   759,   506,   718,  1297,   721,  1505,
     901,  1033,  1033,   803,  1403,  1404,  1326,  1175,   803,  1176,
     789,   539,  1179,   901,  1441,  1014,  1251,   882,  1513,  1034,
    1034,  1179,   921,   960,  1147,   803,  1542,   984,   506,  1490,
     883,   506,   884,   962,  1394,  1597,  1491,   715,   786,  1027,
    1052,   108,  1032,   885,   886,   887,  1492,   888,   803,   889,
    1052,  1610,  1172,  1173,  1175,   638,  1176,   120,   640,  1616,
    1481,   991,  1029,  1062,  1063,  1561,  1172,  1173,   803,  1532,
     800,  1502,   876,  1253,  1254,   970,  1255,  1177,  1175,   669,
    1176,  1589,   670,  1256,   715,  1291,  1082,  1252,  1583,  1605,
    1216,   977,   978,  1257,   426,   146,   657,  1083,   506,  1544,
    1100,   961,  1322,   506,   615,  1258,   979,   506,   715,   564,
    1218,   591,  1242,   506,  1102,   671,   930,   785,  1053,   933,
     506,  1118,   934,   992,  1088,   547,   565,  1341,  1054,   430,
     548,   506,   616,   971,  1574,   427,   782,   506,  1482,  1014,
    1089,   672,  1174,  1293,   505,   617,  1510,   505,   506,  1503,
     435,   506,   506,   506,   506,   506,  1174,  1291,  1121,  1590,
     506,  1175,   612,  1176,  1014,  1122,   431,  1606,   506,  1253,
    1254,   432,  1255,  1292,  1121,  1175,  1055,  1176,   618,   613,
    1172,  1122,  1090,  1060,   440,   871,  1473,  1057,   441,  1257,
     872,   715,  1179,  1056,  1560,   108,  1383,  1172,  1173,  1123,
    1440,  1258,   673,     8,  1058,   715,  1121,  1559,  1565,   108,
     864,   120,   437,  1122,   659,  1293,   433,  1033,   801,   665,
     541,   789,   542,   530,  1510,   120,  1033,  1059,   506,   682,
    1213,  1350,   446,  1014,   621,  1034,   684,  1033,  1474,  1124,
    1559,   650,   612,  1060,  1034,  1354,  1565,   530,   622,   146,
     801,   865,  1510,   705,   651,  1034,   866,   506,  1113,   613,
    1116,  1084,   444,   146,   726,   506,  1282,   530,   732,   733,
     734,   737,  1085,  1072,  1073,   694,   743,   696,  1076,   702,
     445,   614,   550,   800,   750,    78,   458,  1174,   717,  1175,
     865,  1176,   612,   728,  1216,   866,   835,   836,    89,   738,
    1586,   740,   741,  1165,   744,  1166,  1175,  1111,  1176,   613,
     747,  1607,   447,  1608,  1518,   573,   450,   459,  1215,   715,
     460,   574,   456,   103,   652,   388,   575,  1030,  1216,  1621,
    1031,  1538,   993,  1284,   576,  1088,   715,   653,  1217,  1154,
     108,  1274,  1275,   392,   737,   393,   577,   400,  1218,  1285,
     122,  1089,  1336,  1158,   394,  1399,   120,   838,   619,  1106,
     838,   451,  1400,   838,  1276,   457,  1342,   620,  1107,   639,
     849,   526,   850,   774,   642,   506,  1463,   757,   401,  1461,
     520,   781,  1033,  1464,  1077,  1078,  1079,   507,   761,   424,
    1080,   508,   425,   428,   146,   509,   429,   506,   506,   506,
    1034,   442,   448,   521,   443,   449,   403,   778,   675,   676,
     677,   544,   635,   545,   641,   522,  1185,   506,  1186,   506,
    1190,   527,  1191,   633,   634,   656,   506,   658,   533,   506,
    1409,   678,   679,   534,   687,   688,  1074,  1075,   789,  1103,
    1104,   535,   578,  1372,  1373,   579,   818,   819,  1533,   537,
    1534,   543,   825,   826,  1048,  1048,   827,   828,   540,   580,
     549,   506,  1499,  1500,   690,   406,   407,   408,   409,   546,
     410,   411,   691,   413,   414,   550,   554,   555,   556,   415,
     557,   834,   552,   560,   581,  1014,   837,  1014,   593,  1552,
     553,   870,  1527,     1,   568,  1530,   569,   592,  1422,   611,
     623,   506,   624,   631,  1570,   625,   635,   626,   506,   643,
     644,   645,   646,   904,   905,   906,   851,   852,   853,   854,
     855,   856,   857,   858,   859,   860,  1014,   647,   648,   662,
     388,   664,   666,   918,   667,   924,  1324,   506,   506,   506,
     506,  1014,   530,   680,   685,   530,   683,   707,   689,   695,
     686,   708,   709,   715,   727,   739,   752,   425,  1567,   745,
     746,   429,   753,   760,   443,  1545,   928,   449,   460,  1485,
     762,   766,   506,   763,   771,  1488,  1489,   963,   783,   784,
     793,   794,   799,   817,   706,   829,   795,   796,   506,   830,
     831,   832,   842,   845,   846,   848,   955,   956,   873,   874,
     877,   878,   899,   907,   908,   909,   910,   903,   912,   911,
     917,   594,   925,   931,   929,   932,  1371,   998,   935,   595,
     596,   506,   597,   506,  1019,   936,   988,   940,   941,   945,
     598,   942,   943,   506,   599,   950,   600,   944,   954,   951,
     952,   601,   953,   957,   980,   968,   969,   982,   985,   981,
     989,   990,   994,  1019,  1019,  1019,  1019,   602,  1536,  1537,
     999,   995,  1003,  1050,  1006,  1020,   506,  1065,   506,  1022,
    1025,   866,  1051,   800,  1070,  1086,  1087,  1110,  1112,  1120,
     603,   604,   605,   606,   607,   608,   711,  1133,  1019,  1136,
    1105,  1134,  1135,  1139,  1140,   764,   765,  1141,   767,   768,
     769,   770,  1143,  1145,  1081,  1148,  1150,  1153,   776,   777,
    1571,   506,  1154,  1158,   506,  1168,  1164,   506,  1184,  1162,
    1163,  1198,  1205,  1211,   791,  1450,  1210,  1212,   506,   671,
     506,  1223,  1225,  1238,   797,   798,  1207,  1115,  1227,  1115,
    1228,  1230,  1243,  1248,   387,  1279,     8,  1290,  1267,  1019,
     388,  1289,  1295,   901,  1306,  1299,  1268,  1309,   389,  1300,
     390,  1302,  1303,  1315,  1271,  1305,  1310,  1312,   392,  1311,
     393,  1316,  1317,  1321,  1313,  1325,  1330,  1344,  1478,   394,
    1352,  1349,   743,   395,   743,  1356,  1347,  1357,  1361,  1348,
    1358,  1363,  1364,  1216,  1378,   840,  1385,  1392,   840,  1359,
    1360,  1386,  1390,  1387,  1161,  1412,  1393,  1396,  1419,  1413,
    1421,  1417,  1423,  1406,   396,   397,   996,  1429,  1088,  1432,
    1442,  1437,  1448,  1449,  1452,  1453,  1460,  1224,  1439,  1457,
     591,  1479,   506,  1019,  1496,  1504,  1515,  1476,  1507,  1516,
    1484,   506,  1480,  1520,  1235,  1506,  1236,  1535,  1531,  1540,
    1543,   506,  1547,  1497,  1541,  1529,  1548,  1551,   506,  1553,
    1566,  1514,  1572,  1568,  1577,  1578,   506,  1580,  1582,  1594,
    1585,   400,  1588,  1596,  1060,  1609,  1618,  1614,   559,   562,
    1575,  1244,  1592,  1599,  1598,   506,  1617,  1611,   563,   566,
     875,  1613,  1067,  1287,  1602,  1550,  1304,  1573,  1604,   692,
    1365,   663,   401,  1620,   668,   584,   506,  1132,  1226,   716,
    1446,  1281,  1370,  1129,  1320,   506,  1380,  1214,  1377,   506,
    1374,   751,  1327,   808,  1343,   807,   844,  1337,   964,  1587,
     403,  1351,   629,  1584,  1049,   506,  1333,   700,   701,  1298,
    1117,  1286,  1362,  1407,  1368,  1411,  1495,  1246,  1319,  1000,
    1410,  1494,  1270,  1296,  1093,  1431,  1021,  1019,  1501,  1408,
       0,     0,   404,  1308,     0,     0,     0,   726,     0,     0,
       0,     0,     0,     0,   737,     0,     0,     0,     0,     0,
       0,     0,  1019,     0,     0,     0,     0,     0,   405,   406,
     407,   408,   409,     0,   410,   411,   412,   413,   414,  1332,
       0,  1353,     0,   415,   416,     0,     0,     0,     0,     0,
     506,     0,     0,     0,     0,  1346,     0,     0,     0,     0,
    1068,     0,   774,     0,   506,   506,  1071,     0,     0,     0,
       0,   505,     0,     0,     0,   781,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   506,     0,
       0,  1019,     0,     0,     0,     0,     0,     0,   506,     0,
       0,     0,   506,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1144,     0,     0,     0,     0,     0,     0,     0,  1149,
       0,  1151,  1152,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1167,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1438,  1187,  1188,  1189,
       0,  1192,  1193,  1194,  1195,  1196,  1197,     0,  1199,  1200,
    1444,  1445,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1000,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1456,     0,   506,     0,     0,     0,
       0,   506,     0,     0,  1462,     0,     0,  1237,  1465,  1239,
    1240,     0,   506,     0,     0,     0,     0,   506,     0,   506,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1280,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   506,
       0,     0,   506,     0,  1288,     0,     0,     0,   506,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   506,
       0,     0,     0,   506,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   506,     0,     0,     0,   506,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1314,     0,     0,     0,     0,  1318,     0,     0,
       0,     0,  1522,     0,     0,   506,     0,  1528,     0,  1323,
       0,     0,     0,     0,     0,     0,     0,     0,   505,  1328,
    1329,     0,   506,  1019,   506,  1019,     0,  1334,  1335,     0,
       0,     0,     0,     0,     0,     0,     0,   506,     0,     0,
       0,   506,     0,     0,     0,     0,   506,     0,     0,     0,
       0,     0,     0,     0,     0,  1546,     0,     0,  1549,     0,
       0,     0,     0,     0,  1019,     0,     0,  1539,     0,     0,
       0,     0,     0,     0,     0,  1569,     0,     0,     0,  1019,
       0,     0,     0,     0,  1369,     0,     0,     0,     0,     0,
       0,  1576,     0,     0,     0,  1579,     0,  1000,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1388,     0,     0,  1389,     0,  1391,     0,     0,
       0,  1593,   383,   384,     0,   385,   386,     0,   387,     0,
       0,     0,     0,     0,   388,     0,     0,     0,  1600,     0,
    1601,     0,   389,     0,   390,   391,     0,     0,     0,     0,
       0,     0,   392,  1612,   393,     0,     0,  1615,     0,     0,
       0,     0,  1619,   394,     0,     0,     0,   395,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1443,
       0,     0,     0,     0,     0,  1447,     0,     0,   396,   397,
     398,     0,     0,     0,  1451,     0,     0,     0,     0,     0,
       0,     0,  1454,  1455,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1466,  1467,  1468,  1469,  1470,     0,  1471,  1472,     0,
       0,     0,     0,     0,     0,     0,   399,     0,     0,     0,
       0,     0,     0,     0,     0,   400,     0,     0,     0,     0,
       0,     0,     0,     0,  1483,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   401,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   402,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   403,     0,     0,     0,     0,     0,
       0,     0,  1517,     0,     0,     0,     0,  1519,     0,     0,
       0,  1521,     0,  1523,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   404,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   405,   406,   407,   408,   409,     0,   410,   411,
     412,   413,   414,     0,     0,     0,     0,   415,   416,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1581,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1591,
       1,     0,     0,     0,  1595,     0,     0,     2,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     0,
       8,     0,     0,  1603,     9,    10,     0,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,     0,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,    72,    73,    74,    75,     0,     0,    76,    77,     0,
       0,     0,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,     0,     0,    89,     0,    90,    91,    92,
      93,     0,    94,     0,     0,     0,    95,    96,    97,    98,
      99,     0,     0,     0,     0,     0,     0,   100,   101,   102,
     103,   104,   105,   106,     0,     0,     0,   107,   108,   109,
     110,   111,     0,     0,     0,     0,   112,   113,   114,   115,
     116,   117,   118,   119,   120,     0,   121,   122,     0,     0,
     123,   124,   125,     0,     0,     0,   126,     0,   127,   128,
       0,   129,   130,   131,     0,   132,     0,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,     0,     0,
     144,   145,   146,     0,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,     0,   191,
     192,   193,     0,   194,   195,   196,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,     1,     0,     0,     0,     0,     0,     0,     2,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       0,     8,     0,     0,     0,     9,    10,     0,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,     0,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,    72,    73,    74,    75,     0,     0,    76,    77,
       0,     0,     0,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,     0,     0,    89,     0,    90,    91,
      92,    93,     0,    94,     0,     0,     0,    95,    96,    97,
      98,    99,     0,     0,     0,     0,     0,     0,   100,   101,
     102,   103,   104,   105,   106,     0,     0,     0,   107,   108,
     109,   110,   111,     0,     0,     0,     0,   112,   113,   114,
     115,   116,   117,   118,   119,   120,     0,   121,   122,     0,
       0,   123,   124,   125,     0,     0,     0,   126,     0,   127,
     128,     0,   129,   130,   131,     0,   132,     0,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,     0,
       0,   144,   145,   146,     0,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
     191,   192,   193,     0,   194,   195,   196,   197,   198,   199,
       0,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,     2,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     0,     8,     0,     0,     0,   373,   374,
       0,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,   375,    26,    27,    28,    29,
       0,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,    72,    73,    74,    75,     0,
       0,    76,    77,     0,     0,     0,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,     0,     0,    89,
       0,    90,    91,    92,    93,     0,    94,     0,     0,     0,
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   104,   105,   106,     0,     0,
       0,   107,   108,   109,   110,   111,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,   120,     0,
     121,   122,     0,     0,   123,   124,   125,     0,   376,     0,
     126,     0,   127,   128,     0,   129,   130,   131,     0,   132,
       0,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,     0,     0,   144,   145,   146,     0,   377,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,     0,   191,   192,   193,     0,   194,   195,   196,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,     2,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     0,     8,     0,     0,
       0,   373,   374,     0,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,   375,    26,
      27,    28,    29,     0,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,    72,    73,
      74,    75,     0,     0,    76,    77,     0,     0,     0,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
       0,     0,    89,     0,    90,    91,    92,    93,     0,    94,
       0,     0,     0,    95,    96,    97,    98,    99,     0,     0,
       0,     0,     0,     0,   100,   101,   102,   103,   104,   105,
     106,     0,     0,     0,   107,   108,   109,   110,   111,     0,
       0,     0,     0,   112,   113,   114,   115,   116,   117,   118,
     119,   120,     0,   121,   122,     0,     0,   123,   124,   125,
       0,   379,     0,   126,     0,   127,   128,     0,   129,   130,
     131,     0,   132,     0,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,     0,     0,   144,   145,   146,
       0,   377,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,     0,   191,   192,   193,     0,
     194,   195,   196,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,     2,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     0,
       8,     0,     0,     0,   373,   374,     0,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,   375,    26,    27,    28,    29,     0,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,    72,    73,    74,    75,     0,     0,    76,    77,     0,
       0,     0,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,     0,     0,    89,     0,    90,    91,    92,
      93,     0,    94,     0,     0,     0,    95,    96,    97,    98,
      99,     0,     0,     0,     0,     0,     0,   100,   101,   102,
     103,   104,   105,   106,     0,     0,     0,   107,   108,   109,
     110,   111,     0,     0,     0,     0,   112,   113,   114,   115,
     116,   117,   118,   119,   120,     0,   121,   122,     0,     0,
     123,   124,   125,     0,   381,     0,   126,     0,   127,   128,
       0,   129,   130,   131,     0,   132,     0,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,     0,     0,
     144,   145,   146,     0,   377,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,     0,   191,
     192,   193,     0,   194,   195,   196,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
       2,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     0,     8,     0,     0,     0,   373,   374,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,   375,    26,    27,    28,    29,     0,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,    72,    73,    74,    75,     0,     0,
      76,    77,     0,     0,     0,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,     0,     0,    89,     0,
      90,    91,    92,    93,     0,    94,     0,     0,     0,    95,
      96,    97,    98,    99,     0,     0,     0,     0,     0,     0,
     100,   101,   102,   103,   104,   105,   106,     0,     0,     0,
     107,   108,   109,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,   120,     0,   121,
     122,     0,     0,   123,   124,   125,     0,     0,     0,   126,
     523,   127,   128,     0,   129,   130,   131,     0,   132,     0,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,     0,     0,   144,   145,   146,     0,   377,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,     0,   191,   192,   193,     0,   194,   195,   196,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,     2,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     0,     8,     0,     0,     0,
     373,   374,     0,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,   375,    26,    27,
      28,    29,     0,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,    72,    73,    74,
      75,     0,     0,    76,    77,     0,     0,     0,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,     0,
       0,    89,     0,    90,    91,    92,    93,     0,    94,     0,
       0,     0,    95,    96,    97,    98,    99,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,   104,   105,   106,
       0,     0,     0,   107,   108,   109,   110,   111,     0,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
     120,     0,   121,   122,     0,     0,   123,   124,   125,     0,
     833,     0,   126,     0,   127,   128,     0,   129,   130,   131,
       0,   132,     0,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,     0,     0,   144,   145,   146,     0,
     377,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,     0,   191,   192,   193,     0,   194,
     195,   196,   197,   198,   199,     0,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,     2,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     0,     8,
       0,     0,     0,   373,   374,     0,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
     375,    26,    27,    28,    29,     0,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
      72,    73,    74,    75,     0,     0,    76,    77,     0,     0,
       0,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,     0,     0,    89,     0,    90,    91,    92,    93,
       0,    94,     0,     0,     0,    95,    96,    97,    98,    99,
       0,     0,     0,     0,     0,     0,   100,   101,   102,   103,
     104,   105,   106,     0,     0,     0,   107,   108,   109,   110,
     111,     0,     0,     0,     0,   112,   113,   114,   115,   116,
     117,   118,   119,   120,     0,   121,   122,     0,     0,   123,
     124,   125,     0,     0,     0,   126,   839,   127,   128,     0,
     129,   130,   131,     0,   132,     0,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,     0,     0,   144,
     145,   146,     0,   377,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,     0,   191,   192,
     193,     0,   194,   195,   196,   197,   198,   199,     0,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,     2,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     0,     8,     0,     0,     0,   373,   374,     0,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,   375,    26,    27,    28,    29,     0,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,    72,    73,    74,    75,     0,     0,    76,
      77,     0,     0,     0,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,     0,     0,    89,     0,    90,
      91,    92,    93,     0,    94,     0,     0,     0,    95,    96,
      97,    98,    99,     0,     0,     0,     0,     0,     0,   100,
     101,   102,   103,   104,   105,   106,     0,     0,     0,   107,
     108,   109,   110,   111,     0,     0,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,   120,     0,   121,   122,
       0,     0,   123,   124,   125,     0,     0,     0,   126,   843,
     127,   128,     0,   129,   130,   131,     0,   132,     0,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
       0,     0,   144,   145,   146,     0,   377,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
       0,   191,   192,   193,     0,   194,   195,   196,   197,   198,
     199,     0,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,     2,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     0,     8,     0,     0,     0,   373,
     374,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,   375,    26,    27,    28,
      29,     0,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,    72,    73,    74,    75,
       0,     0,    76,    77,     0,     0,     0,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,     0,     0,
      89,     0,    90,    91,    92,    93,     0,    94,     0,     0,
       0,    95,    96,    97,    98,    99,     0,     0,     0,     0,
       0,     0,   100,   101,   102,   103,   104,   105,   106,     0,
       0,     0,   107,   108,   109,   110,   111,     0,     0,     0,
       0,   112,   113,   114,   115,   116,   117,   118,   119,   120,
       0,   121,   122,     0,     0,   123,   124,   125,     0,  1307,
       0,   126,     0,   127,   128,     0,   129,   130,   131,     0,
     132,     0,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,     0,     0,   144,   145,   146,     0,   377,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,     0,   191,   192,   193,     0,   194,   195,
     196,   197,   198,   199,     0,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,     2,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     0,     8,     0,
       0,     0,   373,   374,     0,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,   375,
      26,    27,    28,    29,     0,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,    72,
      73,    74,    75,     0,     0,    76,    77,     0,     0,     0,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,     0,     0,    89,     0,    90,    91,    92,    93,     0,
      94,     0,     0,     0,    95,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,   104,
     105,   106,     0,     0,     0,   107,   108,   109,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,   120,     0,   121,   122,     0,     0,   123,   124,
     125,     0,  1331,     0,   126,     0,   127,   128,     0,   129,
     130,   131,     0,   132,     0,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,     0,     0,   144,   145,
     146,     0,   377,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,     0,   191,   192,   193,
       0,   194,   195,   196,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,     2,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       0,     8,     0,     0,     0,   373,   374,     0,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,   375,    26,    27,    28,    29,     0,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,    72,    73,    74,    75,     0,     0,    76,    77,
       0,     0,     0,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,     0,     0,    89,     0,    90,    91,
      92,    93,     0,    94,     0,     0,     0,    95,    96,    97,
      98,    99,     0,     0,     0,     0,     0,     0,   100,   101,
     102,   103,   104,   105,   106,     0,     0,     0,   107,   108,
     109,   110,   111,     0,     0,     0,     0,   112,   113,   114,
     115,   116,   117,   118,   119,   120,     0,   121,   122,     0,
       0,   123,   124,   125,     0,  1345,     0,   126,     0,   127,
     128,     0,   129,   130,   131,     0,   132,     0,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,     0,
       0,   144,   145,   146,     0,   377,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
     191,   192,   193,     0,   194,   195,   196,   197,   198,   199,
       0,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,     2,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     0,     8,     0,     0,     0,     9,    10,
       0,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
       0,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,    72,    73,    74,    75,     0,
       0,    76,    77,     0,     0,     0,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,     0,     0,    89,
       0,    90,    91,    92,    93,     0,    94,     0,     0,     0,
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   104,   105,   106,     0,     0,
       0,   107,   108,   109,   110,   111,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,   120,     0,
     121,   122,     0,     0,   123,   124,   125,     0,     0,     0,
     126,     0,   127,   128,     0,   129,   130,   131,     0,   132,
       0,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,     0,     0,   144,   145,   146,     0,   377,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,     0,   191,   192,   193,     0,   194,   195,   196,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,     2,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     0,     8,     0,     0,
       0,   373,   374,     0,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   464,   465,    23,   467,   375,    26,
     468,    28,    29,     0,    30,    31,    32,    33,   469,    35,
      36,    37,    38,    39,    40,   471,    42,    43,   472,     0,
      45,    46,    47,   474,   475,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,    72,    73,
      74,    75,     0,     0,    76,    77,     0,     0,     0,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
       0,     0,    89,     0,    90,    91,    92,    93,     0,    94,
       0,     0,     0,   483,    96,    97,    98,    99,     0,     0,
       0,     0,     0,     0,   100,   101,   102,   103,   104,   105,
     106,     0,     0,     0,   107,   108,   627,   110,   111,     0,
       0,     0,     0,   112,   113,   114,   115,   116,   117,   118,
     119,   120,     0,   628,   122,     0,     0,   123,   124,   125,
       0,     0,     0,   126,     0,   127,   128,     0,   129,   130,
     131,     0,   132,     0,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,     0,     0,   144,   145,   146,
       0,   377,   148,   149,   150,   151,   152,   153,   154,   155,
     492,   157,   493,   159,   494,   495,   162,   163,   164,   165,
     166,   167,   496,   169,   497,   498,   499,   500,   174,   175,
     501,   502,   178,   503,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,     0,   191,   192,   193,     0,
     194,   195,   196,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,     2,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     0,
       8,     0,     0,     0,   373,   374,     0,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,   375,    26,    27,    28,    29,     0,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,    72,    73,    74,    75,     0,     0,    76,    77,     0,
       0,     0,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,     0,     0,    89,     0,    90,    91,    92,
      93,     0,    94,     0,     0,     0,    95,    96,    97,    98,
      99,     0,     0,     0,     0,     0,     0,   100,   101,   102,
     103,   104,   105,   106,     0,     0,     0,   107,   108,   109,
     110,   111,     0,     0,     0,     0,   112,   113,   114,   115,
     116,   117,   118,   119,   120,     0,   121,   122,     0,     0,
     123,   124,   125,     0,     0,     0,   126,     0,   127,   128,
       0,   129,   130,   131,     0,   132,     0,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,     0,     0,
     144,   145,   146,     0,   377,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,     0,   191,
     192,   193,     0,   194,   195,   196,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
       2,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     0,     8,     0,     0,     0,     9,   374,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,     0,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,    72,    73,    74,    75,     0,     0,
      76,    77,     0,     0,     0,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,     0,     0,    89,     0,
      90,    91,    92,    93,     0,    94,     0,     0,     0,    95,
      96,    97,    98,    99,     0,     0,     0,     0,     0,     0,
     100,   101,   102,   103,   104,   105,   106,     0,     0,     0,
     107,   108,   109,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,   120,     0,   121,
     122,     0,     0,   123,   124,   125,     0,     0,     0,   126,
       0,   127,   128,     0,   129,   130,   131,     0,   132,     0,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,     0,     0,   144,   145,   146,     0,   377,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,     0,   191,   192,   193,     0,   194,   195,   196,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,     2,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     0,     8,     0,     0,     0,
     788,   374,     0,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,   375,    26,    27,
      28,    29,     0,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,    72,    73,    74,
      75,     0,     0,    76,    77,     0,     0,     0,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,     0,
       0,    89,     0,    90,    91,    92,    93,     0,    94,     0,
       0,     0,    95,    96,    97,    98,    99,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,   104,   105,   106,
       0,     0,     0,   107,   108,   109,   110,   111,     0,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
     120,     0,   121,   122,     0,     0,   123,   124,   125,     0,
       0,     0,   126,     0,   127,   128,     0,   129,   130,   131,
       0,   132,     0,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,     0,     0,   144,   145,   146,     0,
     377,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,     0,   191,   192,   193,     0,   194,
     195,   196,   197,   198,   199,     0,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,     2,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     0,     8,
       0,     0,     0,   373,   374,     0,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,   464,   465,    23,   467,
     375,    26,   468,    28,    29,     0,    30,    31,    32,    33,
     469,    35,    36,    37,    38,    39,    40,   471,    42,    43,
     472,     0,    45,    46,    47,   474,   475,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
      72,    73,    74,    75,     0,     0,    76,    77,     0,     0,
       0,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,     0,     0,    89,     0,    90,    91,    92,    93,
       0,    94,     0,     0,     0,   483,    96,    97,    98,    99,
       0,     0,     0,     0,     0,     0,   100,   101,   102,   103,
     104,   105,   106,     0,     0,     0,   107,   108,   109,   110,
     111,     0,     0,     0,     0,   112,   113,   114,   115,   116,
     117,   118,   119,   120,     0,   121,   122,     0,     0,   123,
     124,   125,     0,     0,     0,   126,     0,   127,   128,     0,
     129,   130,   131,     0,   132,     0,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,     0,     0,   144,
     145,   146,     0,   377,   148,   149,   150,   151,   152,   153,
     154,   155,   492,   157,   493,   159,   494,   495,   162,   163,
     164,   165,   166,   167,   496,   169,   497,   498,   499,   500,
     174,   175,   501,   502,   178,   503,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,     0,   191,   192,
     193,     0,   194,   195,   196,   197,   198,   199,     0,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,     2,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     0,     8,     0,     0,     0,   986,   374,     0,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,   375,    26,    27,    28,    29,     0,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,    72,    73,    74,    75,     0,     0,    76,
      77,     0,     0,     0,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,     0,     0,    89,     0,    90,
      91,    92,    93,     0,    94,     0,     0,     0,    95,    96,
      97,    98,    99,     0,     0,     0,     0,     0,     0,   100,
     101,   102,   103,   104,   105,   106,     0,     0,     0,   107,
     108,   109,   110,   111,     0,     0,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,   120,     0,   121,   122,
       0,     0,   123,   124,   125,     0,     0,     0,   126,     0,
     127,   128,     0,   129,   130,   131,     0,   132,     0,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
       0,     0,   144,   145,   146,     0,   377,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
       0,   191,   192,   193,     0,   194,   195,   196,   197,   198,
     199,     0,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,     2,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     0,     8,     0,     0,     0,   373,
     374,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,   464,   465,    23,   467,   375,    26,   468,    28,
      29,     0,    30,    31,    32,    33,   469,    35,    36,    37,
      38,    39,    40,   471,    42,    43,   472,     0,    45,    46,
      47,   474,   475,    50,   476,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,    72,    73,    74,    75,
       0,     0,    76,    77,     0,     0,     0,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,     0,     0,
      89,     0,    90,    91,    92,    93,     0,    94,     0,     0,
       0,   483,    96,    97,    98,    99,     0,     0,     0,     0,
       0,     0,   100,   101,   102,   103,   104,   105,   106,     0,
       0,     0,   107,   108,     0,   110,   111,     0,     0,     0,
       0,   112,   113,   114,   115,   116,   117,   118,   119,   120,
       0,     0,     0,     0,     0,   123,   124,   125,     0,     0,
       0,   126,     0,   127,   128,     0,   129,   130,   131,     0,
     132,     0,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,     0,     0,   144,   145,   146,     0,   377,
     148,   149,   150,   151,   152,   153,   154,   155,   492,   157,
     493,   159,   494,   495,   162,   163,   164,   165,   166,   167,
     496,   169,   497,   498,   499,   500,   174,   175,   501,   502,
     178,   503,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,     0,   191,   192,   193,     0,   194,   195,
     196,   197,   198,   199,     0,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,     2,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     0,     8,     0,
       0,     0,   373,   374,     0,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,   464,   465,    23,   467,   375,
      26,   468,    28,    29,     0,    30,    31,    32,    33,   469,
      35,    36,    37,    38,    39,    40,   471,    42,    43,   472,
       0,    45,    46,    47,   474,   475,    50,   476,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,    72,
      73,    74,    75,     0,     0,    76,    77,     0,     0,     0,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,     0,     0,    89,     0,    90,    91,    92,    93,     0,
      94,     0,     0,     0,   483,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,   104,
     105,   106,     0,     0,     0,   107,   108,     0,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,   120,     0,     0,     0,     0,     0,   123,   124,
     125,     0,     0,     0,   126,     0,   127,   128,     0,     0,
       0,   131,     0,   132,     0,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,     0,     0,   144,   145,
     146,     0,   377,   148,   149,   150,   151,   152,   153,   154,
     155,   492,   157,   493,   159,   494,   495,   162,   163,   164,
     165,   166,   167,   496,   169,   497,   498,   499,   500,   174,
     175,   501,   502,   178,   503,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,     0,   191,   192,   193,
       0,   194,   195,   196,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,     2,     0,
       0,     0,     0,     0,     0,     3,     0,     0,     0,     7,
       0,     0,     0,     0,     0,   373,   374,     0,    11,    12,
     461,    14,    15,    16,    17,   462,    19,   463,   464,   465,
     466,   467,   375,    26,   468,    28,    29,     0,    30,    31,
      32,    33,   469,    35,   470,    37,    38,    39,    40,   471,
      42,    43,   472,     0,    45,   473,    47,   474,   475,    50,
     476,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,   477,   478,    67,     0,    68,    69,
      70,   479,     0,    73,    74,    75,     0,     0,   480,    77,
       0,     0,     0,     0,    79,    80,    81,   481,   482,    84,
      85,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      92,    93,     0,    94,     0,     0,     0,   483,    96,    97,
     484,   485,     0,     0,     0,     0,     0,     0,   100,   101,
     102,     0,   104,   105,   106,     0,     0,     0,     0,     0,
       0,   110,   111,     0,     0,     0,     0,   112,   113,   114,
     115,   486,   117,   118,   487,     0,     0,     0,     0,     0,
       0,   488,   489,   125,     0,     0,     0,   126,     0,   127,
     490,     0,     0,     0,   131,     0,   132,     0,   133,   134,
     135,   136,   491,   138,   139,   140,   141,   142,   143,     0,
       0,   144,   145,     0,     0,   377,   148,   149,   150,   151,
     152,   153,   154,   155,   492,   157,   493,   159,   494,   495,
     162,   163,   164,   165,   166,   167,   496,   169,   497,   498,
     499,   500,   174,   175,   501,   502,   178,   503,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
     191,   192,   193,     0,   194,   195,   196,   197,   198,   199,
       0,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,     2,     0,     0,     0,     0,     0,     0,     3,     0,
       0,     0,     7,     0,     0,     0,     0,     0,   373,   374,
       0,    11,    12,   510,    14,    15,    16,    17,   462,   511,
     512,   464,   465,   466,   467,   375,    26,   468,    28,    29,
       0,    30,    31,    32,    33,   469,    35,   513,    37,   514,
     515,    40,   471,    42,    43,   472,     0,    45,   516,    47,
     474,   475,    50,   476,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,   477,   478,    67,
       0,    68,    69,    70,   517,     0,    73,    74,    75,     0,
       0,   480,    77,     0,     0,     0,     0,    79,    80,    81,
     481,   482,    84,    85,     0,     0,     0,     0,     0,     0,
       0,    90,    91,    92,    93,     0,    94,     0,     0,     0,
     483,    96,    97,   484,   485,     0,     0,     0,     0,     0,
       0,   100,   101,   102,     0,   104,   105,   106,     0,     0,
       0,     0,     0,     0,   110,   111,     0,     0,     0,     0,
     112,   113,   114,   115,   486,   117,   118,   487,     0,     0,
       0,     0,     0,     0,   488,   489,   125,     0,     0,     0,
     126,     0,   127,   490,     0,     0,     0,   131,     0,   132,
       0,   133,   134,   135,   136,   491,   138,   139,   140,   141,
     142,   143,     0,     0,   144,   145,     0,     0,   377,   148,
     149,   150,   151,   152,   153,   154,   155,   492,   518,   493,
     159,   494,   495,   162,   163,   164,   165,   166,   167,   496,
     169,   497,   498,   499,   500,   174,   175,   501,   502,   178,
     503,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,     0,   191,   192,   193,     0,   194,   195,   196,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   528,     0,     0,     0,     0,     0,
       0,     7,     0,   729,     0,     0,     0,   373,   374,     0,
      11,    12,   510,    14,    15,    16,    17,   462,   511,   512,
     464,   465,   466,   467,   375,    26,   468,    28,    29,     0,
      30,    31,    32,    33,   469,    35,   513,    37,   514,   515,
      40,   471,    42,    43,   472,     0,    45,   516,    47,   474,
     475,    50,   476,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,   477,   478,    67,     0,
      68,    69,    70,   517,     0,    73,    74,    75,     0,     0,
     480,    77,     0,     0,     0,     0,    79,    80,    81,   481,
     482,    84,    85,     0,     0,     0,     0,     0,     0,     0,
      90,    91,    92,    93,     0,    94,     0,     0,     0,   483,
      96,    97,   484,   485,     0,     0,     0,     0,     0,     0,
     100,   101,   102,     0,   104,   105,   106,     0,     0,     0,
       0,     0,     0,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   486,   117,   118,   487,     0,     0,     0,
       0,     0,     0,   488,   489,   125,     0,     0,     0,   126,
     730,   127,   490,     0,     0,     0,     0,     0,   132,     0,
     133,   134,   135,   136,   491,   138,   139,   140,   141,   142,
     143,     0,     0,   144,   145,     0,     0,   377,   148,   149,
     150,   151,   152,   153,   154,   155,   492,   518,   493,   159,
     494,   495,   162,   163,   164,   165,   166,   167,   496,   169,
     497,   498,   499,   500,   174,   175,   501,   502,   178,   503,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,     0,   191,   192,   193,     0,   194,   195,   196,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   528,     0,     0,     0,     0,     0,     0,
       7,     0,     0,     0,     0,     0,   373,   374,     0,    11,
      12,   510,    14,    15,    16,    17,   462,   511,   512,   464,
     465,   466,   467,   375,    26,   468,    28,    29,     0,    30,
      31,    32,    33,   469,    35,   513,    37,   514,   515,    40,
     471,    42,    43,   472,     0,    45,   516,    47,   474,   475,
      50,   476,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,   477,   478,    67,     0,    68,
      69,    70,   517,     0,    73,    74,    75,     0,     0,   480,
      77,     0,     0,     0,     0,    79,    80,    81,   481,   482,
      84,    85,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,    93,     0,    94,     0,     0,     0,   483,    96,
      97,   484,   485,     0,     0,     0,     0,     0,     0,   100,
     101,   102,     0,   104,   105,   106,     0,     0,     0,     0,
       0,     0,   110,   111,     0,     0,     0,     0,   112,   113,
     114,   115,   486,   117,   118,   487,     0,     0,     0,     0,
       0,     0,   488,   489,   125,     0,     0,     0,   126,     0,
     127,   490,     0,     0,     0,     0,     0,   132,     0,   133,
     134,   135,   136,   491,   138,   139,   140,   141,   142,   143,
       0,     0,   144,   145,     0,     0,   377,   148,   149,   150,
     151,   152,   153,   154,   155,   492,   518,   493,   159,   494,
     495,   162,   163,   164,   165,   166,   167,   496,   169,   497,
     498,   499,   500,   174,   175,   501,   502,   178,   503,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
       0,   191,   192,   193,     0,   194,   195,   196,   197,   198,
     199,     0,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   531,     0,     0,     0,     0,     7,     0,     0,
       0,     0,     0,   373,   374,     0,    11,    12,   510,    14,
      15,    16,    17,   462,   511,   512,   464,   465,   466,   467,
     375,    26,   468,    28,    29,     0,    30,    31,    32,    33,
     469,    35,   513,    37,   514,   515,    40,   471,    42,    43,
     472,     0,    45,   516,    47,   474,   475,    50,   476,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,   477,   478,    67,     0,    68,    69,    70,   517,
       0,    73,    74,    75,     0,     0,   480,    77,     0,     0,
       0,     0,    79,    80,    81,   481,   482,    84,    85,     0,
       0,     0,     0,     0,     0,     0,    90,    91,    92,    93,
       0,    94,     0,     0,     0,   483,    96,    97,   484,   485,
       0,     0,     0,     0,     0,     0,   100,   101,   102,     0,
     104,   105,   106,     0,     0,     0,     0,     0,     0,   110,
     111,     0,     0,     0,     0,   112,   113,   114,   115,   486,
     117,   118,   487,     0,     0,     0,     0,     0,     0,   488,
     489,   125,     0,     0,     0,   126,     0,   127,   490,     0,
       0,     0,     0,     0,   132,     0,   133,   134,   135,   136,
     491,   138,   139,   140,   141,   142,   143,     0,     0,   144,
     145,     0,     0,   377,   148,   149,   150,   151,   152,   153,
     154,   155,   492,   518,   493,   159,   494,   495,   162,   163,
     164,   165,   166,   167,   496,   169,   497,   498,   499,   500,
     174,   175,   501,   502,   178,   503,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,     0,   191,   192,
     193,     0,   194,   195,   196,   197,   198,   199,     0,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,     7,
       0,     0,     0,     0,     0,   373,   374,     0,    11,    12,
     461,    14,    15,    16,    17,   462,    19,   463,   464,   465,
    1007,   467,   375,    26,   468,    28,    29,     0,    30,    31,
      32,    33,   469,    35,   470,    37,    38,    39,    40,   471,
      42,    43,   472,     0,    45,   473,    47,   474,   475,    50,
     476,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,   477,   478,    67,     0,    68,    69,
      70,   479,     0,    73,    74,    75,     0,     0,   480,    77,
       0,     0,     0,     0,    79,    80,    81,   481,   482,    84,
      85,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      92,    93,     0,    94,     0,     0,     0,   483,    96,    97,
     484,   485,     0,     0,     0,     0,     0,     0,   100,   101,
     102,     0,   104,   105,  1008,     0,     0,     0,  1009,     0,
       0,   110,   111,     0,     0,     0,     0,   112,   113,   114,
     115,   486,   117,   118,   487,     0,     0,     0,     0,     0,
       0,   488,   489,   125,     0,     0,     0,   126,  1381,   127,
     490,     0,     0,     0,  1382,     0,   132,     0,   133,   134,
     135,   136,   491,   138,   139,   140,   141,   142,   143,     0,
       0,  1010,   145,     0,     0,   377,   148,   149,   150,   151,
     152,   153,   154,   155,   492,   157,   493,   159,   494,   495,
     162,   163,   164,   165,   166,   167,   496,   169,   497,   498,
     499,   500,   174,   175,   501,   502,   178,   503,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
     191,   192,   193,     0,   194,   195,   196,   197,   198,   199,
       0,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,     7,     0,     0,     0,     0,     0,   373,   374,     0,
      11,    12,   510,    14,    15,    16,    17,   462,   511,   512,
     464,   465,   466,   467,   375,    26,   468,    28,    29,     0,
      30,    31,    32,    33,   469,    35,   513,    37,   514,   515,
      40,   471,    42,    43,   472,     0,    45,   516,    47,   474,
     475,    50,   476,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,   477,   478,    67,     0,
      68,    69,    70,   517,     0,    73,    74,    75,     0,     0,
     480,    77,     0,     0,     0,     0,    79,    80,    81,   481,
     482,    84,    85,     0,     0,     0,     0,     0,     0,     0,
      90,    91,    92,    93,     0,    94,     0,     0,     0,   483,
      96,    97,   484,   485,     0,     0,     0,     0,     0,     0,
     100,   101,   102,     0,   104,   105,   106,     0,     0,     0,
       0,     0,     0,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   486,   117,   118,   487,     0,     0,     0,
       0,     0,     0,   488,   489,   125,     0,     0,     0,   126,
     703,   127,   490,     0,     0,     0,   704,     0,   132,     0,
     133,   134,   135,   136,   491,   138,   139,   140,   141,   142,
     143,     0,     0,   144,   145,     0,     0,   377,   148,   149,
     150,   151,   152,   153,   154,   155,   492,   518,   493,   159,
     494,   495,   162,   163,   164,   165,   166,   167,   496,   169,
     497,   498,   499,   500,   174,   175,   501,   502,   178,   503,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,     0,   191,   192,   193,     0,   194,   195,   196,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,     7,     0,     0,     0,     0,     0,   373,
     374,     0,    11,    12,   510,    14,    15,    16,    17,   462,
     511,   512,   464,   465,   466,   467,   375,    26,   468,    28,
      29,     0,    30,    31,    32,    33,   469,    35,   513,    37,
     514,   515,    40,   471,    42,    43,   472,     0,    45,   516,
      47,   474,   475,    50,   476,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,   477,   478,
      67,     0,    68,    69,    70,   517,     0,    73,    74,    75,
       0,     0,   480,    77,     0,     0,     0,     0,    79,    80,
      81,   481,   482,    84,    85,     0,     0,     0,     0,     0,
       0,     0,    90,    91,    92,    93,     0,    94,     0,     0,
       0,   483,    96,    97,   484,   485,     0,     0,     0,     0,
       0,     0,   100,   101,   102,     0,   104,   105,   106,     0,
       0,     0,     0,     0,     0,   110,   111,     0,     0,     0,
       0,   112,   113,   114,   115,   486,   117,   118,   487,     0,
       0,     0,     0,     0,     0,   488,   489,   125,     0,     0,
       0,   126,   748,   127,   490,     0,     0,     0,   749,     0,
     132,     0,   133,   134,   135,   136,   491,   138,   139,   140,
     141,   142,   143,     0,     0,   144,   145,     0,     0,   377,
     148,   149,   150,   151,   152,   153,   154,   155,   492,   518,
     493,   159,   494,   495,   162,   163,   164,   165,   166,   167,
     496,   169,   497,   498,   499,   500,   174,   175,   501,   502,
     178,   503,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,     0,   191,   192,   193,     0,   194,   195,
     196,   197,   198,   199,     0,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,     7,     0,     0,     0,     0,
       0,   373,   374,     0,    11,    12,   461,    14,    15,    16,
      17,   462,    19,   463,   464,   465,  1007,   467,   375,    26,
     468,    28,    29,     0,    30,    31,    32,    33,   469,    35,
     470,    37,    38,    39,    40,   471,    42,    43,   472,     0,
      45,   473,    47,   474,   475,    50,   476,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
     477,   478,    67,     0,    68,    69,    70,   479,     0,    73,
      74,    75,     0,     0,   480,    77,     0,     0,     0,     0,
      79,    80,    81,   481,   482,    84,    85,  1340,     0,     0,
       0,     0,     0,     0,    90,    91,    92,    93,     0,    94,
       0,     0,     0,   483,    96,    97,   484,   485,     0,     0,
       0,     0,     0,     0,   100,   101,   102,     0,   104,   105,
    1008,     0,     0,     0,  1009,     0,     0,   110,   111,     0,
       0,     0,     0,   112,   113,   114,   115,   486,   117,   118,
     487,     0,     0,     0,     0,     0,     0,   488,   489,   125,
       0,     0,     0,   126,     0,   127,   490,     0,     0,     0,
       0,     0,   132,     0,   133,   134,   135,   136,   491,   138,
     139,   140,   141,   142,   143,     0,     0,  1010,   145,     0,
       0,   377,   148,   149,   150,   151,   152,   153,   154,   155,
     492,   157,   493,   159,   494,   495,   162,   163,   164,   165,
     166,   167,   496,   169,   497,   498,   499,   500,   174,   175,
     501,   502,   178,   503,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,     0,   191,   192,   193,     0,
     194,   195,   196,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,     7,     0,     0,
       0,     0,     0,   373,   374,     0,    11,    12,   461,    14,
      15,    16,    17,   462,    19,   463,   464,   465,  1007,   467,
     375,    26,   468,    28,    29,     0,    30,    31,    32,    33,
     469,    35,   470,    37,    38,    39,    40,   471,    42,    43,
     472,     0,    45,   473,    47,   474,   475,    50,   476,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,   477,   478,    67,     0,    68,    69,    70,   479,
       0,    73,    74,    75,     0,     0,   480,    77,     0,     0,
       0,     0,    79,    80,    81,   481,   482,    84,    85,     0,
       0,     0,     0,     0,     0,     0,    90,    91,    92,    93,
       0,    94,     0,     0,     0,   483,    96,    97,   484,   485,
       0,     0,     0,     0,     0,     0,   100,   101,   102,     0,
     104,   105,  1008,     0,     0,     0,  1009,     0,     0,   110,
     111,     0,     0,     0,     0,   112,   113,   114,   115,   486,
     117,   118,   487,     0,     0,     0,     0,     0,     0,   488,
     489,   125,     0,     0,     0,   126,     0,   127,   490,     0,
       0,     0,     0,     0,   132,     0,   133,   134,   135,   136,
     491,   138,   139,   140,   141,   142,   143,     0,     0,  1010,
     145,     0,     0,   377,   148,   149,   150,   151,   152,   153,
     154,   155,   492,   157,   493,   159,   494,   495,   162,   163,
     164,   165,   166,   167,   496,   169,   497,   498,   499,   500,
     174,   175,   501,   502,   178,   503,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,     0,   191,   192,
     193,     0,   194,   195,   196,   197,   198,   199,     0,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,     7,
       0,     0,     0,     0,     0,   373,   374,     0,    11,    12,
     461,    14,    15,    16,    17,   462,    19,   463,   464,   465,
    1007,   467,   375,    26,   468,    28,    29,     0,    30,    31,
      32,    33,   469,    35,   470,    37,    38,    39,    40,   471,
      42,    43,   472,     0,    45,   473,    47,   474,   475,    50,
     476,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,   477,   478,    67,     0,    68,    69,
      70,   479,     0,    73,    74,    75,     0,     0,   480,    77,
       0,     0,     0,     0,    79,    80,    81,   481,   482,    84,
      85,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      92,    93,     0,    94,     0,     0,     0,   483,    96,    97,
     484,   485,     0,     0,     0,     0,     0,     0,   100,   101,
     102,     0,   104,   105,  1008,     0,     0,     0,  1009,     0,
       0,   110,   111,     0,     0,     0,     0,   112,   113,   114,
     115,   486,   117,   118,   487,     0,     0,     0,     0,     0,
       0,   488,   489,   125,     0,     0,     0,   126,     0,   127,
     490,     0,     0,     0,     0,     0,   132,     0,   133,   134,
     135,   136,   491,   138,   139,   140,   141,   142,   143,     0,
       0,   144,   145,     0,     0,   377,   148,   149,   150,   151,
     152,   153,   154,   155,   492,   157,   493,   159,   494,   495,
     162,   163,   164,   165,   166,   167,   496,   169,   497,   498,
     499,   500,   174,   175,   501,   502,   178,   503,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
     191,   192,   193,     0,   194,   195,   196,   197,   198,   199,
       0,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,     7,     0,     0,     0,     0,     0,   373,   374,     0,
      11,    12,   510,    14,    15,    16,    17,   462,   511,   512,
     464,   465,   466,   467,   375,    26,   468,    28,    29,     0,
      30,    31,    32,    33,   469,    35,   513,    37,   514,   515,
      40,   471,    42,    43,   472,     0,    45,   516,    47,   474,
     475,    50,   476,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,   477,   478,    67,     0,
      68,    69,    70,   517,     0,    73,    74,    75,     0,     0,
     480,    77,     0,     0,     0,     0,    79,    80,    81,   481,
     482,    84,    85,     0,     0,     0,     0,     0,     0,     0,
      90,    91,    92,    93,     0,    94,     0,     0,     0,   483,
      96,    97,   484,   485,     0,     0,     0,     0,     0,     0,
     100,   101,   102,     0,   104,   105,   106,     0,     0,     0,
       0,     0,     0,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   486,   117,   118,   487,     0,     0,     0,
       0,     0,     0,   488,   489,   125,     0,     0,     0,   126,
       0,   127,   490,     0,     0,     0,     0,     0,   132,     0,
     133,   134,   135,   136,   491,   138,   139,   140,   141,   142,
     143,     0,     0,   144,   145,     0,     0,   377,   148,   149,
     150,   151,   152,   153,   154,   155,   492,   518,   493,   159,
     494,   495,   162,   163,   164,   165,   166,   167,   496,   169,
     497,   498,   499,   500,   174,   175,   501,   502,   178,   503,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,     0,   191,   192,   193,     0,   194,   195,   196,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,     7,     0,     0,     0,     0,     0,   373,
     374,     0,    11,    12,     0,    14,    15,    16,    17,   462,
       0,     0,   464,   465,   466,     0,   375,    26,   468,    28,
      29,     0,    30,    31,    32,    33,   469,    35,     0,    37,
       0,     0,    40,   471,    42,    43,   472,     0,    45,     0,
      47,     0,     0,    50,   476,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,   477,   478,
      67,     0,    68,    69,    70,     0,     0,    73,    74,    75,
       0,     0,   480,    77,     0,     0,     0,     0,    79,    80,
      81,   481,   482,    84,    85,     0,     0,     0,     0,     0,
       0,     0,    90,    91,    92,    93,     0,    94,     0,     0,
       0,   483,    96,    97,   484,   485,     0,     0,     0,     0,
       0,     0,   100,   101,   102,     0,   104,   105,     0,     0,
       0,     0,     0,     0,     0,   110,   111,     0,     0,     0,
       0,   112,   113,   114,   115,   486,   117,   118,   487,     0,
       0,     0,     0,     0,     0,   488,   489,   125,     0,     0,
       0,   126,     0,   127,   490,     0,     0,     0,     0,     0,
     132,     0,   133,   134,   135,   136,   491,   138,   139,   140,
     141,   142,   143,     0,     0,     0,   145,     0,     0,   377,
     148,   149,   150,   151,   152,   153,   154,   155,   492,     0,
     493,   159,   494,   495,   162,   163,   164,   165,   166,   167,
     496,   169,   497,   498,   499,   500,   174,   175,     0,   502,
     178,   503,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,     0,   191,   192,   193,     0,   194,   195,
     196,   197,   198,   199,     0,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        72,   726,   312,   383,   754,   572,   614,   817,   615,   616,
     617,   618,   737,   130,    86,   569,   247,   399,   829,   830,
     935,   905,  1207,   568,   569,   817,   800,    72,   967,  1220,
    1221,   726,  1367,    23,  1105,  1296,   108,   240,  1031,  1180,
     243,   423,    49,   568,   591,    52,    51,    90,   120,    24,
     122,   113,    90,     7,    92,   829,   830,  1271,   438,   439,
     864,   443,    39,   594,    90,   596,   597,    92,   599,     4,
     601,    92,   136,     8,    90,     4,     5,     6,   609,   610,
     102,    90,    59,    95,   113,    23,    89,    23,    95,   124,
     864,   657,   102,   136,    90,   989,   102,   160,   102,    47,
     102,   138,   113,   141,    28,   102,   209,   163,   154,   804,
     262,   806,   175,   147,   925,   105,    72,   269,     8,     9,
     141,   147,   102,   102,   147,   124,   900,   279,   118,   102,
      86,   102,   169,    57,   861,    32,   170,   130,   194,   152,
      92,    38,    39,   141,   247,   870,    90,   170,   875,   186,
     179,   925,   108,   143,   189,   217,   169,   147,   180,    56,
     150,    58,    59,   141,   120,     8,   122,   179,  1062,   180,
      67,   181,   108,   176,   102,   123,   180,   183,   107,    22,
     170,   183,   117,  1374,   119,     4,   183,   213,   214,     8,
     189,    90,   127,   918,   210,   211,    93,   141,   315,   924,
     193,   180,   266,   180,   209,  1009,   177,   180,    98,   225,
    1351,   163,   147,   963,   168,   287,   154,  1101,   154,  1433,
     229,  1031,  1032,   266,   249,   250,  1141,   117,   266,   119,
     784,   206,  1171,   229,  1305,  1009,    92,   244,   300,  1031,
    1032,  1180,   247,   102,   939,   266,  1507,   227,   320,   262,
     257,   323,   259,   181,  1247,  1590,   269,   147,   783,   806,
     102,   151,   252,   270,   271,   272,   279,   274,   266,   276,
     102,  1606,     8,     9,   117,   320,   119,   167,   323,  1614,
     102,    40,   813,   849,   850,   128,     8,     9,   266,  1474,
      90,   102,   672,   245,   246,   125,   248,   187,   117,    39,
     119,   102,    42,   255,   147,    92,   256,   163,   127,   102,
     101,   210,   211,   265,   147,   205,   388,   267,   390,  1510,
     217,   180,  1133,   395,   112,   277,   225,   399,   147,    27,
     121,   287,  1027,   405,  1108,    75,   718,   568,   180,   721,
     412,   141,   722,   102,    92,   217,    44,  1158,   180,   147,
     222,   423,   140,   183,  1545,   150,   559,   429,   180,  1133,
     108,   101,    98,   150,   320,   153,  1437,   323,   440,   180,
     150,   443,   444,   445,   446,   447,    98,    92,    48,   180,
     452,   117,   152,   119,  1158,    55,    63,   180,   460,   245,
     246,    68,   248,   108,    48,   117,   142,   119,   186,   169,
       8,    55,   150,   147,   113,   131,   150,   142,    41,   265,
     136,   147,  1351,   159,    22,   151,  1227,     8,     9,    73,
    1304,   277,   162,    23,   159,   147,    48,  1524,  1525,   151,
      90,   167,   150,    55,   390,   150,   113,  1247,    92,   395,
     217,   995,   219,   399,  1515,   167,  1256,   131,   520,   405,
     995,   187,   113,  1227,   130,  1247,   412,  1267,   202,   113,
    1557,   175,   152,   147,  1256,   187,  1563,   423,   144,   205,
      92,   131,  1543,   429,   188,  1267,   136,   549,   913,   169,
     915,   256,   150,   205,   440,   557,   131,   443,   444,   445,
     446,   447,   267,   873,   874,   424,   452,   426,   878,   428,
     150,   191,   147,    90,   460,   105,   116,    98,   437,   117,
     131,   119,   152,   442,   101,   136,   633,   634,   118,   448,
     128,   450,   451,   958,   453,   960,   117,   907,   119,   169,
     459,  1602,   113,  1604,  1449,    35,   150,   147,    91,   147,
     150,    41,   116,   143,   175,    42,    46,   147,   101,  1620,
     150,   191,   783,   131,    54,    92,   147,   188,   111,    95,
     151,   240,   241,    60,   520,    62,    66,   163,   121,   147,
     170,   108,   108,    95,    71,   261,   167,   636,   193,   292,
     639,   150,   268,   642,   263,   116,   108,   202,   301,   322,
     662,   147,   664,   549,   327,   667,   187,   526,   194,  1349,
     113,   557,  1412,  1353,   270,   271,   272,   116,   537,   147,
     276,   116,   150,   147,   205,   116,   150,   689,   690,   691,
    1412,   147,   147,   116,   150,   150,   222,   556,   213,   214,
     215,   217,   148,   219,   150,   116,   224,   709,   226,   711,
     224,   116,   226,   184,   185,   387,   718,   389,   116,   721,
    1258,   293,   294,   116,   293,   294,   122,   123,  1212,   284,
     285,   116,   162,   122,   123,   165,   612,   613,  1479,   147,
    1481,   150,   619,   620,   831,   832,   621,   622,   208,   179,
     113,   753,  1424,  1425,   280,   281,   282,   283,   284,   217,
     286,   287,   288,   289,   290,   147,   235,   150,   147,   295,
     113,   630,   234,     0,   204,  1479,   635,  1481,    88,  1520,
     234,   667,  1462,     3,   183,  1465,   183,   161,  1285,   242,
      45,   793,   192,  1033,  1535,    96,   148,    97,   800,   139,
     150,   177,   177,   689,   690,   691,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,  1520,   177,    23,    42,
      42,    42,   146,   709,   113,   711,  1136,   829,   830,   831,
     832,  1535,   718,   239,   291,   721,   286,   277,   297,   180,
     291,   277,   113,   147,   113,   180,   180,   150,  1528,   147,
     147,   150,    29,    15,   150,  1510,   715,   150,   150,  1396,
     206,   180,   864,    23,   223,  1403,  1404,   753,   183,   183,
     113,   162,   102,    67,   430,   223,   164,   164,   880,    90,
      90,    90,   143,   102,   102,    23,   745,   746,   154,   154,
     121,   126,   239,   126,   177,   177,   180,   292,   177,   180,
     177,   126,    90,    92,   180,    39,  1216,   793,    92,   134,
     135,   913,   137,   915,   800,   102,   775,   177,   180,   136,
     145,   180,   180,   925,   149,   177,   151,   180,   177,   180,
     180,   156,   147,   177,    90,   177,   177,   217,   136,   229,
     180,   177,    27,   829,   830,   831,   832,   172,  1486,  1487,
     164,   183,   113,   177,   113,   113,   958,   126,   960,   113,
     141,   136,   178,    90,   136,    23,   279,   292,   147,   247,
     195,   196,   197,   198,   199,   200,   113,    90,   864,   126,
     219,   177,   190,   154,   126,   541,   542,    92,   544,   545,
     546,   547,   113,   136,   880,   147,   113,   141,   554,   555,
    1538,  1003,    95,    95,  1006,    29,   147,  1009,    23,   177,
     177,   113,   177,   113,   570,  1325,   147,   183,  1020,    75,
    1022,   102,   102,   141,   580,   581,   238,   913,   150,   915,
     150,   150,   141,   278,    36,   138,    23,    23,   251,   925,
      42,   279,    23,   229,   183,   219,   253,   180,    50,   219,
      52,   280,   299,   141,   260,   219,   180,   180,    60,   138,
      62,   113,   113,    73,   180,   102,   136,   177,  1378,    71,
       6,   126,   958,    75,   960,   183,   180,   225,   229,   180,
     225,   179,   136,   101,   101,   641,   180,   177,   644,   225,
     225,   180,   141,   180,   953,   141,   180,   243,    74,   275,
     177,   279,    23,   243,   106,   107,   108,    23,    92,   264,
     177,   164,   120,    92,   177,   179,   177,  1003,   250,   179,
    1006,    90,  1124,  1009,   147,    23,   164,   177,   102,    48,
     177,  1133,   180,    90,  1020,   180,  1022,    90,   113,    23,
     102,  1143,   113,   273,   258,   189,   217,   113,  1150,   179,
     189,   280,   177,   189,   113,   217,  1158,   179,    89,   113,
     176,   163,   189,   113,   147,   113,   113,   180,   240,   244,
     298,  1030,   298,   298,   286,  1177,   217,   191,   244,   247,
     671,   280,   865,  1066,   299,  1515,  1108,  1543,   299,   417,
    1203,   393,   194,   299,   397,   286,  1198,   926,  1006,   436,
    1319,  1060,  1211,   923,  1125,  1207,  1225,   999,  1223,  1211,
    1220,   520,  1143,   593,  1159,   592,   644,  1155,   754,  1563,
     222,  1171,   308,  1557,   832,  1227,  1150,   427,   427,  1102,
     915,  1065,  1198,  1256,  1208,  1267,  1412,  1032,  1124,   795,
    1260,  1409,  1041,  1090,   899,  1294,   802,  1133,  1427,  1257,
      -1,    -1,   254,  1112,    -1,    -1,    -1,  1143,    -1,    -1,
      -1,    -1,    -1,    -1,  1150,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1158,    -1,    -1,    -1,    -1,    -1,   280,   281,
     282,   283,   284,    -1,   286,   287,   288,   289,   290,  1148,
      -1,  1177,    -1,   295,   296,    -1,    -1,    -1,    -1,    -1,
    1302,    -1,    -1,    -1,    -1,  1164,    -1,    -1,    -1,    -1,
     866,    -1,  1198,    -1,  1316,  1317,   872,    -1,    -1,    -1,
      -1,  1207,    -1,    -1,    -1,  1211,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1340,    -1,
      -1,  1227,    -1,    -1,    -1,    -1,    -1,    -1,  1350,    -1,
      -1,    -1,  1354,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   937,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   945,
      -1,   947,   948,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   962,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1302,   973,   974,   975,
      -1,   977,   978,   979,   980,   981,   982,    -1,   984,   985,
    1316,  1317,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   999,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1340,    -1,  1458,    -1,    -1,    -1,
      -1,  1463,    -1,    -1,  1350,    -1,    -1,  1023,  1354,  1025,
    1026,    -1,  1474,    -1,    -1,    -1,    -1,  1479,    -1,  1481,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1052,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1511,
      -1,    -1,  1514,    -1,  1070,    -1,    -1,    -1,  1520,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1531,
      -1,    -1,    -1,  1535,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1547,    -1,    -1,    -1,  1551,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1118,    -1,    -1,    -1,    -1,  1123,    -1,    -1,
      -1,    -1,  1458,    -1,    -1,  1577,    -1,  1463,    -1,  1135,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1474,  1145,
    1146,    -1,  1594,  1479,  1596,  1481,    -1,  1153,  1154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1609,    -1,    -1,
      -1,  1613,    -1,    -1,    -1,    -1,  1618,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1511,    -1,    -1,  1514,    -1,
      -1,    -1,    -1,    -1,  1520,    -1,    -1,  1496,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1531,    -1,    -1,    -1,  1535,
      -1,    -1,    -1,    -1,  1210,    -1,    -1,    -1,    -1,    -1,
      -1,  1547,    -1,    -1,    -1,  1551,    -1,  1223,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1238,    -1,    -1,  1241,    -1,  1243,    -1,    -1,
      -1,  1577,    30,    31,    -1,    33,    34,    -1,    36,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,  1594,    -1,
    1596,    -1,    50,    -1,    52,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    60,  1609,    62,    -1,    -1,  1613,    -1,    -1,
      -1,    -1,  1618,    71,    -1,    -1,    -1,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1315,
      -1,    -1,    -1,    -1,    -1,  1321,    -1,    -1,   106,   107,
     108,    -1,    -1,    -1,  1330,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1338,  1339,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1357,  1358,  1359,  1360,  1361,    -1,  1363,  1364,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1390,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   212,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1448,    -1,    -1,    -1,    -1,  1453,    -1,    -1,
      -1,  1457,    -1,  1459,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   280,   281,   282,   283,   284,    -1,   286,   287,
     288,   289,   290,    -1,    -1,    -1,    -1,   295,   296,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1553,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1575,
       3,    -1,    -1,    -1,  1580,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    -1,
      23,    -1,    -1,  1599,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    -1,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    -1,    90,    91,    92,
      93,    94,    95,    96,    97,    -1,    -1,   100,   101,    -1,
      -1,    -1,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,    -1,    -1,   118,    -1,   120,   121,   122,
     123,    -1,   125,    -1,    -1,    -1,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,    -1,    -1,   140,   141,   142,
     143,   144,   145,   146,    -1,    -1,    -1,   150,   151,   152,
     153,   154,    -1,    -1,    -1,    -1,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    -1,   169,   170,    -1,    -1,
     173,   174,   175,    -1,    -1,    -1,   179,    -1,   181,   182,
      -1,   184,   185,   186,    -1,   188,    -1,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,    -1,    -1,
     203,   204,   205,    -1,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,    -1,   252,
     253,   254,    -1,   256,   257,   258,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,     3,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      -1,    23,    -1,    -1,    -1,    27,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    -1,    90,    91,
      92,    93,    94,    95,    96,    97,    -1,    -1,   100,   101,
      -1,    -1,    -1,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    -1,    -1,   118,    -1,   120,   121,
     122,   123,    -1,   125,    -1,    -1,    -1,   129,   130,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,   141,
     142,   143,   144,   145,   146,    -1,    -1,    -1,   150,   151,
     152,   153,   154,    -1,    -1,    -1,    -1,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,   169,   170,    -1,
      -1,   173,   174,   175,    -1,    -1,    -1,   179,    -1,   181,
     182,    -1,   184,   185,   186,    -1,   188,    -1,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,   203,   204,   205,    -1,   207,   208,   209,   210,   211,
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
      19,    20,    21,    -1,    23,    -1,    -1,    -1,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    -1,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      -1,    90,    91,    92,    93,    94,    95,    96,    97,    -1,
      -1,   100,   101,    -1,    -1,    -1,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,    -1,    -1,   118,
      -1,   120,   121,   122,   123,    -1,   125,    -1,    -1,    -1,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,
      -1,   140,   141,   142,   143,   144,   145,   146,    -1,    -1,
      -1,   150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
     169,   170,    -1,    -1,   173,   174,   175,    -1,   177,    -1,
     179,    -1,   181,   182,    -1,   184,   185,   186,    -1,   188,
      -1,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,    -1,    -1,   203,   204,   205,    -1,   207,   208,
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
      -1,    17,    18,    19,    20,    21,    -1,    23,    -1,    -1,
      -1,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    -1,    90,    91,    92,    93,    94,    95,
      96,    97,    -1,    -1,   100,   101,    -1,    -1,    -1,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      -1,    -1,   118,    -1,   120,   121,   122,   123,    -1,   125,
      -1,    -1,    -1,   129,   130,   131,   132,   133,    -1,    -1,
      -1,    -1,    -1,    -1,   140,   141,   142,   143,   144,   145,
     146,    -1,    -1,    -1,   150,   151,   152,   153,   154,    -1,
      -1,    -1,    -1,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,   169,   170,    -1,    -1,   173,   174,   175,
      -1,   177,    -1,   179,    -1,   181,   182,    -1,   184,   185,
     186,    -1,   188,    -1,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,    -1,   203,   204,   205,
      -1,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,    -1,   252,   253,   254,    -1,
     256,   257,   258,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    -1,
      23,    -1,    -1,    -1,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    -1,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    -1,    90,    91,    92,
      93,    94,    95,    96,    97,    -1,    -1,   100,   101,    -1,
      -1,    -1,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,    -1,    -1,   118,    -1,   120,   121,   122,
     123,    -1,   125,    -1,    -1,    -1,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,    -1,    -1,   140,   141,   142,
     143,   144,   145,   146,    -1,    -1,    -1,   150,   151,   152,
     153,   154,    -1,    -1,    -1,    -1,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    -1,   169,   170,    -1,    -1,
     173,   174,   175,    -1,   177,    -1,   179,    -1,   181,   182,
      -1,   184,   185,   186,    -1,   188,    -1,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,    -1,    -1,
     203,   204,   205,    -1,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,    -1,   252,
     253,   254,    -1,   256,   257,   258,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    -1,    23,    -1,    -1,    -1,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    -1,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      90,    91,    92,    93,    94,    95,    96,    97,    -1,    -1,
     100,   101,    -1,    -1,    -1,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    -1,    -1,   118,    -1,
     120,   121,   122,   123,    -1,   125,    -1,    -1,    -1,   129,
     130,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,
     140,   141,   142,   143,   144,   145,   146,    -1,    -1,    -1,
     150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,   169,
     170,    -1,    -1,   173,   174,   175,    -1,    -1,    -1,   179,
     180,   181,   182,    -1,   184,   185,   186,    -1,   188,    -1,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,    -1,    -1,   203,   204,   205,    -1,   207,   208,   209,
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
      17,    18,    19,    20,    21,    -1,    23,    -1,    -1,    -1,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    -1,    90,    91,    92,    93,    94,    95,    96,
      97,    -1,    -1,   100,   101,    -1,    -1,    -1,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,    -1,
      -1,   118,    -1,   120,   121,   122,   123,    -1,   125,    -1,
      -1,    -1,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,    -1,    -1,   140,   141,   142,   143,   144,   145,   146,
      -1,    -1,    -1,   150,   151,   152,   153,   154,    -1,    -1,
      -1,    -1,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,   169,   170,    -1,    -1,   173,   174,   175,    -1,
     177,    -1,   179,    -1,   181,   182,    -1,   184,   185,   186,
      -1,   188,    -1,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,    -1,    -1,   203,   204,   205,    -1,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,   252,   253,   254,    -1,   256,
     257,   258,   259,   260,   261,    -1,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    -1,    23,
      -1,    -1,    -1,    27,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    -1,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    -1,    90,    91,    92,    93,
      94,    95,    96,    97,    -1,    -1,   100,   101,    -1,    -1,
      -1,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    -1,    -1,   118,    -1,   120,   121,   122,   123,
      -1,   125,    -1,    -1,    -1,   129,   130,   131,   132,   133,
      -1,    -1,    -1,    -1,    -1,    -1,   140,   141,   142,   143,
     144,   145,   146,    -1,    -1,    -1,   150,   151,   152,   153,
     154,    -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    -1,   169,   170,    -1,    -1,   173,
     174,   175,    -1,    -1,    -1,   179,   180,   181,   182,    -1,
     184,   185,   186,    -1,   188,    -1,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    -1,    -1,   203,
     204,   205,    -1,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,    -1,   252,   253,
     254,    -1,   256,   257,   258,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      21,    -1,    23,    -1,    -1,    -1,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    -1,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    -1,    90,
      91,    92,    93,    94,    95,    96,    97,    -1,    -1,   100,
     101,    -1,    -1,    -1,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,    -1,    -1,   118,    -1,   120,
     121,   122,   123,    -1,   125,    -1,    -1,    -1,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,
     141,   142,   143,   144,   145,   146,    -1,    -1,    -1,   150,
     151,   152,   153,   154,    -1,    -1,    -1,    -1,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    -1,   169,   170,
      -1,    -1,   173,   174,   175,    -1,    -1,    -1,   179,   180,
     181,   182,    -1,   184,   185,   186,    -1,   188,    -1,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
      -1,    -1,   203,   204,   205,    -1,   207,   208,   209,   210,
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
      18,    19,    20,    21,    -1,    23,    -1,    -1,    -1,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    -1,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    -1,    90,    91,    92,    93,    94,    95,    96,    97,
      -1,    -1,   100,   101,    -1,    -1,    -1,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    -1,    -1,
     118,    -1,   120,   121,   122,   123,    -1,   125,    -1,    -1,
      -1,   129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,
      -1,    -1,   140,   141,   142,   143,   144,   145,   146,    -1,
      -1,    -1,   150,   151,   152,   153,   154,    -1,    -1,    -1,
      -1,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,   169,   170,    -1,    -1,   173,   174,   175,    -1,   177,
      -1,   179,    -1,   181,   182,    -1,   184,   185,   186,    -1,
     188,    -1,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,    -1,    -1,   203,   204,   205,    -1,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,    -1,   252,   253,   254,    -1,   256,   257,
     258,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    -1,    23,    -1,
      -1,    -1,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      -1,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    90,    91,    92,    93,    94,
      95,    96,    97,    -1,    -1,   100,   101,    -1,    -1,    -1,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,    -1,    -1,   118,    -1,   120,   121,   122,   123,    -1,
     125,    -1,    -1,    -1,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,    -1,    -1,   140,   141,   142,   143,   144,
     145,   146,    -1,    -1,    -1,   150,   151,   152,   153,   154,
      -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    -1,   169,   170,    -1,    -1,   173,   174,
     175,    -1,   177,    -1,   179,    -1,   181,   182,    -1,   184,
     185,   186,    -1,   188,    -1,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,    -1,    -1,   203,   204,
     205,    -1,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,    -1,   252,   253,   254,
      -1,   256,   257,   258,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      -1,    23,    -1,    -1,    -1,    27,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    -1,    90,    91,
      92,    93,    94,    95,    96,    97,    -1,    -1,   100,   101,
      -1,    -1,    -1,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    -1,    -1,   118,    -1,   120,   121,
     122,   123,    -1,   125,    -1,    -1,    -1,   129,   130,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,   141,
     142,   143,   144,   145,   146,    -1,    -1,    -1,   150,   151,
     152,   153,   154,    -1,    -1,    -1,    -1,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,   169,   170,    -1,
      -1,   173,   174,   175,    -1,   177,    -1,   179,    -1,   181,
     182,    -1,   184,   185,   186,    -1,   188,    -1,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,   203,   204,   205,    -1,   207,   208,   209,   210,   211,
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
      19,    20,    21,    -1,    23,    -1,    -1,    -1,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    -1,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      -1,    90,    91,    92,    93,    94,    95,    96,    97,    -1,
      -1,   100,   101,    -1,    -1,    -1,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,    -1,    -1,   118,
      -1,   120,   121,   122,   123,    -1,   125,    -1,    -1,    -1,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,
      -1,   140,   141,   142,   143,   144,   145,   146,    -1,    -1,
      -1,   150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
     169,   170,    -1,    -1,   173,   174,   175,    -1,    -1,    -1,
     179,    -1,   181,   182,    -1,   184,   185,   186,    -1,   188,
      -1,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,    -1,    -1,   203,   204,   205,    -1,   207,   208,
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
      -1,    17,    18,    19,    20,    21,    -1,    23,    -1,    -1,
      -1,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    -1,    90,    91,    92,    93,    94,    95,
      96,    97,    -1,    -1,   100,   101,    -1,    -1,    -1,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      -1,    -1,   118,    -1,   120,   121,   122,   123,    -1,   125,
      -1,    -1,    -1,   129,   130,   131,   132,   133,    -1,    -1,
      -1,    -1,    -1,    -1,   140,   141,   142,   143,   144,   145,
     146,    -1,    -1,    -1,   150,   151,   152,   153,   154,    -1,
      -1,    -1,    -1,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,   169,   170,    -1,    -1,   173,   174,   175,
      -1,    -1,    -1,   179,    -1,   181,   182,    -1,   184,   185,
     186,    -1,   188,    -1,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,    -1,   203,   204,   205,
      -1,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,    -1,   252,   253,   254,    -1,
     256,   257,   258,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    -1,
      23,    -1,    -1,    -1,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    -1,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    -1,    90,    91,    92,
      93,    94,    95,    96,    97,    -1,    -1,   100,   101,    -1,
      -1,    -1,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,    -1,    -1,   118,    -1,   120,   121,   122,
     123,    -1,   125,    -1,    -1,    -1,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,    -1,    -1,   140,   141,   142,
     143,   144,   145,   146,    -1,    -1,    -1,   150,   151,   152,
     153,   154,    -1,    -1,    -1,    -1,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    -1,   169,   170,    -1,    -1,
     173,   174,   175,    -1,    -1,    -1,   179,    -1,   181,   182,
      -1,   184,   185,   186,    -1,   188,    -1,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,    -1,    -1,
     203,   204,   205,    -1,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,    -1,   252,
     253,   254,    -1,   256,   257,   258,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    -1,    23,    -1,    -1,    -1,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    -1,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      90,    91,    92,    93,    94,    95,    96,    97,    -1,    -1,
     100,   101,    -1,    -1,    -1,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    -1,    -1,   118,    -1,
     120,   121,   122,   123,    -1,   125,    -1,    -1,    -1,   129,
     130,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,
     140,   141,   142,   143,   144,   145,   146,    -1,    -1,    -1,
     150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,   169,
     170,    -1,    -1,   173,   174,   175,    -1,    -1,    -1,   179,
      -1,   181,   182,    -1,   184,   185,   186,    -1,   188,    -1,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,    -1,    -1,   203,   204,   205,    -1,   207,   208,   209,
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
      17,    18,    19,    20,    21,    -1,    23,    -1,    -1,    -1,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    -1,    90,    91,    92,    93,    94,    95,    96,
      97,    -1,    -1,   100,   101,    -1,    -1,    -1,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,    -1,
      -1,   118,    -1,   120,   121,   122,   123,    -1,   125,    -1,
      -1,    -1,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,    -1,    -1,   140,   141,   142,   143,   144,   145,   146,
      -1,    -1,    -1,   150,   151,   152,   153,   154,    -1,    -1,
      -1,    -1,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,   169,   170,    -1,    -1,   173,   174,   175,    -1,
      -1,    -1,   179,    -1,   181,   182,    -1,   184,   185,   186,
      -1,   188,    -1,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,    -1,    -1,   203,   204,   205,    -1,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,   252,   253,   254,    -1,   256,
     257,   258,   259,   260,   261,    -1,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    -1,    23,
      -1,    -1,    -1,    27,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    -1,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    -1,    90,    91,    92,    93,
      94,    95,    96,    97,    -1,    -1,   100,   101,    -1,    -1,
      -1,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    -1,    -1,   118,    -1,   120,   121,   122,   123,
      -1,   125,    -1,    -1,    -1,   129,   130,   131,   132,   133,
      -1,    -1,    -1,    -1,    -1,    -1,   140,   141,   142,   143,
     144,   145,   146,    -1,    -1,    -1,   150,   151,   152,   153,
     154,    -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    -1,   169,   170,    -1,    -1,   173,
     174,   175,    -1,    -1,    -1,   179,    -1,   181,   182,    -1,
     184,   185,   186,    -1,   188,    -1,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    -1,    -1,   203,
     204,   205,    -1,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,    -1,   252,   253,
     254,    -1,   256,   257,   258,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      21,    -1,    23,    -1,    -1,    -1,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    -1,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    -1,    90,
      91,    92,    93,    94,    95,    96,    97,    -1,    -1,   100,
     101,    -1,    -1,    -1,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,    -1,    -1,   118,    -1,   120,
     121,   122,   123,    -1,   125,    -1,    -1,    -1,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,
     141,   142,   143,   144,   145,   146,    -1,    -1,    -1,   150,
     151,   152,   153,   154,    -1,    -1,    -1,    -1,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    -1,   169,   170,
      -1,    -1,   173,   174,   175,    -1,    -1,    -1,   179,    -1,
     181,   182,    -1,   184,   185,   186,    -1,   188,    -1,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
      -1,    -1,   203,   204,   205,    -1,   207,   208,   209,   210,
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
      18,    19,    20,    21,    -1,    23,    -1,    -1,    -1,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    -1,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    -1,    90,    91,    92,    93,    94,    95,    96,    97,
      -1,    -1,   100,   101,    -1,    -1,    -1,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    -1,    -1,
     118,    -1,   120,   121,   122,   123,    -1,   125,    -1,    -1,
      -1,   129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,
      -1,    -1,   140,   141,   142,   143,   144,   145,   146,    -1,
      -1,    -1,   150,   151,    -1,   153,   154,    -1,    -1,    -1,
      -1,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,   173,   174,   175,    -1,    -1,
      -1,   179,    -1,   181,   182,    -1,   184,   185,   186,    -1,
     188,    -1,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,    -1,    -1,   203,   204,   205,    -1,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,    -1,   252,   253,   254,    -1,   256,   257,
     258,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    -1,    23,    -1,
      -1,    -1,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      -1,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    90,    91,    92,    93,    94,
      95,    96,    97,    -1,    -1,   100,   101,    -1,    -1,    -1,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,    -1,    -1,   118,    -1,   120,   121,   122,   123,    -1,
     125,    -1,    -1,    -1,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,    -1,    -1,   140,   141,   142,   143,   144,
     145,   146,    -1,    -1,    -1,   150,   151,    -1,   153,   154,
      -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,   174,
     175,    -1,    -1,    -1,   179,    -1,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,    -1,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,    -1,    -1,   203,   204,
     205,    -1,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,    -1,   252,   253,   254,
      -1,   256,   257,   258,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    21,
      -1,    -1,    -1,    -1,    -1,    27,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    -1,    90,    91,
      92,    93,    -1,    95,    96,    97,    -1,    -1,   100,   101,
      -1,    -1,    -1,    -1,   106,   107,   108,   109,   110,   111,
     112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,   121,
     122,   123,    -1,   125,    -1,    -1,    -1,   129,   130,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,   141,
     142,    -1,   144,   145,   146,    -1,    -1,    -1,    -1,    -1,
      -1,   153,   154,    -1,    -1,    -1,    -1,   159,   160,   161,
     162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,    -1,
      -1,   173,   174,   175,    -1,    -1,    -1,   179,    -1,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,    -1,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,   203,   204,    -1,    -1,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
     252,   253,   254,    -1,   256,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    -1,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      -1,    90,    91,    92,    93,    -1,    95,    96,    97,    -1,
      -1,   100,   101,    -1,    -1,    -1,    -1,   106,   107,   108,
     109,   110,   111,   112,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   120,   121,   122,   123,    -1,   125,    -1,    -1,    -1,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,
      -1,   140,   141,   142,    -1,   144,   145,   146,    -1,    -1,
      -1,    -1,    -1,    -1,   153,   154,    -1,    -1,    -1,    -1,
     159,   160,   161,   162,   163,   164,   165,   166,    -1,    -1,
      -1,    -1,    -1,    -1,   173,   174,   175,    -1,    -1,    -1,
     179,    -1,   181,   182,    -1,    -1,    -1,   186,    -1,   188,
      -1,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,    -1,    -1,   203,   204,    -1,    -1,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,    -1,   252,   253,   254,    -1,   256,   257,   258,
     259,   260,   261,    -1,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    21,    -1,    23,    -1,    -1,    -1,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    -1,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      90,    91,    92,    93,    -1,    95,    96,    97,    -1,    -1,
     100,   101,    -1,    -1,    -1,    -1,   106,   107,   108,   109,
     110,   111,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     120,   121,   122,   123,    -1,   125,    -1,    -1,    -1,   129,
     130,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,
     140,   141,   142,    -1,   144,   145,   146,    -1,    -1,    -1,
      -1,    -1,    -1,   153,   154,    -1,    -1,    -1,    -1,   159,
     160,   161,   162,   163,   164,   165,   166,    -1,    -1,    -1,
      -1,    -1,    -1,   173,   174,   175,    -1,    -1,    -1,   179,
     180,   181,   182,    -1,    -1,    -1,    -1,    -1,   188,    -1,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,    -1,    -1,   203,   204,    -1,    -1,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,    -1,   252,   253,   254,    -1,   256,   257,   258,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      21,    -1,    -1,    -1,    -1,    -1,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    -1,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    -1,    90,
      91,    92,    93,    -1,    95,    96,    97,    -1,    -1,   100,
     101,    -1,    -1,    -1,    -1,   106,   107,   108,   109,   110,
     111,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,
     121,   122,   123,    -1,   125,    -1,    -1,    -1,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,
     141,   142,    -1,   144,   145,   146,    -1,    -1,    -1,    -1,
      -1,    -1,   153,   154,    -1,    -1,    -1,    -1,   159,   160,
     161,   162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,
      -1,    -1,   173,   174,   175,    -1,    -1,    -1,   179,    -1,
     181,   182,    -1,    -1,    -1,    -1,    -1,   188,    -1,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
      -1,    -1,   203,   204,    -1,    -1,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      -1,   252,   253,   254,    -1,   256,   257,   258,   259,   260,
     261,    -1,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,    16,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    27,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    -1,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    -1,    90,    91,    92,    93,
      -1,    95,    96,    97,    -1,    -1,   100,   101,    -1,    -1,
      -1,    -1,   106,   107,   108,   109,   110,   111,   112,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   120,   121,   122,   123,
      -1,   125,    -1,    -1,    -1,   129,   130,   131,   132,   133,
      -1,    -1,    -1,    -1,    -1,    -1,   140,   141,   142,    -1,
     144,   145,   146,    -1,    -1,    -1,    -1,    -1,    -1,   153,
     154,    -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,
     164,   165,   166,    -1,    -1,    -1,    -1,    -1,    -1,   173,
     174,   175,    -1,    -1,    -1,   179,    -1,   181,   182,    -1,
      -1,    -1,    -1,    -1,   188,    -1,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    -1,    -1,   203,
     204,    -1,    -1,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,    -1,   252,   253,
     254,    -1,   256,   257,   258,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,    21,
      -1,    -1,    -1,    -1,    -1,    27,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    -1,    90,    91,
      92,    93,    -1,    95,    96,    97,    -1,    -1,   100,   101,
      -1,    -1,    -1,    -1,   106,   107,   108,   109,   110,   111,
     112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,   121,
     122,   123,    -1,   125,    -1,    -1,    -1,   129,   130,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,   141,
     142,    -1,   144,   145,   146,    -1,    -1,    -1,   150,    -1,
      -1,   153,   154,    -1,    -1,    -1,    -1,   159,   160,   161,
     162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,    -1,
      -1,   173,   174,   175,    -1,    -1,    -1,   179,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,    -1,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,   203,   204,    -1,    -1,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
     252,   253,   254,    -1,   256,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,    21,    -1,    -1,    -1,    -1,    -1,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    -1,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      90,    91,    92,    93,    -1,    95,    96,    97,    -1,    -1,
     100,   101,    -1,    -1,    -1,    -1,   106,   107,   108,   109,
     110,   111,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     120,   121,   122,   123,    -1,   125,    -1,    -1,    -1,   129,
     130,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,
     140,   141,   142,    -1,   144,   145,   146,    -1,    -1,    -1,
      -1,    -1,    -1,   153,   154,    -1,    -1,    -1,    -1,   159,
     160,   161,   162,   163,   164,   165,   166,    -1,    -1,    -1,
      -1,    -1,    -1,   173,   174,   175,    -1,    -1,    -1,   179,
     180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,    -1,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,    -1,    -1,   203,   204,    -1,    -1,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,    -1,   252,   253,   254,    -1,   256,   257,   258,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,    21,    -1,    -1,    -1,    -1,    -1,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    -1,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    -1,    90,    91,    92,    93,    -1,    95,    96,    97,
      -1,    -1,   100,   101,    -1,    -1,    -1,    -1,   106,   107,
     108,   109,   110,   111,   112,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   120,   121,   122,   123,    -1,   125,    -1,    -1,
      -1,   129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,
      -1,    -1,   140,   141,   142,    -1,   144,   145,   146,    -1,
      -1,    -1,    -1,    -1,    -1,   153,   154,    -1,    -1,    -1,
      -1,   159,   160,   161,   162,   163,   164,   165,   166,    -1,
      -1,    -1,    -1,    -1,    -1,   173,   174,   175,    -1,    -1,
      -1,   179,   180,   181,   182,    -1,    -1,    -1,   186,    -1,
     188,    -1,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,    -1,    -1,   203,   204,    -1,    -1,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,    -1,   252,   253,   254,    -1,   256,   257,
     258,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,    21,    -1,    -1,    -1,    -1,
      -1,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    -1,    90,    91,    92,    93,    -1,    95,
      96,    97,    -1,    -1,   100,   101,    -1,    -1,    -1,    -1,
     106,   107,   108,   109,   110,   111,   112,   113,    -1,    -1,
      -1,    -1,    -1,    -1,   120,   121,   122,   123,    -1,   125,
      -1,    -1,    -1,   129,   130,   131,   132,   133,    -1,    -1,
      -1,    -1,    -1,    -1,   140,   141,   142,    -1,   144,   145,
     146,    -1,    -1,    -1,   150,    -1,    -1,   153,   154,    -1,
      -1,    -1,    -1,   159,   160,   161,   162,   163,   164,   165,
     166,    -1,    -1,    -1,    -1,    -1,    -1,   173,   174,   175,
      -1,    -1,    -1,   179,    -1,   181,   182,    -1,    -1,    -1,
      -1,    -1,   188,    -1,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,    -1,   203,   204,    -1,
      -1,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,    -1,   252,   253,   254,    -1,
     256,   257,   258,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,    21,    -1,    -1,
      -1,    -1,    -1,    27,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    -1,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    -1,    90,    91,    92,    93,
      -1,    95,    96,    97,    -1,    -1,   100,   101,    -1,    -1,
      -1,    -1,   106,   107,   108,   109,   110,   111,   112,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   120,   121,   122,   123,
      -1,   125,    -1,    -1,    -1,   129,   130,   131,   132,   133,
      -1,    -1,    -1,    -1,    -1,    -1,   140,   141,   142,    -1,
     144,   145,   146,    -1,    -1,    -1,   150,    -1,    -1,   153,
     154,    -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,
     164,   165,   166,    -1,    -1,    -1,    -1,    -1,    -1,   173,
     174,   175,    -1,    -1,    -1,   179,    -1,   181,   182,    -1,
      -1,    -1,    -1,    -1,   188,    -1,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    -1,    -1,   203,
     204,    -1,    -1,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,    -1,   252,   253,
     254,    -1,   256,   257,   258,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,    21,
      -1,    -1,    -1,    -1,    -1,    27,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    -1,    90,    91,
      92,    93,    -1,    95,    96,    97,    -1,    -1,   100,   101,
      -1,    -1,    -1,    -1,   106,   107,   108,   109,   110,   111,
     112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,   121,
     122,   123,    -1,   125,    -1,    -1,    -1,   129,   130,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,   141,
     142,    -1,   144,   145,   146,    -1,    -1,    -1,   150,    -1,
      -1,   153,   154,    -1,    -1,    -1,    -1,   159,   160,   161,
     162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,    -1,
      -1,   173,   174,   175,    -1,    -1,    -1,   179,    -1,   181,
     182,    -1,    -1,    -1,    -1,    -1,   188,    -1,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,   203,   204,    -1,    -1,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
     252,   253,   254,    -1,   256,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,    21,    -1,    -1,    -1,    -1,    -1,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    -1,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      90,    91,    92,    93,    -1,    95,    96,    97,    -1,    -1,
     100,   101,    -1,    -1,    -1,    -1,   106,   107,   108,   109,
     110,   111,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     120,   121,   122,   123,    -1,   125,    -1,    -1,    -1,   129,
     130,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,
     140,   141,   142,    -1,   144,   145,   146,    -1,    -1,    -1,
      -1,    -1,    -1,   153,   154,    -1,    -1,    -1,    -1,   159,
     160,   161,   162,   163,   164,   165,   166,    -1,    -1,    -1,
      -1,    -1,    -1,   173,   174,   175,    -1,    -1,    -1,   179,
      -1,   181,   182,    -1,    -1,    -1,    -1,    -1,   188,    -1,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,    -1,    -1,   203,   204,    -1,    -1,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,    -1,   252,   253,   254,    -1,   256,   257,   258,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,    21,    -1,    -1,    -1,    -1,    -1,    27,
      28,    -1,    30,    31,    -1,    33,    34,    35,    36,    37,
      -1,    -1,    40,    41,    42,    -1,    44,    45,    46,    47,
      48,    -1,    50,    51,    52,    53,    54,    55,    -1,    57,
      -1,    -1,    60,    61,    62,    63,    64,    -1,    66,    -1,
      68,    -1,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    -1,    90,    91,    92,    -1,    -1,    95,    96,    97,
      -1,    -1,   100,   101,    -1,    -1,    -1,    -1,   106,   107,
     108,   109,   110,   111,   112,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   120,   121,   122,   123,    -1,   125,    -1,    -1,
      -1,   129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,
      -1,    -1,   140,   141,   142,    -1,   144,   145,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   153,   154,    -1,    -1,    -1,
      -1,   159,   160,   161,   162,   163,   164,   165,   166,    -1,
      -1,    -1,    -1,    -1,    -1,   173,   174,   175,    -1,    -1,
      -1,   179,    -1,   181,   182,    -1,    -1,    -1,    -1,    -1,
     188,    -1,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,    -1,    -1,    -1,   204,    -1,    -1,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,    -1,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,    -1,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,    -1,   252,   253,   254,    -1,   256,   257,
     258,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,     3,    10,    17,    18,    19,    20,    21,    23,    27,
      28,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    90,    91,
      92,    93,    94,    95,    96,    97,   100,   101,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   118,
     120,   121,   122,   123,   125,   129,   130,   131,   132,   133,
     140,   141,   142,   143,   144,   145,   146,   150,   151,   152,
     153,   154,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   169,   170,   173,   174,   175,   179,   181,   182,   184,
     185,   186,   188,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   203,   204,   205,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   252,   253,   254,   256,   257,   258,   259,   260,   261,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   348,   349,   354,   357,
     360,   363,   364,   366,   371,   372,   373,   374,   375,   384,
     385,   387,   388,   389,   394,   396,   398,   399,   400,   405,
     426,   429,   433,   436,   437,   438,   439,   441,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   487,   488,   489,
     503,   504,   506,   507,   508,   509,   510,   511,   512,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   532,
     533,   534,   535,   540,   541,   542,   543,   544,   545,   548,
     552,   607,   608,    27,    28,    44,   177,   207,   385,   177,
     385,   177,   385,    30,    31,    33,    34,    36,    42,    50,
      52,    53,    60,    62,    71,    75,   106,   107,   108,   154,
     163,   194,   212,   222,   254,   280,   281,   282,   283,   284,
     286,   287,   288,   289,   290,   295,   296,   355,   356,   376,
     377,   378,   379,   154,   147,   150,   147,   150,   147,   150,
     147,    63,    68,   113,   391,   150,   365,   150,    28,    57,
     113,    41,   147,   150,   150,   150,   113,   113,   147,   150,
     150,   150,    90,   147,   213,   214,   116,   116,   116,   147,
     150,    32,    37,    39,    40,    41,    42,    43,    46,    54,
      56,    61,    64,    67,    69,    70,    72,    86,    87,    93,
     100,   109,   110,   129,   132,   133,   163,   166,   173,   174,
     182,   194,   216,   218,   220,   221,   228,   230,   231,   232,
     233,   236,   237,   239,   471,   607,   608,   116,   116,   116,
      32,    38,    39,    56,    58,    59,    67,    93,   217,   607,
     113,   116,   116,   180,   385,   607,   147,   116,    14,   606,
     607,    16,   607,   116,   116,   116,   463,   147,    24,   206,
     208,   217,   219,   150,   217,   219,   217,   217,   222,   113,
     147,   367,   234,   234,   235,   150,   147,   113,   319,   320,
       0,   319,   322,   323,    27,    44,   325,   326,   183,   183,
     102,   183,   386,    35,    41,    46,    54,    66,   162,   165,
     179,   204,   390,   395,   396,   397,   414,   415,   419,   401,
     402,   607,   161,    88,   126,   134,   135,   137,   145,   149,
     151,   156,   172,   195,   196,   197,   198,   199,   200,   455,
     456,   242,   152,   169,   191,   112,   140,   153,   186,   193,
     202,   130,   144,    45,   192,    96,    97,   152,   169,   454,
     147,   460,   463,   184,   185,   148,   475,   476,   471,   475,
     471,   150,   475,   139,   150,   177,   177,   177,    23,   605,
     175,   188,   175,   188,   160,   175,   376,   608,   376,   607,
     163,   194,    42,   377,    42,   607,   146,   113,   353,    39,
      42,    75,   101,   162,   606,   213,   214,   215,   293,   294,
     239,   579,   607,   286,   607,   291,   291,   293,   294,   297,
     280,   288,   356,   606,   385,   180,   385,    39,    59,   180,
     528,   529,   385,   180,   186,   607,   388,   277,   277,   113,
     409,   113,   180,   380,   381,   147,   382,   385,   154,   605,
     108,   154,   347,   605,   406,   408,   607,   113,   385,    23,
     180,   606,   607,   607,   607,   427,   428,   607,   385,   180,
     385,   385,   530,   607,   385,   147,   147,   385,   180,   186,
     607,   427,   180,    29,   491,   492,   493,   385,     7,   168,
      15,   385,   206,    23,   388,   388,   180,   388,   388,   388,
     388,   223,   546,   547,   607,   368,   388,   388,   385,   407,
     413,   607,   319,   183,   183,   326,   327,   384,    27,   328,
     384,   388,   387,   113,   162,   164,   164,   388,   388,   102,
      90,    92,   141,   266,   403,   404,   514,   438,   439,   441,
     441,   441,   441,   440,   441,   441,   441,    67,   445,   445,
     444,   446,   446,   446,   446,   447,   447,   448,   448,   223,
      90,    90,    90,   177,   385,   463,   463,   385,   476,   180,
     388,   486,   143,   180,   486,   102,   102,   365,    23,   608,
     608,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,   330,   331,   332,    90,   131,   136,   350,   351,   352,
     607,   131,   136,   154,   154,   330,   605,   121,   126,    49,
      52,    95,   244,   257,   259,   270,   271,   272,   274,   276,
     580,   581,   582,   583,   584,   585,   591,   597,   598,   239,
      90,   229,   359,   292,   607,   607,   607,   126,   177,   177,
     180,   180,   177,   102,   180,   102,   180,   177,   607,    51,
     209,   247,   392,   393,   607,    90,   102,   180,   385,   180,
     606,    92,    39,   606,   605,    92,   102,   136,   404,   514,
     177,   180,   180,   180,   180,   136,   102,   181,   141,   514,
     177,   180,   180,   147,   177,   385,   385,   177,   102,   180,
     102,   180,   181,   607,   492,   493,   124,   189,   177,   177,
     125,   183,    90,   210,   211,   225,    90,   210,   211,   225,
      90,   229,   217,   102,   227,   136,    27,   369,   385,   180,
     177,    40,   102,   326,    27,   183,   108,   183,   607,   164,
     388,   420,   421,   113,   416,   417,   113,    42,   146,   150,
     203,   515,   517,   519,   520,   536,   537,   538,   539,   607,
     113,   388,   113,   141,   404,   141,   141,   403,   404,   441,
     147,   150,   252,   459,   478,   553,   556,   557,   558,   559,
     560,   564,   566,   568,   569,   515,   515,   513,   519,   513,
     177,   178,   102,   180,   180,   142,   159,   142,   159,   131,
     147,   383,   365,   365,   331,   126,   517,   352,   388,   514,
     136,   388,   605,   605,   122,   123,   605,   270,   271,   272,
     276,   607,   256,   267,   256,   267,    23,   279,    92,   108,
     150,   586,   589,   580,    32,    38,    56,    58,    67,    93,
     217,   358,   520,   284,   285,   219,   292,   301,    90,   359,
     292,   605,   147,   530,   531,   607,   530,   531,   141,   514,
     247,    48,    55,    73,   113,   403,   410,   411,   412,   393,
     514,   515,   381,    90,   177,   190,   126,   346,   605,   154,
     126,    92,   346,   113,   388,   136,   136,   404,   147,   388,
     113,   388,   388,   141,    95,   430,   431,   432,    95,   434,
     435,   385,   177,   177,   147,   530,   530,   388,    29,   493,
     124,   189,     8,     9,    98,   117,   119,   187,   382,   488,
     490,   501,   502,   505,    23,   224,   226,   388,   388,   388,
     224,   226,   388,   388,   388,   388,   388,   388,   113,   388,
     388,   353,   370,   102,   183,   177,   367,   238,   549,   550,
     147,   113,   183,   384,   420,    91,   101,   111,   121,   422,
     423,   424,   425,   102,   607,   102,   402,   150,   150,   517,
     150,   138,   169,   186,   516,   607,   607,   388,   141,   388,
     388,   141,   404,   141,   385,   553,   560,   147,   278,   442,
     604,    92,   163,   245,   246,   248,   255,   265,   277,   554,
     555,   574,   575,   576,   577,   599,   602,   251,   253,   561,
     579,   260,   565,   600,   240,   241,   263,   570,   571,   138,
     388,   385,   131,   367,   131,   147,   532,   351,   388,   279,
      23,    92,   108,   150,   592,    23,   586,   359,   516,   219,
     219,   461,   280,   299,   358,   219,   183,   177,   385,   180,
     180,   138,   180,   180,   388,   141,   113,   113,   388,   607,
     412,    73,   515,   388,   605,   102,   346,   408,   388,   388,
     136,   177,   385,   428,   388,   388,   108,   431,    95,   179,
     113,   515,   108,   435,   177,   177,   385,   180,   180,   126,
     187,   490,     6,   607,   187,   501,   183,   225,   225,   225,
     225,   229,   547,   179,   136,   370,   472,   551,   550,   388,
     413,   605,   122,   123,   424,   425,   425,   421,   101,   418,
     417,   180,   186,   515,   518,   180,   180,   180,   388,   388,
     141,   388,   177,   180,   553,   567,   243,   209,   247,   261,
     268,   603,    92,   249,   250,   601,   243,   557,   603,   444,
     574,   558,   141,   275,   562,   563,   601,   279,   573,    74,
     572,   177,   387,    23,   130,   193,   594,   595,   596,    23,
     593,   594,   264,   590,   587,   588,   589,   164,   607,   250,
     359,   461,   177,   388,   607,   607,   411,   388,   120,    92,
     605,   388,   177,   179,   388,   388,   607,   179,   113,   179,
     177,   493,   607,   187,   493,   607,   388,   388,   388,   388,
     388,   388,   388,   150,   202,   383,   177,   425,   605,    90,
     180,   102,   180,   388,   177,   446,    47,   123,   444,   444,
     262,   269,   279,   578,   578,   559,   147,   273,   177,   592,
     592,   596,   102,   180,    23,   601,   180,   102,   361,   362,
     461,   113,   217,   300,   280,   164,    48,   388,   346,   388,
      90,   388,   607,   388,    89,   176,   494,   493,   607,   189,
     493,   113,   472,   515,   515,    90,   444,   444,   191,   385,
      23,   258,   589,   102,   425,   514,   607,   113,   217,   607,
     361,   113,   515,   179,     4,   127,   497,   498,   500,   502,
      22,   128,   495,   496,   499,   502,   189,   493,   189,   607,
     515,   444,   177,   362,   425,   298,   607,   113,   217,   607,
     179,   388,    89,   127,   500,   176,   128,   499,   189,   102,
     180,   388,   298,   607,   113,   388,   113,   383,   286,   298,
     607,   607,   299,   388,   299,   102,   180,   461,   461,   113,
     383,   191,   607,   280,   180,   607,   383,   217,   113,   607,
     299,   461
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
         0,   317,   318,   318,   318,   318,   318,   318,   319,   320,
     320,   320,   320,   321,   321,   322,   322,   322,   322,   323,
     323,   323,   323,   324,   325,   325,   326,   326,   327,   327,
     327,   327,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   329,   329,   330,   330,   331,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   333,   333,   333,   333,
     333,   333,   333,   333,   334,   334,   335,   336,   336,   337,
     337,   338,   339,   340,   340,   341,   341,   342,   342,   342,
     342,   343,   344,   345,   345,   345,   345,   346,   346,   347,
     347,   348,   348,   348,   348,   349,   350,   350,   351,   351,
     351,   352,   353,   353,   354,   354,   354,   355,   355,   356,
     356,   356,   356,   356,   356,   356,   356,   356,   356,   356,
     356,   356,   356,   357,   357,   357,   357,   357,   357,   357,
     357,   358,   358,   359,   359,   360,   360,   361,   361,   362,
     362,   362,   362,   363,   363,   363,   363,   364,   364,   365,
     365,   365,   365,   366,   367,   368,   368,   369,   369,   370,
     370,   371,   372,   373,   374,   374,   375,   375,   375,   376,
     376,   376,   376,   377,   377,   378,   378,   379,   379,   380,
     380,   381,   381,   382,   383,   384,   385,   385,   386,   386,
     387,   387,   388,   388,   388,   388,   388,   388,   388,   388,
     388,   388,   388,   388,   388,   388,   388,   388,   388,   388,
     389,   390,   391,   391,   392,   392,   392,   393,   393,   394,
     394,   395,   396,   396,   396,   397,   397,   397,   397,   397,
     398,   398,   399,   399,   400,   401,   401,   402,   402,   402,
     402,   402,   402,   402,   402,   403,   404,   405,   406,   406,
     407,   407,   408,   408,   408,   408,   409,   409,   410,   410,
     410,   411,   411,   411,   412,   412,   412,   413,   414,   415,
     416,   416,   417,   417,   418,   419,   419,   420,   420,   421,
     421,   422,   422,   422,   422,   422,   422,   422,   423,   423,
     424,   424,   425,   426,   426,   427,   427,   428,   428,   429,
     430,   430,   431,   432,   432,   433,   433,   434,   434,   435,
     435,   436,   437,   437,   438,   438,   439,   439,   439,   439,
     439,   440,   439,   439,   439,   439,   441,   441,   442,   442,
     443,   443,   444,   444,   444,   445,   445,   445,   445,   445,
     446,   446,   446,   447,   447,   447,   448,   448,   449,   449,
     450,   450,   451,   451,   452,   452,   453,   453,   453,   453,
     454,   454,   454,   455,   455,   455,   455,   455,   455,   456,
     456,   456,   457,   457,   457,   457,   458,   458,   459,   459,
     460,   460,   461,   461,   461,   461,   462,   463,   463,   463,
     464,   464,   465,   465,   465,   465,   466,   466,   467,   467,
     467,   467,   467,   467,   467,   468,   468,   469,   469,   470,
     470,   470,   470,   470,   471,   471,   472,   472,   473,   473,
     473,   474,   474,   474,   474,   475,   475,   476,   477,   477,
     477,   477,   477,   477,   477,   477,   477,   478,   478,   479,
     479,   479,   480,   481,   481,   482,   483,   484,   485,   485,
     486,   486,   487,   487,   488,   488,   488,   489,   489,   489,
     489,   489,   489,   490,   490,   491,   491,   492,   493,   493,
     494,   494,   495,   495,   496,   496,   496,   496,   497,   497,
     498,   498,   498,   498,   499,   499,   500,   500,   501,   501,
     501,   501,   502,   502,   502,   502,   503,   503,   504,   504,
     505,   506,   506,   506,   506,   506,   506,   507,   508,   508,
     508,   508,   509,   509,   509,   509,   510,   511,   512,   512,
     512,   512,   513,   513,   514,   515,   515,   515,   516,   516,
     516,   517,   517,   517,   517,   517,   518,   518,   519,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   521,   522,
     522,   522,   523,   524,   525,   525,   525,   526,   526,   526,
     526,   526,   527,   528,   528,   528,   528,   528,   528,   528,
     529,   530,   531,   532,   533,   533,   534,   535,   536,   536,
     537,   538,   538,   539,   540,   540,   540,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   542,   542,   543,
     543,   544,   545,   546,   546,   547,   548,   549,   549,   550,
     550,   550,   550,   551,   551,   552,   552,   553,   554,   554,
     555,   555,   556,   556,   557,   557,   558,   558,   559,   559,
     560,   561,   561,   562,   562,   563,   564,   564,   564,   565,
     565,   566,   567,   567,   568,   569,   569,   570,   570,   571,
     571,   571,   572,   572,   573,   573,   574,   574,   574,   574,
     574,   575,   576,   577,   578,   578,   578,   579,   579,   580,
     580,   580,   580,   580,   580,   580,   580,   581,   581,   581,
     581,   582,   582,   583,   584,   584,   585,   585,   585,   586,
     586,   587,   587,   588,   588,   589,   589,   590,   590,   591,
     591,   591,   592,   592,   593,   593,   594,   594,   595,   595,
     596,   596,   597,   598,   598,   599,   599,   599,   600,   601,
     601,   601,   601,   602,   602,   603,   603,   604,   605,   606,
     606,   607,   607,   607,   607,   607,   607,   607,   607,   607,
     607,   607,   607,   607,   607,   607,   607,   608,   608,   608,
     608,   608,   608,   608,   608,   608,   608,   608,   608,   608,
     608,   608,   608,   608,   608,   608,   608,   608,   608,   608,
     608,   608,   608,   608,   608,   608,   608,   608,   608,   608,
     608,   608,   608,   608,   608,   608,   608,   608,   608,   608,
     608,   608,   608,   608,   608,   608,   608,   608,   608,   608,
     608,   608,   608,   608,   608,   608,   608,   608,   608,   608,
     608,   608,   608,   608,   608,   608,   608,   608,   608,   608,
     608,   608,   608,   608,   608,   608,   608,   608,   608,   608,
     608,   608,   608,   608,   608,   608,   608,   608,   608,   608,
     608,   608,   608,   608,   608,   608,   608,   608,   608,   608,
     608,   608,   608,   608,   608,   608,   608,   608,   608,   608,
     608,   608,   608,   608,   608,   608,   608,   608,   608,   608,
     608,   608,   608,   608,   608,   608,   608,   608,   608,   608,
     608,   608,   608,   608,   608,   608,   608,   608,   608,   608,
     608,   608,   608,   608,   608,   608,   608,   608,   608,   608,
     608,   608,   608,   608,   608,   608,   608,   608,   608,   608,
     608,   608,   608,   608,   608,   608,   608,   608,   608,   608,
     608,   608,   608,   608,   608,   608,   608,   608,   608,   608,
     608,   608,   608,   608,   608,   608,   608,   608,   608,   608,
     608,   608,   608,   608,   608,   608,   608
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  xquery_parser::yyr2_[] =
  {
         0,     2,     1,     2,     1,     2,     2,     3,     1,     1,
       2,     1,     2,     4,     6,     3,     3,     5,     1,     1,
       3,     3,     5,     6,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     1,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     3,     3,     5,
       5,     4,     3,     3,     3,     5,     5,     5,     5,     5,
       5,     4,     3,     3,     4,     5,     6,     1,     3,     3,
       3,     3,     6,     5,     8,     4,     3,     1,     1,     1,
       2,     2,     2,     3,     5,     4,     6,     1,     2,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     1,
       2,     2,     2,     3,     4,     5,     6,     4,     5,     6,
       7,     1,     2,     3,     3,     8,     9,     1,     3,     1,
       2,     2,     3,    11,    14,    13,    22,     3,     3,     2,
       3,     4,     5,     2,     4,     3,     0,     3,     2,     1,
       3,     5,     3,     5,     2,     2,     2,     3,     3,     1,
       2,     1,     1,     4,     4,     5,     5,     7,     5,     1,
       3,     2,     3,     3,     3,     1,     1,     2,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     1,     1,     2,     4,     3,     5,
       4,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     3,     2,     1,     4,     3,     4,     4,
       5,     4,     5,     5,     6,     3,     3,     3,     1,     4,
       1,     4,     3,     4,     4,     5,     4,     5,     1,     2,
       3,     1,     2,     1,     6,     3,     3,     1,     2,     3,
       1,     3,     2,     3,     2,     3,     4,     1,     3,     1,
       2,     1,     1,     1,     2,     2,     2,     3,     1,     1,
       2,     2,     2,     5,     5,     1,     4,     3,     4,     8,
       1,     2,     3,     2,     3,     8,    10,     1,     2,     4,
       7,     8,     1,     3,     1,     3,     1,     3,     3,     3,
       3,     0,     4,     3,     3,     3,     1,     5,     0,     1,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     4,     1,     4,
       1,     4,     1,     4,     1,     2,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     5,     5,     6,     3,     4,     1,     2,
       3,     2,     1,     2,     2,     1,     1,     1,     3,     3,
       1,     1,     1,     2,     1,     2,     2,     1,     2,     2,
       2,     2,     2,     2,     2,     1,     2,     2,     1,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     4,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     3,     1,     4,     4,     3,     4,
       1,     3,     1,     1,     1,     1,     1,     4,     5,     8,
       9,     9,    10,     1,     2,     1,     2,     6,     0,     1,
       3,     3,     0,     1,     1,     1,     2,     2,     0,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     2,     3,     3,
       2,     1,     1,     1,     1,     1,     1,     4,     2,     3,
       6,     7,     2,     3,     6,     7,     4,     4,     2,     3,
       6,     7,     1,     2,     2,     1,     2,     3,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       4,     4,     3,     3,     3,     4,     4,     3,     4,     6,
       4,     6,     4,     3,     4,     6,     6,     4,     6,     6,
       4,     1,     2,     1,     1,     1,     3,     3,     1,     1,
       4,     5,     6,     3,     3,     3,     3,     5,     7,     7,
       5,     5,     5,     7,     7,     5,     5,     3,     3,     5,
       7,     5,     7,     1,     4,     3,     5,     1,     2,     3,
       7,    10,    13,     1,     3,     7,     4,     2,     0,     1,
       1,     2,     1,     3,     1,     3,     1,     4,     1,     2,
       3,     0,     1,     0,     1,     4,     2,     3,     1,     0,
       1,     4,     0,     1,     2,     1,     3,     0,     1,     2,
       2,     1,     0,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     1,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       1,     2,     2,     3,     1,     2,     2,     5,     2,     1,
       1,     0,     1,     1,     3,     3,     5,     0,     2,     4,
       4,     3,     2,     3,     1,     3,     0,     1,     1,     2,
       2,     2,     2,     1,     2,     2,     2,     2,     3,     2,
       3,     3,     4,     2,     2,     1,     1,     3,     1,     1,
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
       1,     1,     1,     1,     1,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const xquery_parser::yytname_[] =
  {
    "\"'end of file'\"", "error", "$undefined", "\"'unrecognized'\"",
  "\"'apos attribute content'\"", "\"'char literal'\"",
  "\"'char literal]]>'\"", "\"'char literal and pi end'\"",
  "\"'&#charref;'\"", "\"'element content'\"", "\"'pref:*'\"",
  "\"'&entity;'\"", "\"'comment literal'\"", "\"'pi <NCName {>'\"",
  "\"'NCName_sval'\"", "\"'pragma literal'\"", "\"'QName #)'\"",
  "\"'*:QName'\"", "\"'element QName {'\"", "\"'attribute QName {'\"",
  "\"'processing-instruction NCName {'\"", "\"'QName'\"",
  "\"'quote attribute content'\"", "\"'STRING'\"", "\"'XML comment'\"",
  "\"'URI'\"", "\"'NCName'\"", "\"'declare'\"", "\"'module'\"",
  "\"'<blank>'\"", "\"'base-uri'\"", "\"'boundary-space'\"",
  "\"'comment'\"", "\"'construction'\"", "\"'copy-namespaces'\"",
  "\"'count'\"", "\"'deterministic'\"", "\"'document'\"",
  "\"'document-node'\"", "\"'element'\"", "\"'eval'\"", "\"'for'\"",
  "\"'function'\"", "\"'if'\"", "\"'import'\"", "\"'instance'\"",
  "\"'let'\"", "\"'most'\"", "\"'next'\"", "\"'no'\"",
  "\"'nondeterministic'\"", "\"'only'\"", "\"'option'\"", "\"'ordering'\"",
  "\"'outer'\"", "\"'previous'\"", "\"'processing-instruction'\"",
  "\"'schema'\"", "\"'schema-attribute'\"", "\"'schema-element'\"",
  "\"'sequential'\"", "\"'set'\"", "\"'simple'\"", "\"'sliding'\"",
  "\"'some'\"", "\"'space'\"", "\"'stable'\"", "\"'text'\"",
  "\"'tumbling'\"", "\"'switch'\"", "\"'typeswitch'\"", "\"'updating'\"",
  "\"'validate'\"", "\"'when'\"", "\"'word'\"", "\"'decimal-format'\"",
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
  "STEP_REDUCE", "$accept", "Module", "UnrecognizedToken",
  "ModuleWithoutBOM", "VersionDecl", "MainModule", "LibraryModule",
  "ModuleDecl", "SIND_DeclList", "VFO_DeclList", "SIND_Decl", "VFO_Decl",
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
  "FTThesaurusID", "opt_relationship", "FTStopWordOption", "FTStopWords",
  "STRING_LITERAL_list", "opt_FTStopWordsInclExcl_list",
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
       318,     0,    -1,   320,    -1,   303,   320,    -1,   319,    -1,
     320,   319,    -1,   303,   319,    -1,   303,   320,   319,    -1,
       3,    -1,   322,    -1,   321,   322,    -1,   323,    -1,   321,
     323,    -1,   207,   208,    23,   183,    -1,   207,   208,    23,
     125,    23,   183,    -1,   325,   183,   384,    -1,   326,   183,
     384,    -1,   325,   183,   326,   183,   384,    -1,   384,    -1,
     324,    -1,   324,   325,   183,    -1,   324,   326,   183,    -1,
     324,   325,   183,   326,   183,    -1,    28,   154,   606,   126,
     605,   183,    -1,   327,    -1,   325,   183,   327,    -1,   328,
      -1,   326,   183,   328,    -1,   333,    -1,   334,    -1,   335,
      -1,   337,    -1,   354,    -1,   357,    -1,   349,    -1,   329,
      -1,   339,    -1,   375,    -1,   360,    -1,   363,    -1,   338,
      -1,    27,   108,    75,   330,    -1,    27,    75,   607,   330,
      -1,   331,    -1,   330,   331,    -1,   332,   126,   532,    -1,
      76,    -1,    84,    -1,    77,    -1,    78,    -1,    79,    -1,
      80,    -1,    85,    -1,    81,    -1,    82,    -1,    83,    -1,
     336,    -1,   343,    -1,   344,    -1,   364,    -1,   340,    -1,
     341,    -1,   342,    -1,   540,    -1,   345,    -1,   348,    -1,
      27,   154,   606,   126,   605,    -1,    27,    31,   175,    -1,
      27,    31,   188,    -1,    27,   108,    39,   154,   605,    -1,
      27,   108,    42,   154,   605,    -1,    27,    52,   607,    23,
      -1,    27,   254,   579,    -1,    27,    53,   163,    -1,    27,
      53,   194,    -1,    27,   108,   162,   121,   122,    -1,    27,
     108,   162,   121,   123,    -1,    27,    34,   175,   102,   142,
      -1,    27,    34,   175,   102,   159,    -1,    27,    34,   160,
     102,   142,    -1,    27,    34,   160,   102,   159,    -1,    27,
     108,   101,   605,    -1,    27,    30,   605,    -1,    44,    57,
     605,    -1,    44,    57,   347,   605,    -1,    44,    57,   605,
      92,   346,    -1,    44,    57,   347,   605,    92,   346,    -1,
     605,    -1,   346,   102,   605,    -1,   154,   606,   126,    -1,
     108,    39,   154,    -1,    44,    28,   605,    -1,    44,    28,
     154,   606,   126,   605,    -1,    44,    28,   605,    92,   346,
      -1,    44,    28,   154,   606,   126,   605,    92,   346,    -1,
      27,   106,   146,   350,    -1,    90,   517,   351,    -1,   351,
      -1,   352,    -1,   131,    -1,   131,   352,    -1,   136,   388,
      -1,   113,   607,    -1,   113,   607,   514,    -1,    27,   107,
     353,   136,   388,    -1,    27,   107,   353,   131,    -1,    27,
     107,   353,   131,   136,   388,    -1,   356,    -1,   355,   356,
      -1,   281,    -1,   282,    -1,   283,    -1,   284,    -1,   163,
      -1,   194,    -1,   222,   294,    -1,   222,   293,    -1,   295,
     294,    -1,   295,   293,    -1,   286,    -1,   287,   286,    -1,
     290,   291,    -1,   289,   291,    -1,    27,   280,   607,    -1,
      27,   280,   607,   359,    -1,    27,   280,   607,    90,   358,
      -1,    27,   280,   607,    90,   358,   359,    -1,    27,   355,
     280,   607,    -1,    27,   355,   280,   607,   359,    -1,    27,
     355,   280,   607,    90,   358,    -1,    27,   355,   280,   607,
      90,   358,   359,    -1,   520,    -1,   520,   516,    -1,   229,
     285,   219,    -1,   229,   284,   219,    -1,    27,   288,   607,
     292,   219,   461,   164,   361,    -1,    27,   355,   288,   607,
     292,   219,   461,   164,   361,    -1,   362,    -1,   361,   102,
     362,    -1,   461,    -1,   461,   514,    -1,   461,   425,    -1,
     461,   514,   425,    -1,    27,   296,   297,   607,   292,   280,
     607,   113,   607,   298,   388,    -1,    27,   296,   297,   607,
     292,   280,   607,   217,   113,   607,   298,   286,   299,   461,
      -1,    27,   296,   297,   607,   292,   280,   607,   300,   217,
     113,   607,   298,   388,    -1,    27,   296,   297,   607,   301,
     299,   250,   280,   607,   217,   113,   607,   299,   461,   191,
     280,   607,   217,   113,   607,   299,   461,    -1,    27,    33,
     175,    -1,    27,    33,   188,    -1,   150,   180,    -1,   150,
     380,   180,    -1,   150,   180,    90,   515,    -1,   150,   380,
     180,    90,   515,    -1,   230,   367,    -1,   147,   368,   385,
     177,    -1,   368,   369,   183,    -1,    -1,   369,   102,   370,
      -1,    27,   370,    -1,   353,    -1,   353,   136,   388,    -1,
      61,   113,   607,   136,   388,    -1,   233,   235,   388,    -1,
     236,   150,   388,   180,   367,    -1,   231,   234,    -1,   232,
     234,    -1,    27,   376,    -1,    27,    50,   376,    -1,    27,
      36,   376,    -1,   377,    -1,    62,   377,    -1,   379,    -1,
     378,    -1,    42,   608,   365,   383,    -1,    42,   608,   365,
     131,    -1,    60,    42,   608,   365,   367,    -1,    60,    42,
     608,   365,   131,    -1,    71,    42,   608,   365,   147,   387,
     177,    -1,    71,    42,   608,   365,   131,    -1,   381,    -1,
     380,   102,   381,    -1,   113,   607,    -1,   113,   607,   514,
      -1,   147,   385,   177,    -1,   147,   385,   177,    -1,   385,
      -1,   387,    -1,   387,   386,    -1,   183,    -1,   386,   387,
     183,    -1,   388,    -1,   387,   102,   388,    -1,   389,    -1,
     426,    -1,   429,    -1,   433,    -1,   436,    -1,   437,    -1,
     541,    -1,   542,    -1,   544,    -1,   543,    -1,   545,    -1,
     548,    -1,   552,    -1,   372,    -1,   373,    -1,   374,    -1,
     371,    -1,   366,    -1,   398,   390,    -1,   179,   388,    -1,
      63,   277,    -1,    68,   277,    -1,   209,    -1,   247,    -1,
      51,   247,    -1,   392,   410,    73,   388,    -1,   392,    73,
     388,    -1,    41,   391,   409,   393,   393,    -1,    41,   391,
     409,   393,    -1,    35,   113,   607,    -1,   400,    -1,   405,
      -1,   394,    -1,   396,    -1,   414,    -1,   419,    -1,   415,
      -1,   395,    -1,   396,    -1,   398,   397,    -1,    41,   113,
      -1,    54,    41,   113,    -1,   399,   401,    -1,   402,    -1,
     401,   102,   113,   402,    -1,   607,   141,   388,    -1,   607,
     514,   141,   388,    -1,   607,   403,   141,   388,    -1,   607,
     514,   403,   141,   388,    -1,   607,   404,   141,   388,    -1,
     607,   514,   404,   141,   388,    -1,   607,   403,   404,   141,
     388,    -1,   607,   514,   403,   404,   141,   388,    -1,    92,
     113,   607,    -1,   266,   113,   607,    -1,    46,   113,   406,
      -1,   408,    -1,   406,   102,   113,   408,    -1,   413,    -1,
     407,   102,   113,   413,    -1,   607,   136,   388,    -1,   607,
     514,   136,   388,    -1,   607,   404,   136,   388,    -1,   607,
     514,   404,   136,   388,    -1,   113,   607,   141,   388,    -1,
     113,   607,   514,   141,   388,    -1,   411,    -1,   113,   607,
      -1,   113,   607,   411,    -1,   403,    -1,   403,   412,    -1,
     412,    -1,    55,   113,   607,    48,   113,   607,    -1,    48,
     113,   607,    -1,    55,   113,   607,    -1,   607,    -1,   204,
     388,    -1,   165,   164,   416,    -1,   417,    -1,   416,   102,
     417,    -1,   113,   607,    -1,   113,   607,   418,    -1,   101,
     605,    -1,   162,   164,   420,    -1,    66,   162,   164,   420,
      -1,   421,    -1,   420,   102,   421,    -1,   388,    -1,   388,
     422,    -1,   423,    -1,   424,    -1,   425,    -1,   423,   424,
      -1,   423,   425,    -1,   424,   425,    -1,   423,   424,   425,
      -1,    91,    -1,   111,    -1,   121,   122,    -1,   121,   123,
      -1,   101,   605,    -1,    64,   113,   427,   181,   388,    -1,
     129,   113,   427,   181,   388,    -1,   428,    -1,   427,   102,
     113,   428,    -1,   607,   141,   388,    -1,   607,   514,   141,
     388,    -1,    69,   150,   385,   180,   430,   108,   179,   388,
      -1,   431,    -1,   430,   431,    -1,   432,   179,   388,    -1,
      95,   388,    -1,   432,    95,   388,    -1,    70,   150,   385,
     180,   434,   108,   179,   388,    -1,    70,   150,   385,   180,
     434,   108,   113,   607,   179,   388,    -1,   435,    -1,   434,
     435,    -1,    95,   515,   179,   388,    -1,    95,   113,   607,
      90,   515,   179,   388,    -1,    43,   150,   385,   180,   190,
     388,   120,   388,    -1,   438,    -1,   437,   161,   438,    -1,
     439,    -1,   438,    88,   439,    -1,   441,    -1,   441,   455,
     441,    -1,   441,   456,   441,    -1,   441,   126,   441,    -1,
     441,   156,   441,    -1,    -1,   441,   151,   440,   441,    -1,
     441,   149,   441,    -1,   441,   137,   441,    -1,   441,   135,
     441,    -1,   443,    -1,   443,   242,    67,   553,   442,    -1,
      -1,   604,    -1,   444,    -1,   444,   191,   444,    -1,   445,
      -1,   444,   169,   445,    -1,   444,   152,   445,    -1,   446,
      -1,   445,   186,   446,    -1,   445,   112,   446,    -1,   445,
     140,   446,    -1,   445,   153,   446,    -1,   447,    -1,   446,
     193,   447,    -1,   446,   202,   447,    -1,   448,    -1,   447,
     144,   448,    -1,   447,   130,   448,    -1,   449,    -1,   449,
      45,   223,   515,    -1,   450,    -1,   450,   192,    90,   515,
      -1,   451,    -1,   451,    96,    90,   513,    -1,   452,    -1,
     452,    97,    90,   513,    -1,   454,    -1,   453,   454,    -1,
     169,    -1,   152,    -1,   453,   169,    -1,   453,   152,    -1,
     457,    -1,   461,    -1,   458,    -1,   195,    -1,   200,    -1,
     199,    -1,   198,    -1,   197,    -1,   196,    -1,   145,    -1,
     172,    -1,   134,    -1,    72,   147,   385,   177,    -1,    72,
     214,   147,   385,   177,    -1,    72,   213,   147,   385,   177,
      -1,    72,    90,   530,   147,   385,   177,    -1,   459,   147,
     177,    -1,   459,   147,   385,   177,    -1,   460,    -1,   459,
     460,    -1,   170,   607,    15,    -1,   170,    16,    -1,   462,
      -1,   462,   463,    -1,   185,   463,    -1,   463,    -1,   184,
      -1,   464,    -1,   464,   184,   463,    -1,   464,   185,   463,
      -1,   465,    -1,   474,    -1,   466,    -1,   466,   475,    -1,
     469,    -1,   469,   475,    -1,   467,   471,    -1,   468,    -1,
     100,   116,    -1,   109,   116,    -1,    93,   116,    -1,   182,
     116,    -1,   110,   116,    -1,   133,   116,    -1,   132,   116,
      -1,   471,    -1,    94,   471,    -1,   470,   471,    -1,   115,
      -1,   166,   116,    -1,    86,   116,    -1,   174,   116,    -1,
     173,   116,    -1,    87,   116,    -1,   520,    -1,   472,    -1,
     607,    -1,   473,    -1,   186,    -1,    10,    -1,    17,    -1,
     477,    -1,   474,   475,    -1,   474,   150,   180,    -1,   474,
     150,   486,   180,    -1,   476,    -1,   475,   476,    -1,   148,
     385,   178,    -1,   478,    -1,   480,    -1,   481,    -1,   482,
      -1,   485,    -1,   487,    -1,   483,    -1,   484,    -1,   533,
      -1,   479,    -1,   532,    -1,   105,    -1,   143,    -1,   118,
      -1,   113,   607,    -1,   150,   180,    -1,   150,   385,   180,
      -1,   114,    -1,   163,   147,   385,   177,    -1,   194,   147,
     385,   177,    -1,   608,   150,   180,    -1,   608,   150,   486,
     180,    -1,   388,    -1,   486,   102,   388,    -1,   488,    -1,
     506,    -1,   489,    -1,   503,    -1,   504,    -1,   151,   607,
     493,   124,    -1,   151,   607,   491,   493,   124,    -1,   151,
     607,   493,   189,   187,   607,   493,   189,    -1,   151,   607,
     493,   189,   490,   187,   607,   493,   189,    -1,   151,   607,
     491,   493,   189,   187,   607,   493,   189,    -1,   151,   607,
     491,   493,   189,   490,   187,   607,   493,   189,    -1,   501,
      -1,   490,   501,    -1,   492,    -1,   491,   492,    -1,    29,
     607,   493,   126,   493,   494,    -1,    -1,    29,    -1,   176,
     495,   176,    -1,    89,   497,    89,    -1,    -1,   496,    -1,
     128,    -1,   499,    -1,   496,   128,    -1,   496,   499,    -1,
      -1,   498,    -1,   127,    -1,   500,    -1,   498,   127,    -1,
     498,   500,    -1,    22,    -1,   502,    -1,     4,    -1,   502,
      -1,   488,    -1,     9,    -1,   505,    -1,   502,    -1,     8,
      -1,   117,    -1,   119,    -1,   382,    -1,   205,    24,   206,
      -1,   205,   206,    -1,   167,   606,   168,    -1,   167,   606,
       7,    -1,    98,     6,    -1,   507,    -1,   508,    -1,   509,
      -1,   510,    -1,   511,    -1,   512,    -1,    37,   147,   385,
     177,    -1,    18,   177,    -1,    18,   385,   177,    -1,    39,
     147,   385,   177,   147,   177,    -1,    39,   147,   385,   177,
     147,   385,   177,    -1,    19,   177,    -1,    19,   385,   177,
      -1,    93,   147,   385,   177,   147,   177,    -1,    93,   147,
     385,   177,   147,   385,   177,    -1,    67,   147,   385,   177,
      -1,    32,   147,   385,   177,    -1,    20,   177,    -1,    20,
     385,   177,    -1,    56,   147,   385,   177,   147,   177,    -1,
      56,   147,   385,   177,   147,   385,   177,    -1,   519,    -1,
     519,   138,    -1,    90,   515,    -1,   517,    -1,   517,   516,
      -1,   203,   150,   180,    -1,   138,    -1,   186,    -1,   169,
      -1,   519,    -1,   520,    -1,   146,   150,   180,    -1,   536,
      -1,   539,    -1,   515,    -1,   518,   102,   515,    -1,   607,
      -1,   522,    -1,   528,    -1,   526,    -1,   529,    -1,   527,
      -1,   525,    -1,   524,    -1,   523,    -1,   521,    -1,   217,
     150,   180,    -1,    38,   150,   180,    -1,    38,   150,   528,
     180,    -1,    38,   150,   529,   180,    -1,    67,   150,   180,
      -1,    32,   150,   180,    -1,    56,   150,   180,    -1,    56,
     150,   606,   180,    -1,    56,   150,    23,   180,    -1,    93,
     150,   180,    -1,    93,   150,   607,   180,    -1,    93,   150,
     607,   102,   530,   180,    -1,    93,   150,   186,   180,    -1,
      93,   150,   186,   102,   530,   180,    -1,    58,   150,   607,
     180,    -1,    39,   150,   180,    -1,    39,   150,   607,   180,
      -1,    39,   150,   607,   102,   530,   180,    -1,    39,   150,
     607,   102,   531,   180,    -1,    39,   150,   186,   180,    -1,
      39,   150,   186,   102,   530,   180,    -1,    39,   150,   186,
     102,   531,   180,    -1,    59,   150,   607,   180,    -1,   607,
      -1,   607,   138,    -1,    23,    -1,   534,    -1,   535,    -1,
     607,   139,   143,    -1,    42,   365,   382,    -1,   537,    -1,
     538,    -1,    42,   150,   186,   180,    -1,    42,   150,   180,
      90,   515,    -1,    42,   150,   518,   180,    90,   515,    -1,
     150,   517,   180,    -1,    27,   212,   213,    -1,    27,   212,
     214,    -1,    27,   212,   215,    -1,   218,   217,   388,   225,
     388,    -1,   218,   217,   388,    90,   224,   225,   388,    -1,
     218,   217,   388,    90,   226,   225,   388,    -1,   218,   217,
     388,   210,   388,    -1,   218,   217,   388,   211,   388,    -1,
     218,   219,   388,   225,   388,    -1,   218,   219,   388,    90,
     224,   225,   388,    -1,   218,   219,   388,    90,   226,   225,
     388,    -1,   218,   219,   388,   210,   388,    -1,   218,   219,
     388,   211,   388,    -1,   216,   217,   388,    -1,   216,   219,
     388,    -1,   221,   217,   388,   229,   388,    -1,   221,   222,
     223,   217,   388,   229,   388,    -1,   220,   217,   388,    90,
     388,    -1,   228,   113,   546,   227,   388,   179,   388,    -1,
     547,    -1,   546,   102,   113,   547,    -1,   607,   136,   388,
      -1,   237,   147,   385,   177,   549,    -1,   550,    -1,   549,
     550,    -1,   238,   551,   383,    -1,   238,   551,   150,   113,
     607,   180,   383,    -1,   238,   551,   150,   113,   607,   102,
     113,   607,   180,   383,    -1,   238,   551,   150,   113,   607,
     102,   113,   607,   102,   113,   607,   180,   383,    -1,   472,
      -1,   551,   202,   472,    -1,   239,   113,   407,    40,   147,
     388,   177,    -1,    40,   147,   388,   177,    -1,   556,   554,
      -1,    -1,   555,    -1,   574,    -1,   555,   574,    -1,   557,
      -1,   556,   255,   557,    -1,   558,    -1,   557,   251,   558,
      -1,   559,    -1,   558,   253,   141,   559,    -1,   560,    -1,
     252,   560,    -1,   564,   561,   562,    -1,    -1,   579,    -1,
      -1,   563,    -1,   275,   147,   385,   177,    -1,   568,   565,
      -1,   150,   553,   180,    -1,   566,    -1,    -1,   600,    -1,
     459,   147,   567,   177,    -1,    -1,   553,    -1,   569,   570,
      -1,   478,    -1,   147,   385,   177,    -1,    -1,   571,    -1,
     241,   572,    -1,   240,   573,    -1,   263,    -1,    -1,    74,
      -1,    -1,   279,    -1,   575,    -1,   576,    -1,   577,    -1,
     602,    -1,   599,    -1,   163,    -1,   277,   444,   578,    -1,
     246,   601,   578,    -1,   279,    -1,   269,    -1,   262,    -1,
     239,   580,    -1,   579,   239,   580,    -1,   581,    -1,   582,
      -1,   583,    -1,   597,    -1,   584,    -1,   591,    -1,   585,
      -1,   598,    -1,    95,   267,    -1,    95,   256,    -1,   259,
      -1,   274,    -1,   244,   267,    -1,   244,   256,    -1,    52,
     607,    23,    -1,   270,    -1,    49,   270,    -1,   272,   586,
      -1,   272,   150,   586,   587,   180,    -1,    49,   272,    -1,
     589,    -1,   108,    -1,    -1,   588,    -1,   589,    -1,   588,
     102,   589,    -1,    92,    23,   590,    -1,    92,    23,   590,
     601,   258,    -1,    -1,   264,    23,    -1,   271,   279,   592,
     594,    -1,   271,   279,   108,   594,    -1,    49,   271,   279,
      -1,    92,    23,    -1,   150,   593,   180,    -1,    23,    -1,
     593,   102,    23,    -1,    -1,   595,    -1,   596,    -1,   595,
     596,    -1,   193,   592,    -1,   130,   592,    -1,   257,    23,
      -1,   276,    -1,    49,   276,    -1,    92,   209,    -1,    92,
     247,    -1,   248,   243,    -1,   260,   601,   273,    -1,   249,
     444,    -1,    92,   123,   444,    -1,    92,    47,   444,    -1,
     250,   444,   191,   444,    -1,   265,   603,    -1,   245,   603,
      -1,   268,    -1,   261,    -1,   278,   243,   446,    -1,    23,
      -1,    14,    -1,   607,    -1,   608,    -1,    93,    -1,    32,
      -1,    38,    -1,    39,    -1,   146,    -1,    43,    -1,   217,
      -1,    56,    -1,    58,    -1,    59,    -1,    67,    -1,    70,
      -1,    69,    -1,   203,    -1,   236,    -1,    21,    -1,   207,
      -1,   121,    -1,    31,    -1,   254,    -1,    30,    -1,   214,
      -1,   213,    -1,   140,    -1,    37,    -1,   252,    -1,   253,
      -1,   267,    -1,   256,    -1,   244,    -1,   278,    -1,   270,
      -1,   272,    -1,   271,    -1,   276,    -1,   248,    -1,   243,
      -1,    74,    -1,   209,    -1,   247,    -1,    47,    -1,   215,
      -1,   228,    -1,   295,    -1,   222,    -1,   195,    -1,   200,
      -1,   199,    -1,   198,    -1,   197,    -1,   196,    -1,    92,
      -1,   106,    -1,   107,    -1,   179,    -1,    41,    -1,    54,
      -1,    63,    -1,    68,    -1,    55,    -1,    48,    -1,    51,
      -1,    73,    -1,    35,    -1,   141,    -1,    46,    -1,   204,
      -1,   164,    -1,   165,    -1,   162,    -1,    66,    -1,    91,
      -1,   111,    -1,   122,    -1,   123,    -1,   101,    -1,    64,
      -1,   129,    -1,   181,    -1,    95,    -1,    90,    -1,   190,
      -1,   120,    -1,   161,    -1,    88,    -1,    45,    -1,   223,
      -1,    96,    -1,   191,    -1,   112,    -1,   153,    -1,   193,
      -1,   144,    -1,   130,    -1,    72,    -1,    97,    -1,   192,
      -1,   145,    -1,   175,    -1,   188,    -1,   154,    -1,   131,
      -1,   125,    -1,   160,    -1,   142,    -1,   159,    -1,    27,
      -1,    33,    -1,    53,    -1,   108,    -1,    34,    -1,    52,
      -1,   208,    -1,    44,    -1,    57,    -1,    28,    -1,    42,
      -1,   266,    -1,   242,    -1,   275,    -1,   277,    -1,   246,
      -1,   260,    -1,   273,    -1,   265,    -1,   245,    -1,   259,
      -1,   274,    -1,   264,    -1,   258,    -1,   257,    -1,   241,
      -1,   240,    -1,   263,    -1,   249,    -1,   250,    -1,   279,
      -1,   269,    -1,   268,    -1,   261,    -1,   221,    -1,   227,
      -1,   224,    -1,   218,    -1,   211,    -1,   210,    -1,   212,
      -1,   229,    -1,   219,    -1,   220,    -1,   226,    -1,   216,
      -1,   225,    -1,    62,    -1,    60,    -1,    71,    -1,    36,
      -1,    50,    -1,   163,    -1,   194,    -1,   235,    -1,   230,
      -1,   233,    -1,   234,    -1,   231,    -1,   232,    -1,   237,
      -1,   238,    -1,    40,    -1,   239,    -1,    61,    -1,   288,
      -1,   286,    -1,   287,    -1,   292,    -1,   293,    -1,   294,
      -1,   289,    -1,   290,    -1,   291,    -1,    75,    -1,    76,
      -1,    77,    -1,    78,    -1,    79,    -1,    80,    -1,    81,
      -1,    82,    -1,    83,    -1,    84,    -1,    85,    -1,   280,
      -1,   281,    -1,   282,    -1,   283,    -1,   284,    -1,   285,
      -1,   296,    -1,   297,    -1,   298,    -1,   299,    -1,   300,
      -1,   301,    -1,   302,    -1,    86,    -1,   100,    -1,   109,
      -1,   166,    -1,   173,    -1,   182,    -1,   132,    -1,    87,
      -1,   110,    -1,   133,    -1,   174,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  xquery_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    10,    13,    16,    20,    22,
      24,    27,    29,    32,    37,    44,    48,    52,    58,    60,
      62,    66,    70,    76,    83,    85,    89,    91,    95,    97,
      99,   101,   103,   105,   107,   109,   111,   113,   115,   117,
     119,   121,   126,   131,   133,   136,   140,   142,   144,   146,
     148,   150,   152,   154,   156,   158,   160,   162,   164,   166,
     168,   170,   172,   174,   176,   178,   180,   186,   190,   194,
     200,   206,   211,   215,   219,   223,   229,   235,   241,   247,
     253,   259,   264,   268,   272,   277,   283,   290,   292,   296,
     300,   304,   308,   315,   321,   330,   335,   339,   341,   343,
     345,   348,   351,   354,   358,   364,   369,   376,   378,   381,
     383,   385,   387,   389,   391,   393,   396,   399,   402,   405,
     407,   410,   413,   416,   420,   425,   431,   438,   443,   449,
     456,   464,   466,   469,   473,   477,   486,   496,   498,   502,
     504,   507,   510,   514,   526,   541,   555,   578,   582,   586,
     589,   593,   598,   604,   607,   612,   616,   617,   621,   624,
     626,   630,   636,   640,   646,   649,   652,   655,   659,   663,
     665,   668,   670,   672,   677,   682,   688,   694,   702,   708,
     710,   714,   717,   721,   725,   729,   731,   733,   736,   738,
     742,   744,   748,   750,   752,   754,   756,   758,   760,   762,
     764,   766,   768,   770,   772,   774,   776,   778,   780,   782,
     784,   787,   790,   793,   796,   798,   800,   803,   808,   812,
     818,   823,   827,   829,   831,   833,   835,   837,   839,   841,
     843,   845,   848,   851,   855,   858,   860,   865,   869,   874,
     879,   885,   890,   896,   902,   909,   913,   917,   921,   923,
     928,   930,   935,   939,   944,   949,   955,   960,   966,   968,
     971,   975,   977,   980,   982,   989,   993,   997,   999,  1002,
    1006,  1008,  1012,  1015,  1019,  1022,  1026,  1031,  1033,  1037,
    1039,  1042,  1044,  1046,  1048,  1051,  1054,  1057,  1061,  1063,
    1065,  1068,  1071,  1074,  1080,  1086,  1088,  1093,  1097,  1102,
    1111,  1113,  1116,  1120,  1123,  1127,  1136,  1147,  1149,  1152,
    1157,  1165,  1174,  1176,  1180,  1182,  1186,  1188,  1192,  1196,
    1200,  1204,  1205,  1210,  1214,  1218,  1222,  1224,  1230,  1231,
    1233,  1235,  1239,  1241,  1245,  1249,  1251,  1255,  1259,  1263,
    1267,  1269,  1273,  1277,  1279,  1283,  1287,  1289,  1294,  1296,
    1301,  1303,  1308,  1310,  1315,  1317,  1320,  1322,  1324,  1327,
    1330,  1332,  1334,  1336,  1338,  1340,  1342,  1344,  1346,  1348,
    1350,  1352,  1354,  1359,  1365,  1371,  1378,  1382,  1387,  1389,
    1392,  1396,  1399,  1401,  1404,  1407,  1409,  1411,  1413,  1417,
    1421,  1423,  1425,  1427,  1430,  1432,  1435,  1438,  1440,  1443,
    1446,  1449,  1452,  1455,  1458,  1461,  1463,  1466,  1469,  1471,
    1474,  1477,  1480,  1483,  1486,  1488,  1490,  1492,  1494,  1496,
    1498,  1500,  1502,  1505,  1509,  1514,  1516,  1519,  1523,  1525,
    1527,  1529,  1531,  1533,  1535,  1537,  1539,  1541,  1543,  1545,
    1547,  1549,  1551,  1554,  1557,  1561,  1563,  1568,  1573,  1577,
    1582,  1584,  1588,  1590,  1592,  1594,  1596,  1598,  1603,  1609,
    1618,  1628,  1638,  1649,  1651,  1654,  1656,  1659,  1666,  1667,
    1669,  1673,  1677,  1678,  1680,  1682,  1684,  1687,  1690,  1691,
    1693,  1695,  1697,  1700,  1703,  1705,  1707,  1709,  1711,  1713,
    1715,  1717,  1719,  1721,  1723,  1725,  1727,  1731,  1734,  1738,
    1742,  1745,  1747,  1749,  1751,  1753,  1755,  1757,  1762,  1765,
    1769,  1776,  1784,  1787,  1791,  1798,  1806,  1811,  1816,  1819,
    1823,  1830,  1838,  1840,  1843,  1846,  1848,  1851,  1855,  1857,
    1859,  1861,  1863,  1865,  1869,  1871,  1873,  1875,  1879,  1881,
    1883,  1885,  1887,  1889,  1891,  1893,  1895,  1897,  1899,  1903,
    1907,  1912,  1917,  1921,  1925,  1929,  1934,  1939,  1943,  1948,
    1955,  1960,  1967,  1972,  1976,  1981,  1988,  1995,  2000,  2007,
    2014,  2019,  2021,  2024,  2026,  2028,  2030,  2034,  2038,  2040,
    2042,  2047,  2053,  2060,  2064,  2068,  2072,  2076,  2082,  2090,
    2098,  2104,  2110,  2116,  2124,  2132,  2138,  2144,  2148,  2152,
    2158,  2166,  2172,  2180,  2182,  2187,  2191,  2197,  2199,  2202,
    2206,  2214,  2225,  2239,  2241,  2245,  2253,  2258,  2261,  2262,
    2264,  2266,  2269,  2271,  2275,  2277,  2281,  2283,  2288,  2290,
    2293,  2297,  2298,  2300,  2301,  2303,  2308,  2311,  2315,  2317,
    2318,  2320,  2325,  2326,  2328,  2331,  2333,  2337,  2338,  2340,
    2343,  2346,  2348,  2349,  2351,  2352,  2354,  2356,  2358,  2360,
    2362,  2364,  2366,  2370,  2374,  2376,  2378,  2380,  2383,  2387,
    2389,  2391,  2393,  2395,  2397,  2399,  2401,  2403,  2406,  2409,
    2411,  2413,  2416,  2419,  2423,  2425,  2428,  2431,  2437,  2440,
    2442,  2444,  2445,  2447,  2449,  2453,  2457,  2463,  2464,  2467,
    2472,  2477,  2481,  2484,  2488,  2490,  2494,  2495,  2497,  2499,
    2502,  2505,  2508,  2511,  2513,  2516,  2519,  2522,  2525,  2529,
    2532,  2536,  2540,  2545,  2548,  2551,  2553,  2555,  2559,  2561,
    2563,  2565,  2567,  2569,  2571,  2573,  2575,  2577,  2579,  2581,
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
         0,  1012,  1012,  1013,  1018,  1019,  1020,  1021,  1025,  1039,
    1044,  1051,  1056,  1067,  1072,  1080,  1085,  1090,  1095,  1103,
    1107,  1112,  1117,  1126,  1135,  1141,  1150,  1156,  1165,  1166,
    1167,  1168,  1173,  1174,  1175,  1176,  1177,  1178,  1179,  1180,
    1181,  1187,  1192,  1201,  1207,  1216,  1225,  1226,  1227,  1228,
    1229,  1230,  1231,  1232,  1233,  1234,  1239,  1240,  1241,  1242,
    1243,  1244,  1245,  1248,  1253,  1254,  1259,  1267,  1273,  1283,
    1289,  1299,  1309,  1317,  1323,  1334,  1339,  1349,  1355,  1361,
    1367,  1384,  1392,  1400,  1404,  1413,  1422,  1435,  1441,  1452,
    1456,  1464,  1469,  1474,  1481,  1494,  1501,  1507,  1514,  1520,
    1524,  1531,  1542,  1546,  1554,  1560,  1566,  1575,  1581,  1590,
    1594,  1600,  1604,  1608,  1612,  1618,  1624,  1630,  1636,  1642,
    1646,  1652,  1658,  1665,  1673,  1681,  1689,  1697,  1709,  1723,
    1737,  1754,  1758,  1767,  1771,  1778,  1786,  1804,  1810,  1818,
    1823,  1830,  1837,  1847,  1857,  1867,  1877,  1894,  1900,  1911,
    1915,  1919,  1923,  1930,  1937,  1956,  1966,  1972,  1978,  1988,
    1995,  2006,  2013,  2020,  2032,  2036,  2043,  2048,  2063,  2080,
    2084,  2088,  2092,  2100,  2111,  2126,  2137,  2152,  2163,  2179,
    2185,  2197,  2201,  2212,  2219,  2227,  2242,  2246,  2260,  2264,
    2273,  2277,  2291,  2292,  2293,  2294,  2295,  2296,  2299,  2300,
    2301,  2302,  2303,  2305,  2306,  2309,  2310,  2311,  2312,  2313,
    2318,  2333,  2340,  2344,  2351,  2355,  2359,  2366,  2374,  2385,
    2395,  2408,  2417,  2418,  2419,  2423,  2424,  2425,  2426,  2427,
    2430,  2436,  2445,  2449,  2457,  2467,  2473,  2485,  2489,  2497,
    2506,  2516,  2524,  2533,  2542,  2557,  2566,  2576,  2584,  2590,
    2599,  2605,  2617,  2625,  2635,  2643,  2655,  2661,  2672,  2674,
    2678,  2686,  2690,  2695,  2699,  2703,  2707,  2715,  2729,  2737,
    2744,  2750,  2761,  2765,  2774,  2782,  2788,  2798,  2804,  2814,
    2818,  2828,  2834,  2840,  2846,  2855,  2864,  2873,  2886,  2890,
    2898,  2904,  2914,  2922,  2931,  2944,  2951,  2963,  2967,  2979,
    2986,  2992,  3001,  3008,  3014,  3026,  3033,  3046,  3052,  3064,
    3070,  3082,  3091,  3095,  3104,  3108,  3116,  3120,  3130,  3137,
    3146,  3156,  3155,  3169,  3178,  3187,  3200,  3204,  3217,  3220,
    3227,  3231,  3240,  3244,  3248,  3257,  3261,  3267,  3273,  3279,
    3290,  3294,  3298,  3306,  3310,  3316,  3326,  3330,  3340,  3344,
    3354,  3358,  3368,  3372,  3382,  3386,  3394,  3398,  3402,  3406,
    3416,  3420,  3424,  3432,  3436,  3440,  3444,  3448,  3452,  3460,
    3464,  3468,  3476,  3480,  3484,  3488,  3499,  3505,  3515,  3521,
    3531,  3535,  3573,  3577,  3583,  3589,  3600,  3608,  3619,  3625,
    3635,  3639,  3647,  3653,  3661,  3667,  3679,  3685,  3695,  3699,
    3703,  3707,  3711,  3717,  3723,  3746,  3750,  3758,  3762,  3773,
    3777,  3781,  3787,  3791,  3805,  3809,  3817,  3821,  3831,  3835,
    3839,  3848,  3852,  3858,  3862,  3870,  3876,  3886,  3894,  3898,
    3902,  3906,  3910,  3914,  3918,  3922,  3926,  3934,  3938,  3946,
    3953,  3960,  3971,  3979,  3983,  3991,  3999,  4007,  4061,  4065,
    4078,  4084,  4094,  4098,  4106,  4110,  4114,  4122,  4132,  4142,
    4152,  4162,  4172,  4187,  4193,  4204,  4210,  4221,  4232,  4234,
    4238,  4243,  4253,  4256,  4263,  4271,  4277,  4287,  4300,  4303,
    4310,  4316,  4322,  4329,  4340,  4344,  4354,  4358,  4368,  4372,
    4376,  4381,  4390,  4396,  4402,  4408,  4418,  4422,  4434,  4438,
    4450,  4462,  4466,  4470,  4474,  4478,  4482,  4490,  4498,  4502,
    4506,  4510,  4527,  4531,  4535,  4539,  4547,  4555,  4563,  4567,
    4571,  4575,  4583,  4589,  4599,  4607,  4611,  4615,  4650,  4656,
    4662,  4672,  4676,  4680,  4684,  4688,  4695,  4701,  4711,  4719,
    4723,  4727,  4731,  4735,  4739,  4743,  4747,  4751,  4759,  4767,
    4771,  4775,  4785,  4793,  4801,  4805,  4809,  4817,  4821,  4827,
    4833,  4837,  4847,  4855,  4859,  4865,  4874,  4883,  4889,  4895,
    4905,  4922,  4929,  4944,  4980,  4984,  4993,  5002,  5012,  5016,
    5025,  5034,  5038,  5049,  5066,  5072,  5078,  5088,  5092,  5098,
    5104,  5108,  5114,  5118,  5124,  5130,  5137,  5147,  5152,  5160,
    5166,  5176,  5198,  5207,  5213,  5226,  5240,  5247,  5253,  5263,
    5268,  5274,  5284,  5297,  5303,  5320,  5324,  5339,  5348,  5351,
    5358,  5363,  5371,  5375,  5382,  5386,  5393,  5397,  5404,  5408,
    5417,  5430,  5433,  5441,  5444,  5452,  5460,  5468,  5472,  5480,
    5483,  5491,  5503,  5506,  5514,  5526,  5532,  5542,  5545,  5553,
    5557,  5561,  5569,  5572,  5580,  5583,  5591,  5595,  5599,  5603,
    5607,  5615,  5623,  5635,  5647,  5651,  5655,  5663,  5669,  5679,
    5683,  5687,  5691,  5695,  5699,  5703,  5707,  5715,  5719,  5723,
    5727,  5735,  5741,  5751,  5761,  5765,  5773,  5783,  5794,  5801,
    5805,  5813,  5816,  5823,  5828,  5837,  5841,  5849,  5852,  5860,
    5869,  5876,  5886,  5890,  5897,  5903,  5913,  5916,  5923,  5928,
    5940,  5948,  5960,  5968,  5972,  5980,  5984,  5988,  5996,  6004,
    6008,  6012,  6016,  6024,  6032,  6044,  6048,  6056,  6069,  6073,
    6074,  6087,  6088,  6089,  6090,  6091,  6092,  6093,  6094,  6095,
    6096,  6097,  6098,  6099,  6100,  6101,  6102,  6106,  6107,  6108,
    6109,  6110,  6111,  6112,  6113,  6114,  6115,  6116,  6117,  6118,
    6119,  6120,  6121,  6122,  6123,  6124,  6125,  6126,  6127,  6128,
    6129,  6130,  6131,  6132,  6133,  6134,  6135,  6136,  6137,  6138,
    6139,  6140,  6141,  6142,  6143,  6144,  6145,  6146,  6147,  6148,
    6149,  6150,  6151,  6152,  6153,  6154,  6155,  6156,  6157,  6158,
    6159,  6160,  6161,  6162,  6163,  6164,  6165,  6166,  6167,  6168,
    6169,  6170,  6171,  6172,  6173,  6174,  6175,  6176,  6177,  6178,
    6179,  6180,  6181,  6182,  6183,  6184,  6185,  6186,  6187,  6188,
    6189,  6190,  6191,  6192,  6193,  6194,  6195,  6196,  6197,  6198,
    6199,  6200,  6201,  6202,  6203,  6204,  6205,  6206,  6207,  6208,
    6209,  6210,  6211,  6212,  6213,  6214,  6215,  6216,  6217,  6218,
    6219,  6220,  6221,  6222,  6223,  6224,  6225,  6226,  6227,  6228,
    6229,  6230,  6231,  6232,  6233,  6234,  6235,  6236,  6237,  6238,
    6239,  6240,  6241,  6242,  6243,  6244,  6245,  6246,  6247,  6248,
    6249,  6250,  6251,  6252,  6253,  6254,  6255,  6256,  6257,  6258,
    6259,  6260,  6261,  6262,  6263,  6264,  6265,  6266,  6267,  6268,
    6269,  6270,  6271,  6272,  6273,  6274,  6275,  6276,  6277,  6278,
    6279,  6280,  6281,  6282,  6283,  6284,  6285,  6286,  6287,  6288,
    6289,  6290,  6291,  6292,  6293,  6294,  6295,  6296,  6297,  6298,
    6299,  6300,  6301,  6302,  6303,  6304,  6305
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
  const int xquery_parser::yylast_ = 11824;
  const int xquery_parser::yynnts_ = 292;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 560;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 317;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 571;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba

/* Line 1053 of lalr1.cc  */
#line 15572 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"


/* Line 1055 of lalr1.cc  */
#line 6309 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"


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

