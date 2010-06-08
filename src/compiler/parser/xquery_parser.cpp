
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
#line 111 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"


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



/* Line 311 of lalr1.cc  */
#line 85 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 895 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 317 of lalr1.cc  */
#line 1011 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_driver.h"
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
#line 157 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"

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
#line 226 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
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
#line 891 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 333 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 116: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 342 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 141: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 889 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 351 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 360 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 369 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 378 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 387 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "Prolog" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 396 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 405 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 414 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 423 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 432 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 441 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 450 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 459 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 468 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 477 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 486 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 495 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 504 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 513 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 522 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 531 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 540 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 549 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 558 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 567 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 576 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 585 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 594 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 603 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 612 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 621 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 630 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 639 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 648 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 657 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "DeclPropertyList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 666 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "DeclProperty" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 675 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 684 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "NodeModifier" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 693 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 702 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 711 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 720 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 729 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 738 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 747 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 756 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "Block" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 765 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "BlockDecls" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 774 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "BlockVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 783 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "BlockVarDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 792 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "AssignExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 801 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "ExitExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 810 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "WhileExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 819 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 828 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 837 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 846 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "FunctionDeclSequential" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 864 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 882 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "EnclosedExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 900 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 909 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "ApplyExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 936 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "ConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 945 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 954 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 963 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 972 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 981 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 990 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 999 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1008 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1017 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1026 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1035 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1044 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1053 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1062 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1071 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1080 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "EvalVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1089 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1098 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1107 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1116 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1125 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1134 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "EvalVarDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1143 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1152 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1161 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1170 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1179 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1188 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1197 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1206 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1215 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1224 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1233 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1242 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1251 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1260 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1269 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1278 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1287 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1296 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1305 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1314 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1323 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1332 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1341 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1350 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1359 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1368 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1377 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1386 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1395 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1404 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1413 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1422 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1431 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1440 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1449 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1458 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1467 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1476 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1485 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1494 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1503 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1512 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1521 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1530 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1539 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1548 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1557 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1566 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1575 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1584 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1593 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1602 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1611 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1620 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1629 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1638 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1647 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1656 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1665 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1674 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1683 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1692 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1701 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1710 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1719 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1728 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1737 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1746 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1755 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1764 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1773 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1782 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1791 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1800 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1809 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1818 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1827 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1836 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1845 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1854 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1863 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1872 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1881 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1890 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1899 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1908 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1917 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1926 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1935 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1944 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1953 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1962 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1971 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1980 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1989 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1998 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2007 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2016 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2025 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2034 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2043 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2052 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2061 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2070 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2079 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2088 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2097 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2106 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2115 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2124 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2133 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2142 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2151 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2160 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2169 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2178 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2187 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2196 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2205 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2214 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2223 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2232 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2241 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2250 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2259 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2268 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2277 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2286 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2295 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2304 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "EvalExpr" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2313 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2322 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2331 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2340 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2349 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2358 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2367 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2376 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2385 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2394 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2403 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2412 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2421 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2430 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2439 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2448 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2457 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2466 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2475 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2484 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2493 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2502 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2511 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2520 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2529 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2538 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2547 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2556 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2565 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2574 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2583 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2592 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2601 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2610 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2619 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2628 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2637 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2646 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2655 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2664 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
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
#line 170 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename);
}

/* Line 553 of lalr1.cc  */
#line 2749 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"

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
#line 1071 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 1075 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.node) = NULL; }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 1076 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.node) = NULL; }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 1077 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.node) = NULL; }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 1078 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.node) = NULL; }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 1083 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
          // Catch unrecognized tokens and report them
          (yyval.node) = NULL;
          if ((yysemantic_stack_[(1) - (1)].err) != NULL) {
            error((yyloc), (yysemantic_stack_[(1) - (1)].err)->msg);
            delete (yysemantic_stack_[(1) - (1)].err);
          } else
            error((yyloc), std::string("syntax error, unexpected character"));
          YYERROR;
        }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 1099 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 1104 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            MainModule *mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
            mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 1111 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1116 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            LibraryModule *lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
            lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1127 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            std::string encoding = "utf-8";
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), encoding );
        }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 1132 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
        }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1140 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new MainModule(
                LOC((yyloc)),
                static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)),
                static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node))
            );
        }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1148 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
        }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1156 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LibraryModule(
                LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1162 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LibraryModule(
                LOC((yyloc)),
                static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
                static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1174 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
            dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
        }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1183 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Prolog( LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)), NULL );
        }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1187 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Prolog( LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)) );
        }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 1191 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Prolog(
                LOC((yyloc)),
                static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
                static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 1203 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
            sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = sdl;
        }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 1209 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            if ( SIND_DeclList *sdl = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                sdl->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 1219 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
            vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = vdl;
        }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 1225 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            if ( VFO_DeclList *vdl = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vdl->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1257 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
         (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
         delete (yysemantic_stack_[(4) - (4)].vstrpair);
       }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1262 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
         (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
         delete (yysemantic_stack_[(4) - (4)].vstrpair);
       }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1271 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
          (yyval.vstrpair) = new vector<string_pair_t>();
          (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
          delete (yysemantic_stack_[(1) - (1)].strpair);
        }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1277 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
          (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
          delete (yysemantic_stack_[(2) - (2)].strpair);
          (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
        }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1286 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
            (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval() );
            delete sl;
        }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1294 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1295 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1296 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1297 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1298 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1299 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1300 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1301 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 1302 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 1303 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1334 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
        }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1343 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::preserve_space
            );
        }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1349 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::strip_space
            );
        }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1359 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_element_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1365 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_function_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1375 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OptionDecl(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval))
            );
        }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1385 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1393 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::ordered
            );
        }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1399 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::unordered
            );
        }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1410 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_greatest);
        }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1415 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_least);
        }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1425 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1431 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1437 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 1443 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 1460 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
        }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 1468 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1476 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
        }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1480 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1489 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1498 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1511 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            URILiteralList *ull = new URILiteralList( LOC((yyloc)));
            ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.node) = ull;
        }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1517 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
                ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1528 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1532 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
        }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1540 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1545 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1550 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1557 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(8) - (4)].sval)),
                            SYMTAB((yysemantic_stack_[(8) - (6)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1570 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
        }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1577 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
            d->type = (yysemantic_stack_[(3) - (2)].node);
            (yyval.node) = d;
        }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1583 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1590 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
            d->ext = false;
            (yyval.node) = d;
        }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1596 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), NULL );
        }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1600 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1607 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1618 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1622 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1630 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(5) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(5) - (5)].expr));
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1636 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL, true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1642 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(6) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(6) - (6)].expr), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1651 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            DeclPropertyList *dpl = new DeclPropertyList( LOC((yyloc)) );
            dpl->addProperty(dynamic_cast<DeclProperty*>((yysemantic_stack_[(1) - (1)].node)));
            (yyval.node) = dpl;
        }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1657 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
        DeclPropertyList *dpl = dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(2) - (1)].node));
        dpl->addProperty( static_cast<DeclProperty*>((yysemantic_stack_[(2) - (2)].node)) );
        (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 1666 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_const );
        }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 1670 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_append_only
            );
        }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 1676 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_queue );
        }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1680 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_mutable );
        }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1684 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_ordered );
        }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1688 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_unordered
            );
        }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1694 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_equality
            );
        }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1700 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_range
            );
        }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1706 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_equality
            );
        }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1712 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_range
            );
        }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1718 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_unique );
        }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1722 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_non_unique
            );
        }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1728 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_automatic
            );
        }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1734 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_manual );
        }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1741 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL,
                              NULL);
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1749 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              NULL,
                              static_cast<NodeModifier*>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1757 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              NULL,
                              NULL,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1765 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                              NULL,
                              static_cast<NodeModifier*>((yysemantic_stack_[(6) - (6)].node)),
                              static_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)));
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1773 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1785 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1799 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1813 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1830 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1834 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1843 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1847 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1854 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                             (yysemantic_stack_[(8) - (6)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                             NULL);
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1862 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1880 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1886 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1894 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1899 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1906 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1913 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1924 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1934 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1944 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1955 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1970 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_preserve
            );
        }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1976 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_strip
            );
        }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1987 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL );
        }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1991 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1995 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)) );
        }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1999 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig(
                dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 2008 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
        }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 2015 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2034 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2043 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 2050 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
            vfo->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = vfo;
        }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 2056 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = new VFO_DeclList( LOC((yyloc)) );
            vfo->push_back((yysemantic_stack_[(2) - (2)].node));
            (yyval.node) = vfo;
        }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 2066 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(1) - (1)].varnametype)));
      VarDecl* vd = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL);
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 2073 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(3) - (1)].varnametype)));
      VarDecl* vd = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(3) - (3)].expr));
      vd->set_global(false);
      (yyval.node) = vd;
        }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 2084 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 2091 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExitExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 2098 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2110 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::BREAK );
        }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2114 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
        }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 2121 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            dynamic_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 2126 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2141 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2158 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 2162 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 2166 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 2170 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 2178 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2188 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2202 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2212 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2226 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2236 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2251 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            ParamList *pl = new ParamList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2257 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
                pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2269 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2273 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 2284 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EnclosedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 2291 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 2299 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QueryBody( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 2314 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 2318 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2332 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new BlockBody( LOC((yyloc)) );
        }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 2336 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            BlockBody *bb = dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (1)].expr));
            bb->add( (yysemantic_stack_[(3) - (2)].expr) );
            (yyval.expr) = bb;
        }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 2345 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 2349 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2390 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2405 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 2412 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_sliding;
        }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 2416 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_tumbling;
        }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 2423 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_start;
        }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 2427 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_end;
        }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 2431 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_only_end;
        }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 2438 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)),
                dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr),
                (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 2446 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr),
                (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 2457 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2467 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2480 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 2502 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 2508 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 2517 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = NULL;
        }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 2521 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_ofor;
        }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 2529 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForClause(
                LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL
            );
        }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 2539 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
            vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vdl;
        }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 2545 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 2557 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 2561 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                         NULL,NULL,
                         (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 2569 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2578 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2588 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 2596 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2605 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2614 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2629 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 2638 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2648 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 2656 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 2662 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2671 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2677 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            if ( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 2689 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 2697 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2707 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                           (yysemantic_stack_[(4) - (4)].expr));
     }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 2715 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                           (yysemantic_stack_[(5) - (5)].expr));
     }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 2727 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 2733 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 2746 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2750 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2758 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2762 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2771 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2775 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2779 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2787 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)),
                           NULL, NULL,
                           new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr))),
                           VarGetsDecl::eval_var);
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2801 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2809 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2816 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2822 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2833 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2837 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2846 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2854 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2860 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2870 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 2876 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2886 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2890 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2900 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2906 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2912 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2918 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2927 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2936 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2945 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2958 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2962 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2970 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 2976 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 2986 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 2994 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 3003 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 3016 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 3023 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 3035 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 3039 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 3051 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 3058 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 3064 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 3073 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3080 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3086 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3098 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3105 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3118 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3124 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3136 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3142 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3154 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3163 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3167 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3176 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3180 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3188 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3192 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 3202 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3209 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 3218 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 3227 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3232 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 3241 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 3250 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 3259 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 3272 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3276 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 3288 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3292 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3299 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3303 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3312 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3316 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3320 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3329 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3333 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3339 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3345 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3351 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3362 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3366 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3370 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3378 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3382 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3388 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3398 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3402 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3412 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3416 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3426 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3430 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3440 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3444 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3454 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3458 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3466 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3470 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3474 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3478 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3488 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3492 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3496 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3504 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3508 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3512 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3516 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3520 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3524 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3532 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3536 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3540 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3548 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3552 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3556 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3560 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3571 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3577 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3587 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3593 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3603 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3607 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3645 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL
            );
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3651 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3657 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3663 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            RelativePathExpr *rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = !rpe ?
                (yysemantic_stack_[(1) - (1)].expr) : new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3674 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NULL;
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3682 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 3693 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3699 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3709 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3713 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3721 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3727 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3735 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3741 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3753 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3759 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3769 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3773 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3777 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3781 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3785 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3791 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3797 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3805 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3809 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3817 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3821 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3832 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3836 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3840 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3846 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3850 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3864 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3868 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3876 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3880 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3890 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all);
    }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3894 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem);
    }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3898 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix);
    }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3907 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3911 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FilterExpr(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3917 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3921 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 3929 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 3935 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 3945 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 3953 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 3957 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 3961 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 3965 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 3969 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 3973 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 3977 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 3981 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 3985 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 3993 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 3997 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4005 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4012 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4019 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4030 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4038 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4042 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4050 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4058 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4066 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4120 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4124 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4136 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4142 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4152 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4156 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4164 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4168 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4172 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4180 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 4190 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 4200 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 4210 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 4220 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 4230 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 4245 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4251 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4262 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4268 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4279 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4296 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4301 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4310 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4314 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4321 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back(
                new QuoteAttrValueContent( LOC((yyloc)),std::string("\"") )
            );
            (yyval.node) = qacl;
        }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4329 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4335 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 4345 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4357 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4361 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4368 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4374 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4380 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4387 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4398 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4402 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4412 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4416 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4426 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4430 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4434 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4439 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4448 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4454 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4460 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4466 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4476 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4480 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4492 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4496 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4508 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4520 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4524 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4528 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4532 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4536 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4540 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4548 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4556 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL
            );
        }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4562 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr)
            );
        }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4568 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4572 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4589 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (2)].expr), NULL );
        }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4593 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4597 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4601 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4609 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4617 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4625 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), NULL );
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4629 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (2)].sval)), (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4633 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4637 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4645 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4651 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4661 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4669 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4673 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4679 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4714 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4720 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4726 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4736 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4740 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4744 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4748 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4752 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4759 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4765 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4775 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4783 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4787 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4791 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4795 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4799 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4803 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4807 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4811 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4815 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4823 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4831 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4835 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4839 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 4849 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 4857 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 4865 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 4869 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 4873 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 4881 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 4885 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 4891 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 4897 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 4901 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 4911 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)) );
        }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 4919 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 4923 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 4929 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 4938 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 4947 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 4953 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 4959 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 4969 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 4986 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 4993 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5008 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 5044 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 5048 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5057 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
        }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5066 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new InlineFunction(LOC ((yyloc)), &*(yysemantic_stack_[(3) - (2)].fnsig)->param, &*(yysemantic_stack_[(3) - (2)].fnsig)->ret, dynamic_cast<EnclosedExpr *>((yysemantic_stack_[(3) - (3)].expr)));
          delete (yysemantic_stack_[(3) - (2)].fnsig);
        }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5076 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5080 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5089 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
        }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5098 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5102 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5113 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5130 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5136 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5142 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5152 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5156 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5162 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5168 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5172 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5178 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5182 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5188 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5194 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5201 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5211 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5216 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5224 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5230 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5240 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5262 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5271 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5277 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5290 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5304 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5311 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5317 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5327 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5332 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5338 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 5348 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 5361 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5367 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5388 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 5407 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr(
        LOC((yyloc)), dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)), (yysemantic_stack_[(7) - (6)].expr)
        );
    }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5413 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr( LOC((yyloc)), new VarGetsDeclList( LOC((yyloc)) ), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5428 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5436 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5440 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5447 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5452 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5460 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5464 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5471 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5475 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5482 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5486 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5493 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5497 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5506 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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
#line 5518 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5522 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5529 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5533 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5541 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5549 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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
#line 5557 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5561 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5568 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5572 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5580 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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
#line 5591 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5595 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5603 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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
#line 5615 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5621 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5630 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5634 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5642 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5646 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5650 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5657 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5661 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5668 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5672 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5680 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5684 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5688 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5692 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5696 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5704 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5712 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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
#line 5724 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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
#line 5736 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5740 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5744 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5752 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5758 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5768 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5772 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5776 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5780 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5784 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5788 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5792 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5796 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5804 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5808 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5812 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5816 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5824 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5830 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5840 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5850 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5854 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5862 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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
#line 5872 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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
#line 5883 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5890 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5894 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5901 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5905 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(1) - (1)].thesaurus_id_list);
        }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5912 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5917 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5926 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5935 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5939 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5946 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 5950 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5958 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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
#line 5967 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 5974 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 5984 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 5988 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 5995 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 6001 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 6010 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 6014 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 6021 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 6026 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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
#line 6038 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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
#line 6046 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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
#line 6058 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 6066 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 6070 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 6078 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 6082 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 6086 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 6094 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 6102 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 6106 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 6110 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 6114 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 6122 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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
#line 6130 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
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
#line 6142 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 6146 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 6154 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 6167 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 6171 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 6177 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("xquery"); }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 6178 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("empty"); }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 6179 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("attribute"); }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 6180 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("comment"); }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 6181 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("document-node"); }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 6182 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("element"); }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 6183 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("item"); }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 6184 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("if"); }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 6185 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("node"); }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 6186 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("processing-instruction"); }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 6187 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema-attribute"); }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 6188 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema-element"); }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 6189 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("text"); }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 6190 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("typeswitch"); }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 6191 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("switch"); }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 6192 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("empty-sequence"); }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 6193 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("boundary-space"); }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 6194 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ft-option"); }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 6195 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("base-uri"); }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 6196 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lax"); }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 6197 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("strict"); }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 6198 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("idiv"); }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 6199 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("document"); }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 6200 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ftnot"); }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 6201 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("not"); }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 6202 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sensitive"); }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 6203 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("insensitive"); }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 6204 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("diacritics"); }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 6205 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("without"); }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 6206 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stemming"); }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 6207 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("thesaurus"); }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 6208 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stop"); }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 6209 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("wildcards"); }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 6210 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("entire"); }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 6211 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("content"); }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 6212 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("word"); }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 6213 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("start"); }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 6214 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("end"); }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 6215 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("most"); }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 6216 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("skip"); }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 6217 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("copy"); }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 6218 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("general"); }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 6219 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("value"); }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 6220 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("eq"); }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 6221 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ne"); }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 6222 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lt"); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 6223 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("le"); }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 6224 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("gt"); }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 6225 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ge"); }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 6226 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("at"); }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 6227 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("context"); }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 6228 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("variable"); }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 6229 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("return"); }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 6230 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("for"); }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 6231 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("outer"); }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 6232 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sliding"); }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 6233 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("tumbling"); }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 6234 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("previous"); }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 6235 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("next"); }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 6236 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("only"); }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 6237 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("when"); }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 6238 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("count"); }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 6239 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("in"); }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 6240 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("let"); }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 6241 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("where"); }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 6242 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("by"); }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 6243 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("group"); }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 6244 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("order"); }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 6245 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stable"); }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 6246 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ascending"); }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 6247 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("descending"); }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 6248 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("greatest"); }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 6249 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("least"); }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 6250 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("collation"); }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 6251 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("some"); }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 6252 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("every"); }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 6253 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("satisfies"); }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 6254 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("case"); }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 6255 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("as"); }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 6256 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("then"); }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 6257 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("else"); }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 6258 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("or"); }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 6259 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("and"); }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 6260 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("instance"); }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 6261 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("of"); }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 6262 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("castable"); }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 6263 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("to"); }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 6264 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("div"); }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 6265 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("mod"); }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 6266 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("union"); }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 6267 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("intersect"); }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 6268 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("except"); }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 6269 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("validate"); }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 6270 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("cast"); }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 6271 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("treat"); }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 6272 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("is"); }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 6273 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("preserve"); }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 6274 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("strip"); }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 6275 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("namespace"); }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 6276 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("external"); }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 6277 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("encoding"); }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 6278 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("no-preserve"); }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 6279 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("inherit"); }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 6280 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("no-inherit"); }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 6281 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("declare"); }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 6282 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("construction"); }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 6283 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ordering"); }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 6284 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("default"); }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 6285 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("copy-namespaces"); }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 6286 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("option"); }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 6287 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("version"); }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 6288 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("import"); }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 6289 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema"); }
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 6290 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("module"); }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 6291 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("function"); }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 6292 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("score"); }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 6293 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("contains"); }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 6294 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("weight"); }
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 6295 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("window"); }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 6296 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("distance"); }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 6297 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("occurs"); }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 6298 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("times"); }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 6299 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("same"); }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 6300 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("different"); }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 6301 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lowercase"); }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 6302 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("uppercase"); }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 6303 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("relationship"); }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 6304 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("levels"); }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 6305 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("language"); }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 6306 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("any"); }
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 6307 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("all"); }
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 6308 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("phrase"); }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 6309 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("exactly"); }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 6310 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("from"); }
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 6311 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("words"); }
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 6312 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sentences"); }
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 6313 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sentence"); }
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 6314 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("paragraph"); }
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 6315 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("replace"); }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 6316 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("modify"); }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 6317 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("first"); }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 6318 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("insert"); }
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 6319 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("before"); }
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 6320 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("after"); }
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 6321 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("revalidation"); }
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 6322 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("with"); }
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 6323 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("nodes"); }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 6324 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("rename"); }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 6325 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("last"); }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 6326 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("delete"); }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 6327 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("into"); }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 6328 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("simple"); }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 6329 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sequential"); }
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 6330 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("updating"); }
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 6331 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("deterministic"); }
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 6332 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("nondeterministic"); }
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 6333 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ordered"); }
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 6334 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("unordered"); }
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 6335 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("returning"); }
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 6336 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("block"); }
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 6337 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("exit"); }
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 6338 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("loop"); }
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6339 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("while"); }
    break;

  case 896:

/* Line 678 of lalr1.cc  */
#line 6340 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("break"); }
    break;

  case 897:

/* Line 678 of lalr1.cc  */
#line 6341 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("continue"); }
    break;

  case 898:

/* Line 678 of lalr1.cc  */
#line 6342 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("try"); }
    break;

  case 899:

/* Line 678 of lalr1.cc  */
#line 6343 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("catch"); }
    break;

  case 900:

/* Line 678 of lalr1.cc  */
#line 6344 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("eval"); }
    break;

  case 901:

/* Line 678 of lalr1.cc  */
#line 6345 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("using"); }
    break;

  case 902:

/* Line 678 of lalr1.cc  */
#line 6346 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("set"); }
    break;

  case 903:

/* Line 678 of lalr1.cc  */
#line 6347 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("index"); }
    break;

  case 904:

/* Line 678 of lalr1.cc  */
#line 6348 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("unique"); }
    break;

  case 905:

