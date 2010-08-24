
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
#line 67 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"


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
#line 86 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 858 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 317 of lalr1.cc  */
#line 958 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"

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
#line 157 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"

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
#line 226 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
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
#line 856 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 333 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 119: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 342 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 144: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 854 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 351 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 360 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 369 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 378 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 387 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 396 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 405 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 414 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 423 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 432 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 441 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 450 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 459 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 468 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 477 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 486 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 495 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 504 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 513 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 522 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 531 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 540 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 549 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 558 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 567 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 576 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 585 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 594 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 603 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 612 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 621 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 630 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 639 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 648 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "DeclPropertyList" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 657 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "DeclProperty" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 666 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 675 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "NodeModifier" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 684 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 693 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 702 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 711 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 720 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 729 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 738 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 747 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "Block" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 756 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "BlockDecls" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 765 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "BlockVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 774 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "BlockVarDecl" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 783 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "AssignExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 792 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "ExitExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 801 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "WhileExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 810 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 819 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 828 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 837 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 846 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "FunctionDeclSequential" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 855 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 864 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 882 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "EnclosedExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 891 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 900 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 909 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 918 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "ApplyExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 927 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "ConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 936 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 945 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 954 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 963 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 972 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 981 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 990 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 999 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1008 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1017 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1026 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1035 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1044 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1053 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1062 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1071 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "EvalVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1080 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1089 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1098 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1107 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1116 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1125 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "EvalVarDecl" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1134 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1143 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1152 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1161 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1170 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1179 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1188 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1197 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1206 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1215 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1224 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1233 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1242 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1251 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1260 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1269 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1278 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1287 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1296 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1305 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1314 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1323 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1332 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1341 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1350 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1359 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1368 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1377 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1386 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1395 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1404 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1413 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1422 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1431 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1440 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1449 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1458 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1467 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1476 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1485 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1494 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1503 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1512 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1521 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1530 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1539 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1548 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1557 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1566 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1575 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1584 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1593 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1602 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1611 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1620 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1629 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1638 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1647 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1656 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1665 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1674 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1683 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1692 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1701 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1710 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1719 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1728 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1737 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1746 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1755 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1764 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1773 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1782 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1791 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1800 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1809 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1818 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1827 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1836 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1845 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1854 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1863 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1872 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1881 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1890 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1899 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1908 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1917 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1926 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1935 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1944 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1953 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1962 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1971 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1980 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1989 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1998 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2007 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2016 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2025 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2034 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2043 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2052 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2061 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2070 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2079 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2088 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2097 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2106 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2115 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2124 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2133 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2142 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2151 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2160 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2169 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2178 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2187 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2196 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2205 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2214 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2223 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2232 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2241 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2250 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2259 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2268 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2277 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2286 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2295 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "EvalExpr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2304 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2313 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2322 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2331 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2340 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2349 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2358 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2367 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2376 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2385 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2394 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2403 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2412 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2421 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2430 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2439 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2448 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2457 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2466 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2475 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2484 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2493 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2502 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2511 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2520 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2529 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2538 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2547 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2556 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2565 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2574 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2583 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2592 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2601 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2610 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2619 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2628 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2637 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2646 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2655 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 610: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2664 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
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
#line 127 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename.getStore()->str());
}

/* Line 553 of lalr1.cc  */
#line 2749 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"

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
#line 1017 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 1050 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL; YYABORT;
        }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 1059 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 1064 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            MainModule *mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
            mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 1071 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 1076 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            LibraryModule *lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
            lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 1087 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            std::string encoding = "utf-8";
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), encoding );
        }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 1092 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
        }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 1100 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);
          (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
        }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1105 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));
          (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
        }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1110 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)), static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));
          (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
        }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 1115 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
        }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1120 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1128 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1136 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1144 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1156 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
        }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1160 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
        }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1165 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
        }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 1170 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)), static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
        }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 1179 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
            dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
        }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 1188 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
            sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = sdl;
        }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 1194 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 1199 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1212 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
            vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = vdl;
        }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 1218 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 1223 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1257 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
          delete (yysemantic_stack_[(4) - (4)].vstrpair);
        }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1262 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
          delete (yysemantic_stack_[(4) - (4)].vstrpair);
        }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1271 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.vstrpair) = new vector<string_pair_t>();
          (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
          delete (yysemantic_stack_[(1) - (1)].strpair);
        }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1277 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
          delete (yysemantic_stack_[(2) - (2)].strpair);
          (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
        }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1286 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
            (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval() );
            delete sl;
        }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1294 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1295 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1296 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1297 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1298 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 1299 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 1300 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 1301 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 1302 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 1303 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1329 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
        }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1337 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::preserve_space
            );
        }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1343 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::strip_space
            );
        }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1353 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_element_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1359 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_function_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1369 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OptionDecl(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval))
            );
        }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1379 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1387 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::ordered
            );
        }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1393 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::unordered
            );
        }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1404 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_greatest);
        }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1409 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_least);
        }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 1419 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 1425 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 1431 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1437 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1454 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
        }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1462 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1470 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
        }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1474 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1483 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1492 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1505 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            URILiteralList *ull = new URILiteralList( LOC((yyloc)));
            ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.node) = ull;
        }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1511 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
                ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1522 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1526 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
        }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1534 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1539 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1544 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1551 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1564 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
        }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1571 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
            d->type = (yysemantic_stack_[(3) - (2)].node);
            (yyval.node) = d;
        }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1577 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1584 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
            d->ext = false;
            (yyval.node) = d;
        }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1590 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), NULL );
        }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1594 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1601 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1612 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1616 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1624 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(5) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(5) - (5)].expr));
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1630 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL, true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 1636 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(6) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(6) - (6)].expr), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 1645 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            DeclPropertyList *dpl = new DeclPropertyList( LOC((yyloc)) );
            dpl->addProperty(dynamic_cast<DeclProperty*>((yysemantic_stack_[(1) - (1)].node)));
            (yyval.node) = dpl;
        }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 1651 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        DeclPropertyList *dpl = dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(2) - (1)].node));
        dpl->addProperty( static_cast<DeclProperty*>((yysemantic_stack_[(2) - (2)].node)) );
        (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1660 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_const );
        }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1664 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_append_only
            );
        }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1670 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_queue );
        }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1674 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_mutable );
        }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1678 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_ordered );
        }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1682 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_unordered
            );
        }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1688 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_equality
            );
        }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1694 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_range
            );
        }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1700 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_equality
            );
        }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1706 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_range
            );
        }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1712 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_unique );
        }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1716 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_non_unique
            );
        }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1722 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_automatic
            );
        }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1728 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_manual );
        }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1735 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1743 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1751 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1759 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1767 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1779 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1793 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1807 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1824 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1828 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1837 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1841 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1848 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1856 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1874 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1880 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1888 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1893 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1900 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1907 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1918 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1928 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1938 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1949 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1964 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_preserve
            );
        }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1970 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_strip
            );
        }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1981 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL );
        }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1985 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1989 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)) );
        }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1993 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 2000 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
        }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 2007 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2026 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2035 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 2042 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
            vfo->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = vfo;
        }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 2048 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = new VFO_DeclList( LOC((yyloc)) );
            vfo->push_back((yysemantic_stack_[(2) - (2)].node));
            (yyval.node) = vfo;
        }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 2058 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(1) - (1)].varnametype)));
      VarDecl* vd = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL);
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 2065 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(3) - (1)].varnametype)));
      VarDecl* vd = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(3) - (3)].expr));
      vd->set_global(false);
      (yyval.node) = vd;
        }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 2076 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2083 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExitExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 2090 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2102 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::BREAK );
        }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 2106 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
        }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 2113 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            dynamic_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 2118 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2133 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2150 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 2154 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 2158 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 2162 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 2170 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2181 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2196 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2207 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2222 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2233 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2249 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            ParamList *pl = new ParamList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 2255 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
                pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 2267 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 2271 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 2282 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EnclosedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 2289 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 2297 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QueryBody( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 2312 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 2316 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2330 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new BlockBody( LOC((yyloc)) );
        }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 2334 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            BlockBody *bb = dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (1)].expr));
            bb->add( (yysemantic_stack_[(3) - (2)].expr) );
            (yyval.expr) = bb;
        }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 2343 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 2347 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2388 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2403 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 2410 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_sliding;
        }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 2414 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_tumbling;
        }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 2421 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_start;
        }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 2425 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_end;
        }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 2429 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_only_end;
        }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 2436 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2444 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr),
                (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 2455 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2465 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2478 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 2500 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 2506 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 2515 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = NULL;
        }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 2519 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_ofor;
        }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 2527 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)), (yysemantic_stack_[(3) - (1)].strval) != NULL);
        }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 2535 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
            vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vdl;
        }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 2541 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 2553 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 2557 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                         NULL,NULL,
                         (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 2565 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
                         NULL,
                         (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 2574 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
                         NULL,
                         (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 2584 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 2592 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                         NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 2601 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC ((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2610 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC ((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                         (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 2625 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 2634 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2644 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2652 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 2658 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 2667 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2673 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 2685 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 2693 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 2703 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                           (yysemantic_stack_[(4) - (4)].expr));
     }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 2711 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                           (yysemantic_stack_[(5) - (5)].expr));
     }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 2723 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2729 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2742 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2746 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2754 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2758 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2767 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2771 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2775 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2783 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)),
                           NULL, NULL,
                           new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr))),
                           VarGetsDecl::eval_var);
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2797 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2805 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2812 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2818 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2829 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2833 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2842 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 2850 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2856 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2866 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2872 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2882 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2886 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2896 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2902 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2908 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2914 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2923 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2932 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2941 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 2954 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 2958 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 2966 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 2972 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 2982 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 2990 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 2999 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 3012 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 3019 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 3031 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 3035 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 3047 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3054 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3060 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3069 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3076 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3082 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3094 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3101 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3114 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3120 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3132 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3138 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3150 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3159 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3163 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3172 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3176 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3184 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3188 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 320:

/* Line 678 of lalr1.cc  */
#line 3198 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3205 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3214 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3223 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3228 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3237 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3246 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3255 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3268 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3272 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3284 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3288 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3295 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3299 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3308 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3312 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3316 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3325 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3329 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3335 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3341 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3347 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3358 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3362 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3366 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3374 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3378 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3384 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3394 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3398 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3408 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3412 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3422 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3426 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3436 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3440 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3450 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3454 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3462 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3466 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3470 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3474 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3484 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3488 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3492 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3500 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3504 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3508 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3512 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3516 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3520 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3528 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3532 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3536 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3544 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3548 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3552 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3556 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3567 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3573 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3583 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3589 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3599 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3603 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3641 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3645 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3651 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3657 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            RelativePathExpr *rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = !rpe ?
                (yysemantic_stack_[(1) - (1)].expr) : new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3668 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NULL;
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3676 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 390:

/* Line 678 of lalr1.cc  */
#line 3687 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3693 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3703 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3707 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3715 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3721 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3729 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3735 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3747 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3753 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3763 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3767 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3771 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3775 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3779 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3785 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3791 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3814 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3818 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3826 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3830 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3841 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3845 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3849 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3855 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3859 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3877 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3885 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3889 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3899 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all);
    }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3903 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem);
    }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3907 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix);
    }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3916 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 3920 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FilterExpr(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 3926 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
        }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 3930 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
        }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 3938 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 3944 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 3954 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 3962 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 3966 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 3970 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 3974 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 3978 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 3982 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 3986 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 3990 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 3994 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4002 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4006 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4014 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4021 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4028 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4039 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4047 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4051 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4059 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4067 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4075 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4129 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4133 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4146 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4152 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4162 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4166 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4174 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4178 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4182 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4190 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 460:

/* Line 678 of lalr1.cc  */
#line 4200 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 461:

/* Line 678 of lalr1.cc  */
#line 4210 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 462:

/* Line 678 of lalr1.cc  */
#line 4220 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 463:

/* Line 678 of lalr1.cc  */
#line 4230 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 464:

/* Line 678 of lalr1.cc  */
#line 4240 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 465:

/* Line 678 of lalr1.cc  */
#line 4255 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4261 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4272 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4278 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4289 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4306 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4311 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4320 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4324 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4331 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back(
                new QuoteAttrValueContent( LOC((yyloc)),std::string("\"") )
            );
            (yyval.node) = qacl;
        }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4339 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4345 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 479:

/* Line 678 of lalr1.cc  */
#line 4355 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4367 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4371 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4378 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4384 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4390 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4397 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4408 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4412 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4422 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4426 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4436 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4440 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4444 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4449 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4458 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4464 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4470 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4476 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4486 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4490 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
        }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4502 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4506 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4518 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4530 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4534 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4538 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4542 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4546 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4550 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4558 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4566 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (1)].sval))), NULL);
        }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4570 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4574 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4578 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4595 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (1)].sval))), NULL );
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4599 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4603 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4607 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4615 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4623 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4631 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (1)].sval)), NULL );
        }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4635 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4639 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4643 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4651 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4657 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4667 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4675 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4679 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4683 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4718 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4724 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4730 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4740 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4744 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4748 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4752 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4756 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4763 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4769 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4779 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4787 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4791 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4795 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4799 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4803 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4807 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4811 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4815 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4819 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4827 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 4835 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 4839 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 4843 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 4853 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 4861 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 4869 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 4873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 4877 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 4885 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 4889 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 4895 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 4901 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 4905 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 4915 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 4923 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 4927 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 4933 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 4942 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 4951 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 4957 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 4963 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 4973 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 4990 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 4997 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5012 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5048 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5052 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5061 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
        }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5070 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new InlineFunction(LOC ((yyloc)), &*(yysemantic_stack_[(3) - (2)].fnsig)->param, &*(yysemantic_stack_[(3) - (2)].fnsig)->ret, dynamic_cast<EnclosedExpr *>((yysemantic_stack_[(3) - (3)].expr)));
          delete (yysemantic_stack_[(3) - (2)].fnsig);
        }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5080 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5084 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5093 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
        }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5102 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5106 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5117 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5134 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5140 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5146 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5156 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5160 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5166 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5172 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5176 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5182 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5186 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5192 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5198 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5205 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5215 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5220 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5228 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5234 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5244 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5266 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5275 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5281 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5294 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5308 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5315 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5321 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5331 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5336 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5342 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 614:

/* Line 678 of lalr1.cc  */
#line 5352 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 615:

/* Line 678 of lalr1.cc  */
#line 5365 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5371 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5388 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new EvalExpr(LOC((yyloc)), dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)), (yysemantic_stack_[(7) - (6)].expr));
        }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5392 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new EvalExpr( LOC((yyloc)), new VarGetsDeclList( LOC((yyloc)) ), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5407 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5415 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5419 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5426 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5431 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5439 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5443 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5450 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5454 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5461 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5465 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5472 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5476 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5485 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 5497 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5501 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5508 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5512 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5520 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5528 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5536 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5540 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5547 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5551 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5559 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5570 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5574 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5582 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5594 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5600 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5609 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5613 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5621 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5625 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5629 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5636 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5640 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5647 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5651 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5659 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5663 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5667 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5671 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5675 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5683 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5691 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5703 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5715 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5719 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5723 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5731 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5737 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5747 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5751 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5755 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5759 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5763 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5767 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5771 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5775 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5783 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5787 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5791 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5795 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5803 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5809 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5819 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5829 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5833 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5841 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 5851 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 5862 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5869 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5873 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5880 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5884 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(1) - (1)].thesaurus_id_list);
        }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5891 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5896 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5905 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5914 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5918 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5925 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 5929 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5937 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 5946 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 5953 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 5963 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 5967 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 5974 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 5980 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 5989 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 5993 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 6000 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 6005 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 6017 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 6025 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 6037 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 6045 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 6049 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 6057 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 6061 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 6065 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 6073 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 6081 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 6085 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 6089 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 6093 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 6101 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 6109 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 6121 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 6125 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 6133 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 6151 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 735:

/* Line 678 of lalr1.cc  */
#line 6164 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 6165 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 6166 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 6167 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 6168 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 6169 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 6170 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 6171 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 6172 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 6173 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 6174 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 6175 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 6176 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 6177 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 6178 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 6182 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 6183 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 6184 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 6185 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 6186 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 6187 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 6188 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 6189 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 6190 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 6191 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 6192 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 6193 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 6194 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 6195 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 6196 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 6197 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 6198 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 6199 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 6200 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 6201 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 6202 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 6203 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 6204 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 6205 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 6206 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 6207 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 6208 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 6209 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 6210 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 6211 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 6212 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 6213 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 6214 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 6215 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 6216 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 6217 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 6218 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 6219 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 6220 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 6221 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 6222 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 6223 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("outer"))); }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 6224 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 6225 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 6226 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 6227 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 6228 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 6229 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 6230 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 6231 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 6232 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 6233 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 6234 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 6235 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 6236 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 6237 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 6238 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 6239 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 6240 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 6241 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 6242 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 6243 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 6244 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 6245 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 6246 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 6247 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 6248 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 6249 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 6250 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 6251 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 6252 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 6253 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 6254 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 6255 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 6256 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 6257 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 6258 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 6259 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 6260 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 6261 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 6262 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 6263 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 6264 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 6265 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 6266 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 6267 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 6268 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 6269 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 6270 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 6271 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 6272 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 6273 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 6274 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 6275 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 6276 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 6277 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 6278 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 6279 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 6280 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 6281 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 6282 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 6283 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 6284 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 6285 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 6286 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 6287 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 6288 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 6289 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 6290 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 6291 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 6292 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 6293 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 6294 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 6295 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 6296 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 6297 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 6298 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 6299 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 6300 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 6301 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 6302 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 6303 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 6304 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 6305 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 6306 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 6307 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 6308 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 6309 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 6310 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 6311 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 6312 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 6313 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 6314 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 6315 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 6316 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 6317 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 6318 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 6319 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 6320 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 6321 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 6322 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 6323 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("deterministic"))); }
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 6324 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nondeterministic"))); }
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 6325 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 6326 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6327 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 896:

/* Line 678 of lalr1.cc  */
#line 6328 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("block"))); }
    break;

  case 897:

/* Line 678 of lalr1.cc  */
#line 6329 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 898:

/* Line 678 of lalr1.cc  */
#line 6330 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 899:

/* Line 678 of lalr1.cc  */
#line 6331 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 900:

/* Line 678 of lalr1.cc  */
#line 6332 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 901:

/* Line 678 of lalr1.cc  */
#line 6333 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 902:

/* Line 678 of lalr1.cc  */
#line 6334 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 903:

/* Line 678 of lalr1.cc  */
#line 6335 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eval"))); }
    break;

  case 904:

/* Line 678 of lalr1.cc  */
#line 6336 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 905:

/* Line 678 of lalr1.cc  */
#line 6337 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 906:

/* Line 678 of lalr1.cc  */
#line 6338 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 907:

/* Line 678 of lalr1.cc  */
#line 6339 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 908:

/* Line 678 of lalr1.cc  */
#line 6340 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 909:

/* Line 678 of lalr1.cc  */
#line 6341 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 910:

/* Line 678 of lalr1.cc  */
#line 6342 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 911:

/* Line 678 of lalr1.cc  */
#line 6343 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 912:

/* Line 678 of lalr1.cc  */
#line 6344 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 913:

/* Line 678 of lalr1.cc  */
#line 6345 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 914:

/* Line 678 of lalr1.cc  */
#line 6346 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 915:

/* Line 678 of lalr1.cc  */
#line 6347 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 916:

/* Line 678 of lalr1.cc  */
#line 6348 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 917:

/* Line 678 of lalr1.cc  */
#line 6349 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 918:

/* Line 678 of lalr1.cc  */
#line 6350 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 919:

/* Line 678 of lalr1.cc  */
#line 6351 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 920:

/* Line 678 of lalr1.cc  */
#line 6352 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 921:

/* Line 678 of lalr1.cc  */
#line 6353 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 922:

/* Line 678 of lalr1.cc  */
#line 6354 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 923:

/* Line 678 of lalr1.cc  */
#line 6355 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 924:

/* Line 678 of lalr1.cc  */
#line 6356 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 925:

/* Line 678 of lalr1.cc  */
#line 6357 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 926:

/* Line 678 of lalr1.cc  */
#line 6358 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 927:

/* Line 678 of lalr1.cc  */
#line 6359 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 928:

/* Line 678 of lalr1.cc  */
#line 6360 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 929:

/* Line 678 of lalr1.cc  */
#line 6361 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 930:

/* Line 678 of lalr1.cc  */
#line 6362 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 931:

/* Line 678 of lalr1.cc  */
#line 6363 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 932:

/* Line 678 of lalr1.cc  */
#line 6364 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 933:

/* Line 678 of lalr1.cc  */
#line 6365 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 934:

/* Line 678 of lalr1.cc  */
#line 6366 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 935:

/* Line 678 of lalr1.cc  */
#line 6367 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 936:

/* Line 678 of lalr1.cc  */
#line 6368 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 937:

/* Line 678 of lalr1.cc  */
#line 6369 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 938:

/* Line 678 of lalr1.cc  */
#line 6370 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 939:

/* Line 678 of lalr1.cc  */
#line 6371 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 940:

/* Line 678 of lalr1.cc  */
#line 6372 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 941:

/* Line 678 of lalr1.cc  */
#line 6373 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 942:

/* Line 678 of lalr1.cc  */
#line 6374 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 943:

/* Line 678 of lalr1.cc  */
#line 6375 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 944:

/* Line 678 of lalr1.cc  */
#line 6376 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 945:

/* Line 678 of lalr1.cc  */
#line 6377 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 946:

/* Line 678 of lalr1.cc  */
#line 6378 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 947:

/* Line 678 of lalr1.cc  */
#line 6379 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 948:

/* Line 678 of lalr1.cc  */
#line 6380 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 949:

/* Line 678 of lalr1.cc  */
#line 6381 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;



