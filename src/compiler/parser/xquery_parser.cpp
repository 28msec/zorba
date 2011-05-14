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
#line 72 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"


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
#line 78 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 317 of lalr1.cc  */
#line 976 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"

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
#line 151 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"

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
#line 217 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
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
        case 107: /* "\"'DECIMAL'\"" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 324 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 121: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 333 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 146: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 342 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 351 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 360 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 369 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 378 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 387 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 396 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 405 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 414 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 423 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 432 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 441 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 450 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 459 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 468 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 477 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 486 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 495 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 504 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 513 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 522 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 531 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 540 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 549 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 558 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 897 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 567 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 897 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 576 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 585 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 594 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 603 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 612 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 621 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 630 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 639 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 897 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 648 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 657 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 666 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 675 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 684 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 693 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 702 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 711 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 897 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 720 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 729 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 738 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "DeclPropertyList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 747 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "DeclProperty" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 756 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 765 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "NodeModifier" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 774 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 783 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 792 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 828 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 837 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 846 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "WhileExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 855 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 882 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 900 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 909 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 918 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 927 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 936 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 945 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 954 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 963 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 972 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 981 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 990 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 999 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1008 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1017 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1026 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1035 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1044 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1053 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1062 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1071 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1080 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1089 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1098 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1107 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1116 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1125 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1134 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1143 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1152 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1161 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1170 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1179 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1188 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1197 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1206 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1215 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1224 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1233 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1242 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1251 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1260 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1269 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1278 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1287 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1296 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1305 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1314 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1323 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1332 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1341 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1350 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1359 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1368 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1377 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1386 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1395 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1404 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1413 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1422 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1431 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1440 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1449 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1458 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1467 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1476 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1485 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1494 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1503 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1512 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1521 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1530 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1539 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1548 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1557 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1566 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1575 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1584 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1593 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1602 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1611 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1620 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1629 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1638 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1647 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1656 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1665 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1674 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1683 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1692 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1701 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1710 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1719 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1728 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1737 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1746 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1755 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1764 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1773 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1782 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1791 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1800 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1809 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1818 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1827 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1836 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1845 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1854 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1863 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1872 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1881 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1890 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1899 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1908 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1917 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1926 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1935 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1944 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1953 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1962 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1971 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1980 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1989 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1998 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2007 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2016 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2025 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2034 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2043 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2052 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2061 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2070 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2079 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2088 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2097 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2106 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2115 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2124 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2133 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2142 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2151 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2160 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2169 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2178 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2187 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2196 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2205 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2214 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2223 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2232 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2241 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2250 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2259 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2268 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2277 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2286 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2295 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2304 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2313 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2322 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2331 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2340 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2349 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2358 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2367 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 897 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2376 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2385 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2394 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2403 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2412 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2421 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2430 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2439 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2448 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2457 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2466 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2475 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2484 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2493 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2502 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2511 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2520 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2529 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2538 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2547 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2556 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2565 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2574 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2583 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2592 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2601 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2610 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2619 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 610: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2628 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 611: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2637 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 615: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2646 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 616: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2655 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 617: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2664 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 618: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2673 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 619: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2682 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2691 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 621: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2700 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 622: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2709 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 623: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2718 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 626: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2727 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 627: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2736 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 628: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2745 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
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
#line 125 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 553 of lalr1.cc  */
#line 2830 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"

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
#line 1037 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 1046 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 1055 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        driver.set_expr( (yyval.node) );
      }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 1060 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
        MainModule *mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
        mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        driver.set_expr( (yyval.node) );
      }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 1067 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        driver.set_expr( (yyval.node) );
      }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 1072 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
        LibraryModule *lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
        lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        driver.set_expr( (yyval.node) );
      }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 1083 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
      }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 1087 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
      }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 1094 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
        Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);
        (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
      }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1099 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
        Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));
        (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
      }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1104 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
        Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)), static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));
        (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
      }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 1109 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
      }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1114 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
        (yylocation_stack_[(3) - (1)]).step();
        error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
        YYERROR;
      }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1121 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
        (yylocation_stack_[(3) - (1)]).step();
        error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
        YYERROR;
      }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1128 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
        (yylocation_stack_[(5) - (3)]).step();
        error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
        YYERROR;
      }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1135 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
        (yylocation_stack_[(5) - (1)]).step();
        error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
        YYERROR;
      }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1146 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
      }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1150 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
        Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

        (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
      }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1156 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
        Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

        (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
      }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 1162 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
        Prolog* prolog = new Prolog(LOC((yyloc)),
                                    static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                    static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

        (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
      }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 1174 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

        dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
      }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 1184 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
        SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
        sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
        (yyval.node) = sdl;
      }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 1190 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
        ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
        (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
      }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 1196 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1231 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
      }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1235 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
      }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1243 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
      }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1251 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
      }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1259 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
      }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1263 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
      }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1271 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1276 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1284 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1289 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1297 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1304 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1311 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 1318 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 1333 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 1343 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 1348 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 1356 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1364 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1375 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1382 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1393 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1398 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1406 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1413 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1420 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1429 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1442 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1450 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1457 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1467 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1474 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1481 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1504 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1510 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1519 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1526 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1536 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1545 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1546 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1547 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1548 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1549 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1550 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1551 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1552 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1553 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1554 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1560 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1568 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1576 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1584 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1591 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1599 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1606 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1611 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1619 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1627 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1642 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1657 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1755 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1760 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1768 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1776 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1787 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1792 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1801 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1806 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1816 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1821 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1830 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1836 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1849 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1854 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1862 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 125:

/* Line 678 of lalr1.cc  */
#line 1873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 126:

/* Line 678 of lalr1.cc  */
#line 1888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 127:

/* Line 678 of lalr1.cc  */
#line 1900 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 128:

/* Line 678 of lalr1.cc  */
#line 1915 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1920 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1925 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1930 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1938 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1945 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1956 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1961 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1971 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      DeclPropertyList *dpl = new DeclPropertyList( LOC((yyloc)) );
      dpl->addProperty(dynamic_cast<DeclProperty*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = dpl;
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1977 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      DeclPropertyList *dpl = dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(2) - (1)].node));
      dpl->addProperty( static_cast<DeclProperty*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1987 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_const );
        }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1991 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_append_only
            );
        }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1997 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_queue );
        }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 2001 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_mutable );
        }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 2005 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_ordered );
        }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 2009 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_unordered
            );
        }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 2015 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_equality
            );
        }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 2021 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_range
            );
        }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 2027 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_equality
            );
        }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 2033 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_range
            );
        }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 2039 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_unique );
        }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 2043 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_non_unique
            );
        }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 2049 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_automatic
            );
        }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 2055 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_manual );
        }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 2062 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL,
                              NULL);
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 2070 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              NULL,
                              static_cast<NodeModifier*>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 2078 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              NULL,
                              NULL,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 2086 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                              NULL,
                              static_cast<NodeModifier*>((yysemantic_stack_[(6) - (6)].node)),
                              static_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)));
    }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 2094 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 157:

/* Line 678 of lalr1.cc  */
#line 2106 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 158:

/* Line 678 of lalr1.cc  */
#line 2120 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 159:

/* Line 678 of lalr1.cc  */
#line 2134 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 160:

/* Line 678 of lalr1.cc  */
#line 2151 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 2155 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 2164 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 2168 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2175 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                             (yysemantic_stack_[(8) - (6)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                             NULL);
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 2183 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 166:

/* Line 678 of lalr1.cc  */
#line 2201 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 2207 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 2215 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 2220 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 2227 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 2234 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 2245 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 2255 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 2265 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 2276 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 176:

/* Line 678 of lalr1.cc  */
#line 2292 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 2299 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 2327 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList* vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
      vfo->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = vfo;
    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2333 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList* vfo = new VFO_DeclList( LOC((yyloc)) );
      vfo->push_back((yysemantic_stack_[(2) - (2)].node));
      (yyval.node) = vfo;
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2343 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 181:

/* Line 678 of lalr1.cc  */
#line 2355 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 182:

/* Line 678 of lalr1.cc  */
#line 2368 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 183:

/* Line 678 of lalr1.cc  */
#line 2380 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 184:

/* Line 678 of lalr1.cc  */
#line 2395 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
        }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 2402 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExitExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 2409 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            BlockBody *bb = dynamic_cast<BlockBody *>((yysemantic_stack_[(5) - (5)].expr));
            if (bb == NULL)
            {
                bb = new BlockBody((yysemantic_stack_[(5) - (5)].expr)->get_location());
                bb->add((yysemantic_stack_[(5) - (5)].expr));
            }
            (yyval.expr) = new WhileExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), bb );
        }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 2422 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::BREAK );
        }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 2426 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
        }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 2433 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 2441 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          if ((yysemantic_stack_[(1) - (1)].expr) == NULL)
          {
            error((yylocation_stack_[(1) - (1)]), "syntax error, unexpected end of file, the query should not be empty");
            YYERROR;
          }

          (yyval.expr) = new QueryBody( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
        }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 2454 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
         (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
       }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 2458 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
         (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
       }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 2462 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
         (yyval.expr) = NULL;
       }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 2469 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 2473 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            BlockBody* blk = dynamic_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));
            if (blk == NULL)
            {
              blk = new BlockBody( LOC((yyloc)) );
              blk->add((yysemantic_stack_[(2) - (1)].expr));
            }

            BlockBody* blk2 = dynamic_cast<BlockBody*>((yysemantic_stack_[(2) - (2)].expr));
            if (blk2 == NULL)
            {
              blk->add((yysemantic_stack_[(2) - (2)].expr));
            } else
            {
              rchandle<VFO_DeclList> newdecls = blk2->get_decls();
              rchandle<VFO_DeclList> olddecls = blk->get_decls();
              if (olddecls.getp() == NULL)
              {
                olddecls = new VFO_DeclList( LOC((yyloc)) );
                blk->set_decls(olddecls);
              }

              if (newdecls.getp() != NULL)
              {
                for (vector<rchandle<parsenode> >::iterator it = newdecls->begin(); it != newdecls->end(); ++it)
                {
                  olddecls->push_back(*it);
                }
                blk->set_decls(olddecls);
              }

              for (unsigned int i = 0; i < blk2->size(); ++i)
                blk->add( (*blk2)[i] );
              delete blk2;
            }
            (yyval.expr) = blk;
        }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 2514 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 2518 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            BlockBody* blk = dynamic_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));
            if (blk == NULL)
            {
              blk = new BlockBody( LOC((yyloc)) );
              blk->add((yysemantic_stack_[(2) - (1)].expr));
            }

            BlockBody* blk2 = dynamic_cast<BlockBody*>((yysemantic_stack_[(2) - (2)].expr));
            if(blk2 == NULL)
            {
              blk->add((yysemantic_stack_[(2) - (2)].expr));
            }
            else
            {
              rchandle<VFO_DeclList> newdecls = blk2->get_decls();
              rchandle<VFO_DeclList> olddecls = blk->get_decls();
              if (olddecls.getp() == NULL) {
                olddecls = new VFO_DeclList( LOC((yyloc)) );
                blk->set_decls(olddecls);
              }

              if (newdecls.getp() != NULL)
              {
                for (vector<rchandle<parsenode> >::iterator it = newdecls->begin(); it != newdecls->end(); ++it)
                {
                  olddecls->push_back(*it);
                }
                blk->set_decls(olddecls);
              }

              for (unsigned int i = 0; i < blk2->size(); ++i)
                blk->add( (*blk2)[i] );

              delete blk2;
            }
            (yyval.expr) = blk;
        }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 2575 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new ApplyExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
        }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 2582 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 2586 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new BlockBody( LOC((yyloc)) );
        }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 2593 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 214:

/* Line 678 of lalr1.cc  */
#line 2608 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 2615 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 2622 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 2629 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 2635 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 2645 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 2650 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 2655 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 222:

/* Line 678 of lalr1.cc  */
#line 2665 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 223:

/* Line 678 of lalr1.cc  */
#line 2678 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          BlockBody* blk = new BlockBody( LOC((yyloc)) );
          VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node));
          blk->set_decls(vfo);
          (yyval.expr) = blk;
        }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 2695 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 2699 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 239:

/* Line 678 of lalr1.cc  */
#line 2781 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 240:

/* Line 678 of lalr1.cc  */
#line 2796 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 2803 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_sliding;
        }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 2807 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_tumbling;
        }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 2814 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_start;
        }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 2818 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_end;
        }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 2822 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_only_end;
        }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2829 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)),
                dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr),
                (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 2837 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr),
                (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 2848 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 249:

/* Line 678 of lalr1.cc  */
#line 2858 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2871 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2900 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2910 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
        }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2918 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
            vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vdl;
        }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2924 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2936 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2940 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)), NULL, NULL, NULL, (yysemantic_stack_[(5) - (5)].expr), true);
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2944 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)), NULL, NULL, (yysemantic_stack_[(4) - (4)].expr), false);
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2948 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (2)].node)), NULL, NULL, (yysemantic_stack_[(6) - (6)].expr), true);
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2952 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)), NULL, dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)), NULL, (yysemantic_stack_[(4) - (4)].expr), false);
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2956 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)), NULL, dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (4)].node)), NULL, (yysemantic_stack_[(6) - (6)].expr), true);
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2960 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)), NULL, (yysemantic_stack_[(5) - (5)].expr), false);
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2965 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(7) - (1)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(7) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(7) - (5)].node)), NULL, (yysemantic_stack_[(7) - (7)].expr), true);
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2971 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2980 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 274:

/* Line 678 of lalr1.cc  */
#line 2990 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 275:

/* Line 678 of lalr1.cc  */
#line 3000 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 276:

/* Line 678 of lalr1.cc  */
#line 3016 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 3025 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 3034 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 3042 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 3048 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 3060 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 3068 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 3078 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 3086 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 3098 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 3104 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 3117 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 3121 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 3129 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 3133 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 3142 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 3146 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 3150 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 3160 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 3168 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 3175 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 3181 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 3192 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 3196 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3205 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3213 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3219 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3229 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3235 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3245 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3249 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3259 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3265 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3271 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3277 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3286 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3295 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3304 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3317 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3321 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3329 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3335 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3345 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3353 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3362 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3375 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3382 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3394 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3398 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3410 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3417 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3423 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3432 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3439 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3445 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3456 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3463 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3469 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3478 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3487 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3494 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3505 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3512 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3524 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3530 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3542 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3548 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3559 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3565 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3576 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3582 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3593 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3602 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3606 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3615 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3619 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3627 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3631 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 356:

/* Line 678 of lalr1.cc  */
#line 3641 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3648 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3657 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3666 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3671 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3680 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3689 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3698 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3711 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3715 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3727 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3731 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3738 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3742 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3751 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3755 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3759 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3768 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3772 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3778 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3784 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3790 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3801 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3805 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3809 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3817 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3821 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3827 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3837 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3841 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3851 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3855 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3865 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3869 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3893 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3897 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3905 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3909 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3913 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3917 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3927 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3931 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3935 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3943 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3947 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3951 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3955 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3959 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3963 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3971 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3975 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3979 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3987 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3991 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3995 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3999 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 4010 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 4016 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 4026 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 4032 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 4042 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 4046 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 4050 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 4088 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 4092 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 4102 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 4112 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 4125 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 4134 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 427:

/* Line 678 of lalr1.cc  */
#line 4144 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 4148 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 4157 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 4161 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 4170 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 4176 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 4184 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 4190 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 4202 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 4208 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 4218 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4222 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4226 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4230 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4234 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4240 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4246 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4254 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4258 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4266 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4270 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4281 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4285 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4289 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4295 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4299 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4313 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4317 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4325 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4329 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4339 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all);
    }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4343 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem);
    }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4347 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix);
    }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4356 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4360 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4364 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4368 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4376 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4382 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4392 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4400 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4404 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4408 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4412 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4416 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4420 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4424 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4428 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4432 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4442 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4450 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4454 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4462 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4469 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4476 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4487 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4495 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4499 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4507 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4515 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4523 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4577 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4581 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4594 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4600 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4610 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4614 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4622 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4626 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4630 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4638 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 498:

/* Line 678 of lalr1.cc  */
#line 4648 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 499:

/* Line 678 of lalr1.cc  */
#line 4658 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 500:

/* Line 678 of lalr1.cc  */
#line 4668 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 501:

/* Line 678 of lalr1.cc  */
#line 4678 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 502:

/* Line 678 of lalr1.cc  */
#line 4688 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 503:

/* Line 678 of lalr1.cc  */
#line 4703 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4709 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4720 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4726 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4737 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4754 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4759 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4768 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4772 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4779 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4785 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4791 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4799 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4811 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4815 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4822 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4828 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4834 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4841 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4852 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4856 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4866 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4870 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4884 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4893 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4902 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4908 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4914 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4920 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
        }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4928 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4932 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4944 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4948 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4960 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4972 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4976 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4980 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4984 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4988 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4992 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 5000 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 5008 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 5012 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 5029 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 5033 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 5041 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 5049 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 5057 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 5061 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 5069 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 5075 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 5085 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 5093 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 5097 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 5101 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 5136 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 5142 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 5148 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 5158 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 5162 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 5166 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 5170 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 5174 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 5181 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 5187 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5197 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 5205 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 5209 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5213 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5217 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5221 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5225 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5229 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5233 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5237 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5245 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5253 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5257 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5261 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5271 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5279 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5287 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5291 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5295 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5303 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5307 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5313 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5319 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5323 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5333 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5341 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5345 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5351 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5360 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5369 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5375 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5381 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5391 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5408 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5415 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5430 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5466 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5470 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5478 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5486 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              new EnclosedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (3)].expr)));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5498 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5502 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5510 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5518 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5522 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5533 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5550 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5556 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5562 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5572 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5576 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5582 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5588 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5592 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5598 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5602 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5608 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5614 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5621 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5631 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5636 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5644 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5650 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5660 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5682 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5691 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5697 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5710 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5724 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5731 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5737 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5747 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5752 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5757 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 646:

/* Line 678 of lalr1.cc  */
#line 5767 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 647:

/* Line 678 of lalr1.cc  */
#line 5780 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5786 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5804 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5812 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5816 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5823 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5828 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5836 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5840 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5847 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5851 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5858 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5862 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5869 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5882 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5898 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5905 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5909 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5917 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5925 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5933 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5937 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5944 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5948 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5956 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5967 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5971 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5979 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5991 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5997 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 6006 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 6010 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 6018 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 6022 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 6026 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 6033 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 6037 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 6044 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 6048 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 6056 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 6060 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 6064 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 6068 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 6072 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 6080 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 6088 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 6100 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 6112 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 6116 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 6120 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 6128 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 6134 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 6144 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 6148 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 6152 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 6156 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 6160 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 6164 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 6168 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 6172 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 6180 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 6184 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 6188 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 6192 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 6200 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 6206 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 6216 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 6226 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 6230 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 6238 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 719:

/* Line 678 of lalr1.cc  */
#line 6248 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 720:

/* Line 678 of lalr1.cc  */
#line 6259 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 6266 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 6270 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 6277 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 6281 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 6288 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 6293 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 6302 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 6311 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 6315 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 6322 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 6326 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 6334 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 6343 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 6350 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 6360 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 6364 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 6371 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 6377 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 6386 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 6390 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 6397 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 6402 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 6414 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 6422 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 6434 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 6442 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 6446 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 6454 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 6458 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 6462 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 6470 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 6478 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 6482 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 6486 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 6490 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 6498 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 6506 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 6518 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 6522 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 6530 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 6548 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 765:

/* Line 678 of lalr1.cc  */
#line 6561 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 6562 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 6563 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 6564 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 6565 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 6566 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 6567 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 6568 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 6569 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 6570 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 6571 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 6572 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 6573 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 6574 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 6575 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 6580 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 6581 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 6582 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 6583 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 6584 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 6585 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 6586 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 6587 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 6588 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 6589 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 6590 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 6591 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 6592 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 6593 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 6594 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 6595 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 6596 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 6597 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 6598 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 6599 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 6600 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 6601 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 6602 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 6603 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 6604 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 6605 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 6606 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 6607 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 6608 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 6609 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 6610 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 6611 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 6612 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 6613 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 6614 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 6615 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 6616 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 6617 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 6618 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 6619 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 6620 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 6621 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 6622 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 6623 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 6624 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 6625 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 6626 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 6627 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 6628 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 6629 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 6630 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 6631 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 6632 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 6633 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 6634 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 6635 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 6636 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 6637 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 6638 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 6639 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 6640 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 6641 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 6642 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 6643 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 6644 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 6645 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 6646 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 6647 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 6648 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 6649 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 6650 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 6651 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 6652 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 6653 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 6654 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 6655 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 6656 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 6657 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 6658 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 6659 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 6660 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 6661 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 6662 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 6663 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 6664 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 6665 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 6666 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 6667 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 6668 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 6669 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 6670 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 6671 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 6672 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 6673 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 6674 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 6675 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 6676 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 6677 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 6678 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 6679 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 6680 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 6681 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 6682 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 6683 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 6684 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 6685 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 6686 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 6687 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 6688 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 6689 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 6690 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 6691 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 6692 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 6693 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6694 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 896:

/* Line 678 of lalr1.cc  */
#line 6695 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 897:

/* Line 678 of lalr1.cc  */
#line 6696 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 898:

/* Line 678 of lalr1.cc  */
#line 6697 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 899:

/* Line 678 of lalr1.cc  */
#line 6698 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 900:

/* Line 678 of lalr1.cc  */
#line 6699 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 901:

/* Line 678 of lalr1.cc  */
#line 6700 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 902:

/* Line 678 of lalr1.cc  */
#line 6701 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 903:

/* Line 678 of lalr1.cc  */
#line 6702 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 904:

/* Line 678 of lalr1.cc  */
#line 6703 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 905:

/* Line 678 of lalr1.cc  */
#line 6704 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 906:

/* Line 678 of lalr1.cc  */
#line 6705 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 907:

/* Line 678 of lalr1.cc  */
#line 6706 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 908:

/* Line 678 of lalr1.cc  */
#line 6707 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 909:

/* Line 678 of lalr1.cc  */
#line 6708 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 910:

/* Line 678 of lalr1.cc  */
#line 6709 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 911:

/* Line 678 of lalr1.cc  */
#line 6710 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 912:

/* Line 678 of lalr1.cc  */
#line 6711 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 913:

/* Line 678 of lalr1.cc  */
#line 6712 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 914:

/* Line 678 of lalr1.cc  */
#line 6713 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 915:

/* Line 678 of lalr1.cc  */
#line 6714 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 916:

/* Line 678 of lalr1.cc  */
#line 6715 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 917:

/* Line 678 of lalr1.cc  */
#line 6716 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 918:

/* Line 678 of lalr1.cc  */
#line 6717 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 919:

/* Line 678 of lalr1.cc  */
#line 6718 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 920:

/* Line 678 of lalr1.cc  */
#line 6719 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 921:

/* Line 678 of lalr1.cc  */
#line 6720 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 922:

/* Line 678 of lalr1.cc  */
#line 6721 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 923:

/* Line 678 of lalr1.cc  */
#line 6722 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 924:

/* Line 678 of lalr1.cc  */
#line 6723 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 925:

/* Line 678 of lalr1.cc  */
#line 6724 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("local"))); }
    break;

  case 926:

/* Line 678 of lalr1.cc  */
#line 6725 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 927:

/* Line 678 of lalr1.cc  */
#line 6726 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 928:

/* Line 678 of lalr1.cc  */
#line 6727 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 929:

/* Line 678 of lalr1.cc  */
#line 6728 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 930:

/* Line 678 of lalr1.cc  */
#line 6729 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 931:

/* Line 678 of lalr1.cc  */
#line 6730 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 932:

/* Line 678 of lalr1.cc  */
#line 6731 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eval"))); }
    break;

  case 933:

/* Line 678 of lalr1.cc  */
#line 6732 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 934:

/* Line 678 of lalr1.cc  */
#line 6733 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 935:

/* Line 678 of lalr1.cc  */
#line 6734 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 936:

/* Line 678 of lalr1.cc  */
#line 6735 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 937:

/* Line 678 of lalr1.cc  */
#line 6736 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 938:

/* Line 678 of lalr1.cc  */
#line 6737 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 939:

/* Line 678 of lalr1.cc  */
#line 6738 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 940:

/* Line 678 of lalr1.cc  */
#line 6739 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 941:

/* Line 678 of lalr1.cc  */
#line 6740 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 942:

/* Line 678 of lalr1.cc  */
#line 6741 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 943:

/* Line 678 of lalr1.cc  */
#line 6742 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 944:

/* Line 678 of lalr1.cc  */
#line 6743 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 945:

/* Line 678 of lalr1.cc  */
#line 6744 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 946:

/* Line 678 of lalr1.cc  */
#line 6745 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 947:

/* Line 678 of lalr1.cc  */
#line 6746 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 948:

/* Line 678 of lalr1.cc  */
#line 6747 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 949:

/* Line 678 of lalr1.cc  */
#line 6748 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 950:

/* Line 678 of lalr1.cc  */
#line 6749 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 951:

/* Line 678 of lalr1.cc  */
#line 6750 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 952:

/* Line 678 of lalr1.cc  */
#line 6751 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 953:

/* Line 678 of lalr1.cc  */
#line 6752 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 954:

/* Line 678 of lalr1.cc  */
#line 6753 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 955:

/* Line 678 of lalr1.cc  */
#line 6754 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 956:

/* Line 678 of lalr1.cc  */
#line 6755 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 957:

/* Line 678 of lalr1.cc  */
#line 6756 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 958:

/* Line 678 of lalr1.cc  */
#line 6757 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 959:

/* Line 678 of lalr1.cc  */
#line 6758 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 960:

/* Line 678 of lalr1.cc  */
#line 6759 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 961:

/* Line 678 of lalr1.cc  */
#line 6760 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 962:

/* Line 678 of lalr1.cc  */
#line 6761 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 963:

/* Line 678 of lalr1.cc  */
#line 6762 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 964:

/* Line 678 of lalr1.cc  */
#line 6763 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 965:

/* Line 678 of lalr1.cc  */
#line 6764 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 966:

/* Line 678 of lalr1.cc  */
#line 6765 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 967:

/* Line 678 of lalr1.cc  */
#line 6766 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 968:

/* Line 678 of lalr1.cc  */
#line 6767 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 969:

/* Line 678 of lalr1.cc  */
#line 6768 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 970:

/* Line 678 of lalr1.cc  */
#line 6769 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 971:

/* Line 678 of lalr1.cc  */
#line 6770 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 972:

/* Line 678 of lalr1.cc  */
#line 6771 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 973:

/* Line 678 of lalr1.cc  */
#line 6772 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 974:

/* Line 678 of lalr1.cc  */
#line 6773 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 975:

/* Line 678 of lalr1.cc  */
#line 6774 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 976:

/* Line 678 of lalr1.cc  */
#line 6775 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 977:

/* Line 678 of lalr1.cc  */
#line 6776 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 978:

/* Line 678 of lalr1.cc  */
#line 6777 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 979:

/* Line 678 of lalr1.cc  */
#line 6783 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          // EQName's namespace URI value is whitespace normalized according to the rules for the xs:anyURI type
          std::string uri = "\"" + SYMTAB((yysemantic_stack_[(3) - (1)].sval)) + "\"";
          std::string eqname = SYMTAB(driver.symtab.put_uri(uri.c_str(), uri.size())) + ":" + SYMTAB((yysemantic_stack_[(3) - (3)].sval));
          (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT(eqname.c_str())), true);
        }
    break;

  case 980:

/* Line 678 of lalr1.cc  */
#line 6789 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 678 of lalr1.cc  */
#line 11820 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1609;
  const short int
  xquery_parser::yypact_[] =
  {
      2971, -1609, -1609,  5044,  5044,  5044, -1609, -1609,     9,  1712,
      -1, -1609, -1609, -1609,   672, -1609, -1609, -1609,    71,   168,
     693, -1609,   635,   424,   519,   643, -1609,    16, -1609, -1609,
   -1609, -1609, -1609, -1609,   703, -1609,   554,   580, -1609, -1609,
   -1609, -1609,   236, -1609,   705, -1609,   619,   634, -1609,   249,
   -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609,
   -1609, -1609, -1609,   285,   331, -1609, -1609, -1609, -1609,   456,
    8300, -1609, -1609, -1609,   429, -1609, -1609, -1609,   401, -1609,
     566,   683, -1609, -1609, 12026, -1609, -1609, -1609, -1609, -1609,
   -1609, -1609, -1609,   723, -1609, -1609,   732,   746, -1609, -1609,
   -1609, -1609, -1609, -1609, -1609,  3268,  3564, 12026, -1609, -1609,
   -1609, -1609, -1609, -1609, -1609,   718, -1609, -1609,   754,  9180,
   -1609,  9470,   762,   764, -1609, -1609, -1609,   766, -1609,  8004,
   -1609, -1609, -1609, -1609, -1609, -1609,   744, -1609, -1609, -1609,
   -1609, -1609, -1609, -1609, -1609,    52,   684, -1609, -1609, -1609,
   -1609, -1609, -1609, -1609, -1609,   591,   747,   600, -1609,   696,
     485, -1609, -1609, -1609, -1609, -1609, -1609,   806, -1609, -1609,
     688,   689,   690, -1609, -1609,   775,   785, -1609, -1609, -1609,
   -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609,
   -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609,
   -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609,
   -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609,
   -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609,
   -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609,  5340,
     932, -1609,  5636, -1609, -1609,    99,    54, -1609, -1609, -1609,
   -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609,
   -1609,    73, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609,
   -1609, -1609, -1609,    -4, -1609, -1609, -1609, -1609, -1609, -1609,
   -1609, -1609,  5044, -1609, -1609, -1609, -1609, -1609, -1609,   830,
   -1609,   751, -1609, -1609, -1609,   593, -1609, -1609, -1609, -1609,
   -1609, -1609, -1609, -1609,   772,   847, -1609,   832,   694,   541,
     499,   507,   450, -1609,   890,   745,   844,   849,  5932, -1609,
   -1609, -1609,   363, -1609, -1609,  8004, -1609,   702, -1609,   792,
    8300, -1609,   792,  8300, -1609, -1609, -1609,   725, -1609, -1609,
   -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609,
   -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609,
   -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609,
   -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609,
     828,   809,   799, -1609, -1609, -1609, -1609, -1609,   774,   776,
     778,   800,   927,   -29,   179,   468, 12310, 12026,   -37,   914,
   12026,   813,   848,    64,  9180, -1609, -1609,   653,  -138,   721,
   12026, -1609, -1609, -1609, -1609, -1609,   675, 12026,   671,   673,
     595,   674,   598,   103, -1609, -1609, -1609, -1609,   784, -1609,
    9180,  5044,   783,  5044,    51,  6228, 10038,   692,   697, 12026,
     856,   248,   824,  6228,   976,   137,   144, 12026,   868,   846,
     883, -1609,  6228,  8888, 12026, 12026, 12026,  5044,   804,  6228,
    6228, 12026,  5044,   839,   840, -1609, -1609, -1609,  6228, 10322,
   -1609,   841, -1609,   842, -1609, -1609, -1609, -1609,   843, -1609,
     845, -1609, -1609, -1609, -1609, -1609,   850, -1609, -1609, -1609,
   -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609,
   -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609,
   -1609, -1609, -1609, -1609, 12026, -1609, -1609, -1609, -1609, -1609,
   -1609, -1609, -1609, -1609, -1609, -1609, -1609,   853, 12026, -1609,
   -1609, -1609,   818,   820,   851,   854,   858, 12026,  5044, -1609,
     852,    36, -1609,   748,   979,  6228, -1609, -1609,    58, -1609,
   -1609, -1609,   993, -1609, -1609, -1609, -1609,  6228,   803, -1609,
     987,  6228,  6228,   833,  6228,  6228,  6228,  6228,   793, 12026,
     834,   835,  6228,  6228,  3268,   777, -1609, -1609, -1609, -1609,
    1712,   643,    84,    90,  1020,  6524,  6524,  6820,  6820,   401,
   -1609, -1609, -1609,  6228, -1609,   910,   635,    16,   864,   870,
     871,  5044,  6228, -1609, -1609, -1609, -1609, -1609, -1609, -1609,
   -1609,  7116,  7116,  7116, -1609,  7116,  7116, -1609,  7116, -1609,
    7116, -1609, -1609, -1609, -1609, -1609, -1609, -1609,  7116,  7116,
     971,  7116,  7116,  7116,  7116,  7116,  7116,  7116,  7116,  7116,
    7116,  7116,   814,   950,   951,   952, -1609, -1609, -1609,  3860,
   -1609, -1609,  8004,  8004,  6228,   792, -1609, -1609,   792, -1609,
    4156,   792,  9180,   900,  4452, -1609, -1609, -1609,    79, -1609,
   -1609, -1609, -1609, -1609,   943,   944,   424,  1023, -1609, -1609,
   12310,   749,   620, 12026,   894,   895,   749,   927,   929,   928,
   -1609, -1609, -1609, -1609, -1609,   280,   815,     3, -1609,   767,
   -1609, -1609, -1609, -1609, 12026,   920,  6228,   949, -1609, -1609,
   12026, 12026, -1609,   936,   885,  5044, -1609,   886,   842,   580,
   -1609,   889,   901,    28, -1609,    40,    47, -1609, -1609,   975,
   -1609,    25, 12026,    15, 12026,   992,   201, -1609,  5044, -1609,
     251, -1609,  9180,   994,  1043,  9180,   927,   995,   240, 12026,
    6228,    16,    38,   903, -1609,   906,   907,   908,    29, -1609,
      66,   912, -1609,   256,   258,   945, -1609,   913,  5044,  5044,
      42, -1609,   276,   290,   459,  6228,    32, -1609, -1609,  6228,
    6228,  6228, -1609,  6228, -1609,  6228, 12026,   979, -1609,   -13,
     211, -1609, -1609, -1609,   227, -1609,   347, -1609, -1609, -1609,
     198,   205,  1004,   865,   876,    86, -1609,   960, -1609, -1609,
     915,   296,   820,  7412,   260,  8596,   777, -1609,    99,   430,
    1070,  1070, -1609, -1609,    92, -1609, -1609,    96, -1609,   972,
   -1609, -1609, -1609, -1609, -1609, -1609, 12026,   937,  6228,   988,
   -1609, -1609, -1609,   847, -1609, -1609, -1609, -1609, -1609,  7116,
   -1609, -1609, -1609,    31,   499,   499,     2,   507,   507,   507,
     507,   450,   450, -1609, -1609, 11458, 11458, 12026, 12026, -1609,
     283, -1609, -1609,    20, -1609, -1609, -1609,   311, -1609, -1609,
   -1609,   313, -1609,   325, -1609,   511,   547,   548, -1609,   424,
   -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609,
     749, -1609,   977, 11742,   966,  6228, -1609, -1609, -1609,  1015,
     927,   927,   749, -1609,   773,   927,   574, 12026,   532,   534,
    1081, -1609, -1609,   827,   414, -1609, -1609, -1609, -1609, -1609,
   -1609, -1609, -1609, -1609, -1609, -1609,   280,   682,   617, -1609,
     888,   501,  6228, -1609, 12026,    56,   817,   927, -1609, -1609,
   -1609, -1609,   964, 12026, -1609, 12026, -1609,  1000,   996, 11458,
    1001,  6228,    26,   973,    10,   242,   867, -1609, -1609,   666,
      15,  1015, 11458,  1006,  1027,   941,   930,   997,   927,   968,
     999,  1029,   927,  6228,   -43, -1609, -1609, -1609,   980, -1609,
   -1609, -1609, -1609,  1014,  6228,  6228,   989, -1609,  1034,  1035,
    5044, -1609,   953,   954,   990, 12026, -1609, 12026, -1609,  6228,
     998,   955,  6228,   341,   348,   377,  1106, -1609,     8, -1609,
      72, -1609, -1609,  1114, -1609,   649,  6228,  6228,  6228,   654,
    6228,  6228,  6228,  6228,  6228,  6228,  1028,  6228,  6228, -1609,
    6228,  1009,  1010,  1011,  1002,   751,   750,   904, -1609,   426,
   -1609,    97,    87,   972,  6820,  6820,  6820,  1068, -1609,  6228,
     642,  1044, -1609, 12026,  1045, -1609, -1609,  6228,    31,   495,
     455, -1609,   869,   157,   892,   896, -1609, -1609,   721, -1609,
     893,   390,  1013,  1016, 11742,  1018, -1609,   537, -1609, -1609,
   -1609, -1609, -1609, -1609, -1609, -1609, -1609,  1033, -1609, -1609,
   -1609,  6228, -1609, -1609,    79, -1609, -1609, -1609, -1609, -1609,
   -1609, -1609,   612, -1609,  1127,   665, -1609, -1609, -1609, -1609,
   -1609, -1609, -1609, -1609, -1609,   897, -1609, -1609,  1132, -1609,
   -1609, -1609, -1609, -1609,   550,  1141, -1609,   670, -1609, -1609,
   -1609,   841,   168,   843,   554,   845,   850,   747,   942,   537,
     956,   958,  7708,   898,   874, -1609,  1015,   682, -1609,   967,
     991,  5044,  1003,  1005,  1042,  1007,  1008, 12026,    43, -1609,
   12026, -1609,  6228,  1049,  6228,  1071,  6228,    30,  1050,  6228,
    1053, -1609,  1084,  1085,  6228, 12026,   763,  1126, -1609, -1609,
   -1609, -1609, -1609, -1609, 11458, -1609,  5044,   927,  1099, -1609,
   -1609, -1609,   927,  1099, -1609,  6228,  1065,  5044, 12026, -1609,
   -1609,  6228,  6228,   513, -1609,    21,   539, -1609, 10606,   553,
   -1609,   637, -1609,  1024, -1609, -1609,  5044,  1022,  1025, -1609,
    6228, -1609, -1609,  1017,  1034,  1113, -1609,  1083, -1609,   156,
   -1609, -1609,  1207, -1609, -1609,  5044, 12026, -1609,   508, -1609,
   -1609, -1609,  1032,   986,  1012, -1609, -1609, -1609,  1019,  1021,
   -1609, -1609, -1609, -1609, -1609,   983, 12026,  1037, -1609, -1609,
    6228,  6228,  6228,  4748,  7412,  8596,   904, -1609,  1107,  8596,
   -1609,  1070,   307, -1609, -1609, -1609,  1044, -1609,   927, -1609,
     782, -1609,   216,  1120, -1609,  6228,  1121,   988,   354,  1041,
   -1609,    31,   981, -1609, -1609,   -60, -1609,   204,     5,   982,
      31,   204,  7116, -1609,   281, -1609, -1609, -1609, -1609, -1609,
   -1609,    31,  1086,   948,   815,     5, -1609, -1609,   957,  1155,
   -1609, -1609, -1609,  9754,  1051,  1052,  1054, -1609, -1609, -1609,
   -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609,
    1206,   -18,  1216,   -18,   978,  1130, -1609, -1609, -1609, -1609,
    1080, 12026,  1030, -1609,   942,  7708, -1609,  1072, -1609, -1609,
   -1609, -1609, -1609, -1609,  6228,  1105, -1609, -1609,  6228, -1609,
     395, -1609,  6228,  1108,  6228, -1609,  6228, 12026, 12026, -1609,
     488, -1609,  6228, -1609,  1138,  1144,  1161,   927,  1099, -1609,
    6228,  1087, -1609, -1609, -1609,  1093, -1609,    23,  6228,  5044,
    1094,    24, -1609, 12026,  1095, 10890,   193, -1609, 11174,  1098,
   -1609, -1609,  1088, -1609, -1609, -1609,  6228,   655,  1106, 12026,
     517, -1609,  1089,  1106, 12026, -1609, -1609,  6228,  6228,  6228,
    6228,  6228, -1609,  6228,   382,   386,   389,   533, -1609, 12026,
   -1609, -1609, -1609, -1609,  1120, -1609, -1609, -1609,   927, -1609,
   -1609, -1609, -1609, -1609,  1102,  7116, -1609, -1609, -1609, -1609,
   -1609,   297,  7116,  7116,   490, -1609,   892, -1609,   170, -1609,
     896,    31,  1135, -1609, -1609,  1031, -1609, -1609, -1609, -1609,
    1194,  1103, -1609,   394, -1609, -1609, -1609, -1609,   330,   330,
   -1609,   -18, -1609, -1609,   397, -1609,  1261,     5,  1195,  1109,
    7708,   -39,  1026, -1609,  1123, -1609, -1609,  6228, -1609,  6228,
    1147, -1609,  6228, -1609, -1609, -1609,  1240, -1609, -1609,  7412,
    6228,   927, -1609, -1609, -1609,  6228,  6228, -1609, -1609, -1609,
    7412,  7412,  1202,  5044, 12026,  1112, 12026,  6228, 12026,  1115,
    7412, -1609,   239,    18,  1106, 12026, -1609,  1104,  1106, -1609,
   -1609, -1609, -1609, -1609, -1609,  1110,  1034,  1035,  6228,  1181,
   -1609,   406, -1609, -1609, -1609,   507,  7116,  7116,     2,   575,
   -1609, -1609, -1609, -1609, -1609, -1609,  6228, -1609, 11458, -1609,
   11458,  1208, -1609, -1609, -1609,  1274, -1609, -1609, -1609,  1040,
    1201, -1609, -1609,  1203, -1609,   679, 12026,  1184,  1090, 12026,
    7708, -1609, -1609,  6228, -1609,  1197, -1609, -1609,  1099, -1609,
   -1609, 11458, -1609, -1609,  1222,  6228,  1134, -1609,  1223,  7412,
   -1609, 12026,   194,   187, -1609,  1125,  1106, -1609,  1128,  7412,
     686,   378, 12026,  1205,  1002,     2,     2,  7116,   403, -1609,
   -1609, 11458, -1609, -1609,  1195,  7708, -1609,  1120,  1036, 12026,
    1209,  1101,  1203, -1609, 12026,  1140, 11458,  5044, 11458,  1142,
   -1609, -1609,  1236,   206, -1609, -1609, -1609, -1609,  1148,   392,
   -1609, -1609, -1609,  1139, -1609,  1218, -1609,   411, 12026, -1609,
       2, -1609, -1609, -1609, -1609, -1609,  6228,  1039, 12026,  1219,
   -1609,  5044,  1152, -1609, -1609,  1153,  6228, -1609, -1609, -1609,
   -1609, -1609, -1609, -1609, 12026,  1227,  1187,   442, -1609,  1056,
    1048, 12026, -1609, -1609,  6228,  7412,  1160, 12026, -1609,  1229,
    1002,  1055,  6228,  1058,  7412,   443, 12026, -1609,  7708, -1609,
    7708,  1232,  1187,  1167, -1609,  1136, 12026, -1609,  1002,  1069,
    1168, -1609, 12026,  1187,  1133, -1609,  1244, 12026,  1063,  7708,
   -1609
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       193,   458,   459,   193,   193,   193,   781,   980,   607,   872,
     881,   822,   786,   784,   766,   873,   876,   829,   790,   767,
     768,   932,   821,   882,   770,   879,   851,   831,   806,   826,
     827,   877,   874,   825,   772,   880,   773,   774,   920,   934,
     919,   823,   842,   836,   775,   824,   777,   776,   921,   860,
     828,   803,   944,   945,   946,   947,   948,   949,   950,   951,
     952,   953,   954,   968,   975,   850,   846,   837,   817,   765,
       0,   845,   853,   861,   969,   841,   479,   818,   819,   875,
     970,   976,   838,   855,     0,   485,   447,   481,   848,   783,
     839,   840,   868,   843,   859,   867,   974,   977,   789,   830,
     870,   480,   858,   863,   769,     0,     0,     0,   395,   856,
     866,   871,   869,   849,   835,   922,   833,   834,   971,     0,
     394,     0,   972,   978,   864,   820,   844,   973,   425,     0,
     457,   865,   847,   854,   862,   857,   923,   811,   816,   815,
     814,   813,   812,   778,   832,     0,   782,   878,   804,   911,
     910,   912,   788,   787,   807,   917,   771,   909,   914,   915,
     906,   810,   852,   908,   918,   916,   907,   808,   913,   925,
     928,   929,   926,   927,   924,   779,   930,   931,   933,   898,
     897,   884,   802,   795,   891,   887,   805,   801,   900,   901,
     791,   792,   785,   794,   896,   895,   892,   888,   905,   899,
     894,   890,   883,   793,   904,   903,   797,   799,   798,   889,
     893,   885,   800,   886,   796,   902,   955,   956,   957,   958,
     959,   960,   936,   937,   935,   941,   942,   943,   938,   939,
     940,   809,   961,   962,   963,   964,   965,   966,   967,   193,
       0,     2,   193,     5,     7,    19,     0,    24,    27,    32,
      33,    34,    35,    36,    37,    38,    28,    54,    55,    29,
      30,     0,    72,    75,    76,    31,    77,    78,    79,    80,
      81,    82,   476,     0,   207,   208,   203,   200,    14,   190,
     191,   192,   196,   198,   199,   201,   202,   204,   209,   194,
     224,   231,   226,   253,   259,     0,   251,   252,   233,   227,
     206,   228,   205,   229,   232,   350,   352,   354,   364,   368,
     370,   373,   378,   381,   384,   386,   388,   390,     0,   392,
     398,   400,     0,   416,   399,   421,   424,   426,   429,   431,
       0,   436,   433,     0,   444,   454,   456,   430,   460,   467,
     477,   468,   469,   470,   473,   474,   471,   472,   492,   494,
     495,   496,   493,   541,   542,   543,   544,   545,   546,   453,
     581,   573,   580,   579,   578,   575,   577,   574,   576,   478,
     475,   608,   609,    39,   234,   235,   237,   236,   238,   230,
       0,   455,   764,   780,   872,   881,   879,   782,     0,     0,
       0,   116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   142,   143,     0,     0,     0,
       0,   138,   139,   140,   141,   148,     0,     0,     0,     0,
       0,     0,     0,     0,   114,   120,   122,   123,     0,   136,
       0,     0,     0,   193,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     278,   279,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   449,   452,   439,     0,     0,
     761,   766,   790,   768,   821,   882,   770,   831,   772,   842,
     775,   777,   776,   860,   968,   975,   765,   969,   819,   970,
     976,   843,   974,   977,   922,   971,   972,   978,   973,   923,
     917,   909,   915,   906,   808,   928,   929,   926,   779,   930,
     445,   455,   764,   437,     0,   179,   438,   441,   766,   767,
     768,   772,   773,   774,   775,   765,   771,   482,     0,   443,
     442,   212,     0,     0,   770,   777,   776,     0,   193,   483,
     930,     0,   231,     0,   508,     0,   448,   762,     0,   763,
     419,   420,     0,   451,   450,   440,   423,     0,     0,   537,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     3,     1,     6,     8,
       0,     0,     0,     0,     0,   193,   193,   193,   193,     0,
     223,   195,   197,     0,   210,     0,     0,     0,     0,     0,
       0,     0,     0,   213,   239,   258,   254,   260,   255,   257,
     256,     0,     0,     0,   409,     0,     0,   407,     0,   359,
       0,   408,   401,   406,   405,   404,   403,   402,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   397,   396,   393,     0,
     417,   422,     0,     0,     0,   432,   464,   435,   434,   446,
       0,   461,     0,     0,     0,   548,   550,   554,     0,    43,
      40,    41,    44,    45,     0,     0,     0,     0,    46,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     618,   619,   620,   145,   144,     0,    99,   152,   149,     0,
     151,   150,   147,   146,     0,   108,     0,     0,   115,   121,
       0,     0,   137,     0,     0,     0,   587,     0,     0,     0,
     583,     0,     0,     0,   597,     0,     0,   241,   242,   261,
     262,     0,     0,     0,     0,   128,     0,   132,   193,   611,
       0,    56,     0,    65,     0,     0,     0,    57,     0,     0,
       0,     0,     0,   761,   588,     0,     0,     0,     0,   323,
       0,     0,   586,     0,     0,     0,   605,     0,     0,     0,
       0,   591,     0,     0,   180,     0,     0,   176,   211,     0,
       0,     0,   482,     0,   484,     0,   509,   508,   505,     0,
       0,   539,   538,   418,     0,   536,     0,   631,   632,   582,
       0,     0,     0,     0,     0,     0,   637,     0,   187,   188,
       0,     0,     0,   196,     0,     0,   216,   217,    20,     0,
      21,     0,     4,    25,     0,    11,    26,     0,    15,   872,
      73,    12,    74,    16,   178,   225,     0,     0,     0,     0,
     214,   240,   296,   351,   353,   357,   363,   362,   361,     0,
     358,   355,   356,     0,   372,   371,   369,   375,   376,   377,
     374,   379,   380,   383,   382,     0,     0,     0,     0,   414,
       0,   427,   428,     0,   465,   462,   490,     0,   979,   610,
     488,     0,   607,     0,   118,     0,     0,     0,    98,     0,
      88,    90,    91,    92,    93,    95,    96,    97,    89,    94,
      84,    85,     0,     0,   104,     0,   100,   102,   103,   110,
       0,     0,    83,    42,     0,     0,     0,     0,     0,     0,
       0,   711,   716,     0,     0,   712,   746,   699,   701,   702,
     703,   705,   707,   706,   704,   708,     0,     0,     0,   153,
       0,     0,     0,   107,     0,   156,     0,     0,   553,   547,
     584,   585,     0,     0,   601,     0,   598,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   243,   244,     0,
     249,   134,     0,     0,   129,     0,     0,     0,     0,     0,
       0,    58,     0,     0,     0,   277,   283,   280,     0,   590,
     589,   596,   604,     0,     0,     0,     0,   552,     0,     0,
       0,   410,     0,     0,     0,     0,   594,     0,   592,     0,
     181,     0,     0,     0,     0,     0,   508,   506,     0,   497,
       0,   486,   487,     0,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   185,
       0,   770,   777,   776,   930,     0,     0,     0,   647,     0,
     218,     0,     0,     0,   193,   193,   193,     0,   250,     0,
     307,   303,   305,     0,   297,   298,   360,     0,     0,     0,
       0,   677,   366,   650,   654,   656,   658,   660,   663,   670,
     671,   679,   882,   769,     0,   778,   385,   559,   565,   566,
     568,   612,   613,   569,   572,   387,   389,   556,   391,   415,
     466,     0,   463,   489,     0,   117,    52,    53,    50,    51,
     125,   124,     0,    86,     0,     0,   105,   106,   111,    70,
      71,    48,    49,    69,   717,     0,   720,   747,     0,   710,
     709,   714,   713,   745,     0,     0,   722,     0,   718,   721,
     700,     0,     0,     0,     0,     0,     0,     0,   154,   160,
       0,     0,     0,     0,     0,   109,   112,     0,   157,     0,
       0,   193,     0,     0,   605,     0,     0,     0,     0,   558,
       0,   264,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   245,     0,     0,     0,     0,   290,     0,   287,   292,
     248,   135,   130,   133,     0,   177,     0,     0,    67,    61,
      64,    63,     0,    59,   281,     0,     0,   193,     0,   321,
     325,     0,     0,     0,   328,     0,     0,   334,     0,     0,
     341,     0,   345,     0,   412,   411,   193,     0,     0,   182,
       0,   184,   322,     0,     0,     0,   509,     0,   498,     0,
     532,   529,     0,   533,   534,     0,     0,   528,     0,   503,
     531,   530,     0,     0,     0,   624,   625,   621,     0,     0,
     629,   630,   626,   635,   633,     0,     0,     0,   639,   186,
       0,     0,     0,     0,     0,     0,   640,   641,     0,     0,
     219,    22,     0,    13,    17,    18,   304,   316,     0,   317,
       0,   308,   309,   310,   311,     0,   300,     0,     0,     0,
     661,   674,     0,   365,   367,     0,   693,     0,     0,     0,
       0,     0,     0,   649,   651,   652,   688,   689,   690,   692,
     691,     0,     0,   665,   664,     0,   668,   672,   686,   684,
     683,   676,   680,     0,     0,     0,     0,   562,   564,   563,
     560,   557,   491,   119,   127,   126,    87,   101,   734,   715,
       0,   739,     0,   739,   728,   723,   155,   161,   163,   162,
       0,     0,     0,   113,   158,     0,    23,     0,   602,   603,
     606,   599,   600,   263,     0,     0,   276,   268,     0,   272,
       0,   266,     0,     0,     0,   285,     0,     0,     0,   247,
     288,   291,     0,   131,     0,     0,    66,     0,    60,   282,
       0,     0,   324,   326,   331,     0,   329,     0,     0,     0,
       0,     0,   335,     0,     0,     0,     0,   342,     0,     0,
     346,   413,     0,   595,   593,   183,     0,     0,   508,     0,
       0,   540,     0,   508,     0,   504,    10,     0,     0,     0,
       0,     0,   638,     0,     0,     0,     0,     0,   642,     0,
     648,   320,   318,   319,   312,   313,   314,   306,     0,   301,
     299,   678,   669,   675,     0,     0,   748,   749,   759,   758,
     757,     0,     0,     0,     0,   750,   655,   756,     0,   653,
     657,     0,     0,   662,   666,     0,   687,   682,   685,   681,
       0,     0,   570,     0,   567,   617,   561,   735,     0,     0,
     733,   740,   741,   737,     0,   732,     0,   730,     0,     0,
       0,     0,     0,   159,     0,   549,   265,     0,   274,     0,
       0,   270,     0,   273,   286,   294,   295,   289,   246,     0,
       0,     0,    62,   284,   555,     0,     0,   332,   336,   330,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   551,     0,     0,   508,     0,   535,     0,   508,   622,
     623,   627,   628,   634,   636,     0,     0,     0,     0,     0,
     643,     0,   315,   302,   673,   760,     0,     0,   752,     0,
     698,   697,   696,   695,   694,   659,     0,   751,     0,   614,
       0,     0,   744,   743,   742,     0,   736,   729,   727,     0,
     724,   725,   719,   164,   166,   168,     0,     0,     0,     0,
       0,   269,   267,     0,   275,     0,   215,   349,    68,   327,
     333,     0,   347,   343,     0,     0,     0,   337,     0,     0,
     339,     0,   518,   512,   507,     0,   508,   499,     0,     0,
       0,     0,     0,     0,     0,   754,   753,     0,     0,   615,
     571,     0,   738,   731,     0,     0,   170,   169,     0,     0,
       0,     0,   165,   271,     0,     0,     0,     0,     0,     0,
     526,   520,     0,   519,   521,   527,   524,   514,     0,   513,
     515,   525,   501,     0,   500,     0,   189,     0,     0,   220,
     755,   667,   616,   726,   167,   171,     0,     0,     0,     0,
     293,     0,     0,   340,   338,     0,     0,   511,   522,   523,
     510,   516,   517,   502,     0,     0,     0,     0,   172,     0,
       0,     0,   348,   344,     0,     0,     0,     0,   644,     0,
       0,     0,     0,     0,     0,     0,     0,   221,     0,   174,
       0,     0,     0,     0,   173,     0,     0,   645,     0,     0,
       0,   222,     0,     0,     0,   646,     0,     0,     0,     0,
     175
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1609, -1609,  -221,  1129, -1609,  1131,  1137, -1609,  1122,  -507,
   -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609,
    -935, -1609, -1609, -1609, -1609,  -218,  -552, -1609,   691,  -121,
   -1609, -1609, -1609, -1609, -1609,   254,   470, -1609, -1609, -1609,
     959, -1609, -1609,   961, -1609, -1609,  -634, -1609,   399, -1609,
     947, -1609,   223,  -891, -1609,  -229,  -272, -1609, -1609,  -820,
   -1609,   796, -1609, -1609, -1609, -1609, -1608,  -535,    11,  -269,
     -97,  -385, -1609,  -169, -1609, -1609, -1609, -1609, -1609,   570,
   -1609,   -86,  1272,     0, -1609, -1609, -1609, -1609,   417, -1609,
   -1609,  -293, -1609,     6, -1609, -1609,   221,  -703,  -671, -1609,
   -1609,   638, -1609, -1609,     4,   207, -1609, -1609, -1609,    93,
   -1609, -1609,   333,   100, -1609, -1609,   104, -1236, -1609,   872,
     189, -1609, -1609,   185,  -967, -1609, -1609,   183, -1609, -1609,
   -1197, -1189, -1609,   180, -1609, -1609,   791,   794, -1609,  -545,
   -1609, -1609,  -632,   278,  -613,   273,   279, -1609, -1609, -1609,
   -1609, -1609,  1092, -1609, -1609, -1609, -1609,  -816,  -303, -1119,
   -1609,   -88, -1609, -1609, -1609, -1609, -1609, -1609, -1609,   -31,
    -783, -1609, -1609,   505,   208, -1609,  -620, -1609, -1609, -1609,
   -1609, -1609, -1609, -1609,   739, -1609,  -975, -1609,   165, -1609,
     618,  -769, -1609, -1609, -1609, -1609, -1609,  -271,  -266, -1156,
   -1061, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609,
   -1609,   543,  -731,  -804,   263,  -814, -1609,    55,  -764, -1609,
   -1609, -1609, -1609, -1609, -1609, -1609,   984,   985,  -285,   458,
     300, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609,
   -1609, -1609, -1609, -1609, -1609,   150, -1609, -1609,   141,   145,
   -1003, -1609, -1609, -1609,   111,   101,   -57,   356, -1609, -1609,
   -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609, -1609,
   -1609,   112, -1609, -1609, -1609,   -51,   350,   493, -1609, -1609,
   -1609, -1609, -1609,   293, -1609, -1609, -1422, -1609, -1609, -1609,
    -574, -1609,    78, -1609,   -69, -1609, -1609, -1609, -1609, -1222,
   -1609,   122, -1609,  -358,  -340,   909,   -58, -1609
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   240,   821,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
    1198,   746,   258,   259,   260,   261,   262,   263,   900,   901,
     902,   264,   265,   266,   906,   907,   908,   267,   422,   423,
     424,   883,   268,   425,   426,   427,   442,   736,   737,   428,
     429,   269,  1148,   939,   270,  1603,  1604,   271,   272,   739,
     273,   515,   274,   275,   276,   277,  1570,   278,   279,   280,
     281,   282,   283,   284,   285,   603,   286,   287,   816,   817,
     288,   289,   290,   542,   292,   604,   440,   969,   970,   293,
     605,   294,   607,   543,   296,   729,   730,  1186,   449,   297,
     450,   451,   733,  1187,  1188,  1189,   608,   609,  1064,  1065,
    1459,   610,  1061,  1062,  1291,  1292,  1293,  1294,   298,   758,
     759,   299,  1213,  1214,  1407,   300,  1216,  1217,   301,   302,
    1219,  1220,  1221,  1222,   303,   304,   305,   306,   849,   307,
    1303,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   628,   629,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   655,   656,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   877,   347,   348,   349,  1248,   787,
     788,   789,  1634,  1678,  1679,  1672,  1673,  1680,  1674,  1249,
    1250,   350,   351,  1251,   352,   353,   354,   355,   356,   357,
     358,  1096,   964,  1086,  1340,  1087,  1493,  1088,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   765,  1163,
     369,   370,   371,   372,  1090,  1091,  1092,  1093,   373,   374,
     375,   376,   377,   378,   805,   806,   379,  1276,  1277,  1049,
    1072,  1313,  1314,  1073,  1074,  1075,  1076,  1077,  1323,  1483,
    1484,  1078,  1326,  1079,  1464,  1080,  1081,  1331,  1332,  1489,
    1487,  1315,  1316,  1317,  1318,  1583,   696,   927,   928,   929,
     930,   931,   932,  1138,  1509,  1600,  1139,  1507,  1598,   933,
    1353,  1504,  1500,  1501,  1502,   934,   935,  1319,  1327,  1474,
    1320,  1470,  1304,   380,   548,   381,   382,   383
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int xquery_parser::yytable_ninf_ = -762;
  const short int
  xquery_parser::yytable_[] =
  {
       291,   856,   606,   291,   291,   291,   295,   575,   533,   295,
     295,   295,   512,   591,   388,   389,   390,   984,  1018,   650,
     541,   857,   858,   859,   860,   586,   512,   583,   962,   996,
    1417,  1215,  1048,  1360,   669,   830,   832,  1070,  1427,   510,
     588,   556,   887,  1010,  1175,  1247,   715,  1203,   884,   512,
     825,   828,   831,   833,  1158,   584,  1455,  1456,   882,   958,
     963,   512,  1095,   512,   689,  1299,   791,  1111,   845,   966,
     846,   847,   715,   848,   584,   850,  1606,   715,   823,   826,
     558,  1240,  1241,   851,   852,   584,  1601,   743,   747,  1115,
     713,   584,  1435,   584,   718,   937,  1205,   584,   584,  1471,
     589,  1089,  1089,  1485,   960,   291,   882,   684,  1728,  1632,
     685,   295,   719,   755,  1019,  1498,   532,   959,  1408,   960,
    1408,  1408,   392,   393,   593,   394,   395,  -761,   391,   678,
     580,   447,   593,   993,  1747,  1238,   993,   960,    76,  1089,
     593,   686,   593,   398,   953,  1755,   593,   581,  1157,   396,
     670,   955,    87,  1466,  1176,  1169,   430,   631,   959,   693,
     694,   679,   714,   671,   470,  1240,  1241,   687,  1192,   961,
    1172,   470,  1242,  1149,  1382,   632,   399,   101,  1118,  1499,
    1020,  1067,  1607,   590,  1068,   592,    76,  1374,   761,   813,
    1036,  1467,  1243,   767,  1244,  1089,  1240,  1282,  1633,  1670,
      87,  1239,  1100,  1240,  1409,   121,  1536,  1541,  1089,   952,
     995,  1670,   707,  1676,   994,  1240,   840,  1012,  1572,   988,
     784,   433,  1245,  1004,   954,   101,   107,   448,   967,   688,
     792,   956,  1693,  1071,  1180,   720,   938,   651,  1417,   291,
    1191,   585,   291,   119,   404,   295,  1514,  1237,   295,  1411,
     606,  1305,  1070,  1070,   744,  1112,  1242,  1356,  1472,  1473,
     587,  1177,   559,  1246,  1247,  1608,   968,  1398,   830,   832,
    1335,   818,   512,  1247,  1435,   512,  1243,   820,  1244,  1054,
     448,   145,   291,  1056,  1281,  1599,   448,  1069,   295,   938,
    1025,  1173,  1345,  1178,   742,   448,   448,  1029,  1463,   657,
     448,   745,   659,   407,  1066,   973,  1245,  1243,  1546,  1244,
     107,   823,   826,  1206,  1243,   593,  1244,  1037,  1677,  1288,
    1089,   434,   878,  1306,  1671,   631,  1243,   119,  1244,   913,
     715,   593,   959,   916,   959,   917,  1708,  1245,   676,   512,
    1290,   461,   512,   632,  1245,   409,   512,  1429,  1576,   723,
     684,   456,   512,   685,  1631,   593,  1245,   740,   672,   512,
     593,   819,   593,   734,   593,   145,   752,   824,   827,  1656,
    1640,   673,   512,   763,   764,  1305,  1547,   918,   512,   983,
    1005,   512,   770,   715,   715,   974,  1179,   593,   981,   512,
    1393,  1605,  1021,  1149,  1007,   512,   512,   512,   512,   462,
     593,  1240,   977,   512,   465,   980,  1307,  1308,  1022,  1309,
     687,   512,  1026,  1027,  1414,  1101,  1310,  1101,  1676,  1030,
    1031,  1695,  1547,  1577,  1350,  1363,  1311,  1028,   813,  1104,
    1089,   291,   735,   291,  1032,   976,  1580,   295,  1312,   295,
     998,  1047,   999,  1581,   717,   593,   591,  1306,  1071,  1071,
     466,  1417,   593,  1582,  1089,  1247,   512,   291,   593,   790,
    1006,  1052,   291,   295,  1099,  1375,   463,   464,   295,  1468,
     512,   794,   688,  1513,  1008,  1023,  1469,   812,   581,   512,
    1040,   593,   593,  1352,  1343,  1070,   593,   811,   814,   960,
     593,  1605,  1048,   593,  1070,  1102,  1450,  1103,  1590,  1002,
    1003,  1595,   830,   832,   830,  1070,  1383,   593,  1135,  1105,
    1643,   512,  1243,   649,  1244,  1715,   514,  1240,  1241,  1283,
    1284,  1285,   882,  1711,  1136,  1233,  1240,  1241,   919,  1492,
    1307,  1308,  1234,  1309,  1024,  1461,  1605,   121,   291,  1519,
    1182,   920,  1245,   921,   295,  1183,  1729,  1741,   513,   532,
    1311,   959,  1119,  1120,   922,   923,   924,  1123,   925,  1686,
     926,  1235,  1312,   870,   871,   872,  1565,  1137,   873,  1089,
    1566,  1675,  1681,  1567,   291,   467,  1273,   441,  1591,  1278,
     295,  1596,   960,   640,  1691,   291,   291,   291,   291,  1160,
    1644,   295,   295,   295,   295,  1716,  1618,   641,  1009,  1411,
    1051,   291,    76,  1055,   512,  1301,   468,   295,  1242,   469,
    1212,  1545,  1675,   634,  1549,   715,    87,  1242,  1681,  1744,
    1199,  1745,   889,  1405,  1199,   512,  1730,  1742,  1243,   121,
    1244,   674,  1279,   595,  1328,  1329,  1212,  1243,   596,  1244,
    1760,   101,   635,   597,  1350,  1067,   512,   675,  1068,  1410,
    1415,  1089,   512,   512,  1089,   636,  1106,  1330,  1245,  1553,
    1351,   598,   107,  1416,  1557,  1070,   444,  1245,  1162,   121,
    1165,   107,   443,  1107,   512,   445,   512,  1520,  1337,   119,
    1478,  1071,  1110,  1568,   512,   516,  1569,   512,   119,   637,
    1071,   512,  1108,  1013,  1014,  1015,   631,   814,   738,  1434,
     437,  1071,   446,  1352,   638,   438,   567,   454,  1555,  1109,
    1338,   568,   903,   639,   632,   291,   592,   145,  1182,  1141,
    1227,   295,  1228,  1183,  1142,   718,   145,  1339,   512,   830,
     631,  1223,   705,   455,  1418,  1287,   633,   706,   291,  1279,
    1143,  1184,  1144,   719,   295,  1288,  1344,  1419,   632,   975,
     439,  1145,  1415,   606,   904,  1289,  1580,   512,   599,   905,
     960,   600,   738,  1581,  1135,  1552,  1290,   650,   291,   291,
    1647,   959,   459,  1582,   295,   295,   601,  1146,   512,  1113,
    1136,  1185,  1288,  1415,  1649,  1635,  1650,   460,   595,  1638,
     595,  1113,  1129,   596,  1131,   596,  1685,  1153,   597,   904,
     597,   602,   517,  1130,   905,  1132,  1154,   512,   512,   512,
     512,  1394,   561,  1045,   562,  1182,   598,  1665,   598,  1046,
    1183,   564,   431,   565,  1089,   432,  1089,   890,   891,   892,
     893,   894,   895,   896,   897,   898,   899,   658,   528,  1396,
    1578,  1579,   661,   435,  1199,   512,   436,  1692,  1124,  1125,
    1126,   529,  1575,   452,  1127,   457,   453,  1089,   458,   512,
     715,  1071,  1702,   874,  1705,   530,   874,  1683,   545,   874,
     690,   691,   692,   546,  1657,   575,   654,  1253,   660,  1254,
    1280,   553,  1258,   554,  1259,   555,   512,  1089,   813,   840,
     652,   653,   702,   703,   557,   512,   560,   512,  1121,  1122,
     563,   512,  1089,  1147,  1089,  1150,  1151,  1452,  1453,   854,
     855,   861,   862,   599,   512,   599,   600,   566,   600,   863,
     864,   569,  1097,  1097,  1592,  1593,   570,   571,   573,   572,
    1451,   785,   577,  1274,   593,   574,   611,   612,   594,   642,
     630,   643,   644,   654,  1645,  1646,   662,   512,   645,   512,
     405,   663,   664,   668,   470,   665,   602,   666,   602,   667,
     680,   613,   682,   683,   695,   698,   700,   716,   701,   614,
     615,   732,   616,   727,   738,   704,  1432,   741,   728,   511,
     617,  1298,   406,   749,   618,   750,   619,   751,   762,   768,
     769,   620,   775,   527,   432,   436,   453,   391,   458,   777,
     291,   778,   783,   469,   779,   512,   295,   780,   621,   793,
     408,   781,   786,   795,   796,  1690,   544,   799,   396,   815,
     804,   808,   809,   822,  1538,   836,   512,   397,   549,   837,
     552,   622,   623,   624,   625,   626,   627,   838,   839,  1532,
     853,   865,   866,   867,   868,   399,   879,   885,   886,   400,
     888,   910,   911,   914,   291,   291,   291,   915,   936,   942,
     295,   295,   295,   940,   944,   947,   948,   949,   710,   411,
     412,   413,   414,   950,   415,   416,   711,   418,   419,   957,
     401,   402,  1057,   420,   972,   951,   979,   989,   978,   982,
     990,   991,   992,   997,  1001,  1000,  1033,  1035,  1034,  1038,
    1573,  1053,  1039,  1063,  1059,   905,  1114,   959,  1133,   512,
    1134,  1152,   512,  1159,  1161,  1167,  1170,  1174,  1181,  1194,
    1168,   734,  1195,  1202,  1196,  1200,  1197,   512,  1201,  1208,
    1207,  1212,  1218,  1211,  1224,  1225,   512,  1230,   405,  1236,
    1226,  1252,  1231,  1266,  1616,   686,  1275,  1321,  1295,  1297,
     512,  1302,  1273,  1322,   882,  1620,  1538,  1325,  1622,  1349,
     512,   291,  1270,  1271,  1272,  1630,  1333,   295,  1354,  1334,
     406,  1336,  1367,  1199,  1341,   938,   812,  1362,  1366,  1358,
    1348,  1359,  1361,  1370,  1444,  1445,  1446,  1368,   512,  1369,
    1365,  1371,  1372,  1378,  1384,  1380,   291,  1386,   408,  1387,
    1388,  1392,   295,  1397,  1400,  1421,  1423,   291,   512,  1424,
    1415,  1426,  1428,   295,  1431,  1437,  1441,   512,  1401,  1436,
    1443,   512,  1449,  1288,  1458,  1462,   291,  1482,  1465,  1475,
    1481,  1488,   295,  1497,  1508,  1494,  1495,  1422,  1496,   511,
    1486,  1438,   511,  1503,  1622,   291,  1506,  1510,  1439,  1517,
    1440,   295,  1522,  1515,  1394,  1531,   410,   411,   412,   413,
     414,  1529,   415,   416,   417,   418,   419,  1530,  1534,  1551,
    1556,   420,   421,  1045,  1045,   512,  1535,  1540,  1543,  1046,
    1046,  1550,  1703,  1574,  1512,  1586,  1588,  1589,  1597,  1135,
    1610,  1613,  1615,  1602,  1621,  1625,  1642,  1637,  1629,  1659,
    1651,  1652,  1653,   512,  1639,  1654,   677,  1655,  1587,   681,
    1609,  1660,  1664,   549,  1666,  1668,  1722,  1667,  1682,   697,
    1688,  1684,  1699,  1701,  1698,  1706,   699,  1707,  1710,   512,
     512,  1749,  1713,  1714,  1721,  1724,  1725,  1568,  1696,   549,
    1722,  1719,  1727,  1734,  1736,   726,  1731,  1746,   731,  1703,
    1732,  1748,  1753,  1752,  1756,   512,   748,   512,  1738,  1757,
     512,  1740,   549,   756,   757,   760,  1759,   582,   576,  1347,
     766,   512,  1193,   578,  1116,   712,   512,   912,   773,   579,
    1364,  1662,   708,  1694,   709,   834,  1050,  1190,  1373,   987,
    1460,   512,  1286,  1391,  1527,  1457,  1454,  1402,  1406,  1412,
     776,  1420,   843,   881,  1430,  1017,   844,  1709,  1712,   291,
     648,  1098,  1357,  1166,  1346,   295,  1442,  1448,   721,   722,
    1447,  1476,  1480,   774,  1585,  1300,  1479,  1584,  1324,  1140,
    1355,  1505,  1594,  1477,     0,     0,     0,   760,     0,     0,
       0,     0,     0,     0,     0,     0,   782,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1689,     0,     0,   807,     0,
       0,     0,  1641,     0,     0,     0,   512,     0,   512,     0,
     512,     0,     0,     0,     0,     0,     0,   512,     0,     0,
    1648,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1045,
     512,     0,   512,     0,     0,  1046,     0,     0,     0,     0,
    1045,  1045,     0,   291,     0,     0,  1046,  1046,   512,   295,
    1045,   512,     0,     0,     0,     0,  1046,     0,     0,     0,
       0,  1737,     0,   512,     0,     0,     0,     0,     0,     0,
       0,   549,     0,   512,     0,     0,     0,     0,     0,  1751,
       0,     0,     0,     0,   512,     0,     0,     0,     0,     0,
       0,     0,   909,   512,     0,     0,     0,     0,     0,     0,
       0,   512,     0,     0,     0,     0,   512,     0,   512,     0,
     512,     0,     0,   941,     0,     0,     0,     0,     0,   945,
     946,     0,     0,     0,     0,     0,     0,     0,     0,  1045,
     512,     0,     0,     0,     0,  1046,     0,     0,     0,  1045,
     512,   965,     0,   971,     0,  1046,     0,     0,     0,     0,
       0,   549,     0,     0,   549,     0,   512,     0,   985,     0,
       0,     0,     0,   512,     0,     0,     0,   291,     0,   512,
       0,     0,     0,   295,     0,     0,     0,     0,   512,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   512,     0,
       0,     0,     0,     0,   512,  1016,     0,     0,     0,   512,
       0,   291,     0,     0,     0,     0,     0,   295,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   511,  1045,     0,     0,     0,     0,
       0,  1046,     0,     0,  1045,     0,     0,   391,     0,     0,
    1046,     0,     0,     0,     0,  1058,     0,   392,   393,     0,
     394,   395,     0,     0,     0,     0,     0,     0,   396,     0,
       0,     0,     0,     0,     0,     0,     0,   397,   398,     0,
       0,     0,     0,     0,  1094,  1094,  1094,  1094,     0,     0,
       0,     0,     0,     0,     0,   399,     0,     0,     0,   400,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1094,     0,     0,     0,     0,     0,     0,     0,
     401,   402,   403,     0,     0,     0,  1128,     0,     0,     0,
       0,     0,     0,   797,   798,     0,   800,   801,   802,   803,
       0,     0,     0,     0,   810,     0,     0,     0,     0,     0,
       0,     0,     0,  1156,     0,     0,     0,     0,     0,     0,
       0,     0,  1164,     0,  1164,   835,     0,     0,  1094,   404,
       0,     0,     0,   841,   842,     0,     0,     0,   405,     0,
       0,  1094,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     406,     0,     0,     0,   766,     0,   766,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   407,     0,
       0,     0,   876,     0,     0,     0,   876,     0,   408,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     409,     0,  1296,     0,     0,     0,     0,     0,   943,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1094,     0,     0,   410,   411,   412,   413,
     414,     0,   415,   416,   417,   418,   419,     0,     0,     0,
       0,   420,   421,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   986,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1011,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   841,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   731,     0,     0,  1376,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1390,     0,     0,     0,     0,     0,
       0,     0,     0,  1094,     0,     0,     0,     0,     0,     0,
    1060,     0,     0,     0,     0,     0,     0,   760,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1094,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1433,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   807,     0,  1117,     0,     0,
       0,     0,     0,     0,   511,     0,     0,     0,   511,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1155,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1171,     0,     0,     0,     0,     0,     0,
       0,     0,  1094,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1204,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1209,  1210,     0,     0,
    1511,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1229,     0,     0,  1232,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1525,  1526,  1255,  1256,
    1257,     0,  1260,  1261,  1262,  1263,  1264,  1265,     0,  1267,
    1268,     0,  1269,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1542,     0,  1094,     0,     0,  1094,     0,     0,
       0,  1060,     0,     0,     0,     0,     0,     0,  1554,     0,
       0,     0,     0,  1558,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1571,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1342,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1377,     0,  1379,     0,  1381,     0,
       0,  1385,     0,  1624,     0,  1626,  1389,  1628,     0,     0,
       0,     0,     0,     0,  1636,     0,     0,     0,  1395,     0,
       0,     0,     0,     0,     0,     0,     0,  1399,     0,     0,
       0,     0,     0,  1403,  1404,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1094,     0,  1094,
       0,     0,  1425,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1658,     0,     0,  1661,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1094,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1669,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1687,     0,     0,     0,     0,     0,     0,     0,     0,
    1094,     0,     0,     0,     0,     0,     0,  1060,  1697,     0,
       0,     0,     0,  1700,     0,  1094,     0,  1094,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1717,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1720,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1726,     0,     0,     0,     0,     0,     0,
    1733,     0,     0,     0,     0,     0,  1735,     0,     0,     0,
       0,     0,     0,     0,     0,  1743,  1516,     0,     0,     0,
    1518,     0,     0,     0,  1521,  1750,  1523,     0,  1524,     0,
       0,  1754,     0,     0,  1528,     0,  1758,     0,     0,     0,
       0,     0,  1533,     0,     0,     0,     0,     0,     0,     0,
    1537,  1539,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1395,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1559,
    1560,  1561,  1562,  1563,     0,  1564,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1611,
       0,  1612,     0,     0,  1614,     0,     0,     0,     0,     0,
       0,     0,  1617,     0,     0,     0,     0,  1619,  1539,     0,
       0,     0,     0,     0,     0,  1623,     0,     0,     0,  1627,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1663,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1623,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1704,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1718,     0,
       0,     0,     0,  1723,     0,     0,     0,     0,  1704,     0,
       0,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     7,  1723,     0,     8,     0,
       0,     0,     9,    10,  1739,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,     0,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,     0,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,     0,    66,    67,    68,    69,    70,    71,    72,
      73,     0,     0,    74,    75,     0,     0,     0,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,     0,
       0,     0,    87,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,    93,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
     104,   105,     0,     0,   106,   107,   108,   109,   110,     0,
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
       0,     0,     0,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     0,     0,     8,     0,     0,     0,   384,
     385,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,   386,    26,    27,    28,
      29,     0,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,     0,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,     0,
      66,    67,    68,    69,    70,    71,    72,    73,     0,     0,
      74,    75,     0,     0,     0,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,     0,     0,     0,    87,
       0,    88,    89,    90,    91,     0,    92,     0,     0,     0,
      93,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,    98,    99,   100,   101,   102,   103,   104,   105,     0,
       0,   106,   107,   108,   109,   110,     0,     0,     0,     0,
     111,   112,   113,   114,   115,   116,   117,   118,     0,   119,
       0,   120,   121,     0,     0,   122,   123,   124,     0,   531,
       0,   125,     0,   126,   127,     0,   128,   129,   130,     0,
     131,     0,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,     0,     0,   143,   144,   145,     0,   387,
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
       0,     0,     0,     2,     3,     4,     5,     6,     7,     0,
       0,     8,     0,     0,     0,   384,   385,     0,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,   534,   386,    26,    27,    28,    29,     0,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,     0,    43,    44,    45,   535,   536,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,     0,    66,    67,    68,    69,
      70,    71,    72,    73,     0,     0,    74,    75,     0,     0,
       0,    76,    77,   488,    79,    80,    81,    82,    83,   537,
      85,    86,     0,     0,     0,    87,     0,    88,    89,    90,
      91,     0,    92,     0,     0,     0,    93,    94,    95,    96,
      97,     0,     0,     0,     0,     0,     0,    98,    99,   100,
     101,   102,   103,   104,   538,     0,     0,   106,   107,   108,
     109,   110,     0,     0,     0,     0,   111,   112,   113,   114,
     115,   116,   117,   118,     0,   119,     0,   120,   121,     0,
       0,   122,   123,   124,     0,     0,     0,   125,   539,   126,
     127,     0,   128,   129,   130,     0,   131,     0,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,     0,
       0,   143,   144,   145,     0,   387,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   505,
     506,   507,   173,   174,   508,   540,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,   192,     0,   193,   194,   195,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,     1,     0,     0,     0,     0,     0,     0,     0,     2,
       3,     4,     5,     6,     7,     0,     0,     8,     0,     0,
       0,   384,   385,     0,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,   534,   386,    26,
      27,    28,    29,     0,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,     0,    43,    44,
      45,   535,   536,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,     0,    66,    67,    68,    69,    70,    71,    72,    73,
       0,     0,    74,    75,     0,     0,     0,    76,    77,   488,
      79,    80,    81,    82,    83,   537,    85,    86,     0,     0,
       0,    87,     0,    88,    89,    90,    91,     0,    92,     0,
       0,     0,    93,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,    98,    99,   100,   101,   102,   103,   104,
     538,     0,     0,   106,   107,   108,   109,   110,     0,     0,
       0,     0,   111,   112,   113,   114,   115,   116,   117,   118,
       0,   119,     0,   120,   121,     0,     0,   122,   123,   124,
       0,   869,     0,   125,     0,   126,   127,     0,   128,   129,
     130,     0,   131,     0,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,     0,     0,   143,   144,   145,
       0,   387,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   505,   506,   507,   173,   174,
     508,   540,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,     0,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     1,     0,     0,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       7,     0,     0,     8,     0,     0,     0,   384,   385,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,   534,   386,    26,    27,    28,    29,     0,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,     0,    43,    44,    45,   535,   536,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,     0,    66,    67,
      68,    69,    70,    71,    72,    73,     0,     0,    74,    75,
       0,     0,     0,    76,    77,   488,    79,    80,    81,    82,
      83,   537,    85,    86,     0,     0,     0,    87,     0,    88,
      89,    90,    91,     0,    92,     0,     0,     0,    93,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,    98,
      99,   100,   101,   102,   103,   104,   538,     0,     0,   106,
     107,   108,   109,   110,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,     0,   119,     0,   120,
     121,     0,     0,   122,   123,   124,     0,     0,     0,   125,
     875,   126,   127,     0,   128,   129,   130,     0,   131,     0,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,     0,     0,   143,   144,   145,     0,   387,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   505,   506,   507,   173,   174,   508,   540,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,     1,     0,     0,     0,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     0,     0,     8,
       0,     0,     0,   384,   385,     0,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,   534,
     386,    26,    27,    28,    29,     0,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,     0,
      43,    44,    45,   535,   536,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,     0,    66,    67,    68,    69,    70,    71,
      72,    73,     0,     0,    74,    75,     0,     0,     0,    76,
      77,   488,    79,    80,    81,    82,    83,   537,    85,    86,
       0,     0,     0,    87,     0,    88,    89,    90,    91,     0,
      92,     0,     0,     0,    93,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,    98,    99,   100,   101,   102,
     103,   104,   538,     0,     0,   106,   107,   108,   109,   110,
       0,     0,     0,     0,   111,   112,   113,   114,   115,   116,
     117,   118,     0,   119,     0,   120,   121,     0,     0,   122,
     123,   124,     0,     0,     0,   125,   880,   126,   127,     0,
     128,   129,   130,     0,   131,     0,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,     0,     0,   143,
     144,   145,     0,   387,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   505,   506,   507,
     173,   174,   508,   540,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
     192,     0,   193,   194,   195,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,     1,
       0,     0,     0,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     0,     0,     8,     0,     0,     0,   384,
     385,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,  1041,   386,    26,    27,    28,
      29,     0,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,     0,    43,    44,    45,  1042,
    1043,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,     0,
      66,    67,    68,    69,    70,    71,    72,    73,     0,     0,
      74,    75,     0,     0,     0,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,     0,     0,     0,    87,
       0,    88,    89,    90,    91,     0,    92,     0,     0,     0,
      93,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,    98,    99,   100,   101,   102,   103,   104,   105,     0,
       0,   106,   107,   108,   109,   110,     0,     0,     0,     0,
     111,   112,   113,   114,   115,   116,   117,   118,     0,   119,
       0,   120,   121,     0,     0,   122,   123,   124,     0,   531,
       0,   125,     0,   126,   127,     0,   128,   129,   130,     0,
     131,     0,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,     0,     0,   143,   144,   145,     0,   387,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,  1044,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,   192,     0,   193,   194,
     195,   196,   197,   198,     0,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,     1,     0,     0,     0,     0,
       0,     0,     0,     2,     3,     4,     5,     6,     7,     0,
       0,     8,     0,     0,     0,   384,   385,     0,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,   386,    26,    27,    28,    29,     0,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,     0,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,     0,    66,    67,    68,    69,
      70,    71,    72,    73,     0,     0,    74,    75,     0,     0,
       0,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,     0,     0,     0,    87,     0,    88,    89,    90,
      91,     0,    92,     0,     0,     0,    93,    94,    95,    96,
      97,     0,     0,     0,     0,     0,     0,    98,    99,   100,
     101,   102,   103,   104,   105,     0,     0,   106,   107,   108,
     109,   110,     0,     0,     0,     0,   111,   112,   113,   114,
     115,   116,   117,   118,     0,   119,     0,   120,   121,     0,
       0,   122,   123,   124,     0,     0,     0,   125,     0,   126,
     127,     0,   128,   129,   130,     0,   131,     0,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,     0,
       0,   143,   144,   145,     0,   387,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,   192,     0,   193,   194,   195,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,     1,     0,     0,     0,     0,     0,     0,     0,     2,
       3,     4,     5,     6,     7,     0,     0,     8,     0,     0,
       0,     9,    10,     0,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,     0,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,     0,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,     0,    66,    67,    68,    69,    70,    71,    72,    73,
       0,     0,    74,    75,     0,     0,     0,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,     0,     0,
       0,    87,     0,    88,    89,    90,    91,     0,    92,     0,
       0,     0,    93,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,    98,    99,   100,   101,   102,   103,   104,
     105,     0,     0,   106,   107,   108,   109,   110,     0,     0,
       0,     0,   111,   112,   113,   114,   115,   116,   117,   118,
       0,   119,     0,   120,   121,     0,     0,   122,   123,   124,
       0,     0,     0,   125,     0,   126,   127,     0,   128,   129,
     130,     0,   131,     0,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,     0,     0,   143,   144,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,     0,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     1,     0,     0,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       7,     0,     0,     8,     0,     0,     0,     9,    10,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,     0,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,     0,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,     0,    66,    67,
      68,    69,    70,    71,    72,    73,     0,     0,    74,    75,
       0,     0,     0,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,     0,     0,     0,    87,     0,    88,
      89,    90,    91,     0,    92,     0,     0,     0,    93,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,    98,
      99,   100,   101,   102,   103,   104,   105,     0,     0,   106,
     107,   108,   109,   110,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,     0,   119,     0,   120,
     121,     0,     0,   122,   123,   124,     0,     0,     0,   125,
       0,   126,   127,     0,   128,   129,   130,     0,   131,     0,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,     0,     0,   143,   144,   145,     0,   387,   147,   148,
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
       0,     2,     3,     4,     5,     6,     7,     0,     0,     8,
       0,     0,     0,   384,   385,     0,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,   474,    23,   476,
     386,    26,   477,    28,    29,     0,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,   479,     0,
      43,    44,    45,   481,   482,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,     0,    66,    67,    68,    69,    70,    71,
      72,    73,     0,     0,    74,    75,     0,     0,     0,    76,
      77,   488,    79,    80,    81,    82,    83,   537,    85,    86,
       0,     0,     0,    87,     0,    88,    89,    90,    91,     0,
      92,     0,     0,     0,   491,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,    98,    99,   100,   101,   102,
     103,   104,   538,     0,     0,   106,   107,   646,   109,   110,
       0,     0,     0,     0,   111,   112,   113,   114,   115,   116,
     117,   118,     0,   119,     0,   647,   121,     0,     0,   122,
     123,   124,     0,     0,     0,   125,     0,   126,   127,     0,
     128,   129,   130,     0,   131,     0,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,     0,     0,   143,
     144,   145,     0,   387,   147,   148,   149,   150,   151,   152,
     153,   154,   500,   156,   501,   158,   502,   503,   161,   162,
     163,   164,   165,   166,   504,   168,   169,   505,   506,   507,
     173,   174,   508,   509,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
     192,     0,   193,   194,   195,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,     1,
       0,     0,     0,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     0,     0,     8,     0,     0,     0,   384,
     385,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,   534,   386,    26,    27,    28,
      29,     0,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,     0,    43,    44,    45,   535,
     536,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,     0,
      66,    67,    68,    69,    70,    71,    72,    73,     0,     0,
      74,    75,     0,     0,     0,    76,    77,   488,    79,    80,
      81,    82,    83,   537,    85,    86,     0,     0,     0,    87,
       0,    88,    89,    90,    91,     0,    92,     0,     0,     0,
      93,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,    98,    99,   100,   101,   102,   103,   104,   538,     0,
       0,   106,   107,   108,   109,   110,     0,     0,     0,     0,
     111,   112,   113,   114,   115,   116,   117,   118,     0,   119,
       0,   120,   121,     0,     0,   122,   123,   124,     0,     0,
       0,   125,     0,   126,   127,     0,   128,   129,   130,     0,
     131,     0,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,     0,     0,   143,   144,   145,     0,   387,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   505,   506,   507,   173,   174,   508,   540,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,   192,     0,   193,   194,
     195,   196,   197,   198,     0,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,     1,     0,     0,     0,     0,
       0,     0,     0,     2,     3,     4,     5,     6,     7,     0,
       0,     8,     0,     0,     0,     9,   385,     0,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,     0,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,     0,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,     0,    66,    67,    68,    69,
      70,    71,    72,    73,     0,     0,    74,    75,     0,     0,
       0,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,     0,     0,     0,    87,     0,    88,    89,    90,
      91,     0,    92,     0,     0,     0,    93,    94,    95,    96,
      97,     0,     0,     0,     0,     0,     0,    98,    99,   100,
     101,   102,   103,   104,   105,     0,     0,   106,   107,   108,
     109,   110,     0,     0,     0,     0,   111,   112,   113,   114,
     115,   116,   117,   118,     0,   119,     0,   120,   121,     0,
       0,   122,   123,   124,     0,     0,     0,   125,     0,   126,
     127,     0,   128,   129,   130,     0,   131,     0,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,     0,
       0,   143,   144,   145,     0,   387,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,   192,     0,   193,   194,   195,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,     1,     0,     0,     0,     0,     0,     0,     0,     2,
       3,     4,     5,     6,     7,     0,     0,     8,     0,     0,
       0,   829,   385,     0,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,   386,    26,
      27,    28,    29,     0,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,     0,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,     0,    66,    67,    68,    69,    70,    71,    72,    73,
       0,     0,    74,    75,     0,     0,     0,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,     0,     0,
       0,    87,     0,    88,    89,    90,    91,     0,    92,     0,
       0,     0,    93,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,    98,    99,   100,   101,   102,   103,   104,
     105,     0,     0,   106,   107,   108,   109,   110,     0,     0,
       0,     0,   111,   112,   113,   114,   115,   116,   117,   118,
       0,   119,     0,   120,   121,     0,     0,   122,   123,   124,
       0,     0,     0,   125,     0,   126,   127,     0,   128,   129,
     130,     0,   131,     0,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,     0,     0,   143,   144,   145,
       0,   387,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,     0,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     1,     0,     0,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       7,     0,     0,     8,     0,     0,     0,   384,   385,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   474,    23,   476,   386,    26,   477,    28,    29,     0,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,   479,     0,    43,    44,    45,   481,   482,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,     0,    66,    67,
      68,    69,    70,    71,    72,    73,     0,     0,    74,    75,
       0,     0,     0,    76,    77,   488,    79,    80,    81,    82,
      83,   537,    85,    86,     0,     0,     0,    87,     0,    88,
      89,    90,    91,     0,    92,     0,     0,     0,   491,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,    98,
      99,   100,   101,   102,   103,   104,   538,     0,     0,   106,
     107,   108,   109,   110,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,     0,   119,     0,   120,
     121,     0,     0,   122,   123,   124,     0,     0,     0,   125,
       0,   126,   127,     0,   128,   129,   130,     0,   131,     0,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,     0,     0,   143,   144,   145,     0,   387,   147,   148,
     149,   150,   151,   152,   153,   154,   500,   156,   501,   158,
     502,   503,   161,   162,   163,   164,   165,   166,   504,   168,
     169,   505,   506,   507,   173,   174,   508,   509,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,     1,     0,     0,     0,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     0,     0,     8,
       0,     0,     0,   384,   385,     0,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,  1041,
     386,    26,    27,    28,    29,     0,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,     0,
      43,    44,    45,  1042,  1043,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,     0,    66,    67,    68,    69,    70,    71,
      72,    73,     0,     0,    74,    75,     0,     0,     0,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
       0,     0,     0,    87,     0,    88,    89,    90,    91,     0,
      92,     0,     0,     0,    93,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,    98,    99,   100,   101,   102,
     103,   104,   105,     0,     0,   106,   107,   108,   109,   110,
       0,     0,     0,     0,   111,   112,   113,   114,   115,   116,
     117,   118,     0,   119,     0,   120,   121,     0,     0,   122,
     123,   124,     0,     0,     0,   125,     0,   126,   127,     0,
     128,   129,   130,     0,   131,     0,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,     0,     0,   143,
     144,   145,     0,   387,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,  1044,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
     192,     0,   193,   194,   195,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,     1,
       0,     0,     0,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     0,     0,     8,     0,     0,     0,   384,
     385,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,   474,    23,   476,   386,    26,   477,    28,
      29,     0,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,   479,     0,    43,    44,    45,   481,
     482,    48,   483,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,     0,
      66,    67,    68,    69,    70,    71,    72,    73,     0,     0,
      74,    75,     0,     0,     0,    76,    77,   488,    79,    80,
      81,    82,    83,   537,    85,    86,     0,     0,     0,    87,
       0,    88,    89,    90,    91,     0,    92,     0,     0,     0,
     491,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,    98,    99,   100,   101,   102,   103,   104,   538,     0,
       0,   106,   107,     0,   109,   110,     0,     0,     0,     0,
     111,   112,   113,   114,   115,   116,   117,   118,     0,   119,
       0,     0,     0,     0,     0,   122,   123,   124,     0,     0,
       0,   125,     0,   126,   127,     0,   128,   129,   130,     0,
     131,     0,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,     0,     0,   143,   144,   145,     0,   387,
     147,   148,   149,   150,   151,   152,   153,   154,   500,   156,
     501,   158,   502,   503,   161,   162,   163,   164,   165,   166,
     504,   168,   169,   505,   506,   507,   173,   174,   508,   509,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,   192,     0,   193,   194,
     195,   196,   197,   198,     0,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,     1,     0,     0,     0,     0,
       0,     0,     0,     2,     3,     4,     5,     6,     7,     0,
       0,     8,     0,     0,     0,   384,   385,     0,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,   474,
      23,   476,   386,    26,   477,    28,    29,     0,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
     479,     0,    43,    44,    45,   481,   482,    48,   483,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,     0,    66,    67,    68,    69,
      70,    71,    72,    73,     0,     0,    74,    75,     0,     0,
       0,    76,    77,   488,    79,    80,    81,    82,    83,   537,
      85,    86,     0,     0,     0,    87,     0,    88,    89,    90,
      91,     0,    92,     0,     0,     0,   491,    94,    95,    96,
      97,     0,     0,     0,     0,     0,     0,    98,    99,   100,
     101,   102,   103,   104,   538,     0,     0,   106,   107,     0,
     109,   110,     0,     0,     0,     0,   111,   112,   113,   114,
     115,   116,   117,   118,     0,   119,     0,     0,     0,     0,
       0,   122,   123,   124,     0,     0,     0,   125,     0,   126,
     127,     0,     0,     0,   130,     0,   131,     0,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,     0,
       0,   143,   144,   145,     0,   387,   147,   148,   149,   150,
     151,   152,   153,   154,   500,   156,   501,   158,   502,   503,
     161,   162,   163,   164,   165,   166,   504,   168,   169,   505,
     506,   507,   173,   174,   508,   509,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,   192,     0,   193,   194,   195,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,     1,     0,     0,     0,     0,     0,     0,     0,     2,
       0,     0,     0,     6,     7,     0,     0,   470,     0,     0,
       0,   384,   385,     0,    11,    12,    13,   471,    15,    16,
      17,   472,    19,   473,    21,   474,   475,   476,   386,    26,
     477,    28,    29,     0,    30,    31,    32,    33,   478,    35,
      36,    37,    38,    39,    40,    41,   479,     0,    43,   480,
      45,   481,   482,    48,   483,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,   484,   485,
      65,     0,    66,    67,    68,   486,     0,    71,    72,    73,
       0,     0,   487,    75,     0,     0,     0,     0,    77,   488,
      79,   489,   490,    82,    83,     0,     0,     0,     0,     0,
       0,     0,     0,    88,    89,    90,    91,     0,    92,     0,
       0,     0,   491,    94,    95,   492,   493,     0,     0,     0,
       0,     0,     0,    98,    99,   100,     0,   102,   103,   104,
       0,     0,     0,     0,     0,     0,   109,   110,     0,     0,
       0,     0,   111,   112,   113,   114,   494,   116,   117,   495,
       0,     0,     0,     0,     0,     0,     0,   496,   497,   124,
       0,     0,     0,   125,     0,   126,   498,     0,     0,     0,
     130,     0,   131,     0,   132,   133,   134,   135,   499,   137,
     138,   139,   140,   141,   142,     0,     0,   143,   144,     0,
       0,   387,   147,   148,   149,   150,   151,   152,   153,   154,
     500,   156,   501,   158,   502,   503,   161,   162,   163,   164,
     165,   166,   504,   168,   169,   505,   506,   507,   173,   174,
     508,   509,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,     0,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     1,     0,     0,
       0,     0,     0,     0,     0,     2,     0,     0,     0,     6,
       7,     0,     0,   470,     0,     0,     0,   384,   385,     0,
      11,    12,    13,   518,    15,    16,    17,   472,   519,   520,
      21,   474,   475,   476,   386,    26,   477,    28,    29,     0,
      30,    31,    32,    33,   521,    35,   522,   523,    38,    39,
      40,    41,   479,     0,    43,   524,    45,   481,   482,    48,
     483,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,   484,   485,    65,     0,    66,    67,
      68,   525,     0,    71,    72,    73,     0,     0,   487,    75,
       0,     0,     0,     0,    77,   488,    79,   489,   490,    82,
      83,     0,     0,     0,     0,     0,     0,     0,     0,    88,
      89,    90,    91,     0,    92,     0,     0,     0,   491,    94,
      95,   492,   493,     0,     0,     0,     0,     0,     0,    98,
      99,   100,     0,   102,   103,   104,     0,     0,     0,     0,
       0,     0,   109,   110,     0,     0,     0,     0,   111,   112,
     113,   114,   494,   116,   117,   495,     0,     0,     0,     0,
       0,     0,     0,   496,   497,   124,     0,     0,     0,   125,
       0,   126,   498,     0,     0,     0,   130,     0,   131,     0,
     132,   133,   134,   135,   499,   137,   138,   139,   140,   141,
     142,     0,     0,   143,   144,     0,     0,   387,   147,   148,
     149,   150,   151,   152,   153,   154,   500,   526,   501,   158,
     502,   503,   161,   162,   163,   164,   165,   166,   504,   168,
     169,   505,   506,   507,   173,   174,   508,   509,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   547,     0,     0,     0,     0,     0,     0,
       0,     6,     7,     0,     0,   753,     0,     0,     0,   384,
     385,     0,    11,    12,    13,   518,    15,    16,    17,   472,
     519,   520,    21,   474,   475,   476,   386,    26,   477,    28,
      29,     0,    30,    31,    32,    33,   521,    35,   522,   523,
      38,    39,    40,    41,   479,     0,    43,   524,    45,   481,
     482,    48,   483,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,   484,   485,    65,     0,
      66,    67,    68,   525,     0,    71,    72,    73,     0,     0,
     487,    75,     0,     0,     0,     0,    77,   488,    79,   489,
     490,    82,    83,     0,     0,     0,     0,     0,     0,     0,
       0,    88,    89,    90,    91,     0,    92,     0,     0,     0,
     491,    94,    95,   492,   493,     0,     0,     0,     0,     0,
       0,    98,    99,   100,     0,   102,   103,   104,     0,     0,
       0,     0,     0,     0,   109,   110,     0,     0,     0,     0,
     111,   112,   113,   114,   494,   116,   117,   495,     0,     0,
       0,     0,     0,     0,     0,   496,   497,   124,     0,     0,
       0,   125,   754,   126,   498,     0,     0,     0,     0,     0,
     131,     0,   132,   133,   134,   135,   499,   137,   138,   139,
     140,   141,   142,     0,     0,   143,   144,     0,     0,   387,
     147,   148,   149,   150,   151,   152,   153,   154,   500,   526,
     501,   158,   502,   503,   161,   162,   163,   164,   165,   166,
     504,   168,   169,   505,   506,   507,   173,   174,   508,   509,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,   192,     0,   193,   194,
     195,   196,   197,   198,     0,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   547,     0,     0,     0,     0,
       0,     0,     0,     6,     7,     0,     0,   470,     0,     0,
       0,   384,   385,     0,    11,    12,    13,   518,    15,    16,
      17,   472,   519,   520,    21,   474,   475,   476,   386,    26,
     477,    28,    29,     0,    30,    31,    32,    33,   521,    35,
     522,   523,    38,    39,    40,    41,   479,     0,    43,   524,
      45,   481,   482,    48,   483,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,   484,   485,
      65,     0,    66,    67,    68,   525,     0,    71,    72,    73,
       0,     0,   487,    75,     0,     0,     0,     0,    77,   488,
      79,   489,   490,    82,    83,     0,     0,     0,     0,     0,
       0,     0,     0,    88,    89,    90,    91,     0,    92,     0,
       0,     0,   491,    94,    95,   492,   493,     0,     0,     0,
       0,     0,     0,    98,    99,   100,     0,   102,   103,   104,
       0,     0,     0,     0,     0,     0,   109,   110,     0,     0,
       0,     0,   111,   112,   113,   114,   494,   116,   117,   495,
       0,     0,     0,     0,     0,     0,     0,   496,   497,   124,
       0,     0,     0,   125,     0,   126,   498,     0,     0,     0,
       0,     0,   131,     0,   132,   133,   134,   135,   499,   137,
     138,   139,   140,   141,   142,     0,     0,   143,   144,     0,
       0,   387,   147,   148,   149,   150,   151,   152,   153,   154,
     500,   526,   501,   158,   502,   503,   161,   162,   163,   164,
     165,   166,   504,   168,   169,   505,   506,   507,   173,   174,
     508,   509,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,     0,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   550,   551,     0,
       0,     0,     0,     6,     7,     0,     0,   470,     0,     0,
       0,   384,   385,     0,    11,    12,    13,   518,    15,    16,
      17,   472,   519,   520,    21,   474,   475,   476,   386,    26,
     477,    28,    29,     0,    30,    31,    32,    33,   521,    35,
     522,   523,    38,    39,    40,    41,   479,     0,    43,   524,
      45,   481,   482,    48,   483,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,   484,   485,
      65,     0,    66,    67,    68,   525,     0,    71,    72,    73,
       0,     0,   487,    75,     0,     0,     0,     0,    77,   488,
      79,   489,   490,    82,    83,     0,     0,     0,     0,     0,
       0,     0,     0,    88,    89,    90,    91,     0,    92,     0,
       0,     0,   491,    94,    95,   492,   493,     0,     0,     0,
       0,     0,     0,    98,    99,   100,     0,   102,   103,   104,
       0,     0,     0,     0,     0,     0,   109,   110,     0,     0,
       0,     0,   111,   112,   113,   114,   494,   116,   117,   495,
       0,     0,     0,     0,     0,     0,     0,   496,   497,   124,
       0,     0,     0,   125,     0,   126,   498,     0,     0,     0,
       0,     0,   131,     0,   132,   133,   134,   135,   499,   137,
     138,   139,   140,   141,   142,     0,     0,   143,   144,     0,
       0,   387,   147,   148,   149,   150,   151,   152,   153,   154,
     500,   526,   501,   158,   502,   503,   161,   162,   163,   164,
     165,   166,   504,   168,   169,   505,   506,   507,   173,   174,
     508,   509,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,     0,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     6,     7,     0,
       0,   470,     0,     0,     0,   384,   385,     0,    11,    12,
      13,   471,    15,    16,    17,   472,    19,   473,    21,   474,
    1082,   476,   386,    26,   477,    28,    29,     0,    30,    31,
      32,    33,   478,    35,    36,    37,    38,    39,    40,    41,
     479,     0,    43,   480,    45,   481,   482,    48,   483,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,   484,   485,    65,     0,    66,    67,    68,   486,
       0,    71,    72,    73,     0,     0,   487,    75,     0,     0,
       0,     0,    77,   488,    79,   489,   490,    82,    83,     0,
       0,     0,     0,     0,     0,     0,     0,    88,    89,    90,
      91,     0,    92,     0,     0,     0,   491,    94,    95,   492,
     493,     0,     0,     0,     0,     0,     0,    98,    99,   100,
       0,   102,   103,  1083,     0,     0,     0,  1084,     0,     0,
     109,   110,     0,     0,     0,     0,   111,   112,   113,   114,
     494,   116,   117,   495,     0,     0,     0,     0,     0,     0,
       0,   496,   497,   124,     0,     0,     0,   125,  1490,   126,
     498,     0,     0,     0,  1491,     0,   131,     0,   132,   133,
     134,   135,   499,   137,   138,   139,   140,   141,   142,     0,
       0,  1085,   144,     0,     0,   387,   147,   148,   149,   150,
     151,   152,   153,   154,   500,   156,   501,   158,   502,   503,
     161,   162,   163,   164,   165,   166,   504,   168,   169,   505,
     506,   507,   173,   174,   508,   509,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,   192,     0,   193,   194,   195,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,     6,     7,     0,     0,   470,     0,     0,     0,   384,
     385,     0,    11,    12,    13,   518,    15,    16,    17,   472,
     519,   520,    21,   474,   475,   476,   386,    26,   477,    28,
      29,     0,    30,    31,    32,    33,   521,    35,   522,   523,
      38,    39,    40,    41,   479,     0,    43,   524,    45,   481,
     482,    48,   483,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,   484,   485,    65,     0,
      66,    67,    68,   525,     0,    71,    72,    73,     0,     0,
     487,    75,     0,     0,     0,     0,    77,   488,    79,   489,
     490,    82,    83,     0,     0,     0,     0,     0,     0,     0,
       0,    88,    89,    90,    91,     0,    92,     0,     0,     0,
     491,    94,    95,   492,   493,     0,     0,     0,     0,     0,
       0,    98,    99,   100,     0,   102,   103,   104,     0,     0,
       0,     0,     0,     0,   109,   110,     0,     0,     0,     0,
     111,   112,   113,   114,   494,   116,   117,   495,     0,     0,
       0,     0,     0,     0,     0,   496,   497,   124,     0,     0,
       0,   125,   724,   126,   498,     0,     0,     0,   725,     0,
     131,     0,   132,   133,   134,   135,   499,   137,   138,   139,
     140,   141,   142,     0,     0,   143,   144,     0,     0,   387,
     147,   148,   149,   150,   151,   152,   153,   154,   500,   526,
     501,   158,   502,   503,   161,   162,   163,   164,   165,   166,
     504,   168,   169,   505,   506,   507,   173,   174,   508,   509,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,   192,     0,   193,   194,
     195,   196,   197,   198,     0,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,     6,     7,     0,     0,   470,
       0,     0,     0,   384,   385,     0,    11,    12,    13,   518,
      15,    16,    17,   472,   519,   520,    21,   474,   475,   476,
     386,    26,   477,    28,    29,     0,    30,    31,    32,    33,
     521,    35,   522,   523,    38,    39,    40,    41,   479,     0,
      43,   524,    45,   481,   482,    48,   483,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
     484,   485,    65,     0,    66,    67,    68,   525,     0,    71,
      72,    73,     0,     0,   487,    75,     0,     0,     0,     0,
      77,   488,    79,   489,   490,    82,    83,     0,     0,     0,
       0,     0,     0,     0,     0,    88,    89,    90,    91,     0,
      92,     0,     0,     0,   491,    94,    95,   492,   493,     0,
       0,     0,     0,     0,     0,    98,    99,   100,     0,   102,
     103,   104,     0,     0,     0,     0,     0,     0,   109,   110,
       0,     0,     0,     0,   111,   112,   113,   114,   494,   116,
     117,   495,     0,     0,     0,     0,     0,     0,     0,   496,
     497,   124,     0,     0,     0,   125,   771,   126,   498,     0,
       0,     0,   772,     0,   131,     0,   132,   133,   134,   135,
     499,   137,   138,   139,   140,   141,   142,     0,     0,   143,
     144,     0,     0,   387,   147,   148,   149,   150,   151,   152,
     153,   154,   500,   526,   501,   158,   502,   503,   161,   162,
     163,   164,   165,   166,   504,   168,   169,   505,   506,   507,
     173,   174,   508,   509,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
     192,     0,   193,   194,   195,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,     6,
       7,     0,     0,   470,     0,     0,     0,   384,   385,     0,
      11,    12,    13,   471,    15,    16,    17,   472,    19,   473,
      21,   474,  1082,   476,   386,    26,   477,    28,    29,     0,
      30,    31,    32,    33,   478,    35,    36,    37,    38,    39,
      40,    41,   479,     0,    43,   480,    45,   481,   482,    48,
     483,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,   484,   485,    65,     0,    66,    67,
      68,   486,     0,    71,    72,    73,     0,     0,   487,    75,
       0,     0,     0,     0,    77,   488,    79,   489,   490,    82,
      83,  1413,     0,     0,     0,     0,     0,     0,     0,    88,
      89,    90,    91,     0,    92,     0,     0,     0,   491,    94,
      95,   492,   493,     0,     0,     0,     0,     0,     0,    98,
      99,   100,     0,   102,   103,  1083,     0,     0,     0,  1084,
       0,     0,   109,   110,     0,     0,     0,     0,   111,   112,
     113,   114,   494,   116,   117,   495,     0,     0,     0,     0,
       0,     0,     0,   496,   497,   124,     0,     0,     0,   125,
       0,   126,   498,     0,     0,     0,     0,     0,   131,     0,
     132,   133,   134,   135,   499,   137,   138,   139,   140,   141,
     142,     0,     0,  1085,   144,     0,     0,   387,   147,   148,
     149,   150,   151,   152,   153,   154,   500,   156,   501,   158,
     502,   503,   161,   162,   163,   164,   165,   166,   504,   168,
     169,   505,   506,   507,   173,   174,   508,   509,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,     6,     7,     0,     0,   470,     0,     0,
       0,   384,   385,     0,    11,    12,    13,   471,    15,    16,
      17,   472,    19,   473,    21,   474,  1082,   476,   386,    26,
     477,    28,    29,     0,    30,    31,    32,    33,   478,    35,
      36,    37,    38,    39,    40,    41,   479,     0,    43,   480,
      45,   481,   482,    48,   483,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,   484,   485,
      65,     0,    66,    67,    68,   486,     0,    71,    72,    73,
       0,     0,   487,    75,     0,     0,     0,     0,    77,   488,
      79,   489,   490,    82,    83,  1544,     0,     0,     0,     0,
       0,     0,     0,    88,    89,    90,    91,     0,    92,     0,
       0,     0,   491,    94,    95,   492,   493,     0,     0,     0,
       0,     0,     0,    98,    99,   100,     0,   102,   103,  1083,
       0,     0,     0,  1084,     0,     0,   109,   110,     0,     0,
       0,     0,   111,   112,   113,   114,   494,   116,   117,   495,
       0,     0,     0,     0,     0,     0,     0,   496,   497,   124,
       0,     0,     0,   125,     0,   126,   498,     0,     0,     0,
       0,     0,   131,     0,   132,   133,   134,   135,   499,   137,
     138,   139,   140,   141,   142,     0,     0,  1085,   144,     0,
       0,   387,   147,   148,   149,   150,   151,   152,   153,   154,
     500,   156,   501,   158,   502,   503,   161,   162,   163,   164,
     165,   166,   504,   168,   169,   505,   506,   507,   173,   174,
     508,   509,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,     0,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     6,     7,     0,
       0,   470,     0,     0,     0,   384,   385,     0,    11,    12,
      13,   471,    15,    16,    17,   472,    19,   473,    21,   474,
    1082,   476,   386,    26,   477,    28,    29,     0,    30,    31,
      32,    33,   478,    35,    36,    37,    38,    39,    40,    41,
     479,     0,    43,   480,    45,   481,   482,    48,   483,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,   484,   485,    65,     0,    66,    67,    68,   486,
       0,    71,    72,    73,     0,     0,   487,    75,     0,     0,
       0,     0,    77,   488,    79,   489,   490,    82,    83,  1548,
       0,     0,     0,     0,     0,     0,     0,    88,    89,    90,
      91,     0,    92,     0,     0,     0,   491,    94,    95,   492,
     493,     0,     0,     0,     0,     0,     0,    98,    99,   100,
       0,   102,   103,  1083,     0,     0,     0,  1084,     0,     0,
     109,   110,     0,     0,     0,     0,   111,   112,   113,   114,
     494,   116,   117,   495,     0,     0,     0,     0,     0,     0,
       0,   496,   497,   124,     0,     0,     0,   125,     0,   126,
     498,     0,     0,     0,     0,     0,   131,     0,   132,   133,
     134,   135,   499,   137,   138,   139,   140,   141,   142,     0,
       0,  1085,   144,     0,     0,   387,   147,   148,   149,   150,
     151,   152,   153,   154,   500,   156,   501,   158,   502,   503,
     161,   162,   163,   164,   165,   166,   504,   168,   169,   505,
     506,   507,   173,   174,   508,   509,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,   192,     0,   193,   194,   195,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,     6,     7,     0,     0,   470,     0,     0,     0,   384,
     385,     0,    11,    12,    13,   471,    15,    16,    17,   472,
      19,   473,    21,   474,  1082,   476,   386,    26,   477,    28,
      29,     0,    30,    31,    32,    33,   478,    35,    36,    37,
      38,    39,    40,    41,   479,     0,    43,   480,    45,   481,
     482,    48,   483,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,   484,   485,    65,     0,
      66,    67,    68,   486,     0,    71,    72,    73,     0,     0,
     487,    75,     0,     0,     0,     0,    77,   488,    79,   489,
     490,    82,    83,     0,     0,     0,     0,     0,     0,     0,
       0,    88,    89,    90,    91,     0,    92,     0,     0,     0,
     491,    94,    95,   492,   493,     0,     0,     0,     0,     0,
       0,    98,    99,   100,     0,   102,   103,  1083,     0,     0,
       0,  1084,     0,     0,   109,   110,     0,     0,     0,     0,
     111,   112,   113,   114,   494,   116,   117,   495,     0,     0,
       0,     0,     0,     0,     0,   496,   497,   124,     0,     0,
       0,   125,     0,   126,   498,     0,     0,     0,     0,     0,
     131,     0,   132,   133,   134,   135,   499,   137,   138,   139,
     140,   141,   142,     0,     0,  1085,   144,     0,     0,   387,
     147,   148,   149,   150,   151,   152,   153,   154,   500,   156,
     501,   158,   502,   503,   161,   162,   163,   164,   165,   166,
     504,   168,   169,   505,   506,   507,   173,   174,   508,   509,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,   192,     0,   193,   194,
     195,   196,   197,   198,     0,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,     6,     7,     0,     0,   470,
       0,     0,     0,   384,   385,     0,    11,    12,    13,   471,
      15,    16,    17,   472,    19,   473,    21,   474,  1082,   476,
     386,    26,   477,    28,    29,     0,    30,    31,    32,    33,
     478,    35,    36,    37,    38,    39,    40,    41,   479,     0,
      43,   480,    45,   481,   482,    48,   483,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
     484,   485,    65,     0,    66,    67,    68,   486,     0,    71,
      72,    73,     0,     0,   487,    75,     0,     0,     0,     0,
      77,   488,    79,   489,   490,    82,    83,     0,     0,     0,
       0,     0,     0,     0,     0,    88,    89,    90,    91,     0,
      92,     0,     0,     0,   491,    94,    95,   492,   493,     0,
       0,     0,     0,     0,     0,    98,    99,   100,     0,   102,
     103,  1083,     0,     0,     0,  1084,     0,     0,   109,   110,
       0,     0,     0,     0,   111,   112,   113,   114,   494,   116,
     117,   495,     0,     0,     0,     0,     0,     0,     0,   496,
     497,   124,     0,     0,     0,   125,     0,   126,   498,     0,
       0,     0,     0,     0,   131,     0,   132,   133,   134,   135,
     499,   137,   138,   139,   140,   141,   142,     0,     0,   143,
     144,     0,     0,   387,   147,   148,   149,   150,   151,   152,
     153,   154,   500,   156,   501,   158,   502,   503,   161,   162,
     163,   164,   165,   166,   504,   168,   169,   505,   506,   507,
     173,   174,   508,   509,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
     192,     0,   193,   194,   195,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,     6,
       7,     0,     0,   470,     0,     0,     0,   384,   385,     0,
      11,    12,    13,   518,    15,    16,    17,   472,   519,   520,
      21,   474,   475,   476,   386,    26,   477,    28,    29,     0,
      30,    31,    32,    33,   521,    35,   522,   523,    38,    39,
      40,    41,   479,     0,    43,   524,    45,   481,   482,    48,
     483,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,   484,   485,    65,     0,    66,    67,
      68,   525,     0,    71,    72,    73,     0,     0,   487,    75,
       0,     0,     0,     0,    77,   488,    79,   489,   490,    82,
      83,     0,     0,     0,     0,     0,     0,     0,     0,    88,
      89,    90,    91,     0,    92,     0,     0,     0,   491,    94,
      95,   492,   493,     0,     0,     0,     0,     0,     0,    98,
      99,   100,     0,   102,   103,   104,     0,     0,     0,     0,
       0,     0,   109,   110,     0,     0,     0,     0,   111,   112,
     113,   114,   494,   116,   117,   495,     0,     0,     0,     0,
       0,     0,     0,   496,   497,   124,     0,     0,     0,   125,
       0,   126,   498,     0,     0,     0,     0,     0,   131,     0,
     132,   133,   134,   135,   499,   137,   138,   139,   140,   141,
     142,     0,     0,   143,   144,     0,     0,   387,   147,   148,
     149,   150,   151,   152,   153,   154,   500,   526,   501,   158,
     502,   503,   161,   162,   163,   164,   165,   166,   504,   168,
     169,   505,   506,   507,   173,   174,   508,   509,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,     6,     7,     0,     0,   470,     0,     0,
       0,   384,   385,     0,    11,    12,    13,     0,    15,    16,
      17,   472,     0,     0,    21,   474,   475,     0,   386,    26,
     477,    28,    29,     0,    30,    31,    32,    33,     0,    35,
       0,     0,    38,    39,    40,    41,   479,     0,    43,     0,
      45,     0,     0,    48,   483,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,   484,   485,
      65,     0,    66,    67,    68,     0,     0,    71,    72,    73,
       0,     0,   487,    75,     0,     0,     0,     0,    77,   488,
      79,   489,   490,    82,    83,     0,     0,     0,     0,     0,
       0,     0,     0,    88,    89,    90,    91,     0,    92,     0,
       0,     0,   491,    94,    95,   492,   493,     0,     0,     0,
       0,     0,     0,    98,    99,   100,     0,   102,   103,     0,
       0,     0,     0,     0,     0,     0,   109,   110,     0,     0,
       0,     0,   111,   112,   113,   114,   494,   116,   117,   495,
       0,     0,     0,     0,     0,     0,     0,   496,   497,   124,
       0,     0,     0,   125,     0,   126,   498,     0,     0,     0,
       0,     0,   131,     0,   132,   133,   134,   135,   499,   137,
     138,   139,   140,   141,   142,     0,     0,     0,   144,     0,
       0,   387,   147,   148,   149,   150,   151,   152,   153,   154,
     500,     0,   501,   158,   502,   503,   161,   162,   163,   164,
     165,   166,   504,   168,   169,   505,   506,   507,   173,   174,
       0,   509,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,     0,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,   633,   295,     3,     4,     5,     0,   176,   105,     3,
       4,     5,    70,   282,     3,     4,     5,   748,   787,   322,
     106,   634,   635,   636,   637,   246,    84,   245,   731,   760,
    1219,   998,   815,  1152,   392,   587,   588,   853,  1235,    70,
     261,   129,   676,   774,    34,  1020,   431,   982,   668,   107,
     585,   586,   587,   588,   945,     1,  1292,  1293,    27,    34,
     731,   119,   866,   121,   404,  1068,     8,   887,   613,    54,
     615,   616,   457,   618,     1,   620,   115,   462,   585,   586,
      28,     9,    10,   628,   629,     1,  1508,   445,   446,   903,
     430,     1,  1248,     1,    43,    92,   139,     1,     1,    94,
     104,   865,   866,  1325,    94,   105,    27,    43,  1716,    91,
      46,   105,    61,   453,   127,   133,   105,    92,    97,    94,
      97,    97,    35,    36,   104,    38,    39,   118,    25,   166,
      31,   115,   104,   104,  1742,   127,   104,    94,   107,   903,
     104,    77,   104,    56,   104,  1753,   104,    48,    92,    46,
     179,   104,   121,   213,   144,   959,   157,   155,    92,   297,
     298,   198,   431,   192,    27,     9,    10,   103,   972,   144,
     144,    27,   100,   937,   144,   173,    73,   146,   909,   197,
     193,   150,   221,   187,   153,   282,   107,   144,   457,   574,
     104,   251,   120,   462,   122,   959,     9,   110,   180,     5,
     121,   193,   182,     9,   183,   174,   183,   183,   972,   181,
     144,     5,   109,    26,   185,     9,   601,   185,  1454,   181,
     184,   150,   150,   181,   184,   146,   154,   270,   213,   165,
     172,   184,  1654,   853,   965,   184,   233,   325,  1427,   239,
     971,   187,   242,   171,   157,   239,  1365,  1016,   242,  1216,
     543,    94,  1068,  1069,   110,   889,   100,  1148,   253,   254,
     187,   964,   210,   191,  1239,   304,   251,  1202,   820,   821,
    1084,   187,   330,  1248,  1430,   333,   120,   187,   122,   187,
     270,   209,   282,   187,   187,  1507,   270,   256,   282,   233,
      92,   962,  1112,   964,   157,   270,   270,    92,  1301,   330,
     270,   157,   333,   216,   849,   104,   150,   120,   115,   122,
     154,   818,   819,   984,   120,   104,   122,   231,   131,   103,
    1084,   153,   662,   166,   130,   155,   120,   171,   122,   687,
     715,   104,    92,    53,    92,    55,   130,   150,   396,   397,
     124,    92,   400,   173,   150,   258,   404,   191,    51,   435,
      43,   115,   410,    46,   115,   104,   150,   443,   179,   417,
     104,   582,   104,   115,   104,   209,   452,   585,   586,  1605,
    1567,   192,   430,   459,   460,    94,   183,    97,   436,   139,
     104,   439,   468,   768,   769,   184,   144,   104,   746,   447,
    1194,  1510,   181,  1157,   104,   453,   454,   455,   456,   150,
     104,     9,   742,   461,   119,   745,   249,   250,   181,   252,
     103,   469,   214,   215,  1218,   104,   259,   104,    26,   214,
     215,  1657,   183,   126,    94,  1156,   269,   229,   813,   104,
    1194,   431,   184,   433,   229,   184,   266,   431,   281,   433,
     184,   181,   184,   273,   433,   104,   715,   166,  1068,  1069,
     119,  1640,   104,   283,  1218,  1430,   514,   457,   104,   545,
     184,    31,   462,   457,   181,  1168,   217,   218,   462,   265,
     528,   557,   165,  1364,   184,   128,   272,   574,    48,   537,
     184,   104,   104,   153,  1104,  1301,   104,   573,   574,    94,
     104,  1610,  1275,   104,  1310,   184,  1279,   184,   104,   768,
     769,   104,  1054,  1055,  1056,  1321,  1177,   104,    94,   184,
     104,   569,   120,   150,   122,   104,   115,     9,    10,  1054,
    1055,  1056,    27,   131,   110,   184,     9,    10,   248,  1333,
     249,   250,   184,   252,   187,   181,  1655,   174,   538,   144,
      52,   261,   150,   263,   538,    57,   104,   104,   119,   538,
     269,    92,   910,   911,   274,   275,   276,   915,   278,   181,
     280,   184,   281,   649,   652,   653,   184,   153,   654,  1333,
     184,  1632,  1633,   184,   574,   119,   150,   153,   184,   153,
     574,   184,    94,   133,   181,   585,   586,   587,   588,   947,
     184,   585,   586,   587,   588,   184,  1531,   147,   139,  1566,
     818,   601,   107,   824,   662,   150,   150,   601,   100,   153,
      97,  1415,  1673,   114,  1418,  1000,   121,   100,  1679,  1738,
     978,  1740,   680,   110,   982,   683,   184,   184,   120,   174,
     122,   163,   206,    40,   244,   245,    97,   120,    45,   122,
    1759,   146,   143,    50,    94,   150,   704,   179,   153,   110,
      97,  1415,   710,   711,  1418,   156,   145,   267,   150,  1428,
     110,    68,   154,   110,  1433,  1481,    23,   150,   953,   174,
     955,   154,   153,   162,   732,    32,   734,  1380,   141,   171,
    1312,  1301,   134,   150,   742,   119,   153,   745,   171,   190,
    1310,   749,   145,   779,   780,   781,   155,   783,   150,   191,
      65,  1321,    59,   153,   197,    70,   221,   153,   191,   162,
     173,   226,    92,   206,   173,   715,   813,   209,    52,    37,
    1005,   715,  1007,    57,    42,    43,   209,   190,   786,  1281,
     155,  1000,   134,   153,    97,    93,   195,   139,   738,   206,
      58,    75,    60,    61,   738,   103,   134,   110,   173,   738,
     115,    69,    97,  1046,   134,   113,   266,   815,   165,   139,
      94,   168,   150,   273,    94,   110,   124,  1070,   768,   769,
     195,    92,   153,   283,   768,   769,   183,    95,   836,   900,
     110,   115,   103,    97,  1588,  1554,  1590,   153,    40,  1558,
      40,   912,   260,    45,   260,    45,   110,   296,    50,   134,
      50,   208,   119,   271,   139,   271,   305,   865,   866,   867,
     868,  1196,   221,   813,   223,    52,    68,  1621,    68,   813,
      57,   221,   150,   223,  1588,   153,  1590,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,   332,   115,  1197,
    1472,  1473,   337,   150,  1202,   903,   153,  1651,   274,   275,
     276,   119,  1465,   150,   280,   150,   153,  1621,   153,   917,
    1245,  1481,  1666,   655,  1668,   119,   658,  1636,   150,   661,
     217,   218,   219,   119,  1605,  1044,   151,   228,   153,   230,
    1049,   119,   228,   119,   230,   119,   944,  1651,  1273,  1274,
     188,   189,   297,   298,   150,   953,   212,   955,   125,   126,
     153,   959,  1666,   221,  1668,   288,   289,   125,   126,   631,
     632,   638,   639,   165,   972,   165,   168,   221,   168,   640,
     641,   115,   867,   868,  1498,  1499,   238,   238,   153,   239,
    1288,   183,     0,   183,   104,   150,   164,    90,   187,    49,
     246,   196,    98,   151,  1576,  1577,   118,  1005,    99,  1007,
     166,   142,   153,   153,    27,   181,   208,   181,   208,   181,
      46,   129,   149,   115,   243,   290,   295,   184,   295,   137,
     138,   115,   140,   281,   150,   301,  1245,     1,   281,    70,
     148,  1067,   198,   115,   152,   139,   154,   104,   184,   150,
     150,   159,   139,    84,   153,   153,   153,    25,   153,   181,
    1000,   181,   150,   153,   153,  1063,  1000,   153,   176,    16,
     226,   153,    33,   210,    27,  1647,   107,   184,    46,   242,
     227,   187,   187,     3,  1409,   115,  1084,    55,   119,   165,
     121,   199,   200,   201,   202,   203,   204,   167,   167,  1397,
      69,   227,    92,    92,    92,    73,   146,   104,   104,    77,
      27,   157,   157,   124,  1054,  1055,  1056,   129,   243,   139,
    1054,  1055,  1056,   296,   115,   129,   181,   181,   284,   285,
     286,   287,   288,   184,   290,   291,   292,   293,   294,   104,
     108,   109,   110,   299,    92,   184,    43,   184,    94,    94,
     184,   184,   184,   181,   181,   150,    92,   221,   233,   139,
    1458,    31,   187,   115,   167,   139,   129,    92,    27,  1167,
     283,   223,  1170,   296,   150,   115,   115,   144,   251,    92,
     124,   115,   181,    94,   194,   157,   129,  1185,   129,   115,
     150,    97,    97,   144,   181,   181,  1194,   139,   166,    33,
     150,    27,   187,   115,  1529,    77,   242,   255,   104,   104,
    1208,   282,   150,   257,    27,  1540,  1541,   264,  1543,    27,
    1218,  1161,   153,   153,   153,  1550,   153,  1161,    27,   153,
     198,   153,  1161,  1531,   141,   233,  1273,   303,   187,   223,
     283,   223,   284,   141,  1270,  1271,  1272,   184,  1246,   184,
     223,   184,   184,   144,   144,   124,  1196,   144,   226,   115,
     115,    75,  1196,   104,   139,   181,   184,  1207,  1266,   184,
      97,   194,   129,  1207,     7,   229,   233,  1275,  1207,   187,
     183,  1279,   115,   103,   103,   184,  1226,   279,   247,   247,
     144,    76,  1226,    27,   104,   184,   184,  1226,   184,   330,
     283,   229,   333,    27,  1629,  1245,   268,   167,   229,   144,
     229,  1245,   144,   181,  1639,    94,   284,   285,   286,   287,
     288,   123,   290,   291,   292,   293,   294,   123,   181,   181,
     181,   299,   300,  1273,  1274,  1333,   183,   183,   183,  1273,
    1274,   183,  1667,   181,   254,   150,    92,   184,    27,    94,
     167,   144,    52,   184,    92,   183,   115,   193,   183,   115,
      92,    27,   262,  1361,   194,   104,   397,   104,   277,   400,
     284,   221,   115,   404,    92,    92,  1701,   183,   193,   410,
     115,   193,   221,   183,   115,   183,   417,    91,   180,  1387,
    1388,   195,   193,   115,   115,   183,   183,   150,   302,   430,
    1725,   302,   115,   183,   115,   436,   290,   115,   439,  1734,
     302,   184,   184,   284,   221,  1413,   447,  1415,   303,   115,
    1418,   303,   453,   454,   455,   456,   303,   245,   239,  1115,
     461,  1429,   973,   242,   904,   428,  1434,   686,   469,   242,
    1157,  1610,   423,  1655,   423,   589,   816,   970,  1167,   751,
    1297,  1449,  1059,  1186,  1390,  1295,  1292,  1208,  1213,  1216,
     528,  1221,   611,   664,  1239,   787,   612,  1673,  1679,  1409,
     318,   868,  1149,   955,  1114,  1409,  1266,  1276,   434,   434,
    1275,  1310,  1321,   514,  1481,  1069,  1314,  1478,  1078,   936,
    1137,  1353,  1501,  1311,    -1,    -1,    -1,   528,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   537,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1644,    -1,    -1,   569,    -1,
      -1,    -1,  1568,    -1,    -1,    -1,  1544,    -1,  1546,    -1,
    1548,    -1,    -1,    -1,    -1,    -1,    -1,  1555,    -1,    -1,
    1586,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1529,
    1588,    -1,  1590,    -1,    -1,  1529,    -1,    -1,    -1,    -1,
    1540,  1541,    -1,  1543,    -1,    -1,  1540,  1541,  1606,  1543,
    1550,  1609,    -1,    -1,    -1,    -1,  1550,    -1,    -1,    -1,
      -1,  1730,    -1,  1621,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   662,    -1,  1631,    -1,    -1,    -1,    -1,    -1,  1748,
      -1,    -1,    -1,    -1,  1642,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   683,  1651,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1659,    -1,    -1,    -1,    -1,  1664,    -1,  1666,    -1,
    1668,    -1,    -1,   704,    -1,    -1,    -1,    -1,    -1,   710,
     711,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1629,
    1688,    -1,    -1,    -1,    -1,  1629,    -1,    -1,    -1,  1639,
    1698,   732,    -1,   734,    -1,  1639,    -1,    -1,    -1,    -1,
      -1,   742,    -1,    -1,   745,    -1,  1714,    -1,   749,    -1,
      -1,    -1,    -1,  1721,    -1,    -1,    -1,  1667,    -1,  1727,
      -1,    -1,    -1,  1667,    -1,    -1,    -1,    -1,  1736,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1746,    -1,
      -1,    -1,    -1,    -1,  1752,   786,    -1,    -1,    -1,  1757,
      -1,  1701,    -1,    -1,    -1,    -1,    -1,  1701,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   815,  1725,    -1,    -1,    -1,    -1,
      -1,  1725,    -1,    -1,  1734,    -1,    -1,    25,    -1,    -1,
    1734,    -1,    -1,    -1,    -1,   836,    -1,    35,    36,    -1,
      38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    -1,
      -1,    -1,    -1,    -1,   865,   866,   867,   868,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   903,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     108,   109,   110,    -1,    -1,    -1,   917,    -1,    -1,    -1,
      -1,    -1,    -1,   561,   562,    -1,   564,   565,   566,   567,
      -1,    -1,    -1,    -1,   572,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   944,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   953,    -1,   955,   593,    -1,    -1,   959,   157,
      -1,    -1,    -1,   601,   602,    -1,    -1,    -1,   166,    -1,
      -1,   972,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,  1005,    -1,  1007,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   216,    -1,
      -1,    -1,   660,    -1,    -1,    -1,   664,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     258,    -1,  1063,    -1,    -1,    -1,    -1,    -1,   706,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1084,    -1,    -1,   284,   285,   286,   287,
     288,    -1,   290,   291,   292,   293,   294,    -1,    -1,    -1,
      -1,   299,   300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   750,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   775,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   785,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1167,    -1,    -1,  1170,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1185,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1194,    -1,    -1,    -1,    -1,    -1,    -1,
     838,    -1,    -1,    -1,    -1,    -1,    -1,  1208,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1218,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1246,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1266,    -1,   905,    -1,    -1,
      -1,    -1,    -1,    -1,  1275,    -1,    -1,    -1,  1279,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   942,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   961,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1333,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   983,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   994,   995,    -1,    -1,
    1361,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1009,    -1,    -1,  1012,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1387,  1388,  1026,  1027,
    1028,    -1,  1030,  1031,  1032,  1033,  1034,  1035,    -1,  1037,
    1038,    -1,  1040,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1413,    -1,  1415,    -1,    -1,  1418,    -1,    -1,
      -1,  1059,    -1,    -1,    -1,    -1,    -1,    -1,  1429,    -1,
      -1,    -1,    -1,  1434,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1449,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1172,    -1,  1174,    -1,  1176,    -1,
      -1,  1179,    -1,  1544,    -1,  1546,  1184,  1548,    -1,    -1,
      -1,    -1,    -1,    -1,  1555,    -1,    -1,    -1,  1196,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1205,    -1,    -1,
      -1,    -1,    -1,  1211,  1212,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1588,    -1,  1590,
      -1,    -1,  1230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1606,    -1,    -1,  1609,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1621,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1631,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1642,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1651,    -1,    -1,    -1,    -1,    -1,    -1,  1295,  1659,    -1,
      -1,    -1,    -1,  1664,    -1,  1666,    -1,  1668,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1688,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1698,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1714,    -1,    -1,    -1,    -1,    -1,    -1,
    1721,    -1,    -1,    -1,    -1,    -1,  1727,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1736,  1374,    -1,    -1,    -1,
    1378,    -1,    -1,    -1,  1382,  1746,  1384,    -1,  1386,    -1,
      -1,  1752,    -1,    -1,  1392,    -1,  1757,    -1,    -1,    -1,
      -1,    -1,  1400,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1408,  1409,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1426,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1437,
    1438,  1439,  1440,  1441,    -1,  1443,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1517,
      -1,  1519,    -1,    -1,  1522,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1530,    -1,    -1,    -1,    -1,  1535,  1536,    -1,
      -1,    -1,    -1,    -1,    -1,  1543,    -1,    -1,    -1,  1547,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1613,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1625,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1667,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1696,    -1,
      -1,    -1,    -1,  1701,    -1,    -1,    -1,    -1,  1706,    -1,
      -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    24,  1724,    -1,    27,    -1,
      -1,    -1,    31,    32,  1732,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,    -1,    -1,   102,   103,    -1,    -1,    -1,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    -1,
      -1,    -1,   121,    -1,   123,   124,   125,   126,    -1,   128,
      -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,
      -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,   148,
     149,   150,    -1,    -1,   153,   154,   155,   156,   157,    -1,
      -1,    -1,    -1,   162,   163,   164,   165,   166,   167,   168,
     169,    -1,   171,    -1,   173,   174,    -1,    -1,   177,   178,
     179,    -1,    -1,    -1,   183,    -1,   185,   186,    -1,   188,
     189,   190,    -1,   192,    -1,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,    -1,    -1,   207,   208,
     209,    -1,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,   256,   257,   258,
      -1,   260,   261,   262,   263,   264,   265,    -1,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,    -1,    -1,
     102,   103,    -1,    -1,    -1,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,    -1,    -1,    -1,   121,
      -1,   123,   124,   125,   126,    -1,   128,    -1,    -1,    -1,
     132,   133,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,
      -1,   143,   144,   145,   146,   147,   148,   149,   150,    -1,
      -1,   153,   154,   155,   156,   157,    -1,    -1,    -1,    -1,
     162,   163,   164,   165,   166,   167,   168,   169,    -1,   171,
      -1,   173,   174,    -1,    -1,   177,   178,   179,    -1,   181,
      -1,   183,    -1,   185,   186,    -1,   188,   189,   190,    -1,
     192,    -1,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,    -1,    -1,   207,   208,   209,    -1,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,    -1,   256,   257,   258,    -1,   260,   261,
     262,   263,   264,   265,    -1,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    20,    21,    22,    23,    24,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,    -1,    -1,   102,   103,    -1,    -1,
      -1,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,    -1,    -1,    -1,   121,    -1,   123,   124,   125,
     126,    -1,   128,    -1,    -1,    -1,   132,   133,   134,   135,
     136,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,
     146,   147,   148,   149,   150,    -1,    -1,   153,   154,   155,
     156,   157,    -1,    -1,    -1,    -1,   162,   163,   164,   165,
     166,   167,   168,   169,    -1,   171,    -1,   173,   174,    -1,
      -1,   177,   178,   179,    -1,    -1,    -1,   183,   184,   185,
     186,    -1,   188,   189,   190,    -1,   192,    -1,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,    -1,
      -1,   207,   208,   209,    -1,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,    -1,
     256,   257,   258,    -1,   260,   261,   262,   263,   264,   265,
      -1,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
      -1,    -1,   102,   103,    -1,    -1,    -1,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,    -1,    -1,
      -1,   121,    -1,   123,   124,   125,   126,    -1,   128,    -1,
      -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,
      -1,    -1,    -1,   143,   144,   145,   146,   147,   148,   149,
     150,    -1,    -1,   153,   154,   155,   156,   157,    -1,    -1,
      -1,    -1,   162,   163,   164,   165,   166,   167,   168,   169,
      -1,   171,    -1,   173,   174,    -1,    -1,   177,   178,   179,
      -1,   181,    -1,   183,    -1,   185,   186,    -1,   188,   189,
     190,    -1,   192,    -1,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,    -1,    -1,   207,   208,   209,
      -1,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,   256,   257,   258,    -1,
     260,   261,   262,   263,   264,   265,    -1,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,    -1,    -1,   102,   103,
      -1,    -1,    -1,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,    -1,    -1,    -1,   121,    -1,   123,
     124,   125,   126,    -1,   128,    -1,    -1,    -1,   132,   133,
     134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,
     144,   145,   146,   147,   148,   149,   150,    -1,    -1,   153,
     154,   155,   156,   157,    -1,    -1,    -1,    -1,   162,   163,
     164,   165,   166,   167,   168,   169,    -1,   171,    -1,   173,
     174,    -1,    -1,   177,   178,   179,    -1,    -1,    -1,   183,
     184,   185,   186,    -1,   188,   189,   190,    -1,   192,    -1,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,    -1,    -1,   207,   208,   209,    -1,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,   256,   257,   258,    -1,   260,   261,   262,   263,
     264,   265,    -1,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    24,    -1,    -1,    27,
      -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,    -1,    -1,   102,   103,    -1,    -1,    -1,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
      -1,    -1,    -1,   121,    -1,   123,   124,   125,   126,    -1,
     128,    -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,
      -1,    -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,
     148,   149,   150,    -1,    -1,   153,   154,   155,   156,   157,
      -1,    -1,    -1,    -1,   162,   163,   164,   165,   166,   167,
     168,   169,    -1,   171,    -1,   173,   174,    -1,    -1,   177,
     178,   179,    -1,    -1,    -1,   183,   184,   185,   186,    -1,
     188,   189,   190,    -1,   192,    -1,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,    -1,    -1,   207,
     208,   209,    -1,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,    -1,   256,   257,
     258,    -1,   260,   261,   262,   263,   264,   265,    -1,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,    -1,    -1,
     102,   103,    -1,    -1,    -1,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,    -1,    -1,    -1,   121,
      -1,   123,   124,   125,   126,    -1,   128,    -1,    -1,    -1,
     132,   133,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,
      -1,   143,   144,   145,   146,   147,   148,   149,   150,    -1,
      -1,   153,   154,   155,   156,   157,    -1,    -1,    -1,    -1,
     162,   163,   164,   165,   166,   167,   168,   169,    -1,   171,
      -1,   173,   174,    -1,    -1,   177,   178,   179,    -1,   181,
      -1,   183,    -1,   185,   186,    -1,   188,   189,   190,    -1,
     192,    -1,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,    -1,    -1,   207,   208,   209,    -1,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,    -1,   256,   257,   258,    -1,   260,   261,
     262,   263,   264,   265,    -1,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    20,    21,    22,    23,    24,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,    -1,    -1,   102,   103,    -1,    -1,
      -1,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,    -1,    -1,    -1,   121,    -1,   123,   124,   125,
     126,    -1,   128,    -1,    -1,    -1,   132,   133,   134,   135,
     136,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,
     146,   147,   148,   149,   150,    -1,    -1,   153,   154,   155,
     156,   157,    -1,    -1,    -1,    -1,   162,   163,   164,   165,
     166,   167,   168,   169,    -1,   171,    -1,   173,   174,    -1,
      -1,   177,   178,   179,    -1,    -1,    -1,   183,    -1,   185,
     186,    -1,   188,   189,   190,    -1,   192,    -1,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,    -1,
      -1,   207,   208,   209,    -1,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,    -1,
     256,   257,   258,    -1,   260,   261,   262,   263,   264,   265,
      -1,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
      -1,    -1,   102,   103,    -1,    -1,    -1,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,    -1,    -1,
      -1,   121,    -1,   123,   124,   125,   126,    -1,   128,    -1,
      -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,
      -1,    -1,    -1,   143,   144,   145,   146,   147,   148,   149,
     150,    -1,    -1,   153,   154,   155,   156,   157,    -1,    -1,
      -1,    -1,   162,   163,   164,   165,   166,   167,   168,   169,
      -1,   171,    -1,   173,   174,    -1,    -1,   177,   178,   179,
      -1,    -1,    -1,   183,    -1,   185,   186,    -1,   188,   189,
     190,    -1,   192,    -1,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,    -1,    -1,   207,   208,   209,
      -1,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,   256,   257,   258,    -1,
     260,   261,   262,   263,   264,   265,    -1,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,    -1,    -1,   102,   103,
      -1,    -1,    -1,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,    -1,    -1,    -1,   121,    -1,   123,
     124,   125,   126,    -1,   128,    -1,    -1,    -1,   132,   133,
     134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,
     144,   145,   146,   147,   148,   149,   150,    -1,    -1,   153,
     154,   155,   156,   157,    -1,    -1,    -1,    -1,   162,   163,
     164,   165,   166,   167,   168,   169,    -1,   171,    -1,   173,
     174,    -1,    -1,   177,   178,   179,    -1,    -1,    -1,   183,
      -1,   185,   186,    -1,   188,   189,   190,    -1,   192,    -1,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,    -1,    -1,   207,   208,   209,    -1,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,   256,   257,   258,    -1,   260,   261,   262,   263,
     264,   265,    -1,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    24,    -1,    -1,    27,
      -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,    -1,    -1,   102,   103,    -1,    -1,    -1,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
      -1,    -1,    -1,   121,    -1,   123,   124,   125,   126,    -1,
     128,    -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,
      -1,    -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,
     148,   149,   150,    -1,    -1,   153,   154,   155,   156,   157,
      -1,    -1,    -1,    -1,   162,   163,   164,   165,   166,   167,
     168,   169,    -1,   171,    -1,   173,   174,    -1,    -1,   177,
     178,   179,    -1,    -1,    -1,   183,    -1,   185,   186,    -1,
     188,   189,   190,    -1,   192,    -1,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,    -1,    -1,   207,
     208,   209,    -1,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,    -1,   256,   257,
     258,    -1,   260,   261,   262,   263,   264,   265,    -1,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,    -1,    -1,
     102,   103,    -1,    -1,    -1,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,    -1,    -1,    -1,   121,
      -1,   123,   124,   125,   126,    -1,   128,    -1,    -1,    -1,
     132,   133,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,
      -1,   143,   144,   145,   146,   147,   148,   149,   150,    -1,
      -1,   153,   154,   155,   156,   157,    -1,    -1,    -1,    -1,
     162,   163,   164,   165,   166,   167,   168,   169,    -1,   171,
      -1,   173,   174,    -1,    -1,   177,   178,   179,    -1,    -1,
      -1,   183,    -1,   185,   186,    -1,   188,   189,   190,    -1,
     192,    -1,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,    -1,    -1,   207,   208,   209,    -1,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,    -1,   256,   257,   258,    -1,   260,   261,
     262,   263,   264,   265,    -1,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    20,    21,    22,    23,    24,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,    -1,    -1,   102,   103,    -1,    -1,
      -1,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,    -1,    -1,    -1,   121,    -1,   123,   124,   125,
     126,    -1,   128,    -1,    -1,    -1,   132,   133,   134,   135,
     136,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,
     146,   147,   148,   149,   150,    -1,    -1,   153,   154,   155,
     156,   157,    -1,    -1,    -1,    -1,   162,   163,   164,   165,
     166,   167,   168,   169,    -1,   171,    -1,   173,   174,    -1,
      -1,   177,   178,   179,    -1,    -1,    -1,   183,    -1,   185,
     186,    -1,   188,   189,   190,    -1,   192,    -1,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,    -1,
      -1,   207,   208,   209,    -1,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,    -1,
     256,   257,   258,    -1,   260,   261,   262,   263,   264,   265,
      -1,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
      -1,    -1,   102,   103,    -1,    -1,    -1,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,    -1,    -1,
      -1,   121,    -1,   123,   124,   125,   126,    -1,   128,    -1,
      -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,
      -1,    -1,    -1,   143,   144,   145,   146,   147,   148,   149,
     150,    -1,    -1,   153,   154,   155,   156,   157,    -1,    -1,
      -1,    -1,   162,   163,   164,   165,   166,   167,   168,   169,
      -1,   171,    -1,   173,   174,    -1,    -1,   177,   178,   179,
      -1,    -1,    -1,   183,    -1,   185,   186,    -1,   188,   189,
     190,    -1,   192,    -1,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,    -1,    -1,   207,   208,   209,
      -1,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,   256,   257,   258,    -1,
     260,   261,   262,   263,   264,   265,    -1,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,    -1,    -1,   102,   103,
      -1,    -1,    -1,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,    -1,    -1,    -1,   121,    -1,   123,
     124,   125,   126,    -1,   128,    -1,    -1,    -1,   132,   133,
     134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,
     144,   145,   146,   147,   148,   149,   150,    -1,    -1,   153,
     154,   155,   156,   157,    -1,    -1,    -1,    -1,   162,   163,
     164,   165,   166,   167,   168,   169,    -1,   171,    -1,   173,
     174,    -1,    -1,   177,   178,   179,    -1,    -1,    -1,   183,
      -1,   185,   186,    -1,   188,   189,   190,    -1,   192,    -1,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,    -1,    -1,   207,   208,   209,    -1,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,   256,   257,   258,    -1,   260,   261,   262,   263,
     264,   265,    -1,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    24,    -1,    -1,    27,
      -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,    -1,    -1,   102,   103,    -1,    -1,    -1,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
      -1,    -1,    -1,   121,    -1,   123,   124,   125,   126,    -1,
     128,    -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,
      -1,    -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,
     148,   149,   150,    -1,    -1,   153,   154,   155,   156,   157,
      -1,    -1,    -1,    -1,   162,   163,   164,   165,   166,   167,
     168,   169,    -1,   171,    -1,   173,   174,    -1,    -1,   177,
     178,   179,    -1,    -1,    -1,   183,    -1,   185,   186,    -1,
     188,   189,   190,    -1,   192,    -1,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,    -1,    -1,   207,
     208,   209,    -1,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,    -1,   256,   257,
     258,    -1,   260,   261,   262,   263,   264,   265,    -1,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,    -1,    -1,
     102,   103,    -1,    -1,    -1,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,    -1,    -1,    -1,   121,
      -1,   123,   124,   125,   126,    -1,   128,    -1,    -1,    -1,
     132,   133,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,
      -1,   143,   144,   145,   146,   147,   148,   149,   150,    -1,
      -1,   153,   154,    -1,   156,   157,    -1,    -1,    -1,    -1,
     162,   163,   164,   165,   166,   167,   168,   169,    -1,   171,
      -1,    -1,    -1,    -1,    -1,   177,   178,   179,    -1,    -1,
      -1,   183,    -1,   185,   186,    -1,   188,   189,   190,    -1,
     192,    -1,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,    -1,    -1,   207,   208,   209,    -1,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,    -1,   256,   257,   258,    -1,   260,   261,
     262,   263,   264,   265,    -1,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    20,    21,    22,    23,    24,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,    -1,    -1,   102,   103,    -1,    -1,
      -1,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,    -1,    -1,    -1,   121,    -1,   123,   124,   125,
     126,    -1,   128,    -1,    -1,    -1,   132,   133,   134,   135,
     136,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,
     146,   147,   148,   149,   150,    -1,    -1,   153,   154,    -1,
     156,   157,    -1,    -1,    -1,    -1,   162,   163,   164,   165,
     166,   167,   168,   169,    -1,   171,    -1,    -1,    -1,    -1,
      -1,   177,   178,   179,    -1,    -1,    -1,   183,    -1,   185,
     186,    -1,    -1,    -1,   190,    -1,   192,    -1,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,    -1,
      -1,   207,   208,   209,    -1,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,    -1,
     256,   257,   258,    -1,   260,   261,   262,   263,   264,   265,
      -1,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      -1,    -1,    -1,    23,    24,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    -1,    92,    93,    94,    95,    -1,    97,    98,    99,
      -1,    -1,   102,   103,    -1,    -1,    -1,    -1,   108,   109,
     110,   111,   112,   113,   114,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   123,   124,   125,   126,    -1,   128,    -1,
      -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,
      -1,    -1,    -1,   143,   144,   145,    -1,   147,   148,   149,
      -1,    -1,    -1,    -1,    -1,    -1,   156,   157,    -1,    -1,
      -1,    -1,   162,   163,   164,   165,   166,   167,   168,   169,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,   178,   179,
      -1,    -1,    -1,   183,    -1,   185,   186,    -1,    -1,    -1,
     190,    -1,   192,    -1,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,    -1,    -1,   207,   208,    -1,
      -1,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,   256,   257,   258,    -1,
     260,   261,   262,   263,   264,   265,    -1,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,    23,
      24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    -1,    92,    93,
      94,    95,    -1,    97,    98,    99,    -1,    -1,   102,   103,
      -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,   113,
     114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,
     124,   125,   126,    -1,   128,    -1,    -1,    -1,   132,   133,
     134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,
     144,   145,    -1,   147,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,   156,   157,    -1,    -1,    -1,    -1,   162,   163,
     164,   165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   177,   178,   179,    -1,    -1,    -1,   183,
      -1,   185,   186,    -1,    -1,    -1,   190,    -1,   192,    -1,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,    -1,    -1,   207,   208,    -1,    -1,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,   256,   257,   258,    -1,   260,   261,   262,   263,
     264,   265,    -1,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    -1,
      92,    93,    94,    95,    -1,    97,    98,    99,    -1,    -1,
     102,   103,    -1,    -1,    -1,    -1,   108,   109,   110,   111,
     112,   113,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   123,   124,   125,   126,    -1,   128,    -1,    -1,    -1,
     132,   133,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,
      -1,   143,   144,   145,    -1,   147,   148,   149,    -1,    -1,
      -1,    -1,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,
     162,   163,   164,   165,   166,   167,   168,   169,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   177,   178,   179,    -1,    -1,
      -1,   183,   184,   185,   186,    -1,    -1,    -1,    -1,    -1,
     192,    -1,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,    -1,    -1,   207,   208,    -1,    -1,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,    -1,   256,   257,   258,    -1,   260,   261,
     262,   263,   264,   265,    -1,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    24,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    -1,    92,    93,    94,    95,    -1,    97,    98,    99,
      -1,    -1,   102,   103,    -1,    -1,    -1,    -1,   108,   109,
     110,   111,   112,   113,   114,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   123,   124,   125,   126,    -1,   128,    -1,
      -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,
      -1,    -1,    -1,   143,   144,   145,    -1,   147,   148,   149,
      -1,    -1,    -1,    -1,    -1,    -1,   156,   157,    -1,    -1,
      -1,    -1,   162,   163,   164,   165,   166,   167,   168,   169,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,   178,   179,
      -1,    -1,    -1,   183,    -1,   185,   186,    -1,    -1,    -1,
      -1,    -1,   192,    -1,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,    -1,    -1,   207,   208,    -1,
      -1,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,   256,   257,   258,    -1,
     260,   261,   262,   263,   264,   265,    -1,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,    17,    18,    -1,
      -1,    -1,    -1,    23,    24,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    -1,    92,    93,    94,    95,    -1,    97,    98,    99,
      -1,    -1,   102,   103,    -1,    -1,    -1,    -1,   108,   109,
     110,   111,   112,   113,   114,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   123,   124,   125,   126,    -1,   128,    -1,
      -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,
      -1,    -1,    -1,   143,   144,   145,    -1,   147,   148,   149,
      -1,    -1,    -1,    -1,    -1,    -1,   156,   157,    -1,    -1,
      -1,    -1,   162,   163,   164,   165,   166,   167,   168,   169,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,   178,   179,
      -1,    -1,    -1,   183,    -1,   185,   186,    -1,    -1,    -1,
      -1,    -1,   192,    -1,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,    -1,    -1,   207,   208,    -1,
      -1,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,   256,   257,   258,    -1,
     260,   261,   262,   263,   264,   265,    -1,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,    23,    24,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    -1,    92,    93,    94,    95,
      -1,    97,    98,    99,    -1,    -1,   102,   103,    -1,    -1,
      -1,    -1,   108,   109,   110,   111,   112,   113,   114,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,   125,
     126,    -1,   128,    -1,    -1,    -1,   132,   133,   134,   135,
     136,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,
      -1,   147,   148,   149,    -1,    -1,    -1,   153,    -1,    -1,
     156,   157,    -1,    -1,    -1,    -1,   162,   163,   164,   165,
     166,   167,   168,   169,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   177,   178,   179,    -1,    -1,    -1,   183,   184,   185,
     186,    -1,    -1,    -1,   190,    -1,   192,    -1,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,    -1,
      -1,   207,   208,    -1,    -1,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,    -1,
     256,   257,   258,    -1,   260,   261,   262,   263,   264,   265,
      -1,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    -1,
      92,    93,    94,    95,    -1,    97,    98,    99,    -1,    -1,
     102,   103,    -1,    -1,    -1,    -1,   108,   109,   110,   111,
     112,   113,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   123,   124,   125,   126,    -1,   128,    -1,    -1,    -1,
     132,   133,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,
      -1,   143,   144,   145,    -1,   147,   148,   149,    -1,    -1,
      -1,    -1,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,
     162,   163,   164,   165,   166,   167,   168,   169,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   177,   178,   179,    -1,    -1,
      -1,   183,   184,   185,   186,    -1,    -1,    -1,   190,    -1,
     192,    -1,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,    -1,    -1,   207,   208,    -1,    -1,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,    -1,   256,   257,   258,    -1,   260,   261,
     262,   263,   264,   265,    -1,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,    23,    24,    -1,    -1,    27,
      -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    92,    93,    94,    95,    -1,    97,
      98,    99,    -1,    -1,   102,   103,    -1,    -1,    -1,    -1,
     108,   109,   110,   111,   112,   113,   114,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   123,   124,   125,   126,    -1,
     128,    -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,
      -1,    -1,    -1,    -1,    -1,   143,   144,   145,    -1,   147,
     148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,   157,
      -1,    -1,    -1,    -1,   162,   163,   164,   165,   166,   167,
     168,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,
     178,   179,    -1,    -1,    -1,   183,   184,   185,   186,    -1,
      -1,    -1,   190,    -1,   192,    -1,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,    -1,    -1,   207,
     208,    -1,    -1,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,    -1,   256,   257,
     258,    -1,   260,   261,   262,   263,   264,   265,    -1,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,    23,
      24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    -1,    92,    93,
      94,    95,    -1,    97,    98,    99,    -1,    -1,   102,   103,
      -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,   113,
     114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,
     124,   125,   126,    -1,   128,    -1,    -1,    -1,   132,   133,
     134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,
     144,   145,    -1,   147,   148,   149,    -1,    -1,    -1,   153,
      -1,    -1,   156,   157,    -1,    -1,    -1,    -1,   162,   163,
     164,   165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   177,   178,   179,    -1,    -1,    -1,   183,
      -1,   185,   186,    -1,    -1,    -1,    -1,    -1,   192,    -1,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,    -1,    -1,   207,   208,    -1,    -1,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,   256,   257,   258,    -1,   260,   261,   262,   263,
     264,   265,    -1,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,    23,    24,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    -1,    92,    93,    94,    95,    -1,    97,    98,    99,
      -1,    -1,   102,   103,    -1,    -1,    -1,    -1,   108,   109,
     110,   111,   112,   113,   114,   115,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   123,   124,   125,   126,    -1,   128,    -1,
      -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,
      -1,    -1,    -1,   143,   144,   145,    -1,   147,   148,   149,
      -1,    -1,    -1,   153,    -1,    -1,   156,   157,    -1,    -1,
      -1,    -1,   162,   163,   164,   165,   166,   167,   168,   169,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,   178,   179,
      -1,    -1,    -1,   183,    -1,   185,   186,    -1,    -1,    -1,
      -1,    -1,   192,    -1,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,    -1,    -1,   207,   208,    -1,
      -1,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,   256,   257,   258,    -1,
     260,   261,   262,   263,   264,   265,    -1,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,    23,    24,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    -1,    92,    93,    94,    95,
      -1,    97,    98,    99,    -1,    -1,   102,   103,    -1,    -1,
      -1,    -1,   108,   109,   110,   111,   112,   113,   114,   115,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,   125,
     126,    -1,   128,    -1,    -1,    -1,   132,   133,   134,   135,
     136,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,
      -1,   147,   148,   149,    -1,    -1,    -1,   153,    -1,    -1,
     156,   157,    -1,    -1,    -1,    -1,   162,   163,   164,   165,
     166,   167,   168,   169,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   177,   178,   179,    -1,    -1,    -1,   183,    -1,   185,
     186,    -1,    -1,    -1,    -1,    -1,   192,    -1,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,    -1,
      -1,   207,   208,    -1,    -1,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,    -1,
     256,   257,   258,    -1,   260,   261,   262,   263,   264,   265,
      -1,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    -1,
      92,    93,    94,    95,    -1,    97,    98,    99,    -1,    -1,
     102,   103,    -1,    -1,    -1,    -1,   108,   109,   110,   111,
     112,   113,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   123,   124,   125,   126,    -1,   128,    -1,    -1,    -1,
     132,   133,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,
      -1,   143,   144,   145,    -1,   147,   148,   149,    -1,    -1,
      -1,   153,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,
     162,   163,   164,   165,   166,   167,   168,   169,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   177,   178,   179,    -1,    -1,
      -1,   183,    -1,   185,   186,    -1,    -1,    -1,    -1,    -1,
     192,    -1,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,    -1,    -1,   207,   208,    -1,    -1,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,    -1,   256,   257,   258,    -1,   260,   261,
     262,   263,   264,   265,    -1,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,    23,    24,    -1,    -1,    27,
      -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    92,    93,    94,    95,    -1,    97,
      98,    99,    -1,    -1,   102,   103,    -1,    -1,    -1,    -1,
     108,   109,   110,   111,   112,   113,   114,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   123,   124,   125,   126,    -1,
     128,    -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,
      -1,    -1,    -1,    -1,    -1,   143,   144,   145,    -1,   147,
     148,   149,    -1,    -1,    -1,   153,    -1,    -1,   156,   157,
      -1,    -1,    -1,    -1,   162,   163,   164,   165,   166,   167,
     168,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,
     178,   179,    -1,    -1,    -1,   183,    -1,   185,   186,    -1,
      -1,    -1,    -1,    -1,   192,    -1,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,    -1,    -1,   207,
     208,    -1,    -1,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,    -1,   256,   257,
     258,    -1,   260,   261,   262,   263,   264,   265,    -1,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,    23,
      24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    -1,    92,    93,
      94,    95,    -1,    97,    98,    99,    -1,    -1,   102,   103,
      -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,   113,
     114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,
     124,   125,   126,    -1,   128,    -1,    -1,    -1,   132,   133,
     134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,
     144,   145,    -1,   147,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,   156,   157,    -1,    -1,    -1,    -1,   162,   163,
     164,   165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   177,   178,   179,    -1,    -1,    -1,   183,
      -1,   185,   186,    -1,    -1,    -1,    -1,    -1,   192,    -1,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,    -1,    -1,   207,   208,    -1,    -1,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,   256,   257,   258,    -1,   260,   261,   262,   263,
     264,   265,    -1,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,    23,    24,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    -1,    34,    35,    36,    -1,    38,    39,
      40,    41,    -1,    -1,    44,    45,    46,    -1,    48,    49,
      50,    51,    52,    -1,    54,    55,    56,    57,    -1,    59,
      -1,    -1,    62,    63,    64,    65,    66,    -1,    68,    -1,
      70,    -1,    -1,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    -1,    92,    93,    94,    -1,    -1,    97,    98,    99,
      -1,    -1,   102,   103,    -1,    -1,    -1,    -1,   108,   109,
     110,   111,   112,   113,   114,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   123,   124,   125,   126,    -1,   128,    -1,
      -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,
      -1,    -1,    -1,   143,   144,   145,    -1,   147,   148,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   156,   157,    -1,    -1,
      -1,    -1,   162,   163,   164,   165,   166,   167,   168,   169,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,   178,   179,
      -1,    -1,    -1,   183,    -1,   185,   186,    -1,    -1,    -1,
      -1,    -1,   192,    -1,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,    -1,    -1,    -1,   208,    -1,
      -1,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,    -1,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
      -1,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,   256,   257,   258,    -1,
     260,   261,   262,   263,   264,   265,    -1,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,    11,    19,    20,    21,    22,    23,    24,    27,    31,
      32,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    92,    93,    94,    95,
      96,    97,    98,    99,   102,   103,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   121,   123,   124,
     125,   126,   128,   132,   133,   134,   135,   136,   143,   144,
     145,   146,   147,   148,   149,   150,   153,   154,   155,   156,
     157,   162,   163,   164,   165,   166,   167,   168,   169,   171,
     173,   174,   177,   178,   179,   183,   185,   186,   188,   189,
     190,   192,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   207,   208,   209,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     256,   257,   258,   260,   261,   262,   263,   264,   265,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     322,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   343,   344,
     345,   346,   347,   348,   352,   353,   354,   358,   363,   372,
     375,   378,   379,   381,   383,   384,   385,   386,   388,   389,
     390,   391,   392,   393,   394,   395,   397,   398,   401,   402,
     403,   404,   405,   410,   412,   414,   415,   420,   439,   442,
     446,   449,   450,   455,   456,   457,   458,   460,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   506,   507,   508,
     522,   523,   525,   526,   527,   528,   529,   530,   531,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   551,
     552,   553,   554,   559,   560,   561,   562,   563,   564,   567,
     624,   626,   627,   628,    31,    32,    48,   211,   389,   389,
     389,    25,    35,    36,    38,    39,    46,    55,    56,    73,
      77,   108,   109,   110,   157,   166,   198,   216,   226,   258,
     284,   285,   286,   287,   288,   290,   291,   292,   293,   294,
     299,   300,   359,   360,   361,   364,   365,   366,   370,   371,
     157,   150,   153,   150,   153,   150,   153,    65,    70,   115,
     407,   153,   367,   153,    23,    32,    59,   115,   270,   419,
     421,   422,   150,   153,   153,   153,   115,   150,   153,   153,
     153,    92,   150,   217,   218,   119,   119,   119,   150,   153,
      27,    37,    41,    43,    45,    46,    47,    50,    58,    66,
      69,    71,    72,    74,    88,    89,    95,   102,   109,   111,
     112,   132,   135,   136,   166,   169,   177,   178,   186,   198,
     220,   222,   224,   225,   232,   235,   236,   237,   240,   241,
     490,   626,   627,   119,   115,   382,   119,   119,    37,    42,
      43,    58,    60,    61,    69,    95,   221,   626,   115,   119,
     119,   181,   389,   391,    47,    71,    72,   115,   150,   184,
     241,   402,   404,   414,   626,   150,   119,    15,   625,   626,
      17,    18,   626,   119,   119,   119,   482,   150,    28,   210,
     212,   221,   223,   153,   221,   223,   221,   221,   226,   115,
     238,   238,   239,   153,   150,   394,   324,     0,   326,   327,
      31,    48,   329,   346,     1,   187,   323,   187,   323,   104,
     187,   390,   391,   104,   187,    40,    45,    50,    68,   165,
     168,   183,   208,   396,   406,   411,   412,   413,   427,   428,
     432,   164,    90,   129,   137,   138,   140,   148,   152,   154,
     159,   176,   199,   200,   201,   202,   203,   204,   474,   475,
     246,   155,   173,   195,   114,   143,   156,   190,   197,   206,
     133,   147,    49,   196,    98,    99,   155,   173,   473,   150,
     479,   482,   188,   189,   151,   494,   495,   490,   494,   490,
     153,   494,   118,   142,   153,   181,   181,   181,   153,   624,
     179,   192,   179,   192,   163,   179,   627,   626,   166,   198,
      46,   626,   149,   115,    43,    46,    77,   103,   165,   625,
     217,   218,   219,   297,   298,   243,   597,   626,   290,   626,
     295,   295,   297,   298,   301,   134,   139,   109,   361,   364,
     284,   292,   371,   625,   390,   392,   184,   389,    43,    61,
     184,   547,   548,   402,   184,   190,   626,   281,   281,   416,
     417,   626,   115,   423,   115,   184,   368,   369,   150,   380,
     402,     1,   157,   624,   110,   157,   342,   624,   626,   115,
     139,   104,   402,    27,   184,   625,   626,   626,   440,   441,
     626,   390,   184,   402,   402,   549,   626,   390,   150,   150,
     402,   184,   190,   626,   626,   139,   440,   181,   181,   153,
     153,   153,   626,   150,   184,   183,    33,   510,   511,   512,
     402,     8,   172,    16,   402,   210,    27,   403,   403,   184,
     403,   403,   403,   403,   227,   565,   566,   626,   187,   187,
     403,   402,   391,   392,   402,   242,   399,   400,   187,   323,
     187,   323,     3,   330,   346,   388,   330,   346,   388,    31,
     347,   388,   347,   388,   382,   403,   115,   165,   167,   167,
     392,   403,   403,   457,   458,   460,   460,   460,   460,   459,
     460,   460,   460,    69,   464,   464,   463,   465,   465,   465,
     465,   466,   466,   467,   467,   227,    92,    92,    92,   181,
     402,   482,   482,   402,   495,   184,   403,   505,   625,   146,
     184,   505,    27,   362,   497,   104,   104,   367,    27,   627,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
     349,   350,   351,    92,   134,   139,   355,   356,   357,   626,
     157,   157,   349,   624,   124,   129,    53,    55,    97,   248,
     261,   263,   274,   275,   276,   278,   280,   598,   599,   600,
     601,   602,   603,   610,   616,   617,   243,    92,   233,   374,
     296,   626,   139,   403,   115,   626,   626,   129,   181,   181,
     184,   184,   181,   104,   184,   104,   184,   104,    34,    92,
      94,   144,   418,   419,   533,   626,    54,   213,   251,   408,
     409,   626,    92,   104,   184,   389,   184,   625,    94,    43,
     625,   624,    94,   139,   533,   626,   403,   422,   181,   184,
     184,   184,   184,   104,   185,   144,   533,   181,   184,   184,
     150,   181,   390,   390,   181,   104,   184,   104,   184,   139,
     533,   403,   185,   402,   402,   402,   626,   511,   512,   127,
     193,   181,   181,   128,   187,    92,   214,   215,   229,    92,
     214,   215,   229,    92,   233,   221,   104,   231,   139,   187,
     184,    47,    71,    72,   241,   404,   414,   181,   491,   570,
     400,   346,    31,    31,   187,   323,   187,   110,   626,   167,
     403,   433,   434,   115,   429,   430,   460,   150,   153,   256,
     478,   497,   571,   574,   575,   576,   577,   578,   582,   584,
     586,   587,    46,   149,   153,   207,   534,   536,   538,   539,
     555,   556,   557,   558,   626,   534,   532,   538,   532,   181,
     182,   104,   184,   184,   104,   184,   145,   162,   145,   162,
     134,   380,   367,   350,   129,   536,   357,   403,   533,   624,
     624,   125,   126,   624,   274,   275,   276,   280,   626,   260,
     271,   260,   271,    27,   283,    94,   110,   153,   604,   607,
     598,    37,    42,    58,    60,    69,    95,   221,   373,   539,
     288,   289,   223,   296,   305,   403,   626,    92,   374,   296,
     624,   150,   549,   550,   626,   549,   550,   115,   124,   534,
     115,   403,   144,   419,   144,    34,   144,   418,   419,   144,
     533,   251,    52,    57,    75,   115,   418,   424,   425,   426,
     409,   533,   534,   369,    92,   181,   194,   129,   341,   624,
     157,   129,    94,   341,   403,   139,   419,   150,   115,   403,
     403,   144,    97,   443,   444,   445,   447,   448,    97,   451,
     452,   453,   454,   390,   181,   181,   150,   549,   549,   403,
     139,   187,   403,   184,   184,   184,    33,   512,   127,   193,
       9,    10,   100,   120,   122,   150,   191,   507,   509,   520,
     521,   524,    27,   228,   230,   403,   403,   403,   228,   230,
     403,   403,   403,   403,   403,   403,   115,   403,   403,   403,
     153,   153,   153,   150,   183,   242,   568,   569,   153,   206,
     394,   187,   110,   388,   388,   388,   433,    93,   103,   113,
     124,   435,   436,   437,   438,   104,   626,   104,   402,   571,
     578,   150,   282,   461,   623,    94,   166,   249,   250,   252,
     259,   269,   281,   572,   573,   592,   593,   594,   595,   618,
     621,   255,   257,   579,   597,   264,   583,   619,   244,   245,
     267,   588,   589,   153,   153,   536,   153,   141,   173,   190,
     535,   141,   403,   497,   134,   380,   551,   356,   283,    27,
      94,   110,   153,   611,    27,   604,   374,   535,   223,   223,
     480,   284,   303,   533,   373,   223,   187,   389,   184,   184,
     141,   184,   184,   417,   144,   418,   626,   403,   144,   403,
     124,   403,   144,   419,   144,   403,   144,   115,   115,   403,
     626,   426,    75,   534,   392,   403,   624,   104,   341,   403,
     139,   389,   441,   403,   403,   110,   444,   445,    97,   183,
     110,   445,   448,   115,   534,    97,   110,   452,    97,   110,
     454,   181,   389,   184,   184,   403,   194,   451,   129,   191,
     509,     7,   390,   626,   191,   520,   187,   229,   229,   229,
     229,   233,   566,   183,   402,   402,   402,   570,   569,   115,
     491,   624,   125,   126,   437,   438,   438,   434,   103,   431,
     430,   181,   184,   571,   585,   247,   213,   251,   265,   272,
     622,    94,   253,   254,   620,   247,   575,   622,   463,   592,
     576,   144,   279,   580,   581,   620,   283,   591,    76,   590,
     184,   190,   534,   537,   184,   184,   184,    27,   133,   197,
     613,   614,   615,    27,   612,   613,   268,   608,   104,   605,
     167,   626,   254,   374,   480,   181,   403,   144,   403,   144,
     418,   403,   144,   403,   403,   626,   626,   425,   403,   123,
     123,    94,   624,   403,   181,   183,   183,   403,   392,   403,
     183,   183,   626,   183,   115,   534,   115,   183,   115,   534,
     183,   181,   110,   512,   626,   191,   181,   512,   626,   403,
     403,   403,   403,   403,   403,   184,   184,   184,   150,   153,
     387,   626,   438,   624,   181,   465,    51,   126,   463,   463,
     266,   273,   283,   596,   596,   577,   150,   277,    92,   184,
     104,   184,   611,   611,   615,   104,   184,    27,   609,   620,
     606,   607,   184,   376,   377,   480,   115,   221,   304,   284,
     167,   403,   403,   144,   403,    52,   392,   403,   341,   403,
     392,    92,   392,   403,   626,   183,   626,   403,   626,   183,
     392,   115,    91,   180,   513,   512,   626,   193,   512,   194,
     451,   402,   115,   104,   184,   463,   463,   195,   402,   534,
     534,    92,    27,   262,   104,   104,   438,   533,   626,   115,
     221,   626,   376,   403,   115,   534,    92,   183,    92,   626,
       5,   130,   516,   517,   519,   521,    26,   131,   514,   515,
     518,   521,   193,   512,   193,   110,   181,   626,   115,   394,
     463,   181,   534,   607,   377,   438,   302,   626,   115,   221,
     626,   183,   534,   392,   403,   534,   183,    91,   130,   519,
     180,   131,   518,   193,   115,   104,   184,   626,   403,   302,
     626,   115,   392,   403,   183,   183,   626,   115,   387,   104,
     184,   290,   302,   626,   183,   626,   115,   394,   303,   403,
     303,   104,   184,   626,   480,   480,   115,   387,   184,   195,
     626,   394,   284,   184,   626,   387,   221,   115,   626,   303,
     480
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
     575
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   321,   322,   322,   323,   324,   324,   324,   324,   325,
     325,   326,   326,   326,   326,   326,   326,   326,   326,   327,
     327,   327,   327,   328,   329,   329,   329,   330,   330,   330,
     330,   330,   331,   331,   331,   331,   331,   331,   331,   331,
     332,   332,   333,   334,   335,   335,   336,   336,   337,   337,
     338,   338,   338,   338,   339,   339,   339,   340,   340,   340,
     340,   341,   341,   342,   342,   343,   343,   343,   343,   344,
     345,   345,   346,   346,   346,   347,   347,   347,   347,   347,
     347,   347,   347,   348,   348,   349,   349,   350,   351,   351,
     351,   351,   351,   351,   351,   351,   351,   351,   352,   353,
     354,   355,   355,   356,   356,   356,   357,   358,   358,   358,
     359,   359,   359,   359,   360,   360,   361,   361,   362,   362,
     363,   363,   364,   364,   365,   365,   366,   366,   367,   367,
     367,   367,   368,   368,   369,   369,   370,   370,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   372,   372,   372,   372,   372,   372,   372,   372,
     373,   373,   374,   374,   375,   375,   376,   376,   377,   377,
     377,   377,   378,   378,   378,   378,   379,   380,   381,   381,
     382,   382,   382,   382,   383,   384,   385,   386,   386,   387,
     388,   389,   389,   389,   390,   390,   391,   391,   392,   392,
     392,   392,   392,   392,   392,   392,   392,   392,   392,   392,
     393,   394,   394,   395,   396,   397,   398,   399,   399,   400,
     400,   400,   400,   401,   402,   402,   403,   403,   403,   403,
     403,   403,   404,   404,   404,   404,   404,   404,   404,   405,
     406,   407,   407,   408,   408,   408,   409,   409,   410,   410,
     411,   412,   412,   412,   413,   413,   413,   413,   413,   414,
     414,   415,   416,   416,   417,   417,   417,   417,   417,   417,
     417,   417,   417,   417,   417,   417,   418,   419,   420,   421,
     421,   422,   422,   422,   422,   423,   423,   424,   424,   424,
     425,   425,   425,   426,   426,   426,   427,   428,   429,   429,
     430,   430,   431,   432,   432,   433,   433,   434,   434,   435,
     435,   435,   435,   435,   435,   435,   436,   436,   437,   437,
     438,   439,   439,   440,   440,   441,   441,   442,   443,   443,
     444,   445,   445,   446,   447,   447,   448,   449,   449,   450,
     450,   451,   451,   452,   452,   453,   453,   454,   454,   455,
     456,   456,   457,   457,   458,   458,   458,   458,   458,   459,
     458,   458,   458,   458,   460,   460,   461,   461,   462,   462,
     463,   463,   463,   464,   464,   464,   464,   464,   465,   465,
     465,   466,   466,   466,   467,   467,   468,   468,   469,   469,
     470,   470,   471,   471,   472,   472,   472,   472,   473,   473,
     473,   474,   474,   474,   474,   474,   474,   475,   475,   475,
     476,   476,   476,   476,   477,   477,   478,   478,   479,   479,
     479,   480,   480,   480,   480,   481,   482,   482,   482,   483,
     483,   484,   484,   484,   484,   485,   485,   486,   486,   486,
     486,   486,   486,   486,   487,   487,   488,   488,   489,   489,
     489,   489,   489,   490,   490,   491,   491,   492,   492,   492,
     493,   493,   493,   493,   494,   494,   495,   496,   496,   496,
     496,   496,   496,   496,   496,   496,   496,   497,   497,   498,
     498,   498,   499,   500,   500,   501,   502,   503,   504,   504,
     505,   505,   506,   506,   507,   507,   507,   508,   508,   508,
     508,   508,   508,   509,   509,   510,   510,   511,   512,   512,
     513,   513,   514,   514,   515,   515,   515,   515,   516,   516,
     517,   517,   517,   517,   518,   518,   519,   519,   520,   520,
     520,   520,   521,   521,   521,   521,   522,   522,   523,   523,
     524,   525,   525,   525,   525,   525,   525,   526,   527,   527,
     528,   528,   529,   530,   531,   531,   532,   532,   533,   534,
     534,   534,   535,   535,   535,   536,   536,   536,   536,   536,
     537,   537,   538,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   540,   541,   541,   541,   542,   543,   544,   544,
     544,   545,   545,   545,   545,   545,   546,   547,   547,   547,
     547,   547,   547,   547,   548,   549,   550,   551,   552,   552,
     553,   554,   555,   555,   556,   557,   557,   558,   559,   559,
     559,   560,   560,   560,   560,   560,   560,   560,   560,   560,
     560,   561,   561,   562,   562,   563,   564,   565,   565,   566,
     567,   568,   568,   569,   569,   569,   569,   570,   570,   571,
     572,   572,   573,   573,   574,   574,   575,   575,   576,   576,
     577,   577,   578,   579,   579,   580,   580,   581,   582,   582,
     582,   583,   583,   584,   585,   585,   586,   587,   587,   588,
     588,   589,   589,   589,   590,   590,   591,   591,   592,   592,
     592,   592,   592,   593,   594,   595,   596,   596,   596,   597,
     597,   598,   598,   598,   598,   598,   598,   598,   598,   599,
     599,   599,   599,   600,   600,   601,   602,   602,   603,   603,
     603,   604,   604,   605,   605,   606,   606,   607,   608,   608,
     609,   609,   610,   610,   610,   611,   611,   612,   612,   613,
     613,   614,   614,   615,   615,   616,   617,   617,   618,   618,
     618,   619,   620,   620,   620,   620,   621,   621,   622,   622,
     623,   624,   625,   625,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   628,
     628
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
       3,     4,     4,     5,     1,     2,     1,     4,     1,     3,
       2,     3,     1,     1,     4,     4,     5,     5,     2,     3,
       4,     5,     1,     3,     2,     3,     1,     2,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     1,     2,
       2,     2,     3,     4,     5,     6,     4,     5,     6,     7,
       1,     2,     3,     3,     8,     9,     1,     3,     1,     2,
       2,     3,    11,    14,    13,    22,     3,     3,     3,     2,
       2,     3,     4,     5,     5,     4,     5,     3,     3,     3,
       1,     1,     1,     0,     1,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     2,     2,     2,     8,     3,     1,     2,     3,
       7,    10,    13,     2,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     1,     1,     2,     4,     3,     5,     4,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     1,     4,     3,     5,     4,     6,     4,     6,
       5,     7,     4,     5,     5,     6,     3,     3,     2,     1,
       3,     4,     5,     3,     6,     4,     5,     1,     2,     3,
       1,     2,     1,     6,     3,     3,     2,     3,     1,     3,
       2,     3,     2,     3,     4,     1,     3,     1,     2,     1,
       1,     1,     2,     2,     2,     3,     1,     1,     2,     2,
       2,     5,     5,     1,     4,     3,     4,     8,     1,     2,
       3,     2,     3,     8,     1,     2,     3,     8,    10,     8,
      10,     1,     2,     4,     7,     1,     2,     4,     7,     8,
       1,     3,     1,     3,     1,     3,     3,     3,     3,     0,
       4,     3,     3,     3,     1,     5,     0,     1,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     4,     1,     4,     1,     4,
       1,     4,     1,     2,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     5,     5,     6,     3,     4,     1,     2,     3,     2,
       2,     1,     2,     2,     1,     1,     1,     3,     3,     1,
       1,     1,     2,     1,     2,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     1,     2,     2,     1,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     4,     1,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     3,     1,     4,     4,     3,     4,
       1,     3,     1,     1,     1,     1,     1,     4,     5,     8,
       9,     9,    10,     1,     2,     1,     2,     6,     0,     1,
       3,     3,     0,     1,     1,     1,     2,     2,     0,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     2,     3,     3,
       2,     1,     1,     1,     1,     1,     1,     4,     3,     7,
       3,     7,     4,     4,     3,     7,     1,     2,     2,     1,
       2,     3,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     4,     4,     3,     3,     3,     4,
       4,     3,     4,     6,     4,     6,     4,     3,     4,     6,
       6,     4,     6,     6,     4,     1,     2,     1,     1,     1,
       3,     3,     1,     1,     4,     5,     6,     3,     3,     3,
       3,     5,     7,     7,     5,     5,     5,     7,     7,     5,
       5,     3,     3,     5,     7,     5,     7,     1,     4,     3,
       5,     1,     2,     3,     7,    10,    13,     1,     3,     2,
       0,     1,     1,     2,     1,     3,     1,     3,     1,     4,
       1,     2,     3,     0,     1,     0,     1,     4,     2,     3,
       1,     0,     1,     4,     0,     1,     2,     1,     3,     0,
       1,     2,     2,     1,     0,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     1,     1,     1,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     1,     2,     2,     3,     1,     2,     2,     5,
       2,     1,     1,     0,     2,     1,     3,     4,     0,     2,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
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
  "\"'EQName #)'\"", "\"'*:QName'\"", "\"'element QName {'\"",
  "\"'attribute QName {'\"", "\"'processing-instruction NCName {'\"",
  "\"'QName'\"", "\"'EQName'\"", "\"'%QName'\"",
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
  "IndexKeySpec", "IntegrityConstraintDecl", "BlockExpr",
  "EnclosedStatementsAndOptionalExpr", "BlockVarDeclList", "BlockVarDecl",
  "AssignStatement", "ExitStatement", "WhileExpr", "FlowCtlStatement",
  "BracedExpr", "QueryBody", "StatementsAndOptionalExpr",
  "StatementsAndExpr", "Statements", "Statement", "ApplyStatement",
  "BlockStatement", "FLWORStatement", "ReturnStatement", "IfStatement",
  "TryStatement", "CatchListStatement", "CatchStatement",
  "VarDeclStatement", "Expr", "ExprSingle", "ExprSimple", "FLWORExpr",
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
       322,     0,    -1,   324,    -1,   307,   324,    -1,     1,     3,
      -1,   326,    -1,   325,   326,    -1,   327,    -1,   325,   327,
      -1,   211,   212,    27,   187,    -1,   211,   212,    27,   128,
      27,   187,    -1,   329,   187,   388,    -1,   346,   187,   388,
      -1,   329,   187,   346,   187,   388,    -1,   388,    -1,   329,
     323,   388,    -1,   346,   323,   388,    -1,   329,   187,   346,
     323,   388,    -1,   329,   323,   346,   187,   388,    -1,   328,
      -1,   328,   329,   187,    -1,   328,   346,   187,    -1,   328,
     329,   187,   346,   187,    -1,    32,   157,   625,   129,   624,
     187,    -1,   330,    -1,   329,   187,   330,    -1,   329,   323,
     330,    -1,   331,    -1,   339,    -1,   344,    -1,   345,    -1,
     353,    -1,   332,    -1,   333,    -1,   334,    -1,   335,    -1,
     336,    -1,   337,    -1,   338,    -1,   559,    -1,    31,    36,
     179,    -1,    31,    36,   192,    -1,    31,   110,   103,   624,
      -1,    31,    35,   624,    -1,    31,    38,   179,    -1,    31,
      38,   192,    -1,    31,    56,   166,    -1,    31,    56,   198,
      -1,    31,   110,   165,   124,   125,    -1,    31,   110,   165,
     124,   126,    -1,    31,    39,   179,   104,   145,    -1,    31,
      39,   179,   104,   162,    -1,    31,    39,   163,   104,   145,
      -1,    31,    39,   163,   104,   162,    -1,   340,    -1,   343,
      -1,    48,    23,     1,    -1,    48,    59,   624,    -1,    48,
      59,   342,   624,    -1,    48,    59,   624,    94,   341,    -1,
      48,    59,   342,   624,    94,   341,    -1,   624,    -1,   341,
     104,   624,    -1,   157,   625,   129,    -1,   110,    43,   157,
      -1,    48,    32,   624,    -1,    48,    32,   157,   625,   129,
     624,    -1,    48,    32,   624,    94,   341,    -1,    48,    32,
     157,   625,   129,   624,    94,   341,    -1,    31,   157,   625,
     129,   624,    -1,    31,   110,    43,   157,   624,    -1,    31,
     110,    46,   157,   624,    -1,   347,    -1,   346,   187,   347,
      -1,   346,   323,   347,    -1,   348,    -1,   352,    -1,   354,
      -1,   358,    -1,   363,    -1,   372,    -1,   375,    -1,   378,
      -1,    31,   110,    77,   349,    -1,    31,    77,   626,   349,
      -1,   350,    -1,   349,   350,    -1,   351,   129,   551,    -1,
      78,    -1,    86,    -1,    79,    -1,    80,    -1,    81,    -1,
      82,    -1,    87,    -1,    83,    -1,    84,    -1,    85,    -1,
      31,    55,   626,    27,    -1,    31,   258,   597,    -1,    31,
     108,   149,   355,    -1,    92,   536,   356,    -1,   356,    -1,
     357,    -1,   134,    -1,   134,   357,    -1,   139,   403,    -1,
      31,   359,   139,   403,    -1,    31,   359,   134,    -1,    31,
     359,   134,   139,   403,    -1,   109,   115,   626,    -1,   109,
     115,   626,   533,    -1,   360,   109,   115,   626,    -1,   360,
     109,   115,   626,   533,    -1,   361,    -1,   360,   361,    -1,
      25,    -1,    25,   153,   362,   184,    -1,   497,    -1,   362,
     104,   497,    -1,    31,   364,    -1,    31,   360,   364,    -1,
     365,    -1,   366,    -1,    46,   627,   367,   380,    -1,    46,
     627,   367,   134,    -1,    73,    46,   627,   367,   380,    -1,
      73,    46,   627,   367,   134,    -1,   153,   184,    -1,   153,
     368,   184,    -1,   153,   184,    92,   534,    -1,   153,   368,
     184,    92,   534,    -1,   369,    -1,   368,   104,   369,    -1,
     115,   626,    -1,   115,   626,   533,    -1,   371,    -1,   370,
     371,    -1,   285,    -1,   286,    -1,   287,    -1,   288,    -1,
     166,    -1,   198,    -1,   226,   298,    -1,   226,   297,    -1,
     299,   298,    -1,   299,   297,    -1,   290,    -1,   291,   290,
      -1,   294,   295,    -1,   293,   295,    -1,    31,   284,   626,
      -1,    31,   284,   626,   374,    -1,    31,   284,   626,    92,
     373,    -1,    31,   284,   626,    92,   373,   374,    -1,    31,
     370,   284,   626,    -1,    31,   370,   284,   626,   374,    -1,
      31,   370,   284,   626,    92,   373,    -1,    31,   370,   284,
     626,    92,   373,   374,    -1,   539,    -1,   539,   535,    -1,
     233,   289,   223,    -1,   233,   288,   223,    -1,    31,   292,
     626,   296,   223,   480,   167,   376,    -1,    31,   370,   292,
     626,   296,   223,   480,   167,   376,    -1,   377,    -1,   376,
     104,   377,    -1,   480,    -1,   480,   533,    -1,   480,   438,
      -1,   480,   533,   438,    -1,    31,   300,   301,   626,   296,
     284,   626,   115,   626,   302,   403,    -1,    31,   300,   301,
     626,   296,   284,   626,   221,   115,   626,   302,   290,   303,
     480,    -1,    31,   300,   301,   626,   296,   284,   626,   304,
     221,   115,   626,   302,   403,    -1,    31,   300,   301,   626,
     305,   303,   254,   284,   626,   221,   115,   626,   303,   480,
     195,   284,   626,   221,   115,   626,   303,   480,    -1,   150,
     389,   181,    -1,   150,   389,   181,    -1,   381,   104,   382,
      -1,   109,   382,    -1,   115,   626,    -1,   115,   626,   533,
      -1,   115,   626,   139,   403,    -1,   115,   626,   533,   139,
     403,    -1,   115,   626,   139,   403,   187,    -1,   237,   239,
     403,   187,    -1,   240,   153,   402,   184,   403,    -1,   235,
     238,   187,    -1,   236,   238,   187,    -1,   150,   402,   181,
      -1,   389,    -1,   390,    -1,   391,    -1,    -1,   402,    -1,
     392,   390,    -1,   392,    -1,   392,   391,    -1,   393,    -1,
     394,    -1,   386,    -1,   395,    -1,   397,    -1,   385,    -1,
     398,    -1,   450,    -1,   446,    -1,   383,    -1,   384,    -1,
     401,    -1,   404,   187,    -1,   150,   391,   181,    -1,   150,
     181,    -1,   414,   396,    -1,   183,   392,    -1,    47,   153,
     402,   184,   194,   392,   123,   392,    -1,   241,   394,   399,
      -1,   400,    -1,   399,   400,    -1,   242,   570,   394,    -1,
     242,   570,   153,   115,   626,   184,   394,    -1,   242,   570,
     153,   115,   626,   104,   115,   626,   184,   394,    -1,   242,
     570,   153,   115,   626,   104,   115,   626,   104,   115,   626,
     184,   394,    -1,   381,   187,    -1,   403,    -1,   402,   104,
     403,    -1,   405,    -1,   442,    -1,   449,    -1,   455,    -1,
     567,    -1,   404,    -1,   456,    -1,   439,    -1,   560,    -1,
     561,    -1,   563,    -1,   562,    -1,   564,    -1,   414,   406,
      -1,   183,   403,    -1,    65,   281,    -1,    70,   281,    -1,
     213,    -1,   251,    -1,    54,   251,    -1,   408,   424,    75,
     403,    -1,   408,    75,   403,    -1,    45,   407,   423,   409,
     409,    -1,    45,   407,   423,   409,    -1,    40,   115,   626,
      -1,   415,    -1,   420,    -1,   410,    -1,   412,    -1,   427,
      -1,   432,    -1,   428,    -1,   411,    -1,   412,    -1,   414,
     413,    -1,    45,   115,   416,    -1,   417,    -1,   416,   104,
     115,   417,    -1,   626,   144,   403,    -1,   626,    34,   124,
     144,   403,    -1,   626,   533,   144,   403,    -1,   626,   533,
      34,   124,   144,   403,    -1,   626,   418,   144,   403,    -1,
     626,    34,   124,   418,   144,   403,    -1,   626,   533,   418,
     144,   403,    -1,   626,   533,    34,   124,   418,   144,   403,
      -1,   626,   419,   144,   403,    -1,   626,   533,   419,   144,
     403,    -1,   626,   418,   419,   144,   403,    -1,   626,   533,
     418,   419,   144,   403,    -1,    94,   115,   626,    -1,   270,
     115,   626,    -1,    50,   421,    -1,   422,    -1,   421,   104,
     422,    -1,   115,   626,   139,   403,    -1,   115,   626,   533,
     139,   403,    -1,   419,   139,   403,    -1,   115,   626,   533,
     419,   139,   403,    -1,   115,   626,   144,   403,    -1,   115,
     626,   533,   144,   403,    -1,   425,    -1,   115,   626,    -1,
     115,   626,   425,    -1,   418,    -1,   418,   426,    -1,   426,
      -1,    57,   115,   626,    52,   115,   626,    -1,    52,   115,
     626,    -1,    57,   115,   626,    -1,   208,   403,    -1,   168,
     167,   429,    -1,   430,    -1,   429,   104,   430,    -1,   115,
     626,    -1,   115,   626,   431,    -1,   103,   624,    -1,   165,
     167,   433,    -1,    68,   165,   167,   433,    -1,   434,    -1,
     433,   104,   434,    -1,   403,    -1,   403,   435,    -1,   436,
      -1,   437,    -1,   438,    -1,   436,   437,    -1,   436,   438,
      -1,   437,   438,    -1,   436,   437,   438,    -1,    93,    -1,
     113,    -1,   124,   125,    -1,   124,   126,    -1,   103,   624,
      -1,    66,   115,   440,   185,   403,    -1,   132,   115,   440,
     185,   403,    -1,   441,    -1,   440,   104,   115,   441,    -1,
     626,   144,   403,    -1,   626,   533,   144,   403,    -1,    71,
     153,   402,   184,   443,   110,   183,   403,    -1,   444,    -1,
     443,   444,    -1,   445,   183,   403,    -1,    97,   403,    -1,
     445,    97,   403,    -1,    71,   153,   402,   184,   447,   110,
     183,   392,    -1,   448,    -1,   447,   448,    -1,   445,   183,
     392,    -1,    72,   153,   402,   184,   451,   110,   183,   403,
      -1,    72,   153,   402,   184,   451,   110,   115,   626,   183,
     403,    -1,    72,   153,   402,   184,   453,   110,   183,   392,
      -1,    72,   153,   402,   184,   451,   110,   115,   626,   183,
     392,    -1,   452,    -1,   451,   452,    -1,    97,   534,   183,
     403,    -1,    97,   115,   626,    92,   534,   183,   403,    -1,
     454,    -1,   453,   454,    -1,    97,   534,   183,   392,    -1,
      97,   115,   626,    92,   534,   183,   392,    -1,    47,   153,
     402,   184,   194,   403,   123,   403,    -1,   457,    -1,   456,
     164,   457,    -1,   458,    -1,   457,    90,   458,    -1,   460,
      -1,   460,   474,   460,    -1,   460,   475,   460,    -1,   460,
     129,   460,    -1,   460,   159,   460,    -1,    -1,   460,   154,
     459,   460,    -1,   460,   152,   460,    -1,   460,   140,   460,
      -1,   460,   138,   460,    -1,   462,    -1,   462,   246,    69,
     571,   461,    -1,    -1,   623,    -1,   463,    -1,   463,   195,
     463,    -1,   464,    -1,   463,   173,   464,    -1,   463,   155,
     464,    -1,   465,    -1,   464,   190,   465,    -1,   464,   114,
     465,    -1,   464,   143,   465,    -1,   464,   156,   465,    -1,
     466,    -1,   465,   197,   466,    -1,   465,   206,   466,    -1,
     467,    -1,   466,   147,   467,    -1,   466,   133,   467,    -1,
     468,    -1,   468,    49,   227,   534,    -1,   469,    -1,   469,
     196,    92,   534,    -1,   470,    -1,   470,    98,    92,   532,
      -1,   471,    -1,   471,    99,    92,   532,    -1,   473,    -1,
     472,   473,    -1,   173,    -1,   155,    -1,   472,   173,    -1,
     472,   155,    -1,   476,    -1,   480,    -1,   477,    -1,   199,
      -1,   204,    -1,   203,    -1,   202,    -1,   201,    -1,   200,
      -1,   148,    -1,   176,    -1,   137,    -1,    74,   150,   390,
     181,    -1,    74,   218,   150,   390,   181,    -1,    74,   217,
     150,   390,   181,    -1,    74,    92,   549,   150,   390,   181,
      -1,   478,   150,   181,    -1,   478,   150,   402,   181,    -1,
     479,    -1,   478,   479,    -1,   174,   626,    16,    -1,   174,
      17,    -1,   174,    18,    -1,   481,    -1,   481,   482,    -1,
     189,   482,    -1,   482,    -1,   188,    -1,   483,    -1,   483,
     188,   482,    -1,   483,   189,   482,    -1,   484,    -1,   493,
      -1,   485,    -1,   485,   494,    -1,   488,    -1,   488,   494,
      -1,   486,   490,    -1,   487,    -1,   102,   119,    -1,   111,
     119,    -1,    95,   119,    -1,   186,   119,    -1,   112,   119,
      -1,   136,   119,    -1,   135,   119,    -1,   490,    -1,    96,
     490,    -1,   489,   490,    -1,   117,    -1,   169,   119,    -1,
      88,   119,    -1,   178,   119,    -1,   177,   119,    -1,    89,
     119,    -1,   539,    -1,   491,    -1,   626,    -1,   492,    -1,
     190,    -1,    11,    -1,    19,    -1,   496,    -1,   493,   494,
      -1,   493,   153,   184,    -1,   493,   153,   505,   184,    -1,
     495,    -1,   494,   495,    -1,   151,   402,   182,    -1,   497,
      -1,   499,    -1,   500,    -1,   501,    -1,   504,    -1,   506,
      -1,   502,    -1,   503,    -1,   552,    -1,   379,    -1,   498,
      -1,   551,    -1,   107,    -1,   146,    -1,   121,    -1,   115,
     626,    -1,   153,   184,    -1,   153,   402,   184,    -1,   116,
      -1,   166,   150,   402,   181,    -1,   198,   150,   402,   181,
      -1,   627,   153,   184,    -1,   627,   153,   505,   184,    -1,
     403,    -1,   505,   104,   403,    -1,   507,    -1,   525,    -1,
     508,    -1,   522,    -1,   523,    -1,   154,   626,   512,   127,
      -1,   154,   626,   510,   512,   127,    -1,   154,   626,   512,
     193,   191,   626,   512,   193,    -1,   154,   626,   512,   193,
     509,   191,   626,   512,   193,    -1,   154,   626,   510,   512,
     193,   191,   626,   512,   193,    -1,   154,   626,   510,   512,
     193,   509,   191,   626,   512,   193,    -1,   520,    -1,   509,
     520,    -1,   511,    -1,   510,   511,    -1,    33,   626,   512,
     129,   512,   513,    -1,    -1,    33,    -1,   180,   514,   180,
      -1,    91,   516,    91,    -1,    -1,   515,    -1,   131,    -1,
     518,    -1,   515,   131,    -1,   515,   518,    -1,    -1,   517,
      -1,   130,    -1,   519,    -1,   517,   130,    -1,   517,   519,
      -1,    26,    -1,   521,    -1,     5,    -1,   521,    -1,   507,
      -1,    10,    -1,   524,    -1,   521,    -1,     9,    -1,   120,
      -1,   122,    -1,   150,   390,   181,    -1,   209,    28,   210,
      -1,   209,   210,    -1,   171,   625,   172,    -1,   171,   625,
       8,    -1,   100,     7,    -1,   526,    -1,   527,    -1,   528,
      -1,   529,    -1,   530,    -1,   531,    -1,    41,   150,   389,
     181,    -1,    20,   389,   181,    -1,    43,   150,   402,   181,
     150,   389,   181,    -1,    21,   389,   181,    -1,    95,   150,
     402,   181,   150,   389,   181,    -1,    69,   150,   390,   181,
      -1,    37,   150,   390,   181,    -1,    22,   389,   181,    -1,
      58,   150,   402,   181,   150,   389,   181,    -1,   538,    -1,
     538,   141,    -1,    92,   534,    -1,   536,    -1,   536,   535,
      -1,   207,   153,   184,    -1,   141,    -1,   190,    -1,   173,
      -1,   538,    -1,   539,    -1,   149,   153,   184,    -1,   555,
      -1,   558,    -1,   534,    -1,   537,   104,   534,    -1,   626,
      -1,   541,    -1,   547,    -1,   545,    -1,   548,    -1,   546,
      -1,   544,    -1,   543,    -1,   542,    -1,   540,    -1,   221,
     153,   184,    -1,    42,   153,   184,    -1,    42,   153,   547,
     184,    -1,    42,   153,   548,   184,    -1,    69,   153,   184,
      -1,    37,   153,   184,    -1,    58,   153,   184,    -1,    58,
     153,   625,   184,    -1,    58,   153,    27,   184,    -1,    95,
     153,   184,    -1,    95,   153,   626,   184,    -1,    95,   153,
     626,   104,   549,   184,    -1,    95,   153,   190,   184,    -1,
      95,   153,   190,   104,   549,   184,    -1,    60,   153,   626,
     184,    -1,    43,   153,   184,    -1,    43,   153,   626,   184,
      -1,    43,   153,   626,   104,   549,   184,    -1,    43,   153,
     626,   104,   550,   184,    -1,    43,   153,   190,   184,    -1,
      43,   153,   190,   104,   549,   184,    -1,    43,   153,   190,
     104,   550,   184,    -1,    61,   153,   626,   184,    -1,   626,
      -1,   626,   141,    -1,    27,    -1,   553,    -1,   554,    -1,
     626,   142,   146,    -1,    46,   367,   380,    -1,   556,    -1,
     557,    -1,    46,   153,   190,   184,    -1,    46,   153,   184,
      92,   534,    -1,    46,   153,   537,   184,    92,   534,    -1,
     153,   536,   184,    -1,    31,   216,   217,    -1,    31,   216,
     218,    -1,    31,   216,   219,    -1,   222,   221,   403,   229,
     403,    -1,   222,   221,   403,    92,   228,   229,   403,    -1,
     222,   221,   403,    92,   230,   229,   403,    -1,   222,   221,
     403,   214,   403,    -1,   222,   221,   403,   215,   403,    -1,
     222,   223,   403,   229,   403,    -1,   222,   223,   403,    92,
     228,   229,   403,    -1,   222,   223,   403,    92,   230,   229,
     403,    -1,   222,   223,   403,   214,   403,    -1,   222,   223,
     403,   215,   403,    -1,   220,   221,   403,    -1,   220,   223,
     403,    -1,   225,   221,   403,   233,   403,    -1,   225,   226,
     227,   221,   403,   233,   403,    -1,   224,   221,   403,    92,
     403,    -1,   232,   115,   565,   231,   403,   183,   403,    -1,
     566,    -1,   565,   104,   115,   566,    -1,   626,   139,   403,
      -1,   241,   150,   402,   181,   568,    -1,   569,    -1,   568,
     569,    -1,   242,   570,   387,    -1,   242,   570,   153,   115,
     626,   184,   387,    -1,   242,   570,   153,   115,   626,   104,
     115,   626,   184,   387,    -1,   242,   570,   153,   115,   626,
     104,   115,   626,   104,   115,   626,   184,   387,    -1,   491,
      -1,   570,   206,   491,    -1,   574,   572,    -1,    -1,   573,
      -1,   592,    -1,   573,   592,    -1,   575,    -1,   574,   259,
     575,    -1,   576,    -1,   575,   255,   576,    -1,   577,    -1,
     576,   257,   144,   577,    -1,   578,    -1,   256,   578,    -1,
     582,   579,   580,    -1,    -1,   597,    -1,    -1,   581,    -1,
     279,   150,   402,   181,    -1,   586,   583,    -1,   153,   571,
     184,    -1,   584,    -1,    -1,   619,    -1,   478,   150,   585,
     181,    -1,    -1,   571,    -1,   587,   588,    -1,   497,    -1,
     150,   402,   181,    -1,    -1,   589,    -1,   245,   590,    -1,
     244,   591,    -1,   267,    -1,    -1,    76,    -1,    -1,   283,
      -1,   593,    -1,   594,    -1,   595,    -1,   621,    -1,   618,
      -1,   166,    -1,   281,   463,   596,    -1,   250,   620,   596,
      -1,   283,    -1,   273,    -1,   266,    -1,   243,   598,    -1,
     597,   243,   598,    -1,   599,    -1,   600,    -1,   601,    -1,
     616,    -1,   602,    -1,   610,    -1,   603,    -1,   617,    -1,
      97,   271,    -1,    97,   260,    -1,   263,    -1,   278,    -1,
     248,   271,    -1,   248,   260,    -1,    55,   626,    27,    -1,
     274,    -1,    53,   274,    -1,   276,   604,    -1,   276,   153,
     604,   605,   184,    -1,    53,   276,    -1,   607,    -1,   110,
      -1,    -1,   104,   606,    -1,   607,    -1,   606,   104,   607,
      -1,    94,    27,   608,   609,    -1,    -1,   268,    27,    -1,
      -1,   620,   262,    -1,   275,   283,   611,   613,    -1,   275,
     283,   110,   613,    -1,    53,   275,   283,    -1,    94,    27,
      -1,   153,   612,   184,    -1,    27,    -1,   612,   104,    27,
      -1,    -1,   614,    -1,   615,    -1,   614,   615,    -1,   197,
     611,    -1,   133,   611,    -1,   261,    27,    -1,   280,    -1,
      53,   280,    -1,    94,   213,    -1,    94,   251,    -1,   252,
     247,    -1,   264,   620,   277,    -1,   253,   463,    -1,    94,
     126,   463,    -1,    94,    51,   463,    -1,   254,   463,   195,
     463,    -1,   269,   622,    -1,   249,   622,    -1,   272,    -1,
     265,    -1,   282,   247,   465,    -1,    27,    -1,    15,    -1,
     626,    -1,   627,    -1,    95,    -1,    37,    -1,    42,    -1,
      43,    -1,   149,    -1,    47,    -1,   221,    -1,    58,    -1,
      60,    -1,    61,    -1,    69,    -1,    72,    -1,    71,    -1,
     207,    -1,   240,    -1,   628,    -1,    23,    -1,   211,    -1,
     124,    -1,    36,    -1,   258,    -1,    35,    -1,   218,    -1,
     217,    -1,   143,    -1,    41,    -1,   256,    -1,   257,    -1,
     271,    -1,   260,    -1,   248,    -1,   282,    -1,   274,    -1,
     276,    -1,   275,    -1,   280,    -1,   252,    -1,   247,    -1,
      76,    -1,   213,    -1,   251,    -1,    51,    -1,   219,    -1,
     232,    -1,   299,    -1,   226,    -1,   199,    -1,   204,    -1,
     203,    -1,   202,    -1,   201,    -1,   200,    -1,    94,    -1,
     108,    -1,   109,    -1,   183,    -1,    45,    -1,    34,    -1,
      65,    -1,    70,    -1,    57,    -1,    52,    -1,    54,    -1,
      75,    -1,    40,    -1,   144,    -1,    50,    -1,   208,    -1,
     167,    -1,   168,    -1,   165,    -1,    68,    -1,    93,    -1,
     113,    -1,   125,    -1,   126,    -1,   103,    -1,    66,    -1,
     132,    -1,   185,    -1,    97,    -1,    92,    -1,   194,    -1,
     123,    -1,   164,    -1,    90,    -1,    49,    -1,   227,    -1,
      98,    -1,   195,    -1,   114,    -1,   156,    -1,   197,    -1,
     147,    -1,   133,    -1,    74,    -1,    99,    -1,   196,    -1,
     148,    -1,   179,    -1,   192,    -1,   157,    -1,   134,    -1,
     128,    -1,   163,    -1,   145,    -1,   162,    -1,    31,    -1,
      38,    -1,    56,    -1,   110,    -1,    39,    -1,    55,    -1,
     212,    -1,    48,    -1,    59,    -1,    32,    -1,    46,    -1,
     270,    -1,   246,    -1,   279,    -1,   281,    -1,   250,    -1,
     264,    -1,   277,    -1,   269,    -1,   249,    -1,   263,    -1,
     278,    -1,   268,    -1,   262,    -1,   261,    -1,   245,    -1,
     244,    -1,   267,    -1,   253,    -1,   254,    -1,   283,    -1,
     273,    -1,   272,    -1,   265,    -1,   225,    -1,   231,    -1,
     228,    -1,   222,    -1,   215,    -1,   214,    -1,   216,    -1,
     233,    -1,   223,    -1,   224,    -1,   230,    -1,   220,    -1,
     229,    -1,    64,    -1,    62,    -1,    73,    -1,   166,    -1,
     198,    -1,   239,    -1,   234,    -1,   237,    -1,   238,    -1,
     235,    -1,   236,    -1,   241,    -1,   242,    -1,    44,    -1,
     243,    -1,    63,    -1,   292,    -1,   290,    -1,   291,    -1,
     296,    -1,   297,    -1,   298,    -1,   293,    -1,   294,    -1,
     295,    -1,    77,    -1,    78,    -1,    79,    -1,    80,    -1,
      81,    -1,    82,    -1,    83,    -1,    84,    -1,    85,    -1,
      86,    -1,    87,    -1,   284,    -1,   285,    -1,   286,    -1,
     287,    -1,   288,    -1,   289,    -1,   300,    -1,   301,    -1,
     302,    -1,   303,    -1,   304,    -1,   305,    -1,   306,    -1,
      88,    -1,   102,    -1,   111,    -1,   169,    -1,   177,    -1,
     186,    -1,   135,    -1,    89,    -1,   112,    -1,   136,    -1,
     178,    -1,   624,   118,   625,    -1,    24,    -1
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
     433,   436,   440,   442,   444,   449,   454,   460,   466,   469,
     473,   478,   484,   486,   490,   493,   497,   499,   502,   504,
     506,   508,   510,   512,   514,   517,   520,   523,   526,   528,
     531,   534,   537,   541,   546,   552,   559,   564,   570,   577,
     585,   587,   590,   594,   598,   607,   617,   619,   623,   625,
     628,   631,   635,   647,   662,   676,   699,   703,   707,   711,
     714,   717,   721,   726,   732,   738,   743,   749,   753,   757,
     761,   763,   765,   767,   768,   770,   773,   775,   778,   780,
     782,   784,   786,   788,   790,   792,   794,   796,   798,   800,
     802,   805,   809,   812,   815,   818,   827,   831,   833,   836,
     840,   848,   859,   873,   876,   878,   882,   884,   886,   888,
     890,   892,   894,   896,   898,   900,   902,   904,   906,   908,
     911,   914,   917,   920,   922,   924,   927,   932,   936,   942,
     947,   951,   953,   955,   957,   959,   961,   963,   965,   967,
     969,   972,   976,   978,   983,   987,   993,   998,  1005,  1010,
    1017,  1023,  1031,  1036,  1042,  1048,  1055,  1059,  1063,  1066,
    1068,  1072,  1077,  1083,  1087,  1094,  1099,  1105,  1107,  1110,
    1114,  1116,  1119,  1121,  1128,  1132,  1136,  1139,  1143,  1145,
    1149,  1152,  1156,  1159,  1163,  1168,  1170,  1174,  1176,  1179,
    1181,  1183,  1185,  1188,  1191,  1194,  1198,  1200,  1202,  1205,
    1208,  1211,  1217,  1223,  1225,  1230,  1234,  1239,  1248,  1250,
    1253,  1257,  1260,  1264,  1273,  1275,  1278,  1282,  1291,  1302,
    1311,  1322,  1324,  1327,  1332,  1340,  1342,  1345,  1350,  1358,
    1367,  1369,  1373,  1375,  1379,  1381,  1385,  1389,  1393,  1397,
    1398,  1403,  1407,  1411,  1415,  1417,  1423,  1424,  1426,  1428,
    1432,  1434,  1438,  1442,  1444,  1448,  1452,  1456,  1460,  1462,
    1466,  1470,  1472,  1476,  1480,  1482,  1487,  1489,  1494,  1496,
    1501,  1503,  1508,  1510,  1513,  1515,  1517,  1520,  1523,  1525,
    1527,  1529,  1531,  1533,  1535,  1537,  1539,  1541,  1543,  1545,
    1547,  1552,  1558,  1564,  1571,  1575,  1580,  1582,  1585,  1589,
    1592,  1595,  1597,  1600,  1603,  1605,  1607,  1609,  1613,  1617,
    1619,  1621,  1623,  1626,  1628,  1631,  1634,  1636,  1639,  1642,
    1645,  1648,  1651,  1654,  1657,  1659,  1662,  1665,  1667,  1670,
    1673,  1676,  1679,  1682,  1684,  1686,  1688,  1690,  1692,  1694,
    1696,  1698,  1701,  1705,  1710,  1712,  1715,  1719,  1721,  1723,
    1725,  1727,  1729,  1731,  1733,  1735,  1737,  1739,  1741,  1743,
    1745,  1747,  1749,  1752,  1755,  1759,  1761,  1766,  1771,  1775,
    1780,  1782,  1786,  1788,  1790,  1792,  1794,  1796,  1801,  1807,
    1816,  1826,  1836,  1847,  1849,  1852,  1854,  1857,  1864,  1865,
    1867,  1871,  1875,  1876,  1878,  1880,  1882,  1885,  1888,  1889,
    1891,  1893,  1895,  1898,  1901,  1903,  1905,  1907,  1909,  1911,
    1913,  1915,  1917,  1919,  1921,  1923,  1927,  1931,  1934,  1938,
    1942,  1945,  1947,  1949,  1951,  1953,  1955,  1957,  1962,  1966,
    1974,  1978,  1986,  1991,  1996,  2000,  2008,  2010,  2013,  2016,
    2018,  2021,  2025,  2027,  2029,  2031,  2033,  2035,  2039,  2041,
    2043,  2045,  2049,  2051,  2053,  2055,  2057,  2059,  2061,  2063,
    2065,  2067,  2069,  2073,  2077,  2082,  2087,  2091,  2095,  2099,
    2104,  2109,  2113,  2118,  2125,  2130,  2137,  2142,  2146,  2151,
    2158,  2165,  2170,  2177,  2184,  2189,  2191,  2194,  2196,  2198,
    2200,  2204,  2208,  2210,  2212,  2217,  2223,  2230,  2234,  2238,
    2242,  2246,  2252,  2260,  2268,  2274,  2280,  2286,  2294,  2302,
    2308,  2314,  2318,  2322,  2328,  2336,  2342,  2350,  2352,  2357,
    2361,  2367,  2369,  2372,  2376,  2384,  2395,  2409,  2411,  2415,
    2418,  2419,  2421,  2423,  2426,  2428,  2432,  2434,  2438,  2440,
    2445,  2447,  2450,  2454,  2455,  2457,  2458,  2460,  2465,  2468,
    2472,  2474,  2475,  2477,  2482,  2483,  2485,  2488,  2490,  2494,
    2495,  2497,  2500,  2503,  2505,  2506,  2508,  2509,  2511,  2513,
    2515,  2517,  2519,  2521,  2523,  2527,  2531,  2533,  2535,  2537,
    2540,  2544,  2546,  2548,  2550,  2552,  2554,  2556,  2558,  2560,
    2563,  2566,  2568,  2570,  2573,  2576,  2580,  2582,  2585,  2588,
    2594,  2597,  2599,  2601,  2602,  2605,  2607,  2611,  2616,  2617,
    2620,  2621,  2624,  2629,  2634,  2638,  2641,  2645,  2647,  2651,
    2652,  2654,  2656,  2659,  2662,  2665,  2668,  2670,  2673,  2676,
    2679,  2682,  2686,  2689,  2693,  2697,  2702,  2705,  2708,  2710,
    2712,  2716,  2718,  2720,  2722,  2724,  2726,  2728,  2730,  2732,
    2734,  2736,  2738,  2740,  2742,  2744,  2746,  2748,  2750,  2752,
    2754,  2756,  2758,  2760,  2762,  2764,  2766,  2768,  2770,  2772,
    2774,  2776,  2778,  2780,  2782,  2784,  2786,  2788,  2790,  2792,
    2794,  2796,  2798,  2800,  2802,  2804,  2806,  2808,  2810,  2812,
    2814,  2816,  2818,  2820,  2822,  2824,  2826,  2828,  2830,  2832,
    2834,  2836,  2838,  2840,  2842,  2844,  2846,  2848,  2850,  2852,
    2854,  2856,  2858,  2860,  2862,  2864,  2866,  2868,  2870,  2872,
    2874,  2876,  2878,  2880,  2882,  2884,  2886,  2888,  2890,  2892,
    2894,  2896,  2898,  2900,  2902,  2904,  2906,  2908,  2910,  2912,
    2914,  2916,  2918,  2920,  2922,  2924,  2926,  2928,  2930,  2932,
    2934,  2936,  2938,  2940,  2942,  2944,  2946,  2948,  2950,  2952,
    2954,  2956,  2958,  2960,  2962,  2964,  2966,  2968,  2970,  2972,
    2974,  2976,  2978,  2980,  2982,  2984,  2986,  2988,  2990,  2992,
    2994,  2996,  2998,  3000,  3002,  3004,  3006,  3008,  3010,  3012,
    3014,  3016,  3018,  3020,  3022,  3024,  3026,  3028,  3030,  3032,
    3034,  3036,  3038,  3040,  3042,  3044,  3046,  3048,  3050,  3052,
    3054,  3056,  3058,  3060,  3062,  3064,  3066,  3068,  3070,  3072,
    3074,  3076,  3078,  3080,  3082,  3084,  3086,  3088,  3090,  3092,
    3094,  3096,  3098,  3100,  3102,  3104,  3106,  3108,  3110,  3112,
    3114,  3116,  3118,  3120,  3122,  3124,  3126,  3128,  3130,  3132,
    3134,  3136,  3138,  3140,  3142,  3144,  3146,  3148,  3150,  3152,
    3156
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,  1035,  1035,  1036,  1045,  1054,  1059,  1066,  1071,  1082,
    1086,  1093,  1098,  1103,  1108,  1113,  1120,  1127,  1134,  1145,
    1149,  1155,  1161,  1173,  1183,  1189,  1195,  1207,  1208,  1209,
    1210,  1211,  1216,  1217,  1218,  1219,  1220,  1221,  1222,  1225,
    1230,  1234,  1242,  1250,  1258,  1262,  1270,  1275,  1283,  1288,
    1296,  1303,  1310,  1317,  1327,  1329,  1332,  1342,  1347,  1355,
    1363,  1374,  1381,  1392,  1397,  1405,  1412,  1419,  1428,  1441,
    1449,  1456,  1466,  1473,  1480,  1491,  1492,  1493,  1494,  1495,
    1496,  1497,  1498,  1503,  1509,  1518,  1525,  1535,  1545,  1546,
    1547,  1548,  1549,  1550,  1551,  1552,  1553,  1554,  1559,  1567,
    1575,  1583,  1590,  1598,  1605,  1610,  1618,  1626,  1641,  1656,
    1754,  1759,  1767,  1775,  1786,  1791,  1800,  1805,  1815,  1820,
    1829,  1835,  1848,  1853,  1861,  1872,  1887,  1899,  1914,  1919,
    1924,  1929,  1937,  1944,  1955,  1960,  1970,  1976,  1986,  1990,
    1996,  2000,  2004,  2008,  2014,  2020,  2026,  2032,  2038,  2042,
    2048,  2054,  2061,  2069,  2077,  2085,  2093,  2105,  2119,  2133,
    2150,  2154,  2163,  2167,  2174,  2182,  2200,  2206,  2214,  2219,
    2226,  2233,  2243,  2253,  2263,  2273,  2291,  2298,  2326,  2332,
    2342,  2354,  2367,  2379,  2394,  2401,  2408,  2421,  2425,  2432,
    2440,  2453,  2457,  2462,  2468,  2472,  2513,  2517,  2559,  2560,
    2561,  2562,  2563,  2564,  2565,  2566,  2567,  2568,  2569,  2570,
    2574,  2581,  2585,  2592,  2607,  2614,  2621,  2628,  2634,  2644,
    2649,  2654,  2664,  2677,  2694,  2698,  2758,  2759,  2760,  2761,
    2762,  2763,  2767,  2768,  2771,  2772,  2773,  2774,  2775,  2780,
    2795,  2802,  2806,  2813,  2817,  2821,  2828,  2836,  2847,  2857,
    2870,  2879,  2880,  2881,  2885,  2886,  2887,  2888,  2889,  2893,
    2899,  2909,  2917,  2923,  2935,  2939,  2943,  2947,  2951,  2955,
    2959,  2964,  2970,  2979,  2989,  2999,  3015,  3024,  3033,  3041,
    3047,  3059,  3067,  3077,  3085,  3097,  3103,  3114,  3116,  3120,
    3128,  3132,  3137,  3141,  3145,  3149,  3159,  3167,  3174,  3180,
    3191,  3195,  3204,  3212,  3218,  3228,  3234,  3244,  3248,  3258,
    3264,  3270,  3276,  3285,  3294,  3303,  3316,  3320,  3328,  3334,
    3344,  3352,  3361,  3374,  3381,  3393,  3397,  3409,  3416,  3422,
    3431,  3438,  3444,  3455,  3462,  3468,  3477,  3486,  3493,  3504,
    3511,  3523,  3529,  3541,  3547,  3558,  3564,  3575,  3581,  3592,
    3601,  3605,  3614,  3618,  3626,  3630,  3640,  3647,  3656,  3666,
    3665,  3679,  3688,  3697,  3710,  3714,  3727,  3730,  3737,  3741,
    3750,  3754,  3758,  3767,  3771,  3777,  3783,  3789,  3800,  3804,
    3808,  3816,  3820,  3826,  3836,  3840,  3850,  3854,  3864,  3868,
    3878,  3882,  3892,  3896,  3904,  3908,  3912,  3916,  3926,  3930,
    3934,  3942,  3946,  3950,  3954,  3958,  3962,  3970,  3974,  3978,
    3986,  3990,  3994,  3998,  4009,  4015,  4025,  4031,  4041,  4045,
    4049,  4087,  4091,  4101,  4111,  4124,  4133,  4143,  4147,  4156,
    4160,  4169,  4175,  4183,  4189,  4201,  4207,  4217,  4221,  4225,
    4229,  4233,  4239,  4245,  4253,  4257,  4265,  4269,  4280,  4284,
    4288,  4294,  4298,  4312,  4316,  4324,  4328,  4338,  4342,  4346,
    4355,  4359,  4363,  4367,  4375,  4381,  4391,  4399,  4403,  4407,
    4411,  4415,  4419,  4423,  4427,  4431,  4441,  4449,  4453,  4461,
    4468,  4475,  4486,  4494,  4498,  4506,  4514,  4522,  4576,  4580,
    4593,  4599,  4609,  4613,  4621,  4625,  4629,  4637,  4647,  4657,
    4667,  4677,  4687,  4702,  4708,  4719,  4725,  4736,  4747,  4749,
    4753,  4758,  4768,  4771,  4778,  4784,  4790,  4798,  4811,  4814,
    4821,  4827,  4833,  4840,  4851,  4855,  4865,  4869,  4879,  4883,
    4887,  4892,  4901,  4907,  4913,  4919,  4927,  4931,  4943,  4947,
    4959,  4971,  4975,  4979,  4983,  4987,  4991,  4999,  5007,  5011,
    5028,  5032,  5040,  5048,  5056,  5060,  5068,  5074,  5084,  5092,
    5096,  5100,  5135,  5141,  5147,  5157,  5161,  5165,  5169,  5173,
    5180,  5186,  5196,  5204,  5208,  5212,  5216,  5220,  5224,  5228,
    5232,  5236,  5244,  5252,  5256,  5260,  5270,  5278,  5286,  5290,
    5294,  5302,  5306,  5312,  5318,  5322,  5332,  5340,  5344,  5350,
    5359,  5368,  5374,  5380,  5390,  5407,  5414,  5429,  5465,  5469,
    5477,  5485,  5497,  5501,  5509,  5517,  5521,  5532,  5549,  5555,
    5561,  5571,  5575,  5581,  5587,  5591,  5597,  5601,  5607,  5613,
    5620,  5630,  5635,  5643,  5649,  5659,  5681,  5690,  5696,  5709,
    5723,  5730,  5736,  5746,  5751,  5756,  5766,  5779,  5785,  5803,
    5812,  5815,  5822,  5827,  5835,  5839,  5846,  5850,  5857,  5861,
    5868,  5872,  5881,  5894,  5897,  5905,  5908,  5916,  5924,  5932,
    5936,  5944,  5947,  5955,  5967,  5970,  5978,  5990,  5996,  6006,
    6009,  6017,  6021,  6025,  6033,  6036,  6044,  6047,  6055,  6059,
    6063,  6067,  6071,  6079,  6087,  6099,  6111,  6115,  6119,  6127,
    6133,  6143,  6147,  6151,  6155,  6159,  6163,  6167,  6171,  6179,
    6183,  6187,  6191,  6199,  6205,  6215,  6225,  6229,  6237,  6247,
    6258,  6265,  6269,  6277,  6280,  6287,  6292,  6301,  6311,  6314,
    6322,  6325,  6333,  6342,  6349,  6359,  6363,  6370,  6376,  6386,
    6389,  6396,  6401,  6413,  6421,  6433,  6441,  6445,  6453,  6457,
    6461,  6469,  6477,  6481,  6485,  6489,  6497,  6505,  6517,  6521,
    6529,  6542,  6546,  6547,  6560,  6561,  6562,  6563,  6564,  6565,
    6566,  6567,  6568,  6569,  6570,  6571,  6572,  6573,  6574,  6575,
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
    6749,  6750,  6751,  6752,  6753,  6754,  6755,  6756,  6757,  6758,
    6759,  6760,  6761,  6762,  6763,  6764,  6765,  6766,  6767,  6768,
    6769,  6770,  6771,  6772,  6773,  6774,  6775,  6776,  6777,  6782,
    6789
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
     315,   316,   317,   318,   319,   320
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 12616;
  const int xquery_parser::yynnts_ = 308;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 577;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 321;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 575;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba

/* Line 1054 of lalr1.cc  */
#line 16266 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6793 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"


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
/* vim:set et sw=4 ts=4: */