/* Line 678 of lalr1.cc  */
#line 6349 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("non"); }
    break;

  case 906:

/* Line 678 of lalr1.cc  */
#line 6350 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("on"); }
    break;

  case 907:

/* Line 678 of lalr1.cc  */
#line 6351 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("range"); }
    break;

  case 908:

/* Line 678 of lalr1.cc  */
#line 6352 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("equality"); }
    break;

  case 909:

/* Line 678 of lalr1.cc  */
#line 6353 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("manually"); }
    break;

  case 910:

/* Line 678 of lalr1.cc  */
#line 6354 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("automatically"); }
    break;

  case 911:

/* Line 678 of lalr1.cc  */
#line 6355 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("maintained"); }
    break;

  case 912:

/* Line 678 of lalr1.cc  */
#line 6356 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("decimal-format"); }
    break;

  case 913:

/* Line 678 of lalr1.cc  */
#line 6357 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("decimal-separator"); }
    break;

  case 914:

/* Line 678 of lalr1.cc  */
#line 6358 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("grouping-separator"); }
    break;

  case 915:

/* Line 678 of lalr1.cc  */
#line 6359 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("infinity"); }
    break;

  case 916:

/* Line 678 of lalr1.cc  */
#line 6360 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("minus-sign"); }
    break;

  case 917:

/* Line 678 of lalr1.cc  */
#line 6361 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("NaN"); }
    break;

  case 918:

/* Line 678 of lalr1.cc  */
#line 6362 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("percent"); }
    break;

  case 919:

/* Line 678 of lalr1.cc  */
#line 6363 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("per-mille"); }
    break;

  case 920:

/* Line 678 of lalr1.cc  */
#line 6364 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("zero-digit"); }
    break;

  case 921:

/* Line 678 of lalr1.cc  */
#line 6365 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("digit"); }
    break;

  case 922:

/* Line 678 of lalr1.cc  */
#line 6366 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("pattern-separator"); }
    break;

  case 923:

/* Line 678 of lalr1.cc  */
#line 6367 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("collection"); }
    break;

  case 924:

/* Line 678 of lalr1.cc  */
#line 6368 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("const"); }
    break;

  case 925:

/* Line 678 of lalr1.cc  */
#line 6369 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("append-only"); }
    break;

  case 926:

/* Line 678 of lalr1.cc  */
#line 6370 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("queue"); }
    break;

  case 927:

/* Line 678 of lalr1.cc  */
#line 6371 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("mutable"); }
    break;

  case 928:

/* Line 678 of lalr1.cc  */
#line 6372 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("read-only"); }
    break;

  case 929:

/* Line 678 of lalr1.cc  */
#line 6373 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("integrity"); }
    break;

  case 930:

/* Line 678 of lalr1.cc  */
#line 6374 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("constraint"); }
    break;

  case 931:

/* Line 678 of lalr1.cc  */
#line 6375 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("check"); }
    break;

  case 932:

/* Line 678 of lalr1.cc  */
#line 6376 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("key"); }
    break;

  case 933:

/* Line 678 of lalr1.cc  */
#line 6377 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("foreach"); }
    break;

  case 934:

/* Line 678 of lalr1.cc  */
#line 6378 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("foreign"); }
    break;

  case 935:

/* Line 678 of lalr1.cc  */
#line 6379 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("keys"); }
    break;

  case 936:

/* Line 678 of lalr1.cc  */
#line 6380 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ancestor"); }
    break;

  case 937:

/* Line 678 of lalr1.cc  */
#line 6381 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("child"); }
    break;

  case 938:

/* Line 678 of lalr1.cc  */
#line 6382 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("descendant"); }
    break;

  case 939:

/* Line 678 of lalr1.cc  */
#line 6383 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("parent"); }
    break;

  case 940:

/* Line 678 of lalr1.cc  */
#line 6384 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("preceding"); }
    break;

  case 941:

/* Line 678 of lalr1.cc  */
#line 6385 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("self"); }
    break;

  case 942:

/* Line 678 of lalr1.cc  */
#line 6386 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("following"); }
    break;

  case 943:

/* Line 678 of lalr1.cc  */
#line 6387 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ancestor-or-self"); }
    break;

  case 944:

/* Line 678 of lalr1.cc  */
#line 6388 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("descendant-or-self"); }
    break;

  case 945:

/* Line 678 of lalr1.cc  */
#line 6389 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("following-sibling"); }
    break;

  case 946:

/* Line 678 of lalr1.cc  */
#line 6390 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("preceding-sibling"); }
    break;



