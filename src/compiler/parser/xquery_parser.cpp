
/* A Bison parser, made by GNU Bison 2.4.  */

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
#line 67 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"


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



/* Line 311 of lalr1.cc  */
#line 86 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 856 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 317 of lalr1.cc  */
#line 956 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"

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
#line 157 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"

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
#line 226 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
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

/* Line 480 of lalr1.cc  */
#line 854 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 333 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 118: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 342 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 143: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 351 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 360 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 369 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 378 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 387 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 396 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 405 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 414 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 423 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 432 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 441 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 450 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 459 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 468 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 477 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 486 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 495 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 504 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 513 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 522 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 531 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 540 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 549 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 558 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 567 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 576 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 585 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 594 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 603 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 612 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 621 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 630 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 639 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 648 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "DeclPropertyList" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 657 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "DeclProperty" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 666 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 675 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "NodeModifier" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 684 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 693 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 702 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 711 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 720 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 729 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 738 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 747 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "Block" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 756 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "BlockDecls" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 765 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "BlockVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 774 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "BlockVarDecl" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 783 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "AssignExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 792 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "ExitExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 801 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "WhileExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 810 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 819 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 828 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 837 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 846 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "FunctionDeclSequential" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 855 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 864 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 873 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 882 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "EnclosedExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 891 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 900 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 909 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 918 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "ApplyExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 927 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "ConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 936 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 945 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 954 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 963 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 972 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 981 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 990 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 999 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1008 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1017 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1026 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1035 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1044 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1053 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1062 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1071 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "EvalVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1080 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1089 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1098 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1107 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1116 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1125 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "EvalVarDecl" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1134 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1143 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1152 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1161 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1170 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1179 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1188 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1197 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1206 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1215 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1224 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1233 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1242 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1251 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1260 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1269 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1278 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1287 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1296 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1305 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1314 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1323 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1332 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1341 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1350 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1359 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1368 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1377 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1386 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1395 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1404 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1413 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1422 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1431 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1440 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1449 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1458 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1467 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1476 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1485 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1494 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1503 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1512 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1521 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1530 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1539 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1548 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1557 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1566 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1575 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1584 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1593 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1602 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1611 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1620 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1629 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1638 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1647 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1656 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1665 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1674 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1683 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1692 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1701 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1710 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1719 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1728 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1737 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1746 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1755 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1764 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1773 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1782 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1791 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1800 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1809 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1818 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1827 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1836 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1845 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1854 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1863 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1872 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1881 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1890 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1899 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1908 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1917 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1926 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1935 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1944 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1953 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1962 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1971 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1980 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1989 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1998 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2007 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2016 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2025 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2034 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2043 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2052 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2061 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2070 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2079 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2088 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2097 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2106 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2115 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2124 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2133 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2142 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2151 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2160 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2169 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2178 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2187 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 868 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2196 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2205 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2214 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2223 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2232 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2241 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2250 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2259 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2268 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2277 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2286 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2295 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "EvalExpr" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2304 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2313 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2322 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2331 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2340 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2349 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2358 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2367 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2376 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2385 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2394 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2403 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2412 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2421 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2430 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2439 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2448 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2457 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2466 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2475 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2484 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2493 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2502 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2511 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2520 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2529 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2538 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2547 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2556 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2565 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2574 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2583 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2592 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2601 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2610 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2619 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2628 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2637 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2646 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2655 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2664 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
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
#line 127 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename.getStore()->str());
}

/* Line 553 of lalr1.cc  */
#line 2749 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"

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
#line 1015 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 1019 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.node) = NULL; }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 1020 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.node) = NULL; }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 1021 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.node) = NULL; }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 1022 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.node) = NULL; }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 1027 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1041 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 1046 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            MainModule *mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
            mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 1053 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1058 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            LibraryModule *lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
            lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1069 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            std::string encoding = "utf-8";
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), encoding );
        }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 1074 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
        }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1082 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);
          (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
        }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1087 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));
          (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
        }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1092 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)), static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));
          (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
        }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1097 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
        }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1105 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
        }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1109 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
        }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1114 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
        }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 1119 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)), static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
        }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 1128 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
            dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
        }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 1137 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
            sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = sdl;
        }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 1143 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 1152 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
            vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = vdl;
        }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 1158 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1189 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
          delete (yysemantic_stack_[(4) - (4)].vstrpair);
        }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1194 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
          delete (yysemantic_stack_[(4) - (4)].vstrpair);
        }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1203 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.vstrpair) = new vector<string_pair_t>();
          (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
          delete (yysemantic_stack_[(1) - (1)].strpair);
        }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1209 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
          delete (yysemantic_stack_[(2) - (2)].strpair);
          (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
        }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1218 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
            (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval() );
            delete sl;
        }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1226 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1227 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1228 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1229 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1230 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1231 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1232 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 1233 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 1234 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 1235 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1261 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
        }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1269 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::preserve_space
            );
        }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1275 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::strip_space
            );
        }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1285 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_element_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1291 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_function_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1301 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OptionDecl(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval))
            );
        }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1311 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1319 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::ordered
            );
        }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1325 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::unordered
            );
        }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1336 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_greatest);
        }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1341 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_least);
        }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1351 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1357 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 1363 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 1369 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 1386 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
        }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1394 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1402 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
        }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1406 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1415 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1424 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1437 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            URILiteralList *ull = new URILiteralList( LOC((yyloc)));
            ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.node) = ull;
        }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1443 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
                ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1454 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1458 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
        }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1466 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1471 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1476 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1483 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(8) - (4)].sval)),
                            SYMTAB((yysemantic_stack_[(8) - (6)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1496 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
        }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1503 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
            d->type = (yysemantic_stack_[(3) - (2)].node);
            (yyval.node) = d;
        }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1509 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1516 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
            d->ext = false;
            (yyval.node) = d;
        }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1522 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), NULL );
        }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1526 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1533 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1544 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1548 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1556 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(5) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(5) - (5)].expr));
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1562 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL, true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1568 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(6) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(6) - (6)].expr), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1577 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            DeclPropertyList *dpl = new DeclPropertyList( LOC((yyloc)) );
            dpl->addProperty(dynamic_cast<DeclProperty*>((yysemantic_stack_[(1) - (1)].node)));
            (yyval.node) = dpl;
        }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 1583 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
        DeclPropertyList *dpl = dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(2) - (1)].node));
        dpl->addProperty( static_cast<DeclProperty*>((yysemantic_stack_[(2) - (2)].node)) );
        (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 1592 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_const );
        }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 1596 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_append_only
            );
        }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1602 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_queue );
        }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1606 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_mutable );
        }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1610 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_ordered );
        }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1614 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_unordered
            );
        }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1620 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_equality
            );
        }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1626 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_range
            );
        }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1632 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_equality
            );
        }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1638 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_range
            );
        }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1644 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_unique );
        }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1648 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_non_unique
            );
        }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1654 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_automatic
            );
        }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1660 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_manual );
        }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1667 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL,
                              NULL);
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1675 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              NULL,
                              static_cast<NodeModifier*>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1683 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              NULL,
                              NULL,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1691 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                              NULL,
                              static_cast<NodeModifier*>((yysemantic_stack_[(6) - (6)].node)),
                              static_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)));
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1699 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1711 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1725 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1739 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1756 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1760 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1769 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1773 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1780 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                             (yysemantic_stack_[(8) - (6)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                             NULL);
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1788 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1806 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1812 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1820 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1825 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1832 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1839 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1850 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1860 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1870 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1881 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1896 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_preserve
            );
        }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1902 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_strip
            );
        }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1913 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL );
        }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1917 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1921 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)) );
        }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1925 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1932 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
        }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1939 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1958 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1967 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 1974 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
            vfo->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = vfo;
        }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 1980 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = new VFO_DeclList( LOC((yyloc)) );
            vfo->push_back((yysemantic_stack_[(2) - (2)].node));
            (yyval.node) = vfo;
        }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 1990 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(1) - (1)].varnametype)));
      VarDecl* vd = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL);
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 1997 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(3) - (1)].varnametype)));
      VarDecl* vd = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(3) - (3)].expr));
      vd->set_global(false);
      (yyval.node) = vd;
        }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 2008 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 2015 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExitExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 2022 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2034 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::BREAK );
        }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 2038 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
        }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 2045 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            dynamic_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 2050 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2065 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2082 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 2086 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 2090 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 2094 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 2102 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2113 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2128 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2139 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2154 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2165 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2181 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            ParamList *pl = new ParamList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2187 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
                pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2199 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 2203 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 2214 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EnclosedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 2221 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 2229 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QueryBody( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 2244 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 2248 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2262 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new BlockBody( LOC((yyloc)) );
        }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 2266 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            BlockBody *bb = dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (1)].expr));
            bb->add( (yysemantic_stack_[(3) - (2)].expr) );
            (yyval.expr) = bb;
        }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 2275 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 2279 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2320 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2335 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 2342 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_sliding;
        }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 2346 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_tumbling;
        }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 2353 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_start;
        }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 2357 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_end;
        }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 2361 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_only_end;
        }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 2368 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)),
                dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr),
                (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 2376 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr),
                (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 2387 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2397 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2410 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 2432 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 2438 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 2447 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = NULL;
        }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 2451 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_ofor;
        }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 2459 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForClause(
                LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL
            );
        }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 2469 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
            vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vdl;
        }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 2475 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 2487 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 2491 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                         NULL,NULL,
                         (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 2499 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2508 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2518 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 2526 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2535 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2544 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2559 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2568 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 2578 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 2586 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2592 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2601 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 2607 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            if ( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 2619 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2627 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 2637 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                           (yysemantic_stack_[(4) - (4)].expr));
     }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 2645 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                           (yysemantic_stack_[(5) - (5)].expr));
     }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 2657 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 2663 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2676 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2680 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2688 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2692 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2701 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2705 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2709 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2717 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)),
                           NULL, NULL,
                           new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr))),
                           VarGetsDecl::eval_var);
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2731 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2739 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2746 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2752 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2763 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2767 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2776 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2784 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2790 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 2800 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2806 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2816 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2820 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2830 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2836 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2842 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2848 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2857 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2866 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2875 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2888 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2892 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 2900 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 2906 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 2916 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 2924 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2933 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2946 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 2953 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 2965 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 2969 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 2981 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 2988 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 2994 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3003 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3010 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3016 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3028 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3035 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3048 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3054 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3066 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3072 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3084 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3093 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3097 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3106 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3110 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3118 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3122 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 3132 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3139 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 3148 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 3157 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3162 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 3171 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 3180 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 3189 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 3202 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3206 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 3218 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3222 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3229 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3233 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3242 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3246 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3250 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3259 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3263 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3269 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3275 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3281 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3292 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3296 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3300 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3308 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3312 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3318 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3328 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3332 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3342 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3346 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3356 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3360 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3370 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3374 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3384 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3388 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3396 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3400 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3404 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3408 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3418 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3422 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3426 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3434 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3438 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3442 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3446 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3450 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3454 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3462 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3466 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3470 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3478 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3482 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3486 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3490 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3501 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3507 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3517 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3523 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3533 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3537 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3575 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3579 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3585 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3591 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            RelativePathExpr *rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = !rpe ?
                (yysemantic_stack_[(1) - (1)].expr) : new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3602 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NULL;
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3610 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 3621 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3627 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3637 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3641 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3649 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3655 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3663 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3669 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3681 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3687 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3697 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3701 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3705 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3709 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3713 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3719 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3725 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3748 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3752 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3760 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3764 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3775 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3779 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3783 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3789 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3793 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3807 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3811 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3819 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3823 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3833 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all);
    }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3837 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem);
    }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3841 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix);
    }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3850 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3854 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FilterExpr(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3860 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 3864 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
        }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 3872 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 3878 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 3888 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 3896 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 3900 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 3904 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 3908 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 3912 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 3916 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 3920 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 3924 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 3928 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 3936 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 3940 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 3948 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 3955 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 3962 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 3973 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 3981 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 3985 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 3993 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4001 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4009 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4063 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4067 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4080 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4086 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4096 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4100 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4108 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4112 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4116 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4124 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 4134 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 4144 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 4154 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 4164 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 4174 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 4189 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4195 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4206 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4212 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4223 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4240 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4245 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4254 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4258 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4265 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back(
                new QuoteAttrValueContent( LOC((yyloc)),std::string("\"") )
            );
            (yyval.node) = qacl;
        }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4273 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4279 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 4289 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4301 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4305 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4312 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4318 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4324 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4331 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4342 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4346 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4356 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4360 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4370 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4374 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4378 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4383 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4392 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4398 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4404 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4410 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4420 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4424 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4436 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4440 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4452 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4464 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4468 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4472 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4476 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4480 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4484 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4492 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4500 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (1)].sval))), NULL);
        }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4504 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4508 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4512 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4529 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (1)].sval))), NULL );
        }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4533 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4537 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4541 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4549 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4557 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4565 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (1)].sval)), NULL );
        }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4569 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4573 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4577 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4585 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4591 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4601 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4609 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4613 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4617 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4652 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4658 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4664 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4674 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4678 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4682 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4686 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4690 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4697 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4703 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4713 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4721 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4725 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4729 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4733 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4737 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4741 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4745 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4749 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4753 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4761 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4769 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4773 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 4777 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 4787 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 4795 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 4803 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 4807 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 4811 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 4819 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 4823 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 4829 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 4835 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 4839 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 4849 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 4857 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 4861 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 4867 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 4876 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 4885 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 4891 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 4897 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 4907 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 4924 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 4931 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 4946 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 4982 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 4986 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 4995 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
        }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5004 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new InlineFunction(LOC ((yyloc)), &*(yysemantic_stack_[(3) - (2)].fnsig)->param, &*(yysemantic_stack_[(3) - (2)].fnsig)->ret, dynamic_cast<EnclosedExpr *>((yysemantic_stack_[(3) - (3)].expr)));
          delete (yysemantic_stack_[(3) - (2)].fnsig);
        }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5014 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5018 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5027 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
        }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5036 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5040 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5051 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5068 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5074 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5080 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5090 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5094 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5100 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5106 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5110 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5116 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5120 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5126 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5132 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5139 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5149 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5154 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5162 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5168 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5178 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5200 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5209 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5215 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5228 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5242 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5249 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5255 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5265 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5270 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5276 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 5286 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 5299 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5305 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5322 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new EvalExpr(LOC((yyloc)), dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)), (yysemantic_stack_[(7) - (6)].expr));
        }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5326 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new EvalExpr( LOC((yyloc)), new VarGetsDeclList( LOC((yyloc)) ), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5341 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5349 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5353 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5360 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5365 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5373 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5377 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5384 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5388 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5395 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5399 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5406 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5410 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5419 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 5431 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5435 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5442 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5446 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5454 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5462 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5470 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5474 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5481 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5485 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5493 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5504 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5508 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5516 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5528 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5534 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5543 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5547 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5555 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5559 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5563 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5570 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5574 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5581 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5585 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5593 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5597 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5601 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5605 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5609 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5617 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5625 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5637 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5649 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5653 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5657 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5665 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5671 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5681 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5685 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5689 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5693 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5697 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5701 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5705 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5709 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5717 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5721 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5725 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5729 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5737 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5743 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5753 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5763 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5767 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5775 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 5785 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 5796 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5803 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5807 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5814 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5818 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(1) - (1)].thesaurus_id_list);
        }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5825 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5830 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5839 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5848 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5852 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5859 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5863 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5871 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 5880 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5887 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 5897 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 5901 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 5908 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 5914 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 5923 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 5927 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 5934 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 5939 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 5951 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 5959 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 5971 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 5979 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 5983 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 5991 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 5995 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 5999 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 6007 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 6015 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 6019 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 6023 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 6027 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 6035 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 6043 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 6055 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 6059 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 6067 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 6085 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
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

  case 733:

/* Line 678 of lalr1.cc  */
#line 6098 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 6099 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 6100 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 6101 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 6102 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 6103 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 6104 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 6105 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 6106 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 6107 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 6108 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 6109 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 6110 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 6111 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 6112 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 6116 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 6117 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 6118 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 6119 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 6120 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 6121 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 6122 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 6123 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 6124 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 6125 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 6126 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 6127 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 6128 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 6129 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 6130 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 6131 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 6132 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 6133 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 6134 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 6135 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 6136 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 6137 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 6138 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 6139 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 6140 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 6141 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 6142 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 6143 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 6144 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 6145 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 6146 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 6147 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 6148 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 6149 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 6150 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 6151 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 6152 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 6153 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 6154 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 6155 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 6156 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 6157 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("outer"))); }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 6158 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 6159 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 6160 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 6161 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 6162 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 6163 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 6164 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 6165 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 6166 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 6167 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 6168 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 6169 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 6170 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 6171 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 6172 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 6173 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 6174 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 6175 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 6176 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 6177 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 6178 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 6179 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 6180 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 6181 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 6182 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 6183 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 6184 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 6185 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 6186 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 6187 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 6188 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 6189 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 6190 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 6191 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 6192 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 6193 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 6194 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 6195 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 6196 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 6197 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 6198 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 6199 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 6200 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 6201 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 6202 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 6203 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 6204 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 6205 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 6206 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 6207 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 6208 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 6209 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 6210 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 6211 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 6212 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 6213 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 6214 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 6215 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 6216 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 6217 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 6218 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 6219 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 6220 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 6221 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 6222 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 6223 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 6224 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 6225 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 6226 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 6227 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 6228 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 6229 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 6230 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 6231 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 6232 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 6233 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 6234 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 6235 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 6236 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 6237 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 6238 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 6239 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 6240 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 6241 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 6242 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 6243 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 6244 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 6245 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 6246 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 6247 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 6248 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 6249 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 6250 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 6251 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 6252 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 6253 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 6254 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 6255 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 6256 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 6257 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("deterministic"))); }
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 6258 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nondeterministic"))); }
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 6259 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 6260 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 6261 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 6262 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("block"))); }
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6263 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 896:

