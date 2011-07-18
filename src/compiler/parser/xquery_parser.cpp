
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
#line 71 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"


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
#line 79 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 863 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 317 of lalr1.cc  */
#line 963 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"

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
#line 152 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"

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
#line 221 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
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
#line 861 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 328 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 122: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 860 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 337 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 147: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 859 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 346 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 355 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 364 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 373 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 382 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 391 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 400 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 409 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 418 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 427 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 436 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 445 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 454 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 463 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 472 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 481 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 490 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 499 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 508 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 517 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 526 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 535 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 544 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 553 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 562 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 884 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 571 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 884 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 580 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 589 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 598 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 607 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 616 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 625 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 634 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 643 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 884 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 652 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 661 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 670 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 679 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 688 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 697 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 706 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 715 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 884 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 724 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 733 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 742 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "DeclPropertyList" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 751 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "DeclProperty" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 760 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 769 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "NodeModifier" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 778 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 787 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 796 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 805 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 814 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 823 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 832 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 841 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 850 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 859 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 868 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 877 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 886 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 895 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 904 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 913 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 922 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 949 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 958 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 967 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 976 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 985 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 994 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1003 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1012 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1021 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1030 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1039 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1048 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1057 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1066 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1075 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1084 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1093 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1102 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1111 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1120 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1129 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1138 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1147 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1156 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1165 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1174 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1183 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1192 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1201 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1210 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1219 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1228 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1237 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1246 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1255 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1264 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1273 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1282 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1291 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1300 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1309 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1318 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1327 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1336 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1345 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1354 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1363 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1372 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1381 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1390 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1399 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1408 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1417 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1426 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1435 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1444 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1453 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1462 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1471 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1480 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1489 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1498 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1507 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1516 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1525 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1534 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1543 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1552 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1561 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1570 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1579 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1588 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1597 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1606 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1615 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1624 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1633 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1642 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1651 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1660 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1669 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1678 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1687 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1696 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1705 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1714 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1723 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1732 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1741 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1750 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1759 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1768 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1777 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1786 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1795 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1804 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1813 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1822 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1831 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1840 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1849 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1858 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1867 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1876 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1885 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1894 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1903 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1912 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1921 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1930 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1939 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1948 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1957 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1966 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1975 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1984 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1993 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2002 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2011 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2020 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2029 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2038 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2047 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2056 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2065 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2074 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2083 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2092 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2101 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2110 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2119 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2128 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2137 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2146 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2155 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2164 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2173 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2182 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2191 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2200 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2209 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2218 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2227 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2236 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2245 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2254 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2263 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2272 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2281 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2290 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2299 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2308 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2317 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2326 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2335 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2344 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2353 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2362 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2371 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2380 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 884 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2389 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2398 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2407 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2416 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2425 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2434 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2443 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2452 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2461 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2470 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2479 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2488 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2497 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2506 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2515 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2524 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2533 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2542 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2551 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2560 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2569 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2578 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2587 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2596 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2605 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2614 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2623 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2632 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 612: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2641 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 613: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2650 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 617: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2659 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 618: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2668 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 619: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2677 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2686 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 621: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2695 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 622: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2704 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 623: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2713 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 624: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2722 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 625: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 878 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2731 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 628: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2740 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 629: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2749 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 630: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 881 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2758 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
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
#line 124 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 553 of lalr1.cc  */
#line 2843 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"

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
#line 1024 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 1033 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 1042 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 1048 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 1056 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 1062 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 1073 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 1078 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 1086 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1093 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1100 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 1109 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1116 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1124 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1132 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1140 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1151 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1156 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1163 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 1170 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 1182 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 1192 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 1199 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 1206 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 1241 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1246 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1254 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1262 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1270 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1275 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1283 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1288 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1296 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1301 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1309 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1316 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1323 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 1330 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 1345 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 1355 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 1360 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 1368 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1376 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1387 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1394 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1405 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1410 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1418 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1425 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1432 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1441 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 1454 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1462 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1469 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1479 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1486 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1493 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1516 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1522 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1531 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1538 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1548 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1557 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1558 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1559 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1560 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1561 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1562 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1563 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1564 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1565 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1566 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1572 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1580 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1588 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1596 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1603 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1611 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1618 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1623 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1631 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1639 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 1654 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 1669 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 1687 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1692 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1700 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1708 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1719 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1724 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1733 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1738 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1745 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1750 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1760 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1765 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1774 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1780 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1793 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1798 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1806 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 1817 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 1832 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 1844 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 1859 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1864 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1869 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1874 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1882 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1889 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1900 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1905 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1915 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      DeclPropertyList *dpl = new DeclPropertyList( LOC((yyloc)) );
      dpl->addProperty(dynamic_cast<DeclProperty*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = dpl;
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1921 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      DeclPropertyList *dpl = dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(2) - (1)].node));
      dpl->addProperty( static_cast<DeclProperty*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1931 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_const );
        }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1935 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_append_only
            );
        }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1941 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_queue );
        }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1945 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_mutable );
        }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1949 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_ordered );
        }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1953 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_unordered
            );
        }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1959 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_equality
            );
        }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1965 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_range
            );
        }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1971 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_equality
            );
        }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1977 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_range
            );
        }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1983 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_unique );
        }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1987 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_non_unique
            );
        }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1993 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_automatic
            );
        }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1999 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_manual );
        }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 2006 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2014 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2022 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2030 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2038 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2050 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2064 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2078 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2095 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 2099 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2108 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 2112 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 2119 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2127 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2145 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 2151 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 2160 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 2165 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 2172 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 2179 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 2191 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2201 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2211 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2222 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2238 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2258 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2263 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2267 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 2275 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 2280 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 2284 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 2292 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 2297 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 2309 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 2316 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 2345 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 2350 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 2358 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2375 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 2383 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 2391 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 2398 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 2405 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 2412 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 2419 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)));
      vdecl->add((yysemantic_stack_[(4) - (4)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 2429 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2441 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2454 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2466 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2482 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 2490 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 2498 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 2506 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2521 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 2526 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 2534 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2548 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2565 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2590 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 2598 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 2605 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 2616 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 2622 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 2628 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2639 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2654 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 2659 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2697 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2711 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 2719 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2724 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2732 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 2737 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 2742 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2750 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2759 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2771 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2781 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2794 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2818 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2825 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2835 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2843 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2850 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2860 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2870 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2880 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2890 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2900 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2910 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2920 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2930 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2941 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2950 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2960 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2970 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 2986 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2995 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 3004 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 3012 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 3018 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 3030 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 3038 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 3048 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 3056 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 3068 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 3074 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 3087 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 3091 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 3099 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 3103 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 3112 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 3116 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3120 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3130 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3138 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3145 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3151 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3162 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3166 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3175 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3183 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3189 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3199 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3205 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3215 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3219 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3229 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3235 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3241 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3247 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 3256 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 3265 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 3274 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 3287 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3291 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3299 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3305 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3315 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3323 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 3332 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 3345 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3352 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3364 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3368 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3380 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3387 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3393 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3402 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3409 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3415 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3426 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3433 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3439 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3448 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3457 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3464 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 3475 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3482 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 3494 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3500 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3512 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3518 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3529 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3535 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3546 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3552 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3563 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3572 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3576 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3585 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3589 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3597 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3601 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 3611 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3618 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 3627 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 3636 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3641 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 3650 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 3659 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 3668 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 3681 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3685 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 3697 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3701 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3708 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3712 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3721 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3725 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3729 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3738 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3742 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3748 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3754 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3760 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3771 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3775 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3779 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3787 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3791 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3797 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3807 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3811 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3821 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3825 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3835 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3839 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3849 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3853 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3863 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3867 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3875 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3879 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3883 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3887 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3897 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3901 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3905 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3913 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3917 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3921 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3925 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3929 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3933 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3941 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3945 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3949 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3957 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3961 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3965 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3969 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3980 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3986 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3996 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 4002 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 4012 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 4016 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 4020 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 4058 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 4062 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 4072 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 4082 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 4095 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 4104 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 4114 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 4118 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 4127 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 4131 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4140 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4146 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 4154 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4160 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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
#line 4172 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4178 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4188 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4192 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4196 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4200 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4204 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4210 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4216 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4224 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4228 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4236 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4240 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4251 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4255 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4259 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4265 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4269 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4283 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4287 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4295 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4299 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4309 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4313 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4317 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4321 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4330 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4334 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4338 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4342 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4350 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4356 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4366 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4374 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4378 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4382 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4386 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4390 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4394 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4398 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4402 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4406 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4416 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4424 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4428 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4436 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4443 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4450 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4461 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4469 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4473 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4481 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4489 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4497 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4551 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4555 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4568 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4574 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4584 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4588 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4596 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4600 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4604 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4612 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 506:

/* Line 678 of lalr1.cc  */
#line 4622 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 507:

/* Line 678 of lalr1.cc  */
#line 4632 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 508:

/* Line 678 of lalr1.cc  */
#line 4642 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 509:

/* Line 678 of lalr1.cc  */
#line 4652 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 510:

/* Line 678 of lalr1.cc  */
#line 4662 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 511:

/* Line 678 of lalr1.cc  */
#line 4677 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4683 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4694 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4700 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4711 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4728 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4733 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4742 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4746 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4753 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4759 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4765 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4773 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4785 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4789 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4796 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4802 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4808 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4815 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4826 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4830 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4840 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4844 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4854 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4858 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4862 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4867 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4876 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4882 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4888 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4894 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
        }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4902 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4907 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4915 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4920 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4928 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4936 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4941 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 4946 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 4951 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 4956 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 4961 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 4970 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 4978 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 4982 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 4999 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 5003 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 5011 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 5019 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 5027 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 5031 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 5039 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 5045 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 5055 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 5063 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 5067 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 5071 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 5106 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 5112 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5118 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 5128 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 5132 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5136 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5140 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5144 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5151 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5157 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5167 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5175 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5179 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5183 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5187 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5191 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5195 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5199 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5203 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5207 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5215 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5223 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5227 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5231 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5241 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5249 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5257 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5261 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5265 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5273 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5277 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5283 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5289 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5293 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5303 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5311 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5315 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5321 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5330 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5339 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5345 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5351 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5361 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5378 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5385 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5400 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5436 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5440 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5448 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5456 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5468 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5472 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5480 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5488 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5492 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5503 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5520 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5526 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5532 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5542 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5546 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5552 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5558 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5562 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5568 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5572 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5578 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5584 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5591 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5601 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5606 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5614 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5620 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5630 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5652 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5661 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5667 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5680 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5694 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5701 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5707 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5717 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5722 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5727 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 654:

/* Line 678 of lalr1.cc  */
#line 5737 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 655:

/* Line 678 of lalr1.cc  */
#line 5751 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5759 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5765 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5783 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5791 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5795 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5802 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5807 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5815 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5819 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5826 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5830 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5837 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5841 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5848 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5852 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5861 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5873 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5877 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5884 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5888 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5896 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5904 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5912 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5916 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5923 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5927 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5935 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5946 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5950 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5958 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5970 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5976 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5985 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5989 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5997 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 6001 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 6005 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 6012 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 6016 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 6023 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 6027 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 6035 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 6039 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 6043 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 6047 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 6051 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 6059 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 6067 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 6079 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 6091 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 6095 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 6099 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 6107 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 6113 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 6123 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 6127 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 6131 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 6135 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 6139 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 6143 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 6147 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 6151 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 6159 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 6163 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 6167 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 6171 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 6179 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 6185 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 6195 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 6205 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 6209 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 6217 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 728:

/* Line 678 of lalr1.cc  */
#line 6227 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 729:

/* Line 678 of lalr1.cc  */
#line 6238 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 6245 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 6249 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 6256 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 6260 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 6267 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 6272 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 6281 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 6290 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 6294 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 6301 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 6305 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 6313 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 6322 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 6329 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 6339 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 6343 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 6350 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 6356 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 6365 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 6369 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 6376 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 6381 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 6393 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 6401 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 6413 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 6421 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 6425 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 6433 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 6437 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 6441 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 6449 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 6457 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 6461 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 6465 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 6469 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 6477 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 6485 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 6497 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 6501 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 6509 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 6527 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
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

  case 774:

/* Line 678 of lalr1.cc  */
#line 6540 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 6541 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 6542 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 6543 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 6544 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 6545 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 6546 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 6547 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 6548 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 6549 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 6550 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 6551 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 6552 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 6553 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 6554 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 6559 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 6560 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 6561 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 6562 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 6563 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 6564 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 6565 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 6566 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 6567 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 6568 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 6569 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 6570 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 6571 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 6572 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 6573 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 6574 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 6575 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 6576 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 6577 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 6578 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 6579 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 6580 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 6581 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 6582 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 6583 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 6584 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 6585 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 6586 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 6587 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 6588 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 6589 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 6590 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 6591 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 6592 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 6593 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 6594 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 6595 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 6596 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 6597 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 6598 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 6599 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 6600 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 6601 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 6602 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 6603 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 6604 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 6605 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 6606 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 6607 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 6608 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 6609 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 6610 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 6611 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 6612 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 6613 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 6614 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 6615 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 6616 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 6617 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 6618 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 6619 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 6620 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 6621 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 6622 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 6623 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 6624 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 6625 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 6626 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 6627 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 6628 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 6629 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 6630 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 6631 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 6632 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 6633 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 6634 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 6635 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 6636 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 6637 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 6638 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 6639 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 6640 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 6641 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 6642 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 6643 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 6644 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 6645 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 6646 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 6647 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 6648 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 6649 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 6650 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 6651 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 6652 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 6653 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 6654 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 6655 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 6656 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 6657 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 6658 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 6659 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 6660 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 6661 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 6662 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 6663 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6664 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 896:

/* Line 678 of lalr1.cc  */
#line 6665 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 897:

/* Line 678 of lalr1.cc  */
#line 6666 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 898:

/* Line 678 of lalr1.cc  */
#line 6667 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 899:

/* Line 678 of lalr1.cc  */
#line 6668 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 900:

/* Line 678 of lalr1.cc  */
#line 6669 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 901:

/* Line 678 of lalr1.cc  */
#line 6670 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 902:

/* Line 678 of lalr1.cc  */
#line 6671 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 903:

/* Line 678 of lalr1.cc  */
#line 6672 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 904:

/* Line 678 of lalr1.cc  */
#line 6673 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 905:

/* Line 678 of lalr1.cc  */
#line 6674 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 906:

/* Line 678 of lalr1.cc  */
#line 6675 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 907:

/* Line 678 of lalr1.cc  */
#line 6676 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 908:

/* Line 678 of lalr1.cc  */
#line 6677 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 909:

/* Line 678 of lalr1.cc  */
#line 6678 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 910:

/* Line 678 of lalr1.cc  */
#line 6679 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 911:

/* Line 678 of lalr1.cc  */
#line 6680 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 912:

/* Line 678 of lalr1.cc  */
#line 6681 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 913:

/* Line 678 of lalr1.cc  */
#line 6682 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 914:

/* Line 678 of lalr1.cc  */
#line 6683 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 915:

/* Line 678 of lalr1.cc  */
#line 6684 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 916:

/* Line 678 of lalr1.cc  */
#line 6685 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 917:

/* Line 678 of lalr1.cc  */
#line 6686 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 918:

/* Line 678 of lalr1.cc  */
#line 6687 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 919:

/* Line 678 of lalr1.cc  */
#line 6688 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 920:

/* Line 678 of lalr1.cc  */
#line 6689 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 921:

/* Line 678 of lalr1.cc  */
#line 6690 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 922:

/* Line 678 of lalr1.cc  */
#line 6691 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 923:

/* Line 678 of lalr1.cc  */
#line 6692 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 924:

/* Line 678 of lalr1.cc  */
#line 6693 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 925:

/* Line 678 of lalr1.cc  */
#line 6694 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 926:

/* Line 678 of lalr1.cc  */
#line 6695 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 927:

/* Line 678 of lalr1.cc  */
#line 6696 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 928:

/* Line 678 of lalr1.cc  */
#line 6697 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 929:

/* Line 678 of lalr1.cc  */
#line 6698 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 930:

/* Line 678 of lalr1.cc  */
#line 6699 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 931:

/* Line 678 of lalr1.cc  */
#line 6700 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 932:

/* Line 678 of lalr1.cc  */
#line 6701 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 933:

/* Line 678 of lalr1.cc  */
#line 6702 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 934:

/* Line 678 of lalr1.cc  */
#line 6703 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 935:

/* Line 678 of lalr1.cc  */
#line 6704 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("local"))); }
    break;

  case 936:

/* Line 678 of lalr1.cc  */
#line 6705 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 937:

/* Line 678 of lalr1.cc  */
#line 6706 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 938:

/* Line 678 of lalr1.cc  */
#line 6707 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 939:

/* Line 678 of lalr1.cc  */
#line 6708 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 940:

/* Line 678 of lalr1.cc  */
#line 6709 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 941:

/* Line 678 of lalr1.cc  */
#line 6710 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 942:

/* Line 678 of lalr1.cc  */
#line 6711 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 943:

/* Line 678 of lalr1.cc  */
#line 6712 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 944:

/* Line 678 of lalr1.cc  */
#line 6713 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 945:

/* Line 678 of lalr1.cc  */
#line 6714 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 946:

/* Line 678 of lalr1.cc  */
#line 6715 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 947:

/* Line 678 of lalr1.cc  */
#line 6716 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 948:

/* Line 678 of lalr1.cc  */
#line 6717 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 949:

/* Line 678 of lalr1.cc  */
#line 6718 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 950:

/* Line 678 of lalr1.cc  */
#line 6719 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 951:

/* Line 678 of lalr1.cc  */
#line 6720 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 952:

/* Line 678 of lalr1.cc  */
#line 6721 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 953:

/* Line 678 of lalr1.cc  */
#line 6722 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 954:

/* Line 678 of lalr1.cc  */
#line 6723 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 955:

/* Line 678 of lalr1.cc  */
#line 6724 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 956:

/* Line 678 of lalr1.cc  */
#line 6725 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 957:

/* Line 678 of lalr1.cc  */
#line 6726 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 958:

/* Line 678 of lalr1.cc  */
#line 6727 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 959:

/* Line 678 of lalr1.cc  */
#line 6728 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 960:

/* Line 678 of lalr1.cc  */
#line 6729 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 961:

/* Line 678 of lalr1.cc  */
#line 6730 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 962:

/* Line 678 of lalr1.cc  */
#line 6731 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 963:

/* Line 678 of lalr1.cc  */
#line 6732 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 964:

/* Line 678 of lalr1.cc  */
#line 6733 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 965:

/* Line 678 of lalr1.cc  */
#line 6734 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 966:

/* Line 678 of lalr1.cc  */
#line 6735 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 967:

/* Line 678 of lalr1.cc  */
#line 6736 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 968:

/* Line 678 of lalr1.cc  */
#line 6737 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 969:

/* Line 678 of lalr1.cc  */
#line 6738 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 970:

/* Line 678 of lalr1.cc  */
#line 6739 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 971:

/* Line 678 of lalr1.cc  */
#line 6740 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 972:

/* Line 678 of lalr1.cc  */
#line 6741 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 973:

/* Line 678 of lalr1.cc  */
#line 6742 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 974:

/* Line 678 of lalr1.cc  */
#line 6743 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 975:

/* Line 678 of lalr1.cc  */
#line 6744 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 976:

/* Line 678 of lalr1.cc  */
#line 6745 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 977:

/* Line 678 of lalr1.cc  */
#line 6746 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 978:

/* Line 678 of lalr1.cc  */
#line 6747 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 979:

/* Line 678 of lalr1.cc  */
#line 6748 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 980:

/* Line 678 of lalr1.cc  */
#line 6749 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 981:

/* Line 678 of lalr1.cc  */
#line 6750 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 982:

/* Line 678 of lalr1.cc  */
#line 6751 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 983:

/* Line 678 of lalr1.cc  */
#line 6752 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 984:

/* Line 678 of lalr1.cc  */
#line 6753 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 985:

/* Line 678 of lalr1.cc  */
#line 6754 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 986:

/* Line 678 of lalr1.cc  */
#line 6755 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 987:

/* Line 678 of lalr1.cc  */
#line 6756 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 988:

/* Line 678 of lalr1.cc  */
#line 6762 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    {
          // EQName's namespace URI value is whitespace normalized according to the rules for the xs:anyURI type
          std::string uri = "\"" + SYMTAB((yysemantic_stack_[(3) - (1)].sval)) + "\"";
          std::string eqname = SYMTAB(driver.symtab.put_uri(uri.c_str(), uri.size())) + ":" + SYMTAB((yysemantic_stack_[(3) - (3)].sval));
          (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT(eqname.c_str())), true);
        }
    break;

  case 989:

/* Line 678 of lalr1.cc  */
#line 6768 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 678 of lalr1.cc  */
#line 11951 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1441;
  const short int
  xquery_parser::yypact_[] =
  {
      3219, -1441, -1441, -1441,  4705,  4705,  4705, -1441, -1441,    66,
     254,    45,  1564,   340, -1441, -1441, -1441,   277, -1441, -1441,
   -1441,   366,   367,   744,    75,   390,   436,   138, -1441,     6,
   -1441, -1441, -1441, -1441, -1441, -1441,   763, -1441,   536,   561,
   -1441, -1441, -1441, -1441,   500, -1441,   768, -1441,   571,   619,
   -1441,   182, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441,
   -1441, -1441, -1441, -1441, -1441,   718,   725, -1441, -1441, -1441,
   -1441,   270,  9160, -1441, -1441, -1441,   740, -1441, -1441, -1441,
     653, -1441,   760,   785, -1441, -1441, 12887, -1441, -1441, -1441,
   -1441, -1441, -1441, -1441, -1441,   684, -1441, -1441,   800,   810,
   -1441, -1441, -1441, -1441, -1441, -1441, -1441,  3517,  6487, 12887,
   -1441, -1441, -1441, -1441, -1441, -1441, -1441,   737, -1441, -1441,
     824, 10041, -1441, 10331,   827,   829, -1441, -1441, -1441,   837,
   -1441,  8863, -1441, -1441, -1441, -1441, -1441, -1441,   807, -1441,
   -1441, -1441, -1441, -1441, -1441, -1441, -1441,    78,   746, -1441,
   -1441, -1441, -1441, -1441, -1441, -1441, -1441,   654,   806,   691,
   -1441,   742,   585, -1441, -1441, -1441, -1441, -1441, -1441,   860,
   -1441,   305,   738,   739,   741, -1441, -1441,   825,   831, -1441,
   -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441,
   -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441,
   -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441,
   -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441,
   -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441,
   -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441,
   -1441, -1441,  5002,   983, -1441,  5299, -1441, -1441,   269,    84,
   -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441,
   -1441, -1441, -1441, -1441,    86, -1441, -1441, -1441, -1441, -1441,
   -1441,   312, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441,
    4705, -1441, -1441, -1441, -1441,   237, -1441, -1441, -1441, -1441,
   -1441, -1441, -1441, -1441,   879, -1441,   797, -1441, -1441, -1441,
     302, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441,   821,
     896, -1441,   594,   743,   518,   526,   236,   611, -1441,   939,
     794,   893,   894,  7675, -1441, -1441, -1441,    -6, -1441, -1441,
    8863, -1441,   441, -1441,   843,  9160, -1441,   843,  9160, -1441,
   -1441, -1441,   769, -1441, -1441, -1441, -1441, -1441, -1441, -1441,
   -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441,
   -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441,
   -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441,
   -1441, -1441, -1441, -1441, -1441,   877,   854,   844, -1441, -1441,
   -1441, -1441, -1441,   832, -1441,  4705,   833,   835,   294,   294,
     989,   507,   641,   501, 13171, 12887,   290,   972, 12887,   870,
     905,   319, 10041, -1441, -1441,   649,   633,   778, 12887, -1441,
   -1441, -1441, -1441, -1441,   734, 12887,   727,   730,   635,   726,
     735,   127, -1441, -1441, -1441,   680, -1441, 10041,  4705,   842,
    4705,    93,  7972, 10899,   747,   749, 12887,   914,     7,   882,
    7972,  1033,   102,   105, 12887,   919,   898,   931, -1441,  7972,
    9749, 12887, 12887, 12887,  4705,   855,  7972,  7972, 12887,  4705,
     888,   890, -1441, -1441, -1441,  7972, 11183, -1441,   889, -1441,
     891, -1441, -1441, -1441, -1441,   892, -1441,   895, -1441, -1441,
   -1441, -1441, -1441,   899, -1441, -1441, -1441, -1441, -1441, -1441,
   -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441,
   -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441,
   -1441, -1441, 12887, -1441, -1441, -1441, -1441, -1441, -1441, -1441,
   -1441, -1441, -1441, -1441, -1441,   902, 12887, -1441, -1441, -1441,
     862,  3814,   900,   901,   904, 12887,  4705, -1441,   897,    22,
   -1441,   341,  1012,  7972, -1441, -1441,    83, -1441, -1441, -1441,
    1035, -1441, -1441, -1441, -1441,  7972,   839, -1441,  1027,  7972,
    7972,   874,  7972,  7972,  7972,  7972,   834, 12887,   653,   329,
     872,   873,  7972,  7972,  3517,   820, -1441, -1441, -1441, -1441,
    1564,   138,    88,    95,  1061,  5596,  5596,  5893,  5893,   653,
   -1441, -1441,   879,   653, -1441,  7972, -1441,   950,    75,     6,
     903,   906,   907,  4705,  7972, -1441, -1441, -1441, -1441, -1441,
   -1441, -1441, -1441,  8269,  8269,  8269, -1441,  8269,  8269, -1441,
    8269, -1441,  8269, -1441, -1441, -1441, -1441, -1441, -1441, -1441,
    8269,  8269,   997,  8269,  8269,  8269,  8269,  8269,  8269,  8269,
    8269,  8269,  8269,  8269,   840,   977,   984,   990, -1441, -1441,
   -1441,  6784, -1441, -1441,  8863,  8863,  7972,   843, -1441, -1441,
     843, -1441,  7081,   843, 10041,   929,  7378, -1441, -1441, -1441,
   -1441,    27, -1441,   224, -1441, -1441, -1441, -1441, -1441,   980,
     981,   390,  1053, -1441, -1441, 13171,   924,   516, 12887,   930,
     932,   924,   989,   966,   962, -1441, -1441, -1441, -1441, -1441,
      49,   850,   -13, -1441,   798, -1441, -1441, -1441, -1441, 12887,
     957,  7972,   982, -1441, 12887, 12887, -1441,   970,   920,  4705,
   -1441,   921,   891,   561, -1441,   916,   922,   217, -1441,   257,
     262, -1441, -1441,   999, -1441,    26, 12887,    10, 12887,  1015,
     306, -1441,  4705, -1441,   324, -1441, 10041,  1014,  1065, 10041,
     989,  1016,   489, 12887,  7972,     6,   273,   927, -1441,   928,
     933,   934,     1, -1441,   175,   935, -1441,   327,   328,   963,
   -1441,   938,  4705,  4705,   284, -1441,   330,   346,   540,  7972,
      25, -1441, -1441,  7972,  7972,  7972, -1441,  7972, -1441,  7972,
   12887,  1012, -1441,   191,   378, -1441, -1441, -1441,   391, -1441,
     352, -1441, -1441, -1441,   189,   197,  1022,   887,   908,    12,
   -1441,   976, -1441,   653, -1441, -1441,   936,   371,  4111,   409,
    9457,   820, -1441,   269,   687,  1090,  1090, -1441, -1441,    96,
   -1441, -1441,    98, -1441,  1609, -1441, -1441, -1441, -1441, -1441,
   -1441, -1441, 12887,   958,  7972,  1009, -1441, -1441, -1441,   896,
   -1441, -1441, -1441, -1441, -1441,  8269, -1441, -1441, -1441,    59,
     526,   526,   632,   236,   236,   236,   236,   611,   611, -1441,
   -1441, 12319, 12319, 12887, 12887, -1441,   454, -1441, -1441,   -15,
   -1441, -1441, -1441,   382, -1441, -1441, -1441,   392,   294, -1441,
   -1441,    19,   509,   666, -1441,   390, -1441, -1441, -1441, -1441,
   -1441, -1441, -1441, -1441, -1441, -1441,   924, -1441,   998, 12603,
     987,  7972, -1441, -1441, -1441,  1036,   989,   989,   924, -1441,
     688,   989,   615, 12887,   424,   462,  1102, -1441, -1441,   848,
     364, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441,
   -1441, -1441,    49,    81,   647, -1441,   909,   513,  7972, -1441,
   12887,    17,   841,   989, -1441, -1441, -1441, -1441,   985, 12887,
   -1441, 12887, -1441,  1018,  1017, 12319,  1021,  7972,   -41,   995,
      16,   397,   910, -1441, -1441,   668,    10,  1036, 12319,  1028,
    1050,   964,   953,  1020,   989,   993,  1023,  1057,   989,  7972,
     -54, -1441, -1441, -1441,   994, -1441, -1441, -1441, -1441,  1038,
    7972,  7972,  1010, -1441,  1058,  1060,  4705, -1441,   978,   979,
    1008, 12887, -1441, 12887, -1441,  7972,  1024,   975,  7972,   400,
     414,   423,  1130, -1441,   279, -1441,   226, -1441, -1441,  1137,
   -1441,   697,  7972,  7972,  7972,   698,  7972,  7972,  7972,  7972,
    7972,  7972,  1051,  7972,  7972, -1441, -1441,  6190,  1019,  1025,
    1026,  1030,   797,   716,   925, -1441,   554, -1441,   111,    41,
    1609,  5893,  5893,  5893,  1091, -1441,  7972,   652,  1066, -1441,
   12887,  1069, -1441, -1441,  7972,    59,    71,     9, -1441,   911,
      90,   937,   912, -1441, -1441,   778, -1441,   913,   -88,  1029,
    1034, 12603,  1037, -1441,   613, -1441, -1441, -1441, -1441, -1441,
   -1441, -1441, -1441, -1441,  1045, -1441, -1441, -1441,  7972, -1441,
   -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441,   667, -1441,
    1146,   759, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441,
   -1441,   915, -1441, -1441,  1147, -1441, -1441, -1441, -1441, -1441,
     517,  1160, -1441,   713, -1441, -1441, -1441,   889,   367,   892,
     536,   895,   899,   806,   956,   613,   968,   986,  8566,   917,
     918, -1441,  1036,    81, -1441,   991,  1013,  4705,  1031,  1032,
    1062,  1039,  1040, 12887,    38, -1441, 12887, -1441,  7972,  1055,
    7972,  1078,  7972,   -31,  1064,  7972,  1068, -1441,  1089,  1092,
    7972, 12887,   723,  1131, -1441, -1441, -1441, -1441, -1441, -1441,
   12319, -1441,  4705,   989,  1101, -1441, -1441, -1441,   989,  1101,
   -1441,  7972,  1071,  4705, 12887, -1441, -1441,  7972,  7972,   724,
   -1441,    30,   728, -1441, 11467,   733, -1441,   748, -1441,  1044,
   -1441, -1441,  4705,  1042,  1047, -1441,  7972, -1441, -1441,  1041,
    1058,  1116, -1441,  1088, -1441,   538, -1441, -1441,  1214, -1441,
   -1441,  4705, 12887, -1441,   617, -1441, -1441, -1441,  1046,  1003,
    1005, -1441, -1441, -1441,  1007,  1011, -1441, -1441, -1441, -1441,
   -1441,  1004, 12887,  1056, -1441, -1441,  7972,  7972,  7972,  4408,
    6190,  9457,   925, -1441,  1113,  9457, -1441,  1090,   316, -1441,
   -1441, -1441,  1066, -1441,   989, -1441,   812, -1441,   603,  1135,
   -1441,  7972,  1139,  1009,   495,  1059, -1441,    59,  1000, -1441,
   -1441,   -64, -1441,  -110,    53,  1001,    59,  -110,  8269, -1441,
      64, -1441, -1441, -1441, -1441, -1441, -1441,    59,  1106,   973,
     850,    53, -1441, -1441,   971,  1169, -1441, -1441, -1441, 10615,
    1067,  1072,  1073, -1441, -1441, -1441, -1441, -1441, -1441, -1441,
   -1441, -1441, -1441, -1441, -1441,  1225,   280,  1227,   280,   996,
    1154, -1441, -1441, -1441, -1441,  1094, 12887,  1048, -1441,   956,
    8566, -1441,  1081, -1441, -1441, -1441, -1441, -1441, -1441,  7972,
    1115, -1441, -1441,  7972, -1441,   528, -1441,  7972,  1119,  7972,
   -1441,  7972, 12887, 12887, -1441,    91, -1441,  7972, -1441,  1144,
    1148,  1175,   989,  1101, -1441,  7972,  1093, -1441, -1441, -1441,
    1087, -1441,   198,  7972,  4705,  1096,   212, -1441, 12887,  1098,
   11751,    13, -1441, 12035,  1099, -1441, -1441,  1095, -1441, -1441,
   -1441,  7972,   750,  1130, 12887,   732, -1441,  1103,  1130, 12887,
   -1441, -1441,  7972,  7972,  7972,  7972,  7972, -1441,  7972,   433,
     440,   452,   568, -1441, 12887, -1441, -1441, -1441, -1441,  1135,
   -1441, -1441, -1441,   989, -1441, -1441, -1441, -1441, -1441,  1104,
    8269, -1441, -1441, -1441, -1441, -1441,   322,  8269,  8269,   519,
   -1441,   937, -1441,   196, -1441,   912,    59,  1122, -1441, -1441,
    1006, -1441, -1441, -1441, -1441,  1181,  1107, -1441,   460, -1441,
   -1441, -1441, -1441,    40,    40, -1441,   280, -1441, -1441,   461,
   -1441,  1247,    53,  1192,  1108,  8566,   -46,  1049, -1441,  1126,
   -1441, -1441,  7972, -1441,  7972,  1150, -1441,  7972, -1441, -1441,
   -1441,  1243, -1441, -1441,  6190,  7972,   989, -1441, -1441, -1441,
    7972,  7972, -1441, -1441, -1441,  6190,  6190,  1206,  4705, 12887,
    1118, 12887,  7972, 12887,  1121,  6190, -1441,   242,    24,  1130,
   12887, -1441,  1112,  1130, -1441, -1441, -1441, -1441, -1441, -1441,
    1105,  1058,  1060,  7972,  1191, -1441,   463, -1441, -1441, -1441,
     236,  8269,  8269,   632,   535, -1441, -1441, -1441, -1441, -1441,
   -1441,  7972, -1441, 12319, -1441, 12319,  1215, -1441, -1441, -1441,
    1280, -1441, -1441, -1441,  1052,  1208, -1441, -1441,  1209, -1441,
     736, 12887,  1195,  1100, 12887,  8566, -1441, -1441,  7972, -1441,
    1200, -1441, -1441,  1101, -1441, -1441, 12319, -1441, -1441,  1224,
    7972,  1134, -1441,  1228,  6190, -1441, 12887,   214,   543, -1441,
    1129,  1130, -1441,  1132,  6190,   751,   497, 12887,  1204,  1030,
     632,   632,  8269,   502, -1441, -1441, 12319, -1441, -1441,  1192,
    8566, -1441,  1135,  1043, 12887,  1211,  1110,  1209, -1441, 12887,
    1140, 12319,  4705, 12319,  1141, -1441, -1441,  1238,   511, -1441,
   -1441, -1441, -1441,  1152,   565, -1441, -1441, -1441,  1142, -1441,
    1219, -1441,   482, 12887, -1441,   632, -1441, -1441, -1441, -1441,
   -1441,  7972,  1070, 12887,  1221, -1441,  4705,  1155, -1441, -1441,
    1156,  7972, -1441, -1441, -1441, -1441, -1441, -1441, -1441, 12887,
    1222,  1190,   483, -1441,  1054,  1075, 12887, -1441, -1441,  7972,
    6190,  1159, 12887, -1441,  1231,  1030,  1077,  7972,  1079,  6190,
     484, 12887, -1441,  8566, -1441,  8566,  1232,  1190,  1164, -1441,
    1157, 12887, -1441,  1030,  1074,  1166, -1441, 12887,  1190,  1133,
   -1441,  1240, 12887,  1080,  8566, -1441
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       181,   465,   466,   467,   184,   184,   184,   790,   989,   116,
     118,   615,   881,   890,   831,   795,   793,   775,   882,   885,
     838,   799,   776,   777,   830,   891,   779,   888,   860,   840,
     815,   835,   836,   886,   883,   834,   781,   889,   782,   783,
     930,   943,   929,   832,   851,   845,   784,   833,   786,   785,
     931,   869,   837,   812,   953,   954,   955,   956,   957,   958,
     959,   960,   961,   962,   963,   977,   984,   859,   855,   846,
     826,   774,     0,   854,   862,   870,   978,   850,   487,   827,
     828,   884,   979,   985,   847,   864,     0,   493,   454,   489,
     857,   792,   848,   849,   877,   852,   868,   876,   983,   986,
     798,   839,   879,   488,   867,   872,   778,     0,     0,     0,
     402,   865,   875,   880,   878,   858,   844,   932,   842,   843,
     980,     0,   401,     0,   981,   987,   873,   829,   853,   982,
     432,     0,   464,   874,   856,   863,   871,   866,   933,   820,
     825,   824,   823,   822,   821,   787,   841,     0,   791,   887,
     813,   921,   920,   922,   797,   796,   816,   927,   780,   919,
     924,   925,   916,   819,   861,   918,   928,   926,   917,   817,
     923,   935,   938,   939,   936,   937,   934,   788,   940,   941,
     942,   907,   906,   893,   811,   804,   900,   896,   814,   810,
     908,   909,   800,   801,   794,   803,   905,   904,   901,   897,
     914,   915,   913,   903,   899,   892,   802,   912,   911,   806,
     808,   807,   898,   902,   894,   809,   895,   805,   910,   964,
     965,   966,   967,   968,   969,   945,   946,   944,   950,   951,
     952,   947,   948,   949,   818,   970,   971,   972,   973,   974,
     975,   976,   181,     0,     2,   181,     5,     7,    19,     0,
      24,    27,    32,    33,    34,    35,    36,    37,    38,    28,
      54,    55,    29,    30,     0,    72,    75,    76,    31,    77,
      78,     0,   114,    79,    80,    81,    82,    14,   178,   179,
     180,   187,   189,   484,   190,     0,   191,   192,   193,   194,
     195,   196,   197,   200,   185,   231,   238,   233,   260,   266,
       0,   258,   259,   240,   234,   199,   235,   198,   236,   239,
     357,   359,   361,   371,   375,   377,   380,   385,   388,   391,
     393,   395,   397,     0,   399,   405,   407,     0,   423,   406,
     428,   431,   433,   436,   438,     0,   443,   440,     0,   451,
     461,   463,   437,   468,   475,   485,   476,   477,   478,   481,
     482,   479,   480,   500,   502,   503,   504,   501,   549,   550,
     551,   552,   553,   554,   460,   589,   581,   588,   587,   586,
     583,   585,   582,   584,   486,   483,   616,   617,    39,   241,
     242,   244,   243,   245,   237,     0,   462,   773,   789,   881,
     890,   888,   791,     0,   182,   183,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   144,   145,     0,     0,     0,     0,   140,
     141,   142,   143,   150,     0,     0,     0,     0,     0,     0,
       0,     0,   122,   124,   125,     0,   138,     0,     0,     0,
     184,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   285,   286,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   456,   459,   446,     0,     0,   770,   775,   799,
     777,   830,   891,   779,   840,   781,   851,   784,   786,   785,
     869,   977,   984,   774,   978,   828,   979,   985,   852,   983,
     986,   932,   980,   981,   987,   982,   933,   927,   919,   925,
     916,   817,   935,   938,   939,   936,   788,   940,   452,   462,
     773,   444,     0,   207,   445,   448,   775,   776,   777,   781,
     782,   783,   784,   774,   780,   490,     0,   450,   449,   202,
       0,     0,   779,   786,   785,     0,   184,   491,   940,     0,
     238,     0,   516,     0,   455,   771,     0,   772,   426,   427,
       0,   458,   457,   447,   430,     0,     0,   545,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     3,     1,     6,     8,
       0,     0,     0,     0,     0,   181,   181,   181,   181,     0,
     115,   188,   186,     0,   205,     0,   216,     0,     0,     0,
       0,     0,     0,     0,     0,   221,   246,   265,   261,   267,
     262,   264,   263,     0,     0,     0,   416,     0,     0,   414,
       0,   366,     0,   415,   408,   413,   412,   411,   410,   409,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   404,   403,
     400,     0,   424,   429,     0,     0,     0,   439,   472,   442,
     441,   453,     0,   469,     0,     0,     0,   556,   558,   562,
     615,     0,   120,     0,    43,    40,    41,    44,    45,     0,
       0,     0,     0,    46,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   626,   627,   628,   147,   146,
       0,    99,   154,   151,     0,   153,   152,   149,   148,     0,
     108,     0,     0,   123,     0,     0,   139,     0,     0,     0,
     595,     0,     0,     0,   591,     0,     0,     0,   605,     0,
       0,   248,   249,   268,   269,     0,     0,     0,     0,   130,
       0,   134,   184,   619,     0,    56,     0,    65,     0,     0,
       0,    57,     0,     0,     0,     0,     0,   770,   596,     0,
       0,     0,     0,   330,     0,     0,   594,     0,     0,     0,
     613,     0,     0,     0,     0,   599,     0,     0,   211,     0,
       0,   203,   201,     0,     0,     0,   490,     0,   492,     0,
     517,   516,   513,     0,     0,   547,   546,   425,     0,   544,
       0,   639,   640,   590,     0,     0,     0,     0,     0,     0,
     645,     0,   208,     0,   219,   220,     0,     0,     0,     0,
       0,   224,   225,    20,     0,    21,     0,     4,    25,     0,
      11,    26,     0,    15,   881,    73,    12,    74,    16,   209,
     206,   232,     0,     0,     0,     0,   222,   247,   303,   358,
     360,   364,   370,   369,   368,     0,   365,   362,   363,     0,
     379,   378,   376,   382,   383,   384,   381,   386,   387,   390,
     389,     0,     0,     0,     0,   421,     0,   434,   435,     0,
     473,   470,   498,     0,   988,   618,   496,     0,     0,   117,
     119,     0,     0,     0,    98,     0,    88,    90,    91,    92,
      93,    95,    96,    97,    89,    94,    84,    85,     0,     0,
     104,     0,   100,   102,   103,   110,     0,     0,    83,    42,
       0,     0,     0,     0,     0,     0,     0,   720,   725,     0,
       0,   721,   755,   708,   710,   711,   712,   714,   716,   715,
     713,   717,     0,     0,     0,   155,     0,     0,     0,   107,
       0,   158,     0,     0,   561,   555,   592,   593,     0,     0,
     609,     0,   606,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   250,   251,     0,   256,   136,     0,     0,
     131,     0,     0,     0,     0,     0,     0,    58,     0,     0,
       0,   284,   290,   287,     0,   598,   597,   604,   612,     0,
       0,     0,     0,   560,     0,     0,     0,   417,     0,     0,
       0,     0,   602,     0,   600,     0,   212,     0,     0,     0,
       0,     0,   516,   514,     0,   505,     0,   494,   495,     0,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   210,   217,     0,   779,   786,
     785,   940,     0,     0,     0,   656,     0,   226,     0,     0,
       0,   181,   181,   181,     0,   257,     0,   314,   310,   312,
       0,   304,   305,   367,     0,     0,     0,     0,   686,   373,
     659,   663,   665,   667,   669,   672,   679,   680,   688,   891,
     778,     0,   787,   392,   567,   573,   574,   576,   620,   621,
     577,   580,   394,   396,   564,   398,   422,   474,     0,   471,
     497,   121,    52,    53,    50,    51,   127,   126,     0,    86,
       0,     0,   105,   106,   111,    70,    71,    48,    49,    69,
     726,     0,   729,   756,     0,   719,   718,   723,   722,   754,
       0,     0,   731,     0,   727,   730,   709,     0,     0,     0,
       0,     0,     0,     0,   156,   162,     0,     0,     0,     0,
       0,   109,   112,     0,   159,     0,     0,   184,     0,     0,
     613,     0,     0,     0,     0,   566,     0,   271,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   252,     0,     0,
       0,     0,   297,     0,   294,   299,   255,   137,   132,   135,
       0,   204,     0,     0,    67,    61,    64,    63,     0,    59,
     288,     0,     0,   184,     0,   328,   332,     0,     0,     0,
     335,     0,     0,   341,     0,     0,   348,     0,   352,     0,
     419,   418,   184,     0,     0,   213,     0,   215,   329,     0,
       0,     0,   517,     0,   506,     0,   540,   537,     0,   541,
     542,     0,     0,   536,     0,   511,   539,   538,     0,     0,
       0,   632,   633,   629,     0,     0,   637,   638,   634,   643,
     641,     0,     0,     0,   647,   218,     0,     0,     0,     0,
       0,     0,   648,   649,     0,     0,   227,    22,     0,    13,
      17,    18,   311,   323,     0,   324,     0,   315,   316,   317,
     318,     0,   307,     0,     0,     0,   670,   683,     0,   372,
     374,     0,   702,     0,     0,     0,     0,     0,     0,   658,
     660,   661,   697,   698,   699,   701,   700,     0,     0,   674,
     673,     0,   677,   681,   695,   693,   692,   685,   689,     0,
       0,     0,     0,   570,   572,   571,   568,   565,   499,   129,
     128,    87,   101,   743,   724,     0,   748,     0,   748,   737,
     732,   157,   163,   165,   164,     0,     0,     0,   113,   160,
       0,    23,     0,   610,   611,   614,   607,   608,   270,     0,
       0,   283,   275,     0,   279,     0,   273,     0,     0,     0,
     292,     0,     0,     0,   254,   295,   298,     0,   133,     0,
       0,    66,     0,    60,   289,     0,     0,   331,   333,   338,
       0,   336,     0,     0,     0,     0,     0,   342,     0,     0,
       0,     0,   349,     0,     0,   353,   420,     0,   603,   601,
     214,     0,     0,   516,     0,     0,   548,     0,   516,     0,
     512,    10,     0,     0,     0,     0,     0,   646,     0,     0,
       0,     0,     0,   650,     0,   657,   327,   325,   326,   319,
     320,   321,   313,     0,   308,   306,   687,   678,   684,     0,
       0,   757,   758,   768,   767,   766,     0,     0,     0,     0,
     759,   664,   765,     0,   662,   666,     0,     0,   671,   675,
       0,   696,   691,   694,   690,     0,     0,   578,     0,   575,
     625,   569,   744,     0,     0,   742,   749,   750,   746,     0,
     741,     0,   739,     0,     0,     0,     0,     0,   161,     0,
     557,   272,     0,   281,     0,     0,   277,     0,   280,   293,
     301,   302,   296,   253,     0,     0,     0,    62,   291,   563,
       0,     0,   339,   343,   337,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   559,     0,     0,   516,
       0,   543,     0,   516,   630,   631,   635,   636,   642,   644,
       0,     0,     0,     0,     0,   651,     0,   322,   309,   682,
     769,     0,     0,   761,     0,   707,   706,   705,   704,   703,
     668,     0,   760,     0,   622,     0,     0,   753,   752,   751,
       0,   745,   738,   736,     0,   733,   734,   728,   166,   168,
     170,     0,     0,     0,     0,     0,   276,   274,     0,   282,
       0,   223,   356,    68,   334,   340,     0,   354,   350,     0,
       0,     0,   344,     0,     0,   346,     0,   526,   520,   515,
       0,   516,   507,     0,     0,     0,     0,     0,     0,     0,
     763,   762,     0,     0,   623,   579,     0,   747,   740,     0,
       0,   172,   171,     0,     0,     0,     0,   167,   278,     0,
       0,     0,     0,     0,     0,   534,   528,     0,   527,   529,
     535,   532,   522,     0,   521,   523,   533,   509,     0,   508,
       0,   655,     0,     0,   228,   764,   676,   624,   735,   169,
     173,     0,     0,     0,     0,   300,     0,     0,   347,   345,
       0,     0,   519,   530,   531,   518,   524,   525,   510,     0,
       0,     0,     0,   174,     0,     0,     0,   355,   351,     0,
       0,     0,     0,   652,     0,     0,     0,     0,     0,     0,
       0,     0,   229,     0,   176,     0,     0,     0,     0,   175,
       0,     0,   653,     0,     0,     0,   230,     0,     0,     0,
     654,     0,     0,     0,     0,   177
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1441, -1441,  -219,  1120, -1441,  1109,  1123, -1441,  1117,  -541,
   -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441,
    -963, -1441, -1441, -1441, -1441,  -216,  -570, -1441,   643,  -750,
   -1441, -1441, -1441, -1441, -1441,   227,   443, -1441, -1441,    29,
    -222,   961, -1441,   940, -1441, -1441,  -624, -1441,   372, -1441,
     941, -1441,   193,  -921, -1441,  -261,  -301, -1441,  -538, -1441,
       5,    89,    68,  -277,  -177, -1441,  -855, -1441, -1441,  -528,
   -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441,
     539,   -91,  1490,     0, -1441, -1441, -1441, -1441,   386, -1441,
   -1441,  -284, -1441,     8, -1441, -1441,   192,  -719,  -709, -1441,
   -1441,   609, -1441, -1441,   -23,   177, -1441, -1441, -1441,    72,
   -1441, -1441,   310,    76, -1441, -1441,    80, -1266, -1441,   853,
     166, -1441, -1441,   162,  -980, -1441, -1441,   160, -1441, -1441,
   -1213, -1188, -1441,   156, -1441, -1441,   771,   772, -1441,  -564,
   -1441, -1441,  -630,   297,  -626,   295,   298, -1441, -1441, -1441,
   -1441, -1441,  1076, -1441, -1441, -1441, -1441,  -838,  -309, -1131,
   -1441,  -102, -1441, -1441, -1441, -1441, -1441, -1441, -1441,   -26,
    -791, -1441, -1441,   574,   239, -1441,  -374, -1441, -1441, -1441,
   -1441, -1441, -1441, -1441,   719, -1441,  -985, -1441,   142, -1441,
     601,  -799, -1441, -1441, -1441, -1441, -1441,  -291,  -282, -1151,
    -883, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441,
   -1441,   520,  -755,  -773,   243,  -863, -1441,    70,  -780, -1441,
   -1441, -1441, -1441, -1441, -1441, -1441,   969,   974,  -270,   445,
     281, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441,
   -1441, -1441, -1441, -1441, -1441,   125, -1441, -1441,   120, -1018,
     123, -1032, -1441, -1441, -1441,    92,    82,   -79,   334, -1441,
   -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441, -1441,
   -1441, -1441,    97, -1441, -1441, -1441,   -72,   331,   470, -1441,
   -1441, -1441, -1441, -1441,   272, -1441, -1441, -1440, -1441, -1441,
   -1441,  -558, -1441,    55, -1441,   -87, -1441, -1441, -1441, -1441,
   -1217, -1441,   101, -1441,  -316,  -368,  1063,   118, -1441
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
  const short int xquery_parser::yytable_ninf_ = -771;
  const short int
  xquery_parser::yytable_[] =
  {
       296,   585,  1034,   601,   296,   296,   296,  1000,   300,   393,
     396,   397,   300,   300,   300,   872,   618,   549,   662,  1012,
     873,   874,   875,   876,   682,   682,   978,   845,   847,   564,
     596,  1087,   593,  1026,  1231,  1219,   979,  1375,  1442,  1065,
    1174,   431,  1470,  1471,   704,   598,   518,  1432,  1127,   600,
     822,  1263,  1191,  1315,   838,   841,  1131,   840,   843,   846,
     848,   861,   974,   862,   863,   982,   864,   903,   866,   727,
    1621,   849,   395,   395,   395,   850,   867,   868,   400,   401,
     953,   402,   403,  1616,   684,   594,  1221,   594,   680,   594,
     605,   805,   769,   394,   394,   394,   594,   594,   406,   594,
     680,  1106,  1106,   932,  1188,   933,  1009,   296,   566,  1112,
    1173,   976,   594,  1450,  1397,   300,  1647,  1052,   601,   975,
    1157,   976,   454,   748,  1500,  1158,   732,   605,  1423,  1561,
    1009,   477,   898,   976,   477,  1365,   757,   761,   732,  1106,
    1159,   444,  1160,   733,  1198,   661,   445,   934,  1486,  1199,
    1481,  1161,  1298,     9,    10,   733,  1483,  1344,  1345,  1321,
    1317,  1192,   451,  1484,  -770,  1122,  1129,    78,  1117,   123,
    1134,   977,   452,  1165,   404,   541,  1622,  1162,  1129,    78,
    1346,    89,  1123,  1389,   123,  1321,   976,  1010,  1482,   602,
     520,   446,   749,    89,  1367,  1106,   394,  1562,   453,   412,
     579,   407,  1185,  1587,   520,  1648,   103,   798,  1106,   600,
    1084,  1028,   899,  1085,  1424,  1208,   758,   455,   103,  1685,
     398,   954,  1084,  1256,   983,  1085,  1196,   520,   663,  1708,
     455,  1322,  1207,  1253,   123,  1256,  1257,   722,  1351,   520,
     455,   520,   296,  1371,  1053,   296,   123,  1087,  1087,  1529,
     300,   954,  1426,   300,  1432,  1413,   806,  1322,   415,  1623,
     756,  1193,   984,   759,   601,   845,   847,   618,   975,  1189,
    1263,  1194,   595,  1360,   597,   468,   833,   455,   734,  1263,
     296,  1128,  1041,   835,  1071,  1478,  1073,   455,   300,   567,
    1045,  1222,   838,   841,  1450,  1055,  1423,   455,   935,  1297,
     417,  1083,   590,  1163,   602,  1614,   894,  1487,  1488,   669,
    1423,   936,   671,   937,  1323,  1324,  1086,  1325,   591,  1035,
    1011,  1106,   605,   680,   938,   939,   940,  1258,   941,   898,
     942,     9,    10,   469,  1327,  1259,   856,  1260,     9,    10,
    1323,  1324,   603,  1325,   607,  1686,  1328,  1259,   608,  1260,
    1326,   737,   643,   609,  1671,     9,    10,   600,  1646,   754,
    1327,   699,   969,   700,   699,  1261,   700,   971,   766,  1655,
     644,   610,  1328,   834,  1591,   777,   778,  1261,   605,   839,
     842,   109,  1551,   607,   784,  1036,   929,   608,   993,   605,
     474,   996,   609,  1165,  1620,   296,  1556,   701,   121,   968,
     470,   471,    78,   300,  1042,  1043,  1710,  1254,   399,   900,
     610,   989,  1046,  1047,  1513,   578,    89,  1378,  1262,  1044,
     702,   475,   599,   702,   476,   604,  1562,  1048,   438,   605,
    1106,   439,   605,   605,   650,  1021,   147,  1408,   296,   823,
     296,   103,   970,   651,   997,   731,   300,   972,   300,  1592,
     602,  1023,   601,   520,  1106,  1004,   520,   693,  1528,  1151,
    1263,  1429,   804,  1595,   296,  1390,  1020,  1432,   611,   296,
    1596,   612,   300,  1255,   808,  1152,   605,   300,  1514,  1087,
    1597,  1039,   703,   605,  1398,   703,   613,  1118,  1087,   694,
     975,   990,   827,   829,  1620,  1088,   605,  1118,   437,  1087,
    1065,   845,   847,   845,  1465,   605,   729,   611,   395,   992,
     612,   614,  1014,  1015,   605,  1022,  1685,   440,  1153,   605,
    1256,   441,   691,   520,  1121,   799,   520,   728,   605,   394,
     520,  1024,   729,  1299,  1300,  1301,   520,   729,   605,  1620,
    1040,   296,  1195,   520,   448,   605,   296,  1256,  1257,   300,
     614,   601,  1256,   775,   300,   520,  1057,   605,   781,   605,
    1037,   520,   887,   888,   520,  1605,  1610,  1119,  1658,  1106,
     886,  1691,   520,  1038,  1256,   889,  1507,  1120,   520,   520,
     520,   520,   975,  1633,   296,  1249,   520,  1730,  1744,  1756,
     450,  1064,   300,  1691,   520,   296,   296,   296,   296,  1250,
     605,  1426,   605,   300,   300,   300,   300,   605,  1251,   919,
    1135,  1136,  1365,   296,   395,  1139,   463,  1068,  1580,   431,
    1072,   300,  1759,   976,  1760,  1581,  1256,  1257,  1366,   999,
     664,   665,  1259,   975,  1260,   394,  1116,  1582,   602,  1258,
     520,   646,  1723,  1775,  1568,  1606,  1611,  1176,  1659,  1572,
    1106,   920,   828,  1106,   520,  1124,   921,  1560,  1087,  1259,
    1564,  1260,  1261,   520,  1259,   689,  1260,  1731,  1745,  1757,
     647,  1367,  1125,  1534,   643,  1692,  1535,  1476,  1215,  1701,
    1025,   690,  1215,   648,  1706,  1145,  1259,   685,  1260,  1261,
     461,   643,   644,   109,  1261,   520,  1146,  1726,  1493,  1178,
     686,  1181,  1029,  1030,  1031,  1289,   829,  1304,  1294,   644,
     121,  1088,  1088,  1743,   645,   462,  1261,   649,  1258,  1583,
    1069,  1198,  1584,  1147,   625,   466,  1199,   845,  1306,   296,
    1444,  1662,   626,   627,  1148,   628,   591,   300,  1259,  1762,
    1260,  1256,  1257,   629,  1200,   652,  1303,   630,   147,   631,
    1770,  1243,   296,  1244,   632,  1353,  1304,   991,   607,   653,
     300,  1295,   608,   976,  1690,  1696,  1305,   609,  1261,   522,
    1650,   633,   109,   467,  1653,  1295,  1198,  1306,   662,   618,
    1285,  1199,   296,   296,  1201,   610,  1595,  1354,   643,   121,
     300,   300,   520,  1596,   634,   635,   636,   637,   638,   639,
     536,  1126,  1359,  1597,  1355,  1690,   644,   575,  1151,  1449,
    1169,  1696,   576,   905,  1137,  1138,   520,   752,   752,  1170,
     395,   687,  1228,  1106,  1152,  1106,  1228,   147,  1062,   975,
    1664,  1430,  1665,  1258,   688,  1420,  1063,   520,   472,  1425,
    1304,   394,   520,   520,  1431,   473,  1433,   413,  1430,  1430,
     729,   729,  1698,  1259,  1590,  1260,  1106,  1593,  1594,  1434,
     521,  1567,  1700,  1680,   520,  1672,   520,   705,   706,   707,
     720,  1018,  1019,   431,   520,   721,   569,   520,   570,   414,
     524,   520,   611,  1261,   585,   612,  1106,   109,   553,  1296,
    1140,  1141,  1142,  1707,   920,   442,  1143,  1411,   443,   921,
    1290,  1106,  1215,  1106,   121,   525,   890,   416,  1717,   890,
    1720,   670,   890,   572,   459,   573,   673,   460,   520,   464,
     537,   666,   465,   672,  1570,   614,  1269,  1274,  1270,  1275,
     538,   708,   709,   717,   718,  1409,  1166,  1167,  1467,  1468,
     870,   871,   147,  1088,   554,   877,   878,   561,   520,   562,
     879,   880,  1088,  1114,  1114,  1607,  1608,   563,   565,   568,
     571,  1660,  1661,  1088,   574,   724,   419,   420,   421,   422,
     520,   423,   424,   725,   426,   427,   577,   580,   581,   583,
     428,   582,   584,   587,   605,   606,   623,   624,  1466,   654,
     642,   655,   656,  1314,   657,   666,   674,   675,   676,   520,
     520,   520,   520,   906,   907,   908,   909,   910,   911,   912,
     913,   914,   915,   856,   677,   678,   296,   679,   477,   695,
     697,   698,   710,   715,   300,   713,   716,   730,   719,   741,
     746,   742,  1705,   752,   755,   763,   765,   520,   764,   782,
     776,   783,   789,   439,   791,   443,   460,   800,   797,   465,
     809,   520,   807,   476,   793,   794,   810,  1062,   795,   813,
     824,   825,   818,   830,   837,  1063,   852,   869,   881,   853,
     882,   296,   296,   296,   854,   855,   895,   883,   520,   300,
     300,   300,   904,   884,   729,   901,   902,   520,   926,   520,
     927,   930,   931,   520,   952,   956,  1547,   958,   960,   431,
     963,   966,   964,   965,   973,  1239,   520,   967,   988,   994,
     995,   998,  1005,  1006,  1016,  1049,  1054,  1013,  1007,  1008,
    1017,  1050,  1088,  1070,  1056,  1080,  1076,   921,  1130,   975,
    1051,  1149,  1150,  1168,  1183,   519,  1177,  1186,  1175,   520,
    1190,   520,  1184,  1210,   748,  1223,  1211,  1553,  1212,   535,
    1213,  1216,  1218,  1217,  1224,  1227,  1228,  1588,  1234,  1242,
    1240,  1241,  1197,  1247,  1246,  1252,  1268,  1282,  1291,   701,
    1338,  1311,   552,  1286,  1313,   680,  1364,   296,  1341,  1287,
    1288,  1289,  1382,  1349,   557,   300,   560,  1357,  1350,  1369,
     954,  1352,  1373,  1337,  1318,  1459,  1460,  1461,   520,  1363,
    1393,  1381,  1376,  1395,  1385,  1402,  1412,  1407,  1403,  1399,
    1374,  1415,   296,  1401,  1430,  1380,  1383,  1384,  1443,   520,
     300,  1446,  1377,   296,  1386,  1387,  1436,  1438,  1416,  1464,
    1215,   300,  1439,  1452,  1451,  1453,  1441,  1454,  1456,  1304,
    1458,  1455,   296,  1473,  1477,   395,  1503,  1437,  1480,  1490,
     300,  1496,  1509,  1497,  1512,  1501,  1518,  1510,  1511,  1523,
    1532,   296,  1525,  1530,  1537,  1521,   394,  1631,  1544,   300,
    1546,  1550,  1545,  1601,  1603,  1549,  1612,  1566,  1635,  1553,
    1555,  1637,  1558,  1565,  1602,  1571,  1589,  1151,  1645,  1062,
    1062,   395,  1604,  1617,  1625,  1628,  1630,  1063,  1063,  1636,
    1654,   520,  1640,  1527,   520,  1644,  1652,  1657,  1666,  1667,
     395,  1674,   394,  1669,  1670,  1668,  1679,  1681,  1682,   520,
    1703,  1683,  1675,  1697,  1716,  1721,  1699,  1713,   520,   729,
    1722,   394,  1714,  1725,  1624,  1729,  1728,  1736,  1742,  1739,
    1740,  1583,   520,  1749,   928,  1746,  1711,  1751,  1761,  1763,
    1447,  1768,   520,  1764,   588,  1771,  1772,   828,  1362,  1767,
     683,  1209,   586,  1132,  1677,   592,  1379,  1637,   589,  1709,
    1067,   723,  1206,  1734,  1003,  1388,   726,  1409,  1747,  1406,
     520,  1753,  1542,  1755,  1774,  1475,  1302,  1472,  1469,   790,
    1417,  1421,  1427,  1435,   859,   897,   860,  1445,   519,   660,
     520,   519,  1033,  1727,  1115,  1718,  1724,  1457,  1372,   520,
     735,  1361,  1463,   520,  1462,   736,  1182,  1600,  1491,  1495,
    1316,  1599,  1156,  1520,   296,  1370,  1340,  1494,  1492,  1609,
       0,     0,   300,     0,     0,     0,     0,     0,     0,  1737,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1737,     0,     0,     0,   520,   692,     0,
       0,   696,  1718,     0,     0,   557,     0,     0,     0,     0,
       0,   712,  1704,     0,     0,     0,     0,     0,   714,     0,
       0,     0,  1656,     0,   520,     0,     0,     0,     0,     0,
     557,     0,     0,     0,     0,     0,   740,     0,     0,   745,
    1663,     0,     0,     0,     0,     0,     0,   762,     0,     0,
     520,   520,     0,   557,   770,   771,   774,     0,     0,     0,
       0,   780,     0,     0,     0,     0,     0,     0,     0,   787,
       0,     0,     0,     0,  1062,     0,   520,     0,   520,     0,
       0,   520,  1063,     0,     0,  1062,  1062,     0,   296,     0,
       0,     0,   520,  1063,  1063,  1062,   300,   520,  1752,     0,
       0,     0,     0,  1063,     0,     0,     0,     0,     0,     0,
       0,     0,   520,     0,     0,   788,  1766,     0,     0,     0,
       9,    10,     0,     0,     0,     0,     0,     0,     0,   774,
       0,   400,   401,     0,   402,   403,     0,     0,   796,     0,
       0,   404,     0,     0,     0,     0,     0,     0,     0,     0,
     405,   406,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     9,    10,     0,   407,     0,
     821,     0,   408,     0,  1062,     0,     0,     0,     0,     0,
       0,     0,  1063,     0,  1062,     0,   404,     0,     0,     0,
       0,     0,  1063,     0,     0,   405,     0,     0,     0,     0,
       0,     0,     0,   409,   410,   411,     0,   520,     0,   520,
       0,   520,   296,   407,     0,     0,     0,   408,   520,     0,
     300,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   296,     0,   409,   410,
    1074,   520,   412,   520,   300,     0,     0,     0,     0,     0,
       0,   413,     0,     0,     0,     0,     0,   557,     0,   520,
    1062,     0,   520,     0,     0,     0,     0,     0,  1063,  1062,
       0,     0,     0,     0,   520,     0,     0,  1063,     0,     0,
       0,   925,     0,   414,   520,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   520,   413,     0,     0,     0,
       0,   415,   957,     0,   520,     0,     0,   961,   962,     0,
       0,   416,   520,     0,     0,     0,     0,   520,     0,   520,
       0,   520,     0,     0,     0,     0,     0,     0,   414,   981,
       0,   987,     0,     0,     0,     0,     0,     0,     0,   557,
       0,   520,   557,   417,     0,     0,  1001,     0,     0,     0,
       0,   520,     0,     0,     0,     0,   416,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   520,     0,   418,
     419,   420,   421,   422,   520,   423,   424,   425,   426,   427,
     520,     0,     0,  1032,   428,   429,     0,     0,     0,   520,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   520,
       0,     0,     0,     0,     0,   520,     0,     0,     0,     0,
     520,     0,     0,   519,   418,   419,   420,   421,   422,     0,
     423,   424,   425,   426,   427,     0,     0,     0,     0,   428,
     429,     0,     0,     0,     0,  1075,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1111,  1111,  1111,  1111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1111,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1144,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1172,     0,     0,     0,     0,     0,     0,
       0,     0,  1180,     0,  1180,     0,     0,     0,  1111,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1111,     0,     0,     0,     0,     0,     0,     0,   811,
     812,     0,   814,   815,   816,   817,     0,     0,     0,     0,
       0,     0,   826,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   780,     0,   780,     0,     0,     0,
       0,     0,     0,     0,     0,   851,     0,     0,     0,     0,
       0,     0,     0,   857,   858,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1312,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   892,     0,  1111,     0,   892,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   959,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   745,     0,     0,  1391,
       0,     0,     0,     0,  1002,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1405,     0,     0,     0,     0,     0,
       0,     0,     0,  1111,     0,     0,     0,     0,     0,  1027,
       0,     0,     0,     0,     0,     0,     0,   774,     0,   857,
       0,     0,     0,     0,     0,     0,     0,  1111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1448,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1077,   821,     0,     0,     0,     0,
       0,     0,     0,     0,   519,     0,     0,     0,   519,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1133,  1111,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1526,
       0,     0,     0,     0,     0,     0,     0,     0,  1171,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1540,  1541,  1187,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1220,
       0,  1557,     0,  1111,     0,     0,  1111,     0,     0,     0,
    1225,  1226,     0,     0,     0,     0,     0,  1569,     0,     0,
       0,     0,  1573,     0,     0,  1245,     0,     0,  1248,     0,
       0,     0,     0,     0,     0,     0,     0,  1586,     0,     0,
       0,     0,  1271,  1272,  1273,     0,  1276,  1277,  1278,  1279,
    1280,  1281,     0,  1283,  1284,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1077,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1358,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1639,     0,  1641,     0,  1643,     0,     0,     0,
       0,     0,     0,  1651,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1111,     0,  1111,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1392,     0,
    1394,     0,  1396,     0,  1673,  1400,     0,  1676,     0,     0,
    1404,     0,     0,     0,     0,     0,     0,     0,     0,  1111,
       0,     0,  1410,     0,     0,     0,     0,     0,     0,  1684,
       0,  1414,     0,     0,     0,     0,     0,  1418,  1419,     0,
    1702,     0,     0,     0,     0,     0,     0,     0,     0,  1111,
       0,     0,     0,     0,     0,     0,  1440,  1712,     0,     0,
       0,     0,  1715,     0,  1111,     0,  1111,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1732,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1735,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1741,     0,     0,     0,     0,     0,     0,  1748,
       0,  1077,     0,     0,     0,  1750,     0,     0,     0,     0,
       0,     0,     0,     0,  1758,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1765,     0,     0,     0,     0,     0,
    1769,     0,     0,     0,     0,  1773,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1531,
       0,     0,     0,  1533,     0,     0,     0,  1536,     0,  1538,
       0,  1539,     0,     0,     0,     0,     0,  1543,     0,     0,
       0,     0,     0,     0,     0,  1548,     0,     0,     0,     0,
       0,     0,     0,  1552,  1554,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1410,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1574,  1575,  1576,  1577,  1578,     0,  1579,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1626,     0,  1627,     0,     0,  1629,     0,     0,
       0,     0,     0,     0,     0,  1632,     0,     0,     0,     0,
    1634,  1554,     0,     0,     0,     0,     0,     0,  1638,     0,
       0,     0,  1642,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1678,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1638,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1719,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1733,     0,     0,     0,     0,  1738,     0,     0,     0,
       0,  1719,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1738,
       1,     2,     0,     0,     0,     0,     0,  1754,     0,     3,
       4,     5,     6,     7,     8,     9,    10,     0,    11,     0,
       0,     0,    12,    13,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
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
       0,     0,     0,   127,     0,   128,   129,     0,   130,   131,
     132,     0,   133,     0,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,     0,     0,   145,   146,   147,
       0,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     9,    10,     0,    11,     0,     0,     0,
     389,   390,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,   391,    28,    29,    30,
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
       0,   122,   123,     0,     0,   124,   125,   126,     0,   539,
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
     237,   238,   239,   240,   241,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,   389,   390,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,   391,    28,    29,    30,    31,     0,    32,
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
       0,     0,   124,   125,   126,     0,   792,     0,   127,     0,
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
     240,   241,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     9,    10,     0,
      11,     0,     0,     0,   389,   390,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,  1058,
     391,    28,    29,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,  1059,  1060,    50,    51,    52,    53,    54,
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
     125,   126,     0,   792,     0,   127,     0,   128,   129,     0,
     130,   131,   132,     0,   133,     0,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,     0,     0,   145,
     146,   147,     0,   392,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,  1061,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,   389,   390,     0,    14,    15,    16,    17,    18,    19,
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
     539,     0,   127,     0,   128,   129,     0,   130,   131,   132,
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
     236,   237,   238,   239,   240,   241,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,     0,    11,     0,     0,     0,   389,   390,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
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
     123,     0,     0,   124,   125,   126,     0,     0,     0,   127,
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
     239,   240,   241,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,     0,     0,     0,    12,    13,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,     0,    32,    33,    34,
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
     124,   125,   126,     0,     0,     0,   127,     0,   128,   129,
       0,   130,   131,   132,     0,   133,     0,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,     0,     0,
     145,   146,   147,     0,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,     0,    11,     0,
       0,     0,    12,    13,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
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
       0,     0,     0,   127,     0,   128,   129,     0,   130,   131,
     132,     0,   133,     0,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,     0,     0,   145,   146,   147,
       0,   392,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,     0,     0,     0,    12,
     390,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,    48,    49,
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
     122,   123,     0,     0,   124,   125,   126,     0,     0,     0,
     127,     0,   128,   129,     0,   130,   131,   132,     0,   133,
       0,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,     0,     0,   145,   146,   147,     0,   392,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     9,
      10,     0,    11,     0,     0,     0,   844,   390,     0,    14,
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
     241,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
       0,     0,     0,   389,   390,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,  1058,   391,
      28,    29,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,  1059,  1060,    50,    51,    52,    53,    54,    55,
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
     147,     0,   392,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,  1061,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     0,     0,     0,    11,     0,     0,     0,
     389,   390,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   542,   391,    28,    29,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,   543,
     544,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,    72,    73,    74,    75,     0,     0,
      76,    77,     0,     0,     0,    78,    79,   495,    81,    82,
      83,    84,    85,   545,    87,    88,     0,     0,     0,    89,
       0,    90,    91,    92,    93,     0,    94,     0,     0,     0,
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   104,   105,   106,   546,     0,
       0,   108,   109,   110,   111,   112,     0,     0,     0,     0,
     113,   114,   115,   116,   117,   118,   119,   120,     0,   121,
       0,   122,   123,     0,     0,   124,   125,   126,     0,     0,
       0,   127,   547,   128,   129,     0,   130,   131,   132,     0,
     133,     0,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,     0,     0,   145,   146,   147,     0,   392,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   512,   513,   514,   515,   175,   176,   516,   548,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   389,   390,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   542,   391,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,   543,   544,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,    72,    73,    74,    75,     0,     0,    76,    77,     0,
       0,     0,    78,    79,   495,    81,    82,    83,    84,    85,
     545,    87,    88,     0,     0,     0,    89,     0,    90,    91,
      92,    93,     0,    94,     0,     0,     0,    95,    96,    97,
      98,    99,     0,     0,     0,     0,     0,     0,   100,   101,
     102,   103,   104,   105,   106,   546,     0,     0,   108,   109,
     110,   111,   112,     0,     0,     0,     0,   113,   114,   115,
     116,   117,   118,   119,   120,     0,   121,     0,   122,   123,
       0,     0,   124,   125,   126,     0,   885,     0,   127,     0,
     128,   129,     0,   130,   131,   132,     0,   133,     0,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
       0,     0,   145,   146,   147,     0,   392,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   512,
     513,   514,   515,   175,   176,   516,   548,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   194,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     0,     0,     0,
      11,     0,     0,     0,   389,   390,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,   542,
     391,    28,    29,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,   543,   544,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,    72,    73,
      74,    75,     0,     0,    76,    77,     0,     0,     0,    78,
      79,   495,    81,    82,    83,    84,    85,   545,    87,    88,
       0,     0,     0,    89,     0,    90,    91,    92,    93,     0,
      94,     0,     0,     0,    95,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,   104,
     105,   106,   546,     0,     0,   108,   109,   110,   111,   112,
       0,     0,     0,     0,   113,   114,   115,   116,   117,   118,
     119,   120,     0,   121,     0,   122,   123,     0,     0,   124,
     125,   126,     0,     0,     0,   127,   891,   128,   129,     0,
     130,   131,   132,     0,   133,     0,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,     0,     0,   145,
     146,   147,     0,   392,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   512,   513,   514,   515,
     175,   176,   516,   548,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   389,   390,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   542,   391,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     543,   544,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,    72,    73,    74,    75,     0,
       0,    76,    77,     0,     0,     0,    78,    79,   495,    81,
      82,    83,    84,    85,   545,    87,    88,     0,     0,     0,
      89,     0,    90,    91,    92,    93,     0,    94,     0,     0,
       0,    95,    96,    97,    98,    99,     0,     0,     0,     0,
       0,     0,   100,   101,   102,   103,   104,   105,   106,   546,
       0,     0,   108,   109,   110,   111,   112,     0,     0,     0,
       0,   113,   114,   115,   116,   117,   118,   119,   120,     0,
     121,     0,   122,   123,     0,     0,   124,   125,   126,     0,
       0,     0,   127,   896,   128,   129,     0,   130,   131,   132,
       0,   133,     0,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,     0,     0,   145,   146,   147,     0,
     392,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   512,   513,   514,   515,   175,   176,   516,
     548,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     0,     0,     0,    11,     0,     0,     0,   389,   390,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,   481,    25,   483,   391,    28,   484,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,   486,     0,    45,    46,    47,   488,   489,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,    72,    73,    74,    75,     0,     0,    76,    77,
       0,     0,     0,    78,    79,   495,    81,    82,    83,    84,
      85,   545,    87,    88,     0,     0,     0,    89,     0,    90,
      91,    92,    93,     0,    94,     0,     0,     0,   498,    96,
      97,    98,    99,     0,     0,     0,     0,     0,     0,   100,
     101,   102,   103,   104,   105,   106,   546,     0,     0,   108,
     109,   658,   111,   112,     0,     0,     0,     0,   113,   114,
     115,   116,   117,   118,   119,   120,     0,   121,     0,   659,
     123,     0,     0,   124,   125,   126,     0,     0,     0,   127,
       0,   128,   129,     0,   130,   131,   132,     0,   133,     0,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,     0,     0,   145,   146,   147,     0,   392,   149,   150,
     151,   152,   153,   154,   155,   156,   507,   158,   508,   160,
     509,   510,   163,   164,   165,   166,   167,   168,   511,   170,
     512,   513,   514,   515,   175,   176,   516,   517,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     0,
       0,    11,     0,     0,     0,   389,   390,     0,    14,    15,
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
     124,   125,   126,     0,     0,     0,   127,     0,   128,   129,
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
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     0,     0,     0,    11,     0,
       0,     0,   389,   390,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,   481,    25,   483,   391,    28,
     484,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,   486,     0,    45,    46,
      47,   488,   489,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,    72,    73,    74,    75,
       0,     0,    76,    77,     0,     0,     0,    78,    79,   495,
      81,    82,    83,    84,    85,   545,    87,    88,     0,     0,
       0,    89,     0,    90,    91,    92,    93,     0,    94,     0,
       0,     0,   498,    96,    97,    98,    99,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,   104,   105,   106,
     546,     0,     0,   108,   109,   110,   111,   112,     0,     0,
       0,     0,   113,   114,   115,   116,   117,   118,   119,   120,
       0,   121,     0,   122,   123,     0,     0,   124,   125,   126,
       0,     0,     0,   127,     0,   128,   129,     0,   130,   131,
     132,     0,   133,     0,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,     0,     0,   145,   146,   147,
       0,   392,   149,   150,   151,   152,   153,   154,   155,   156,
     507,   158,   508,   160,   509,   510,   163,   164,   165,   166,
     167,   168,   511,   170,   512,   513,   514,   515,   175,   176,
     516,   517,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     0,     0,     0,    11,     0,     0,     0,   389,
     390,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,   481,    25,   483,   391,    28,   484,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,   486,     0,    45,    46,    47,   488,   489,
      50,   490,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,    72,    73,    74,    75,     0,     0,    76,
      77,     0,     0,     0,    78,    79,   495,    81,    82,    83,
      84,    85,   545,    87,    88,     0,     0,     0,    89,     0,
      90,    91,    92,    93,     0,    94,     0,     0,     0,   498,
      96,    97,    98,    99,     0,     0,     0,     0,     0,     0,
     100,   101,   102,   103,   104,   105,   106,   546,     0,     0,
     108,   109,     0,   111,   112,     0,     0,     0,     0,   113,
     114,   115,   116,   117,   118,   119,   120,     0,   121,     0,
       0,     0,     0,     0,   124,   125,   126,     0,     0,     0,
     127,     0,   128,   129,     0,   130,   131,   132,     0,   133,
       0,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,     0,     0,   145,   146,   147,     0,   392,   149,
     150,   151,   152,   153,   154,   155,   156,   507,   158,   508,
     160,   509,   510,   163,   164,   165,   166,   167,   168,   511,
     170,   512,   513,   514,   515,   175,   176,   516,   517,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     0,
       0,     0,    11,     0,     0,     0,   389,   390,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,   481,
      25,   483,   391,    28,   484,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
     486,     0,    45,    46,    47,   488,   489,    50,   490,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
      72,    73,    74,    75,     0,     0,    76,    77,     0,     0,
       0,    78,    79,   495,    81,    82,    83,    84,    85,   545,
      87,    88,     0,     0,     0,    89,     0,    90,    91,    92,
      93,     0,    94,     0,     0,     0,   498,    96,    97,    98,
      99,     0,     0,     0,     0,     0,     0,   100,   101,   102,
     103,   104,   105,   106,   546,     0,     0,   108,   109,     0,
     111,   112,     0,     0,     0,     0,   113,   114,   115,   116,
     117,   118,   119,   120,     0,   121,     0,     0,     0,     0,
       0,   124,   125,   126,     0,     0,     0,   127,     0,   128,
     129,     0,     0,     0,   132,     0,   133,     0,   134,   135,
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
     241,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     0,     0,     0,     7,     8,     0,     0,     0,   477,
       0,     0,     0,   389,   390,     0,    14,    15,    16,   478,
      18,    19,    20,   479,    22,   480,   481,   482,   483,   391,
      28,   484,    30,    31,     0,    32,    33,    34,    35,   485,
      37,    38,    39,    40,    41,    42,    43,   486,     0,    45,
     487,    47,   488,   489,    50,   490,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,   491,
     492,    67,     0,    68,    69,    70,   493,     0,    73,    74,
      75,     0,     0,   494,    77,     0,     0,     0,     0,    79,
     495,    81,   496,   497,    84,    85,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    91,    92,    93,     0,    94,
       0,     0,     0,   498,    96,    97,   499,   500,     0,     0,
       0,     0,     0,     0,   100,   101,   102,     0,   104,   105,
     106,     0,     0,     0,     0,     0,     0,   111,   112,     0,
       0,     0,     0,   113,   114,   115,   116,   501,   118,   119,
     502,     0,     0,     0,     0,     0,     0,     0,   503,   504,
     126,     0,     0,     0,   127,     0,   128,   505,     0,     0,
       0,   132,     0,   133,     0,   134,   135,   136,   137,   506,
     139,   140,   141,   142,   143,   144,     0,     0,   145,   146,
       0,     0,   392,   149,   150,   151,   152,   153,   154,   155,
     156,   507,   158,   508,   160,   509,   510,   163,   164,   165,
     166,   167,   168,   511,   170,   512,   513,   514,   515,   175,
     176,   516,   517,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     0,     0,
       0,     7,     8,     0,     0,     0,   477,     0,     0,     0,
     389,   390,     0,    14,    15,    16,   526,    18,    19,    20,
     479,   527,   528,   481,   482,   483,   391,    28,   484,    30,
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
       0,   127,     0,   128,   505,     0,     0,     0,   132,     0,
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
     237,   238,   239,   240,   241,   555,     0,     0,     0,     0,
       0,     0,     0,     7,     8,     0,     0,     0,   767,     0,
       0,     0,   389,   390,     0,    14,    15,    16,   526,    18,
      19,    20,   479,   527,   528,   481,   482,   483,   391,    28,
     484,    30,    31,     0,    32,    33,    34,    35,   529,    37,
     530,   531,    40,    41,    42,    43,   486,     0,    45,   532,
      47,   488,   489,    50,   490,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,   491,   492,
      67,     0,    68,    69,    70,   533,     0,    73,    74,    75,
       0,     0,   494,    77,     0,     0,     0,     0,    79,   495,
      81,   496,   497,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,    90,    91,    92,    93,     0,    94,     0,
       0,     0,   498,    96,    97,   499,   500,     0,     0,     0,
       0,     0,     0,   100,   101,   102,     0,   104,   105,   106,
       0,     0,     0,     0,     0,     0,   111,   112,     0,     0,
       0,     0,   113,   114,   115,   116,   501,   118,   119,   502,
       0,     0,     0,     0,     0,     0,     0,   503,   504,   126,
       0,     0,     0,   127,   768,   128,   505,     0,     0,     0,
       0,     0,   133,     0,   134,   135,   136,   137,   506,   139,
     140,   141,   142,   143,   144,     0,     0,   145,   146,     0,
       0,   392,   149,   150,   151,   152,   153,   154,   155,   156,
     507,   534,   508,   160,   509,   510,   163,   164,   165,   166,
     167,   168,   511,   170,   512,   513,   514,   515,   175,   176,
     516,   517,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   555,     0,     0,
       0,     0,     0,     0,     0,     7,     8,     0,     0,     0,
     477,     0,     0,     0,   389,   390,     0,    14,    15,    16,
     526,    18,    19,    20,   479,   527,   528,   481,   482,   483,
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
     559,     0,     0,     0,     0,     7,     8,     0,     0,     0,
     477,     0,     0,     0,   389,   390,     0,    14,    15,    16,
     526,    18,    19,    20,   479,   527,   528,   481,   482,   483,
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
     233,   234,   235,   236,   237,   238,   239,   240,   241,     7,
       8,     0,     0,     0,   477,     0,     0,     0,   389,   390,
       0,    14,    15,    16,   478,    18,    19,    20,   479,    22,
     480,   481,  1099,   483,   391,    28,   484,    30,    31,     0,
      32,    33,    34,    35,   485,    37,    38,    39,    40,    41,
      42,    43,   486,     0,    45,   487,    47,   488,   489,    50,
     490,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,   491,   492,    67,     0,    68,    69,
      70,   493,     0,    73,    74,    75,     0,     0,   494,    77,
       0,     0,     0,     0,    79,   495,    81,   496,   497,    84,
      85,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,    93,     0,    94,     0,     0,     0,   498,    96,
      97,   499,   500,     0,     0,     0,     0,     0,     0,   100,
     101,   102,     0,   104,   105,  1100,     0,     0,     0,  1101,
       0,     0,   111,   112,     0,     0,     0,     0,   113,   114,
     115,   116,   501,   118,   119,   502,     0,     0,     0,     0,
       0,     0,     0,   503,   504,   126,     0,     0,     0,   127,
    1505,   128,   505,     0,     0,     0,  1506,     0,   133,     0,
     134,   135,   136,   137,   506,   139,   140,   141,   142,   143,
     144,     0,     0,  1102,   146,     0,     0,   392,   149,   150,
     151,   152,   153,   154,   155,   156,   507,   158,   508,   160,
     509,   510,   163,   164,   165,   166,   167,   168,   511,   170,
     512,   513,   514,   515,   175,   176,   516,   517,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     7,     8,     0,     0,     0,   477,     0,
       0,     0,   389,   390,     0,    14,    15,    16,   526,    18,
      19,    20,   479,   527,   528,   481,   482,   483,   391,    28,
     484,    30,    31,     0,    32,    33,    34,    35,   529,    37,
     530,   531,    40,    41,    42,    43,   486,     0,    45,   532,
      47,   488,   489,    50,   490,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,   491,   492,
      67,     0,    68,    69,    70,   533,     0,    73,    74,    75,
       0,     0,   494,    77,     0,     0,     0,     0,    79,   495,
      81,   496,   497,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,    90,    91,    92,    93,     0,    94,     0,
       0,     0,   498,    96,    97,   499,   500,     0,     0,     0,
       0,     0,     0,   100,   101,   102,     0,   104,   105,   106,
       0,     0,     0,     0,     0,     0,   111,   112,     0,     0,
       0,     0,   113,   114,   115,   116,   501,   118,   119,   502,
       0,     0,     0,     0,     0,     0,     0,   503,   504,   126,
       0,     0,     0,   127,   738,   128,   505,     0,     0,     0,
     739,     0,   133,     0,   134,   135,   136,   137,   506,   139,
     140,   141,   142,   143,   144,     0,     0,   145,   146,     0,
       0,   392,   149,   150,   151,   152,   153,   154,   155,   156,
     507,   534,   508,   160,   509,   510,   163,   164,   165,   166,
     167,   168,   511,   170,   512,   513,   514,   515,   175,   176,
     516,   517,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     7,     8,     0,
       0,     0,   477,     0,     0,     0,   389,   390,     0,    14,
      15,    16,   526,    18,    19,    20,   479,   527,   528,   481,
     482,   483,   391,    28,   484,    30,    31,     0,    32,    33,
      34,    35,   529,    37,   530,   531,    40,    41,    42,    43,
     486,     0,    45,   532,    47,   488,   489,    50,   490,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,   491,   492,    67,     0,    68,    69,    70,   533,
       0,    73,    74,    75,     0,     0,   494,    77,     0,     0,
       0,     0,    79,   495,    81,   496,   497,    84,    85,     0,
       0,     0,     0,     0,     0,     0,     0,    90,    91,    92,
      93,     0,    94,     0,     0,     0,   498,    96,    97,   499,
     500,     0,     0,     0,     0,     0,     0,   100,   101,   102,
       0,   104,   105,   106,     0,     0,     0,     0,     0,     0,
     111,   112,     0,     0,     0,     0,   113,   114,   115,   116,
     501,   118,   119,   502,     0,     0,     0,     0,     0,     0,
       0,   503,   504,   126,     0,     0,     0,   127,   785,   128,
     505,     0,     0,     0,   786,     0,   133,     0,   134,   135,
     136,   137,   506,   139,   140,   141,   142,   143,   144,     0,
       0,   145,   146,     0,     0,   392,   149,   150,   151,   152,
     153,   154,   155,   156,   507,   534,   508,   160,   509,   510,
     163,   164,   165,   166,   167,   168,   511,   170,   512,   513,
     514,   515,   175,   176,   516,   517,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     7,     8,     0,     0,     0,   477,     0,     0,     0,
     389,   390,     0,    14,    15,    16,   478,    18,    19,    20,
     479,    22,   480,   481,  1099,   483,   391,    28,   484,    30,
      31,     0,    32,    33,    34,    35,   485,    37,    38,    39,
      40,    41,    42,    43,   486,     0,    45,   487,    47,   488,
     489,    50,   490,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,   491,   492,    67,     0,
      68,    69,    70,   493,     0,    73,    74,    75,     0,     0,
     494,    77,     0,     0,     0,     0,    79,   495,    81,   496,
     497,    84,    85,  1428,     0,     0,     0,     0,     0,     0,
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
     237,   238,   239,   240,   241,     7,     8,     0,     0,     0,
     477,     0,     0,     0,   389,   390,     0,    14,    15,    16,
     478,    18,    19,    20,   479,    22,   480,   481,  1099,   483,
     391,    28,   484,    30,    31,     0,    32,    33,    34,    35,
     485,    37,    38,    39,    40,    41,    42,    43,   486,     0,
      45,   487,    47,   488,   489,    50,   490,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
     491,   492,    67,     0,    68,    69,    70,   493,     0,    73,
      74,    75,     0,     0,   494,    77,     0,     0,     0,     0,
      79,   495,    81,   496,   497,    84,    85,  1559,     0,     0,
       0,     0,     0,     0,     0,    90,    91,    92,    93,     0,
      94,     0,     0,     0,   498,    96,    97,   499,   500,     0,
       0,     0,     0,     0,     0,   100,   101,   102,     0,   104,
     105,  1100,     0,     0,     0,  1101,     0,     0,   111,   112,
       0,     0,     0,     0,   113,   114,   115,   116,   501,   118,
     119,   502,     0,     0,     0,     0,     0,     0,     0,   503,
     504,   126,     0,     0,     0,   127,     0,   128,   505,     0,
       0,     0,     0,     0,   133,     0,   134,   135,   136,   137,
     506,   139,   140,   141,   142,   143,   144,     0,     0,  1102,
     146,     0,     0,   392,   149,   150,   151,   152,   153,   154,
     155,   156,   507,   158,   508,   160,   509,   510,   163,   164,
     165,   166,   167,   168,   511,   170,   512,   513,   514,   515,
     175,   176,   516,   517,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     7,
       8,     0,     0,     0,   477,     0,     0,     0,   389,   390,
       0,    14,    15,    16,   478,    18,    19,    20,   479,    22,
     480,   481,  1099,   483,   391,    28,   484,    30,    31,     0,
      32,    33,    34,    35,   485,    37,    38,    39,    40,    41,
      42,    43,   486,     0,    45,   487,    47,   488,   489,    50,
     490,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,   491,   492,    67,     0,    68,    69,
      70,   493,     0,    73,    74,    75,     0,     0,   494,    77,
       0,     0,     0,     0,    79,   495,    81,   496,   497,    84,
      85,  1563,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,    93,     0,    94,     0,     0,     0,   498,    96,
      97,   499,   500,     0,     0,     0,     0,     0,     0,   100,
     101,   102,     0,   104,   105,  1100,     0,     0,     0,  1101,
       0,     0,   111,   112,     0,     0,     0,     0,   113,   114,
     115,   116,   501,   118,   119,   502,     0,     0,     0,     0,
       0,     0,     0,   503,   504,   126,     0,     0,     0,   127,
       0,   128,   505,     0,     0,     0,     0,     0,   133,     0,
     134,   135,   136,   137,   506,   139,   140,   141,   142,   143,
     144,     0,     0,  1102,   146,     0,     0,   392,   149,   150,
     151,   152,   153,   154,   155,   156,   507,   158,   508,   160,
     509,   510,   163,   164,   165,   166,   167,   168,   511,   170,
     512,   513,   514,   515,   175,   176,   516,   517,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     7,     8,     0,     0,     0,   477,     0,
       0,     0,   389,   390,     0,    14,    15,    16,   478,    18,
      19,    20,   479,    22,   480,   481,  1099,   483,   391,    28,
     484,    30,    31,     0,    32,    33,    34,    35,   485,    37,
      38,    39,    40,    41,    42,    43,   486,     0,    45,   487,
      47,   488,   489,    50,   490,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,   491,   492,
      67,     0,    68,    69,    70,   493,     0,    73,    74,    75,
       0,     0,   494,    77,     0,     0,     0,     0,    79,   495,
      81,   496,   497,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,    90,    91,    92,    93,     0,    94,     0,
       0,     0,   498,    96,    97,   499,   500,     0,     0,     0,
       0,     0,     0,   100,   101,   102,     0,   104,   105,  1100,
       0,     0,     0,  1101,     0,     0,   111,   112,     0,     0,
       0,     0,   113,   114,   115,   116,   501,   118,   119,   502,
       0,     0,     0,     0,     0,     0,     0,   503,   504,   126,
       0,     0,     0,   127,     0,   128,   505,     0,     0,     0,
       0,     0,   133,     0,   134,   135,   136,   137,   506,   139,
     140,   141,   142,   143,   144,     0,     0,  1102,   146,     0,
       0,   392,   149,   150,   151,   152,   153,   154,   155,   156,
     507,   158,   508,   160,   509,   510,   163,   164,   165,   166,
     167,   168,   511,   170,   512,   513,   514,   515,   175,   176,
     516,   517,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     7,     8,     0,
       0,     0,   477,     0,     0,     0,   389,   390,     0,    14,
      15,    16,   478,    18,    19,    20,   479,    22,   480,   481,
    1099,   483,   391,    28,   484,    30,    31,     0,    32,    33,
      34,    35,   485,    37,    38,    39,    40,    41,    42,    43,
     486,     0,    45,   487,    47,   488,   489,    50,   490,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,   491,   492,    67,     0,    68,    69,    70,   493,
       0,    73,    74,    75,     0,     0,   494,    77,     0,     0,
       0,     0,    79,   495,    81,   496,   497,    84,    85,     0,
       0,     0,     0,     0,     0,     0,     0,    90,    91,    92,
      93,     0,    94,     0,     0,     0,   498,    96,    97,   499,
     500,     0,     0,     0,     0,     0,     0,   100,   101,   102,
       0,   104,   105,  1100,     0,     0,     0,  1101,     0,     0,
     111,   112,     0,     0,     0,     0,   113,   114,   115,   116,
     501,   118,   119,   502,     0,     0,     0,     0,     0,     0,
       0,   503,   504,   126,     0,     0,     0,   127,     0,   128,
     505,     0,     0,     0,     0,     0,   133,     0,   134,   135,
     136,   137,   506,   139,   140,   141,   142,   143,   144,     0,
       0,   145,   146,     0,     0,   392,   149,   150,   151,   152,
     153,   154,   155,   156,   507,   158,   508,   160,   509,   510,
     163,   164,   165,   166,   167,   168,   511,   170,   512,   513,
     514,   515,   175,   176,   516,   517,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     7,     8,     0,     0,     0,   477,     0,     0,     0,
     389,   390,     0,    14,    15,    16,   526,    18,    19,    20,
     479,   527,   528,   481,   482,   483,   391,    28,   484,    30,
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
     237,   238,   239,   240,   241,     7,     8,     0,     0,     0,
     477,     0,     0,     0,   389,   390,     0,    14,    15,    16,
       0,    18,    19,    20,   479,     0,     0,   481,   482,     0,
     391,    28,   484,    30,    31,     0,    32,    33,    34,    35,
       0,    37,     0,     0,    40,    41,    42,    43,   486,     0,
      45,     0,    47,     0,     0,    50,   490,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
     491,   492,    67,     0,    68,    69,    70,     0,     0,    73,
      74,    75,     0,     0,   494,    77,     0,     0,     0,     0,
      79,   495,    81,   496,   497,    84,    85,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    91,    92,    93,     0,
      94,     0,     0,     0,   498,    96,    97,   499,   500,     0,
       0,     0,     0,     0,     0,   100,   101,   102,     0,   104,
     105,     0,     0,     0,     0,     0,     0,     0,   111,   112,
       0,     0,     0,     0,   113,   114,   115,   116,   501,   118,
     119,   502,     0,     0,     0,     0,     0,     0,     0,   503,
     504,   126,     0,     0,     0,   127,     0,   128,   505,     0,
       0,     0,     0,     0,   133,     0,   134,   135,   136,   137,
     506,   139,   140,   141,   142,   143,   144,     0,     0,     0,
     146,     0,     0,   392,   149,   150,   151,   152,   153,   154,
     155,   156,   507,     0,   508,   160,   509,   510,   163,   164,
     165,   166,   167,   168,   511,   170,   512,   513,   514,   515,
     175,   176,     0,   517,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,   178,   801,   280,     4,     5,     6,   762,     0,     4,
       5,     6,     4,     5,     6,   645,   300,   108,   327,   774,
     646,   647,   648,   649,   398,   399,   745,   597,   598,   131,
     249,   869,   248,   788,  1014,   998,   745,  1168,  1251,   830,
     961,    12,  1308,  1309,   412,   264,    72,  1235,   903,   271,
     578,  1036,    36,  1085,   595,   596,   919,   595,   596,   597,
     598,   625,    36,   627,   628,    55,   630,   691,   632,   437,
     116,   599,     4,     5,     6,   603,   640,   641,    37,    38,
      93,    40,    41,  1523,   400,     1,   140,     1,    29,     1,
     105,     8,   460,     4,     5,     6,     1,     1,    57,     1,
      29,   881,   882,    54,   145,    56,   105,   107,    30,   882,
      93,    95,     1,  1264,   145,   107,    92,   105,   395,    93,
      39,    95,   116,   116,  1341,    44,    45,   105,    98,   116,
     105,    29,   105,    95,    29,    95,   452,   453,    45,   919,
      59,    66,    61,    62,    53,   151,    71,    98,    95,    58,
     214,    70,   111,    26,    27,    62,   266,   245,   246,    95,
     151,   145,    24,   273,   119,   146,   916,   108,   183,   175,
     925,   145,    34,   953,    47,   107,   222,    96,   928,   108,
     268,   122,   163,   145,   175,    95,    95,   186,   252,   280,
      72,   116,   185,   122,   154,   975,   107,   184,    60,   158,
     171,    74,   975,  1469,    86,   181,   147,   185,   988,   431,
     151,   186,   185,   154,   184,   988,   111,   271,   147,     5,
     154,   234,   151,     9,   214,   154,   981,   109,   330,  1669,
     271,   167,   987,  1032,   175,     9,    10,   110,  1101,   121,
     271,   123,   242,  1164,   232,   245,   175,  1085,  1086,  1380,
     242,   234,  1232,   245,  1442,  1218,   173,   167,   217,   305,
     158,   980,   252,   158,   541,   835,   836,   551,    93,   978,
    1255,   980,   188,  1128,   188,    93,   188,   271,   185,  1264,
     280,   905,    93,   188,   188,  1317,   188,   271,   280,   211,
      93,  1000,   833,   834,  1445,   823,    98,   271,   249,   188,
     259,   865,    33,   222,   395,  1522,   674,   254,   255,   335,
      98,   262,   338,   264,   250,   251,   257,   253,    49,   128,
     145,  1101,   105,    29,   275,   276,   277,   101,   279,   105,
     281,    26,    27,   151,   270,   121,   613,   123,    26,    27,
     250,   251,   105,   253,    42,   131,   282,   121,    46,   123,
     260,   442,   156,    51,  1620,    26,    27,   579,   116,   450,
     270,    45,   105,    47,    45,   151,    47,   105,   459,  1582,
     174,    69,   282,   592,    52,   466,   467,   151,   105,   595,
     596,   155,   184,    42,   475,   194,   702,    46,   756,   105,
     120,   759,    51,  1173,  1525,   395,   184,    78,   172,   182,
     218,   219,   108,   395,   215,   216,  1672,   128,   154,   185,
      69,   105,   215,   216,   134,   110,   122,  1172,   192,   230,
     104,   151,   110,   104,   154,   188,   184,   230,   151,   105,
    1210,   154,   105,   105,   198,   105,   210,  1210,   438,   110,
     440,   147,   185,   207,   760,   440,   438,   185,   440,   127,
     541,   105,   729,   335,  1234,   182,   338,   167,  1379,    95,
    1445,  1234,   553,   267,   464,  1184,   182,  1655,   166,   469,
     274,   169,   464,   194,   565,   111,   105,   469,   198,  1317,
     284,   129,   166,   105,  1193,   166,   184,   105,  1326,   199,
      93,   185,   583,   584,  1625,   869,   105,   105,   158,  1337,
    1291,  1071,  1072,  1073,  1295,   105,   438,   166,   440,   185,
     169,   209,   185,   185,   105,   185,     5,   151,   154,   105,
       9,   154,   404,   405,   898,   184,   408,   438,   105,   440,
     412,   185,   464,  1071,  1072,  1073,   418,   469,   105,  1670,
     188,   541,   145,   425,   154,   105,   546,     9,    10,   541,
     209,   828,     9,   464,   546,   437,   185,   105,   469,   105,
     182,   443,   664,   665,   446,   105,   105,   185,   105,  1349,
     661,    28,   454,   182,     9,   666,  1349,   185,   460,   461,
     462,   463,    93,  1546,   584,   185,   468,   105,   105,   105,
     154,   182,   584,    28,   476,   595,   596,   597,   598,   185,
     105,  1581,   105,   595,   596,   597,   598,   105,   185,    93,
     926,   927,    95,   613,   546,   931,   116,   833,   185,   590,
     839,   613,  1753,    95,  1755,   185,     9,    10,   111,   140,
     189,   190,   121,    93,   123,   546,   182,   185,   729,   101,
     522,   115,   131,  1774,  1443,   185,   185,   963,   185,  1448,
    1430,   135,   584,  1433,   536,   146,   140,  1430,  1496,   121,
    1433,   123,   151,   545,   121,   164,   123,   185,   185,   185,
     144,   154,   163,   145,   156,   132,  1395,   182,   994,   182,
     140,   180,   998,   157,   182,   261,   121,   180,   123,   151,
     154,   156,   174,   155,   151,   577,   272,   132,  1328,   969,
     193,   971,   793,   794,   795,   151,   797,   104,   154,   174,
     172,  1085,  1086,  1731,   196,   154,   151,   191,   101,   151,
      33,    53,   154,   261,   130,   154,    58,  1297,   125,   729,
     192,   196,   138,   139,   272,   141,    49,   729,   121,  1757,
     123,     9,    10,   149,    76,   134,    94,   153,   210,   155,
    1768,  1021,   752,  1023,   160,   142,   104,   752,    42,   148,
     752,   207,    46,    95,  1647,  1648,   114,    51,   151,   116,
    1569,   177,   155,   154,  1573,   207,    53,   125,  1087,  1063,
    1057,    58,   782,   783,   116,    69,   267,   174,   156,   172,
     782,   783,   674,   274,   200,   201,   202,   203,   204,   205,
     116,   135,   135,   284,   191,  1688,   174,   222,    95,   192,
     297,  1694,   227,   695,   126,   127,   698,   151,   151,   306,
     752,   180,    98,  1603,   111,  1605,    98,   210,   828,    93,
    1603,    98,  1605,   101,   193,   111,   828,   719,   120,   111,
     104,   752,   724,   725,   111,   120,    98,   167,    98,    98,
     782,   783,  1651,   121,  1480,   123,  1636,  1487,  1488,   111,
     120,   111,   111,  1636,   746,  1620,   748,   218,   219,   220,
     135,   782,   783,   844,   756,   140,   222,   759,   224,   199,
     120,   763,   166,   151,  1061,   169,  1666,   155,   151,  1066,
     275,   276,   277,  1666,   135,   151,   281,  1213,   154,   140,
     184,  1681,  1218,  1683,   172,   120,   667,   227,  1681,   670,
    1683,   337,   673,   222,   151,   224,   342,   154,   800,   151,
     120,   152,   154,   154,   192,   209,   229,   229,   231,   231,
     120,   298,   299,   298,   299,  1212,   289,   290,   126,   127,
     643,   644,   210,  1317,   120,   650,   651,   120,   830,   120,
     652,   653,  1326,   883,   884,  1513,  1514,   120,   151,   213,
     154,  1591,  1592,  1337,   222,   285,   286,   287,   288,   289,
     852,   291,   292,   293,   294,   295,   116,   239,   239,   154,
     300,   240,   151,     0,   105,   188,   165,    91,  1304,    50,
     247,   197,    99,  1084,   100,   152,   119,   143,   154,   881,
     882,   883,   884,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,  1290,   182,   182,  1016,   182,    29,    47,
     150,   116,   244,   296,  1016,   291,   296,   185,   302,   282,
     116,   282,  1662,   151,     1,   116,   105,   919,   140,   151,
     185,   151,   140,   154,   182,   154,   154,    35,   151,   154,
     211,   933,    17,   154,   154,   154,    29,  1057,   154,   185,
     188,   188,   228,   243,     3,  1057,   116,    70,   228,   166,
      93,  1071,  1072,  1073,   168,   168,   147,    93,   960,  1071,
    1072,  1073,    29,    93,  1016,   105,   105,   969,   158,   971,
     158,   125,   130,   975,   244,   297,  1412,   140,   116,  1070,
     130,   185,   182,   182,   105,  1016,   988,   185,    93,    95,
      45,    95,   185,   185,   151,    93,   140,   182,   185,   185,
     182,   234,  1496,    33,   188,   116,   168,   140,   130,    93,
     222,    29,   284,   224,   116,    72,   151,   116,   297,  1021,
     145,  1023,   125,    93,   116,   151,   182,  1424,   195,    86,
     130,   158,    95,   130,   116,   145,    98,  1473,    98,   151,
     182,   182,   252,   188,   140,    35,    29,   116,   243,    78,
     258,   105,   109,   154,   105,    29,    29,  1177,   265,   154,
     154,   151,  1177,   154,   121,  1177,   123,   142,   154,    29,
     234,   154,   224,   256,   283,  1286,  1287,  1288,  1080,   284,
     145,   188,   285,   125,   142,   116,   105,    76,   116,   145,
     224,   140,  1212,   145,    98,   224,   185,   185,   130,  1101,
    1212,     7,   304,  1223,   185,   185,   182,   185,  1223,   116,
    1546,  1223,   185,   230,   188,   230,   195,   230,   234,   104,
     184,   230,  1242,   104,   185,  1177,    77,  1242,   248,   248,
    1242,   145,   185,   280,    29,   284,    29,   185,   185,   105,
     145,  1261,   168,   182,   145,   269,  1177,  1544,   124,  1261,
      95,   184,   124,   151,    93,   182,    29,   182,  1555,  1556,
     184,  1558,   184,   184,   278,   182,   182,    95,  1565,  1289,
    1290,  1223,   185,   185,   168,   145,    53,  1289,  1290,    93,
     195,  1183,   184,   255,  1186,   184,   194,   116,    93,    29,
    1242,   116,  1223,   105,   105,   263,   116,    93,   184,  1201,
     116,    93,   222,   194,   184,   184,   194,   116,  1210,  1261,
      92,  1242,   222,   181,   285,   116,   194,   116,   116,   184,
     184,   151,  1224,   184,   701,   291,   303,   116,   116,   185,
    1261,   185,  1234,   196,   245,   222,   116,  1289,  1131,   285,
     399,   989,   242,   920,  1625,   248,  1173,  1644,   245,  1670,
     831,   431,   986,   303,   765,  1183,   435,  1654,   303,  1202,
    1262,   304,  1405,   304,   304,  1313,  1076,  1311,  1308,   536,
    1224,  1229,  1232,  1237,   623,   676,   624,  1255,   335,   323,
    1282,   338,   801,  1694,   884,  1682,  1688,  1282,  1165,  1291,
     441,  1130,  1292,  1295,  1291,   441,   971,  1496,  1326,  1337,
    1086,  1493,   952,  1368,  1424,  1153,  1095,  1330,  1327,  1516,
      -1,    -1,  1424,    -1,    -1,    -1,    -1,    -1,    -1,  1716,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1740,    -1,    -1,    -1,  1349,   405,    -1,
      -1,   408,  1749,    -1,    -1,   412,    -1,    -1,    -1,    -1,
      -1,   418,  1659,    -1,    -1,    -1,    -1,    -1,   425,    -1,
      -1,    -1,  1583,    -1,  1376,    -1,    -1,    -1,    -1,    -1,
     437,    -1,    -1,    -1,    -1,    -1,   443,    -1,    -1,   446,
    1601,    -1,    -1,    -1,    -1,    -1,    -1,   454,    -1,    -1,
    1402,  1403,    -1,   460,   461,   462,   463,    -1,    -1,    -1,
      -1,   468,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   476,
      -1,    -1,    -1,    -1,  1544,    -1,  1428,    -1,  1430,    -1,
      -1,  1433,  1544,    -1,    -1,  1555,  1556,    -1,  1558,    -1,
      -1,    -1,  1444,  1555,  1556,  1565,  1558,  1449,  1745,    -1,
      -1,    -1,    -1,  1565,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1464,    -1,    -1,   522,  1763,    -1,    -1,    -1,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   536,
      -1,    37,    38,    -1,    40,    41,    -1,    -1,   545,    -1,
      -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    -1,    74,    -1,
     577,    -1,    78,    -1,  1644,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1644,    -1,  1654,    -1,    47,    -1,    -1,    -1,
      -1,    -1,  1654,    -1,    -1,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   109,   110,   111,    -1,  1559,    -1,  1561,
      -1,  1563,  1682,    74,    -1,    -1,    -1,    78,  1570,    -1,
    1682,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1716,    -1,   109,   110,
     111,  1603,   158,  1605,  1716,    -1,    -1,    -1,    -1,    -1,
      -1,   167,    -1,    -1,    -1,    -1,    -1,   674,    -1,  1621,
    1740,    -1,  1624,    -1,    -1,    -1,    -1,    -1,  1740,  1749,
      -1,    -1,    -1,    -1,  1636,    -1,    -1,  1749,    -1,    -1,
      -1,   698,    -1,   199,  1646,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1657,   167,    -1,    -1,    -1,
      -1,   217,   719,    -1,  1666,    -1,    -1,   724,   725,    -1,
      -1,   227,  1674,    -1,    -1,    -1,    -1,  1679,    -1,  1681,
      -1,  1683,    -1,    -1,    -1,    -1,    -1,    -1,   199,   746,
      -1,   748,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   756,
      -1,  1703,   759,   259,    -1,    -1,   763,    -1,    -1,    -1,
      -1,  1713,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1729,    -1,   285,
     286,   287,   288,   289,  1736,   291,   292,   293,   294,   295,
    1742,    -1,    -1,   800,   300,   301,    -1,    -1,    -1,  1751,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1761,
      -1,    -1,    -1,    -1,    -1,  1767,    -1,    -1,    -1,    -1,
    1772,    -1,    -1,   830,   285,   286,   287,   288,   289,    -1,
     291,   292,   293,   294,   295,    -1,    -1,    -1,    -1,   300,
     301,    -1,    -1,    -1,    -1,   852,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   881,   882,   883,   884,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   919,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   933,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   960,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   969,    -1,   971,    -1,    -1,    -1,   975,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   988,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   569,
     570,    -1,   572,   573,   574,   575,    -1,    -1,    -1,    -1,
      -1,    -1,   582,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1021,    -1,  1023,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   605,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   613,   614,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1080,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   672,    -1,  1101,    -1,   676,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   721,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1183,    -1,    -1,  1186,
      -1,    -1,    -1,    -1,   764,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1201,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1210,    -1,    -1,    -1,    -1,    -1,   789,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1224,    -1,   799,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1234,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1262,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   854,  1282,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1291,    -1,    -1,    -1,  1295,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   921,  1349,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1376,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   958,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1402,  1403,   977,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   999,
      -1,  1428,    -1,  1430,    -1,    -1,  1433,    -1,    -1,    -1,
    1010,  1011,    -1,    -1,    -1,    -1,    -1,  1444,    -1,    -1,
      -1,    -1,  1449,    -1,    -1,  1025,    -1,    -1,  1028,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1464,    -1,    -1,
      -1,    -1,  1042,  1043,  1044,    -1,  1046,  1047,  1048,  1049,
    1050,  1051,    -1,  1053,  1054,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1076,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1559,    -1,  1561,    -1,  1563,    -1,    -1,    -1,
      -1,    -1,    -1,  1570,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1603,    -1,  1605,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1188,    -1,
    1190,    -1,  1192,    -1,  1621,  1195,    -1,  1624,    -1,    -1,
    1200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1636,
      -1,    -1,  1212,    -1,    -1,    -1,    -1,    -1,    -1,  1646,
      -1,  1221,    -1,    -1,    -1,    -1,    -1,  1227,  1228,    -1,
    1657,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1666,
      -1,    -1,    -1,    -1,    -1,    -1,  1246,  1674,    -1,    -1,
      -1,    -1,  1679,    -1,  1681,    -1,  1683,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1703,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1713,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1729,    -1,    -1,    -1,    -1,    -1,    -1,  1736,
      -1,  1311,    -1,    -1,    -1,  1742,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1751,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1761,    -1,    -1,    -1,    -1,    -1,
    1767,    -1,    -1,    -1,    -1,  1772,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1389,
      -1,    -1,    -1,  1393,    -1,    -1,    -1,  1397,    -1,  1399,
      -1,  1401,    -1,    -1,    -1,    -1,    -1,  1407,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1415,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1423,  1424,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1441,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1452,  1453,  1454,  1455,  1456,    -1,  1458,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1532,    -1,  1534,    -1,    -1,  1537,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1545,    -1,    -1,    -1,    -1,
    1550,  1551,    -1,    -1,    -1,    -1,    -1,    -1,  1558,    -1,
      -1,    -1,  1562,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1628,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1640,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1682,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1711,    -1,    -1,    -1,    -1,  1716,    -1,    -1,    -1,
      -1,  1721,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1739,
      11,    12,    -1,    -1,    -1,    -1,    -1,  1747,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    29,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
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
      -1,    -1,    -1,   184,    -1,   186,   187,    -1,   189,   190,
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
     301,   302,   303,   304,   305,   306,   307,   308,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    29,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
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
      -1,   174,   175,    -1,    -1,   178,   179,   180,    -1,   182,
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
     303,   304,   305,   306,   307,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
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
      -1,    -1,   178,   179,   180,    -1,   182,    -1,   184,    -1,
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
     306,   307,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
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
     179,   180,    -1,   182,    -1,   184,    -1,   186,   187,    -1,
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
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
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
     182,    -1,   184,    -1,   186,   187,    -1,   189,   190,   191,
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
     302,   303,   304,   305,   306,   307,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
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
     305,   306,   307,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
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
     178,   179,   180,    -1,    -1,    -1,   184,    -1,   186,   187,
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
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    29,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
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
      -1,    -1,    -1,   184,    -1,   186,   187,    -1,   189,   190,
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
     301,   302,   303,   304,   305,   306,   307,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
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
     304,   305,   306,   307,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,
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
     307,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
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
     300,   301,   302,   303,   304,   305,   306,   307,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
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
      -1,   184,   185,   186,   187,    -1,   189,   190,   191,    -1,
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
     303,   304,   305,   306,   307,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
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
      -1,    -1,   178,   179,   180,    -1,   182,    -1,   184,    -1,
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
     306,   307,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
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
     179,   180,    -1,    -1,    -1,   184,   185,   186,   187,    -1,
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
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
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
      -1,    -1,   184,   185,   186,   187,    -1,   189,   190,   191,
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
     302,   303,   304,   305,   306,   307,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
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
     305,   306,   307,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
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
     178,   179,   180,    -1,    -1,    -1,   184,    -1,   186,   187,
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
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
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
      -1,    -1,    -1,   184,    -1,   186,   187,    -1,   189,   190,
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
     301,   302,   303,   304,   305,   306,   307,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
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
     154,   155,    -1,   157,   158,    -1,    -1,    -1,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,    -1,   172,    -1,
      -1,    -1,    -1,    -1,   178,   179,   180,    -1,    -1,    -1,
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
     304,   305,   306,   307,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,
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
     147,   148,   149,   150,   151,    -1,    -1,   154,   155,    -1,
     157,   158,    -1,    -1,    -1,    -1,   163,   164,   165,   166,
     167,   168,   169,   170,    -1,   172,    -1,    -1,    -1,    -1,
      -1,   178,   179,   180,    -1,    -1,    -1,   184,    -1,   186,
     187,    -1,    -1,    -1,   191,    -1,   193,    -1,   195,   196,
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
     307,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    -1,    93,    94,    95,    96,    -1,    98,    99,
     100,    -1,    -1,   103,   104,    -1,    -1,    -1,    -1,   109,
     110,   111,   112,   113,   114,   115,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,   125,   126,   127,    -1,   129,
      -1,    -1,    -1,   133,   134,   135,   136,   137,    -1,    -1,
      -1,    -1,    -1,    -1,   144,   145,   146,    -1,   148,   149,
     150,    -1,    -1,    -1,    -1,    -1,    -1,   157,   158,    -1,
      -1,    -1,    -1,   163,   164,   165,   166,   167,   168,   169,
     170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,   179,
     180,    -1,    -1,    -1,   184,    -1,   186,   187,    -1,    -1,
      -1,   191,    -1,   193,    -1,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,    -1,    -1,   208,   209,
      -1,    -1,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,   257,   258,   259,
      -1,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
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
      -1,   184,    -1,   186,   187,    -1,    -1,    -1,   191,    -1,
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
     303,   304,   305,   306,   307,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    -1,    93,    94,    95,    96,    -1,    98,    99,   100,
      -1,    -1,   103,   104,    -1,    -1,    -1,    -1,   109,   110,
     111,   112,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,   125,   126,   127,    -1,   129,    -1,
      -1,    -1,   133,   134,   135,   136,   137,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   145,   146,    -1,   148,   149,   150,
      -1,    -1,    -1,    -1,    -1,    -1,   157,   158,    -1,    -1,
      -1,    -1,   163,   164,   165,   166,   167,   168,   169,   170,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,   179,   180,
      -1,    -1,    -1,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,    -1,    -1,   208,   209,    -1,
      -1,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,    -1,   257,   258,   259,    -1,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
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
     299,   300,   301,   302,   303,   304,   305,   306,   307,    18,
      19,    -1,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
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
     299,   300,   301,   302,   303,   304,   305,   306,   307,    24,
      25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
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
     145,   146,    -1,   148,   149,   150,    -1,    -1,    -1,   154,
      -1,    -1,   157,   158,    -1,    -1,    -1,    -1,   163,   164,
     165,   166,   167,   168,   169,   170,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   178,   179,   180,    -1,    -1,    -1,   184,
     185,   186,   187,    -1,    -1,    -1,   191,    -1,   193,    -1,
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
     305,   306,   307,    24,    25,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    -1,    93,    94,    95,    96,    -1,    98,    99,   100,
      -1,    -1,   103,   104,    -1,    -1,    -1,    -1,   109,   110,
     111,   112,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,   125,   126,   127,    -1,   129,    -1,
      -1,    -1,   133,   134,   135,   136,   137,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   145,   146,    -1,   148,   149,   150,
      -1,    -1,    -1,    -1,    -1,    -1,   157,   158,    -1,    -1,
      -1,    -1,   163,   164,   165,   166,   167,   168,   169,   170,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,   179,   180,
      -1,    -1,    -1,   184,   185,   186,   187,    -1,    -1,    -1,
     191,    -1,   193,    -1,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,    -1,    -1,   208,   209,    -1,
      -1,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,    -1,   257,   258,   259,    -1,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,    24,    25,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    94,    95,    96,
      -1,    98,    99,   100,    -1,    -1,   103,   104,    -1,    -1,
      -1,    -1,   109,   110,   111,   112,   113,   114,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,
     127,    -1,   129,    -1,    -1,    -1,   133,   134,   135,   136,
     137,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,
      -1,   148,   149,   150,    -1,    -1,    -1,    -1,    -1,    -1,
     157,   158,    -1,    -1,    -1,    -1,   163,   164,   165,   166,
     167,   168,   169,   170,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   178,   179,   180,    -1,    -1,    -1,   184,   185,   186,
     187,    -1,    -1,    -1,   191,    -1,   193,    -1,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,    -1,
      -1,   208,   209,    -1,    -1,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
     257,   258,   259,    -1,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
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
     303,   304,   305,   306,   307,    24,    25,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,    93,    94,    95,    96,    -1,    98,
      99,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,    -1,
     109,   110,   111,   112,   113,   114,   115,   116,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,    -1,
     129,    -1,    -1,    -1,   133,   134,   135,   136,   137,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   145,   146,    -1,   148,
     149,   150,    -1,    -1,    -1,   154,    -1,    -1,   157,   158,
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
     299,   300,   301,   302,   303,   304,   305,   306,   307,    24,
      25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    94,
      95,    96,    -1,    98,    99,   100,    -1,    -1,   103,   104,
      -1,    -1,    -1,    -1,   109,   110,   111,   112,   113,   114,
     115,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
     125,   126,   127,    -1,   129,    -1,    -1,    -1,   133,   134,
     135,   136,   137,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     145,   146,    -1,   148,   149,   150,    -1,    -1,    -1,   154,
      -1,    -1,   157,   158,    -1,    -1,    -1,    -1,   163,   164,
     165,   166,   167,   168,   169,   170,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   178,   179,   180,    -1,    -1,    -1,   184,
      -1,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
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
     305,   306,   307,    24,    25,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    -1,    93,    94,    95,    96,    -1,    98,    99,   100,
      -1,    -1,   103,   104,    -1,    -1,    -1,    -1,   109,   110,
     111,   112,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,   125,   126,   127,    -1,   129,    -1,
      -1,    -1,   133,   134,   135,   136,   137,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   145,   146,    -1,   148,   149,   150,
      -1,    -1,    -1,   154,    -1,    -1,   157,   158,    -1,    -1,
      -1,    -1,   163,   164,   165,   166,   167,   168,   169,   170,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,   179,   180,
      -1,    -1,    -1,   184,    -1,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,    -1,    -1,   208,   209,    -1,
      -1,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,    -1,   257,   258,   259,    -1,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,    24,    25,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    94,    95,    96,
      -1,    98,    99,   100,    -1,    -1,   103,   104,    -1,    -1,
      -1,    -1,   109,   110,   111,   112,   113,   114,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,
     127,    -1,   129,    -1,    -1,    -1,   133,   134,   135,   136,
     137,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,
      -1,   148,   149,   150,    -1,    -1,    -1,   154,    -1,    -1,
     157,   158,    -1,    -1,    -1,    -1,   163,   164,   165,   166,
     167,   168,   169,   170,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   178,   179,   180,    -1,    -1,    -1,   184,    -1,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,    -1,
      -1,   208,   209,    -1,    -1,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
     257,   258,   259,    -1,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
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
     303,   304,   305,   306,   307,    24,    25,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      -1,    40,    41,    42,    43,    -1,    -1,    46,    47,    -1,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      -1,    60,    -1,    -1,    63,    64,    65,    66,    67,    -1,
      69,    -1,    71,    -1,    -1,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,    93,    94,    95,    -1,    -1,    98,
      99,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,    -1,
     109,   110,   111,   112,   113,   114,   115,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,    -1,
     129,    -1,    -1,    -1,   133,   134,   135,   136,   137,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   145,   146,    -1,   148,
     149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,   158,
      -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,   168,
     169,   170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,
     179,   180,    -1,    -1,    -1,   184,    -1,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,    -1,    -1,    -1,
     209,    -1,    -1,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,    -1,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,    -1,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,    11,    12,    20,    21,    22,    23,    24,    25,    26,
      27,    29,    33,    34,    36,    37,    38,    39,    40,    41,
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
     562,   563,   564,   565,   568,   626,   628,   629,   630,    33,
      34,    49,   212,   382,   383,   384,   382,   382,   154,   154,
      37,    38,    40,    41,    47,    56,    57,    74,    78,   109,
     110,   111,   158,   167,   199,   217,   227,   259,   285,   286,
     287,   288,   289,   291,   292,   293,   294,   295,   300,   301,
     360,   361,   365,   366,   367,   371,   372,   158,   151,   154,
     151,   154,   151,   154,    66,    71,   116,   408,   154,   368,
     154,    24,    34,    60,   116,   271,   420,   422,   423,   151,
     154,   154,   154,   116,   151,   154,   154,   154,    93,   151,
     218,   219,   120,   120,   120,   151,   154,    29,    39,    43,
      45,    46,    47,    48,    51,    59,    67,    70,    72,    73,
      75,    89,    90,    96,   103,   110,   112,   113,   133,   136,
     137,   167,   170,   178,   179,   187,   199,   221,   223,   225,
     226,   233,   235,   236,   237,   238,   241,   242,   491,   628,
     629,   120,   116,   391,   120,   120,    39,    44,    45,    59,
      61,    62,    70,    96,   222,   628,   116,   120,   120,   182,
     382,   384,    48,    72,    73,   116,   151,   185,   242,   403,
     405,   415,   628,   151,   120,    16,   627,   628,    18,    19,
     628,   120,   120,   120,   483,   151,    30,   211,   213,   222,
     224,   154,   222,   224,   222,   222,   227,   116,   110,   361,
     239,   239,   240,   154,   151,   386,   325,     0,   327,   328,
      33,    49,   330,   347,     1,   188,   324,   188,   324,   110,
     362,   385,   403,   105,   188,   105,   188,    42,    46,    51,
      69,   166,   169,   184,   209,   398,   407,   412,   413,   414,
     428,   429,   433,   165,    91,   130,   138,   139,   141,   149,
     153,   155,   160,   177,   200,   201,   202,   203,   204,   205,
     475,   476,   247,   156,   174,   196,   115,   144,   157,   191,
     198,   207,   134,   148,    50,   197,    99,   100,   156,   174,
     474,   151,   480,   483,   189,   190,   152,   495,   496,   491,
     495,   491,   154,   495,   119,   143,   154,   182,   182,   182,
      29,   363,   498,   363,   626,   180,   193,   180,   193,   164,
     180,   629,   628,   167,   199,    47,   628,   150,   116,    45,
      47,    78,   104,   166,   627,   218,   219,   220,   298,   299,
     244,   599,   628,   291,   628,   296,   296,   298,   299,   302,
     135,   140,   110,   365,   285,   293,   372,   627,   383,   384,
     185,   382,    45,    62,   185,   548,   549,   403,   185,   191,
     628,   282,   282,   417,   418,   628,   116,   424,   116,   185,
     369,   370,   151,   388,   403,     1,   158,   626,   111,   158,
     343,   626,   628,   116,   140,   105,   403,    29,   185,   627,
     628,   628,   441,   442,   628,   383,   185,   403,   403,   550,
     628,   383,   151,   151,   403,   185,   191,   628,   628,   140,
     441,   182,   182,   154,   154,   154,   628,   151,   185,   184,
      35,   511,   512,   513,   403,     8,   173,    17,   403,   211,
      29,   404,   404,   185,   404,   404,   404,   404,   228,   566,
     567,   628,   391,   110,   188,   188,   404,   403,   384,   403,
     243,   401,   402,   188,   324,   188,   324,     3,   331,   347,
     380,   331,   347,   380,    33,   348,   380,   348,   380,   391,
     391,   404,   116,   166,   168,   168,   385,   404,   404,   458,
     459,   461,   461,   461,   461,   460,   461,   461,   461,    70,
     465,   465,   464,   466,   466,   466,   466,   467,   467,   468,
     468,   228,    93,    93,    93,   182,   403,   483,   483,   403,
     496,   185,   404,   506,   627,   147,   185,   506,   105,   185,
     185,   105,   105,   368,    29,   629,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,   350,   351,   352,    93,
     135,   140,   356,   357,   358,   628,   158,   158,   350,   626,
     125,   130,    54,    56,    98,   249,   262,   264,   275,   276,
     277,   279,   281,   600,   601,   602,   603,   604,   605,   612,
     618,   619,   244,    93,   234,   375,   297,   628,   140,   404,
     116,   628,   628,   130,   182,   182,   185,   185,   182,   105,
     185,   105,   185,   105,    36,    93,    95,   145,   419,   420,
     534,   628,    55,   214,   252,   409,   410,   628,    93,   105,
     185,   382,   185,   627,    95,    45,   627,   626,    95,   140,
     534,   628,   404,   423,   182,   185,   185,   185,   185,   105,
     186,   145,   534,   182,   185,   185,   151,   182,   383,   383,
     182,   105,   185,   105,   185,   140,   534,   404,   186,   403,
     403,   403,   628,   512,   513,   128,   194,   182,   182,   129,
     188,    93,   215,   216,   230,    93,   215,   216,   230,    93,
     234,   222,   105,   232,   140,   391,   188,   185,    48,    72,
      73,   242,   405,   415,   182,   492,   572,   402,   347,    33,
      33,   188,   324,   188,   111,   628,   168,   404,   434,   435,
     116,   430,   431,   461,   151,   154,   257,   479,   498,   573,
     576,   577,   578,   579,   580,   584,   586,   588,   589,    47,
     150,   154,   208,   535,   537,   539,   540,   556,   557,   558,
     559,   628,   535,   533,   539,   533,   182,   183,   105,   185,
     185,   498,   146,   163,   146,   163,   135,   388,   368,   351,
     130,   537,   358,   404,   534,   626,   626,   126,   127,   626,
     275,   276,   277,   281,   628,   261,   272,   261,   272,    29,
     284,    95,   111,   154,   606,   609,   600,    39,    44,    59,
      61,    70,    96,   222,   374,   540,   289,   290,   224,   297,
     306,   404,   628,    93,   375,   297,   626,   151,   550,   551,
     628,   550,   551,   116,   125,   535,   116,   404,   145,   420,
     145,    36,   145,   419,   420,   145,   534,   252,    53,    58,
      76,   116,   419,   425,   426,   427,   410,   534,   535,   370,
      93,   182,   195,   130,   342,   626,   158,   130,    95,   342,
     404,   140,   420,   151,   116,   404,   404,   145,    98,   444,
     445,   446,   448,   449,    98,   452,   453,   454,   455,   383,
     182,   182,   151,   550,   550,   404,   140,   188,   404,   185,
     185,   185,    35,   513,   128,   194,     9,    10,   101,   121,
     123,   151,   192,   508,   510,   521,   522,   525,    29,   229,
     231,   404,   404,   404,   229,   231,   404,   404,   404,   404,
     404,   404,   116,   404,   404,   385,   154,   154,   154,   151,
     184,   243,   569,   570,   154,   207,   386,   188,   111,   380,
     380,   380,   434,    94,   104,   114,   125,   436,   437,   438,
     439,   105,   628,   105,   403,   573,   580,   151,   283,   462,
     625,    95,   167,   250,   251,   253,   260,   270,   282,   574,
     575,   594,   595,   596,   597,   620,   623,   256,   258,   581,
     599,   265,   585,   621,   245,   246,   268,   590,   591,   154,
     154,   537,   154,   142,   174,   191,   536,   142,   404,   135,
     388,   552,   357,   284,    29,    95,   111,   154,   613,    29,
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
     185,   185,    29,   134,   198,   615,   616,   617,    29,   614,
     615,   269,   610,   105,   607,   168,   628,   255,   375,   481,
     182,   404,   145,   404,   145,   419,   404,   145,   404,   404,
     628,   628,   426,   404,   124,   124,    95,   626,   404,   182,
     184,   184,   404,   385,   404,   184,   184,   628,   184,   116,
     535,   116,   184,   116,   535,   184,   182,   111,   513,   628,
     192,   182,   513,   628,   404,   404,   404,   404,   404,   404,
     185,   185,   185,   151,   154,   571,   628,   439,   626,   182,
     466,    52,   127,   464,   464,   267,   274,   284,   598,   598,
     579,   151,   278,    93,   185,   105,   185,   613,   613,   617,
     105,   185,    29,   611,   622,   608,   609,   185,   377,   378,
     481,   116,   222,   305,   285,   168,   404,   404,   145,   404,
      53,   385,   404,   342,   404,   385,    93,   385,   404,   628,
     184,   628,   404,   628,   184,   385,   116,    92,   181,   514,
     513,   628,   194,   513,   195,   452,   403,   116,   105,   185,
     464,   464,   196,   403,   535,   535,    93,    29,   263,   105,
     105,   439,   534,   628,   116,   222,   628,   377,   404,   116,
     535,    93,   184,    93,   628,     5,   131,   517,   518,   520,
     522,    28,   132,   515,   516,   519,   522,   194,   513,   194,
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
     491,   491,   492,   492,   493,   493,   493,   493,   494,   494,
     494,   494,   495,   495,   496,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   498,   498,   499,   499,   499,
     500,   501,   501,   502,   503,   504,   505,   505,   506,   506,
     507,   507,   508,   508,   508,   509,   509,   509,   509,   509,
     509,   510,   510,   511,   511,   512,   513,   513,   514,   514,
     515,   515,   516,   516,   516,   516,   517,   517,   518,   518,
     518,   518,   519,   519,   520,   520,   521,   521,   521,   521,
     522,   522,   522,   522,   523,   523,   524,   524,   525,   526,
     526,   526,   526,   526,   526,   527,   528,   528,   529,   529,
     530,   531,   532,   532,   533,   533,   534,   535,   535,   535,
     536,   536,   536,   537,   537,   537,   537,   537,   538,   538,
     539,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     541,   542,   542,   542,   543,   544,   545,   545,   545,   546,
     546,   546,   546,   546,   547,   548,   548,   548,   548,   548,
     548,   548,   549,   550,   551,   552,   553,   553,   554,   555,
     556,   556,   557,   558,   558,   559,   560,   560,   560,   561,
     561,   561,   561,   561,   561,   561,   561,   561,   561,   562,
     562,   563,   563,   564,   565,   566,   566,   567,   568,   569,
     569,   570,   570,   570,   570,   571,   572,   572,   573,   574,
     574,   575,   575,   576,   576,   577,   577,   578,   578,   579,
     579,   580,   581,   581,   582,   582,   583,   584,   584,   584,
     585,   585,   586,   587,   587,   588,   589,   589,   590,   590,
     591,   591,   591,   592,   592,   593,   593,   594,   594,   594,
     594,   594,   595,   596,   597,   598,   598,   598,   599,   599,
     600,   600,   600,   600,   600,   600,   600,   600,   601,   601,
     601,   601,   602,   602,   603,   604,   604,   605,   605,   605,
     606,   606,   607,   607,   608,   608,   609,   610,   610,   611,
     611,   612,   612,   612,   613,   613,   614,   614,   615,   615,
     616,   616,   617,   617,   618,   619,   619,   620,   620,   620,
     621,   622,   622,   622,   622,   623,   623,   624,   624,   625,
     626,   627,   627,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   629,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       3,     4,     1,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     3,     1,     4,     4,     3,     4,     1,     3,
       1,     1,     1,     1,     1,     4,     5,     8,     9,     9,
      10,     1,     2,     1,     2,     6,     0,     1,     3,     3,
       0,     1,     1,     1,     2,     2,     0,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     2,     3,     3,     2,     1,
       1,     1,     1,     1,     1,     4,     3,     7,     3,     7,
       4,     4,     3,     7,     1,     2,     2,     1,     2,     3,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     4,     4,     3,     3,     3,     4,     4,     3,
       4,     6,     4,     6,     4,     3,     4,     6,     6,     4,
       6,     6,     4,     1,     2,     1,     1,     1,     3,     3,
       1,     1,     4,     5,     6,     3,     3,     3,     3,     5,
       7,     7,     5,     5,     5,     7,     7,     5,     5,     3,
       3,     5,     7,     5,     7,     1,     4,     3,     5,     1,
       2,     3,     7,    10,    13,     3,     1,     3,     2,     0,
       1,     1,     2,     1,     3,     1,     3,     1,     4,     1,
       2,     3,     0,     1,     0,     1,     4,     2,     3,     1,
       0,     1,     4,     0,     1,     2,     1,     3,     0,     1,
       2,     2,     1,     0,     1,     0,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     1,     1,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     1,     2,     2,     3,     1,     2,     2,     5,     2,
       1,     1,     0,     2,     1,     3,     4,     0,     2,     0,
       2,     4,     4,     3,     2,     3,     1,     3,     0,     1,
       1,     2,     2,     2,     2,     1,     2,     2,     2,     2,
       3,     2,     3,     3,     4,     2,     2,     1,     1,     3,
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
  "\"'ns:*'\"", "\"'&entity;'\"", "\"'comment literal'\"",
  "\"'pi <NCName {>'\"", "\"'NCName_sval'\"", "\"'pragma literal'\"",
  "\"'QName #)'\"", "\"'EQName #)'\"", "\"'*:QName'\"",
  "\"'element QName {'\"", "\"'attribute QName {'\"",
  "\"'processing-instruction NCName {'\"", "\"'QName'\"", "\"'EQName'\"",
  "\"'%QName'\"", "\"'%EQName'\"", "\"'quote attribute content'\"",
  "\"'STRING'\"", "\"'XML comment'\"", "\"'URI'\"", "\"'NCName'\"",
  "\"'declare'\"", "\"'module'\"", "\"'<blank>'\"", "\"'allowing'\"",
  "\"'base-uri'\"", "\"'boundary-space'\"", "\"'comment'\"",
  "\"'construction'\"", "\"'copy-namespaces'\"", "\"'count'\"",
  "\"'document'\"", "\"'document-node'\"", "\"'element'\"", "\"'for'\"",
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
      -1,   212,   213,    29,   188,    -1,   212,   213,    29,   129,
      29,   188,    -1,   330,   188,   380,    -1,   347,   188,   380,
      -1,   330,   188,   347,   188,   380,    -1,   380,    -1,   330,
     324,   380,    -1,   347,   324,   380,    -1,   330,   188,   347,
     324,   380,    -1,   330,   324,   347,   188,   380,    -1,   329,
      -1,   329,   330,   188,    -1,   329,   347,   188,    -1,   329,
     330,   188,   347,   188,    -1,    34,   158,   627,   130,   626,
     188,    -1,   331,    -1,   330,   188,   331,    -1,   330,   324,
     331,    -1,   332,    -1,   340,    -1,   345,    -1,   346,    -1,
     354,    -1,   333,    -1,   334,    -1,   335,    -1,   336,    -1,
     337,    -1,   338,    -1,   339,    -1,   560,    -1,    33,    38,
     180,    -1,    33,    38,   193,    -1,    33,   111,   104,   626,
      -1,    33,    37,   626,    -1,    33,    40,   180,    -1,    33,
      40,   193,    -1,    33,    57,   167,    -1,    33,    57,   199,
      -1,    33,   111,   166,   125,   126,    -1,    33,   111,   166,
     125,   127,    -1,    33,    41,   180,   105,   146,    -1,    33,
      41,   180,   105,   163,    -1,    33,    41,   164,   105,   146,
      -1,    33,    41,   164,   105,   163,    -1,   341,    -1,   344,
      -1,    49,    24,     1,    -1,    49,    60,   626,    -1,    49,
      60,   343,   626,    -1,    49,    60,   626,    95,   342,    -1,
      49,    60,   343,   626,    95,   342,    -1,   626,    -1,   342,
     105,   626,    -1,   158,   627,   130,    -1,   111,    45,   158,
      -1,    49,    34,   626,    -1,    49,    34,   158,   627,   130,
     626,    -1,    49,    34,   626,    95,   342,    -1,    49,    34,
     158,   627,   130,   626,    95,   342,    -1,    33,   158,   627,
     130,   626,    -1,    33,   111,    45,   158,   626,    -1,    33,
     111,    47,   158,   626,    -1,   348,    -1,   347,   188,   348,
      -1,   347,   324,   348,    -1,   349,    -1,   353,    -1,   355,
      -1,   359,    -1,   364,    -1,   373,    -1,   376,    -1,   379,
      -1,    33,   111,    78,   350,    -1,    33,    78,   628,   350,
      -1,   351,    -1,   350,   351,    -1,   352,   130,   552,    -1,
      79,    -1,    87,    -1,    80,    -1,    81,    -1,    82,    -1,
      83,    -1,    88,    -1,    84,    -1,    85,    -1,    86,    -1,
      33,    56,   628,    29,    -1,    33,   259,   599,    -1,    33,
     109,   150,   356,    -1,    93,   537,   357,    -1,   357,    -1,
     358,    -1,   135,    -1,   135,   358,    -1,   140,   404,    -1,
      33,   360,   140,   404,    -1,    33,   360,   135,    -1,    33,
     360,   135,   140,   404,    -1,   110,   116,   628,    -1,   110,
     116,   628,   534,    -1,   361,   110,   116,   628,    -1,   361,
     110,   116,   628,   534,    -1,   362,    -1,   361,   362,    -1,
      26,    -1,    26,   154,   363,   185,    -1,    27,    -1,    27,
     154,   363,   185,    -1,   498,    -1,   363,   105,   498,    -1,
      33,   365,    -1,    33,   361,   365,    -1,   366,    -1,   367,
      -1,    47,   629,   368,   388,    -1,    47,   629,   368,   135,
      -1,    74,    47,   629,   368,   388,    -1,    74,    47,   629,
     368,   135,    -1,   154,   185,    -1,   154,   369,   185,    -1,
     154,   185,    93,   535,    -1,   154,   369,   185,    93,   535,
      -1,   370,    -1,   369,   105,   370,    -1,   116,   628,    -1,
     116,   628,   534,    -1,   372,    -1,   371,   372,    -1,   286,
      -1,   287,    -1,   288,    -1,   289,    -1,   167,    -1,   199,
      -1,   227,   299,    -1,   227,   298,    -1,   300,   299,    -1,
     300,   298,    -1,   291,    -1,   292,   291,    -1,   295,   296,
      -1,   294,   296,    -1,    33,   285,   628,    -1,    33,   285,
     628,   375,    -1,    33,   285,   628,    93,   374,    -1,    33,
     285,   628,    93,   374,   375,    -1,    33,   371,   285,   628,
      -1,    33,   371,   285,   628,   375,    -1,    33,   371,   285,
     628,    93,   374,    -1,    33,   371,   285,   628,    93,   374,
     375,    -1,   540,    -1,   540,   536,    -1,   234,   290,   224,
      -1,   234,   289,   224,    -1,    33,   293,   628,   297,   224,
     481,   168,   377,    -1,    33,   371,   293,   628,   297,   224,
     481,   168,   377,    -1,   378,    -1,   377,   105,   378,    -1,
     481,    -1,   481,   534,    -1,   481,   439,    -1,   481,   534,
     439,    -1,    33,   301,   302,   628,   297,   285,   628,   116,
     628,   303,   404,    -1,    33,   301,   302,   628,   297,   285,
     628,   222,   116,   628,   303,   291,   304,   481,    -1,    33,
     301,   302,   628,   297,   285,   628,   305,   222,   116,   628,
     303,   404,    -1,    33,   301,   302,   628,   306,   304,   255,
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
     410,   410,    -1,    46,   408,   424,   410,    -1,    42,   116,
     628,    -1,   416,    -1,   421,    -1,   411,    -1,   413,    -1,
     428,    -1,   433,    -1,   429,    -1,   412,    -1,   413,    -1,
     415,   414,    -1,    46,   116,   417,    -1,   418,    -1,   417,
     105,   116,   418,    -1,   628,   145,   404,    -1,   628,    36,
     125,   145,   404,    -1,   628,   534,   145,   404,    -1,   628,
     534,    36,   125,   145,   404,    -1,   628,   419,   145,   404,
      -1,   628,    36,   125,   419,   145,   404,    -1,   628,   534,
     419,   145,   404,    -1,   628,   534,    36,   125,   419,   145,
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
      -1,   480,    -1,   479,   480,    -1,   175,   628,    17,    -1,
     175,    18,    -1,   175,    19,    -1,   482,    -1,   482,   483,
      -1,   190,   483,    -1,   483,    -1,   189,    -1,   484,    -1,
     484,   189,   483,    -1,   484,   190,   483,    -1,   485,    -1,
     494,    -1,   486,    -1,   486,   495,    -1,   489,    -1,   489,
     495,    -1,   487,   491,    -1,   488,    -1,   103,   120,    -1,
     112,   120,    -1,    96,   120,    -1,   187,   120,    -1,   113,
     120,    -1,   137,   120,    -1,   136,   120,    -1,   491,    -1,
      97,   491,    -1,   490,   491,    -1,   118,    -1,   170,   120,
      -1,    89,   120,    -1,   179,   120,    -1,   178,   120,    -1,
      90,   120,    -1,   540,    -1,   492,    -1,   628,    -1,   493,
      -1,   191,    -1,    11,    -1,    12,    -1,    20,    -1,   497,
      -1,   494,   495,    -1,   494,   154,   185,    -1,   494,   154,
     506,   185,    -1,   496,    -1,   495,   496,    -1,   152,   403,
     183,    -1,   498,    -1,   500,    -1,   501,    -1,   502,    -1,
     505,    -1,   507,    -1,   503,    -1,   504,    -1,   553,    -1,
     387,    -1,   499,    -1,   552,    -1,   108,    -1,   147,    -1,
     122,    -1,   116,   628,    -1,   154,   185,    -1,   154,   403,
     185,    -1,   117,    -1,   167,   151,   403,   182,    -1,   199,
     151,   403,   182,    -1,   629,   154,   185,    -1,   629,   154,
     506,   185,    -1,   404,    -1,   506,   105,   404,    -1,   508,
      -1,   526,    -1,   509,    -1,   523,    -1,   524,    -1,   155,
     628,   513,   128,    -1,   155,   628,   511,   513,   128,    -1,
     155,   628,   513,   194,   192,   628,   513,   194,    -1,   155,
     628,   513,   194,   510,   192,   628,   513,   194,    -1,   155,
     628,   511,   513,   194,   192,   628,   513,   194,    -1,   155,
     628,   511,   513,   194,   510,   192,   628,   513,   194,    -1,
     521,    -1,   510,   521,    -1,   512,    -1,   511,   512,    -1,
      35,   628,   513,   130,   513,   514,    -1,    -1,    35,    -1,
     181,   515,   181,    -1,    92,   517,    92,    -1,    -1,   516,
      -1,   132,    -1,   519,    -1,   516,   132,    -1,   516,   519,
      -1,    -1,   518,    -1,   131,    -1,   520,    -1,   518,   131,
      -1,   518,   520,    -1,    28,    -1,   522,    -1,     5,    -1,
     522,    -1,   508,    -1,    10,    -1,   525,    -1,   522,    -1,
       9,    -1,   121,    -1,   123,    -1,   151,   383,   182,    -1,
     210,    30,   211,    -1,   210,   211,    -1,   172,   627,   173,
      -1,   172,   627,     8,    -1,   101,     7,    -1,   527,    -1,
     528,    -1,   529,    -1,   530,    -1,   531,    -1,   532,    -1,
      43,   151,   382,   182,    -1,    21,   382,   182,    -1,    45,
     151,   403,   182,   151,   382,   182,    -1,    22,   382,   182,
      -1,    96,   151,   403,   182,   151,   382,   182,    -1,    70,
     151,   383,   182,    -1,    39,   151,   383,   182,    -1,    23,
     382,   182,    -1,    59,   151,   403,   182,   151,   382,   182,
      -1,   539,    -1,   539,   142,    -1,    93,   535,    -1,   537,
      -1,   537,   536,    -1,   208,   154,   185,    -1,   142,    -1,
     191,    -1,   174,    -1,   539,    -1,   540,    -1,   150,   154,
     185,    -1,   556,    -1,   559,    -1,   535,    -1,   538,   105,
     535,    -1,   628,    -1,   542,    -1,   548,    -1,   546,    -1,
     549,    -1,   547,    -1,   545,    -1,   544,    -1,   543,    -1,
     541,    -1,   222,   154,   185,    -1,    44,   154,   185,    -1,
      44,   154,   548,   185,    -1,    44,   154,   549,   185,    -1,
      70,   154,   185,    -1,    39,   154,   185,    -1,    59,   154,
     185,    -1,    59,   154,   627,   185,    -1,    59,   154,    29,
     185,    -1,    96,   154,   185,    -1,    96,   154,   628,   185,
      -1,    96,   154,   628,   105,   550,   185,    -1,    96,   154,
     191,   185,    -1,    96,   154,   191,   105,   550,   185,    -1,
      61,   154,   628,   185,    -1,    45,   154,   185,    -1,    45,
     154,   628,   185,    -1,    45,   154,   628,   105,   550,   185,
      -1,    45,   154,   628,   105,   551,   185,    -1,    45,   154,
     191,   185,    -1,    45,   154,   191,   105,   550,   185,    -1,
      45,   154,   191,   105,   551,   185,    -1,    62,   154,   628,
     185,    -1,   628,    -1,   628,   142,    -1,    29,    -1,   554,
      -1,   555,    -1,   628,   143,   147,    -1,    47,   368,   388,
      -1,   557,    -1,   558,    -1,    47,   154,   191,   185,    -1,
      47,   154,   185,    93,   535,    -1,    47,   154,   538,   185,
      93,   535,    -1,   154,   537,   185,    -1,    33,   217,   218,
      -1,    33,   217,   219,    -1,    33,   217,   220,    -1,   223,
     222,   404,   230,   404,    -1,   223,   222,   404,    93,   229,
     230,   404,    -1,   223,   222,   404,    93,   231,   230,   404,
      -1,   223,   222,   404,   215,   404,    -1,   223,   222,   404,
     216,   404,    -1,   223,   224,   404,   230,   404,    -1,   223,
     224,   404,    93,   229,   230,   404,    -1,   223,   224,   404,
      93,   231,   230,   404,    -1,   223,   224,   404,   215,   404,
      -1,   223,   224,   404,   216,   404,    -1,   221,   222,   404,
      -1,   221,   224,   404,    -1,   226,   222,   404,   234,   404,
      -1,   226,   227,   228,   222,   404,   234,   404,    -1,   225,
     222,   404,    93,   404,    -1,   233,   116,   566,   232,   404,
     184,   404,    -1,   567,    -1,   566,   105,   116,   567,    -1,
     628,   140,   404,    -1,   242,   151,   403,   182,   569,    -1,
     570,    -1,   569,   570,    -1,   243,   572,   571,    -1,   243,
     572,   154,   116,   628,   185,   571,    -1,   243,   572,   154,
     116,   628,   105,   116,   628,   185,   571,    -1,   243,   572,
     154,   116,   628,   105,   116,   628,   105,   116,   628,   185,
     571,    -1,   151,   403,   182,    -1,   492,    -1,   572,   207,
     492,    -1,   576,   574,    -1,    -1,   575,    -1,   594,    -1,
     575,   594,    -1,   577,    -1,   576,   260,   577,    -1,   578,
      -1,   577,   256,   578,    -1,   579,    -1,   578,   258,   145,
     579,    -1,   580,    -1,   257,   580,    -1,   584,   581,   582,
      -1,    -1,   599,    -1,    -1,   583,    -1,   280,   151,   403,
     182,    -1,   588,   585,    -1,   154,   573,   185,    -1,   586,
      -1,    -1,   621,    -1,   479,   151,   587,   182,    -1,    -1,
     573,    -1,   589,   590,    -1,   498,    -1,   151,   403,   182,
      -1,    -1,   591,    -1,   246,   592,    -1,   245,   593,    -1,
     268,    -1,    -1,    77,    -1,    -1,   284,    -1,   595,    -1,
     596,    -1,   597,    -1,   623,    -1,   620,    -1,   167,    -1,
     282,   464,   598,    -1,   251,   622,   598,    -1,   284,    -1,
     274,    -1,   267,    -1,   244,   600,    -1,   599,   244,   600,
      -1,   601,    -1,   602,    -1,   603,    -1,   618,    -1,   604,
      -1,   612,    -1,   605,    -1,   619,    -1,    98,   272,    -1,
      98,   261,    -1,   264,    -1,   279,    -1,   249,   272,    -1,
     249,   261,    -1,    56,   628,    29,    -1,   275,    -1,    54,
     275,    -1,   277,   606,    -1,   277,   154,   606,   607,   185,
      -1,    54,   277,    -1,   609,    -1,   111,    -1,    -1,   105,
     608,    -1,   609,    -1,   608,   105,   609,    -1,    95,    29,
     610,   611,    -1,    -1,   269,    29,    -1,    -1,   622,   263,
      -1,   276,   284,   613,   615,    -1,   276,   284,   111,   615,
      -1,    54,   276,   284,    -1,    95,    29,    -1,   154,   614,
     185,    -1,    29,    -1,   614,   105,    29,    -1,    -1,   616,
      -1,   617,    -1,   616,   617,    -1,   198,   613,    -1,   134,
     613,    -1,   262,    29,    -1,   281,    -1,    54,   281,    -1,
      95,   214,    -1,    95,   252,    -1,   253,   248,    -1,   265,
     622,   278,    -1,   254,   464,    -1,    95,   127,   464,    -1,
      95,    52,   464,    -1,   255,   464,   196,   464,    -1,   270,
     624,    -1,   250,   624,    -1,   273,    -1,   266,    -1,   283,
     248,   466,    -1,    29,    -1,    16,    -1,   628,    -1,   629,
      -1,    96,    -1,    39,    -1,    44,    -1,    45,    -1,   150,
      -1,    48,    -1,   222,    -1,    59,    -1,    61,    -1,    62,
      -1,    70,    -1,    73,    -1,    72,    -1,   208,    -1,   241,
      -1,   630,    -1,    24,    -1,   212,    -1,   125,    -1,    38,
      -1,   259,    -1,    37,    -1,   219,    -1,   218,    -1,   144,
      -1,    43,    -1,   257,    -1,   258,    -1,   272,    -1,   261,
      -1,   249,    -1,   283,    -1,   275,    -1,   277,    -1,   276,
      -1,   281,    -1,   253,    -1,   248,    -1,    77,    -1,   214,
      -1,   252,    -1,    52,    -1,   220,    -1,   233,    -1,   300,
      -1,   227,    -1,   200,    -1,   205,    -1,   204,    -1,   203,
      -1,   202,    -1,   201,    -1,    95,    -1,   109,    -1,   110,
      -1,   184,    -1,    46,    -1,    36,    -1,    66,    -1,    71,
      -1,    58,    -1,    53,    -1,    55,    -1,    76,    -1,    42,
      -1,   145,    -1,    51,    -1,   209,    -1,   168,    -1,   169,
      -1,   166,    -1,    69,    -1,    94,    -1,   114,    -1,   126,
      -1,   127,    -1,   104,    -1,    67,    -1,   133,    -1,   186,
      -1,    98,    -1,    93,    -1,   195,    -1,   124,    -1,   165,
      -1,    91,    -1,    50,    -1,   228,    -1,    99,    -1,   196,
      -1,   115,    -1,   157,    -1,   198,    -1,   148,    -1,   134,
      -1,    75,    -1,   100,    -1,   197,    -1,   149,    -1,   180,
      -1,   193,    -1,   158,    -1,   135,    -1,   129,    -1,   164,
      -1,   146,    -1,   163,    -1,    33,    -1,    40,    -1,    57,
      -1,   111,    -1,    41,    -1,    56,    -1,   213,    -1,    49,
      -1,    60,    -1,    34,    -1,    47,    -1,   271,    -1,   247,
      -1,   280,    -1,   282,    -1,   251,    -1,   265,    -1,   278,
      -1,   270,    -1,   250,    -1,   264,    -1,   279,    -1,   269,
      -1,   263,    -1,   262,    -1,   246,    -1,   245,    -1,   254,
      -1,   255,    -1,   284,    -1,   274,    -1,   273,    -1,   268,
      -1,   266,    -1,   267,    -1,   226,    -1,   232,    -1,   229,
      -1,   223,    -1,   216,    -1,   215,    -1,   217,    -1,   234,
      -1,   224,    -1,   225,    -1,   231,    -1,   221,    -1,   230,
      -1,    65,    -1,    63,    -1,    74,    -1,   167,    -1,   199,
      -1,   240,    -1,   235,    -1,   238,    -1,   239,    -1,   236,
      -1,   237,    -1,   242,    -1,   243,    -1,   244,    -1,    64,
      -1,   293,    -1,   291,    -1,   292,    -1,   297,    -1,   298,
      -1,   299,    -1,   294,    -1,   295,    -1,   296,    -1,    78,
      -1,    79,    -1,    80,    -1,    81,    -1,    82,    -1,    83,
      -1,    84,    -1,    85,    -1,    86,    -1,    87,    -1,    88,
      -1,   285,    -1,   286,    -1,   287,    -1,   288,    -1,   289,
      -1,   290,    -1,   301,    -1,   302,    -1,   303,    -1,   304,
      -1,   305,    -1,   306,    -1,   307,    -1,    89,    -1,   103,
      -1,   112,    -1,   170,    -1,   178,    -1,   187,    -1,   136,
      -1,    90,    -1,   113,    -1,   137,    -1,   179,    -1,   626,
     119,   627,    -1,    25,    -1
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
    1703,  1705,  1707,  1709,  1711,  1713,  1715,  1717,  1719,  1721,
    1724,  1728,  1733,  1735,  1738,  1742,  1744,  1746,  1748,  1750,
    1752,  1754,  1756,  1758,  1760,  1762,  1764,  1766,  1768,  1770,
    1772,  1775,  1778,  1782,  1784,  1789,  1794,  1798,  1803,  1805,
    1809,  1811,  1813,  1815,  1817,  1819,  1824,  1830,  1839,  1849,
    1859,  1870,  1872,  1875,  1877,  1880,  1887,  1888,  1890,  1894,
    1898,  1899,  1901,  1903,  1905,  1908,  1911,  1912,  1914,  1916,
    1918,  1921,  1924,  1926,  1928,  1930,  1932,  1934,  1936,  1938,
    1940,  1942,  1944,  1946,  1950,  1954,  1957,  1961,  1965,  1968,
    1970,  1972,  1974,  1976,  1978,  1980,  1985,  1989,  1997,  2001,
    2009,  2014,  2019,  2023,  2031,  2033,  2036,  2039,  2041,  2044,
    2048,  2050,  2052,  2054,  2056,  2058,  2062,  2064,  2066,  2068,
    2072,  2074,  2076,  2078,  2080,  2082,  2084,  2086,  2088,  2090,
    2092,  2096,  2100,  2105,  2110,  2114,  2118,  2122,  2127,  2132,
    2136,  2141,  2148,  2153,  2160,  2165,  2169,  2174,  2181,  2188,
    2193,  2200,  2207,  2212,  2214,  2217,  2219,  2221,  2223,  2227,
    2231,  2233,  2235,  2240,  2246,  2253,  2257,  2261,  2265,  2269,
    2275,  2283,  2291,  2297,  2303,  2309,  2317,  2325,  2331,  2337,
    2341,  2345,  2351,  2359,  2365,  2373,  2375,  2380,  2384,  2390,
    2392,  2395,  2399,  2407,  2418,  2432,  2436,  2438,  2442,  2445,
    2446,  2448,  2450,  2453,  2455,  2459,  2461,  2465,  2467,  2472,
    2474,  2477,  2481,  2482,  2484,  2485,  2487,  2492,  2495,  2499,
    2501,  2502,  2504,  2509,  2510,  2512,  2515,  2517,  2521,  2522,
    2524,  2527,  2530,  2532,  2533,  2535,  2536,  2538,  2540,  2542,
    2544,  2546,  2548,  2550,  2554,  2558,  2560,  2562,  2564,  2567,
    2571,  2573,  2575,  2577,  2579,  2581,  2583,  2585,  2587,  2590,
    2593,  2595,  2597,  2600,  2603,  2607,  2609,  2612,  2615,  2621,
    2624,  2626,  2628,  2629,  2632,  2634,  2638,  2643,  2644,  2647,
    2648,  2651,  2656,  2661,  2665,  2668,  2672,  2674,  2678,  2679,
    2681,  2683,  2686,  2689,  2692,  2695,  2697,  2700,  2703,  2706,
    2709,  2713,  2716,  2720,  2724,  2729,  2732,  2735,  2737,  2739,
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
         0,  1022,  1022,  1023,  1032,  1041,  1047,  1055,  1061,  1072,
    1077,  1085,  1092,  1099,  1108,  1115,  1123,  1131,  1139,  1150,
    1155,  1162,  1169,  1181,  1191,  1198,  1205,  1217,  1218,  1219,
    1220,  1221,  1226,  1227,  1228,  1229,  1230,  1231,  1232,  1235,
    1240,  1245,  1253,  1261,  1269,  1274,  1282,  1287,  1295,  1300,
    1308,  1315,  1322,  1329,  1339,  1341,  1344,  1354,  1359,  1367,
    1375,  1386,  1393,  1404,  1409,  1417,  1424,  1431,  1440,  1453,
    1461,  1468,  1478,  1485,  1492,  1503,  1504,  1505,  1506,  1507,
    1508,  1509,  1510,  1515,  1521,  1530,  1537,  1547,  1557,  1558,
    1559,  1560,  1561,  1562,  1563,  1564,  1565,  1566,  1571,  1579,
    1587,  1595,  1602,  1610,  1617,  1622,  1630,  1638,  1653,  1668,
    1686,  1691,  1699,  1707,  1718,  1723,  1732,  1737,  1744,  1749,
    1759,  1764,  1773,  1779,  1792,  1797,  1805,  1816,  1831,  1843,
    1858,  1863,  1868,  1873,  1881,  1888,  1899,  1904,  1914,  1920,
    1930,  1934,  1940,  1944,  1948,  1952,  1958,  1964,  1970,  1976,
    1982,  1986,  1992,  1998,  2005,  2013,  2021,  2029,  2037,  2049,
    2063,  2077,  2094,  2098,  2107,  2111,  2118,  2126,  2144,  2150,
    2159,  2164,  2171,  2178,  2189,  2199,  2209,  2219,  2237,  2257,
    2262,  2267,  2274,  2279,  2284,  2291,  2296,  2308,  2315,  2327,
    2328,  2329,  2330,  2331,  2332,  2333,  2335,  2336,  2337,  2338,
    2339,  2344,  2349,  2357,  2374,  2382,  2390,  2397,  2404,  2411,
    2418,  2428,  2440,  2453,  2465,  2481,  2489,  2497,  2505,  2520,
    2525,  2533,  2547,  2564,  2589,  2597,  2604,  2615,  2621,  2627,
    2638,  2653,  2658,  2673,  2674,  2675,  2676,  2677,  2678,  2683,
    2684,  2687,  2688,  2689,  2690,  2691,  2696,  2710,  2718,  2723,
    2731,  2736,  2741,  2749,  2758,  2770,  2780,  2793,  2801,  2802,
    2803,  2808,  2809,  2810,  2811,  2812,  2817,  2824,  2834,  2842,
    2849,  2859,  2869,  2879,  2889,  2899,  2909,  2919,  2929,  2940,
    2949,  2959,  2969,  2985,  2994,  3003,  3011,  3017,  3029,  3037,
    3047,  3055,  3067,  3073,  3084,  3086,  3090,  3098,  3102,  3107,
    3111,  3115,  3119,  3129,  3137,  3144,  3150,  3161,  3165,  3174,
    3182,  3188,  3198,  3204,  3214,  3218,  3228,  3234,  3240,  3246,
    3255,  3264,  3273,  3286,  3290,  3298,  3304,  3314,  3322,  3331,
    3344,  3351,  3363,  3367,  3379,  3386,  3392,  3401,  3408,  3414,
    3425,  3432,  3438,  3447,  3456,  3463,  3474,  3481,  3493,  3499,
    3511,  3517,  3528,  3534,  3545,  3551,  3562,  3571,  3575,  3584,
    3588,  3596,  3600,  3610,  3617,  3626,  3636,  3635,  3649,  3658,
    3667,  3680,  3684,  3697,  3700,  3707,  3711,  3720,  3724,  3728,
    3737,  3741,  3747,  3753,  3759,  3770,  3774,  3778,  3786,  3790,
    3796,  3806,  3810,  3820,  3824,  3834,  3838,  3848,  3852,  3862,
    3866,  3874,  3878,  3882,  3886,  3896,  3900,  3904,  3912,  3916,
    3920,  3924,  3928,  3932,  3940,  3944,  3948,  3956,  3960,  3964,
    3968,  3979,  3985,  3995,  4001,  4011,  4015,  4019,  4057,  4061,
    4071,  4081,  4094,  4103,  4113,  4117,  4126,  4130,  4139,  4145,
    4153,  4159,  4171,  4177,  4187,  4191,  4195,  4199,  4203,  4209,
    4215,  4223,  4227,  4235,  4239,  4250,  4254,  4258,  4264,  4268,
    4282,  4286,  4294,  4298,  4308,  4312,  4316,  4320,  4329,  4333,
    4337,  4341,  4349,  4355,  4365,  4373,  4377,  4381,  4385,  4389,
    4393,  4397,  4401,  4405,  4415,  4423,  4427,  4435,  4442,  4449,
    4460,  4468,  4472,  4480,  4488,  4496,  4550,  4554,  4567,  4573,
    4583,  4587,  4595,  4599,  4603,  4611,  4621,  4631,  4641,  4651,
    4661,  4676,  4682,  4693,  4699,  4710,  4721,  4723,  4727,  4732,
    4742,  4745,  4752,  4758,  4764,  4772,  4785,  4788,  4795,  4801,
    4807,  4814,  4825,  4829,  4839,  4843,  4853,  4857,  4861,  4866,
    4875,  4881,  4887,  4893,  4901,  4906,  4914,  4919,  4927,  4935,
    4940,  4945,  4950,  4955,  4960,  4969,  4977,  4981,  4998,  5002,
    5010,  5018,  5026,  5030,  5038,  5044,  5054,  5062,  5066,  5070,
    5105,  5111,  5117,  5127,  5131,  5135,  5139,  5143,  5150,  5156,
    5166,  5174,  5178,  5182,  5186,  5190,  5194,  5198,  5202,  5206,
    5214,  5222,  5226,  5230,  5240,  5248,  5256,  5260,  5264,  5272,
    5276,  5282,  5288,  5292,  5302,  5310,  5314,  5320,  5329,  5338,
    5344,  5350,  5360,  5377,  5384,  5399,  5435,  5439,  5447,  5455,
    5467,  5471,  5479,  5487,  5491,  5502,  5519,  5525,  5531,  5541,
    5545,  5551,  5557,  5561,  5567,  5571,  5577,  5583,  5590,  5600,
    5605,  5613,  5619,  5629,  5651,  5660,  5666,  5679,  5693,  5700,
    5706,  5716,  5721,  5726,  5736,  5750,  5758,  5764,  5782,  5791,
    5794,  5801,  5806,  5814,  5818,  5825,  5829,  5836,  5840,  5847,
    5851,  5860,  5873,  5876,  5884,  5887,  5895,  5903,  5911,  5915,
    5923,  5926,  5934,  5946,  5949,  5957,  5969,  5975,  5985,  5988,
    5996,  6000,  6004,  6012,  6015,  6023,  6026,  6034,  6038,  6042,
    6046,  6050,  6058,  6066,  6078,  6090,  6094,  6098,  6106,  6112,
    6122,  6126,  6130,  6134,  6138,  6142,  6146,  6150,  6158,  6162,
    6166,  6170,  6178,  6184,  6194,  6204,  6208,  6216,  6226,  6237,
    6244,  6248,  6256,  6259,  6266,  6271,  6280,  6290,  6293,  6301,
    6304,  6312,  6321,  6328,  6338,  6342,  6349,  6355,  6365,  6368,
    6375,  6380,  6392,  6400,  6412,  6420,  6424,  6432,  6436,  6440,
    6448,  6456,  6460,  6464,  6468,  6476,  6484,  6496,  6500,  6508,
    6521,  6525,  6526,  6539,  6540,  6541,  6542,  6543,  6544,  6545,
    6546,  6547,  6548,  6549,  6550,  6551,  6552,  6553,  6554,  6558,
    6559,  6560,  6561,  6562,  6563,  6564,  6565,  6566,  6567,  6568,
    6569,  6570,  6571,  6572,  6573,  6574,  6575,  6576,  6577,  6578,
    6579,  6580,  6581,  6582,  6583,  6584,  6585,  6586,  6587,  6588,
    6589,  6590,  6591,  6592,  6593,  6594,  6595,  6596,  6597,  6598,
    6599,  6600,  6601,  6602,  6603,  6604,  6605,  6606,  6607,  6608,
    6609,  6610,  6611,  6612,  6613,  6614,  6615,  6616,  6617,  6618,
    6619,  6620,  6621,  6622,  6623,  6624,  6625,  6626,  6627,  6628,
    6629,  6630,  6631,  6632,  6633,  6634,  6635,  6636,  6637,  6638,
    6639,  6640,  6641,  6642,  6643,  6644,  6645,  6646,  6647,  6648,
    6649,  6650,  6651,  6652,  6653,  6654,  6655,  6656,  6657,  6658,
    6659,  6660,  6661,  6662,  6663,  6664,  6665,  6666,  6667,  6668,
    6669,  6670,  6671,  6672,  6673,  6674,  6675,  6676,  6677,  6678,
    6679,  6680,  6681,  6682,  6683,  6684,  6685,  6686,  6687,  6688,
    6689,  6690,  6691,  6692,  6693,  6694,  6695,  6696,  6697,  6698,
    6699,  6700,  6701,  6702,  6703,  6704,  6705,  6706,  6707,  6708,
    6709,  6710,  6711,  6712,  6713,  6714,  6715,  6716,  6717,  6718,
    6719,  6720,  6721,  6722,  6723,  6724,  6725,  6726,  6727,  6728,
    6729,  6730,  6731,  6732,  6733,  6734,  6735,  6736,  6737,  6738,
    6739,  6740,  6741,  6742,  6743,  6744,  6745,  6746,  6747,  6748,
    6749,  6750,  6751,  6752,  6753,  6754,  6755,  6756,  6761,  6768
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
  const int xquery_parser::yylast_ = 13478;
  const int xquery_parser::yynnts_ = 309;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 587;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 322;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 576;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 16579 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6772 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"


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

