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
#line 72 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"


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
#line 78 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 859 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 317 of lalr1.cc  */
#line 959 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"

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
  if (error != zorba::err::ZXQP0000_NO_ERROR)
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

  if (error != zorba::err::ZXQP0000_NO_ERROR)
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
#line 151 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"

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
#line 217 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
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
        case 109: /* "\"'DECIMAL'\"" */

/* Line 480 of lalr1.cc  */
#line 857 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 324 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 123: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 856 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 333 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 148: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 855 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 342 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 351 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 360 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 369 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 378 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 387 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 396 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 405 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 414 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 423 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 880 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 432 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 880 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 441 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 450 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 459 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 468 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 477 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 486 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 495 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 504 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 513 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 522 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 531 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 540 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 549 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 558 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 567 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 576 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 585 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 594 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 603 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 612 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 621 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 880 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 630 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 639 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "DeclPropertyList" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 648 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "DeclProperty" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 657 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 666 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "NodeModifier" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 675 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 684 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 693 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 702 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 711 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 720 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 880 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 729 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 738 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "Block" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 747 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "BlockDecls" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 756 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "BlockVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 765 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "BlockVarDecl" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 774 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "AssignExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 783 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "ExitExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 792 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "WhileExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 801 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 810 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 819 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 828 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 837 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 846 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 855 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 864 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "FunctionDeclSequential" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 873 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 891 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 900 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "EnclosedExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 918 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 927 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 936 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "ApplyExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 945 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "ConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 954 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 963 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 972 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 981 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 990 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 999 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1008 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1017 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1026 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1035 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1044 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1053 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1062 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1071 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1080 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1089 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1098 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1107 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1116 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1125 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1134 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1143 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1152 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1161 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1170 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1179 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1188 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1197 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1206 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1215 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1224 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1233 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1242 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1251 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1260 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1269 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1278 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1287 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1296 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1305 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1314 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1323 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1332 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1341 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1350 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1359 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1368 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1377 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1386 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1395 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1404 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1413 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1422 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1431 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1440 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1449 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1458 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1467 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1476 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1485 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1494 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1503 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1512 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1521 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1530 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1539 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1548 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1557 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1566 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1575 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1584 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1593 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1602 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1611 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1620 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1629 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1638 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1647 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1656 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1665 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1674 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1683 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1692 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1701 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1710 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1719 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1728 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1737 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1746 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1755 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1764 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1773 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1782 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1791 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1800 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1809 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1818 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1827 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1836 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1845 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1854 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1863 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1872 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1881 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1890 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1899 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1908 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1917 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1926 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1935 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1944 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1953 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1962 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1971 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1980 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1989 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1998 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2007 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2016 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2025 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2034 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2043 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2052 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2061 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2070 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2079 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2088 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2097 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2106 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2115 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2124 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2133 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2142 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2151 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2160 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2169 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2178 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2187 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2196 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2205 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2214 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2223 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2232 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2241 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2250 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2259 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2268 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2277 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2286 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 880 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2295 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2304 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2313 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2322 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2331 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2340 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2349 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2358 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2367 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2376 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2385 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2394 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2403 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2412 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2421 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2430 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2439 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2448 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2457 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2466 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2475 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2484 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2493 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2502 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2511 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2520 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2529 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2538 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2547 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2556 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2565 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2574 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2583 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2592 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2601 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2610 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2619 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2628 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 610: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2637 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 613: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2646 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 614: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2655 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 615: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2664 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
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
#line 125 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 553 of lalr1.cc  */
#line 2749 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"

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
#line 1020 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 1053 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL; YYABORT;
        }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 1062 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 1067 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            MainModule *mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
            mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 1074 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 1079 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            LibraryModule *lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
            lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 1090 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
        }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 1094 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
        }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 1102 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);
          (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
        }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1107 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));
          (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
        }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1112 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)), static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));
          (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
        }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 1117 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
        }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1122 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
          (yylocation_stack_[(3) - (1)]).step();
          error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement."); 
          YYERROR;
        }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1129 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
          (yylocation_stack_[(3) - (1)]).step();
          error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration."); 
          YYERROR;
        }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1136 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
          (yylocation_stack_[(5) - (3)]).step();
          error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
          YYERROR;
        }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1143 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
          (yylocation_stack_[(5) - (1)]).step();
          error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
          YYERROR;
        }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1154 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
        }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1158 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
        }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1163 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
        }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 1168 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)), static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
        }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 1177 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
            dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
        }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 1186 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
            sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = sdl;
        }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 1192 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 1198 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            // error
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
            (yylocation_stack_[(3) - (1)]).step();
            error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration."); 
            YYERROR;
        }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 1210 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
            vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = vdl;
        }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 1216 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 1222 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
            (yylocation_stack_[(3) - (1)]).step();
            error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
            YYERROR;
        }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1255 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
          delete (yysemantic_stack_[(4) - (4)].vstrpair);
        }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1260 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
          delete (yysemantic_stack_[(4) - (4)].vstrpair);
        }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1269 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.vstrpair) = new vector<string_pair_t>();
          (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
          delete (yysemantic_stack_[(1) - (1)].strpair);
        }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1275 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
          delete (yysemantic_stack_[(2) - (2)].strpair);
          (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
        }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1284 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
            (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
            delete sl;
        }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1292 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1293 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1294 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1295 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1296 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 1297 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 1298 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 1299 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 1300 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 1301 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1324 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yyval.node); // to prevent the Bison warning
          error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
          YYERROR;
        }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1334 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
        }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1342 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::preserve_space
            );
        }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1348 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::strip_space
            );
        }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1358 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_element_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1364 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_function_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1374 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OptionDecl(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval))
            );
        }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1384 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1392 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::ordered
            );
        }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1398 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::unordered
            );
        }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1409 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_greatest);
        }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 1414 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_least);
        }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 1424 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 1430 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1436 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1442 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1459 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
        }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1467 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1475 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
        }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1479 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport(
                LOC((yyloc)),
                dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                NULL
            );
        }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1488 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport(
                LOC((yyloc)),
                NULL,
                SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1497 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport(
                LOC((yyloc)),
                dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1510 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            URILiteralList *ull = new URILiteralList( LOC((yyloc)));
            ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.node) = ull;
        }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1516 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
                ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1527 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1531 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
        }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1539 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1544 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1549 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1556 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(8) - (4)].sval)),
                            SYMTAB((yysemantic_stack_[(8) - (6)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1569 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
        }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1576 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
            d->type = (yysemantic_stack_[(3) - (2)].node);
            (yyval.node) = d;
        }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1582 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1589 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
            d->ext = false;
            (yyval.node) = d;
        }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1595 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), NULL );
        }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1599 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1606 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1617 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)), NULL, NULL);
      dynamic_cast<VarNameAndType*>((yyval.varnametype))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1622 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)), NULL);
      dynamic_cast<VarNameAndType*>((yyval.varnametype))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1627 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (5)].expr)), NULL, static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (2)].node)));
      dynamic_cast<VarNameAndType*>((yyval.varnametype))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 1632 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (5)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)), static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)));
      dynamic_cast<VarNameAndType*>((yyval.varnametype))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 1641 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(3) - (1)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(3) - (3)].expr), nt->get_annotations());
      dynamic_cast<VarDecl*>((yyval.node))->setComment(nt->getCommentString());
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 1647 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(2) - (1)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL, nt->get_annotations(), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(nt->getCommentString());
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1653 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (1)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(4) - (4)].expr), nt->get_annotations(), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(nt->getCommentString());
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1662 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            DeclPropertyList *dpl = new DeclPropertyList( LOC((yyloc)) );
            dpl->addProperty(dynamic_cast<DeclProperty*>((yysemantic_stack_[(1) - (1)].node)));
            (yyval.node) = dpl;
        }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1668 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        DeclPropertyList *dpl = dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(2) - (1)].node));
        dpl->addProperty( static_cast<DeclProperty*>((yysemantic_stack_[(2) - (2)].node)) );
        (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1677 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_const );
        }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1681 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_append_only
            );
        }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1687 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_queue );
        }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1691 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_mutable );
        }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1695 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_ordered );
        }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1699 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_unordered
            );
        }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1705 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_equality
            );
        }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1711 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_range
            );
        }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1717 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_equality
            );
        }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1723 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_range
            );
        }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1729 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_unique );
        }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1733 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_non_unique
            );
        }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1739 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_automatic
            );
        }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1745 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_manual );
        }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 1752 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL,
                              NULL);
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1760 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              NULL,
                              static_cast<NodeModifier*>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1768 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              NULL,
                              NULL,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1776 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                              NULL,
                              static_cast<NodeModifier*>((yysemantic_stack_[(6) - (6)].node)),
                              static_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)));
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1784 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 133:

/* Line 678 of lalr1.cc  */
#line 1796 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 134:

/* Line 678 of lalr1.cc  */
#line 1810 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 135:

/* Line 678 of lalr1.cc  */
#line 1824 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 136:

/* Line 678 of lalr1.cc  */
#line 1841 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1845 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1854 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1858 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1865 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                             (yysemantic_stack_[(8) - (6)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                             NULL);
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1873 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 142:

/* Line 678 of lalr1.cc  */
#line 1891 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1897 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1905 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1910 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1917 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1924 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1935 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1945 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1955 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1966 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 152:

/* Line 678 of lalr1.cc  */
#line 1981 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_preserve
            );
        }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1987 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_strip
            );
        }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1998 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL );
        }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 2002 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 2006 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)) );
        }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 2010 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 2017 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
        }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 2024 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 160:

/* Line 678 of lalr1.cc  */
#line 2043 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
            auto_ptr<VFO_DeclList> vfo2( dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)) );
            if ( !(yysemantic_stack_[(3) - (1)].node) )
                vfo = new VFO_DeclList( LOC((yyloc)) );
            vfo->push_back( *vfo2.get() );
            (yyval.node) = vfo;
        }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 2052 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 2059 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
            vfo->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = vfo;
        }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 2065 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = new VFO_DeclList( LOC((yyloc)) );
            vfo->push_back((yysemantic_stack_[(2) - (2)].node));
            (yyval.node) = vfo;
        }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2075 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 2081 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)), NULL, NULL);

      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 2088 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 2094 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)), (yysemantic_stack_[(5) - (5)].expr), NULL);
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 2104 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 2111 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExitExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 2118 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            BlockBody *bb = dynamic_cast<BlockBody *>((yysemantic_stack_[(5) - (5)].expr));
            if ( !bb ) {
                bb = new BlockBody( (yysemantic_stack_[(5) - (5)].expr)->get_location() );
                bb->add((yysemantic_stack_[(5) - (5)].expr));
            }
            (yyval.expr) = new WhileExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), bb );
        }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 2130 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::BREAK );
        }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 2134 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
        }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 2142 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnnotationListParsenode( LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
        }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 2146 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 2154 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnnotationParsenode( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
        }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 2158 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnnotationParsenode( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))), static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
        }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 2165 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnnotationLiteralListParsenode( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
        }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 2169 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2177 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2182 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node))->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
            static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node))->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
            (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
        }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2191 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 2195 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 2199 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 2203 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 2211 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 186:

/* Line 678 of lalr1.cc  */
#line 2222 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 187:

/* Line 678 of lalr1.cc  */
#line 2237 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 188:

/* Line 678 of lalr1.cc  */
#line 2248 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 189:

/* Line 678 of lalr1.cc  */
#line 2263 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 190:

/* Line 678 of lalr1.cc  */
#line 2274 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 191:

/* Line 678 of lalr1.cc  */
#line 2290 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            ParamList *pl = new ParamList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 2296 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
                pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 2308 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 2312 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 2323 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EnclosedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 2330 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 2338 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QueryBody( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 2353 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 2357 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            auto_ptr<BlockBody> blk( dynamic_cast<BlockBody*>((yysemantic_stack_[(2) - (2)].expr)) );
            BlockBody *blk2 = new BlockBody( LOC((yyloc)) );
            blk2->add( (yysemantic_stack_[(2) - (1)].expr) );

            for ( ulong i = 0; i < blk->size(); ++i )
                blk2->add( (*blk)[i] );

            (yyval.expr) = blk2;
        }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 2371 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new BlockBody( LOC((yyloc)) );
        }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 2375 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            BlockBody *bb = dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (1)].expr));
            bb->add( (yysemantic_stack_[(3) - (2)].expr) );
            (yyval.expr) = bb;
        }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 2384 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 2388 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2442 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2457 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 2464 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_sliding;
        }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 2468 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_tumbling;
        }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 2475 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_start;
        }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 2479 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_end;
        }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 2483 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_only_end;
        }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 2490 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2498 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr),
                (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 2509 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2519 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2532 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 2554 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 2560 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 2570 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
        }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 2578 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
            vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vdl;
        }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 2584 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2596 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 2600 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)), NULL, NULL, NULL, (yysemantic_stack_[(5) - (5)].expr), true);
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 2604 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)), NULL, NULL, (yysemantic_stack_[(4) - (4)].expr), false);
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2608 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (2)].node)), NULL, NULL, (yysemantic_stack_[(6) - (6)].expr), true);
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2612 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)), NULL, dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)), NULL, (yysemantic_stack_[(4) - (4)].expr), false);
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 2616 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)), NULL, dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (4)].node)), NULL, (yysemantic_stack_[(6) - (6)].expr), true);
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 2620 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)), NULL, (yysemantic_stack_[(5) - (5)].expr), false);
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2625 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(7) - (1)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(7) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(7) - (5)].node)), NULL, (yysemantic_stack_[(7) - (7)].expr), true);
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 2631 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2640 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2650 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2660 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2676 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2685 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2694 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2702 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2708 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2720 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2728 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2738 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2746 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2758 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2764 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2777 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2781 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2789 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2793 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2802 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 2810 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2820 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2828 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2835 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2841 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2852 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2856 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2865 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2873 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2879 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2889 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2895 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2905 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 2909 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 2919 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 2925 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 2931 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 2937 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 2946 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 2955 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 2964 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 2977 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 2981 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 2989 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 2995 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3005 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3013 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3022 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3035 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3042 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3054 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3058 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3070 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3077 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3083 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3092 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3099 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3105 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3117 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3124 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3137 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3143 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3155 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3161 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3173 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3182 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3186 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3195 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3199 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3207 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3211 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 328:

/* Line 678 of lalr1.cc  */
#line 3221 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3228 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3237 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3246 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3251 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3260 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3269 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3278 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3291 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3295 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3307 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3311 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3318 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3322 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3331 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3335 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3339 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3348 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3352 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3358 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3364 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3370 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3381 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3385 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3389 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3397 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3401 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3407 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3417 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3421 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3431 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3435 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3445 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3449 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3459 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3463 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3473 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3477 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3485 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3489 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3493 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3497 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3507 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3511 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3515 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3523 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3527 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3531 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3535 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3539 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3543 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3551 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3555 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3559 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3567 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3571 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3575 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3579 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3590 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3596 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3606 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3612 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3622 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3626 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3630 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3669 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3673 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3683 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3693 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3707 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3717 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 399:

/* Line 678 of lalr1.cc  */
#line 3727 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3731 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3741 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3745 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3754 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3760 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3768 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3774 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3786 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3792 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3802 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3810 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3814 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3818 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3824 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3830 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3857 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3865 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3869 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3880 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3884 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3888 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3894 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 3898 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 3912 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 3916 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 3924 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 3928 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 3938 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all);
    }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 3942 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem);
    }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 3946 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix);
    }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 3955 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 3959 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 3963 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 3967 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 3975 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 3981 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 3991 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 3999 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4003 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4007 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4011 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4015 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4019 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4023 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4027 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4031 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4039 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4043 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4051 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4058 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4065 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4076 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4084 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4088 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4096 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4104 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4112 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4166 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4170 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4183 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4189 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4199 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4203 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4211 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4215 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4219 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4227 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 469:

/* Line 678 of lalr1.cc  */
#line 4237 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 470:

/* Line 678 of lalr1.cc  */
#line 4247 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 471:

/* Line 678 of lalr1.cc  */
#line 4257 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 472:

/* Line 678 of lalr1.cc  */
#line 4267 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 473:

/* Line 678 of lalr1.cc  */
#line 4277 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 474:

/* Line 678 of lalr1.cc  */
#line 4292 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4298 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4309 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4315 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4326 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4343 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4348 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4357 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4361 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4368 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4374 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4380 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4388 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4400 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4404 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4411 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4417 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4423 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4430 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4441 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4445 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4455 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4459 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4469 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4473 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4477 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4482 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4491 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4497 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4503 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4509 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4519 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4523 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
        }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4535 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4539 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4551 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4563 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4567 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4571 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4575 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4579 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4583 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4591 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4599 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (1)].sval))), NULL);
        }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4603 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4607 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4611 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4628 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (1)].sval))), NULL );
        }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4632 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4636 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4640 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4648 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4656 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4664 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (1)].sval)), NULL );
        }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4668 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4672 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4676 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4684 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4690 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4700 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4708 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4712 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4716 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4751 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4757 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4763 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4773 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4777 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4781 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4785 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4789 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4796 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4802 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4812 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4820 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 4824 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 4828 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 4832 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 4836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 4840 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 4844 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 4848 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 4852 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 4860 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 4868 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 4872 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 4876 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 4886 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 4894 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 4902 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 4906 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 4910 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 4918 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 4922 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 4928 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 4934 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 4938 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 4948 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 4956 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 4960 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 4966 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 4975 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 4984 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 4990 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 4996 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5006 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5023 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5030 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5045 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5081 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5085 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5094 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
        }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5103 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new InlineFunction(LOC ((yyloc)), &*(yysemantic_stack_[(3) - (2)].fnsig)->param, &*(yysemantic_stack_[(3) - (2)].fnsig)->ret, dynamic_cast<EnclosedExpr *>((yysemantic_stack_[(3) - (3)].expr)));
          delete (yysemantic_stack_[(3) - (2)].fnsig);
        }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5113 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5117 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5126 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
        }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5135 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5139 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5150 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5167 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5173 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5179 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5189 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5193 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5199 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5205 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5209 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5215 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5219 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5225 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5231 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5238 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5248 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5253 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5261 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5267 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5277 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5299 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5308 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5314 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5327 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5341 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5348 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5354 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5364 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5369 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5374 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 623:

/* Line 678 of lalr1.cc  */
#line 5384 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 624:

/* Line 678 of lalr1.cc  */
#line 5397 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5403 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5421 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5429 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5433 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5440 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5445 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5453 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5457 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5464 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5468 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5475 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5479 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5486 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5490 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5499 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5511 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5515 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5522 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5526 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5534 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5542 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5550 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5554 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5561 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5565 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5573 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5584 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5588 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5596 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5608 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5614 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5623 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5627 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5635 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5639 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5643 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5650 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5654 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5661 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5665 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5673 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5677 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5681 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5685 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5689 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5697 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5705 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5717 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5729 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5733 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5737 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5745 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5751 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5761 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5765 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5769 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5773 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5777 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5781 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5785 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5789 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5797 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5801 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5805 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5809 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5817 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5823 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5833 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5843 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5855 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 696:

/* Line 678 of lalr1.cc  */
#line 5865 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 697:

/* Line 678 of lalr1.cc  */
#line 5876 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5883 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5887 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5894 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 5898 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5905 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 5910 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 5919 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 5928 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 5932 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 5939 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 5943 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 5951 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 5960 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 5967 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 5977 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 5981 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 5988 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 5994 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 6003 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 6007 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 6014 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 6019 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 6031 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 6039 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 6051 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 6059 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 6063 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 6071 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 6075 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 6079 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 6087 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 6095 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 6099 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 6103 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 6107 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 6115 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 6123 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 6135 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 6139 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 6147 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 6165 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 742:

/* Line 678 of lalr1.cc  */
#line 6178 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 6179 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 6180 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 6181 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 6182 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 6183 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 6184 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 6185 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 6186 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 6187 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 6188 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 6189 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 6190 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 6191 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 6192 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 6197 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 6198 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 6199 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 6200 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 6201 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 6202 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 6203 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 6204 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 6205 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 6206 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 6207 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 6208 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 6209 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 6210 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 6211 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 6212 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 6213 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 6214 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 6215 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 6216 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 6217 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 6218 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 6219 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 6220 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 6221 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 6222 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 6223 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 6224 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 6225 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 6226 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 6227 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 6228 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 6229 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 6230 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 6231 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 6232 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 6233 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 6234 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 6235 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 6236 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 6237 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 6238 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 6239 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 6240 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 6241 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 6242 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 6243 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 6244 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 6245 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 6246 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 6247 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 6248 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 6249 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 6250 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 6251 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 6252 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 6253 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 6254 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 6255 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 6256 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 6257 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 6258 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 6259 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 6260 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 6261 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 6262 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 6263 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 6264 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 6265 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 6266 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 6267 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 6268 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 6269 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 6270 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 6271 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 6272 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 6273 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 6274 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 6275 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 6276 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 6277 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 6278 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 6279 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 6280 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 6281 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 6282 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 6283 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 6284 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 6285 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 6286 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 6287 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 6288 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 6289 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 6290 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 6291 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 6292 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 6293 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 6294 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 6295 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 6296 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 6297 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 6298 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 6299 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 6300 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 6301 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 6302 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 6303 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 6304 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 6305 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 6306 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 6307 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 6308 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 6309 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 6310 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 6311 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 6312 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 6313 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 6314 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 6315 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 6316 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 6317 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 6318 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 6319 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 6320 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 6321 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 6322 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 6323 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 6324 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 6325 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 6326 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 6327 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 6328 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 6329 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 6330 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 6331 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 6332 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 6333 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6334 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 896:

/* Line 678 of lalr1.cc  */
#line 6335 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 897:

/* Line 678 of lalr1.cc  */
#line 6336 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 898:

/* Line 678 of lalr1.cc  */
#line 6337 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 899:

/* Line 678 of lalr1.cc  */
#line 6338 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("deterministic"))); }
    break;

  case 900:

/* Line 678 of lalr1.cc  */
#line 6339 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nondeterministic"))); }
    break;

  case 901:

/* Line 678 of lalr1.cc  */
#line 6340 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 902:

/* Line 678 of lalr1.cc  */
#line 6341 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 903:

/* Line 678 of lalr1.cc  */
#line 6342 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 904:

/* Line 678 of lalr1.cc  */
#line 6343 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("block"))); }
    break;

  case 905:

/* Line 678 of lalr1.cc  */
#line 6344 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 906:

/* Line 678 of lalr1.cc  */
#line 6345 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 907:

/* Line 678 of lalr1.cc  */
#line 6346 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 908:

/* Line 678 of lalr1.cc  */
#line 6347 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 909:

/* Line 678 of lalr1.cc  */
#line 6348 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 910:

/* Line 678 of lalr1.cc  */
#line 6349 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 911:

/* Line 678 of lalr1.cc  */
#line 6350 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eval"))); }
    break;

  case 912:

/* Line 678 of lalr1.cc  */
#line 6351 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 913:

/* Line 678 of lalr1.cc  */
#line 6352 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 914:

/* Line 678 of lalr1.cc  */
#line 6353 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 915:

/* Line 678 of lalr1.cc  */
#line 6354 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 916:

/* Line 678 of lalr1.cc  */
#line 6355 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 917:

/* Line 678 of lalr1.cc  */
#line 6356 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 918:

/* Line 678 of lalr1.cc  */
#line 6357 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 919:

/* Line 678 of lalr1.cc  */
#line 6358 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 920:

/* Line 678 of lalr1.cc  */
#line 6359 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 921:

/* Line 678 of lalr1.cc  */
#line 6360 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 922:

/* Line 678 of lalr1.cc  */
#line 6361 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 923:

/* Line 678 of lalr1.cc  */
#line 6362 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 924:

/* Line 678 of lalr1.cc  */
#line 6363 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 925:

/* Line 678 of lalr1.cc  */
#line 6364 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 926:

/* Line 678 of lalr1.cc  */
#line 6365 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 927:

/* Line 678 of lalr1.cc  */
#line 6366 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 928:

/* Line 678 of lalr1.cc  */
#line 6367 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 929:

/* Line 678 of lalr1.cc  */
#line 6368 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 930:

/* Line 678 of lalr1.cc  */
#line 6369 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 931:

/* Line 678 of lalr1.cc  */
#line 6370 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 932:

/* Line 678 of lalr1.cc  */
#line 6371 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 933:

/* Line 678 of lalr1.cc  */
#line 6372 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 934:

/* Line 678 of lalr1.cc  */
#line 6373 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 935:

/* Line 678 of lalr1.cc  */
#line 6374 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 936:

/* Line 678 of lalr1.cc  */
#line 6375 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 937:

/* Line 678 of lalr1.cc  */
#line 6376 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 938:

/* Line 678 of lalr1.cc  */
#line 6377 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 939:

/* Line 678 of lalr1.cc  */
#line 6378 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 940:

/* Line 678 of lalr1.cc  */
#line 6379 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 941:

/* Line 678 of lalr1.cc  */
#line 6380 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 942:

/* Line 678 of lalr1.cc  */
#line 6381 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 943:

/* Line 678 of lalr1.cc  */
#line 6382 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 944:

/* Line 678 of lalr1.cc  */
#line 6383 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 945:

/* Line 678 of lalr1.cc  */
#line 6384 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 946:

/* Line 678 of lalr1.cc  */
#line 6385 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 947:

/* Line 678 of lalr1.cc  */
#line 6386 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 948:

/* Line 678 of lalr1.cc  */
#line 6387 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 949:

/* Line 678 of lalr1.cc  */
#line 6388 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 950:

/* Line 678 of lalr1.cc  */
#line 6389 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 951:

/* Line 678 of lalr1.cc  */
#line 6390 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 952:

/* Line 678 of lalr1.cc  */
#line 6391 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 953:

/* Line 678 of lalr1.cc  */
#line 6392 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 954:

/* Line 678 of lalr1.cc  */
#line 6393 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 955:

/* Line 678 of lalr1.cc  */
#line 6394 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 956:

/* Line 678 of lalr1.cc  */
#line 6395 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 957:

/* Line 678 of lalr1.cc  */
#line 6396 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 958:

/* Line 678 of lalr1.cc  */
#line 6401 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { 
          // EQName's namespace URI value is whitespace normalized according to the rules for the xs:anyURI type
          std::string uri = "\"" + SYMTAB((yysemantic_stack_[(3) - (1)].sval)) + "\"";
          std::string eqname = SYMTAB(driver.symtab.put_uri(uri.c_str(), uri.size())) + ":" + SYMTAB((yysemantic_stack_[(3) - (3)].sval));
          (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT(eqname.c_str())), true); 
        }
    break;

  case 959:

/* Line 678 of lalr1.cc  */
#line 6407 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 678 of lalr1.cc  */
#line 11483 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1349;
  const short int
  xquery_parser::yypact_[] =
  {
      2319, -1349, -1349,  2618,  2916,  3214, -1349, -1349,    38,  1052,
     127, -1349, -1349, -1349,   505, -1349, -1349, -1349, -1349,   130,
     279,   557, -1349,   529,   377,   399,   589, -1349,   -19, -1349,
   -1349, -1349, -1349, -1349, -1349, -1349,   582, -1349,   419,   475,
   -1349,   564, -1349, -1349,   567, -1349,   597, -1349,   566,   584,
   -1349,   208, -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349,
   -1349, -1349, -1349, -1349, -1349,   338,   403, -1349, -1349, -1349,
   -1349,   501,  8578, -1349, -1349, -1349,   656, -1349, -1349, -1349,
   -1349, -1349,   658,   674, -1349, -1349, 11758, -1349, -1349, -1349,
   -1349, -1349, -1349, -1349, -1349,   633, -1349, -1349,   679,   680,
   -1349, -1349, -1349, -1349, -1349, -1349, -1349,  3512, 11758, -1349,
   -1349, -1349, -1349, -1349, -1349, -1349,   650, -1349, -1349,   683,
    9464, -1349,  9756,   684,   685, -1349, -1349, -1349,   686, -1349,
    8280, -1349, -1349, -1349, -1349, -1349, -1349,   657, -1349, -1349,
   -1349, -1349, -1349, -1349, -1349, -1349,    39,   594, -1349, -1349,
   -1349, -1349, -1349, -1349, -1349, -1349,   186,   655,   215, -1349,
     588,   269, -1349, -1349, -1349, -1349, -1349, -1349,   695, -1349,
     672,   585,   586,   587, -1349, -1349,   675,   681, -1349, -1349,
   -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349,
   -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349,
   -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349,
   -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349,
   -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349,
   -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349,
    5598,   827, -1349,  5896, -1349, -1349,   107,    41,    63, -1349,
   -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349,
   -1349, -1349, -1349, -1349, -1349, -1349, -1349,   497, -1349, -1349,
   -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349,
   -1349,     0, -1349, -1349, -1349, -1349,   342, -1349, -1349, -1349,
   -1349, -1349, -1349,   665,   740, -1349,   568,   590,   428,   371,
     429,   449, -1349,   784,   637,   736,   738,  6194, -1349, -1349,
   -1349,   -16, -1349, -1349,  8280, -1349,   124, -1349,   688,  8578,
   -1349,   688,  8578, -1349, -1349, -1349,   506, -1349, -1349, -1349,
   -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349,
   -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349,
   -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349,
   -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349,   717,
     698,   689, -1349, -1349, -1349, -1349, -1349, -1349,   660, -1349,
     662, -1349,   663,   693,   823,   395,   481,   243, 12044, 11758,
     -45,   804,   805,   808, 11758,   705,   744,   347,  9464, -1349,
   -1349,   545,   402,   618, 11758, -1349, -1349, -1349, -1349, -1349,
     570, 11758,   571,   572,   431,   561,   378, -1349,   293, -1349,
   -1349, -1349, -1349, -1349,  9464,  6492,   687,  6492,    80,  6492,
   10328,   592,   593, 11758,   748,   -14,   715,  6492,   869,    56,
     148, 11758,   754,   731,   768, -1349,  6492,  9170, 11758, 11758,
   11758, 11758,  6492,   691,  6492,  6492, 11758,  6492,   726,   727,
   -1349, -1349, -1349,  6492, 10614, -1349,   725, -1349,   728, -1349,
   -1349, -1349, -1349,   729, -1349, -1349,   730, -1349, -1349, -1349,
   -1349, -1349,   732, -1349, -1349, -1349, -1349, -1349, -1349, -1349,
   -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349,
   -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349,
   -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349,
   -1349, -1349, 11758, -1349, -1349, -1349,   696,   848,  6492, -1349,
   -1349,    66, -1349, -1349, -1349,   870, -1349, -1349, -1349, -1349,
    6492,   678, -1349,   864,  6492,  6492,   706,  6492,  6492,  6492,
    6492,   664, 11758, -1349, -1349, -1349, -1349,  6492,  6492,  6492,
   -1349, -1349, -1349, -1349,  1052,   589,    65,    70,   891,  6790,
    6790,  7088,  7088,   756,  6492,  6492, -1349,  6492,   778,   529,
     -19,   737,   739,   742,  6492,  6492, -1349, -1349, -1349, -1349,
   -1349, -1349, -1349,  7386,  7386,  7386, -1349,  7386,  7386, -1349,
    7386, -1349,  7386, -1349, -1349, -1349, -1349, -1349, -1349, -1349,
    7386,  7386,   828,  7386,  7386,  7386,  7386,  7386,  7386,  7386,
    7386,  7386,  7386,  7386,   669,   807,   809,   811, -1349, -1349,
   -1349,  3810, -1349, -1349,  8280,  8280,  6492,   688, -1349, -1349,
     688, -1349,  4108,   688,  9464,   758,  4406, -1349, -1349, -1349,
     185, -1349, -1349, -1349, -1349, -1349,   801,   803,   377,   885,
   -1349, -1349, 12044, -1349, 12044,   734,   464, 11758,   755,   757,
     734,   823,   787,   786, -1349, -1349, -1349, -1349, -1349,    47,
     670,   -18, -1349,   620, -1349, -1349, -1349, -1349, 11758, 11758,
   11758, -1349,   802, -1349, -1349,   789,   741, -1349,   743,   728,
     475, -1349,   735,   745,   746, -1349,   -13,    13, -1349, -1349,
     816, -1349,    18, 11758,    -7, 11758,   829,   123, -1349,  6492,
   -1349,   749, -1349,  9464,   831,   881,  9464,   823,   832,   305,
   11758,  6492,   -19,   747,   750, -1349,   752,   753,   759,   791,
      -4, -1349,    31,   751, -1349,   762,   765,   788, -1349,   760,
    6492,  6492,   769, -1349,   224,   231,   200, -1349, 11758,   848,
   -1349,    82,   770, -1349, -1349, -1349,   771, -1349,   183, -1349,
   -1349, -1349,   103,   119,   847,   707,   733,   -17, -1349,   817,
    7684, -1349,   773,   774,   107,   349,   929,   929, -1349,    78,
   -1349, -1349,    83, -1349, -1349,   908, -1349, -1349, -1349, -1349,
    6492, -1349, -1349,     2, 11758,   792,  6492,   845, -1349, -1349,
     740, -1349, -1349, -1349, -1349, -1349,  7386, -1349, -1349, -1349,
      30,   371,   371,   382,   429,   429,   429,   429,   449,   449,
   -1349, -1349, 11186, 11186, 11758, 11758, -1349,   781, -1349, -1349,
     783, -1349, -1349, -1349,   275, -1349, -1349, -1349,   307, -1349,
     316, -1349,   -12,   485,   354, -1349,   377,   377, -1349, -1349,
   -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349,   734, -1349,
     838, 11472,   830,  6492, -1349, -1349, -1349,   876,   823,   823,
     734, -1349,   617,   823,   465, 11758,   369,   390,   946, -1349,
   -1349,   692,    14, -1349, -1349, -1349, -1349, -1349, -1349, -1349,
   -1349, -1349, -1349, -1349,    47,   105,   463, -1349,   761,   391,
      28,   682, 11758,   823, -1349, -1349, -1349, -1349,   824, 11758,
   -1349, 11758, -1349,   861,   853, 11186,   865,  6492,   -77,   835,
      17,   322,   763, -1349, -1349,   503,    -7,   876, 11186,   867,
     894,   806,   794,   854,   823,   833,   860,   897,   823,  6492,
     -36, -1349, -1349, -1349,   842, -1349, -1349, -1349, -1349,  6492,
     878,  6492,  6492,   850, -1349,   899,   901,  6492, -1349,   818,
     819,   851, 11758, -1349, 11758, -1349,  6492,   971, -1349,   220,
   -1349,    72, -1349, -1349,   978, -1349,   487,  6492,  6492,  6492,
     546,  6492,  6492,  6492,  6492,  6492,  6492,   889,  6492,  6492,
     890,     3,   825,   672,   766,    86,    20,   908,  7088,  7088,
    7088,   930, -1349, -1349, -1349,  6492,    36,   905, -1349, 11758,
     906, -1349, -1349,  6492,    30,   459,   -15, -1349,   764,   102,
     767,   775, -1349, -1349,   618, -1349,   772,   304,   858,   859,
   11472,   862, -1349,   427, -1349, -1349, -1349, -1349, -1349, -1349,
   -1349, -1349, -1349,   879, -1349, -1349, -1349,  6492, -1349, -1349,
     185, -1349, -1349, -1349, -1349, -1349, -1349,  6492, -1349,   439,
     458, -1349,   994,   575, -1349, -1349, -1349, -1349, -1349, -1349,
   -1349, -1349, -1349,   776, -1349, -1349,   996, -1349, -1349, -1349,
   -1349, -1349,   389,   998, -1349,   528, -1349, -1349, -1349,   725,
     279,   729,   419,   730,   732,   655,   793,   427,   810,   812,
    7982,   777,   721,   105, -1349,   814,   876,   840,  4704,   841,
     844,   893,   846,   855, 11758,    24, -1349, 11758, -1349,  6492,
     887,  6492,   914,  6492,   -54,   896,  6492,   900, -1349,   926,
     928,  6492, 11758,   629,   970, -1349, -1349, -1349, -1349, -1349,
   -1349, 11186, -1349,  6492,   823,   943, -1349, -1349, -1349,   823,
     943, -1349,  6492,   909,  5002, -1349, 11758, -1349, -1349,  6492,
    6492,   578, -1349,     1, 10900,   579, -1349,   868, -1349, -1349,
    5300,   871,   872, -1349, -1349,   922, -1349,    85, -1349, -1349,
    1047, -1349, -1349, 11758, -1349, -1349,   386, -1349, -1349, -1349,
     873,   836,   837, -1349, -1349, -1349,   843,   849, -1349, -1349,
   -1349, -1349, -1349,   821, 11758,   874, -1349, 11758, -1349,   890,
   -1349, -1349, -1349,  8876,   766, -1349,   929,   327, -1349, -1349,
   -1349,   905, -1349,   823, -1349,   640, -1349,   438,   955, -1349,
    6492,   959,   845,   883,   886, -1349,    30,   820, -1349, -1349,
     -94, -1349,   413,    44,   822,    30,   413,  7386, -1349,    22,
   -1349, -1349, -1349, -1349, -1349, -1349,    30,   927,   797,   670,
      44, -1349, -1349,   796,  1004, -1349, -1349, -1349, 10042,   898,
     907,   910, -1349, -1349, -1349, -1349, -1349, -1349, -1349,   902,
   -1349, -1349, -1349,  6492, -1349, -1349, -1349, -1349,  1056,   312,
    1059,   312,   834,   986, -1349, -1349, -1349, -1349,   931, 11758,
     839,   793,  7982, -1349, -1349, -1349,   915, -1349, -1349, -1349,
   -1349, -1349, -1349,  6492,   951, -1349, -1349,  6492, -1349,   255,
   -1349,  6492,   957,  6492, -1349,  6492, 11758, 11758, -1349,    75,
   -1349,  6492, -1349,   976,  1009,   823,   943, -1349,  6492, -1349,
     923, -1349, -1349, -1349,   932, -1349,  6492,  6492, 11758,   934,
      40, -1349, -1349, -1349,   924, -1349, -1349,   971, 11758,   393,
   -1349,   971, 11758, -1349, -1349,  6492,  6492,  6492,  6492,  6492,
   -1349,  6492,   326, -1349, -1349,   385, -1349, -1349, -1349, -1349,
     955, -1349, -1349, -1349,   823, -1349, -1349, -1349, -1349, -1349,
     937,  7386, -1349, -1349, -1349, -1349, -1349,   227,  7386,  7386,
     408, -1349,   767, -1349,   250, -1349,   775,    30,   960, -1349,
   -1349,   856, -1349, -1349, -1349, -1349,  1017,   936, -1349,   333,
   -1349, -1349, -1349, -1349,   235, -1349,   301,   301, -1349,   312,
   -1349, -1349,   336, -1349,  1086,    44,  1018,   938,  7982,   -79,
     852, -1349,   954, -1349, -1349,  6492, -1349,  6492,   969, -1349,
    6492, -1349, -1349, -1349,  1072, -1349, -1349,  6492,   823, -1349,
   -1349, -1349,  6492, -1349, -1349,  1034,  6492, 11758,  6492, -1349,
      -2,   971, 11758,   935,   971, -1349, -1349, -1349, -1349, -1349,
   -1349,  6492,   988,  1015,  8876, -1349, -1349, -1349, -1349,   429,
    7386,  7386,   382,   451, -1349, -1349, -1349, -1349, -1349, -1349,
    6492, -1349, 11186, -1349, 11186,  1039, -1349, -1349, -1349, -1349,
    1107, -1349, -1349, -1349,   875,  1031, -1349, -1349,  1035, -1349,
     591, 11758,  1023,   920, 11758,  7982, -1349, -1349,  6492, -1349,
    1027, -1349,   943, -1349, 11186, -1349,   961, -1349,   179,    81,
   -1349,   952,   971, -1349,   953, -1349,  6492, 11758, -1349,   382,
     382,  7386,   967, -1349, -1349, 11186, -1349, -1349,  1018,  7982,
   -1349,   955,   857, 11758,  1036,   933,  1035, -1349, 11758,   972,
    6492, -1349, -1349,  1061,   381, -1349, -1349, -1349, -1349,   973,
     374, -1349, -1349, -1349,   963, -1349, -1349,   337,   382, -1349,
   -1349, -1349, -1349, -1349,  6492,   866, 11758,  1042, -1349,  6492,
   -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349,  1043,  1013,
   -1349,   877,   880, 11758, -1349, 11758, -1349,   863,  6492,   882,
     345,  7982, -1349,  7982,  1049,  1013, -1349,   974, 11758, -1349,
     888,   987, 11758,  1013,   956, -1349,  1058, 11758,   884,  7982,
   -1349
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   430,   431,     0,     0,     0,   758,   959,   584,   849,
     858,   799,   763,   761,   743,   850,   853,   806,   899,   767,
     744,   745,   911,   798,   859,   747,   856,   828,   808,   783,
     803,   900,   804,   854,   851,   802,   749,   857,   750,   751,
     897,   913,   896,   800,   819,   813,   752,   801,   754,   753,
     898,   837,   805,   780,   923,   924,   925,   926,   927,   928,
     929,   930,   931,   932,   933,   947,   954,   827,   823,   814,
     794,   742,     0,   822,   830,   838,   948,   818,   450,   795,
     796,   852,   949,   955,   815,   832,     0,   456,   419,   452,
     825,   760,   816,   817,   845,   820,   836,   844,   953,   956,
     766,   807,   847,   451,   835,   840,   746,     0,     0,   367,
     833,   843,   848,   846,   826,   812,   901,   810,   811,   950,
       0,   366,     0,   951,   957,   841,   797,   821,   952,   397,
       0,   429,   842,   824,   831,   839,   834,   902,   788,   793,
     792,   791,   790,   789,   755,   809,     0,   759,   855,   781,
     888,   887,   889,   765,   764,   784,   894,   748,   886,   891,
     892,   883,   787,   829,   885,   895,   893,   884,   785,   890,
     904,   907,   908,   905,   906,   903,   756,   909,   910,   912,
     875,   874,   861,   779,   772,   868,   864,   782,   778,   877,
     878,   768,   769,   762,   771,   873,   872,   869,   865,   882,
     876,   871,   867,   860,   770,   881,   880,   774,   776,   775,
     866,   870,   862,   777,   863,   773,   879,   934,   935,   936,
     937,   938,   939,   915,   916,   914,   920,   921,   922,   917,
     918,   919,   786,   940,   941,   942,   943,   944,   945,   946,
       0,     0,     2,     0,     5,     7,    19,     0,     0,    24,
      27,    38,    30,    31,    32,    58,    33,    42,    34,    62,
      63,    64,    59,    60,    66,    67,    37,     0,    35,    36,
      40,    41,    61,   220,   219,   216,   217,   218,    39,    14,
     197,   198,   202,   204,   235,   241,     0,   233,   234,   205,
     206,   207,   208,   209,   322,   324,   326,   336,   340,   342,
     345,   350,   353,   356,   358,   360,   362,     0,   364,   370,
     372,     0,   388,   371,   393,   396,   398,   401,   403,     0,
     408,   405,     0,   416,   426,   428,   402,   432,   439,   448,
     440,   441,   442,   445,   446,   443,   444,   463,   465,   466,
     467,   464,   512,   513,   514,   515,   516,   517,   425,   558,
     550,   557,   556,   555,   552,   554,   551,   553,   449,   447,
     585,   586,    65,   210,   211,   213,   212,   214,   215,     0,
     427,   741,   757,   849,   858,   856,   519,   759,     0,   523,
       0,   529,     0,   175,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   118,
     119,     0,     0,     0,     0,   114,   115,   116,   117,   124,
       0,     0,     0,     0,     0,     0,     0,   112,     0,   173,
     179,   181,   184,   183,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   260,   261,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     421,   424,   411,     0,     0,   738,   743,   767,   745,   798,
     859,   747,   808,   749,   913,   819,   752,   754,   753,   837,
     947,   954,   742,   948,   949,   955,   820,   953,   956,   901,
     950,   951,   957,   952,   902,   894,   886,   892,   883,   785,
     904,   907,   908,   905,   756,   909,   417,   427,   741,   409,
     410,   413,   743,   744,   745,   749,   750,   751,   752,   742,
     748,   453,     0,   415,   414,   454,     0,   479,     0,   420,
     739,     0,   740,   391,   392,     0,   423,   422,   412,   395,
       0,     0,   508,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   161,   158,   171,   172,     0,     0,     0,
       3,     1,     6,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   110,     0,     0,   200,   199,     0,     0,
       0,     0,     0,     0,     0,     0,   221,   240,   236,   242,
     237,   239,   238,     0,     0,     0,   381,     0,     0,   379,
       0,   331,     0,   380,   373,   378,   377,   376,   375,   374,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   369,   368,
     365,     0,   389,   394,     0,     0,     0,   404,   436,   407,
     406,   418,     0,   433,     0,     0,     0,   520,   524,   530,
       0,    85,    70,    71,   152,   153,     0,     0,     0,     0,
      76,    77,     0,   182,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   595,   596,   597,   121,   120,     0,
      75,   128,   125,     0,   127,   126,   123,   122,     0,     0,
       0,   113,     0,   174,   180,     0,     0,   564,     0,     0,
       0,   560,     0,     0,     0,   574,     0,     0,   223,   224,
     243,   244,     0,     0,     0,     0,   154,     0,   191,     0,
     588,     0,    68,     0,    94,     0,     0,     0,    86,     0,
       0,     0,     0,     0,   738,   565,     0,     0,     0,     0,
       0,   305,     0,     0,   563,     0,     0,     0,   582,     0,
       0,     0,     0,   568,     0,     0,     0,   455,   480,   479,
     476,     0,     0,   510,   509,   390,     0,   507,     0,   608,
     609,   559,     0,     0,     0,     0,     0,     0,   614,     0,
       0,   169,     0,     0,    20,     0,    21,     0,     4,     0,
      25,    11,     0,    26,    15,   849,    28,    12,    29,    16,
       0,   109,   203,     0,     0,     0,     0,     0,   222,   278,
     323,   325,   329,   335,   334,   333,     0,   330,   327,   328,
       0,   344,   343,   341,   347,   348,   349,   346,   351,   352,
     355,   354,     0,     0,     0,     0,   386,     0,   399,   400,
       0,   437,   434,   461,     0,   958,   587,   459,     0,   584,
       0,   177,     0,     0,     0,    74,     0,     0,    48,    50,
      51,    52,    53,    55,    56,    57,    49,    54,    44,    45,
       0,     0,   102,     0,    98,   100,   101,   105,     0,     0,
      43,    84,     0,     0,     0,     0,     0,     0,     0,   688,
     693,     0,     0,   689,   723,   676,   678,   679,   680,   682,
     684,   683,   681,   685,     0,     0,     0,   129,     0,     0,
     132,     0,     0,     0,   528,   518,   561,   562,     0,     0,
     578,     0,   575,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   225,   226,     0,   231,   193,     0,     0,
     155,     0,     0,     0,     0,     0,     0,    87,     0,     0,
       0,   259,   265,   262,     0,   567,   566,   573,   581,     0,
       0,     0,     0,     0,   527,     0,     0,     0,   382,     0,
       0,     0,     0,   571,     0,   569,     0,   479,   477,     0,
     468,     0,   457,   458,     0,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     849,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   111,   201,   232,     0,   289,   285,   287,     0,
     279,   280,   332,     0,     0,     0,     0,   654,   338,   627,
     631,   633,   635,   637,   640,   647,   648,   656,   859,   746,
       0,   755,   357,   536,   542,   543,   545,   589,   590,   546,
     549,   359,   361,   533,   363,   387,   438,     0,   435,   460,
       0,   176,    82,    83,    80,    81,   186,     0,   185,     0,
       0,    46,     0,     0,   103,   104,   106,    72,    73,    78,
      79,    69,   694,     0,   697,   724,     0,   687,   686,   691,
     690,   722,     0,     0,   699,     0,   695,   698,   677,     0,
       0,     0,     0,     0,     0,     0,   130,   136,     0,     0,
       0,     0,     0,     0,   133,     0,   107,     0,     0,     0,
       0,   582,     0,     0,     0,     0,   535,     0,   246,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   227,     0,
       0,     0,     0,   272,     0,   269,   274,   230,   194,   156,
     192,     0,   195,     0,     0,    96,    90,    93,    92,     0,
      88,   263,     0,     0,     0,   168,     0,   303,   307,     0,
       0,     0,   310,     0,     0,     0,   317,     0,   384,   383,
       0,     0,     0,   304,   480,     0,   469,     0,   503,   500,
       0,   504,   505,     0,   506,   499,     0,   474,   502,   501,
       0,     0,     0,   601,   602,   598,     0,     0,   606,   607,
     603,   612,   610,     0,     0,     0,   616,     0,   163,     0,
     160,   159,   170,     0,   617,   618,    22,     0,    13,    17,
      18,   286,   298,     0,   299,     0,   290,   291,   292,   293,
       0,   282,     0,     0,     0,   638,   651,     0,   337,   339,
       0,   670,     0,     0,     0,     0,     0,     0,   626,   628,
     629,   665,   666,   667,   669,   668,     0,     0,   642,   641,
       0,   645,   649,   663,   661,   660,   653,   657,     0,     0,
       0,     0,   539,   541,   540,   537,   534,   462,   178,     0,
     188,   187,   190,     0,    47,    99,   711,   692,     0,   716,
       0,   716,   705,   700,   131,   137,   139,   138,     0,     0,
       0,   134,     0,   108,    23,   521,     0,   579,   580,   583,
     576,   577,   245,     0,     0,   258,   250,     0,   254,     0,
     248,     0,     0,     0,   267,     0,     0,     0,   229,   270,
     273,     0,   157,     0,    95,     0,    89,   264,     0,   531,
       0,   306,   308,   313,     0,   311,     0,     0,     0,     0,
       0,   318,   385,   525,     0,   572,   570,   479,     0,     0,
     511,   479,     0,   475,    10,     0,     0,     0,     0,     0,
     615,     0,   164,   162,   624,     0,   619,   302,   300,   301,
     294,   295,   296,   288,     0,   283,   281,   655,   646,   652,
       0,     0,   725,   726,   736,   735,   734,     0,     0,     0,
       0,   727,   632,   733,     0,   630,   634,     0,     0,   639,
     643,     0,   664,   659,   662,   658,     0,     0,   547,     0,
     544,   594,   538,   196,     0,   712,     0,     0,   710,   717,
     718,   714,     0,   709,     0,   707,     0,     0,     0,     0,
       0,   135,     0,   522,   247,     0,   256,     0,     0,   252,
       0,   255,   268,   276,   277,   271,   228,     0,     0,    91,
     266,   532,     0,   314,   312,     0,     0,     0,     0,   526,
       0,   479,     0,     0,   479,   599,   600,   604,   605,   611,
     613,     0,   165,     0,     0,   620,   297,   284,   650,   737,
       0,     0,   729,     0,   675,   674,   673,   672,   671,   636,
       0,   728,     0,   591,     0,     0,   189,   721,   720,   719,
       0,   713,   706,   704,     0,   701,   702,   696,   140,   142,
     144,     0,     0,     0,     0,     0,   251,   249,     0,   257,
       0,   321,    97,   309,     0,   319,     0,   315,   489,   483,
     478,     0,   479,   470,     0,   166,     0,     0,   625,   731,
     730,     0,     0,   592,   548,     0,   715,   708,     0,     0,
     146,   145,     0,     0,     0,     0,   141,   253,     0,     0,
       0,   497,   491,     0,   490,   492,   498,   495,   485,     0,
     484,   486,   496,   472,     0,   471,   167,     0,   732,   644,
     593,   703,   143,   147,     0,     0,     0,     0,   275,     0,
     316,   482,   493,   494,   481,   487,   488,   473,     0,     0,
     148,     0,     0,     0,   320,     0,   621,     0,     0,     0,
       0,     0,   150,     0,     0,     0,   149,     0,     0,   622,
       0,     0,     0,     0,     0,   623,     0,     0,     0,     0,
     151
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1349, -1349,  -228,   940, -1349,   939,   942, -1349,   944,  -224,
    -516,  -531, -1349,   507,  -714, -1349, -1349, -1349, -1349, -1349,
   -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349,  -927,
   -1349, -1349, -1349, -1349,   108,   306, -1349, -1349, -1349,   798,
   -1349,    73,  -880, -1349,  -352,  -377, -1349, -1349,  -595, -1349,
    -876, -1349, -1349,   -26, -1349, -1349, -1349, -1349, -1349,   790,
   -1349, -1349,   795,   813, -1349, -1349, -1349,   268,   779, -1348,
    -526,     8, -1349,  -573,   724, -1349, -1349, -1349, -1349,   276,
   -1349, -1349,   941, -1349, -1349, -1349, -1349,    92,  -695,  -686,
   -1349, -1349,   489, -1349, -1349,  -122,    76, -1349, -1349, -1349,
     -20, -1349, -1349,   209,   -11, -1349, -1349,    -9, -1209, -1349,
     701,    59, -1349, -1349,    55, -1349, -1349, -1349,    58, -1349,
   -1349,   638,   636, -1349,  -525, -1349, -1349,  -612,   168,  -610,
     164,   167, -1349, -1349, -1349, -1349, -1349,   925, -1349, -1349,
   -1349, -1349,  -802,  -301, -1078, -1349,  -114, -1349, -1349, -1349,
   -1349, -1349, -1349, -1349,   -38, -1196, -1349, -1349,   407,    57,
   -1349,  -619, -1349, -1349, -1349, -1349, -1349, -1349, -1349,   595,
   -1349,  -948, -1349,    48, -1349,   477,  -758, -1349, -1349, -1349,
   -1349, -1349,  -356,  -346, -1149,  -961, -1349, -1349, -1349, -1349,
   -1349, -1349, -1349, -1349, -1349, -1349,   405,  -727,  -808,   136,
    -791, -1349,   -48,  -809, -1349, -1349, -1349, -1349, -1349, -1349,
   -1349,   826,   892,  -391,   323,   173, -1349, -1349, -1349, -1349,
   -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349, -1349,
      32, -1349, -1349,    23, -1349,  -989, -1349, -1349, -1349,    -6,
     -10,  -167,   226, -1349, -1349, -1349, -1349, -1349, -1349, -1349,
   -1349, -1349, -1349, -1349, -1349, -1349,    -1, -1349, -1349, -1349,
    -161,   221,   353, -1349, -1349, -1349, -1349, -1349,   165, -1349,
   -1349, -1347, -1349, -1349, -1349,  -644, -1349,   -42, -1349,  -178,
   -1349, -1349, -1349, -1349, -1202, -1349,     6, -1349,  -379,  -359,
      25,   -72, -1349
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   241,   787,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   868,   869,   870,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,  1155,
     727,   265,   266,   874,   875,   876,   267,   268,   416,   417,
     269,  1106,   907,   270,  1528,  1529,   271,   272,   436,   273,
     554,   780,  1001,  1218,   274,   275,   276,   277,   418,   419,
     850,   278,   420,   421,   422,   423,   717,   718,  1194,  1068,
     279,   280,   577,   281,   282,   283,   586,   434,   935,   936,
     284,   587,   285,   589,   286,   287,   710,   711,  1143,   443,
     288,   444,   445,   714,  1144,  1145,  1146,   590,   591,  1020,
    1021,  1395,   592,  1017,  1018,  1236,  1237,  1238,  1239,   289,
     740,   741,   290,  1171,  1172,  1173,   291,  1175,  1176,   292,
     293,   294,   295,   816,   296,  1248,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   610,   611,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   637,   638,
     327,   328,   329,   330,   331,   332,   333,   334,   335,   844,
     336,   337,   338,  1196,   759,   760,   761,  1550,  1589,  1590,
    1583,  1584,  1591,  1585,  1197,  1198,   339,   340,  1199,   341,
     342,   343,   344,   345,   346,   347,  1052,   930,  1042,  1285,
    1043,  1429,  1044,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   747,  1120,   358,   359,   360,   361,  1046,
    1047,  1048,  1049,   362,   363,   364,   365,   366,   367,   777,
     778,   368,  1224,  1225,  1385,  1028,  1258,  1259,  1029,  1030,
    1031,  1032,  1033,  1268,  1419,  1420,  1034,  1271,  1035,  1400,
    1036,  1037,  1276,  1277,  1425,  1423,  1260,  1261,  1262,  1263,
    1507,   680,   895,   896,   897,   898,   899,   900,  1096,  1447,
    1525,  1097,  1445,  1523,   901,  1301,  1442,  1438,  1439,  1440,
     902,   903,  1264,  1272,  1410,  1265,  1406,  1249,   369,   531,
     370,   371,   372
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int xquery_parser::yytable_ninf_ = -739;
  const short int
  xquery_parser::yytable_[] =
  {
       508,   979,   950,   823,   803,   651,   824,   825,   826,   827,
     632,   378,   380,   382,   508,   963,   539,   928,  1026,   570,
     572,  1160,   567,  1045,  1045,  1051,   929,  1384,  1391,  1392,
    1114,   851,  1308,  1195,   506,  1244,   508,  1495,  1531,   673,
     796,   798,   568,   791,   794,   797,   799,  1373,   508,   932,
     508,  1132,   924,   790,   793,   384,   385,   849,   386,   387,
     724,   728,  1045,   854,   568,   695,   568,   541,  1421,  1129,
     812,   568,   813,   814,   763,   815,   905,   817,   390,   568,
    1073,  1188,  1189,   465,   568,   818,   819,   568,   736,   997,
    1188,  1548,  1331,   919,  1188,  1189,  1107,   507,   441,  1526,
    1356,   884,   960,   715,   885,  1162,   575,  1587,   575,  1219,
    1093,   521,   925,   926,   926,   526,  1045,  1126,  1250,   921,
     926,  1402,  1113,   660,   699,   925,  1094,  1222,  1139,  1045,
    1149,  1232,  1227,   527,  1140,  1062,   631,  1246,   564,    78,
    1407,  1233,  1099,   700,  1532,   532,   886,   535,  1100,   699,
    1076,  1234,  1063,    89,  1071,   661,   565,  1477,  -738,  1403,
     122,   122,  1235,  1133,   927,  1101,  1071,  1102,   700,  1095,
    1323,   926,   716,   920,  1190,   465,  1103,   962,   103,   398,
    1549,  1496,  1023,   961,  1581,  1024,  1357,  1190,  1188,   576,
    1251,  1013,  1220,  1291,  1191,   442,  1192,   986,  1250,   922,
     633,  1027,  1104,  1191,  1137,  1192,   122,  1191,   933,  1192,
    1148,   980,   849,   990,  1588,   723,   998,   906,   442,  1185,
    1373,  1601,  1026,  1026,   719,  1478,  1304,  1533,   108,   939,
     569,  1045,  1346,   719,  1452,  1134,   442,   719,   401,  1195,
     764,   108,  1130,  1524,  1135,   120,   934,   508,  1195,  1280,
     508,   542,   571,   442,   784,   796,   798,  1399,   120,   786,
     725,  1069,  1070,   906,  1163,  1193,   701,  1008,   790,   793,
    1251,  1626,  1010,  1252,  1253,  1226,  1254,   981,  1368,  1500,
     403,   639,   427,   146,   641,   845,   424,  1639,  1025,   442,
     442,  1022,   881,  1256,    78,  1645,   146,   887,  1558,  1408,
    1409,  1191,   456,  1192,  1107,  1257,   960,   726,    89,   940,
     888,  1582,   889,   984,   634,   635,   658,   508,   383,   987,
     988,  1570,   508,   890,   891,   892,   508,   893,  1105,   894,
     972,   719,   508,   103,   989,   991,   992,   974,   785,   508,
     388,   575,  1045,  1342,   507,   789,   792,   507,   947,  1186,
     993,   926,   508,  1252,  1253,  1501,  1254,   391,   508,   392,
     457,   508,  1603,  1255,   943,  1045,  1359,   946,   393,   508,
    1530,   668,   985,  1256,   669,   508,   508,   508,   508,   508,
    1006,  1057,   578,  1188,   508,  1257,  1581,   976,   579,  1313,
    1188,   668,   508,   580,   669,  1188,  1189,  1298,   565,   925,
    1587,  1457,  1188,  1189,   692,  1027,  1027,   613,   656,   544,
     973,   545,   581,  1057,   659,  1187,   925,   975,  1516,   665,
     925,  1195,  1060,   532,   657,   614,   670,   458,   459,   681,
    1324,  1451,   671,   696,   428,   698,   683,   704,   547,  1514,
     548,  1288,  1520,  1618,  1026,   721,   949,  1436,  1332,   532,
     508,  1634,   671,  1026,   733,   707,  1300,  1530,   712,   460,
     743,  1058,   745,   746,  1026,   749,   729,  1491,  1136,  1045,
    1428,   752,   532,   737,   738,   739,   742,   796,   798,   796,
     508,   748,  1228,  1229,  1230,  1298,   849,   616,  1190,   755,
    1066,  1530,   550,  1059,   672,  1190,  1191,   551,  1192,  1077,
    1078,  1299,  1061,  1191,  1081,  1192,  1067,  1615,  1191,   582,
    1192,  1437,   583,  1612,   672,  1191,   617,  1192,  1504,  1515,
     838,   839,  1521,  1619,   461,  1505,   719,   584,  1119,   618,
    1122,  1635,   435,   719,  1117,  1506,   762,  1067,   719,   613,
    1493,  1542,   108,  1233,  1300,   719,   399,   742,   766,   108,
    1273,  1274,   585,  1636,   437,  1637,  1139,   614,   871,   120,
    1005,  1009,  1140,   619,  1235,  1156,   120,   783,    78,  1156,
    1282,  1650,   508,  1275,   448,  1290,   652,   779,   400,  1372,
    1141,  1181,    89,  1182,   622,   613,  1482,  1586,  1592,   653,
     856,   553,   857,  1494,  1292,   508,   431,   146,   623,   926,
     872,   432,  1283,   614,   146,   873,   402,   103,   613,  1480,
    1293,  1023,   438,  1483,  1024,  1026,   508,   508,   508,  1284,
    1142,   439,   462,  1586,  1093,   615,   614,  1027,   620,  1592,
     449,  1087,  1064,   573,  1458,   122,  1027,   621,   574,   837,
    1094,   508,  1088,   508,   840,  1414,   433,  1027,  1561,  1065,
     440,   508,  1089,   463,   508,  1492,   464,   425,   508,   636,
     426,   642,   654,  1090,   689,   405,   406,   407,   408,   532,
     409,   410,   690,   412,   413,   655,  1504,  1170,  1174,   414,
    1404,   450,  1139,  1505,   451,   925,   508,  1405,  1140,  1111,
    1354,  1360,   877,  1506,   841,   796,  1233,   841,  1112,   595,
     841,   677,   678,  1045,  1563,  1045,  1564,   596,   597,   429,
     598,   872,   430,   909,   910,   911,   873,  1201,   599,  1202,
    1434,   454,   600,  1551,   601,   632,  1554,   941,   640,   602,
     686,   687,   508,   643,   446,  1045,  1579,   447,   931,   455,
     937,  1082,  1083,  1084,  1079,  1080,   603,  1085,   532,   452,
     522,   532,   453,  1108,  1109,   951,  1045,  1600,   969,   970,
     508,   508,   508,   508,   674,   675,   676,  1388,  1389,   604,
     605,   606,   607,   608,   609,  1344,  1206,   509,  1207,   510,
    1156,   821,   822,   977,   828,   829,  1053,  1053,  1002,   830,
     831,  1499,  1517,  1518,  1594,   511,  1502,  1503,  1027,   508,
     523,   524,   528,  1571,   529,   536,   537,   538,   543,   540,
     546,   549,   552,   508,   858,   859,   860,   861,   862,   863,
     864,   865,   866,   867,   553,   555,   556,   561,   557,  1014,
     558,   593,   594,   559,   624,   625,   626,   644,   612,   627,
     508,   636,   645,   647,   646,   648,   649,   508,   650,   508,
     465,   662,   388,   508,  1387,   664,   666,  1050,  1050,  1050,
    1050,   667,   682,   679,   688,   713,   508,   719,   684,   685,
     722,   730,   731,   697,   732,   708,   709,   744,   750,   751,
     426,   758,   757,   430,   447,   453,   765,   464,  1559,  1560,
     767,   768,   771,   776,   788,   804,  1050,   800,   832,   820,
     508,   833,   508,   834,   805,   835,   846,   852,   806,   853,
    1086,   807,   855,   882,   878,   904,   879,   883,   908,   912,
     913,   916,   923,   938,   914,   945,   915,   944,   948,   918,
     954,   917,   959,   383,   964,   942,   955,  1116,   956,   957,
     967,   994,   995,   968,  1121,   958,  1121,   508,   965,  1598,
    1050,   966,   971,   982,   983,   388,   996,  1004,   999,  1003,
    1007,  1015,  1019,  1050,  1055,   389,  1469,  1056,   508,  1072,
     925,   873,   391,  1091,   392,  1177,  1118,  1092,  1124,  1125,
    1115,  1131,  1127,   393,   715,  1154,  1110,   394,  1151,  1152,
    1153,  1158,  1157,  1159,  1164,  1166,  1169,   748,  1170,   748,
    1174,  1178,  1179,  1180,  1184,  1200,  1214,  1217,  1221,   670,
    1223,  1240,  1242,  1278,  1279,  1497,  1138,  1281,   395,   396,
    1011,   849,  1286,  1297,  1266,  1302,  1310,  1317,   906,  1314,
    1318,  1243,  1320,  1327,  1267,  1306,  1319,  1307,  1270,  1312,
    1329,  1321,  1333,  1336,  1241,  1337,  1335,  1341,  1247,  1345,
    1348,  1362,   508,  1367,  1370,   508,  1379,  1365,  1366,  1381,
    1233,  1296,  1374,  1309,  1394,  1050,  1397,  1375,  1376,  1401,
     508,  1411,  1398,  1417,  1377,  1289,   399,   383,  1418,   508,
    1378,  1422,  1424,  1435,  1430,  1433,  1441,   384,   385,  1156,
     386,   387,  1446,  1431,   508,  1450,  1432,  1455,  1453,   388,
    1448,  1467,   508,  1460,  1444,  1468,  1471,  1479,   400,   389,
     390,  1512,  1510,  1522,  1093,  1538,   391,  1472,   392,  1476,
    1498,   508,  1513,  1535,  1527,  1540,  1316,   393,  1544,  1556,
    1553,   394,  1557,  1565,  1566,  1511,   402,  1568,  1534,  1567,
    1573,  1569,   508,  1574,  1578,   508,  1580,  1593,  1595,   712,
    1599,   508,  1325,  1606,  1611,  1614,  1607,  1609,  1617,  1623,
    1625,  1604,   395,   396,   397,  1067,  1638,  1339,  1631,  1627,
    1621,  1640,  1350,  1643,  1642,  1647,  1050,   880,  1074,  1646,
     560,  1295,   562,  1576,  1628,   563,  1311,  1633,  1364,  1649,
     566,   742,  1602,  1383,   404,   405,   406,   407,   408,  1050,
     409,   410,   411,   412,   413,   663,   508,  1150,   693,   414,
     415,   398,  1147,   694,   691,   720,  1322,  1465,  1371,  1340,
     399,   953,  1396,   756,  1231,  1351,  1355,   588,  1390,  1393,
     811,   810,   630,  1361,  1616,  1369,   978,   508,  1613,   779,
    1054,   848,  1382,  1305,  1123,  1294,  1380,  1386,   507,  1412,
    1509,  1245,   400,  1508,   702,  1269,  1416,  1098,  1415,  1443,
    1303,  1519,  1413,     0,   508,   508,     0,     0,   769,   770,
     401,   772,   773,   774,   775,     0,     0,     0,     0,     0,
     402,   781,   782,     0,     0,     0,   508,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   508,     0,   801,   802,
     508,     0,     0,  1050,     0,     0,     0,     0,   808,   809,
       0,     0,   403,     0,     0,     0,     0,     0,     0,     0,
     703,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1449,     0,     0,     0,   404,   405,
     406,   407,   408,     0,   409,   410,   411,   412,   413,     0,
       0,     0,     0,   414,   415,     0,     0,     0,     0,     0,
       0,  1463,  1464,     0,     0,     0,   843,     0,     0,     0,
     843,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1475,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1481,     0,     0,     0,  1484,     0,     0,
       0,     0,     0,     0,     0,   508,     0,     0,     0,     0,
     508,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   508,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     508,     0,   508,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   952,     0,     0,     0,   508,
       0,     0,   508,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   508,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   508,     0,     0,     0,     0,
       0,     0,     0,   508,     0,     0,     0,     0,     0,     0,
       0,   508,  1546,     0,     0,     0,   508,  1552,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1562,   507,
       0,     0,     0,     0,  1012,     0,     0,     0,     0,     0,
    1016,     0,     0,     0,   508,     0,     0,  1050,     0,  1050,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   508,     0,   508,     0,     0,  1572,     0,     0,  1575,
       0,     0,     0,     0,     0,     0,   508,     0,     0,  1050,
     508,     0,     0,     0,     0,   508,     0,     0,     0,     0,
       0,     0,  1597,     0,     0,     0,     0,     0,     0,     0,
    1050,     0,     0,     0,     0,     0,     0,  1075,  1605,     0,
       0,     0,     0,  1608,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1622,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1629,     0,
    1630,  1128,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1641,     0,     0,     0,  1644,     0,     0,
       0,     0,  1648,  1161,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1165,     0,  1167,  1168,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1183,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1203,  1204,  1205,     0,  1208,  1209,  1210,  1211,  1212,
    1213,     0,  1215,  1216,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1016,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1287,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1326,     0,  1328,     0,  1330,     0,     0,
    1334,     0,     0,     0,     0,  1338,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1343,     0,     0,
       0,     0,     0,     0,     0,     0,  1347,     0,     0,     0,
       0,     0,     0,  1352,  1353,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1016,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1454,     0,     0,
       0,  1456,     0,     0,     0,  1459,     0,  1461,     0,  1462,
       0,     0,     0,     0,     0,  1466,     0,     0,     0,     0,
       0,     0,  1470,     0,     0,     0,     0,     0,     0,     0,
    1473,  1474,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1485,
    1486,  1487,  1488,  1489,     0,  1490,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1536,
       0,  1537,     0,     0,  1539,     0,     0,     0,     0,     0,
       0,  1541,     0,     0,     0,     0,  1543,     0,     0,     0,
    1545,     0,  1547,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1555,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1577,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1596,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1610,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1620,     0,
       1,     0,     0,  1624,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     0,     0,     8,     0,     0,     0,
       9,    10,  1632,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,    72,    73,    74,
      75,     0,     0,    76,    77,     0,     0,     0,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,     0,
       0,     0,    89,     0,    90,    91,    92,    93,     0,    94,
       0,     0,     0,    95,    96,    97,    98,    99,     0,     0,
       0,     0,     0,     0,   100,   101,   102,   103,   104,   105,
     106,     0,     0,     0,   107,   108,   109,   110,   111,     0,
       0,     0,     0,   112,   113,   114,   115,   116,   117,   118,
     119,     0,   120,     0,   121,   122,     0,     0,   123,   124,
     125,     0,     0,     0,   126,     0,   127,   128,     0,   129,
     130,   131,     0,   132,     0,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,     0,     0,   144,   145,
     146,     0,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,     0,   191,   192,   193,
       0,   194,   195,   196,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,     1,
       0,     0,     0,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     0,     0,     8,     0,     0,     0,   373,
     374,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   375,    27,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,    72,    73,    74,    75,
       0,     0,    76,    77,     0,     0,     0,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,     0,     0,
       0,    89,     0,    90,    91,    92,    93,     0,    94,     0,
       0,     0,    95,    96,    97,    98,    99,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,   104,   105,   106,
       0,     0,     0,   107,   108,   109,   110,   111,     0,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
       0,   120,     0,   121,   122,     0,     0,   123,   124,   125,
       0,   376,     0,   126,     0,   127,   128,     0,   129,   130,
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
     233,   234,   235,   236,   237,   238,   239,     1,     0,     0,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       7,     0,     0,     8,     0,     0,     0,   373,   374,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   375,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,    72,    73,    74,    75,     0,     0,
      76,    77,     0,     0,     0,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,     0,     0,     0,    89,
       0,    90,    91,    92,    93,     0,    94,     0,     0,     0,
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   104,   105,   106,     0,     0,
       0,   107,   108,   109,   110,   111,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,     0,   120,
       0,   121,   122,     0,     0,   123,   124,   125,     0,   379,
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
     235,   236,   237,   238,   239,     1,     0,     0,     0,     0,
       0,     0,     0,     2,     3,     4,     5,     6,     7,     0,
       0,     8,     0,     0,     0,   373,   374,     0,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   375,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,    72,    73,    74,    75,     0,     0,    76,    77,
       0,     0,     0,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,     0,     0,     0,    89,     0,    90,
      91,    92,    93,     0,    94,     0,     0,     0,    95,    96,
      97,    98,    99,     0,     0,     0,     0,     0,     0,   100,
     101,   102,   103,   104,   105,   106,     0,     0,     0,   107,
     108,   109,   110,   111,     0,     0,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,     0,   120,     0,   121,
     122,     0,     0,   123,   124,   125,     0,   381,     0,   126,
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
     237,   238,   239,     1,     0,     0,     0,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     0,     0,     8,
       0,     0,     0,   373,   374,     0,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   375,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
      72,    73,    74,    75,     0,     0,    76,    77,     0,     0,
       0,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,     0,     0,     0,    89,     0,    90,    91,    92,
      93,     0,    94,     0,     0,     0,    95,    96,    97,    98,
      99,     0,     0,     0,     0,     0,     0,   100,   101,   102,
     103,   104,   105,   106,     0,     0,     0,   107,   108,   109,
     110,   111,     0,     0,     0,     0,   112,   113,   114,   115,
     116,   117,   118,   119,     0,   120,     0,   121,   122,     0,
       0,   123,   124,   125,     0,     0,     0,   126,   525,   127,
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
     239,     1,     0,     0,     0,     0,     0,     0,     0,     2,
       3,     4,     5,     6,     7,     0,     0,     8,     0,     0,
       0,   373,   374,     0,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,   375,
      27,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,    72,    73,
      74,    75,     0,     0,    76,    77,     0,     0,     0,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
       0,     0,     0,    89,     0,    90,    91,    92,    93,     0,
      94,     0,     0,     0,    95,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,   104,
     105,   106,     0,     0,     0,   107,   108,   109,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,     0,   120,     0,   121,   122,     0,     0,   123,
     124,   125,     0,   836,     0,   126,     0,   127,   128,     0,
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
     231,   232,   233,   234,   235,   236,   237,   238,   239,     1,
       0,     0,     0,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     0,     0,     8,     0,     0,     0,   373,
     374,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   375,    27,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,    72,    73,    74,    75,
       0,     0,    76,    77,     0,     0,     0,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,     0,     0,
       0,    89,     0,    90,    91,    92,    93,     0,    94,     0,
       0,     0,    95,    96,    97,    98,    99,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,   104,   105,   106,
       0,     0,     0,   107,   108,   109,   110,   111,     0,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
       0,   120,     0,   121,   122,     0,     0,   123,   124,   125,
       0,     0,     0,   126,   842,   127,   128,     0,   129,   130,
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
     233,   234,   235,   236,   237,   238,   239,     1,     0,     0,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       7,     0,     0,     8,     0,     0,     0,   373,   374,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   375,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,    72,    73,    74,    75,     0,     0,
      76,    77,     0,     0,     0,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,     0,     0,     0,    89,
       0,    90,    91,    92,    93,     0,    94,     0,     0,     0,
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   104,   105,   106,     0,     0,
       0,   107,   108,   109,   110,   111,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,     0,   120,
       0,   121,   122,     0,     0,   123,   124,   125,     0,     0,
       0,   126,   847,   127,   128,     0,   129,   130,   131,     0,
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
     235,   236,   237,   238,   239,     1,     0,     0,     0,     0,
       0,     0,     0,     2,     3,     4,     5,     6,     7,     0,
       0,     8,     0,     0,     0,   373,   374,     0,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   375,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,    72,    73,    74,    75,     0,     0,    76,    77,
       0,     0,     0,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,     0,     0,     0,    89,     0,    90,
      91,    92,    93,     0,    94,     0,     0,     0,    95,    96,
      97,    98,    99,     0,     0,     0,     0,     0,     0,   100,
     101,   102,   103,   104,   105,   106,     0,     0,     0,   107,
     108,   109,   110,   111,     0,     0,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,     0,   120,     0,   121,
     122,     0,     0,   123,   124,   125,     0,  1315,     0,   126,
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
     237,   238,   239,     1,     0,     0,     0,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     0,     0,     8,
       0,     0,     0,   373,   374,     0,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   375,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
      72,    73,    74,    75,     0,     0,    76,    77,     0,     0,
       0,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,     0,     0,     0,    89,     0,    90,    91,    92,
      93,     0,    94,     0,     0,     0,    95,    96,    97,    98,
      99,     0,     0,     0,     0,     0,     0,   100,   101,   102,
     103,   104,   105,   106,     0,     0,     0,   107,   108,   109,
     110,   111,     0,     0,     0,     0,   112,   113,   114,   115,
     116,   117,   118,   119,     0,   120,     0,   121,   122,     0,
       0,   123,   124,   125,     0,  1349,     0,   126,     0,   127,
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
     239,     1,     0,     0,     0,     0,     0,     0,     0,     2,
       3,     4,     5,     6,     7,     0,     0,     8,     0,     0,
       0,   373,   374,     0,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,   375,
      27,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,    72,    73,
      74,    75,     0,     0,    76,    77,     0,     0,     0,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
       0,     0,     0,    89,     0,    90,    91,    92,    93,     0,
      94,     0,     0,     0,    95,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,   104,
     105,   106,     0,     0,     0,   107,   108,   109,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,     0,   120,     0,   121,   122,     0,     0,   123,
     124,   125,     0,  1363,     0,   126,     0,   127,   128,     0,
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
     231,   232,   233,   234,   235,   236,   237,   238,   239,     1,
       0,     0,     0,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     0,     0,     8,     0,     0,     0,     9,
      10,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,    72,    73,    74,    75,
       0,     0,    76,    77,     0,     0,     0,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,     0,     0,
       0,    89,     0,    90,    91,    92,    93,     0,    94,     0,
       0,     0,    95,    96,    97,    98,    99,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,   104,   105,   106,
       0,     0,     0,   107,   108,   109,   110,   111,     0,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
       0,   120,     0,   121,   122,     0,     0,   123,   124,   125,
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
     233,   234,   235,   236,   237,   238,   239,     1,     0,     0,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       7,     0,     0,     8,     0,     0,     0,     9,    10,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,    72,    73,    74,    75,     0,     0,
      76,    77,     0,     0,     0,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,     0,     0,     0,    89,
       0,    90,    91,    92,    93,     0,    94,     0,     0,     0,
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   104,   105,   106,     0,     0,
       0,   107,   108,   109,   110,   111,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,     0,   120,
       0,   121,   122,     0,     0,   123,   124,   125,     0,     0,
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
     235,   236,   237,   238,   239,     1,     0,     0,     0,     0,
       0,     0,     0,     2,     3,     4,     5,     6,     7,     0,
       0,     8,     0,     0,     0,   373,   374,     0,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
     469,    24,   471,   375,    27,   472,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,   474,
      42,    43,   475,     0,    45,    46,    47,   477,   478,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,    72,    73,    74,    75,     0,     0,    76,    77,
       0,     0,     0,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,     0,     0,     0,    89,     0,    90,
      91,    92,    93,     0,    94,     0,     0,     0,   486,    96,
      97,    98,    99,     0,     0,     0,     0,     0,     0,   100,
     101,   102,   103,   104,   105,   106,     0,     0,     0,   107,
     108,   628,   110,   111,     0,     0,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,     0,   120,     0,   629,
     122,     0,     0,   123,   124,   125,     0,     0,     0,   126,
       0,   127,   128,     0,   129,   130,   131,     0,   132,     0,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,     0,     0,   144,   145,   146,     0,   377,   148,   149,
     150,   151,   152,   153,   154,   155,   495,   157,   496,   159,
     497,   498,   162,   163,   164,   165,   166,   167,   499,   169,
     500,   501,   502,   503,   174,   175,   504,   505,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,     0,   191,   192,   193,     0,   194,   195,   196,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,     1,     0,     0,     0,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     0,     0,     8,
       0,     0,     0,   373,   374,     0,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   375,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
      72,    73,    74,    75,     0,     0,    76,    77,     0,     0,
       0,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,     0,     0,     0,    89,     0,    90,    91,    92,
      93,     0,    94,     0,     0,     0,    95,    96,    97,    98,
      99,     0,     0,     0,     0,     0,     0,   100,   101,   102,
     103,   104,   105,   106,     0,     0,     0,   107,   108,   109,
     110,   111,     0,     0,     0,     0,   112,   113,   114,   115,
     116,   117,   118,   119,     0,   120,     0,   121,   122,     0,
       0,   123,   124,   125,     0,     0,     0,   126,     0,   127,
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
     239,     1,     0,     0,     0,     0,     0,     0,     0,     2,
       3,     4,     5,     6,     7,     0,     0,     8,     0,     0,
       0,     9,   374,     0,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,    72,    73,
      74,    75,     0,     0,    76,    77,     0,     0,     0,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
       0,     0,     0,    89,     0,    90,    91,    92,    93,     0,
      94,     0,     0,     0,    95,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,   104,
     105,   106,     0,     0,     0,   107,   108,   109,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,     0,   120,     0,   121,   122,     0,     0,   123,
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
     231,   232,   233,   234,   235,   236,   237,   238,   239,     1,
       0,     0,     0,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     0,     0,     8,     0,     0,     0,   795,
     374,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   375,    27,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,    72,    73,    74,    75,
       0,     0,    76,    77,     0,     0,     0,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,     0,     0,
       0,    89,     0,    90,    91,    92,    93,     0,    94,     0,
       0,     0,    95,    96,    97,    98,    99,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,   104,   105,   106,
       0,     0,     0,   107,   108,   109,   110,   111,     0,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
       0,   120,     0,   121,   122,     0,     0,   123,   124,   125,
       0,     0,     0,   126,     0,   127,   128,     0,   129,   130,
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
     233,   234,   235,   236,   237,   238,   239,     1,     0,     0,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       7,     0,     0,     8,     0,     0,     0,   373,   374,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,   469,    24,   471,   375,    27,   472,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,   474,    42,    43,   475,     0,    45,    46,    47,   477,
     478,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,    72,    73,    74,    75,     0,     0,
      76,    77,     0,     0,     0,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,     0,     0,     0,    89,
       0,    90,    91,    92,    93,     0,    94,     0,     0,     0,
     486,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   104,   105,   106,     0,     0,
       0,   107,   108,   109,   110,   111,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,     0,   120,
       0,   121,   122,     0,     0,   123,   124,   125,     0,     0,
       0,   126,     0,   127,   128,     0,   129,   130,   131,     0,
     132,     0,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,     0,     0,   144,   145,   146,     0,   377,
     148,   149,   150,   151,   152,   153,   154,   155,   495,   157,
     496,   159,   497,   498,   162,   163,   164,   165,   166,   167,
     499,   169,   500,   501,   502,   503,   174,   175,   504,   505,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,     0,   191,   192,   193,     0,   194,   195,
     196,   197,   198,   199,     0,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,     1,     0,     0,     0,     0,
       0,     0,     0,     2,     3,     4,     5,     6,     7,     0,
       0,     8,     0,     0,     0,  1000,   374,     0,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   375,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,    72,    73,    74,    75,     0,     0,    76,    77,
       0,     0,     0,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,     0,     0,     0,    89,     0,    90,
      91,    92,    93,     0,    94,     0,     0,     0,    95,    96,
      97,    98,    99,     0,     0,     0,     0,     0,     0,   100,
     101,   102,   103,   104,   105,   106,     0,     0,     0,   107,
     108,   109,   110,   111,     0,     0,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,     0,   120,     0,   121,
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
     237,   238,   239,     1,     0,     0,     0,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     0,     0,     8,
       0,     0,     0,   373,   374,     0,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,   469,    24,
     471,   375,    27,   472,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,   474,    42,    43,
     475,     0,    45,    46,    47,   477,   478,    50,   479,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
      72,    73,    74,    75,     0,     0,    76,    77,     0,     0,
       0,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,     0,     0,     0,    89,     0,    90,    91,    92,
      93,     0,    94,     0,     0,     0,   486,    96,    97,    98,
      99,     0,     0,     0,     0,     0,     0,   100,   101,   102,
     103,   104,   105,   106,     0,     0,     0,   107,   108,     0,
     110,   111,     0,     0,     0,     0,   112,   113,   114,   115,
     116,   117,   118,   119,     0,   120,     0,     0,     0,     0,
       0,   123,   124,   125,     0,     0,     0,   126,     0,   127,
     128,     0,   129,   130,   131,     0,   132,     0,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,     0,
       0,   144,   145,   146,     0,   377,   148,   149,   150,   151,
     152,   153,   154,   155,   495,   157,   496,   159,   497,   498,
     162,   163,   164,   165,   166,   167,   499,   169,   500,   501,
     502,   503,   174,   175,   504,   505,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
     191,   192,   193,     0,   194,   195,   196,   197,   198,   199,
       0,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,     1,     0,     0,     0,     0,     0,     0,     0,     2,
       3,     4,     5,     6,     7,     0,     0,     8,     0,     0,
       0,   373,   374,     0,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,   469,    24,   471,   375,
      27,   472,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,   474,    42,    43,   475,     0,
      45,    46,    47,   477,   478,    50,   479,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,    72,    73,
      74,    75,     0,     0,    76,    77,     0,     0,     0,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
       0,     0,     0,    89,     0,    90,    91,    92,    93,     0,
      94,     0,     0,     0,   486,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,   104,
     105,   106,     0,     0,     0,   107,   108,     0,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,     0,   120,     0,     0,     0,     0,     0,   123,
     124,   125,     0,     0,     0,   126,     0,   127,   128,     0,
       0,     0,   131,     0,   132,     0,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,     0,     0,   144,
     145,   146,     0,   377,   148,   149,   150,   151,   152,   153,
     154,   155,   495,   157,   496,   159,   497,   498,   162,   163,
     164,   165,   166,   167,   499,   169,   500,   501,   502,   503,
     174,   175,   504,   505,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,     0,   191,   192,
     193,     0,   194,   195,   196,   197,   198,   199,     0,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,     1,
       0,     0,     0,     0,     0,     0,     0,     2,     0,     0,
       0,     6,     7,     0,     0,   465,     0,     0,     0,   373,
     374,     0,    11,    12,    13,   466,    15,    16,    17,    18,
     467,    20,   468,    22,   469,   470,   471,   375,    27,   472,
      29,    30,     0,    31,    32,    33,    34,    35,   473,    37,
      38,    39,    40,   474,    42,    43,   475,     0,    45,   476,
      47,   477,   478,    50,   479,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,   480,   481,
      67,     0,    68,    69,    70,   482,     0,    73,    74,    75,
       0,     0,   483,    77,     0,     0,     0,     0,    79,    80,
      81,   484,   485,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,    90,    91,    92,    93,     0,    94,     0,
       0,     0,   486,    96,    97,   487,   488,     0,     0,     0,
       0,     0,     0,   100,   101,   102,     0,   104,   105,   106,
       0,     0,     0,     0,     0,     0,   110,   111,     0,     0,
       0,     0,   112,   113,   114,   115,   489,   117,   118,   490,
       0,     0,     0,     0,     0,     0,     0,   491,   492,   125,
       0,     0,     0,   126,     0,   127,   493,     0,     0,     0,
     131,     0,   132,     0,   133,   134,   135,   136,   494,   138,
     139,   140,   141,   142,   143,     0,     0,   144,   145,     0,
       0,   377,   148,   149,   150,   151,   152,   153,   154,   155,
     495,   157,   496,   159,   497,   498,   162,   163,   164,   165,
     166,   167,   499,   169,   500,   501,   502,   503,   174,   175,
     504,   505,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,     0,   191,   192,   193,     0,
     194,   195,   196,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,     1,     0,     0,
       0,     0,     0,     0,     0,     2,     0,     0,     0,     6,
       7,     0,     0,   465,     0,     0,     0,   373,   374,     0,
      11,    12,    13,   512,    15,    16,    17,    18,   467,   513,
     514,    22,   469,   470,   471,   375,    27,   472,    29,    30,
       0,    31,    32,    33,    34,    35,   515,    37,   516,   517,
      40,   474,    42,    43,   475,     0,    45,   518,    47,   477,
     478,    50,   479,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,   480,   481,    67,     0,
      68,    69,    70,   519,     0,    73,    74,    75,     0,     0,
     483,    77,     0,     0,     0,     0,    79,    80,    81,   484,
     485,    84,    85,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    91,    92,    93,     0,    94,     0,     0,     0,
     486,    96,    97,   487,   488,     0,     0,     0,     0,     0,
       0,   100,   101,   102,     0,   104,   105,   106,     0,     0,
       0,     0,     0,     0,   110,   111,     0,     0,     0,     0,
     112,   113,   114,   115,   489,   117,   118,   490,     0,     0,
       0,     0,     0,     0,     0,   491,   492,   125,     0,     0,
       0,   126,     0,   127,   493,     0,     0,     0,   131,     0,
     132,     0,   133,   134,   135,   136,   494,   138,   139,   140,
     141,   142,   143,     0,     0,   144,   145,     0,     0,   377,
     148,   149,   150,   151,   152,   153,   154,   155,   495,   520,
     496,   159,   497,   498,   162,   163,   164,   165,   166,   167,
     499,   169,   500,   501,   502,   503,   174,   175,   504,   505,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,     0,   191,   192,   193,     0,   194,   195,
     196,   197,   198,   199,     0,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   530,     0,     0,     0,     0,
       0,     0,     0,     6,     7,     0,     0,   734,     0,     0,
       0,   373,   374,     0,    11,    12,    13,   512,    15,    16,
      17,    18,   467,   513,   514,    22,   469,   470,   471,   375,
      27,   472,    29,    30,     0,    31,    32,    33,    34,    35,
     515,    37,   516,   517,    40,   474,    42,    43,   475,     0,
      45,   518,    47,   477,   478,    50,   479,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
     480,   481,    67,     0,    68,    69,    70,   519,     0,    73,
      74,    75,     0,     0,   483,    77,     0,     0,     0,     0,
      79,    80,    81,   484,   485,    84,    85,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    91,    92,    93,     0,
      94,     0,     0,     0,   486,    96,    97,   487,   488,     0,
       0,     0,     0,     0,     0,   100,   101,   102,     0,   104,
     105,   106,     0,     0,     0,     0,     0,     0,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   489,   117,
     118,   490,     0,     0,     0,     0,     0,     0,     0,   491,
     492,   125,     0,     0,     0,   126,   735,   127,   493,     0,
       0,     0,     0,     0,   132,     0,   133,   134,   135,   136,
     494,   138,   139,   140,   141,   142,   143,     0,     0,   144,
     145,     0,     0,   377,   148,   149,   150,   151,   152,   153,
     154,   155,   495,   520,   496,   159,   497,   498,   162,   163,
     164,   165,   166,   167,   499,   169,   500,   501,   502,   503,
     174,   175,   504,   505,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,     0,   191,   192,
     193,     0,   194,   195,   196,   197,   198,   199,     0,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   530,
       0,     0,     0,     0,     0,     0,     0,     6,     7,     0,
       0,   465,     0,     0,     0,   373,   374,     0,    11,    12,
      13,   512,    15,    16,    17,    18,   467,   513,   514,    22,
     469,   470,   471,   375,    27,   472,    29,    30,     0,    31,
      32,    33,    34,    35,   515,    37,   516,   517,    40,   474,
      42,    43,   475,     0,    45,   518,    47,   477,   478,    50,
     479,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,   480,   481,    67,     0,    68,    69,
      70,   519,     0,    73,    74,    75,     0,     0,   483,    77,
       0,     0,     0,     0,    79,    80,    81,   484,   485,    84,
      85,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,    93,     0,    94,     0,     0,     0,   486,    96,
      97,   487,   488,     0,     0,     0,     0,     0,     0,   100,
     101,   102,     0,   104,   105,   106,     0,     0,     0,     0,
       0,     0,   110,   111,     0,     0,     0,     0,   112,   113,
     114,   115,   489,   117,   118,   490,     0,     0,     0,     0,
       0,     0,     0,   491,   492,   125,     0,     0,     0,   126,
       0,   127,   493,     0,     0,     0,     0,     0,   132,     0,
     133,   134,   135,   136,   494,   138,   139,   140,   141,   142,
     143,     0,     0,   144,   145,     0,     0,   377,   148,   149,
     150,   151,   152,   153,   154,   155,   495,   520,   496,   159,
     497,   498,   162,   163,   164,   165,   166,   167,   499,   169,
     500,   501,   502,   503,   174,   175,   504,   505,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,     0,   191,   192,   193,     0,   194,   195,   196,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   533,   534,     0,     0,     0,     0,     6,
       7,     0,     0,   465,     0,     0,     0,   373,   374,     0,
      11,    12,    13,   512,    15,    16,    17,    18,   467,   513,
     514,    22,   469,   470,   471,   375,    27,   472,    29,    30,
       0,    31,    32,    33,    34,    35,   515,    37,   516,   517,
      40,   474,    42,    43,   475,     0,    45,   518,    47,   477,
     478,    50,   479,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,   480,   481,    67,     0,
      68,    69,    70,   519,     0,    73,    74,    75,     0,     0,
     483,    77,     0,     0,     0,     0,    79,    80,    81,   484,
     485,    84,    85,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    91,    92,    93,     0,    94,     0,     0,     0,
     486,    96,    97,   487,   488,     0,     0,     0,     0,     0,
       0,   100,   101,   102,     0,   104,   105,   106,     0,     0,
       0,     0,     0,     0,   110,   111,     0,     0,     0,     0,
     112,   113,   114,   115,   489,   117,   118,   490,     0,     0,
       0,     0,     0,     0,     0,   491,   492,   125,     0,     0,
       0,   126,     0,   127,   493,     0,     0,     0,     0,     0,
     132,     0,   133,   134,   135,   136,   494,   138,   139,   140,
     141,   142,   143,     0,     0,   144,   145,     0,     0,   377,
     148,   149,   150,   151,   152,   153,   154,   155,   495,   520,
     496,   159,   497,   498,   162,   163,   164,   165,   166,   167,
     499,   169,   500,   501,   502,   503,   174,   175,   504,   505,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,     0,   191,   192,   193,     0,   194,   195,
     196,   197,   198,   199,     0,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,     6,     7,     0,     0,   465,
       0,     0,     0,   373,   374,     0,    11,    12,    13,   466,
      15,    16,    17,    18,   467,    20,   468,    22,   469,  1038,
     471,   375,    27,   472,    29,    30,     0,    31,    32,    33,
      34,    35,   473,    37,    38,    39,    40,   474,    42,    43,
     475,     0,    45,   476,    47,   477,   478,    50,   479,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,   480,   481,    67,     0,    68,    69,    70,   482,
       0,    73,    74,    75,     0,     0,   483,    77,     0,     0,
       0,     0,    79,    80,    81,   484,   485,    84,    85,     0,
       0,     0,     0,     0,     0,     0,     0,    90,    91,    92,
      93,     0,    94,     0,     0,     0,   486,    96,    97,   487,
     488,     0,     0,     0,     0,     0,     0,   100,   101,   102,
       0,   104,   105,  1039,     0,     0,     0,  1040,     0,     0,
     110,   111,     0,     0,     0,     0,   112,   113,   114,   115,
     489,   117,   118,   490,     0,     0,     0,     0,     0,     0,
       0,   491,   492,   125,     0,     0,     0,   126,  1426,   127,
     493,     0,     0,     0,  1427,     0,   132,     0,   133,   134,
     135,   136,   494,   138,   139,   140,   141,   142,   143,     0,
       0,  1041,   145,     0,     0,   377,   148,   149,   150,   151,
     152,   153,   154,   155,   495,   157,   496,   159,   497,   498,
     162,   163,   164,   165,   166,   167,   499,   169,   500,   501,
     502,   503,   174,   175,   504,   505,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
     191,   192,   193,     0,   194,   195,   196,   197,   198,   199,
       0,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,     6,     7,     0,     0,   465,     0,     0,     0,   373,
     374,     0,    11,    12,    13,   512,    15,    16,    17,    18,
     467,   513,   514,    22,   469,   470,   471,   375,    27,   472,
      29,    30,     0,    31,    32,    33,    34,    35,   515,    37,
     516,   517,    40,   474,    42,    43,   475,     0,    45,   518,
      47,   477,   478,    50,   479,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,   480,   481,
      67,     0,    68,    69,    70,   519,     0,    73,    74,    75,
       0,     0,   483,    77,     0,     0,     0,     0,    79,    80,
      81,   484,   485,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,    90,    91,    92,    93,     0,    94,     0,
       0,     0,   486,    96,    97,   487,   488,     0,     0,     0,
       0,     0,     0,   100,   101,   102,     0,   104,   105,   106,
       0,     0,     0,     0,     0,     0,   110,   111,     0,     0,
       0,     0,   112,   113,   114,   115,   489,   117,   118,   490,
       0,     0,     0,     0,     0,     0,     0,   491,   492,   125,
       0,     0,     0,   126,   705,   127,   493,     0,     0,     0,
     706,     0,   132,     0,   133,   134,   135,   136,   494,   138,
     139,   140,   141,   142,   143,     0,     0,   144,   145,     0,
       0,   377,   148,   149,   150,   151,   152,   153,   154,   155,
     495,   520,   496,   159,   497,   498,   162,   163,   164,   165,
     166,   167,   499,   169,   500,   501,   502,   503,   174,   175,
     504,   505,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,     0,   191,   192,   193,     0,
     194,   195,   196,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,     6,     7,     0,
       0,   465,     0,     0,     0,   373,   374,     0,    11,    12,
      13,   512,    15,    16,    17,    18,   467,   513,   514,    22,
     469,   470,   471,   375,    27,   472,    29,    30,     0,    31,
      32,    33,    34,    35,   515,    37,   516,   517,    40,   474,
      42,    43,   475,     0,    45,   518,    47,   477,   478,    50,
     479,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,   480,   481,    67,     0,    68,    69,
      70,   519,     0,    73,    74,    75,     0,     0,   483,    77,
       0,     0,     0,     0,    79,    80,    81,   484,   485,    84,
      85,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,    93,     0,    94,     0,     0,     0,   486,    96,
      97,   487,   488,     0,     0,     0,     0,     0,     0,   100,
     101,   102,     0,   104,   105,   106,     0,     0,     0,     0,
       0,     0,   110,   111,     0,     0,     0,     0,   112,   113,
     114,   115,   489,   117,   118,   490,     0,     0,     0,     0,
       0,     0,     0,   491,   492,   125,     0,     0,     0,   126,
     753,   127,   493,     0,     0,     0,   754,     0,   132,     0,
     133,   134,   135,   136,   494,   138,   139,   140,   141,   142,
     143,     0,     0,   144,   145,     0,     0,   377,   148,   149,
     150,   151,   152,   153,   154,   155,   495,   520,   496,   159,
     497,   498,   162,   163,   164,   165,   166,   167,   499,   169,
     500,   501,   502,   503,   174,   175,   504,   505,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,     0,   191,   192,   193,     0,   194,   195,   196,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,     6,     7,     0,     0,   465,     0,     0,
       0,   373,   374,     0,    11,    12,    13,   466,    15,    16,
      17,    18,   467,    20,   468,    22,   469,  1038,   471,   375,
      27,   472,    29,    30,     0,    31,    32,    33,    34,    35,
     473,    37,    38,    39,    40,   474,    42,    43,   475,     0,
      45,   476,    47,   477,   478,    50,   479,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
     480,   481,    67,     0,    68,    69,    70,   482,     0,    73,
      74,    75,     0,     0,   483,    77,     0,     0,     0,     0,
      79,    80,    81,   484,   485,    84,    85,  1358,     0,     0,
       0,     0,     0,     0,     0,    90,    91,    92,    93,     0,
      94,     0,     0,     0,   486,    96,    97,   487,   488,     0,
       0,     0,     0,     0,     0,   100,   101,   102,     0,   104,
     105,  1039,     0,     0,     0,  1040,     0,     0,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   489,   117,
     118,   490,     0,     0,     0,     0,     0,     0,     0,   491,
     492,   125,     0,     0,     0,   126,     0,   127,   493,     0,
       0,     0,     0,     0,   132,     0,   133,   134,   135,   136,
     494,   138,   139,   140,   141,   142,   143,     0,     0,  1041,
     145,     0,     0,   377,   148,   149,   150,   151,   152,   153,
     154,   155,   495,   157,   496,   159,   497,   498,   162,   163,
     164,   165,   166,   167,   499,   169,   500,   501,   502,   503,
     174,   175,   504,   505,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,     0,   191,   192,
     193,     0,   194,   195,   196,   197,   198,   199,     0,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,     6,
       7,     0,     0,   465,     0,     0,     0,   373,   374,     0,
      11,    12,    13,   466,    15,    16,    17,    18,   467,    20,
     468,    22,   469,  1038,   471,   375,    27,   472,    29,    30,
       0,    31,    32,    33,    34,    35,   473,    37,    38,    39,
      40,   474,    42,    43,   475,     0,    45,   476,    47,   477,
     478,    50,   479,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,   480,   481,    67,     0,
      68,    69,    70,   482,     0,    73,    74,    75,     0,     0,
     483,    77,     0,     0,     0,     0,    79,    80,    81,   484,
     485,    84,    85,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    91,    92,    93,     0,    94,     0,     0,     0,
     486,    96,    97,   487,   488,     0,     0,     0,     0,     0,
       0,   100,   101,   102,     0,   104,   105,  1039,     0,     0,
       0,  1040,     0,     0,   110,   111,     0,     0,     0,     0,
     112,   113,   114,   115,   489,   117,   118,   490,     0,     0,
       0,     0,     0,     0,     0,   491,   492,   125,     0,     0,
       0,   126,     0,   127,   493,     0,     0,     0,     0,     0,
     132,     0,   133,   134,   135,   136,   494,   138,   139,   140,
     141,   142,   143,     0,     0,  1041,   145,     0,     0,   377,
     148,   149,   150,   151,   152,   153,   154,   155,   495,   157,
     496,   159,   497,   498,   162,   163,   164,   165,   166,   167,
     499,   169,   500,   501,   502,   503,   174,   175,   504,   505,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,     0,   191,   192,   193,     0,   194,   195,
     196,   197,   198,   199,     0,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,     6,     7,     0,     0,   465,
       0,     0,     0,   373,   374,     0,    11,    12,    13,   466,
      15,    16,    17,    18,   467,    20,   468,    22,   469,  1038,
     471,   375,    27,   472,    29,    30,     0,    31,    32,    33,
      34,    35,   473,    37,    38,    39,    40,   474,    42,    43,
     475,     0,    45,   476,    47,   477,   478,    50,   479,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,   480,   481,    67,     0,    68,    69,    70,   482,
       0,    73,    74,    75,     0,     0,   483,    77,     0,     0,
       0,     0,    79,    80,    81,   484,   485,    84,    85,     0,
       0,     0,     0,     0,     0,     0,     0,    90,    91,    92,
      93,     0,    94,     0,     0,     0,   486,    96,    97,   487,
     488,     0,     0,     0,     0,     0,     0,   100,   101,   102,
       0,   104,   105,  1039,     0,     0,     0,  1040,     0,     0,
     110,   111,     0,     0,     0,     0,   112,   113,   114,   115,
     489,   117,   118,   490,     0,     0,     0,     0,     0,     0,
       0,   491,   492,   125,     0,     0,     0,   126,     0,   127,
     493,     0,     0,     0,     0,     0,   132,     0,   133,   134,
     135,   136,   494,   138,   139,   140,   141,   142,   143,     0,
       0,   144,   145,     0,     0,   377,   148,   149,   150,   151,
     152,   153,   154,   155,   495,   157,   496,   159,   497,   498,
     162,   163,   164,   165,   166,   167,   499,   169,   500,   501,
     502,   503,   174,   175,   504,   505,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
     191,   192,   193,     0,   194,   195,   196,   197,   198,   199,
       0,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,     6,     7,     0,     0,   465,     0,     0,     0,   373,
     374,     0,    11,    12,    13,   512,    15,    16,    17,    18,
     467,   513,   514,    22,   469,   470,   471,   375,    27,   472,
      29,    30,     0,    31,    32,    33,    34,    35,   515,    37,
     516,   517,    40,   474,    42,    43,   475,     0,    45,   518,
      47,   477,   478,    50,   479,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,   480,   481,
      67,     0,    68,    69,    70,   519,     0,    73,    74,    75,
       0,     0,   483,    77,     0,     0,     0,     0,    79,    80,
      81,   484,   485,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,    90,    91,    92,    93,     0,    94,     0,
       0,     0,   486,    96,    97,   487,   488,     0,     0,     0,
       0,     0,     0,   100,   101,   102,     0,   104,   105,   106,
       0,     0,     0,     0,     0,     0,   110,   111,     0,     0,
       0,     0,   112,   113,   114,   115,   489,   117,   118,   490,
       0,     0,     0,     0,     0,     0,     0,   491,   492,   125,
       0,     0,     0,   126,     0,   127,   493,     0,     0,     0,
       0,     0,   132,     0,   133,   134,   135,   136,   494,   138,
     139,   140,   141,   142,   143,     0,     0,   144,   145,     0,
       0,   377,   148,   149,   150,   151,   152,   153,   154,   155,
     495,   520,   496,   159,   497,   498,   162,   163,   164,   165,
     166,   167,   499,   169,   500,   501,   502,   503,   174,   175,
     504,   505,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,     0,   191,   192,   193,     0,
     194,   195,   196,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,     6,     7,     0,
       0,   465,     0,     0,     0,   373,   374,     0,    11,    12,
      13,     0,    15,    16,    17,    18,   467,     0,     0,    22,
     469,   470,     0,   375,    27,   472,    29,    30,     0,    31,
      32,    33,    34,    35,     0,    37,     0,     0,    40,   474,
      42,    43,   475,     0,    45,     0,    47,     0,     0,    50,
     479,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,   480,   481,    67,     0,    68,    69,
      70,     0,     0,    73,    74,    75,     0,     0,   483,    77,
       0,     0,     0,     0,    79,    80,    81,   484,   485,    84,
      85,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,    93,     0,    94,     0,     0,     0,   486,    96,
      97,   487,   488,     0,     0,     0,     0,     0,     0,   100,
     101,   102,     0,   104,   105,     0,     0,     0,     0,     0,
       0,     0,   110,   111,     0,     0,     0,     0,   112,   113,
     114,   115,   489,   117,   118,   490,     0,     0,     0,     0,
       0,     0,     0,   491,   492,   125,     0,     0,     0,   126,
       0,   127,   493,     0,     0,     0,     0,     0,   132,     0,
     133,   134,   135,   136,   494,   138,   139,   140,   141,   142,
     143,     0,     0,     0,   145,     0,     0,   377,   148,   149,
     150,   151,   152,   153,   154,   155,   495,     0,   496,   159,
     497,   498,   162,   163,   164,   165,   166,   167,   499,   169,
     500,   501,   502,   503,   174,   175,     0,   505,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,     0,   191,   192,   193,     0,   194,   195,   196,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        72,   759,   729,   615,   577,   384,   616,   617,   618,   619,
     311,     3,     4,     5,    86,   742,   130,   712,   820,   247,
     248,   948,   246,   832,   833,   833,   712,  1223,  1237,  1238,
     910,   650,  1110,   981,    72,  1024,   108,  1385,   117,   398,
     571,   572,     1,   569,   570,   571,   572,  1196,   120,    56,
     122,    34,    34,   569,   570,    35,    36,    27,    38,    39,
     439,   440,   871,   658,     1,   424,     1,    28,  1270,   146,
     595,     1,   597,   598,     8,   600,    94,   602,    58,     1,
     871,     9,    10,    27,     1,   610,   611,     1,   447,   106,
       9,    93,   146,   106,     9,    10,   905,    72,   117,  1446,
      99,    54,   106,   117,    57,   141,   106,    26,   106,   106,
      96,    86,    94,    96,    96,   107,   925,   925,    96,   106,
      96,   215,    94,   168,    44,    94,   112,  1003,    53,   938,
     938,    95,   112,   108,    59,   147,   152,   152,    31,   109,
      96,   105,    37,    63,   223,   120,    99,   122,    43,    44,
     877,   115,   164,   123,   868,   200,    49,   117,   120,   253,
     176,   176,   126,   146,   146,    60,   880,    62,    63,   155,
     146,    96,   186,   186,   102,    27,    71,   146,   148,   159,
     182,  1390,   152,   187,     5,   155,   185,   102,     9,   189,
     168,   189,   189,  1069,   122,   272,   124,    94,    96,   186,
     314,   820,    97,   122,   931,   124,   176,   122,   215,   124,
     937,   129,    27,    94,   133,   159,   233,   235,   272,   977,
    1369,  1568,  1024,  1025,   152,   185,  1106,   306,   156,   106,
     189,  1040,  1159,   152,  1312,   930,   272,   152,   218,  1187,
     174,   156,   928,  1445,   930,   173,   253,   319,  1196,  1040,
     322,   212,   189,   272,   189,   786,   787,  1246,   173,   189,
     112,   856,   857,   235,   950,   193,   186,   189,   784,   785,
     168,  1619,   189,   251,   252,   189,   254,   195,   193,    52,
     260,   319,   152,   211,   322,   644,   159,  1635,   258,   272,
     272,   816,   671,   271,   109,  1643,   211,   250,  1494,   255,
     256,   122,    94,   124,  1113,   283,   106,   159,   123,   186,
     263,   132,   265,   130,   190,   191,   388,   389,    25,   216,
     217,  1530,   394,   276,   277,   278,   398,   280,   223,   282,
     106,   152,   404,   148,   231,   216,   217,   106,   566,   411,
      47,   106,  1151,  1151,   319,   569,   570,   322,   727,   129,
     231,    96,   424,   251,   252,   128,   254,    64,   430,    66,
     152,   433,  1571,   261,   723,  1174,  1174,   726,    75,   441,
    1448,    44,   189,   271,    47,   447,   448,   449,   450,   451,
      31,   106,    40,     9,   456,   283,     5,   187,    46,  1116,
       9,    44,   464,    51,    47,     9,    10,    96,    49,    94,
      26,   146,     9,    10,   111,  1024,  1025,   157,   165,   223,
     186,   225,    70,   106,   389,   195,    94,   186,   183,   394,
      94,  1369,   106,   398,   181,   175,    79,   219,   220,   404,
    1125,  1311,   105,   425,   155,   427,   411,   429,   223,   106,
     225,  1060,   106,   106,  1246,   437,   141,   135,  1134,   424,
     522,   106,   105,  1255,   446,   430,   155,  1535,   433,   121,
     452,   186,   454,   455,  1266,   457,   441,   141,   146,  1278,
    1278,   463,   447,   448,   449,   450,   451,  1008,  1009,  1010,
     552,   456,  1008,  1009,  1010,    96,    27,   116,   102,   464,
     136,  1569,   223,   186,   167,   102,   122,   228,   124,   878,
     879,   112,   186,   122,   883,   124,   152,   133,   122,   167,
     124,   199,   170,   132,   167,   122,   145,   124,   268,   186,
     634,   635,   186,   186,   121,   275,   152,   185,   919,   158,
     921,   186,   155,   152,   913,   285,   528,   152,   152,   157,
     155,  1468,   156,   105,   155,   152,   168,   522,   540,   156,
     246,   247,   210,  1631,   155,  1633,    53,   175,    94,   173,
     784,   789,    59,   192,   126,   944,   173,   559,   109,   948,
     143,  1649,   644,   269,   155,   136,   181,   552,   200,   193,
      77,   972,   123,   974,   135,   157,   193,  1548,  1549,   194,
     662,   152,   664,   208,   136,   667,    67,   211,   149,    96,
     136,    72,   175,   175,   211,   141,   228,   148,   157,  1367,
     152,   152,    23,  1371,   155,  1417,   688,   689,   690,   192,
     117,    32,   121,  1584,    96,   197,   175,  1246,   199,  1590,
     155,   262,   147,   136,  1329,   176,  1255,   208,   141,   631,
     112,   713,   273,   715,   636,  1257,   117,  1266,   197,   164,
      61,   723,   262,   152,   726,  1382,   155,   152,   730,   153,
     155,   155,   181,   273,   286,   287,   288,   289,   290,   644,
     292,   293,   294,   295,   296,   194,   268,    99,    99,   301,
     267,   117,    53,   275,   117,    94,   758,   274,    59,   298,
     112,   112,   667,   285,   637,  1226,   105,   640,   307,   131,
     643,   299,   300,  1512,  1512,  1514,  1514,   139,   140,   152,
     142,   136,   155,   688,   689,   690,   141,   230,   150,   232,
    1293,   155,   154,  1481,   156,  1026,  1484,   719,   321,   161,
     299,   300,   804,   326,   152,  1544,  1544,   155,   713,   155,
     715,   276,   277,   278,   127,   128,   178,   282,   723,   152,
     117,   726,   155,   290,   291,   730,  1565,  1565,   750,   751,
     832,   833,   834,   835,   219,   220,   221,   127,   128,   201,
     202,   203,   204,   205,   206,  1154,   230,   121,   232,   121,
    1159,   613,   614,   758,   620,   621,   834,   835,   780,   622,
     623,  1401,  1436,  1437,  1552,   121,  1408,  1409,  1417,   871,
     121,   121,   152,  1530,   121,   121,   121,   121,   214,   152,
     155,   223,   117,   885,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,   152,   240,   240,     0,   241,   804,
     155,   166,    92,   152,    50,   198,   100,   120,   248,   101,
     912,   153,   144,   183,   155,   183,   183,   919,   155,   921,
      27,    47,    47,   925,  1233,    47,   151,   832,   833,   834,
     835,   117,   292,   245,   303,   117,   938,   152,   297,   297,
       1,   117,   141,   186,   106,   283,   283,   186,   152,   152,
     155,    33,   186,   155,   155,   155,    16,   155,  1500,  1501,
     212,    27,   186,   229,     3,   117,   871,   141,   229,    71,
     972,    94,   974,    94,   167,    94,   148,   106,   169,   106,
     885,   169,    27,   126,   159,   245,   159,   131,   298,   117,
     131,   186,   106,    94,   183,    44,   183,    96,    96,   183,
     183,   186,   141,    25,   183,   186,   186,   912,   186,   186,
     152,    94,   235,   183,   919,   186,   921,  1019,   186,  1561,
     925,   186,   183,   183,   183,    47,   223,   183,   141,   186,
      31,   169,   117,   938,   183,    57,  1345,   184,  1040,   131,
      94,   141,    64,    27,    66,   967,   152,   285,   117,   126,
     298,   146,   117,    75,   117,   131,   225,    79,    94,   183,
     196,   131,   159,    96,   152,   117,   146,   972,    99,   974,
      99,   183,   183,   152,    33,    27,   117,   117,   183,    79,
     244,   106,   106,   155,   155,  1394,   253,   155,   110,   111,
     112,    27,   143,    27,   257,    27,   305,   186,   235,   189,
     186,  1023,   186,   146,   259,   225,   143,   225,   266,   225,
     126,   186,   146,   117,  1019,   117,   146,    77,   284,   106,
     141,   183,  1124,   131,     7,  1127,   235,   186,   186,   185,
     105,   285,   189,   286,   105,  1040,   183,   231,   231,   249,
    1142,   249,   186,   146,   231,  1067,   168,    25,   281,  1151,
     231,   285,    78,    27,   186,   183,    27,    35,    36,  1468,
      38,    39,   106,   186,  1166,   256,   186,   146,   183,    47,
     169,   125,  1174,   146,   270,    96,   183,   183,   200,    57,
      58,    94,   152,    27,    96,   146,    64,   185,    66,   185,
     183,  1193,   186,   169,   186,    53,  1118,    75,    94,   141,
     195,    79,   117,    94,    27,   279,   228,   106,   286,   264,
     117,   106,  1214,   223,   117,  1217,   185,   195,   195,  1124,
     183,  1223,  1127,   117,    93,   182,   223,   185,   195,   117,
     117,   304,   110,   111,   112,   152,   117,  1142,   305,   292,
     304,   197,  1164,   186,   286,   117,  1151,   670,   872,   223,
     240,  1073,   243,  1535,   304,   243,  1113,   305,  1180,   305,
     246,  1166,  1569,  1219,   286,   287,   288,   289,   290,  1174,
     292,   293,   294,   295,   296,   392,  1278,   939,   418,   301,
     302,   159,   936,   418,   416,   436,  1124,  1339,  1193,  1143,
     168,   732,  1242,   522,  1015,  1166,  1171,   286,  1237,  1240,
     594,   593,   307,  1175,  1590,  1187,   759,  1309,  1584,  1214,
     835,   646,  1217,  1107,   921,  1072,  1214,  1224,  1223,  1255,
    1417,  1025,   200,  1414,   428,  1034,  1266,   904,  1259,  1301,
    1095,  1439,  1256,    -1,  1336,  1337,    -1,    -1,   544,   545,
     218,   547,   548,   549,   550,    -1,    -1,    -1,    -1,    -1,
     228,   557,   558,    -1,    -1,    -1,  1358,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1368,    -1,   574,   575,
    1372,    -1,    -1,  1278,    -1,    -1,    -1,    -1,   584,   585,
      -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     428,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1309,    -1,    -1,    -1,   286,   287,
     288,   289,   290,    -1,   292,   293,   294,   295,   296,    -1,
      -1,    -1,    -1,   301,   302,    -1,    -1,    -1,    -1,    -1,
      -1,  1336,  1337,    -1,    -1,    -1,   642,    -1,    -1,    -1,
     646,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1358,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1368,    -1,    -1,    -1,  1372,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1477,    -1,    -1,    -1,    -1,
    1482,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1494,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1512,    -1,  1514,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   731,    -1,    -1,    -1,  1531,
      -1,    -1,  1534,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1544,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1557,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1565,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1573,  1477,    -1,    -1,    -1,  1578,  1482,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1510,  1494,
      -1,    -1,    -1,    -1,   800,    -1,    -1,    -1,    -1,    -1,
     806,    -1,    -1,    -1,  1606,    -1,    -1,  1512,    -1,  1514,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1623,    -1,  1625,    -1,    -1,  1531,    -1,    -1,  1534,
      -1,    -1,    -1,    -1,    -1,    -1,  1638,    -1,    -1,  1544,
    1642,    -1,    -1,    -1,    -1,  1647,    -1,    -1,    -1,    -1,
      -1,    -1,  1557,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1565,    -1,    -1,    -1,    -1,    -1,    -1,   873,  1573,    -1,
      -1,    -1,    -1,  1578,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1606,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1623,    -1,
    1625,   927,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1638,    -1,    -1,    -1,  1642,    -1,    -1,
      -1,    -1,  1647,   949,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   959,    -1,   961,   962,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     976,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   987,   988,   989,    -1,   991,   992,   993,   994,   995,
     996,    -1,   998,   999,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1015,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1057,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1129,    -1,  1131,    -1,  1133,    -1,    -1,
    1136,    -1,    -1,    -1,    -1,  1141,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1153,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1162,    -1,    -1,    -1,
      -1,    -1,    -1,  1169,  1170,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1240,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1323,    -1,    -1,
      -1,  1327,    -1,    -1,    -1,  1331,    -1,  1333,    -1,  1335,
      -1,    -1,    -1,    -1,    -1,  1341,    -1,    -1,    -1,    -1,
      -1,    -1,  1348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1356,  1357,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1375,
    1376,  1377,  1378,  1379,    -1,  1381,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1455,
      -1,  1457,    -1,    -1,  1460,    -1,    -1,    -1,    -1,    -1,
      -1,  1467,    -1,    -1,    -1,    -1,  1472,    -1,    -1,    -1,
    1476,    -1,  1478,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1491,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1538,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1556,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1580,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1604,    -1,
      11,    -1,    -1,  1609,    -1,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,
      31,    32,  1628,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    98,    99,   100,
     101,    -1,    -1,   104,   105,    -1,    -1,    -1,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,    -1,
      -1,    -1,   123,    -1,   125,   126,   127,   128,    -1,   130,
      -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,
      -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,   150,
     151,    -1,    -1,    -1,   155,   156,   157,   158,   159,    -1,
      -1,    -1,    -1,   164,   165,   166,   167,   168,   169,   170,
     171,    -1,   173,    -1,   175,   176,    -1,    -1,   179,   180,
     181,    -1,    -1,    -1,   185,    -1,   187,   188,    -1,   190,
     191,   192,    -1,   194,    -1,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,    -1,    -1,   209,   210,
     211,    -1,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,    -1,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,    -1,   104,   105,    -1,    -1,    -1,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,    -1,    -1,
      -1,   123,    -1,   125,   126,   127,   128,    -1,   130,    -1,
      -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   146,   147,   148,   149,   150,   151,
      -1,    -1,    -1,   155,   156,   157,   158,   159,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,   173,    -1,   175,   176,    -1,    -1,   179,   180,   181,
      -1,   183,    -1,   185,    -1,   187,   188,    -1,   190,   191,
     192,    -1,   194,    -1,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,    -1,    -1,   209,   210,   211,
      -1,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,   258,   259,   260,    -1,
     262,   263,   264,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,    -1,
     104,   105,    -1,    -1,    -1,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,    -1,    -1,    -1,   123,
      -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   146,   147,   148,   149,   150,   151,    -1,    -1,
      -1,   155,   156,   157,   158,   159,    -1,    -1,    -1,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,   173,
      -1,   175,   176,    -1,    -1,   179,   180,   181,    -1,   183,
      -1,   185,    -1,   187,   188,    -1,   190,   191,   192,    -1,
     194,    -1,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,    -1,    -1,   209,   210,   211,    -1,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    20,    21,    22,    23,    24,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,    -1,   104,   105,
      -1,    -1,    -1,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,   123,    -1,   125,
     126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,   148,   149,   150,   151,    -1,    -1,    -1,   155,
     156,   157,   158,   159,    -1,    -1,    -1,    -1,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,   173,    -1,   175,
     176,    -1,    -1,   179,   180,   181,    -1,   183,    -1,   185,
      -1,   187,   188,    -1,   190,   191,   192,    -1,   194,    -1,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,    -1,    -1,   209,   210,   211,    -1,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    24,    -1,    -1,    27,
      -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,
      -1,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,    -1,    -1,    -1,   123,    -1,   125,   126,   127,
     128,    -1,   130,    -1,    -1,    -1,   134,   135,   136,   137,
     138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,
     148,   149,   150,   151,    -1,    -1,    -1,   155,   156,   157,
     158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,   173,    -1,   175,   176,    -1,
      -1,   179,   180,   181,    -1,    -1,    -1,   185,   186,   187,
     188,    -1,   190,   191,   192,    -1,   194,    -1,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,    -1,
      -1,   209,   210,   211,    -1,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
     258,   259,   260,    -1,   262,   263,   264,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
      -1,    -1,    -1,   123,    -1,   125,   126,   127,   128,    -1,
     130,    -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,
      -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,
     150,   151,    -1,    -1,    -1,   155,   156,   157,   158,   159,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,   173,    -1,   175,   176,    -1,    -1,   179,
     180,   181,    -1,   183,    -1,   185,    -1,   187,   188,    -1,
     190,   191,   192,    -1,   194,    -1,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,    -1,    -1,   209,
     210,   211,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,   258,   259,
     260,    -1,   262,   263,   264,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,    -1,   104,   105,    -1,    -1,    -1,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,    -1,    -1,
      -1,   123,    -1,   125,   126,   127,   128,    -1,   130,    -1,
      -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   146,   147,   148,   149,   150,   151,
      -1,    -1,    -1,   155,   156,   157,   158,   159,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,   173,    -1,   175,   176,    -1,    -1,   179,   180,   181,
      -1,    -1,    -1,   185,   186,   187,   188,    -1,   190,   191,
     192,    -1,   194,    -1,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,    -1,    -1,   209,   210,   211,
      -1,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,   258,   259,   260,    -1,
     262,   263,   264,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,    -1,
     104,   105,    -1,    -1,    -1,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,    -1,    -1,    -1,   123,
      -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   146,   147,   148,   149,   150,   151,    -1,    -1,
      -1,   155,   156,   157,   158,   159,    -1,    -1,    -1,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,   173,
      -1,   175,   176,    -1,    -1,   179,   180,   181,    -1,    -1,
      -1,   185,   186,   187,   188,    -1,   190,   191,   192,    -1,
     194,    -1,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,    -1,    -1,   209,   210,   211,    -1,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    20,    21,    22,    23,    24,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,    -1,   104,   105,
      -1,    -1,    -1,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,   123,    -1,   125,
     126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,   148,   149,   150,   151,    -1,    -1,    -1,   155,
     156,   157,   158,   159,    -1,    -1,    -1,    -1,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,   173,    -1,   175,
     176,    -1,    -1,   179,   180,   181,    -1,   183,    -1,   185,
      -1,   187,   188,    -1,   190,   191,   192,    -1,   194,    -1,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,    -1,    -1,   209,   210,   211,    -1,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    24,    -1,    -1,    27,
      -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,
      -1,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,    -1,    -1,    -1,   123,    -1,   125,   126,   127,
     128,    -1,   130,    -1,    -1,    -1,   134,   135,   136,   137,
     138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,
     148,   149,   150,   151,    -1,    -1,    -1,   155,   156,   157,
     158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,   173,    -1,   175,   176,    -1,
      -1,   179,   180,   181,    -1,   183,    -1,   185,    -1,   187,
     188,    -1,   190,   191,   192,    -1,   194,    -1,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,    -1,
      -1,   209,   210,   211,    -1,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
     258,   259,   260,    -1,   262,   263,   264,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
      -1,    -1,    -1,   123,    -1,   125,   126,   127,   128,    -1,
     130,    -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,
      -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,
     150,   151,    -1,    -1,    -1,   155,   156,   157,   158,   159,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,   173,    -1,   175,   176,    -1,    -1,   179,
     180,   181,    -1,   183,    -1,   185,    -1,   187,   188,    -1,
     190,   191,   192,    -1,   194,    -1,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,    -1,    -1,   209,
     210,   211,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,   258,   259,
     260,    -1,   262,   263,   264,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,    -1,   104,   105,    -1,    -1,    -1,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,    -1,    -1,
      -1,   123,    -1,   125,   126,   127,   128,    -1,   130,    -1,
      -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   146,   147,   148,   149,   150,   151,
      -1,    -1,    -1,   155,   156,   157,   158,   159,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,   173,    -1,   175,   176,    -1,    -1,   179,   180,   181,
      -1,    -1,    -1,   185,    -1,   187,   188,    -1,   190,   191,
     192,    -1,   194,    -1,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,    -1,    -1,   209,   210,   211,
      -1,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,   258,   259,   260,    -1,
     262,   263,   264,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,    -1,
     104,   105,    -1,    -1,    -1,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,    -1,    -1,    -1,   123,
      -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   146,   147,   148,   149,   150,   151,    -1,    -1,
      -1,   155,   156,   157,   158,   159,    -1,    -1,    -1,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,   173,
      -1,   175,   176,    -1,    -1,   179,   180,   181,    -1,    -1,
      -1,   185,    -1,   187,   188,    -1,   190,   191,   192,    -1,
     194,    -1,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,    -1,    -1,   209,   210,   211,    -1,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    20,    21,    22,    23,    24,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,    -1,   104,   105,
      -1,    -1,    -1,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,   123,    -1,   125,
     126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,   148,   149,   150,   151,    -1,    -1,    -1,   155,
     156,   157,   158,   159,    -1,    -1,    -1,    -1,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,   173,    -1,   175,
     176,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,   185,
      -1,   187,   188,    -1,   190,   191,   192,    -1,   194,    -1,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,    -1,    -1,   209,   210,   211,    -1,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    24,    -1,    -1,    27,
      -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,
      -1,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,    -1,    -1,    -1,   123,    -1,   125,   126,   127,
     128,    -1,   130,    -1,    -1,    -1,   134,   135,   136,   137,
     138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,
     148,   149,   150,   151,    -1,    -1,    -1,   155,   156,   157,
     158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,   173,    -1,   175,   176,    -1,
      -1,   179,   180,   181,    -1,    -1,    -1,   185,    -1,   187,
     188,    -1,   190,   191,   192,    -1,   194,    -1,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,    -1,
      -1,   209,   210,   211,    -1,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
     258,   259,   260,    -1,   262,   263,   264,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
      -1,    -1,    -1,   123,    -1,   125,   126,   127,   128,    -1,
     130,    -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,
      -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,
     150,   151,    -1,    -1,    -1,   155,   156,   157,   158,   159,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,   173,    -1,   175,   176,    -1,    -1,   179,
     180,   181,    -1,    -1,    -1,   185,    -1,   187,   188,    -1,
     190,   191,   192,    -1,   194,    -1,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,    -1,    -1,   209,
     210,   211,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,   258,   259,
     260,    -1,   262,   263,   264,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,    -1,   104,   105,    -1,    -1,    -1,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,    -1,    -1,
      -1,   123,    -1,   125,   126,   127,   128,    -1,   130,    -1,
      -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   146,   147,   148,   149,   150,   151,
      -1,    -1,    -1,   155,   156,   157,   158,   159,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,   173,    -1,   175,   176,    -1,    -1,   179,   180,   181,
      -1,    -1,    -1,   185,    -1,   187,   188,    -1,   190,   191,
     192,    -1,   194,    -1,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,    -1,    -1,   209,   210,   211,
      -1,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,   258,   259,   260,    -1,
     262,   263,   264,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,    -1,
     104,   105,    -1,    -1,    -1,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,    -1,    -1,    -1,   123,
      -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   146,   147,   148,   149,   150,   151,    -1,    -1,
      -1,   155,   156,   157,   158,   159,    -1,    -1,    -1,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,   173,
      -1,   175,   176,    -1,    -1,   179,   180,   181,    -1,    -1,
      -1,   185,    -1,   187,   188,    -1,   190,   191,   192,    -1,
     194,    -1,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,    -1,    -1,   209,   210,   211,    -1,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    20,    21,    22,    23,    24,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,    -1,   104,   105,
      -1,    -1,    -1,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,   123,    -1,   125,
     126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,   148,   149,   150,   151,    -1,    -1,    -1,   155,
     156,   157,   158,   159,    -1,    -1,    -1,    -1,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,   173,    -1,   175,
     176,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,   185,
      -1,   187,   188,    -1,   190,   191,   192,    -1,   194,    -1,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,    -1,    -1,   209,   210,   211,    -1,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    24,    -1,    -1,    27,
      -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,
      -1,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,    -1,    -1,    -1,   123,    -1,   125,   126,   127,
     128,    -1,   130,    -1,    -1,    -1,   134,   135,   136,   137,
     138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,
     148,   149,   150,   151,    -1,    -1,    -1,   155,   156,    -1,
     158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,   173,    -1,    -1,    -1,    -1,
      -1,   179,   180,   181,    -1,    -1,    -1,   185,    -1,   187,
     188,    -1,   190,   191,   192,    -1,   194,    -1,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,    -1,
      -1,   209,   210,   211,    -1,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
     258,   259,   260,    -1,   262,   263,   264,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
      -1,    -1,    -1,   123,    -1,   125,   126,   127,   128,    -1,
     130,    -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,
      -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,
     150,   151,    -1,    -1,    -1,   155,   156,    -1,   158,   159,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,   173,    -1,    -1,    -1,    -1,    -1,   179,
     180,   181,    -1,    -1,    -1,   185,    -1,   187,   188,    -1,
      -1,    -1,   192,    -1,   194,    -1,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,    -1,    -1,   209,
     210,   211,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,   258,   259,
     260,    -1,   262,   263,   264,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,
      -1,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    -1,    99,   100,   101,
      -1,    -1,   104,   105,    -1,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   125,   126,   127,   128,    -1,   130,    -1,
      -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   146,   147,    -1,   149,   150,   151,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   159,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,
      -1,    -1,    -1,   185,    -1,   187,   188,    -1,    -1,    -1,
     192,    -1,   194,    -1,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,    -1,    -1,   209,   210,    -1,
      -1,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,   258,   259,   260,    -1,
     262,   263,   264,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,    23,
      24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    -1,    99,   100,   101,    -1,    -1,
     104,   105,    -1,    -1,    -1,    -1,   110,   111,   112,   113,
     114,   115,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   146,   147,    -1,   149,   150,   151,    -1,    -1,
      -1,    -1,    -1,    -1,   158,   159,    -1,    -1,    -1,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   179,   180,   181,    -1,    -1,
      -1,   185,    -1,   187,   188,    -1,    -1,    -1,   192,    -1,
     194,    -1,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,    -1,    -1,   209,   210,    -1,    -1,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    24,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    -1,    99,
     100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   115,   116,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   125,   126,   127,   128,    -1,
     130,    -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,
      -1,    -1,    -1,    -1,    -1,   145,   146,   147,    -1,   149,
     150,   151,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,
     180,   181,    -1,    -1,    -1,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,    -1,    -1,   209,
     210,    -1,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,   258,   259,
     260,    -1,   262,   263,   264,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    -1,    99,   100,   101,    -1,    -1,   104,   105,
      -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,
     126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,    -1,   149,   150,   151,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   159,    -1,    -1,    -1,    -1,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,   185,
      -1,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,    -1,    -1,   209,   210,    -1,    -1,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,    17,    18,    -1,    -1,    -1,    -1,    23,
      24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    -1,    99,   100,   101,    -1,    -1,
     104,   105,    -1,    -1,    -1,    -1,   110,   111,   112,   113,
     114,   115,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   146,   147,    -1,   149,   150,   151,    -1,    -1,
      -1,    -1,    -1,    -1,   158,   159,    -1,    -1,    -1,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   179,   180,   181,    -1,    -1,
      -1,   185,    -1,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,    -1,    -1,   209,   210,    -1,    -1,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,    23,    24,    -1,    -1,    27,
      -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      -1,    99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,   116,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,   127,
     128,    -1,   130,    -1,    -1,    -1,   134,   135,   136,   137,
     138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,
      -1,   149,   150,   151,    -1,    -1,    -1,   155,    -1,    -1,
     158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   179,   180,   181,    -1,    -1,    -1,   185,   186,   187,
     188,    -1,    -1,    -1,   192,    -1,   194,    -1,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,    -1,
      -1,   209,   210,    -1,    -1,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
     258,   259,   260,    -1,   262,   263,   264,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    -1,    99,   100,   101,
      -1,    -1,   104,   105,    -1,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   125,   126,   127,   128,    -1,   130,    -1,
      -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   146,   147,    -1,   149,   150,   151,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   159,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,
      -1,    -1,    -1,   185,   186,   187,   188,    -1,    -1,    -1,
     192,    -1,   194,    -1,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,    -1,    -1,   209,   210,    -1,
      -1,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,   258,   259,   260,    -1,
     262,   263,   264,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,    23,    24,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    -1,    99,   100,   101,    -1,    -1,   104,   105,
      -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,
     126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,    -1,   149,   150,   151,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   159,    -1,    -1,    -1,    -1,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,   185,
     186,   187,   188,    -1,    -1,    -1,   192,    -1,   194,    -1,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,    -1,    -1,   209,   210,    -1,    -1,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,    23,    24,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    -1,    99,
     100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   115,   116,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   125,   126,   127,   128,    -1,
     130,    -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,
      -1,    -1,    -1,    -1,    -1,   145,   146,   147,    -1,   149,
     150,   151,    -1,    -1,    -1,   155,    -1,    -1,   158,   159,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,
     180,   181,    -1,    -1,    -1,   185,    -1,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,    -1,    -1,   209,
     210,    -1,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,   258,   259,
     260,    -1,   262,   263,   264,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,    23,
      24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    -1,    99,   100,   101,    -1,    -1,
     104,   105,    -1,    -1,    -1,    -1,   110,   111,   112,   113,
     114,   115,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   146,   147,    -1,   149,   150,   151,    -1,    -1,
      -1,   155,    -1,    -1,   158,   159,    -1,    -1,    -1,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   179,   180,   181,    -1,    -1,
      -1,   185,    -1,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,    -1,    -1,   209,   210,    -1,    -1,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,    23,    24,    -1,    -1,    27,
      -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      -1,    99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,   116,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,   127,
     128,    -1,   130,    -1,    -1,    -1,   134,   135,   136,   137,
     138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,
      -1,   149,   150,   151,    -1,    -1,    -1,   155,    -1,    -1,
     158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   179,   180,   181,    -1,    -1,    -1,   185,    -1,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,    -1,
      -1,   209,   210,    -1,    -1,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
     258,   259,   260,    -1,   262,   263,   264,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    -1,    99,   100,   101,
      -1,    -1,   104,   105,    -1,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   125,   126,   127,   128,    -1,   130,    -1,
      -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   146,   147,    -1,   149,   150,   151,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   159,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,
      -1,    -1,    -1,   185,    -1,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,    -1,    -1,   209,   210,    -1,
      -1,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,   258,   259,   260,    -1,
     262,   263,   264,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,    23,    24,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    -1,    -1,    45,
      46,    47,    -1,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    -1,    61,    -1,    -1,    64,    65,
      66,    67,    68,    -1,    70,    -1,    72,    -1,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    -1,    -1,    99,   100,   101,    -1,    -1,   104,   105,
      -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,
     126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,    -1,   149,   150,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   159,    -1,    -1,    -1,    -1,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,   185,
      -1,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,    -1,    -1,    -1,   210,    -1,    -1,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    -1,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,    -1,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,    11,    19,    20,    21,    22,    23,    24,    27,    31,
      32,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    94,    95,
      96,    97,    98,    99,   100,   101,   104,   105,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   123,
     125,   126,   127,   128,   130,   134,   135,   136,   137,   138,
     145,   146,   147,   148,   149,   150,   151,   155,   156,   157,
     158,   159,   164,   165,   166,   167,   168,   169,   170,   171,
     173,   175,   176,   179,   180,   181,   185,   187,   188,   190,
     191,   192,   194,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   209,   210,   211,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   258,   259,   260,   262,   263,   264,   265,   266,   267,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   324,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   354,   355,   359,   360,   363,
     366,   369,   370,   372,   377,   378,   379,   380,   384,   393,
     394,   396,   397,   398,   403,   405,   407,   408,   413,   432,
     435,   439,   442,   443,   444,   445,   447,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   493,   494,   495,   509,
     510,   512,   513,   514,   515,   516,   517,   518,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   538,   539,
     540,   541,   546,   547,   548,   549,   550,   551,   554,   611,
     613,   614,   615,    31,    32,    49,   183,   213,   394,   183,
     394,   183,   394,    25,    35,    36,    38,    39,    47,    57,
      58,    64,    66,    75,    79,   110,   111,   112,   159,   168,
     200,   218,   228,   260,   286,   287,   288,   289,   290,   292,
     293,   294,   295,   296,   301,   302,   361,   362,   381,   382,
     385,   386,   387,   388,   159,   152,   155,   152,   155,   152,
     155,    67,    72,   117,   400,   155,   371,   155,    23,    32,
      61,   117,   272,   412,   414,   415,   152,   155,   155,   155,
     117,   117,   152,   155,   155,   155,    94,   152,   219,   220,
     121,   121,   121,   152,   155,    27,    37,    42,    44,    46,
      47,    48,    51,    60,    65,    68,    71,    73,    74,    76,
      90,    91,    97,   104,   113,   114,   134,   137,   138,   168,
     171,   179,   180,   188,   200,   222,   224,   226,   227,   234,
     236,   237,   238,   239,   242,   243,   477,   613,   614,   121,
     121,   121,    37,    43,    44,    60,    62,    63,    71,    97,
     223,   613,   117,   121,   121,   186,   394,   613,   152,   121,
      15,   612,   613,    17,    18,   613,   121,   121,   121,   469,
     152,    28,   212,   214,   223,   225,   155,   223,   225,   223,
     223,   228,   117,   152,   373,   240,   240,   241,   155,   152,
     326,     0,   328,   329,    31,    49,   331,   332,     1,   189,
     325,   189,   325,   136,   141,   106,   189,   395,    40,    46,
      51,    70,   167,   170,   185,   210,   399,   404,   405,   406,
     420,   421,   425,   166,    92,   131,   139,   140,   142,   150,
     154,   156,   161,   178,   201,   202,   203,   204,   205,   206,
     461,   462,   248,   157,   175,   197,   116,   145,   158,   192,
     199,   208,   135,   149,    50,   198,   100,   101,   157,   175,
     460,   152,   466,   469,   190,   191,   153,   481,   482,   477,
     481,   477,   155,   481,   120,   144,   155,   183,   183,   183,
     155,   611,   181,   194,   181,   194,   165,   181,   614,   613,
     168,   200,    47,   386,    47,   613,   151,   117,    44,    47,
      79,   105,   167,   612,   219,   220,   221,   299,   300,   245,
     584,   613,   292,   613,   297,   297,   299,   300,   303,   286,
     294,   362,   111,   382,   385,   612,   394,   186,   394,    44,
      63,   186,   534,   535,   394,   186,   192,   613,   283,   283,
     409,   410,   613,   117,   416,   117,   186,   389,   390,   152,
     391,   394,     1,   159,   611,   112,   159,   353,   611,   613,
     117,   141,   106,   394,    27,   186,   612,   613,   613,   613,
     433,   434,   613,   394,   186,   394,   394,   536,   613,   394,
     152,   152,   394,   186,   192,   613,   433,   186,    33,   497,
     498,   499,   394,     8,   174,    16,   394,   212,    27,   397,
     397,   186,   397,   397,   397,   397,   229,   552,   553,   613,
     374,   397,   397,   394,   189,   325,   189,   325,     3,   332,
     333,   393,   332,   333,   393,    31,   334,   393,   334,   393,
     141,   397,   397,   396,   117,   167,   169,   169,   397,   397,
     444,   445,   447,   447,   447,   447,   446,   447,   447,   447,
      71,   451,   451,   450,   452,   452,   452,   452,   453,   453,
     454,   454,   229,    94,    94,    94,   183,   394,   469,   469,
     394,   482,   186,   397,   492,   612,   148,   186,   492,    27,
     383,   484,   106,   106,   371,    27,   614,   614,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,   336,   337,
     338,    94,   136,   141,   356,   357,   358,   613,   159,   159,
     336,   611,   126,   131,    54,    57,    99,   250,   263,   265,
     276,   277,   278,   280,   282,   585,   586,   587,   588,   589,
     590,   597,   603,   604,   245,    94,   235,   365,   298,   613,
     613,   613,   117,   131,   183,   183,   186,   186,   183,   106,
     186,   106,   186,   106,    34,    94,    96,   146,   411,   412,
     520,   613,    56,   215,   253,   401,   402,   613,    94,   106,
     186,   394,   186,   612,    96,    44,   612,   611,    96,   141,
     520,   613,   397,   415,   183,   186,   186,   186,   186,   141,
     106,   187,   146,   520,   183,   186,   186,   152,   183,   394,
     394,   183,   106,   186,   106,   186,   187,   613,   498,   499,
     129,   195,   183,   183,   130,   189,    94,   216,   217,   231,
      94,   216,   217,   231,    94,   235,   223,   106,   233,   141,
      31,   375,   394,   186,   183,   332,    31,    31,   189,   325,
     189,   112,   397,   189,   613,   169,   397,   426,   427,   117,
     422,   423,   447,   152,   155,   258,   465,   484,   558,   561,
     562,   563,   564,   565,   569,   571,   573,   574,    47,   151,
     155,   209,   521,   523,   525,   526,   542,   543,   544,   545,
     613,   521,   519,   525,   519,   183,   184,   106,   186,   186,
     106,   186,   147,   164,   147,   164,   136,   152,   392,   371,
     371,   337,   131,   523,   358,   397,   520,   611,   611,   127,
     128,   611,   276,   277,   278,   282,   613,   262,   273,   262,
     273,    27,   285,    96,   112,   155,   591,   594,   585,    37,
      43,    60,    62,    71,    97,   223,   364,   526,   290,   291,
     225,   298,   307,    94,   365,   298,   613,   611,   152,   536,
     537,   613,   536,   537,   117,   126,   521,   117,   397,   146,
     412,   146,    34,   146,   411,   412,   146,   520,   253,    53,
      59,    77,   117,   411,   417,   418,   419,   402,   520,   521,
     390,    94,   183,   196,   131,   352,   611,   159,   131,    96,
     352,   397,   141,   412,   152,   397,   117,   397,   397,   146,
      99,   436,   437,   438,    99,   440,   441,   394,   183,   183,
     152,   536,   536,   397,    33,   499,   129,   195,     9,    10,
     102,   122,   124,   193,   391,   494,   496,   507,   508,   511,
      27,   230,   232,   397,   397,   397,   230,   232,   397,   397,
     397,   397,   397,   397,   117,   397,   397,   117,   376,   106,
     189,   183,   373,   244,   555,   556,   189,   112,   393,   393,
     393,   426,    95,   105,   115,   126,   428,   429,   430,   431,
     106,   613,   106,   394,   558,   565,   152,   284,   448,   610,
      96,   168,   251,   252,   254,   261,   271,   283,   559,   560,
     579,   580,   581,   582,   605,   608,   257,   259,   566,   584,
     266,   570,   606,   246,   247,   269,   575,   576,   155,   155,
     523,   155,   143,   175,   192,   522,   143,   397,   484,   394,
     136,   373,   136,   152,   538,   357,   285,    27,    96,   112,
     155,   598,    27,   591,   365,   522,   225,   225,   467,   286,
     305,   364,   225,   520,   189,   183,   394,   186,   186,   143,
     186,   186,   410,   146,   411,   613,   397,   146,   397,   126,
     397,   146,   412,   146,   397,   146,   117,   117,   397,   613,
     419,    77,   521,   397,   611,   106,   352,   397,   141,   183,
     394,   434,   397,   397,   112,   437,    99,   185,   117,   521,
     112,   441,   183,   183,   394,   186,   186,   131,   193,   496,
       7,   613,   193,   507,   189,   231,   231,   231,   231,   235,
     553,   185,   613,   376,   478,   557,   556,   611,   127,   128,
     430,   431,   431,   427,   105,   424,   423,   183,   186,   558,
     572,   249,   215,   253,   267,   274,   609,    96,   255,   256,
     607,   249,   562,   609,   450,   579,   563,   146,   281,   567,
     568,   607,   285,   578,    78,   577,   186,   192,   521,   524,
     186,   186,   186,   183,   396,    27,   135,   199,   600,   601,
     602,    27,   599,   600,   270,   595,   106,   592,   169,   613,
     256,   365,   467,   183,   397,   146,   397,   146,   411,   397,
     146,   397,   397,   613,   613,   418,   397,   125,    96,   611,
     397,   183,   185,   397,   397,   613,   185,   117,   185,   183,
     499,   613,   193,   499,   613,   397,   397,   397,   397,   397,
     397,   141,   520,   155,   208,   392,   431,   611,   183,   452,
      52,   128,   450,   450,   268,   275,   285,   583,   583,   564,
     152,   279,    94,   186,   106,   186,   183,   598,   598,   602,
     106,   186,    27,   596,   607,   593,   594,   186,   367,   368,
     467,   117,   223,   306,   286,   169,   397,   397,   146,   397,
      53,   397,   352,   397,    94,   397,   613,   397,    93,   182,
     500,   499,   613,   195,   499,   397,   141,   117,   478,   450,
     450,   197,   394,   521,   521,    94,    27,   264,   106,   106,
     431,   520,   613,   117,   223,   613,   367,   397,   117,   521,
     185,     5,   132,   503,   504,   506,   508,    26,   133,   501,
     502,   505,   508,   195,   499,   195,   397,   613,   450,   183,
     521,   594,   368,   431,   304,   613,   117,   223,   613,   185,
     397,    93,   132,   506,   182,   133,   505,   195,   106,   186,
     397,   304,   613,   117,   397,   117,   392,   292,   304,   613,
     613,   305,   397,   305,   106,   186,   467,   467,   117,   392,
     197,   613,   286,   186,   613,   392,   223,   117,   613,   305,
     467
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
     575,   576,   577
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   323,   324,   324,   325,   326,   326,   326,   326,   327,
     327,   328,   328,   328,   328,   328,   328,   328,   328,   329,
     329,   329,   329,   330,   331,   331,   331,   332,   332,   332,
     333,   333,   333,   333,   333,   334,   334,   334,   334,   334,
     334,   334,   334,   335,   335,   336,   336,   337,   338,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   339,   339,
     339,   339,   339,   339,   339,   339,   340,   340,   340,   341,
     342,   342,   343,   343,   344,   345,   346,   346,   347,   347,
     348,   348,   348,   348,   349,   350,   351,   351,   351,   351,
     352,   352,   353,   353,   354,   354,   354,   354,   355,   356,
     356,   357,   357,   357,   358,   359,   359,   359,   359,   360,
     360,   360,   361,   361,   362,   362,   362,   362,   362,   362,
     362,   362,   362,   362,   362,   362,   362,   362,   363,   363,
     363,   363,   363,   363,   363,   363,   364,   364,   365,   365,
     366,   366,   367,   367,   368,   368,   368,   368,   369,   369,
     369,   369,   370,   370,   371,   371,   371,   371,   372,   373,
     374,   374,   375,   375,   376,   376,   376,   376,   377,   378,
     379,   380,   380,   381,   381,   382,   382,   383,   383,   384,
     384,   385,   385,   385,   385,   386,   386,   387,   387,   388,
     388,   389,   389,   390,   390,   391,   392,   393,   394,   394,
     395,   395,   396,   396,   397,   397,   397,   397,   397,   397,
     397,   397,   397,   397,   397,   397,   397,   397,   397,   397,
     397,   398,   399,   400,   400,   401,   401,   401,   402,   402,
     403,   403,   404,   405,   405,   405,   406,   406,   406,   406,
     406,   407,   407,   408,   409,   409,   410,   410,   410,   410,
     410,   410,   410,   410,   410,   410,   410,   410,   411,   412,
     413,   414,   414,   415,   415,   415,   415,   416,   416,   417,
     417,   417,   418,   418,   418,   419,   419,   419,   420,   421,
     422,   422,   423,   423,   424,   425,   425,   426,   426,   427,
     427,   428,   428,   428,   428,   428,   428,   428,   429,   429,
     430,   430,   431,   432,   432,   433,   433,   434,   434,   435,
     436,   436,   437,   438,   438,   439,   439,   440,   440,   441,
     441,   442,   443,   443,   444,   444,   445,   445,   445,   445,
     445,   446,   445,   445,   445,   445,   447,   447,   448,   448,
     449,   449,   450,   450,   450,   451,   451,   451,   451,   451,
     452,   452,   452,   453,   453,   453,   454,   454,   455,   455,
     456,   456,   457,   457,   458,   458,   459,   459,   459,   459,
     460,   460,   460,   461,   461,   461,   461,   461,   461,   462,
     462,   462,   463,   463,   463,   463,   464,   464,   465,   465,
     466,   466,   466,   467,   467,   467,   467,   468,   469,   469,
     469,   470,   470,   471,   471,   471,   471,   472,   472,   473,
     473,   473,   473,   473,   473,   473,   474,   474,   475,   475,
     476,   476,   476,   476,   476,   477,   477,   478,   478,   479,
     479,   479,   480,   480,   480,   480,   481,   481,   482,   483,
     483,   483,   483,   483,   483,   483,   483,   483,   484,   484,
     485,   485,   485,   486,   487,   487,   488,   489,   490,   491,
     491,   492,   492,   493,   493,   494,   494,   494,   495,   495,
     495,   495,   495,   495,   496,   496,   497,   497,   498,   499,
     499,   500,   500,   501,   501,   502,   502,   502,   502,   503,
     503,   504,   504,   504,   504,   505,   505,   506,   506,   507,
     507,   507,   507,   508,   508,   508,   508,   509,   509,   510,
     510,   511,   512,   512,   512,   512,   512,   512,   513,   514,
     514,   514,   514,   515,   515,   515,   515,   516,   517,   518,
     518,   518,   518,   519,   519,   520,   521,   521,   521,   522,
     522,   522,   523,   523,   523,   523,   523,   524,   524,   525,
     526,   526,   526,   526,   526,   526,   526,   526,   526,   527,
     528,   528,   528,   529,   530,   531,   531,   531,   532,   532,
     532,   532,   532,   533,   534,   534,   534,   534,   534,   534,
     534,   535,   536,   537,   538,   539,   539,   540,   541,   542,
     542,   543,   544,   544,   545,   546,   546,   546,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   548,   548,
     549,   549,   550,   551,   552,   552,   553,   554,   555,   555,
     556,   556,   556,   556,   557,   557,   558,   559,   559,   560,
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
     607,   607,   607,   608,   608,   609,   609,   610,   611,   612,
     612,   613,   613,   613,   613,   613,   613,   613,   613,   613,
     613,   613,   613,   613,   613,   613,   613,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   615,   615
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
       1,     1,     1,     1,     1,     1,     1,     1,     3,     5,
       3,     3,     5,     5,     4,     3,     3,     3,     5,     5,
       5,     5,     5,     5,     4,     3,     3,     4,     5,     6,
       1,     3,     3,     3,     3,     6,     5,     8,     4,     3,
       1,     1,     1,     2,     2,     4,     5,     5,     6,     3,
       2,     4,     1,     2,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     1,     2,     2,     2,     3,     4,
       5,     6,     4,     5,     6,     7,     1,     2,     3,     3,
       8,     9,     1,     3,     1,     2,     2,     3,    11,    14,
      13,    22,     3,     3,     2,     3,     4,     5,     2,     4,
       3,     0,     3,     2,     2,     3,     4,     5,     5,     3,
       5,     2,     2,     1,     2,     1,     4,     1,     3,     2,
       3,     1,     2,     1,     1,     4,     4,     5,     5,     7,
       5,     1,     3,     2,     3,     3,     3,     1,     1,     2,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     1,     1,     2,     4,     3,
       5,     4,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     1,     4,     3,     5,     4,     6,
       4,     6,     5,     7,     4,     5,     5,     6,     3,     3,
       2,     1,     3,     4,     5,     3,     6,     4,     5,     1,
       2,     3,     1,     2,     1,     6,     3,     3,     2,     3,
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
       3,     2,     2,     1,     2,     2,     1,     1,     1,     3,
       3,     1,     1,     1,     2,     1,     2,     2,     1,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     2,     1,
       2,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     4,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     3,     1,     4,     4,     3,
       4,     1,     3,     1,     1,     1,     1,     1,     4,     5,
       8,     9,     9,    10,     1,     2,     1,     2,     6,     0,
       1,     3,     3,     0,     1,     1,     1,     2,     2,     0,
       1,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     2,     3,
       3,     2,     1,     1,     1,     1,     1,     1,     4,     2,
       3,     6,     7,     2,     3,     6,     7,     4,     4,     2,
       3,     6,     7,     1,     2,     2,     1,     2,     3,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     4,     4,     3,     3,     3,     4,     4,     3,     4,
       6,     4,     6,     4,     3,     4,     6,     6,     4,     6,
       6,     4,     1,     2,     1,     1,     1,     3,     3,     1,
       1,     4,     5,     6,     3,     3,     3,     3,     5,     7,
       7,     5,     5,     5,     7,     7,     5,     5,     3,     3,
       5,     7,     5,     7,     1,     4,     3,     5,     1,     2,
       3,     7,    10,    13,     1,     3,     2,     0,     1,     1,
       2,     1,     3,     1,     3,     1,     4,     1,     2,     3,
       0,     1,     0,     1,     4,     2,     3,     1,     0,     1,
       4,     0,     1,     2,     1,     3,     0,     1,     2,     2,
       1,     0,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     1,     1,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       2,     2,     3,     1,     2,     2,     5,     2,     1,     1,
       0,     2,     1,     3,     4,     0,     2,     0,     2,     4,
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
  "\"'QName'\"", "\"'EQName'\"", "\"'%QName'\"",
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
  "LetClause", "VarGetsDeclList", "VarGetsDecl", "WindowVarDecl",
  "WindowVars", "WindowVars3", "WindowVars2", "WhereClause",
  "GroupByClause", "GroupSpecList", "GroupSpec", "GroupCollationSpec",
  "OrderByClause", "OrderSpecList", "OrderSpec", "OrderModifier",
  "OrderDirSpec", "OrderEmptySpec", "OrderCollationSpec", "QuantifiedExpr",
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
  "CatchListExpr", "CatchExpr", "NameTestList", "FTSelection",
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
  "FUNCTION_NAME", "EQNAME", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const xquery_parser::rhs_number_type
  xquery_parser::yyrhs_[] =
  {
       324,     0,    -1,   326,    -1,   309,   326,    -1,     1,     3,
      -1,   328,    -1,   327,   328,    -1,   329,    -1,   327,   329,
      -1,   213,   214,    27,   189,    -1,   213,   214,    27,   130,
      27,   189,    -1,   331,   189,   393,    -1,   332,   189,   393,
      -1,   331,   189,   332,   189,   393,    -1,   393,    -1,   331,
     325,   393,    -1,   332,   325,   393,    -1,   331,   189,   332,
     325,   393,    -1,   331,   325,   332,   189,   393,    -1,   330,
      -1,   330,   331,   189,    -1,   330,   332,   189,    -1,   330,
     331,   189,   332,   189,    -1,    32,   159,   612,   131,   611,
     189,    -1,   333,    -1,   331,   189,   333,    -1,   331,   325,
     333,    -1,   334,    -1,   332,   189,   334,    -1,   332,   325,
     334,    -1,   339,    -1,   340,    -1,   341,    -1,   343,    -1,
     345,    -1,   360,    -1,   363,    -1,   355,    -1,   335,    -1,
     384,    -1,   366,    -1,   369,    -1,   344,    -1,    31,   112,
      79,   336,    -1,    31,    79,   613,   336,    -1,   337,    -1,
     336,   337,    -1,   338,   131,   538,    -1,    80,    -1,    88,
      -1,    81,    -1,    82,    -1,    83,    -1,    84,    -1,    89,
      -1,    85,    -1,    86,    -1,    87,    -1,   342,    -1,   349,
      -1,   350,    -1,   370,    -1,   346,    -1,   347,    -1,   348,
      -1,   546,    -1,   351,    -1,   354,    -1,    49,    23,     1,
      -1,    31,   159,   612,   131,   611,    -1,    31,    36,   181,
      -1,    31,    36,   194,    -1,    31,   112,    44,   159,   611,
      -1,    31,   112,    47,   159,   611,    -1,    31,    57,   613,
      27,    -1,    31,   260,   584,    -1,    31,    58,   168,    -1,
      31,    58,   200,    -1,    31,   112,   167,   126,   127,    -1,
      31,   112,   167,   126,   128,    -1,    31,    39,   181,   106,
     147,    -1,    31,    39,   181,   106,   164,    -1,    31,    39,
     165,   106,   147,    -1,    31,    39,   165,   106,   164,    -1,
      31,   112,   105,   611,    -1,    31,    35,   611,    -1,    49,
      61,   611,    -1,    49,    61,   353,   611,    -1,    49,    61,
     611,    96,   352,    -1,    49,    61,   353,   611,    96,   352,
      -1,   611,    -1,   352,   106,   611,    -1,   159,   612,   131,
      -1,   112,    44,   159,    -1,    49,    32,   611,    -1,    49,
      32,   159,   612,   131,   611,    -1,    49,    32,   611,    96,
     352,    -1,    49,    32,   159,   612,   131,   611,    96,   352,
      -1,    31,   110,   151,   356,    -1,    94,   523,   357,    -1,
     357,    -1,   358,    -1,   136,    -1,   136,   358,    -1,   141,
     397,    -1,    31,   111,   117,   613,    -1,    31,   111,   117,
     613,   520,    -1,    31,   381,   111,   117,   613,    -1,    31,
     381,   111,   117,   613,   520,    -1,   359,   141,   397,    -1,
     359,   136,    -1,   359,   136,   141,   397,    -1,   362,    -1,
     361,   362,    -1,   287,    -1,   288,    -1,   289,    -1,   290,
      -1,   168,    -1,   200,    -1,   228,   300,    -1,   228,   299,
      -1,   301,   300,    -1,   301,   299,    -1,   292,    -1,   293,
     292,    -1,   296,   297,    -1,   295,   297,    -1,    31,   286,
     613,    -1,    31,   286,   613,   365,    -1,    31,   286,   613,
      94,   364,    -1,    31,   286,   613,    94,   364,   365,    -1,
      31,   361,   286,   613,    -1,    31,   361,   286,   613,   365,
      -1,    31,   361,   286,   613,    94,   364,    -1,    31,   361,
     286,   613,    94,   364,   365,    -1,   526,    -1,   526,   522,
      -1,   235,   291,   225,    -1,   235,   290,   225,    -1,    31,
     294,   613,   298,   225,   467,   169,   367,    -1,    31,   361,
     294,   613,   298,   225,   467,   169,   367,    -1,   368,    -1,
     367,   106,   368,    -1,   467,    -1,   467,   520,    -1,   467,
     431,    -1,   467,   520,   431,    -1,    31,   302,   303,   613,
     298,   286,   613,   117,   613,   304,   397,    -1,    31,   302,
     303,   613,   298,   286,   613,   223,   117,   613,   304,   292,
     305,   467,    -1,    31,   302,   303,   613,   298,   286,   613,
     306,   223,   117,   613,   304,   397,    -1,    31,   302,   303,
     613,   307,   305,   256,   286,   613,   223,   117,   613,   305,
     467,   197,   286,   613,   223,   117,   613,   305,   467,    -1,
      31,    38,   181,    -1,    31,    38,   194,    -1,   155,   186,
      -1,   155,   389,   186,    -1,   155,   186,    94,   521,    -1,
     155,   389,   186,    94,   521,    -1,   236,   373,    -1,   152,
     374,   394,   183,    -1,   374,   375,   189,    -1,    -1,   375,
     106,   376,    -1,    31,   376,    -1,   117,   613,    -1,   117,
     613,   520,    -1,   117,   613,   141,   397,    -1,   117,   613,
     520,   141,   397,    -1,    65,   117,   613,   141,   397,    -1,
     239,   241,   397,    -1,   242,   155,   397,   186,   373,    -1,
     237,   240,    -1,   238,   240,    -1,   382,    -1,   381,   382,
      -1,    25,    -1,    25,   155,   383,   186,    -1,   484,    -1,
     383,   106,   484,    -1,    31,   385,    -1,    31,   381,   385,
      -1,   386,    -1,    66,   386,    -1,   388,    -1,   387,    -1,
      47,   614,   371,   392,    -1,    47,   614,   371,   136,    -1,
      64,    47,   614,   371,   373,    -1,    64,    47,   614,   371,
     136,    -1,    75,    47,   614,   371,   152,   396,   183,    -1,
      75,    47,   614,   371,   136,    -1,   390,    -1,   389,   106,
     390,    -1,   117,   613,    -1,   117,   613,   520,    -1,   152,
     394,   183,    -1,   152,   394,   183,    -1,   394,    -1,   396,
      -1,   396,   395,    -1,   189,    -1,   395,   396,   189,    -1,
     397,    -1,   396,   106,   397,    -1,   398,    -1,   432,    -1,
     435,    -1,   439,    -1,   442,    -1,   443,    -1,   547,    -1,
     548,    -1,   550,    -1,   549,    -1,   551,    -1,   554,    -1,
     378,    -1,   379,    -1,   380,    -1,   377,    -1,   372,    -1,
     407,   399,    -1,   185,   397,    -1,    67,   283,    -1,    72,
     283,    -1,   215,    -1,   253,    -1,    56,   253,    -1,   401,
     417,    77,   397,    -1,   401,    77,   397,    -1,    46,   400,
     416,   402,   402,    -1,    46,   400,   416,   402,    -1,    40,
     117,   613,    -1,   408,    -1,   413,    -1,   403,    -1,   405,
      -1,   420,    -1,   425,    -1,   421,    -1,   404,    -1,   405,
      -1,   407,   406,    -1,    46,   117,   409,    -1,   410,    -1,
     409,   106,   117,   410,    -1,   613,   146,   397,    -1,   613,
      34,   126,   146,   397,    -1,   613,   520,   146,   397,    -1,
     613,   520,    34,   126,   146,   397,    -1,   613,   411,   146,
     397,    -1,   613,    34,   126,   411,   146,   397,    -1,   613,
     520,   411,   146,   397,    -1,   613,   520,    34,   126,   411,
     146,   397,    -1,   613,   412,   146,   397,    -1,   613,   520,
     412,   146,   397,    -1,   613,   411,   412,   146,   397,    -1,
     613,   520,   411,   412,   146,   397,    -1,    96,   117,   613,
      -1,   272,   117,   613,    -1,    51,   414,    -1,   415,    -1,
     414,   106,   415,    -1,   117,   613,   141,   397,    -1,   117,
     613,   520,   141,   397,    -1,   412,   141,   397,    -1,   117,
     613,   520,   412,   141,   397,    -1,   117,   613,   146,   397,
      -1,   117,   613,   520,   146,   397,    -1,   418,    -1,   117,
     613,    -1,   117,   613,   418,    -1,   411,    -1,   411,   419,
      -1,   419,    -1,    59,   117,   613,    53,   117,   613,    -1,
      53,   117,   613,    -1,    59,   117,   613,    -1,   210,   397,
      -1,   170,   169,   422,    -1,   423,    -1,   422,   106,   423,
      -1,   117,   613,    -1,   117,   613,   424,    -1,   105,   611,
      -1,   167,   169,   426,    -1,    70,   167,   169,   426,    -1,
     427,    -1,   426,   106,   427,    -1,   397,    -1,   397,   428,
      -1,   429,    -1,   430,    -1,   431,    -1,   429,   430,    -1,
     429,   431,    -1,   430,   431,    -1,   429,   430,   431,    -1,
      95,    -1,   115,    -1,   126,   127,    -1,   126,   128,    -1,
     105,   611,    -1,    68,   117,   433,   187,   397,    -1,   134,
     117,   433,   187,   397,    -1,   434,    -1,   433,   106,   117,
     434,    -1,   613,   146,   397,    -1,   613,   520,   146,   397,
      -1,    73,   155,   394,   186,   436,   112,   185,   397,    -1,
     437,    -1,   436,   437,    -1,   438,   185,   397,    -1,    99,
     397,    -1,   438,    99,   397,    -1,    74,   155,   394,   186,
     440,   112,   185,   397,    -1,    74,   155,   394,   186,   440,
     112,   117,   613,   185,   397,    -1,   441,    -1,   440,   441,
      -1,    99,   521,   185,   397,    -1,    99,   117,   613,    94,
     521,   185,   397,    -1,    48,   155,   394,   186,   196,   397,
     125,   397,    -1,   444,    -1,   443,   166,   444,    -1,   445,
      -1,   444,    92,   445,    -1,   447,    -1,   447,   461,   447,
      -1,   447,   462,   447,    -1,   447,   131,   447,    -1,   447,
     161,   447,    -1,    -1,   447,   156,   446,   447,    -1,   447,
     154,   447,    -1,   447,   142,   447,    -1,   447,   140,   447,
      -1,   449,    -1,   449,   248,    71,   558,   448,    -1,    -1,
     610,    -1,   450,    -1,   450,   197,   450,    -1,   451,    -1,
     450,   175,   451,    -1,   450,   157,   451,    -1,   452,    -1,
     451,   192,   452,    -1,   451,   116,   452,    -1,   451,   145,
     452,    -1,   451,   158,   452,    -1,   453,    -1,   452,   199,
     453,    -1,   452,   208,   453,    -1,   454,    -1,   453,   149,
     454,    -1,   453,   135,   454,    -1,   455,    -1,   455,    50,
     229,   521,    -1,   456,    -1,   456,   198,    94,   521,    -1,
     457,    -1,   457,   100,    94,   519,    -1,   458,    -1,   458,
     101,    94,   519,    -1,   460,    -1,   459,   460,    -1,   175,
      -1,   157,    -1,   459,   175,    -1,   459,   157,    -1,   463,
      -1,   467,    -1,   464,    -1,   201,    -1,   206,    -1,   205,
      -1,   204,    -1,   203,    -1,   202,    -1,   150,    -1,   178,
      -1,   139,    -1,    76,   152,   394,   183,    -1,    76,   220,
     152,   394,   183,    -1,    76,   219,   152,   394,   183,    -1,
      76,    94,   536,   152,   394,   183,    -1,   465,   152,   183,
      -1,   465,   152,   394,   183,    -1,   466,    -1,   465,   466,
      -1,   176,   613,    16,    -1,   176,    17,    -1,   176,    18,
      -1,   468,    -1,   468,   469,    -1,   191,   469,    -1,   469,
      -1,   190,    -1,   470,    -1,   470,   190,   469,    -1,   470,
     191,   469,    -1,   471,    -1,   480,    -1,   472,    -1,   472,
     481,    -1,   475,    -1,   475,   481,    -1,   473,   477,    -1,
     474,    -1,   104,   121,    -1,   113,   121,    -1,    97,   121,
      -1,   188,   121,    -1,   114,   121,    -1,   138,   121,    -1,
     137,   121,    -1,   477,    -1,    98,   477,    -1,   476,   477,
      -1,   119,    -1,   171,   121,    -1,    90,   121,    -1,   180,
     121,    -1,   179,   121,    -1,    91,   121,    -1,   526,    -1,
     478,    -1,   613,    -1,   479,    -1,   192,    -1,    11,    -1,
      19,    -1,   483,    -1,   480,   481,    -1,   480,   155,   186,
      -1,   480,   155,   492,   186,    -1,   482,    -1,   481,   482,
      -1,   153,   394,   184,    -1,   484,    -1,   486,    -1,   487,
      -1,   488,    -1,   491,    -1,   493,    -1,   489,    -1,   490,
      -1,   539,    -1,   485,    -1,   538,    -1,   109,    -1,   148,
      -1,   123,    -1,   117,   613,    -1,   155,   186,    -1,   155,
     394,   186,    -1,   118,    -1,   168,   152,   394,   183,    -1,
     200,   152,   394,   183,    -1,   614,   155,   186,    -1,   614,
     155,   492,   186,    -1,   397,    -1,   492,   106,   397,    -1,
     494,    -1,   512,    -1,   495,    -1,   509,    -1,   510,    -1,
     156,   613,   499,   129,    -1,   156,   613,   497,   499,   129,
      -1,   156,   613,   499,   195,   193,   613,   499,   195,    -1,
     156,   613,   499,   195,   496,   193,   613,   499,   195,    -1,
     156,   613,   497,   499,   195,   193,   613,   499,   195,    -1,
     156,   613,   497,   499,   195,   496,   193,   613,   499,   195,
      -1,   507,    -1,   496,   507,    -1,   498,    -1,   497,   498,
      -1,    33,   613,   499,   131,   499,   500,    -1,    -1,    33,
      -1,   182,   501,   182,    -1,    93,   503,    93,    -1,    -1,
     502,    -1,   133,    -1,   505,    -1,   502,   133,    -1,   502,
     505,    -1,    -1,   504,    -1,   132,    -1,   506,    -1,   504,
     132,    -1,   504,   506,    -1,    26,    -1,   508,    -1,     5,
      -1,   508,    -1,   494,    -1,    10,    -1,   511,    -1,   508,
      -1,     9,    -1,   122,    -1,   124,    -1,   391,    -1,   211,
      28,   212,    -1,   211,   212,    -1,   173,   612,   174,    -1,
     173,   612,     8,    -1,   102,     7,    -1,   513,    -1,   514,
      -1,   515,    -1,   516,    -1,   517,    -1,   518,    -1,    42,
     152,   394,   183,    -1,    20,   183,    -1,    20,   394,   183,
      -1,    44,   152,   394,   183,   152,   183,    -1,    44,   152,
     394,   183,   152,   394,   183,    -1,    21,   183,    -1,    21,
     394,   183,    -1,    97,   152,   394,   183,   152,   183,    -1,
      97,   152,   394,   183,   152,   394,   183,    -1,    71,   152,
     394,   183,    -1,    37,   152,   394,   183,    -1,    22,   183,
      -1,    22,   394,   183,    -1,    60,   152,   394,   183,   152,
     183,    -1,    60,   152,   394,   183,   152,   394,   183,    -1,
     525,    -1,   525,   143,    -1,    94,   521,    -1,   523,    -1,
     523,   522,    -1,   209,   155,   186,    -1,   143,    -1,   192,
      -1,   175,    -1,   525,    -1,   526,    -1,   151,   155,   186,
      -1,   542,    -1,   545,    -1,   521,    -1,   524,   106,   521,
      -1,   613,    -1,   528,    -1,   534,    -1,   532,    -1,   535,
      -1,   533,    -1,   531,    -1,   530,    -1,   529,    -1,   527,
      -1,   223,   155,   186,    -1,    43,   155,   186,    -1,    43,
     155,   534,   186,    -1,    43,   155,   535,   186,    -1,    71,
     155,   186,    -1,    37,   155,   186,    -1,    60,   155,   186,
      -1,    60,   155,   612,   186,    -1,    60,   155,    27,   186,
      -1,    97,   155,   186,    -1,    97,   155,   613,   186,    -1,
      97,   155,   613,   106,   536,   186,    -1,    97,   155,   192,
     186,    -1,    97,   155,   192,   106,   536,   186,    -1,    62,
     155,   613,   186,    -1,    44,   155,   186,    -1,    44,   155,
     613,   186,    -1,    44,   155,   613,   106,   536,   186,    -1,
      44,   155,   613,   106,   537,   186,    -1,    44,   155,   192,
     186,    -1,    44,   155,   192,   106,   536,   186,    -1,    44,
     155,   192,   106,   537,   186,    -1,    63,   155,   613,   186,
      -1,   613,    -1,   613,   143,    -1,    27,    -1,   540,    -1,
     541,    -1,   613,   144,   148,    -1,    47,   371,   391,    -1,
     543,    -1,   544,    -1,    47,   155,   192,   186,    -1,    47,
     155,   186,    94,   521,    -1,    47,   155,   524,   186,    94,
     521,    -1,   155,   523,   186,    -1,    31,   218,   219,    -1,
      31,   218,   220,    -1,    31,   218,   221,    -1,   224,   223,
     397,   231,   397,    -1,   224,   223,   397,    94,   230,   231,
     397,    -1,   224,   223,   397,    94,   232,   231,   397,    -1,
     224,   223,   397,   216,   397,    -1,   224,   223,   397,   217,
     397,    -1,   224,   225,   397,   231,   397,    -1,   224,   225,
     397,    94,   230,   231,   397,    -1,   224,   225,   397,    94,
     232,   231,   397,    -1,   224,   225,   397,   216,   397,    -1,
     224,   225,   397,   217,   397,    -1,   222,   223,   397,    -1,
     222,   225,   397,    -1,   227,   223,   397,   235,   397,    -1,
     227,   228,   229,   223,   397,   235,   397,    -1,   226,   223,
     397,    94,   397,    -1,   234,   117,   552,   233,   397,   185,
     397,    -1,   553,    -1,   552,   106,   117,   553,    -1,   613,
     141,   397,    -1,   243,   152,   394,   183,   555,    -1,   556,
      -1,   555,   556,    -1,   244,   557,   392,    -1,   244,   557,
     155,   117,   613,   186,   392,    -1,   244,   557,   155,   117,
     613,   106,   117,   613,   186,   392,    -1,   244,   557,   155,
     117,   613,   106,   117,   613,   106,   117,   613,   186,   392,
      -1,   478,    -1,   557,   208,   478,    -1,   561,   559,    -1,
      -1,   560,    -1,   579,    -1,   560,   579,    -1,   562,    -1,
     561,   261,   562,    -1,   563,    -1,   562,   257,   563,    -1,
     564,    -1,   563,   259,   146,   564,    -1,   565,    -1,   258,
     565,    -1,   569,   566,   567,    -1,    -1,   584,    -1,    -1,
     568,    -1,   281,   152,   394,   183,    -1,   573,   570,    -1,
     155,   558,   186,    -1,   571,    -1,    -1,   606,    -1,   465,
     152,   572,   183,    -1,    -1,   558,    -1,   574,   575,    -1,
     484,    -1,   152,   394,   183,    -1,    -1,   576,    -1,   247,
     577,    -1,   246,   578,    -1,   269,    -1,    -1,    78,    -1,
      -1,   285,    -1,   580,    -1,   581,    -1,   582,    -1,   608,
      -1,   605,    -1,   168,    -1,   283,   450,   583,    -1,   252,
     607,   583,    -1,   285,    -1,   275,    -1,   268,    -1,   245,
     585,    -1,   584,   245,   585,    -1,   586,    -1,   587,    -1,
     588,    -1,   603,    -1,   589,    -1,   597,    -1,   590,    -1,
     604,    -1,    99,   273,    -1,    99,   262,    -1,   265,    -1,
     280,    -1,   250,   273,    -1,   250,   262,    -1,    57,   613,
      27,    -1,   276,    -1,    54,   276,    -1,   278,   591,    -1,
     278,   155,   591,   592,   186,    -1,    54,   278,    -1,   594,
      -1,   112,    -1,    -1,   106,   593,    -1,   594,    -1,   593,
     106,   594,    -1,    96,    27,   595,   596,    -1,    -1,   270,
      27,    -1,    -1,   607,   264,    -1,   277,   285,   598,   600,
      -1,   277,   285,   112,   600,    -1,    54,   277,   285,    -1,
      96,    27,    -1,   155,   599,   186,    -1,    27,    -1,   599,
     106,    27,    -1,    -1,   601,    -1,   602,    -1,   601,   602,
      -1,   199,   598,    -1,   135,   598,    -1,   263,    27,    -1,
     282,    -1,    54,   282,    -1,    96,   215,    -1,    96,   253,
      -1,   254,   249,    -1,   266,   607,   279,    -1,   255,   450,
      -1,    96,   128,   450,    -1,    96,    52,   450,    -1,   256,
     450,   197,   450,    -1,   271,   609,    -1,   251,   609,    -1,
     274,    -1,   267,    -1,   284,   249,   452,    -1,    27,    -1,
      15,    -1,   613,    -1,   614,    -1,    97,    -1,    37,    -1,
      43,    -1,    44,    -1,   151,    -1,    48,    -1,   223,    -1,
      60,    -1,    62,    -1,    63,    -1,    71,    -1,    74,    -1,
      73,    -1,   209,    -1,   242,    -1,   615,    -1,    23,    -1,
     213,    -1,   126,    -1,    36,    -1,   260,    -1,    35,    -1,
     220,    -1,   219,    -1,   145,    -1,    42,    -1,   258,    -1,
     259,    -1,   273,    -1,   262,    -1,   250,    -1,   284,    -1,
     276,    -1,   278,    -1,   277,    -1,   282,    -1,   254,    -1,
     249,    -1,    78,    -1,   215,    -1,   253,    -1,    52,    -1,
     221,    -1,   234,    -1,   301,    -1,   228,    -1,   201,    -1,
     206,    -1,   205,    -1,   204,    -1,   203,    -1,   202,    -1,
      96,    -1,   110,    -1,   111,    -1,   185,    -1,    46,    -1,
      34,    -1,    67,    -1,    72,    -1,    59,    -1,    53,    -1,
      56,    -1,    77,    -1,    40,    -1,   146,    -1,    51,    -1,
     210,    -1,   169,    -1,   170,    -1,   167,    -1,    70,    -1,
      95,    -1,   115,    -1,   127,    -1,   128,    -1,   105,    -1,
      68,    -1,   134,    -1,   187,    -1,    99,    -1,    94,    -1,
     196,    -1,   125,    -1,   166,    -1,    92,    -1,    50,    -1,
     229,    -1,   100,    -1,   197,    -1,   116,    -1,   158,    -1,
     199,    -1,   149,    -1,   135,    -1,    76,    -1,   101,    -1,
     198,    -1,   150,    -1,   181,    -1,   194,    -1,   159,    -1,
     136,    -1,   130,    -1,   165,    -1,   147,    -1,   164,    -1,
      31,    -1,    38,    -1,    58,    -1,   112,    -1,    39,    -1,
      57,    -1,   214,    -1,    49,    -1,    61,    -1,    32,    -1,
      47,    -1,   272,    -1,   248,    -1,   281,    -1,   283,    -1,
     252,    -1,   266,    -1,   279,    -1,   271,    -1,   251,    -1,
     265,    -1,   280,    -1,   270,    -1,   264,    -1,   263,    -1,
     247,    -1,   246,    -1,   269,    -1,   255,    -1,   256,    -1,
     285,    -1,   275,    -1,   274,    -1,   267,    -1,   227,    -1,
     233,    -1,   230,    -1,   224,    -1,   217,    -1,   216,    -1,
     218,    -1,   235,    -1,   225,    -1,   226,    -1,   232,    -1,
     222,    -1,   231,    -1,    66,    -1,    64,    -1,    75,    -1,
      41,    -1,    55,    -1,   168,    -1,   200,    -1,   241,    -1,
     236,    -1,   239,    -1,   240,    -1,   237,    -1,   238,    -1,
     243,    -1,   244,    -1,    45,    -1,   245,    -1,    65,    -1,
     294,    -1,   292,    -1,   293,    -1,   298,    -1,   299,    -1,
     300,    -1,   295,    -1,   296,    -1,   297,    -1,    79,    -1,
      80,    -1,    81,    -1,    82,    -1,    83,    -1,    84,    -1,
      85,    -1,    86,    -1,    87,    -1,    88,    -1,    89,    -1,
     286,    -1,   287,    -1,   288,    -1,   289,    -1,   290,    -1,
     291,    -1,   302,    -1,   303,    -1,   304,    -1,   305,    -1,
     306,    -1,   307,    -1,   308,    -1,    90,    -1,   104,    -1,
     113,    -1,   171,    -1,   179,    -1,   188,    -1,   137,    -1,
      91,    -1,   114,    -1,   138,    -1,   180,    -1,   611,   120,
     612,    -1,    24,    -1
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
     181,   183,   185,   187,   189,   191,   193,   195,   197,   201,
     207,   211,   215,   221,   227,   232,   236,   240,   244,   250,
     256,   262,   268,   274,   280,   285,   289,   293,   298,   304,
     311,   313,   317,   321,   325,   329,   336,   342,   351,   356,
     360,   362,   364,   366,   369,   372,   377,   383,   389,   396,
     400,   403,   408,   410,   413,   415,   417,   419,   421,   423,
     425,   428,   431,   434,   437,   439,   442,   445,   448,   452,
     457,   463,   470,   475,   481,   488,   496,   498,   501,   505,
     509,   518,   528,   530,   534,   536,   539,   542,   546,   558,
     573,   587,   610,   614,   618,   621,   625,   630,   636,   639,
     644,   648,   649,   653,   656,   659,   663,   668,   674,   680,
     684,   690,   693,   696,   698,   701,   703,   708,   710,   714,
     717,   721,   723,   726,   728,   730,   735,   740,   746,   752,
     760,   766,   768,   772,   775,   779,   783,   787,   789,   791,
     794,   796,   800,   802,   806,   808,   810,   812,   814,   816,
     818,   820,   822,   824,   826,   828,   830,   832,   834,   836,
     838,   840,   843,   846,   849,   852,   854,   856,   859,   864,
     868,   874,   879,   883,   885,   887,   889,   891,   893,   895,
     897,   899,   901,   904,   908,   910,   915,   919,   925,   930,
     937,   942,   949,   955,   963,   968,   974,   980,   987,   991,
     995,   998,  1000,  1004,  1009,  1015,  1019,  1026,  1031,  1037,
    1039,  1042,  1046,  1048,  1051,  1053,  1060,  1064,  1068,  1071,
    1075,  1077,  1081,  1084,  1088,  1091,  1095,  1100,  1102,  1106,
    1108,  1111,  1113,  1115,  1117,  1120,  1123,  1126,  1130,  1132,
    1134,  1137,  1140,  1143,  1149,  1155,  1157,  1162,  1166,  1171,
    1180,  1182,  1185,  1189,  1192,  1196,  1205,  1216,  1218,  1221,
    1226,  1234,  1243,  1245,  1249,  1251,  1255,  1257,  1261,  1265,
    1269,  1273,  1274,  1279,  1283,  1287,  1291,  1293,  1299,  1300,
    1302,  1304,  1308,  1310,  1314,  1318,  1320,  1324,  1328,  1332,
    1336,  1338,  1342,  1346,  1348,  1352,  1356,  1358,  1363,  1365,
    1370,  1372,  1377,  1379,  1384,  1386,  1389,  1391,  1393,  1396,
    1399,  1401,  1403,  1405,  1407,  1409,  1411,  1413,  1415,  1417,
    1419,  1421,  1423,  1428,  1434,  1440,  1447,  1451,  1456,  1458,
    1461,  1465,  1468,  1471,  1473,  1476,  1479,  1481,  1483,  1485,
    1489,  1493,  1495,  1497,  1499,  1502,  1504,  1507,  1510,  1512,
    1515,  1518,  1521,  1524,  1527,  1530,  1533,  1535,  1538,  1541,
    1543,  1546,  1549,  1552,  1555,  1558,  1560,  1562,  1564,  1566,
    1568,  1570,  1572,  1574,  1577,  1581,  1586,  1588,  1591,  1595,
    1597,  1599,  1601,  1603,  1605,  1607,  1609,  1611,  1613,  1615,
    1617,  1619,  1621,  1623,  1626,  1629,  1633,  1635,  1640,  1645,
    1649,  1654,  1656,  1660,  1662,  1664,  1666,  1668,  1670,  1675,
    1681,  1690,  1700,  1710,  1721,  1723,  1726,  1728,  1731,  1738,
    1739,  1741,  1745,  1749,  1750,  1752,  1754,  1756,  1759,  1762,
    1763,  1765,  1767,  1769,  1772,  1775,  1777,  1779,  1781,  1783,
    1785,  1787,  1789,  1791,  1793,  1795,  1797,  1799,  1803,  1806,
    1810,  1814,  1817,  1819,  1821,  1823,  1825,  1827,  1829,  1834,
    1837,  1841,  1848,  1856,  1859,  1863,  1870,  1878,  1883,  1888,
    1891,  1895,  1902,  1910,  1912,  1915,  1918,  1920,  1923,  1927,
    1929,  1931,  1933,  1935,  1937,  1941,  1943,  1945,  1947,  1951,
    1953,  1955,  1957,  1959,  1961,  1963,  1965,  1967,  1969,  1971,
    1975,  1979,  1984,  1989,  1993,  1997,  2001,  2006,  2011,  2015,
    2020,  2027,  2032,  2039,  2044,  2048,  2053,  2060,  2067,  2072,
    2079,  2086,  2091,  2093,  2096,  2098,  2100,  2102,  2106,  2110,
    2112,  2114,  2119,  2125,  2132,  2136,  2140,  2144,  2148,  2154,
    2162,  2170,  2176,  2182,  2188,  2196,  2204,  2210,  2216,  2220,
    2224,  2230,  2238,  2244,  2252,  2254,  2259,  2263,  2269,  2271,
    2274,  2278,  2286,  2297,  2311,  2313,  2317,  2320,  2321,  2323,
    2325,  2328,  2330,  2334,  2336,  2340,  2342,  2347,  2349,  2352,
    2356,  2357,  2359,  2360,  2362,  2367,  2370,  2374,  2376,  2377,
    2379,  2384,  2385,  2387,  2390,  2392,  2396,  2397,  2399,  2402,
    2405,  2407,  2408,  2410,  2411,  2413,  2415,  2417,  2419,  2421,
    2423,  2425,  2429,  2433,  2435,  2437,  2439,  2442,  2446,  2448,
    2450,  2452,  2454,  2456,  2458,  2460,  2462,  2465,  2468,  2470,
    2472,  2475,  2478,  2482,  2484,  2487,  2490,  2496,  2499,  2501,
    2503,  2504,  2507,  2509,  2513,  2518,  2519,  2522,  2523,  2526,
    2531,  2536,  2540,  2543,  2547,  2549,  2553,  2554,  2556,  2558,
    2561,  2564,  2567,  2570,  2572,  2575,  2578,  2581,  2584,  2588,
    2591,  2595,  2599,  2604,  2607,  2610,  2612,  2614,  2618,  2620,
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
    2982,  2984,  2986,  2988,  2990,  2992,  2994,  2996,  2998,  3000,
    3002,  3004,  3006,  3008,  3010,  3012,  3014,  3016,  3018,  3020,
    3022,  3024,  3026,  3028,  3030,  3032,  3034,  3036,  3038,  3040,
    3042,  3044,  3046,  3048,  3050,  3052,  3054,  3056,  3058,  3062
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,  1018,  1018,  1019,  1052,  1061,  1066,  1073,  1078,  1089,
    1093,  1101,  1106,  1111,  1116,  1121,  1128,  1135,  1142,  1153,
    1157,  1162,  1167,  1176,  1185,  1191,  1197,  1209,  1215,  1221,
    1232,  1233,  1234,  1235,  1236,  1241,  1242,  1243,  1244,  1245,
    1246,  1247,  1248,  1254,  1259,  1268,  1274,  1283,  1292,  1293,
    1294,  1295,  1296,  1297,  1298,  1299,  1300,  1301,  1306,  1307,
    1308,  1309,  1310,  1311,  1312,  1315,  1320,  1321,  1323,  1333,
    1341,  1347,  1357,  1363,  1373,  1383,  1391,  1397,  1408,  1413,
    1423,  1429,  1435,  1441,  1458,  1466,  1474,  1478,  1487,  1496,
    1509,  1515,  1526,  1530,  1538,  1543,  1548,  1555,  1568,  1575,
    1581,  1588,  1594,  1598,  1605,  1616,  1621,  1626,  1631,  1640,
    1646,  1652,  1661,  1667,  1676,  1680,  1686,  1690,  1694,  1698,
    1704,  1710,  1716,  1722,  1728,  1732,  1738,  1744,  1751,  1759,
    1767,  1775,  1783,  1795,  1809,  1823,  1840,  1844,  1853,  1857,
    1864,  1872,  1890,  1896,  1904,  1909,  1916,  1923,  1933,  1943,
    1953,  1963,  1980,  1986,  1997,  2001,  2005,  2009,  2016,  2023,
    2042,  2052,  2058,  2064,  2074,  2080,  2087,  2093,  2103,  2110,
    2117,  2129,  2133,  2141,  2145,  2153,  2157,  2164,  2168,  2176,
    2181,  2190,  2194,  2198,  2202,  2210,  2221,  2236,  2247,  2262,
    2273,  2289,  2295,  2307,  2311,  2322,  2329,  2337,  2352,  2356,
    2370,  2374,  2383,  2387,  2415,  2416,  2417,  2418,  2419,  2420,
    2423,  2424,  2425,  2426,  2427,  2429,  2432,  2433,  2434,  2435,
    2436,  2441,  2456,  2463,  2467,  2474,  2478,  2482,  2489,  2497,
    2508,  2518,  2531,  2540,  2541,  2542,  2546,  2547,  2548,  2549,
    2550,  2553,  2559,  2569,  2577,  2583,  2595,  2599,  2603,  2607,
    2611,  2615,  2619,  2624,  2630,  2639,  2649,  2659,  2675,  2684,
    2693,  2701,  2707,  2719,  2727,  2737,  2745,  2757,  2763,  2774,
    2776,  2780,  2788,  2792,  2797,  2801,  2805,  2809,  2819,  2827,
    2834,  2840,  2851,  2855,  2864,  2872,  2878,  2888,  2894,  2904,
    2908,  2918,  2924,  2930,  2936,  2945,  2954,  2963,  2976,  2980,
    2988,  2994,  3004,  3012,  3021,  3034,  3041,  3053,  3057,  3069,
    3076,  3082,  3091,  3098,  3104,  3116,  3123,  3136,  3142,  3154,
    3160,  3172,  3181,  3185,  3194,  3198,  3206,  3210,  3220,  3227,
    3236,  3246,  3245,  3259,  3268,  3277,  3290,  3294,  3307,  3310,
    3317,  3321,  3330,  3334,  3338,  3347,  3351,  3357,  3363,  3369,
    3380,  3384,  3388,  3396,  3400,  3406,  3416,  3420,  3430,  3434,
    3444,  3448,  3458,  3462,  3472,  3476,  3484,  3488,  3492,  3496,
    3506,  3510,  3514,  3522,  3526,  3530,  3534,  3538,  3542,  3550,
    3554,  3558,  3566,  3570,  3574,  3578,  3589,  3595,  3605,  3611,
    3621,  3625,  3629,  3668,  3672,  3682,  3692,  3706,  3716,  3726,
    3730,  3740,  3744,  3753,  3759,  3767,  3773,  3785,  3791,  3801,
    3805,  3809,  3813,  3817,  3823,  3829,  3852,  3856,  3864,  3868,
    3879,  3883,  3887,  3893,  3897,  3911,  3915,  3923,  3927,  3937,
    3941,  3945,  3954,  3958,  3962,  3966,  3974,  3980,  3990,  3998,
    4002,  4006,  4010,  4014,  4018,  4022,  4026,  4030,  4038,  4042,
    4050,  4057,  4064,  4075,  4083,  4087,  4095,  4103,  4111,  4165,
    4169,  4182,  4188,  4198,  4202,  4210,  4214,  4218,  4226,  4236,
    4246,  4256,  4266,  4276,  4291,  4297,  4308,  4314,  4325,  4336,
    4338,  4342,  4347,  4357,  4360,  4367,  4373,  4379,  4387,  4400,
    4403,  4410,  4416,  4422,  4429,  4440,  4444,  4454,  4458,  4468,
    4472,  4476,  4481,  4490,  4496,  4502,  4508,  4518,  4522,  4534,
    4538,  4550,  4562,  4566,  4570,  4574,  4578,  4582,  4590,  4598,
    4602,  4606,  4610,  4627,  4631,  4635,  4639,  4647,  4655,  4663,
    4667,  4671,  4675,  4683,  4689,  4699,  4707,  4711,  4715,  4750,
    4756,  4762,  4772,  4776,  4780,  4784,  4788,  4795,  4801,  4811,
    4819,  4823,  4827,  4831,  4835,  4839,  4843,  4847,  4851,  4859,
    4867,  4871,  4875,  4885,  4893,  4901,  4905,  4909,  4917,  4921,
    4927,  4933,  4937,  4947,  4955,  4959,  4965,  4974,  4983,  4989,
    4995,  5005,  5022,  5029,  5044,  5080,  5084,  5093,  5102,  5112,
    5116,  5125,  5134,  5138,  5149,  5166,  5172,  5178,  5188,  5192,
    5198,  5204,  5208,  5214,  5218,  5224,  5230,  5237,  5247,  5252,
    5260,  5266,  5276,  5298,  5307,  5313,  5326,  5340,  5347,  5353,
    5363,  5368,  5373,  5383,  5396,  5402,  5420,  5429,  5432,  5439,
    5444,  5452,  5456,  5463,  5467,  5474,  5478,  5485,  5489,  5498,
    5511,  5514,  5522,  5525,  5533,  5541,  5549,  5553,  5561,  5564,
    5572,  5584,  5587,  5595,  5607,  5613,  5623,  5626,  5634,  5638,
    5642,  5650,  5653,  5661,  5664,  5672,  5676,  5680,  5684,  5688,
    5696,  5704,  5716,  5728,  5732,  5736,  5744,  5750,  5760,  5764,
    5768,  5772,  5776,  5780,  5784,  5788,  5796,  5800,  5804,  5808,
    5816,  5822,  5832,  5842,  5846,  5854,  5864,  5875,  5882,  5886,
    5894,  5897,  5904,  5909,  5918,  5928,  5931,  5939,  5942,  5950,
    5959,  5966,  5976,  5980,  5987,  5993,  6003,  6006,  6013,  6018,
    6030,  6038,  6050,  6058,  6062,  6070,  6074,  6078,  6086,  6094,
    6098,  6102,  6106,  6114,  6122,  6134,  6138,  6146,  6159,  6163,
    6164,  6177,  6178,  6179,  6180,  6181,  6182,  6183,  6184,  6185,
    6186,  6187,  6188,  6189,  6190,  6191,  6192,  6196,  6197,  6198,
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
    6299,  6300,  6301,  6302,  6303,  6304,  6305,  6306,  6307,  6308,
    6309,  6310,  6311,  6312,  6313,  6314,  6315,  6316,  6317,  6318,
    6319,  6320,  6321,  6322,  6323,  6324,  6325,  6326,  6327,  6328,
    6329,  6330,  6331,  6332,  6333,  6334,  6335,  6336,  6337,  6338,
    6339,  6340,  6341,  6342,  6343,  6344,  6345,  6346,  6347,  6348,
    6349,  6350,  6351,  6352,  6353,  6354,  6355,  6356,  6357,  6358,
    6359,  6360,  6361,  6362,  6363,  6364,  6365,  6366,  6367,  6368,
    6369,  6370,  6371,  6372,  6373,  6374,  6375,  6376,  6377,  6378,
    6379,  6380,  6381,  6382,  6383,  6384,  6385,  6386,  6387,  6388,
    6389,  6390,  6391,  6392,  6393,  6394,  6395,  6396,  6401,  6407
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
     315,   316,   317,   318,   319,   320,   321,   322
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 12352;
  const int xquery_parser::yynnts_ = 293;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 561;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 323;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 577;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba

/* Line 1054 of lalr1.cc  */
#line 15816 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6411 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"


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
    driver.set_expr(new ParseErrorNode(driver.parserError->loc, driver.parserError->err_code, driver.parserError->msg));
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
/* vim:set et sw=4 ts=4: */