/* Line 678 of lalr1.cc  */
#line 6264 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 897:

/* Line 678 of lalr1.cc  */
#line 6265 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 898:

/* Line 678 of lalr1.cc  */
#line 6266 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 899:

/* Line 678 of lalr1.cc  */
#line 6267 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 900:

/* Line 678 of lalr1.cc  */
#line 6268 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 901:

/* Line 678 of lalr1.cc  */
#line 6269 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eval"))); }
    break;

  case 902:

/* Line 678 of lalr1.cc  */
#line 6270 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 903:

/* Line 678 of lalr1.cc  */
#line 6271 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 904:

/* Line 678 of lalr1.cc  */
#line 6272 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 905:

/* Line 678 of lalr1.cc  */
#line 6273 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 906:

/* Line 678 of lalr1.cc  */
#line 6274 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 907:

/* Line 678 of lalr1.cc  */
#line 6275 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 908:

/* Line 678 of lalr1.cc  */
#line 6276 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 909:

/* Line 678 of lalr1.cc  */
#line 6277 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 910:

/* Line 678 of lalr1.cc  */
#line 6278 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 911:

/* Line 678 of lalr1.cc  */
#line 6279 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 912:

/* Line 678 of lalr1.cc  */
#line 6280 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 913:

/* Line 678 of lalr1.cc  */
#line 6281 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 914:

/* Line 678 of lalr1.cc  */
#line 6282 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 915:

/* Line 678 of lalr1.cc  */
#line 6283 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 916:

/* Line 678 of lalr1.cc  */
#line 6284 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 917:

/* Line 678 of lalr1.cc  */
#line 6285 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 918:

/* Line 678 of lalr1.cc  */
#line 6286 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 919:

/* Line 678 of lalr1.cc  */
#line 6287 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 920:

/* Line 678 of lalr1.cc  */
#line 6288 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 921:

/* Line 678 of lalr1.cc  */
#line 6289 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 922:

/* Line 678 of lalr1.cc  */
#line 6290 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 923:

/* Line 678 of lalr1.cc  */
#line 6291 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 924:

/* Line 678 of lalr1.cc  */
#line 6292 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 925:

/* Line 678 of lalr1.cc  */
#line 6293 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 926:

/* Line 678 of lalr1.cc  */
#line 6294 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 927:

/* Line 678 of lalr1.cc  */
#line 6295 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 928:

/* Line 678 of lalr1.cc  */
#line 6296 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 929:

/* Line 678 of lalr1.cc  */
#line 6297 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 930:

/* Line 678 of lalr1.cc  */
#line 6298 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 931:

/* Line 678 of lalr1.cc  */
#line 6299 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 932:

/* Line 678 of lalr1.cc  */
#line 6300 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 933:

/* Line 678 of lalr1.cc  */
#line 6301 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 934:

/* Line 678 of lalr1.cc  */
#line 6302 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 935:

/* Line 678 of lalr1.cc  */
#line 6303 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 936:

/* Line 678 of lalr1.cc  */
#line 6304 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 937:

/* Line 678 of lalr1.cc  */
#line 6305 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 938:

/* Line 678 of lalr1.cc  */
#line 6306 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 939:

/* Line 678 of lalr1.cc  */
#line 6307 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 940:

/* Line 678 of lalr1.cc  */
#line 6308 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 941:

/* Line 678 of lalr1.cc  */
#line 6309 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 942:

/* Line 678 of lalr1.cc  */
#line 6310 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 943:

/* Line 678 of lalr1.cc  */
#line 6311 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 944:

/* Line 678 of lalr1.cc  */
#line 6312 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 945:

/* Line 678 of lalr1.cc  */
#line 6313 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 946:

/* Line 678 of lalr1.cc  */
#line 6314 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 947:

/* Line 678 of lalr1.cc  */
#line 6315 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;



