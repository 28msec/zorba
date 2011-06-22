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
#line 72 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"


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
#line 78 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 874 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 317 of lalr1.cc  */
#line 974 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"

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
  Error const &error = CollectionDecl::validatePropertyList(static_cast<DeclPropertyList*>(props));
  if (error != zorba::zerr::ZXQP0000_NO_ERROR)
  {
    driver.set_expr(new ParseErrorNode(driver.createQueryLoc(loc),
                                       error,
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
  Error const &error =
  AST_IndexDecl::validatePropertyList(static_cast<DeclPropertyList*>(props));

  if (error != zorba::zerr::ZXQP0000_NO_ERROR)
  {
    driver.set_expr(new ParseErrorNode(driver.createQueryLoc(loc),
                                       error,
                                       static_cast<QName*>(qname)->get_qname(),
                                       true));
    return false;
  }
  return true;
}



/* Line 317 of lalr1.cc  */
#line 151 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"

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
#line 217 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
        case 108: /* "\"'DECIMAL'\"" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 324 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 122: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 333 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 147: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 342 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 351 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 360 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 369 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 378 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 387 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 396 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 405 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 414 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 423 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 432 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 441 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 450 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 459 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 468 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 477 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 486 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 495 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 504 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 513 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 522 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 531 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 540 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 549 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 558 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 895 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 567 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 895 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 576 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 585 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 594 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 603 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 612 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 621 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 630 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 639 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 895 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 648 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 657 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 666 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 675 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 684 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 693 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 702 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 711 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 895 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 720 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 729 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 738 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "DeclPropertyList" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 747 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "DeclProperty" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 756 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 765 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "NodeModifier" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 774 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 783 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 792 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 828 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 837 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 846 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 855 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 882 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 900 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 909 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 918 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 927 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 936 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 945 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 954 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 963 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 972 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 981 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 990 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 999 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1008 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1017 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1026 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1035 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1044 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1053 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1062 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1071 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1080 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1089 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1098 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1107 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1116 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1125 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1134 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1143 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1152 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1161 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1170 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1179 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1188 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1197 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1206 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1215 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1224 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1233 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1242 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1251 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1260 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1269 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1278 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1287 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1296 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1305 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1314 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1323 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1332 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1341 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1350 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1359 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1368 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1377 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1386 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1395 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1404 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1413 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1422 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1431 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1440 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1449 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1458 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1467 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1476 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1485 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1494 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1503 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1512 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1521 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1530 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1539 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1548 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1557 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1566 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1575 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1584 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1593 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1602 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1611 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1620 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1629 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1638 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1647 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1656 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1665 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1674 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1683 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1692 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1701 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1710 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1719 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1728 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1737 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1746 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1755 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1764 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1773 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1782 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1791 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1800 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1809 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1818 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1827 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1836 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1845 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1854 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1863 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1872 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1881 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1890 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1899 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1908 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1917 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1926 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1935 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1944 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1953 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1962 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1971 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1980 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1989 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1998 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2007 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2016 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2025 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2034 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2043 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2052 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2061 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2070 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2079 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2088 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2097 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2106 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2115 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2124 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2133 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2142 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2151 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2160 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2169 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2178 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2187 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2196 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2205 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2214 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2223 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2232 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2241 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2250 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2259 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2268 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2277 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2286 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2295 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2304 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2313 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2322 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2331 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2340 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2349 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2358 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2367 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2376 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 895 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2385 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2394 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2403 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2412 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2421 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2430 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2439 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2448 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2457 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2466 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2475 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2484 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2493 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2502 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2511 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2520 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2529 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2538 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2547 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2556 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2565 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2574 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2583 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2592 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2601 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2610 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2619 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2628 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 612: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2637 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 613: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2646 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 617: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2655 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 618: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2664 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 619: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2673 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2682 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 621: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2691 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 622: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2700 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 623: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2709 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 624: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2718 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 625: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2727 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 628: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2736 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 629: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2745 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 630: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2754 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
#line 125 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 553 of lalr1.cc  */
#line 2839 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"

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
#line 1035 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 1044 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 1053 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 1059 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 1067 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 1073 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 1084 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 1089 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 1097 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1104 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1111 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 1120 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1127 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1135 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1143 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1151 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1162 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1167 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1174 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 1181 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 1193 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 1203 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 1210 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 1217 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      // error
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1252 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1257 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1265 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1273 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1281 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1286 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1294 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1299 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1307 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1312 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1320 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1327 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1334 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 1341 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 1356 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 1366 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 1371 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 1379 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1387 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1398 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1405 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1416 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1421 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1429 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1436 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1443 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1452 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(8) - (4)].sval)),
                            SYMTAB((yysemantic_stack_[(8) - (6)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1465 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1473 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1480 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1490 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1497 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1504 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1527 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1533 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1542 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1549 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1559 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1568 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1569 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1570 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1571 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1572 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1573 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1574 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1575 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1576 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1577 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1583 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1591 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1599 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1607 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1614 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1622 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1629 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1634 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1642 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1650 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (2)].varnametype)));

      (yyval.node) = new VarDecl(LOC((yyloc)),
                       nt->theName,
                       nt->theType,
                       (yysemantic_stack_[(4) - (4)].expr),
                       nt->get_annotations(),
                       true,    // global
                       false);  // not external

      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 1665 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(3) - (2)].varnametype)));

      (yyval.node) = new VarDecl(LOC((yyloc)),
                       nt->theName,
                       nt->theType,
                       NULL,   // no init expr
                       nt->get_annotations(),
                       true,   // global
                       true);  // external

      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 1680 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(5) - (2)].varnametype)));

      (yyval.node) = new VarDecl(LOC((yyloc)),
                       nt->theName,
                       nt->theType,
                       (yysemantic_stack_[(5) - (5)].expr),     // init expr
                       nt->get_annotations(),
                       true,   // global
                       true);  // external

      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 1698 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1703 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1711 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1719 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1730 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1735 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1744 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1749 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1761 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1771 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1776 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1785 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1791 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1804 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1809 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1817 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->theParams,
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->theReturnType,
                            (yysemantic_stack_[(4) - (4)].expr),      // body
                            false,   // not explicitly updating
                            false);  // not external
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1828 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            (yysemantic_stack_[(4) - (3)].fnsig)->theParams.getp(),
                            (yysemantic_stack_[(4) - (3)].fnsig)->theReturnType.getp(),
                            NULL,   // no body
                            false,   // not explicitly updating
                            true);  // external
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 1843 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theParams.getp(),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theReturnType.getp(),
                            (yysemantic_stack_[(5) - (5)].expr),    // body
                            true,  // updating
                            false);// not external
      delete (yysemantic_stack_[(5) - (4)].fnsig);
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1855 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theParams.getp(),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theReturnType.getp(),
                            NULL,  // no body
                            true,  // updating
                            true); // external
      delete (yysemantic_stack_[(5) - (4)].fnsig);
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1875 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1880 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1885 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1893 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1900 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1911 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1916 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1926 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      DeclPropertyList *dpl = new DeclPropertyList( LOC((yyloc)) );
      dpl->addProperty(dynamic_cast<DeclProperty*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = dpl;
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1932 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      DeclPropertyList *dpl = dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(2) - (1)].node));
      dpl->addProperty( static_cast<DeclProperty*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1942 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_const );
        }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1946 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_append_only
            );
        }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1952 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_queue );
        }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1956 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_mutable );
        }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1960 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_ordered );
        }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1964 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_unordered
            );
        }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1970 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_equality
            );
        }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1976 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_range
            );
        }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1982 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_equality
            );
        }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1988 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_range
            );
        }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1994 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_unique );
        }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1998 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_non_unique
            );
        }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 2004 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_automatic
            );
        }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 2010 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_manual );
        }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 2017 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL,
                              NULL);
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 2025 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              NULL,
                              static_cast<NodeModifier*>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 2033 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              NULL,
                              NULL,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 2041 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                              NULL,
                              static_cast<NodeModifier*>((yysemantic_stack_[(6) - (6)].node)),
                              static_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)));
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 2049 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 159:

/* Line 678 of lalr1.cc  */
#line 2061 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 160:

/* Line 678 of lalr1.cc  */
#line 2075 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 161:

/* Line 678 of lalr1.cc  */
#line 2089 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 162:

/* Line 678 of lalr1.cc  */
#line 2106 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 2110 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2119 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 2123 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 2130 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                             (yysemantic_stack_[(8) - (6)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                             NULL);
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 2138 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 168:

/* Line 678 of lalr1.cc  */
#line 2156 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 2162 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 2171 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 2176 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 2183 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 2190 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 2202 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 2212 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 2222 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 2233 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 178:

/* Line 678 of lalr1.cc  */
#line 2249 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      if ((yysemantic_stack_[(1) - (1)].expr) == NULL)
      {
        error((yylocation_stack_[(1) - (1)]), "syntax error, unexpected end of file, the query should not be empty");
        YYERROR;
      }

      if (dynamic_cast<BlockBody*>((yysemantic_stack_[(1) - (1)].expr)) != NULL)
      {
        BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(1) - (1)].expr));
        blk->setTopLevel(true);
      }

      (yyval.expr) = new QueryBody(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2269 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2274 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2278 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 2286 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 2291 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 2295 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 2303 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 2308 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 2320 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 2327 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 2356 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 2361 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 2369 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      if (dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (2)].expr)) == NULL)
      {
        BlockBody* blk = new BlockBody(LOC((yyloc)));
        blk->add((yysemantic_stack_[(3) - (2)].expr));
        (yyval.expr) = blk;
      }
      else
      {
        (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
      }
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 2386 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 2394 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 2402 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 2409 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 2416 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 2423 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 2430 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)));
      vdecl->add((yysemantic_stack_[(4) - (4)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 2440 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)),
                                NULL,  // no type
                                NULL,  // no init expr
                                NULL,  // no annotations
                                false, // not global
                                false);// not external
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 2452 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                                dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)), // type
                                NULL,  // no init expr
                                NULL,  // no annotations
                                false, // not global
                                false);// not external

      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 2465 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                NULL,  // no type
                                (yysemantic_stack_[(4) - (4)].expr),    // init expr
                                NULL,  // no annotations
                                false, // not global
                                false);// not external
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 2477 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)), // type
                                (yysemantic_stack_[(5) - (5)].expr),    // init expr
                                NULL,  // no annotations
                                false, // not global
                                false);// not external
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 2493 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 2501 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 2509 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 2517 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* bb = dynamic_cast<BlockBody *>((yysemantic_stack_[(5) - (5)].expr));
      if (bb == NULL)
      {
        bb = new BlockBody((yysemantic_stack_[(5) - (5)].expr)->get_location());
        bb->add((yysemantic_stack_[(5) - (5)].expr));
      }

      (yyval.expr) = new WhileExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), bb);
    }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 2532 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 2537 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 2545 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      ReturnExpr* re = dynamic_cast<ReturnExpr*>((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = new FLWORExpr(LOC((yyloc)),
                         dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node)),
                         re->get_return_val(),
                         re->get_location(),
                         driver.theCompilerCB->theConfig.force_gflwor);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 2559 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      exprnode* retExpr = (yysemantic_stack_[(2) - (2)].expr);

      if (dynamic_cast<VarDeclStmt*>(retExpr) != NULL)
      {
        BlockBody* blk = new BlockBody(LOC((yyloc)));
        blk->add(retExpr);
        retExpr = blk;
      }

      (yyval.expr) = new ReturnExpr(LOC((yyloc)), retExpr);
    }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 2576 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      exprnode* thenExpr = (yysemantic_stack_[(8) - (6)].expr);
      exprnode* elseExpr = (yysemantic_stack_[(8) - (8)].expr);

      if (dynamic_cast<VarDeclStmt*>(thenExpr) != NULL)
      {
        BlockBody* blk = new BlockBody(LOC((yyloc)));
        blk->add(thenExpr);
        thenExpr = blk;
      }

      if (dynamic_cast<VarDeclStmt*>(elseExpr) != NULL)
      {
        BlockBody* blk = new BlockBody(LOC((yyloc)));
        blk->add(elseExpr);
        elseExpr = blk;
      }

      (yyval.expr) = new IfExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), thenExpr, elseExpr);
    }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 2601 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 2609 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 2616 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 2627 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 2633 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 2639 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 230:

/* Line 678 of lalr1.cc  */
#line 2650 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 231:

/* Line 678 of lalr1.cc  */
#line 2665 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 2670 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      Expr* expr = dynamic_cast<Expr*>((yysemantic_stack_[(3) - (1)].expr));
      if ( !expr )
      {
        expr = new Expr( LOC((yyloc)) );
        expr->push_back( (yysemantic_stack_[(3) - (1)].expr) );
      }
      expr->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.expr) = expr;
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2708 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      ReturnExpr *re = dynamic_cast<ReturnExpr*>((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = new FLWORExpr(LOC((yyloc)),
                         dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node)),
                         re->get_return_val(),
                         re->get_location(),
                         driver.theCompilerCB->theConfig.force_gflwor);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 2722 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 2730 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2735 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2743 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 2748 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 2753 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2761 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)),
                            (yysemantic_stack_[(4) - (4)].expr),
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 2770 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            NULL,
                            (yysemantic_stack_[(3) - (3)].expr),
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 2782 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 256:

/* Line 678 of lalr1.cc  */
#line 2792 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 2805 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2829 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2836 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2846 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2854 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2871 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)),
                         NULL,
                         NULL,
                         NULL,
                         (yysemantic_stack_[(3) - (3)].expr),
                         false);
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2881 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         NULL,
                         NULL,
                         NULL,
                         (yysemantic_stack_[(5) - (5)].expr),
                         true);
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2891 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                         NULL,
                         NULL,
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2901 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (2)].node)),
                         NULL,
                         NULL,
                         (yysemantic_stack_[(6) - (6)].expr),
                         true);
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2911 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
                         NULL,
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2921 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (4)].node)),
                         NULL,
                         (yysemantic_stack_[(6) - (6)].expr),
                         true);
    }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 2931 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
                         NULL,
                         (yysemantic_stack_[(5) - (5)].expr),
                         false);
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2941 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(7) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(7) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(7) - (5)].node)),
                         NULL,
                         (yysemantic_stack_[(7) - (7)].expr),
                         true);
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2952 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2961 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 281:

/* Line 678 of lalr1.cc  */
#line 2971 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 282:

/* Line 678 of lalr1.cc  */
#line 2981 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 283:

/* Line 678 of lalr1.cc  */
#line 2997 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 3006 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 3015 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 3023 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 3029 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 3041 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 3049 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 3059 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 3067 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 3079 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 3085 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 3098 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 3102 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 3110 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 3114 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 3123 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 3127 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3131 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3141 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3149 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3156 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3162 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3173 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3177 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3186 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3194 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3200 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3210 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3216 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3226 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3230 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3240 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3246 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3252 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3258 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3267 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3276 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3285 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3298 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3302 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3310 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3316 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3326 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3334 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3343 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3356 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3363 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3375 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3379 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3391 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3398 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3404 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3413 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3420 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3426 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3437 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3444 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3450 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3459 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3468 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3475 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3486 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3493 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3505 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3511 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3523 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3529 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3540 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3546 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3557 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3563 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3574 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3583 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3587 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3596 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3600 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3608 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3612 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 363:

/* Line 678 of lalr1.cc  */
#line 3622 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3629 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3638 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3647 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3652 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3661 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3670 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3679 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3692 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3708 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3712 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3719 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3723 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3732 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3736 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3749 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3753 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3759 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3765 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3771 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3782 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3786 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3790 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3798 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3802 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3808 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3818 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3822 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3832 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3836 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3846 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3850 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3860 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3874 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3878 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3890 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3894 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3898 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3912 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3916 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3924 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3928 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3932 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3936 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3940 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3944 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3952 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3956 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3960 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3968 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3972 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3976 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3980 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3991 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3997 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 4007 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 4013 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 4023 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 4027 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 4031 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 4069 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 4073 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 4083 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 4093 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 4106 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 4115 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      AxisStep* as = dynamic_cast<AxisStep*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (as ?
            new RelativePathExpr(LOC((yyloc)),
                                 ParseConstants::st_slash,
                                 new ContextItemExpr( LOC((yyloc)), true ), (yysemantic_stack_[(1) - (1)].expr))
            :
            (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 4125 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 4129 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 4138 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 4142 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4151 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4157 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4165 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4171 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4183 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4189 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4199 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4203 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4207 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4211 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4215 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4221 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4227 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4235 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4239 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4247 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4251 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4262 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4266 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4270 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4276 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4280 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4294 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4298 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4306 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4310 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4320 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all);
    }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4324 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem);
    }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4328 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix);
    }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4337 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4341 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4345 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4349 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4357 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4363 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4373 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4381 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4385 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4389 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4393 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4397 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4401 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4405 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4409 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4413 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4423 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4431 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4435 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4443 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4450 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4457 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4468 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4476 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4480 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4488 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4496 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4504 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4558 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4562 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4575 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4581 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4591 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4595 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4603 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4607 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4611 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4619 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 505:

/* Line 678 of lalr1.cc  */
#line 4629 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 506:

/* Line 678 of lalr1.cc  */
#line 4639 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 507:

/* Line 678 of lalr1.cc  */
#line 4649 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 508:

/* Line 678 of lalr1.cc  */
#line 4659 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 509:

/* Line 678 of lalr1.cc  */
#line 4669 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 510:

/* Line 678 of lalr1.cc  */
#line 4684 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4701 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4707 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4718 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4735 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4749 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4753 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4760 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4766 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4772 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4780 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4792 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4796 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4803 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4809 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4815 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4822 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4833 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4837 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4847 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4851 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4865 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4874 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4883 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4895 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4901 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
        }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4909 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4914 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4922 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4927 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4935 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4943 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4948 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4953 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 4958 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 4963 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 4968 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 4977 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 4985 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 4989 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 5006 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 5010 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 5018 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 5026 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 5034 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 5038 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 5046 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 5052 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 5062 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 5070 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 5074 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 5078 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 5113 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 5119 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 5125 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5135 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 5139 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 5143 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5147 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5151 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5158 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5164 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5174 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5182 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5186 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5190 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5194 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5198 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5202 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5206 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5210 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5214 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5222 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5230 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5234 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5238 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5248 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5256 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5264 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5268 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5272 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5280 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5284 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5290 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5296 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5300 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5310 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5318 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5322 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5328 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5337 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5346 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5352 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5358 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5368 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5385 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5392 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5407 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5443 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5447 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5455 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5463 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5475 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5479 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5487 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5495 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5499 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5510 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5527 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5533 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5539 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5549 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5553 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5559 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5565 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5569 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5575 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5579 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5585 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5591 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5598 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5608 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5613 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5621 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5627 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5637 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5659 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5668 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5674 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5701 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5708 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5714 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5724 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5729 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5734 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 653:

/* Line 678 of lalr1.cc  */
#line 5744 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 654:

/* Line 678 of lalr1.cc  */
#line 5758 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5766 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5772 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5790 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5798 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5802 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5809 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5814 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5822 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5826 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5833 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5837 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5844 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5848 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5855 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5859 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5868 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5880 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5884 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5891 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5895 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5903 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5911 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5919 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5923 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5930 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5934 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5942 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5953 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5957 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5965 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5977 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5983 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5992 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5996 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 6004 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 6008 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 6012 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 6019 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 6023 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 6030 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 6034 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 6042 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 6046 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 6050 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 6054 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 6058 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 6066 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 6074 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 6086 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 6098 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 6102 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 6106 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 6114 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 6120 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 6130 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 6134 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 6138 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 6142 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 6146 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 6150 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 6154 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 6158 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 6166 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 6170 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 6174 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 6178 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 6186 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 6192 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 6202 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 6212 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 6216 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 6224 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 727:

/* Line 678 of lalr1.cc  */
#line 6234 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 728:

/* Line 678 of lalr1.cc  */
#line 6245 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 6252 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 6256 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 6263 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 6267 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 6274 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 6279 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 6288 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 6297 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 6301 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 6308 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 6312 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 6320 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 6329 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 6336 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 6346 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 6350 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 6357 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 6363 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 6372 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 6376 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 6383 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 6388 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 6400 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 6408 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 6420 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 6428 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 6432 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 6440 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 6444 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 6448 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 6456 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 6464 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 6468 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 6472 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 6476 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 6484 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 6492 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 6504 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 6508 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 6516 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 6534 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          auto_ptr<QName> lQName( static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
          zstring const &tmp = lQName->get_qname();
          if ( tmp.find (':') != string::npos ) {
            error((yylocation_stack_[(1) - (1)]), "A NCName is expected, found a QName");
            YYERROR;
          }
          (yyval.sval) = SYMTAB_PUT(tmp.c_str());
        }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 6547 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 6548 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 6549 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 6550 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 6551 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 6552 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 6553 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 6554 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 6555 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 6556 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 6557 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 6558 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 6559 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 6560 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 6561 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 6566 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 6567 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 6568 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 6569 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 6570 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 6571 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 6572 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 6573 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 6574 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 6575 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 6576 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 6577 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 6578 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 6579 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 6580 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 6581 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 6582 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 6583 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 6584 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 6585 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 6586 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 6587 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 6588 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 6589 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 6590 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 6591 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 6592 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 6593 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 6594 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 6595 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 6596 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 6597 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 6598 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 6599 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 6600 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 6601 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 6602 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 6603 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 6604 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 6605 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 6606 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 6607 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 6608 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 6609 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 6610 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 6611 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 6612 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 6613 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 6614 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 6615 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 6616 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 6617 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 6618 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 6619 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 6620 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 6621 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 6622 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 6623 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 6624 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 6625 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 6626 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 6627 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 6628 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 6629 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 6630 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 6631 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 6632 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 6633 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 6634 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 6635 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 6636 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 6637 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 6638 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 6639 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 6640 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 6641 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 6642 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 6643 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 6644 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 6645 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 6646 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 6647 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 6648 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 6649 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 6650 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 6651 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 6652 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 6653 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 6654 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 6655 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 6656 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 6657 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 6658 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 6659 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 6660 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 6661 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 6662 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 6663 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 6664 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 6665 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 6666 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 6667 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 6668 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 6669 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 6670 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 6671 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6672 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 896:

/* Line 678 of lalr1.cc  */
#line 6673 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 897:

/* Line 678 of lalr1.cc  */
#line 6674 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 898:

/* Line 678 of lalr1.cc  */
#line 6675 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 899:

/* Line 678 of lalr1.cc  */
#line 6676 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 900:

/* Line 678 of lalr1.cc  */
#line 6677 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 901:

/* Line 678 of lalr1.cc  */
#line 6678 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 902:

/* Line 678 of lalr1.cc  */
#line 6679 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 903:

/* Line 678 of lalr1.cc  */
#line 6680 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 904:

/* Line 678 of lalr1.cc  */
#line 6681 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 905:

/* Line 678 of lalr1.cc  */
#line 6682 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 906:

/* Line 678 of lalr1.cc  */
#line 6683 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 907:

/* Line 678 of lalr1.cc  */
#line 6684 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 908:

/* Line 678 of lalr1.cc  */
#line 6685 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 909:

/* Line 678 of lalr1.cc  */
#line 6686 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 910:

/* Line 678 of lalr1.cc  */
#line 6687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 911:

/* Line 678 of lalr1.cc  */
#line 6688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 912:

/* Line 678 of lalr1.cc  */
#line 6689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 913:

/* Line 678 of lalr1.cc  */
#line 6690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 914:

/* Line 678 of lalr1.cc  */
#line 6691 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 915:

/* Line 678 of lalr1.cc  */
#line 6692 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 916:

/* Line 678 of lalr1.cc  */
#line 6693 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 917:

/* Line 678 of lalr1.cc  */
#line 6694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 918:

/* Line 678 of lalr1.cc  */
#line 6695 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 919:

/* Line 678 of lalr1.cc  */
#line 6696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 920:

/* Line 678 of lalr1.cc  */
#line 6697 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 921:

/* Line 678 of lalr1.cc  */
#line 6698 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 922:

/* Line 678 of lalr1.cc  */
#line 6699 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 923:

/* Line 678 of lalr1.cc  */
#line 6700 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 924:

/* Line 678 of lalr1.cc  */
#line 6701 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 925:

/* Line 678 of lalr1.cc  */
#line 6702 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 926:

/* Line 678 of lalr1.cc  */
#line 6703 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 927:

/* Line 678 of lalr1.cc  */
#line 6704 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 928:

/* Line 678 of lalr1.cc  */
#line 6705 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 929:

/* Line 678 of lalr1.cc  */
#line 6706 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 930:

/* Line 678 of lalr1.cc  */
#line 6707 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 931:

/* Line 678 of lalr1.cc  */
#line 6708 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 932:

/* Line 678 of lalr1.cc  */
#line 6709 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 933:

/* Line 678 of lalr1.cc  */
#line 6710 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 934:

/* Line 678 of lalr1.cc  */
#line 6711 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("local"))); }
    break;

  case 935:

/* Line 678 of lalr1.cc  */
#line 6712 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 936:

/* Line 678 of lalr1.cc  */
#line 6713 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 937:

/* Line 678 of lalr1.cc  */
#line 6714 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 938:

/* Line 678 of lalr1.cc  */
#line 6715 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 939:

/* Line 678 of lalr1.cc  */
#line 6716 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 940:

/* Line 678 of lalr1.cc  */
#line 6717 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 941:

/* Line 678 of lalr1.cc  */
#line 6718 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eval"))); }
    break;

  case 942:

/* Line 678 of lalr1.cc  */
#line 6719 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 943:

/* Line 678 of lalr1.cc  */
#line 6720 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 944:

/* Line 678 of lalr1.cc  */
#line 6721 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 945:

/* Line 678 of lalr1.cc  */
#line 6722 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 946:

/* Line 678 of lalr1.cc  */
#line 6723 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 947:

/* Line 678 of lalr1.cc  */
#line 6724 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 948:

/* Line 678 of lalr1.cc  */
#line 6725 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 949:

/* Line 678 of lalr1.cc  */
#line 6726 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 950:

/* Line 678 of lalr1.cc  */
#line 6727 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 951:

/* Line 678 of lalr1.cc  */
#line 6728 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 952:

/* Line 678 of lalr1.cc  */
#line 6729 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 953:

/* Line 678 of lalr1.cc  */
#line 6730 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 954:

/* Line 678 of lalr1.cc  */
#line 6731 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 955:

/* Line 678 of lalr1.cc  */
#line 6732 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 956:

/* Line 678 of lalr1.cc  */
#line 6733 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 957:

/* Line 678 of lalr1.cc  */
#line 6734 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 958:

/* Line 678 of lalr1.cc  */
#line 6735 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 959:

/* Line 678 of lalr1.cc  */
#line 6736 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 960:

/* Line 678 of lalr1.cc  */
#line 6737 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 961:

/* Line 678 of lalr1.cc  */
#line 6738 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 962:

/* Line 678 of lalr1.cc  */
#line 6739 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 963:

/* Line 678 of lalr1.cc  */
#line 6740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 964:

/* Line 678 of lalr1.cc  */
#line 6741 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 965:

/* Line 678 of lalr1.cc  */
#line 6742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 966:

/* Line 678 of lalr1.cc  */
#line 6743 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 967:

/* Line 678 of lalr1.cc  */
#line 6744 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 968:

/* Line 678 of lalr1.cc  */
#line 6745 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 969:

/* Line 678 of lalr1.cc  */
#line 6746 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 970:

/* Line 678 of lalr1.cc  */
#line 6747 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 971:

/* Line 678 of lalr1.cc  */
#line 6748 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 972:

/* Line 678 of lalr1.cc  */
#line 6749 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 973:

/* Line 678 of lalr1.cc  */
#line 6750 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 974:

/* Line 678 of lalr1.cc  */
#line 6751 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 975:

/* Line 678 of lalr1.cc  */
#line 6752 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 976:

/* Line 678 of lalr1.cc  */
#line 6753 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 977:

/* Line 678 of lalr1.cc  */
#line 6754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 978:

/* Line 678 of lalr1.cc  */
#line 6755 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 979:

/* Line 678 of lalr1.cc  */
#line 6756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 980:

/* Line 678 of lalr1.cc  */
#line 6757 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 981:

/* Line 678 of lalr1.cc  */
#line 6758 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 982:

/* Line 678 of lalr1.cc  */
#line 6759 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 983:

/* Line 678 of lalr1.cc  */
#line 6760 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 984:

/* Line 678 of lalr1.cc  */
#line 6761 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 985:

/* Line 678 of lalr1.cc  */
#line 6762 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 986:

/* Line 678 of lalr1.cc  */
#line 6763 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 987:

/* Line 678 of lalr1.cc  */
#line 6764 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 988:

/* Line 678 of lalr1.cc  */
#line 6770 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          // EQName's namespace URI value is whitespace normalized according to the rules for the xs:anyURI type
          std::string uri = "\"" + SYMTAB((yysemantic_stack_[(3) - (1)].sval)) + "\"";
          std::string eqname = SYMTAB(driver.symtab.put_uri(uri.c_str(), uri.size())) + ":" + SYMTAB((yysemantic_stack_[(3) - (3)].sval));
          (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT(eqname.c_str())), true);
        }
    break;

  case 989:

/* Line 678 of lalr1.cc  */
#line 6776 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 678 of lalr1.cc  */
#line 11945 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1431;
  const short int
  xquery_parser::yypact_[] =
  {
      2917, -1431, -1431,  4403,  4403,  4403, -1431, -1431,   155,   323,
      95,  1655,    31, -1431, -1431, -1431,   272, -1431, -1431, -1431,
     369,   415,   738, -1431,   514,   469,   499,   703, -1431,   -60,
   -1431, -1431, -1431, -1431, -1431, -1431,   754, -1431,   579,   585,
   -1431, -1431, -1431, -1431,   570, -1431,   765, -1431,   651,   659,
   -1431,   102, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431,   588,   735, -1431, -1431, -1431,
   -1431,   641,  8858, -1431, -1431, -1431,   751, -1431, -1431, -1431,
     772, -1431,   761,   823, -1431, -1431, 12597, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431,   841, -1431, -1431,   843,   845,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431,  3215,  6185, 12597,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431,   819, -1431, -1431,
     856,  9741, -1431, 10032,   867,   870, -1431, -1431, -1431,   871,
   -1431,  8561, -1431, -1431, -1431, -1431, -1431, -1431,   842, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431,    76,   779, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431,   387,   840,   601,
   -1431,   773,   632, -1431, -1431, -1431, -1431, -1431, -1431,   880,
   -1431,   111,   760,   766,   763, -1431, -1431,   858,   859, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431,  4700,  1007, -1431,  4997, -1431, -1431,   134,    83,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431,    86, -1431, -1431, -1431, -1431, -1431,
   -1431,   201, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
    4403, -1431, -1431, -1431, -1431,    41, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431,   908, -1431,   826, -1431, -1431, -1431,
     503, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,   852,
     927, -1431,   994,   774,   515,   536,   265,   178, -1431,   975,
     830,   929,   930,  7373, -1431, -1431, -1431,   212, -1431, -1431,
    8561, -1431,   180, -1431,   877,  8858, -1431,   877,  8858, -1431,
   -1431, -1431,   605, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431,   912,   890,   881, -1431, -1431,
   -1431, -1431, -1431,   854, -1431,  4403,   855,   860,    78,    78,
    1010,    -1,   607,   216, 12882, 12597,   448,   997, 12597,   891,
     931,   404,  9741, -1431, -1431,   721,   629,   802, 12597, -1431,
   -1431, -1431, -1431, -1431,   757, 12597,   753,   755,   638,   748,
     734,   113, -1431, -1431, -1431,   799, -1431,  9741,  4403,   868,
    4403,    65,  7670, 10602,   770,   776, 12597,   938,    12,   905,
    7670,  1058,    66,    97, 12597,   944,   922,   959, -1431,  7670,
    9448, 12597, 12597, 12597,  4403,   883,  7670,  7670, 12597,  4403,
     914,   915, -1431, -1431, -1431,  7670, 10887, -1431,   916, -1431,
     920, -1431, -1431, -1431, -1431,   921, -1431,   928, -1431, -1431,
   -1431, -1431, -1431,   935, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, 12597, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431,   941, 12597, -1431, -1431, -1431,
     887,  3512,   942,   943,   957, 12597,  4403, -1431,   932,   240,
   -1431,   725,  1061,  7670, -1431, -1431,   121, -1431, -1431, -1431,
    1082, -1431, -1431, -1431, -1431,  7670,   902, -1431,  1087,  7670,
    7670,   933,  7670,  7670,  7670,  7670,   889, 12597,   772,   326,
     934,   937,  7670,  7670,  3215,   873, -1431, -1431, -1431, -1431,
    1655,   703,    96,   107,  1116,  5294,  5294,  5591,  5591,   772,
   -1431, -1431,   908,   772, -1431,  7670, -1431,  1004,   514,   -60,
     962,   955,   961,  4403,  7670, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431,  7967,  7967,  7967, -1431,  7967,  7967, -1431,
    7967, -1431,  7967, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
    7967,  7967,  1060,  7967,  7967,  7967,  7967,  7967,  7967,  7967,
    7967,  7967,  7967,  7967,   903,  1041,  1043,  1045, -1431, -1431,
   -1431,  6482, -1431, -1431,  8561,  8561,  7670,   877, -1431, -1431,
     877, -1431,  6779,   877,  9741,   992,  7076, -1431, -1431, -1431,
   -1431,   256, -1431,   276, -1431, -1431, -1431, -1431, -1431,  1036,
    1037,   469,  1117, -1431, -1431, 12882,  1022,    50, 12597,   986,
     988,  1022,  1010,  1026,  1023, -1431, -1431, -1431, -1431, -1431,
     156,   913,    70, -1431,   862, -1431, -1431, -1431, -1431, 12597,
    1012,  7670,  1040, -1431, 12597, 12597, -1431,  1030,   980,  4403,
   -1431,   981,   920,   585, -1431,   982,   983,   147, -1431,   280,
     283, -1431, -1431,  1064, -1431,    37, 12597,    24, 12597,  1073,
     293, -1431,  4403, -1431,   306, -1431,  9741,  1075,  1128,  9741,
    1010,  1079,    58, 12597,  7670,   -60,   245,   990, -1431,   991,
     995,   996,    60, -1431,    68,  1000, -1431,   334,   342,  1033,
   -1431,  1003,  4403,  4403,   260, -1431,   352,   353,   567,  7670,
     208, -1431, -1431,  7670,  7670,  7670, -1431,  7670, -1431,  7670,
   12597,  1061, -1431,   163,   314, -1431, -1431, -1431,   410, -1431,
      18, -1431, -1431, -1431,   116,   237,  1093,   956,   967,   -13,
   -1431,  1051, -1431,   772, -1431, -1431,  1013,   354,  3809,   412,
    9155,   873, -1431,   134,   135,  1160,  1160, -1431, -1431,   109,
   -1431, -1431,   110, -1431,    48, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, 12597,  1032,  7670,  1088, -1431, -1431, -1431,   927,
   -1431, -1431, -1431, -1431, -1431,  7967, -1431, -1431, -1431,    26,
     536,   536,   535,   265,   265,   265,   265,   178,   178, -1431,
   -1431, 12027, 12027, 12597, 12597, -1431,   443, -1431, -1431,    35,
   -1431, -1431, -1431,   368, -1431, -1431, -1431,   374,    78, -1431,
   -1431,   584,   614,   532, -1431,   469, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431,  1022, -1431,  1076, 12312,
    1063,  7670, -1431, -1431, -1431,  1112,  1010,  1010,  1022, -1431,
     795,  1010,   626, 12597,   327,   434,  1179, -1431, -1431,   924,
     511, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431,   156,   132,   656, -1431,   985,   561,  7670, -1431,
   12597,    71,   917,  1010, -1431, -1431, -1431, -1431,  1059, 12597,
   -1431, 12597, -1431,  1095,  1090, 12027,  1097,  7670,   -12,  1072,
      29,   262,   968, -1431, -1431,   639,    24,  1112, 12027,  1103,
    1129,  1039,  1029,  1096,  1010,  1067,  1098,  1132,  1010,  7670,
     -51, -1431, -1431, -1431,  1080, -1431, -1431, -1431, -1431,  1114,
    7670,  7670,  1089, -1431,  1137,  1139,  4403, -1431,  1056,  1062,
    1092, 12597, -1431, 12597, -1431,  7670,  1100,  1065,  7670,   389,
     390,   396,  1213, -1431,   210, -1431,   533, -1431, -1431,  1222,
   -1431,   667,  7670,  7670,  7670,   702,  7670,  7670,  7670,  7670,
    7670,  7670,  1135,  7670,  7670, -1431, -1431,  5888,  1101,  1102,
    1105,  1106,   826,   831,  1017, -1431,   463, -1431,   115,   105,
      48,  5591,  5591,  5591,  1184, -1431,  7670,   707,  1158, -1431,
   12597,  1159, -1431, -1431,  7670,    26,   375,   370, -1431,   987,
     139,  1009,  1008, -1431, -1431,   802, -1431,  1006,   -90,  1115,
    1118, 12312,  1119, -1431,   554, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431,  1126, -1431, -1431, -1431,  7670, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,   630, -1431,
    1246,   764, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431,   998, -1431, -1431,  1248, -1431, -1431, -1431, -1431, -1431,
     521,  1250, -1431,   685, -1431, -1431, -1431,   916,   415,   921,
     579,   928,   935,   840,  1046,   554,  1055,  1057,  8264,  1015,
     984, -1431,  1112,   132, -1431,  1068,  1109,  4403,  1108,  1113,
    1149,  1122,  1123, 12597,   484, -1431, 12597, -1431,  7670,  1156,
    7670,  1169,  7670,   -10,  1157,  7670,  1164, -1431,  1196,  1198,
    7670, 12597,   853,  1228, -1431, -1431, -1431, -1431, -1431, -1431,
   12027, -1431,  4403,  1010,  1210, -1431, -1431, -1431,  1010,  1210,
   -1431,  7670,  1176,  4403, 12597, -1431, -1431,  7670,  7670,   704,
   -1431,     4,   706, -1431, 11172,   731, -1431,   732, -1431,  1136,
   -1431, -1431,  4403,  1134,  1138, -1431,  7670, -1431, -1431,  1127,
    1137,  1219, -1431,  1194, -1431,   598, -1431, -1431,  1319, -1431,
   -1431,  4403, 12597, -1431,   809, -1431, -1431, -1431,  1140,  1099,
    1104, -1431, -1431, -1431,  1107,  1110, -1431, -1431, -1431, -1431,
   -1431,  1111, 12597,  1143, -1431, -1431,  7670,  7670,  7670,  4106,
    5888,  9155,  1017, -1431,  1215,  9155, -1431,  1160,   263, -1431,
   -1431, -1431,  1158, -1431,  1010, -1431,   822, -1431,   597,  1229,
   -1431,  7670,  1232,  1088,   455,  1147, -1431,    26,  1091, -1431,
   -1431,   337, -1431,   602,   -19,  1094,    26,   602,  7967, -1431,
      74, -1431, -1431, -1431, -1431, -1431, -1431,    26,  1193,  1066,
     913,   -19, -1431, -1431,  1069,  1264, -1431, -1431, -1431, 10317,
    1162,  1163,  1165, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431,  1315,   226,  1316,   226,  1083,
    1244, -1431, -1431, -1431, -1431,  1183, 12597,  1120, -1431,  1046,
    8264, -1431,  1172, -1431, -1431, -1431, -1431, -1431, -1431,  7670,
    1214, -1431, -1431,  7670, -1431,   529, -1431,  7670,  1216,  7670,
   -1431,  7670, 12597, 12597, -1431,   623, -1431,  7670, -1431,  1231,
    1234,  1265,  1010,  1210, -1431,  7670,  1181, -1431, -1431, -1431,
    1180, -1431,    19,  7670,  4403,  1182,    21, -1431, 12597,  1185,
   11457,    33, -1431, 11742,  1186, -1431, -1431,  1190, -1431, -1431,
   -1431,  7670,   733,  1213, 12597,   851, -1431,  1192,  1213, 12597,
   -1431, -1431,  7670,  7670,  7670,  7670,  7670, -1431,  7670,   408,
     427,   435,   531, -1431, 12597, -1431, -1431, -1431, -1431,  1229,
   -1431, -1431, -1431,  1010, -1431, -1431, -1431, -1431, -1431,  1197,
    7967, -1431, -1431, -1431, -1431, -1431,    69,  7967,  7967,   519,
   -1431,  1009, -1431,   219, -1431,  1008,    26,  1217, -1431, -1431,
    1124, -1431, -1431, -1431, -1431,  1272,  1191, -1431,   450, -1431,
   -1431, -1431, -1431,   220,   220, -1431,   226, -1431, -1431,   451,
   -1431,  1339,   -19,  1283,  1195,  8264,   -15,  1121, -1431,  1218,
   -1431, -1431,  7670, -1431,  7670,  1236, -1431,  7670, -1431, -1431,
   -1431,  1330, -1431, -1431,  5888,  7670,  1010, -1431, -1431, -1431,
    7670,  7670, -1431, -1431, -1431,  5888,  5888,  1292,  4403, 12597,
    1204, 12597,  7670, 12597,  1205,  5888, -1431,    38,    23,  1213,
   12597, -1431,  1199,  1213, -1431, -1431, -1431, -1431, -1431, -1431,
    1200,  1137,  1139,  7670,  1275, -1431,   453, -1431, -1431, -1431,
     265,  7967,  7967,   535,   568, -1431, -1431, -1431, -1431, -1431,
   -1431,  7670, -1431, 12027, -1431, 12027,  1299, -1431, -1431, -1431,
    1366, -1431, -1431, -1431,  1133,  1295, -1431, -1431,  1296, -1431,
     729, 12597,  1281,  1189, 12597,  8264, -1431, -1431,  7670, -1431,
    1288, -1431, -1431,  1210, -1431, -1431, 12027, -1431, -1431,  1312,
    7670,  1223, -1431,  1317,  5888, -1431, 12597,   255,   857, -1431,
    1220,  1213, -1431,  1221,  5888,   742,   473, 12597,  1297,  1106,
     535,   535,  7967,   477, -1431, -1431, 12027, -1431, -1431,  1283,
    8264, -1431,  1229,  1125, 12597,  1300,  1207,  1296, -1431, 12597,
    1224, 12027,  4403, 12027,  1233, -1431, -1431,  1320,   440, -1431,
   -1431, -1431, -1431,  1238,   888, -1431, -1431, -1431,  1226, -1431,
    1305, -1431,   459, 12597, -1431,   535, -1431, -1431, -1431, -1431,
   -1431,  7670,  1130, 12597,  1306, -1431,  4403,  1242, -1431, -1431,
    1243,  7670, -1431, -1431, -1431, -1431, -1431, -1431, -1431, 12597,
    1318,  1280,   460, -1431,  1141,  1142, 12597, -1431, -1431,  7670,
    5888,  1251, 12597, -1431,  1322,  1106,  1144,  7670,  1145,  5888,
     461, 12597, -1431,  8264, -1431,  8264,  1323,  1280,  1255, -1431,
    1240, 12597, -1431,  1106,  1161,  1256, -1431, 12597,  1280,  1225,
   -1431,  1326, 12597,  1146,  8264, -1431
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       181,   465,   466,   184,   184,   184,   789,   989,   116,   118,
     614,   880,   889,   830,   794,   792,   774,   881,   884,   837,
     798,   775,   776,   941,   829,   890,   778,   887,   859,   839,
     814,   834,   835,   885,   882,   833,   780,   888,   781,   782,
     929,   943,   928,   831,   850,   844,   783,   832,   785,   784,
     930,   868,   836,   811,   953,   954,   955,   956,   957,   958,
     959,   960,   961,   962,   963,   977,   984,   858,   854,   845,
     825,   773,     0,   853,   861,   869,   978,   849,   486,   826,
     827,   883,   979,   985,   846,   863,     0,   492,   454,   488,
     856,   791,   847,   848,   876,   851,   867,   875,   983,   986,
     797,   838,   878,   487,   866,   871,   777,     0,     0,     0,
     402,   864,   874,   879,   877,   857,   843,   931,   841,   842,
     980,     0,   401,     0,   981,   987,   872,   828,   852,   982,
     432,     0,   464,   873,   855,   862,   870,   865,   932,   819,
     824,   823,   822,   821,   820,   786,   840,     0,   790,   886,
     812,   920,   919,   921,   796,   795,   815,   926,   779,   918,
     923,   924,   915,   818,   860,   917,   927,   925,   916,   816,
     922,   934,   937,   938,   935,   936,   933,   787,   939,   940,
     942,   906,   905,   892,   810,   803,   899,   895,   813,   809,
     907,   908,   799,   800,   793,   802,   904,   903,   900,   896,
     913,   914,   912,   902,   898,   891,   801,   911,   910,   805,
     807,   806,   897,   901,   893,   808,   894,   804,   909,   964,
     965,   966,   967,   968,   969,   945,   946,   944,   950,   951,
     952,   947,   948,   949,   817,   970,   971,   972,   973,   974,
     975,   976,   181,     0,     2,   181,     5,     7,    19,     0,
      24,    27,    32,    33,    34,    35,    36,    37,    38,    28,
      54,    55,    29,    30,     0,    72,    75,    76,    31,    77,
      78,     0,   114,    79,    80,    81,    82,    14,   178,   179,
     180,   187,   189,   483,   190,     0,   191,   192,   193,   194,
     195,   196,   197,   200,   185,   231,   238,   233,   260,   266,
       0,   258,   259,   240,   234,   199,   235,   198,   236,   239,
     357,   359,   361,   371,   375,   377,   380,   385,   388,   391,
     393,   395,   397,     0,   399,   405,   407,     0,   423,   406,
     428,   431,   433,   436,   438,     0,   443,   440,     0,   451,
     461,   463,   437,   467,   474,   484,   475,   476,   477,   480,
     481,   478,   479,   499,   501,   502,   503,   500,   548,   549,
     550,   551,   552,   553,   460,   588,   580,   587,   586,   585,
     582,   584,   581,   583,   485,   482,   615,   616,    39,   241,
     242,   244,   243,   245,   237,     0,   462,   772,   788,   880,
     889,   887,   790,     0,   182,   183,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   144,   145,     0,     0,     0,     0,   140,
     141,   142,   143,   150,     0,     0,     0,     0,     0,     0,
       0,     0,   122,   124,   125,     0,   138,     0,     0,     0,
     184,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   285,   286,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   456,   459,   446,     0,     0,   769,   774,   798,
     776,   829,   890,   778,   839,   780,   850,   783,   785,   784,
     868,   977,   984,   773,   978,   827,   979,   985,   851,   983,
     986,   931,   980,   981,   987,   982,   932,   926,   918,   924,
     915,   816,   934,   937,   938,   935,   787,   939,   452,   462,
     772,   444,     0,   207,   445,   448,   774,   775,   776,   780,
     781,   782,   783,   773,   779,   489,     0,   450,   449,   202,
       0,     0,   778,   785,   784,     0,   184,   490,   939,     0,
     238,     0,   515,     0,   455,   770,     0,   771,   426,   427,
       0,   458,   457,   447,   430,     0,     0,   544,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     3,     1,     6,     8,
       0,     0,     0,     0,     0,   181,   181,   181,   181,     0,
     115,   188,   186,     0,   205,     0,   216,     0,     0,     0,
       0,     0,     0,     0,     0,   221,   246,   265,   261,   267,
     262,   264,   263,     0,     0,     0,   416,     0,     0,   414,
       0,   366,     0,   415,   408,   413,   412,   411,   410,   409,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   404,   403,
     400,     0,   424,   429,     0,     0,     0,   439,   471,   442,
     441,   453,     0,   468,     0,     0,     0,   555,   557,   561,
     614,     0,   120,     0,    43,    40,    41,    44,    45,     0,
       0,     0,     0,    46,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   625,   626,   627,   147,   146,
       0,    99,   154,   151,     0,   153,   152,   149,   148,     0,
     108,     0,     0,   123,     0,     0,   139,     0,     0,     0,
     594,     0,     0,     0,   590,     0,     0,     0,   604,     0,
       0,   248,   249,   268,   269,     0,     0,     0,     0,   130,
       0,   134,   184,   618,     0,    56,     0,    65,     0,     0,
       0,    57,     0,     0,     0,     0,     0,   769,   595,     0,
       0,     0,     0,   330,     0,     0,   593,     0,     0,     0,
     612,     0,     0,     0,     0,   598,     0,     0,   211,     0,
       0,   203,   201,     0,     0,     0,   489,     0,   491,     0,
     516,   515,   512,     0,     0,   546,   545,   425,     0,   543,
       0,   638,   639,   589,     0,     0,     0,     0,     0,     0,
     644,     0,   208,     0,   219,   220,     0,     0,     0,     0,
       0,   224,   225,    20,     0,    21,     0,     4,    25,     0,
      11,    26,     0,    15,   880,    73,    12,    74,    16,   209,
     206,   232,     0,     0,     0,     0,   222,   247,   303,   358,
     360,   364,   370,   369,   368,     0,   365,   362,   363,     0,
     379,   378,   376,   382,   383,   384,   381,   386,   387,   390,
     389,     0,     0,     0,     0,   421,     0,   434,   435,     0,
     472,   469,   497,     0,   988,   617,   495,     0,     0,   117,
     119,     0,     0,     0,    98,     0,    88,    90,    91,    92,
      93,    95,    96,    97,    89,    94,    84,    85,     0,     0,
     104,     0,   100,   102,   103,   110,     0,     0,    83,    42,
       0,     0,     0,     0,     0,     0,     0,   719,   724,     0,
       0,   720,   754,   707,   709,   710,   711,   713,   715,   714,
     712,   716,     0,     0,     0,   155,     0,     0,     0,   107,
       0,   158,     0,     0,   560,   554,   591,   592,     0,     0,
     608,     0,   605,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   250,   251,     0,   256,   136,     0,     0,
     131,     0,     0,     0,     0,     0,     0,    58,     0,     0,
       0,   284,   290,   287,     0,   597,   596,   603,   611,     0,
       0,     0,     0,   559,     0,     0,     0,   417,     0,     0,
       0,     0,   601,     0,   599,     0,   212,     0,     0,     0,
       0,     0,   515,   513,     0,   504,     0,   493,   494,     0,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   210,   217,     0,   778,   785,
     784,   939,     0,     0,     0,   655,     0,   226,     0,     0,
       0,   181,   181,   181,     0,   257,     0,   314,   310,   312,
       0,   304,   305,   367,     0,     0,     0,     0,   685,   373,
     658,   662,   664,   666,   668,   671,   678,   679,   687,   890,
     777,     0,   786,   392,   566,   572,   573,   575,   619,   620,
     576,   579,   394,   396,   563,   398,   422,   473,     0,   470,
     496,   121,    52,    53,    50,    51,   127,   126,     0,    86,
       0,     0,   105,   106,   111,    70,    71,    48,    49,    69,
     725,     0,   728,   755,     0,   718,   717,   722,   721,   753,
       0,     0,   730,     0,   726,   729,   708,     0,     0,     0,
       0,     0,     0,     0,   156,   162,     0,     0,     0,     0,
       0,   109,   112,     0,   159,     0,     0,   184,     0,     0,
     612,     0,     0,     0,     0,   565,     0,   271,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   252,     0,     0,
       0,     0,   297,     0,   294,   299,   255,   137,   132,   135,
       0,   204,     0,     0,    67,    61,    64,    63,     0,    59,
     288,     0,     0,   184,     0,   328,   332,     0,     0,     0,
     335,     0,     0,   341,     0,     0,   348,     0,   352,     0,
     419,   418,   184,     0,     0,   213,     0,   215,   329,     0,
       0,     0,   516,     0,   505,     0,   539,   536,     0,   540,
     541,     0,     0,   535,     0,   510,   538,   537,     0,     0,
       0,   631,   632,   628,     0,     0,   636,   637,   633,   642,
     640,     0,     0,     0,   646,   218,     0,     0,     0,     0,
       0,     0,   647,   648,     0,     0,   227,    22,     0,    13,
      17,    18,   311,   323,     0,   324,     0,   315,   316,   317,
     318,     0,   307,     0,     0,     0,   669,   682,     0,   372,
     374,     0,   701,     0,     0,     0,     0,     0,     0,   657,
     659,   660,   696,   697,   698,   700,   699,     0,     0,   673,
     672,     0,   676,   680,   694,   692,   691,   684,   688,     0,
       0,     0,     0,   569,   571,   570,   567,   564,   498,   129,
     128,    87,   101,   742,   723,     0,   747,     0,   747,   736,
     731,   157,   163,   165,   164,     0,     0,     0,   113,   160,
       0,    23,     0,   609,   610,   613,   606,   607,   270,     0,
       0,   283,   275,     0,   279,     0,   273,     0,     0,     0,
     292,     0,     0,     0,   254,   295,   298,     0,   133,     0,
       0,    66,     0,    60,   289,     0,     0,   331,   333,   338,
       0,   336,     0,     0,     0,     0,     0,   342,     0,     0,
       0,     0,   349,     0,     0,   353,   420,     0,   602,   600,
     214,     0,     0,   515,     0,     0,   547,     0,   515,     0,
     511,    10,     0,     0,     0,     0,     0,   645,     0,     0,
       0,     0,     0,   649,     0,   656,   327,   325,   326,   319,
     320,   321,   313,     0,   308,   306,   686,   677,   683,     0,
       0,   756,   757,   767,   766,   765,     0,     0,     0,     0,
     758,   663,   764,     0,   661,   665,     0,     0,   670,   674,
       0,   695,   690,   693,   689,     0,     0,   577,     0,   574,
     624,   568,   743,     0,     0,   741,   748,   749,   745,     0,
     740,     0,   738,     0,     0,     0,     0,     0,   161,     0,
     556,   272,     0,   281,     0,     0,   277,     0,   280,   293,
     301,   302,   296,   253,     0,     0,     0,    62,   291,   562,
       0,     0,   339,   343,   337,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   558,     0,     0,   515,
       0,   542,     0,   515,   629,   630,   634,   635,   641,   643,
       0,     0,     0,     0,     0,   650,     0,   322,   309,   681,
     768,     0,     0,   760,     0,   706,   705,   704,   703,   702,
     667,     0,   759,     0,   621,     0,     0,   752,   751,   750,
       0,   744,   737,   735,     0,   732,   733,   727,   166,   168,
     170,     0,     0,     0,     0,     0,   276,   274,     0,   282,
       0,   223,   356,    68,   334,   340,     0,   354,   350,     0,
       0,     0,   344,     0,     0,   346,     0,   525,   519,   514,
       0,   515,   506,     0,     0,     0,     0,     0,     0,     0,
     762,   761,     0,     0,   622,   578,     0,   746,   739,     0,
       0,   172,   171,     0,     0,     0,     0,   167,   278,     0,
       0,     0,     0,     0,     0,   533,   527,     0,   526,   528,
     534,   531,   521,     0,   520,   522,   532,   508,     0,   507,
       0,   654,     0,     0,   228,   763,   675,   623,   734,   169,
     173,     0,     0,     0,     0,   300,     0,     0,   347,   345,
       0,     0,   518,   529,   530,   517,   523,   524,   509,     0,
       0,     0,     0,   174,     0,     0,     0,   355,   351,     0,
       0,     0,     0,   651,     0,     0,     0,     0,     0,     0,
       0,     0,   229,     0,   176,     0,     0,     0,     0,   175,
       0,     0,   652,     0,     0,     0,   230,     0,     0,     0,
     653,     0,     0,     0,     0,   177
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1431, -1431,  -221,  1201, -1431,  1206,  1208, -1431,  1209,  -515,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
    -969, -1431, -1431, -1431, -1431,  -212,  -566, -1431,   743,  -398,
   -1431, -1431, -1431, -1431, -1431,   321,   534, -1431, -1431,    -3,
    -232,  1070, -1431,  1024, -1431, -1431,  -626, -1431,   467, -1431,
    1025, -1431,   285,  -924, -1431,  -166,  -209, -1431,  -537, -1431,
      10,    64,    16,  -245,  -176, -1431,  -851, -1431, -1431,  -521,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
     631,   191,  1188,     0, -1431, -1431, -1431, -1431,   478, -1431,
   -1431,  -278, -1431,     6, -1431, -1431,   282,  -718,  -712, -1431,
   -1431,   698, -1431, -1431,    61,   266, -1431, -1431, -1431,   154,
   -1431, -1431,   394,   161, -1431, -1431,   165, -1238, -1431,   939,
     250, -1431, -1431,   247,  -976, -1431, -1431,   248, -1431, -1431,
   -1209, -1212, -1431,   244, -1431, -1431,   861,   863, -1431,  -542,
   -1431, -1431,  -638,   307,  -601,   308,   309, -1431, -1431, -1431,
   -1431, -1431,  1166, -1431, -1431, -1431, -1431,  -828,  -315, -1113,
   -1431,   -97, -1431, -1431, -1431, -1431, -1431, -1431, -1431,   -21,
    -781, -1431, -1431,   575,   213, -1431,  -382, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431,   810, -1431,  -983, -1431,   230, -1431,
     687,  -800, -1431, -1431, -1431, -1431, -1431,  -204,  -197, -1152,
    -897, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431,   608,  -744,  -710,   328,  -816, -1431,    85,  -857, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431,  1053,  1071,  -307,   525,
     367, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431,   217, -1431, -1431,   206,  -990,
     209, -1035, -1431, -1431, -1431,   175,   168,    11,   416, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431,   176, -1431, -1431, -1431,    15,   414,   558, -1431,
   -1431, -1431, -1431, -1431,   358, -1431, -1431, -1430, -1431, -1431,
   -1431,  -531, -1431,   146, -1431,     2, -1431, -1431, -1431, -1431,
   -1221, -1431,   189, -1431,  -300,  -346,   402,   -46, -1431
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   243,   836,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
    1214,   760,   261,   262,   263,   264,   265,   266,   916,   917,
     918,   267,   268,   269,   922,   923,   924,   270,   430,   271,
     272,   681,   273,   432,   433,   434,   449,   750,   751,   435,
     436,   274,  1164,   955,   275,  1618,  1619,   276,   277,   278,
     540,   279,   280,   281,   282,   283,   753,   284,   285,   523,
     286,   287,   288,   289,   290,   291,   615,   292,   293,   831,
     832,   294,   295,   550,   297,   616,   447,   985,   986,   298,
     617,   299,   619,   551,   301,   743,   744,  1202,   456,   302,
     457,   458,   747,  1203,  1204,  1205,   620,   621,  1081,  1082,
    1474,   622,  1078,  1079,  1307,  1308,  1309,  1310,   303,   772,
     773,   304,  1229,  1230,  1422,   305,  1232,  1233,   306,   307,
    1235,  1236,  1237,  1238,   308,   309,   310,   311,   865,   312,
    1319,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   640,   641,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   667,   668,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   893,   352,   353,   354,  1264,   801,
     802,   803,  1649,  1693,  1694,  1687,  1688,  1695,  1689,  1265,
    1266,   355,   356,  1267,   357,   358,   359,   360,   361,   362,
     363,  1113,   980,  1103,  1356,  1104,  1508,  1105,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   779,  1179,
     374,   375,   376,   377,  1107,  1108,  1109,  1110,   378,   379,
     380,   381,   382,   383,   819,   820,   384,  1292,  1293,  1585,
    1066,  1089,  1329,  1330,  1090,  1091,  1092,  1093,  1094,  1339,
    1498,  1499,  1095,  1342,  1096,  1479,  1097,  1098,  1347,  1348,
    1504,  1502,  1331,  1332,  1333,  1334,  1598,   711,   943,   944,
     945,   946,   947,   948,  1154,  1524,  1615,  1155,  1522,  1613,
     949,  1368,  1519,  1515,  1516,  1517,   950,   951,  1335,  1343,
    1489,  1336,  1485,  1320,   385,   556,   386,   387,   388
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int xquery_parser::yytable_ninf_ = -770;
  const short int
  xquery_parser::yytable_[] =
  {
       296,  1034,   585,   296,   296,   296,   300,   872,   431,   300,
     300,   300,   662,   393,   396,   397,   682,   682,  1000,   395,
     395,   395,   618,  1432,  1106,  1106,   520,   978,   596,  1219,
    1012,   845,   847,   979,   564,   601,   593,  1174,  1231,   600,
     520,  1087,  1442,   598,  1026,   873,   874,   875,   876,  1065,
    1315,   518,  1127,  1263,   680,  1375,   454,   822,   840,   843,
     846,   848,  1106,   520,  1191,   903,   704,   394,   394,   394,
    1470,  1471,   974,     8,     9,   520,  1486,   520,   849,   982,
     838,   841,   850,   861,   594,   862,   863,   594,   864,  1221,
     866,   727,  1052,  1616,   477,   404,  1165,   594,   867,   868,
     684,  1621,  1423,  1131,   405,   566,   680,   296,   594,   732,
     594,   594,  1450,   300,   769,  1647,   594,  1423,  1106,  1423,
    1500,  1591,   407,   541,   976,   477,   408,   733,   748,   805,
     975,  1106,   976,  1188,    78,  1397,     8,     9,     8,     9,
     605,   400,   401,   919,   402,   403,   603,  1039,    89,  1561,
     601,   975,   757,   761,  1646,  1344,  1345,   409,   410,  1074,
     404,   975,   406,   953,  1173,  1009,   590,  1069,   579,  1321,
    1157,   394,  1112,   103,  1192,  1158,   732,  1084,  1346,   685,
    1085,  1134,   977,   591,   591,   920,    78,   407,  1424,   437,
     921,  1159,   686,  1160,   733,   468,  1592,   749,   999,   600,
      89,   123,  1161,  1551,  1648,  1556,  1040,  1622,   758,  1041,
     932,   455,   933,  1011,  -769,   413,  1298,  1562,  1117,  1053,
     455,   578,  1562,   722,   756,   103,     8,     9,  1162,   604,
    1432,  1587,  1253,   663,  1321,  1487,  1488,  1196,   983,  1708,
    1371,  1322,   296,  1207,  1106,   296,  1010,   414,   300,  1413,
     734,   300,   605,   469,   934,   759,  1426,  1087,  1087,   455,
    1685,   455,  1193,   412,  1256,  1185,  1189,  1529,  1194,   845,
     847,   595,  1263,   618,   597,   416,   984,  1360,  1208,  1128,
     296,  1263,  1478,  1086,   833,  1351,   300,   567,  1222,   520,
    1623,  1035,   520,  1450,   806,   835,   601,  1071,  1073,   549,
     455,  1614,  1055,  1297,   954,   954,  1322,   699,   455,   398,
     700,   599,   652,  1009,   669,  1365,  1165,   671,   838,   841,
     470,   471,   415,  1083,  1323,  1324,   653,  1325,   894,   968,
    1045,  1042,  1043,   418,   419,   420,   421,   422,  1254,   423,
     424,   425,   426,   427,  1327,   605,  1044,   600,   428,   429,
     605,     8,     9,  1106,  1163,   975,  1328,  1036,   691,   520,
    1513,   898,   520,   661,   417,   605,   520,   702,   856,   664,
     665,   834,   520,  1655,  1367,   643,  1259,  1106,  1260,   520,
     689,   898,  1671,   839,   842,   969,  1686,   123,   971,  1323,
    1324,   520,  1325,   644,  1028,   296,   690,   520,   989,  1326,
     520,   300,   929,   680,  1255,   935,  1261,  1195,   520,  1327,
     993,   605,  1620,   996,   520,   520,   520,   520,   936,   605,
     937,  1328,   520,   438,  1514,   798,   439,  1004,  1378,   703,
     520,   938,   939,   940,  1710,   941,   823,   942,   296,   605,
     296,   899,  1020,  1432,   300,  1685,   300,   605,   699,  1256,
     731,   700,  1046,  1047,   729,  1528,   395,  1021,  1023,   605,
     997,   900,  1263,   650,   296,   970,  1390,  1048,   972,   296,
     300,   602,   651,  1118,   519,   300,   520,   399,   990,  1118,
     729,  1398,   701,    78,   601,   729,  1595,  1088,   535,  1087,
     520,   992,  1106,  1596,   605,   605,  1037,    89,  1087,   520,
    1408,   605,   728,  1597,   394,   845,   847,   845,   702,  1087,
    1065,   552,  1620,   605,  1465,   605,  1121,   605,  1129,  1014,
     440,  1317,   103,   557,  1429,   560,  1084,  1015,   775,  1085,
    1129,   520,   605,   781,  1299,  1300,  1301,  1022,  1024,  1057,
     605,   296,  1256,  1257,   607,   123,   296,   300,   605,   608,
     123,  1481,   300,  1119,   609,  1605,  1610,  1620,  1658,  1120,
     605,  1259,   395,  1260,  1730,  1744,  1756,   887,   888,   441,
     703,  1723,   610,  1106,  1249,  1250,  1106,  1633,   605,   976,
     444,  1251,   605,   601,   296,   445,   602,   431,  1145,  1482,
     300,  1261,  1038,  1580,  1064,   296,   296,   296,   296,  1146,
     828,   300,   300,   300,   300,  1426,  1151,  1256,  1257,   569,
     394,   570,  1581,   296,  1289,   693,  1365,  1294,  1072,   300,
    1582,  1068,  1152,   448,   976,  1116,  1135,  1136,   520,  1389,
     446,  1139,  1366,   737,  1258,  1606,  1611,  1476,  1659,  1507,
    1759,   754,  1760,  1568,  1731,  1745,  1757,   694,  1572,   905,
     766,   646,   520,   450,  1259,  1701,  1260,   777,   778,  1706,
     975,  1775,  1178,  1176,  1181,  1153,   784,  1126,  1087,   611,
    1295,   643,   612,   520,  1534,  1367,  1198,  1535,   520,   520,
     647,  1199,  1583,   752,  1261,  1584,   463,   613,   109,   644,
    1493,   643,  1198,   648,  1215,  1147,  1353,  1199,  1215,  1258,
     520,  1304,   520,  1088,  1088,   121,  1148,  1025,   472,   644,
     520,   645,   614,   520,  1243,  1200,  1244,   520,   976,  1259,
    1560,  1260,  1306,  1564,   643,  1262,   451,   649,  1354,   296,
    1122,   845,   602,   461,   976,   300,   452,   519,  1295,   462,
     519,  1743,   644,   147,   804,  1355,  1106,  1123,  1106,  1261,
    1690,  1696,   296,   109,   520,  1201,   808,   666,   300,   672,
    1124,   474,   991,   453,  1662,  1359,   607,  1762,   395,  1650,
     121,   608,   662,  1653,   827,   829,   609,  1125,  1770,  1106,
    1151,   752,   296,   296,   520,   618,  1595,   687,   300,   300,
    1444,  1690,   475,  1596,   610,   476,  1152,  1696,   729,   729,
     688,  1303,  1228,  1597,  1228,   466,   520,   692,   147,  1106,
     696,  1304,  1285,   467,   557,  1420,   394,  1425,  1256,  1257,
     712,  1305,   975,   572,  1106,   573,  1106,   714,  1062,  1430,
    1433,  1430,  1306,  1304,  1063,   520,   520,   520,   520,   557,
    1430,   431,  1431,  1434,  1567,   740,  1018,  1019,   745,  1593,
    1594,  1698,   886,  1700,   575,   473,   762,   889,  1169,   576,
    1256,  1257,   557,   770,   771,   774,  1256,  1170,  1483,   720,
     780,   521,   607,   520,   721,  1484,  1672,   608,   787,  1590,
     890,   524,   609,   890,  1691,   585,   890,   520,   522,   442,
    1296,   611,   443,  1664,   612,  1665,  1269,  1256,  1270,   920,
     610,  1140,  1141,  1142,   921,   459,  1198,  1143,   460,   799,
    1258,  1199,   670,  1411,   520,  1691,   464,   673,  1215,   465,
     602,  1137,  1138,   520,   788,   520,  1680,   708,   709,   520,
    1259,  1274,  1260,  1275,   614,  1088,   717,   718,   774,   705,
     706,   707,   520,   525,  1088,  1166,  1167,   796,  1467,  1468,
     870,   871,  1258,  1660,  1661,  1088,  1707,   536,   877,   878,
    1261,   879,   880,   537,   109,   538,   413,  1409,  1114,  1114,
     553,  1717,  1259,  1720,  1260,   520,   554,   520,  1259,   821,
    1260,   121,  1607,  1608,  1029,  1030,  1031,   561,   829,  1692,
     562,   563,   568,   565,   571,   574,   577,   611,   414,   580,
     612,  1449,  1261,   582,  1466,   581,   109,   587,  1261,  1259,
     584,  1260,   583,   605,   606,  1290,   296,   623,   624,   147,
    1726,   642,   300,   121,  1705,   654,   416,   655,   656,   666,
     657,   674,   729,   675,   520,   676,   677,   678,   477,  1261,
     614,   697,   679,  1570,   695,   856,   710,   698,   713,   715,
     719,   716,   741,   730,   746,   520,   752,  1062,   742,   755,
     763,   147,   764,  1063,   765,   782,   783,   431,   776,   791,
     439,   296,   296,   296,   443,   460,   557,   300,   300,   300,
    1239,   789,   465,   797,   724,   419,   420,   421,   422,   476,
     423,   424,   725,   426,   427,   800,   793,   794,   807,   428,
     925,   906,   907,   908,   909,   910,   911,   912,   913,   914,
     915,   795,  1547,   809,  1088,   810,   830,   818,   813,   837,
     852,   957,   824,   854,   625,   825,   961,   962,   853,   855,
     869,   881,   626,   627,   882,   628,   883,   520,   884,   895,
     520,   901,   902,   629,   926,   904,   927,   630,   981,   631,
     987,   930,   958,   931,   632,   520,   960,   952,   557,   956,
     963,   557,   964,   965,   520,  1001,   988,   966,   967,   973,
     994,   633,   995,  1588,   998,  1005,  1006,   296,   520,  1553,
    1007,  1008,  1013,   300,  1016,  1017,  1049,  1382,   520,  1051,
    1050,  1054,  1070,   395,   634,   635,   636,   637,   638,   639,
    1076,  1056,  1032,   921,  1080,   975,  1130,  1149,  1150,  1168,
    1177,  1183,   296,  1186,  1175,  1184,   520,  1190,   300,   748,
    1197,  1211,  1210,   296,  1212,  1216,  1213,  1218,  1217,   300,
    1224,  1223,   519,  1416,  1227,  1228,   520,  1234,  1240,   395,
    1246,   394,   296,  1242,  1241,   520,  1215,  1252,   300,   520,
    1268,  1282,  1437,  1247,  1075,  1286,  1287,  1289,   395,  1288,
    1291,   296,   701,  1311,  1313,  1337,  1338,   300,  1357,  1349,
    1318,  1341,  1350,  1352,   680,  1314,  1364,   729,  1369,  1373,
     954,  1374,  1363,  1111,  1111,  1111,  1111,   394,  1377,  1062,
    1062,  1385,  1380,  1383,  1395,  1063,  1063,  1381,  1384,  1631,
    1376,  1393,  1399,   520,  1407,   828,   394,  1386,  1387,  1401,
    1635,  1553,  1402,  1637,  1403,  1412,  1415,  1430,  1436,  1438,
    1645,  1111,  1441,  1439,  1443,  1447,  1446,  1458,  1451,  1452,
     520,  1464,  1477,  1304,  1453,  1144,  1473,  1454,  1496,  1480,
    1455,  1503,  1490,  1512,  1518,  1456,  1497,  1509,  1510,  1523,
    1511,  1525,  1521,  1501,  1530,  1544,   520,   520,  1545,  1532,
    1546,  1537,  1172,  1549,  1550,  1603,  1555,  1612,  1601,  1558,
    1565,  1180,  1566,  1180,  1571,  1527,  1604,  1111,  1151,  1589,
    1617,  1628,   520,  1630,   520,  1636,  1625,   520,  1640,  1644,
    1111,  1657,  1666,  1652,  1667,  1654,  1668,  1674,   520,  1637,
    1669,  1670,  1602,   520,  1679,  1681,  1624,  1682,  1716,  1409,
    1683,  1675,  1722,  1703,  1697,  1699,  1713,  1721,   520,  1725,
    1728,  1729,  1736,   780,   296,   780,  1739,  1740,  1711,  1714,
     300,  1583,  1746,  1734,  1742,  1749,  1764,  1718,  1751,  1761,
    1763,  1768,  1772,   586,   928,  1747,  1767,  1771,  1753,  1755,
    1774,   588,  1362,   589,  1132,   723,  1209,   592,  1379,  1677,
     726,  1709,  1067,  1003,  1206,  1388,  1542,  1475,  1406,   683,
    1302,  1737,  1472,  1469,  1417,   790,  1421,  1459,  1460,  1461,
    1427,  1435,  1312,  1704,   859,  1445,   897,   860,  1033,   660,
    1727,  1724,  1115,  1372,   735,  1737,  1182,  1361,  1463,  1457,
    1462,  1491,  1316,  1111,  1718,  1495,  1494,  1600,  1599,  1340,
    1156,  1370,   736,   520,  1520,   520,  1492,   520,  1609,     0,
       0,     0,     0,     0,   520,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1062,     0,     0,     0,     0,     0,
    1063,     0,     0,     0,     0,  1062,  1062,   520,   296,   520,
       0,  1063,  1063,     0,   300,  1062,     0,     0,     0,  1752,
       0,  1063,     0,     0,     0,   520,     0,     0,   520,     0,
       0,     0,     0,     0,     0,   745,     0,  1766,  1391,     0,
     520,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     520,     0,     0,  1405,     0,     0,     0,     0,     0,     0,
       0,   520,  1111,     0,     0,     0,     0,     0,     0,     0,
     520,     0,     0,     0,     0,     0,   774,     0,   520,     0,
       0,     0,     0,   520,     0,   520,  1111,   520,     0,     0,
       0,     0,     0,     0,  1062,     0,     0,     0,     0,     0,
    1063,     0,     0,     0,  1062,     0,     0,   520,     0,     0,
    1063,     0,     0,     0,  1448,     0,     0,   520,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       8,     9,   296,   520,   821,     0,     0,     0,   300,     0,
     520,   400,   401,   519,   402,   403,   520,   519,     0,     0,
       0,     0,   404,     0,     0,   520,     0,     0,     0,     0,
       0,   405,   406,     0,     0,   520,   296,     0,     0,     0,
       0,   520,   300,     0,     0,     0,   520,     0,     0,   407,
       0,     0,     0,   408,     0,     0,     0,     0,     0,     0,
    1062,     0,     0,     0,     0,     0,  1063,     0,     0,  1062,
       0,  1111,     0,     0,     0,  1063,     0,   811,   812,     0,
     814,   815,   816,   817,   409,   410,   411,     0,     0,     0,
     826,     0,     0,     0,  1656,     0,     0,     0,  1526,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1663,   851,     0,     0,     0,     0,     0,     0,
       0,   857,   858,     0,  1540,  1541,     0,     0,     0,     0,
       0,     0,     0,   412,     0,     0,     0,     0,     0,     0,
       0,     0,   413,     0,     0,     0,     0,     0,     0,     0,
    1557,     0,  1111,     0,     0,  1111,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1569,     0,     0,     0,
       0,  1573,     0,     0,   414,     0,     0,     0,     0,     0,
     892,     0,     0,     0,   892,     0,  1586,     0,     0,     0,
       0,     0,   415,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   416,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   959,
       0,     0,     0,     0,   417,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     418,   419,   420,   421,   422,     0,   423,   424,   425,   426,
     427,     0,  1002,     0,     0,   428,   429,     0,     0,     0,
       0,  1639,     0,  1641,     0,  1643,     0,     0,     0,     0,
       0,     0,  1651,     0,     0,     0,     0,  1027,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   857,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1111,     0,  1111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1673,     0,     0,  1676,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1111,     0,
       0,     0,  1077,     0,     0,     0,     0,     0,  1684,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1702,
       0,     0,     0,     0,     0,     0,     0,     0,  1111,     0,
       0,     0,     0,     0,     0,     0,  1712,     0,     0,     0,
       0,  1715,     0,  1111,     0,  1111,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1732,     0,     0,     0,  1133,
       0,     0,     0,     0,     0,  1735,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1741,     0,     0,     0,     0,     0,     0,  1748,     0,
       0,     0,     0,     0,  1750,     0,  1171,     0,     0,     0,
       0,     0,     0,  1758,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1765,     0,  1187,     0,     0,     0,  1769,
       0,     0,     0,     0,  1773,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1220,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1225,  1226,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1245,     0,     0,  1248,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1271,  1272,  1273,     0,  1276,  1277,  1278,  1279,  1280,  1281,
       0,  1283,  1284,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1077,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1358,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1392,     0,  1394,     0,
    1396,     0,     0,  1400,     0,     0,     0,     0,  1404,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1410,     0,     0,     0,     0,     0,     0,     0,     0,  1414,
       0,     0,     0,     0,     0,  1418,  1419,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1440,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1077,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1531,     0,     0,
       0,  1533,     0,     0,     0,  1536,     0,  1538,     0,  1539,
       0,     0,     0,     0,     0,  1543,     0,     0,     0,     0,
       0,     0,     0,  1548,     0,     0,     0,     0,     0,     0,
       0,  1552,  1554,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1410,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1574,  1575,  1576,  1577,  1578,     0,  1579,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1626,     0,  1627,     0,     0,  1629,     0,     0,     0,     0,
       0,     0,     0,  1632,     0,     0,     0,     0,  1634,  1554,
       0,     0,     0,     0,     0,     0,  1638,     0,     0,     0,
    1642,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1678,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1638,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1719,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1733,
       0,     0,     0,     0,  1738,     0,     0,     0,     0,  1719,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1738,     1,     0,
       0,     0,     0,     0,     0,  1754,     2,     3,     4,     5,
       6,     7,     8,     9,     0,    10,     0,     0,     0,    11,
      12,     0,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,    72,    73,    74,    75,     0,     0,
      76,    77,     0,     0,     0,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,     0,     0,     0,    89,
       0,    90,    91,    92,    93,     0,    94,     0,     0,     0,
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   104,   105,   106,   107,     0,
       0,   108,   109,   110,   111,   112,     0,     0,     0,     0,
     113,   114,   115,   116,   117,   118,   119,   120,     0,   121,
       0,   122,   123,     0,     0,   124,   125,   126,     0,     0,
       0,   127,     0,   128,   129,     0,   130,   131,   132,     0,
     133,     0,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,     0,     0,   145,   146,   147,     0,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     1,     0,     0,     0,
       0,     0,     0,     0,     2,     3,     4,     5,     6,     7,
       8,     9,     0,    10,     0,     0,     0,   389,   390,     0,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,   391,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,    72,    73,    74,    75,     0,     0,    76,    77,
       0,     0,     0,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,     0,     0,     0,    89,     0,    90,
      91,    92,    93,     0,    94,     0,     0,     0,    95,    96,
      97,    98,    99,     0,     0,     0,     0,     0,     0,   100,
     101,   102,   103,   104,   105,   106,   107,     0,     0,   108,
     109,   110,   111,   112,     0,     0,     0,     0,   113,   114,
     115,   116,   117,   118,   119,   120,     0,   121,     0,   122,
     123,     0,     0,   124,   125,   126,     0,   539,     0,   127,
       0,   128,   129,     0,   130,   131,   132,     0,   133,     0,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,     0,     0,   145,   146,   147,     0,   392,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     1,     0,     0,     0,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     8,     9,     0,
      10,     0,     0,     0,   389,   390,     0,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,   391,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,    72,
      73,    74,    75,     0,     0,    76,    77,     0,     0,     0,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,     0,     0,     0,    89,     0,    90,    91,    92,    93,
       0,    94,     0,     0,     0,    95,    96,    97,    98,    99,
       0,     0,     0,     0,     0,     0,   100,   101,   102,   103,
     104,   105,   106,   107,     0,     0,   108,   109,   110,   111,
     112,     0,     0,     0,     0,   113,   114,   115,   116,   117,
     118,   119,   120,     0,   121,     0,   122,   123,     0,     0,
     124,   125,   126,     0,   792,     0,   127,     0,   128,   129,
       0,   130,   131,   132,     0,   133,     0,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,     0,     0,
     145,   146,   147,     0,   392,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       1,     0,     0,     0,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     8,     9,     0,    10,     0,     0,
       0,   389,   390,     0,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,  1058,   391,    28,
      29,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,  1059,  1060,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,    72,    73,    74,    75,
       0,     0,    76,    77,     0,     0,     0,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,     0,     0,
       0,    89,     0,    90,    91,    92,    93,     0,    94,     0,
       0,     0,    95,    96,    97,    98,    99,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,   104,   105,   106,
     107,     0,     0,   108,   109,   110,   111,   112,     0,     0,
       0,     0,   113,   114,   115,   116,   117,   118,   119,   120,
       0,   121,     0,   122,   123,     0,     0,   124,   125,   126,
       0,   792,     0,   127,     0,   128,   129,     0,   130,   131,
     132,     0,   133,     0,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,     0,     0,   145,   146,   147,
       0,   392,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,  1061,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     1,     0,     0,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       7,     8,     9,     0,    10,     0,     0,     0,   389,   390,
       0,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,  1058,   391,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,  1059,  1060,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,    72,    73,    74,    75,     0,     0,    76,
      77,     0,     0,     0,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,     0,     0,     0,    89,     0,
      90,    91,    92,    93,     0,    94,     0,     0,     0,    95,
      96,    97,    98,    99,     0,     0,     0,     0,     0,     0,
     100,   101,   102,   103,   104,   105,   106,   107,     0,     0,
     108,   109,   110,   111,   112,     0,     0,     0,     0,   113,
     114,   115,   116,   117,   118,   119,   120,     0,   121,     0,
     122,   123,     0,     0,   124,   125,   126,     0,   539,     0,
     127,     0,   128,   129,     0,   130,   131,   132,     0,   133,
       0,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,     0,     0,   145,   146,   147,     0,   392,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,  1061,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,     1,     0,     0,     0,     0,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     8,     9,
       0,    10,     0,     0,     0,   389,   390,     0,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,   391,    28,    29,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
      72,    73,    74,    75,     0,     0,    76,    77,     0,     0,
       0,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,     0,     0,     0,    89,     0,    90,    91,    92,
      93,     0,    94,     0,     0,     0,    95,    96,    97,    98,
      99,     0,     0,     0,     0,     0,     0,   100,   101,   102,
     103,   104,   105,   106,   107,     0,     0,   108,   109,   110,
     111,   112,     0,     0,     0,     0,   113,   114,   115,   116,
     117,   118,   119,   120,     0,   121,     0,   122,   123,     0,
       0,   124,   125,   126,     0,     0,     0,   127,     0,   128,
     129,     0,   130,   131,   132,     0,   133,     0,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,     0,
       0,   145,   146,   147,     0,   392,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     1,     0,     0,     0,     0,     0,     0,     0,     2,
       3,     4,     5,     6,     7,     8,     9,     0,    10,     0,
       0,     0,    11,    12,     0,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,    72,    73,    74,
      75,     0,     0,    76,    77,     0,     0,     0,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,     0,
       0,     0,    89,     0,    90,    91,    92,    93,     0,    94,
       0,     0,     0,    95,    96,    97,    98,    99,     0,     0,
       0,     0,     0,     0,   100,   101,   102,   103,   104,   105,
     106,   107,     0,     0,   108,   109,   110,   111,   112,     0,
       0,     0,     0,   113,   114,   115,   116,   117,   118,   119,
     120,     0,   121,     0,   122,   123,     0,     0,   124,   125,
     126,     0,     0,     0,   127,     0,   128,   129,     0,   130,
     131,   132,     0,   133,     0,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,     0,     0,   145,   146,
     147,     0,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,     1,     0,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,     0,    10,     0,     0,     0,    11,
      12,     0,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,    72,    73,    74,    75,     0,     0,
      76,    77,     0,     0,     0,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,     0,     0,     0,    89,
       0,    90,    91,    92,    93,     0,    94,     0,     0,     0,
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   104,   105,   106,   107,     0,
       0,   108,   109,   110,   111,   112,     0,     0,     0,     0,
     113,   114,   115,   116,   117,   118,   119,   120,     0,   121,
       0,   122,   123,     0,     0,   124,   125,   126,     0,     0,
       0,   127,     0,   128,   129,     0,   130,   131,   132,     0,
     133,     0,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,     0,     0,   145,   146,   147,     0,   392,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     1,     0,     0,     0,     0,
       0,     0,     0,     2,     3,     4,     5,     6,     7,     8,
       9,     0,    10,     0,     0,     0,    11,   390,     0,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,    72,    73,    74,    75,     0,     0,    76,    77,     0,
       0,     0,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,     0,     0,     0,    89,     0,    90,    91,
      92,    93,     0,    94,     0,     0,     0,    95,    96,    97,
      98,    99,     0,     0,     0,     0,     0,     0,   100,   101,
     102,   103,   104,   105,   106,   107,     0,     0,   108,   109,
     110,   111,   112,     0,     0,     0,     0,   113,   114,   115,
     116,   117,   118,   119,   120,     0,   121,     0,   122,   123,
       0,     0,   124,   125,   126,     0,     0,     0,   127,     0,
     128,   129,     0,   130,   131,   132,     0,   133,     0,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
       0,     0,   145,   146,   147,     0,   392,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   194,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,     1,     0,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     8,     9,     0,    10,
       0,     0,     0,   844,   390,     0,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
     391,    28,    29,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,    72,    73,
      74,    75,     0,     0,    76,    77,     0,     0,     0,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
       0,     0,     0,    89,     0,    90,    91,    92,    93,     0,
      94,     0,     0,     0,    95,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,   104,
     105,   106,   107,     0,     0,   108,   109,   110,   111,   112,
       0,     0,     0,     0,   113,   114,   115,   116,   117,   118,
     119,   120,     0,   121,     0,   122,   123,     0,     0,   124,
     125,   126,     0,     0,     0,   127,     0,   128,   129,     0,
     130,   131,   132,     0,   133,     0,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,     0,     0,   145,
     146,   147,     0,   392,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     1,
       0,     0,     0,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     8,     9,     0,    10,     0,     0,     0,
     389,   390,     0,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,  1058,   391,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
    1059,  1060,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,    72,    73,    74,    75,     0,
       0,    76,    77,     0,     0,     0,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,     0,     0,     0,
      89,     0,    90,    91,    92,    93,     0,    94,     0,     0,
       0,    95,    96,    97,    98,    99,     0,     0,     0,     0,
       0,     0,   100,   101,   102,   103,   104,   105,   106,   107,
       0,     0,   108,   109,   110,   111,   112,     0,     0,     0,
       0,   113,   114,   115,   116,   117,   118,   119,   120,     0,
     121,     0,   122,   123,     0,     0,   124,   125,   126,     0,
       0,     0,   127,     0,   128,   129,     0,   130,   131,   132,
       0,   133,     0,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,     0,     0,   145,   146,   147,     0,
     392,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
    1061,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,     1,     0,     0,     0,
       0,     0,     0,     0,     2,     3,     4,     5,     6,     7,
       0,     0,     0,    10,     0,     0,     0,   389,   390,     0,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   542,   391,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,   543,   544,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,    72,    73,    74,    75,     0,     0,    76,    77,
       0,     0,     0,    78,    79,   495,    81,    82,    83,    84,
      85,   545,    87,    88,     0,     0,     0,    89,     0,    90,
      91,    92,    93,     0,    94,     0,     0,     0,    95,    96,
      97,    98,    99,     0,     0,     0,     0,     0,     0,   100,
     101,   102,   103,   104,   105,   106,   546,     0,     0,   108,
     109,   110,   111,   112,     0,     0,     0,     0,   113,   114,
     115,   116,   117,   118,   119,   120,     0,   121,     0,   122,
     123,     0,     0,   124,   125,   126,     0,     0,     0,   127,
     547,   128,   129,     0,   130,   131,   132,     0,   133,     0,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,     0,     0,   145,   146,   147,     0,   392,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     512,   513,   514,   515,   175,   176,   516,   548,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     1,     0,     0,     0,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     0,     0,     0,
      10,     0,     0,     0,   389,   390,     0,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     542,   391,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,   543,   544,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,    72,
      73,    74,    75,     0,     0,    76,    77,     0,     0,     0,
      78,    79,   495,    81,    82,    83,    84,    85,   545,    87,
      88,     0,     0,     0,    89,     0,    90,    91,    92,    93,
       0,    94,     0,     0,     0,    95,    96,    97,    98,    99,
       0,     0,     0,     0,     0,     0,   100,   101,   102,   103,
     104,   105,   106,   546,     0,     0,   108,   109,   110,   111,
     112,     0,     0,     0,     0,   113,   114,   115,   116,   117,
     118,   119,   120,     0,   121,     0,   122,   123,     0,     0,
     124,   125,   126,     0,   885,     0,   127,     0,   128,   129,
       0,   130,   131,   132,     0,   133,     0,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,     0,     0,
     145,   146,   147,     0,   392,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   512,   513,   514,
     515,   175,   176,   516,   548,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       1,     0,     0,     0,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     0,     0,     0,    10,     0,     0,
       0,   389,   390,     0,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   542,   391,    28,
      29,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,   543,   544,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,    72,    73,    74,    75,
       0,     0,    76,    77,     0,     0,     0,    78,    79,   495,
      81,    82,    83,    84,    85,   545,    87,    88,     0,     0,
       0,    89,     0,    90,    91,    92,    93,     0,    94,     0,
       0,     0,    95,    96,    97,    98,    99,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,   104,   105,   106,
     546,     0,     0,   108,   109,   110,   111,   112,     0,     0,
       0,     0,   113,   114,   115,   116,   117,   118,   119,   120,
       0,   121,     0,   122,   123,     0,     0,   124,   125,   126,
       0,     0,     0,   127,   891,   128,   129,     0,   130,   131,
     132,     0,   133,     0,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,     0,     0,   145,   146,   147,
       0,   392,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   512,   513,   514,   515,   175,   176,
     516,   548,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     1,     0,     0,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       7,     0,     0,     0,    10,     0,     0,     0,   389,   390,
       0,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   542,   391,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,   543,   544,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,    72,    73,    74,    75,     0,     0,    76,
      77,     0,     0,     0,    78,    79,   495,    81,    82,    83,
      84,    85,   545,    87,    88,     0,     0,     0,    89,     0,
      90,    91,    92,    93,     0,    94,     0,     0,     0,    95,
      96,    97,    98,    99,     0,     0,     0,     0,     0,     0,
     100,   101,   102,   103,   104,   105,   106,   546,     0,     0,
     108,   109,   110,   111,   112,     0,     0,     0,     0,   113,
     114,   115,   116,   117,   118,   119,   120,     0,   121,     0,
     122,   123,     0,     0,   124,   125,   126,     0,     0,     0,
     127,   896,   128,   129,     0,   130,   131,   132,     0,   133,
       0,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,     0,     0,   145,   146,   147,     0,   392,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   512,   513,   514,   515,   175,   176,   516,   548,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,     1,     0,     0,     0,     0,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     0,     0,
       0,    10,     0,     0,     0,   389,   390,     0,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,   481,
      25,   483,   391,    28,   484,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
     486,     0,    45,    46,    47,   488,   489,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
      72,    73,    74,    75,     0,     0,    76,    77,     0,     0,
       0,    78,    79,   495,    81,    82,    83,    84,    85,   545,
      87,    88,     0,     0,     0,    89,     0,    90,    91,    92,
      93,     0,    94,     0,     0,     0,   498,    96,    97,    98,
      99,     0,     0,     0,     0,     0,     0,   100,   101,   102,
     103,   104,   105,   106,   546,     0,     0,   108,   109,   658,
     111,   112,     0,     0,     0,     0,   113,   114,   115,   116,
     117,   118,   119,   120,     0,   121,     0,   659,   123,     0,
       0,   124,   125,   126,     0,     0,     0,   127,     0,   128,
     129,     0,   130,   131,   132,     0,   133,     0,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,     0,
       0,   145,   146,   147,     0,   392,   149,   150,   151,   152,
     153,   154,   155,   156,   507,   158,   508,   160,   509,   510,
     163,   164,   165,   166,   167,   168,   511,   170,   512,   513,
     514,   515,   175,   176,   516,   517,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     1,     0,     0,     0,     0,     0,     0,     0,     2,
       3,     4,     5,     6,     7,     0,     0,     0,    10,     0,
       0,     0,   389,   390,     0,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,   542,   391,
      28,    29,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,   543,   544,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,    72,    73,    74,
      75,     0,     0,    76,    77,     0,     0,     0,    78,    79,
     495,    81,    82,    83,    84,    85,   545,    87,    88,     0,
       0,     0,    89,     0,    90,    91,    92,    93,     0,    94,
       0,     0,     0,    95,    96,    97,    98,    99,     0,     0,
       0,     0,     0,     0,   100,   101,   102,   103,   104,   105,
     106,   546,     0,     0,   108,   109,   110,   111,   112,     0,
       0,     0,     0,   113,   114,   115,   116,   117,   118,   119,
     120,     0,   121,     0,   122,   123,     0,     0,   124,   125,
     126,     0,     0,     0,   127,     0,   128,   129,     0,   130,
     131,   132,     0,   133,     0,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,     0,     0,   145,   146,
     147,     0,   392,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   512,   513,   514,   515,   175,
     176,   516,   548,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,     1,     0,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     0,     0,     0,    10,     0,     0,     0,   389,
     390,     0,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,   481,    25,   483,   391,    28,   484,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,   486,     0,    45,    46,    47,   488,
     489,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,    72,    73,    74,    75,     0,     0,
      76,    77,     0,     0,     0,    78,    79,   495,    81,    82,
      83,    84,    85,   545,    87,    88,     0,     0,     0,    89,
       0,    90,    91,    92,    93,     0,    94,     0,     0,     0,
     498,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   104,   105,   106,   546,     0,
       0,   108,   109,   110,   111,   112,     0,     0,     0,     0,
     113,   114,   115,   116,   117,   118,   119,   120,     0,   121,
       0,   122,   123,     0,     0,   124,   125,   126,     0,     0,
       0,   127,     0,   128,   129,     0,   130,   131,   132,     0,
     133,     0,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,     0,     0,   145,   146,   147,     0,   392,
     149,   150,   151,   152,   153,   154,   155,   156,   507,   158,
     508,   160,   509,   510,   163,   164,   165,   166,   167,   168,
     511,   170,   512,   513,   514,   515,   175,   176,   516,   517,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     1,     0,     0,     0,     0,
       0,     0,     0,     2,     3,     4,     5,     6,     7,     0,
       0,     0,    10,     0,     0,     0,   389,   390,     0,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     481,    25,   483,   391,    28,   484,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,   486,     0,    45,    46,    47,   488,   489,    50,   490,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,    72,    73,    74,    75,     0,     0,    76,    77,     0,
       0,     0,    78,    79,   495,    81,    82,    83,    84,    85,
     545,    87,    88,     0,     0,     0,    89,     0,    90,    91,
      92,    93,     0,    94,     0,     0,     0,   498,    96,    97,
      98,    99,     0,     0,     0,     0,     0,     0,   100,   101,
     102,   103,   104,   105,   106,   546,     0,     0,   108,   109,
       0,   111,   112,     0,     0,     0,     0,   113,   114,   115,
     116,   117,   118,   119,   120,     0,   121,     0,     0,     0,
       0,     0,   124,   125,   126,     0,     0,     0,   127,     0,
     128,   129,     0,   130,   131,   132,     0,   133,     0,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
       0,     0,   145,   146,   147,     0,   392,   149,   150,   151,
     152,   153,   154,   155,   156,   507,   158,   508,   160,   509,
     510,   163,   164,   165,   166,   167,   168,   511,   170,   512,
     513,   514,   515,   175,   176,   516,   517,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   194,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,     1,     0,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     0,     0,     0,    10,
       0,     0,     0,   389,   390,     0,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,   481,    25,   483,
     391,    28,   484,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,   486,     0,
      45,    46,    47,   488,   489,    50,   490,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,    72,    73,
      74,    75,     0,     0,    76,    77,     0,     0,     0,    78,
      79,   495,    81,    82,    83,    84,    85,   545,    87,    88,
       0,     0,     0,    89,     0,    90,    91,    92,    93,     0,
      94,     0,     0,     0,   498,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,   104,
     105,   106,   546,     0,     0,   108,   109,     0,   111,   112,
       0,     0,     0,     0,   113,   114,   115,   116,   117,   118,
     119,   120,     0,   121,     0,     0,     0,     0,     0,   124,
     125,   126,     0,     0,     0,   127,     0,   128,   129,     0,
       0,     0,   132,     0,   133,     0,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,     0,     0,   145,
     146,   147,     0,   392,   149,   150,   151,   152,   153,   154,
     155,   156,   507,   158,   508,   160,   509,   510,   163,   164,
     165,   166,   167,   168,   511,   170,   512,   513,   514,   515,
     175,   176,   516,   517,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     1,
       0,     0,     0,     0,     0,     0,     0,     2,     0,     0,
       0,     6,     7,     0,     0,     0,   477,     0,     0,     0,
     389,   390,     0,    13,    14,    15,   478,    17,    18,    19,
     479,    21,   480,    23,   481,   482,   483,   391,    28,   484,
      30,    31,     0,    32,    33,    34,    35,   485,    37,    38,
      39,    40,    41,    42,    43,   486,     0,    45,   487,    47,
     488,   489,    50,   490,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,   491,   492,    67,
       0,    68,    69,    70,   493,     0,    73,    74,    75,     0,
       0,   494,    77,     0,     0,     0,     0,    79,   495,    81,
     496,   497,    84,    85,     0,     0,     0,     0,     0,     0,
       0,     0,    90,    91,    92,    93,     0,    94,     0,     0,
       0,   498,    96,    97,   499,   500,     0,     0,     0,     0,
       0,     0,   100,   101,   102,     0,   104,   105,   106,     0,
       0,     0,     0,     0,     0,   111,   112,     0,     0,     0,
       0,   113,   114,   115,   116,   501,   118,   119,   502,     0,
       0,     0,     0,     0,     0,     0,   503,   504,   126,     0,
       0,     0,   127,     0,   128,   505,     0,     0,     0,   132,
       0,   133,     0,   134,   135,   136,   137,   506,   139,   140,
     141,   142,   143,   144,     0,     0,   145,   146,     0,     0,
     392,   149,   150,   151,   152,   153,   154,   155,   156,   507,
     158,   508,   160,   509,   510,   163,   164,   165,   166,   167,
     168,   511,   170,   512,   513,   514,   515,   175,   176,   516,
     517,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,     1,     0,     0,     0,
       0,     0,     0,     0,     2,     0,     0,     0,     6,     7,
       0,     0,     0,   477,     0,     0,     0,   389,   390,     0,
      13,    14,    15,   526,    17,    18,    19,   479,   527,   528,
      23,   481,   482,   483,   391,    28,   484,    30,    31,     0,
      32,    33,    34,    35,   529,    37,   530,   531,    40,    41,
      42,    43,   486,     0,    45,   532,    47,   488,   489,    50,
     490,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,   491,   492,    67,     0,    68,    69,
      70,   533,     0,    73,    74,    75,     0,     0,   494,    77,
       0,     0,     0,     0,    79,   495,    81,   496,   497,    84,
      85,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,    93,     0,    94,     0,     0,     0,   498,    96,
      97,   499,   500,     0,     0,     0,     0,     0,     0,   100,
     101,   102,     0,   104,   105,   106,     0,     0,     0,     0,
       0,     0,   111,   112,     0,     0,     0,     0,   113,   114,
     115,   116,   501,   118,   119,   502,     0,     0,     0,     0,
       0,     0,     0,   503,   504,   126,     0,     0,     0,   127,
       0,   128,   505,     0,     0,     0,   132,     0,   133,     0,
     134,   135,   136,   137,   506,   139,   140,   141,   142,   143,
     144,     0,     0,   145,   146,     0,     0,   392,   149,   150,
     151,   152,   153,   154,   155,   156,   507,   534,   508,   160,
     509,   510,   163,   164,   165,   166,   167,   168,   511,   170,
     512,   513,   514,   515,   175,   176,   516,   517,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   555,     0,     0,     0,     0,     0,     0,
       0,     6,     7,     0,     0,     0,   767,     0,     0,     0,
     389,   390,     0,    13,    14,    15,   526,    17,    18,    19,
     479,   527,   528,    23,   481,   482,   483,   391,    28,   484,
      30,    31,     0,    32,    33,    34,    35,   529,    37,   530,
     531,    40,    41,    42,    43,   486,     0,    45,   532,    47,
     488,   489,    50,   490,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,   491,   492,    67,
       0,    68,    69,    70,   533,     0,    73,    74,    75,     0,
       0,   494,    77,     0,     0,     0,     0,    79,   495,    81,
     496,   497,    84,    85,     0,     0,     0,     0,     0,     0,
       0,     0,    90,    91,    92,    93,     0,    94,     0,     0,
       0,   498,    96,    97,   499,   500,     0,     0,     0,     0,
       0,     0,   100,   101,   102,     0,   104,   105,   106,     0,
       0,     0,     0,     0,     0,   111,   112,     0,     0,     0,
       0,   113,   114,   115,   116,   501,   118,   119,   502,     0,
       0,     0,     0,     0,     0,     0,   503,   504,   126,     0,
       0,     0,   127,   768,   128,   505,     0,     0,     0,     0,
       0,   133,     0,   134,   135,   136,   137,   506,   139,   140,
     141,   142,   143,   144,     0,     0,   145,   146,     0,     0,
     392,   149,   150,   151,   152,   153,   154,   155,   156,   507,
     534,   508,   160,   509,   510,   163,   164,   165,   166,   167,
     168,   511,   170,   512,   513,   514,   515,   175,   176,   516,
     517,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   555,     0,     0,     0,
       0,     0,     0,     0,     6,     7,     0,     0,     0,   477,
       0,     0,     0,   389,   390,     0,    13,    14,    15,   526,
      17,    18,    19,   479,   527,   528,    23,   481,   482,   483,
     391,    28,   484,    30,    31,     0,    32,    33,    34,    35,
     529,    37,   530,   531,    40,    41,    42,    43,   486,     0,
      45,   532,    47,   488,   489,    50,   490,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
     491,   492,    67,     0,    68,    69,    70,   533,     0,    73,
      74,    75,     0,     0,   494,    77,     0,     0,     0,     0,
      79,   495,    81,   496,   497,    84,    85,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    91,    92,    93,     0,
      94,     0,     0,     0,   498,    96,    97,   499,   500,     0,
       0,     0,     0,     0,     0,   100,   101,   102,     0,   104,
     105,   106,     0,     0,     0,     0,     0,     0,   111,   112,
       0,     0,     0,     0,   113,   114,   115,   116,   501,   118,
     119,   502,     0,     0,     0,     0,     0,     0,     0,   503,
     504,   126,     0,     0,     0,   127,     0,   128,   505,     0,
       0,     0,     0,     0,   133,     0,   134,   135,   136,   137,
     506,   139,   140,   141,   142,   143,   144,     0,     0,   145,
     146,     0,     0,   392,   149,   150,   151,   152,   153,   154,
     155,   156,   507,   534,   508,   160,   509,   510,   163,   164,
     165,   166,   167,   168,   511,   170,   512,   513,   514,   515,
     175,   176,   516,   517,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   558,
     559,     0,     0,     0,     0,     6,     7,     0,     0,     0,
     477,     0,     0,     0,   389,   390,     0,    13,    14,    15,
     526,    17,    18,    19,   479,   527,   528,    23,   481,   482,
     483,   391,    28,   484,    30,    31,     0,    32,    33,    34,
      35,   529,    37,   530,   531,    40,    41,    42,    43,   486,
       0,    45,   532,    47,   488,   489,    50,   490,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,   491,   492,    67,     0,    68,    69,    70,   533,     0,
      73,    74,    75,     0,     0,   494,    77,     0,     0,     0,
       0,    79,   495,    81,   496,   497,    84,    85,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    91,    92,    93,
       0,    94,     0,     0,     0,   498,    96,    97,   499,   500,
       0,     0,     0,     0,     0,     0,   100,   101,   102,     0,
     104,   105,   106,     0,     0,     0,     0,     0,     0,   111,
     112,     0,     0,     0,     0,   113,   114,   115,   116,   501,
     118,   119,   502,     0,     0,     0,     0,     0,     0,     0,
     503,   504,   126,     0,     0,     0,   127,     0,   128,   505,
       0,     0,     0,     0,     0,   133,     0,   134,   135,   136,
     137,   506,   139,   140,   141,   142,   143,   144,     0,     0,
     145,   146,     0,     0,   392,   149,   150,   151,   152,   153,
     154,   155,   156,   507,   534,   508,   160,   509,   510,   163,
     164,   165,   166,   167,   168,   511,   170,   512,   513,   514,
     515,   175,   176,   516,   517,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       6,     7,     0,     0,     0,   477,     0,     0,     0,   389,
     390,     0,    13,    14,    15,   478,    17,    18,    19,   479,
      21,   480,    23,   481,  1099,   483,   391,    28,   484,    30,
      31,     0,    32,    33,    34,    35,   485,    37,    38,    39,
      40,    41,    42,    43,   486,     0,    45,   487,    47,   488,
     489,    50,   490,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,   491,   492,    67,     0,
      68,    69,    70,   493,     0,    73,    74,    75,     0,     0,
     494,    77,     0,     0,     0,     0,    79,   495,    81,   496,
     497,    84,    85,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    91,    92,    93,     0,    94,     0,     0,     0,
     498,    96,    97,   499,   500,     0,     0,     0,     0,     0,
       0,   100,   101,   102,     0,   104,   105,  1100,     0,     0,
       0,  1101,     0,     0,   111,   112,     0,     0,     0,     0,
     113,   114,   115,   116,   501,   118,   119,   502,     0,     0,
       0,     0,     0,     0,     0,   503,   504,   126,     0,     0,
       0,   127,  1505,   128,   505,     0,     0,     0,  1506,     0,
     133,     0,   134,   135,   136,   137,   506,   139,   140,   141,
     142,   143,   144,     0,     0,  1102,   146,     0,     0,   392,
     149,   150,   151,   152,   153,   154,   155,   156,   507,   158,
     508,   160,   509,   510,   163,   164,   165,   166,   167,   168,
     511,   170,   512,   513,   514,   515,   175,   176,   516,   517,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     6,     7,     0,     0,     0,
     477,     0,     0,     0,   389,   390,     0,    13,    14,    15,
     526,    17,    18,    19,   479,   527,   528,    23,   481,   482,
     483,   391,    28,   484,    30,    31,     0,    32,    33,    34,
      35,   529,    37,   530,   531,    40,    41,    42,    43,   486,
       0,    45,   532,    47,   488,   489,    50,   490,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,   491,   492,    67,     0,    68,    69,    70,   533,     0,
      73,    74,    75,     0,     0,   494,    77,     0,     0,     0,
       0,    79,   495,    81,   496,   497,    84,    85,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    91,    92,    93,
       0,    94,     0,     0,     0,   498,    96,    97,   499,   500,
       0,     0,     0,     0,     0,     0,   100,   101,   102,     0,
     104,   105,   106,     0,     0,     0,     0,     0,     0,   111,
     112,     0,     0,     0,     0,   113,   114,   115,   116,   501,
     118,   119,   502,     0,     0,     0,     0,     0,     0,     0,
     503,   504,   126,     0,     0,     0,   127,   738,   128,   505,
       0,     0,     0,   739,     0,   133,     0,   134,   135,   136,
     137,   506,   139,   140,   141,   142,   143,   144,     0,     0,
     145,   146,     0,     0,   392,   149,   150,   151,   152,   153,
     154,   155,   156,   507,   534,   508,   160,   509,   510,   163,
     164,   165,   166,   167,   168,   511,   170,   512,   513,   514,
     515,   175,   176,   516,   517,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       6,     7,     0,     0,     0,   477,     0,     0,     0,   389,
     390,     0,    13,    14,    15,   526,    17,    18,    19,   479,
     527,   528,    23,   481,   482,   483,   391,    28,   484,    30,
      31,     0,    32,    33,    34,    35,   529,    37,   530,   531,
      40,    41,    42,    43,   486,     0,    45,   532,    47,   488,
     489,    50,   490,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,   491,   492,    67,     0,
      68,    69,    70,   533,     0,    73,    74,    75,     0,     0,
     494,    77,     0,     0,     0,     0,    79,   495,    81,   496,
     497,    84,    85,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    91,    92,    93,     0,    94,     0,     0,     0,
     498,    96,    97,   499,   500,     0,     0,     0,     0,     0,
       0,   100,   101,   102,     0,   104,   105,   106,     0,     0,
       0,     0,     0,     0,   111,   112,     0,     0,     0,     0,
     113,   114,   115,   116,   501,   118,   119,   502,     0,     0,
       0,     0,     0,     0,     0,   503,   504,   126,     0,     0,
       0,   127,   785,   128,   505,     0,     0,     0,   786,     0,
     133,     0,   134,   135,   136,   137,   506,   139,   140,   141,
     142,   143,   144,     0,     0,   145,   146,     0,     0,   392,
     149,   150,   151,   152,   153,   154,   155,   156,   507,   534,
     508,   160,   509,   510,   163,   164,   165,   166,   167,   168,
     511,   170,   512,   513,   514,   515,   175,   176,   516,   517,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     6,     7,     0,     0,     0,
     477,     0,     0,     0,   389,   390,     0,    13,    14,    15,
     478,    17,    18,    19,   479,    21,   480,    23,   481,  1099,
     483,   391,    28,   484,    30,    31,     0,    32,    33,    34,
      35,   485,    37,    38,    39,    40,    41,    42,    43,   486,
       0,    45,   487,    47,   488,   489,    50,   490,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,   491,   492,    67,     0,    68,    69,    70,   493,     0,
      73,    74,    75,     0,     0,   494,    77,     0,     0,     0,
       0,    79,   495,    81,   496,   497,    84,    85,  1428,     0,
       0,     0,     0,     0,     0,     0,    90,    91,    92,    93,
       0,    94,     0,     0,     0,   498,    96,    97,   499,   500,
       0,     0,     0,     0,     0,     0,   100,   101,   102,     0,
     104,   105,  1100,     0,     0,     0,  1101,     0,     0,   111,
     112,     0,     0,     0,     0,   113,   114,   115,   116,   501,
     118,   119,   502,     0,     0,     0,     0,     0,     0,     0,
     503,   504,   126,     0,     0,     0,   127,     0,   128,   505,
       0,     0,     0,     0,     0,   133,     0,   134,   135,   136,
     137,   506,   139,   140,   141,   142,   143,   144,     0,     0,
    1102,   146,     0,     0,   392,   149,   150,   151,   152,   153,
     154,   155,   156,   507,   158,   508,   160,   509,   510,   163,
     164,   165,   166,   167,   168,   511,   170,   512,   513,   514,
     515,   175,   176,   516,   517,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       6,     7,     0,     0,     0,   477,     0,     0,     0,   389,
     390,     0,    13,    14,    15,   478,    17,    18,    19,   479,
      21,   480,    23,   481,  1099,   483,   391,    28,   484,    30,
      31,     0,    32,    33,    34,    35,   485,    37,    38,    39,
      40,    41,    42,    43,   486,     0,    45,   487,    47,   488,
     489,    50,   490,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,   491,   492,    67,     0,
      68,    69,    70,   493,     0,    73,    74,    75,     0,     0,
     494,    77,     0,     0,     0,     0,    79,   495,    81,   496,
     497,    84,    85,  1559,     0,     0,     0,     0,     0,     0,
       0,    90,    91,    92,    93,     0,    94,     0,     0,     0,
     498,    96,    97,   499,   500,     0,     0,     0,     0,     0,
       0,   100,   101,   102,     0,   104,   105,  1100,     0,     0,
       0,  1101,     0,     0,   111,   112,     0,     0,     0,     0,
     113,   114,   115,   116,   501,   118,   119,   502,     0,     0,
       0,     0,     0,     0,     0,   503,   504,   126,     0,     0,
       0,   127,     0,   128,   505,     0,     0,     0,     0,     0,
     133,     0,   134,   135,   136,   137,   506,   139,   140,   141,
     142,   143,   144,     0,     0,  1102,   146,     0,     0,   392,
     149,   150,   151,   152,   153,   154,   155,   156,   507,   158,
     508,   160,   509,   510,   163,   164,   165,   166,   167,   168,
     511,   170,   512,   513,   514,   515,   175,   176,   516,   517,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     6,     7,     0,     0,     0,
     477,     0,     0,     0,   389,   390,     0,    13,    14,    15,
     478,    17,    18,    19,   479,    21,   480,    23,   481,  1099,
     483,   391,    28,   484,    30,    31,     0,    32,    33,    34,
      35,   485,    37,    38,    39,    40,    41,    42,    43,   486,
       0,    45,   487,    47,   488,   489,    50,   490,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,   491,   492,    67,     0,    68,    69,    70,   493,     0,
      73,    74,    75,     0,     0,   494,    77,     0,     0,     0,
       0,    79,   495,    81,   496,   497,    84,    85,  1563,     0,
       0,     0,     0,     0,     0,     0,    90,    91,    92,    93,
       0,    94,     0,     0,     0,   498,    96,    97,   499,   500,
       0,     0,     0,     0,     0,     0,   100,   101,   102,     0,
     104,   105,  1100,     0,     0,     0,  1101,     0,     0,   111,
     112,     0,     0,     0,     0,   113,   114,   115,   116,   501,
     118,   119,   502,     0,     0,     0,     0,     0,     0,     0,
     503,   504,   126,     0,     0,     0,   127,     0,   128,   505,
       0,     0,     0,     0,     0,   133,     0,   134,   135,   136,
     137,   506,   139,   140,   141,   142,   143,   144,     0,     0,
    1102,   146,     0,     0,   392,   149,   150,   151,   152,   153,
     154,   155,   156,   507,   158,   508,   160,   509,   510,   163,
     164,   165,   166,   167,   168,   511,   170,   512,   513,   514,
     515,   175,   176,   516,   517,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       6,     7,     0,     0,     0,   477,     0,     0,     0,   389,
     390,     0,    13,    14,    15,   478,    17,    18,    19,   479,
      21,   480,    23,   481,  1099,   483,   391,    28,   484,    30,
      31,     0,    32,    33,    34,    35,   485,    37,    38,    39,
      40,    41,    42,    43,   486,     0,    45,   487,    47,   488,
     489,    50,   490,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,   491,   492,    67,     0,
      68,    69,    70,   493,     0,    73,    74,    75,     0,     0,
     494,    77,     0,     0,     0,     0,    79,   495,    81,   496,
     497,    84,    85,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    91,    92,    93,     0,    94,     0,     0,     0,
     498,    96,    97,   499,   500,     0,     0,     0,     0,     0,
       0,   100,   101,   102,     0,   104,   105,  1100,     0,     0,
       0,  1101,     0,     0,   111,   112,     0,     0,     0,     0,
     113,   114,   115,   116,   501,   118,   119,   502,     0,     0,
       0,     0,     0,     0,     0,   503,   504,   126,     0,     0,
       0,   127,     0,   128,   505,     0,     0,     0,     0,     0,
     133,     0,   134,   135,   136,   137,   506,   139,   140,   141,
     142,   143,   144,     0,     0,  1102,   146,     0,     0,   392,
     149,   150,   151,   152,   153,   154,   155,   156,   507,   158,
     508,   160,   509,   510,   163,   164,   165,   166,   167,   168,
     511,   170,   512,   513,   514,   515,   175,   176,   516,   517,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     6,     7,     0,     0,     0,
     477,     0,     0,     0,   389,   390,     0,    13,    14,    15,
     478,    17,    18,    19,   479,    21,   480,    23,   481,  1099,
     483,   391,    28,   484,    30,    31,     0,    32,    33,    34,
      35,   485,    37,    38,    39,    40,    41,    42,    43,   486,
       0,    45,   487,    47,   488,   489,    50,   490,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,   491,   492,    67,     0,    68,    69,    70,   493,     0,
      73,    74,    75,     0,     0,   494,    77,     0,     0,     0,
       0,    79,   495,    81,   496,   497,    84,    85,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    91,    92,    93,
       0,    94,     0,     0,     0,   498,    96,    97,   499,   500,
       0,     0,     0,     0,     0,     0,   100,   101,   102,     0,
     104,   105,  1100,     0,     0,     0,  1101,     0,     0,   111,
     112,     0,     0,     0,     0,   113,   114,   115,   116,   501,
     118,   119,   502,     0,     0,     0,     0,     0,     0,     0,
     503,   504,   126,     0,     0,     0,   127,     0,   128,   505,
       0,     0,     0,     0,     0,   133,     0,   134,   135,   136,
     137,   506,   139,   140,   141,   142,   143,   144,     0,     0,
     145,   146,     0,     0,   392,   149,   150,   151,   152,   153,
     154,   155,   156,   507,   158,   508,   160,   509,   510,   163,
     164,   165,   166,   167,   168,   511,   170,   512,   513,   514,
     515,   175,   176,   516,   517,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       6,     7,     0,     0,     0,   477,     0,     0,     0,   389,
     390,     0,    13,    14,    15,   526,    17,    18,    19,   479,
     527,   528,    23,   481,   482,   483,   391,    28,   484,    30,
      31,     0,    32,    33,    34,    35,   529,    37,   530,   531,
      40,    41,    42,    43,   486,     0,    45,   532,    47,   488,
     489,    50,   490,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,   491,   492,    67,     0,
      68,    69,    70,   533,     0,    73,    74,    75,     0,     0,
     494,    77,     0,     0,     0,     0,    79,   495,    81,   496,
     497,    84,    85,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    91,    92,    93,     0,    94,     0,     0,     0,
     498,    96,    97,   499,   500,     0,     0,     0,     0,     0,
       0,   100,   101,   102,     0,   104,   105,   106,     0,     0,
       0,     0,     0,     0,   111,   112,     0,     0,     0,     0,
     113,   114,   115,   116,   501,   118,   119,   502,     0,     0,
       0,     0,     0,     0,     0,   503,   504,   126,     0,     0,
       0,   127,     0,   128,   505,     0,     0,     0,     0,     0,
     133,     0,   134,   135,   136,   137,   506,   139,   140,   141,
     142,   143,   144,     0,     0,   145,   146,     0,     0,   392,
     149,   150,   151,   152,   153,   154,   155,   156,   507,   534,
     508,   160,   509,   510,   163,   164,   165,   166,   167,   168,
     511,   170,   512,   513,   514,   515,   175,   176,   516,   517,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     6,     7,     0,     0,     0,
     477,     0,     0,     0,   389,   390,     0,    13,    14,    15,
       0,    17,    18,    19,   479,     0,     0,    23,   481,   482,
       0,   391,    28,   484,    30,    31,     0,    32,    33,    34,
      35,     0,    37,     0,     0,    40,    41,    42,    43,   486,
       0,    45,     0,    47,     0,     0,    50,   490,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,   491,   492,    67,     0,    68,    69,    70,     0,     0,
      73,    74,    75,     0,     0,   494,    77,     0,     0,     0,
       0,    79,   495,    81,   496,   497,    84,    85,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    91,    92,    93,
       0,    94,     0,     0,     0,   498,    96,    97,   499,   500,
       0,     0,     0,     0,     0,     0,   100,   101,   102,     0,
     104,   105,     0,     0,     0,     0,     0,     0,     0,   111,
     112,     0,     0,     0,     0,   113,   114,   115,   116,   501,
     118,   119,   502,     0,     0,     0,     0,     0,     0,     0,
     503,   504,   126,     0,     0,     0,   127,     0,   128,   505,
       0,     0,     0,     0,     0,   133,     0,   134,   135,   136,
     137,   506,   139,   140,   141,   142,   143,   144,     0,     0,
       0,   146,     0,     0,   392,   149,   150,   151,   152,   153,
     154,   155,   156,   507,     0,   508,   160,   509,   510,   163,
     164,   165,   166,   167,   168,   511,   170,   512,   513,   514,
     515,   175,   176,     0,   517,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,   801,   178,     3,     4,     5,     0,   645,    11,     3,
       4,     5,   327,     3,     4,     5,   398,   399,   762,     3,
       4,     5,   300,  1235,   881,   882,    72,   745,   249,   998,
     774,   597,   598,   745,   131,   280,   248,   961,  1014,   271,
      86,   869,  1251,   264,   788,   646,   647,   648,   649,   830,
    1085,    72,   903,  1036,    28,  1168,   116,   578,   595,   596,
     597,   598,   919,   109,    35,   691,   412,     3,     4,     5,
    1308,  1309,    35,    25,    26,   121,    95,   123,   599,    55,
     595,   596,   603,   625,     1,   627,   628,     1,   630,   140,
     632,   437,   105,  1523,    28,    47,   953,     1,   640,   641,
     400,   116,    98,   919,    56,    29,    28,   107,     1,    44,
       1,     1,  1264,   107,   460,    92,     1,    98,   975,    98,
    1341,    52,    74,   107,    95,    28,    78,    62,   116,     8,
      93,   988,    95,   145,   108,   145,    25,    26,    25,    26,
     105,    36,    37,    93,    39,    40,   105,   129,   122,   116,
     395,    93,   452,   453,   116,   245,   246,   109,   110,   111,
      47,    93,    57,    93,    93,   105,    32,    32,   171,    95,
      38,   107,   882,   147,   145,    43,    44,   151,   268,   180,
     154,   925,   145,    49,    49,   135,   108,    74,   184,   158,
     140,    59,   193,    61,    62,    93,   127,   185,   140,   431,
     122,   175,    70,   184,   181,   184,   188,   222,   111,    93,
      54,   271,    56,   145,   119,   167,   111,   184,   183,   232,
     271,   110,   184,   110,   158,   147,    25,    26,    96,   188,
    1442,  1469,  1032,   330,    95,   254,   255,   981,   214,  1669,
    1164,   167,   242,   987,  1101,   245,   186,   199,   242,  1218,
     185,   245,   105,   151,    98,   158,  1232,  1085,  1086,   271,
       5,   271,   980,   158,     9,   975,   978,  1380,   980,   835,
     836,   188,  1255,   551,   188,   227,   252,  1128,   988,   905,
     280,  1264,  1317,   257,   188,  1101,   280,   211,  1000,   335,
     305,   128,   338,  1445,   173,   188,   541,   188,   188,   108,
     271,  1522,   823,   188,   234,   234,   167,    44,   271,   154,
      47,   110,   134,   105,   335,    95,  1173,   338,   833,   834,
     218,   219,   217,   865,   250,   251,   148,   253,   674,   182,
      93,   215,   216,   285,   286,   287,   288,   289,   128,   291,
     292,   293,   294,   295,   270,   105,   230,   579,   300,   301,
     105,    25,    26,  1210,   222,    93,   282,   194,   404,   405,
     134,   105,   408,   151,   259,   105,   412,   104,   613,   189,
     190,   592,   418,  1582,   154,   156,   121,  1234,   123,   425,
     164,   105,  1620,   595,   596,   105,   131,   175,   105,   250,
     251,   437,   253,   174,   186,   395,   180,   443,   105,   260,
     446,   395,   702,    28,   194,   249,   151,   145,   454,   270,
     756,   105,  1525,   759,   460,   461,   462,   463,   262,   105,
     264,   282,   468,   151,   198,   185,   154,   182,  1172,   166,
     476,   275,   276,   277,  1672,   279,   110,   281,   438,   105,
     440,   185,   182,  1655,   438,     5,   440,   105,    44,     9,
     440,    47,   215,   216,   438,  1379,   440,   105,   105,   105,
     760,   185,  1445,   198,   464,   185,  1184,   230,   185,   469,
     464,   280,   207,   105,    72,   469,   522,   154,   185,   105,
     464,  1193,    78,   108,   729,   469,   267,   869,    86,  1317,
     536,   185,  1349,   274,   105,   105,   182,   122,  1326,   545,
    1210,   105,   438,   284,   440,  1071,  1072,  1073,   104,  1337,
    1291,   109,  1625,   105,  1295,   105,   898,   105,   916,   185,
     151,   151,   147,   121,  1234,   123,   151,   185,   464,   154,
     928,   577,   105,   469,  1071,  1072,  1073,   185,   185,   185,
     105,   541,     9,    10,    41,   175,   546,   541,   105,    46,
     175,   214,   546,   185,    51,   105,   105,  1670,   105,   185,
     105,   121,   546,   123,   105,   105,   105,   664,   665,   154,
     166,   131,    69,  1430,   185,   185,  1433,  1546,   105,    95,
      66,   185,   105,   828,   584,    71,   395,   590,   261,   252,
     584,   151,   182,   185,   182,   595,   596,   597,   598,   272,
     584,   595,   596,   597,   598,  1581,    95,     9,    10,   222,
     546,   224,   185,   613,   151,   167,    95,   154,   839,   613,
     185,   833,   111,   154,    95,   182,   926,   927,   674,   145,
     116,   931,   111,   442,   101,   185,   185,   182,   185,  1349,
    1753,   450,  1755,  1443,   185,   185,   185,   199,  1448,   695,
     459,   115,   698,   154,   121,   182,   123,   466,   467,   182,
      93,  1774,   969,   963,   971,   154,   475,   135,  1496,   166,
     207,   156,   169,   719,   145,   154,    53,  1395,   724,   725,
     144,    58,   151,   151,   151,   154,   116,   184,   155,   174,
    1328,   156,    53,   157,   994,   261,   142,    58,   998,   101,
     746,   104,   748,  1085,  1086,   172,   272,   140,   120,   174,
     756,   196,   209,   759,  1021,    76,  1023,   763,    95,   121,
    1430,   123,   125,  1433,   156,   192,    23,   191,   174,   729,
     146,  1297,   541,   154,    95,   729,    33,   335,   207,   154,
     338,  1731,   174,   210,   553,   191,  1603,   163,  1605,   151,
    1647,  1648,   752,   155,   800,   116,   565,   152,   752,   154,
     146,   120,   752,    60,   196,   135,    41,  1757,   752,  1569,
     172,    46,  1087,  1573,   583,   584,    51,   163,  1768,  1636,
      95,   151,   782,   783,   830,  1063,   267,   180,   782,   783,
     192,  1688,   151,   274,    69,   154,   111,  1694,   782,   783,
     193,    94,    98,   284,    98,   154,   852,   405,   210,  1666,
     408,   104,  1057,   154,   412,   111,   752,   111,     9,    10,
     418,   114,    93,   222,  1681,   224,  1683,   425,   828,    98,
      98,    98,   125,   104,   828,   881,   882,   883,   884,   437,
      98,   844,   111,   111,   111,   443,   782,   783,   446,  1487,
    1488,  1651,   661,   111,   222,   120,   454,   666,   297,   227,
       9,    10,   460,   461,   462,   463,     9,   306,   266,   135,
     468,   120,    41,   919,   140,   273,  1620,    46,   476,  1480,
     667,   120,    51,   670,    27,  1061,   673,   933,   116,   151,
    1066,   166,   154,  1603,   169,  1605,   229,     9,   231,   135,
      69,   275,   276,   277,   140,   151,    53,   281,   154,   184,
     101,    58,   337,  1213,   960,    27,   151,   342,  1218,   154,
     729,   126,   127,   969,   522,   971,  1636,   298,   299,   975,
     121,   229,   123,   231,   209,  1317,   298,   299,   536,   218,
     219,   220,   988,   120,  1326,   289,   290,   545,   126,   127,
     643,   644,   101,  1591,  1592,  1337,  1666,   116,   650,   651,
     151,   652,   653,   120,   155,   120,   167,  1212,   883,   884,
     151,  1681,   121,  1683,   123,  1021,   120,  1023,   121,   577,
     123,   172,  1513,  1514,   793,   794,   795,   120,   797,   132,
     120,   120,   213,   151,   154,   222,   116,   166,   199,   239,
     169,   192,   151,   240,  1304,   239,   155,     0,   151,   121,
     151,   123,   154,   105,   188,   184,  1016,   165,    91,   210,
     132,   247,  1016,   172,  1662,    50,   227,   197,    99,   152,
     100,   119,  1016,   143,  1080,   154,   182,   182,    28,   151,
     209,   150,   182,   192,    47,  1290,   244,   116,   291,   296,
     302,   296,   282,   185,   116,  1101,   151,  1057,   282,     1,
     116,   210,   140,  1057,   105,   151,   151,  1070,   185,   182,
     154,  1071,  1072,  1073,   154,   154,   674,  1071,  1072,  1073,
    1016,   140,   154,   151,   285,   286,   287,   288,   289,   154,
     291,   292,   293,   294,   295,    34,   154,   154,    16,   300,
     698,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,   154,  1412,   211,  1496,    28,   243,   228,   185,     3,
     116,   719,   188,   168,   130,   188,   724,   725,   166,   168,
      70,   228,   138,   139,    93,   141,    93,  1183,    93,   147,
    1186,   105,   105,   149,   158,    28,   158,   153,   746,   155,
     748,   125,   140,   130,   160,  1201,   116,   244,   756,   297,
     130,   759,   182,   182,  1210,   763,    93,   185,   185,   105,
      95,   177,    44,  1473,    95,   185,   185,  1177,  1224,  1424,
     185,   185,   182,  1177,   151,   182,    93,  1177,  1234,   222,
     234,   140,    32,  1177,   200,   201,   202,   203,   204,   205,
     168,   188,   800,   140,   116,    93,   130,    28,   284,   224,
     151,   116,  1212,   116,   297,   125,  1262,   145,  1212,   116,
     252,   182,    93,  1223,   195,   158,   130,    95,   130,  1223,
     116,   151,   830,  1223,   145,    98,  1282,    98,   182,  1223,
     140,  1177,  1242,   151,   182,  1291,  1546,    34,  1242,  1295,
      28,   116,  1242,   188,   852,   154,   154,   151,  1242,   154,
     243,  1261,    78,   105,   105,   256,   258,  1261,   142,   154,
     283,   265,   154,   154,    28,  1084,    28,  1261,    28,   224,
     234,   224,   284,   881,   882,   883,   884,  1223,   304,  1289,
    1290,   142,   224,   185,   125,  1289,  1290,   188,   185,  1544,
     285,   145,   145,  1349,    76,  1289,  1242,   185,   185,   145,
    1555,  1556,   116,  1558,   116,   105,   140,    98,   182,   185,
    1565,   919,   195,   185,   130,  1261,     7,   184,   188,   230,
    1376,   116,   185,   104,   230,   933,   104,   230,   145,   248,
     230,    77,   248,    28,    28,   234,   280,   185,   185,   105,
     185,   168,   269,   284,   182,   124,  1402,  1403,   124,   145,
      95,   145,   960,   182,   184,    93,   184,    28,   151,   184,
     184,   969,   182,   971,   182,   255,   185,   975,    95,   182,
     185,   145,  1428,    53,  1430,    93,   168,  1433,   184,   184,
     988,   116,    93,   194,    28,   195,   263,   116,  1444,  1644,
     105,   105,   278,  1449,   116,    93,   285,   184,   184,  1654,
      93,   222,    92,   116,   194,   194,   116,   184,  1464,   181,
     194,   116,   116,  1021,  1424,  1023,   184,   184,   303,   222,
    1424,   151,   291,   303,   116,   184,   196,  1682,   116,   116,
     185,   185,   116,   242,   701,   303,   285,   222,   304,   304,
     304,   245,  1131,   245,   920,   431,   989,   248,  1173,  1625,
     435,  1670,   831,   765,   986,  1183,  1405,  1313,  1202,   399,
    1076,  1716,  1311,  1308,  1224,   536,  1229,  1286,  1287,  1288,
    1232,  1237,  1080,  1659,   623,  1255,   676,   624,   801,   323,
    1694,  1688,   884,  1165,   441,  1740,   971,  1130,  1292,  1282,
    1291,  1326,  1086,  1101,  1749,  1337,  1330,  1496,  1493,  1095,
     952,  1153,   441,  1559,  1368,  1561,  1327,  1563,  1516,    -1,
      -1,    -1,    -1,    -1,  1570,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1544,    -1,    -1,    -1,    -1,    -1,
    1544,    -1,    -1,    -1,    -1,  1555,  1556,  1603,  1558,  1605,
      -1,  1555,  1556,    -1,  1558,  1565,    -1,    -1,    -1,  1745,
      -1,  1565,    -1,    -1,    -1,  1621,    -1,    -1,  1624,    -1,
      -1,    -1,    -1,    -1,    -1,  1183,    -1,  1763,  1186,    -1,
    1636,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1646,    -1,    -1,  1201,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1657,  1210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1666,    -1,    -1,    -1,    -1,    -1,  1224,    -1,  1674,    -1,
      -1,    -1,    -1,  1679,    -1,  1681,  1234,  1683,    -1,    -1,
      -1,    -1,    -1,    -1,  1644,    -1,    -1,    -1,    -1,    -1,
    1644,    -1,    -1,    -1,  1654,    -1,    -1,  1703,    -1,    -1,
    1654,    -1,    -1,    -1,  1262,    -1,    -1,  1713,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    26,  1682,  1729,  1282,    -1,    -1,    -1,  1682,    -1,
    1736,    36,    37,  1291,    39,    40,  1742,  1295,    -1,    -1,
      -1,    -1,    47,    -1,    -1,  1751,    -1,    -1,    -1,    -1,
      -1,    56,    57,    -1,    -1,  1761,  1716,    -1,    -1,    -1,
      -1,  1767,  1716,    -1,    -1,    -1,  1772,    -1,    -1,    74,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,
    1740,    -1,    -1,    -1,    -1,    -1,  1740,    -1,    -1,  1749,
      -1,  1349,    -1,    -1,    -1,  1749,    -1,   569,   570,    -1,
     572,   573,   574,   575,   109,   110,   111,    -1,    -1,    -1,
     582,    -1,    -1,    -1,  1583,    -1,    -1,    -1,  1376,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1601,   605,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   613,   614,    -1,  1402,  1403,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1428,    -1,  1430,    -1,    -1,  1433,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1444,    -1,    -1,    -1,
      -1,  1449,    -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,
     672,    -1,    -1,    -1,   676,    -1,  1464,    -1,    -1,    -1,
      -1,    -1,   217,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   721,
      -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     285,   286,   287,   288,   289,    -1,   291,   292,   293,   294,
     295,    -1,   764,    -1,    -1,   300,   301,    -1,    -1,    -1,
      -1,  1559,    -1,  1561,    -1,  1563,    -1,    -1,    -1,    -1,
      -1,    -1,  1570,    -1,    -1,    -1,    -1,   789,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   799,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1603,    -1,  1605,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1621,    -1,    -1,  1624,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1636,    -1,
      -1,    -1,   854,    -1,    -1,    -1,    -1,    -1,  1646,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1657,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1666,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1674,    -1,    -1,    -1,
      -1,  1679,    -1,  1681,    -1,  1683,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1703,    -1,    -1,    -1,   921,
      -1,    -1,    -1,    -1,    -1,  1713,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1729,    -1,    -1,    -1,    -1,    -1,    -1,  1736,    -1,
      -1,    -1,    -1,    -1,  1742,    -1,   958,    -1,    -1,    -1,
      -1,    -1,    -1,  1751,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1761,    -1,   977,    -1,    -1,    -1,  1767,
      -1,    -1,    -1,    -1,  1772,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   999,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1010,  1011,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1025,    -1,    -1,  1028,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1042,  1043,  1044,    -1,  1046,  1047,  1048,  1049,  1050,  1051,
      -1,  1053,  1054,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1076,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1188,    -1,  1190,    -1,
    1192,    -1,    -1,  1195,    -1,    -1,    -1,    -1,  1200,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1212,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1221,
      -1,    -1,    -1,    -1,    -1,  1227,  1228,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1246,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1311,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1389,    -1,    -1,
      -1,  1393,    -1,    -1,    -1,  1397,    -1,  1399,    -1,  1401,
      -1,    -1,    -1,    -1,    -1,  1407,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1415,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1423,  1424,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1441,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1452,  1453,  1454,  1455,  1456,    -1,  1458,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1532,    -1,  1534,    -1,    -1,  1537,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1545,    -1,    -1,    -1,    -1,  1550,  1551,
      -1,    -1,    -1,    -1,    -1,    -1,  1558,    -1,    -1,    -1,
    1562,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1628,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1640,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1682,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1711,
      -1,    -1,    -1,    -1,  1716,    -1,    -1,    -1,    -1,  1721,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1739,    11,    -1,
      -1,    -1,    -1,    -1,    -1,  1747,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    28,    -1,    -1,    -1,    32,
      33,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,    94,    95,    96,    97,    98,    99,   100,    -1,    -1,
     103,   104,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,    -1,    -1,    -1,   122,
      -1,   124,   125,   126,   127,    -1,   129,    -1,    -1,    -1,
     133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   145,   146,   147,   148,   149,   150,   151,    -1,
      -1,   154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,
     163,   164,   165,   166,   167,   168,   169,   170,    -1,   172,
      -1,   174,   175,    -1,    -1,   178,   179,   180,    -1,    -1,
      -1,   184,    -1,   186,   187,    -1,   189,   190,   191,    -1,
     193,    -1,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,   208,   209,   210,    -1,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,    -1,   257,   258,   259,    -1,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    28,    -1,    -1,    -1,    32,    33,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    94,
      95,    96,    97,    98,    99,   100,    -1,    -1,   103,   104,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,    -1,    -1,    -1,   122,    -1,   124,
     125,   126,   127,    -1,   129,    -1,    -1,    -1,   133,   134,
     135,   136,   137,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,   154,
     155,   156,   157,   158,    -1,    -1,    -1,    -1,   163,   164,
     165,   166,   167,   168,   169,   170,    -1,   172,    -1,   174,
     175,    -1,    -1,   178,   179,   180,    -1,   182,    -1,   184,
      -1,   186,   187,    -1,   189,   190,   191,    -1,   193,    -1,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    -1,    -1,   208,   209,   210,    -1,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,    -1,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      28,    -1,    -1,    -1,    32,    33,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    -1,    93,    94,    95,    96,    97,
      98,    99,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    -1,    -1,    -1,   122,    -1,   124,   125,   126,   127,
      -1,   129,    -1,    -1,    -1,   133,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,
     148,   149,   150,   151,    -1,    -1,   154,   155,   156,   157,
     158,    -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,    -1,   172,    -1,   174,   175,    -1,    -1,
     178,   179,   180,    -1,   182,    -1,   184,    -1,   186,   187,
      -1,   189,   190,   191,    -1,   193,    -1,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,    -1,    -1,
     208,   209,   210,    -1,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    28,    -1,    -1,
      -1,    32,    33,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    -1,    93,    94,    95,    96,    97,    98,    99,   100,
      -1,    -1,   103,   104,    -1,    -1,    -1,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,    -1,    -1,
      -1,   122,    -1,   124,   125,   126,   127,    -1,   129,    -1,
      -1,    -1,   133,   134,   135,   136,   137,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   145,   146,   147,   148,   149,   150,
     151,    -1,    -1,   154,   155,   156,   157,   158,    -1,    -1,
      -1,    -1,   163,   164,   165,   166,   167,   168,   169,   170,
      -1,   172,    -1,   174,   175,    -1,    -1,   178,   179,   180,
      -1,   182,    -1,   184,    -1,   186,   187,    -1,   189,   190,
     191,    -1,   193,    -1,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,    -1,    -1,   208,   209,   210,
      -1,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,    -1,   257,   258,   259,    -1,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    28,    -1,    -1,    -1,    32,    33,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    -1,    93,
      94,    95,    96,    97,    98,    99,   100,    -1,    -1,   103,
     104,    -1,    -1,    -1,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    -1,    -1,    -1,   122,    -1,
     124,   125,   126,   127,    -1,   129,    -1,    -1,    -1,   133,
     134,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   145,   146,   147,   148,   149,   150,   151,    -1,    -1,
     154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,    -1,   172,    -1,
     174,   175,    -1,    -1,   178,   179,   180,    -1,   182,    -1,
     184,    -1,   186,   187,    -1,   189,   190,   191,    -1,   193,
      -1,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,    -1,    -1,   208,   209,   210,    -1,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    -1,   257,   258,   259,    -1,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    28,    -1,    -1,    -1,    32,    33,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    94,    95,    96,
      97,    98,    99,   100,    -1,    -1,   103,   104,    -1,    -1,
      -1,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,    -1,    -1,    -1,   122,    -1,   124,   125,   126,
     127,    -1,   129,    -1,    -1,    -1,   133,   134,   135,   136,
     137,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,   154,   155,   156,
     157,   158,    -1,    -1,    -1,    -1,   163,   164,   165,   166,
     167,   168,   169,   170,    -1,   172,    -1,   174,   175,    -1,
      -1,   178,   179,   180,    -1,    -1,    -1,   184,    -1,   186,
     187,    -1,   189,   190,   191,    -1,   193,    -1,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,    -1,
      -1,   208,   209,   210,    -1,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
     257,   258,   259,    -1,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    28,    -1,
      -1,    -1,    32,    33,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    -1,    93,    94,    95,    96,    97,    98,    99,
     100,    -1,    -1,   103,   104,    -1,    -1,    -1,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,    -1,
      -1,    -1,   122,    -1,   124,   125,   126,   127,    -1,   129,
      -1,    -1,    -1,   133,   134,   135,   136,   137,    -1,    -1,
      -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,   149,
     150,   151,    -1,    -1,   154,   155,   156,   157,   158,    -1,
      -1,    -1,    -1,   163,   164,   165,   166,   167,   168,   169,
     170,    -1,   172,    -1,   174,   175,    -1,    -1,   178,   179,
     180,    -1,    -1,    -1,   184,    -1,   186,   187,    -1,   189,
     190,   191,    -1,   193,    -1,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,    -1,    -1,   208,   209,
     210,    -1,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,   257,   258,   259,
      -1,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    28,    -1,    -1,    -1,    32,
      33,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,    94,    95,    96,    97,    98,    99,   100,    -1,    -1,
     103,   104,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,    -1,    -1,    -1,   122,
      -1,   124,   125,   126,   127,    -1,   129,    -1,    -1,    -1,
     133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   145,   146,   147,   148,   149,   150,   151,    -1,
      -1,   154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,
     163,   164,   165,   166,   167,   168,   169,   170,    -1,   172,
      -1,   174,   175,    -1,    -1,   178,   179,   180,    -1,    -1,
      -1,   184,    -1,   186,   187,    -1,   189,   190,   191,    -1,
     193,    -1,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,   208,   209,   210,    -1,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,    -1,   257,   258,   259,    -1,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    20,    21,    22,    23,    24,    25,
      26,    -1,    28,    -1,    -1,    -1,    32,    33,    -1,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    94,    95,
      96,    97,    98,    99,   100,    -1,    -1,   103,   104,    -1,
      -1,    -1,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    -1,    -1,    -1,   122,    -1,   124,   125,
     126,   127,    -1,   129,    -1,    -1,    -1,   133,   134,   135,
     136,   137,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,
     146,   147,   148,   149,   150,   151,    -1,    -1,   154,   155,
     156,   157,   158,    -1,    -1,    -1,    -1,   163,   164,   165,
     166,   167,   168,   169,   170,    -1,   172,    -1,   174,   175,
      -1,    -1,   178,   179,   180,    -1,    -1,    -1,   184,    -1,
     186,   187,    -1,   189,   190,   191,    -1,   193,    -1,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
      -1,    -1,   208,   209,   210,    -1,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
      -1,   257,   258,   259,    -1,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    28,
      -1,    -1,    -1,    32,    33,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,    93,    94,    95,    96,    97,    98,
      99,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
      -1,    -1,    -1,   122,    -1,   124,   125,   126,   127,    -1,
     129,    -1,    -1,    -1,   133,   134,   135,   136,   137,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,
     149,   150,   151,    -1,    -1,   154,   155,   156,   157,   158,
      -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,   168,
     169,   170,    -1,   172,    -1,   174,   175,    -1,    -1,   178,
     179,   180,    -1,    -1,    -1,   184,    -1,   186,   187,    -1,
     189,   190,   191,    -1,   193,    -1,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,    -1,    -1,   208,
     209,   210,    -1,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,    -1,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    28,    -1,    -1,    -1,
      32,    33,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      -1,    93,    94,    95,    96,    97,    98,    99,   100,    -1,
      -1,   103,   104,    -1,    -1,    -1,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,    -1,    -1,    -1,
     122,    -1,   124,   125,   126,   127,    -1,   129,    -1,    -1,
      -1,   133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   145,   146,   147,   148,   149,   150,   151,
      -1,    -1,   154,   155,   156,   157,   158,    -1,    -1,    -1,
      -1,   163,   164,   165,   166,   167,   168,   169,   170,    -1,
     172,    -1,   174,   175,    -1,    -1,   178,   179,   180,    -1,
      -1,    -1,   184,    -1,   186,   187,    -1,   189,   190,   191,
      -1,   193,    -1,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,    -1,    -1,   208,   209,   210,    -1,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,   257,   258,   259,    -1,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    28,    -1,    -1,    -1,    32,    33,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    94,
      95,    96,    97,    98,    99,   100,    -1,    -1,   103,   104,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,    -1,    -1,    -1,   122,    -1,   124,
     125,   126,   127,    -1,   129,    -1,    -1,    -1,   133,   134,
     135,   136,   137,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,   154,
     155,   156,   157,   158,    -1,    -1,    -1,    -1,   163,   164,
     165,   166,   167,   168,   169,   170,    -1,   172,    -1,   174,
     175,    -1,    -1,   178,   179,   180,    -1,    -1,    -1,   184,
     185,   186,   187,    -1,   189,   190,   191,    -1,   193,    -1,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    -1,    -1,   208,   209,   210,    -1,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,    -1,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    32,    33,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    -1,    93,    94,    95,    96,    97,
      98,    99,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    -1,    -1,    -1,   122,    -1,   124,   125,   126,   127,
      -1,   129,    -1,    -1,    -1,   133,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,
     148,   149,   150,   151,    -1,    -1,   154,   155,   156,   157,
     158,    -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,    -1,   172,    -1,   174,   175,    -1,    -1,
     178,   179,   180,    -1,   182,    -1,   184,    -1,   186,   187,
      -1,   189,   190,   191,    -1,   193,    -1,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,    -1,    -1,
     208,   209,   210,    -1,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    28,    -1,    -1,
      -1,    32,    33,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    -1,    93,    94,    95,    96,    97,    98,    99,   100,
      -1,    -1,   103,   104,    -1,    -1,    -1,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,    -1,    -1,
      -1,   122,    -1,   124,   125,   126,   127,    -1,   129,    -1,
      -1,    -1,   133,   134,   135,   136,   137,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   145,   146,   147,   148,   149,   150,
     151,    -1,    -1,   154,   155,   156,   157,   158,    -1,    -1,
      -1,    -1,   163,   164,   165,   166,   167,   168,   169,   170,
      -1,   172,    -1,   174,   175,    -1,    -1,   178,   179,   180,
      -1,    -1,    -1,   184,   185,   186,   187,    -1,   189,   190,
     191,    -1,   193,    -1,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,    -1,    -1,   208,   209,   210,
      -1,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,    -1,   257,   258,   259,    -1,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    28,    -1,    -1,    -1,    32,    33,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    -1,    93,
      94,    95,    96,    97,    98,    99,   100,    -1,    -1,   103,
     104,    -1,    -1,    -1,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    -1,    -1,    -1,   122,    -1,
     124,   125,   126,   127,    -1,   129,    -1,    -1,    -1,   133,
     134,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   145,   146,   147,   148,   149,   150,   151,    -1,    -1,
     154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,    -1,   172,    -1,
     174,   175,    -1,    -1,   178,   179,   180,    -1,    -1,    -1,
     184,   185,   186,   187,    -1,   189,   190,   191,    -1,   193,
      -1,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,    -1,    -1,   208,   209,   210,    -1,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    -1,   257,   258,   259,    -1,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    28,    -1,    -1,    -1,    32,    33,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    94,    95,    96,
      97,    98,    99,   100,    -1,    -1,   103,   104,    -1,    -1,
      -1,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,    -1,    -1,    -1,   122,    -1,   124,   125,   126,
     127,    -1,   129,    -1,    -1,    -1,   133,   134,   135,   136,
     137,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,   154,   155,   156,
     157,   158,    -1,    -1,    -1,    -1,   163,   164,   165,   166,
     167,   168,   169,   170,    -1,   172,    -1,   174,   175,    -1,
      -1,   178,   179,   180,    -1,    -1,    -1,   184,    -1,   186,
     187,    -1,   189,   190,   191,    -1,   193,    -1,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,    -1,
      -1,   208,   209,   210,    -1,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
     257,   258,   259,    -1,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    28,    -1,
      -1,    -1,    32,    33,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    -1,    93,    94,    95,    96,    97,    98,    99,
     100,    -1,    -1,   103,   104,    -1,    -1,    -1,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,    -1,
      -1,    -1,   122,    -1,   124,   125,   126,   127,    -1,   129,
      -1,    -1,    -1,   133,   134,   135,   136,   137,    -1,    -1,
      -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,   149,
     150,   151,    -1,    -1,   154,   155,   156,   157,   158,    -1,
      -1,    -1,    -1,   163,   164,   165,   166,   167,   168,   169,
     170,    -1,   172,    -1,   174,   175,    -1,    -1,   178,   179,
     180,    -1,    -1,    -1,   184,    -1,   186,   187,    -1,   189,
     190,   191,    -1,   193,    -1,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,    -1,    -1,   208,   209,
     210,    -1,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,   257,   258,   259,
      -1,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    28,    -1,    -1,    -1,    32,
      33,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,    94,    95,    96,    97,    98,    99,   100,    -1,    -1,
     103,   104,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,    -1,    -1,    -1,   122,
      -1,   124,   125,   126,   127,    -1,   129,    -1,    -1,    -1,
     133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   145,   146,   147,   148,   149,   150,   151,    -1,
      -1,   154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,
     163,   164,   165,   166,   167,   168,   169,   170,    -1,   172,
      -1,   174,   175,    -1,    -1,   178,   179,   180,    -1,    -1,
      -1,   184,    -1,   186,   187,    -1,   189,   190,   191,    -1,
     193,    -1,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,   208,   209,   210,    -1,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,    -1,   257,   258,   259,    -1,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    28,    -1,    -1,    -1,    32,    33,    -1,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    94,    95,
      96,    97,    98,    99,   100,    -1,    -1,   103,   104,    -1,
      -1,    -1,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    -1,    -1,    -1,   122,    -1,   124,   125,
     126,   127,    -1,   129,    -1,    -1,    -1,   133,   134,   135,
     136,   137,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,
     146,   147,   148,   149,   150,   151,    -1,    -1,   154,   155,
      -1,   157,   158,    -1,    -1,    -1,    -1,   163,   164,   165,
     166,   167,   168,   169,   170,    -1,   172,    -1,    -1,    -1,
      -1,    -1,   178,   179,   180,    -1,    -1,    -1,   184,    -1,
     186,   187,    -1,   189,   190,   191,    -1,   193,    -1,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
      -1,    -1,   208,   209,   210,    -1,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
      -1,   257,   258,   259,    -1,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    32,    33,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,    93,    94,    95,    96,    97,    98,
      99,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
      -1,    -1,    -1,   122,    -1,   124,   125,   126,   127,    -1,
     129,    -1,    -1,    -1,   133,   134,   135,   136,   137,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,
     149,   150,   151,    -1,    -1,   154,   155,    -1,   157,   158,
      -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,   168,
     169,   170,    -1,   172,    -1,    -1,    -1,    -1,    -1,   178,
     179,   180,    -1,    -1,    -1,   184,    -1,   186,   187,    -1,
      -1,    -1,   191,    -1,   193,    -1,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,    -1,    -1,   208,
     209,   210,    -1,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,    -1,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,
      -1,    23,    24,    -1,    -1,    -1,    28,    -1,    -1,    -1,
      32,    33,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      -1,    93,    94,    95,    96,    -1,    98,    99,   100,    -1,
      -1,   103,   104,    -1,    -1,    -1,    -1,   109,   110,   111,
     112,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   124,   125,   126,   127,    -1,   129,    -1,    -1,
      -1,   133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   145,   146,    -1,   148,   149,   150,    -1,
      -1,    -1,    -1,    -1,    -1,   157,   158,    -1,    -1,    -1,
      -1,   163,   164,   165,   166,   167,   168,   169,   170,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   178,   179,   180,    -1,
      -1,    -1,   184,    -1,   186,   187,    -1,    -1,    -1,   191,
      -1,   193,    -1,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,    -1,    -1,   208,   209,    -1,    -1,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,   257,   258,   259,    -1,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,    23,    24,
      -1,    -1,    -1,    28,    -1,    -1,    -1,    32,    33,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    94,
      95,    96,    -1,    98,    99,   100,    -1,    -1,   103,   104,
      -1,    -1,    -1,    -1,   109,   110,   111,   112,   113,   114,
     115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
     125,   126,   127,    -1,   129,    -1,    -1,    -1,   133,   134,
     135,   136,   137,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     145,   146,    -1,   148,   149,   150,    -1,    -1,    -1,    -1,
      -1,    -1,   157,   158,    -1,    -1,    -1,    -1,   163,   164,
     165,   166,   167,   168,   169,   170,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   178,   179,   180,    -1,    -1,    -1,   184,
      -1,   186,   187,    -1,    -1,    -1,   191,    -1,   193,    -1,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    -1,    -1,   208,   209,    -1,    -1,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,    -1,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    24,    -1,    -1,    -1,    28,    -1,    -1,    -1,
      32,    33,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      -1,    93,    94,    95,    96,    -1,    98,    99,   100,    -1,
      -1,   103,   104,    -1,    -1,    -1,    -1,   109,   110,   111,
     112,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   124,   125,   126,   127,    -1,   129,    -1,    -1,
      -1,   133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   145,   146,    -1,   148,   149,   150,    -1,
      -1,    -1,    -1,    -1,    -1,   157,   158,    -1,    -1,    -1,
      -1,   163,   164,   165,   166,   167,   168,   169,   170,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   178,   179,   180,    -1,
      -1,    -1,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,    -1,    -1,   208,   209,    -1,    -1,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,   257,   258,   259,    -1,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    24,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    32,    33,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,    93,    94,    95,    96,    -1,    98,
      99,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,    -1,
     109,   110,   111,   112,   113,   114,   115,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,    -1,
     129,    -1,    -1,    -1,   133,   134,   135,   136,   137,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   145,   146,    -1,   148,
     149,   150,    -1,    -1,    -1,    -1,    -1,    -1,   157,   158,
      -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,   168,
     169,   170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,
     179,   180,    -1,    -1,    -1,   184,    -1,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,    -1,    -1,   208,
     209,    -1,    -1,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,    -1,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,    17,
      18,    -1,    -1,    -1,    -1,    23,    24,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    32,    33,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    -1,    93,    94,    95,    96,    -1,
      98,    99,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,
      -1,   109,   110,   111,   112,   113,   114,   115,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,
      -1,   129,    -1,    -1,    -1,   133,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,    -1,
     148,   149,   150,    -1,    -1,    -1,    -1,    -1,    -1,   157,
     158,    -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     178,   179,   180,    -1,    -1,    -1,   184,    -1,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,    -1,    -1,
     208,   209,    -1,    -1,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
      23,    24,    -1,    -1,    -1,    28,    -1,    -1,    -1,    32,
      33,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,    94,    95,    96,    -1,    98,    99,   100,    -1,    -1,
     103,   104,    -1,    -1,    -1,    -1,   109,   110,   111,   112,
     113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,   125,   126,   127,    -1,   129,    -1,    -1,    -1,
     133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   145,   146,    -1,   148,   149,   150,    -1,    -1,
      -1,   154,    -1,    -1,   157,   158,    -1,    -1,    -1,    -1,
     163,   164,   165,   166,   167,   168,   169,   170,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   178,   179,   180,    -1,    -1,
      -1,   184,   185,   186,   187,    -1,    -1,    -1,   191,    -1,
     193,    -1,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,   208,   209,    -1,    -1,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,    -1,   257,   258,   259,    -1,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,    23,    24,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    32,    33,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    -1,    93,    94,    95,    96,    -1,
      98,    99,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,
      -1,   109,   110,   111,   112,   113,   114,   115,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,
      -1,   129,    -1,    -1,    -1,   133,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,    -1,
     148,   149,   150,    -1,    -1,    -1,    -1,    -1,    -1,   157,
     158,    -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     178,   179,   180,    -1,    -1,    -1,   184,   185,   186,   187,
      -1,    -1,    -1,   191,    -1,   193,    -1,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,    -1,    -1,
     208,   209,    -1,    -1,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
      23,    24,    -1,    -1,    -1,    28,    -1,    -1,    -1,    32,
      33,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,    94,    95,    96,    -1,    98,    99,   100,    -1,    -1,
     103,   104,    -1,    -1,    -1,    -1,   109,   110,   111,   112,
     113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,   125,   126,   127,    -1,   129,    -1,    -1,    -1,
     133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   145,   146,    -1,   148,   149,   150,    -1,    -1,
      -1,    -1,    -1,    -1,   157,   158,    -1,    -1,    -1,    -1,
     163,   164,   165,   166,   167,   168,   169,   170,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   178,   179,   180,    -1,    -1,
      -1,   184,   185,   186,   187,    -1,    -1,    -1,   191,    -1,
     193,    -1,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,   208,   209,    -1,    -1,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,    -1,   257,   258,   259,    -1,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,    23,    24,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    32,    33,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    -1,    93,    94,    95,    96,    -1,
      98,    99,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,
      -1,   109,   110,   111,   112,   113,   114,   115,   116,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,
      -1,   129,    -1,    -1,    -1,   133,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,    -1,
     148,   149,   150,    -1,    -1,    -1,   154,    -1,    -1,   157,
     158,    -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     178,   179,   180,    -1,    -1,    -1,   184,    -1,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,    -1,    -1,
     208,   209,    -1,    -1,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
      23,    24,    -1,    -1,    -1,    28,    -1,    -1,    -1,    32,
      33,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,    94,    95,    96,    -1,    98,    99,   100,    -1,    -1,
     103,   104,    -1,    -1,    -1,    -1,   109,   110,   111,   112,
     113,   114,   115,   116,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,   125,   126,   127,    -1,   129,    -1,    -1,    -1,
     133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   145,   146,    -1,   148,   149,   150,    -1,    -1,
      -1,   154,    -1,    -1,   157,   158,    -1,    -1,    -1,    -1,
     163,   164,   165,   166,   167,   168,   169,   170,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   178,   179,   180,    -1,    -1,
      -1,   184,    -1,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,   208,   209,    -1,    -1,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,    -1,   257,   258,   259,    -1,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,    23,    24,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    32,    33,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    -1,    93,    94,    95,    96,    -1,
      98,    99,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,
      -1,   109,   110,   111,   112,   113,   114,   115,   116,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,
      -1,   129,    -1,    -1,    -1,   133,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,    -1,
     148,   149,   150,    -1,    -1,    -1,   154,    -1,    -1,   157,
     158,    -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     178,   179,   180,    -1,    -1,    -1,   184,    -1,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,    -1,    -1,
     208,   209,    -1,    -1,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
      23,    24,    -1,    -1,    -1,    28,    -1,    -1,    -1,    32,
      33,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,    94,    95,    96,    -1,    98,    99,   100,    -1,    -1,
     103,   104,    -1,    -1,    -1,    -1,   109,   110,   111,   112,
     113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,   125,   126,   127,    -1,   129,    -1,    -1,    -1,
     133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   145,   146,    -1,   148,   149,   150,    -1,    -1,
      -1,   154,    -1,    -1,   157,   158,    -1,    -1,    -1,    -1,
     163,   164,   165,   166,   167,   168,   169,   170,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   178,   179,   180,    -1,    -1,
      -1,   184,    -1,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,   208,   209,    -1,    -1,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,    -1,   257,   258,   259,    -1,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,    23,    24,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    32,    33,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    -1,    93,    94,    95,    96,    -1,
      98,    99,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,
      -1,   109,   110,   111,   112,   113,   114,   115,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,
      -1,   129,    -1,    -1,    -1,   133,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,    -1,
     148,   149,   150,    -1,    -1,    -1,   154,    -1,    -1,   157,
     158,    -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     178,   179,   180,    -1,    -1,    -1,   184,    -1,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,    -1,    -1,
     208,   209,    -1,    -1,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
      23,    24,    -1,    -1,    -1,    28,    -1,    -1,    -1,    32,
      33,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,    94,    95,    96,    -1,    98,    99,   100,    -1,    -1,
     103,   104,    -1,    -1,    -1,    -1,   109,   110,   111,   112,
     113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,   125,   126,   127,    -1,   129,    -1,    -1,    -1,
     133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   145,   146,    -1,   148,   149,   150,    -1,    -1,
      -1,    -1,    -1,    -1,   157,   158,    -1,    -1,    -1,    -1,
     163,   164,   165,   166,   167,   168,   169,   170,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   178,   179,   180,    -1,    -1,
      -1,   184,    -1,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,   208,   209,    -1,    -1,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,    -1,   257,   258,   259,    -1,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,    23,    24,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    32,    33,    -1,    35,    36,    37,
      -1,    39,    40,    41,    42,    -1,    -1,    45,    46,    47,
      -1,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    -1,    60,    -1,    -1,    63,    64,    65,    66,    67,
      -1,    69,    -1,    71,    -1,    -1,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    -1,    93,    94,    95,    -1,    -1,
      98,    99,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,
      -1,   109,   110,   111,   112,   113,   114,   115,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,
      -1,   129,    -1,    -1,    -1,   133,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,    -1,
     148,   149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,
     158,    -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     178,   179,   180,    -1,    -1,    -1,   184,    -1,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,    -1,    -1,
      -1,   209,    -1,    -1,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,    11,    19,    20,    21,    22,    23,    24,    25,    26,
      28,    32,    33,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    93,    94,
      95,    96,    97,    98,    99,   100,   103,   104,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   122,
     124,   125,   126,   127,   129,   133,   134,   135,   136,   137,
     144,   145,   146,   147,   148,   149,   150,   151,   154,   155,
     156,   157,   158,   163,   164,   165,   166,   167,   168,   169,
     170,   172,   174,   175,   178,   179,   180,   184,   186,   187,
     189,   190,   191,   193,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   208,   209,   210,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   257,   258,   259,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   323,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   344,   345,   346,   347,   348,   349,   353,   354,   355,
     359,   361,   362,   364,   373,   376,   379,   380,   381,   383,
     384,   385,   386,   387,   389,   390,   392,   393,   394,   395,
     396,   397,   399,   400,   403,   404,   405,   406,   411,   413,
     415,   416,   421,   440,   443,   447,   450,   451,   456,   457,
     458,   459,   461,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   497,   498,   499,   500,   501,   502,   503,
     504,   505,   507,   508,   509,   523,   524,   526,   527,   528,
     529,   530,   531,   532,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   552,   553,   554,   555,   560,   561,
     562,   563,   564,   565,   568,   626,   628,   629,   630,    32,
      33,    49,   212,   382,   383,   384,   382,   382,   154,   154,
      36,    37,    39,    40,    47,    56,    57,    74,    78,   109,
     110,   111,   158,   167,   199,   217,   227,   259,   285,   286,
     287,   288,   289,   291,   292,   293,   294,   295,   300,   301,
     360,   361,   365,   366,   367,   371,   372,   158,   151,   154,
     151,   154,   151,   154,    66,    71,   116,   408,   154,   368,
     154,    23,    33,    60,   116,   271,   420,   422,   423,   151,
     154,   154,   154,   116,   151,   154,   154,   154,    93,   151,
     218,   219,   120,   120,   120,   151,   154,    28,    38,    42,
      44,    46,    47,    48,    51,    59,    67,    70,    72,    73,
      75,    89,    90,    96,   103,   110,   112,   113,   133,   136,
     137,   167,   170,   178,   179,   187,   199,   221,   223,   225,
     226,   233,   235,   236,   237,   238,   241,   242,   491,   628,
     629,   120,   116,   391,   120,   120,    38,    43,    44,    59,
      61,    62,    70,    96,   222,   628,   116,   120,   120,   182,
     382,   384,    48,    72,    73,   116,   151,   185,   242,   403,
     405,   415,   628,   151,   120,    15,   627,   628,    17,    18,
     628,   120,   120,   120,   483,   151,    29,   211,   213,   222,
     224,   154,   222,   224,   222,   222,   227,   116,   110,   361,
     239,   239,   240,   154,   151,   386,   325,     0,   327,   328,
      32,    49,   330,   347,     1,   188,   324,   188,   324,   110,
     362,   385,   403,   105,   188,   105,   188,    41,    46,    51,
      69,   166,   169,   184,   209,   398,   407,   412,   413,   414,
     428,   429,   433,   165,    91,   130,   138,   139,   141,   149,
     153,   155,   160,   177,   200,   201,   202,   203,   204,   205,
     475,   476,   247,   156,   174,   196,   115,   144,   157,   191,
     198,   207,   134,   148,    50,   197,    99,   100,   156,   174,
     474,   151,   480,   483,   189,   190,   152,   495,   496,   491,
     495,   491,   154,   495,   119,   143,   154,   182,   182,   182,
      28,   363,   498,   363,   626,   180,   193,   180,   193,   164,
     180,   629,   628,   167,   199,    47,   628,   150,   116,    44,
      47,    78,   104,   166,   627,   218,   219,   220,   298,   299,
     244,   599,   628,   291,   628,   296,   296,   298,   299,   302,
     135,   140,   110,   365,   285,   293,   372,   627,   383,   384,
     185,   382,    44,    62,   185,   548,   549,   403,   185,   191,
     628,   282,   282,   417,   418,   628,   116,   424,   116,   185,
     369,   370,   151,   388,   403,     1,   158,   626,   111,   158,
     343,   626,   628,   116,   140,   105,   403,    28,   185,   627,
     628,   628,   441,   442,   628,   383,   185,   403,   403,   550,
     628,   383,   151,   151,   403,   185,   191,   628,   628,   140,
     441,   182,   182,   154,   154,   154,   628,   151,   185,   184,
      34,   511,   512,   513,   403,     8,   173,    16,   403,   211,
      28,   404,   404,   185,   404,   404,   404,   404,   228,   566,
     567,   628,   391,   110,   188,   188,   404,   403,   384,   403,
     243,   401,   402,   188,   324,   188,   324,     3,   331,   347,
     380,   331,   347,   380,    32,   348,   380,   348,   380,   391,
     391,   404,   116,   166,   168,   168,   385,   404,   404,   458,
     459,   461,   461,   461,   461,   460,   461,   461,   461,    70,
     465,   465,   464,   466,   466,   466,   466,   467,   467,   468,
     468,   228,    93,    93,    93,   182,   403,   483,   483,   403,
     496,   185,   404,   506,   627,   147,   185,   506,   105,   185,
     185,   105,   105,   368,    28,   629,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,   350,   351,   352,    93,
     135,   140,   356,   357,   358,   628,   158,   158,   350,   626,
     125,   130,    54,    56,    98,   249,   262,   264,   275,   276,
     277,   279,   281,   600,   601,   602,   603,   604,   605,   612,
     618,   619,   244,    93,   234,   375,   297,   628,   140,   404,
     116,   628,   628,   130,   182,   182,   185,   185,   182,   105,
     185,   105,   185,   105,    35,    93,    95,   145,   419,   420,
     534,   628,    55,   214,   252,   409,   410,   628,    93,   105,
     185,   382,   185,   627,    95,    44,   627,   626,    95,   140,
     534,   628,   404,   423,   182,   185,   185,   185,   185,   105,
     186,   145,   534,   182,   185,   185,   151,   182,   383,   383,
     182,   105,   185,   105,   185,   140,   534,   404,   186,   403,
     403,   403,   628,   512,   513,   128,   194,   182,   182,   129,
     188,    93,   215,   216,   230,    93,   215,   216,   230,    93,
     234,   222,   105,   232,   140,   391,   188,   185,    48,    72,
      73,   242,   405,   415,   182,   492,   572,   402,   347,    32,
      32,   188,   324,   188,   111,   628,   168,   404,   434,   435,
     116,   430,   431,   461,   151,   154,   257,   479,   498,   573,
     576,   577,   578,   579,   580,   584,   586,   588,   589,    47,
     150,   154,   208,   535,   537,   539,   540,   556,   557,   558,
     559,   628,   535,   533,   539,   533,   182,   183,   105,   185,
     185,   498,   146,   163,   146,   163,   135,   388,   368,   351,
     130,   537,   358,   404,   534,   626,   626,   126,   127,   626,
     275,   276,   277,   281,   628,   261,   272,   261,   272,    28,
     284,    95,   111,   154,   606,   609,   600,    38,    43,    59,
      61,    70,    96,   222,   374,   540,   289,   290,   224,   297,
     306,   404,   628,    93,   375,   297,   626,   151,   550,   551,
     628,   550,   551,   116,   125,   535,   116,   404,   145,   420,
     145,    35,   145,   419,   420,   145,   534,   252,    53,    58,
      76,   116,   419,   425,   426,   427,   410,   534,   535,   370,
      93,   182,   195,   130,   342,   626,   158,   130,    95,   342,
     404,   140,   420,   151,   116,   404,   404,   145,    98,   444,
     445,   446,   448,   449,    98,   452,   453,   454,   455,   383,
     182,   182,   151,   550,   550,   404,   140,   188,   404,   185,
     185,   185,    34,   513,   128,   194,     9,    10,   101,   121,
     123,   151,   192,   508,   510,   521,   522,   525,    28,   229,
     231,   404,   404,   404,   229,   231,   404,   404,   404,   404,
     404,   404,   116,   404,   404,   385,   154,   154,   154,   151,
     184,   243,   569,   570,   154,   207,   386,   188,   111,   380,
     380,   380,   434,    94,   104,   114,   125,   436,   437,   438,
     439,   105,   628,   105,   403,   573,   580,   151,   283,   462,
     625,    95,   167,   250,   251,   253,   260,   270,   282,   574,
     575,   594,   595,   596,   597,   620,   623,   256,   258,   581,
     599,   265,   585,   621,   245,   246,   268,   590,   591,   154,
     154,   537,   154,   142,   174,   191,   536,   142,   404,   135,
     388,   552,   357,   284,    28,    95,   111,   154,   613,    28,
     606,   375,   536,   224,   224,   481,   285,   304,   534,   374,
     224,   188,   382,   185,   185,   142,   185,   185,   418,   145,
     419,   628,   404,   145,   404,   125,   404,   145,   420,   145,
     404,   145,   116,   116,   404,   628,   427,    76,   535,   385,
     404,   626,   105,   342,   404,   140,   382,   442,   404,   404,
     111,   445,   446,    98,   184,   111,   446,   449,   116,   535,
      98,   111,   453,    98,   111,   455,   182,   382,   185,   185,
     404,   195,   452,   130,   192,   510,     7,   383,   628,   192,
     521,   188,   230,   230,   230,   230,   234,   567,   184,   403,
     403,   403,   572,   570,   116,   492,   626,   126,   127,   438,
     439,   439,   435,   104,   432,   431,   182,   185,   573,   587,
     248,   214,   252,   266,   273,   624,    95,   254,   255,   622,
     248,   577,   624,   464,   594,   578,   145,   280,   582,   583,
     622,   284,   593,    77,   592,   185,   191,   535,   538,   185,
     185,   185,    28,   134,   198,   615,   616,   617,    28,   614,
     615,   269,   610,   105,   607,   168,   628,   255,   375,   481,
     182,   404,   145,   404,   145,   419,   404,   145,   404,   404,
     628,   628,   426,   404,   124,   124,    95,   626,   404,   182,
     184,   184,   404,   385,   404,   184,   184,   628,   184,   116,
     535,   116,   184,   116,   535,   184,   182,   111,   513,   628,
     192,   182,   513,   628,   404,   404,   404,   404,   404,   404,
     185,   185,   185,   151,   154,   571,   628,   439,   626,   182,
     466,    52,   127,   464,   464,   267,   274,   284,   598,   598,
     579,   151,   278,    93,   185,   105,   185,   613,   613,   617,
     105,   185,    28,   611,   622,   608,   609,   185,   377,   378,
     481,   116,   222,   305,   285,   168,   404,   404,   145,   404,
      53,   385,   404,   342,   404,   385,    93,   385,   404,   628,
     184,   628,   404,   628,   184,   385,   116,    92,   181,   514,
     513,   628,   194,   513,   195,   452,   403,   116,   105,   185,
     464,   464,   196,   403,   535,   535,    93,    28,   263,   105,
     105,   439,   534,   628,   116,   222,   628,   377,   404,   116,
     535,    93,   184,    93,   628,     5,   131,   517,   518,   520,
     522,    27,   132,   515,   516,   519,   522,   194,   513,   194,
     111,   182,   628,   116,   386,   464,   182,   535,   609,   378,
     439,   303,   628,   116,   222,   628,   184,   535,   385,   404,
     535,   184,    92,   131,   520,   181,   132,   519,   194,   116,
     105,   185,   628,   404,   303,   628,   116,   385,   404,   184,
     184,   628,   116,   571,   105,   185,   291,   303,   628,   184,
     628,   116,   386,   304,   404,   304,   105,   185,   628,   481,
     481,   116,   571,   185,   196,   628,   386,   285,   185,   628,
     571,   222,   116,   628,   304,   481
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
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   322,   323,   323,   324,   325,   325,   325,   325,   326,
     326,   327,   327,   327,   327,   327,   327,   327,   327,   328,
     328,   328,   328,   329,   330,   330,   330,   331,   331,   331,
     331,   331,   332,   332,   332,   332,   332,   332,   332,   332,
     333,   333,   334,   335,   336,   336,   337,   337,   338,   338,
     339,   339,   339,   339,   340,   340,   340,   341,   341,   341,
     341,   342,   342,   343,   343,   344,   344,   344,   344,   345,
     346,   346,   347,   347,   347,   348,   348,   348,   348,   348,
     348,   348,   348,   349,   349,   350,   350,   351,   352,   352,
     352,   352,   352,   352,   352,   352,   352,   352,   353,   354,
     355,   356,   356,   357,   357,   357,   358,   359,   359,   359,
     360,   360,   360,   360,   361,   361,   362,   362,   362,   362,
     363,   363,   364,   364,   365,   365,   366,   366,   367,   367,
     368,   368,   368,   368,   369,   369,   370,   370,   371,   371,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   373,   373,   373,   373,   373,   373,
     373,   373,   374,   374,   375,   375,   376,   376,   377,   377,
     378,   378,   378,   378,   379,   379,   379,   379,   380,   381,
     381,   381,   382,   382,   382,   383,   383,   384,   384,   385,
     385,   385,   385,   385,   385,   385,   385,   385,   385,   385,
     385,   386,   386,   387,   388,   389,   390,   390,   390,   390,
     390,   391,   391,   391,   391,   392,   393,   394,   395,   396,
     396,   397,   398,   399,   400,   401,   401,   402,   402,   402,
     402,   403,   403,   404,   404,   404,   404,   404,   404,   405,
     405,   405,   405,   405,   405,   405,   406,   407,   408,   408,
     409,   409,   409,   410,   410,   411,   411,   412,   413,   413,
     413,   414,   414,   414,   414,   414,   415,   415,   416,   417,
     417,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   419,   420,   421,   422,   422,   423,   423,
     423,   423,   424,   424,   425,   425,   425,   426,   426,   426,
     427,   427,   427,   428,   429,   430,   430,   431,   431,   432,
     433,   433,   434,   434,   435,   435,   436,   436,   436,   436,
     436,   436,   436,   437,   437,   438,   438,   439,   440,   440,
     441,   441,   442,   442,   443,   444,   444,   445,   446,   446,
     447,   448,   448,   449,   450,   450,   451,   451,   452,   452,
     453,   453,   454,   454,   455,   455,   456,   457,   457,   458,
     458,   459,   459,   459,   459,   459,   460,   459,   459,   459,
     459,   461,   461,   462,   462,   463,   463,   464,   464,   464,
     465,   465,   465,   465,   465,   466,   466,   466,   467,   467,
     467,   468,   468,   469,   469,   470,   470,   471,   471,   472,
     472,   473,   473,   473,   473,   474,   474,   474,   475,   475,
     475,   475,   475,   475,   476,   476,   476,   477,   477,   477,
     477,   478,   478,   479,   479,   480,   480,   480,   481,   481,
     481,   481,   482,   483,   483,   483,   484,   484,   485,   485,
     485,   485,   486,   486,   487,   487,   487,   487,   487,   487,
     487,   488,   488,   489,   489,   490,   490,   490,   490,   490,
     491,   491,   492,   492,   493,   493,   493,   494,   494,   494,
     494,   495,   495,   496,   497,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   498,   498,   499,   499,   499,   500,
     501,   501,   502,   503,   504,   505,   505,   506,   506,   507,
     507,   508,   508,   508,   509,   509,   509,   509,   509,   509,
     510,   510,   511,   511,   512,   513,   513,   514,   514,   515,
     515,   516,   516,   516,   516,   517,   517,   518,   518,   518,
     518,   519,   519,   520,   520,   521,   521,   521,   521,   522,
     522,   522,   522,   523,   523,   524,   524,   525,   526,   526,
     526,   526,   526,   526,   527,   528,   528,   529,   529,   530,
     531,   532,   532,   533,   533,   534,   535,   535,   535,   536,
     536,   536,   537,   537,   537,   537,   537,   538,   538,   539,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   541,
     542,   542,   542,   543,   544,   545,   545,   545,   546,   546,
     546,   546,   546,   547,   548,   548,   548,   548,   548,   548,
     548,   549,   550,   551,   552,   553,   553,   554,   555,   556,
     556,   557,   558,   558,   559,   560,   560,   560,   561,   561,
     561,   561,   561,   561,   561,   561,   561,   561,   562,   562,
     563,   563,   564,   565,   566,   566,   567,   568,   569,   569,
     570,   570,   570,   570,   571,   572,   572,   573,   574,   574,
     575,   575,   576,   576,   577,   577,   578,   578,   579,   579,
     580,   581,   581,   582,   582,   583,   584,   584,   584,   585,
     585,   586,   587,   587,   588,   589,   589,   590,   590,   591,
     591,   591,   592,   592,   593,   593,   594,   594,   594,   594,
     594,   595,   596,   597,   598,   598,   598,   599,   599,   600,
     600,   600,   600,   600,   600,   600,   600,   601,   601,   601,
     601,   602,   602,   603,   604,   604,   605,   605,   605,   606,
     606,   607,   607,   608,   608,   609,   610,   610,   611,   611,
     612,   612,   612,   613,   613,   614,   614,   615,   615,   616,
     616,   617,   617,   618,   619,   619,   620,   620,   620,   621,
     622,   622,   622,   622,   623,   623,   624,   624,   625,   626,
     627,   627,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   629,   629,
     629,   629,   629,   629,   629,   629,   629,   629,   629,   629,
     629,   629,   629,   629,   629,   629,   629,   629,   629,   629,
     629,   629,   629,   629,   629,   629,   629,   629,   629,   629,
     629,   629,   629,   629,   629,   629,   629,   629,   629,   629,
     629,   629,   629,   629,   629,   629,   629,   629,   629,   629,
     629,   629,   629,   629,   629,   629,   629,   629,   629,   629,
     629,   629,   629,   629,   629,   629,   629,   629,   629,   629,
     629,   629,   629,   629,   629,   629,   629,   629,   629,   629,
     629,   629,   629,   629,   629,   629,   629,   629,   629,   629,
     629,   629,   629,   629,   629,   629,   629,   629,   629,   629,
     629,   629,   629,   629,   629,   629,   629,   629,   629,   629,
     629,   629,   629,   629,   629,   629,   629,   629,   629,   629,
     629,   629,   629,   629,   629,   629,   629,   629,   629,   629,
     629,   629,   629,   629,   629,   629,   629,   629,   629,   629,
     629,   629,   629,   629,   629,   629,   629,   629,   629,   629,
     629,   629,   629,   629,   629,   629,   629,   629,   629,   629,
     629,   629,   629,   629,   629,   629,   629,   629,   629,   629,
     629,   629,   629,   629,   629,   629,   629,   629,   629,   629,
     629,   629,   629,   629,   629,   629,   629,   629,   629,   629,
     629,   629,   629,   629,   629,   629,   629,   629,   630,   630
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  xquery_parser::yyr2_[] =
  {
         0,     2,     1,     2,     2,     1,     2,     1,     2,     4,
       6,     3,     3,     5,     1,     3,     3,     5,     5,     1,
       3,     3,     5,     6,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     4,     3,     3,     3,     3,     3,     5,     5,
       5,     5,     5,     5,     1,     1,     3,     3,     4,     5,
       6,     1,     3,     3,     3,     3,     6,     5,     8,     5,
       5,     5,     1,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     3,
       4,     3,     1,     1,     1,     2,     2,     4,     3,     5,
       3,     4,     4,     5,     1,     2,     1,     4,     1,     4,
       1,     3,     2,     3,     1,     1,     4,     4,     5,     5,
       2,     3,     4,     5,     1,     3,     2,     3,     1,     2,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       1,     2,     2,     2,     3,     4,     5,     6,     4,     5,
       6,     7,     1,     2,     3,     3,     8,     9,     1,     3,
       1,     2,     2,     3,    11,    14,    13,    22,     1,     1,
       1,     0,     1,     1,     0,     1,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     3,     3,     2,     3,     2,     3,     3,
       4,     2,     3,     4,     5,     5,     2,     4,     5,     3,
       3,     2,     2,     8,     3,     1,     2,     3,     7,    10,
      13,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       1,     1,     2,     4,     3,     5,     4,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     1,
       4,     3,     5,     4,     6,     4,     6,     5,     7,     4,
       5,     5,     6,     3,     3,     2,     1,     3,     4,     5,
       3,     6,     4,     5,     1,     2,     3,     1,     2,     1,
       6,     3,     3,     2,     3,     1,     3,     2,     3,     2,
       3,     4,     1,     3,     1,     2,     1,     1,     1,     2,
       2,     2,     3,     1,     1,     2,     2,     2,     5,     5,
       1,     4,     3,     4,     8,     1,     2,     3,     2,     3,
       8,     1,     2,     3,     8,    10,     8,    10,     1,     2,
       4,     7,     1,     2,     4,     7,     8,     1,     3,     1,
       3,     1,     3,     3,     3,     3,     0,     4,     3,     3,
       3,     1,     5,     0,     1,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     4,     1,     4,     1,     4,     1,     4,     1,
       2,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     5,     5,
       6,     3,     4,     1,     2,     3,     2,     2,     1,     2,
       2,     1,     1,     1,     3,     3,     1,     1,     1,     2,
       1,     2,     2,     1,     2,     2,     2,     2,     2,     2,
       2,     1,     2,     2,     1,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       4,     1,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     3,     1,     4,     4,     3,     4,     1,     3,     1,
       1,     1,     1,     1,     4,     5,     8,     9,     9,    10,
       1,     2,     1,     2,     6,     0,     1,     3,     3,     0,
       1,     1,     1,     2,     2,     0,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     2,     3,     3,     2,     1,     1,
       1,     1,     1,     1,     4,     3,     7,     3,     7,     4,
       4,     3,     7,     1,     2,     2,     1,     2,     3,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     4,     4,     3,     3,     3,     4,     4,     3,     4,
       6,     4,     6,     4,     3,     4,     6,     6,     4,     6,
       6,     4,     1,     2,     1,     1,     1,     3,     3,     1,
       1,     4,     5,     6,     3,     3,     3,     3,     5,     7,
       7,     5,     5,     5,     7,     7,     5,     5,     3,     3,
       5,     7,     5,     7,     1,     4,     3,     5,     1,     2,
       3,     7,    10,    13,     3,     1,     3,     2,     0,     1,
       1,     2,     1,     3,     1,     3,     1,     4,     1,     2,
       3,     0,     1,     0,     1,     4,     2,     3,     1,     0,
       1,     4,     0,     1,     2,     1,     3,     0,     1,     2,
       2,     1,     0,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     1,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       1,     2,     2,     3,     1,     2,     2,     5,     2,     1,
       1,     0,     2,     1,     3,     4,     0,     2,     0,     2,
       4,     4,     3,     2,     3,     1,     3,     0,     1,     1,
       2,     2,     2,     2,     1,     2,     2,     2,     2,     3,
       2,     3,     3,     4,     2,     2,     1,     1,     3,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1
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
  "\"'EQName #)'\"", "\"'*:QName'\"", "\"'element QName {'\"",
  "\"'attribute QName {'\"", "\"'processing-instruction NCName {'\"",
  "\"'QName'\"", "\"'EQName'\"", "\"'%QName'\"", "\"'%EQName'\"",
  "\"'quote attribute content'\"", "\"'STRING'\"", "\"'XML comment'\"",
  "\"'URI'\"", "\"'NCName'\"", "\"'declare'\"", "\"'module'\"",
  "\"'<blank>'\"", "\"'allowing'\"", "\"'base-uri'\"",
  "\"'boundary-space'\"", "\"'comment'\"", "\"'construction'\"",
  "\"'copy-namespaces'\"", "\"'count'\"", "\"'document'\"",
  "\"'document-node'\"", "\"'element'\"", "\"'eval'\"", "\"'for'\"",
  "\"'function'\"", "\"'if'\"", "\"'import'\"", "\"'instance'\"",
  "\"'let'\"", "\"'most'\"", "\"'next'\"", "\"'no'\"", "\"'only'\"",
  "\"'option'\"", "\"'ordering'\"", "\"'previous'\"",
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
  "\"':'\"", "\"'::'\"", "\"'{{'\"", "\"'DOUBLE'\"", "\"'<double {>'\"",
  "\"'else'\"", "\"'empty'\"", "\"'greatest'\"", "\"'least'\"", "\"'/>'\"",
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
  "\"'copy'\"", "\"'with'\"", "\"'local'\"", "\"'break'\"",
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
  "SIND_DeclList", "SIND_Decl", "Setter", "BoundarySpaceDecl",
  "DefaultCollationDecl", "BaseURIDecl", "ConstructionDecl",
  "OrderingModeDecl", "EmptyOrderDecl", "CopyNamespacesDecl", "Import",
  "SchemaImport", "URILiteralList", "SchemaPrefix", "ModuleImport",
  "NamespaceDecl", "DefaultNamespaceDecl", "VFO_DeclList", "VFO_Decl",
  "DecimalFormatDecl", "DecimalFormatParamList", "DecimalFormatParam",
  "DecimalFormatParamName", "OptionDecl", "FTOptionDecl", "CtxItemDecl",
  "CtxItemDecl2", "CtxItemDecl3", "CtxItemDecl4", "VarDecl",
  "VarNameAndType", "AnnotationList", "Annotation",
  "AnnotationLiteralList", "FunctionDecl", "FunctionDecl2",
  "FunctionDeclSimple", "FunctionDeclUpdating", "FunctionSig", "ParamList",
  "Param", "DeclPropertyList", "DeclProperty", "CollectionDecl",
  "CollectionTypeDecl", "NodeModifier", "IndexDecl", "IndexKeyList",
  "IndexKeySpec", "IntegrityConstraintDecl", "QueryBody",
  "StatementsAndOptionalExprTop", "StatementsAndOptionalExpr",
  "StatementsAndExpr", "Statements", "Statement", "BlockStatement",
  "BlockExpr", "EnclosedStatementsAndOptionalExpr", "VarDeclStatement",
  "BlockVarDeclList", "BlockVarDecl", "AssignStatement", "ApplyStatement",
  "ExitStatement", "WhileStatement", "FlowCtlStatement", "FLWORStatement",
  "ReturnStatement", "IfStatement", "TryStatement", "CatchListStatement",
  "CatchStatement", "Expr", "ExprSingle", "ExprSimple", "FLWORExpr",
  "ReturnExpr", "WindowType", "FLWORWinCondType", "FLWORWinCond",
  "WindowClause", "CountClause", "ForLetWinClause", "FLWORClause",
  "FLWORClauseList", "ForClause", "VarInDeclList", "VarInDecl",
  "PositionalVar", "FTScoreVar", "LetClause", "VarGetsDeclList",
  "VarGetsDecl", "WindowVarDecl", "WindowVars", "WindowVars3",
  "WindowVars2", "WhereClause", "GroupByClause", "GroupSpecList",
  "GroupSpec", "GroupCollationSpec", "OrderByClause", "OrderSpecList",
  "OrderSpec", "OrderModifier", "OrderDirSpec", "OrderEmptySpec",
  "OrderCollationSpec", "QuantifiedExpr", "QVarInDeclList", "QVarInDecl",
  "SwitchExpr", "SwitchCaseClauseList", "SwitchCaseClause",
  "SwitchCaseOperandList", "SwitchStatement", "SwitchCaseStatementList",
  "SwitchCaseStatement", "TypeswitchExpr", "TypeswitchStatement",
  "CaseClauseList", "CaseClause", "CaseStatementList", "CaseStatement",
  "IfExpr", "OrExpr", "AndExpr", "ComparisonExpr", "$@1", "FTContainsExpr",
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
  "CatchListExpr", "CatchExpr", "BracedExpr", "NameTestList",
  "FTSelection", "opt_FTPosFilter_list", "FTPosFilter_list", "FTOr",
  "FTAnd", "FTMildNot", "FTUnaryNot", "FTPrimaryWithOptions",
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
  "FTIgnoreOption", "URI_LITERAL", "NCNAME", "QNAME", "FUNCTION_NAME",
  "EQNAME", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const xquery_parser::rhs_number_type
  xquery_parser::yyrhs_[] =
  {
       323,     0,    -1,   325,    -1,   308,   325,    -1,     1,     3,
      -1,   327,    -1,   326,   327,    -1,   328,    -1,   326,   328,
      -1,   212,   213,    28,   188,    -1,   212,   213,    28,   129,
      28,   188,    -1,   330,   188,   380,    -1,   347,   188,   380,
      -1,   330,   188,   347,   188,   380,    -1,   380,    -1,   330,
     324,   380,    -1,   347,   324,   380,    -1,   330,   188,   347,
     324,   380,    -1,   330,   324,   347,   188,   380,    -1,   329,
      -1,   329,   330,   188,    -1,   329,   347,   188,    -1,   329,
     330,   188,   347,   188,    -1,    33,   158,   627,   130,   626,
     188,    -1,   331,    -1,   330,   188,   331,    -1,   330,   324,
     331,    -1,   332,    -1,   340,    -1,   345,    -1,   346,    -1,
     354,    -1,   333,    -1,   334,    -1,   335,    -1,   336,    -1,
     337,    -1,   338,    -1,   339,    -1,   560,    -1,    32,    37,
     180,    -1,    32,    37,   193,    -1,    32,   111,   104,   626,
      -1,    32,    36,   626,    -1,    32,    39,   180,    -1,    32,
      39,   193,    -1,    32,    57,   167,    -1,    32,    57,   199,
      -1,    32,   111,   166,   125,   126,    -1,    32,   111,   166,
     125,   127,    -1,    32,    40,   180,   105,   146,    -1,    32,
      40,   180,   105,   163,    -1,    32,    40,   164,   105,   146,
      -1,    32,    40,   164,   105,   163,    -1,   341,    -1,   344,
      -1,    49,    23,     1,    -1,    49,    60,   626,    -1,    49,
      60,   343,   626,    -1,    49,    60,   626,    95,   342,    -1,
      49,    60,   343,   626,    95,   342,    -1,   626,    -1,   342,
     105,   626,    -1,   158,   627,   130,    -1,   111,    44,   158,
      -1,    49,    33,   626,    -1,    49,    33,   158,   627,   130,
     626,    -1,    49,    33,   626,    95,   342,    -1,    49,    33,
     158,   627,   130,   626,    95,   342,    -1,    32,   158,   627,
     130,   626,    -1,    32,   111,    44,   158,   626,    -1,    32,
     111,    47,   158,   626,    -1,   348,    -1,   347,   188,   348,
      -1,   347,   324,   348,    -1,   349,    -1,   353,    -1,   355,
      -1,   359,    -1,   364,    -1,   373,    -1,   376,    -1,   379,
      -1,    32,   111,    78,   350,    -1,    32,    78,   628,   350,
      -1,   351,    -1,   350,   351,    -1,   352,   130,   552,    -1,
      79,    -1,    87,    -1,    80,    -1,    81,    -1,    82,    -1,
      83,    -1,    88,    -1,    84,    -1,    85,    -1,    86,    -1,
      32,    56,   628,    28,    -1,    32,   259,   599,    -1,    32,
     109,   150,   356,    -1,    93,   537,   357,    -1,   357,    -1,
     358,    -1,   135,    -1,   135,   358,    -1,   140,   404,    -1,
      32,   360,   140,   404,    -1,    32,   360,   135,    -1,    32,
     360,   135,   140,   404,    -1,   110,   116,   628,    -1,   110,
     116,   628,   534,    -1,   361,   110,   116,   628,    -1,   361,
     110,   116,   628,   534,    -1,   362,    -1,   361,   362,    -1,
      25,    -1,    25,   154,   363,   185,    -1,    26,    -1,    26,
     154,   363,   185,    -1,   498,    -1,   363,   105,   498,    -1,
      32,   365,    -1,    32,   361,   365,    -1,   366,    -1,   367,
      -1,    47,   629,   368,   388,    -1,    47,   629,   368,   135,
      -1,    74,    47,   629,   368,   388,    -1,    74,    47,   629,
     368,   135,    -1,   154,   185,    -1,   154,   369,   185,    -1,
     154,   185,    93,   535,    -1,   154,   369,   185,    93,   535,
      -1,   370,    -1,   369,   105,   370,    -1,   116,   628,    -1,
     116,   628,   534,    -1,   372,    -1,   371,   372,    -1,   286,
      -1,   287,    -1,   288,    -1,   289,    -1,   167,    -1,   199,
      -1,   227,   299,    -1,   227,   298,    -1,   300,   299,    -1,
     300,   298,    -1,   291,    -1,   292,   291,    -1,   295,   296,
      -1,   294,   296,    -1,    32,   285,   628,    -1,    32,   285,
     628,   375,    -1,    32,   285,   628,    93,   374,    -1,    32,
     285,   628,    93,   374,   375,    -1,    32,   371,   285,   628,
      -1,    32,   371,   285,   628,   375,    -1,    32,   371,   285,
     628,    93,   374,    -1,    32,   371,   285,   628,    93,   374,
     375,    -1,   540,    -1,   540,   536,    -1,   234,   290,   224,
      -1,   234,   289,   224,    -1,    32,   293,   628,   297,   224,
     481,   168,   377,    -1,    32,   371,   293,   628,   297,   224,
     481,   168,   377,    -1,   378,    -1,   377,   105,   378,    -1,
     481,    -1,   481,   534,    -1,   481,   439,    -1,   481,   534,
     439,    -1,    32,   301,   302,   628,   297,   285,   628,   116,
     628,   303,   404,    -1,    32,   301,   302,   628,   297,   285,
     628,   222,   116,   628,   303,   291,   304,   481,    -1,    32,
     301,   302,   628,   297,   285,   628,   305,   222,   116,   628,
     303,   404,    -1,    32,   301,   302,   628,   306,   304,   255,
     285,   628,   222,   116,   628,   304,   481,   196,   285,   628,
     222,   116,   628,   304,   481,    -1,   381,    -1,   383,    -1,
     384,    -1,    -1,   383,    -1,   384,    -1,    -1,   403,    -1,
     384,   403,    -1,   385,    -1,   384,   385,    -1,   386,    -1,
     389,    -1,   392,    -1,   393,    -1,   394,    -1,   395,    -1,
     396,    -1,   397,    -1,   399,    -1,   451,    -1,   447,    -1,
     400,    -1,   151,   384,   182,    -1,   151,   182,    -1,   151,
     382,   182,    -1,   151,   382,   182,    -1,   390,   188,    -1,
     390,   105,   391,    -1,   110,   391,    -1,   235,   110,   391,
      -1,   361,   110,   391,    -1,   235,   361,   110,   391,    -1,
     116,   628,    -1,   116,   628,   534,    -1,   116,   628,   140,
     404,    -1,   116,   628,   534,   140,   404,    -1,   116,   628,
     140,   404,   188,    -1,   405,   188,    -1,   238,   240,   404,
     188,    -1,   241,   154,   403,   185,   385,    -1,   236,   239,
     188,    -1,   237,   239,   188,    -1,   415,   398,    -1,   184,
     385,    -1,    48,   154,   403,   185,   195,   385,   124,   385,
      -1,   242,   386,   401,    -1,   402,    -1,   401,   402,    -1,
     243,   572,   386,    -1,   243,   572,   154,   116,   628,   185,
     386,    -1,   243,   572,   154,   116,   628,   105,   116,   628,
     185,   386,    -1,   243,   572,   154,   116,   628,   105,   116,
     628,   105,   116,   628,   185,   386,    -1,   404,    -1,   403,
     105,   404,    -1,   406,    -1,   443,    -1,   450,    -1,   456,
      -1,   568,    -1,   405,    -1,   457,    -1,   440,    -1,   561,
      -1,   562,    -1,   564,    -1,   563,    -1,   565,    -1,   415,
     407,    -1,   184,   404,    -1,    66,   282,    -1,    71,   282,
      -1,   214,    -1,   252,    -1,    55,   252,    -1,   409,   425,
      76,   404,    -1,   409,    76,   404,    -1,    46,   408,   424,
     410,   410,    -1,    46,   408,   424,   410,    -1,    41,   116,
     628,    -1,   416,    -1,   421,    -1,   411,    -1,   413,    -1,
     428,    -1,   433,    -1,   429,    -1,   412,    -1,   413,    -1,
     415,   414,    -1,    46,   116,   417,    -1,   418,    -1,   417,
     105,   116,   418,    -1,   628,   145,   404,    -1,   628,    35,
     125,   145,   404,    -1,   628,   534,   145,   404,    -1,   628,
     534,    35,   125,   145,   404,    -1,   628,   419,   145,   404,
      -1,   628,    35,   125,   419,   145,   404,    -1,   628,   534,
     419,   145,   404,    -1,   628,   534,    35,   125,   419,   145,
     404,    -1,   628,   420,   145,   404,    -1,   628,   534,   420,
     145,   404,    -1,   628,   419,   420,   145,   404,    -1,   628,
     534,   419,   420,   145,   404,    -1,    95,   116,   628,    -1,
     271,   116,   628,    -1,    51,   422,    -1,   423,    -1,   422,
     105,   423,    -1,   116,   628,   140,   404,    -1,   116,   628,
     534,   140,   404,    -1,   420,   140,   404,    -1,   116,   628,
     534,   420,   140,   404,    -1,   116,   628,   145,   404,    -1,
     116,   628,   534,   145,   404,    -1,   426,    -1,   116,   628,
      -1,   116,   628,   426,    -1,   419,    -1,   419,   427,    -1,
     427,    -1,    58,   116,   628,    53,   116,   628,    -1,    53,
     116,   628,    -1,    58,   116,   628,    -1,   209,   404,    -1,
     169,   168,   430,    -1,   431,    -1,   430,   105,   431,    -1,
     116,   628,    -1,   116,   628,   432,    -1,   104,   626,    -1,
     166,   168,   434,    -1,    69,   166,   168,   434,    -1,   435,
      -1,   434,   105,   435,    -1,   404,    -1,   404,   436,    -1,
     437,    -1,   438,    -1,   439,    -1,   437,   438,    -1,   437,
     439,    -1,   438,   439,    -1,   437,   438,   439,    -1,    94,
      -1,   114,    -1,   125,   126,    -1,   125,   127,    -1,   104,
     626,    -1,    67,   116,   441,   186,   404,    -1,   133,   116,
     441,   186,   404,    -1,   442,    -1,   441,   105,   116,   442,
      -1,   628,   145,   404,    -1,   628,   534,   145,   404,    -1,
      72,   154,   403,   185,   444,   111,   184,   404,    -1,   445,
      -1,   444,   445,    -1,   446,   184,   404,    -1,    98,   404,
      -1,   446,    98,   404,    -1,    72,   154,   403,   185,   448,
     111,   184,   385,    -1,   449,    -1,   448,   449,    -1,   446,
     184,   385,    -1,    73,   154,   403,   185,   452,   111,   184,
     404,    -1,    73,   154,   403,   185,   452,   111,   116,   628,
     184,   404,    -1,    73,   154,   403,   185,   454,   111,   184,
     385,    -1,    73,   154,   403,   185,   452,   111,   116,   628,
     184,   385,    -1,   453,    -1,   452,   453,    -1,    98,   535,
     184,   404,    -1,    98,   116,   628,    93,   535,   184,   404,
      -1,   455,    -1,   454,   455,    -1,    98,   535,   184,   385,
      -1,    98,   116,   628,    93,   535,   184,   385,    -1,    48,
     154,   403,   185,   195,   404,   124,   404,    -1,   458,    -1,
     457,   165,   458,    -1,   459,    -1,   458,    91,   459,    -1,
     461,    -1,   461,   475,   461,    -1,   461,   476,   461,    -1,
     461,   130,   461,    -1,   461,   160,   461,    -1,    -1,   461,
     155,   460,   461,    -1,   461,   153,   461,    -1,   461,   141,
     461,    -1,   461,   139,   461,    -1,   463,    -1,   463,   247,
      70,   573,   462,    -1,    -1,   625,    -1,   464,    -1,   464,
     196,   464,    -1,   465,    -1,   464,   174,   465,    -1,   464,
     156,   465,    -1,   466,    -1,   465,   191,   466,    -1,   465,
     115,   466,    -1,   465,   144,   466,    -1,   465,   157,   466,
      -1,   467,    -1,   466,   198,   467,    -1,   466,   207,   467,
      -1,   468,    -1,   467,   148,   468,    -1,   467,   134,   468,
      -1,   469,    -1,   469,    50,   228,   535,    -1,   470,    -1,
     470,   197,    93,   535,    -1,   471,    -1,   471,    99,    93,
     533,    -1,   472,    -1,   472,   100,    93,   533,    -1,   474,
      -1,   473,   474,    -1,   174,    -1,   156,    -1,   473,   174,
      -1,   473,   156,    -1,   477,    -1,   481,    -1,   478,    -1,
     200,    -1,   205,    -1,   204,    -1,   203,    -1,   202,    -1,
     201,    -1,   149,    -1,   177,    -1,   138,    -1,    75,   151,
     383,   182,    -1,    75,   219,   151,   383,   182,    -1,    75,
     218,   151,   383,   182,    -1,    75,    93,   550,   151,   383,
     182,    -1,   479,   151,   182,    -1,   479,   151,   403,   182,
      -1,   480,    -1,   479,   480,    -1,   175,   628,    16,    -1,
     175,    17,    -1,   175,    18,    -1,   482,    -1,   482,   483,
      -1,   190,   483,    -1,   483,    -1,   189,    -1,   484,    -1,
     484,   189,   483,    -1,   484,   190,   483,    -1,   485,    -1,
     494,    -1,   486,    -1,   486,   495,    -1,   489,    -1,   489,
     495,    -1,   487,   491,    -1,   488,    -1,   103,   120,    -1,
     112,   120,    -1,    96,   120,    -1,   187,   120,    -1,   113,
     120,    -1,   137,   120,    -1,   136,   120,    -1,   491,    -1,
      97,   491,    -1,   490,   491,    -1,   118,    -1,   170,   120,
      -1,    89,   120,    -1,   179,   120,    -1,   178,   120,    -1,
      90,   120,    -1,   540,    -1,   492,    -1,   628,    -1,   493,
      -1,   191,    -1,    11,    -1,    19,    -1,   497,    -1,   494,
     495,    -1,   494,   154,   185,    -1,   494,   154,   506,   185,
      -1,   496,    -1,   495,   496,    -1,   152,   403,   183,    -1,
     498,    -1,   500,    -1,   501,    -1,   502,    -1,   505,    -1,
     507,    -1,   503,    -1,   504,    -1,   553,    -1,   387,    -1,
     499,    -1,   552,    -1,   108,    -1,   147,    -1,   122,    -1,
     116,   628,    -1,   154,   185,    -1,   154,   403,   185,    -1,
     117,    -1,   167,   151,   403,   182,    -1,   199,   151,   403,
     182,    -1,   629,   154,   185,    -1,   629,   154,   506,   185,
      -1,   404,    -1,   506,   105,   404,    -1,   508,    -1,   526,
      -1,   509,    -1,   523,    -1,   524,    -1,   155,   628,   513,
     128,    -1,   155,   628,   511,   513,   128,    -1,   155,   628,
     513,   194,   192,   628,   513,   194,    -1,   155,   628,   513,
     194,   510,   192,   628,   513,   194,    -1,   155,   628,   511,
     513,   194,   192,   628,   513,   194,    -1,   155,   628,   511,
     513,   194,   510,   192,   628,   513,   194,    -1,   521,    -1,
     510,   521,    -1,   512,    -1,   511,   512,    -1,    34,   628,
     513,   130,   513,   514,    -1,    -1,    34,    -1,   181,   515,
     181,    -1,    92,   517,    92,    -1,    -1,   516,    -1,   132,
      -1,   519,    -1,   516,   132,    -1,   516,   519,    -1,    -1,
     518,    -1,   131,    -1,   520,    -1,   518,   131,    -1,   518,
     520,    -1,    27,    -1,   522,    -1,     5,    -1,   522,    -1,
     508,    -1,    10,    -1,   525,    -1,   522,    -1,     9,    -1,
     121,    -1,   123,    -1,   151,   383,   182,    -1,   210,    29,
     211,    -1,   210,   211,    -1,   172,   627,   173,    -1,   172,
     627,     8,    -1,   101,     7,    -1,   527,    -1,   528,    -1,
     529,    -1,   530,    -1,   531,    -1,   532,    -1,    42,   151,
     382,   182,    -1,    20,   382,   182,    -1,    44,   151,   403,
     182,   151,   382,   182,    -1,    21,   382,   182,    -1,    96,
     151,   403,   182,   151,   382,   182,    -1,    70,   151,   383,
     182,    -1,    38,   151,   383,   182,    -1,    22,   382,   182,
      -1,    59,   151,   403,   182,   151,   382,   182,    -1,   539,
      -1,   539,   142,    -1,    93,   535,    -1,   537,    -1,   537,
     536,    -1,   208,   154,   185,    -1,   142,    -1,   191,    -1,
     174,    -1,   539,    -1,   540,    -1,   150,   154,   185,    -1,
     556,    -1,   559,    -1,   535,    -1,   538,   105,   535,    -1,
     628,    -1,   542,    -1,   548,    -1,   546,    -1,   549,    -1,
     547,    -1,   545,    -1,   544,    -1,   543,    -1,   541,    -1,
     222,   154,   185,    -1,    43,   154,   185,    -1,    43,   154,
     548,   185,    -1,    43,   154,   549,   185,    -1,    70,   154,
     185,    -1,    38,   154,   185,    -1,    59,   154,   185,    -1,
      59,   154,   627,   185,    -1,    59,   154,    28,   185,    -1,
      96,   154,   185,    -1,    96,   154,   628,   185,    -1,    96,
     154,   628,   105,   550,   185,    -1,    96,   154,   191,   185,
      -1,    96,   154,   191,   105,   550,   185,    -1,    61,   154,
     628,   185,    -1,    44,   154,   185,    -1,    44,   154,   628,
     185,    -1,    44,   154,   628,   105,   550,   185,    -1,    44,
     154,   628,   105,   551,   185,    -1,    44,   154,   191,   185,
      -1,    44,   154,   191,   105,   550,   185,    -1,    44,   154,
     191,   105,   551,   185,    -1,    62,   154,   628,   185,    -1,
     628,    -1,   628,   142,    -1,    28,    -1,   554,    -1,   555,
      -1,   628,   143,   147,    -1,    47,   368,   388,    -1,   557,
      -1,   558,    -1,    47,   154,   191,   185,    -1,    47,   154,
     185,    93,   535,    -1,    47,   154,   538,   185,    93,   535,
      -1,   154,   537,   185,    -1,    32,   217,   218,    -1,    32,
     217,   219,    -1,    32,   217,   220,    -1,   223,   222,   404,
     230,   404,    -1,   223,   222,   404,    93,   229,   230,   404,
      -1,   223,   222,   404,    93,   231,   230,   404,    -1,   223,
     222,   404,   215,   404,    -1,   223,   222,   404,   216,   404,
      -1,   223,   224,   404,   230,   404,    -1,   223,   224,   404,
      93,   229,   230,   404,    -1,   223,   224,   404,    93,   231,
     230,   404,    -1,   223,   224,   404,   215,   404,    -1,   223,
     224,   404,   216,   404,    -1,   221,   222,   404,    -1,   221,
     224,   404,    -1,   226,   222,   404,   234,   404,    -1,   226,
     227,   228,   222,   404,   234,   404,    -1,   225,   222,   404,
      93,   404,    -1,   233,   116,   566,   232,   404,   184,   404,
      -1,   567,    -1,   566,   105,   116,   567,    -1,   628,   140,
     404,    -1,   242,   151,   403,   182,   569,    -1,   570,    -1,
     569,   570,    -1,   243,   572,   571,    -1,   243,   572,   154,
     116,   628,   185,   571,    -1,   243,   572,   154,   116,   628,
     105,   116,   628,   185,   571,    -1,   243,   572,   154,   116,
     628,   105,   116,   628,   105,   116,   628,   185,   571,    -1,
     151,   403,   182,    -1,   492,    -1,   572,   207,   492,    -1,
     576,   574,    -1,    -1,   575,    -1,   594,    -1,   575,   594,
      -1,   577,    -1,   576,   260,   577,    -1,   578,    -1,   577,
     256,   578,    -1,   579,    -1,   578,   258,   145,   579,    -1,
     580,    -1,   257,   580,    -1,   584,   581,   582,    -1,    -1,
     599,    -1,    -1,   583,    -1,   280,   151,   403,   182,    -1,
     588,   585,    -1,   154,   573,   185,    -1,   586,    -1,    -1,
     621,    -1,   479,   151,   587,   182,    -1,    -1,   573,    -1,
     589,   590,    -1,   498,    -1,   151,   403,   182,    -1,    -1,
     591,    -1,   246,   592,    -1,   245,   593,    -1,   268,    -1,
      -1,    77,    -1,    -1,   284,    -1,   595,    -1,   596,    -1,
     597,    -1,   623,    -1,   620,    -1,   167,    -1,   282,   464,
     598,    -1,   251,   622,   598,    -1,   284,    -1,   274,    -1,
     267,    -1,   244,   600,    -1,   599,   244,   600,    -1,   601,
      -1,   602,    -1,   603,    -1,   618,    -1,   604,    -1,   612,
      -1,   605,    -1,   619,    -1,    98,   272,    -1,    98,   261,
      -1,   264,    -1,   279,    -1,   249,   272,    -1,   249,   261,
      -1,    56,   628,    28,    -1,   275,    -1,    54,   275,    -1,
     277,   606,    -1,   277,   154,   606,   607,   185,    -1,    54,
     277,    -1,   609,    -1,   111,    -1,    -1,   105,   608,    -1,
     609,    -1,   608,   105,   609,    -1,    95,    28,   610,   611,
      -1,    -1,   269,    28,    -1,    -1,   622,   263,    -1,   276,
     284,   613,   615,    -1,   276,   284,   111,   615,    -1,    54,
     276,   284,    -1,    95,    28,    -1,   154,   614,   185,    -1,
      28,    -1,   614,   105,    28,    -1,    -1,   616,    -1,   617,
      -1,   616,   617,    -1,   198,   613,    -1,   134,   613,    -1,
     262,    28,    -1,   281,    -1,    54,   281,    -1,    95,   214,
      -1,    95,   252,    -1,   253,   248,    -1,   265,   622,   278,
      -1,   254,   464,    -1,    95,   127,   464,    -1,    95,    52,
     464,    -1,   255,   464,   196,   464,    -1,   270,   624,    -1,
     250,   624,    -1,   273,    -1,   266,    -1,   283,   248,   466,
      -1,    28,    -1,    15,    -1,   628,    -1,   629,    -1,    96,
      -1,    38,    -1,    43,    -1,    44,    -1,   150,    -1,    48,
      -1,   222,    -1,    59,    -1,    61,    -1,    62,    -1,    70,
      -1,    73,    -1,    72,    -1,   208,    -1,   241,    -1,   630,
      -1,    23,    -1,   212,    -1,   125,    -1,    37,    -1,   259,
      -1,    36,    -1,   219,    -1,   218,    -1,   144,    -1,    42,
      -1,   257,    -1,   258,    -1,   272,    -1,   261,    -1,   249,
      -1,   283,    -1,   275,    -1,   277,    -1,   276,    -1,   281,
      -1,   253,    -1,   248,    -1,    77,    -1,   214,    -1,   252,
      -1,    52,    -1,   220,    -1,   233,    -1,   300,    -1,   227,
      -1,   200,    -1,   205,    -1,   204,    -1,   203,    -1,   202,
      -1,   201,    -1,    95,    -1,   109,    -1,   110,    -1,   184,
      -1,    46,    -1,    35,    -1,    66,    -1,    71,    -1,    58,
      -1,    53,    -1,    55,    -1,    76,    -1,    41,    -1,   145,
      -1,    51,    -1,   209,    -1,   168,    -1,   169,    -1,   166,
      -1,    69,    -1,    94,    -1,   114,    -1,   126,    -1,   127,
      -1,   104,    -1,    67,    -1,   133,    -1,   186,    -1,    98,
      -1,    93,    -1,   195,    -1,   124,    -1,   165,    -1,    91,
      -1,    50,    -1,   228,    -1,    99,    -1,   196,    -1,   115,
      -1,   157,    -1,   198,    -1,   148,    -1,   134,    -1,    75,
      -1,   100,    -1,   197,    -1,   149,    -1,   180,    -1,   193,
      -1,   158,    -1,   135,    -1,   129,    -1,   164,    -1,   146,
      -1,   163,    -1,    32,    -1,    39,    -1,    57,    -1,   111,
      -1,    40,    -1,    56,    -1,   213,    -1,    49,    -1,    60,
      -1,    33,    -1,    47,    -1,   271,    -1,   247,    -1,   280,
      -1,   282,    -1,   251,    -1,   265,    -1,   278,    -1,   270,
      -1,   250,    -1,   264,    -1,   279,    -1,   269,    -1,   263,
      -1,   262,    -1,   246,    -1,   245,    -1,   254,    -1,   255,
      -1,   284,    -1,   274,    -1,   273,    -1,   268,    -1,   266,
      -1,   267,    -1,   226,    -1,   232,    -1,   229,    -1,   223,
      -1,   216,    -1,   215,    -1,   217,    -1,   234,    -1,   224,
      -1,   225,    -1,   231,    -1,   221,    -1,   230,    -1,    65,
      -1,    63,    -1,    74,    -1,   167,    -1,   199,    -1,   240,
      -1,   235,    -1,   238,    -1,   239,    -1,   236,    -1,   237,
      -1,   242,    -1,   243,    -1,    45,    -1,   244,    -1,    64,
      -1,   293,    -1,   291,    -1,   292,    -1,   297,    -1,   298,
      -1,   299,    -1,   294,    -1,   295,    -1,   296,    -1,    78,
      -1,    79,    -1,    80,    -1,    81,    -1,    82,    -1,    83,
      -1,    84,    -1,    85,    -1,    86,    -1,    87,    -1,    88,
      -1,   285,    -1,   286,    -1,   287,    -1,   288,    -1,   289,
      -1,   290,    -1,   301,    -1,   302,    -1,   303,    -1,   304,
      -1,   305,    -1,   306,    -1,   307,    -1,    89,    -1,   103,
      -1,   112,    -1,   170,    -1,   178,    -1,   187,    -1,   136,
      -1,    90,    -1,   113,    -1,   137,    -1,   179,    -1,   626,
     119,   627,    -1,    24,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  xquery_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    11,    13,    16,    18,    21,
      26,    33,    37,    41,    47,    49,    53,    57,    63,    69,
      71,    75,    79,    85,    92,    94,    98,   102,   104,   106,
     108,   110,   112,   114,   116,   118,   120,   122,   124,   126,
     128,   132,   136,   141,   145,   149,   153,   157,   161,   167,
     173,   179,   185,   191,   197,   199,   201,   205,   209,   214,
     220,   227,   229,   233,   237,   241,   245,   252,   258,   267,
     273,   279,   285,   287,   291,   295,   297,   299,   301,   303,
     305,   307,   309,   311,   316,   321,   323,   326,   330,   332,
     334,   336,   338,   340,   342,   344,   346,   348,   350,   355,
     359,   364,   368,   370,   372,   374,   377,   380,   385,   389,
     395,   399,   404,   409,   415,   417,   420,   422,   427,   429,
     434,   436,   440,   443,   447,   449,   451,   456,   461,   467,
     473,   476,   480,   485,   491,   493,   497,   500,   504,   506,
     509,   511,   513,   515,   517,   519,   521,   524,   527,   530,
     533,   535,   538,   541,   544,   548,   553,   559,   566,   571,
     577,   584,   592,   594,   597,   601,   605,   614,   624,   626,
     630,   632,   635,   638,   642,   654,   669,   683,   706,   708,
     710,   712,   713,   715,   717,   718,   720,   723,   725,   728,
     730,   732,   734,   736,   738,   740,   742,   744,   746,   748,
     750,   752,   756,   759,   763,   767,   770,   774,   777,   781,
     785,   790,   793,   797,   802,   808,   814,   817,   822,   828,
     832,   836,   839,   842,   851,   855,   857,   860,   864,   872,
     883,   897,   899,   903,   905,   907,   909,   911,   913,   915,
     917,   919,   921,   923,   925,   927,   929,   932,   935,   938,
     941,   943,   945,   948,   953,   957,   963,   968,   972,   974,
     976,   978,   980,   982,   984,   986,   988,   990,   993,   997,
     999,  1004,  1008,  1014,  1019,  1026,  1031,  1038,  1044,  1052,
    1057,  1063,  1069,  1076,  1080,  1084,  1087,  1089,  1093,  1098,
    1104,  1108,  1115,  1120,  1126,  1128,  1131,  1135,  1137,  1140,
    1142,  1149,  1153,  1157,  1160,  1164,  1166,  1170,  1173,  1177,
    1180,  1184,  1189,  1191,  1195,  1197,  1200,  1202,  1204,  1206,
    1209,  1212,  1215,  1219,  1221,  1223,  1226,  1229,  1232,  1238,
    1244,  1246,  1251,  1255,  1260,  1269,  1271,  1274,  1278,  1281,
    1285,  1294,  1296,  1299,  1303,  1312,  1323,  1332,  1343,  1345,
    1348,  1353,  1361,  1363,  1366,  1371,  1379,  1388,  1390,  1394,
    1396,  1400,  1402,  1406,  1410,  1414,  1418,  1419,  1424,  1428,
    1432,  1436,  1438,  1444,  1445,  1447,  1449,  1453,  1455,  1459,
    1463,  1465,  1469,  1473,  1477,  1481,  1483,  1487,  1491,  1493,
    1497,  1501,  1503,  1508,  1510,  1515,  1517,  1522,  1524,  1529,
    1531,  1534,  1536,  1538,  1541,  1544,  1546,  1548,  1550,  1552,
    1554,  1556,  1558,  1560,  1562,  1564,  1566,  1568,  1573,  1579,
    1585,  1592,  1596,  1601,  1603,  1606,  1610,  1613,  1616,  1618,
    1621,  1624,  1626,  1628,  1630,  1634,  1638,  1640,  1642,  1644,
    1647,  1649,  1652,  1655,  1657,  1660,  1663,  1666,  1669,  1672,
    1675,  1678,  1680,  1683,  1686,  1688,  1691,  1694,  1697,  1700,
    1703,  1705,  1707,  1709,  1711,  1713,  1715,  1717,  1719,  1722,
    1726,  1731,  1733,  1736,  1740,  1742,  1744,  1746,  1748,  1750,
    1752,  1754,  1756,  1758,  1760,  1762,  1764,  1766,  1768,  1770,
    1773,  1776,  1780,  1782,  1787,  1792,  1796,  1801,  1803,  1807,
    1809,  1811,  1813,  1815,  1817,  1822,  1828,  1837,  1847,  1857,
    1868,  1870,  1873,  1875,  1878,  1885,  1886,  1888,  1892,  1896,
    1897,  1899,  1901,  1903,  1906,  1909,  1910,  1912,  1914,  1916,
    1919,  1922,  1924,  1926,  1928,  1930,  1932,  1934,  1936,  1938,
    1940,  1942,  1944,  1948,  1952,  1955,  1959,  1963,  1966,  1968,
    1970,  1972,  1974,  1976,  1978,  1983,  1987,  1995,  1999,  2007,
    2012,  2017,  2021,  2029,  2031,  2034,  2037,  2039,  2042,  2046,
    2048,  2050,  2052,  2054,  2056,  2060,  2062,  2064,  2066,  2070,
    2072,  2074,  2076,  2078,  2080,  2082,  2084,  2086,  2088,  2090,
    2094,  2098,  2103,  2108,  2112,  2116,  2120,  2125,  2130,  2134,
    2139,  2146,  2151,  2158,  2163,  2167,  2172,  2179,  2186,  2191,
    2198,  2205,  2210,  2212,  2215,  2217,  2219,  2221,  2225,  2229,
    2231,  2233,  2238,  2244,  2251,  2255,  2259,  2263,  2267,  2273,
    2281,  2289,  2295,  2301,  2307,  2315,  2323,  2329,  2335,  2339,
    2343,  2349,  2357,  2363,  2371,  2373,  2378,  2382,  2388,  2390,
    2393,  2397,  2405,  2416,  2430,  2434,  2436,  2440,  2443,  2444,
    2446,  2448,  2451,  2453,  2457,  2459,  2463,  2465,  2470,  2472,
    2475,  2479,  2480,  2482,  2483,  2485,  2490,  2493,  2497,  2499,
    2500,  2502,  2507,  2508,  2510,  2513,  2515,  2519,  2520,  2522,
    2525,  2528,  2530,  2531,  2533,  2534,  2536,  2538,  2540,  2542,
    2544,  2546,  2548,  2552,  2556,  2558,  2560,  2562,  2565,  2569,
    2571,  2573,  2575,  2577,  2579,  2581,  2583,  2585,  2588,  2591,
    2593,  2595,  2598,  2601,  2605,  2607,  2610,  2613,  2619,  2622,
    2624,  2626,  2627,  2630,  2632,  2636,  2641,  2642,  2645,  2646,
    2649,  2654,  2659,  2663,  2666,  2670,  2672,  2676,  2677,  2679,
    2681,  2684,  2687,  2690,  2693,  2695,  2698,  2701,  2704,  2707,
    2711,  2714,  2718,  2722,  2727,  2730,  2733,  2735,  2737,  2741,
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
    2983,  2985,  2987,  2989,  2991,  2993,  2995,  2997,  2999,  3001,
    3003,  3005,  3007,  3009,  3011,  3013,  3015,  3017,  3019,  3021,
    3023,  3025,  3027,  3029,  3031,  3033,  3035,  3037,  3039,  3041,
    3043,  3045,  3047,  3049,  3051,  3053,  3055,  3057,  3059,  3061,
    3063,  3065,  3067,  3069,  3071,  3073,  3075,  3077,  3079,  3081,
    3083,  3085,  3087,  3089,  3091,  3093,  3095,  3097,  3099,  3101,
    3103,  3105,  3107,  3109,  3111,  3113,  3115,  3117,  3119,  3121,
    3123,  3125,  3127,  3129,  3131,  3133,  3135,  3137,  3139,  3141,
    3143,  3145,  3147,  3149,  3151,  3153,  3155,  3157,  3159,  3161,
    3163,  3165,  3167,  3169,  3171,  3173,  3175,  3177,  3179,  3183
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,  1033,  1033,  1034,  1043,  1052,  1058,  1066,  1072,  1083,
    1088,  1096,  1103,  1110,  1119,  1126,  1134,  1142,  1150,  1161,
    1166,  1173,  1180,  1192,  1202,  1209,  1216,  1228,  1229,  1230,
    1231,  1232,  1237,  1238,  1239,  1240,  1241,  1242,  1243,  1246,
    1251,  1256,  1264,  1272,  1280,  1285,  1293,  1298,  1306,  1311,
    1319,  1326,  1333,  1340,  1350,  1352,  1355,  1365,  1370,  1378,
    1386,  1397,  1404,  1415,  1420,  1428,  1435,  1442,  1451,  1464,
    1472,  1479,  1489,  1496,  1503,  1514,  1515,  1516,  1517,  1518,
    1519,  1520,  1521,  1526,  1532,  1541,  1548,  1558,  1568,  1569,
    1570,  1571,  1572,  1573,  1574,  1575,  1576,  1577,  1582,  1590,
    1598,  1606,  1613,  1621,  1628,  1633,  1641,  1649,  1664,  1679,
    1697,  1702,  1710,  1718,  1729,  1734,  1743,  1748,  1755,  1760,
    1770,  1775,  1784,  1790,  1803,  1808,  1816,  1827,  1842,  1854,
    1869,  1874,  1879,  1884,  1892,  1899,  1910,  1915,  1925,  1931,
    1941,  1945,  1951,  1955,  1959,  1963,  1969,  1975,  1981,  1987,
    1993,  1997,  2003,  2009,  2016,  2024,  2032,  2040,  2048,  2060,
    2074,  2088,  2105,  2109,  2118,  2122,  2129,  2137,  2155,  2161,
    2170,  2175,  2182,  2189,  2200,  2210,  2220,  2230,  2248,  2268,
    2273,  2278,  2285,  2290,  2295,  2302,  2307,  2319,  2326,  2338,
    2339,  2340,  2341,  2342,  2343,  2344,  2346,  2347,  2348,  2349,
    2350,  2355,  2360,  2368,  2385,  2393,  2401,  2408,  2415,  2422,
    2429,  2439,  2451,  2464,  2476,  2492,  2500,  2508,  2516,  2531,
    2536,  2544,  2558,  2575,  2600,  2608,  2615,  2626,  2632,  2638,
    2649,  2664,  2669,  2684,  2685,  2686,  2687,  2688,  2689,  2694,
    2695,  2698,  2699,  2700,  2701,  2702,  2707,  2721,  2729,  2734,
    2742,  2747,  2752,  2760,  2769,  2781,  2791,  2804,  2812,  2813,
    2814,  2819,  2820,  2821,  2822,  2823,  2828,  2835,  2845,  2853,
    2860,  2870,  2880,  2890,  2900,  2910,  2920,  2930,  2940,  2951,
    2960,  2970,  2980,  2996,  3005,  3014,  3022,  3028,  3040,  3048,
    3058,  3066,  3078,  3084,  3095,  3097,  3101,  3109,  3113,  3118,
    3122,  3126,  3130,  3140,  3148,  3155,  3161,  3172,  3176,  3185,
    3193,  3199,  3209,  3215,  3225,  3229,  3239,  3245,  3251,  3257,
    3266,  3275,  3284,  3297,  3301,  3309,  3315,  3325,  3333,  3342,
    3355,  3362,  3374,  3378,  3390,  3397,  3403,  3412,  3419,  3425,
    3436,  3443,  3449,  3458,  3467,  3474,  3485,  3492,  3504,  3510,
    3522,  3528,  3539,  3545,  3556,  3562,  3573,  3582,  3586,  3595,
    3599,  3607,  3611,  3621,  3628,  3637,  3647,  3646,  3660,  3669,
    3678,  3691,  3695,  3708,  3711,  3718,  3722,  3731,  3735,  3739,
    3748,  3752,  3758,  3764,  3770,  3781,  3785,  3789,  3797,  3801,
    3807,  3817,  3821,  3831,  3835,  3845,  3849,  3859,  3863,  3873,
    3877,  3885,  3889,  3893,  3897,  3907,  3911,  3915,  3923,  3927,
    3931,  3935,  3939,  3943,  3951,  3955,  3959,  3967,  3971,  3975,
    3979,  3990,  3996,  4006,  4012,  4022,  4026,  4030,  4068,  4072,
    4082,  4092,  4105,  4114,  4124,  4128,  4137,  4141,  4150,  4156,
    4164,  4170,  4182,  4188,  4198,  4202,  4206,  4210,  4214,  4220,
    4226,  4234,  4238,  4246,  4250,  4261,  4265,  4269,  4275,  4279,
    4293,  4297,  4305,  4309,  4319,  4323,  4327,  4336,  4340,  4344,
    4348,  4356,  4362,  4372,  4380,  4384,  4388,  4392,  4396,  4400,
    4404,  4408,  4412,  4422,  4430,  4434,  4442,  4449,  4456,  4467,
    4475,  4479,  4487,  4495,  4503,  4557,  4561,  4574,  4580,  4590,
    4594,  4602,  4606,  4610,  4618,  4628,  4638,  4648,  4658,  4668,
    4683,  4689,  4700,  4706,  4717,  4728,  4730,  4734,  4739,  4749,
    4752,  4759,  4765,  4771,  4779,  4792,  4795,  4802,  4808,  4814,
    4821,  4832,  4836,  4846,  4850,  4860,  4864,  4868,  4873,  4882,
    4888,  4894,  4900,  4908,  4913,  4921,  4926,  4934,  4942,  4947,
    4952,  4957,  4962,  4967,  4976,  4984,  4988,  5005,  5009,  5017,
    5025,  5033,  5037,  5045,  5051,  5061,  5069,  5073,  5077,  5112,
    5118,  5124,  5134,  5138,  5142,  5146,  5150,  5157,  5163,  5173,
    5181,  5185,  5189,  5193,  5197,  5201,  5205,  5209,  5213,  5221,
    5229,  5233,  5237,  5247,  5255,  5263,  5267,  5271,  5279,  5283,
    5289,  5295,  5299,  5309,  5317,  5321,  5327,  5336,  5345,  5351,
    5357,  5367,  5384,  5391,  5406,  5442,  5446,  5454,  5462,  5474,
    5478,  5486,  5494,  5498,  5509,  5526,  5532,  5538,  5548,  5552,
    5558,  5564,  5568,  5574,  5578,  5584,  5590,  5597,  5607,  5612,
    5620,  5626,  5636,  5658,  5667,  5673,  5686,  5700,  5707,  5713,
    5723,  5728,  5733,  5743,  5757,  5765,  5771,  5789,  5798,  5801,
    5808,  5813,  5821,  5825,  5832,  5836,  5843,  5847,  5854,  5858,
    5867,  5880,  5883,  5891,  5894,  5902,  5910,  5918,  5922,  5930,
    5933,  5941,  5953,  5956,  5964,  5976,  5982,  5992,  5995,  6003,
    6007,  6011,  6019,  6022,  6030,  6033,  6041,  6045,  6049,  6053,
    6057,  6065,  6073,  6085,  6097,  6101,  6105,  6113,  6119,  6129,
    6133,  6137,  6141,  6145,  6149,  6153,  6157,  6165,  6169,  6173,
    6177,  6185,  6191,  6201,  6211,  6215,  6223,  6233,  6244,  6251,
    6255,  6263,  6266,  6273,  6278,  6287,  6297,  6300,  6308,  6311,
    6319,  6328,  6335,  6345,  6349,  6356,  6362,  6372,  6375,  6382,
    6387,  6399,  6407,  6419,  6427,  6431,  6439,  6443,  6447,  6455,
    6463,  6467,  6471,  6475,  6483,  6491,  6503,  6507,  6515,  6528,
    6532,  6533,  6546,  6547,  6548,  6549,  6550,  6551,  6552,  6553,
    6554,  6555,  6556,  6557,  6558,  6559,  6560,  6561,  6565,  6566,
    6567,  6568,  6569,  6570,  6571,  6572,  6573,  6574,  6575,  6576,
    6577,  6578,  6579,  6580,  6581,  6582,  6583,  6584,  6585,  6586,
    6587,  6588,  6589,  6590,  6591,  6592,  6593,  6594,  6595,  6596,
    6597,  6598,  6599,  6600,  6601,  6602,  6603,  6604,  6605,  6606,
    6607,  6608,  6609,  6610,  6611,  6612,  6613,  6614,  6615,  6616,
    6617,  6618,  6619,  6620,  6621,  6622,  6623,  6624,  6625,  6626,
    6627,  6628,  6629,  6630,  6631,  6632,  6633,  6634,  6635,  6636,
    6637,  6638,  6639,  6640,  6641,  6642,  6643,  6644,  6645,  6646,
    6647,  6648,  6649,  6650,  6651,  6652,  6653,  6654,  6655,  6656,
    6657,  6658,  6659,  6660,  6661,  6662,  6663,  6664,  6665,  6666,
    6667,  6668,  6669,  6670,  6671,  6672,  6673,  6674,  6675,  6676,
    6677,  6678,  6679,  6680,  6681,  6682,  6683,  6684,  6685,  6686,
    6687,  6688,  6689,  6690,  6691,  6692,  6693,  6694,  6695,  6696,
    6697,  6698,  6699,  6700,  6701,  6702,  6703,  6704,  6705,  6706,
    6707,  6708,  6709,  6710,  6711,  6712,  6713,  6714,  6715,  6716,
    6717,  6718,  6719,  6720,  6721,  6722,  6723,  6724,  6725,  6726,
    6727,  6728,  6729,  6730,  6731,  6732,  6733,  6734,  6735,  6736,
    6737,  6738,  6739,  6740,  6741,  6742,  6743,  6744,  6745,  6746,
    6747,  6748,  6749,  6750,  6751,  6752,  6753,  6754,  6755,  6756,
    6757,  6758,  6759,  6760,  6761,  6762,  6763,  6764,  6769,  6776
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
     315,   316,   317,   318,   319,   320,   321
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 13189;
  const int xquery_parser::yynnts_ = 309;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 587;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 322;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 576;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba

/* Line 1054 of lalr1.cc  */
#line 16512 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6780 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"


namespace zorba {

namespace parser {

const char *the_tumbling = "tumbling", *the_sliding = "sliding",
  *the_start = "start", *the_end = "end", *the_only_end = "only end",
  *the_declare = "declare", *the_create = "create";

} // namespace parser

/*
 *  The error member function registers the errors to the driver.
 */
void xquery_parser::error(zorba::xquery_parser::location_type const& loc, string const& msg)
{
  if (driver.parserError != NULL)
  {
    driver.set_expr(new ParseErrorNode(driver.parserError->loc, driver.parserError->err_code, driver.parserError->msg));
  }
  else
  {
    // remove the double quoting "''" from every token description
    string message = msg;
    int pos;
    while ((pos = message.find("\"'")) != -1 || (pos = message.find("'\"")) != -1)
      message.replace(pos, 2, "\"");
    driver.set_expr(new ParseErrorNode(driver.createQueryLoc(loc), err::XPST0003, message));
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