/* Line 678 of lalr1.cc  */
#line 11427 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1340;
  const short int
  xquery_parser::yypact_[] =
  {
      1948, -1340, -1340,  2242,  2535,  2828, -1340, -1340,  1099,   -22,
   -1340, -1340,   522, -1340, -1340, -1340, -1340,   147,   174,   527,
     159,   436,   237,   276,    91, -1340,   336, -1340, -1340, -1340,
   -1340, -1340, -1340,   426, -1340,   533, -1340,   329,   361, -1340,
     427, -1340, -1340,   454, -1340,   535, -1340,   421,   478, -1340,
     214, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340,   463,   568, -1340, -1340, -1340, -1340,
     431,  8102, -1340, -1340, -1340,   571, -1340, -1340, -1340, -1340,
   -1340,   598,   602, -1340, -1340, 11234, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340,   536, -1340, -1340,   605,   609, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340,  3121, 11234, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340,   564, -1340, -1340,   612,  8973,
   -1340,  9260,   637,   643, -1340, -1340, -1340,   652, -1340,  7809,
   -1340, -1340, -1340, -1340, -1340, -1340,   623, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340,    36,   565, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340,   300,   544,   403, -1340,   559,
     226, -1340, -1340, -1340, -1340, -1340, -1340,   665, -1340,   635,
     552,   553,   558, -1340, -1340,   640,   648, -1340,   683, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,  5172,
     798, -1340,  5465, -1340, -1340,   119,    53,    58, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,   -13,
   -1340, -1340, -1340, -1340,   148,   685, -1340, -1340, -1340, -1340,
   -1340, -1340,   641,   715, -1340,   632,   566,   399,   223,   -60,
     218, -1340,   761,   615,   716,   714,  5758, -1340, -1340, -1340,
     -18, -1340, -1340,  7809, -1340,   483, -1340,   666,  8102, -1340,
     666,  8102, -1340, -1340, -1340,   555, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,   674,
     667, -1340, -1340, -1340, -1340, -1340,   638, -1340,   639, -1340,
     642,   795,   410,   449,   457,   547, 11516,   547, 11234,   -33,
     778,   779,   780, 11234,   677,   711,   500,  8973, -1340, -1340,
     494,   437,   586, 11234, -1340, -1340, -1340, -1340, -1340,   540,
   11234,   542,   543,   451,   538,   409, -1340, -1340, -1340, -1340,
   -1340,  8973,  6051,   656,  6051,    49,  6051,  9824,  6051,   560,
     562,   733,     5,   700,  6051,    59,    54, 11234, -1340,  6051,
    8684, 11234, 11234, 11234, 11234,  6051,   668,  6051,  6051, 11234,
    6051,   702,   704, -1340, -1340, -1340,  6051, 10106,   703, -1340,
     705, -1340, -1340, -1340, -1340, -1340, -1340,   706, -1340, -1340,
     707, -1340, -1340, -1340, -1340, -1340,   708, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, 11234, -1340, -1340,
   -1340,   672,   825,  6051, -1340, -1340,   100, -1340, -1340,   844,
   -1340, -1340, -1340, -1340,  6051,   654, -1340,   838,  6051,  6051,
     684,  6051,  6051,  6051,  6051,   644, 11234, -1340, -1340, -1340,
   -1340,  6051,  6051,  6051, 11234, -1340, -1340, -1340, -1340,  1099,
      91,    64,    73,   861,  6344,  6344,  6637,  6637,  6051, -1340,
    6051,   752,   578,   336,   426,   709,   710,   713,  6051,  6051,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, 11234,  6930,  6930,
    6930, -1340,  6930,  6930, -1340,  6930, -1340,  6930, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340,  6930,  6930,   799,  6930,  6930,
    6930,  6930,  6930,  6930,  6930,  6930,  6930,  6930,  6930,   645,
     782,   783,   785, -1340, -1340, -1340,  3414, -1340, -1340,  7809,
    7809,  6051,   666, -1340, -1340,   666, -1340,  3707,   666,   726,
    4000, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
     768,   776, -1340,   237, -1340,   856, -1340, -1340, 11516, -1340,
   11516,   658,   387, 11234,   525,   727,   728,   658,   795,   759,
     757, -1340, -1340, -1340, -1340, -1340,    17,   647,   -25, -1340,
     592, -1340, -1340, -1340, -1340, 11234, 11234, 11234, -1340,   764,
     717, -1340,   718,   705,   361, -1340,   719,   720,   721, -1340,
      13,    15,   731, -1340, -1340, 11234,    -3, 11234,   801,    41,
   -1340,  6051, -1340,   723,  8973,   804,   854,  8973,   795,   805,
     807, -1340,   -12,   734,   730, -1340,   732,   736,   737,   777,
      18, -1340,   253,   741, -1340,   739,   740,   774, -1340,   745,
    6051,  6051,   746, -1340,    42,    65,    38, -1340, 11234,   825,
   -1340,   -14,   747, -1340, -1340, -1340,   749, -1340,   167, -1340,
   -1340, -1340,   219,   345,   839,   699,   722,   -17, -1340,   794,
    7223, -1340,   754,   755,    95, -1340, -1340,   119,   293,   908,
     908, -1340,    80, -1340, -1340,    83, -1340, -1340,  1551, -1340,
   -1340, -1340, -1340, -1340,     1, 11234,   772,  6051,   827, -1340,
   -1340,   836, -1340,     9,   715, -1340, -1340, -1340, -1340, -1340,
    6930, -1340, -1340, -1340,     8,   223,   223,   182,   -60,   -60,
     -60,   -60,   218,   218, -1340, -1340, 10670, 10670, 11234, 11234,
   -1340,   767, -1340, -1340,   769, -1340, -1340, -1340,   101, -1340,
   -1340,   195,   272,   275,     0, -1340,   237,   237, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,   658, -1340,
     819, 10952,   810,  6051, -1340, -1340, -1340,   858,   814,  6051,
     795,   795,   658, -1340,   624,   795,   382, 11234,   341,   363,
     928, -1340, -1340,   673,    29, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340,    17,   142,   464, -1340,
     735,   335,   -11,   663,   795, -1340, -1340, -1340, -1340,   809,
   11234, -1340, 11234, -1340, -1340,   266,   712, -1340, -1340,   319,
      -3,   858, 10670,   845,   867,   784,   773,   840,   795,   808,
     841,   872,   795,   852, 10670,  6051,   855,   833,   -61,   823,
   -1340, -1340, -1340, -1340,  6051,   860,  6051,  6051,   830, -1340,
     880,   881,  6051, -1340,   800,   802,   831, 11234, -1340, 11234,
   -1340,  6051,   951, -1340,   264, -1340,   179, -1340, -1340,   958,
   -1340,   486,  6051,  6051,  6051,   493,  6051,  6051,  6051,  6051,
    6051,  6051,   869,  6051,  6051,   711,    37,   806,   635,   748,
     837,   874,    84,    61,  1551,  6637,  6637,  6637,   910, -1340,
   -1340,  6051,   389,   886, -1340, 11234,   887, -1340,   877,   879,
    6051,   -54,   853,   -16, -1340,  6051,     8,   210,     6, -1340,
     724,   145,   742,   743, -1340, -1340,   586, -1340,   738,   324,
     847,   849, 10952,   851, -1340,   -15, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340,   857, -1340, -1340, -1340,  6051,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340,  6051, -1340,    10,
      25, -1340,   981,   528, -1340, -1340, -1340,  6051, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340,   729, -1340, -1340,   982, -1340,
   -1340, -1340, -1340, -1340,   358,   983, -1340,   492, -1340, -1340,
   -1340,   703,   174,   706,   329,   707,   708,   544,   781,   -15,
     790,   792,  7516,   744,   751,   142, -1340,   793,   832,  4293,
     834,   842,   875,   843,   846,  6051,   876, -1340,   903,   905,
    6051, 11234,   595,   946, -1340, -1340, -1340, -1340, -1340, -1340,
   10670, -1340,  6051,   795,   919, -1340, -1340, -1340,   795,   919,
   11234, -1340, -1340, 11234,  6051,  6051,   889,  4586, -1340, 11234,
   -1340, -1340,  6051,  6051,   530, -1340,     3, 10388,   531, -1340,
     850, -1340, -1340,  4879,   848,   859, -1340, -1340,   904, -1340,
     390, -1340, -1340,  1023, -1340, -1340, 11234, -1340, -1340,   407,
   -1340, -1340, -1340,   862,   811,   812, -1340, -1340, -1340,   813,
     815, -1340, -1340, -1340, -1340, -1340,   803, 11234,   863, -1340,
     895, -1340,   711, -1340, -1340, -1340,  8395,   748, -1340,  6051,
   11234,   908,    63, -1340, -1340, -1340,   886, -1340,   795, -1340,
     629, -1340,   285,   932, -1340,  6051,   933,   827, 11234, 11234,
   -1340,  6051,   894,  6051,  6051,   -35,   900,   866,   864, -1340,
       8,   816, -1340, -1340,   -98, -1340,   383,    35,   817,     8,
     383,  6930, -1340,   156, -1340, -1340, -1340, -1340, -1340, -1340,
       8,   907,   771,   647,    35, -1340, -1340,   786,   977, -1340,
   -1340, -1340,  9542,   873,   882,   883, -1340, -1340, -1340, -1340,
   -1340, -1340,   878, -1340, -1340, -1340,  6051, -1340, -1340, -1340,
   -1340, -1340,  1029,    -2,  1033,    -2,   797,   965, -1340, -1340,
   -1340, -1340,   902, 11234,   820,   781,  7516, -1340, -1340,   890,
   -1340, -1340, -1340, -1340, -1340, -1340,  6051, 11234, 11234, -1340,
     490, -1340,  6051, -1340,   944,   980,   795,   919, -1340, -1340,
   -1340, -1340,  6051, -1340,   892, -1340, -1340, -1340,   896, -1340,
    6051,  6051, 11234,   897,   194, -1340, -1340, -1340,   901, -1340,
   -1340,   951, 11234,   429, -1340,   951, 11234, -1340, -1340,  6051,
    6051,  6051,  6051,  6051, -1340,  6051,  6051, -1340, -1340,   152,
   -1340,   906, -1340, -1340, -1340, -1340,   932, -1340, -1340, -1340,
     795, -1340, -1340, -1340, -1340, -1340,  6051, -1340, -1340,  6051,
     938,  6051, -1340, -1340, -1340,   909,  6930, -1340, -1340, -1340,
   -1340, -1340,    43,  6930,  6930,   342, -1340,   742, -1340,    21,
   -1340,   743,     8,   926, -1340, -1340,   818, -1340, -1340, -1340,
   -1340,   984,   912, -1340,   199, -1340, -1340, -1340, -1340,    57,
   -1340,   231,   231, -1340,    -2, -1340, -1340,   209, -1340,  1057,
      35,   913,   979, -1340,  7516,   -57,   821, -1340,   918, -1340,
   -1340, -1340,  1036, -1340, -1340,  6051,   795, -1340, -1340, -1340,
    6051, -1340, -1340,   997,  6051, 11234,  6051, -1340,    -8,   951,
   11234,   899,   951, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
     976,  8395, -1340, -1340, -1340, -1340, -1340, -1340,  6051, -1340,
   -1340,   -60,  6930,  6930,   182,   414, -1340, -1340, -1340, -1340,
   -1340, -1340,  6051, -1340, 10670, -1340, 10670,  1000, -1340, -1340,
   -1340, -1340,  1071, -1340, -1340, -1340,   865, -1340,   965,   993,
   -1340,   539, 11234,   985,   885, 11234,  7516,   986, -1340,   919,
   -1340, 10670, -1340,   921, -1340,   374,   375, -1340,   914,   951,
   -1340,   916, 11234, -1340, -1340,   182,   182,  6930,   920, -1340,
   -1340, 10670, -1340, -1340, -1340,  7516, -1340,   932,   822, 11234,
     994,   891,   993, 11234,   927,  6051, -1340, -1340,  1020,   416,
   -1340, -1340, -1340, -1340,   934,   397, -1340, -1340, -1340,   922,
   -1340,   215,   182, -1340, -1340, -1340, -1340,  6051,   824, 11234,
     999, -1340,  6051, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340,  1001,   966, -1340,   829,   826, 11234, -1340, 11234, -1340,
     828,  6051,   868,   216,  7516, -1340,  7516,  1003,   966, -1340,
     930, 11234, -1340,   870,   937, 11234,   966,   911, -1340,  1005,
   11234,   884,  7516, -1340
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   421,   422,     0,     0,     0,   750,   575,   841,   850,
     755,   753,   736,   842,   845,   798,   891,   759,   737,   738,
     903,   790,   851,   740,   848,   820,   800,   775,   795,   892,
     796,   846,   843,   791,   794,   742,   849,   743,   744,   889,
     905,   888,   792,   811,   805,   745,   793,   747,   746,   890,
     829,   797,   772,   915,   916,   917,   918,   919,   920,   921,
     922,   923,   924,   925,   939,   946,   819,   815,   806,   786,
     735,     0,   814,   822,   830,   940,   810,   441,   787,   788,
     844,   941,   947,   807,   824,     0,   447,   410,   443,   817,
     752,   808,   809,   837,   812,   828,   836,   945,   948,   758,
     799,   839,   442,   827,   832,   739,     0,     0,   359,   825,
     835,   840,   838,   818,   804,   893,   802,   803,   942,     0,
     358,     0,   943,   949,   833,   789,   813,   944,   388,     0,
     420,   834,   816,   823,   831,   826,   894,   780,   785,   784,
     783,   782,   781,   748,   801,     0,   751,   847,   773,   880,
     879,   881,   757,   756,   776,   886,   741,   878,   883,   884,
     875,   779,   821,   877,   887,   885,   876,   777,   882,   896,
     899,   900,   897,   898,   895,   749,   901,   902,   904,   867,
     866,   853,   771,   764,   860,   856,   774,   770,   869,   870,
     760,   761,   754,   763,   865,   864,   861,   857,   874,   868,
     863,   859,   852,   762,   873,   872,   766,   768,   767,   858,
     862,   854,   769,   855,   765,   871,   926,   927,   928,   929,
     930,   931,   907,   908,   906,   912,   913,   914,   909,   910,
     911,   778,   932,   933,   934,   935,   936,   937,   938,     0,
       0,     2,     0,     5,     7,    19,     0,     0,    24,    27,
      37,    30,    31,    32,    58,    33,    42,    38,    62,    63,
      64,    59,    60,    66,    67,    36,    34,    35,    40,    41,
      61,   211,   210,   207,   208,   209,    39,    14,   187,   188,
     192,   194,   226,   232,     0,     0,   224,   225,   195,   196,
     197,   198,   199,   314,   316,   318,   328,   332,   334,   337,
     342,   345,   348,   350,   352,   354,     0,   356,   362,   364,
       0,   380,   363,   384,   387,   389,   392,   394,     0,   399,
     396,     0,   407,   417,   419,   393,   423,   430,   439,   431,
     432,   433,   436,   437,   434,   435,   454,   456,   457,   458,
     455,   503,   504,   505,   506,   507,   508,   416,   549,   541,
     548,   547,   546,   543,   545,   542,   544,   440,   438,   576,
     577,    65,   200,   201,   203,   202,   204,   205,   206,   418,
     734,   841,   850,   848,   510,   751,     0,   514,     0,   520,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   115,   116,
       0,     0,     0,     0,   111,   112,   113,   114,   121,     0,
       0,     0,     0,     0,     0,     0,   109,   168,   171,   174,
     173,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   235,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   412,   415,   402,     0,     0,   736,   759,
     738,   903,   790,   851,   740,   800,   791,   742,   905,   811,
     745,   747,   746,   829,   939,   946,   735,   940,   941,   947,
     812,   945,   948,   893,   942,   943,   949,   944,   894,   886,
     878,   884,   875,   777,   896,   899,   900,   897,   749,   901,
     904,   408,   418,   734,   400,   401,   404,   736,   737,   738,
     742,   743,   744,   745,   735,   741,   444,     0,   406,   405,
     445,     0,   470,     0,   411,   732,     0,   733,   383,     0,
     414,   413,   403,   386,     0,     0,   499,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   158,   155,   166,
     167,     0,     0,     0,     0,     3,     1,     6,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   190,
     189,     0,   234,     0,     0,     0,     0,     0,     0,     0,
     212,   231,   227,   233,   228,   230,   229,     0,     0,     0,
       0,   373,     0,     0,   371,     0,   323,     0,   372,   365,
     370,   369,   368,   367,   366,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   361,   360,   357,     0,   381,   385,     0,
       0,     0,   395,   427,   398,   397,   409,     0,   424,     0,
       0,   511,   515,   521,   731,    84,    69,    70,   149,   150,
       0,     0,   170,     0,   169,     0,    75,    76,     0,   172,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   586,   587,   588,   118,   117,     0,    74,   125,   122,
       0,   124,   123,   120,   119,     0,     0,     0,   110,     0,
       0,   555,     0,     0,     0,   551,     0,     0,     0,   565,
       0,     0,     0,   214,   215,     0,     0,     0,   151,     0,
     181,     0,   579,     0,     0,    93,     0,     0,     0,    85,
     249,   250,     0,     0,     0,   556,     0,     0,     0,     0,
       0,   297,     0,     0,   554,     0,     0,     0,   573,     0,
       0,     0,     0,   559,     0,     0,     0,   446,   471,   470,
     467,     0,     0,   501,   500,   382,     0,   498,     0,   599,
     600,   550,     0,     0,     0,     0,     0,     0,   605,     0,
       0,   164,     0,     0,     0,   252,   269,    20,     0,    21,
       0,     4,     0,    25,    11,     0,    26,    15,   841,    28,
      12,    29,    16,   193,     0,     0,     0,     0,     0,   213,
     270,   236,   237,     0,   315,   317,   321,   327,   326,   325,
       0,   322,   319,   320,     0,   336,   335,   333,   339,   340,
     341,   338,   343,   344,   347,   346,     0,     0,     0,     0,
     378,     0,   390,   391,     0,   428,   425,   452,     0,   578,
     450,     0,     0,     0,     0,    73,     0,     0,    48,    50,
      51,    52,    53,    55,    56,    57,    49,    54,    44,    45,
       0,     0,   101,     0,    97,    99,   100,   104,   107,     0,
       0,     0,    43,    83,     0,     0,     0,     0,     0,     0,
       0,   681,   686,     0,     0,   682,   716,   669,   671,   672,
     673,   675,   677,   676,   674,   678,     0,     0,     0,   126,
       0,     0,   129,     0,     0,   519,   509,   552,   553,     0,
       0,   569,     0,   566,   618,     0,     0,   216,   217,     0,
     222,   183,     0,     0,   152,     0,     0,     0,     0,     0,
       0,    86,     0,     0,     0,     0,     0,     0,     0,     0,
     558,   557,   564,   572,     0,     0,     0,     0,     0,   518,
       0,     0,     0,   374,     0,     0,     0,     0,   562,     0,
     560,     0,   470,   468,     0,   459,     0,   448,   449,     0,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   841,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   191,
     223,     0,   281,   277,   279,     0,   271,   272,     0,     0,
       0,     0,     0,     0,   324,     0,     0,     0,     0,   647,
     330,   620,   624,   626,   628,   630,   633,   640,   641,   649,
     851,   739,     0,   748,   349,   527,   533,   534,   536,   580,
     581,   537,   540,   351,   353,   524,   355,   379,   429,     0,
     426,   451,    81,    82,    79,    80,   176,     0,   175,     0,
       0,    46,     0,     0,   102,   103,   105,     0,   106,    71,
      72,    77,    78,    68,   687,     0,   690,   717,     0,   680,
     679,   684,   683,   715,     0,     0,   692,     0,   688,   691,
     670,     0,     0,     0,     0,     0,     0,     0,   127,   133,
       0,     0,     0,     0,     0,     0,   130,     0,     0,     0,
       0,     0,   573,     0,     0,     0,     0,   218,     0,     0,
       0,     0,   263,     0,   260,   265,   221,   184,   153,   182,
       0,   185,     0,     0,    95,    89,    92,    91,     0,    87,
       0,   526,   254,     0,     0,     0,     0,     0,   163,     0,
     295,   299,     0,     0,     0,   302,     0,     0,     0,   309,
       0,   376,   375,     0,     0,     0,   296,   471,     0,   460,
       0,   494,   491,     0,   495,   496,     0,   497,   490,     0,
     465,   493,   492,     0,     0,     0,   592,   593,   589,     0,
       0,   597,   598,   594,   603,   601,     0,     0,     0,   607,
     161,   160,     0,   157,   156,   165,     0,   608,   609,     0,
       0,    22,     0,    13,    17,    18,   278,   290,     0,   291,
       0,   282,   283,   284,   285,     0,   274,     0,     0,     0,
     239,     0,     0,     0,     0,     0,     0,     0,     0,   631,
     644,     0,   329,   331,     0,   663,     0,     0,     0,     0,
       0,     0,   619,   621,   622,   658,   659,   660,   662,   661,
       0,     0,   635,   634,     0,   638,   642,   656,   654,   653,
     646,   650,     0,     0,     0,     0,   530,   532,   531,   528,
     525,   453,     0,   178,   177,   180,     0,    47,    98,   108,
     704,   685,     0,   709,     0,   709,   698,   693,   128,   134,
     136,   135,     0,     0,     0,   131,     0,    23,   512,     0,
     570,   571,   574,   567,   568,   258,     0,     0,     0,   220,
     261,   264,     0,   154,     0,    94,     0,    88,   251,   248,
     256,   255,     0,   522,     0,   298,   300,   305,     0,   303,
       0,     0,     0,     0,     0,   310,   377,   516,     0,   563,
     561,   470,     0,     0,   502,   470,     0,   466,    10,     0,
       0,     0,     0,     0,   606,     0,     0,   159,   615,     0,
     610,     0,   253,   294,   292,   293,   286,   287,   288,   280,
       0,   275,   273,   238,   247,   241,     0,   243,   240,     0,
       0,     0,   648,   639,   645,     0,     0,   718,   719,   729,
     728,   727,     0,     0,     0,     0,   720,   625,   726,     0,
     623,   627,     0,     0,   632,   636,     0,   657,   652,   655,
     651,     0,     0,   538,     0,   535,   585,   529,   186,     0,
     705,     0,     0,   703,   710,   711,   707,     0,   702,     0,
     700,     0,   694,   695,     0,     0,     0,   132,     0,   513,
     259,   267,   268,   262,   219,     0,     0,    90,   257,   523,
       0,   306,   304,     0,     0,     0,     0,   517,     0,   470,
       0,     0,   470,   590,   591,   595,   596,   602,   604,   162,
       0,     0,   611,   617,   289,   276,   245,   242,     0,   244,
     643,   730,     0,     0,   722,     0,   668,   667,   666,   665,
     664,   629,     0,   721,     0,   582,     0,     0,   179,   714,
     713,   712,     0,   706,   699,   697,     0,   689,     0,   137,
     139,   141,     0,     0,     0,     0,     0,     0,   313,    96,
     301,     0,   311,     0,   307,   480,   474,   469,     0,   470,
     461,     0,     0,   616,   246,   724,   723,     0,     0,   583,
     539,     0,   708,   701,   696,     0,   143,   142,     0,     0,
       0,     0,   138,     0,     0,     0,   488,   482,     0,   481,
     483,   489,   486,   476,     0,   475,   477,   487,   463,     0,
     462,     0,   725,   637,   584,   140,   144,     0,     0,     0,
       0,   266,     0,   308,   473,   484,   485,   472,   478,   479,
     464,     0,     0,   145,     0,     0,     0,   312,     0,   612,
       0,     0,     0,     0,     0,   147,     0,     0,     0,   146,
       0,     0,   613,     0,     0,     0,     0,     0,   614,     0,
       0,     0,     0,   148
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1340, -1340,  -231,   888, -1340,   898,   924, -1340,   893,  -223,
    -518,  -555, -1340,   453,  -351, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,  -926,
   -1340, -1340, -1340, -1340,    69,   279,   750, -1340, -1340,   762,
   -1340,    39,  -881, -1340,  -383,  -408, -1340, -1340,  -581, -1340,
    -716, -1340, -1340,   -48, -1340, -1340, -1340, -1340, -1340,   289,
     787, -1340, -1340, -1340,   225,   753, -1339,  -526,    40, -1340,
    -569,   364, -1340, -1340, -1340, -1340,   235, -1340, -1340,   915,
   -1340, -1340, -1340, -1340, -1340,   -65,  -761,  -772, -1340, -1340,
   -1340,    24, -1340, -1340,  -153,    47,   -40, -1340, -1340, -1340,
     -55, -1340, -1340,   173,   -49, -1340, -1340,   -43, -1198, -1340,
     664,    31, -1340, -1340,    28, -1340, -1340, -1340,    27, -1340,
   -1340,   600,   594, -1340,  -537, -1340, -1340,  -603,   154,  -594,
     150,   155, -1340, -1340, -1340, -1340, -1340,   917, -1340, -1340,
   -1340, -1340,  -788,  -302, -1079, -1340,  -116, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340,   -38, -1177, -1340, -1340,   347,    26,
   -1340,  -763, -1340, -1340, -1340, -1340, -1340, -1340, -1340,   549,
   -1340,  -939, -1340,    20, -1340,   442,  -744, -1340, -1340, -1340,
   -1340, -1340,  -382,  -375, -1082,  -975, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340,   366,  -728,  -817,    97,
    -799, -1340,   -53,  -824, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340,   775,   789,  -428,   286,   135, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
       7, -1340, -1340,    -5, -1340, -1340,  -982, -1340, -1340, -1340,
     -44,   -51,  -202,   198, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340,   -42, -1340, -1340,
   -1340,  -197,   190,   321, -1340, -1340, -1340, -1340, -1340,   131,
   -1340, -1340, -1262, -1340, -1340, -1340,  -646, -1340,   -76, -1340,
    -214, -1340, -1340, -1340, -1340, -1170, -1340,   -29, -1340,  -372,
    -369,    16,   -71
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   240,   780,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   858,   859,   860,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,  1134,
     718,   264,   265,   864,   865,   866,  1200,   266,   415,   416,
     267,  1098,   899,   268,  1519,  1520,   269,   270,   433,   271,
     548,   770,   986,  1201,   272,   273,   274,   275,   276,   417,
     418,   419,   420,   709,   710,  1177,  1058,   277,   278,   570,
     279,   280,   281,   580,   431,   919,   920,   282,   581,   283,
     583,   284,   285,   286,   801,   802,  1122,   937,   287,   720,
     774,   721,   706,  1123,  1124,  1125,   775,   584,   585,  1006,
    1007,  1381,   586,  1003,  1004,  1221,  1222,  1223,  1224,   288,
     730,   731,   289,  1154,  1155,  1156,   290,  1158,  1159,   291,
     292,   293,   294,   810,   295,  1242,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   605,   606,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   632,   633,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   838,
     335,   336,   337,  1179,   749,   750,   751,  1537,  1574,  1575,
    1568,  1569,  1576,  1570,  1180,  1181,   338,   339,  1182,   340,
     341,   342,   343,   344,   345,   346,  1044,   938,  1034,  1279,
    1035,  1424,  1036,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   737,  1111,   357,   358,   359,   360,  1038,
    1039,  1040,  1041,   361,   362,   363,   364,   365,   366,   767,
     768,   367,  1207,  1208,  1369,   368,  1020,  1252,  1253,  1021,
    1022,  1023,  1024,  1025,  1262,  1414,  1415,  1026,  1265,  1027,
    1395,  1028,  1029,  1270,  1271,  1420,  1418,  1254,  1255,  1256,
    1257,  1499,   677,   887,   888,   889,   890,   891,   892,  1088,
    1441,  1442,  1089,  1440,  1515,   893,  1295,  1437,  1433,  1434,
    1435,   894,   895,  1258,  1266,  1405,  1259,  1401,  1243,  1135,
     526,   369,   370
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int xquery_parser::yytable_ninf_ = -235;
  const short int
  xquery_parser::yytable_[] =
  {
       503,   794,  1037,  1037,   948,   964,  1139,   817,   627,   645,
    1043,   789,   791,   533,   503,   565,   567,   818,   819,   820,
     821,  1106,   562,  1302,  1377,  1378,  1018,  1178,   670,  1368,
    1482,  1012,     7,   501,  1238,  1443,   503,  1037,   784,   787,
     790,   792,  1011,   376,   378,   380,   783,   786,   503,   916,
     503,  1019,   689,   806,   563,   807,   808,  1522,   809,   563,
     811,   535,  1063,   715,   719,   563,   897,   876,   812,   813,
     877,   726,   844,  1099,   563,  1013,  1145,  1009,   644,   934,
    1105,   563,  1535,   644,   563,   563,   982,   502,  1231,   693,
     568,  1492,   381,   382,  1416,   383,   384,  1357,  1037,  1340,
     934,   516,  1009,   665,   568,  1128,   666,  1389,   753,   694,
    1037,   965,  1397,   878,    77,   389,   910,  1141,   912,   707,
     435,   945,  1085,   522,  1276,   935,  1234,    88,  1402,  1431,
     626,   656,  1056,   421,   615,   527,   990,   529,  1086,  1066,
    1202,   945,  1283,   616,   923,   957,   521,   559,  1057,   436,
    1398,  1010,   102,   121,  1240,  1277,  1015,  1285,   547,  1016,
     568,  1523,   657,   716,   560,   668,  1146,  1493,   959,  1536,
    1212,   569,  1278,  1286,   608,  1091,   966,   121,  1484,   121,
    1087,  1092,   693,  1341,   571,   999,   708,  1116,  1171,  1172,
     572,   609,  1432,  1127,   911,   573,   913,   628,   991,  1093,
     946,  1094,   694,   574,  1049,   898,   936,   917,  1037,   717,
    1095,   983,  1327,   936,   714,   575,   397,  1298,  1168,   898,
     961,  1203,   924,   958,   789,   791,   669,  1448,  1018,  1018,
     695,  1178,   936,  1274,     7,  1508,  1096,   564,  1244,  1232,
    1178,  1236,   566,   536,  1524,   918,   960,   503,   777,  1244,
     503,   936,  1235,  1019,  1019,   936,  1554,   779,  1394,   783,
     786,  1017,   879,  1609,   995,  1059,  1060,   997,  1211,   754,
    1516,  1357,  1205,  1014,   400,   880,   936,   881,  1173,  1622,
     634,  1099,  1050,   636,  1496,  1403,  1404,  1628,   882,   883,
     884,  1497,   885,   969,   886,   424,   873,  1174,  1049,  1175,
    1057,  1498,  1506,  1480,  1543,   449,  1037,   428,  1465,  1245,
     971,   576,  1512,  1323,   577,   653,    77,   503,  1601,  1617,
    1245,   993,   503,  1556,  1292,   425,   503,   711,   578,    88,
     778,   107,   503,  1037,   502,   608,   611,   502,   560,   503,
    1343,   782,   785,  1284,   934,   927,   931,   119,   930,   617,
     503,   970,   609,   579,   102,  1481,   503,   934,  1015,  1586,
    1097,  1016,   450,   618,   612,  1521,   503,  1176,  1118,   503,
     503,   503,   503,   503,  1466,  1119,  1051,   613,   503,  1566,
    1507,   121,  1294,  1171,  1171,   145,   503,  1218,   432,  1169,
    1513,  1246,  1247,  1120,  1248,   947,  1602,  1618,  1572,  1171,
    1172,  1249,  1246,  1247,   655,  1248,  1171,  1220,  1115,   661,
     614,  1250,  1009,   527,  1178,  1052,  1171,  1172,  1054,   678,
    1572,  1566,  1250,  1251,  1447,  1171,   680,   434,   451,   452,
     972,   973,  1053,  1121,  1251,  1055,   975,   527,  1171,  1172,
     789,   791,   789,   701,   544,   974,   503,  1521,  1037,   545,
     437,  1292,  1018,   722,  1170,  1423,   527,   727,   728,   729,
     732,  1018,   690,  1390,   692,   738,   698,  1293,   438,  1213,
    1214,  1215,  1018,   745,   713,   503,  1521,  1019,   861,   723,
     441,  1217,  1110,   503,  1113,   733,  1019,   735,   736,  1173,
     739,  1218,  1174,  1174,  1175,  1175,   742,  1019,  1069,  1070,
     429,  1219,  1567,  1073,  1573,   430,  1173,  1061,  1174,  1294,
    1175,  1220,   442,   832,   833,  1174,   503,  1175,   538,   862,
     539,  1061,   711,   711,   863,  1174,  1598,  1175,  1173,  1164,
    1529,  1165,  1108,   732,  1174,  1619,  1175,  1620,   711,  1118,
     665,   443,   107,   666,  1595,   711,  1119,  1174,   455,  1175,
    -234,   996,   608,  1633,   992,   711,   976,   977,   119,   107,
    1571,  1577,   769,   752,   711,  1267,  1268,   608,   444,   609,
     776,   978,   447,   398,   756,   119,   667,   711,  1352,   456,
     453,   107,   457,  1009,   609,  1085,   646,   846,  1269,   847,
     386,   610,   503,   773,  1571,  1356,   145,   119,  1079,   647,
    1577,  1086,   668,   803,   399,  1496,  1547,  1468,   390,  1080,
     391,  1471,  1497,   145,   503,   503,   503,  1470,   650,   392,
    1081,   541,  1498,   542,  1018,   648,  1153,  1157,  1103,   448,
     934,  1082,   401,   651,   503,   145,   503,  1104,   649,  1338,
    1344,  1218,   429,   503,  1118,  1399,   503,   430,  1409,  1019,
     517,  1119,  1400,  1074,  1075,  1076,   789,   868,   835,  1077,
     862,   835,   869,   669,   835,   863,   831,   635,   629,   630,
     422,   834,   638,   423,   652,   426,   654,   503,   427,   867,
    1037,   439,  1037,   445,   440,   454,   446,  1549,   504,  1550,
     686,   404,   405,   406,   407,   540,   408,   409,   687,   411,
     412,   901,   902,   903,   631,   413,   637,  1037,   671,   672,
     673,  1184,   523,  1185,  1564,   505,   627,  1429,  1189,   506,
    1190,   915,   518,   921,   503,  1538,   519,  1037,  1541,   524,
     527,   674,   675,   527,  1584,   848,   849,   850,   851,   852,
     853,   854,   855,   856,   857,   683,   684,  1071,  1072,  1100,
    1101,   925,  1374,  1375,   530,   503,   503,   503,   503,   590,
     531,  1325,   815,   816,   962,   822,   823,   591,   592,   532,
     593,   534,   824,   825,   537,  1045,  1045,   543,   594,   546,
     954,   955,   595,   547,   596,  1509,  1510,   549,   550,   597,
     503,   552,   702,  1557,   551,  1579,   553,   554,   556,   587,
    1494,  1495,  1491,   588,   589,   598,   503,   619,   620,   607,
     987,  1000,   622,   621,   639,   631,   641,   642,   640,   644,
     643,   658,   386,   660,   662,   663,   676,   679,   599,   600,
     601,   602,   603,   604,   681,   682,   685,   691,   703,   503,
     704,   503,  1042,  1042,  1042,  1042,  1373,   705,   711,   734,
     740,   503,   741,   747,   423,   748,   427,   440,   446,   457,
     755,   757,   758,   503,   781,   761,   795,   814,   766,   826,
     839,   842,   796,   827,   828,   797,   829,  1042,   798,   843,
     845,   874,   870,   871,   875,   900,   503,   896,   503,  1545,
    1546,   904,   922,  1078,   929,   905,   906,   928,   932,   909,
     907,   908,   759,   760,   926,   762,   763,   764,   765,   914,
     933,   940,   939,   941,   944,   771,   772,   942,   943,   949,
     950,   951,   952,   953,   956,   967,  1112,   968,  1112,   980,
     979,   984,   793,   989,   503,   988,   994,  1001,  1042,  1008,
     981,  1005,   799,   800,  1582,  1047,  1062,   863,  1048,   934,
    1042,  1067,  1083,  1084,  1457,  1102,  1107,  1109,  1130,   707,
    1117,   503,  1131,  1136,  1132,  1138,  1140,  1133,  1137,  1143,
    1144,  1147,  1152,   738,  1149,   738,  1153,  1157,  1161,  1163,
    1162,  1167,  1183,  1197,  1204,  1209,   667,  1206,  1210,  1225,
    1227,  1228,  1160,  1229,  1260,  1233,  1280,  1261,  1272,  1264,
    1273,   837,  1275,  1241,   837,     7,  1291,  1296,  1485,  1290,
    1300,   898,  1301,  1306,  1312,  1310,  1307,  1317,  1316,  1318,
    1322,  1226,  1326,  1311,  1313,  1303,  1332,  1314,  1346,  1349,
    1354,  1351,  1366,  1363,  1218,  1380,  1386,  1359,  1360,  1361,
    1350,  1362,  1391,  1365,  1392,  1393,  1358,  1413,  1042,  1412,
     503,  1304,  1419,  1430,  1425,  1237,  1428,  1436,  1085,   503,
    1396,  1406,  1439,  1426,  1427,  1455,  1417,  1444,  1449,   503,
    1459,  1446,   503,  1456,  1502,  1504,  1460,  1464,   503,  1467,
    1488,  1514,  1518,  1526,  1483,  1527,   503,  1490,  1531,  1540,
    1542,  1551,  1503,  1505,  1517,  1552,  1555,  1282,  1583,  1559,
    1563,  1565,  1525,  1560,  1578,   503,  1580,  1592,  1589,  1590,
    1594,  1597,  1600,  1606,  1057,  1608,  1610,  1621,  1626,  1630,
     872,  1587,  1623,  1604,  1553,  1611,   503,   555,  1614,  1629,
     381,   382,  1288,   383,   384,   503,   385,  1320,   561,   503,
     557,  1064,   386,  1562,  1305,   664,  1042,  1585,  1129,  1309,
     387,  1625,   388,   389,  1367,  1126,   722,   503,   503,  1329,
     390,  1002,   391,  1383,  1328,   732,   558,  1453,  1616,  1321,
    1372,   392,  1382,  1042,  1216,   393,  1379,   688,   659,  1376,
    1335,   746,  1339,   805,  1632,  1345,   712,  1334,   804,   841,
    1353,   963,  1355,  1599,  1596,  1046,  1299,  1287,  1114,   582,
     696,   503,  1370,  1348,  1364,  1407,   394,   395,   396,  1411,
    1501,  1410,  1500,   769,   697,  1239,  1263,  1090,  1297,  1438,
    1511,  1408,   502,   625,     0,     0,   776,  1065,     0,     0,
       0,     0,   503,  1068,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   803,  1384,   503,   503,     0,     0,
       0,     0,     0,     0,   397,     0,     0,     0,     0,     0,
       0,     0,     0,   398,     0,     0,     0,     0,     0,     0,
       0,   503,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   503,     0,     0,     0,   503,     0,     0,  1042,     0,
       0,     0,     0,     0,   399,     0,     0,     0,     0,  1142,
       0,     0,     0,     0,     0,     0,     0,     0,  1148,     0,
    1150,  1151,   400,     0,     0,     0,     0,     0,     0,  1445,
       0,     0,   401,     0,     0,  1166,     0,     0,     0,     0,
       0,     0,     0,  1451,  1452,     0,  1186,  1187,  1188,     0,
    1191,  1192,  1193,  1194,  1195,  1196,     0,  1198,  1199,     0,
       0,     0,     0,     0,   402,     0,     0,     0,  1463,     0,
       0,     0,     0,     0,     0,  1002,     0,     0,  1469,     0,
       0,     0,  1472,     0,  1230,     0,     0,     0,     0,     0,
     403,   404,   405,   406,   407,     0,   408,   409,   410,   411,
     412,     0,     0,     0,   503,   413,   414,     0,     0,   503,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     503,     0,     0,  1281,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1289,     0,   503,     0,   503,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   503,     0,     0,   503,     0,     0,     0,     0,     0,
     503,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   503,     0,     0,     0,     0,     0,     0,     0,  1315,
     503,  1533,     0,     0,  1319,     0,  1539,     0,   503,     0,
       0,     0,   503,     0,     0,     0,  1324,   502,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1330,  1331,
       0,     0,     0,     0,     0,     0,  1336,  1337,   503,     0,
    1042,     0,  1042,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   503,     0,   503,  1558,     0,
       0,  1561,  1548,     0,     0,     0,     0,  1042,     0,     0,
     503,     0,     0,     0,   503,     0,     0,     0,  1581,   503,
       0,     0,     0,     0,     0,     0,     0,  1042,     0,     0,
       0,     0,     0,  1371,     0,  1588,     0,     0,     0,  1591,
       0,     0,     0,     0,     0,     0,     0,     0,   385,  1002,
       0,     0,     0,     0,   386,  1385,     0,  1387,  1388,     0,
       0,     0,   387,     0,   388,  1605,     0,     0,     0,     0,
       0,     0,   390,     0,   391,     0,     0,     0,     0,     0,
       0,     0,  1612,   392,  1613,     0,     0,   393,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1624,     0,     0,
       0,  1627,     0,     0,     0,     0,  1631,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   394,   395,
     998,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1450,     0,     0,     0,     0,     0,  1454,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1458,     0,     0,     0,
       0,     0,     0,     0,  1461,  1462,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   398,     0,     0,     0,     0,
       0,     0,     0,  1473,  1474,  1475,  1476,  1477,     0,  1478,
    1479,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   399,     0,     0,     0,
    1486,     0,     0,  1487,     0,  1489,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   401,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   402,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1528,
       0,     0,     0,     0,  1530,     0,     0,     0,  1532,     0,
    1534,     0,   403,   404,   405,   406,   407,     0,   408,   409,
     410,   411,   412,     0,     0,     0,     0,   413,   414,     0,
       0,     0,  1544,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1593,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1603,     0,     0,     0,     0,  1607,     0,     0,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     0,     7,     0,     0,  1615,     8,     9,     0,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,     0,    29,
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
       0,     0,   122,   123,   124,     0,     0,     0,   125,     0,
     126,   127,     0,   128,   129,   130,     0,   131,     0,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
       0,     0,   143,   144,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,     0,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     0,     7,     0,     0,     0,
     371,   372,     0,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,   373,    25,    26,
      27,    28,     0,    29,    30,    31,    32,    33,    34,    35,
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
     374,     0,   125,     0,   126,   127,     0,   128,   129,   130,
       0,   131,     0,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,     0,     0,   143,   144,   145,     0,
     375,   147,   148,   149,   150,   151,   152,   153,   154,   155,
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
       0,     0,     0,   371,   372,     0,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     373,    25,    26,    27,    28,     0,    29,    30,    31,    32,
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
     123,   124,     0,   377,     0,   125,     0,   126,   127,     0,
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
      21,    22,    23,   373,    25,    26,    27,    28,     0,    29,
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
       0,     0,   122,   123,   124,     0,   379,     0,   125,     0,
     126,   127,     0,   128,   129,   130,     0,   131,     0,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
       0,     0,   143,   144,   145,     0,   375,   147,   148,   149,
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
       3,     4,     5,     6,     0,     7,     0,     0,     0,   371,
     372,     0,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,   373,    25,    26,    27,
      28,     0,    29,    30,    31,    32,    33,    34,    35,    36,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,   373,
      25,    26,    27,    28,     0,    29,    30,    31,    32,    33,
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
     124,     0,   830,     0,   125,     0,   126,   127,     0,   128,
     129,   130,     0,   131,     0,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,     0,     0,   143,   144,
     145,     0,   375,   147,   148,   149,   150,   151,   152,   153,
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
       0,     7,     0,     0,     0,   371,   372,     0,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,   373,    25,    26,    27,    28,     0,    29,    30,
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
       0,   122,   123,   124,     0,     0,     0,   125,   836,   126,
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
      19,    20,    21,    22,    23,   373,    25,    26,    27,    28,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
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
     125,   840,   126,   127,     0,   128,   129,   130,     0,   131,
       0,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,     0,     0,   143,   144,   145,     0,   375,   147,
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
       0,   371,   372,     0,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,   373,    25,
      26,    27,    28,     0,    29,    30,    31,    32,    33,    34,
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
       0,  1308,     0,   125,     0,   126,   127,     0,   128,   129,
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
      23,   373,    25,    26,    27,    28,     0,    29,    30,    31,
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
     122,   123,   124,     0,  1333,     0,   125,     0,   126,   127,
       0,   128,   129,   130,     0,   131,     0,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,     0,     0,
     143,   144,   145,     0,   375,   147,   148,   149,   150,   151,
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
       5,     6,     0,     7,     0,     0,     0,   371,   372,     0,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   373,    25,    26,    27,    28,     0,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
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
     121,     0,     0,   122,   123,   124,     0,  1347,     0,   125,
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
       8,     9,     0,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,    29,    30,    31,    32,    33,    34,    35,
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
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
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
       0,     0,     0,     8,     9,     0,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,     0,    29,    30,    31,    32,
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
       6,     0,     7,     0,     0,     0,   371,   372,     0,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,   461,
     462,    22,   464,   373,    25,   465,    27,    28,     0,    29,
      30,    31,    32,   466,    34,    35,    36,    37,    38,    39,
     468,    41,    42,   469,     0,    44,    45,    46,   471,   472,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     0,    67,
      68,    69,    70,    71,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,    88,     0,    89,
      90,    91,    92,     0,    93,     0,     0,     0,   480,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,   105,     0,     0,     0,   106,
     107,   623,   109,   110,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,   119,     0,   624,   121,
       0,     0,   122,   123,   124,     0,     0,     0,   125,     0,
     126,   127,     0,   128,   129,   130,     0,   131,     0,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
       0,     0,   143,   144,   145,     0,   375,   147,   148,   149,
     150,   151,   152,   153,   154,   489,   156,   490,   158,   491,
     492,   161,   162,   163,   164,   165,   166,   493,   168,   494,
     495,   496,   497,   173,   174,   498,   499,   177,   500,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,     0,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     4,     5,     6,     0,     7,     0,     0,     0,   371,
     372,     0,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,   373,    25,    26,    27,
      28,     0,    29,    30,    31,    32,    33,    34,    35,    36,
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
      25,    26,    27,    28,     0,    29,    30,    31,    32,    33,
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
     145,     0,   375,   147,   148,   149,   150,   151,   152,   153,
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
       0,     7,     0,     0,     0,   788,   372,     0,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,   373,    25,    26,    27,    28,     0,    29,    30,
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
      19,   461,   462,    22,   464,   373,    25,   465,    27,    28,
       0,    29,    30,    31,    32,   466,    34,    35,    36,    37,
      38,    39,   468,    41,    42,   469,     0,    44,    45,    46,
     471,   472,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
       0,    67,    68,    69,    70,    71,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,     0,     0,    88,
       0,    89,    90,    91,    92,     0,    93,     0,     0,     0,
     480,    95,    96,    97,    98,     0,     0,     0,     0,     0,
       0,    99,   100,   101,   102,   103,   104,   105,     0,     0,
       0,   106,   107,   108,   109,   110,     0,     0,     0,     0,
     111,   112,   113,   114,   115,   116,   117,   118,   119,     0,
     120,   121,     0,     0,   122,   123,   124,     0,     0,     0,
     125,     0,   126,   127,     0,   128,   129,   130,     0,   131,
       0,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,     0,     0,   143,   144,   145,     0,   375,   147,
     148,   149,   150,   151,   152,   153,   154,   489,   156,   490,
     158,   491,   492,   161,   162,   163,   164,   165,   166,   493,
     168,   494,   495,   496,   497,   173,   174,   498,   499,   177,
     500,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,   192,     0,   193,   194,   195,
     196,   197,   198,     0,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     0,     7,     0,     0,
       0,   985,   372,     0,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,   373,    25,
      26,    27,    28,     0,    29,    30,    31,    32,    33,    34,
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
      13,    14,    15,    16,    17,    18,    19,   461,   462,    22,
     464,   373,    25,   465,    27,    28,     0,    29,    30,    31,
      32,   466,    34,    35,    36,    37,    38,    39,   468,    41,
      42,   469,     0,    44,    45,    46,   471,   472,    49,   473,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,     0,    67,    68,    69,
      70,    71,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,    88,     0,    89,    90,    91,
      92,     0,    93,     0,     0,     0,   480,    95,    96,    97,
      98,     0,     0,     0,     0,     0,     0,    99,   100,   101,
     102,   103,   104,   105,     0,     0,     0,   106,   107,     0,
     109,   110,     0,     0,     0,     0,   111,   112,   113,   114,
     115,   116,   117,   118,   119,     0,     0,     0,     0,     0,
     122,   123,   124,     0,     0,     0,   125,     0,   126,   127,
       0,   128,   129,   130,     0,   131,     0,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,     0,     0,
     143,   144,   145,     0,   375,   147,   148,   149,   150,   151,
     152,   153,   154,   489,   156,   490,   158,   491,   492,   161,
     162,   163,   164,   165,   166,   493,   168,   494,   495,   496,
     497,   173,   174,   498,   499,   177,   500,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,     0,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     0,     7,     0,     0,     0,   371,   372,     0,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
     461,   462,    22,   464,   373,    25,   465,    27,    28,     0,
      29,    30,    31,    32,   466,    34,    35,    36,    37,    38,
      39,   468,    41,    42,   469,     0,    44,    45,    46,   471,
     472,    49,   473,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,     0,
      67,    68,    69,    70,    71,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,     0,     0,    88,     0,
      89,    90,    91,    92,     0,    93,     0,     0,     0,   480,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
      99,   100,   101,   102,   103,   104,   105,     0,     0,     0,
     106,   107,     0,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,   119,     0,     0,
       0,     0,     0,   122,   123,   124,     0,     0,     0,   125,
       0,   126,   127,     0,     0,     0,   130,     0,   131,     0,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,     0,     0,   143,   144,   145,     0,   375,   147,   148,
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
     371,   372,     0,    10,    11,   458,    13,    14,    15,    16,
     459,    18,   460,   461,   462,   463,   464,   373,    25,   465,
      27,    28,     0,    29,    30,    31,    32,   466,    34,   467,
      36,    37,    38,    39,   468,    41,    42,   469,     0,    44,
     470,    46,   471,   472,    49,   473,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,   474,
     475,    66,     0,    67,    68,    69,   476,     0,    72,    73,
      74,     0,     0,   477,    76,     0,     0,     0,     0,    78,
      79,    80,   478,   479,    83,    84,     0,     0,     0,     0,
       0,     0,     0,    89,    90,    91,    92,     0,    93,     0,
       0,     0,   480,    95,    96,   481,   482,     0,     0,     0,
       0,     0,     0,    99,   100,   101,     0,   103,   104,   105,
       0,     0,     0,     0,     0,     0,   109,   110,     0,     0,
       0,     0,   111,   112,   113,   114,   483,   116,   117,   484,
       0,     0,     0,     0,     0,     0,   485,   486,   124,     0,
       0,     0,   125,     0,   126,   487,     0,     0,     0,   130,
       0,   131,     0,   132,   133,   134,   135,   488,   137,   138,
     139,   140,   141,   142,     0,     0,   143,   144,     0,     0,
     375,   147,   148,   149,   150,   151,   152,   153,   154,   489,
     156,   490,   158,   491,   492,   161,   162,   163,   164,   165,
     166,   493,   168,   494,   495,   496,   497,   173,   174,   498,
     499,   177,   500,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,   192,     0,   193,
     194,   195,   196,   197,   198,     0,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,     1,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     0,     6,     0,     0,
       0,     0,     0,   371,   372,     0,    10,    11,   507,    13,
      14,    15,    16,   459,   508,   509,   461,   462,   463,   464,
     373,    25,   465,    27,    28,     0,    29,    30,    31,    32,
     466,    34,   510,    36,   511,   512,    39,   468,    41,    42,
     469,     0,    44,   513,    46,   471,   472,    49,   473,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,   474,   475,    66,     0,    67,    68,    69,   514,
       0,    72,    73,    74,     0,     0,   477,    76,     0,     0,
       0,     0,    78,    79,    80,   478,   479,    83,    84,     0,
       0,     0,     0,     0,     0,     0,    89,    90,    91,    92,
       0,    93,     0,     0,     0,   480,    95,    96,   481,   482,
       0,     0,     0,     0,     0,     0,    99,   100,   101,     0,
     103,   104,   105,     0,     0,     0,     0,     0,     0,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   483,
     116,   117,   484,     0,     0,     0,     0,     0,     0,   485,
     486,   124,     0,     0,     0,   125,     0,   126,   487,     0,
       0,     0,   130,     0,   131,     0,   132,   133,   134,   135,
     488,   137,   138,   139,   140,   141,   142,     0,     0,   143,
     144,     0,     0,   375,   147,   148,   149,   150,   151,   152,
     153,   154,   489,   515,   490,   158,   491,   492,   161,   162,
     163,   164,   165,   166,   493,   168,   494,   495,   496,   497,
     173,   174,   498,   499,   177,   500,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
     192,     0,   193,   194,   195,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   525,
       0,     0,     0,     0,     0,     0,     6,     0,   724,     0,
       0,     0,   371,   372,     0,    10,    11,   507,    13,    14,
      15,    16,   459,   508,   509,   461,   462,   463,   464,   373,
      25,   465,    27,    28,     0,    29,    30,    31,    32,   466,
      34,   510,    36,   511,   512,    39,   468,    41,    42,   469,
       0,    44,   513,    46,   471,   472,    49,   473,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,   474,   475,    66,     0,    67,    68,    69,   514,     0,
      72,    73,    74,     0,     0,   477,    76,     0,     0,     0,
       0,    78,    79,    80,   478,   479,    83,    84,     0,     0,
       0,     0,     0,     0,     0,    89,    90,    91,    92,     0,
      93,     0,     0,     0,   480,    95,    96,   481,   482,     0,
       0,     0,     0,     0,     0,    99,   100,   101,     0,   103,
     104,   105,     0,     0,     0,     0,     0,     0,   109,   110,
       0,     0,     0,     0,   111,   112,   113,   114,   483,   116,
     117,   484,     0,     0,     0,     0,     0,     0,   485,   486,
     124,     0,     0,     0,   125,   725,   126,   487,     0,     0,
       0,     0,     0,   131,     0,   132,   133,   134,   135,   488,
     137,   138,   139,   140,   141,   142,     0,     0,   143,   144,
       0,     0,   375,   147,   148,   149,   150,   151,   152,   153,
     154,   489,   515,   490,   158,   491,   492,   161,   162,   163,
     164,   165,   166,   493,   168,   494,   495,   496,   497,   173,
     174,   498,   499,   177,   500,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   525,     0,
       0,     0,     0,     0,     0,     6,     0,     0,     0,     0,
       0,   371,   372,     0,    10,    11,   507,    13,    14,    15,
      16,   459,   508,   509,   461,   462,   463,   464,   373,    25,
     465,    27,    28,     0,    29,    30,    31,    32,   466,    34,
     510,    36,   511,   512,    39,   468,    41,    42,   469,     0,
      44,   513,    46,   471,   472,    49,   473,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
     474,   475,    66,     0,    67,    68,    69,   514,     0,    72,
      73,    74,     0,     0,   477,    76,     0,     0,     0,     0,
      78,    79,    80,   478,   479,    83,    84,     0,     0,     0,
       0,     0,     0,     0,    89,    90,    91,    92,     0,    93,
       0,     0,     0,   480,    95,    96,   481,   482,     0,     0,
       0,     0,     0,     0,    99,   100,   101,     0,   103,   104,
     105,     0,     0,     0,     0,     0,     0,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   483,   116,   117,
     484,     0,     0,     0,     0,     0,     0,   485,   486,   124,
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
       0,    10,    11,   507,    13,    14,    15,    16,   459,   508,
     509,   461,   462,   463,   464,   373,    25,   465,    27,    28,
       0,    29,    30,    31,    32,   466,    34,   510,    36,   511,
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
       0,     0,     0,     0,   485,   486,   124,     0,     0,     0,
     125,     0,   126,   487,     0,     0,     0,     0,     0,   131,
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
     371,   372,     0,    10,    11,   458,    13,    14,    15,    16,
     459,    18,   460,   461,   462,  1030,   464,   373,    25,   465,
      27,    28,     0,    29,    30,    31,    32,   466,    34,   467,
      36,    37,    38,    39,   468,    41,    42,   469,     0,    44,
     470,    46,   471,   472,    49,   473,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,   474,
     475,    66,     0,    67,    68,    69,   476,     0,    72,    73,
      74,     0,     0,   477,    76,     0,     0,     0,     0,    78,
      79,    80,   478,   479,    83,    84,     0,     0,     0,     0,
       0,     0,     0,    89,    90,    91,    92,     0,    93,     0,
       0,     0,   480,    95,    96,   481,   482,     0,     0,     0,
       0,     0,     0,    99,   100,   101,     0,   103,   104,  1031,
       0,     0,     0,  1032,     0,     0,   109,   110,     0,     0,
       0,     0,   111,   112,   113,   114,   483,   116,   117,   484,
       0,     0,     0,     0,     0,     0,   485,   486,   124,     0,
       0,     0,   125,  1421,   126,   487,     0,     0,     0,  1422,
       0,   131,     0,   132,   133,   134,   135,   488,   137,   138,
     139,   140,   141,   142,     0,     0,  1033,   144,     0,     0,
     375,   147,   148,   149,   150,   151,   152,   153,   154,   489,
     156,   490,   158,   491,   492,   161,   162,   163,   164,   165,
     166,   493,   168,   494,   495,   496,   497,   173,   174,   498,
     499,   177,   500,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,   192,     0,   193,
     194,   195,   196,   197,   198,     0,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,     6,     0,     0,     0,
       0,     0,   371,   372,     0,    10,    11,   507,    13,    14,
      15,    16,   459,   508,   509,   461,   462,   463,   464,   373,
      25,   465,    27,    28,     0,    29,    30,    31,    32,   466,
      34,   510,    36,   511,   512,    39,   468,    41,    42,   469,
       0,    44,   513,    46,   471,   472,    49,   473,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,   474,   475,    66,     0,    67,    68,    69,   514,     0,
      72,    73,    74,     0,     0,   477,    76,     0,     0,     0,
       0,    78,    79,    80,   478,   479,    83,    84,     0,     0,
       0,     0,     0,     0,     0,    89,    90,    91,    92,     0,
      93,     0,     0,     0,   480,    95,    96,   481,   482,     0,
       0,     0,     0,     0,     0,    99,   100,   101,     0,   103,
     104,   105,     0,     0,     0,     0,     0,     0,   109,   110,
       0,     0,     0,     0,   111,   112,   113,   114,   483,   116,
     117,   484,     0,     0,     0,     0,     0,     0,   485,   486,
     124,     0,     0,     0,   125,   699,   126,   487,     0,     0,
       0,   700,     0,   131,     0,   132,   133,   134,   135,   488,
     137,   138,   139,   140,   141,   142,     0,     0,   143,   144,
       0,     0,   375,   147,   148,   149,   150,   151,   152,   153,
     154,   489,   515,   490,   158,   491,   492,   161,   162,   163,
     164,   165,   166,   493,   168,   494,   495,   496,   497,   173,
     174,   498,   499,   177,   500,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,     6,     0,
       0,     0,     0,     0,   371,   372,     0,    10,    11,   507,
      13,    14,    15,    16,   459,   508,   509,   461,   462,   463,
     464,   373,    25,   465,    27,    28,     0,    29,    30,    31,
      32,   466,    34,   510,    36,   511,   512,    39,   468,    41,
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
     485,   486,   124,     0,     0,     0,   125,   743,   126,   487,
       0,     0,     0,   744,     0,   131,     0,   132,   133,   134,
     135,   488,   137,   138,   139,   140,   141,   142,     0,     0,
     143,   144,     0,     0,   375,   147,   148,   149,   150,   151,
     152,   153,   154,   489,   515,   490,   158,   491,   492,   161,
     162,   163,   164,   165,   166,   493,   168,   494,   495,   496,
     497,   173,   174,   498,   499,   177,   500,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,     0,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
       6,     0,     0,     0,     0,     0,   371,   372,     0,    10,
      11,   458,    13,    14,    15,    16,   459,    18,   460,   461,
     462,  1030,   464,   373,    25,   465,    27,    28,     0,    29,
      30,    31,    32,   466,    34,   467,    36,    37,    38,    39,
     468,    41,    42,   469,     0,    44,   470,    46,   471,   472,
      49,   473,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,   474,   475,    66,     0,    67,
      68,    69,   476,     0,    72,    73,    74,     0,     0,   477,
      76,     0,     0,     0,     0,    78,    79,    80,   478,   479,
      83,    84,  1342,     0,     0,     0,     0,     0,     0,    89,
      90,    91,    92,     0,    93,     0,     0,     0,   480,    95,
      96,   481,   482,     0,     0,     0,     0,     0,     0,    99,
     100,   101,     0,   103,   104,  1031,     0,     0,     0,  1032,
       0,     0,   109,   110,     0,     0,     0,     0,   111,   112,
     113,   114,   483,   116,   117,   484,     0,     0,     0,     0,
       0,     0,   485,   486,   124,     0,     0,     0,   125,     0,
     126,   487,     0,     0,     0,     0,     0,   131,     0,   132,
     133,   134,   135,   488,   137,   138,   139,   140,   141,   142,
       0,     0,  1033,   144,     0,     0,   375,   147,   148,   149,
     150,   151,   152,   153,   154,   489,   156,   490,   158,   491,
     492,   161,   162,   163,   164,   165,   166,   493,   168,   494,
     495,   496,   497,   173,   174,   498,   499,   177,   500,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,     0,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     6,     0,     0,     0,     0,     0,   371,   372,
       0,    10,    11,   458,    13,    14,    15,    16,   459,    18,
     460,   461,   462,  1030,   464,   373,    25,   465,    27,    28,
       0,    29,    30,    31,    32,   466,    34,   467,    36,    37,
      38,    39,   468,    41,    42,   469,     0,    44,   470,    46,
     471,   472,    49,   473,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,   474,   475,    66,
       0,    67,    68,    69,   476,     0,    72,    73,    74,     0,
       0,   477,    76,     0,     0,     0,     0,    78,    79,    80,
     478,   479,    83,    84,     0,     0,     0,     0,     0,     0,
       0,    89,    90,    91,    92,     0,    93,     0,     0,     0,
     480,    95,    96,   481,   482,     0,     0,     0,     0,     0,
       0,    99,   100,   101,     0,   103,   104,  1031,     0,     0,
       0,  1032,     0,     0,   109,   110,     0,     0,     0,     0,
     111,   112,   113,   114,   483,   116,   117,   484,     0,     0,
       0,     0,     0,     0,   485,   486,   124,     0,     0,     0,
     125,     0,   126,   487,     0,     0,     0,     0,     0,   131,
       0,   132,   133,   134,   135,   488,   137,   138,   139,   140,
     141,   142,     0,     0,  1033,   144,     0,     0,   375,   147,
     148,   149,   150,   151,   152,   153,   154,   489,   156,   490,
     158,   491,   492,   161,   162,   163,   164,   165,   166,   493,
     168,   494,   495,   496,   497,   173,   174,   498,   499,   177,
     500,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,   192,     0,   193,   194,   195,
     196,   197,   198,     0,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,     6,     0,     0,     0,     0,     0,
     371,   372,     0,    10,    11,   458,    13,    14,    15,    16,
     459,    18,   460,   461,   462,  1030,   464,   373,    25,   465,
      27,    28,     0,    29,    30,    31,    32,   466,    34,   467,
      36,    37,    38,    39,   468,    41,    42,   469,     0,    44,
     470,    46,   471,   472,    49,   473,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,   474,
     475,    66,     0,    67,    68,    69,   476,     0,    72,    73,
      74,     0,     0,   477,    76,     0,     0,     0,     0,    78,
      79,    80,   478,   479,    83,    84,     0,     0,     0,     0,
       0,     0,     0,    89,    90,    91,    92,     0,    93,     0,
       0,     0,   480,    95,    96,   481,   482,     0,     0,     0,
       0,     0,     0,    99,   100,   101,     0,   103,   104,  1031,
       0,     0,     0,  1032,     0,     0,   109,   110,     0,     0,
       0,     0,   111,   112,   113,   114,   483,   116,   117,   484,
       0,     0,     0,     0,     0,     0,   485,   486,   124,     0,
       0,     0,   125,     0,   126,   487,     0,     0,     0,     0,
       0,   131,     0,   132,   133,   134,   135,   488,   137,   138,
     139,   140,   141,   142,     0,     0,   143,   144,     0,     0,
     375,   147,   148,   149,   150,   151,   152,   153,   154,   489,
     156,   490,   158,   491,   492,   161,   162,   163,   164,   165,
     166,   493,   168,   494,   495,   496,   497,   173,   174,   498,
     499,   177,   500,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,   192,     0,   193,
     194,   195,   196,   197,   198,     0,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,     6,     0,     0,     0,
       0,     0,   371,   372,     0,    10,    11,   507,    13,    14,
      15,    16,   459,   508,   509,   461,   462,   463,   464,   373,
      25,   465,    27,    28,     0,    29,    30,    31,    32,   466,
      34,   510,    36,   511,   512,    39,   468,    41,    42,   469,
       0,    44,   513,    46,   471,   472,    49,   473,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,   474,   475,    66,     0,    67,    68,    69,   514,     0,
      72,    73,    74,     0,     0,   477,    76,     0,     0,     0,
       0,    78,    79,    80,   478,   479,    83,    84,     0,     0,
       0,     0,     0,     0,     0,    89,    90,    91,    92,     0,
      93,     0,     0,     0,   480,    95,    96,   481,   482,     0,
       0,     0,     0,     0,     0,    99,   100,   101,     0,   103,
     104,   105,     0,     0,     0,     0,     0,     0,   109,   110,
       0,     0,     0,     0,   111,   112,   113,   114,   483,   116,
     117,   484,     0,     0,     0,     0,     0,     0,   485,   486,
     124,     0,     0,     0,   125,     0,   126,   487,     0,     0,
       0,     0,     0,   131,     0,   132,   133,   134,   135,   488,
     137,   138,   139,   140,   141,   142,     0,     0,   143,   144,
       0,     0,   375,   147,   148,   149,   150,   151,   152,   153,
     154,   489,   515,   490,   158,   491,   492,   161,   162,   163,
     164,   165,   166,   493,   168,   494,   495,   496,   497,   173,
     174,   498,   499,   177,   500,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,     6,     0,
       0,     0,     0,     0,   371,   372,     0,    10,    11,     0,
      13,    14,    15,    16,   459,     0,     0,   461,   462,   463,
       0,   373,    25,   465,    27,    28,     0,    29,    30,    31,
      32,   466,    34,     0,    36,     0,     0,    39,   468,    41,
      42,   469,     0,    44,     0,    46,     0,     0,    49,   473,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,   474,   475,    66,     0,    67,    68,    69,
       0,     0,    72,    73,    74,     0,     0,   477,    76,     0,
       0,     0,     0,    78,    79,    80,   478,   479,    83,    84,
       0,     0,     0,     0,     0,     0,     0,    89,    90,    91,
      92,     0,    93,     0,     0,     0,   480,    95,    96,   481,
     482,     0,     0,     0,     0,     0,     0,    99,   100,   101,
       0,   103,   104,     0,     0,     0,     0,     0,     0,     0,
     109,   110,     0,     0,     0,     0,   111,   112,   113,   114,
     483,   116,   117,   484,     0,     0,     0,     0,     0,     0,
     485,   486,   124,     0,     0,     0,   125,     0,   126,   487,
       0,     0,     0,     0,     0,   131,     0,   132,   133,   134,
     135,   488,   137,   138,   139,   140,   141,   142,     0,     0,
       0,   144,     0,     0,   375,   147,   148,   149,   150,   151,
     152,   153,   154,   489,     0,   490,   158,   491,   492,   161,
     162,   163,   164,   165,   166,   493,   168,   494,   495,   496,
     497,   173,   174,     0,   499,   177,   500,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,     0,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        71,   570,   826,   827,   732,   749,   932,   610,   310,   381,
     827,   566,   567,   129,    85,   246,   247,   611,   612,   613,
     614,   902,   245,  1102,  1222,  1223,   814,   966,   397,  1206,
    1369,   803,    24,    71,  1016,  1297,   107,   861,   564,   565,
     566,   567,   803,     3,     4,     5,   564,   565,   119,    52,
     121,   814,   421,   590,     1,   592,   593,   114,   595,     1,
     597,    25,   861,   435,   436,     1,    91,    50,   605,   606,
      53,   440,   653,   897,     1,   803,   137,    93,    24,    91,
      91,     1,    90,    24,     1,     1,   103,    71,   142,    40,
     103,    48,    31,    32,  1264,    34,    35,  1179,   922,    96,
      91,    85,    93,    40,   103,   922,    43,   142,     8,    60,
     934,   125,   210,    96,   106,    54,   103,   934,   103,   114,
      29,   103,    93,   107,   139,   137,   142,   119,    93,   131,
     148,   164,   132,   155,   194,   119,    41,   121,   109,   867,
     103,   103,   132,   203,   103,   103,   106,    28,   148,    58,
     248,   142,   144,   171,   148,   170,   148,   132,   148,   151,
     103,   218,   195,   109,    45,   102,   938,   124,   103,   177,
     109,   184,   187,   148,   153,    33,   190,   171,  1376,   171,
     151,    39,    40,   180,    36,   184,   181,   915,     9,    10,
      42,   170,   194,   921,   181,    47,   181,   313,   103,    57,
     182,    59,    60,    55,   103,   230,   267,   210,  1032,   155,
      68,   228,  1138,   267,   155,    67,   155,  1098,   962,   230,
     182,   184,   181,   181,   779,   780,   163,  1306,  1016,  1017,
     181,  1170,   267,  1032,    24,   178,    94,   184,    93,  1011,
    1179,  1013,   184,   207,   301,   248,   181,   318,   184,    93,
     321,   267,  1013,  1016,  1017,   267,  1518,   184,  1240,   777,
     778,   253,   245,  1602,   184,   846,   847,   184,   184,   169,
    1440,  1353,   988,   810,   213,   258,   267,   260,    99,  1618,
     318,  1105,   181,   321,   263,   250,   251,  1626,   271,   272,
     273,   270,   275,   126,   277,   148,   668,   118,   103,   120,
     148,   280,   103,   151,  1481,    91,  1130,   148,   114,   164,
      91,   163,   103,  1130,   166,   386,   106,   388,   103,   103,
     164,    28,   393,  1521,    93,   151,   397,   148,   180,   119,
     561,   152,   403,  1157,   318,   153,   113,   321,    45,   410,
    1157,   564,   565,  1059,    91,   714,   718,   168,   717,   131,
     421,   184,   170,   205,   144,   203,   427,    91,   148,  1557,
     218,   151,   148,   145,   141,  1444,   437,   188,    49,   440,
     441,   442,   443,   444,   180,    56,   181,   154,   449,     5,
     181,   171,   151,     9,     9,   206,   457,   102,   151,   125,
     181,   246,   247,    74,   249,   142,   181,   181,    23,     9,
      10,   256,   246,   247,   388,   249,     9,   122,   142,   393,
     187,   266,    93,   397,  1353,   143,     9,    10,   143,   403,
      23,     5,   266,   278,  1305,     9,   410,   151,   214,   215,
     211,   212,   160,   114,   278,   160,    91,   421,     9,    10,
     995,   996,   997,   427,   218,   226,   517,  1526,  1272,   223,
     114,    93,  1240,   437,   190,  1272,   440,   441,   442,   443,
     444,  1249,   422,  1235,   424,   449,   426,   109,    42,   995,
     996,   997,  1260,   457,   434,   546,  1555,  1240,    91,   439,
     151,    92,   910,   554,   912,   445,  1249,   447,   448,    99,
     450,   102,   118,   118,   120,   120,   456,  1260,   870,   871,
      64,   112,   128,   875,   129,    69,    99,   858,   118,   151,
     120,   122,   151,   629,   630,   118,   587,   120,   218,   132,
     220,   872,   148,   148,   137,   118,   129,   120,    99,   957,
    1456,   959,   904,   517,   118,  1614,   120,  1616,   148,    49,
      40,   114,   152,    43,   128,   148,    56,   118,   117,   120,
     114,   782,   153,  1632,   777,   148,   211,   212,   168,   152,
    1535,  1536,   546,   523,   148,   241,   242,   153,   114,   170,
     554,   226,   151,   164,   534,   168,    76,   148,   188,   148,
     117,   152,   151,    93,   170,    93,   176,   658,   264,   660,
      43,   192,   663,   553,  1569,   188,   206,   168,   257,   189,
    1575,   109,   102,   587,   195,   263,   192,  1351,    61,   268,
      63,  1355,   270,   206,   685,   686,   687,   188,   161,    72,
     257,   218,   280,   220,  1412,   176,    96,    96,   293,   151,
      91,   268,   223,   176,   705,   206,   707,   302,   189,   109,
     109,   102,    64,   714,    49,   262,   717,    69,  1251,  1412,
     114,    56,   269,   271,   272,   273,  1211,   132,   632,   277,
     132,   635,   137,   163,   638,   137,   626,   320,   185,   186,
     148,   631,   325,   151,   385,   148,   387,   748,   151,   663,
    1504,   148,  1506,   148,   151,   117,   151,  1504,   117,  1506,
     281,   282,   283,   284,   285,   151,   287,   288,   289,   290,
     291,   685,   686,   687,   149,   296,   151,  1531,   214,   215,
     216,   225,   148,   227,  1531,   117,  1018,  1286,   225,   117,
     227,   705,   117,   707,   795,  1469,   117,  1551,  1472,   117,
     714,   294,   295,   717,  1551,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,   294,   295,   123,   124,   285,
     286,   711,   123,   124,   117,   826,   827,   828,   829,   127,
     117,  1133,   608,   609,   748,   615,   616,   135,   136,   117,
     138,   148,   617,   618,   209,   828,   829,   218,   146,   114,
     740,   741,   150,   148,   152,  1431,  1432,   235,   235,   157,
     861,   151,   428,  1521,   236,  1539,   148,   114,     0,   114,
    1403,  1404,  1396,   162,    89,   173,   877,    46,   193,   243,
     770,   795,    98,    97,   140,   149,   178,   178,   151,    24,
     178,    43,    43,    43,   147,   114,   240,   287,   196,   197,
     198,   199,   200,   201,   292,   292,   298,   181,   278,   910,
     278,   912,   826,   827,   828,   829,  1218,   114,   148,   181,
     148,   922,   148,   181,   151,    30,   151,   151,   151,   151,
      16,   207,    24,   934,     3,   181,   114,    68,   224,   224,
     144,   103,   163,    91,    91,   165,    91,   861,   165,   103,
      24,   122,   155,   155,   127,   293,   957,   240,   959,  1492,
    1493,   127,    91,   877,    40,   178,   178,    93,    93,   178,
     181,   181,   538,   539,   181,   541,   542,   543,   544,   178,
     103,   181,   178,   181,   137,   551,   552,   181,   181,   178,
     181,   181,   148,   178,   178,   178,   910,   178,   912,   230,
      91,   137,   568,   178,  1005,   181,    28,   165,   922,   103,
     218,   114,   578,   579,  1547,   178,   127,   137,   179,    91,
     934,   137,    24,   280,  1326,   220,   293,   148,    91,   114,
     248,  1032,   178,   155,   191,    93,   114,   127,   127,   114,
     137,   148,   142,   957,   114,   959,    96,    96,   178,   148,
     178,    30,    24,   114,   178,   148,    76,   239,   114,   103,
     103,   114,   952,   114,   252,   142,   139,   254,   151,   261,
     151,   637,   151,   279,   640,    24,    24,    24,  1380,   280,
     220,   230,   220,   220,   139,   181,   184,   114,   142,   114,
      74,  1005,   103,   181,   181,   281,   137,   181,   178,   181,
       7,   127,   137,   230,   102,   102,   142,   226,   226,   226,
     181,   226,   142,   180,   178,   181,   184,   276,  1032,   142,
    1121,   300,    75,    24,   181,  1015,   178,    24,    93,  1130,
     244,   244,   265,   181,   181,   121,   280,   165,   178,  1140,
     178,   251,  1143,    93,   148,    91,   180,   180,  1149,   178,
     142,    24,   103,   165,   178,    49,  1157,   178,    91,   190,
     114,    91,   274,   181,   181,    24,   103,  1057,   178,   114,
     114,   180,   281,   218,   190,  1176,   190,   180,   114,   218,
      90,   177,   190,   114,   148,   114,   287,   114,   181,   114,
     667,   299,   192,   299,   259,   299,  1197,   239,   300,   218,
      31,    32,  1063,    34,    35,  1206,    37,  1121,   245,  1210,
     242,   862,    43,  1526,  1105,   395,  1130,  1555,   923,  1109,
      51,   281,    53,    54,  1202,   920,  1140,  1228,  1229,  1143,
      61,   797,    63,  1228,  1140,  1149,   242,  1320,   300,  1122,
    1210,    72,  1227,  1157,  1001,    76,  1225,   415,   391,  1222,
    1149,   517,  1154,   589,   300,  1158,   433,  1147,   588,   640,
    1170,   749,  1176,  1575,  1569,   829,  1099,  1062,   912,   284,
     425,  1272,  1207,  1163,  1197,  1249,   107,   108,   109,  1260,
    1412,  1253,  1409,  1197,   425,  1017,  1026,   896,  1087,  1295,
    1434,  1250,  1206,   306,    -1,    -1,  1210,   863,    -1,    -1,
      -1,    -1,  1303,   869,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1228,  1229,  1317,  1318,    -1,    -1,
      -1,    -1,    -1,    -1,   155,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   164,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1342,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1352,    -1,    -1,    -1,  1356,    -1,    -1,  1272,    -1,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,   935,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   944,    -1,
     946,   947,   213,    -1,    -1,    -1,    -1,    -1,    -1,  1303,
      -1,    -1,   223,    -1,    -1,   961,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1317,  1318,    -1,   972,   973,   974,    -1,
     976,   977,   978,   979,   980,   981,    -1,   983,   984,    -1,
      -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,  1342,    -1,
      -1,    -1,    -1,    -1,    -1,  1001,    -1,    -1,  1352,    -1,
      -1,    -1,  1356,    -1,  1010,    -1,    -1,    -1,    -1,    -1,
     281,   282,   283,   284,   285,    -1,   287,   288,   289,   290,
     291,    -1,    -1,    -1,  1465,   296,   297,    -1,    -1,  1470,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1481,    -1,    -1,  1049,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1067,    -1,  1504,    -1,  1506,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1522,    -1,    -1,  1525,    -1,    -1,    -1,    -1,    -1,
    1531,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1542,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1115,
    1551,  1465,    -1,    -1,  1120,    -1,  1470,    -1,  1559,    -1,
      -1,    -1,  1563,    -1,    -1,    -1,  1132,  1481,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1144,  1145,
      -1,    -1,    -1,    -1,    -1,    -1,  1152,  1153,  1589,    -1,
    1504,    -1,  1506,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1606,    -1,  1608,  1522,    -1,
      -1,  1525,  1502,    -1,    -1,    -1,    -1,  1531,    -1,    -1,
    1621,    -1,    -1,    -1,  1625,    -1,    -1,    -1,  1542,  1630,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1551,    -1,    -1,
      -1,    -1,    -1,  1209,    -1,  1559,    -1,    -1,    -1,  1563,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,  1225,
      -1,    -1,    -1,    -1,    43,  1231,    -1,  1233,  1234,    -1,
      -1,    -1,    51,    -1,    53,  1589,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1606,    72,  1608,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1621,    -1,    -1,
      -1,  1625,    -1,    -1,    -1,    -1,  1630,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1316,    -1,    -1,    -1,    -1,    -1,  1322,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1332,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1340,  1341,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   164,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1359,  1360,  1361,  1362,  1363,    -1,  1365,
    1366,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
    1386,    -1,    -1,  1389,    -1,  1391,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1455,
      -1,    -1,    -1,    -1,  1460,    -1,    -1,    -1,  1464,    -1,
    1466,    -1,   281,   282,   283,   284,   285,    -1,   287,   288,
     289,   290,   291,    -1,    -1,    -1,    -1,   296,   297,    -1,
      -1,    -1,  1488,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1565,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1587,    -1,    -1,    -1,    -1,  1592,    -1,    -1,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,
      22,    -1,    24,    -1,    -1,  1611,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    51,
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
      -1,    -1,   174,   175,   176,    -1,    -1,    -1,   180,    -1,
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
     302,   303,   304,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    -1,    24,    -1,    -1,    -1,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    51,    52,    53,    54,    55,    56,    57,
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
      45,    46,    47,    48,    49,    -1,    51,    52,    53,    54,
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
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    51,
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
      49,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
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
      -1,   180,   181,   182,   183,    -1,   185,   186,   187,    -1,
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
      46,    47,    48,    49,    -1,    51,    52,    53,    54,    55,
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
      43,    44,    45,    46,    47,    48,    49,    -1,    51,    52,
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
      -1,   174,   175,   176,    -1,    -1,    -1,   180,   181,   182,
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
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
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
      47,    48,    49,    -1,    51,    52,    53,    54,    55,    56,
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
      44,    45,    46,    47,    48,    49,    -1,    51,    52,    53,
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
     174,   175,   176,    -1,   178,    -1,   180,    -1,   182,   183,
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
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
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
     171,    -1,    -1,   174,   175,   176,    -1,   178,    -1,   180,
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
      48,    49,    -1,    51,    52,    53,    54,    55,    56,    57,
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
      45,    46,    47,    48,    49,    -1,    51,    52,    53,    54,
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
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    51,
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
      -1,    -1,   174,   175,   176,    -1,    -1,    -1,   180,    -1,
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
      49,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
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
      46,    47,    48,    49,    -1,    51,    52,    53,    54,    55,
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
      43,    44,    45,    46,    47,    48,    49,    -1,    51,    52,
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
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
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
      47,    48,    49,    -1,    51,    52,    53,    54,    55,    56,
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
      44,    45,    46,    47,    48,    49,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    -1,    91,    92,    93,
      94,    95,    96,    97,    98,    -1,    -1,   101,   102,    -1,
      -1,    -1,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,    -1,    -1,   119,    -1,   121,   122,   123,
     124,    -1,   126,    -1,    -1,    -1,   130,   131,   132,   133,
     134,    -1,    -1,    -1,    -1,    -1,    -1,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,    -1,   151,   152,    -1,
     154,   155,    -1,    -1,    -1,    -1,   160,   161,   162,   163,
     164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,    -1,
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
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    -1,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    -1,
      91,    92,    93,    94,    95,    96,    97,    98,    -1,    -1,
     101,   102,    -1,    -1,    -1,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,    -1,    -1,   119,    -1,
     121,   122,   123,   124,    -1,   126,    -1,    -1,    -1,   130,
     131,   132,   133,   134,    -1,    -1,    -1,    -1,    -1,    -1,
     141,   142,   143,   144,   145,   146,   147,    -1,    -1,    -1,
     151,   152,    -1,   154,   155,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,    -1,   174,   175,   176,    -1,    -1,    -1,   180,
      -1,   182,   183,    -1,    -1,    -1,   187,    -1,   189,    -1,
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
      18,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    51,    52,    53,    54,    55,    56,    57,
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
      -1,    -1,   180,    -1,   182,   183,    -1,    -1,    -1,   187,
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
     298,   299,   300,   301,   302,   303,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    51,    52,    53,    54,
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
     175,   176,    -1,    -1,    -1,   180,    -1,   182,   183,    -1,
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,    24,    -1,
      -1,    -1,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    51,    52,    53,    54,    55,
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
     176,    -1,    -1,    -1,   180,   181,   182,   183,    -1,    -1,
      -1,    -1,    -1,   189,    -1,   191,   192,   193,   194,   195,
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
      -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    51,    52,    53,    54,    55,    56,
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
     297,   298,   299,   300,   301,   302,   303,    17,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
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
      -1,    -1,    -1,    -1,   174,   175,   176,    -1,    -1,    -1,
     180,    -1,   182,   183,    -1,    -1,    -1,    -1,    -1,   189,
      -1,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,    -1,    -1,   204,   205,    -1,    -1,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,   253,   254,   255,    -1,   257,   258,   259,
     260,   261,   262,    -1,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,    22,    -1,    -1,    -1,    -1,    -1,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    91,    92,    93,    94,    -1,    96,    97,
      98,    -1,    -1,   101,   102,    -1,    -1,    -1,    -1,   107,
     108,   109,   110,   111,   112,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,   122,   123,   124,    -1,   126,    -1,
      -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,    -1,    -1,   141,   142,   143,    -1,   145,   146,   147,
      -1,    -1,    -1,   151,    -1,    -1,   154,   155,    -1,    -1,
      -1,    -1,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,    -1,   174,   175,   176,    -1,
      -1,    -1,   180,   181,   182,   183,    -1,    -1,    -1,   187,
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
     298,   299,   300,   301,   302,   303,    22,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    51,    52,    53,    54,    55,
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
     176,    -1,    -1,    -1,   180,   181,   182,   183,    -1,    -1,
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
     296,   297,   298,   299,   300,   301,   302,   303,    22,    -1,
      -1,    -1,    -1,    -1,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    51,    52,    53,
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
     174,   175,   176,    -1,    -1,    -1,   180,   181,   182,   183,
      -1,    -1,    -1,   187,    -1,   189,    -1,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,    -1,    -1,
     204,   205,    -1,    -1,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,    -1,   253,
     254,   255,    -1,   257,   258,   259,   260,   261,   262,    -1,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
      22,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    -1,    91,
      92,    93,    94,    -1,    96,    97,    98,    -1,    -1,   101,
     102,    -1,    -1,    -1,    -1,   107,   108,   109,   110,   111,
     112,   113,   114,    -1,    -1,    -1,    -1,    -1,    -1,   121,
     122,   123,   124,    -1,   126,    -1,    -1,    -1,   130,   131,
     132,   133,   134,    -1,    -1,    -1,    -1,    -1,    -1,   141,
     142,   143,    -1,   145,   146,   147,    -1,    -1,    -1,   151,
      -1,    -1,   154,   155,    -1,    -1,    -1,    -1,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,
      -1,    -1,   174,   175,   176,    -1,    -1,    -1,   180,    -1,
     182,   183,    -1,    -1,    -1,    -1,    -1,   189,    -1,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
      -1,    -1,   204,   205,    -1,    -1,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
      -1,   253,   254,   255,    -1,   257,   258,   259,   260,   261,
     262,    -1,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,    22,    -1,    -1,    -1,    -1,    -1,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    -1,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      -1,    91,    92,    93,    94,    -1,    96,    97,    98,    -1,
      -1,   101,   102,    -1,    -1,    -1,    -1,   107,   108,   109,
     110,   111,   112,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,   122,   123,   124,    -1,   126,    -1,    -1,    -1,
     130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,    -1,
      -1,   141,   142,   143,    -1,   145,   146,   147,    -1,    -1,
      -1,   151,    -1,    -1,   154,   155,    -1,    -1,    -1,    -1,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,    -1,   174,   175,   176,    -1,    -1,    -1,
     180,    -1,   182,   183,    -1,    -1,    -1,    -1,    -1,   189,
      -1,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,    -1,    -1,   204,   205,    -1,    -1,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,   253,   254,   255,    -1,   257,   258,   259,
     260,   261,   262,    -1,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,    22,    -1,    -1,    -1,    -1,    -1,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    91,    92,    93,    94,    -1,    96,    97,
      98,    -1,    -1,   101,   102,    -1,    -1,    -1,    -1,   107,
     108,   109,   110,   111,   112,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,   122,   123,   124,    -1,   126,    -1,
      -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,    -1,    -1,   141,   142,   143,    -1,   145,   146,   147,
      -1,    -1,    -1,   151,    -1,    -1,   154,   155,    -1,    -1,
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
     298,   299,   300,   301,   302,   303,    22,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    51,    52,    53,    54,    55,
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
      -1,    -1,    -1,   189,    -1,   191,   192,   193,   194,   195,
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
     296,   297,   298,   299,   300,   301,   302,   303,    22,    -1,
      -1,    -1,    -1,    -1,    28,    29,    -1,    31,    32,    -1,
      34,    35,    36,    37,    38,    -1,    -1,    41,    42,    43,
      -1,    45,    46,    47,    48,    49,    -1,    51,    52,    53,
      54,    55,    56,    -1,    58,    -1,    -1,    61,    62,    63,
      64,    65,    -1,    67,    -1,    69,    -1,    -1,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    -1,    91,    92,    93,
      -1,    -1,    96,    97,    98,    -1,    -1,   101,   102,    -1,
      -1,    -1,    -1,   107,   108,   109,   110,   111,   112,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,
     124,    -1,   126,    -1,    -1,    -1,   130,   131,   132,   133,
     134,    -1,    -1,    -1,    -1,    -1,    -1,   141,   142,   143,
      -1,   145,   146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     154,   155,    -1,    -1,    -1,    -1,   160,   161,   162,   163,
     164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,    -1,
     174,   175,   176,    -1,    -1,    -1,   180,    -1,   182,   183,
      -1,    -1,    -1,    -1,    -1,   189,    -1,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,    -1,    -1,
      -1,   205,    -1,    -1,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,    -1,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,    -1,   253,
     254,   255,    -1,   257,   258,   259,   260,   261,   262,    -1,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,    11,    18,    19,    20,    21,    22,    24,    28,    29,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    51,
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
     389,   390,   395,   397,   399,   400,   401,   406,   427,   430,
     434,   437,   438,   439,   440,   442,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   488,   489,   490,   504,   505,
     507,   508,   509,   510,   511,   512,   513,   521,   522,   523,
     524,   525,   526,   527,   528,   529,   530,   533,   534,   535,
     536,   541,   542,   543,   544,   545,   546,   549,   553,   609,
     610,    28,    29,    45,   178,   208,   386,   178,   386,   178,
     386,    31,    32,    34,    35,    37,    43,    51,    53,    54,
      61,    63,    72,    76,   107,   108,   109,   155,   164,   195,
     213,   223,   255,   281,   282,   283,   284,   285,   287,   288,
     289,   290,   291,   296,   297,   356,   357,   377,   378,   379,
     380,   155,   148,   151,   148,   151,   148,   151,   148,    64,
      69,   392,   151,   366,   151,    29,    58,   114,    42,   148,
     151,   151,   151,   114,   114,   148,   151,   151,   151,    91,
     148,   214,   215,   117,   117,   117,   148,   151,    33,    38,
      40,    41,    42,    43,    44,    47,    55,    57,    62,    65,
      68,    70,    71,    73,    87,    88,    94,   101,   110,   111,
     130,   133,   134,   164,   167,   174,   175,   183,   195,   217,
     219,   221,   222,   229,   231,   232,   233,   234,   237,   238,
     240,   472,   609,   610,   117,   117,   117,    33,    39,    40,
      57,    59,    60,    68,    94,   218,   609,   114,   117,   117,
     181,   386,   609,   148,   117,    15,   608,   609,    17,   609,
     117,   117,   117,   464,   148,    25,   207,   209,   218,   220,
     151,   218,   220,   218,   218,   223,   114,   148,   368,   235,
     235,   236,   151,   148,   114,   321,     0,   323,   324,    28,
      45,   326,   327,     1,   184,   320,   184,   320,   103,   184,
     387,    36,    42,    47,    55,    67,   163,   166,   180,   205,
     391,   396,   397,   398,   415,   416,   420,   114,   162,    89,
     127,   135,   136,   138,   146,   150,   152,   157,   173,   196,
     197,   198,   199,   200,   201,   456,   457,   243,   153,   170,
     192,   113,   141,   154,   187,   194,   203,   131,   145,    46,
     193,    97,    98,   153,   170,   455,   148,   461,   464,   185,
     186,   149,   476,   477,   472,   476,   472,   151,   476,   140,
     151,   178,   178,   178,    24,   607,   176,   189,   176,   189,
     161,   176,   377,   610,   377,   609,   164,   195,    43,   378,
      43,   609,   147,   114,   354,    40,    43,    76,   102,   163,
     608,   214,   215,   216,   294,   295,   240,   580,   609,   287,
     609,   292,   292,   294,   295,   298,   281,   289,   357,   608,
     386,   181,   386,    40,    60,   181,   529,   530,   386,   181,
     187,   609,   389,   278,   278,   114,   410,   114,   181,   381,
     382,   148,   383,   386,   155,   607,   109,   155,   348,   607,
     407,   409,   609,   386,    24,   181,   608,   609,   609,   609,
     428,   429,   609,   386,   181,   386,   386,   531,   609,   386,
     148,   148,   386,   181,   187,   609,   428,   181,    30,   492,
     493,   494,   386,     8,   169,    16,   386,   207,    24,   389,
     389,   181,   389,   389,   389,   389,   224,   547,   548,   609,
     369,   389,   389,   386,   408,   414,   609,   184,   320,   184,
     320,     3,   327,   328,   385,   327,   328,   385,    28,   329,
     385,   329,   385,   389,   388,   114,   163,   165,   165,   389,
     389,   402,   403,   609,   439,   440,   442,   442,   442,   442,
     441,   442,   442,   442,    68,   446,   446,   445,   447,   447,
     447,   447,   448,   448,   449,   449,   224,    91,    91,    91,
     178,   386,   464,   464,   386,   477,   181,   389,   487,   144,
     181,   487,   103,   103,   366,    24,   610,   610,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,   331,   332,
     333,    91,   132,   137,   351,   352,   353,   609,   132,   137,
     155,   155,   331,   607,   122,   127,    50,    53,    96,   245,
     258,   260,   271,   272,   273,   275,   277,   581,   582,   583,
     584,   585,   586,   593,   599,   600,   240,    91,   230,   360,
     293,   609,   609,   609,   127,   178,   178,   181,   181,   178,
     103,   181,   103,   181,   178,   609,    52,   210,   248,   393,
     394,   609,    91,   103,   181,   386,   181,   608,    93,    40,
     608,   607,    93,   103,    91,   137,   267,   405,   515,   178,
     181,   181,   181,   181,   137,   103,   182,   142,   515,   178,
     181,   181,   148,   178,   386,   386,   178,   103,   181,   103,
     181,   182,   609,   493,   494,   125,   190,   178,   178,   126,
     184,    91,   211,   212,   226,    91,   211,   212,   226,    91,
     230,   218,   103,   228,   137,    28,   370,   386,   181,   178,
      41,   103,   327,    28,    28,   184,   320,   184,   109,   184,
     609,   165,   389,   421,   422,   114,   417,   418,   103,    93,
     142,   404,   405,   515,   442,   148,   151,   253,   460,   479,
     554,   557,   558,   559,   560,   561,   565,   567,   569,   570,
      43,   147,   151,   204,   516,   518,   520,   521,   537,   538,
     539,   540,   609,   516,   514,   520,   514,   178,   179,   103,
     181,   181,   143,   160,   143,   160,   132,   148,   384,   366,
     366,   332,   127,   518,   353,   389,   515,   137,   389,   607,
     607,   123,   124,   607,   271,   272,   273,   277,   609,   257,
     268,   257,   268,    24,   280,    93,   109,   151,   587,   590,
     581,    33,    39,    57,    59,    68,    94,   218,   359,   521,
     285,   286,   220,   293,   302,    91,   360,   293,   607,   148,
     531,   532,   609,   531,   532,   142,   515,   248,    49,    56,
      74,   114,   404,   411,   412,   413,   394,   515,   516,   382,
      91,   178,   191,   127,   347,   607,   155,   127,    93,   347,
     114,   516,   389,   114,   137,   137,   405,   148,   389,   114,
     389,   389,   142,    96,   431,   432,   433,    96,   435,   436,
     386,   178,   178,   148,   531,   531,   389,    30,   494,   125,
     190,     9,    10,    99,   118,   120,   188,   383,   489,   491,
     502,   503,   506,    24,   225,   227,   389,   389,   389,   225,
     227,   389,   389,   389,   389,   389,   389,   114,   389,   389,
     354,   371,   103,   184,   178,   368,   239,   550,   551,   148,
     114,   184,   109,   385,   385,   385,   421,    92,   102,   112,
     122,   423,   424,   425,   426,   103,   609,   103,   114,   114,
     389,   142,   405,   142,   142,   404,   405,   386,   554,   561,
     148,   279,   443,   606,    93,   164,   246,   247,   249,   256,
     266,   278,   555,   556,   575,   576,   577,   578,   601,   604,
     252,   254,   562,   580,   261,   566,   602,   241,   242,   264,
     571,   572,   151,   151,   518,   151,   139,   170,   187,   517,
     139,   389,   386,   132,   368,   132,   148,   533,   352,   389,
     280,    24,    93,   109,   151,   594,    24,   587,   360,   517,
     220,   220,   462,   281,   300,   359,   220,   184,   178,   386,
     181,   181,   139,   181,   181,   389,   142,   114,   114,   389,
     609,   413,    74,   516,   389,   607,   103,   347,   409,   609,
     389,   389,   137,   178,   386,   429,   389,   389,   109,   432,
      96,   180,   114,   516,   109,   436,   178,   178,   386,   181,
     181,   127,   188,   491,     7,   609,   188,   502,   184,   226,
     226,   226,   226,   230,   548,   180,   137,   371,   473,   552,
     551,   389,   414,   607,   123,   124,   425,   426,   426,   422,
     102,   419,   418,   403,   609,   389,   142,   389,   389,   142,
     405,   142,   178,   181,   554,   568,   244,   210,   248,   262,
     269,   605,    93,   250,   251,   603,   244,   558,   605,   445,
     575,   559,   142,   276,   563,   564,   603,   280,   574,    75,
     573,   181,   187,   516,   519,   181,   181,   181,   178,   388,
      24,   131,   194,   596,   597,   598,    24,   595,   596,   265,
     591,   588,   589,   590,   165,   609,   251,   360,   462,   178,
     389,   609,   609,   412,   389,   121,    93,   607,   389,   178,
     180,   389,   389,   609,   180,   114,   180,   178,   494,   609,
     188,   494,   609,   389,   389,   389,   389,   389,   389,   389,
     151,   203,   384,   178,   426,   607,   389,   389,   142,   389,
     178,   447,    48,   124,   445,   445,   263,   270,   280,   579,
     579,   560,   148,   274,    91,   181,   103,   181,   178,   594,
     594,   598,   103,   181,    24,   592,   603,   181,   103,   362,
     363,   462,   114,   218,   301,   281,   165,    49,   389,   347,
     389,    91,   389,   609,   389,    90,   177,   495,   494,   609,
     190,   494,   114,   473,   389,   445,   445,   192,   386,   516,
     516,    91,    24,   259,   590,   103,   426,   515,   609,   114,
     218,   609,   362,   114,   516,   180,     5,   128,   498,   499,
     501,   503,    23,   129,   496,   497,   500,   503,   190,   494,
     190,   609,   445,   178,   516,   363,   426,   299,   609,   114,
     218,   609,   180,   389,    90,   128,   501,   177,   129,   500,
     190,   103,   181,   389,   299,   609,   114,   389,   114,   384,
     287,   299,   609,   609,   300,   389,   300,   103,   181,   462,
     462,   114,   384,   192,   609,   281,   181,   609,   384,   218,
     114,   609,   300,   462
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
     550,   551,   551,   551,   551,   552,   552,   553,   553,   554,
     555,   555,   556,   556,   557,   557,   558,   558,   559,   559,
     560,   560,   561,   562,   562,   563,   563,   564,   565,   565,
     565,   566,   566,   567,   568,   568,   569,   570,   570,   571,
     571,   572,   572,   572,   573,   573,   574,   574,   575,   575,
     575,   575,   575,   576,   577,   578,   579,   579,   579,   580,
     580,   581,   581,   581,   581,   581,   581,   581,   581,   582,
     582,   582,   582,   583,   583,   584,   585,   585,   586,   586,
     586,   587,   587,   588,   588,   589,   589,   590,   591,   591,
     592,   592,   593,   593,   593,   594,   594,   595,   595,   596,
     596,   597,   597,   598,   598,   599,   600,   600,   601,   601,
     601,   602,   603,   603,   603,   603,   604,   604,   605,   605,
     606,   607,   608,   608,   609,   609,   609,   609,   609,   609,
     609,   609,   609,   609,   609,   609,   609,   609,   609,   609,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610
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
       1,     1,     1,     2,     1,     2,     3,     1,     4,     3,
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
       2,     2,     2,     2,     2,     2,     2,     1,     2,     2,
       1,     2,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     4,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     3,     1,     4,     4,
       3,     4,     1,     3,     1,     1,     1,     1,     1,     4,
       5,     8,     9,     9,    10,     1,     2,     1,     2,     6,
       0,     1,     3,     3,     0,     1,     1,     1,     2,     2,
       0,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       3,     3,     2,     1,     1,     1,     1,     1,     1,     4,
       2,     3,     6,     7,     2,     3,     6,     7,     4,     4,
       2,     3,     6,     7,     1,     2,     2,     1,     2,     3,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     4,     4,     3,     3,     3,     4,     4,     3,
       4,     6,     4,     6,     4,     3,     4,     6,     6,     4,
       6,     6,     4,     1,     2,     1,     1,     1,     3,     3,
       1,     1,     4,     5,     6,     3,     3,     3,     3,     5,
       7,     7,     5,     5,     5,     7,     7,     5,     5,     3,
       3,     5,     7,     5,     7,     1,     4,     3,     5,     1,
       2,     3,     7,    10,    13,     1,     3,     7,     4,     2,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
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
  "ForStart", "ForClause", "VarInDeclList", "VarInDecl", "PositionalVar",
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
       319,     0,    -1,   321,    -1,   304,   321,    -1,     1,     3,
      -1,   323,    -1,   322,   323,    -1,   324,    -1,   322,   324,
      -1,   208,   209,    24,   184,    -1,   208,   209,    24,   126,
      24,   184,    -1,   326,   184,   385,    -1,   327,   184,   385,
      -1,   326,   184,   327,   184,   385,    -1,   385,    -1,   326,
     320,   385,    -1,   327,   320,   385,    -1,   326,   184,   327,
     320,   385,    -1,   326,   320,   327,   184,   385,    -1,   325,
      -1,   325,   326,   184,    -1,   325,   327,   184,    -1,   325,
     326,   184,   327,   184,    -1,    29,   155,   608,   127,   607,
     184,    -1,   328,    -1,   326,   184,   328,    -1,   326,   320,
     328,    -1,   329,    -1,   327,   184,   329,    -1,   327,   320,
     329,    -1,   334,    -1,   335,    -1,   336,    -1,   338,    -1,
     355,    -1,   358,    -1,   350,    -1,   330,    -1,   340,    -1,
     376,    -1,   361,    -1,   364,    -1,   339,    -1,    28,   109,
      76,   331,    -1,    28,    76,   609,   331,    -1,   332,    -1,
     331,   332,    -1,   333,   127,   533,    -1,    77,    -1,    85,
      -1,    78,    -1,    79,    -1,    80,    -1,    81,    -1,    86,
      -1,    82,    -1,    83,    -1,    84,    -1,   337,    -1,   344,
      -1,   345,    -1,   365,    -1,   341,    -1,   342,    -1,   343,
      -1,   541,    -1,   346,    -1,   349,    -1,    28,   155,   608,
     127,   607,    -1,    28,    32,   176,    -1,    28,    32,   189,
      -1,    28,   109,    40,   155,   607,    -1,    28,   109,    43,
     155,   607,    -1,    28,    53,   609,    24,    -1,    28,   255,
     580,    -1,    28,    54,   164,    -1,    28,    54,   195,    -1,
      28,   109,   163,   122,   123,    -1,    28,   109,   163,   122,
     124,    -1,    28,    35,   176,   103,   143,    -1,    28,    35,
     176,   103,   160,    -1,    28,    35,   161,   103,   143,    -1,
      28,    35,   161,   103,   160,    -1,    28,   109,   102,   607,
      -1,    28,    31,   607,    -1,    45,    58,   607,    -1,    45,
      58,   348,   607,    -1,    45,    58,   607,    93,   347,    -1,
      45,    58,   348,   607,    93,   347,    -1,   607,    -1,   347,
     103,   607,    -1,   155,   608,   127,    -1,   109,    40,   155,
      -1,    45,    29,   607,    -1,    45,    29,   155,   608,   127,
     607,    -1,    45,    29,   607,    93,   347,    -1,    45,    29,
     155,   608,   127,   607,    93,   347,    -1,    28,   107,   147,
     351,    -1,    91,   518,   352,    -1,   352,    -1,   353,    -1,
     132,    -1,   132,   353,    -1,   137,   389,    -1,   114,   609,
      -1,   114,   609,   515,    -1,    28,   108,   354,   137,   389,
      -1,    28,   108,   354,   132,    -1,    28,   108,   354,   132,
     137,   389,    -1,   357,    -1,   356,   357,    -1,   282,    -1,
     283,    -1,   284,    -1,   285,    -1,   164,    -1,   195,    -1,
     223,   295,    -1,   223,   294,    -1,   296,   295,    -1,   296,
     294,    -1,   287,    -1,   288,   287,    -1,   291,   292,    -1,
     290,   292,    -1,    28,   281,   609,    -1,    28,   281,   609,
     360,    -1,    28,   281,   609,    91,   359,    -1,    28,   281,
     609,    91,   359,   360,    -1,    28,   356,   281,   609,    -1,
      28,   356,   281,   609,   360,    -1,    28,   356,   281,   609,
      91,   359,    -1,    28,   356,   281,   609,    91,   359,   360,
      -1,   521,    -1,   521,   517,    -1,   230,   286,   220,    -1,
     230,   285,   220,    -1,    28,   289,   609,   293,   220,   462,
     165,   362,    -1,    28,   356,   289,   609,   293,   220,   462,
     165,   362,    -1,   363,    -1,   362,   103,   363,    -1,   462,
      -1,   462,   515,    -1,   462,   426,    -1,   462,   515,   426,
      -1,    28,   297,   298,   609,   293,   281,   609,   114,   609,
     299,   389,    -1,    28,   297,   298,   609,   293,   281,   609,
     218,   114,   609,   299,   287,   300,   462,    -1,    28,   297,
     298,   609,   293,   281,   609,   301,   218,   114,   609,   299,
     389,    -1,    28,   297,   298,   609,   302,   300,   251,   281,
     609,   218,   114,   609,   300,   462,   192,   281,   609,   218,
     114,   609,   300,   462,    -1,    28,    34,   176,    -1,    28,
      34,   189,    -1,   151,   181,    -1,   151,   381,   181,    -1,
     151,   181,    91,   516,    -1,   151,   381,   181,    91,   516,
      -1,   231,   368,    -1,   148,   369,   386,   178,    -1,   369,
     370,   184,    -1,    -1,   370,   103,   371,    -1,    28,   371,
      -1,   354,    -1,   354,   137,   389,    -1,    62,   114,   609,
     137,   389,    -1,   234,   236,   389,    -1,   237,   151,   389,
     181,   368,    -1,   232,   235,    -1,   233,   235,    -1,    28,
     377,    -1,    28,    51,   377,    -1,    28,    37,   377,    -1,
     378,    -1,    63,   378,    -1,   380,    -1,   379,    -1,    43,
     610,   366,   384,    -1,    43,   610,   366,   132,    -1,    61,
      43,   610,   366,   368,    -1,    61,    43,   610,   366,   132,
      -1,    72,    43,   610,   366,   148,   388,   178,    -1,    72,
      43,   610,   366,   132,    -1,   382,    -1,   381,   103,   382,
      -1,   114,   609,    -1,   114,   609,   515,    -1,   148,   386,
     178,    -1,   148,   386,   178,    -1,   386,    -1,   388,    -1,
     388,   387,    -1,   184,    -1,   387,   388,   184,    -1,   389,
      -1,   388,   103,   389,    -1,   390,    -1,   427,    -1,   430,
      -1,   434,    -1,   437,    -1,   438,    -1,   542,    -1,   543,
      -1,   545,    -1,   544,    -1,   546,    -1,   549,    -1,   553,
      -1,   373,    -1,   374,    -1,   375,    -1,   372,    -1,   367,
      -1,   399,   391,    -1,   180,   389,    -1,    64,   278,    -1,
      69,   278,    -1,   210,    -1,   248,    -1,    52,   248,    -1,
     393,   411,    74,   389,    -1,   393,    74,   389,    -1,    42,
     392,   410,   394,   394,    -1,    42,   392,   410,   394,    -1,
      36,   114,   609,    -1,   401,    -1,   406,    -1,   395,    -1,
     397,    -1,   415,    -1,   420,    -1,   416,    -1,   396,    -1,
     397,    -1,   399,   398,    -1,    42,    -1,    55,    42,    -1,
     400,   114,   402,    -1,   403,    -1,   402,   103,   114,   403,
      -1,   609,   142,   389,    -1,   609,   515,   142,   389,    -1,
     609,   404,   142,   389,    -1,   609,   515,   404,   142,   389,
      -1,   609,   405,   142,   389,    -1,   609,   515,   405,   142,
     389,    -1,   609,   404,   405,   142,   389,    -1,   609,   515,
     404,   405,   142,   389,    -1,    93,   114,   609,    -1,   267,
     114,   609,    -1,    47,   114,   407,    -1,   409,    -1,   407,
     103,   114,   409,    -1,   414,    -1,   408,   103,   114,   414,
      -1,   609,   137,   389,    -1,   609,   515,   137,   389,    -1,
     609,   405,   137,   389,    -1,   609,   515,   405,   137,   389,
      -1,   114,   609,   142,   389,    -1,   114,   609,   515,   142,
     389,    -1,   412,    -1,   114,   609,    -1,   114,   609,   412,
      -1,   404,    -1,   404,   413,    -1,   413,    -1,    56,   114,
     609,    49,   114,   609,    -1,    49,   114,   609,    -1,    56,
     114,   609,    -1,   609,    -1,   205,   389,    -1,   166,   165,
     417,    -1,   418,    -1,   417,   103,   418,    -1,   114,   609,
      -1,   114,   609,   419,    -1,   102,   607,    -1,   163,   165,
     421,    -1,    67,   163,   165,   421,    -1,   422,    -1,   421,
     103,   422,    -1,   389,    -1,   389,   423,    -1,   424,    -1,
     425,    -1,   426,    -1,   424,   425,    -1,   424,   426,    -1,
     425,   426,    -1,   424,   425,   426,    -1,    92,    -1,   112,
      -1,   122,   123,    -1,   122,   124,    -1,   102,   607,    -1,
      65,   114,   428,   182,   389,    -1,   130,   114,   428,   182,
     389,    -1,   429,    -1,   428,   103,   114,   429,    -1,   609,
     142,   389,    -1,   609,   515,   142,   389,    -1,    70,   151,
     386,   181,   431,   109,   180,   389,    -1,   432,    -1,   431,
     432,    -1,   433,   180,   389,    -1,    96,   389,    -1,   433,
      96,   389,    -1,    71,   151,   386,   181,   435,   109,   180,
     389,    -1,    71,   151,   386,   181,   435,   109,   114,   609,
     180,   389,    -1,   436,    -1,   435,   436,    -1,    96,   516,
     180,   389,    -1,    96,   114,   609,    91,   516,   180,   389,
      -1,    44,   151,   386,   181,   191,   389,   121,   389,    -1,
     439,    -1,   438,   162,   439,    -1,   440,    -1,   439,    89,
     440,    -1,   442,    -1,   442,   456,   442,    -1,   442,   457,
     442,    -1,   442,   127,   442,    -1,   442,   157,   442,    -1,
      -1,   442,   152,   441,   442,    -1,   442,   150,   442,    -1,
     442,   138,   442,    -1,   442,   136,   442,    -1,   444,    -1,
     444,   243,    68,   554,   443,    -1,    -1,   606,    -1,   445,
      -1,   445,   192,   445,    -1,   446,    -1,   445,   170,   446,
      -1,   445,   153,   446,    -1,   447,    -1,   446,   187,   447,
      -1,   446,   113,   447,    -1,   446,   141,   447,    -1,   446,
     154,   447,    -1,   448,    -1,   447,   194,   448,    -1,   447,
     203,   448,    -1,   449,    -1,   448,   145,   449,    -1,   448,
     131,   449,    -1,   450,    -1,   450,    46,   224,   516,    -1,
     451,    -1,   451,   193,    91,   516,    -1,   452,    -1,   452,
      97,    91,   514,    -1,   453,    -1,   453,    98,    91,   514,
      -1,   455,    -1,   454,   455,    -1,   170,    -1,   153,    -1,
     454,   170,    -1,   454,   153,    -1,   458,    -1,   462,    -1,
     459,    -1,   196,    -1,   201,    -1,   200,    -1,   199,    -1,
     198,    -1,   197,    -1,   146,    -1,   173,    -1,   135,    -1,
      73,   148,   386,   178,    -1,    73,   215,   148,   386,   178,
      -1,    73,   214,   148,   386,   178,    -1,    73,    91,   531,
     148,   386,   178,    -1,   460,   148,   178,    -1,   460,   148,
     386,   178,    -1,   461,    -1,   460,   461,    -1,   171,   609,
      16,    -1,   171,    17,    -1,   463,    -1,   463,   464,    -1,
     186,   464,    -1,   464,    -1,   185,    -1,   465,    -1,   465,
     185,   464,    -1,   465,   186,   464,    -1,   466,    -1,   475,
      -1,   467,    -1,   467,   476,    -1,   470,    -1,   470,   476,
      -1,   468,   472,    -1,   469,    -1,   101,   117,    -1,   110,
     117,    -1,    94,   117,    -1,   183,   117,    -1,   111,   117,
      -1,   134,   117,    -1,   133,   117,    -1,   472,    -1,    95,
     472,    -1,   471,   472,    -1,   116,    -1,   167,   117,    -1,
      87,   117,    -1,   175,   117,    -1,   174,   117,    -1,    88,
     117,    -1,   521,    -1,   473,    -1,   609,    -1,   474,    -1,
     187,    -1,    11,    -1,    18,    -1,   478,    -1,   475,   476,
      -1,   475,   151,   181,    -1,   475,   151,   487,   181,    -1,
     477,    -1,   476,   477,    -1,   149,   386,   179,    -1,   479,
      -1,   481,    -1,   482,    -1,   483,    -1,   486,    -1,   488,
      -1,   484,    -1,   485,    -1,   534,    -1,   480,    -1,   533,
      -1,   106,    -1,   144,    -1,   119,    -1,   114,   609,    -1,
     151,   181,    -1,   151,   386,   181,    -1,   115,    -1,   164,
     148,   386,   178,    -1,   195,   148,   386,   178,    -1,   610,
     151,   181,    -1,   610,   151,   487,   181,    -1,   389,    -1,
     487,   103,   389,    -1,   489,    -1,   507,    -1,   490,    -1,
     504,    -1,   505,    -1,   152,   609,   494,   125,    -1,   152,
     609,   492,   494,   125,    -1,   152,   609,   494,   190,   188,
     609,   494,   190,    -1,   152,   609,   494,   190,   491,   188,
     609,   494,   190,    -1,   152,   609,   492,   494,   190,   188,
     609,   494,   190,    -1,   152,   609,   492,   494,   190,   491,
     188,   609,   494,   190,    -1,   502,    -1,   491,   502,    -1,
     493,    -1,   492,   493,    -1,    30,   609,   494,   127,   494,
     495,    -1,    -1,    30,    -1,   177,   496,   177,    -1,    90,
     498,    90,    -1,    -1,   497,    -1,   129,    -1,   500,    -1,
     497,   129,    -1,   497,   500,    -1,    -1,   499,    -1,   128,
      -1,   501,    -1,   499,   128,    -1,   499,   501,    -1,    23,
      -1,   503,    -1,     5,    -1,   503,    -1,   489,    -1,    10,
      -1,   506,    -1,   503,    -1,     9,    -1,   118,    -1,   120,
      -1,   383,    -1,   206,    25,   207,    -1,   206,   207,    -1,
     168,   608,   169,    -1,   168,   608,     8,    -1,    99,     7,
      -1,   508,    -1,   509,    -1,   510,    -1,   511,    -1,   512,
      -1,   513,    -1,    38,   148,   386,   178,    -1,    19,   178,
      -1,    19,   386,   178,    -1,    40,   148,   386,   178,   148,
     178,    -1,    40,   148,   386,   178,   148,   386,   178,    -1,
      20,   178,    -1,    20,   386,   178,    -1,    94,   148,   386,
     178,   148,   178,    -1,    94,   148,   386,   178,   148,   386,
     178,    -1,    68,   148,   386,   178,    -1,    33,   148,   386,
     178,    -1,    21,   178,    -1,    21,   386,   178,    -1,    57,
     148,   386,   178,   148,   178,    -1,    57,   148,   386,   178,
     148,   386,   178,    -1,   520,    -1,   520,   139,    -1,    91,
     516,    -1,   518,    -1,   518,   517,    -1,   204,   151,   181,
      -1,   139,    -1,   187,    -1,   170,    -1,   520,    -1,   521,
      -1,   147,   151,   181,    -1,   537,    -1,   540,    -1,   516,
      -1,   519,   103,   516,    -1,   609,    -1,   523,    -1,   529,
      -1,   527,    -1,   530,    -1,   528,    -1,   526,    -1,   525,
      -1,   524,    -1,   522,    -1,   218,   151,   181,    -1,    39,
     151,   181,    -1,    39,   151,   529,   181,    -1,    39,   151,
     530,   181,    -1,    68,   151,   181,    -1,    33,   151,   181,
      -1,    57,   151,   181,    -1,    57,   151,   608,   181,    -1,
      57,   151,    24,   181,    -1,    94,   151,   181,    -1,    94,
     151,   609,   181,    -1,    94,   151,   609,   103,   531,   181,
      -1,    94,   151,   187,   181,    -1,    94,   151,   187,   103,
     531,   181,    -1,    59,   151,   609,   181,    -1,    40,   151,
     181,    -1,    40,   151,   609,   181,    -1,    40,   151,   609,
     103,   531,   181,    -1,    40,   151,   609,   103,   532,   181,
      -1,    40,   151,   187,   181,    -1,    40,   151,   187,   103,
     531,   181,    -1,    40,   151,   187,   103,   532,   181,    -1,
      60,   151,   609,   181,    -1,   609,    -1,   609,   139,    -1,
      24,    -1,   535,    -1,   536,    -1,   609,   140,   144,    -1,
      43,   366,   383,    -1,   538,    -1,   539,    -1,    43,   151,
     187,   181,    -1,    43,   151,   181,    91,   516,    -1,    43,
     151,   519,   181,    91,   516,    -1,   151,   518,   181,    -1,
      28,   213,   214,    -1,    28,   213,   215,    -1,    28,   213,
     216,    -1,   219,   218,   389,   226,   389,    -1,   219,   218,
     389,    91,   225,   226,   389,    -1,   219,   218,   389,    91,
     227,   226,   389,    -1,   219,   218,   389,   211,   389,    -1,
     219,   218,   389,   212,   389,    -1,   219,   220,   389,   226,
     389,    -1,   219,   220,   389,    91,   225,   226,   389,    -1,
     219,   220,   389,    91,   227,   226,   389,    -1,   219,   220,
     389,   211,   389,    -1,   219,   220,   389,   212,   389,    -1,
     217,   218,   389,    -1,   217,   220,   389,    -1,   222,   218,
     389,   230,   389,    -1,   222,   223,   224,   218,   389,   230,
     389,    -1,   221,   218,   389,    91,   389,    -1,   229,   114,
     547,   228,   389,   180,   389,    -1,   548,    -1,   547,   103,
     114,   548,    -1,   609,   137,   389,    -1,   238,   148,   386,
     178,   550,    -1,   551,    -1,   550,   551,    -1,   239,   552,
     384,    -1,   239,   552,   151,   114,   609,   181,   384,    -1,
     239,   552,   151,   114,   609,   103,   114,   609,   181,   384,
      -1,   239,   552,   151,   114,   609,   103,   114,   609,   103,
     114,   609,   181,   384,    -1,   473,    -1,   552,   203,   473,
      -1,   240,   114,   408,    41,   148,   389,   178,    -1,    41,
     148,   389,   178,    -1,   557,   555,    -1,    -1,   556,    -1,
     575,    -1,   556,   575,    -1,   558,    -1,   557,   256,   558,
      -1,   559,    -1,   558,   252,   559,    -1,   560,    -1,   559,
     254,   142,   560,    -1,   561,    -1,   253,   561,    -1,   565,
     562,   563,    -1,    -1,   580,    -1,    -1,   564,    -1,   276,
     148,   386,   178,    -1,   569,   566,    -1,   151,   554,   181,
      -1,   567,    -1,    -1,   602,    -1,   460,   148,   568,   178,
      -1,    -1,   554,    -1,   570,   571,    -1,   479,    -1,   148,
     386,   178,    -1,    -1,   572,    -1,   242,   573,    -1,   241,
     574,    -1,   264,    -1,    -1,    75,    -1,    -1,   280,    -1,
     576,    -1,   577,    -1,   578,    -1,   604,    -1,   601,    -1,
     164,    -1,   278,   445,   579,    -1,   247,   603,   579,    -1,
     280,    -1,   270,    -1,   263,    -1,   240,   581,    -1,   580,
     240,   581,    -1,   582,    -1,   583,    -1,   584,    -1,   599,
      -1,   585,    -1,   593,    -1,   586,    -1,   600,    -1,    96,
     268,    -1,    96,   257,    -1,   260,    -1,   275,    -1,   245,
     268,    -1,   245,   257,    -1,    53,   609,    24,    -1,   271,
      -1,    50,   271,    -1,   273,   587,    -1,   273,   151,   587,
     588,   181,    -1,    50,   273,    -1,   590,    -1,   109,    -1,
      -1,   589,    -1,   590,    -1,   589,   103,   590,    -1,    93,
      24,   591,   592,    -1,    -1,   265,    24,    -1,    -1,   603,
     259,    -1,   272,   280,   594,   596,    -1,   272,   280,   109,
     596,    -1,    50,   272,   280,    -1,    93,    24,    -1,   151,
     595,   181,    -1,    24,    -1,   595,   103,    24,    -1,    -1,
     597,    -1,   598,    -1,   597,   598,    -1,   194,   594,    -1,
     131,   594,    -1,   258,    24,    -1,   277,    -1,    50,   277,
      -1,    93,   210,    -1,    93,   248,    -1,   249,   244,    -1,
     261,   603,   274,    -1,   250,   445,    -1,    93,   124,   445,
      -1,    93,    48,   445,    -1,   251,   445,   192,   445,    -1,
     266,   605,    -1,   246,   605,    -1,   269,    -1,   262,    -1,
     279,   244,   447,    -1,    24,    -1,    15,    -1,   609,    -1,
     610,    -1,    94,    -1,    33,    -1,    39,    -1,    40,    -1,
     147,    -1,    44,    -1,   218,    -1,    57,    -1,    59,    -1,
      60,    -1,    68,    -1,    71,    -1,    70,    -1,   204,    -1,
     237,    -1,    22,    -1,   208,    -1,   122,    -1,    32,    -1,
     255,    -1,    31,    -1,   215,    -1,   214,    -1,   141,    -1,
      38,    -1,   253,    -1,   254,    -1,   268,    -1,   257,    -1,
     245,    -1,   279,    -1,   271,    -1,   273,    -1,   272,    -1,
     277,    -1,   249,    -1,   244,    -1,    75,    -1,   210,    -1,
     248,    -1,    48,    -1,   216,    -1,   229,    -1,   296,    -1,
     223,    -1,   196,    -1,   201,    -1,   200,    -1,   199,    -1,
     198,    -1,   197,    -1,    93,    -1,   107,    -1,   108,    -1,
     180,    -1,    42,    -1,    55,    -1,    64,    -1,    69,    -1,
      56,    -1,    49,    -1,    52,    -1,    74,    -1,    36,    -1,
     142,    -1,    47,    -1,   205,    -1,   165,    -1,   166,    -1,
     163,    -1,    67,    -1,    92,    -1,   112,    -1,   123,    -1,
     124,    -1,   102,    -1,    65,    -1,   130,    -1,   182,    -1,
      96,    -1,    91,    -1,   191,    -1,   121,    -1,   162,    -1,
      89,    -1,    46,    -1,   224,    -1,    97,    -1,   192,    -1,
     113,    -1,   154,    -1,   194,    -1,   145,    -1,   131,    -1,
      73,    -1,    98,    -1,   193,    -1,   146,    -1,   176,    -1,
     189,    -1,   155,    -1,   132,    -1,   126,    -1,   161,    -1,
     143,    -1,   160,    -1,    28,    -1,    34,    -1,    54,    -1,
     109,    -1,    35,    -1,    53,    -1,   209,    -1,    45,    -1,
      58,    -1,    29,    -1,    43,    -1,   267,    -1,   243,    -1,
     276,    -1,   278,    -1,   247,    -1,   261,    -1,   274,    -1,
     266,    -1,   246,    -1,   260,    -1,   275,    -1,   265,    -1,
     259,    -1,   258,    -1,   242,    -1,   241,    -1,   264,    -1,
     250,    -1,   251,    -1,   280,    -1,   270,    -1,   269,    -1,
     262,    -1,   222,    -1,   228,    -1,   225,    -1,   219,    -1,
     212,    -1,   211,    -1,   213,    -1,   230,    -1,   220,    -1,
     221,    -1,   227,    -1,   217,    -1,   226,    -1,    63,    -1,
      61,    -1,    72,    -1,    37,    -1,    51,    -1,   164,    -1,
     195,    -1,   236,    -1,   231,    -1,   234,    -1,   235,    -1,
     232,    -1,   233,    -1,   238,    -1,   239,    -1,    41,    -1,
     240,    -1,    62,    -1,   289,    -1,   287,    -1,   288,    -1,
     293,    -1,   294,    -1,   295,    -1,   290,    -1,   291,    -1,
     292,    -1,    76,    -1,    77,    -1,    78,    -1,    79,    -1,
      80,    -1,    81,    -1,    82,    -1,    83,    -1,    84,    -1,
      85,    -1,    86,    -1,   281,    -1,   282,    -1,   283,    -1,
     284,    -1,   285,    -1,   286,    -1,   297,    -1,   298,    -1,
     299,    -1,   300,    -1,   301,    -1,   302,    -1,   303,    -1,
      87,    -1,   101,    -1,   110,    -1,   167,    -1,   174,    -1,
     183,    -1,   133,    -1,    88,    -1,   111,    -1,   134,    -1,
     175,    -1
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
     856,   858,   860,   862,   865,   867,   870,   874,   876,   881,
     885,   890,   895,   901,   906,   912,   918,   925,   929,   933,
     937,   939,   944,   946,   951,   955,   960,   965,   971,   976,
     982,   984,   987,   991,   993,   996,   998,  1005,  1009,  1013,
    1015,  1018,  1022,  1024,  1028,  1031,  1035,  1038,  1042,  1047,
    1049,  1053,  1055,  1058,  1060,  1062,  1064,  1067,  1070,  1073,
    1077,  1079,  1081,  1084,  1087,  1090,  1096,  1102,  1104,  1109,
    1113,  1118,  1127,  1129,  1132,  1136,  1139,  1143,  1152,  1163,
    1165,  1168,  1173,  1181,  1190,  1192,  1196,  1198,  1202,  1204,
    1208,  1212,  1216,  1220,  1221,  1226,  1230,  1234,  1238,  1240,
    1246,  1247,  1249,  1251,  1255,  1257,  1261,  1265,  1267,  1271,
    1275,  1279,  1283,  1285,  1289,  1293,  1295,  1299,  1303,  1305,
    1310,  1312,  1317,  1319,  1324,  1326,  1331,  1333,  1336,  1338,
    1340,  1343,  1346,  1348,  1350,  1352,  1354,  1356,  1358,  1360,
    1362,  1364,  1366,  1368,  1370,  1375,  1381,  1387,  1394,  1398,
    1403,  1405,  1408,  1412,  1415,  1417,  1420,  1423,  1425,  1427,
    1429,  1433,  1437,  1439,  1441,  1443,  1446,  1448,  1451,  1454,
    1456,  1459,  1462,  1465,  1468,  1471,  1474,  1477,  1479,  1482,
    1485,  1487,  1490,  1493,  1496,  1499,  1502,  1504,  1506,  1508,
    1510,  1512,  1514,  1516,  1518,  1521,  1525,  1530,  1532,  1535,
    1539,  1541,  1543,  1545,  1547,  1549,  1551,  1553,  1555,  1557,
    1559,  1561,  1563,  1565,  1567,  1570,  1573,  1577,  1579,  1584,
    1589,  1593,  1598,  1600,  1604,  1606,  1608,  1610,  1612,  1614,
    1619,  1625,  1634,  1644,  1654,  1665,  1667,  1670,  1672,  1675,
    1682,  1683,  1685,  1689,  1693,  1694,  1696,  1698,  1700,  1703,
    1706,  1707,  1709,  1711,  1713,  1716,  1719,  1721,  1723,  1725,
    1727,  1729,  1731,  1733,  1735,  1737,  1739,  1741,  1743,  1747,
    1750,  1754,  1758,  1761,  1763,  1765,  1767,  1769,  1771,  1773,
    1778,  1781,  1785,  1792,  1800,  1803,  1807,  1814,  1822,  1827,
    1832,  1835,  1839,  1846,  1854,  1856,  1859,  1862,  1864,  1867,
    1871,  1873,  1875,  1877,  1879,  1881,  1885,  1887,  1889,  1891,
    1895,  1897,  1899,  1901,  1903,  1905,  1907,  1909,  1911,  1913,
    1915,  1919,  1923,  1928,  1933,  1937,  1941,  1945,  1950,  1955,
    1959,  1964,  1971,  1976,  1983,  1988,  1992,  1997,  2004,  2011,
    2016,  2023,  2030,  2035,  2037,  2040,  2042,  2044,  2046,  2050,
    2054,  2056,  2058,  2063,  2069,  2076,  2080,  2084,  2088,  2092,
    2098,  2106,  2114,  2120,  2126,  2132,  2140,  2148,  2154,  2160,
    2164,  2168,  2174,  2182,  2188,  2196,  2198,  2203,  2207,  2213,
    2215,  2218,  2222,  2230,  2241,  2255,  2257,  2261,  2269,  2274,
    2277,  2278,  2280,  2282,  2285,  2287,  2291,  2293,  2297,  2299,
    2304,  2306,  2309,  2313,  2314,  2316,  2317,  2319,  2324,  2327,
    2331,  2333,  2334,  2336,  2341,  2342,  2344,  2347,  2349,  2353,
    2354,  2356,  2359,  2362,  2364,  2365,  2367,  2368,  2370,  2372,
    2374,  2376,  2378,  2380,  2382,  2386,  2390,  2392,  2394,  2396,
    2399,  2403,  2405,  2407,  2409,  2411,  2413,  2415,  2417,  2419,
    2422,  2425,  2427,  2429,  2432,  2435,  2439,  2441,  2444,  2447,
    2453,  2456,  2458,  2460,  2461,  2463,  2465,  2469,  2474,  2475,
    2478,  2479,  2482,  2487,  2492,  2496,  2499,  2503,  2505,  2509,
    2510,  2512,  2514,  2517,  2520,  2523,  2526,  2528,  2531,  2534,
    2537,  2540,  2544,  2547,  2551,  2555,  2560,  2563,  2566,  2568,
    2570,  2574,  2576,  2578,  2580,  2582,  2584,  2586,  2588,  2590,
    2592,  2594,  2596,  2598,  2600,  2602,  2604,  2606,  2608,  2610,
    2612,  2614,  2616,  2618,  2620,  2622,  2624,  2626,  2628,  2630,
    2632,  2634,  2636,  2638,  2640,  2642,  2644,  2646,  2648,  2650,
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
    2992,  2994,  2996,  2998,  3000,  3002,  3004,  3006,  3008,  3010
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,  1015,  1015,  1016,  1049,  1058,  1063,  1070,  1075,  1086,
    1091,  1099,  1104,  1109,  1114,  1119,  1127,  1135,  1143,  1155,
    1159,  1164,  1169,  1178,  1187,  1193,  1198,  1211,  1217,  1222,
    1234,  1235,  1236,  1237,  1242,  1243,  1244,  1245,  1246,  1247,
    1248,  1249,  1250,  1256,  1261,  1270,  1276,  1285,  1294,  1295,
    1296,  1297,  1298,  1299,  1300,  1301,  1302,  1303,  1308,  1309,
    1310,  1311,  1312,  1313,  1314,  1317,  1322,  1323,  1328,  1336,
    1342,  1352,  1358,  1368,  1378,  1386,  1392,  1403,  1408,  1418,
    1424,  1430,  1436,  1453,  1461,  1469,  1473,  1482,  1491,  1504,
    1510,  1521,  1525,  1533,  1538,  1543,  1550,  1563,  1570,  1576,
    1583,  1589,  1593,  1600,  1611,  1615,  1623,  1629,  1635,  1644,
    1650,  1659,  1663,  1669,  1673,  1677,  1681,  1687,  1693,  1699,
    1705,  1711,  1715,  1721,  1727,  1734,  1742,  1750,  1758,  1766,
    1778,  1792,  1806,  1823,  1827,  1836,  1840,  1847,  1855,  1873,
    1879,  1887,  1892,  1899,  1906,  1916,  1926,  1936,  1946,  1963,
    1969,  1980,  1984,  1988,  1992,  1999,  2006,  2025,  2035,  2041,
    2047,  2057,  2064,  2075,  2082,  2089,  2101,  2105,  2112,  2117,
    2132,  2149,  2153,  2157,  2161,  2169,  2180,  2195,  2206,  2221,
    2232,  2248,  2254,  2266,  2270,  2281,  2288,  2296,  2311,  2315,
    2329,  2333,  2342,  2346,  2360,  2361,  2362,  2363,  2364,  2365,
    2368,  2369,  2370,  2371,  2372,  2374,  2375,  2378,  2379,  2380,
    2381,  2382,  2387,  2402,  2409,  2413,  2420,  2424,  2428,  2435,
    2443,  2454,  2464,  2477,  2486,  2487,  2488,  2492,  2493,  2494,
    2495,  2496,  2499,  2505,  2514,  2518,  2526,  2534,  2540,  2552,
    2556,  2564,  2573,  2583,  2591,  2600,  2609,  2624,  2633,  2643,
    2651,  2657,  2666,  2672,  2684,  2692,  2702,  2710,  2722,  2728,
    2739,  2741,  2745,  2753,  2757,  2762,  2766,  2770,  2774,  2782,
    2796,  2804,  2811,  2817,  2828,  2832,  2841,  2849,  2855,  2865,
    2871,  2881,  2885,  2895,  2901,  2907,  2913,  2922,  2931,  2940,
    2953,  2957,  2965,  2971,  2981,  2989,  2998,  3011,  3018,  3030,
    3034,  3046,  3053,  3059,  3068,  3075,  3081,  3093,  3100,  3113,
    3119,  3131,  3137,  3149,  3158,  3162,  3171,  3175,  3183,  3187,
    3197,  3204,  3213,  3223,  3222,  3236,  3245,  3254,  3267,  3271,
    3284,  3287,  3294,  3298,  3307,  3311,  3315,  3324,  3328,  3334,
    3340,  3346,  3357,  3361,  3365,  3373,  3377,  3383,  3393,  3397,
    3407,  3411,  3421,  3425,  3435,  3439,  3449,  3453,  3461,  3465,
    3469,  3473,  3483,  3487,  3491,  3499,  3503,  3507,  3511,  3515,
    3519,  3527,  3531,  3535,  3543,  3547,  3551,  3555,  3566,  3572,
    3582,  3588,  3598,  3602,  3640,  3644,  3650,  3656,  3667,  3675,
    3686,  3692,  3702,  3706,  3714,  3720,  3728,  3734,  3746,  3752,
    3762,  3766,  3770,  3774,  3778,  3784,  3790,  3813,  3817,  3825,
    3829,  3840,  3844,  3848,  3854,  3858,  3872,  3876,  3884,  3888,
    3898,  3902,  3906,  3915,  3919,  3925,  3929,  3937,  3943,  3953,
    3961,  3965,  3969,  3973,  3977,  3981,  3985,  3989,  3993,  4001,
    4005,  4013,  4020,  4027,  4038,  4046,  4050,  4058,  4066,  4074,
    4128,  4132,  4145,  4151,  4161,  4165,  4173,  4177,  4181,  4189,
    4199,  4209,  4219,  4229,  4239,  4254,  4260,  4271,  4277,  4288,
    4299,  4301,  4305,  4310,  4320,  4323,  4330,  4338,  4344,  4354,
    4367,  4370,  4377,  4383,  4389,  4396,  4407,  4411,  4421,  4425,
    4435,  4439,  4443,  4448,  4457,  4463,  4469,  4475,  4485,  4489,
    4501,  4505,  4517,  4529,  4533,  4537,  4541,  4545,  4549,  4557,
    4565,  4569,  4573,  4577,  4594,  4598,  4602,  4606,  4614,  4622,
    4630,  4634,  4638,  4642,  4650,  4656,  4666,  4674,  4678,  4682,
    4717,  4723,  4729,  4739,  4743,  4747,  4751,  4755,  4762,  4768,
    4778,  4786,  4790,  4794,  4798,  4802,  4806,  4810,  4814,  4818,
    4826,  4834,  4838,  4842,  4852,  4860,  4868,  4872,  4876,  4884,
    4888,  4894,  4900,  4904,  4914,  4922,  4926,  4932,  4941,  4950,
    4956,  4962,  4972,  4989,  4996,  5011,  5047,  5051,  5060,  5069,
    5079,  5083,  5092,  5101,  5105,  5116,  5133,  5139,  5145,  5155,
    5159,  5165,  5171,  5175,  5181,  5185,  5191,  5197,  5204,  5214,
    5219,  5227,  5233,  5243,  5265,  5274,  5280,  5293,  5307,  5314,
    5320,  5330,  5335,  5341,  5351,  5364,  5370,  5387,  5391,  5406,
    5415,  5418,  5425,  5430,  5438,  5442,  5449,  5453,  5460,  5464,
    5471,  5475,  5484,  5497,  5500,  5508,  5511,  5519,  5527,  5535,
    5539,  5547,  5550,  5558,  5570,  5573,  5581,  5593,  5599,  5609,
    5612,  5620,  5624,  5628,  5636,  5639,  5647,  5650,  5658,  5662,
    5666,  5670,  5674,  5682,  5690,  5702,  5714,  5718,  5722,  5730,
    5736,  5746,  5750,  5754,  5758,  5762,  5766,  5770,  5774,  5782,
    5786,  5790,  5794,  5802,  5808,  5818,  5828,  5832,  5840,  5850,
    5861,  5868,  5872,  5880,  5883,  5890,  5895,  5904,  5914,  5917,
    5925,  5928,  5936,  5945,  5952,  5962,  5966,  5973,  5979,  5989,
    5992,  5999,  6004,  6016,  6024,  6036,  6044,  6048,  6056,  6060,
    6064,  6072,  6080,  6084,  6088,  6092,  6100,  6108,  6120,  6124,
    6132,  6145,  6149,  6150,  6163,  6164,  6165,  6166,  6167,  6168,
    6169,  6170,  6171,  6172,  6173,  6174,  6175,  6176,  6177,  6178,
    6182,  6183,  6184,  6185,  6186,  6187,  6188,  6189,  6190,  6191,
    6192,  6193,  6194,  6195,  6196,  6197,  6198,  6199,  6200,  6201,
    6202,  6203,  6204,  6205,  6206,  6207,  6208,  6209,  6210,  6211,
    6212,  6213,  6214,  6215,  6216,  6217,  6218,  6219,  6220,  6221,
    6222,  6223,  6224,  6225,  6226,  6227,  6228,  6229,  6230,  6231,
    6232,  6233,  6234,  6235,  6236,  6237,  6238,  6239,  6240,  6241,
    6242,  6243,  6244,  6245,  6246,  6247,  6248,  6249,  6250,  6251,
    6252,  6253,  6254,  6255,  6256,  6257,  6258,  6259,  6260,  6261,
    6262,  6263,  6264,  6265,  6266,  6267,  6268,  6269,  6270,  6271,
    6272,  6273,  6274,  6275,  6276,  6277,  6278,  6279,  6280,  6281,
    6282,  6283,  6284,  6285,  6286,  6287,  6288,  6289,  6290,  6291,
    6292,  6293,  6294,  6295,  6296,  6297,  6298,  6299,  6300,  6301,
    6302,  6303,  6304,  6305,  6306,  6307,  6308,  6309,  6310,  6311,
    6312,  6313,  6314,  6315,  6316,  6317,  6318,  6319,  6320,  6321,
    6322,  6323,  6324,  6325,  6326,  6327,  6328,  6329,  6330,  6331,
    6332,  6333,  6334,  6335,  6336,  6337,  6338,  6339,  6340,  6341,
    6342,  6343,  6344,  6345,  6346,  6347,  6348,  6349,  6350,  6351,
    6352,  6353,  6354,  6355,  6356,  6357,  6358,  6359,  6360,  6361,
    6362,  6363,  6364,  6365,  6366,  6367,  6368,  6369,  6370,  6371,
    6372,  6373,  6374,  6375,  6376,  6377,  6378,  6379,  6380,  6381
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
  const int xquery_parser::yylast_ = 11819;
  const int xquery_parser::yynnts_ = 293;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 556;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 318;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 572;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 15637 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6385 "/home/mbrantner/zorba/trunk/src/compiler/parser/xquery_parser.y"


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