/* Line 678 of lalr1.cc  */
#line 11384 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1335;
  const short int
  xquery_parser::yypact_[] =
  {
      1923, -1335, -1335, -1335,  2517,  2810,  3103, -1335, -1335,  1569,
     204, -1335, -1335,   425, -1335, -1335, -1335, -1335,     0,   245,
     461,   318,   324,   384,   426,    99, -1335,   449, -1335, -1335,
   -1335, -1335, -1335, -1335,   552, -1335,   462, -1335,   454,   492,
   -1335,   486, -1335, -1335,   531, -1335,   466, -1335,   516,   523,
   -1335,   189, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335,
   -1335, -1335, -1335, -1335, -1335,   563,   564, -1335, -1335, -1335,
   -1335,   277,  8084, -1335, -1335, -1335,   566, -1335, -1335, -1335,
   -1335, -1335,   578,   579, -1335, -1335, 11216, -1335, -1335, -1335,
   -1335, -1335, -1335, -1335, -1335,   583, -1335, -1335,   581,   582,
   -1335, -1335, -1335, -1335, -1335, -1335, -1335,  3396, 11216, -1335,
   -1335, -1335, -1335, -1335, -1335, -1335,   554, -1335, -1335,   586,
    8955, -1335,  9242,   587,   588, -1335, -1335, -1335,   589, -1335,
    7791, -1335, -1335, -1335, -1335, -1335, -1335,   559, -1335, -1335,
   -1335, -1335, -1335, -1335, -1335, -1335,    30,   491, -1335, -1335,
   -1335, -1335, -1335, -1335, -1335, -1335,   292,   560,   409, -1335,
     495,   200, -1335, -1335, -1335, -1335, -1335, -1335,   600, -1335,
     567,   482,   483,   489, -1335, -1335,   577,   584, -1335,   616,
   -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335,
   -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335,
   -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335,
   -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335,
   -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335,
   -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335,
    2224,   732, -1335,   731,  5447, -1335, -1335,   268,   553,   555,
   -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335,
   -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335,
   -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335,
   -1335,   -25, -1335, -1335, -1335, -1335,   131, 11216, -1335, -1335,
   -1335, -1335, -1335, -1335,   576,   647, -1335,   574,   497,   -46,
     266,   371,   366, -1335,   695,   549,   646,   648,  5740, -1335,
   -1335, -1335,   320, -1335, -1335,  7791, -1335,   403, -1335,   596,
    8084, -1335,   596,  8084, -1335, -1335, -1335,   479, -1335, -1335,
   -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335,
   -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335,
   -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335,
   -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335,
   -1335,   609,   602, -1335, -1335, -1335, -1335, -1335,   585, -1335,
     591, -1335,   598,   730,   257,   288,   170,   420, 11498,   420,
   11216,   111,   712,   714,   719, 11216,   617,   651,    60,  8955,
   -1335, -1335,   407,   330,   537, 11216, -1335, -1335, -1335, -1335,
   -1335,   500, 11216,   487,   490,   337,   480,   388, -1335, -1335,
   -1335, -1335, -1335,  8955,  6033,   603,  6033,    69,  6033,  9806,
    6033,   511,   519, -1335,   685,     3,   652,  6033,    55,    56,
   11216,   687,  6033,  8666, 11216, 11216, 11216, 11216,  6033,   622,
    6033,  6033, 11216,  6033,   656,   658, -1335, -1335, -1335,  6033,
   10088,   657, -1335,   660, -1335, -1335, -1335, -1335, -1335, -1335,
     662, -1335, -1335,   663, -1335, -1335, -1335, -1335, -1335,   664,
   -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335,
   -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335,
   -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335,
   -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335,
   11216, -1335, -1335, -1335,   626,   786,  6033, -1335, -1335,    49,
   -1335, -1335,   801, -1335, -1335, -1335, -1335,  6033,   611, -1335,
     795,  6033,  6033,   640,  6033,  6033,  6033,  6033,   599, 11216,
   -1335, -1335, -1335, -1335,  6033,  6033,  6033, 11216, -1335,   731,
   -1335, -1335, -1335, -1335,  1569,    99,   641,   642,  6326,  6619,
    6033, -1335,  6033,   710,   324,   449,   552,   665,   667,   668,
    6033,  6033, -1335, -1335, -1335, -1335, -1335, -1335, -1335,   724,
   -1335,   -10,  6912,  6912,  6912, -1335,  6912,  6912, -1335,  6912,
   -1335,  6912, -1335, -1335, -1335, -1335, -1335, -1335, -1335,  6912,
    6912,   761,  6912,  6912,  6912,  6912,  6912,  6912,  6912,  6912,
    6912,  6912,  6912,   610,   746,   747,   748, -1335, -1335, -1335,
    3689, -1335, -1335,  7791,  7791,  6033,   596, -1335, -1335,   596,
   -1335,  3982,   596,   696,  4275, -1335, -1335, -1335, -1335, -1335,
   -1335, -1335, -1335, -1335,   738,   740, -1335,   384, -1335,   821,
   -1335, -1335, 11498, -1335, 11498,   608,   367, 11216,   421,   691,
     692,   608,   730,   726,   722, -1335, -1335, -1335, -1335, -1335,
      -7,   612,   -37, -1335,   557, -1335, -1335, -1335, -1335, 11216,
   11216, 11216, -1335,   728,   673, -1335,   675,   660,   492, -1335,
     676,   677,   678, -1335,   -11,    11,   681, -1335, -1335, 11216,
     -14, 11216,   769,    48, -1335,  6033, -1335,   680,  8955,   770,
     822,  8955,   730,   771,   762, -1335,   -35, -1335,   693,   688,
   -1335,   697,   698,   699,   735,   -21, -1335,   218,   703, -1335,
     701,   702,   725, -1335,   706,  6033,  6033,   707, -1335,    79,
     180,    -2, -1335, 11216,   786, -1335,   -59,   708, -1335, -1335,
   -1335,   715, -1335,   173, -1335, -1335, -1335,   -23,    92,   785,
     669,   670,   -26, -1335,   753,  7205, -1335,   717,   723,    84,
   -1335, -1335, -1335,   268,   872,   718, -1335, -1335,   759, -1335,
   -1335, -1335,   -18, 11216,   745,  6033,   789, -1335, -1335,   797,
   10652,   798,  6033,   799,   -45,   772,   -20,   647, -1335, -1335,
   -1335, -1335, -1335,  6912, -1335, -1335, -1335,    20,   266,   266,
     119,   371,   371,   371,   371,   366,   366, -1335, -1335, 10652,
   10652, 11216, 11216, -1335,   737, -1335, -1335,   739, -1335, -1335,
   -1335,   202, -1335, -1335,   205,   345,   359,   377, -1335,   384,
     384, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335,
   -1335,   608, -1335,   790, 10934,   779,  6033, -1335, -1335, -1335,
     828,   784,  6033,   730,   730,   608, -1335,   525,   730,   309,
   11216,   300,   303,   898, -1335, -1335,   644,   261, -1335, -1335,
   -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335,    -7,
      51,   368, -1335,   705,   106,   -30,   633,   730, -1335, -1335,
   -1335, -1335,   780, 11216, -1335, 11216, -1335, -1335,   310,   686,
   -1335, -1335,   485,   -14,   828, 10652,   815,   842,   758,   749,
     810,   730,   787,   812,   850,   730,   830,  6033,   809,   -63,
     800, -1335, -1335, -1335, -1335,  6033,   833,  6033,  6033,   808,
   -1335,   856,   857,  6033, -1335,   777,   778,   813, 11216, -1335,
   11216, -1335,  6033,   928, -1335,   -32, -1335,   203, -1335, -1335,
     936, -1335,   381,  6033,  6033,  6033,   412,  6033,  6033,  6033,
    6033,  6033,  6033,   848,  6033,  6033,   651,    -9,   788,   567,
     729,   816,   849,   781,   759,  6619,   891, -1335, -1335,  6033,
      28,   866, -1335, 11216,   867, -1335, 11216,   820,   823, 10934,
     824, -1335,   -43, -1335, -1335, -1335, -1335, -1335, -1335, -1335,
   11216, -1335, 11216,  6033,   831,  6033,  6033,    -8,   834, -1335,
    6033,    20,   182,   332, -1335,   700,    44,   720,   727, -1335,
   -1335,   537, -1335,   716,   220, -1335, -1335, -1335,   839, -1335,
   -1335, -1335,  6033, -1335, -1335, -1335, -1335, -1335, -1335, -1335,
    6033, -1335,   383,   401, -1335,   956,   453, -1335, -1335, -1335,
    6033, -1335, -1335, -1335, -1335, -1335, -1335, -1335,   704, -1335,
   -1335,   959, -1335, -1335, -1335, -1335, -1335,   275,   961, -1335,
     457, -1335, -1335, -1335,   657,   245,   662,   454,   663,   664,
     560,   756,   -43,   767,   768,  7498,   734,   689,    51, -1335,
     773,   811,  4568,   818,   819,   858,   825,   826,  6033,   854,
   -1335,   887,   889,  6033, 11216,    98,   930, -1335, -1335, -1335,
   -1335, -1335, -1335, 10652, -1335,  6033,   730,   902, -1335, -1335,
   -1335,   730,   902, 11216, -1335,  6033,  6033,   871,  4861, -1335,
   11216, -1335, -1335,  6033,  6033,   458, -1335,    -1, 10370,   460,
   -1335,   832, -1335, -1335,  5154,   835,   836, -1335, -1335,   882,
   -1335,   267, -1335, -1335,  1004, -1335, -1335, 11216, -1335, -1335,
     396, -1335, -1335, -1335,   829,   792,   793, -1335, -1335, -1335,
     794,   796, -1335, -1335, -1335, -1335, -1335,   782, 11216,   841,
   -1335,   886, -1335,   651, -1335, -1335, -1335,  8377,   729, -1335,
    6033, 11216,   872, -1335,   866, -1335,   730, -1335,   528, -1335,
     276,   922, -1335,  6033,   923,   789, -1335,  9524,   845,   846,
     847, -1335, -1335, -1335, -1335, -1335, -1335, -1335,  6033, -1335,
   -1335,  6033,   888,  6033,   851,   852, -1335,    20,   807, -1335,
   -1335,   -92, -1335,    94,    -5,   814,    20,    94,  6912, -1335,
     -22, -1335, -1335, -1335, -1335, -1335, -1335,    20,   890,   755,
     612,    -5, -1335, -1335,   754,   963, -1335, -1335, -1335, -1335,
   -1335,   861, -1335, -1335, -1335,  6033, -1335, -1335, -1335, -1335,
   -1335,  1021,   155,  1028,   155,   802,   964, -1335, -1335, -1335,
   -1335,   894, 11216,   803,   756,  7498, -1335, -1335,   883, -1335,
   -1335, -1335, -1335, -1335, -1335,  6033, 11216, 11216, -1335,    67,
   -1335,  6033, -1335,   939,   970,   730,   902, -1335, -1335, -1335,
    6033, -1335,   892, -1335, -1335, -1335,   884, -1335,  6033,  6033,
   11216,   885,   -28, -1335, -1335, -1335,   893, -1335, -1335,   928,
   11216,   427, -1335,   928, 11216, -1335, -1335,  6033,  6033,  6033,
    6033,  6033, -1335,  6033,  6033, -1335, -1335,   244, -1335,   895,
   -1335, -1335, -1335, -1335,   922, -1335, -1335, -1335,   730, -1335,
   -1335,   977,   896, -1335,   232, -1335, -1335, -1335, -1335, -1335,
    6033, -1335, -1335, -1335, -1335,   897,  6912, -1335, -1335, -1335,
   -1335, -1335,    57,  6912,  6912,   238, -1335,   720, -1335,   159,
   -1335,   727,    20,   921, -1335, -1335,   804, -1335, -1335, -1335,
   -1335, -1335,    12, -1335,   214,   214, -1335,   155, -1335, -1335,
     235, -1335,  1050,    -5,   900,   973, -1335,  7498,   -75,   817,
   -1335,   917, -1335, -1335, -1335,  1035, -1335, -1335,  6033,   730,
   -1335, -1335, -1335,  6033, -1335, -1335,   994,  6033, 11216,  6033,
   -1335,    -3,   928, 11216,   899,   928, -1335, -1335, -1335, -1335,
   -1335, -1335, -1335,   974,  8377, -1335, -1335, -1335, -1335, 10652,
   -1335, 10652,   999, -1335, -1335,   371,  6912,  6912,   119,   -15,
   -1335, -1335, -1335, -1335, -1335, -1335,  6033, -1335, -1335, -1335,
   -1335, -1335,  1067, -1335, -1335, -1335,   837, -1335,   964,   989,
   -1335,   470, 11216,   979,   876, 11216,  7498,   981, -1335,   902,
   -1335, 10652, -1335,   920, -1335,   167,   196, -1335,   911,   928,
   -1335,   912, 11216, -1335, -1335, -1335, 10652,   119,   119,  6912,
     925, -1335, -1335, -1335,  7498, -1335,   922,   805, 11216,   991,
     901,   989, 11216,   927,  6033, -1335, -1335,  1018,   262, -1335,
   -1335, -1335, -1335,   932,   422, -1335, -1335, -1335,   924, -1335,
     236, -1335,   119, -1335, -1335, -1335,  6033,   827, 11216,   996,
   -1335,  6033, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335,
     997,   965, -1335,   838,   840, 11216, -1335, 11216, -1335,   843,
    6033,   844,   240,  7498, -1335,  7498,   998,   965, -1335,   929,
   11216, -1335,   853,   934, 11216,   965,   904, -1335,  1002, 11216,
     855,  7498, -1335
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,     8,   419,   420,     0,     0,     0,   748,   573,   839,
     848,   753,   751,   734,   840,   843,   796,   889,   757,   735,
     736,   901,   788,   849,   738,   846,   818,   798,   773,   793,
     890,   794,   844,   841,   789,   792,   740,   847,   741,   742,
     887,   903,   886,   790,   809,   803,   743,   791,   745,   744,
     888,   827,   795,   770,   913,   914,   915,   916,   917,   918,
     919,   920,   921,   922,   923,   937,   944,   817,   813,   804,
     784,   733,     0,   812,   820,   828,   938,   808,   439,   785,
     786,   842,   939,   945,   805,   822,     0,   445,   408,   441,
     815,   750,   806,   807,   835,   810,   826,   834,   943,   946,
     756,   797,   837,   440,   825,   830,   737,     0,     0,   357,
     823,   833,   838,   836,   816,   802,   891,   800,   801,   940,
       0,   356,     0,   941,   947,   831,   787,   811,   942,   386,
       0,   418,   832,   814,   821,   829,   824,   892,   778,   783,
     782,   781,   780,   779,   746,   799,     0,   749,   845,   771,
     878,   877,   879,   755,   754,   774,   884,   739,   876,   881,
     882,   873,   777,   819,   875,   885,   883,   874,   775,   880,
     894,   897,   898,   895,   896,   893,   747,   899,   900,   902,
     865,   864,   851,   769,   762,   858,   854,   772,   768,   867,
     868,   758,   759,   752,   761,   863,   862,   859,   855,   872,
     866,   861,   857,   850,   760,   871,   870,   764,   766,   765,
     856,   860,   852,   767,   853,   763,   869,   924,   925,   926,
     927,   928,   929,   905,   906,   904,   910,   911,   912,   907,
     908,   909,   776,   930,   931,   932,   933,   934,   935,   936,
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
     204,   416,   732,   839,   848,   846,   508,   749,     0,   512,
       0,   518,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     113,   114,     0,     0,     0,     0,   109,   110,   111,   112,
     119,     0,     0,     0,     0,     0,     0,     0,   107,   166,
     169,   172,   171,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   232,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   410,   413,   400,     0,
       0,   734,   757,   736,   901,   788,   849,   738,   798,   789,
     740,   903,   809,   743,   745,   744,   827,   937,   944,   733,
     938,   939,   945,   810,   943,   946,   891,   940,   941,   947,
     942,   892,   884,   876,   882,   873,   775,   894,   897,   898,
     895,   747,   899,   902,   406,   416,   732,   398,   399,   402,
     734,   735,   736,   740,   741,   742,   743,   733,   739,   442,
       0,   404,   403,   443,     0,   468,     0,   409,   730,     0,
     731,   381,     0,   412,   411,   401,   384,     0,     0,   497,
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
     407,     0,   422,     0,     0,   509,   513,   519,   729,    82,
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
     250,   267,     7,    20,    21,     0,    25,    15,   839,    27,
      16,   191,     0,     0,     0,     0,     0,   211,   268,     0,
       0,     0,     0,     0,     0,     0,     0,   313,   315,   319,
     325,   324,   323,     0,   320,   317,   318,     0,   334,   333,
     331,   337,   338,   339,   336,   341,   342,   345,   344,     0,
       0,     0,     0,   376,     0,   388,   389,     0,   426,   423,
     450,     0,   576,   448,     0,     0,     0,     0,    71,     0,
       0,    46,    48,    49,    50,    51,    53,    54,    55,    47,
      52,    42,    43,     0,     0,    99,     0,    95,    97,    98,
     102,   105,     0,     0,     0,    41,    81,     0,     0,     0,
       0,     0,     0,     0,   679,   684,     0,     0,   680,   714,
     667,   669,   670,   671,   673,   675,   674,   672,   676,     0,
       0,     0,   124,     0,     0,   127,     0,     0,   517,   507,
     550,   551,     0,     0,   567,     0,   564,   616,     0,     0,
     214,   215,     0,   220,   181,     0,     0,   150,     0,     0,
       0,     0,     0,     0,    84,     0,     0,     0,     0,     0,
       0,   556,   555,   562,   570,     0,     0,     0,     0,     0,
     516,     0,     0,     0,   372,     0,     0,     0,     0,   560,
       0,   558,     0,   468,   466,     0,   457,     0,   446,   447,
       0,    13,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   839,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   189,   221,     0,
     279,   275,   277,     0,   269,   270,     0,   849,   737,     0,
     746,   524,   525,   531,   532,   534,   578,   579,   535,   538,
       0,   237,     0,     0,     0,     0,     0,     0,     0,   322,
       0,     0,     0,     0,   645,   328,   618,   622,   624,   626,
     628,   631,   638,   639,   647,   347,   349,   351,   522,   353,
     377,   427,     0,   424,   449,    79,    80,    77,    78,   174,
       0,   173,     0,     0,    44,     0,     0,   100,   101,   103,
       0,   104,    69,    70,    75,    76,    66,   685,     0,   688,
     715,     0,   678,   677,   682,   681,   713,     0,     0,   690,
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
     451,     0,   176,   175,   178,     0,    45,    96,   106,   702,
     683,     0,   707,     0,   707,   696,   691,   126,   132,   134,
     133,     0,     0,     0,   129,     0,    23,   510,     0,   568,
     569,   572,   565,   566,   256,     0,     0,     0,   218,   259,
     262,     0,   152,     0,    92,     0,    86,   249,   254,   253,
       0,   520,     0,   296,   298,   303,     0,   301,     0,     0,
       0,     0,     0,   308,   375,   514,     0,   561,   559,   468,
       0,     0,   500,   468,     0,   464,    14,     0,     0,     0,
       0,     0,   604,     0,     0,   157,   613,     0,   608,     0,
     251,   292,   290,   291,   284,   285,   286,   278,     0,   273,
     271,     0,     0,   536,     0,   533,   583,   527,   243,   240,
       0,   242,   646,   637,   643,     0,     0,   716,   717,   727,
     726,   725,     0,     0,     0,     0,   718,   623,   724,     0,
     621,   625,     0,     0,   630,   634,     0,   655,   650,   653,
     649,   184,     0,   703,     0,     0,   701,   708,   709,   705,
       0,   700,     0,   698,     0,   692,   693,     0,     0,     0,
     130,     0,   511,   257,   265,   266,   260,   217,     0,     0,
      88,   255,   521,     0,   304,   302,     0,     0,     0,     0,
     515,     0,   468,     0,     0,   468,   588,   589,   593,   594,
     600,   602,   160,     0,     0,   609,   615,   287,   274,     0,
     580,     0,     0,   244,   641,   728,     0,     0,   720,     0,
     666,   665,   664,   663,   662,   627,     0,   719,   177,   712,
     711,   710,     0,   704,   697,   695,     0,   687,     0,   135,
     137,   139,     0,     0,     0,     0,     0,     0,   311,    94,
     299,     0,   309,     0,   305,   478,   472,   467,     0,   468,
     459,     0,     0,   614,   581,   537,     0,   722,   721,     0,
       0,   706,   699,   694,     0,   141,   140,     0,     0,     0,
       0,   136,     0,     0,     0,   486,   480,     0,   479,   481,
     487,   484,   474,     0,   473,   475,   485,   461,     0,   460,
       0,   582,   723,   635,   138,   142,     0,     0,     0,     0,
     264,     0,   306,   471,   482,   483,   470,   476,   477,   462,
       0,     0,   143,     0,     0,     0,   310,     0,   610,     0,
       0,     0,     0,     0,   145,     0,     0,     0,   144,     0,
       0,   611,     0,     0,     0,     0,     0,   612,     0,     0,
       0,     0,   146
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1335, -1335,  -212,   879, -1335,   878,   903, -1335,   869,  -229,
    -522,  -552, -1335,   452,  -741, -1335, -1335, -1335, -1335, -1335,
   -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335,  -914,
   -1335, -1335, -1335, -1335,    61,   263,   733, -1335, -1335,   741,
   -1335,    21,  -881, -1335,  -385,  -412, -1335, -1335,  -608, -1335,
    -849, -1335, -1335,   -69, -1335, -1335, -1335, -1335, -1335,   254,
     743, -1335, -1335, -1335,   211,   709, -1334,  -546,     5, -1335,
    -559,   349, -1335, -1335, -1335, -1335,   217, -1335, -1335,   860,
   -1335, -1335, -1335, -1335, -1335,   135,  -544,  -701, -1335, -1335,
   -1335,     6, -1335, -1335,  -171,    25,   -55, -1335, -1335, -1335,
     -73, -1335, -1335,   158,   -64, -1335, -1335,   -60, -1180, -1335,
     643,    14, -1335, -1335,     7, -1335, -1335, -1335,     2, -1335,
   -1335,   573,   575, -1335,  -535, -1335, -1335,  -613,    42,  -612,
      37,    40, -1335, -1335, -1335, -1335, -1335,   859, -1335, -1335,
   -1335, -1335,  -797,  -300, -1076, -1335,   -96, -1335, -1335, -1335,
   -1335, -1335, -1335, -1335,   -40, -1177, -1335, -1335,   264,   -39,
   -1335,  -778, -1335, -1335, -1335, -1335, -1335, -1335, -1335,   522,
   -1335,  -941, -1335,     1, -1335,   416,  -747, -1335, -1335, -1335,
   -1335, -1335,  -393,  -384, -1111, -1052, -1335, -1335, -1335, -1335,
   -1335, -1335, -1335, -1335, -1335, -1335,   341,  -718,  -814,    73,
    -801, -1335,  -173,  -732, -1335, -1335, -1335, -1335, -1335, -1335,
   -1335,   750,   751,  -474,   265,   114, -1335, -1335, -1335, -1335,
   -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335,
     -17, -1335, -1335,   -24, -1335, -1335,  -987, -1335, -1335, -1335,
     -80,   -85,  -227,   151, -1335, -1335, -1335, -1335, -1335, -1335,
   -1335, -1335, -1335, -1335, -1335, -1335, -1335,   -74, -1335, -1335,
   -1335,  -222,   147,   290, -1335, -1335, -1335, -1335, -1335,   100,
   -1335, -1335, -1261, -1335, -1335, -1335,  -761, -1335,  -103, -1335,
    -235, -1335, -1335, -1335, -1335, -1219, -1335,   -62, -1335,  -381,
    -372,    76,   -72
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   861,   862,   863,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,  1137,
     722,   266,   267,   867,   868,   869,  1201,   268,   417,   418,
     269,  1101,   902,   270,  1509,  1510,   271,   272,   436,   273,
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
     337,   338,   339,  1180,   754,   755,   756,  1527,  1563,  1564,
    1557,  1558,  1565,  1559,  1181,  1182,   340,   341,  1183,   342,
     343,   344,   345,   346,   347,   348,  1047,   806,  1011,  1234,
    1012,  1384,  1013,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   742,  1114,   359,   360,   361,   362,  1015,
    1016,  1017,  1018,   363,   364,   365,   366,   367,   368,   772,
     773,   369,  1208,  1209,  1367,   370,  1035,  1259,  1260,  1036,
    1037,  1038,  1039,  1040,  1269,  1414,  1415,  1041,  1272,  1042,
    1395,  1043,  1044,  1277,  1278,  1420,  1418,  1261,  1262,  1263,
    1264,  1493,   681,   890,   891,   892,   893,   894,   895,  1091,
    1434,  1435,  1092,  1433,  1505,   896,  1294,  1430,  1426,  1427,
    1428,   897,   898,  1265,  1273,  1405,  1266,  1401,  1250,  1138,
     529,   371,   372
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       506,   820,   649,   821,   822,   823,   824,   965,   939,   378,
     380,   382,   631,   792,   506,  1045,  1046,   789,   567,   949,
    1033,  1142,   787,   790,  1109,   938,  1179,   674,   558,  1301,
    1366,   561,   504,  1475,   536,  1436,   506,   919,  1512,  1034,
    1375,  1376,   879,     8,  1245,   880,   786,   804,   506,   847,
     506,   693,  1416,   900,   538,   800,   758,   719,   723,   809,
    1108,   810,   811,  1066,   812,   966,   814,   972,  1014,  1355,
    1251,   731,   801,  1146,   815,   816,   983,   570,   648,   648,
     800,   946,   801,  1094,   570,  1458,  1525,  1402,   881,  1095,
     697,   913,  1170,  1203,  1338,  1231,  1023,  1014,  1014,   669,
     946,   937,   670,  1024,  1486,  1028,   612,  1096,   697,  1097,
     698,  1131,   524,   915,   570,  1121,   711,  1397,  1098,  1215,
    1064,  1026,  1122,   613,   991,    78,  1232,   438,   698,  1216,
     967,   802,  1014,  1241,  1064,   671,  1251,   612,    89,  1217,
    1206,  1252,  1513,  1233,  1099,   614,  1121,   426,   505,  1218,
     926,  1459,  1069,  1122,   613,  1398,   439,  1171,   571,   801,
     947,   672,   519,   103,   720,   997,   573,  1030,  1102,   914,
    1031,  1555,   574,  1526,  1204,  1172,  1539,   575,  1339,   962,
    1487,   958,   976,   712,   525,   576,   992,   973,   974,  1498,
     122,   916,   901,  1014,  1477,   920,   530,   577,   532,   901,
    1119,   984,   975,   803,  1172,     8,  1130,  1252,  1229,   718,
     721,  1172,  1173,  1283,  1506,   506,  1169,   759,  1561,   632,
    1297,   803,   673,  1253,  1254,  1514,  1255,  1326,   927,  1441,
    1179,   803,   789,   921,  1033,  1033,   539,   882,  1147,  1179,
    1355,  1062,  1063,  1257,  1403,  1404,   803,  1543,   506,   699,
     883,   506,   884,  1034,  1034,  1258,   803,  1598,   803,   959,
    1394,   786,  1027,   885,   886,   887,  1555,   888,  1100,   889,
    1172,   612,  1032,  1611,   660,  1172,  1173,  1014,  1029,   452,
     638,  1617,   960,   640,  1175,  1424,  1176,    78,   613,  1253,
    1254,   876,  1255,   578,  1556,   564,   579,  1533,   970,  1256,
      89,  1174,   977,   978,  1052,   661,  1291,  1052,   800,  1257,
     580,   612,   565,  1175,   715,  1176,   657,   979,   506,  1322,
    1175,  1258,  1176,   506,  1562,   103,  1242,   506,   613,  1030,
     654,  1545,  1031,   506,  1481,   581,   453,  1502,  1590,   785,
     506,   934,  1606,   715,  1341,   655,   930,   782,  1425,   933,
     715,   506,   122,  1088,   108,  1399,   971,   506,   423,   948,
     961,  1511,  1400,   591,  1293,  1174,  1575,  1291,   506,  1089,
     120,   506,   506,   506,   506,   506,  1102,  1216,   615,  1175,
     506,  1176,  1053,  1292,  1175,  1054,  1176,   431,   506,  1584,
    1177,  1060,   432,   458,  1473,   427,   505,  1218,  1106,   505,
     800,  1014,   454,   455,  1172,  1173,   616,  1107,   146,   715,
    1179,  1090,  1482,  1383,   715,  1503,  1591,   547,   108,   617,
    1607,  1490,   548,  1440,   459,  1293,  1014,   460,  1491,   694,
    1172,   696,   650,   702,   120,  1172,  1173,   433,  1492,  1113,
    1511,  1116,   717,   789,  1561,   651,  1474,   728,   506,  1213,
    1033,  1118,   618,   738,  1350,   740,   741,   864,   744,  1033,
    1274,  1275,   388,   652,   747,   430,   659,   630,  1511,  1034,
    1033,   665,   146,  1560,  1566,   530,   653,   506,  1034,  1247,
     392,   682,   393,  1276,  1165,   506,  1166,  1055,   684,  1034,
     122,   394,  1072,  1073,  1174,  1014,   621,  1076,   865,   530,
    1490,  1057,   122,   866,  1056,   705,  1560,  1491,  1059,   541,
     622,   542,  1566,  1175,  1282,  1176,   726,  1492,  1058,   530,
     732,   733,   734,   737,  1060,  1174,  1111,  1608,   743,  1609,
     550,   757,  1284,  1121,   435,  1519,   750,   835,   836,  1175,
    1122,  1176,   761,   715,  1175,  1622,  1176,   108,  1285,  1088,
    1587,   400,   871,  1154,   993,  1158,  1082,   872,  1123,  1084,
     800,   778,   440,   120,   619,  1089,  1336,  1083,  1342,   715,
    1085,  1216,   424,   620,   715,   425,   437,   801,   108,  1077,
    1078,  1079,   401,  1354,   865,  1080,   639,   633,   634,   866,
     849,   642,   850,   441,   120,   506,   737,   838,  1124,   446,
     838,   146,  1461,   838,   444,  1185,  1464,  1186,   428,   442,
     403,   429,   443,   448,  1463,  1033,   449,   506,   506,   506,
     675,   676,   677,   678,   679,   774,   544,   635,   545,   641,
     687,   688,   146,   781,  1034,   834,  1190,   506,  1191,   506,
     837,   656,   445,   658,   447,  1409,   506,  1074,  1075,   506,
    1372,  1373,  1103,  1104,   818,   819,   825,   826,  1048,  1048,
     789,   827,   828,  1499,  1500,  1534,   450,  1535,   690,   406,
     407,   408,   409,   451,   410,   411,   691,   413,   414,   456,
     457,   506,   507,   415,   851,   852,   853,   854,   855,   856,
     857,   858,   859,   860,   508,   509,   520,   521,   522,   540,
     594,   526,   527,   533,   534,   535,   537,  1553,   595,   596,
     543,   597,   546,   549,   550,  1528,   552,   553,  1531,   598,
     928,   506,  1571,   599,   554,   600,  1422,   555,   506,   557,
     601,   556,   560,   631,     1,   593,   568,   592,   569,   611,
     623,   624,   625,   870,   635,   626,   602,  1014,   643,  1014,
     955,   956,   644,   648,   662,  1324,   388,   506,   506,   506,
     506,   664,   645,   666,   667,   904,   905,   906,   646,   603,
     604,   605,   606,   607,   608,   647,   680,   689,   685,   706,
     988,   686,  1568,   695,  1485,   918,   683,   924,   707,  1014,
    1488,  1489,   506,  1546,   530,   387,   708,   530,   709,   715,
     727,   388,   739,   745,  1014,   746,   752,   425,   506,   389,
     429,   390,   443,   449,   460,   753,   760,   762,   763,   392,
     766,   393,   771,   793,   783,   784,   799,   794,   817,   963,
     394,   795,   796,   829,   395,  1371,   830,   831,   832,   842,
     845,   506,   846,   506,   848,   873,   874,   877,   878,   903,
     908,   899,   909,   506,   907,   912,   910,   911,   917,   925,
     929,   932,   931,   935,   936,   396,   397,   996,   941,   998,
     940,   945,   953,  1537,  1538,   980,  1019,   942,   943,   944,
     950,   951,   952,   954,   957,   968,   506,   982,   506,   985,
     764,   765,   969,   767,   768,   769,   770,   989,   981,   994,
     990,   995,  1003,   776,   777,  1019,  1019,  1019,  1019,   999,
    1006,  1020,  1022,  1025,  1050,   866,  1065,  1051,   800,   791,
    1070,  1086,   400,  1087,  1105,  1110,  1572,  1112,   711,   797,
     798,   506,  1133,  1120,   506,  1134,  1136,   506,  1140,  1135,
    1019,  1139,  1141,  1143,  1450,  1145,  1150,  1148,   506,  1153,
     506,  1154,  1158,   401,  1162,  1163,  1081,  1168,  1161,  1184,
    1164,  1198,  1211,  1210,  1212,  1205,   671,  1207,  1223,  1225,
    1227,  1267,  1238,  1228,  1230,  1243,  1271,  1279,  1248,     8,
    1268,   403,  1290,  1289,  1295,   901,  1299,  1300,  1303,  1115,
     840,  1115,  1305,   840,  1306,  1315,  1311,  1478,  1309,  1310,
    1316,  1019,  1317,  1321,  1325,  1312,  1313,  1330,  1349,  1344,
    1352,  1361,  1356,   404,  1302,  1347,  1348,  1357,  1358,  1359,
    1363,  1360,  1364,  1216,  1378,  1385,  1386,  1387,  1392,  1390,
    1413,  1412,  1393,  1417,   743,  1244,   743,  1419,  1421,   405,
     406,   407,   408,   409,  1423,   410,   411,   412,   413,   414,
    1396,  1429,   506,  1439,   415,   416,  1088,  1406,  1437,  1448,
    1442,   506,  1449,  1453,  1457,  1281,  1432,  1479,  1496,  1452,
    1460,   506,  1476,  1504,  1484,  1508,  1480,  1497,   506,  1224,
    1507,  1516,   591,  1517,  1521,  1019,   506,  1532,  1530,  1536,
    1541,  1544,  1548,  1549,  1552,  1542,  1235,  1515,  1236,  1554,
    1567,  1569,  1573,  1576,  1578,   506,  1581,  1583,  1586,  1595,
    1597,  1610,  1060,  1589,  1615,  1619,   566,  1308,  1579,   559,
    1612,  1618,   562,   875,  1599,  1593,   506,  1287,  1067,  1304,
     668,  1551,  1574,  1614,  1365,   506,   663,  1132,  1600,   506,
    1129,  1226,  1603,  1605,  1000,   716,   584,   563,  1446,  1327,
    1320,  1021,  1380,  1332,  1621,   506,  1370,  1214,   692,  1377,
    1374,  1343,  1337,   751,  1333,   807,   844,   629,   808,  1346,
     964,  1588,  1351,  1049,  1585,  1298,  1407,   700,   701,  1286,
    1117,  1362,  1411,  1246,  1368,  1495,  1410,  1494,  1270,  1093,
    1296,  1431,  1501,     0,     0,  1408,     0,     0,     0,     0,
    1319,     0,     0,     0,     0,     0,     0,     0,     0,  1019,
       0,     0,     0,     0,     0,  1068,     0,     0,     0,   726,
       0,  1071,     0,     0,     0,     0,   737,     0,     0,     0,
     506,     0,     0,     0,  1019,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   506,   506,     0,     0,     0,     0,
       0,     0,     0,  1353,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   506,     0,
       0,     0,     0,     0,   774,     0,     0,     0,   506,     0,
       0,     0,   506,   505,     0,     0,  1144,   781,     0,     0,
       0,     0,     0,     0,  1149,     0,  1151,  1152,     0,     0,
       0,     0,     0,  1019,     0,     0,     0,     0,     0,     0,
       0,  1167,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1187,  1188,  1189,     0,  1192,  1193,  1194,  1195,
    1196,  1197,     0,  1199,  1200,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1000,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1237,     0,  1239,  1240,     0,     0,  1438,     0,
       0,     0,     0,     0,     0,     0,   506,     0,     0,     0,
       0,   506,  1444,  1445,     0,     0,     0,     0,     0,     0,
       0,  1280,   506,     0,     0,     0,     0,   506,     0,   506,
       0,     0,     0,     0,     0,     0,  1456,     0,     0,  1288,
       0,     0,     0,     0,     0,     0,  1462,     0,     0,     0,
    1465,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     506,     0,     0,   506,     0,     0,     0,     0,     0,   506,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     506,     0,     0,     0,   506,     0,     0,  1314,     0,     0,
       0,     0,  1318,     0,     0,     0,   506,     0,     0,     0,
     506,     0,     0,     0,  1323,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1328,  1329,     0,     0,     0,     0,
       0,  1540,  1334,  1335,     0,     0,   506,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   506,     0,   506,     0,     0,     0,     0,
       0,     0,     0,     0,  1523,     0,     0,     0,   506,  1529,
       0,     0,   506,     0,     0,     0,     0,   506,     0,     0,
     505,     0,     0,     0,     0,  1019,     0,  1019,     0,  1369,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1000,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1388,  1547,     0,
    1389,  1550,  1391,     0,     0,     0,     0,  1019,     0,   383,
     384,     0,   385,   386,     0,   387,     0,     0,  1570,     0,
       0,   388,  1019,     0,     0,     0,     0,     0,     0,   389,
       0,   390,   391,     0,  1577,     0,     0,     0,  1580,   392,
       0,   393,     0,     0,     0,     0,     0,     0,     0,     0,
     394,     0,     0,     0,   395,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1594,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1443,     0,     0,     0,     0,     0,
    1447,  1601,     0,  1602,     0,   396,   397,   398,     0,  1451,
       0,     0,     0,     0,     0,     0,  1613,  1454,  1455,     0,
    1616,     0,     0,     0,     0,  1620,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1466,  1467,  1468,  1469,
    1470,     0,  1471,  1472,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   399,     0,     0,     0,     0,     0,     0,
       0,     0,   400,     0,     0,     0,     0,     0,     0,  1483,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   401,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   402,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   403,     0,     0,     0,     0,     0,  1518,     0,     0,
       0,     0,  1520,     0,     0,     0,  1522,     0,  1524,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   404,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   405,
     406,   407,   408,   409,     0,   410,   411,   412,   413,   414,
       0,     0,     0,     0,   415,   416,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1582,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1592,     1,     0,     0,     0,
    1596,     0,     0,     2,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     0,     8,     0,     0,  1604,
       9,    10,     0,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
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
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,     0,   191,   192,   193,     0,   194,
     195,   196,   197,   198,   199,     0,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,     1,     0,     0,
       0,     0,     0,     0,     2,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     0,     8,     0,     0,
       0,     9,    10,     0,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
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
       0,     0,     0,   126,     0,   127,   128,     0,   129,   130,
     131,     0,   132,     0,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,     0,     0,   144,   145,   146,
       0,   147,   148,   149,   150,   151,   152,   153,   154,   155,
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
     123,   124,   125,     0,   376,     0,   126,     0,   127,   128,
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
     122,     0,     0,   123,   124,   125,     0,   379,     0,   126,
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
     381,     0,   126,     0,   127,   128,     0,   129,   130,   131,
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
     124,   125,     0,     0,     0,   126,   523,   127,   128,     0,
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
       0,     0,   123,   124,   125,     0,   833,     0,   126,     0,
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
       0,   121,   122,     0,     0,   123,   124,   125,     0,     0,
       0,   126,   839,   127,   128,     0,   129,   130,   131,     0,
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
     125,     0,     0,     0,   126,   843,   127,   128,     0,   129,
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
       0,   123,   124,   125,     0,  1307,     0,   126,     0,   127,
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
     121,   122,     0,     0,   123,   124,   125,     0,  1331,     0,
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
       0,  1345,     0,   126,     0,   127,   128,     0,   129,   130,
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
       8,     0,     0,     0,     9,    10,     0,    11,    12,    13,
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
     464,   465,    23,   467,   375,    26,   468,    28,    29,     0,
      30,    31,    32,    33,   469,    35,    36,    37,    38,    39,
      40,   471,    42,    43,   472,     0,    45,    46,    47,   474,
     475,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,    72,    73,    74,    75,     0,     0,
      76,    77,     0,     0,     0,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,     0,     0,    89,     0,
      90,    91,    92,    93,     0,    94,     0,     0,     0,   483,
      96,    97,    98,    99,     0,     0,     0,     0,     0,     0,
     100,   101,   102,   103,   104,   105,   106,     0,     0,     0,
     107,   108,   627,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,   120,     0,   628,
     122,     0,     0,   123,   124,   125,     0,     0,     0,   126,
       0,   127,   128,     0,   129,   130,   131,     0,   132,     0,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,     0,     0,   144,   145,   146,     0,   377,   148,   149,
     150,   151,   152,   153,   154,   155,   492,   157,   493,   159,
     494,   495,   162,   163,   164,   165,   166,   167,   496,   169,
     497,   498,   499,   500,   174,   175,   501,   502,   178,   503,
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
       0,     0,     0,     9,   374,     0,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,     0,    30,    31,    32,    33,
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
     124,   125,     0,     0,     0,   126,     0,   127,   128,     0,
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
       7,     0,     8,     0,     0,     0,   788,   374,     0,    11,
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
      47,   474,   475,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,    72,    73,    74,    75,
       0,     0,    76,    77,     0,     0,     0,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,     0,     0,
      89,     0,    90,    91,    92,    93,     0,    94,     0,     0,
       0,   483,    96,    97,    98,    99,     0,     0,     0,     0,
       0,     0,   100,   101,   102,   103,   104,   105,   106,     0,
       0,     0,   107,   108,   109,   110,   111,     0,     0,     0,
       0,   112,   113,   114,   115,   116,   117,   118,   119,   120,
       0,   121,   122,     0,     0,   123,   124,   125,     0,     0,
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
       0,     0,   986,   374,     0,    11,    12,    13,    14,    15,
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
     125,     0,     0,     0,   126,     0,   127,   128,     0,   129,
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
      13,    14,    15,    16,    17,    18,    19,    20,   464,   465,
      23,   467,   375,    26,   468,    28,    29,     0,    30,    31,
      32,    33,   469,    35,    36,    37,    38,    39,    40,   471,
      42,    43,   472,     0,    45,    46,    47,   474,   475,    50,
     476,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,    72,    73,    74,    75,     0,     0,    76,    77,
       0,     0,     0,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,     0,     0,    89,     0,    90,    91,
      92,    93,     0,    94,     0,     0,     0,   483,    96,    97,
      98,    99,     0,     0,     0,     0,     0,     0,   100,   101,
     102,   103,   104,   105,   106,     0,     0,     0,   107,   108,
       0,   110,   111,     0,     0,     0,     0,   112,   113,   114,
     115,   116,   117,   118,   119,   120,     0,     0,     0,     0,
       0,   123,   124,   125,     0,     0,     0,   126,     0,   127,
     128,     0,   129,   130,   131,     0,   132,     0,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,     0,
       0,   144,   145,   146,     0,   377,   148,   149,   150,   151,
     152,   153,   154,   155,   492,   157,   493,   159,   494,   495,
     162,   163,   164,   165,   166,   167,   496,   169,   497,   498,
     499,   500,   174,   175,   501,   502,   178,   503,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
     191,   192,   193,     0,   194,   195,   196,   197,   198,   199,
       0,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,     2,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     0,     8,     0,     0,     0,   373,   374,
       0,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,   464,   465,    23,   467,   375,    26,   468,    28,    29,
       0,    30,    31,    32,    33,   469,    35,    36,    37,    38,
      39,    40,   471,    42,    43,   472,     0,    45,    46,    47,
     474,   475,    50,   476,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,    72,    73,    74,    75,     0,
       0,    76,    77,     0,     0,     0,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,     0,     0,    89,
       0,    90,    91,    92,    93,     0,    94,     0,     0,     0,
     483,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   104,   105,   106,     0,     0,
       0,   107,   108,     0,   110,   111,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,   120,     0,
       0,     0,     0,     0,   123,   124,   125,     0,     0,     0,
     126,     0,   127,   128,     0,     0,     0,   131,     0,   132,
       0,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,     0,     0,   144,   145,   146,     0,   377,   148,
     149,   150,   151,   152,   153,   154,   155,   492,   157,   493,
     159,   494,   495,   162,   163,   164,   165,   166,   167,   496,
     169,   497,   498,   499,   500,   174,   175,   501,   502,   178,
     503,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,     0,   191,   192,   193,     0,   194,   195,   196,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,     2,     0,     0,     0,     0,     0,
       0,     3,     0,     0,     0,     7,     0,     0,     0,     0,
       0,   373,   374,     0,    11,    12,   461,    14,    15,    16,
      17,   462,    19,   463,   464,   465,   466,   467,   375,    26,
     468,    28,    29,     0,    30,    31,    32,    33,   469,    35,
     470,    37,    38,    39,    40,   471,    42,    43,   472,     0,
      45,   473,    47,   474,   475,    50,   476,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
     477,   478,    67,     0,    68,    69,    70,   479,     0,    73,
      74,    75,     0,     0,   480,    77,     0,     0,     0,     0,
      79,    80,    81,   481,   482,    84,    85,     0,     0,     0,
       0,     0,     0,     0,    90,    91,    92,    93,     0,    94,
       0,     0,     0,   483,    96,    97,   484,   485,     0,     0,
       0,     0,     0,     0,   100,   101,   102,     0,   104,   105,
     106,     0,     0,     0,     0,     0,     0,   110,   111,     0,
       0,     0,     0,   112,   113,   114,   115,   486,   117,   118,
     487,     0,     0,     0,     0,     0,     0,   488,   489,   125,
       0,     0,     0,   126,     0,   127,   490,     0,     0,     0,
     131,     0,   132,     0,   133,   134,   135,   136,   491,   138,
     139,   140,   141,   142,   143,     0,     0,   144,   145,     0,
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
       0,     0,     0,     0,     3,     0,     0,     0,     7,     0,
       0,     0,     0,     0,   373,   374,     0,    11,    12,   510,
      14,    15,    16,    17,   462,   511,   512,   464,   465,   466,
     467,   375,    26,   468,    28,    29,     0,    30,    31,    32,
      33,   469,    35,   513,    37,   514,   515,    40,   471,    42,
      43,   472,     0,    45,   516,    47,   474,   475,    50,   476,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,   477,   478,    67,     0,    68,    69,    70,
     517,     0,    73,    74,    75,     0,     0,   480,    77,     0,
       0,     0,     0,    79,    80,    81,   481,   482,    84,    85,
       0,     0,     0,     0,     0,     0,     0,    90,    91,    92,
      93,     0,    94,     0,     0,     0,   483,    96,    97,   484,
     485,     0,     0,     0,     0,     0,     0,   100,   101,   102,
       0,   104,   105,   106,     0,     0,     0,     0,     0,     0,
     110,   111,     0,     0,     0,     0,   112,   113,   114,   115,
     486,   117,   118,   487,     0,     0,     0,     0,     0,     0,
     488,   489,   125,     0,     0,     0,   126,     0,   127,   490,
       0,     0,     0,   131,     0,   132,     0,   133,   134,   135,
     136,   491,   138,   139,   140,   141,   142,   143,     0,     0,
     144,   145,     0,     0,   377,   148,   149,   150,   151,   152,
     153,   154,   155,   492,   518,   493,   159,   494,   495,   162,
     163,   164,   165,   166,   167,   496,   169,   497,   498,   499,
     500,   174,   175,   501,   502,   178,   503,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,     0,   191,
     192,   193,     0,   194,   195,   196,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     528,     0,     0,     0,     0,     0,     0,     7,     0,   729,
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
     489,   125,     0,     0,     0,   126,   730,   127,   490,     0,
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
     231,   232,   233,   234,   235,   236,   237,   238,   239,   528,
       0,     0,     0,     0,     0,     0,     7,     0,     0,     0,
       0,     0,   373,   374,     0,    11,    12,   510,    14,    15,
      16,    17,   462,   511,   512,   464,   465,   466,   467,   375,
      26,   468,    28,    29,     0,    30,    31,    32,    33,   469,
      35,   513,    37,   514,   515,    40,   471,    42,    43,   472,
       0,    45,   516,    47,   474,   475,    50,   476,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,   477,   478,    67,     0,    68,    69,    70,   517,     0,
      73,    74,    75,     0,     0,   480,    77,     0,     0,     0,
       0,    79,    80,    81,   481,   482,    84,    85,     0,     0,
       0,     0,     0,     0,     0,    90,    91,    92,    93,     0,
      94,     0,     0,     0,   483,    96,    97,   484,   485,     0,
       0,     0,     0,     0,     0,   100,   101,   102,     0,   104,
     105,   106,     0,     0,     0,     0,     0,     0,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   486,   117,
     118,   487,     0,     0,     0,     0,     0,     0,   488,   489,
     125,     0,     0,     0,   126,     0,   127,   490,     0,     0,
       0,     0,     0,   132,     0,   133,   134,   135,   136,   491,
     138,   139,   140,   141,   142,   143,     0,     0,   144,   145,
       0,     0,   377,   148,   149,   150,   151,   152,   153,   154,
     155,   492,   518,   493,   159,   494,   495,   162,   163,   164,
     165,   166,   167,   496,   169,   497,   498,   499,   500,   174,
     175,   501,   502,   178,   503,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,     0,   191,   192,   193,
       0,   194,   195,   196,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   531,     0,
       0,     0,     0,     7,     0,     0,     0,     0,     0,   373,
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
       0,   126,     0,   127,   490,     0,     0,     0,     0,     0,
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
      79,    80,    81,   481,   482,    84,    85,     0,     0,     0,
       0,     0,     0,     0,    90,    91,    92,    93,     0,    94,
       0,     0,     0,   483,    96,    97,   484,   485,     0,     0,
       0,     0,     0,     0,   100,   101,   102,     0,   104,   105,
    1008,     0,     0,     0,  1009,     0,     0,   110,   111,     0,
       0,     0,     0,   112,   113,   114,   115,   486,   117,   118,
     487,     0,     0,     0,     0,     0,     0,   488,   489,   125,
       0,     0,     0,   126,  1381,   127,   490,     0,     0,     0,
    1382,     0,   132,     0,   133,   134,   135,   136,   491,   138,
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
     489,   125,     0,     0,     0,   126,   703,   127,   490,     0,
       0,     0,   704,     0,   132,     0,   133,   134,   135,   136,
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
     510,    14,    15,    16,    17,   462,   511,   512,   464,   465,
     466,   467,   375,    26,   468,    28,    29,     0,    30,    31,
      32,    33,   469,    35,   513,    37,   514,   515,    40,   471,
      42,    43,   472,     0,    45,   516,    47,   474,   475,    50,
     476,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,   477,   478,    67,     0,    68,    69,
      70,   517,     0,    73,    74,    75,     0,     0,   480,    77,
       0,     0,     0,     0,    79,    80,    81,   481,   482,    84,
      85,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      92,    93,     0,    94,     0,     0,     0,   483,    96,    97,
     484,   485,     0,     0,     0,     0,     0,     0,   100,   101,
     102,     0,   104,   105,   106,     0,     0,     0,     0,     0,
       0,   110,   111,     0,     0,     0,     0,   112,   113,   114,
     115,   486,   117,   118,   487,     0,     0,     0,     0,     0,
       0,   488,   489,   125,     0,     0,     0,   126,   748,   127,
     490,     0,     0,     0,   749,     0,   132,     0,   133,   134,
     135,   136,   491,   138,   139,   140,   141,   142,   143,     0,
       0,   144,   145,     0,     0,   377,   148,   149,   150,   151,
     152,   153,   154,   155,   492,   518,   493,   159,   494,   495,
     162,   163,   164,   165,   166,   167,   496,   169,   497,   498,
     499,   500,   174,   175,   501,   502,   178,   503,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
     191,   192,   193,     0,   194,   195,   196,   197,   198,   199,
       0,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,     7,     0,     0,     0,     0,     0,   373,   374,     0,
      11,    12,   461,    14,    15,    16,    17,   462,    19,   463,
     464,   465,  1007,   467,   375,    26,   468,    28,    29,     0,
      30,    31,    32,    33,   469,    35,   470,    37,    38,    39,
      40,   471,    42,    43,   472,     0,    45,   473,    47,   474,
     475,    50,   476,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,   477,   478,    67,     0,
      68,    69,    70,   479,     0,    73,    74,    75,     0,     0,
     480,    77,     0,     0,     0,     0,    79,    80,    81,   481,
     482,    84,    85,  1340,     0,     0,     0,     0,     0,     0,
      90,    91,    92,    93,     0,    94,     0,     0,     0,   483,
      96,    97,   484,   485,     0,     0,     0,     0,     0,     0,
     100,   101,   102,     0,   104,   105,  1008,     0,     0,     0,
    1009,     0,     0,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   486,   117,   118,   487,     0,     0,     0,
       0,     0,     0,   488,   489,   125,     0,     0,     0,   126,
       0,   127,   490,     0,     0,     0,     0,     0,   132,     0,
     133,   134,   135,   136,   491,   138,   139,   140,   141,   142,
     143,     0,     0,  1010,   145,     0,     0,   377,   148,   149,
     150,   151,   152,   153,   154,   155,   492,   157,   493,   159,
     494,   495,   162,   163,   164,   165,   166,   167,   496,   169,
     497,   498,   499,   500,   174,   175,   501,   502,   178,   503,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,     0,   191,   192,   193,     0,   194,   195,   196,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,     7,     0,     0,     0,     0,     0,   373,
     374,     0,    11,    12,   461,    14,    15,    16,    17,   462,
      19,   463,   464,   465,  1007,   467,   375,    26,   468,    28,
      29,     0,    30,    31,    32,    33,   469,    35,   470,    37,
      38,    39,    40,   471,    42,    43,   472,     0,    45,   473,
      47,   474,   475,    50,   476,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,   477,   478,
      67,     0,    68,    69,    70,   479,     0,    73,    74,    75,
       0,     0,   480,    77,     0,     0,     0,     0,    79,    80,
      81,   481,   482,    84,    85,     0,     0,     0,     0,     0,
       0,     0,    90,    91,    92,    93,     0,    94,     0,     0,
       0,   483,    96,    97,   484,   485,     0,     0,     0,     0,
       0,     0,   100,   101,   102,     0,   104,   105,  1008,     0,
       0,     0,  1009,     0,     0,   110,   111,     0,     0,     0,
       0,   112,   113,   114,   115,   486,   117,   118,   487,     0,
       0,     0,     0,     0,     0,   488,   489,   125,     0,     0,
       0,   126,     0,   127,   490,     0,     0,     0,     0,     0,
     132,     0,   133,   134,   135,   136,   491,   138,   139,   140,
     141,   142,   143,     0,     0,  1010,   145,     0,     0,   377,
     148,   149,   150,   151,   152,   153,   154,   155,   492,   157,
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
      79,    80,    81,   481,   482,    84,    85,     0,     0,     0,
       0,     0,     0,     0,    90,    91,    92,    93,     0,    94,
       0,     0,     0,   483,    96,    97,   484,   485,     0,     0,
       0,     0,     0,     0,   100,   101,   102,     0,   104,   105,
    1008,     0,     0,     0,  1009,     0,     0,   110,   111,     0,
       0,     0,     0,   112,   113,   114,   115,   486,   117,   118,
     487,     0,     0,     0,     0,     0,     0,   488,   489,   125,
       0,     0,     0,   126,     0,   127,   490,     0,     0,     0,
       0,     0,   132,     0,   133,   134,   135,   136,   491,   138,
     139,   140,   141,   142,   143,     0,     0,   144,   145,     0,
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
       0,    14,    15,    16,    17,   462,     0,     0,   464,   465,
     466,     0,   375,    26,   468,    28,    29,     0,    30,    31,
      32,    33,   469,    35,     0,    37,     0,     0,    40,   471,
      42,    43,   472,     0,    45,     0,    47,     0,     0,    50,
     476,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,   477,   478,    67,     0,    68,    69,
      70,     0,     0,    73,    74,    75,     0,     0,   480,    77,
       0,     0,     0,     0,    79,    80,    81,   481,   482,    84,
      85,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      92,    93,     0,    94,     0,     0,     0,   483,    96,    97,
     484,   485,     0,     0,     0,     0,     0,     0,   100,   101,
     102,     0,   104,   105,     0,     0,     0,     0,     0,     0,
       0,   110,   111,     0,     0,     0,     0,   112,   113,   114,
     115,   486,   117,   118,   487,     0,     0,     0,     0,     0,
       0,   488,   489,   125,     0,     0,     0,   126,     0,   127,
     490,     0,     0,     0,     0,     0,   132,     0,   133,   134,
     135,   136,   491,   138,   139,   140,   141,   142,   143,     0,
       0,     0,   145,     0,     0,   377,   148,   149,   150,   151,
     152,   153,   154,   155,   492,     0,   493,   159,   494,   495,
     162,   163,   164,   165,   166,   167,   496,   169,   497,   498,
     499,   500,   174,   175,     0,   502,   178,   503,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
     191,   192,   193,     0,   194,   195,   196,   197,   198,   199,
       0,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        72,   614,   383,   615,   616,   617,   618,   754,   726,     4,
       5,     6,   312,   572,    86,   829,   830,   569,   247,   737,
     817,   935,   568,   569,   905,   726,   967,   399,   240,  1105,
    1207,   243,    72,  1367,   130,  1296,   108,    51,   113,   817,
    1220,  1221,    49,    23,  1031,    52,   568,   591,   120,   657,
     122,   423,  1271,    90,    24,    90,     7,   438,   439,   594,
      90,   596,   597,   864,   599,   124,   601,    90,   800,  1180,
      92,   443,    92,   136,   609,   610,   102,   102,    23,    23,
      90,   102,    92,    32,   102,   113,    89,    92,    95,    38,
      39,   102,   124,   102,    95,   138,   141,   829,   830,    39,
     102,   136,    42,   804,    47,   806,   152,    56,    39,    58,
      59,   925,   107,   102,   102,    48,   113,   209,    67,    91,
     861,   141,    55,   169,    40,   105,   169,    28,    59,   101,
     189,   141,   864,   141,   875,    75,    92,   152,   118,   111,
     989,   163,   217,   186,    93,   191,    48,   147,    72,   121,
     102,   179,   870,    55,   169,   247,    57,   189,   183,    92,
     181,   101,    86,   143,   108,   183,    35,   147,   900,   180,
     150,     4,    41,   176,   183,     8,   191,    46,   179,   181,
     123,   102,    90,   180,   108,    54,   102,   210,   211,   177,
     170,   180,   229,   925,  1374,   209,   120,    66,   122,   229,
     918,   227,   225,   266,     8,    23,   924,   163,  1009,   154,
     154,     8,     9,  1062,  1433,   287,   963,   168,    22,   315,
    1101,   266,   162,   245,   246,   300,   248,  1141,   180,  1305,
    1171,   266,   784,   247,  1031,  1032,   206,   244,   939,  1180,
    1351,   849,   850,   265,   249,   250,   266,  1508,   320,   180,
     257,   323,   259,  1031,  1032,   277,   266,  1591,   266,   180,
    1247,   783,   806,   270,   271,   272,     4,   274,   217,   276,
       8,   152,   252,  1607,   163,     8,     9,  1009,   813,    90,
     320,  1615,   102,   323,   117,   130,   119,   105,   169,   245,
     246,   672,   248,   162,   127,    27,   165,  1474,   125,   255,
     118,    98,   210,   211,   102,   194,    92,   102,    90,   265,
     179,   152,    44,   117,   147,   119,   388,   225,   390,  1133,
     117,   277,   119,   395,   128,   143,  1027,   399,   169,   147,
     160,  1511,   150,   405,   102,   204,   147,   102,   102,   568,
     412,   722,   102,   147,  1158,   175,   718,   559,   193,   721,
     147,   423,   170,    92,   151,   261,   183,   429,   154,   141,
     180,  1437,   268,   287,   150,    98,  1546,    92,   440,   108,
     167,   443,   444,   445,   446,   447,  1108,   101,   112,   117,
     452,   119,   180,   108,   117,   180,   119,    63,   460,   127,
     187,   147,    68,   116,   150,   150,   320,   121,   292,   323,
      90,  1133,   213,   214,     8,     9,   140,   301,   205,   147,
    1351,   150,   180,  1227,   147,   180,   180,   217,   151,   153,
     180,   262,   222,  1304,   147,   150,  1158,   150,   269,   424,
       8,   426,   175,   428,   167,     8,     9,   113,   279,   913,
    1516,   915,   437,   995,    22,   188,   202,   442,   520,   995,
    1247,   141,   186,   448,   187,   450,   451,    90,   453,  1256,
     240,   241,    42,   175,   459,   147,   390,   147,  1544,  1247,
    1267,   395,   205,  1525,  1526,   399,   188,   549,  1256,   147,
      60,   405,    62,   263,   958,   557,   960,   142,   412,  1267,
     170,    71,   873,   874,    98,  1227,   130,   878,   131,   423,
     262,   142,   170,   136,   159,   429,  1558,   269,   131,   217,
     144,   219,  1564,   117,   131,   119,   440,   279,   159,   443,
     444,   445,   446,   447,   147,    98,   907,  1603,   452,  1605,
     147,   526,   131,    48,   150,  1449,   460,   633,   634,   117,
      55,   119,   537,   147,   117,  1621,   119,   151,   147,    92,
     128,   163,   131,    95,   783,    95,   256,   136,    73,   256,
      90,   556,   113,   167,   193,   108,   108,   267,   108,   147,
     267,   101,   147,   202,   147,   150,   150,    92,   151,   270,
     271,   272,   194,   187,   131,   276,   322,   184,   185,   136,
     662,   327,   664,    41,   167,   667,   520,   636,   113,   113,
     639,   205,  1349,   642,   150,   224,  1353,   226,   147,   147,
     222,   150,   150,   147,   187,  1412,   150,   689,   690,   691,
     213,   214,   215,   293,   294,   549,   217,   148,   219,   150,
     293,   294,   205,   557,  1412,   630,   224,   709,   226,   711,
     635,   387,   150,   389,   113,  1258,   718,   122,   123,   721,
     122,   123,   284,   285,   612,   613,   619,   620,   831,   832,
    1212,   621,   622,  1424,  1425,  1479,   150,  1481,   280,   281,
     282,   283,   284,   150,   286,   287,   288,   289,   290,   116,
     116,   753,   116,   295,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,   116,   116,   113,   116,   116,   208,
     126,   147,   116,   116,   116,   116,   147,  1521,   134,   135,
     150,   137,   217,   113,   147,  1462,   234,   234,  1465,   145,
     715,   793,  1536,   149,   235,   151,  1285,   150,   800,   113,
     156,   147,     0,  1033,     3,    88,   183,   161,   183,   242,
      45,   192,    96,   667,   148,    97,   172,  1479,   139,  1481,
     745,   746,   150,    23,    42,  1136,    42,   829,   830,   831,
     832,    42,   177,   146,   113,   689,   690,   691,   177,   195,
     196,   197,   198,   199,   200,   177,   239,   297,   291,   430,
     775,   291,  1529,   180,  1396,   709,   286,   711,   277,  1521,
    1403,  1404,   864,  1511,   718,    36,   277,   721,   113,   147,
     113,    42,   180,   147,  1536,   147,   180,   150,   880,    50,
     150,    52,   150,   150,   150,    29,    15,   206,    23,    60,
     180,    62,   223,   113,   183,   183,   102,   162,    67,   753,
      71,   164,   164,   223,    75,  1216,    90,    90,    90,   143,
     102,   913,   102,   915,    23,   154,   154,   121,   126,   292,
     177,   239,   177,   925,   126,   177,   180,   180,   177,    90,
     180,    39,    92,    92,   102,   106,   107,   108,   180,   793,
     177,   136,   147,  1486,  1487,    90,   800,   180,   180,   180,
     177,   180,   180,   177,   177,   177,   958,   217,   960,   136,
     541,   542,   177,   544,   545,   546,   547,   180,   229,    27,
     177,   183,   113,   554,   555,   829,   830,   831,   832,   164,
     113,   113,   113,   141,   177,   136,   126,   178,    90,   570,
     136,    23,   163,   279,   219,   292,  1539,   147,   113,   580,
     581,  1003,    90,   247,  1006,   177,   126,  1009,   126,   190,
     864,   154,    92,   113,  1325,   136,   113,   147,  1020,   141,
    1022,    95,    95,   194,   177,   177,   880,    29,   953,    23,
     147,   113,   113,   147,   183,   177,    75,   238,   102,   102,
     150,   251,   141,   150,   150,   141,   260,   138,   278,    23,
     253,   222,    23,   279,    23,   229,   219,   219,   299,   913,
     641,   915,   219,   644,   183,   141,   138,  1378,   180,   180,
     113,   925,   113,    73,   102,   180,   180,   136,   126,   177,
       6,   229,   183,   254,   280,   180,   180,   225,   225,   225,
     179,   225,   136,   101,   101,   180,   180,   180,   177,   141,
     275,   141,   180,   279,   958,  1030,   960,    74,   177,   280,
     281,   282,   283,   284,    23,   286,   287,   288,   289,   290,
     243,    23,  1124,   250,   295,   296,    92,   243,   164,   120,
     177,  1133,    92,   179,   179,  1060,   264,    90,   147,   177,
     177,  1143,   177,    23,   177,   102,   180,   273,  1150,  1003,
     180,   164,  1006,    48,    90,  1009,  1158,   113,   189,    90,
      23,   102,   113,   217,   113,   258,  1020,   280,  1022,   179,
     189,   189,   177,   298,   113,  1177,   179,    89,   176,   113,
     113,   113,   147,   189,   180,   113,   247,  1112,   217,   240,
     191,   217,   244,   671,   286,   298,  1198,  1066,   865,  1108,
     397,  1516,  1544,   280,  1203,  1207,   393,   926,   298,  1211,
     923,  1006,   299,   299,   795,   436,   286,   244,  1319,  1143,
    1125,   802,  1225,  1148,   299,  1227,  1211,   999,   417,  1223,
    1220,  1159,  1155,   520,  1150,   592,   644,   308,   593,  1164,
     754,  1564,  1171,   832,  1558,  1102,  1256,   427,   427,  1065,
     915,  1198,  1267,  1032,  1208,  1412,  1260,  1409,  1041,   899,
    1090,  1294,  1427,    -1,    -1,  1257,    -1,    -1,    -1,    -1,
    1124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1133,
      -1,    -1,    -1,    -1,    -1,   866,    -1,    -1,    -1,  1143,
      -1,   872,    -1,    -1,    -1,    -1,  1150,    -1,    -1,    -1,
    1302,    -1,    -1,    -1,  1158,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1316,  1317,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1177,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1340,    -1,
      -1,    -1,    -1,    -1,  1198,    -1,    -1,    -1,  1350,    -1,
      -1,    -1,  1354,  1207,    -1,    -1,   937,  1211,    -1,    -1,
      -1,    -1,    -1,    -1,   945,    -1,   947,   948,    -1,    -1,
      -1,    -1,    -1,  1227,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   962,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   973,   974,   975,    -1,   977,   978,   979,   980,
     981,   982,    -1,   984,   985,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   999,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1023,    -1,  1025,  1026,    -1,    -1,  1302,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1458,    -1,    -1,    -1,
      -1,  1463,  1316,  1317,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1052,  1474,    -1,    -1,    -1,    -1,  1479,    -1,  1481,
      -1,    -1,    -1,    -1,    -1,    -1,  1340,    -1,    -1,  1070,
      -1,    -1,    -1,    -1,    -1,    -1,  1350,    -1,    -1,    -1,
    1354,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1512,    -1,    -1,  1515,    -1,    -1,    -1,    -1,    -1,  1521,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1532,    -1,    -1,    -1,  1536,    -1,    -1,  1118,    -1,    -1,
      -1,    -1,  1123,    -1,    -1,    -1,  1548,    -1,    -1,    -1,
    1552,    -1,    -1,    -1,  1135,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1145,  1146,    -1,    -1,    -1,    -1,
      -1,  1496,  1153,  1154,    -1,    -1,  1578,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1595,    -1,  1597,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1458,    -1,    -1,    -1,  1610,  1463,
      -1,    -1,  1614,    -1,    -1,    -1,    -1,  1619,    -1,    -1,
    1474,    -1,    -1,    -1,    -1,  1479,    -1,  1481,    -1,  1210,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1238,  1512,    -1,
    1241,  1515,  1243,    -1,    -1,    -1,    -1,  1521,    -1,    30,
      31,    -1,    33,    34,    -1,    36,    -1,    -1,  1532,    -1,
      -1,    42,  1536,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    52,    53,    -1,  1548,    -1,    -1,    -1,  1552,    60,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1578,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1315,    -1,    -1,    -1,    -1,    -1,
    1321,  1595,    -1,  1597,    -1,   106,   107,   108,    -1,  1330,
      -1,    -1,    -1,    -1,    -1,    -1,  1610,  1338,  1339,    -1,
    1614,    -1,    -1,    -1,    -1,  1619,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1357,  1358,  1359,  1360,
    1361,    -1,  1363,  1364,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,  1390,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   212,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   222,    -1,    -1,    -1,    -1,    -1,  1448,    -1,    -1,
      -1,    -1,  1453,    -1,    -1,    -1,  1457,    -1,  1459,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   280,
     281,   282,   283,   284,    -1,   286,   287,   288,   289,   290,
      -1,    -1,    -1,    -1,   295,   296,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1554,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1576,     3,    -1,    -1,    -1,
    1581,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    -1,    23,    -1,    -1,  1600,
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
     297,   298,   299,   300,   301,   302,   303,     3,    -1,    -1,
      -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,
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
     170,    -1,    -1,   173,   174,   175,    -1,   177,    -1,   179,
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
      -1,    -1,   173,   174,   175,    -1,   177,    -1,   179,    -1,
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
      -1,   169,   170,    -1,    -1,   173,   174,   175,    -1,    -1,
      -1,   179,   180,   181,   182,    -1,   184,   185,   186,    -1,
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
     175,    -1,    -1,    -1,   179,   180,   181,   182,    -1,   184,
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
      -1,    -1,   150,   151,   152,   153,   154,    -1,    -1,    -1,
      -1,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,   169,   170,    -1,    -1,   173,   174,   175,    -1,    -1,
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
     175,    -1,    -1,    -1,   179,    -1,   181,   182,    -1,   184,
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
      -1,   153,   154,    -1,    -1,    -1,    -1,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,
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
      -1,   150,   151,    -1,   153,   154,    -1,    -1,    -1,    -1,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
      -1,    -1,    -1,    -1,   173,   174,   175,    -1,    -1,    -1,
     179,    -1,   181,   182,    -1,    -1,    -1,   186,    -1,   188,
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
      -1,    17,    -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,
      -1,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    -1,    90,    91,    92,    93,    -1,    95,
      96,    97,    -1,    -1,   100,   101,    -1,    -1,    -1,    -1,
     106,   107,   108,   109,   110,   111,   112,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   120,   121,   122,   123,    -1,   125,
      -1,    -1,    -1,   129,   130,   131,   132,   133,    -1,    -1,
      -1,    -1,    -1,    -1,   140,   141,   142,    -1,   144,   145,
     146,    -1,    -1,    -1,    -1,    -1,    -1,   153,   154,    -1,
      -1,    -1,    -1,   159,   160,   161,   162,   163,   164,   165,
     166,    -1,    -1,    -1,    -1,    -1,    -1,   173,   174,   175,
      -1,    -1,    -1,   179,    -1,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,    -1,   190,   191,   192,   193,   194,   195,
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
     296,   297,   298,   299,   300,   301,   302,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    -1,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    -1,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    -1,    90,    91,    92,
      93,    -1,    95,    96,    97,    -1,    -1,   100,   101,    -1,
      -1,    -1,    -1,   106,   107,   108,   109,   110,   111,   112,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,   121,   122,
     123,    -1,   125,    -1,    -1,    -1,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,    -1,    -1,   140,   141,   142,
      -1,   144,   145,   146,    -1,    -1,    -1,    -1,    -1,    -1,
     153,   154,    -1,    -1,    -1,    -1,   159,   160,   161,   162,
     163,   164,   165,   166,    -1,    -1,    -1,    -1,    -1,    -1,
     173,   174,   175,    -1,    -1,    -1,   179,    -1,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,    -1,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,    -1,    -1,
     203,   204,    -1,    -1,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,    -1,   252,
     253,   254,    -1,   256,   257,   258,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    23,
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
     174,   175,    -1,    -1,    -1,   179,   180,   181,   182,    -1,
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
     294,   295,   296,   297,   298,   299,   300,   301,   302,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,
      -1,    -1,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      -1,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    90,    91,    92,    93,    -1,
      95,    96,    97,    -1,    -1,   100,   101,    -1,    -1,    -1,
      -1,   106,   107,   108,   109,   110,   111,   112,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   120,   121,   122,   123,    -1,
     125,    -1,    -1,    -1,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,    -1,    -1,   140,   141,   142,    -1,   144,
     145,   146,    -1,    -1,    -1,    -1,    -1,    -1,   153,   154,
      -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,   164,
     165,   166,    -1,    -1,    -1,    -1,    -1,    -1,   173,   174,
     175,    -1,    -1,    -1,   179,    -1,   181,   182,    -1,    -1,
      -1,    -1,    -1,   188,    -1,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,    -1,    -1,   203,   204,
      -1,    -1,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,    -1,   252,   253,   254,
      -1,   256,   257,   258,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,    16,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,    27,
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
      -1,   179,    -1,   181,   182,    -1,    -1,    -1,    -1,    -1,
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
     106,   107,   108,   109,   110,   111,   112,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   120,   121,   122,   123,    -1,   125,
      -1,    -1,    -1,   129,   130,   131,   132,   133,    -1,    -1,
      -1,    -1,    -1,    -1,   140,   141,   142,    -1,   144,   145,
     146,    -1,    -1,    -1,   150,    -1,    -1,   153,   154,    -1,
      -1,    -1,    -1,   159,   160,   161,   162,   163,   164,   165,
     166,    -1,    -1,    -1,    -1,    -1,    -1,   173,   174,   175,
      -1,    -1,    -1,   179,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,    -1,   190,   191,   192,   193,   194,   195,
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
     144,   145,   146,    -1,    -1,    -1,    -1,    -1,    -1,   153,
     154,    -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,
     164,   165,   166,    -1,    -1,    -1,    -1,    -1,    -1,   173,
     174,   175,    -1,    -1,    -1,   179,   180,   181,   182,    -1,
      -1,    -1,   186,    -1,   188,    -1,   190,   191,   192,   193,
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
     142,    -1,   144,   145,   146,    -1,    -1,    -1,    -1,    -1,
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
     110,   111,   112,   113,    -1,    -1,    -1,    -1,    -1,    -1,
     120,   121,   122,   123,    -1,   125,    -1,    -1,    -1,   129,
     130,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,
     140,   141,   142,    -1,   144,   145,   146,    -1,    -1,    -1,
     150,    -1,    -1,   153,   154,    -1,    -1,    -1,    -1,   159,
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
      -1,    -1,   150,    -1,    -1,   153,   154,    -1,    -1,    -1,
      -1,   159,   160,   161,   162,   163,   164,   165,   166,    -1,
      -1,    -1,    -1,    -1,    -1,   173,   174,   175,    -1,    -1,
      -1,   179,    -1,   181,   182,    -1,    -1,    -1,    -1,    -1,
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
     106,   107,   108,   109,   110,   111,   112,    -1,    -1,    -1,
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
      -1,    33,    34,    35,    36,    37,    -1,    -1,    40,    41,
      42,    -1,    44,    45,    46,    47,    48,    -1,    50,    51,
      52,    53,    54,    55,    -1,    57,    -1,    -1,    60,    61,
      62,    63,    64,    -1,    66,    -1,    68,    -1,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    -1,    90,    91,
      92,    -1,    -1,    95,    96,    97,    -1,    -1,   100,   101,
      -1,    -1,    -1,    -1,   106,   107,   108,   109,   110,   111,
     112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,   121,
     122,   123,    -1,   125,    -1,    -1,    -1,   129,   130,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,   141,
     142,    -1,   144,   145,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   153,   154,    -1,    -1,    -1,    -1,   159,   160,   161,
     162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,    -1,
      -1,   173,   174,   175,    -1,    -1,    -1,   179,    -1,   181,
     182,    -1,    -1,    -1,    -1,    -1,   188,    -1,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,    -1,   204,    -1,    -1,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,    -1,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
     252,   253,   254,    -1,   256,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302
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
     552,   608,   609,    27,    28,    44,   177,   207,   385,   177,
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
     233,   236,   237,   239,   471,   608,   609,   116,   116,   116,
      32,    38,    39,    56,    58,    59,    67,    93,   217,   608,
     113,   116,   116,   180,   385,   608,   147,   116,    14,   607,
     608,    16,   608,   116,   116,   116,   463,   147,    24,   206,
     208,   217,   219,   150,   217,   219,   217,   217,   222,   113,
     147,   367,   234,   234,   235,   150,   147,   113,   319,   320,
       0,   319,   322,   323,    27,    44,   325,   326,   183,   183,
     102,   183,   386,    35,    41,    46,    54,    66,   162,   165,
     179,   204,   390,   395,   396,   397,   414,   415,   419,   401,
     402,   608,   161,    88,   126,   134,   135,   137,   145,   149,
     151,   156,   172,   195,   196,   197,   198,   199,   200,   455,
     456,   242,   152,   169,   191,   112,   140,   153,   186,   193,
     202,   130,   144,    45,   192,    96,    97,   152,   169,   454,
     147,   460,   463,   184,   185,   148,   475,   476,   471,   475,
     471,   150,   475,   139,   150,   177,   177,   177,    23,   606,
     175,   188,   175,   188,   160,   175,   376,   609,   376,   608,
     163,   194,    42,   377,    42,   608,   146,   113,   353,    39,
      42,    75,   101,   162,   607,   213,   214,   215,   293,   294,
     239,   579,   608,   286,   608,   291,   291,   293,   294,   297,
     280,   288,   356,   607,   385,   180,   385,    39,    59,   180,
     528,   529,   385,   180,   186,   608,   388,   277,   277,   113,
     409,   113,   180,   380,   381,   147,   382,   385,   154,   606,
     108,   154,   347,   606,   406,   408,   608,   113,   385,    23,
     180,   607,   608,   608,   608,   427,   428,   608,   385,   180,
     385,   385,   530,   608,   385,   147,   147,   385,   180,   186,
     608,   427,   180,    29,   491,   492,   493,   385,     7,   168,
      15,   385,   206,    23,   388,   388,   180,   388,   388,   388,
     388,   223,   546,   547,   608,   368,   388,   388,   385,   407,
     413,   608,   319,   183,   183,   326,   327,   384,    27,   328,
     384,   388,   387,   113,   162,   164,   164,   388,   388,   102,
      90,    92,   141,   266,   403,   404,   514,   438,   439,   441,
     441,   441,   441,   440,   441,   441,   441,    67,   445,   445,
     444,   446,   446,   446,   446,   447,   447,   448,   448,   223,
      90,    90,    90,   177,   385,   463,   463,   385,   476,   180,
     388,   486,   143,   180,   486,   102,   102,   365,    23,   609,
     609,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,   330,   331,   332,    90,   131,   136,   350,   351,   352,
     608,   131,   136,   154,   154,   330,   606,   121,   126,    49,
      52,    95,   244,   257,   259,   270,   271,   272,   274,   276,
     580,   581,   582,   583,   584,   585,   592,   598,   599,   239,
      90,   229,   359,   292,   608,   608,   608,   126,   177,   177,
     180,   180,   177,   102,   180,   102,   180,   177,   608,    51,
     209,   247,   392,   393,   608,    90,   102,   180,   385,   180,
     607,    92,    39,   607,   606,    92,   102,   136,   404,   514,
     177,   180,   180,   180,   180,   136,   102,   181,   141,   514,
     177,   180,   180,   147,   177,   385,   385,   177,   102,   180,
     102,   180,   181,   608,   492,   493,   124,   189,   177,   177,
     125,   183,    90,   210,   211,   225,    90,   210,   211,   225,
      90,   229,   217,   102,   227,   136,    27,   369,   385,   180,
     177,    40,   102,   326,    27,   183,   108,   183,   608,   164,
     388,   420,   421,   113,   416,   417,   113,    42,   146,   150,
     203,   515,   517,   519,   520,   536,   537,   538,   539,   608,
     113,   388,   113,   141,   404,   141,   141,   403,   404,   441,
     147,   150,   252,   459,   478,   553,   556,   557,   558,   559,
     560,   564,   566,   568,   569,   515,   515,   513,   519,   513,
     177,   178,   102,   180,   180,   142,   159,   142,   159,   131,
     147,   383,   365,   365,   331,   126,   517,   352,   388,   514,
     136,   388,   606,   606,   122,   123,   606,   270,   271,   272,
     276,   608,   256,   267,   256,   267,    23,   279,    92,   108,
     150,   586,   589,   580,    32,    38,    56,    58,    67,    93,
     217,   358,   520,   284,   285,   219,   292,   301,    90,   359,
     292,   606,   147,   530,   531,   608,   530,   531,   141,   514,
     247,    48,    55,    73,   113,   403,   410,   411,   412,   393,
     514,   515,   381,    90,   177,   190,   126,   346,   606,   154,
     126,    92,   346,   113,   388,   136,   136,   404,   147,   388,
     113,   388,   388,   141,    95,   430,   431,   432,    95,   434,
     435,   385,   177,   177,   147,   530,   530,   388,    29,   493,
     124,   189,     8,     9,    98,   117,   119,   187,   382,   488,
     490,   501,   502,   505,    23,   224,   226,   388,   388,   388,
     224,   226,   388,   388,   388,   388,   388,   388,   113,   388,
     388,   353,   370,   102,   183,   177,   367,   238,   549,   550,
     147,   113,   183,   384,   420,    91,   101,   111,   121,   422,
     423,   424,   425,   102,   608,   102,   402,   150,   150,   517,
     150,   138,   169,   186,   516,   608,   608,   388,   141,   388,
     388,   141,   404,   141,   385,   553,   560,   147,   278,   442,
     605,    92,   163,   245,   246,   248,   255,   265,   277,   554,
     555,   574,   575,   576,   577,   600,   603,   251,   253,   561,
     579,   260,   565,   601,   240,   241,   263,   570,   571,   138,
     388,   385,   131,   367,   131,   147,   532,   351,   388,   279,
      23,    92,   108,   150,   593,    23,   586,   359,   516,   219,
     219,   461,   280,   299,   358,   219,   183,   177,   385,   180,
     180,   138,   180,   180,   388,   141,   113,   113,   388,   608,
     412,    73,   515,   388,   606,   102,   346,   408,   388,   388,
     136,   177,   385,   428,   388,   388,   108,   431,    95,   179,
     113,   515,   108,   435,   177,   177,   385,   180,   180,   126,
     187,   490,     6,   608,   187,   501,   183,   225,   225,   225,
     225,   229,   547,   179,   136,   370,   472,   551,   550,   388,
     413,   606,   122,   123,   424,   425,   425,   421,   101,   418,
     417,   180,   186,   515,   518,   180,   180,   180,   388,   388,
     141,   388,   177,   180,   553,   567,   243,   209,   247,   261,
     268,   604,    92,   249,   250,   602,   243,   557,   604,   444,
     574,   558,   141,   275,   562,   563,   602,   279,   573,    74,
     572,   177,   387,    23,   130,   193,   595,   596,   597,    23,
     594,   595,   264,   590,   587,   588,   589,   164,   608,   250,
     359,   461,   177,   388,   608,   608,   411,   388,   120,    92,
     606,   388,   177,   179,   388,   388,   608,   179,   113,   179,
     177,   493,   608,   187,   493,   608,   388,   388,   388,   388,
     388,   388,   388,   150,   202,   383,   177,   425,   606,    90,
     180,   102,   180,   388,   177,   446,    47,   123,   444,   444,
     262,   269,   279,   578,   578,   559,   147,   273,   177,   593,
     593,   597,   102,   180,    23,   591,   602,   180,   102,   361,
     362,   461,   113,   217,   300,   280,   164,    48,   388,   346,
     388,    90,   388,   608,   388,    89,   176,   494,   493,   608,
     189,   493,   113,   472,   515,   515,    90,   444,   444,   191,
     385,    23,   258,   589,   102,   425,   514,   608,   113,   217,
     608,   361,   113,   515,   179,     4,   127,   497,   498,   500,
     502,    22,   128,   495,   496,   499,   502,   189,   493,   189,
     608,   515,   444,   177,   362,   425,   298,   608,   113,   217,
     608,   179,   388,    89,   127,   500,   176,   128,   499,   189,
     102,   180,   388,   298,   608,   113,   388,   113,   383,   286,
     298,   608,   608,   299,   388,   299,   102,   180,   461,   461,
     113,   383,   191,   608,   280,   180,   608,   383,   217,   113,
     608,   299,   461
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
     586,   587,   587,   588,   588,   589,   590,   590,   591,   591,
     592,   592,   592,   593,   593,   594,   594,   595,   595,   596,
     596,   597,   597,   598,   599,   599,   600,   600,   600,   601,
     602,   602,   602,   602,   603,   603,   604,   604,   605,   606,
     607,   607,   608,   608,   608,   608,   608,   608,   608,   608,
     608,   608,   608,   608,   608,   608,   608,   608,   609,   609,
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
     609,   609,   609,   609,   609,   609,   609,   609
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
       1,     0,     1,     1,     3,     4,     0,     2,     0,     2,
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
       1,     1,     1,     1,     1,     1,     1,     1
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
       318,     0,    -1,   320,    -1,   303,   320,    -1,   319,    -1,
     320,   319,    -1,   303,   319,    -1,   303,   320,   319,    -1,
       3,    -1,   322,    -1,   321,   322,    -1,   323,    -1,   321,
     323,    -1,   207,   208,    23,   183,    -1,   207,   208,    23,
     125,    23,   183,    -1,   325,   183,   384,    -1,   326,   183,
     384,    -1,   325,   183,   326,   183,   384,    -1,   384,    -1,
     324,    -1,   324,   325,   183,    -1,   324,   326,   183,    -1,
     324,   325,   183,   326,   183,    -1,    28,   154,   607,   126,
     606,   183,    -1,   327,    -1,   325,   183,   327,    -1,   328,
      -1,   326,   183,   328,    -1,   333,    -1,   334,    -1,   335,
      -1,   337,    -1,   354,    -1,   357,    -1,   349,    -1,   329,
      -1,   339,    -1,   375,    -1,   360,    -1,   363,    -1,   338,
      -1,    27,   108,    75,   330,    -1,    27,    75,   608,   330,
      -1,   331,    -1,   330,   331,    -1,   332,   126,   532,    -1,
      76,    -1,    84,    -1,    77,    -1,    78,    -1,    79,    -1,
      80,    -1,    85,    -1,    81,    -1,    82,    -1,    83,    -1,
     336,    -1,   343,    -1,   344,    -1,   364,    -1,   340,    -1,
     341,    -1,   342,    -1,   540,    -1,   345,    -1,   348,    -1,
      27,   154,   607,   126,   606,    -1,    27,    31,   175,    -1,
      27,    31,   188,    -1,    27,   108,    39,   154,   606,    -1,
      27,   108,    42,   154,   606,    -1,    27,    52,   608,    23,
      -1,    27,   254,   579,    -1,    27,    53,   163,    -1,    27,
      53,   194,    -1,    27,   108,   162,   121,   122,    -1,    27,
     108,   162,   121,   123,    -1,    27,    34,   175,   102,   142,
      -1,    27,    34,   175,   102,   159,    -1,    27,    34,   160,
     102,   142,    -1,    27,    34,   160,   102,   159,    -1,    27,
     108,   101,   606,    -1,    27,    30,   606,    -1,    44,    57,
     606,    -1,    44,    57,   347,   606,    -1,    44,    57,   606,
      92,   346,    -1,    44,    57,   347,   606,    92,   346,    -1,
     606,    -1,   346,   102,   606,    -1,   154,   607,   126,    -1,
     108,    39,   154,    -1,    44,    28,   606,    -1,    44,    28,
     154,   607,   126,   606,    -1,    44,    28,   606,    92,   346,
      -1,    44,    28,   154,   607,   126,   606,    92,   346,    -1,
      27,   106,   146,   350,    -1,    90,   517,   351,    -1,   351,
      -1,   352,    -1,   131,    -1,   131,   352,    -1,   136,   388,
      -1,   113,   608,    -1,   113,   608,   514,    -1,    27,   107,
     353,   136,   388,    -1,    27,   107,   353,   131,    -1,    27,
     107,   353,   131,   136,   388,    -1,   356,    -1,   355,   356,
      -1,   281,    -1,   282,    -1,   283,    -1,   284,    -1,   163,
      -1,   194,    -1,   222,   294,    -1,   222,   293,    -1,   295,
     294,    -1,   295,   293,    -1,   286,    -1,   287,   286,    -1,
     290,   291,    -1,   289,   291,    -1,    27,   280,   608,    -1,
      27,   280,   608,   359,    -1,    27,   280,   608,    90,   358,
      -1,    27,   280,   608,    90,   358,   359,    -1,    27,   355,
     280,   608,    -1,    27,   355,   280,   608,   359,    -1,    27,
     355,   280,   608,    90,   358,    -1,    27,   355,   280,   608,
      90,   358,   359,    -1,   520,    -1,   520,   516,    -1,   229,
     285,   219,    -1,   229,   284,   219,    -1,    27,   288,   608,
     292,   219,   461,   164,   361,    -1,    27,   355,   288,   608,
     292,   219,   461,   164,   361,    -1,   362,    -1,   361,   102,
     362,    -1,   461,    -1,   461,   514,    -1,   461,   425,    -1,
     461,   514,   425,    -1,    27,   296,   297,   608,   292,   280,
     608,   113,   608,   298,   388,    -1,    27,   296,   297,   608,
     292,   280,   608,   217,   113,   608,   298,   286,   299,   461,
      -1,    27,   296,   297,   608,   292,   280,   608,   300,   217,
     113,   608,   298,   388,    -1,    27,   296,   297,   608,   301,
     299,   250,   280,   608,   217,   113,   608,   299,   461,   191,
     280,   608,   217,   113,   608,   299,   461,    -1,    27,    33,
     175,    -1,    27,    33,   188,    -1,   150,   180,    -1,   150,
     380,   180,    -1,   150,   180,    90,   515,    -1,   150,   380,
     180,    90,   515,    -1,   230,   367,    -1,   147,   368,   385,
     177,    -1,   368,   369,   183,    -1,    -1,   369,   102,   370,
      -1,    27,   370,    -1,   353,    -1,   353,   136,   388,    -1,
      61,   113,   608,   136,   388,    -1,   233,   235,   388,    -1,
     236,   150,   388,   180,   367,    -1,   231,   234,    -1,   232,
     234,    -1,    27,   376,    -1,    27,    50,   376,    -1,    27,
      36,   376,    -1,   377,    -1,    62,   377,    -1,   379,    -1,
     378,    -1,    42,   609,   365,   383,    -1,    42,   609,   365,
     131,    -1,    60,    42,   609,   365,   367,    -1,    60,    42,
     609,   365,   131,    -1,    71,    42,   609,   365,   147,   387,
     177,    -1,    71,    42,   609,   365,   131,    -1,   381,    -1,
     380,   102,   381,    -1,   113,   608,    -1,   113,   608,   514,
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
     409,   393,    -1,    35,   113,   608,    -1,   400,    -1,   405,
      -1,   394,    -1,   396,    -1,   414,    -1,   419,    -1,   415,
      -1,   395,    -1,   396,    -1,   398,   397,    -1,    41,   113,
      -1,    54,    41,   113,    -1,   399,   401,    -1,   402,    -1,
     401,   102,   113,   402,    -1,   608,   141,   388,    -1,   608,
     514,   141,   388,    -1,   608,   403,   141,   388,    -1,   608,
     514,   403,   141,   388,    -1,   608,   404,   141,   388,    -1,
     608,   514,   404,   141,   388,    -1,   608,   403,   404,   141,
     388,    -1,   608,   514,   403,   404,   141,   388,    -1,    92,
     113,   608,    -1,   266,   113,   608,    -1,    46,   113,   406,
      -1,   408,    -1,   406,   102,   113,   408,    -1,   413,    -1,
     407,   102,   113,   413,    -1,   608,   136,   388,    -1,   608,
     514,   136,   388,    -1,   608,   404,   136,   388,    -1,   608,
     514,   404,   136,   388,    -1,   113,   608,   141,   388,    -1,
     113,   608,   514,   141,   388,    -1,   411,    -1,   113,   608,
      -1,   113,   608,   411,    -1,   403,    -1,   403,   412,    -1,
     412,    -1,    55,   113,   608,    48,   113,   608,    -1,    48,
     113,   608,    -1,    55,   113,   608,    -1,   608,    -1,   204,
     388,    -1,   165,   164,   416,    -1,   417,    -1,   416,   102,
     417,    -1,   113,   608,    -1,   113,   608,   418,    -1,   101,
     606,    -1,   162,   164,   420,    -1,    66,   162,   164,   420,
      -1,   421,    -1,   420,   102,   421,    -1,   388,    -1,   388,
     422,    -1,   423,    -1,   424,    -1,   425,    -1,   423,   424,
      -1,   423,   425,    -1,   424,   425,    -1,   423,   424,   425,
      -1,    91,    -1,   111,    -1,   121,   122,    -1,   121,   123,
      -1,   101,   606,    -1,    64,   113,   427,   181,   388,    -1,
     129,   113,   427,   181,   388,    -1,   428,    -1,   427,   102,
     113,   428,    -1,   608,   141,   388,    -1,   608,   514,   141,
     388,    -1,    69,   150,   385,   180,   430,   108,   179,   388,
      -1,   431,    -1,   430,   431,    -1,   432,   179,   388,    -1,
      95,   388,    -1,   432,    95,   388,    -1,    70,   150,   385,
     180,   434,   108,   179,   388,    -1,    70,   150,   385,   180,
     434,   108,   113,   608,   179,   388,    -1,   435,    -1,   434,
     435,    -1,    95,   515,   179,   388,    -1,    95,   113,   608,
      90,   515,   179,   388,    -1,    43,   150,   385,   180,   190,
     388,   120,   388,    -1,   438,    -1,   437,   161,   438,    -1,
     439,    -1,   438,    88,   439,    -1,   441,    -1,   441,   455,
     441,    -1,   441,   456,   441,    -1,   441,   126,   441,    -1,
     441,   156,   441,    -1,    -1,   441,   151,   440,   441,    -1,
     441,   149,   441,    -1,   441,   137,   441,    -1,   441,   135,
     441,    -1,   443,    -1,   443,   242,    67,   553,   442,    -1,
      -1,   605,    -1,   444,    -1,   444,   191,   444,    -1,   445,
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
     460,    -1,   170,   608,    15,    -1,   170,    16,    -1,   462,
      -1,   462,   463,    -1,   185,   463,    -1,   463,    -1,   184,
      -1,   464,    -1,   464,   184,   463,    -1,   464,   185,   463,
      -1,   465,    -1,   474,    -1,   466,    -1,   466,   475,    -1,
     469,    -1,   469,   475,    -1,   467,   471,    -1,   468,    -1,
     100,   116,    -1,   109,   116,    -1,    93,   116,    -1,   182,
     116,    -1,   110,   116,    -1,   133,   116,    -1,   132,   116,
      -1,   471,    -1,    94,   471,    -1,   470,   471,    -1,   115,
      -1,   166,   116,    -1,    86,   116,    -1,   174,   116,    -1,
     173,   116,    -1,    87,   116,    -1,   520,    -1,   472,    -1,
     608,    -1,   473,    -1,   186,    -1,    10,    -1,    17,    -1,
     477,    -1,   474,   475,    -1,   474,   150,   180,    -1,   474,
     150,   486,   180,    -1,   476,    -1,   475,   476,    -1,   148,
     385,   178,    -1,   478,    -1,   480,    -1,   481,    -1,   482,
      -1,   485,    -1,   487,    -1,   483,    -1,   484,    -1,   533,
      -1,   479,    -1,   532,    -1,   105,    -1,   143,    -1,   118,
      -1,   113,   608,    -1,   150,   180,    -1,   150,   385,   180,
      -1,   114,    -1,   163,   147,   385,   177,    -1,   194,   147,
     385,   177,    -1,   609,   150,   180,    -1,   609,   150,   486,
     180,    -1,   388,    -1,   486,   102,   388,    -1,   488,    -1,
     506,    -1,   489,    -1,   503,    -1,   504,    -1,   151,   608,
     493,   124,    -1,   151,   608,   491,   493,   124,    -1,   151,
     608,   493,   189,   187,   608,   493,   189,    -1,   151,   608,
     493,   189,   490,   187,   608,   493,   189,    -1,   151,   608,
     491,   493,   189,   187,   608,   493,   189,    -1,   151,   608,
     491,   493,   189,   490,   187,   608,   493,   189,    -1,   501,
      -1,   490,   501,    -1,   492,    -1,   491,   492,    -1,    29,
     608,   493,   126,   493,   494,    -1,    -1,    29,    -1,   176,
     495,   176,    -1,    89,   497,    89,    -1,    -1,   496,    -1,
     128,    -1,   499,    -1,   496,   128,    -1,   496,   499,    -1,
      -1,   498,    -1,   127,    -1,   500,    -1,   498,   127,    -1,
     498,   500,    -1,    22,    -1,   502,    -1,     4,    -1,   502,
      -1,   488,    -1,     9,    -1,   505,    -1,   502,    -1,     8,
      -1,   117,    -1,   119,    -1,   382,    -1,   205,    24,   206,
      -1,   205,   206,    -1,   167,   607,   168,    -1,   167,   607,
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
      -1,   539,    -1,   515,    -1,   518,   102,   515,    -1,   608,
      -1,   522,    -1,   528,    -1,   526,    -1,   529,    -1,   527,
      -1,   525,    -1,   524,    -1,   523,    -1,   521,    -1,   217,
     150,   180,    -1,    38,   150,   180,    -1,    38,   150,   528,
     180,    -1,    38,   150,   529,   180,    -1,    67,   150,   180,
      -1,    32,   150,   180,    -1,    56,   150,   180,    -1,    56,
     150,   607,   180,    -1,    56,   150,    23,   180,    -1,    93,
     150,   180,    -1,    93,   150,   608,   180,    -1,    93,   150,
     608,   102,   530,   180,    -1,    93,   150,   186,   180,    -1,
      93,   150,   186,   102,   530,   180,    -1,    58,   150,   608,
     180,    -1,    39,   150,   180,    -1,    39,   150,   608,   180,
      -1,    39,   150,   608,   102,   530,   180,    -1,    39,   150,
     608,   102,   531,   180,    -1,    39,   150,   186,   180,    -1,
      39,   150,   186,   102,   530,   180,    -1,    39,   150,   186,
     102,   531,   180,    -1,    59,   150,   608,   180,    -1,   608,
      -1,   608,   138,    -1,    23,    -1,   534,    -1,   535,    -1,
     608,   139,   143,    -1,    42,   365,   382,    -1,   537,    -1,
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
     547,    -1,   546,   102,   113,   547,    -1,   608,   136,   388,
      -1,   237,   147,   385,   177,   549,    -1,   550,    -1,   549,
     550,    -1,   238,   551,   383,    -1,   238,   551,   150,   113,
     608,   180,   383,    -1,   238,   551,   150,   113,   608,   102,
     113,   608,   180,   383,    -1,   238,   551,   150,   113,   608,
     102,   113,   608,   102,   113,   608,   180,   383,    -1,   472,
      -1,   551,   202,   472,    -1,   239,   113,   407,    40,   147,
     388,   177,    -1,    40,   147,   388,   177,    -1,   556,   554,
      -1,    -1,   555,    -1,   574,    -1,   555,   574,    -1,   557,
      -1,   556,   255,   557,    -1,   558,    -1,   557,   251,   558,
      -1,   559,    -1,   558,   253,   141,   559,    -1,   560,    -1,
     252,   560,    -1,   564,   561,   562,    -1,    -1,   579,    -1,
      -1,   563,    -1,   275,   147,   385,   177,    -1,   568,   565,
      -1,   150,   553,   180,    -1,   566,    -1,    -1,   601,    -1,
     459,   147,   567,   177,    -1,    -1,   553,    -1,   569,   570,
      -1,   478,    -1,   147,   385,   177,    -1,    -1,   571,    -1,
     241,   572,    -1,   240,   573,    -1,   263,    -1,    -1,    74,
      -1,    -1,   279,    -1,   575,    -1,   576,    -1,   577,    -1,
     603,    -1,   600,    -1,   163,    -1,   277,   444,   578,    -1,
     246,   602,   578,    -1,   279,    -1,   269,    -1,   262,    -1,
     239,   580,    -1,   579,   239,   580,    -1,   581,    -1,   582,
      -1,   583,    -1,   598,    -1,   584,    -1,   592,    -1,   585,
      -1,   599,    -1,    95,   267,    -1,    95,   256,    -1,   259,
      -1,   274,    -1,   244,   267,    -1,   244,   256,    -1,    52,
     608,    23,    -1,   270,    -1,    49,   270,    -1,   272,   586,
      -1,   272,   150,   586,   587,   180,    -1,    49,   272,    -1,
     589,    -1,   108,    -1,    -1,   588,    -1,   589,    -1,   588,
     102,   589,    -1,    92,    23,   590,   591,    -1,    -1,   264,
      23,    -1,    -1,   602,   258,    -1,   271,   279,   593,   595,
      -1,   271,   279,   108,   595,    -1,    49,   271,   279,    -1,
      92,    23,    -1,   150,   594,   180,    -1,    23,    -1,   594,
     102,    23,    -1,    -1,   596,    -1,   597,    -1,   596,   597,
      -1,   193,   593,    -1,   130,   593,    -1,   257,    23,    -1,
     276,    -1,    49,   276,    -1,    92,   209,    -1,    92,   247,
      -1,   248,   243,    -1,   260,   602,   273,    -1,   249,   444,
      -1,    92,   123,   444,    -1,    92,    47,   444,    -1,   250,
     444,   191,   444,    -1,   265,   604,    -1,   245,   604,    -1,
     268,    -1,   261,    -1,   278,   243,   446,    -1,    23,    -1,
      14,    -1,   608,    -1,   609,    -1,    93,    -1,    32,    -1,
      38,    -1,    39,    -1,   146,    -1,    43,    -1,   217,    -1,
      56,    -1,    58,    -1,    59,    -1,    67,    -1,    70,    -1,
      69,    -1,   203,    -1,   236,    -1,    21,    -1,   207,    -1,
     121,    -1,    31,    -1,   254,    -1,    30,    -1,   214,    -1,
     213,    -1,   140,    -1,    37,    -1,   252,    -1,   253,    -1,
     267,    -1,   256,    -1,   244,    -1,   278,    -1,   270,    -1,
     272,    -1,   271,    -1,   276,    -1,   248,    -1,   243,    -1,
      74,    -1,   209,    -1,   247,    -1,    47,    -1,   215,    -1,
     228,    -1,   295,    -1,   222,    -1,   195,    -1,   200,    -1,
     199,    -1,   198,    -1,   197,    -1,   196,    -1,    92,    -1,
     106,    -1,   107,    -1,   179,    -1,    41,    -1,    54,    -1,
      63,    -1,    68,    -1,    55,    -1,    48,    -1,    51,    -1,
      73,    -1,    35,    -1,   141,    -1,    46,    -1,   204,    -1,
     164,    -1,   165,    -1,   162,    -1,    66,    -1,    91,    -1,
     111,    -1,   122,    -1,   123,    -1,   101,    -1,    64,    -1,
     129,    -1,   181,    -1,    95,    -1,    90,    -1,   190,    -1,
     120,    -1,   161,    -1,    88,    -1,    45,    -1,   223,    -1,
      96,    -1,   191,    -1,   112,    -1,   153,    -1,   193,    -1,
     144,    -1,   130,    -1,    72,    -1,    97,    -1,   192,    -1,
     145,    -1,   175,    -1,   188,    -1,   154,    -1,   131,    -1,
     125,    -1,   160,    -1,   142,    -1,   159,    -1,    27,    -1,
      33,    -1,    53,    -1,   108,    -1,    34,    -1,    52,    -1,
     208,    -1,    44,    -1,    57,    -1,    28,    -1,    42,    -1,
     266,    -1,   242,    -1,   275,    -1,   277,    -1,   246,    -1,
     260,    -1,   273,    -1,   265,    -1,   245,    -1,   259,    -1,
     274,    -1,   264,    -1,   258,    -1,   257,    -1,   241,    -1,
     240,    -1,   263,    -1,   249,    -1,   250,    -1,   279,    -1,
     269,    -1,   268,    -1,   261,    -1,   221,    -1,   227,    -1,
     224,    -1,   218,    -1,   211,    -1,   210,    -1,   212,    -1,
     229,    -1,   219,    -1,   220,    -1,   226,    -1,   216,    -1,
     225,    -1,    62,    -1,    60,    -1,    71,    -1,    36,    -1,
      50,    -1,   163,    -1,   194,    -1,   235,    -1,   230,    -1,
     233,    -1,   234,    -1,   231,    -1,   232,    -1,   237,    -1,
     238,    -1,    40,    -1,   239,    -1,    61,    -1,   288,    -1,
     286,    -1,   287,    -1,   292,    -1,   293,    -1,   294,    -1,
     289,    -1,   290,    -1,   291,    -1,    75,    -1,    76,    -1,
      77,    -1,    78,    -1,    79,    -1,    80,    -1,    81,    -1,
      82,    -1,    83,    -1,    84,    -1,    85,    -1,   280,    -1,
     281,    -1,   282,    -1,   283,    -1,   284,    -1,   285,    -1,
     296,    -1,   297,    -1,   298,    -1,   299,    -1,   300,    -1,
     301,    -1,   302,    -1,    86,    -1,   100,    -1,   109,    -1,
     166,    -1,   173,    -1,   182,    -1,   132,    -1,    87,    -1,
     110,    -1,   133,    -1,   174,    -1
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
    2442,  2444,  2445,  2447,  2449,  2453,  2458,  2459,  2462,  2463,
    2466,  2471,  2476,  2480,  2483,  2487,  2489,  2493,  2494,  2496,
    2498,  2501,  2504,  2507,  2510,  2512,  2515,  2518,  2521,  2524,
    2528,  2531,  2535,  2539,  2544,  2547,  2550,  2552,  2554,  2558,
    2560,  2562,  2564,  2566,  2568,  2570,  2572,  2574,  2576,  2578,
    2580,  2582,  2584,  2586,  2588,  2590,  2592,  2594,  2596,  2598,
    2600,  2602,  2604,  2606,  2608,  2610,  2612,  2614,  2616,  2618,
    2620,  2622,  2624,  2626,  2628,  2630,  2632,  2634,  2636,  2638,
    2640,  2642,  2644,  2646,  2648,  2650,  2652,  2654,  2656,  2658,
    2660,  2662,  2664,  2666,  2668,  2670,  2672,  2674,  2676,  2678,
    2680,  2682,  2684,  2686,  2688,  2690,  2692,  2694,  2696,  2698,
    2700,  2702,  2704,  2706,  2708,  2710,  2712,  2714,  2716,  2718,
    2720,  2722,  2724,  2726,  2728,  2730,  2732,  2734,  2736,  2738,
    2740,  2742,  2744,  2746,  2748,  2750,  2752,  2754,  2756,  2758,
    2760,  2762,  2764,  2766,  2768,  2770,  2772,  2774,  2776,  2778,
    2780,  2782,  2784,  2786,  2788,  2790,  2792,  2794,  2796,  2798,
    2800,  2802,  2804,  2806,  2808,  2810,  2812,  2814,  2816,  2818,
    2820,  2822,  2824,  2826,  2828,  2830,  2832,  2834,  2836,  2838,
    2840,  2842,  2844,  2846,  2848,  2850,  2852,  2854,  2856,  2858,
    2860,  2862,  2864,  2866,  2868,  2870,  2872,  2874,  2876,  2878,
    2880,  2882,  2884,  2886,  2888,  2890,  2892,  2894,  2896,  2898,
    2900,  2902,  2904,  2906,  2908,  2910,  2912,  2914,  2916,  2918,
    2920,  2922,  2924,  2926,  2928,  2930,  2932,  2934,  2936,  2938,
    2940,  2942,  2944,  2946,  2948,  2950,  2952,  2954,  2956,  2958,
    2960,  2962,  2964,  2966,  2968,  2970,  2972,  2974,  2976,  2978,
    2980,  2982,  2984,  2986,  2988,  2990,  2992,  2994
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,  1013,  1013,  1014,  1019,  1020,  1021,  1022,  1026,  1040,
    1045,  1052,  1057,  1068,  1073,  1081,  1086,  1091,  1096,  1104,
    1108,  1113,  1118,  1127,  1136,  1142,  1151,  1157,  1166,  1167,
    1168,  1169,  1174,  1175,  1176,  1177,  1178,  1179,  1180,  1181,
    1182,  1188,  1193,  1202,  1208,  1217,  1226,  1227,  1228,  1229,
    1230,  1231,  1232,  1233,  1234,  1235,  1240,  1241,  1242,  1243,
    1244,  1245,  1246,  1249,  1254,  1255,  1260,  1268,  1274,  1284,
    1290,  1300,  1310,  1318,  1324,  1335,  1340,  1350,  1356,  1362,
    1368,  1385,  1393,  1401,  1405,  1414,  1423,  1436,  1442,  1453,
    1457,  1465,  1470,  1475,  1482,  1495,  1502,  1508,  1515,  1521,
    1525,  1532,  1543,  1547,  1555,  1561,  1567,  1576,  1582,  1591,
    1595,  1601,  1605,  1609,  1613,  1619,  1625,  1631,  1637,  1643,
    1647,  1653,  1659,  1666,  1674,  1682,  1690,  1698,  1710,  1724,
    1738,  1755,  1759,  1768,  1772,  1779,  1787,  1805,  1811,  1819,
    1824,  1831,  1838,  1848,  1858,  1868,  1878,  1895,  1901,  1912,
    1916,  1920,  1924,  1931,  1938,  1957,  1967,  1973,  1979,  1989,
    1996,  2007,  2014,  2021,  2033,  2037,  2044,  2049,  2064,  2081,
    2085,  2089,  2093,  2101,  2112,  2127,  2138,  2153,  2164,  2180,
    2186,  2198,  2202,  2213,  2220,  2228,  2243,  2247,  2261,  2265,
    2274,  2278,  2292,  2293,  2294,  2295,  2296,  2297,  2300,  2301,
    2302,  2303,  2304,  2306,  2307,  2310,  2311,  2312,  2313,  2314,
    2319,  2334,  2341,  2345,  2352,  2356,  2360,  2367,  2375,  2386,
    2396,  2409,  2418,  2419,  2420,  2424,  2425,  2426,  2427,  2428,
    2431,  2437,  2446,  2450,  2458,  2468,  2474,  2486,  2490,  2498,
    2507,  2517,  2525,  2534,  2543,  2558,  2567,  2577,  2585,  2591,
    2600,  2606,  2618,  2626,  2636,  2644,  2656,  2662,  2673,  2675,
    2679,  2687,  2691,  2696,  2700,  2704,  2708,  2716,  2730,  2738,
    2745,  2751,  2762,  2766,  2775,  2783,  2789,  2799,  2805,  2815,
    2819,  2829,  2835,  2841,  2847,  2856,  2865,  2874,  2887,  2891,
    2899,  2905,  2915,  2923,  2932,  2945,  2952,  2964,  2968,  2980,
    2987,  2993,  3002,  3009,  3015,  3027,  3034,  3047,  3053,  3065,
    3071,  3083,  3092,  3096,  3105,  3109,  3117,  3121,  3131,  3138,
    3147,  3157,  3156,  3170,  3179,  3188,  3201,  3205,  3218,  3221,
    3228,  3232,  3241,  3245,  3249,  3258,  3262,  3268,  3274,  3280,
    3291,  3295,  3299,  3307,  3311,  3317,  3327,  3331,  3341,  3345,
    3355,  3359,  3369,  3373,  3383,  3387,  3395,  3399,  3403,  3407,
    3417,  3421,  3425,  3433,  3437,  3441,  3445,  3449,  3453,  3461,
    3465,  3469,  3477,  3481,  3485,  3489,  3500,  3506,  3516,  3522,
    3532,  3536,  3574,  3578,  3584,  3590,  3601,  3609,  3620,  3626,
    3636,  3640,  3648,  3654,  3662,  3668,  3680,  3686,  3696,  3700,
    3704,  3708,  3712,  3718,  3724,  3747,  3751,  3759,  3763,  3774,
    3778,  3782,  3788,  3792,  3806,  3810,  3818,  3822,  3832,  3836,
    3840,  3849,  3853,  3859,  3863,  3871,  3877,  3887,  3895,  3899,
    3903,  3907,  3911,  3915,  3919,  3923,  3927,  3935,  3939,  3947,
    3954,  3961,  3972,  3980,  3984,  3992,  4000,  4008,  4062,  4066,
    4079,  4085,  4095,  4099,  4107,  4111,  4115,  4123,  4133,  4143,
    4153,  4163,  4173,  4188,  4194,  4205,  4211,  4222,  4233,  4235,
    4239,  4244,  4254,  4257,  4264,  4272,  4278,  4288,  4301,  4304,
    4311,  4317,  4323,  4330,  4341,  4345,  4355,  4359,  4369,  4373,
    4377,  4382,  4391,  4397,  4403,  4409,  4419,  4423,  4435,  4439,
    4451,  4463,  4467,  4471,  4475,  4479,  4483,  4491,  4499,  4503,
    4507,  4511,  4528,  4532,  4536,  4540,  4548,  4556,  4564,  4568,
    4572,  4576,  4584,  4590,  4600,  4608,  4612,  4616,  4651,  4657,
    4663,  4673,  4677,  4681,  4685,  4689,  4696,  4702,  4712,  4720,
    4724,  4728,  4732,  4736,  4740,  4744,  4748,  4752,  4760,  4768,
    4772,  4776,  4786,  4794,  4802,  4806,  4810,  4818,  4822,  4828,
    4834,  4838,  4848,  4856,  4860,  4866,  4875,  4884,  4890,  4896,
    4906,  4923,  4930,  4945,  4981,  4985,  4994,  5003,  5013,  5017,
    5026,  5035,  5039,  5050,  5067,  5073,  5079,  5089,  5093,  5099,
    5105,  5109,  5115,  5119,  5125,  5131,  5138,  5148,  5153,  5161,
    5167,  5177,  5199,  5208,  5214,  5227,  5241,  5248,  5254,  5264,
    5269,  5275,  5285,  5298,  5304,  5321,  5325,  5340,  5349,  5352,
    5359,  5364,  5372,  5376,  5383,  5387,  5394,  5398,  5405,  5409,
    5418,  5431,  5434,  5442,  5445,  5453,  5461,  5469,  5473,  5481,
    5484,  5492,  5504,  5507,  5515,  5527,  5533,  5543,  5546,  5554,
    5558,  5562,  5570,  5573,  5581,  5584,  5592,  5596,  5600,  5604,
    5608,  5616,  5624,  5636,  5648,  5652,  5656,  5664,  5670,  5680,
    5684,  5688,  5692,  5696,  5700,  5704,  5708,  5716,  5720,  5724,
    5728,  5736,  5742,  5752,  5762,  5766,  5774,  5784,  5795,  5802,
    5806,  5814,  5817,  5824,  5829,  5838,  5848,  5851,  5859,  5862,
    5870,  5879,  5886,  5896,  5900,  5907,  5913,  5923,  5926,  5933,
    5938,  5950,  5958,  5970,  5978,  5982,  5990,  5994,  5998,  6006,
    6014,  6018,  6022,  6026,  6034,  6042,  6054,  6058,  6066,  6079,
    6083,  6084,  6097,  6098,  6099,  6100,  6101,  6102,  6103,  6104,
    6105,  6106,  6107,  6108,  6109,  6110,  6111,  6112,  6116,  6117,
    6118,  6119,  6120,  6121,  6122,  6123,  6124,  6125,  6126,  6127,
    6128,  6129,  6130,  6131,  6132,  6133,  6134,  6135,  6136,  6137,
    6138,  6139,  6140,  6141,  6142,  6143,  6144,  6145,  6146,  6147,
    6148,  6149,  6150,  6151,  6152,  6153,  6154,  6155,  6156,  6157,
    6158,  6159,  6160,  6161,  6162,  6163,  6164,  6165,  6166,  6167,
    6168,  6169,  6170,  6171,  6172,  6173,  6174,  6175,  6176,  6177,
    6178,  6179,  6180,  6181,  6182,  6183,  6184,  6185,  6186,  6187,
    6188,  6189,  6190,  6191,  6192,  6193,  6194,  6195,  6196,  6197,
    6198,  6199,  6200,  6201,  6202,  6203,  6204,  6205,  6206,  6207,
    6208,  6209,  6210,  6211,  6212,  6213,  6214,  6215,  6216,  6217,
    6218,  6219,  6220,  6221,  6222,  6223,  6224,  6225,  6226,  6227,
    6228,  6229,  6230,  6231,  6232,  6233,  6234,  6235,  6236,  6237,
    6238,  6239,  6240,  6241,  6242,  6243,  6244,  6245,  6246,  6247,
    6248,  6249,  6250,  6251,  6252,  6253,  6254,  6255,  6256,  6257,
    6258,  6259,  6260,  6261,  6262,  6263,  6264,  6265,  6266,  6267,
    6268,  6269,  6270,  6271,  6272,  6273,  6274,  6275,  6276,  6277,
    6278,  6279,  6280,  6281,  6282,  6283,  6284,  6285,  6286,  6287,
    6288,  6289,  6290,  6291,  6292,  6293,  6294,  6295,  6296,  6297,
    6298,  6299,  6300,  6301,  6302,  6303,  6304,  6305,  6306,  6307,
    6308,  6309,  6310,  6311,  6312,  6313,  6314,  6315
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
  const int xquery_parser::yylast_ = 11800;
  const int xquery_parser::yynnts_ = 293;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 560;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 317;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 571;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 15587 "/home/soso/work/zorba1/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6319 "/home/soso/work/zorba1/src/compiler/parser/xquery_parser.y"


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