/* Line 678 of lalr1.cc  */
#line 11403 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"
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
      1571, -1330, -1330, -1330, -1330, -1330,   264,   -39, -1330, -1330,
     420, -1330, -1330, -1330, -1330,     2,   190,  9733,   247,    76,
     275,   287,   294, -1330,    24, -1330, -1330, -1330, -1330, -1330,
   -1330,   400, -1330,  7728, -1330, -1330,   318, -1330,   391, -1330,
   -1330,   431, -1330,   451, -1330,   440,   454, -1330,   195, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
   -1330, -1330,   491,   514, -1330, -1330, -1330, -1330,  9163,  7146,
   -1330, -1330, -1330,   526, -1330, -1330, -1330, -1330, -1330,   528,
     541, -1330, -1330, 11158, -1330, -1330, -1330, -1330, -1330, -1330,
   -1330, -1330,   504, -1330, -1330,   557,   563, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330,  2165, 11158, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330,   534, -1330, -1330,   567,  8306, -1330,  8593,
     569,   575, -1330, -1330, -1330, 11158,   578, -1330,  6853, -1330,
   -1330, -1330, -1330, -1330, -1330,   549, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330,    38,   492, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330,   163,   552,   365, -1330,   485,   369,
   -1330, -1330, -1330, -1330, -1330, -1330,   593, -1330,   560,   473,
     475,   476, -1330, -1330,   564,   571, -1330,   597, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,  1872,   714,
   -1330,   717,  5095, -1330, -1330,   463,  5388,   535,   540, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
     -13, -1330, -1330, -1330, -1330,   429, 11158, -1330, -1330, -1330,
   -1330, -1330, -1330,   565,   639, -1330,   829,   489,   261,   386,
     -51,   216, -1330,   689,   543,   642,   643,  5681, -1330, -1330,
   -1330,   145, -1330, -1330,  6853, -1330,    93, -1330,   591,  7146,
   -1330,   591,  7146, -1330, -1330, -1330,   481, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
     353, -1330,   719,   227,   336,   -20,   357, 11158,   357, 11158,
     150,   700,   701,   702, 11158,   610,   644,   226,  8306, -1330,
   -1330,   411,   239,   518, 11158, -1330, -1330, -1330, -1330, -1330,
     477, 11158,   478,   479,   315,   465,   537, -1330, -1330, -1330,
   -1330, -1330,  8306,  5388,   586,  5388,    27, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330,  5388, 10018, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,   620,
    5388,   494,   495, -1330,   657,   -16,   630,  5388,    52,    94,
   11158,   665, -1330,  5388,  8017,   633, -1330, 11158, 11158, 11158,
    5388,   601,  5388,  5388, 11158,  5388,   635,   636, -1330, -1330,
   -1330,  5388, 10303,   637,   638,   640,   641,   645,   646, -1330,
   -1330, -1330, -1330, -1330, -1330, 11158, -1330, -1330, -1330,   607,
     763,  5388, -1330,    64, -1330,   776, -1330, -1330,   614, -1330,
   -1330,  5388,   590, -1330,   777,  5388,  5388,   618,  5388,  5388,
    5388,  5388,   576, 11158, -1330, -1330, -1330, -1330,  5388,  5388,
    5388, 11158, -1330,   717, -1330, -1330, -1330, -1330,   264,   294,
   -1330, -1330,   463,   773,  5388, -1330,  5388,   690,    76,    24,
     400,   648,   647,   649,  5388,  5388, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330,   710, -1330,   -14,  5974,  5974,  5974, -1330,
    5974,  5974, -1330,  5974, -1330,  5974, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330,  5974,  5974,   735,  5974,  5974,  5974,  5974,
    5974,  5974,  5974,  5974,  5974,  5974,  5974,   589,   725,   726,
     728, -1330, -1330, -1330,  2458, -1330, -1330,  6853,  6853,  5388,
     591, -1330, -1330,   591, -1330,  2751,   591,   681,  3044, -1330,
   -1330, -1330, -1330, -1330, -1330,   729,   730, -1330,   275, -1330,
     808, -1330, -1330, 11158, -1330, 11158,   670,    15, 11158,   456,
     679,   683,   670,   719,   720,   709, -1330, -1330, -1330, -1330,
   -1330,   -12,   599,   -10, -1330,   544, -1330, -1330, -1330, -1330,
   11158, 11158, 11158, -1330,   718,   666, -1330,   672,   640,   318,
   -1330,   671,   673,   675, -1330,   -18,    11,  3337,   680, -1330,
   -1330, 11158,    -6, 11158,   760,    28, -1330,  5388, -1330,   676,
    8306,   766,   820,  8306,   719,   768,   759, -1330,   -28, -1330,
     685,   686, -1330,   687,  3630,   688,   727,    -8, -1330,    34,
     692, -1330,   691,   693,   723, -1330,   695,  5388,  5388,   697,
   -1330,    30,   156,  3923,    12, -1330, 11158,   763, -1330,    -4,
     708, -1330, -1330, -1330, -1330,   712, -1330,     3, -1330, -1330,
   -1330,   -35,   -15,   775,   662,   677,   -30, -1330,   758,  6267,
   -1330,   715,   721,    56, -1330, -1330, -1330,   713, -1330,   622,
   -1330, -1330,    -2, 11158,   736,  5388,   788, -1330, -1330,   790,
   10588,   796,  5388,   802,   -49,   780,    -5,   639, -1330, -1330,
   -1330, -1330, -1330,  5974, -1330, -1330, -1330,    13,   386,   386,
     339,   -51,   -51,   -51,   -51,   216,   216, -1330, -1330, 10588,
   10588, 11158, 11158, -1330,   739, -1330, -1330,   740, -1330, -1330,
   -1330,   185, -1330, -1330,   186,   364,   401,   259, -1330,   275,
     275, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
   -1330,   670, -1330,   791, 10873,   786,  5388, -1330, -1330, -1330,
     834,   792,  5388,   719,   719,   670, -1330,   501,   719,   340,
   11158,   308,   314,   905, -1330, -1330,   651,     9, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,   -12,
      32,   350, -1330,   716,    31,     8,   652,   719, -1330, -1330,
   -1330, -1330,   782, 11158, -1330, 11158, -1330, -1330,   753, -1330,
     196,   684, -1330, -1330,   503,    -6,   834, 10588,   821,   845,
     762,   749,   815,   719,   789,   816,   853,   719,   835,  5388,
     811,   -59,   803, -1330, -1330, -1330,   772, -1330,  5388,   840,
    5388,  5388,   813, -1330,   861,   862,  5388, -1330,   781,   783,
     812, 11158, -1330, 11158, -1330, -1330,   785,  5388,   936, -1330,
     169, -1330,    49, -1330, -1330,   945, -1330,   407,  5388,  5388,
    5388,   413,  5388,  5388,  5388,  5388,  5388,  5388,   855,  5388,
    5388,   644,     1,   794,   560,   732,   822,   860,   773,   900,
   -1330, -1330,  5388,   323,   874, -1330, 11158,   875, -1330, 11158,
     832,   833, 10873,   836, -1330,   236, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330, 11158, -1330, 11158,  5388,   838,  5388,  5388,
     -22,   847, -1330,  5388,    13,   371,   191, -1330,   711,    62,
     737,   734, -1330, -1330,   518, -1330,   731,  -108, -1330, -1330,
   -1330,   854, -1330, -1330, -1330,  5388, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330,  5388, -1330,   368,   428, -1330,   972,   466,
   -1330, -1330, -1330,  5388, -1330, -1330, -1330, -1330, -1330, -1330,
   -1330,   722, -1330, -1330,   973, -1330, -1330, -1330, -1330, -1330,
     304,   974, -1330,   471, -1330, -1330, -1330,   638,   190,   641,
     645,   646,   552,   771,   236,   778,   784,  6560,   724,   696,
      32, -1330,   787,   823,  4216,   830,   831,   871,   837,   839,
   -1330,  5388,   872, -1330,   901,   902,  5388, 11158,   412,   943,
   -1330, -1330, -1330, -1330, -1330, -1330, 10588, -1330,  5388,   719,
     918, -1330, -1330, -1330,   719,   918, 11158, -1330,  5388,  5388,
     885,  4509, -1330, -1330, 11158, -1330, -1330,  5388,  5388,   354,
   -1330,     0,  9448,   474, -1330,   856, -1330, -1330,  4802,   842,
     844, -1330, -1330, -1330,   906, -1330,    71, -1330, -1330,  1023,
   -1330, -1330, 11158, -1330, -1330,   502, -1330, -1330, -1330,   850,
     809,   810, -1330, -1330, -1330,   814,   817, -1330, -1330, -1330,
   -1330, -1330,   807, 11158,   863, -1330,   903, -1330,   644, -1330,
   -1330, -1330,  7439,   732, -1330,  5388, 11158,   874, -1330,   719,
   -1330,   525, -1330,    21,   939, -1330,  5388,   942,   788, -1330,
    8878,   867,   868,   870, -1330, -1330, -1330, -1330, -1330, -1330,
   -1330,  5388, -1330, -1330,  5388,   910,  5388,   876,   877, -1330,
      13,   818, -1330, -1330,   -82, -1330,   326,   -23,   819,    13,
     326,  5974, -1330,   128, -1330, -1330, -1330, -1330, -1330, -1330,
      13,   911,   779,   599,   -23, -1330, -1330,   793,   984, -1330,
   -1330, -1330, -1330, -1330,   882, -1330, -1330, -1330,  5388, -1330,
   -1330, -1330, -1330, -1330,  1038,   198,  1039,   198,   799,   970,
   -1330, -1330, -1330, -1330,   904, 11158,   824,   771,  6560, -1330,
   -1330,   890, -1330, -1330, -1330, -1330, -1330, -1330,  5388, 11158,
   11158, -1330,    78, -1330,  5388, -1330,   949,   978,   719,   918,
   -1330, -1330, -1330,  5388, -1330,   894, -1330, -1330, -1330,   893,
   -1330,  5388,  5388, 11158,   896,    -7, -1330, -1330, -1330,   907,
   -1330, -1330,   936, 11158,   570, -1330,   936, 11158, -1330, -1330,
    5388,  5388,  5388,  5388,  5388, -1330,  5388,  5388, -1330, -1330,
      -9, -1330,   908, -1330, -1330, -1330, -1330,   939, -1330, -1330,
   -1330,   719, -1330, -1330,   983,   897, -1330,   187, -1330, -1330,
   -1330, -1330, -1330,  5388, -1330, -1330, -1330, -1330,   909,  5974,
   -1330, -1330, -1330, -1330, -1330,   229,  5974,  5974,   238, -1330,
     737, -1330,   151, -1330,   734,    13,   931, -1330, -1330,   804,
   -1330, -1330, -1330, -1330, -1330,   173, -1330,   213,   213, -1330,
     198, -1330, -1330,   188, -1330,  1058,   -23,   912,   979, -1330,
    6560,   -66,   800, -1330,   919, -1330, -1330, -1330,  1040, -1330,
   -1330,  5388,   719, -1330, -1330, -1330,  5388, -1330, -1330,   997,
    5388, 11158,  5388, -1330,     4,   936, 11158,   899,   936, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330,   977,  7439, -1330, -1330,
   -1330, -1330, 10588, -1330, 10588,  1001, -1330, -1330,   -51,  5974,
    5974,   339,   341, -1330, -1330, -1330, -1330, -1330, -1330,  5388,
   -1330, -1330, -1330, -1330, -1330,  1071, -1330, -1330, -1330,   841,
   -1330,   970,   992, -1330,   484, 11158,   982,   878, 11158,  6560,
     985, -1330,   918, -1330, 10588, -1330,   917, -1330,    57,   333,
   -1330,   913,   936, -1330,   914, 11158, -1330, -1330, -1330, 10588,
     339,   339,  5974,   922, -1330, -1330, -1330,  6560, -1330,   939,
     805, 11158,   987,   887,   992, 11158,   928,  5388, -1330, -1330,
    1019,   155, -1330, -1330, -1330, -1330,   933,   410, -1330, -1330,
   -1330,   920, -1330,   209, -1330,   339, -1330, -1330, -1330,  5388,
     825, 11158,  1000, -1330,  5388, -1330, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330,  1002,   967, -1330,   828,   826, 11158, -1330,
   11158, -1330,   827,  5388,   843,   228,  6560, -1330,  6560,  1004,
     967, -1330,   926, 11158, -1330,   848,   940, 11158,   967,   915,
   -1330,  1006, 11158,   846,  6560, -1330
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
     940,   946,   829,   785,   809,     0,   941,   385,     0,   417,
     830,   812,   819,   827,   822,   890,   776,   781,   780,   779,
     778,   777,   748,   797,     0,   733,   843,   769,   876,   875,
     877,   753,   752,   772,   882,   741,   874,   879,   880,   871,
     775,   817,   873,   883,   881,   872,   773,   878,   892,   896,
     897,   893,   894,   891,   895,   898,   899,   901,   863,   862,
     849,   767,   760,   856,   852,   770,   766,   865,   866,   756,
     757,   750,   759,   861,   860,   857,   853,   870,   864,   859,
     855,   848,   758,   869,   868,   762,   764,   763,   854,   858,
     850,   765,   851,   761,   867,   923,   924,   925,   926,   927,
     928,   904,   905,   903,   909,   910,   911,   906,   907,   908,
     774,   929,   930,   931,   932,   933,   934,   935,     0,     0,
       4,     2,     0,     9,    11,    17,     0,     0,     0,    23,
      25,    34,    27,    28,    29,    55,    30,    39,    35,    59,
      60,    61,    56,    57,    63,    64,    33,    31,    32,    37,
      38,    58,   208,   207,   204,   205,   206,    36,    16,   184,
     185,   189,   191,   223,   229,     0,     0,   221,   222,   192,
     193,   194,   195,   196,   311,   313,   315,   325,   329,   331,
     334,   339,   342,   345,   347,   349,   351,     0,   353,   359,
     361,     0,   377,   360,   381,   384,   386,   389,   391,     0,
     396,   393,     0,   404,   414,   416,   390,   420,   427,   436,
     428,   429,   430,   433,   434,   431,   432,   451,   453,   454,
     455,   452,   500,   501,   502,   503,   504,   505,   413,   546,
     538,   545,   544,   543,   540,   542,   539,   541,   437,   435,
     573,   574,    62,   197,   198,   200,   199,   201,   202,   203,
     415,   732,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   112,
     113,     0,     0,     0,     0,   108,   109,   110,   111,   118,
       0,     0,     0,     0,     0,     0,     0,   106,   165,   168,
     171,   170,     0,     0,     0,     0,     0,   837,   846,   736,
     755,   737,   738,   900,   786,   847,   740,   844,   796,   787,
     742,   744,   902,   807,   745,   747,   746,   825,   936,   943,
     735,   937,   938,   944,   808,   942,   945,     0,     0,   889,
     939,   940,   946,   941,   890,   733,   882,   741,   874,   880,
     871,   773,   892,   896,   897,   893,   895,   898,   901,     0,
       0,     0,     0,   231,     0,     0,     0,     0,     0,     0,
       0,     0,   615,     0,     0,     0,   616,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   409,   412,
     399,     0,     0,     0,   736,   738,   742,   745,   735,   405,
     415,   397,   398,   401,   441,     0,   403,   402,   442,     0,
     467,     0,   408,     0,   380,     0,   411,   410,     0,   400,
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
       0,     0,   553,     0,     0,     0,     0,     0,   294,     0,
       0,   551,     0,     0,     0,   570,     0,     0,     0,     0,
     556,     0,     0,     0,     0,   443,   468,   467,   464,     0,
       0,   498,   497,   379,   561,     0,   495,     0,   596,   597,
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
       0,     0,     0,   555,   554,   517,     0,   569,     0,     0,
       0,     0,     0,   515,     0,     0,     0,   371,     0,     0,
       0,     0,   559,     0,   557,   511,     0,     0,   467,   465,
       0,   456,     0,   445,   446,     0,    13,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   837,     0,     0,     0,     0,     0,     0,    22,     0,
     188,   220,     0,   278,   274,   276,     0,   268,   269,     0,
     847,   739,     0,   748,   523,   524,   530,   531,   533,   577,
     578,   534,   537,     0,   236,     0,     0,     0,     0,     0,
       0,     0,   321,     0,     0,     0,     0,   647,   327,   620,
     624,   626,   628,   630,   633,   640,   641,   649,   346,   348,
     350,   521,   352,   376,   426,     0,   423,   448,    78,    79,
      76,    77,   173,     0,   172,     0,     0,    43,     0,     0,
      99,   100,   102,     0,   103,    68,    69,    74,    75,    65,
     687,     0,   690,   717,     0,   680,   679,   684,   683,   715,
       0,     0,   692,     0,   688,   691,   670,     0,     0,     0,
       0,     0,     0,   124,   130,     0,     0,     0,     0,     0,
       0,   127,     0,     0,     0,     0,     0,   570,     0,     0,
     508,     0,     0,   215,     0,     0,     0,     0,   260,     0,
     257,   262,   218,   181,   150,   179,     0,   182,     0,     0,
      92,    86,    89,    88,     0,    84,     0,   251,     0,     0,
       0,     0,   518,   160,     0,   292,   296,     0,     0,     0,
     299,     0,     0,     0,   306,     0,   373,   372,     0,     0,
       0,   512,   293,   468,     0,   457,     0,   491,   488,     0,
     492,   493,     0,   494,   487,     0,   462,   490,   489,     0,
       0,     0,   589,   590,   586,     0,     0,   594,   595,   591,
     600,   598,     0,     0,     0,   604,   158,   157,     0,   154,
     153,   162,     0,   605,   606,     0,     0,   275,   287,     0,
     288,     0,   279,   280,   281,   282,     0,   271,     0,   235,
       0,     0,     0,     0,   527,   529,   528,   525,   244,   245,
     238,     0,   240,   237,     0,     0,     0,     0,     0,   631,
     644,     0,   326,   328,     0,   663,     0,     0,     0,     0,
       0,     0,   619,   621,   622,   658,   659,   660,   662,   661,
       0,     0,   635,   634,     0,   638,   642,   656,   654,   653,
     646,   650,   522,   450,     0,   175,   174,   177,     0,    44,
      95,   105,   704,   685,     0,   709,     0,   709,   698,   693,
     125,   131,   133,   132,     0,     0,     0,   128,     0,    19,
     509,     0,   567,   568,   571,   564,   565,   255,     0,     0,
       0,   217,   258,   261,     0,   151,     0,    91,     0,    85,
     248,   253,   252,     0,   519,     0,   295,   297,   302,     0,
     300,     0,     0,     0,     0,     0,   307,   374,   513,     0,
     560,   558,   467,     0,     0,   499,   467,     0,   463,    14,
       0,     0,     0,     0,     0,   603,     0,     0,   156,   612,
       0,   607,     0,   250,   291,   289,   290,   283,   284,   285,
     277,     0,   272,   270,     0,     0,   535,     0,   532,   582,
     526,   242,   239,     0,   241,   648,   639,   645,     0,     0,
     718,   719,   729,   728,   727,     0,     0,     0,     0,   720,
     625,   726,     0,   623,   627,     0,     0,   632,   636,     0,
     657,   652,   655,   651,   183,     0,   705,     0,     0,   703,
     710,   711,   707,     0,   702,     0,   700,     0,   694,   695,
       0,     0,     0,   129,     0,   510,   256,   264,   265,   259,
     216,     0,     0,    87,   254,   520,     0,   303,   301,     0,
       0,     0,     0,   514,     0,   467,     0,     0,   467,   587,
     588,   592,   593,   599,   601,   159,     0,     0,   608,   617,
     286,   273,     0,   579,     0,     0,   243,   643,   730,     0,
       0,   722,     0,   668,   667,   666,   665,   664,   629,     0,
     721,   176,   714,   713,   712,     0,   706,   699,   697,     0,
     689,     0,   134,   136,   138,     0,     0,     0,     0,     0,
       0,   310,    93,   298,     0,   308,     0,   304,   477,   471,
     466,     0,   467,   458,     0,     0,   613,   580,   536,     0,
     724,   723,     0,     0,   708,   701,   696,     0,   140,   139,
       0,     0,     0,     0,   135,     0,     0,     0,   485,   479,
       0,   478,   480,   486,   483,   473,     0,   472,   474,   484,
     460,     0,   459,     0,   581,   725,   637,   137,   141,     0,
       0,     0,     0,   263,     0,   305,   470,   481,   482,   469,
     475,   476,   461,     0,     0,   142,     0,     0,     0,   309,
       0,   609,     0,     0,     0,     0,     0,   144,     0,     0,
       0,   143,     0,     0,   610,     0,     0,     0,     0,     0,
     611,     0,     0,     0,     0,   145
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1330, -1330,  -211,   884, -1330,   883,   888, -1330,   886, -1330,
     558,   572,  -550, -1330,   467,  -289, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
    -913, -1330, -1330, -1330, -1330,    74,   282,   752, -1330, -1330,
     738, -1330,    40,  -878, -1330,  -366,  -391, -1330, -1330,  -611,
   -1330,  -907, -1330, -1330,   -50, -1330, -1330, -1330, -1330, -1330,
     274,   765, -1330, -1330, -1330,   231,   674, -1329,   916,   -94,
   -1330,  -557,   -95, -1330, -1330, -1330, -1330,   237, -1330, -1330,
     866, -1330, -1330, -1330, -1330, -1330,   154,  -545,  -689, -1330,
   -1330, -1330,    18, -1330, -1330,  -156,    39,   -48, -1330, -1330,
   -1330,   -58, -1330, -1330,   167,   -55, -1330, -1330,   -47, -1188,
   -1330,   650,    19, -1330, -1330,    20, -1330, -1330, -1330,    14,
   -1330, -1330,   582,   577, -1330,  -549, -1330, -1330,  -590,    47,
    -605,    44,    53, -1330, -1330, -1330, -1330, -1330,   864, -1330,
   -1330, -1330, -1330,  -785,  -303, -1076, -1330,  -113, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330,   -41, -1170, -1330, -1330,   297,
     -67, -1330,  -757, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
     532, -1330,  -942, -1330,     6, -1330,   426,  -745, -1330, -1330,
   -1330, -1330, -1330,  -383,  -376, -1119, -1172, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330,   355,  -717,  -796,
      84,  -791, -1330,  -162,  -771, -1330, -1330, -1330, -1330, -1330,
   -1330, -1330,   764,   767,  -469,   276,   121, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
   -1330,   -11, -1330, -1330,   -19, -1330,  -369,  -106, -1330,  -990,
   -1330, -1330, -1330,   -63,   -73,  -217,   165, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
     -62, -1330, -1330, -1330,  -210,   159,   305, -1330, -1330, -1330,
   -1330, -1330,   112, -1330, -1330, -1253, -1330, -1330, -1330,  -744,
   -1330,   -91, -1330,  -223, -1330, -1330, -1330, -1330, -1217, -1330,
     -52, -1330,   -17, -1330
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   851,   852,   853,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
    1130,   714,   265,   266,   857,   858,   859,  1196,   267,   406,
     407,   268,  1093,   892,   269,  1502,  1503,   270,   271,   476,
     272,   545,   769,   982,  1197,   273,   274,   275,   276,   277,
     408,   409,   410,   411,   705,   706,  1173,  1054,   278,   279,
     566,   280,   281,   282,   576,   474,   914,   915,   283,   577,
     284,   579,   285,   286,   287,   583,   584,  1118,   795,   288,
     716,   773,   717,   702,  1119,  1120,  1121,   774,   580,   581,
     997,   998,  1372,   582,   994,   995,  1212,  1213,  1214,  1215,
     289,   727,   728,   290,  1149,  1150,  1151,   291,  1153,  1154,
     292,   293,   294,   295,   803,   296,  1242,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   603,
     604,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   630,
     631,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     831,   336,   337,   338,  1175,   747,   748,   749,  1520,  1556,
    1557,  1550,  1551,  1558,  1552,  1176,  1177,   339,   340,  1178,
     341,   342,   343,   344,   345,   346,   347,  1040,   796,  1004,
    1227,  1005,  1377,  1006,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   734,  1106,   358,   359,   360,   361,
    1008,  1009,  1010,  1011,   362,   363,   364,   365,   366,   367,
     766,   767,   368,  1203,  1204,  1360,  1131,   485,   369,  1028,
    1252,  1253,  1029,  1030,  1031,  1032,  1033,  1262,  1407,  1408,
    1034,  1265,  1035,  1388,  1036,  1037,  1270,  1271,  1413,  1411,
    1254,  1255,  1256,  1257,  1486,   672,   880,   881,   882,   883,
     884,   885,  1084,  1427,  1428,  1085,  1426,  1498,   886,  1287,
    1423,  1419,  1420,  1421,   887,   888,  1258,  1266,  1398,  1259,
    1394,  1243,   370,   371
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       469,   931,   960,   640,   811,   812,   813,   814,   625,   782,
     519,   523,   942,   780,  1135,   530,   486,  1101,   810,  1007,
    1174,  1294,  1026,  1038,  1039,  1368,  1369,   552,   509,   930,
     555,  1468,  1359,     5,  1238,   869,  1429,   837,   870,   799,
     794,   800,   801,   911,   802,  1505,   804,  1409,  1007,  1007,
    1027,   503,   510,   967,   805,   806,  1348,  1167,  1168,   532,
     790,  1548,  1087,  1059,   688,  1167,   514,  1395,  1088,   688,
     978,   751,   639,   971,   790,  1139,   791,  1201,   890,  1167,
    1168,   871,   903,  1007,   689,   791,  1089,   564,   520,   689,
    1016,  1518,   939,  1331,   986,   703,  1100,  1090,   564,  1081,
     486,  1198,   525,   854,  1451,  1017,   929,  1021,   528,   711,
     715,   905,   939,   412,   639,  1082,    75,  1234,   961,  1094,
    1209,  1124,   790,  1091,  1114,   792,   965,  1390,   918,    86,
     951,  1115,  1267,  1268,  1019,   480,  1053,   471,   645,  1466,
    1211,   613,   472,  1062,   855,  1169,  1007,   415,  1276,   856,
     614,  1506,  1244,   646,   100,  1269,   987,  1083,  1023,  1548,
     904,  1024,   704,  1167,  1170,  1391,  1171,  1169,   791,   565,
    1452,   940,  1170,   941,  1171,   968,   969,  1332,  1519,  1470,
     990,   119,  1549,  1199,   962,   966,  1170,   473,  1171,   906,
     970,   957,  1467,  1112,   707,   972,   973,   979,   105,  1123,
     712,   626,   707,   912,   710,   690,   919,   793,   952,  1499,
     974,  1222,   125,  1164,   117,  1290,   707,   793,  1244,   891,
     105,  1319,  1434,  1245,  1174,  1348,  1396,  1397,  1055,  1056,
     752,  1007,   872,  1174,  1507,  1172,   117,   891,   793,  1026,
    1026,   913,  1140,   533,   793,   873,   713,   874,  1536,  1092,
    1387,  1020,   793,   144,  1022,  1591,   953,  1343,   875,   876,
     877,   793,   878,   660,   879,  1025,   661,  1027,  1027,   585,
    1170,  1604,  1171,   564,  1479,   144,   627,   628,   632,  1610,
    1577,   634,   665,   494,   790,  1045,  1045,  1474,  1495,  1245,
     624,  1165,   372,   373,   866,   374,   375,  1526,   376,   662,
     707,   606,   510,  1284,   377,   510,   684,  1246,  1247,  1583,
    1248,   651,   378,   119,   379,   380,  1538,  1249,   607,   685,
     478,   687,   381,  1098,   382,   663,  1417,  1250,  1599,  1094,
    1315,  1235,  1099,   383,   954,  1111,  1240,   384,   416,  1251,
     495,  1167,   776,   652,   615,   926,  1553,  1559,  1491,   479,
    1480,  1568,  1554,   693,  1504,  1007,  1334,  1166,   616,   119,
     648,  1286,   650,  1046,  1047,  1475,  1496,   656,   385,   386,
     387,   486,  1224,  1246,  1247,   698,  1248,   673,   723,  1553,
     535,  1007,   536,   709,   675,  1559,   664,  1584,  1052,   720,
    1418,     5,   470,  1250,  1284,   486,   730,   377,   732,   733,
     641,   736,  1174,  1225,  1053,  1251,  1600,   739,   496,   497,
    1285,   606,  1208,  1483,   642,   381,   388,   382,  1167,  1433,
    1484,  1226,  1209,   475,  1376,   389,   383,   750,   607,  1554,
    1485,   696,  1210,  1504,  1105,   477,  1108,   755,   780,   481,
     758,   759,  1211,   761,   762,   763,   764,  1148,  1170,  1007,
    1171,   608,  1286,   770,   771,  1026,   772,   390,  1114,  1555,
    1329,  1504,   567,   718,  1026,  1115,   487,   486,   568,   781,
     725,   726,   729,   569,    75,  1026,   391,   735,   707,   787,
     788,   570,  1159,  1027,  1160,   742,   392,    86,   558,   606,
     637,   606,  1027,   571,  1065,  1066,   609,  1275,   729,  1069,
    1483,   638,   488,  1027,  1048,   559,   607,  1484,   607,   643,
    1167,  1168,   100,   544,   825,   826,  1023,  1485,   393,  1024,
    1601,  1049,  1602,   644,   610,  1170,   768,  1171,  1103,  1512,
     824,  1532,   669,   670,   775,   827,  1580,   611,  1615,   119,
     830,  1050,   489,   830,   394,   395,   396,   397,   398,  1114,
     399,   400,   401,   402,   403,   707,  1115,  1277,  1051,   404,
     405,  1081,  1057,   828,  1075,   413,   828,  1152,   414,   828,
    1077,   612,   790,  1278,  1116,  1076,  1057,  1082,  1167,  1168,
    1335,  1078,   538,  1209,   539,   861,   541,  1392,   492,   572,
     862,   542,   573,   791,  1393,   855,   490,  1454,  1169,   491,
     856,  1457,   493,   908,   922,   498,   574,   925,   678,   679,
    1070,  1071,  1072,   920,  1117,   515,  1073,  1170,   633,  1171,
    1026,  1067,  1068,   636,   666,   667,   668,   629,   499,   635,
     936,  1180,   575,  1181,  1095,  1096,   839,  1185,   840,  1186,
     511,   860,   512,   948,   949,  1365,  1366,   707,  1027,   956,
     647,   105,   649,   808,   809,   513,   376,   815,   816,  1041,
    1041,  1402,   377,   894,   895,   896,  1169,   117,   817,   818,
     378,   516,   379,  1492,  1493,   983,  1527,   517,  1528,   521,
     381,   522,   382,   526,   910,  1170,   916,  1171,  1347,   527,
     993,   383,   529,   486,   531,   384,   486,  1014,   389,   534,
     537,  1007,   540,  1007,   543,   544,   144,   546,   551,   547,
    1521,   548,   549,  1524,   554,   707,   550,   562,  1546,   105,
       1,  1415,   563,   625,   586,   587,   385,   386,   989,   958,
     390,   605,   617,  1564,   618,   117,   619,   629,   620,   639,
     653,   377,   655,  1007,   841,   842,   843,   844,   845,   846,
     847,   848,   849,   850,   657,   658,  1456,   671,  1007,   392,
    1317,  1061,   680,   674,   686,   697,   991,  1064,   701,   676,
     677,   699,   700,  1012,   144,   707,   719,  1561,   724,   731,
     737,   738,   743,   389,  1478,   745,   414,  1539,   448,   484,
     746,   753,   754,   491,   502,   756,   760,   757,   779,   765,
     807,   783,  1012,  1012,  1012,  1012,  1481,  1482,   784,   785,
     789,   786,   819,   820,   821,   390,   822,   681,   395,   396,
     397,   398,   832,   399,   400,   682,   402,   403,   838,   835,
     836,   863,   404,   868,  1137,   864,   893,  1012,   889,   867,
    1364,   898,   897,  1143,   392,  1145,  1146,   899,   917,   900,
     902,   901,  1155,  1074,   921,   909,   923,   924,   927,   928,
     932,   938,  1162,   975,   933,   934,   937,   943,   946,   944,
     947,   945,   950,  1182,  1183,  1184,   393,  1187,  1188,  1189,
    1190,  1191,  1192,   963,  1194,  1195,  1107,   964,  1107,  1530,
    1531,   976,   980,   984,   977,   988,   985,   993,   992,   996,
    1012,   999,   394,   395,   396,   397,   398,  1013,   399,   400,
     401,   402,   403,  1015,  1043,  1058,  1044,   404,   405,  1018,
     856,  1230,   790,  1232,  1233,  1079,  1063,  1104,  1110,  1237,
    1080,  1113,   703,  1126,   735,  1097,   735,  1127,  1128,  1129,
    1133,  1132,  1565,  1134,  1102,  1138,  1136,  1142,  1141,  1443,
    1273,  1144,  1147,   588,  1148,  1152,  1156,  1158,  1157,  1274,
    1161,   589,   590,  1163,   591,  1179,  1193,  1205,  1281,  1200,
    1202,  1206,   592,   662,  1216,  1218,   593,  1231,   594,  1217,
    1220,  1221,   585,   595,  1223,  1012,  1236,  1261,  1260,  1241,
    1272,  1264,     5,  1283,  1288,  1296,  1228,  1292,  1229,   596,
     891,  1282,  1471,  1293,  1295,  1299,  1298,  1304,  1302,  1303,
    1301,  1308,  1309,  1310,  1314,  1305,  1307,  1306,  1318,  1323,
    1340,  1311,  1341,   597,   598,   599,   600,   601,   602,  1345,
    1342,  1337,  1349,  1316,  1350,  1351,  1354,  1357,  1209,  1352,
    1356,  1371,  1353,  1321,  1322,  1378,  1379,  1325,  1380,  1383,
    1405,  1385,  1327,  1328,  1406,  1386,  1412,  1414,  1416,  1422,
    1081,  1389,  1399,  1425,  1339,  1435,  1430,  1441,  1442,  1445,
    1446,  1472,  1410,  1450,  1432,  1473,  1489,  1490,  1497,  1501,
    1508,  1509,  1453,  1469,  1477,  1514,  1510,  1523,  1525,  1529,
    1500,  1534,  1537,  1541,  1547,  1542,  1545,  1566,  1571,  1535,
    1312,  1560,  1562,  1569,  1572,  1574,  1576,  1579,  1582,  1012,
    1362,  1588,  1053,  1590,  1592,  1603,  1605,  1612,  1608,   718,
     777,   993,   553,  1586,  1593,   556,  1596,   729,  1607,   865,
     557,   560,  1611,  1280,   778,  1012,  1381,  1060,   659,  1382,
    1297,  1384,  1598,  1544,   683,  1614,  1567,   654,  1358,  1125,
     708,   578,  1122,  1219,  1320,  1346,  1439,  1313,  1363,  1207,
    1373,  1370,   561,  1326,   798,   744,  1367,  1336,   797,  1330,
     834,   623,  1344,   959,  1581,  1578,   768,  1042,  1291,  1279,
     691,  1109,  1355,   692,  1361,   510,  1400,  1404,  1488,   775,
    1239,  1403,  1487,  1263,  1086,  1289,  1424,  1494,  1401,     0,
       0,     0,     0,  1012,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1436,     0,     0,     0,     0,     0,  1440,
       0,     0,     0,     0,     0,     0,     0,     0,  1444,     0,
       0,     0,     0,     0,     0,     0,  1447,  1448,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1459,  1460,  1461,  1462,  1463,
       0,  1464,  1465,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1431,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1476,     0,
       0,     0,  1437,  1438,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1449,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1455,     0,     0,     0,
    1458,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1511,     0,     0,     0,
       0,  1513,     0,     0,     0,  1515,     0,  1517,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1533,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1516,     0,     0,     0,     0,  1522,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     510,     0,  1575,     0,     0,  1012,     0,  1012,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1585,     0,     0,     0,     0,  1589,
       0,     0,     0,     0,     0,     0,     0,     0,  1540,     0,
       0,  1543,     0,     0,     0,     0,     0,  1012,  1597,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1563,     0,
       0,     0,  1012,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1570,     0,     0,     0,  1573,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1587,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1594,     0,  1595,     1,     0,     0,     0,     0,     0,
       0,     2,     0,     0,     0,     0,  1606,     0,     3,     4,
    1609,     5,     0,     0,     0,  1613,     6,     7,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,     0,    27,
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
       0,     0,   120,   121,   122,     0,     0,     0,   123,     0,
     124,   125,   126,     0,   127,   128,   129,     0,   130,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     0,     0,   142,   143,   144,     0,   145,   146,     0,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,     0,   189,   190,   191,     0,   192,   193,   194,
     195,   196,   197,     0,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,     1,     0,     0,     0,     0,
       0,     0,     2,     0,     0,     0,     0,     0,     0,     3,
       4,     0,     5,     0,     0,     0,     0,     6,     7,     0,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,     0,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,     0,
      65,    66,    67,    68,    69,    70,    71,    72,     0,     0,
      73,    74,     0,     0,     0,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,     0,     0,    86,     0,
      87,    88,    89,    90,     0,    91,     0,     0,     0,    92,
      93,    94,    95,    96,     0,     0,     0,     0,     0,     0,
      97,    98,    99,   100,   101,   102,   103,     0,     0,     0,
     104,   105,   106,   107,   108,     0,     0,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   117,     0,   118,
     119,     0,     0,   120,   121,   122,     0,     0,     0,   123,
       0,   124,   125,   126,     0,   127,   128,   129,     0,   130,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,     0,     0,   142,   143,   144,     0,   145,   146,
       0,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,     0,   189,   190,   191,     0,   192,   193,
     194,   195,   196,   197,     0,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,     2,     0,     0,     0,     0,
       0,     0,     3,     4,     0,     5,     0,     0,     0,     0,
     417,   418,     0,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,   427,    23,    24,
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
       0,     0,   123,   518,   124,   125,   126,     0,   127,   128,
     129,     0,   130,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,     0,     0,   142,   143,   144,
       0,   455,   146,     0,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,     0,   189,   190,   191,
       0,   192,   193,   194,   195,   196,   197,     0,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,     2,     0,
       0,     0,     0,     0,     0,     3,     4,     0,     5,     0,
       0,     0,     0,   417,   418,     0,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
     427,    23,    24,    25,    26,     0,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,     0,    65,    66,    67,    68,
      69,    70,    71,    72,     0,     0,    73,    74,     0,     0,
       0,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,     0,     0,    86,     0,    87,    88,    89,    90,
       0,    91,     0,     0,     0,    92,    93,    94,    95,    96,
       0,     0,     0,     0,     0,     0,    97,    98,    99,   100,
     101,   102,   103,     0,     0,     0,   104,   105,   106,   107,
     108,     0,     0,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,     0,   118,   119,     0,     0,   120,
     121,   122,     0,   823,     0,   123,     0,   124,   125,   126,
       0,   127,   128,   129,     0,   130,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,     0,     0,
     142,   143,   144,     0,   455,   146,     0,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     0,
     189,   190,   191,     0,   192,   193,   194,   195,   196,   197,
       0,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,     2,     0,     0,     0,     0,     0,     0,     3,     4,
       0,     5,     0,     0,     0,     0,   417,   418,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,   427,    23,    24,    25,    26,     0,    27,
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
       0,     0,   120,   121,   122,     0,     0,     0,   123,   829,
     124,   125,   126,     0,   127,   128,   129,     0,   130,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     0,     0,   142,   143,   144,     0,   455,   146,     0,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,     0,   189,   190,   191,     0,   192,   193,   194,
     195,   196,   197,     0,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,     2,     0,     0,     0,     0,     0,
       0,     3,     4,     0,     5,     0,     0,     0,     0,   417,
     418,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,   427,    23,    24,    25,
      26,     0,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,    65,    66,    67,    68,    69,    70,    71,    72,
       0,     0,    73,    74,     0,     0,     0,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,     0,     0,
      86,     0,    87,    88,    89,    90,     0,    91,     0,     0,
       0,    92,    93,    94,    95,    96,     0,     0,     0,     0,
       0,     0,    97,    98,    99,   100,   101,   102,   103,     0,
       0,     0,   104,   105,   106,   107,   108,     0,     0,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
       0,   118,   119,     0,     0,   120,   121,   122,     0,     0,
       0,   123,   833,   124,   125,   126,     0,   127,   128,   129,
       0,   130,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,     0,     0,   142,   143,   144,     0,
     455,   146,     0,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,     0,   189,   190,   191,     0,
     192,   193,   194,   195,   196,   197,     0,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,     2,     0,     0,
       0,     0,     0,     0,     3,     4,     0,     5,     0,     0,
       0,     0,   417,   418,     0,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,   427,
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
     122,     0,   907,     0,   123,     0,   124,   125,   126,     0,
     127,   128,   129,     0,   130,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,     0,     0,   142,
     143,   144,     0,   455,   146,     0,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     0,   189,
     190,   191,     0,   192,   193,   194,   195,   196,   197,     0,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
       2,     0,     0,     0,     0,     0,     0,     3,     4,     0,
       5,     0,     0,     0,     0,   417,   418,     0,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,   427,    23,    24,    25,    26,     0,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,     0,    65,    66,
      67,    68,    69,    70,    71,    72,     0,     0,    73,    74,
       0,     0,     0,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,     0,     0,    86,     0,    87,    88,
      89,    90,     0,    91,     0,     0,     0,    92,    93,    94,
      95,    96,     0,     0,     0,     0,     0,     0,    97,    98,
      99,   100,   101,   102,   103,     0,     0,     0,   104,   105,
     106,   107,   108,     0,     0,     0,     0,   109,   110,   111,
     112,   113,   114,   115,   116,   117,     0,   118,   119,     0,
       0,   120,   121,   122,     0,   935,     0,   123,     0,   124,
     125,   126,     0,   127,   128,   129,     0,   130,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
       0,     0,   142,   143,   144,     0,   455,   146,     0,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,     0,   189,   190,   191,     0,   192,   193,   194,   195,
     196,   197,     0,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,     2,     0,     0,     0,     0,     0,     0,
       3,     4,     0,     5,     0,     0,     0,     0,   417,   418,
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,   427,    23,    24,    25,    26,
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
     118,   119,     0,     0,   120,   121,   122,     0,   955,     0,
     123,     0,   124,   125,   126,     0,   127,   128,   129,     0,
     130,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,   144,     0,   455,
     146,     0,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     0,   189,   190,   191,     0,   192,
     193,   194,   195,   196,   197,     0,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,     2,     0,     0,     0,
       0,     0,     0,     3,     4,     0,     5,     0,     0,     0,
       0,   417,   418,     0,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,   427,    23,
      24,    25,    26,     0,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,     0,    65,    66,    67,    68,    69,    70,
      71,    72,     0,     0,    73,    74,     0,     0,     0,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
       0,     0,    86,     0,    87,    88,    89,    90,     0,    91,
       0,     0,     0,    92,    93,    94,    95,    96,     0,     0,
       0,     0,     0,     0,    97,    98,    99,   100,   101,   102,
     103,     0,     0,     0,   104,   105,   106,   107,   108,     0,
       0,     0,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   117,     0,   118,   119,     0,     0,   120,   121,   122,
       0,  1300,     0,   123,     0,   124,   125,   126,     0,   127,
     128,   129,     0,   130,     0,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,     0,     0,   142,   143,
     144,     0,   455,   146,     0,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,     0,   189,   190,
     191,     0,   192,   193,   194,   195,   196,   197,     0,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,     2,
       0,     0,     0,     0,     0,     0,     3,     4,     0,     5,
       0,     0,     0,     0,   417,   418,     0,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   427,    23,    24,    25,    26,     0,    27,    28,    29,
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
     120,   121,   122,     0,  1324,     0,   123,     0,   124,   125,
     126,     0,   127,   128,   129,     0,   130,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     0,
       0,   142,   143,   144,     0,   455,   146,     0,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       0,   189,   190,   191,     0,   192,   193,   194,   195,   196,
     197,     0,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,     2,     0,     0,     0,     0,     0,     0,     3,
       4,     0,     5,     0,     0,     0,     0,   417,   418,     0,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,   427,    23,    24,    25,    26,     0,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,     0,
      65,    66,    67,    68,    69,    70,    71,    72,     0,     0,
      73,    74,     0,     0,     0,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,     0,     0,    86,     0,
      87,    88,    89,    90,     0,    91,     0,     0,     0,    92,
      93,    94,    95,    96,     0,     0,     0,     0,     0,     0,
      97,    98,    99,   100,   101,   102,   103,     0,     0,     0,
     104,   105,   106,   107,   108,     0,     0,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   117,     0,   118,
     119,     0,     0,   120,   121,   122,     0,  1338,     0,   123,
       0,   124,   125,   126,     0,   127,   128,   129,     0,   130,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,     0,     0,   142,   143,   144,     0,   455,   146,
       0,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,     0,   189,   190,   191,     0,   192,   193,
     194,   195,   196,   197,     0,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,     2,     0,     0,     0,     0,
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
       0,     0,   123,     0,   124,   125,   126,     0,   127,   128,
     129,     0,   130,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,     0,     0,   142,   143,   144,
       0,   455,   146,     0,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,     0,   189,   190,   191,
       0,   192,   193,   194,   195,   196,   197,     0,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,     2,     0,
       0,     0,     0,     0,     0,     3,     4,     0,     5,     0,
       0,     0,     0,   417,   418,     0,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
     427,    23,    24,    25,    26,     0,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,     0,    65,    66,    67,    68,
      69,    70,    71,    72,     0,     0,    73,    74,     0,     0,
       0,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,     0,     0,    86,     0,    87,    88,    89,    90,
       0,    91,     0,     0,     0,    92,    93,    94,    95,    96,
       0,     0,     0,     0,     0,     0,    97,    98,    99,   100,
     101,   102,   103,     0,     0,     0,   104,   105,   106,   107,
     108,     0,     0,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,     0,   118,   119,     0,     0,   120,
     121,   122,     0,     0,     0,   123,     0,   124,   125,   126,
       0,   127,   128,   129,     0,   130,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,     0,     0,
     142,   143,   144,     0,   455,   146,     0,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     0,
     189,   190,   191,     0,   192,   193,   194,   195,   196,   197,
       0,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,     2,     0,     0,     0,     0,     0,     0,     3,     4,
       0,     5,     0,     0,     0,     0,   417,   418,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,   423,
     424,    20,   426,   427,    23,   428,    25,    26,     0,    27,
      28,    29,    30,   429,    32,    33,    34,    35,    36,    37,
     432,    39,    40,   433,     0,    42,    43,    44,   435,   436,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     0,    65,
      66,    67,    68,    69,    70,    71,    72,     0,     0,    73,
      74,     0,     0,     0,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,     0,     0,    86,     0,    87,
      88,    89,    90,     0,    91,     0,     0,     0,   444,    93,
      94,    95,    96,     0,     0,     0,     0,     0,     0,    97,
      98,    99,   100,   101,   102,   103,     0,     0,     0,   104,
     105,   621,   107,   108,     0,     0,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,     0,   622,   119,
       0,     0,   120,   121,   122,     0,     0,     0,   123,     0,
     124,   125,   126,     0,   127,   128,   129,     0,   130,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     0,     0,   142,   143,   144,     0,   455,   146,     0,
     147,   148,   149,   150,   151,   152,   153,   456,   155,   458,
     157,   459,   460,   160,   161,   162,   163,   164,   165,   461,
     167,   462,   463,   464,   465,   172,   173,   466,   467,   176,
     468,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,     0,   189,   190,   191,     0,   192,   193,   194,
     195,   196,   197,     0,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,     2,     0,     0,     0,     0,     0,
       0,     3,     4,     0,     5,     0,     0,     0,     0,   417,
     418,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,   423,   424,    20,   426,   427,    23,   428,    25,
      26,     0,    27,    28,    29,    30,   429,    32,    33,    34,
      35,    36,    37,   432,    39,    40,   433,     0,    42,    43,
      44,   435,   436,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,    65,    66,    67,    68,    69,    70,    71,    72,
       0,     0,    73,    74,     0,     0,     0,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,     0,     0,
      86,     0,    87,    88,    89,    90,     0,    91,     0,     0,
       0,   444,    93,    94,    95,    96,     0,     0,     0,     0,
       0,     0,    97,    98,    99,   100,   101,   102,   103,     0,
       0,     0,   104,   105,   106,   107,   108,     0,     0,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
       0,   118,   119,     0,     0,   120,   121,   122,     0,     0,
       0,   123,     0,   124,   125,   126,     0,   127,   128,   129,
       0,   130,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,     0,     0,   142,   143,   144,     0,
     455,   146,     0,   147,   148,   149,   150,   151,   152,   153,
     456,   155,   458,   157,   459,   460,   160,   161,   162,   163,
     164,   165,   461,   167,   462,   463,   464,   465,   172,   173,
     466,   467,   176,   468,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,     0,   189,   190,   191,     0,
     192,   193,   194,   195,   196,   197,     0,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,     2,     0,     0,
       0,     0,     0,     0,     3,     4,     0,     5,     0,     0,
       0,     0,   981,   418,     0,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,   427,
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
     122,     0,     0,     0,   123,     0,   124,   125,   126,     0,
     127,   128,   129,     0,   130,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,     0,     0,   142,
     143,   144,     0,   455,   146,     0,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     0,   189,
     190,   191,     0,   192,   193,   194,   195,   196,   197,     0,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
       2,     0,     0,     0,     0,     0,     0,     3,     4,     0,
       5,     0,     0,     0,     0,   417,   418,     0,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,   423,   424,
      20,   426,   427,    23,   428,    25,    26,     0,    27,    28,
      29,    30,   429,    32,    33,    34,    35,    36,    37,   432,
      39,    40,   433,     0,    42,    43,    44,   435,   436,    47,
     437,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,     0,    65,    66,
      67,    68,    69,    70,    71,    72,     0,     0,    73,    74,
       0,     0,     0,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,     0,     0,    86,     0,    87,    88,
      89,    90,     0,    91,     0,     0,     0,   444,    93,    94,
      95,    96,     0,     0,     0,     0,     0,     0,    97,    98,
      99,   100,   101,   102,   103,     0,     0,     0,   104,   105,
       0,   107,   108,     0,     0,     0,     0,   109,   110,   111,
     112,   113,   114,   115,   116,   117,     0,     0,     0,     0,
       0,   120,   121,   122,     0,     0,     0,   123,     0,   124,
     125,   126,     0,   127,   128,   129,     0,   130,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
       0,     0,   142,   143,   144,     0,   455,   146,     0,   147,
     148,   149,   150,   151,   152,   153,   456,   155,   458,   157,
     459,   460,   160,   161,   162,   163,   164,   165,   461,   167,
     462,   463,   464,   465,   172,   173,   466,   467,   176,   468,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,     0,   189,   190,   191,     0,   192,   193,   194,   195,
     196,   197,     0,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,     2,     0,     0,     0,     0,     0,     0,
       3,     4,     0,     5,     0,     0,     0,     0,   417,   418,
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,   423,   424,    20,   426,   427,    23,   428,    25,    26,
       0,    27,    28,    29,    30,   429,    32,    33,    34,    35,
      36,    37,   432,    39,    40,   433,     0,    42,    43,    44,
     435,   436,    47,   437,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,    65,    66,    67,    68,    69,    70,    71,    72,     0,
       0,    73,    74,     0,     0,     0,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,     0,     0,    86,
       0,    87,    88,    89,    90,     0,    91,     0,     0,     0,
     444,    93,    94,    95,    96,     0,     0,     0,     0,     0,
       0,    97,    98,    99,   100,   101,   102,   103,     0,     0,
       0,   104,   105,     0,   107,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,     0,
       0,     0,     0,     0,   120,   121,   122,     0,     0,     0,
     123,     0,   124,   125,   126,     0,     0,     0,   129,     0,
     130,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,   144,     0,   455,
     146,     0,   147,   148,   149,   150,   151,   152,   153,   456,
     155,   458,   157,   459,   460,   160,   161,   162,   163,   164,
     165,   461,   167,   462,   463,   464,   465,   172,   173,   466,
     467,   176,   468,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     0,   189,   190,   191,     0,   192,
     193,   194,   195,   196,   197,     0,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,     2,     0,     0,     0,
       0,     0,     0,     3,     4,     0,     0,     0,     0,     0,
       0,   417,   418,     0,     8,     9,   504,    11,    12,    13,
      14,   420,    16,   505,   423,   424,   425,   426,   427,    23,
     428,    25,    26,     0,    27,    28,    29,    30,   429,    32,
     506,    34,    35,    36,    37,   432,    39,    40,   433,     0,
      42,   507,    44,   435,   436,    47,   437,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
     438,   439,    64,     0,    65,    66,    67,   508,     0,    70,
      71,    72,     0,     0,   441,    74,     0,     0,     0,     0,
      76,    77,    78,   442,   443,    81,    82,     0,     0,     0,
       0,     0,     0,     0,    87,    88,    89,    90,     0,    91,
       0,     0,     0,   444,    93,    94,   445,   446,     0,     0,
       0,     0,     0,     0,    97,    98,    99,     0,   101,   102,
     103,     0,     0,     0,     0,     0,     0,   107,   108,     0,
       0,     0,     0,   109,   110,   111,   112,   449,   114,   115,
     450,     0,     0,     0,     0,     0,     0,   451,   452,   122,
       0,     0,     0,   123,     0,   124,   125,   453,     0,     0,
       0,   129,     0,   130,     0,   131,   132,   133,   134,   454,
     136,   137,   138,   139,   140,   141,     0,     0,   142,   143,
       0,     0,   455,   146,     0,   147,   148,   149,   150,   151,
     152,   153,   456,   155,   458,   157,   459,   460,   160,   161,
     162,   163,   164,   165,   461,   167,   462,   463,   464,   465,
     172,   173,   466,   467,   176,   468,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,     0,   189,   190,
     191,     0,   192,   193,   194,   195,   196,   197,     0,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,     2,
       0,     0,     0,     0,     0,     0,     3,     4,     0,     0,
       0,     0,     0,     0,   417,   418,     0,     8,     9,   419,
      11,    12,    13,    14,   420,   421,   422,   423,   424,   425,
     426,   427,    23,   428,    25,    26,     0,    27,    28,    29,
      30,   429,    32,   430,    34,    35,   431,    37,   432,    39,
      40,   433,     0,    42,   434,    44,   435,   436,    47,   437,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,   438,   439,    64,     0,    65,    66,    67,
     440,     0,    70,    71,    72,     0,     0,   441,    74,     0,
       0,     0,     0,    76,    77,    78,   442,   443,    81,    82,
       0,     0,     0,     0,     0,     0,     0,    87,    88,    89,
      90,     0,    91,     0,     0,     0,   444,    93,    94,   445,
     446,     0,     0,     0,     0,     0,     0,    97,    98,    99,
       0,   101,   102,   103,     0,     0,     0,     0,     0,     0,
     107,   108,     0,     0,     0,     0,   109,   110,   111,   112,
     449,   114,   115,   450,     0,     0,     0,     0,     0,     0,
     451,   452,   122,     0,     0,     0,   123,     0,   124,     0,
     453,     0,     0,     0,   129,     0,   130,     0,   131,   132,
     133,   134,   454,   136,   137,   138,   139,   140,   141,     0,
       0,   142,   143,     0,     0,   455,   146,     0,   147,   148,
     149,   150,   151,   152,   153,   456,   457,   458,   157,   459,
     460,   160,   161,   162,   163,   164,   165,   461,   167,   462,
     463,   464,   465,   172,   173,   466,   467,   176,   468,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       0,   189,   190,   191,     0,   192,   193,   194,   195,   196,
     197,     0,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   482,     0,     0,     0,     4,     0,     0,     0,
       0,     0,     0,   417,   418,     0,     8,     9,   419,    11,
      12,    13,    14,   420,   421,   422,   423,   424,   425,   426,
     427,    23,   428,    25,    26,     0,    27,    28,    29,    30,
     429,    32,   430,    34,    35,   431,    37,   432,    39,    40,
     433,     0,    42,   434,    44,   435,   436,    47,   437,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,   438,   439,    64,     0,    65,    66,    67,   440,
       0,    70,    71,    72,     0,     0,   441,    74,     0,     0,
       0,     0,    76,    77,    78,   442,   443,    81,    82,     0,
       0,     0,     0,     0,     0,     0,    87,    88,    89,    90,
       0,    91,     0,     0,     0,   444,    93,    94,   445,   446,
       0,     0,     0,     0,     0,     0,    97,    98,    99,     0,
     101,   102,   103,   483,     0,     0,   484,     0,     0,   107,
     108,     0,     0,     0,     0,   109,   110,   111,   112,   449,
     114,   115,   450,     0,     0,     0,     0,     0,     0,   451,
     452,   122,     0,     0,     0,   123,     0,   124,     0,   453,
       0,     0,     0,     0,     0,   130,     0,   131,   132,   133,
     134,   454,   136,   137,   138,   139,   140,   141,     0,     0,
     142,   143,     0,     0,   455,   146,     0,   147,   148,   149,
     150,   151,   152,   153,   456,   457,   458,   157,   459,   460,
     160,   161,   162,   163,   164,   165,   461,   167,   462,   463,
     464,   465,   172,   173,   466,   467,   176,   468,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     0,
     189,   190,   191,     0,   192,   193,   194,   195,   196,   197,
       0,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   482,     0,     0,     0,     4,     0,   721,     0,     0,
       0,     0,   417,   418,     0,     8,     9,   419,    11,    12,
      13,    14,   420,   421,   422,   423,   424,   425,   426,   427,
      23,   428,    25,    26,     0,    27,    28,    29,    30,   429,
      32,   430,    34,    35,   431,    37,   432,    39,    40,   433,
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
     122,     0,     0,     0,   123,   722,   124,     0,   453,     0,
       0,     0,     0,     0,   130,     0,   131,   132,   133,   134,
     454,   136,   137,   138,   139,   140,   141,     0,     0,   142,
     143,     0,     0,   455,   146,     0,   147,   148,   149,   150,
     151,   152,   153,   456,   457,   458,   157,   459,   460,   160,
     161,   162,   163,   164,   165,   461,   167,   462,   463,   464,
     465,   172,   173,   466,   467,   176,   468,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     0,   189,
     190,   191,     0,   192,   193,   194,   195,   196,   197,     0,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     482,     0,     0,     0,     4,     0,     0,     0,     0,     0,
       0,   417,   418,     0,     8,     9,   419,    11,    12,    13,
      14,   420,   421,   422,   423,   424,   425,   426,   427,    23,
     428,    25,    26,     0,    27,    28,    29,    30,   429,    32,
     430,    34,    35,   431,    37,   432,    39,    40,   433,     0,
      42,   434,    44,   435,   436,    47,   437,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
     438,   439,    64,     0,    65,    66,    67,   440,     0,    70,
      71,    72,     0,     0,   441,    74,     0,     0,     0,     0,
      76,    77,    78,   442,   443,    81,    82,     0,     0,     0,
       0,     0,     0,     0,    87,    88,    89,    90,     0,    91,
       0,     0,     0,   444,    93,    94,   445,   446,     0,     0,
       0,     0,     0,     0,    97,    98,    99,     0,   101,   102,
     103,     0,     0,     0,     0,     0,     0,   107,   108,     0,
       0,     0,     0,   109,   110,   111,   112,   449,   114,   115,
     450,     0,     0,     0,     0,     0,     0,   451,   452,   122,
       0,     0,     0,   123,     0,   124,     0,   453,     0,     0,
       0,     0,     0,   130,     0,   131,   132,   133,   134,   454,
     136,   137,   138,   139,   140,   141,     0,     0,   142,   143,
       0,     0,   455,   146,     0,   147,   148,   149,   150,   151,
     152,   153,   456,   457,   458,   157,   459,   460,   160,   161,
     162,   163,   164,   165,   461,   167,   462,   463,   464,   465,
     172,   173,   466,   467,   176,   468,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,     0,   189,   190,
     191,     0,   192,   193,   194,   195,   196,   197,     0,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   524,
       0,     4,     0,     0,     0,     0,     0,     0,   417,   418,
       0,     8,     9,   419,    11,    12,    13,    14,   420,   421,
     422,   423,   424,   425,   426,   427,    23,   428,    25,    26,
       0,    27,    28,    29,    30,   429,    32,   430,    34,    35,
     431,    37,   432,    39,    40,   433,     0,    42,   434,    44,
     435,   436,    47,   437,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,   438,   439,    64,
       0,    65,    66,    67,   440,     0,    70,    71,    72,     0,
       0,   441,    74,     0,     0,     0,     0,    76,    77,    78,
     442,   443,    81,    82,     0,     0,     0,     0,     0,     0,
       0,    87,    88,    89,    90,     0,    91,     0,     0,     0,
     444,    93,    94,   445,   446,     0,     0,     0,     0,     0,
       0,    97,    98,    99,     0,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   107,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   449,   114,   115,   450,     0,     0,
       0,     0,     0,     0,   451,   452,   122,     0,     0,     0,
     123,     0,   124,     0,   453,     0,     0,     0,     0,     0,
     130,     0,   131,   132,   133,   134,   454,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,     0,     0,   455,
     146,     0,   147,   148,   149,   150,   151,   152,   153,   456,
     457,   458,   157,   459,   460,   160,   161,   162,   163,   164,
     165,   461,   167,   462,   463,   464,   465,   172,   173,   466,
     467,   176,   468,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     0,   189,   190,   191,     0,   192,
     193,   194,   195,   196,   197,     0,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,     4,     0,     0,     0,
       0,     0,     0,   417,   418,     0,     8,     9,   504,    11,
      12,    13,    14,   420,    16,   505,   423,   424,  1000,   426,
     427,    23,   428,    25,    26,     0,    27,    28,    29,    30,
     429,    32,   506,    34,    35,    36,    37,   432,    39,    40,
     433,     0,    42,   507,    44,   435,   436,    47,   437,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,   438,   439,    64,     0,    65,    66,    67,   508,
       0,    70,    71,    72,     0,     0,   441,    74,     0,     0,
       0,     0,    76,    77,    78,   442,   443,    81,    82,     0,
       0,     0,     0,     0,     0,     0,    87,    88,    89,    90,
       0,    91,     0,     0,     0,   444,    93,    94,   445,   446,
       0,     0,     0,     0,     0,     0,    97,    98,    99,     0,
     101,   102,  1001,     0,     0,     0,  1002,     0,     0,   107,
     108,     0,     0,     0,     0,   109,   110,   111,   112,   449,
     114,   115,   450,     0,     0,     0,     0,     0,     0,   451,
     452,   122,     0,     0,     0,   123,  1374,   124,   125,   453,
       0,     0,     0,  1375,     0,   130,     0,   131,   132,   133,
     134,   454,   136,   137,   138,   139,   140,   141,     0,     0,
    1003,   143,     0,     0,   455,   146,     0,   147,   148,   149,
     150,   151,   152,   153,   456,   155,   458,   157,   459,   460,
     160,   161,   162,   163,   164,   165,   461,   167,   462,   463,
     464,   465,   172,   173,   466,   467,   176,   468,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     0,
     189,   190,   191,     0,   192,   193,   194,   195,   196,   197,
       0,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,     4,     0,     0,     0,     0,     0,     0,   417,   418,
       0,     8,     9,   419,    11,    12,    13,    14,   420,   421,
     422,   423,   424,   425,   426,   427,    23,   428,    25,    26,
       0,    27,    28,    29,    30,   429,    32,   430,    34,    35,
     431,    37,   432,    39,    40,   433,     0,    42,   434,    44,
     435,   436,    47,   437,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,   438,   439,    64,
       0,    65,    66,    67,   440,     0,    70,    71,    72,     0,
       0,   441,    74,     0,     0,     0,     0,    76,    77,    78,
     442,   443,    81,    82,     0,     0,     0,   500,     0,     0,
       0,    87,    88,    89,    90,     0,    91,     0,     0,     0,
     444,    93,    94,   445,   446,     0,     0,     0,     0,     0,
       0,    97,    98,    99,     0,   101,   102,   103,   501,     0,
       0,   502,     0,     0,   107,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   449,   114,   115,   450,     0,     0,
       0,     0,     0,     0,   451,   452,   122,     0,     0,     0,
     123,     0,   124,     0,   453,     0,     0,     0,     0,     0,
     130,     0,   131,   132,   133,   134,   454,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,     0,     0,   455,
     146,     0,   147,   148,   149,   150,   151,   152,   153,   456,
     457,   458,   157,   459,   460,   160,   161,   162,   163,   164,
     165,   461,   167,   462,   463,   464,   465,   172,   173,   466,
     467,   176,   468,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     0,   189,   190,   191,     0,   192,
     193,   194,   195,   196,   197,     0,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,     4,     0,     0,     0,
       0,     0,     0,   417,   418,     0,     8,     9,   504,    11,
      12,    13,    14,   420,    16,   505,   423,   424,  1000,   426,
     427,    23,   428,    25,    26,     0,    27,    28,    29,    30,
     429,    32,   506,    34,    35,    36,    37,   432,    39,    40,
     433,     0,    42,   507,    44,   435,   436,    47,   437,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,   438,   439,    64,     0,    65,    66,    67,   508,
       0,    70,    71,    72,     0,     0,   441,    74,     0,     0,
       0,     0,    76,    77,    78,   442,   443,    81,    82,  1333,
       0,     0,     0,     0,     0,     0,    87,    88,    89,    90,
       0,    91,     0,     0,     0,   444,    93,    94,   445,   446,
       0,     0,     0,     0,     0,     0,    97,    98,    99,     0,
     101,   102,  1001,     0,     0,     0,  1002,     0,     0,   107,
     108,     0,     0,     0,     0,   109,   110,   111,   112,   449,
     114,   115,   450,     0,     0,     0,     0,     0,     0,   451,
     452,   122,     0,     0,     0,   123,     0,   124,   125,   453,
       0,     0,     0,     0,     0,   130,     0,   131,   132,   133,
     134,   454,   136,   137,   138,   139,   140,   141,     0,     0,
    1003,   143,     0,     0,   455,   146,     0,   147,   148,   149,
     150,   151,   152,   153,   456,   155,   458,   157,   459,   460,
     160,   161,   162,   163,   164,   165,   461,   167,   462,   463,
     464,   465,   172,   173,   466,   467,   176,   468,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     0,
     189,   190,   191,     0,   192,   193,   194,   195,   196,   197,
       0,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,     4,     0,     0,     0,     0,     0,     0,   417,   418,
       0,     8,     9,   419,    11,    12,    13,    14,   420,   421,
     422,   423,   424,   425,   426,   427,    23,   428,    25,    26,
       0,    27,    28,    29,    30,   429,    32,   430,    34,    35,
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
     123,     0,   124,     0,   453,     0,     0,     0,     0,     0,
     130,     0,   131,   132,   133,   134,   454,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,     0,     0,   455,
     146,     0,   147,   148,   149,   150,   151,   152,   153,   456,
     457,   458,   157,   459,   460,   160,   161,   162,   163,   164,
     165,   461,   167,   462,   463,   464,   465,   172,   173,   466,
     467,   176,   468,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     0,   189,   190,   191,     0,   192,
     193,   194,   195,   196,   197,     0,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,     4,     0,     0,     0,
       0,     0,     0,   417,   418,     0,     8,     9,   419,    11,
      12,    13,    14,   420,   421,   422,   423,   424,   425,   426,
     427,    23,   428,    25,    26,     0,    27,    28,    29,    30,
     429,    32,   430,    34,    35,   431,    37,   432,    39,    40,
     433,     0,    42,   434,    44,   435,   436,    47,   437,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,   438,   439,    64,     0,    65,    66,    67,   440,
       0,    70,    71,    72,     0,     0,   441,    74,     0,     0,
       0,     0,    76,    77,    78,   442,   443,    81,    82,     0,
       0,     0,     0,     0,     0,     0,    87,    88,    89,    90,
       0,    91,     0,     0,     0,   444,    93,    94,   445,   446,
       0,     0,     0,     0,     0,     0,    97,    98,    99,     0,
     101,   102,   103,     0,     0,     0,     0,     0,     0,   107,
     108,     0,     0,     0,     0,   109,   110,   111,   112,   449,
     114,   115,   450,     0,     0,     0,     0,     0,     0,   451,
     452,   122,     0,     0,     0,   123,   694,   124,     0,   453,
       0,     0,     0,   695,     0,   130,     0,   131,   132,   133,
     134,   454,   136,   137,   138,   139,   140,   141,     0,     0,
     142,   143,     0,     0,   455,   146,     0,   147,   148,   149,
     150,   151,   152,   153,   456,   457,   458,   157,   459,   460,
     160,   161,   162,   163,   164,   165,   461,   167,   462,   463,
     464,   465,   172,   173,   466,   467,   176,   468,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     0,
     189,   190,   191,     0,   192,   193,   194,   195,   196,   197,
       0,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,     4,     0,     0,     0,     0,     0,     0,   417,   418,
       0,     8,     9,   419,    11,    12,    13,    14,   420,   421,
     422,   423,   424,   425,   426,   427,    23,   428,    25,    26,
       0,    27,    28,    29,    30,   429,    32,   430,    34,    35,
     431,    37,   432,    39,    40,   433,     0,    42,   434,    44,
     435,   436,    47,   437,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,   438,   439,    64,
       0,    65,    66,    67,   440,     0,    70,    71,    72,     0,
       0,   441,    74,     0,     0,     0,     0,    76,    77,    78,
     442,   443,    81,    82,     0,     0,     0,     0,     0,     0,
       0,    87,    88,    89,    90,     0,    91,     0,     0,     0,
     444,    93,    94,   445,   446,     0,     0,     0,     0,     0,
       0,    97,    98,    99,     0,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   107,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   449,   114,   115,   450,     0,     0,
       0,     0,     0,     0,   451,   452,   122,     0,     0,     0,
     123,   740,   124,     0,   453,     0,     0,     0,   741,     0,
     130,     0,   131,   132,   133,   134,   454,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,     0,     0,   455,
     146,     0,   147,   148,   149,   150,   151,   152,   153,   456,
     457,   458,   157,   459,   460,   160,   161,   162,   163,   164,
     165,   461,   167,   462,   463,   464,   465,   172,   173,   466,
     467,   176,   468,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     0,   189,   190,   191,     0,   192,
     193,   194,   195,   196,   197,     0,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,     4,     0,     0,     0,
       0,     0,     0,   417,   418,     0,     8,     9,   504,    11,
      12,    13,    14,   420,    16,   505,   423,   424,  1000,   426,
     427,    23,   428,    25,    26,     0,    27,    28,    29,    30,
     429,    32,   506,    34,    35,    36,    37,   432,    39,    40,
     433,     0,    42,   507,    44,   435,   436,    47,   437,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,   438,   439,    64,     0,    65,    66,    67,   508,
       0,    70,    71,    72,     0,     0,   441,    74,     0,     0,
       0,     0,    76,    77,    78,   442,   443,    81,    82,     0,
       0,     0,     0,     0,     0,     0,    87,    88,    89,    90,
       0,    91,     0,     0,     0,   444,    93,    94,   445,   446,
       0,     0,     0,     0,     0,     0,    97,    98,    99,     0,
     101,   102,  1001,     0,     0,     0,  1002,     0,     0,   107,
     108,     0,     0,     0,     0,   109,   110,   111,   112,   449,
     114,   115,   450,     0,     0,     0,     0,     0,     0,   451,
     452,   122,     0,     0,     0,   123,     0,   124,   125,   453,
       0,     0,     0,     0,     0,   130,     0,   131,   132,   133,
     134,   454,   136,   137,   138,   139,   140,   141,     0,     0,
    1003,   143,     0,     0,   455,   146,     0,   147,   148,   149,
     150,   151,   152,   153,   456,   155,   458,   157,   459,   460,
     160,   161,   162,   163,   164,   165,   461,   167,   462,   463,
     464,   465,   172,   173,   466,   467,   176,   468,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     0,
     189,   190,   191,     0,   192,   193,   194,   195,   196,   197,
       0,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,     4,     0,     0,     0,     0,     0,     0,   417,   418,
       0,     8,     9,   504,    11,    12,    13,    14,   420,    16,
     505,   423,   424,  1000,   426,   427,    23,   428,    25,    26,
       0,    27,    28,    29,    30,   429,    32,   506,    34,    35,
      36,    37,   432,    39,    40,   433,     0,    42,   507,    44,
     435,   436,    47,   437,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,   438,   439,    64,
       0,    65,    66,    67,   508,     0,    70,    71,    72,     0,
       0,   441,    74,     0,     0,     0,     0,    76,    77,    78,
     442,   443,    81,    82,     0,     0,     0,     0,     0,     0,
       0,    87,    88,    89,    90,     0,    91,     0,     0,     0,
     444,    93,    94,   445,   446,     0,     0,     0,     0,     0,
       0,    97,    98,    99,     0,   101,   102,  1001,     0,     0,
       0,  1002,     0,     0,   107,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   449,   114,   115,   450,     0,     0,
       0,     0,     0,     0,   451,   452,   122,     0,     0,     0,
     123,     0,   124,   125,   453,     0,     0,     0,     0,     0,
     130,     0,   131,   132,   133,   134,   454,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,     0,     0,   455,
     146,     0,   147,   148,   149,   150,   151,   152,   153,   456,
     155,   458,   157,   459,   460,   160,   161,   162,   163,   164,
     165,   461,   167,   462,   463,   464,   465,   172,   173,   466,
     467,   176,   468,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     0,   189,   190,   191,     0,   192,
     193,   194,   195,   196,   197,     0,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,     4,     0,     0,     0,
       0,     0,     0,   417,   418,     0,     8,     9,   419,    11,
      12,    13,    14,   420,   421,   422,   423,   424,   425,   426,
     427,    23,   428,    25,    26,     0,    27,    28,    29,    30,
     429,    32,   430,    34,    35,   431,    37,   432,    39,    40,
     433,     0,    42,   434,    44,   435,   436,    47,   437,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,   438,   439,    64,     0,    65,    66,    67,   440,
       0,    70,    71,    72,     0,     0,   441,    74,     0,     0,
       0,     0,    76,    77,    78,   442,   443,    81,    82,     0,
       0,     0,     0,     0,     0,     0,    87,    88,    89,    90,
       0,    91,     0,     0,     0,   444,    93,    94,   445,   446,
       0,     0,     0,     0,     0,     0,    97,    98,    99,     0,
     101,   102,   103,     0,     0,     0,     0,     0,     0,   107,
     108,     0,     0,     0,     0,   109,   110,   111,   112,   449,
     114,   115,   450,     0,     0,     0,     0,     0,     0,   451,
     452,   122,     0,     0,     0,   123,     0,   124,     0,   453,
       0,     0,     0,     0,     0,   130,     0,   131,   132,   133,
     134,   454,   136,   137,   138,   139,   140,   141,     0,     0,
     142,   143,     0,     0,   455,   146,     0,   147,   148,   149,
     150,   151,   152,   153,   456,   457,   458,   157,   459,   460,
     160,   161,   162,   163,   164,   165,   461,   167,   462,   463,
     464,   465,   172,   173,   466,   467,   176,   468,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     0,
     189,   190,   191,     0,   192,   193,   194,   195,   196,   197,
       0,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        17,   718,   747,   372,   609,   610,   611,   612,   311,   566,
     104,   117,   729,   563,   927,   128,    33,   895,   608,   790,
     962,  1097,   807,   819,   820,  1213,  1214,   238,    69,   718,
     241,  1360,  1202,    20,  1024,    47,  1289,   648,    50,   588,
     585,   590,   591,    49,   593,   111,   595,  1264,   819,   820,
     807,    68,    69,    88,   603,   604,  1175,     8,     9,    21,
      88,     4,    30,   854,    37,     8,    83,    90,    36,    37,
     100,     7,    20,    88,    88,   134,    90,   984,    88,     8,
       9,    93,   100,   854,    57,    90,    54,   100,   105,    57,
     139,    87,   100,    93,    38,   111,    88,    65,   100,    90,
     117,   100,   119,    88,   111,   794,   134,   796,   125,   478,
     479,   100,   100,   152,    20,   106,   103,   139,   122,   890,
      99,   917,    88,    91,    46,   139,   123,   209,   100,   116,
     100,    53,   240,   241,   139,   111,   145,    61,   158,   148,
     119,   192,    66,   860,   129,    96,   917,   145,  1055,   134,
     201,   217,    90,   173,   141,   263,   100,   148,   145,     4,
     178,   148,   178,     8,   115,   247,   117,    96,    90,   182,
     177,   179,   115,   139,   117,   210,   211,   177,   174,  1367,
     182,   168,   125,   182,   188,   182,   115,   111,   117,   178,
     225,   179,   201,   910,   145,   210,   211,   227,   149,   916,
     106,   314,   145,   209,   152,   178,   178,   266,   178,  1426,
     225,  1002,   180,   958,   165,  1093,   145,   266,    90,   229,
     149,  1134,  1298,   161,  1166,  1344,   249,   250,   839,   840,
     166,  1002,   244,  1175,   300,   186,   165,   229,   266,  1024,
    1025,   247,   931,   205,   266,   257,   152,   259,  1501,   217,
    1240,   796,   266,   204,   803,  1584,   100,   186,   270,   271,
     272,   266,   274,    37,   276,   252,    40,  1024,  1025,   286,
     115,  1600,   117,   100,    45,   204,   183,   184,   319,  1608,
     125,   322,   388,    88,    88,   100,   100,   100,   100,   161,
     145,   122,    28,    29,   663,    31,    32,  1467,    34,    73,
     145,   150,   319,    90,    40,   322,   412,   245,   246,   100,
     248,   161,    48,   168,    50,    51,  1504,   255,   167,   413,
      26,   415,    58,   292,    60,    99,   128,   265,   100,  1100,
    1126,  1020,   301,    69,   178,   139,   145,    73,   148,   277,
     145,     8,   553,   193,   128,   714,  1518,  1519,   175,    55,
     121,  1539,    19,   447,  1430,  1126,  1152,   188,   142,   168,
     377,   148,   379,   178,   178,   178,   178,   384,   104,   105,
     106,   388,   136,   245,   246,   470,   248,   394,   484,  1551,
     217,  1152,   219,   477,   401,  1557,   160,   178,   129,   483,
     192,    20,   145,   265,    90,   412,   490,    40,   492,   493,
     173,   495,  1344,   167,   145,   277,   178,   501,   213,   214,
     106,   150,    89,   262,   187,    58,   152,    60,     8,  1297,
     269,   185,    99,   148,  1220,   161,    69,   521,   167,    19,
     279,   448,   109,  1509,   903,   148,   905,   531,   988,    39,
     535,   536,   119,   538,   539,   540,   541,    93,   115,  1220,
     117,   190,   148,   548,   549,  1240,   550,   193,    46,   126,
     106,  1537,    33,   480,  1249,    53,   148,   484,    39,   564,
     487,   488,   489,    44,   103,  1260,   212,   494,   145,   574,
     575,    52,   951,  1240,   953,   502,   222,   116,    25,   150,
     137,   150,  1249,    64,   863,   864,   110,   129,   515,   868,
     262,   148,   111,  1260,   140,    42,   167,   269,   167,   173,
       8,     9,   141,   145,   627,   628,   145,   279,   254,   148,
    1596,   157,  1598,   187,   138,   115,   543,   117,   897,  1442,
     624,   190,   293,   294,   551,   629,   126,   151,  1614,   168,
     635,   140,   111,   638,   280,   281,   282,   283,   284,    46,
     286,   287,   288,   289,   290,   145,    53,   129,   157,   295,
     296,    90,   851,   630,   256,   145,   633,    93,   148,   636,
     256,   185,    88,   145,    71,   267,   865,   106,     8,     9,
     106,   267,   217,    99,   219,   129,   217,   261,   148,   160,
     134,   222,   163,    90,   268,   129,   145,  1342,    96,   148,
     134,  1346,   148,   697,   710,   114,   177,   713,   293,   294,
     270,   271,   272,   707,   111,   111,   276,   115,   321,   117,
    1405,   120,   121,   326,   213,   214,   215,   146,   114,   148,
     724,   224,   203,   226,   284,   285,   653,   224,   655,   226,
     114,   658,   114,   737,   738,   120,   121,   145,  1405,   743,
     376,   149,   378,   606,   607,   114,    34,   613,   614,   821,
     822,  1251,    40,   680,   681,   682,    96,   165,   615,   616,
      48,   114,    50,  1417,  1418,   769,  1472,   114,  1474,   145,
      58,   114,    60,   114,   701,   115,   703,   117,   186,   114,
     785,    69,   114,   710,   145,    73,   713,   792,   161,   207,
     148,  1472,   217,  1474,   111,   145,   204,   234,   111,   234,
    1455,   235,   148,  1458,     0,   145,   145,   182,  1514,   149,
       3,  1278,   182,  1026,   159,    86,   104,   105,   106,   746,
     193,   242,    43,  1529,   191,   165,    94,   146,    95,    20,
      40,    40,    40,  1514,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,   144,   111,   186,   239,  1529,   222,
    1129,   856,   297,   286,   178,   145,   783,   862,   111,   291,
     291,   277,   277,   790,   204,   145,   111,  1522,   145,   178,
     145,   145,   145,   161,  1389,   178,   148,  1504,   148,   148,
      27,    15,   178,   148,   148,   205,   178,    20,    25,   223,
      65,   111,   819,   820,   821,   822,  1396,  1397,   160,   162,
     100,   162,   223,    88,    88,   193,    88,   280,   281,   282,
     283,   284,   141,   286,   287,   288,   289,   290,    20,   100,
     100,   152,   295,   124,   929,   152,   292,   854,   239,   119,
    1209,   175,   124,   938,   222,   940,   941,   175,    88,   178,
     175,   178,   946,   870,   178,   175,    90,    37,    90,   100,
     175,   134,   957,    88,   178,   178,   178,   175,   145,   178,
     175,   178,   175,   968,   969,   970,   254,   972,   973,   974,
     975,   976,   977,   175,   979,   980,   903,   175,   905,  1479,
    1480,   229,   134,   178,   217,   182,   175,   992,   162,   111,
     917,   111,   280,   281,   282,   283,   284,   111,   286,   287,
     288,   289,   290,   111,   175,   124,   176,   295,   296,   139,
     134,  1016,    88,  1018,  1019,    20,   134,   145,   175,  1023,
     279,   247,   111,    88,   951,   219,   953,   175,   189,   124,
     124,   152,  1532,    90,   292,   134,   111,   175,   145,  1318,
    1045,   111,   139,   124,    93,    93,   175,   145,   175,  1053,
     175,   132,   133,    27,   135,    20,   111,   145,  1063,   175,
     238,   111,   143,    73,   100,   100,   147,   139,   149,   996,
     148,   148,   999,   154,   148,  1002,   139,   253,   251,   278,
     136,   260,    20,    20,    20,   299,  1013,   219,  1015,   170,
     229,   279,  1371,   219,   280,   182,   219,   136,   178,   178,
    1104,   139,   111,   111,    71,   178,  1111,   178,   100,   134,
     178,  1116,   178,   194,   195,   196,   197,   198,   199,     6,
     124,   175,   182,  1128,   225,   225,   229,   134,    99,   225,
     177,    99,   225,  1138,  1139,   178,   178,  1141,   178,   139,
     139,   175,  1147,  1148,   275,   178,    72,   175,    20,    20,
      90,   243,   243,   264,  1158,   175,   162,   118,    90,   175,
     177,    88,   279,   177,   250,   178,   145,   273,    20,   100,
     280,   162,   175,   175,   175,    88,    46,   188,   111,    88,
     178,    20,   100,   111,   177,   217,   111,   175,   111,   258,
    1117,   188,   188,   298,   217,   177,    87,   174,   188,  1126,
    1205,   111,   145,   111,   286,   111,   190,   111,   178,  1136,
     562,  1216,   238,   298,   298,   242,   299,  1144,   280,   662,
     242,   245,   217,  1059,   562,  1152,  1231,   855,   386,  1234,
    1100,  1236,   299,  1509,   406,   299,  1537,   382,  1198,   918,
     476,   285,   915,   999,  1136,  1172,  1312,  1118,  1206,   992,
    1218,  1216,   246,  1144,   587,   515,  1213,  1153,   586,  1149,
     638,   307,  1166,   747,  1557,  1551,  1193,   822,  1094,  1058,
     416,   905,  1193,   416,  1203,  1202,  1249,  1260,  1405,  1206,
    1025,  1253,  1402,  1034,   889,  1083,  1287,  1420,  1250,    -1,
      -1,    -1,    -1,  1220,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1308,    -1,    -1,    -1,    -1,    -1,  1314,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1323,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1331,  1332,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1350,  1351,  1352,  1353,  1354,
      -1,  1356,  1357,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1295,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1383,    -1,
      -1,    -1,  1309,  1310,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1333,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1343,    -1,    -1,    -1,
    1347,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1441,    -1,    -1,    -1,
      -1,  1446,    -1,    -1,    -1,  1450,    -1,  1452,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1489,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1451,    -1,    -1,    -1,    -1,  1456,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1467,    -1,  1547,    -1,    -1,  1472,    -1,  1474,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1569,    -1,    -1,    -1,    -1,  1574,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1505,    -1,
      -1,  1508,    -1,    -1,    -1,    -1,    -1,  1514,  1593,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1525,    -1,
      -1,    -1,  1529,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1541,    -1,    -1,    -1,  1545,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1571,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1588,    -1,  1590,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    10,    -1,    -1,    -1,    -1,  1603,    -1,    17,    18,
    1607,    20,    -1,    -1,    -1,  1612,    25,    26,    -1,    28,
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
     299,   300,   301,   302,   303,     3,    -1,    -1,    -1,    -1,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    -1,
      88,    89,    90,    91,    92,    93,    94,    95,    -1,    -1,
      98,    99,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,    -1,   116,    -1,
     118,   119,   120,   121,    -1,   123,    -1,    -1,    -1,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,    -1,
     138,   139,   140,   141,   142,   143,   144,    -1,    -1,    -1,
     148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,
     158,   159,   160,   161,   162,   163,   164,   165,    -1,   167,
     168,    -1,    -1,   171,   172,   173,    -1,    -1,    -1,   177,
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
      95,    -1,    -1,    98,    99,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
      -1,   116,    -1,   118,   119,   120,   121,    -1,   123,    -1,
      -1,    -1,   127,   128,   129,   130,   131,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,   148,   149,   150,   151,   152,    -1,    -1,
      -1,    -1,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,   167,   168,    -1,    -1,   171,   172,   173,    -1,
      -1,    -1,   177,   178,   179,   180,   181,    -1,   183,   184,
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
      92,    93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,
      -1,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,    -1,    -1,   116,    -1,   118,   119,   120,   121,
      -1,   123,    -1,    -1,    -1,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,
     142,   143,   144,    -1,    -1,    -1,   148,   149,   150,   151,
     152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,
     162,   163,   164,   165,    -1,   167,   168,    -1,    -1,   171,
     172,   173,    -1,   175,    -1,   177,    -1,   179,   180,   181,
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
      89,    90,    91,    92,    93,    94,    95,    -1,    -1,    98,
      99,    -1,    -1,    -1,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,    -1,    -1,   116,    -1,   118,
     119,   120,   121,    -1,   123,    -1,    -1,    -1,   127,   128,
     129,   130,   131,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,   167,   168,
      -1,    -1,   171,   172,   173,    -1,    -1,    -1,   177,   178,
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
      -1,    -1,    98,    99,    -1,    -1,    -1,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,    -1,    -1,
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
      93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,    -1,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    -1,    -1,   116,    -1,   118,   119,   120,   121,    -1,
     123,    -1,    -1,    -1,   127,   128,   129,   130,   131,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,   148,   149,   150,   151,   152,
      -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,   167,   168,    -1,    -1,   171,   172,
     173,    -1,   175,    -1,   177,    -1,   179,   180,   181,    -1,
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
      90,    91,    92,    93,    94,    95,    -1,    -1,    98,    99,
      -1,    -1,    -1,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,    -1,    -1,   116,    -1,   118,   119,
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
      -1,    88,    89,    90,    91,    92,    93,    94,    95,    -1,
      -1,    98,    99,    -1,    -1,    -1,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,    -1,   116,
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
      94,    95,    -1,    -1,    98,    99,    -1,    -1,    -1,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
      -1,    -1,   116,    -1,   118,   119,   120,   121,    -1,   123,
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
      91,    92,    93,    94,    95,    -1,    -1,    98,    99,    -1,
      -1,    -1,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,    -1,    -1,   116,    -1,   118,   119,   120,
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
      88,    89,    90,    91,    92,    93,    94,    95,    -1,    -1,
      98,    99,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,    -1,   116,    -1,
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
      95,    -1,    -1,    98,    99,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
      -1,   116,    -1,   118,   119,   120,   121,    -1,   123,    -1,
      -1,    -1,   127,   128,   129,   130,   131,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,   148,   149,   150,   151,   152,    -1,    -1,
      -1,    -1,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,   167,   168,    -1,    -1,   171,   172,   173,    -1,
      -1,    -1,   177,    -1,   179,   180,   181,    -1,   183,   184,
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
      92,    93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,
      -1,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,    -1,    -1,   116,    -1,   118,   119,   120,   121,
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
      89,    90,    91,    92,    93,    94,    95,    -1,    -1,    98,
      99,    -1,    -1,    -1,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,    -1,    -1,   116,    -1,   118,
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
      -1,    -1,    98,    99,    -1,    -1,    -1,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,    -1,    -1,
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
      93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,    -1,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    -1,    -1,   116,    -1,   118,   119,   120,   121,    -1,
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
      60,    61,    62,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    -1,    88,    89,
      90,    91,    92,    93,    94,    95,    -1,    -1,    98,    99,
      -1,    -1,    -1,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,    -1,    -1,   116,    -1,   118,   119,
     120,   121,    -1,   123,    -1,    -1,    -1,   127,   128,   129,
     130,   131,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,
     140,   141,   142,   143,   144,    -1,    -1,    -1,   148,   149,
      -1,   151,   152,    -1,    -1,    -1,    -1,   157,   158,   159,
     160,   161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,
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
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    88,    89,    90,    91,    92,    93,    94,    95,    -1,
      -1,    98,    99,    -1,    -1,    -1,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,    -1,   116,
      -1,   118,   119,   120,   121,    -1,   123,    -1,    -1,    -1,
     127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,   148,   149,    -1,   151,   152,    -1,    -1,    -1,    -1,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
      -1,    -1,    -1,    -1,   171,   172,   173,    -1,    -1,    -1,
     177,    -1,   179,   180,   181,    -1,    -1,    -1,   185,    -1,
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
      -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    -1,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    88,    89,    90,    91,    -1,    93,
      94,    95,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,
     104,   105,   106,   107,   108,   109,   110,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   118,   119,   120,   121,    -1,   123,
      -1,    -1,    -1,   127,   128,   129,   130,   131,    -1,    -1,
      -1,    -1,    -1,    -1,   138,   139,   140,    -1,   142,   143,
     144,    -1,    -1,    -1,    -1,    -1,    -1,   151,   152,    -1,
      -1,    -1,    -1,   157,   158,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,    -1,    -1,    -1,   171,   172,   173,
      -1,    -1,    -1,   177,    -1,   179,   180,   181,    -1,    -1,
      -1,   185,    -1,   187,    -1,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,    -1,    -1,   202,   203,
      -1,    -1,   206,   207,    -1,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,    -1,   252,   253,
     254,    -1,   256,   257,   258,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,    10,
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
     171,   172,   173,    -1,    -1,    -1,   177,    -1,   179,    -1,
     181,    -1,    -1,    -1,   185,    -1,   187,    -1,   189,   190,
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
     301,   302,    14,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    -1,    88,    89,    90,    91,
      -1,    93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,
      -1,    -1,   104,   105,   106,   107,   108,   109,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,   121,
      -1,   123,    -1,    -1,    -1,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,    -1,
     142,   143,   144,   145,    -1,    -1,   148,    -1,    -1,   151,
     152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,   171,
     172,   173,    -1,    -1,    -1,   177,    -1,   179,    -1,   181,
      -1,    -1,    -1,    -1,    -1,   187,    -1,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,    -1,    -1,
     202,   203,    -1,    -1,   206,   207,    -1,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
     252,   253,   254,    -1,   256,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,    14,    -1,    -1,    -1,    18,    -1,    20,    -1,    -1,
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
     173,    -1,    -1,    -1,   177,   178,   179,    -1,   181,    -1,
      -1,    -1,    -1,    -1,   187,    -1,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,    -1,    -1,   202,
     203,    -1,    -1,   206,   207,    -1,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,    -1,   252,
     253,   254,    -1,   256,   257,   258,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
      14,    -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    -1,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    88,    89,    90,    91,    -1,    93,
      94,    95,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,
     104,   105,   106,   107,   108,   109,   110,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   118,   119,   120,   121,    -1,   123,
      -1,    -1,    -1,   127,   128,   129,   130,   131,    -1,    -1,
      -1,    -1,    -1,    -1,   138,   139,   140,    -1,   142,   143,
     144,    -1,    -1,    -1,    -1,    -1,    -1,   151,   152,    -1,
      -1,    -1,    -1,   157,   158,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,    -1,    -1,    -1,   171,   172,   173,
      -1,    -1,    -1,   177,    -1,   179,    -1,   181,    -1,    -1,
      -1,    -1,    -1,   187,    -1,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,    -1,    -1,   202,   203,
      -1,    -1,   206,   207,    -1,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,    -1,   252,   253,
     254,    -1,   256,   257,   258,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,    16,
      -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
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
      -1,    -1,    -1,    -1,   151,   152,    -1,    -1,    -1,    -1,
     157,   158,   159,   160,   161,   162,   163,   164,    -1,    -1,
      -1,    -1,    -1,    -1,   171,   172,   173,    -1,    -1,    -1,
     177,    -1,   179,    -1,   181,    -1,    -1,    -1,    -1,    -1,
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
     297,   298,   299,   300,   301,   302,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    -1,    88,    89,    90,    91,
      -1,    93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,
      -1,    -1,   104,   105,   106,   107,   108,   109,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,   121,
      -1,   123,    -1,    -1,    -1,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,    -1,
     142,   143,   144,    -1,    -1,    -1,   148,    -1,    -1,   151,
     152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,   171,
     172,   173,    -1,    -1,    -1,   177,   178,   179,   180,   181,
      -1,    -1,    -1,   185,    -1,   187,    -1,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,    -1,    -1,
     202,   203,    -1,    -1,   206,   207,    -1,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
     252,   253,   254,    -1,   256,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    88,    89,    90,    91,    -1,    93,    94,    95,    -1,
      -1,    98,    99,    -1,    -1,    -1,    -1,   104,   105,   106,
     107,   108,   109,   110,    -1,    -1,    -1,   114,    -1,    -1,
      -1,   118,   119,   120,   121,    -1,   123,    -1,    -1,    -1,
     127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,    -1,   142,   143,   144,   145,    -1,
      -1,   148,    -1,    -1,   151,   152,    -1,    -1,    -1,    -1,
     157,   158,   159,   160,   161,   162,   163,   164,    -1,    -1,
      -1,    -1,    -1,    -1,   171,   172,   173,    -1,    -1,    -1,
     177,    -1,   179,    -1,   181,    -1,    -1,    -1,    -1,    -1,
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
     297,   298,   299,   300,   301,   302,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    -1,    88,    89,    90,    91,
      -1,    93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,
      -1,    -1,   104,   105,   106,   107,   108,   109,   110,   111,
      -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,   121,
      -1,   123,    -1,    -1,    -1,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,    -1,
     142,   143,   144,    -1,    -1,    -1,   148,    -1,    -1,   151,
     152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,   171,
     172,   173,    -1,    -1,    -1,   177,    -1,   179,   180,   181,
      -1,    -1,    -1,    -1,    -1,   187,    -1,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,    -1,    -1,
     202,   203,    -1,    -1,   206,   207,    -1,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
     252,   253,   254,    -1,   256,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
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
     177,    -1,   179,    -1,   181,    -1,    -1,    -1,    -1,    -1,
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
     297,   298,   299,   300,   301,   302,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    -1,    88,    89,    90,    91,
      -1,    93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,
      -1,    -1,   104,   105,   106,   107,   108,   109,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,   121,
      -1,   123,    -1,    -1,    -1,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,    -1,
     142,   143,   144,    -1,    -1,    -1,    -1,    -1,    -1,   151,
     152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,   171,
     172,   173,    -1,    -1,    -1,   177,   178,   179,    -1,   181,
      -1,    -1,    -1,   185,    -1,   187,    -1,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,    -1,    -1,
     202,   203,    -1,    -1,   206,   207,    -1,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
     252,   253,   254,    -1,   256,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
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
      -1,    -1,    -1,    -1,   151,   152,    -1,    -1,    -1,    -1,
     157,   158,   159,   160,   161,   162,   163,   164,    -1,    -1,
      -1,    -1,    -1,    -1,   171,   172,   173,    -1,    -1,    -1,
     177,   178,   179,    -1,   181,    -1,    -1,    -1,   185,    -1,
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
     297,   298,   299,   300,   301,   302,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    -1,    88,    89,    90,    91,
      -1,    93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,
      -1,    -1,   104,   105,   106,   107,   108,   109,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,   121,
      -1,   123,    -1,    -1,    -1,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,    -1,
     142,   143,   144,    -1,    -1,    -1,   148,    -1,    -1,   151,
     152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,   171,
     172,   173,    -1,    -1,    -1,   177,    -1,   179,   180,   181,
      -1,    -1,    -1,    -1,    -1,   187,    -1,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,    -1,    -1,
     202,   203,    -1,    -1,   206,   207,    -1,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
     252,   253,   254,    -1,   256,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
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
     177,    -1,   179,   180,   181,    -1,    -1,    -1,    -1,    -1,
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
     297,   298,   299,   300,   301,   302,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    -1,    88,    89,    90,    91,
      -1,    93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,
      -1,    -1,   104,   105,   106,   107,   108,   109,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,   121,
      -1,   123,    -1,    -1,    -1,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,    -1,
     142,   143,   144,    -1,    -1,    -1,    -1,    -1,    -1,   151,
     152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,   171,
     172,   173,    -1,    -1,    -1,   177,    -1,   179,    -1,   181,
      -1,    -1,    -1,    -1,    -1,   187,    -1,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,    -1,    -1,
     202,   203,    -1,    -1,   206,   207,    -1,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
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
     329,   330,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   349,   350,   355,   358,   361,
     364,   365,   367,   372,   373,   374,   375,   376,   385,   386,
     388,   389,   390,   395,   397,   399,   400,   401,   406,   427,
     430,   434,   437,   438,   439,   440,   442,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   488,   489,   490,   504,
     505,   507,   508,   509,   510,   511,   512,   513,   521,   522,
     523,   524,   525,   526,   527,   528,   529,   530,   533,   534,
     535,   536,   541,   542,   543,   544,   545,   546,   549,   555,
     609,   610,    28,    29,    31,    32,    34,    40,    48,    50,
      51,    58,    60,    69,    73,   104,   105,   106,   152,   161,
     193,   212,   222,   254,   280,   281,   282,   283,   284,   286,
     287,   288,   289,   290,   295,   296,   356,   357,   377,   378,
     379,   380,   152,   145,   148,   145,   148,    25,    26,    30,
      35,    36,    37,    38,    39,    40,    41,    42,    44,    52,
      54,    57,    59,    62,    65,    67,    68,    70,    84,    85,
      91,    98,   107,   108,   127,   130,   131,   145,   148,   161,
     164,   171,   172,   181,   193,   206,   216,   217,   218,   220,
     221,   228,   230,   231,   232,   233,   236,   237,   239,   609,
     145,    61,    66,   111,   392,   148,   366,   148,    26,    55,
     111,    39,    14,   145,   148,   554,   609,   148,   111,   111,
     145,   148,   148,   148,    88,   145,   213,   214,   114,   114,
     114,   145,   148,   609,    30,    37,    54,    65,    91,   472,
     609,   114,   114,   114,   609,   111,   114,   114,   178,   386,
     609,   145,   114,   554,    16,   609,   114,   114,   609,   114,
     464,   145,    21,   205,   207,   217,   219,   148,   217,   219,
     217,   217,   222,   111,   145,   368,   234,   234,   235,   148,
     145,   111,   319,   320,     0,   319,   322,   323,    25,    42,
     325,   385,   182,   182,   100,   182,   387,    33,    39,    44,
      52,    64,   160,   163,   177,   203,   391,   396,   397,   398,
     415,   416,   420,   402,   403,   609,   159,    86,   124,   132,
     133,   135,   143,   147,   149,   154,   170,   194,   195,   196,
     197,   198,   199,   456,   457,   242,   150,   167,   190,   110,
     138,   151,   185,   192,   201,   128,   142,    43,   191,    94,
      95,   150,   167,   455,   145,   461,   464,   183,   184,   146,
     476,   477,   472,   476,   472,   148,   476,   137,   148,    20,
     553,   173,   187,   173,   187,   158,   173,   377,   609,   377,
     609,   161,   193,    40,   378,    40,   609,   144,   111,   354,
      37,    40,    73,    99,   160,   554,   213,   214,   215,   293,
     294,   239,   582,   609,   286,   609,   291,   291,   293,   294,
     297,   280,   288,   357,   554,   386,   178,   386,    37,    57,
     178,   529,   530,   386,   178,   185,   609,   145,   389,   277,
     277,   111,   410,   111,   178,   381,   382,   145,   383,   386,
     152,   553,   106,   152,   348,   553,   407,   409,   609,   111,
     386,    20,   178,   554,   145,   609,   609,   428,   429,   609,
     386,   178,   386,   386,   531,   609,   386,   145,   145,   386,
     178,   185,   609,   145,   428,   178,    27,   492,   493,   494,
     386,     7,   166,    15,   178,   386,   205,    20,   389,   389,
     178,   389,   389,   389,   389,   223,   547,   548,   609,   369,
     389,   389,   386,   408,   414,   609,   319,   327,   328,    25,
     329,   389,   388,   111,   160,   162,   162,   389,   389,   100,
      88,    90,   139,   266,   404,   405,   515,   439,   440,   442,
     442,   442,   442,   441,   442,   442,   442,    65,   446,   446,
     445,   447,   447,   447,   447,   448,   448,   449,   449,   223,
      88,    88,    88,   175,   386,   464,   464,   386,   477,   178,
     389,   487,   141,   178,   487,   100,   100,   366,    20,   609,
     609,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,   331,   332,   333,    88,   129,   134,   351,   352,   353,
     609,   129,   134,   152,   152,   331,   553,   119,   124,    47,
      50,    93,   244,   257,   259,   270,   271,   272,   274,   276,
     583,   584,   585,   586,   587,   588,   595,   601,   602,   239,
      88,   229,   360,   292,   609,   609,   609,   124,   175,   175,
     178,   178,   175,   100,   178,   100,   178,   175,   386,   175,
     609,    49,   209,   247,   393,   394,   609,    88,   100,   178,
     386,   178,   554,    90,    37,   554,   553,    90,   100,   134,
     405,   515,   175,   178,   178,   175,   386,   178,   134,   100,
     179,   139,   515,   175,   178,   178,   145,   175,   386,   386,
     175,   100,   178,   100,   178,   175,   386,   179,   609,   493,
     494,   122,   188,   175,   175,   123,   182,    88,   210,   211,
     225,    88,   210,   211,   225,    88,   229,   217,   100,   227,
     134,    25,   370,   386,   178,   175,    38,   100,   182,   106,
     182,   609,   162,   389,   421,   422,   111,   417,   418,   111,
      40,   144,   148,   202,   516,   518,   520,   521,   537,   538,
     539,   540,   609,   111,   389,   111,   139,   405,   139,   139,
     404,   405,   442,   145,   148,   252,   460,   479,   556,   559,
     560,   561,   562,   563,   567,   569,   571,   572,   516,   516,
     514,   520,   514,   175,   176,   100,   178,   178,   140,   157,
     140,   157,   129,   145,   384,   366,   366,   332,   124,   518,
     353,   389,   515,   134,   389,   553,   553,   120,   121,   553,
     270,   271,   272,   276,   609,   256,   267,   256,   267,    20,
     279,    90,   106,   148,   589,   592,   583,    30,    36,    54,
      65,    91,   217,   359,   521,   284,   285,   219,   292,   301,
      88,   360,   292,   553,   145,   531,   532,   609,   531,   532,
     175,   139,   515,   247,    46,    53,    71,   111,   404,   411,
     412,   413,   394,   515,   516,   382,    88,   175,   189,   124,
     347,   553,   152,   124,    90,   347,   111,   389,   134,   134,
     405,   145,   175,   389,   111,   389,   389,   139,    93,   431,
     432,   433,    93,   435,   436,   386,   175,   175,   145,   531,
     531,   175,   389,    27,   494,   122,   188,     8,     9,    96,
     115,   117,   186,   383,   489,   491,   502,   503,   506,    20,
     224,   226,   389,   389,   389,   224,   226,   389,   389,   389,
     389,   389,   389,   111,   389,   389,   354,   371,   100,   182,
     175,   368,   238,   550,   551,   145,   111,   421,    89,    99,
     109,   119,   423,   424,   425,   426,   100,   609,   100,   403,
     148,   148,   518,   148,   136,   167,   185,   517,   609,   609,
     389,   139,   389,   389,   139,   405,   139,   386,   556,   563,
     145,   278,   443,   608,    90,   161,   245,   246,   248,   255,
     265,   277,   557,   558,   577,   578,   579,   580,   603,   606,
     251,   253,   564,   582,   260,   568,   604,   240,   241,   263,
     573,   574,   136,   389,   386,   129,   368,   129,   145,   533,
     352,   389,   279,    20,    90,   106,   148,   596,    20,   589,
     360,   517,   219,   219,   462,   280,   299,   359,   219,   182,
     175,   386,   178,   178,   136,   178,   178,   389,   139,   111,
     111,   389,   609,   413,    71,   516,   389,   553,   100,   347,
     409,   389,   389,   134,   175,   386,   429,   389,   389,   106,
     432,    93,   177,   111,   516,   106,   436,   175,   175,   386,
     178,   178,   124,   186,   491,     6,   609,   186,   502,   182,
     225,   225,   225,   225,   229,   548,   177,   134,   371,   473,
     552,   551,   389,   414,   553,   120,   121,   425,   426,   426,
     422,    99,   419,   418,   178,   185,   516,   519,   178,   178,
     178,   389,   389,   139,   389,   175,   178,   556,   570,   243,
     209,   247,   261,   268,   607,    90,   249,   250,   605,   243,
     560,   607,   445,   577,   561,   139,   275,   565,   566,   605,
     279,   576,    72,   575,   175,   388,    20,   128,   192,   598,
     599,   600,    20,   597,   598,   264,   593,   590,   591,   592,
     162,   609,   250,   360,   462,   175,   389,   609,   609,   412,
     389,   118,    90,   553,   389,   175,   177,   389,   389,   609,
     177,   111,   177,   175,   494,   609,   186,   494,   609,   389,
     389,   389,   389,   389,   389,   389,   148,   201,   384,   175,
     426,   553,    88,   178,   100,   178,   389,   175,   447,    45,
     121,   445,   445,   262,   269,   279,   581,   581,   562,   145,
     273,   175,   596,   596,   600,   100,   178,    20,   594,   605,
     178,   100,   362,   363,   462,   111,   217,   300,   280,   162,
      46,   389,   347,   389,    88,   389,   609,   389,    87,   174,
     495,   494,   609,   188,   494,   111,   473,   516,   516,    88,
     445,   445,   190,   386,    20,   258,   592,   100,   426,   515,
     609,   111,   217,   609,   362,   111,   516,   177,     4,   125,
     498,   499,   501,   503,    19,   126,   496,   497,   500,   503,
     188,   494,   188,   609,   516,   445,   175,   363,   426,   298,
     609,   111,   217,   609,   177,   389,    87,   125,   501,   174,
     126,   500,   188,   100,   178,   389,   298,   609,   111,   389,
     111,   384,   286,   298,   609,   609,   299,   389,   299,   100,
     178,   462,   462,   111,   384,   190,   609,   280,   178,   609,
     384,   217,   111,   609,   299,   462
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
     320,   320,   320,   321,   321,   322,   322,   323,   323,   324,
     325,   325,   325,   326,   326,   327,   327,   328,   328,   328,
     328,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     330,   330,   331,   331,   332,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   334,   334,   334,   334,   334,
     334,   334,   334,   335,   335,   336,   337,   337,   338,   338,
     339,   340,   341,   341,   342,   342,   343,   343,   343,   343,
     344,   345,   346,   346,   346,   346,   347,   347,   348,   348,
     349,   349,   349,   349,   350,   351,   351,   352,   352,   352,
     353,   354,   354,   355,   355,   355,   356,   356,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   358,   358,   358,   358,   358,   358,   358,   358,
     359,   359,   360,   360,   361,   361,   362,   362,   363,   363,
     363,   363,   364,   364,   364,   364,   365,   365,   366,   366,
     366,   366,   367,   368,   369,   369,   370,   370,   371,   371,
     372,   373,   374,   375,   375,   376,   376,   376,   377,   377,
     377,   377,   378,   378,   379,   379,   380,   380,   381,   381,
     382,   382,   383,   384,   385,   386,   386,   387,   387,   388,
     388,   389,   389,   389,   389,   389,   389,   389,   389,   389,
     389,   389,   389,   389,   389,   389,   389,   389,   389,   390,
     391,   392,   392,   393,   393,   393,   394,   394,   395,   395,
     396,   397,   397,   397,   398,   398,   398,   398,   398,   399,
     399,   400,   400,   401,   402,   402,   403,   403,   403,   403,
     403,   403,   403,   403,   404,   405,   406,   407,   407,   408,
     408,   409,   409,   409,   409,   410,   410,   411,   411,   411,
     412,   412,   412,   413,   413,   413,   414,   415,   416,   417,
     417,   418,   418,   419,   420,   420,   421,   421,   422,   422,
     423,   423,   423,   423,   423,   423,   423,   424,   424,   425,
     425,   426,   427,   427,   428,   428,   429,   429,   430,   431,
     431,   432,   433,   433,   434,   434,   435,   435,   436,   436,
     437,   438,   438,   439,   439,   440,   440,   440,   440,   440,
     441,   440,   440,   440,   440,   442,   442,   443,   443,   444,
     444,   445,   445,   445,   446,   446,   446,   446,   446,   447,
     447,   447,   448,   448,   448,   449,   449,   450,   450,   451,
     451,   452,   452,   453,   453,   454,   454,   454,   454,   455,
     455,   455,   456,   456,   456,   456,   456,   456,   457,   457,
     457,   458,   458,   458,   458,   459,   459,   460,   460,   461,
     461,   462,   462,   462,   462,   463,   464,   464,   464,   465,
     465,   466,   466,   466,   466,   467,   467,   468,   468,   468,
     468,   468,   468,   468,   469,   469,   470,   470,   471,   471,
     471,   471,   471,   472,   472,   473,   473,   474,   474,   474,
     475,   475,   475,   475,   476,   476,   477,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   479,   479,   480,   480,
     480,   481,   482,   482,   483,   484,   485,   486,   486,   487,
     487,   488,   488,   489,   489,   489,   490,   490,   490,   490,
     490,   490,   491,   491,   492,   492,   493,   494,   494,   495,
     495,   496,   496,   497,   497,   497,   497,   498,   498,   499,
     499,   499,   499,   500,   500,   501,   501,   502,   502,   502,
     502,   503,   503,   503,   503,   504,   504,   505,   505,   506,
     507,   507,   507,   507,   507,   507,   508,   509,   509,   509,
     509,   510,   510,   510,   510,   511,   512,   513,   513,   513,
     513,   514,   514,   515,   516,   516,   516,   517,   517,   517,
     518,   518,   518,   518,   518,   519,   519,   520,   521,   521,
     521,   521,   521,   521,   521,   521,   521,   522,   523,   523,
     523,   524,   525,   526,   526,   526,   527,   527,   527,   527,
     527,   528,   529,   529,   529,   529,   529,   529,   529,   530,
     531,   532,   533,   534,   534,   535,   536,   537,   537,   538,
     539,   539,   540,   541,   541,   541,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   543,   543,   544,   544,
     545,   546,   547,   547,   548,   549,   550,   550,   551,   551,
     551,   551,   552,   552,   553,   554,   554,   555,   555,   556,
     557,   557,   558,   558,   559,   559,   560,   560,   561,   561,
     562,   562,   563,   564,   564,   565,   565,   566,   567,   567,
     567,   568,   568,   569,   570,   570,   571,   572,   572,   573,
     573,   574,   574,   574,   575,   575,   576,   576,   577,   577,
     577,   577,   577,   578,   579,   580,   581,   581,   581,   582,
     582,   583,   583,   583,   583,   583,   583,   583,   583,   584,
     584,   584,   584,   585,   585,   586,   587,   587,   588,   588,
     588,   589,   589,   590,   590,   591,   591,   592,   593,   593,
     594,   594,   595,   595,   595,   596,   596,   597,   597,   598,
     598,   599,   599,   600,   600,   601,   602,   602,   603,   603,
     603,   604,   605,   605,   605,   605,   606,   606,   607,   607,
     608,   609,   609,   610,   610,   610,   610,   610,   610,   610,
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
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610
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
       6,     3,     3,     4,     6,     6,     4,     6,     6,     4,
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
  "\"'satisfies'\"", "\"'<schema attribute ('\"", "\"'self'\"", "\"';'\"",
  "\"'/'\"", "\"'//'\"", "\"'*'\"", "\"</ (start tag end)\"",
  "\"'strip'\"", "\"'> (tag end)'\"", "\"'then'\"", "\"'to'\"",
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
       318,     0,    -1,   320,    -1,   303,   320,    -1,   319,    -1,
     320,   319,    -1,   303,   319,    -1,   303,   320,   319,    -1,
       3,    -1,   322,    -1,   321,   322,    -1,   323,    -1,   321,
     323,    -1,   206,   207,    20,   182,    -1,   206,   207,    20,
     123,    20,   182,    -1,   325,   385,    -1,   385,    -1,   324,
      -1,   324,   325,    -1,    26,   152,   554,   124,   553,   182,
      -1,   326,   182,    -1,   327,   182,    -1,   326,   182,   327,
     182,    -1,   328,    -1,   326,   182,   328,    -1,   329,    -1,
     327,   182,   329,    -1,   334,    -1,   335,    -1,   336,    -1,
     338,    -1,   355,    -1,   358,    -1,   350,    -1,   330,    -1,
     340,    -1,   376,    -1,   361,    -1,   364,    -1,   339,    -1,
      25,   106,    73,   331,    -1,    25,    73,   609,   331,    -1,
     332,    -1,   331,   332,    -1,   333,   124,   533,    -1,    74,
      -1,    82,    -1,    75,    -1,    76,    -1,    77,    -1,    78,
      -1,    83,    -1,    79,    -1,    80,    -1,    81,    -1,   337,
      -1,   344,    -1,   345,    -1,   365,    -1,   341,    -1,   342,
      -1,   343,    -1,   541,    -1,   346,    -1,   349,    -1,    25,
     152,   554,   124,   553,    -1,    25,    29,   173,    -1,    25,
      29,   187,    -1,    25,   106,    37,   152,   553,    -1,    25,
     106,    40,   152,   553,    -1,    25,    50,   609,    20,    -1,
      25,   254,   582,    -1,    25,    51,   161,    -1,    25,    51,
     193,    -1,    25,   106,   160,   119,   120,    -1,    25,   106,
     160,   119,   121,    -1,    25,    32,   173,   100,   140,    -1,
      25,    32,   173,   100,   157,    -1,    25,    32,   158,   100,
     140,    -1,    25,    32,   158,   100,   157,    -1,    25,   106,
      99,   553,    -1,    25,    28,   553,    -1,    42,    55,   553,
      -1,    42,    55,   348,   553,    -1,    42,    55,   553,    90,
     347,    -1,    42,    55,   348,   553,    90,   347,    -1,   553,
      -1,   347,   100,   553,    -1,   152,   554,   124,    -1,   106,
      37,   152,    -1,    42,    26,   553,    -1,    42,    26,   152,
     554,   124,   553,    -1,    42,    26,   553,    90,   347,    -1,
      42,    26,   152,   554,   124,   553,    90,   347,    -1,    25,
     104,   144,   351,    -1,    88,   518,   352,    -1,   352,    -1,
     353,    -1,   129,    -1,   129,   353,    -1,   134,   389,    -1,
     111,   609,    -1,   111,   609,   515,    -1,    25,   105,   354,
     134,   389,    -1,    25,   105,   354,   129,    -1,    25,   105,
     354,   129,   134,   389,    -1,   357,    -1,   356,   357,    -1,
     281,    -1,   282,    -1,   283,    -1,   284,    -1,   161,    -1,
     193,    -1,   222,   294,    -1,   222,   293,    -1,   295,   294,
      -1,   295,   293,    -1,   286,    -1,   287,   286,    -1,   290,
     291,    -1,   289,   291,    -1,    25,   280,   609,    -1,    25,
     280,   609,   360,    -1,    25,   280,   609,    88,   359,    -1,
      25,   280,   609,    88,   359,   360,    -1,    25,   356,   280,
     609,    -1,    25,   356,   280,   609,   360,    -1,    25,   356,
     280,   609,    88,   359,    -1,    25,   356,   280,   609,    88,
     359,   360,    -1,   521,    -1,   521,   517,    -1,   229,   285,
     219,    -1,   229,   284,   219,    -1,    25,   288,   609,   292,
     219,   462,   162,   362,    -1,    25,   356,   288,   609,   292,
     219,   462,   162,   362,    -1,   363,    -1,   362,   100,   363,
      -1,   462,    -1,   462,   515,    -1,   462,   426,    -1,   462,
     515,   426,    -1,    25,   296,   297,   609,   292,   280,   609,
     111,   609,   298,   389,    -1,    25,   296,   297,   609,   292,
     280,   609,   217,   111,   609,   298,   286,   299,   462,    -1,
      25,   296,   297,   609,   292,   280,   609,   300,   217,   111,
     609,   298,   389,    -1,    25,   296,   297,   609,   301,   299,
     250,   280,   609,   217,   111,   609,   299,   462,   190,   280,
     609,   217,   111,   609,   299,   462,    -1,    25,    31,   173,
      -1,    25,    31,   187,    -1,   148,   178,    -1,   148,   381,
     178,    -1,   148,   178,    88,   516,    -1,   148,   381,   178,
      88,   516,    -1,   230,   368,    -1,   145,   369,   386,   175,
      -1,   369,   370,   182,    -1,    -1,   370,   100,   371,    -1,
      25,   371,    -1,   354,    -1,   354,   134,   389,    -1,    59,
     111,   609,   134,   389,    -1,   233,   235,   389,    -1,   236,
     148,   389,   178,   368,    -1,   231,   234,    -1,   232,   234,
      -1,    25,   377,    -1,    25,    48,   377,    -1,    25,    34,
     377,    -1,   378,    -1,    60,   378,    -1,   380,    -1,   379,
      -1,    40,   609,   366,   384,    -1,    40,   609,   366,   129,
      -1,    58,    40,   609,   366,   368,    -1,    58,    40,   609,
     366,   129,    -1,    69,    40,   609,   366,   145,   388,   175,
      -1,    69,    40,   609,   366,   129,    -1,   382,    -1,   381,
     100,   382,    -1,   111,   609,    -1,   111,   609,   515,    -1,
     145,   386,   175,    -1,   145,   386,   175,    -1,   386,    -1,
     388,    -1,   388,   387,    -1,   182,    -1,   387,   388,   182,
      -1,   389,    -1,   388,   100,   389,    -1,   390,    -1,   427,
      -1,   430,    -1,   434,    -1,   437,    -1,   438,    -1,   542,
      -1,   543,    -1,   545,    -1,   544,    -1,   546,    -1,   549,
      -1,   555,    -1,   373,    -1,   374,    -1,   375,    -1,   372,
      -1,   367,    -1,   399,   391,    -1,   177,   389,    -1,    61,
     277,    -1,    66,   277,    -1,   209,    -1,   247,    -1,    49,
     247,    -1,   393,   411,    71,   389,    -1,   393,    71,   389,
      -1,    39,   392,   410,   394,   394,    -1,    39,   392,   410,
     394,    -1,    33,   111,   609,    -1,   401,    -1,   406,    -1,
     395,    -1,   397,    -1,   415,    -1,   420,    -1,   416,    -1,
     396,    -1,   397,    -1,   399,   398,    -1,    39,   111,    -1,
      52,    39,   111,    -1,   400,   402,    -1,   403,    -1,   402,
     100,   111,   403,    -1,   609,   139,   389,    -1,   609,   515,
     139,   389,    -1,   609,   404,   139,   389,    -1,   609,   515,
     404,   139,   389,    -1,   609,   405,   139,   389,    -1,   609,
     515,   405,   139,   389,    -1,   609,   404,   405,   139,   389,
      -1,   609,   515,   404,   405,   139,   389,    -1,    90,   111,
     609,    -1,   266,   111,   609,    -1,    44,   111,   407,    -1,
     409,    -1,   407,   100,   111,   409,    -1,   414,    -1,   408,
     100,   111,   414,    -1,   609,   134,   389,    -1,   609,   515,
     134,   389,    -1,   609,   405,   134,   389,    -1,   609,   515,
     405,   134,   389,    -1,   111,   609,   139,   389,    -1,   111,
     609,   515,   139,   389,    -1,   412,    -1,   111,   609,    -1,
     111,   609,   412,    -1,   404,    -1,   404,   413,    -1,   413,
      -1,    53,   111,   609,    46,   111,   609,    -1,    46,   111,
     609,    -1,    53,   111,   609,    -1,   609,    -1,   203,   389,
      -1,   163,   162,   417,    -1,   418,    -1,   417,   100,   418,
      -1,   111,   609,    -1,   111,   609,   419,    -1,    99,   553,
      -1,   160,   162,   421,    -1,    64,   160,   162,   421,    -1,
     422,    -1,   421,   100,   422,    -1,   389,    -1,   389,   423,
      -1,   424,    -1,   425,    -1,   426,    -1,   424,   425,    -1,
     424,   426,    -1,   425,   426,    -1,   424,   425,   426,    -1,
      89,    -1,   109,    -1,   119,   120,    -1,   119,   121,    -1,
      99,   553,    -1,    62,   111,   428,   179,   389,    -1,   127,
     111,   428,   179,   389,    -1,   429,    -1,   428,   100,   111,
     429,    -1,   609,   139,   389,    -1,   609,   515,   139,   389,
      -1,    67,   148,   386,   178,   431,   106,   177,   389,    -1,
     432,    -1,   431,   432,    -1,   433,   177,   389,    -1,    93,
     389,    -1,   433,    93,   389,    -1,    68,   148,   386,   178,
     435,   106,   177,   389,    -1,    68,   148,   386,   178,   435,
     106,   111,   609,   177,   389,    -1,   436,    -1,   435,   436,
      -1,    93,   516,   177,   389,    -1,    93,   111,   609,    88,
     516,   177,   389,    -1,    41,   148,   386,   178,   189,   389,
     118,   389,    -1,   439,    -1,   438,   159,   439,    -1,   440,
      -1,   439,    86,   440,    -1,   442,    -1,   442,   456,   442,
      -1,   442,   457,   442,    -1,   442,   124,   442,    -1,   442,
     154,   442,    -1,    -1,   442,   149,   441,   442,    -1,   442,
     147,   442,    -1,   442,   135,   442,    -1,   442,   133,   442,
      -1,   444,    -1,   444,   242,    65,   556,   443,    -1,    -1,
     608,    -1,   445,    -1,   445,   190,   445,    -1,   446,    -1,
     445,   167,   446,    -1,   445,   150,   446,    -1,   447,    -1,
     446,   185,   447,    -1,   446,   110,   447,    -1,   446,   138,
     447,    -1,   446,   151,   447,    -1,   448,    -1,   447,   192,
     448,    -1,   447,   201,   448,    -1,   449,    -1,   448,   142,
     449,    -1,   448,   128,   449,    -1,   450,    -1,   450,    43,
     223,   516,    -1,   451,    -1,   451,   191,    88,   516,    -1,
     452,    -1,   452,    94,    88,   514,    -1,   453,    -1,   453,
      95,    88,   514,    -1,   455,    -1,   454,   455,    -1,   167,
      -1,   150,    -1,   454,   167,    -1,   454,   150,    -1,   458,
      -1,   462,    -1,   459,    -1,   194,    -1,   199,    -1,   198,
      -1,   197,    -1,   196,    -1,   195,    -1,   143,    -1,   170,
      -1,   132,    -1,    70,   145,   386,   175,    -1,    70,   214,
     145,   386,   175,    -1,    70,   213,   145,   386,   175,    -1,
      70,    88,   531,   145,   386,   175,    -1,   460,   145,   175,
      -1,   460,   145,   386,   175,    -1,   461,    -1,   460,   461,
      -1,   168,   609,    15,    -1,   168,    16,    -1,   463,    -1,
     463,   464,    -1,   184,   464,    -1,   464,    -1,   183,    -1,
     465,    -1,   465,   183,   464,    -1,   465,   184,   464,    -1,
     466,    -1,   475,    -1,   467,    -1,   467,   476,    -1,   470,
      -1,   470,   476,    -1,   468,   472,    -1,   469,    -1,    98,
     114,    -1,   107,   114,    -1,    91,   114,    -1,   181,   114,
      -1,   108,   114,    -1,   131,   114,    -1,   130,   114,    -1,
     472,    -1,    92,   472,    -1,   471,   472,    -1,   113,    -1,
     164,   114,    -1,    84,   114,    -1,   172,   114,    -1,   171,
     114,    -1,    85,   114,    -1,   521,    -1,   473,    -1,   609,
      -1,   474,    -1,   185,    -1,    10,    -1,    17,    -1,   478,
      -1,   475,   476,    -1,   475,   148,   178,    -1,   475,   148,
     487,   178,    -1,   477,    -1,   476,   477,    -1,   146,   386,
     176,    -1,   479,    -1,   481,    -1,   482,    -1,   483,    -1,
     486,    -1,   488,    -1,   484,    -1,   485,    -1,   534,    -1,
     480,    -1,   533,    -1,   103,    -1,   141,    -1,   116,    -1,
     111,   609,    -1,   148,   178,    -1,   148,   386,   178,    -1,
     112,    -1,   161,   145,   386,   175,    -1,   193,   145,   386,
     175,    -1,   609,   148,   178,    -1,   609,   148,   487,   178,
      -1,   389,    -1,   487,   100,   389,    -1,   489,    -1,   507,
      -1,   490,    -1,   504,    -1,   505,    -1,   149,   609,   494,
     122,    -1,   149,   609,   492,   494,   122,    -1,   149,   609,
     494,   188,   186,   609,   494,   188,    -1,   149,   609,   494,
     188,   491,   186,   609,   494,   188,    -1,   149,   609,   492,
     494,   188,   186,   609,   494,   188,    -1,   149,   609,   492,
     494,   188,   491,   186,   609,   494,   188,    -1,   502,    -1,
     491,   502,    -1,   493,    -1,   492,   493,    -1,    27,   609,
     494,   124,   494,   495,    -1,    -1,    27,    -1,   174,   496,
     174,    -1,    87,   498,    87,    -1,    -1,   497,    -1,   126,
      -1,   500,    -1,   497,   126,    -1,   497,   500,    -1,    -1,
     499,    -1,   125,    -1,   501,    -1,   499,   125,    -1,   499,
     501,    -1,    19,    -1,   503,    -1,     4,    -1,   503,    -1,
     489,    -1,     9,    -1,   506,    -1,   503,    -1,     8,    -1,
     115,    -1,   117,    -1,   383,    -1,   204,    21,   205,    -1,
     204,   205,    -1,   165,   554,   166,    -1,   165,   554,     7,
      -1,    96,     6,    -1,   508,    -1,   509,    -1,   510,    -1,
     511,    -1,   512,    -1,   513,    -1,    35,   145,   386,   175,
      -1,    37,   609,   145,   175,    -1,    37,   609,   145,   386,
     175,    -1,    37,   145,   386,   175,   145,   175,    -1,    37,
     145,   386,   175,   145,   386,   175,    -1,    91,   609,   145,
     175,    -1,    91,   609,   145,   386,   175,    -1,    91,   145,
     386,   175,   145,   175,    -1,    91,   145,   386,   175,   145,
     386,   175,    -1,    65,   145,   386,   175,    -1,    30,   145,
     386,   175,    -1,    54,   554,   145,   175,    -1,    54,   554,
     145,   386,   175,    -1,    54,   145,   386,   175,   145,   175,
      -1,    54,   145,   386,   175,   145,   386,   175,    -1,   520,
      -1,   520,   136,    -1,    88,   516,    -1,   518,    -1,   518,
     517,    -1,   202,   148,   178,    -1,   136,    -1,   185,    -1,
     167,    -1,   520,    -1,   521,    -1,   144,   148,   178,    -1,
     537,    -1,   540,    -1,   516,    -1,   519,   100,   516,    -1,
     609,    -1,   523,    -1,   529,    -1,   527,    -1,   530,    -1,
     528,    -1,   526,    -1,   525,    -1,   524,    -1,   522,    -1,
     217,   148,   178,    -1,    36,   148,   178,    -1,    36,   148,
     529,   178,    -1,    36,   148,   530,   178,    -1,    65,   148,
     178,    -1,    30,   148,   178,    -1,    54,   148,   178,    -1,
      54,   148,   554,   178,    -1,    54,   148,    20,   178,    -1,
      91,   148,   178,    -1,    91,   148,   609,   178,    -1,    91,
     148,   609,   100,   531,   178,    -1,    91,   148,   185,   178,
      -1,    91,   148,   185,   100,   531,   178,    -1,   180,   609,
     178,    -1,    37,   148,   178,    -1,    37,   148,   609,   178,
      -1,    37,   148,   609,   100,   531,   178,    -1,    37,   148,
     609,   100,   532,   178,    -1,    37,   148,   185,   178,    -1,
      37,   148,   185,   100,   531,   178,    -1,    37,   148,   185,
     100,   532,   178,    -1,    57,   148,   609,   178,    -1,   609,
      -1,   609,   136,    -1,    20,    -1,   535,    -1,   536,    -1,
     609,   137,   141,    -1,    40,   366,   383,    -1,   538,    -1,
     539,    -1,    40,   148,   185,   178,    -1,    40,   148,   178,
      88,   516,    -1,    40,   148,   519,   178,    88,   516,    -1,
     148,   518,   178,    -1,    25,   212,   213,    -1,    25,   212,
     214,    -1,    25,   212,   215,    -1,   218,   217,   389,   225,
     389,    -1,   218,   217,   389,    88,   224,   225,   389,    -1,
     218,   217,   389,    88,   226,   225,   389,    -1,   218,   217,
     389,   210,   389,    -1,   218,   217,   389,   211,   389,    -1,
     218,   219,   389,   225,   389,    -1,   218,   219,   389,    88,
     224,   225,   389,    -1,   218,   219,   389,    88,   226,   225,
     389,    -1,   218,   219,   389,   210,   389,    -1,   218,   219,
     389,   211,   389,    -1,   216,   217,   389,    -1,   216,   219,
     389,    -1,   221,   217,   389,   229,   389,    -1,   221,   222,
     223,   217,   389,   229,   389,    -1,   220,   217,   389,    88,
     389,    -1,   228,   111,   547,   227,   389,   177,   389,    -1,
     548,    -1,   547,   100,   111,   548,    -1,   609,   134,   389,
      -1,   237,   145,   386,   175,   550,    -1,   551,    -1,   550,
     551,    -1,   238,   552,   384,    -1,   238,   552,   148,   111,
     609,   178,   384,    -1,   238,   552,   148,   111,   609,   100,
     111,   609,   178,   384,    -1,   238,   552,   148,   111,   609,
     100,   111,   609,   100,   111,   609,   178,   384,    -1,   473,
      -1,   552,   201,   473,    -1,    20,    -1,    14,    -1,   609,
      -1,   239,   111,   408,    38,   145,   389,   175,    -1,    38,
     145,   389,   175,    -1,   559,   557,    -1,    -1,   558,    -1,
     577,    -1,   558,   577,    -1,   560,    -1,   559,   255,   560,
      -1,   561,    -1,   560,   251,   561,    -1,   562,    -1,   561,
     253,   139,   562,    -1,   563,    -1,   252,   563,    -1,   567,
     564,   565,    -1,    -1,   582,    -1,    -1,   566,    -1,   275,
     145,   386,   175,    -1,   571,   568,    -1,   148,   556,   178,
      -1,   569,    -1,    -1,   604,    -1,   460,   145,   570,   175,
      -1,    -1,   556,    -1,   572,   573,    -1,   479,    -1,   145,
     386,   175,    -1,    -1,   574,    -1,   241,   575,    -1,   240,
     576,    -1,   263,    -1,    -1,    72,    -1,    -1,   279,    -1,
     578,    -1,   579,    -1,   580,    -1,   606,    -1,   603,    -1,
     161,    -1,   277,   445,   581,    -1,   246,   605,   581,    -1,
     279,    -1,   269,    -1,   262,    -1,   239,   583,    -1,   582,
     239,   583,    -1,   584,    -1,   585,    -1,   586,    -1,   601,
      -1,   587,    -1,   595,    -1,   588,    -1,   602,    -1,    93,
     267,    -1,    93,   256,    -1,   259,    -1,   274,    -1,   244,
     267,    -1,   244,   256,    -1,    50,   609,    20,    -1,   270,
      -1,    47,   270,    -1,   272,   589,    -1,   272,   148,   589,
     590,   178,    -1,    47,   272,    -1,   592,    -1,   106,    -1,
      -1,   591,    -1,   592,    -1,   591,   100,   592,    -1,    90,
      20,   593,   594,    -1,    -1,   264,    20,    -1,    -1,   605,
     258,    -1,   271,   279,   596,   598,    -1,   271,   279,   106,
     598,    -1,    47,   271,   279,    -1,    90,    20,    -1,   148,
     597,   178,    -1,    20,    -1,   597,   100,    20,    -1,    -1,
     599,    -1,   600,    -1,   599,   600,    -1,   192,   596,    -1,
     128,   596,    -1,   257,    20,    -1,   276,    -1,    47,   276,
      -1,    90,   209,    -1,    90,   247,    -1,   248,   243,    -1,
     260,   605,   273,    -1,   249,   445,    -1,    90,   121,   445,
      -1,    90,    45,   445,    -1,   250,   445,   190,   445,    -1,
     265,   607,    -1,   245,   607,    -1,   268,    -1,   261,    -1,
     278,   243,   447,    -1,    18,    -1,   610,    -1,   206,    -1,
     119,    -1,    91,    -1,    30,    -1,    36,    -1,    37,    -1,
     144,    -1,    41,    -1,   217,    -1,    54,    -1,    56,    -1,
      57,    -1,    65,    -1,    68,    -1,    67,    -1,   202,    -1,
      29,    -1,   254,    -1,    28,    -1,   214,    -1,   213,    -1,
     138,    -1,    35,    -1,   252,    -1,   253,    -1,   267,    -1,
     256,    -1,   244,    -1,   278,    -1,   270,    -1,   272,    -1,
     271,    -1,   276,    -1,   248,    -1,   243,    -1,    72,    -1,
     209,    -1,   247,    -1,    45,    -1,   215,    -1,   228,    -1,
     295,    -1,   222,    -1,   194,    -1,   199,    -1,   198,    -1,
     197,    -1,   196,    -1,   195,    -1,    90,    -1,   104,    -1,
     105,    -1,   177,    -1,    39,    -1,    52,    -1,    61,    -1,
      66,    -1,    53,    -1,    46,    -1,    49,    -1,    71,    -1,
      33,    -1,   139,    -1,    44,    -1,   203,    -1,   162,    -1,
     163,    -1,   160,    -1,    64,    -1,    89,    -1,   109,    -1,
     120,    -1,   121,    -1,    99,    -1,    62,    -1,   127,    -1,
     179,    -1,    93,    -1,    88,    -1,   189,    -1,   118,    -1,
     159,    -1,    86,    -1,    43,    -1,   223,    -1,    94,    -1,
     190,    -1,   110,    -1,   151,    -1,   192,    -1,   142,    -1,
     128,    -1,    70,    -1,    95,    -1,   191,    -1,   143,    -1,
     173,    -1,   187,    -1,   152,    -1,   129,    -1,   123,    -1,
     158,    -1,   140,    -1,   157,    -1,    25,    -1,    31,    -1,
      51,    -1,   106,    -1,    32,    -1,    50,    -1,   207,    -1,
      42,    -1,    55,    -1,    26,    -1,    40,    -1,   266,    -1,
     242,    -1,   275,    -1,   277,    -1,   246,    -1,   260,    -1,
     273,    -1,   265,    -1,   245,    -1,   259,    -1,   274,    -1,
     264,    -1,   258,    -1,   257,    -1,   241,    -1,   240,    -1,
     263,    -1,   249,    -1,   250,    -1,   279,    -1,   269,    -1,
     268,    -1,   261,    -1,   221,    -1,   227,    -1,   224,    -1,
     218,    -1,   211,    -1,   210,    -1,   212,    -1,   229,    -1,
     219,    -1,   220,    -1,   226,    -1,   216,    -1,   225,    -1,
      60,    -1,    58,    -1,    69,    -1,    34,    -1,    48,    -1,
     161,    -1,   193,    -1,   235,    -1,   230,    -1,   233,    -1,
     234,    -1,   236,    -1,   231,    -1,   232,    -1,   237,    -1,
     238,    -1,    38,    -1,   239,    -1,    59,    -1,   288,    -1,
     286,    -1,   287,    -1,   292,    -1,   293,    -1,   294,    -1,
     289,    -1,   290,    -1,   291,    -1,    73,    -1,    74,    -1,
      75,    -1,    76,    -1,    77,    -1,    78,    -1,    79,    -1,
      80,    -1,    81,    -1,    82,    -1,    83,    -1,   280,    -1,
     281,    -1,   282,    -1,   283,    -1,   284,    -1,   285,    -1,
     296,    -1,   297,    -1,   298,    -1,   299,    -1,   300,    -1,
     301,    -1,   302,    -1,    84,    -1,    98,    -1,   107,    -1,
     164,    -1,   171,    -1,   181,    -1,   130,    -1,    85,    -1,
     108,    -1,   131,    -1,   172,    -1
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
    1961,  1968,  1972,  1976,  1981,  1988,  1995,  2000,  2007,  2014,
    2019,  2021,  2024,  2026,  2028,  2030,  2034,  2038,  2040,  2042,
    2047,  2053,  2060,  2064,  2068,  2072,  2076,  2082,  2090,  2098,
    2104,  2110,  2116,  2124,  2132,  2138,  2144,  2148,  2152,  2158,
    2166,  2172,  2180,  2182,  2187,  2191,  2197,  2199,  2202,  2206,
    2214,  2225,  2239,  2241,  2245,  2247,  2249,  2251,  2259,  2264,
    2267,  2268,  2270,  2272,  2275,  2277,  2281,  2283,  2287,  2289,
    2294,  2296,  2299,  2303,  2304,  2306,  2307,  2309,  2314,  2317,
    2321,  2323,  2324,  2326,  2331,  2332,  2334,  2337,  2339,  2343,
    2344,  2346,  2349,  2352,  2354,  2355,  2357,  2358,  2360,  2362,
    2364,  2366,  2368,  2370,  2372,  2376,  2380,  2382,  2384,  2386,
    2389,  2393,  2395,  2397,  2399,  2401,  2403,  2405,  2407,  2409,
    2412,  2415,  2417,  2419,  2422,  2425,  2429,  2431,  2434,  2437,
    2443,  2446,  2448,  2450,  2451,  2453,  2455,  2459,  2464,  2465,
    2468,  2469,  2472,  2477,  2482,  2486,  2489,  2493,  2495,  2499,
    2500,  2502,  2504,  2507,  2510,  2513,  2516,  2518,  2521,  2524,
    2527,  2530,  2534,  2537,  2541,  2545,  2550,  2553,  2556,  2558,
    2560,  2564,  2566,  2568,  2570,  2572,  2574,  2576,  2578,  2580,
    2582,  2584,  2586,  2588,  2590,  2592,  2594,  2596,  2598,  2600,
    2602,  2604,  2606,  2608,  2610,  2612,  2614,  2616,  2618,  2620,
    2622,  2624,  2626,  2628,  2630,  2632,  2634,  2636,  2638,  2640,
    2642,  2644,  2646,  2648,  2650,  2652,  2654,  2656,  2658,  2660,
    2662,  2664,  2666,  2668,  2670,  2672,  2674,  2676,  2678,  2680,
    2682,  2684,  2686,  2688,  2690,  2692,  2694,  2696,  2698,  2700,
    2702,  2704,  2706,  2708,  2710,  2712,  2714,  2716,  2718,  2720,
    2722,  2724,  2726,  2728,  2730,  2732,  2734,  2736,  2738,  2740,
    2742,  2744,  2746,  2748,  2750,  2752,  2754,  2756,  2758,  2760,
    2762,  2764,  2766,  2768,  2770,  2772,  2774,  2776,  2778,  2780,
    2782,  2784,  2786,  2788,  2790,  2792,  2794,  2796,  2798,  2800,
    2802,  2804,  2806,  2808,  2810,  2812,  2814,  2816,  2818,  2820,
    2822,  2824,  2826,  2828,  2830,  2832,  2834,  2836,  2838,  2840,
    2842,  2844,  2846,  2848,  2850,  2852,  2854,  2856,  2858,  2860,
    2862,  2864,  2866,  2868,  2870,  2872,  2874,  2876,  2878,  2880,
    2882,  2884,  2886,  2888,  2890,  2892,  2894,  2896,  2898,  2900,
    2902,  2904,  2906,  2908,  2910,  2912,  2914,  2916,  2918,  2920,
    2922,  2924,  2926,  2928,  2930,  2932,  2934,  2936,  2938,  2940,
    2942,  2944,  2946,  2948,  2950,  2952,  2954,  2956,  2958,  2960,
    2962,  2964,  2966,  2968,  2970,  2972,  2974,  2976,  2978,  2980,
    2982,  2984,  2986,  2988,  2990,  2992,  2994
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,  1069,  1069,  1070,  1075,  1076,  1077,  1078,  1082,  1098,
    1103,  1110,  1115,  1126,  1131,  1139,  1147,  1155,  1161,  1173,
    1182,  1186,  1190,  1202,  1208,  1218,  1224,  1234,  1235,  1236,
    1237,  1242,  1243,  1244,  1245,  1246,  1247,  1248,  1249,  1250,
    1256,  1261,  1270,  1276,  1285,  1294,  1295,  1296,  1297,  1298,
    1299,  1300,  1301,  1302,  1303,  1308,  1309,  1310,  1311,  1312,
    1313,  1314,  1317,  1322,  1323,  1333,  1342,  1348,  1358,  1364,
    1374,  1384,  1392,  1398,  1409,  1414,  1424,  1430,  1436,  1442,
    1459,  1467,  1475,  1479,  1488,  1497,  1510,  1516,  1527,  1531,
    1539,  1544,  1549,  1556,  1569,  1576,  1582,  1589,  1595,  1599,
    1606,  1617,  1621,  1629,  1635,  1641,  1650,  1656,  1665,  1669,
    1675,  1679,  1683,  1687,  1693,  1699,  1705,  1711,  1717,  1721,
    1727,  1733,  1740,  1748,  1756,  1764,  1772,  1784,  1798,  1812,
    1829,  1833,  1842,  1846,  1853,  1861,  1879,  1885,  1893,  1898,
    1905,  1912,  1922,  1932,  1942,  1952,  1969,  1975,  1986,  1990,
    1994,  1998,  2007,  2014,  2033,  2043,  2049,  2055,  2065,  2072,
    2083,  2090,  2097,  2109,  2113,  2120,  2125,  2140,  2157,  2161,
    2165,  2169,  2177,  2187,  2201,  2211,  2225,  2235,  2250,  2256,
    2268,  2272,  2283,  2290,  2298,  2313,  2317,  2331,  2335,  2344,
    2348,  2362,  2363,  2364,  2365,  2366,  2367,  2370,  2371,  2372,
    2373,  2374,  2376,  2377,  2380,  2381,  2382,  2383,  2384,  2389,
    2404,  2411,  2415,  2422,  2426,  2430,  2437,  2445,  2456,  2466,
    2479,  2488,  2489,  2490,  2494,  2495,  2496,  2497,  2498,  2501,
    2507,  2516,  2520,  2528,  2538,  2544,  2556,  2560,  2568,  2577,
    2587,  2595,  2604,  2613,  2628,  2637,  2647,  2655,  2661,  2670,
    2676,  2688,  2696,  2706,  2714,  2726,  2732,  2743,  2745,  2749,
    2757,  2761,  2766,  2770,  2774,  2778,  2786,  2800,  2808,  2815,
    2821,  2832,  2836,  2845,  2853,  2859,  2869,  2875,  2885,  2889,
    2899,  2905,  2911,  2917,  2926,  2935,  2944,  2957,  2961,  2969,
    2975,  2985,  2993,  3002,  3015,  3022,  3034,  3038,  3050,  3057,
    3063,  3072,  3079,  3085,  3097,  3104,  3117,  3123,  3135,  3141,
    3153,  3162,  3166,  3175,  3179,  3187,  3191,  3201,  3208,  3217,
    3227,  3226,  3240,  3249,  3258,  3271,  3275,  3288,  3291,  3298,
    3302,  3311,  3315,  3319,  3328,  3332,  3338,  3344,  3350,  3361,
    3365,  3369,  3377,  3381,  3387,  3397,  3401,  3411,  3415,  3425,
    3429,  3439,  3443,  3453,  3457,  3465,  3469,  3473,  3477,  3487,
    3491,  3495,  3503,  3507,  3511,  3515,  3519,  3523,  3531,  3535,
    3539,  3547,  3551,  3555,  3559,  3570,  3576,  3586,  3592,  3602,
    3606,  3644,  3650,  3656,  3662,  3673,  3681,  3692,  3698,  3708,
    3712,  3720,  3726,  3734,  3740,  3752,  3758,  3768,  3772,  3776,
    3780,  3784,  3790,  3796,  3804,  3808,  3816,  3820,  3831,  3835,
    3839,  3845,  3849,  3863,  3867,  3875,  3879,  3889,  3893,  3897,
    3906,  3910,  3916,  3920,  3928,  3934,  3944,  3952,  3956,  3960,
    3964,  3968,  3972,  3976,  3980,  3984,  3992,  3996,  4004,  4011,
    4018,  4029,  4037,  4041,  4049,  4057,  4065,  4119,  4123,  4135,
    4141,  4151,  4155,  4163,  4167,  4171,  4179,  4189,  4199,  4209,
    4219,  4229,  4244,  4250,  4261,  4267,  4278,  4289,  4291,  4295,
    4300,  4310,  4313,  4320,  4328,  4334,  4344,  4357,  4360,  4367,
    4373,  4379,  4386,  4397,  4401,  4411,  4415,  4425,  4429,  4433,
    4438,  4447,  4453,  4459,  4465,  4475,  4479,  4491,  4495,  4507,
    4519,  4523,  4527,  4531,  4535,  4539,  4547,  4555,  4561,  4567,
    4571,  4588,  4592,  4596,  4600,  4608,  4616,  4624,  4628,  4632,
    4636,  4644,  4650,  4660,  4668,  4672,  4678,  4713,  4719,  4725,
    4735,  4739,  4743,  4747,  4751,  4758,  4764,  4774,  4782,  4786,
    4790,  4794,  4798,  4802,  4806,  4810,  4814,  4822,  4830,  4834,
    4838,  4848,  4856,  4864,  4868,  4872,  4880,  4884,  4890,  4896,
    4900,  4910,  4918,  4922,  4928,  4937,  4946,  4952,  4958,  4968,
    4985,  4992,  5007,  5043,  5047,  5056,  5065,  5075,  5079,  5088,
    5097,  5101,  5112,  5129,  5135,  5141,  5151,  5155,  5161,  5167,
    5171,  5177,  5181,  5187,  5193,  5200,  5210,  5215,  5223,  5229,
    5239,  5261,  5270,  5276,  5289,  5303,  5310,  5316,  5326,  5331,
    5337,  5347,  5360,  5366,  5376,  5386,  5387,  5406,  5412,  5427,
    5436,  5439,  5446,  5451,  5459,  5463,  5470,  5474,  5481,  5485,
    5492,  5496,  5505,  5518,  5521,  5529,  5532,  5540,  5548,  5556,
    5560,  5568,  5571,  5579,  5591,  5594,  5602,  5614,  5620,  5630,
    5633,  5641,  5645,  5649,  5657,  5660,  5668,  5671,  5679,  5683,
    5687,  5691,  5695,  5703,  5711,  5723,  5735,  5739,  5743,  5751,
    5757,  5767,  5771,  5775,  5779,  5783,  5787,  5791,  5795,  5803,
    5807,  5811,  5815,  5823,  5829,  5839,  5849,  5853,  5861,  5871,
    5882,  5889,  5893,  5901,  5904,  5911,  5916,  5925,  5935,  5938,
    5946,  5949,  5957,  5966,  5973,  5983,  5987,  5994,  6000,  6010,
    6013,  6020,  6025,  6037,  6045,  6057,  6065,  6069,  6077,  6081,
    6085,  6093,  6101,  6105,  6109,  6113,  6121,  6129,  6141,  6145,
    6153,  6166,  6170,  6177,  6178,  6179,  6180,  6181,  6182,  6183,
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
    6354,  6355,  6356,  6357,  6358,  6359,  6360,  6361,  6362,  6363,
    6364,  6365,  6366,  6367,  6368,  6369,  6370,  6371,  6372,  6373,
    6374,  6375,  6376,  6377,  6378,  6379,  6380,  6381,  6382,  6383,
    6384,  6385,  6386,  6387,  6388,  6389,  6390
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
  const int xquery_parser::yylast_ = 11460;
  const int xquery_parser::yynnts_ = 294;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 554;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 317;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 571;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 15535 "/home/markos/zorba/zorba_clean/build-gdb/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6394 "/home/markos/zorba/zorba_clean/src/compiler/parser/xquery_parser.y"


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

