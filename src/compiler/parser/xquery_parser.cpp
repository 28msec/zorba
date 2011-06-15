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
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 317 of lalr1.cc  */
#line 973 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"

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
#line 871 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 324 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 121: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 333 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 146: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 869 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 342 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 351 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 360 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 369 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 378 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 387 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 396 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 405 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 414 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 423 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 432 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 441 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 450 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 459 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 468 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 477 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 486 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 495 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 504 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 513 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 522 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 531 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 540 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 549 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 558 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 567 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 576 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 585 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 594 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 603 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 612 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 621 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 630 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 639 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 648 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 657 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 666 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 675 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 684 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 693 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 702 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 711 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 720 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 729 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 738 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "DeclPropertyList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 747 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "DeclProperty" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 756 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 765 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "NodeModifier" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 774 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 783 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 792 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 828 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 837 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 846 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 855 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 882 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 900 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 909 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 918 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 927 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 936 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 945 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 954 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 963 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 972 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 981 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 990 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 999 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1008 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1017 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1026 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1035 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1044 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1053 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1062 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1071 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1080 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1089 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1098 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1107 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1116 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1125 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1134 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1143 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1152 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1161 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1170 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1179 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1188 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1197 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1206 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1215 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1224 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1233 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1242 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1251 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1260 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1269 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1278 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1287 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1296 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1305 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1314 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1323 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1332 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1341 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1350 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1359 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1368 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1377 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1386 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1395 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1404 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1413 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1422 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1431 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1440 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1449 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1458 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1467 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1476 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1485 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1494 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1503 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1512 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1521 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1530 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1539 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1548 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1557 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1566 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1575 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1584 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1593 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1602 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1611 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1620 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1629 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1638 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1647 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1656 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1665 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1674 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1683 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1692 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1701 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1710 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1719 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1728 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1737 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1746 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1755 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1764 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1773 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1782 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1791 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1800 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1809 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1818 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1827 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1836 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1845 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1854 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1863 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1872 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1881 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1890 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1899 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1908 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1917 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1926 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1935 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1944 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1953 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1962 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1971 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1980 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1989 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1998 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2007 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2016 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2025 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2034 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2043 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2052 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2061 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2070 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2079 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2088 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2097 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2106 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2115 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2124 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2133 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2142 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2151 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2160 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2169 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2178 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2187 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2196 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2205 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2214 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2223 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2232 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2241 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2250 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2259 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2268 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2277 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2286 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2295 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2304 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2313 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2322 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2331 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2340 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2349 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2358 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2367 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2376 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2385 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2394 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2403 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2412 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2421 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2430 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2439 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2448 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2457 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2466 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2475 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2484 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2493 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2502 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2511 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2520 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2529 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2538 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2547 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2556 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2565 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2574 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2583 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2592 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2601 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2610 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2619 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2628 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 611: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2637 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 612: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2646 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 616: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2655 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 617: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2664 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 618: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2673 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 619: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2682 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2691 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 621: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2700 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 622: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2709 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 623: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2718 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 624: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2727 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 627: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2736 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 628: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2745 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 629: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2754 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
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
#line 2839 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"

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
#line 1034 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 1043 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 1052 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 1058 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 1066 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 1072 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
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
#line 1088 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 1096 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1103 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1110 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 1119 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1126 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1134 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1142 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1150 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1161 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1166 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1173 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 1180 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 1192 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 1202 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 1209 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 1216 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1251 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1256 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1264 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1272 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1280 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1285 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1293 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1298 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1306 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1311 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1319 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1326 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1333 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 1340 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 1355 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 1365 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 1370 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 1378 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1386 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1397 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1404 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1415 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1420 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1428 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1435 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1442 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1451 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1464 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1472 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1479 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1489 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1496 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1503 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1526 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1532 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1541 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1548 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1558 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1567 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1568 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1569 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1570 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1571 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1572 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1573 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1574 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1575 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1576 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1582 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1590 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1598 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1606 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1613 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1621 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1628 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1633 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1641 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1649 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1664 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1679 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1697 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1702 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1710 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1718 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1729 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1734 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1743 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1748 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1758 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1763 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1772 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1778 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1791 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1796 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1804 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1815 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1830 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1842 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1857 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1862 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1872 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1887 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1898 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1903 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1913 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      DeclPropertyList *dpl = new DeclPropertyList( LOC((yyloc)) );
      dpl->addProperty(dynamic_cast<DeclProperty*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = dpl;
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1919 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      DeclPropertyList *dpl = dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(2) - (1)].node));
      dpl->addProperty( static_cast<DeclProperty*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1929 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_const );
        }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1933 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_append_only
            );
        }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1939 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_queue );
        }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1943 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_mutable );
        }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1947 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_ordered );
        }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1951 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_unordered
            );
        }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1957 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_equality
            );
        }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1963 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_range
            );
        }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1969 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_equality
            );
        }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1975 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_range
            );
        }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1981 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_unique );
        }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1985 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_non_unique
            );
        }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1991 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_automatic
            );
        }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1997 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_manual );
        }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 2004 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2012 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2020 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2028 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2036 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2048 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2062 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2076 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2093 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 2097 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 2106 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 2110 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2117 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2125 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2143 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 2149 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 2158 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 2163 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 2170 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 2177 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 2189 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2199 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2209 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2220 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2236 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 177:

/* Line 678 of lalr1.cc  */
#line 2256 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 2261 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2265 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2273 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2278 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 2282 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 2290 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 2295 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 2307 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 2314 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 2343 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 2348 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 2356 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 202:

/* Line 678 of lalr1.cc  */
#line 2373 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 2381 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 2389 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 2396 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 2403 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 2410 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 2417 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)));
      vdecl->add((yysemantic_stack_[(4) - (4)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 2427 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 210:

/* Line 678 of lalr1.cc  */
#line 2439 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 211:

/* Line 678 of lalr1.cc  */
#line 2452 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 212:

/* Line 678 of lalr1.cc  */
#line 2464 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 213:

/* Line 678 of lalr1.cc  */
#line 2480 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 2488 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 2496 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 2504 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 217:

/* Line 678 of lalr1.cc  */
#line 2519 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 2524 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 2532 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 220:

/* Line 678 of lalr1.cc  */
#line 2546 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 221:

/* Line 678 of lalr1.cc  */
#line 2563 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 222:

/* Line 678 of lalr1.cc  */
#line 2588 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 2596 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 2603 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 2614 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 2620 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 2626 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 228:

/* Line 678 of lalr1.cc  */
#line 2637 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 229:

/* Line 678 of lalr1.cc  */
#line 2652 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 2657 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 244:

/* Line 678 of lalr1.cc  */
#line 2695 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 245:

/* Line 678 of lalr1.cc  */
#line 2709 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2717 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 2722 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 2730 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2735 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2740 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 2748 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)),
                            (yysemantic_stack_[(4) - (4)].expr),
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 2757 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            NULL,
                            (yysemantic_stack_[(3) - (3)].expr),
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2769 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 254:

/* Line 678 of lalr1.cc  */
#line 2779 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 2792 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2816 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2823 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2833 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2841 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2848 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2858 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 270:

/* Line 678 of lalr1.cc  */
#line 2868 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 271:

/* Line 678 of lalr1.cc  */
#line 2878 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 272:

/* Line 678 of lalr1.cc  */
#line 2888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 273:

/* Line 678 of lalr1.cc  */
#line 2898 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 274:

/* Line 678 of lalr1.cc  */
#line 2908 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 275:

/* Line 678 of lalr1.cc  */
#line 2918 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 276:

/* Line 678 of lalr1.cc  */
#line 2928 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 277:

/* Line 678 of lalr1.cc  */
#line 2939 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2948 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 279:

/* Line 678 of lalr1.cc  */
#line 2958 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 280:

/* Line 678 of lalr1.cc  */
#line 2968 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 281:

/* Line 678 of lalr1.cc  */
#line 2984 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2993 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 3002 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 3010 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 3016 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 3028 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 3036 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 3046 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 3054 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 3066 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 3072 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 3085 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 3089 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 3097 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 3101 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 3110 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 3114 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 3118 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 3128 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3136 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3143 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3149 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3160 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3164 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3173 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3181 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3187 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3197 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3203 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3213 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3217 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3227 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3233 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3239 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3245 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3254 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3263 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3272 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3285 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3289 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3297 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3303 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3313 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3321 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3330 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3343 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3350 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3362 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3366 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3378 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3385 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3391 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3400 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3407 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3413 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3424 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3431 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3437 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3446 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3455 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3462 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3473 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3480 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 3492 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3498 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3510 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3516 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3527 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3533 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3544 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3550 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3561 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3570 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3574 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3583 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3587 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3595 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3599 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 361:

/* Line 678 of lalr1.cc  */
#line 3609 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3616 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3625 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3634 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3639 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3648 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3657 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3666 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3679 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3683 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3695 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3699 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3706 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3710 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3719 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3723 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3727 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3736 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3740 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3746 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3752 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3758 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3769 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3773 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3777 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3785 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3789 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3795 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3805 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3809 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3819 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3823 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3833 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3837 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3847 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3851 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3865 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3881 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3895 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3899 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3903 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3911 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3915 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3919 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3923 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3927 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3931 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3939 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3943 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3947 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3955 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3959 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3963 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3967 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3978 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3984 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3994 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 4000 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 4010 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 4014 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 4018 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 4056 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 4060 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 4070 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 4080 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 4093 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 4102 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 432:

/* Line 678 of lalr1.cc  */
#line 4112 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 4116 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 4125 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 4129 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 4138 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 4144 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4152 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4158 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4170 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4176 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4186 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4190 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4194 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4198 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4202 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4208 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4214 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4222 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4226 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4234 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4238 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4249 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4253 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4257 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4263 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4267 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4281 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4285 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4293 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4297 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4307 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all);
    }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4311 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem);
    }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4315 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix);
    }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4324 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4328 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4332 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4336 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4344 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4350 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4360 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4368 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4372 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4376 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4380 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4384 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4388 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4392 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4396 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4400 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4410 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4418 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4422 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4430 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4437 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4444 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4455 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4463 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4467 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4475 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4483 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4491 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4545 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4549 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4562 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4568 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4578 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4582 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4590 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4594 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4598 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4606 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 503:

/* Line 678 of lalr1.cc  */
#line 4616 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 504:

/* Line 678 of lalr1.cc  */
#line 4626 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 505:

/* Line 678 of lalr1.cc  */
#line 4636 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 506:

/* Line 678 of lalr1.cc  */
#line 4646 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 507:

/* Line 678 of lalr1.cc  */
#line 4656 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 508:

/* Line 678 of lalr1.cc  */
#line 4671 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4677 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4688 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4694 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4705 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4722 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4727 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4736 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4740 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4747 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4753 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4759 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4767 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4779 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4783 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4790 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4796 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4802 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4809 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4820 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4824 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4834 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4838 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4848 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4852 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4856 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4870 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4882 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
        }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4896 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4901 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4909 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4914 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4922 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4930 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4935 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4940 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4945 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4950 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 4955 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 4964 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 4972 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 4976 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 4993 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 4997 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 5005 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 5013 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 5021 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 5025 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 5033 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 5039 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 5049 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 5057 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 5061 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 5065 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 5100 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 5106 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 5112 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 5122 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 5126 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5130 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 5134 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 5138 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5145 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5151 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5161 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5169 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5173 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5177 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5181 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5185 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5189 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5193 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5197 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5201 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5209 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5217 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5221 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5225 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5235 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5243 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5251 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5255 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5259 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5267 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5271 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5277 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5283 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5287 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5297 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5305 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5309 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5315 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5324 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5333 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5339 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5345 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5355 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5372 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5379 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5394 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5430 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5434 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5442 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5450 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5462 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5466 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5474 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5482 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5486 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5497 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5514 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5520 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5526 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5536 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5540 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5546 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5552 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5556 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5562 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5566 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5572 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5578 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5585 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5595 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5600 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5608 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5614 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5624 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5646 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5655 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5661 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5674 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5688 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5695 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5701 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5711 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5716 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5721 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 651:

/* Line 678 of lalr1.cc  */
#line 5731 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 652:

/* Line 678 of lalr1.cc  */
#line 5745 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5753 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5759 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5777 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5785 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5789 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5796 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5801 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5809 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5813 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5820 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5824 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5831 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5835 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5842 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5846 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5855 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5871 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5878 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5882 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5890 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5898 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5906 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5910 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5917 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5921 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5929 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5940 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5944 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5952 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5964 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5970 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5979 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5983 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5991 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5995 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5999 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 6006 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 6010 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 6017 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 6021 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 6029 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 6033 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 6037 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 6041 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 6045 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 6053 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 6061 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 6073 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 6085 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 6089 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 6093 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 6101 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 6107 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 6117 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 6121 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 6125 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 6129 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 6133 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 6137 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 6141 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 6145 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 6153 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 6157 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 6161 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 6165 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 6173 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 6179 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 6189 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 6199 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 6203 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 6211 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 725:

/* Line 678 of lalr1.cc  */
#line 6221 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 726:

/* Line 678 of lalr1.cc  */
#line 6232 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 6239 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 6243 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 6250 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 6254 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 6261 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 6266 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 6275 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 6284 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 6288 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 6295 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 6299 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 6307 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 6316 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 6323 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 6333 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 6337 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 6344 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 6350 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 6359 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 6363 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 6370 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 6375 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 6387 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 6395 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 6407 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 6415 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 6419 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 6427 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 6431 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 6435 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 6443 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 6451 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 6455 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 6459 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 6463 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 6471 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 6479 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 6491 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 6495 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 6503 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 6521 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 771:

/* Line 678 of lalr1.cc  */
#line 6534 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 6535 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 6536 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 6537 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 6538 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 6539 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 6540 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 6541 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 6542 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 6543 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 6544 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 6545 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 6546 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 6547 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 6548 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 6553 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 6554 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 6555 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 6556 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 6557 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 6558 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 6559 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 6560 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 6561 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 6562 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 6563 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 6564 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 6565 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 6566 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 6567 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 6568 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 6569 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 6570 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 6571 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 6572 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 6573 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 6574 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 6575 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 6576 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 6577 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 6578 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 6579 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 6580 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 6581 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 6582 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 6583 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 6584 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 6585 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 6586 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 6587 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 6588 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 6589 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 6590 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 6591 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 6592 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 6593 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 6594 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 6595 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 6596 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 6597 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 6598 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 6599 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 6600 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 6601 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 6602 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 6603 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 6604 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 6605 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 6606 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 6607 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 6608 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 6609 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 6610 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 6611 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 6612 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 6613 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 6614 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 6615 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 6616 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 6617 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 6618 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 6619 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 6620 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 6621 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 6622 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 6623 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 6624 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 6625 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 6626 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 6627 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 6628 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 6629 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 6630 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 6631 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 6632 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 6633 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 6634 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 6635 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 6636 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 6637 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 6638 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 6639 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 6640 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 6641 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 6642 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 6643 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 6644 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 6645 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 6646 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 6647 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 6648 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 6649 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 6650 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 6651 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 6652 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 6653 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 6654 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 6655 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 6656 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 6657 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 6658 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 6659 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 6660 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6661 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 896:

/* Line 678 of lalr1.cc  */
#line 6662 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 897:

/* Line 678 of lalr1.cc  */
#line 6663 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 898:

/* Line 678 of lalr1.cc  */
#line 6664 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 899:

/* Line 678 of lalr1.cc  */
#line 6665 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 900:

/* Line 678 of lalr1.cc  */
#line 6666 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 901:

/* Line 678 of lalr1.cc  */
#line 6667 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 902:

/* Line 678 of lalr1.cc  */
#line 6668 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 903:

/* Line 678 of lalr1.cc  */
#line 6669 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 904:

/* Line 678 of lalr1.cc  */
#line 6670 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 905:

/* Line 678 of lalr1.cc  */
#line 6671 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 906:

/* Line 678 of lalr1.cc  */
#line 6672 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 907:

/* Line 678 of lalr1.cc  */
#line 6673 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 908:

/* Line 678 of lalr1.cc  */
#line 6674 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 909:

/* Line 678 of lalr1.cc  */
#line 6675 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 910:

/* Line 678 of lalr1.cc  */
#line 6676 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 911:

/* Line 678 of lalr1.cc  */
#line 6677 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 912:

/* Line 678 of lalr1.cc  */
#line 6678 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 913:

/* Line 678 of lalr1.cc  */
#line 6679 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 914:

/* Line 678 of lalr1.cc  */
#line 6680 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 915:

/* Line 678 of lalr1.cc  */
#line 6681 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 916:

/* Line 678 of lalr1.cc  */
#line 6682 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 917:

/* Line 678 of lalr1.cc  */
#line 6683 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 918:

/* Line 678 of lalr1.cc  */
#line 6684 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 919:

/* Line 678 of lalr1.cc  */
#line 6685 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 920:

/* Line 678 of lalr1.cc  */
#line 6686 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 921:

/* Line 678 of lalr1.cc  */
#line 6687 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 922:

/* Line 678 of lalr1.cc  */
#line 6688 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 923:

/* Line 678 of lalr1.cc  */
#line 6689 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 924:

/* Line 678 of lalr1.cc  */
#line 6690 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 925:

/* Line 678 of lalr1.cc  */
#line 6691 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 926:

/* Line 678 of lalr1.cc  */
#line 6692 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 927:

/* Line 678 of lalr1.cc  */
#line 6693 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 928:

/* Line 678 of lalr1.cc  */
#line 6694 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 929:

/* Line 678 of lalr1.cc  */
#line 6695 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 930:

/* Line 678 of lalr1.cc  */
#line 6696 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 931:

/* Line 678 of lalr1.cc  */
#line 6697 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("local"))); }
    break;

  case 932:

/* Line 678 of lalr1.cc  */
#line 6698 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 933:

/* Line 678 of lalr1.cc  */
#line 6699 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 934:

/* Line 678 of lalr1.cc  */
#line 6700 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 935:

/* Line 678 of lalr1.cc  */
#line 6701 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 936:

/* Line 678 of lalr1.cc  */
#line 6702 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 937:

/* Line 678 of lalr1.cc  */
#line 6703 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 938:

/* Line 678 of lalr1.cc  */
#line 6704 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eval"))); }
    break;

  case 939:

/* Line 678 of lalr1.cc  */
#line 6705 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 940:

/* Line 678 of lalr1.cc  */
#line 6706 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 941:

/* Line 678 of lalr1.cc  */
#line 6707 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 942:

/* Line 678 of lalr1.cc  */
#line 6708 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 943:

/* Line 678 of lalr1.cc  */
#line 6709 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 944:

/* Line 678 of lalr1.cc  */
#line 6710 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 945:

/* Line 678 of lalr1.cc  */
#line 6711 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 946:

/* Line 678 of lalr1.cc  */
#line 6712 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 947:

/* Line 678 of lalr1.cc  */
#line 6713 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 948:

/* Line 678 of lalr1.cc  */
#line 6714 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 949:

/* Line 678 of lalr1.cc  */
#line 6715 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 950:

/* Line 678 of lalr1.cc  */
#line 6716 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 951:

/* Line 678 of lalr1.cc  */
#line 6717 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 952:

/* Line 678 of lalr1.cc  */
#line 6718 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 953:

/* Line 678 of lalr1.cc  */
#line 6719 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 954:

/* Line 678 of lalr1.cc  */
#line 6720 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 955:

/* Line 678 of lalr1.cc  */
#line 6721 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 956:

/* Line 678 of lalr1.cc  */
#line 6722 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 957:

/* Line 678 of lalr1.cc  */
#line 6723 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 958:

/* Line 678 of lalr1.cc  */
#line 6724 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 959:

/* Line 678 of lalr1.cc  */
#line 6725 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 960:

/* Line 678 of lalr1.cc  */
#line 6726 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 961:

/* Line 678 of lalr1.cc  */
#line 6727 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 962:

/* Line 678 of lalr1.cc  */
#line 6728 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 963:

/* Line 678 of lalr1.cc  */
#line 6729 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 964:

/* Line 678 of lalr1.cc  */
#line 6730 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 965:

/* Line 678 of lalr1.cc  */
#line 6731 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 966:

/* Line 678 of lalr1.cc  */
#line 6732 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 967:

/* Line 678 of lalr1.cc  */
#line 6733 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 968:

/* Line 678 of lalr1.cc  */
#line 6734 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 969:

/* Line 678 of lalr1.cc  */
#line 6735 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 970:

/* Line 678 of lalr1.cc  */
#line 6736 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 971:

/* Line 678 of lalr1.cc  */
#line 6737 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 972:

/* Line 678 of lalr1.cc  */
#line 6738 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 973:

/* Line 678 of lalr1.cc  */
#line 6739 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 974:

/* Line 678 of lalr1.cc  */
#line 6740 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 975:

/* Line 678 of lalr1.cc  */
#line 6741 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 976:

/* Line 678 of lalr1.cc  */
#line 6742 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 977:

/* Line 678 of lalr1.cc  */
#line 6743 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 978:

/* Line 678 of lalr1.cc  */
#line 6744 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 979:

/* Line 678 of lalr1.cc  */
#line 6745 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 980:

/* Line 678 of lalr1.cc  */
#line 6746 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 981:

/* Line 678 of lalr1.cc  */
#line 6747 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 982:

/* Line 678 of lalr1.cc  */
#line 6748 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 983:

/* Line 678 of lalr1.cc  */
#line 6749 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 984:

/* Line 678 of lalr1.cc  */
#line 6750 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 985:

/* Line 678 of lalr1.cc  */
#line 6756 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          // EQName's namespace URI value is whitespace normalized according to the rules for the xs:anyURI type
          std::string uri = "\"" + SYMTAB((yysemantic_stack_[(3) - (1)].sval)) + "\"";
          std::string eqname = SYMTAB(driver.symtab.put_uri(uri.c_str(), uri.size())) + ":" + SYMTAB((yysemantic_stack_[(3) - (3)].sval));
          (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT(eqname.c_str())), true);
        }
    break;

  case 986:

/* Line 678 of lalr1.cc  */
#line 6762 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 678 of lalr1.cc  */
#line 11918 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1440;
  const short int
  xquery_parser::yypact_[] =
  {
      2876, -1440, -1440,  4357,  4357,  4357, -1440, -1440,    59,   277,
    1728,   382, -1440, -1440, -1440,    22, -1440, -1440, -1440,   438,
     213,   599, -1440,   587,   283,   481,   754, -1440,   -38, -1440,
   -1440, -1440, -1440, -1440, -1440,   703, -1440,   541,   563, -1440,
   -1440, -1440, -1440,   620, -1440,   758, -1440,   637,   688, -1440,
     204, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440,
   -1440, -1440, -1440, -1440,   738,   748, -1440, -1440, -1440, -1440,
      33,  8797, -1440, -1440, -1440,   759, -1440, -1440, -1440,   789,
   -1440,   791,   794, -1440, -1440, 12523, -1440, -1440, -1440, -1440,
   -1440, -1440, -1440, -1440,   801, -1440, -1440,   803,   806, -1440,
   -1440, -1440, -1440, -1440, -1440, -1440,  3173,  4653, 12523, -1440,
   -1440, -1440, -1440, -1440, -1440, -1440,   781, -1440, -1440,   817,
    9677, -1440,  9967,   838,   849, -1440, -1440, -1440,   852, -1440,
    8501, -1440, -1440, -1440, -1440, -1440, -1440,   828, -1440, -1440,
   -1440, -1440, -1440, -1440, -1440, -1440,    50,   775, -1440, -1440,
   -1440, -1440, -1440, -1440, -1440, -1440,   194,   833,   606, -1440,
     778,   580, -1440, -1440, -1440, -1440, -1440, -1440,   885, -1440,
      95,   765,   766,   762, -1440, -1440,   853,   855, -1440, -1440,
   -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440,
   -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440,
   -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440,
   -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440,
   -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440,
   -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440,
    4949,  1008, -1440,  5245, -1440, -1440,   143,    72, -1440, -1440,
   -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440,
   -1440, -1440,    74, -1440, -1440, -1440, -1440, -1440, -1440,   107,
   -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440,  4357, -1440,
   -1440, -1440, -1440,     9, -1440, -1440, -1440, -1440, -1440, -1440,
   -1440, -1440,   905, -1440,   823, -1440, -1440, -1440,   631, -1440,
   -1440, -1440, -1440, -1440, -1440, -1440, -1440,   848,   923, -1440,
     941,   769,   482,    25,   435,    31, -1440,   965,   822,   921,
     922,  7317, -1440, -1440, -1440,   473, -1440, -1440,  8501, -1440,
     750, -1440,   869,  8797, -1440,   869,  8797, -1440, -1440, -1440,
     768, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440,
   -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440,
   -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440,
   -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440,
   -1440, -1440, -1440,   906,   888,   874, -1440, -1440, -1440, -1440,
   -1440,   850, -1440,  4357,   851,   854,   419,  1006,     8,   603,
     567, 12807, 12523,   349,   988, 12523,   887,   924,   474,  9677,
   -1440, -1440,   710,   647,   795, 12523, -1440, -1440, -1440, -1440,
   -1440,   752, 12523,   745,   746,   649,   742,   740,   405, -1440,
   -1440, -1440,   689, -1440,  9677,  4357,   860,  4357,    58,  7613,
   10535,   767,   770, 12523,   931,    21,   897,  7613,  1048,   118,
     114, 12523,   938,   915,   952, -1440,  7613,  9385, 12523, 12523,
   12523,  4357,   876,  7613,  7613, 12523,  4357,   912,   913, -1440,
   -1440, -1440,  7613, 10819, -1440,   908, -1440,   916, -1440, -1440,
   -1440, -1440,   918, -1440,   927, -1440, -1440, -1440, -1440, -1440,
     929, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440,
   -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440,
   -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, 12523,
   -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440,
   -1440, -1440,   925, 12523, -1440, -1440, -1440,   884,  3469,   932,
     933,   934, 12523,  4357, -1440,   926,    53, -1440,   643,  1042,
    7613, -1440, -1440,    64, -1440, -1440, -1440,  1061, -1440, -1440,
   -1440, -1440,  7613,   878, -1440,  1067,  7613,  7613,   917,  7613,
    7613,  7613,  7613,   870, 12523,   789,   124,   909,   919,  7613,
    7613,  3173,   857, -1440, -1440, -1440, -1440,  1728,   754,    85,
      93,  1099,  5541,  5541,  5837,  5837,   789, -1440, -1440,   905,
     789, -1440,  7613, -1440,   989,   587,   -38,   940,   936,   942,
    4357,  7613, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440,
    7909,  7909,  7909, -1440,  7909,  7909, -1440,  7909, -1440,  7909,
   -1440, -1440, -1440, -1440, -1440, -1440, -1440,  7909,  7909,  1038,
    7909,  7909,  7909,  7909,  7909,  7909,  7909,  7909,  7909,  7909,
    7909,   881,  1018,  1019,  1020, -1440, -1440, -1440,  6133, -1440,
   -1440,  8501,  8501,  7613,   869, -1440, -1440,   869, -1440,  6429,
     869,  9677,   967,  6725, -1440, -1440, -1440, -1440,   130, -1440,
   -1440, -1440, -1440, -1440, -1440,  1010,  1011,   283,  1089, -1440,
   -1440, 12807,   911,   634, 12523,   961,   962,   911,  1006,   996,
     992, -1440, -1440, -1440, -1440, -1440,    63,   879,    12, -1440,
     827, -1440, -1440, -1440, -1440, 12523,   985,  7613,  1012, -1440,
   12523, 12523, -1440,  1000,   944,  4357, -1440,   949,   916,   563,
   -1440,   947,   950,   226, -1440,   177,   201, -1440, -1440,  1029,
   -1440,    32, 12523,    16, 12523,  1044,   212, -1440,  4357, -1440,
     216, -1440,  9677,  1043,  1095,  9677,  1006,  1045,    71, 12523,
    7613,   -38,   244,   963, -1440,   968,   969,   971,    36, -1440,
      51,   970, -1440,   224,   225,   999, -1440,   976,  4357,  4357,
     298, -1440,   242,   258,   341,  7613,    42, -1440, -1440,  7613,
    7613,  7613, -1440,  7613, -1440,  7613, 12523,  1042, -1440,    20,
     472, -1440, -1440, -1440,   479, -1440,    41, -1440, -1440, -1440,
     138,   294,  1054,   928,   937,    24, -1440,  1021, -1440,   789,
   -1440, -1440,   975,   261,  3765,   485,  9093,   857, -1440,   143,
     302,  1132,  1132, -1440, -1440,    98, -1440, -1440,   102, -1440,
     982, -1440, -1440, -1440, -1440, -1440, -1440, -1440, 12523,   997,
    7613,  1050, -1440, -1440, -1440,   923, -1440, -1440, -1440, -1440,
   -1440,  7909, -1440, -1440, -1440,    44,    25,    25,    11,   435,
     435,   435,   435,    31,    31, -1440, -1440, 11955, 11955, 12523,
   12523, -1440,   492, -1440, -1440,    40, -1440, -1440, -1440,   274,
   -1440, -1440, -1440,   275,   419, -1440,   533,   558,    48, -1440,
     283, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440,
   -1440,   911, -1440,  1037, 12239,  1028,  7613, -1440, -1440, -1440,
    1076,  1006,  1006,   911, -1440,   206,  1006,   619, 12523,   247,
     369,  1142, -1440, -1440,   891,   324, -1440, -1440, -1440, -1440,
   -1440, -1440, -1440, -1440, -1440, -1440, -1440,    63,   119,   662,
   -1440,   948,   493,  7613, -1440, 12523,    37,   880,  1006, -1440,
   -1440, -1440, -1440,  1025, 12523, -1440, 12523, -1440,  1055,  1057,
   11955,  1069,  7613,   -39,  1041,    29,   487,   935, -1440, -1440,
     607,    16,  1076, 11955,  1073,  1097,  1009,   998,  1062,  1006,
    1036,  1065,  1101,  1006,  7613,   -22, -1440, -1440, -1440,  1046,
   -1440, -1440, -1440, -1440,  1082,  7613,  7613,  1056, -1440,  1102,
    1104,  4357, -1440,  1024,  1031,  1052, 12523, -1440, 12523, -1440,
    7613,  1070,  1023,  7613,   279,   286,   345,  1173, -1440,   260,
   -1440,   536, -1440, -1440,  1187, -1440,   702,  7613,  7613,  7613,
     705,  7613,  7613,  7613,  7613,  7613,  7613,  1100,  7613,  7613,
   -1440, -1440,  7021,  1063,  1064,  1066,  1071,   823,   693,   978,
   -1440,   251, -1440,   106,    99,   982,  5837,  5837,  5837,  1145,
   -1440,  7613,   751,  1119, -1440, 12523,  1122, -1440, -1440,  7613,
      44,   270,   534, -1440,   954,   179,   974,   973, -1440, -1440,
     795, -1440,   977,   602,  1079,  1081, 12239,  1086, -1440,   471,
   -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440,  1105,
   -1440, -1440, -1440,  7613, -1440, -1440, -1440, -1440, -1440, -1440,
   -1440, -1440, -1440,   626, -1440,  1218,   757, -1440, -1440, -1440,
   -1440, -1440, -1440, -1440, -1440, -1440,   966, -1440, -1440,  1221,
   -1440, -1440, -1440, -1440, -1440,   539,  1223, -1440,   677, -1440,
   -1440, -1440,   908,   213,   918,   541,   927,   929,   833,  1022,
     471,  1030,  1034,  8205,   979,   951, -1440,  1076,   119, -1440,
    1035,  1074,  4357,  1080,  1093,  1110,  1094,  1096, 12523,   248,
   -1440, 12523, -1440,  7613,  1116,  7613,  1141,  7613,    -2,  1139,
    7613,  1143, -1440,  1171,  1174,  7613, 12523,   845,  1213, -1440,
   -1440, -1440, -1440, -1440, -1440, 11955, -1440,  4357,  1006,  1188,
   -1440, -1440, -1440,  1006,  1188, -1440,  7613,  1154,  4357, 12523,
   -1440, -1440,  7613,  7613,   694, -1440,    18,   700, -1440, 11103,
     753, -1440,   763, -1440,  1113, -1440, -1440,  4357,  1111,  1112,
   -1440,  7613, -1440, -1440,  1103,  1102,  1203, -1440,  1172, -1440,
     550, -1440, -1440,  1295, -1440, -1440,  4357, 12523, -1440,   565,
   -1440, -1440, -1440,  1117,  1077,  1078, -1440, -1440, -1440,  1083,
    1085, -1440, -1440, -1440, -1440, -1440,  1075, 12523,  1120, -1440,
   -1440,  7613,  7613,  7613,  4061,  7021,  9093,   978, -1440,  1200,
    9093, -1440,  1132,   233, -1440, -1440, -1440,  1119, -1440,  1006,
   -1440,   829, -1440,    68,  1214, -1440,  7613,  1215,  1050,   498,
    1135, -1440,    44,  1087, -1440, -1440,   400, -1440,   553,    56,
    1088,    44,   553,  7909, -1440,    54, -1440, -1440, -1440, -1440,
   -1440, -1440,    44,  1177,  1047,   879,    56, -1440, -1440,  1033,
    1246, -1440, -1440, -1440, 10251,  1148,  1149,  1152, -1440, -1440,
   -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440,
    1296,    26,  1300,    26,  1072,  1233, -1440, -1440, -1440, -1440,
    1175, 12523,  1084, -1440,  1022,  8205, -1440,  1158, -1440, -1440,
   -1440, -1440, -1440, -1440,  7613,  1197, -1440, -1440,  7613, -1440,
     330, -1440,  7613,  1201,  7613, -1440,  7613, 12523, 12523, -1440,
     671, -1440,  7613, -1440,  1224,  1225,  1250,  1006,  1188, -1440,
    7613,  1165, -1440, -1440, -1440,  1166, -1440,    28,  7613,  4357,
    1167,    34, -1440, 12523,  1170, 11387,    43, -1440, 11671,  1176,
   -1440, -1440,  1183, -1440, -1440, -1440,  7613,   774,  1173, 12523,
     612, -1440,  1184,  1173, 12523, -1440, -1440,  7613,  7613,  7613,
    7613,  7613, -1440,  7613,   351,   358,   386,   315, -1440, 12523,
   -1440, -1440, -1440, -1440,  1214, -1440, -1440, -1440,  1006, -1440,
   -1440, -1440, -1440, -1440,  1185,  7909, -1440, -1440, -1440, -1440,
   -1440,    82,  7909,  7909,   579, -1440,   974, -1440,   209, -1440,
     973,    44,  1204, -1440, -1440,  1090, -1440, -1440, -1440, -1440,
    1263,  1186, -1440,   387, -1440, -1440, -1440, -1440,   207,   207,
   -1440,    26, -1440, -1440,   402, -1440,  1329,    56,  1264,  1189,
    8205,   -54,  1091, -1440,  1190, -1440, -1440,  7613, -1440,  7613,
    1228, -1440,  7613, -1440, -1440, -1440,  1316, -1440, -1440,  7021,
    7613,  1006, -1440, -1440, -1440,  7613,  7613, -1440, -1440, -1440,
    7021,  7021,  1277,  4357, 12523,  1191, 12523,  7613, 12523,  1193,
    7021, -1440,    55,    39,  1173, 12523, -1440,  1192,  1173, -1440,
   -1440, -1440, -1440, -1440, -1440,  1194,  1102,  1104,  7613,  1265,
   -1440,   423, -1440, -1440, -1440,   435,  7909,  7909,    11,   574,
   -1440, -1440, -1440, -1440, -1440, -1440,  7613, -1440, 11955, -1440,
   11955,  1286, -1440, -1440, -1440,  1354, -1440, -1440, -1440,  1121,
    1280, -1440, -1440,  1282, -1440,   661, 12523,  1272,  1168, 12523,
    8205, -1440, -1440,  7613, -1440,  1275, -1440, -1440,  1188, -1440,
   -1440, 11955, -1440, -1440,  1299,  7613,  1209, -1440,  1302,  7021,
   -1440, 12523,   197,   430, -1440,  1202,  1173, -1440,  1207,  7021,
     780,   510, 12523,  1281,  1071,    11,    11,  7909,   516, -1440,
   -1440, 11955, -1440, -1440,  1264,  8205, -1440,  1214,  1106, 12523,
    1287,  1180,  1282, -1440, 12523,  1220, 11955,  4357, 11955,  1222,
   -1440, -1440,  1313,   375, -1440, -1440, -1440, -1440,  1226,   504,
   -1440, -1440, -1440,  1217, -1440,  1292, -1440,   458, 12523, -1440,
      11, -1440, -1440, -1440, -1440, -1440,  7613,  1114, 12523,  1297,
   -1440,  4357,  1231, -1440, -1440,  1232,  7613, -1440, -1440, -1440,
   -1440, -1440, -1440, -1440, 12523,  1303,  1267,   459, -1440,  1130,
    1124, 12523, -1440, -1440,  7613,  7021,  1238, 12523, -1440,  1307,
    1071,  1125,  7613,  1126,  7021,   462, 12523, -1440,  8205, -1440,
    8205,  1308,  1267,  1240, -1440,  1235, 12523, -1440,  1071,  1147,
    1243, -1440, 12523,  1267,  1211, -1440,  1318, 12523,  1131,  8205,
   -1440
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       179,   463,   464,   182,   182,   182,   787,   986,   116,   612,
     878,   887,   828,   792,   790,   772,   879,   882,   835,   796,
     773,   774,   938,   827,   888,   776,   885,   857,   837,   812,
     832,   833,   883,   880,   831,   778,   886,   779,   780,   926,
     940,   925,   829,   848,   842,   781,   830,   783,   782,   927,
     866,   834,   809,   950,   951,   952,   953,   954,   955,   956,
     957,   958,   959,   960,   974,   981,   856,   852,   843,   823,
     771,     0,   851,   859,   867,   975,   847,   484,   824,   825,
     881,   976,   982,   844,   861,     0,   490,   452,   486,   854,
     789,   845,   846,   874,   849,   865,   873,   980,   983,   795,
     836,   876,   485,   864,   869,   775,     0,     0,     0,   400,
     862,   872,   877,   875,   855,   841,   928,   839,   840,   977,
       0,   399,     0,   978,   984,   870,   826,   850,   979,   430,
       0,   462,   871,   853,   860,   868,   863,   929,   817,   822,
     821,   820,   819,   818,   784,   838,     0,   788,   884,   810,
     917,   916,   918,   794,   793,   813,   923,   777,   915,   920,
     921,   912,   816,   858,   914,   924,   922,   913,   814,   919,
     931,   934,   935,   932,   933,   930,   785,   936,   937,   939,
     904,   903,   890,   808,   801,   897,   893,   811,   807,   906,
     907,   797,   798,   791,   800,   902,   901,   898,   894,   911,
     905,   900,   896,   889,   799,   910,   909,   803,   805,   804,
     895,   899,   891,   806,   892,   802,   908,   961,   962,   963,
     964,   965,   966,   942,   943,   941,   947,   948,   949,   944,
     945,   946,   815,   967,   968,   969,   970,   971,   972,   973,
     179,     0,     2,   179,     5,     7,    19,     0,    24,    27,
      32,    33,    34,    35,    36,    37,    38,    28,    54,    55,
      29,    30,     0,    72,    75,    76,    31,    77,    78,     0,
     114,    79,    80,    81,    82,    14,   176,   177,   178,   185,
     187,   481,   188,     0,   189,   190,   191,   192,   193,   194,
     195,   198,   183,   229,   236,   231,   258,   264,     0,   256,
     257,   238,   232,   197,   233,   196,   234,   237,   355,   357,
     359,   369,   373,   375,   378,   383,   386,   389,   391,   393,
     395,     0,   397,   403,   405,     0,   421,   404,   426,   429,
     431,   434,   436,     0,   441,   438,     0,   449,   459,   461,
     435,   465,   472,   482,   473,   474,   475,   478,   479,   476,
     477,   497,   499,   500,   501,   498,   546,   547,   548,   549,
     550,   551,   458,   586,   578,   585,   584,   583,   580,   582,
     579,   581,   483,   480,   613,   614,    39,   239,   240,   242,
     241,   243,   235,     0,   460,   770,   786,   878,   887,   885,
     788,     0,   180,   181,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     142,   143,     0,     0,     0,     0,   138,   139,   140,   141,
     148,     0,     0,     0,     0,     0,     0,     0,     0,   120,
     122,   123,     0,   136,     0,     0,     0,   182,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   283,   284,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   454,
     457,   444,     0,     0,   767,   772,   796,   774,   827,   888,
     776,   837,   778,   848,   781,   783,   782,   866,   974,   981,
     771,   975,   825,   976,   982,   849,   980,   983,   928,   977,
     978,   984,   979,   929,   923,   915,   921,   912,   814,   931,
     934,   935,   932,   785,   936,   450,   460,   770,   442,     0,
     205,   443,   446,   772,   773,   774,   778,   779,   780,   781,
     771,   777,   487,     0,   448,   447,   200,     0,     0,   776,
     783,   782,     0,   182,   488,   936,     0,   236,     0,   513,
       0,   453,   768,     0,   769,   424,   425,     0,   456,   455,
     445,   428,     0,     0,   542,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     3,     1,     6,     8,     0,     0,     0,
       0,     0,   179,   179,   179,   179,     0,   115,   186,   184,
       0,   203,     0,   214,     0,     0,     0,     0,     0,     0,
       0,     0,   219,   244,   263,   259,   265,   260,   262,   261,
       0,     0,     0,   414,     0,     0,   412,     0,   364,     0,
     413,   406,   411,   410,   409,   408,   407,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   402,   401,   398,     0,   422,
     427,     0,     0,     0,   437,   469,   440,   439,   451,     0,
     466,     0,     0,     0,   553,   555,   559,   612,     0,   118,
      43,    40,    41,    44,    45,     0,     0,     0,     0,    46,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   623,   624,   625,   145,   144,     0,    99,   152,   149,
       0,   151,   150,   147,   146,     0,   108,     0,     0,   121,
       0,     0,   137,     0,     0,     0,   592,     0,     0,     0,
     588,     0,     0,     0,   602,     0,     0,   246,   247,   266,
     267,     0,     0,     0,     0,   128,     0,   132,   182,   616,
       0,    56,     0,    65,     0,     0,     0,    57,     0,     0,
       0,     0,     0,   767,   593,     0,     0,     0,     0,   328,
       0,     0,   591,     0,     0,     0,   610,     0,     0,     0,
       0,   596,     0,     0,   209,     0,     0,   201,   199,     0,
       0,     0,   487,     0,   489,     0,   514,   513,   510,     0,
       0,   544,   543,   423,     0,   541,     0,   636,   637,   587,
       0,     0,     0,     0,     0,     0,   642,     0,   206,     0,
     217,   218,     0,     0,     0,     0,     0,   222,   223,    20,
       0,    21,     0,     4,    25,     0,    11,    26,     0,    15,
     878,    73,    12,    74,    16,   207,   204,   230,     0,     0,
       0,     0,   220,   245,   301,   356,   358,   362,   368,   367,
     366,     0,   363,   360,   361,     0,   377,   376,   374,   380,
     381,   382,   379,   384,   385,   388,   387,     0,     0,     0,
       0,   419,     0,   432,   433,     0,   470,   467,   495,     0,
     985,   615,   493,     0,     0,   117,     0,     0,     0,    98,
       0,    88,    90,    91,    92,    93,    95,    96,    97,    89,
      94,    84,    85,     0,     0,   104,     0,   100,   102,   103,
     110,     0,     0,    83,    42,     0,     0,     0,     0,     0,
       0,     0,   717,   722,     0,     0,   718,   752,   705,   707,
     708,   709,   711,   713,   712,   710,   714,     0,     0,     0,
     153,     0,     0,     0,   107,     0,   156,     0,     0,   558,
     552,   589,   590,     0,     0,   606,     0,   603,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   248,   249,
       0,   254,   134,     0,     0,   129,     0,     0,     0,     0,
       0,     0,    58,     0,     0,     0,   282,   288,   285,     0,
     595,   594,   601,   609,     0,     0,     0,     0,   557,     0,
       0,     0,   415,     0,     0,     0,     0,   599,     0,   597,
       0,   210,     0,     0,     0,     0,     0,   513,   511,     0,
     502,     0,   491,   492,     0,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     208,   215,     0,   776,   783,   782,   936,     0,     0,     0,
     653,     0,   224,     0,     0,     0,   179,   179,   179,     0,
     255,     0,   312,   308,   310,     0,   302,   303,   365,     0,
       0,     0,     0,   683,   371,   656,   660,   662,   664,   666,
     669,   676,   677,   685,   888,   775,     0,   784,   390,   564,
     570,   571,   573,   617,   618,   574,   577,   392,   394,   561,
     396,   420,   471,     0,   468,   494,   119,    52,    53,    50,
      51,   125,   124,     0,    86,     0,     0,   105,   106,   111,
      70,    71,    48,    49,    69,   723,     0,   726,   753,     0,
     716,   715,   720,   719,   751,     0,     0,   728,     0,   724,
     727,   706,     0,     0,     0,     0,     0,     0,     0,   154,
     160,     0,     0,     0,     0,     0,   109,   112,     0,   157,
       0,     0,   182,     0,     0,   610,     0,     0,     0,     0,
     563,     0,   269,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   250,     0,     0,     0,     0,   295,     0,   292,
     297,   253,   135,   130,   133,     0,   202,     0,     0,    67,
      61,    64,    63,     0,    59,   286,     0,     0,   182,     0,
     326,   330,     0,     0,     0,   333,     0,     0,   339,     0,
       0,   346,     0,   350,     0,   417,   416,   182,     0,     0,
     211,     0,   213,   327,     0,     0,     0,   514,     0,   503,
       0,   537,   534,     0,   538,   539,     0,     0,   533,     0,
     508,   536,   535,     0,     0,     0,   629,   630,   626,     0,
       0,   634,   635,   631,   640,   638,     0,     0,     0,   644,
     216,     0,     0,     0,     0,     0,     0,   645,   646,     0,
       0,   225,    22,     0,    13,    17,    18,   309,   321,     0,
     322,     0,   313,   314,   315,   316,     0,   305,     0,     0,
       0,   667,   680,     0,   370,   372,     0,   699,     0,     0,
       0,     0,     0,     0,   655,   657,   658,   694,   695,   696,
     698,   697,     0,     0,   671,   670,     0,   674,   678,   692,
     690,   689,   682,   686,     0,     0,     0,     0,   567,   569,
     568,   565,   562,   496,   127,   126,    87,   101,   740,   721,
       0,   745,     0,   745,   734,   729,   155,   161,   163,   162,
       0,     0,     0,   113,   158,     0,    23,     0,   607,   608,
     611,   604,   605,   268,     0,     0,   281,   273,     0,   277,
       0,   271,     0,     0,     0,   290,     0,     0,     0,   252,
     293,   296,     0,   131,     0,     0,    66,     0,    60,   287,
       0,     0,   329,   331,   336,     0,   334,     0,     0,     0,
       0,     0,   340,     0,     0,     0,     0,   347,     0,     0,
     351,   418,     0,   600,   598,   212,     0,     0,   513,     0,
       0,   545,     0,   513,     0,   509,    10,     0,     0,     0,
       0,     0,   643,     0,     0,     0,     0,     0,   647,     0,
     654,   325,   323,   324,   317,   318,   319,   311,     0,   306,
     304,   684,   675,   681,     0,     0,   754,   755,   765,   764,
     763,     0,     0,     0,     0,   756,   661,   762,     0,   659,
     663,     0,     0,   668,   672,     0,   693,   688,   691,   687,
       0,     0,   575,     0,   572,   622,   566,   741,     0,     0,
     739,   746,   747,   743,     0,   738,     0,   736,     0,     0,
       0,     0,     0,   159,     0,   554,   270,     0,   279,     0,
       0,   275,     0,   278,   291,   299,   300,   294,   251,     0,
       0,     0,    62,   289,   560,     0,     0,   337,   341,   335,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   556,     0,     0,   513,     0,   540,     0,   513,   627,
     628,   632,   633,   639,   641,     0,     0,     0,     0,     0,
     648,     0,   320,   307,   679,   766,     0,     0,   758,     0,
     704,   703,   702,   701,   700,   665,     0,   757,     0,   619,
       0,     0,   750,   749,   748,     0,   742,   735,   733,     0,
     730,   731,   725,   164,   166,   168,     0,     0,     0,     0,
       0,   274,   272,     0,   280,     0,   221,   354,    68,   332,
     338,     0,   352,   348,     0,     0,     0,   342,     0,     0,
     344,     0,   523,   517,   512,     0,   513,   504,     0,     0,
       0,     0,     0,     0,     0,   760,   759,     0,     0,   620,
     576,     0,   744,   737,     0,     0,   170,   169,     0,     0,
       0,     0,   165,   276,     0,     0,     0,     0,     0,     0,
     531,   525,     0,   524,   526,   532,   529,   519,     0,   518,
     520,   530,   506,     0,   505,     0,   652,     0,     0,   226,
     761,   673,   621,   732,   167,   171,     0,     0,     0,     0,
     298,     0,     0,   345,   343,     0,     0,   516,   527,   528,
     515,   521,   522,   507,     0,     0,     0,     0,   172,     0,
       0,     0,   353,   349,     0,     0,     0,     0,   649,     0,
       0,     0,     0,     0,     0,     0,     0,   227,     0,   174,
       0,     0,     0,     0,   173,     0,     0,   650,     0,     0,
       0,   228,     0,     0,     0,   651,     0,     0,     0,     0,
     175
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1440, -1440,  -217,  1195, -1440,  1196,  1198, -1440,  1199,  -535,
   -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440,
    -959, -1440, -1440, -1440, -1440,  -218,  -568, -1440,   739,  -333,
   -1440, -1440, -1440, -1440, -1440,   317,   525, -1440, -1440,    19,
    -225, -1440, -1440,  1014, -1440, -1440,  -618, -1440,   460, -1440,
    1016, -1440,   278,  -920, -1440,  -170,  -214, -1440,  -511, -1440,
      10,    15,    87,  -240,  -175, -1440,  -831, -1440, -1440,  -507,
   -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440,
     625,    47,  1160,     0, -1440, -1440, -1440, -1440,   475, -1440,
   -1440,  -291, -1440,     6, -1440, -1440,   276,  -710,  -687, -1440,
   -1440,   696, -1440, -1440,    60,   262, -1440, -1440, -1440,   147,
   -1440, -1440,   390,   152, -1440, -1440,   159, -1257, -1440,   930,
     245, -1440, -1440,   241,  -961, -1440, -1440,   240, -1440, -1440,
   -1196, -1179, -1440,   237, -1440, -1440,   856,   847, -1440,  -527,
   -1440, -1440,  -634,   319,  -603,   314,   316, -1440, -1440, -1440,
   -1440, -1440,  1151, -1440, -1440, -1440, -1440,  -828,  -301, -1131,
   -1440,  -129, -1440, -1440, -1440, -1440, -1440, -1440, -1440,   -15,
    -774, -1440, -1440,   572,   236, -1440,  -363, -1440, -1440, -1440,
   -1440, -1440, -1440, -1440,   797, -1440,  -976, -1440,   223, -1440,
     678,  -776, -1440, -1440, -1440, -1440, -1440,  -215,  -206, -1171,
    -800, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440,
   -1440,   598,  -735,  -856,   320,  -834, -1440,    84,  -861, -1440,
   -1440, -1440, -1440, -1440, -1440, -1440,  1049,  1051,  -209,   515,
     357, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440,
   -1440, -1440, -1440, -1440, -1440,   208, -1440, -1440,   196, -1012,
     198, -1021, -1440, -1440, -1440,   165,   156,    -1,   410, -1440,
   -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440, -1440,
   -1440, -1440,   167, -1440, -1440, -1440,     5,   404,   549, -1440,
   -1440, -1440, -1440, -1440,   350, -1440, -1440, -1439, -1440, -1440,
   -1440,  -524, -1440,   134, -1440,   -11, -1440, -1440, -1440, -1440,
   -1240, -1440,   180, -1440,  -385,  -349,   483,   -46, -1440
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   241,   832,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
    1209,   756,   259,   260,   261,   262,   263,   264,   911,   912,
     913,   265,   266,   267,   917,   918,   919,   268,   427,   269,
     270,   678,   271,   429,   430,   431,   446,   746,   747,   432,
     433,   272,  1159,   950,   273,  1613,  1614,   274,   275,   276,
     537,   277,   278,   279,   280,   281,   749,   282,   283,   520,
     284,   285,   286,   287,   288,   289,   612,   290,   291,   827,
     828,   292,   293,   547,   295,   613,   444,   980,   981,   296,
     614,   297,   616,   548,   299,   739,   740,  1197,   453,   300,
     454,   455,   743,  1198,  1199,  1200,   617,   618,  1076,  1077,
    1469,   619,  1073,  1074,  1302,  1303,  1304,  1305,   301,   768,
     769,   302,  1224,  1225,  1417,   303,  1227,  1228,   304,   305,
    1230,  1231,  1232,  1233,   306,   307,   308,   309,   861,   310,
    1314,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   637,   638,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   664,   665,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   889,   350,   351,   352,  1259,   797,
     798,   799,  1644,  1688,  1689,  1682,  1683,  1690,  1684,  1260,
    1261,   353,   354,  1262,   355,   356,   357,   358,   359,   360,
     361,  1108,   975,  1098,  1351,  1099,  1503,  1100,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   775,  1174,
     372,   373,   374,   375,  1102,  1103,  1104,  1105,   376,   377,
     378,   379,   380,   381,   815,   816,   382,  1287,  1288,  1580,
    1061,  1084,  1324,  1325,  1085,  1086,  1087,  1088,  1089,  1334,
    1493,  1494,  1090,  1337,  1091,  1474,  1092,  1093,  1342,  1343,
    1499,  1497,  1326,  1327,  1328,  1329,  1593,   707,   938,   939,
     940,   941,   942,   943,  1149,  1519,  1610,  1150,  1517,  1608,
     944,  1363,  1514,  1510,  1511,  1512,   945,   946,  1330,  1338,
    1484,  1331,  1480,  1315,   383,   553,   384,   385,   386
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int xquery_parser::yytable_ninf_ = -768;
  const short int
  xquery_parser::yytable_[] =
  {
       294,   561,   582,   294,   294,   294,   298,   615,   868,   298,
     298,   298,   680,   391,   394,   395,  1101,  1101,   392,   392,
     392,  1029,  1107,   995,   659,   517,   841,   843,   590,   428,
     593,   973,  1370,   679,  1214,  1007,  1169,  1082,   598,   517,
     869,   870,   871,   872,   597,   595,  1465,  1466,  1226,  1021,
    1437,  1427,  1060,  1101,   974,  1258,   515,   834,   837,  1310,
     700,  1616,   517,  1186,   753,   757,   969,  1122,   818,   898,
     977,   677,   801,   591,   517,   591,   517,   451,   563,  1611,
    1126,   836,   839,   842,   844,   723,   591,  1160,  1445,   845,
     393,   393,   393,   846,   591,   857,  1495,   858,   859,   591,
     860,   728,   862,   591,   948,  1183,   294,   591,   765,  1101,
     863,   864,   298,   600,  1180,  1418,   927,  1216,   928,   729,
       8,   392,  1101,   971,   970,  1418,   971,  1203,  1047,  1168,
    1642,  1418,     8,  1586,   397,   398,   744,   399,   400,   643,
    1004,   474,  1392,   970,   602,   474,  1004,  1030,  1316,     8,
    1481,    77,   471,   598,   546,   403,  1152,   602,  1556,  1508,
     929,  1153,   728,   970,   649,    88,   640,  1617,   644,  1034,
    1641,  1299,   435,  1187,   587,   436,   972,  1154,   650,  1155,
     729,   645,  1121,   472,   641,  1129,   473,   681,  1156,   576,
     102,   588,  1301,   538,  1079,  1006,   601,  1080,   748,   660,
     682,  1419,  1680,   597,   575,   745,  1251,  1582,  1587,  1293,
     994,  1546,   396,  1031,  1157,   646,   596,  1551,   122,  1643,
    1317,  1005,  1112,  1509,   754,  1703,  1557,  1023,  1035,   978,
    1036,   452,   452,   819,   894,  1101,   802,   794,  1557,  1366,
     294,  1191,   730,   294,  1524,   949,   298,  1202,   452,   298,
    1618,  1248,  1082,  1082,  1408,  1048,   409,   615,  1427,   592,
     564,   594,  1346,   841,   843,  1188,  1421,   979,   452,  1445,
     949,   755,   829,  1316,  1258,   752,   695,  1609,   294,   696,
     831,   964,  1123,  1258,   298,  1066,  1184,   517,  1189,  1068,
     517,  1473,  1355,  1292,   834,   837,   465,   677,   598,   452,
    1081,  1360,   452,  1318,  1319,   966,  1320,  1160,  1217,  1482,
    1483,   930,  1050,   924,   895,   412,   984,  1254,   666,  1255,
     602,   668,   890,  1322,   931,   599,   932,  1681,   602,   602,
     602,  1132,  1133,  1064,  1078,  1323,   698,   933,   934,   935,
    1158,   936,   971,   937,  1101,  1317,  1016,  1256,   602,  1403,
     588,   597,  1037,  1038,   466,   687,   517,   414,  1666,   517,
    1362,   965,  1018,   517,   640,   602,   438,  1039,  1101,   517,
     852,   992,   830,  1424,   835,   838,   517,    77,  1113,  1113,
    1680,  1650,   641,   602,  1251,   967,  1040,  1249,   517,  1615,
     602,    88,  1384,   294,   517,  -767,   985,   517,   699,   298,
     987,  1284,   602,   988,  1289,   517,   991,   963,  1009,  1010,
    1705,   517,   517,   517,   517,   566,   102,   567,  1146,   517,
    1079,   467,   468,  1080,   971,   999,  1017,   517,  1318,  1319,
       8,  1320,  1373,   970,  1147,   294,   445,   294,  1321,  1251,
     599,   298,  1019,   298,   122,  1052,   677,   727,  1322,   602,
     724,   401,   392,  1250,  1523,   602,  1686,  1290,  1114,  1115,
    1323,   294,   602,  1244,  1258,  1578,   294,   298,  1579,  1385,
    1245,  1427,   298,   517,  1529,  1590,   771,  1148,   404,  1015,
    1020,   777,  1591,  1101,  1082,   598,   733,   517,  1502,  1615,
     602,  1600,  1592,  1082,   750,  1254,   517,  1255,   841,   843,
     841,  1393,  1083,   762,  1082,  1718,  1605,  1140,  1041,  1042,
     773,   774,  1060,  1251,   718,   689,  1460,   695,  1141,   780,
     696,  1290,   725,  1043,   393,  1256,    77,  1653,   517,  1246,
    1686,  1116,   883,   884,  1615,  1575,  1130,  1131,   294,   434,
      88,  1134,  1576,   294,   298,  1251,  1252,   690,   725,   298,
    1254,   697,  1255,   725,   516,  1294,  1295,  1296,   392,  1251,
    1252,  1687,  1725,  1739,  1101,   102,  1751,  1101,   532,  1555,
    1577,  1601,  1559,  1171,  1251,  1252,   602,   698,  1124,   970,
    1256,   294,  1628,   602,   598,   599,  1606,   298,   437,   602,
    1124,   549,   294,   294,   294,   294,   602,   800,   298,   298,
     298,   298,   602,   554,  1210,   557,   428,  1654,  1210,   804,
     294,  1063,  1348,  1476,   602,  1421,   298,  1754,  1067,  1755,
     602,  1251,  1252,   658,  1254,   517,  1255,   823,   825,  1142,
     393,  1190,   647,  1360,   447,  1721,  1253,   640,  1770,   699,
    1143,   648,  1726,  1740,  1349,   900,  1752,   122,   517,  1361,
    1253,  1477,   441,  1032,  1256,   641,  1254,   442,  1255,  1193,
    1033,  1350,  1563,  1082,  1194,  1253,  1059,  1567,   824,   517,
    1254,   604,  1255,  1111,   517,   517,   605,   642,  1117,  1471,
    1530,   606,  1195,   604,  1312,  1254,  1256,  1255,   605,  1488,
     108,  1696,  1362,   606,   458,  1118,   517,  1701,   517,   607,
    1256,   971,   443,  1119,   108,   882,   517,   120,   122,   517,
     885,   607,  1253,   517,  1738,  1256,   459,  1083,  1083,   108,
    1120,   120,  1196,  1193,   841,   294,   914,  1257,  1194,   640,
     685,   298,  1254,   604,  1255,   460,   120,  1101,   605,  1101,
    1757,  1439,  1659,   606,  1660,   146,   686,   641,   294,   439,
     517,  1765,   440,   970,   298,  1173,  1444,  1176,   986,   146,
    1354,   607,  1256,   392,  1299,   971,   108,   615,   915,  1657,
    1101,  1146,   599,   916,   146,  1675,   748,   448,   294,   294,
     517,   659,   683,   120,   298,   298,   449,  1147,  1645,  1164,
     463,  1223,  1648,  1013,  1014,   684,   608,  1223,  1165,   609,
    1101,   572,   517,  1565,  1415,  1702,   573,  1238,   608,  1239,
    1420,   609,  1280,   450,   610,  1101,   516,  1101,  1478,   516,
    1712,   146,  1715,  1406,  1057,  1479,   795,   569,  1210,   570,
    1058,   517,   517,   517,   517,   393,  1024,  1025,  1026,   611,
     825,   464,  1685,  1691,  1298,  1590,  1339,  1340,  1588,  1589,
    1425,   611,  1591,   456,  1299,   410,   457,   469,   608,   428,
    1428,   609,  1592,  1426,  1300,   725,   725,   470,   517,  1341,
    1693,  1425,  1585,  1429,   716,  1301,  1285,  1425,   518,   717,
    1667,   582,   517,  1685,  1562,   688,  1291,   411,   692,  1691,
    1695,   915,   554,  1135,  1136,  1137,   916,  1193,   708,  1138,
     886,   611,  1194,   886,   519,   710,   886,   667,   461,   517,
     521,   462,   670,   522,  1461,   413,   533,   554,   517,   663,
     517,   669,   534,   736,   517,   535,   741,   701,   702,   703,
    1264,   550,  1265,  1269,   758,  1270,   551,   517,   661,   662,
     554,   766,   767,   770,   704,   705,   713,   714,   776,  1083,
    1161,  1162,  1655,  1656,  1462,  1463,   783,   558,  1083,   866,
     867,   873,   874,  1109,  1109,   875,   876,  1404,   559,  1083,
     517,   560,   517,   720,   416,   417,   418,   419,   562,   420,
     421,   721,   423,   424,  1602,  1603,   568,   565,   425,   901,
     902,   903,   904,   905,   906,   907,   908,   909,   910,   571,
     574,   579,   784,   577,   578,   581,   580,     8,   584,   602,
     603,   294,   620,   621,   651,   639,   770,   298,   652,   653,
     663,   654,  1542,  1700,   671,   792,  1234,   673,   401,   517,
     672,   674,   675,   474,   691,   676,   693,   402,   706,   694,
     711,   712,   709,   715,   726,   852,   742,   748,   737,   751,
     517,   738,  1057,   759,   760,   404,   761,   817,  1058,   405,
     772,   436,   778,   779,   785,   787,   294,   294,   294,   440,
     622,   457,   298,   298,   298,   796,   793,   803,   623,   624,
     462,   625,   473,  1583,   428,   789,   790,   791,   805,   626,
     406,   407,  1069,   627,   806,   628,   820,   814,   725,   826,
     629,   809,   833,   850,   848,   849,   821,   865,   877,   851,
     878,   879,   880,   891,   896,   897,   899,   630,   921,   922,
     925,   926,   947,   951,   953,   959,  1309,   955,  1083,   958,
     960,   961,   517,   968,   962,   517,   983,   989,   990,   993,
     631,   632,   633,   634,   635,   636,  1044,  1000,   410,  1011,
     517,  1008,  1001,  1002,   554,  1003,  1210,  1012,  1046,   517,
    1049,  1045,  1051,  1065,  1071,  1075,  1125,   916,   970,  1144,
    1178,  1163,   294,   517,  1145,  1172,  1170,   920,   298,  1548,
     411,  1179,  1377,   517,  1181,  1185,  1192,   392,   744,  1205,
    1206,  1208,  1207,  1211,  1212,  1213,  1218,  1219,   952,  1223,
    1222,  1229,  1237,   956,   957,  1235,  1247,   294,   413,  1241,
    1242,   517,  1236,   298,  1263,  1277,  1281,  1282,   294,  1283,
    1286,  1284,   697,  1306,   298,   976,  1308,   982,  1411,  1332,
    1333,   517,  1344,   392,  1345,   554,  1313,   294,   554,  1347,
     517,  1336,   996,   298,   517,   677,  1352,  1432,  1359,  1358,
    1364,  1380,   392,  1368,  1372,   949,   294,  1369,  1375,   393,
    1388,  1376,   298,  1371,  1378,  1390,   415,   416,   417,   418,
     419,  1442,   420,   421,   422,   423,   424,  1379,  1381,  1027,
    1382,   425,   426,  1394,  1057,  1057,  1397,  1396,  1402,  1398,
    1058,  1058,  1407,  1410,  1431,  1433,  1434,  1436,   517,  1626,
    1425,  1438,  1441,  1453,  1446,   393,  1447,  1448,  1451,   516,
    1630,  1548,  1449,  1632,  1450,  1459,  1496,  1299,  1468,  1472,
    1640,  1491,  1498,  1507,   393,   517,  1492,  1513,  1454,  1455,
    1456,  1070,  1504,  1505,  1475,  1485,  1506,  1518,  1522,  1525,
    1516,  1527,  1520,   725,  1541,  1532,  1544,  1539,  1540,  1545,
    1550,   517,   517,  1553,  1596,  1598,  1607,  1620,  1146,  1560,
    1106,  1106,  1106,  1106,  1561,  1566,  1584,  1597,  1625,  1631,
    1599,   824,  1623,  1612,  1635,  1619,  1639,   517,  1661,   517,
    1652,  1662,   517,  1663,  1664,  1647,  1665,  1669,  1649,  1670,
    1674,  1676,  1677,   517,  1678,  1692,  1698,  1106,   517,  1632,
    1694,  1709,  1708,  1711,  1717,  1716,  1720,  1724,  1706,  1404,
    1723,  1139,  1731,   517,  1734,  1735,  1729,  1578,  1737,   294,
    1741,  1744,  1746,  1756,  1758,   298,  1742,  1763,  1748,  1750,
    1759,  1762,  1766,  1767,  1769,   583,   923,  1713,  1167,   585,
    1127,   586,   719,  1357,  1204,   589,  1374,  1175,   722,  1175,
    1672,  1704,  1062,  1106,  1383,  1470,  1201,   998,  1467,  1401,
    1537,  1297,  1464,   786,  1412,  1416,  1106,  1422,   856,  1430,
     893,  1732,   657,  1440,  1722,  1028,   855,  1719,  1110,  1699,
    1367,  1177,  1356,  1458,  1457,  1452,  1486,   731,  1490,   732,
    1595,  1311,  1489,  1594,  1335,  1732,  1151,  1515,  1365,   776,
    1604,   776,  1487,     0,  1713,     0,     0,     0,   517,     0,
     517,     0,   517,     0,     0,     0,     0,     0,     0,   517,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1057,
       0,     0,     0,     0,     0,  1058,     0,     0,     0,     0,
    1057,  1057,   517,   294,   517,     0,  1058,  1058,  1307,   298,
    1057,     0,     0,     0,     0,  1747,  1058,     0,     0,     0,
     517,     0,     0,   517,     0,     0,     0,     0,     0,  1106,
       0,     0,     0,  1761,     0,   517,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   517,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   517,     0,     0,     0,
       0,     0,     0,     0,     0,   517,     0,     0,     0,     0,
       0,     0,     0,   517,     0,  1651,     0,     0,   517,     0,
     517,     0,   517,     0,     0,     0,     0,     0,     0,  1057,
       0,     0,     0,  1658,     0,  1058,     0,     0,     0,  1057,
       0,     0,   517,     0,     0,  1058,     0,     0,     0,     0,
       0,   741,   517,     0,  1386,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   294,   517,  1400,
       0,     0,     0,   298,     0,   517,     0,     0,  1106,     0,
       0,   517,     0,     0,     0,     0,     0,     0,     0,     0,
     517,     0,   770,     0,     0,     0,     0,     0,     0,     0,
     517,   294,  1106,     0,     0,     0,   517,   298,     0,     0,
       0,   517,     0,     0,     0,     0,   807,   808,     0,   810,
     811,   812,   813,     0,     0,  1057,     0,     0,     0,   822,
    1443,  1058,     0,     0,  1057,     0,     0,     0,     0,     0,
    1058,     0,     0,     8,     0,     0,     0,     0,     0,     0,
     817,     0,   847,   397,   398,     0,   399,   400,     0,   516,
     853,   854,     0,   516,   401,     0,     0,     0,     0,     0,
       0,     0,     0,   402,   403,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   404,     0,     0,     0,   405,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1106,     0,   888,
       0,     0,     0,   888,     0,     0,   406,   407,   408,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1521,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   954,     0,     0,
    1535,  1536,     0,     0,     0,   409,     0,     0,     0,     0,
       0,     0,     0,     0,   410,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1552,     0,  1106,     0,
       0,  1106,     0,     0,     0,     0,     0,     0,     0,     0,
     997,     0,  1564,     0,     0,     0,   411,  1568,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1581,     0,   412,  1022,     0,     0,     0,     0,
       0,     0,     0,     0,   413,   853,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   414,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1072,     0,   415,   416,   417,   418,   419,     0,   420,   421,
     422,   423,   424,     0,     0,     0,     0,   425,   426,     0,
       0,     0,     0,     0,     0,     0,     0,  1634,     0,  1636,
       0,  1638,     0,     0,     0,     0,     0,     0,  1646,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1128,     0,     0,     0,
       0,  1106,     0,  1106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1668,
       0,     0,  1671,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1166,  1106,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1679,     0,     0,     0,     0,     0,
       0,     0,  1182,     0,     0,  1697,     0,     0,     0,     0,
       0,     0,     0,     0,  1106,     0,     0,     0,     0,     0,
       0,     0,  1707,     0,  1215,     0,     0,  1710,     0,  1106,
       0,  1106,     0,     0,     0,  1220,  1221,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1240,  1727,     0,  1243,     0,     0,     0,     0,     0,     0,
       0,  1730,     0,     0,     0,     0,     0,  1266,  1267,  1268,
       0,  1271,  1272,  1273,  1274,  1275,  1276,  1736,  1278,  1279,
       0,     0,     0,     0,  1743,     0,     0,     0,     0,     0,
    1745,     0,     0,     0,     0,     0,     0,     0,     0,  1753,
       0,  1072,     0,     0,     0,     0,     0,     0,     0,  1760,
       0,     0,     0,     0,     0,  1764,     0,     0,     0,     0,
    1768,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1353,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1387,     0,  1389,     0,  1391,     0,     0,
    1395,     0,     0,     0,     0,  1399,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1405,     0,     0,
       0,     0,     0,     0,     0,     0,  1409,     0,     0,     0,
       0,     0,  1413,  1414,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1435,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1072,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1526,     0,     0,     0,  1528,     0,
       0,     0,  1531,     0,  1533,     0,  1534,     0,     0,     0,
       0,     0,  1538,     0,     0,     0,     0,     0,     0,     0,
    1543,     0,     0,     0,     0,     0,     0,     0,  1547,  1549,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1405,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1569,  1570,  1571,
    1572,  1573,     0,  1574,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1621,     0,  1622,
       0,     0,  1624,     0,     0,     0,     0,     0,     0,     0,
    1627,     0,     0,     0,     0,  1629,  1549,     0,     0,     0,
       0,     0,     0,  1633,     0,     0,     0,  1637,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1673,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1633,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1714,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1728,     0,     0,     0,
       0,  1733,     0,     0,     0,     0,  1714,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,     0,
       0,     0,     0,     0,  1733,     2,     3,     4,     5,     6,
       7,     8,  1749,     9,     0,     0,     0,    10,    11,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,     0,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,     0,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,    67,    68,
      69,    70,    71,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,     0,     0,     0,    88,     0,    89,
      90,    91,    92,     0,    93,     0,     0,     0,    94,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,   105,   106,     0,     0,   107,
     108,   109,   110,   111,     0,     0,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,     0,   120,     0,   121,
     122,     0,     0,   123,   124,   125,     0,     0,     0,   126,
       0,   127,   128,     0,   129,   130,   131,     0,   132,     0,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,     0,     0,   144,   145,   146,     0,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,     0,   191,   192,   193,     0,   194,   195,   196,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,     1,     0,     0,     0,     0,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     8,     0,
       9,     0,     0,     0,   387,   388,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   389,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,     0,    67,    68,    69,    70,    71,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,     0,     0,     0,    88,     0,    89,    90,    91,    92,
       0,    93,     0,     0,     0,    94,    95,    96,    97,    98,
       0,     0,     0,     0,     0,     0,    99,   100,   101,   102,
     103,   104,   105,   106,     0,     0,   107,   108,   109,   110,
     111,     0,     0,     0,     0,   112,   113,   114,   115,   116,
     117,   118,   119,     0,   120,     0,   121,   122,     0,     0,
     123,   124,   125,     0,   536,     0,   126,     0,   127,   128,
       0,   129,   130,   131,     0,   132,     0,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,     0,     0,
     144,   145,   146,     0,   390,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,     0,   191,
     192,   193,     0,   194,   195,   196,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
       1,     0,     0,     0,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,     0,
     387,   388,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   389,    27,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
       0,    67,    68,    69,    70,    71,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,     0,     0,     0,
      88,     0,    89,    90,    91,    92,     0,    93,     0,     0,
       0,    94,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,    99,   100,   101,   102,   103,   104,   105,   106,
       0,     0,   107,   108,   109,   110,   111,     0,     0,     0,
       0,   112,   113,   114,   115,   116,   117,   118,   119,     0,
     120,     0,   121,   122,     0,     0,   123,   124,   125,     0,
     788,     0,   126,     0,   127,   128,     0,   129,   130,   131,
       0,   132,     0,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,     0,     0,   144,   145,   146,     0,
     390,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,     0,   191,   192,   193,     0,   194,
     195,   196,   197,   198,   199,     0,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,     1,     0,     0,     0,
       0,     0,     0,     0,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,     0,     0,   387,   388,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,  1053,   389,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,  1054,  1055,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,     0,    67,    68,    69,
      70,    71,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,     0,    88,     0,    89,    90,
      91,    92,     0,    93,     0,     0,     0,    94,    95,    96,
      97,    98,     0,     0,     0,     0,     0,     0,    99,   100,
     101,   102,   103,   104,   105,   106,     0,     0,   107,   108,
     109,   110,   111,     0,     0,     0,     0,   112,   113,   114,
     115,   116,   117,   118,   119,     0,   120,     0,   121,   122,
       0,     0,   123,   124,   125,     0,   788,     0,   126,     0,
     127,   128,     0,   129,   130,   131,     0,   132,     0,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
       0,     0,   144,   145,   146,     0,   390,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,  1056,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
       0,   191,   192,   193,     0,   194,   195,   196,   197,   198,
     199,     0,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,     1,     0,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,     0,   387,   388,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,  1053,   389,
      27,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,    44,
      45,    46,  1054,  1055,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,     0,    67,    68,    69,    70,    71,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,     0,    88,     0,    89,    90,    91,    92,     0,    93,
       0,     0,     0,    94,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,    99,   100,   101,   102,   103,   104,
     105,   106,     0,     0,   107,   108,   109,   110,   111,     0,
       0,     0,     0,   112,   113,   114,   115,   116,   117,   118,
     119,     0,   120,     0,   121,   122,     0,     0,   123,   124,
     125,     0,   536,     0,   126,     0,   127,   128,     0,   129,
     130,   131,     0,   132,     0,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,     0,     0,   144,   145,
     146,     0,   390,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,  1056,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,     0,   191,   192,   193,
       0,   194,   195,   196,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,     1,     0,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,     0,   387,   388,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   389,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     0,    67,
      68,    69,    70,    71,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,     0,    88,     0,
      89,    90,    91,    92,     0,    93,     0,     0,     0,    94,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
      99,   100,   101,   102,   103,   104,   105,   106,     0,     0,
     107,   108,   109,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,     0,   120,     0,
     121,   122,     0,     0,   123,   124,   125,     0,     0,     0,
     126,     0,   127,   128,     0,   129,   130,   131,     0,   132,
       0,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,     0,     0,   144,   145,   146,     0,   390,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,     0,   191,   192,   193,     0,   194,   195,   196,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,     1,     0,     0,     0,     0,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     0,     0,
       9,     0,     0,     0,   387,   388,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
     539,   389,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,   540,   541,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,     0,    67,    68,    69,    70,    71,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,   492,    80,    81,    82,    83,    84,   542,    86,
      87,     0,     0,     0,    88,     0,    89,    90,    91,    92,
       0,    93,     0,     0,     0,    94,    95,    96,    97,    98,
       0,     0,     0,     0,     0,     0,    99,   100,   101,   102,
     103,   104,   105,   543,     0,     0,   107,   108,   109,   110,
     111,     0,     0,     0,     0,   112,   113,   114,   115,   116,
     117,   118,   119,     0,   120,     0,   121,   122,     0,     0,
     123,   124,   125,     0,     0,     0,   126,   544,   127,   128,
       0,   129,   130,   131,     0,   132,     0,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,     0,     0,
     144,   145,   146,     0,   390,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   509,   510,   511,
     512,   174,   175,   513,   545,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,     0,   191,
     192,   193,     0,   194,   195,   196,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
       1,     0,     0,     0,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,     0,
      10,    11,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
       0,    67,    68,    69,    70,    71,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,     0,     0,     0,
      88,     0,    89,    90,    91,    92,     0,    93,     0,     0,
       0,    94,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,    99,   100,   101,   102,   103,   104,   105,   106,
       0,     0,   107,   108,   109,   110,   111,     0,     0,     0,
       0,   112,   113,   114,   115,   116,   117,   118,   119,     0,
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
     234,   235,   236,   237,   238,   239,     1,     0,     0,     0,
       0,     0,     0,     0,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,     0,     0,    10,    11,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,     0,    67,    68,    69,
      70,    71,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,     0,    88,     0,    89,    90,
      91,    92,     0,    93,     0,     0,     0,    94,    95,    96,
      97,    98,     0,     0,     0,     0,     0,     0,    99,   100,
     101,   102,   103,   104,   105,   106,     0,     0,   107,   108,
     109,   110,   111,     0,     0,     0,     0,   112,   113,   114,
     115,   116,   117,   118,   119,     0,   120,     0,   121,   122,
       0,     0,   123,   124,   125,     0,     0,     0,   126,     0,
     127,   128,     0,   129,   130,   131,     0,   132,     0,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
       0,     0,   144,   145,   146,     0,   390,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
       0,   191,   192,   193,     0,   194,   195,   196,   197,   198,
     199,     0,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,     1,     0,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,     0,    10,   388,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,     0,    67,    68,    69,    70,    71,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,     0,    88,     0,    89,    90,    91,    92,     0,    93,
       0,     0,     0,    94,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,    99,   100,   101,   102,   103,   104,
     105,   106,     0,     0,   107,   108,   109,   110,   111,     0,
       0,     0,     0,   112,   113,   114,   115,   116,   117,   118,
     119,     0,   120,     0,   121,   122,     0,     0,   123,   124,
     125,     0,     0,     0,   126,     0,   127,   128,     0,   129,
     130,   131,     0,   132,     0,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,     0,     0,   144,   145,
     146,     0,   390,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,     0,   191,   192,   193,
       0,   194,   195,   196,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,     1,     0,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,     0,   840,   388,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   389,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     0,    67,
      68,    69,    70,    71,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,     0,    88,     0,
      89,    90,    91,    92,     0,    93,     0,     0,     0,    94,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
      99,   100,   101,   102,   103,   104,   105,   106,     0,     0,
     107,   108,   109,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,     0,   120,     0,
     121,   122,     0,     0,   123,   124,   125,     0,     0,     0,
     126,     0,   127,   128,     0,   129,   130,   131,     0,   132,
       0,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,     0,     0,   144,   145,   146,     0,   390,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,     0,   191,   192,   193,     0,   194,   195,   196,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,     1,     0,     0,     0,     0,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     0,     0,
       9,     0,     0,     0,   387,   388,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
     539,   389,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,   540,   541,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,     0,    67,    68,    69,    70,    71,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,   492,    80,    81,    82,    83,    84,   542,    86,
      87,     0,     0,     0,    88,     0,    89,    90,    91,    92,
       0,    93,     0,     0,     0,    94,    95,    96,    97,    98,
       0,     0,     0,     0,     0,     0,    99,   100,   101,   102,
     103,   104,   105,   543,     0,     0,   107,   108,   109,   110,
     111,     0,     0,     0,     0,   112,   113,   114,   115,   116,
     117,   118,   119,     0,   120,     0,   121,   122,     0,     0,
     123,   124,   125,     0,   881,     0,   126,     0,   127,   128,
       0,   129,   130,   131,     0,   132,     0,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,     0,     0,
     144,   145,   146,     0,   390,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   509,   510,   511,
     512,   174,   175,   513,   545,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,     0,   191,
     192,   193,     0,   194,   195,   196,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
       1,     0,     0,     0,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     0,     0,     9,     0,     0,     0,
     387,   388,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,   539,   389,    27,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,    44,    45,    46,
     540,   541,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
       0,    67,    68,    69,    70,    71,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,   492,    80,
      81,    82,    83,    84,   542,    86,    87,     0,     0,     0,
      88,     0,    89,    90,    91,    92,     0,    93,     0,     0,
       0,    94,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,    99,   100,   101,   102,   103,   104,   105,   543,
       0,     0,   107,   108,   109,   110,   111,     0,     0,     0,
       0,   112,   113,   114,   115,   116,   117,   118,   119,     0,
     120,     0,   121,   122,     0,     0,   123,   124,   125,     0,
       0,     0,   126,   887,   127,   128,     0,   129,   130,   131,
       0,   132,     0,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,     0,     0,   144,   145,   146,     0,
     390,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   509,   510,   511,   512,   174,   175,   513,
     545,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,     0,   191,   192,   193,     0,   194,
     195,   196,   197,   198,   199,     0,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,     1,     0,     0,     0,
       0,     0,     0,     0,     2,     3,     4,     5,     6,     7,
       0,     0,     9,     0,     0,     0,   387,   388,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,   539,   389,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,   540,   541,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,     0,    67,    68,    69,
      70,    71,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,   492,    80,    81,    82,    83,    84,
     542,    86,    87,     0,     0,     0,    88,     0,    89,    90,
      91,    92,     0,    93,     0,     0,     0,    94,    95,    96,
      97,    98,     0,     0,     0,     0,     0,     0,    99,   100,
     101,   102,   103,   104,   105,   543,     0,     0,   107,   108,
     109,   110,   111,     0,     0,     0,     0,   112,   113,   114,
     115,   116,   117,   118,   119,     0,   120,     0,   121,   122,
       0,     0,   123,   124,   125,     0,     0,     0,   126,   892,
     127,   128,     0,   129,   130,   131,     0,   132,     0,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
       0,     0,   144,   145,   146,     0,   390,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   509,
     510,   511,   512,   174,   175,   513,   545,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
       0,   191,   192,   193,     0,   194,   195,   196,   197,   198,
     199,     0,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,     1,     0,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,     0,   387,   388,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,  1053,   389,
      27,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,    44,
      45,    46,  1054,  1055,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,     0,    67,    68,    69,    70,    71,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,     0,    88,     0,    89,    90,    91,    92,     0,    93,
       0,     0,     0,    94,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,    99,   100,   101,   102,   103,   104,
     105,   106,     0,     0,   107,   108,   109,   110,   111,     0,
       0,     0,     0,   112,   113,   114,   115,   116,   117,   118,
     119,     0,   120,     0,   121,   122,     0,     0,   123,   124,
     125,     0,     0,     0,   126,     0,   127,   128,     0,   129,
     130,   131,     0,   132,     0,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,     0,     0,   144,   145,
     146,     0,   390,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,  1056,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,     0,   191,   192,   193,
       0,   194,   195,   196,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,     1,     0,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     0,     0,     9,     0,     0,     0,   387,   388,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,   478,    24,   480,   389,    27,   481,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,   483,     0,    44,    45,    46,   485,   486,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     0,    67,
      68,    69,    70,    71,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,   492,    80,    81,    82,
      83,    84,   542,    86,    87,     0,     0,     0,    88,     0,
      89,    90,    91,    92,     0,    93,     0,     0,     0,   495,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
      99,   100,   101,   102,   103,   104,   105,   543,     0,     0,
     107,   108,   655,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,     0,   120,     0,
     656,   122,     0,     0,   123,   124,   125,     0,     0,     0,
     126,     0,   127,   128,     0,   129,   130,   131,     0,   132,
       0,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,     0,     0,   144,   145,   146,     0,   390,   148,
     149,   150,   151,   152,   153,   154,   155,   504,   157,   505,
     159,   506,   507,   162,   163,   164,   165,   166,   167,   508,
     169,   509,   510,   511,   512,   174,   175,   513,   514,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,     0,   191,   192,   193,     0,   194,   195,   196,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,     1,     0,     0,     0,     0,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     0,     0,
       9,     0,     0,     0,   387,   388,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
     539,   389,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,   540,   541,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,     0,    67,    68,    69,    70,    71,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,   492,    80,    81,    82,    83,    84,   542,    86,
      87,     0,     0,     0,    88,     0,    89,    90,    91,    92,
       0,    93,     0,     0,     0,    94,    95,    96,    97,    98,
       0,     0,     0,     0,     0,     0,    99,   100,   101,   102,
     103,   104,   105,   543,     0,     0,   107,   108,   109,   110,
     111,     0,     0,     0,     0,   112,   113,   114,   115,   116,
     117,   118,   119,     0,   120,     0,   121,   122,     0,     0,
     123,   124,   125,     0,     0,     0,   126,     0,   127,   128,
       0,   129,   130,   131,     0,   132,     0,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,     0,     0,
     144,   145,   146,     0,   390,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   509,   510,   511,
     512,   174,   175,   513,   545,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,     0,   191,
     192,   193,     0,   194,   195,   196,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
       1,     0,     0,     0,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     0,     0,     9,     0,     0,     0,
     387,   388,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,   478,    24,   480,   389,    27,   481,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,   483,     0,    44,    45,    46,
     485,   486,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
       0,    67,    68,    69,    70,    71,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,   492,    80,
      81,    82,    83,    84,   542,    86,    87,     0,     0,     0,
      88,     0,    89,    90,    91,    92,     0,    93,     0,     0,
       0,   495,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,    99,   100,   101,   102,   103,   104,   105,   543,
       0,     0,   107,   108,   109,   110,   111,     0,     0,     0,
       0,   112,   113,   114,   115,   116,   117,   118,   119,     0,
     120,     0,   121,   122,     0,     0,   123,   124,   125,     0,
       0,     0,   126,     0,   127,   128,     0,   129,   130,   131,
       0,   132,     0,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,     0,     0,   144,   145,   146,     0,
     390,   148,   149,   150,   151,   152,   153,   154,   155,   504,
     157,   505,   159,   506,   507,   162,   163,   164,   165,   166,
     167,   508,   169,   509,   510,   511,   512,   174,   175,   513,
     514,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,     0,   191,   192,   193,     0,   194,
     195,   196,   197,   198,   199,     0,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,     1,     0,     0,     0,
       0,     0,     0,     0,     2,     3,     4,     5,     6,     7,
       0,     0,     9,     0,     0,     0,   387,   388,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
     478,    24,   480,   389,    27,   481,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   483,     0,    44,    45,    46,   485,   486,    49,   487,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,     0,    67,    68,    69,
      70,    71,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,   492,    80,    81,    82,    83,    84,
     542,    86,    87,     0,     0,     0,    88,     0,    89,    90,
      91,    92,     0,    93,     0,     0,     0,   495,    95,    96,
      97,    98,     0,     0,     0,     0,     0,     0,    99,   100,
     101,   102,   103,   104,   105,   543,     0,     0,   107,   108,
       0,   110,   111,     0,     0,     0,     0,   112,   113,   114,
     115,   116,   117,   118,   119,     0,   120,     0,     0,     0,
       0,     0,   123,   124,   125,     0,     0,     0,   126,     0,
     127,   128,     0,   129,   130,   131,     0,   132,     0,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
       0,     0,   144,   145,   146,     0,   390,   148,   149,   150,
     151,   152,   153,   154,   155,   504,   157,   505,   159,   506,
     507,   162,   163,   164,   165,   166,   167,   508,   169,   509,
     510,   511,   512,   174,   175,   513,   514,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
       0,   191,   192,   193,     0,   194,   195,   196,   197,   198,
     199,     0,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,     1,     0,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     0,     0,     9,     0,
       0,     0,   387,   388,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,   478,    24,   480,   389,
      27,   481,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,   483,     0,    44,
      45,    46,   485,   486,    49,   487,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,     0,    67,    68,    69,    70,    71,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,    77,    78,
     492,    80,    81,    82,    83,    84,   542,    86,    87,     0,
       0,     0,    88,     0,    89,    90,    91,    92,     0,    93,
       0,     0,     0,   495,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,    99,   100,   101,   102,   103,   104,
     105,   543,     0,     0,   107,   108,     0,   110,   111,     0,
       0,     0,     0,   112,   113,   114,   115,   116,   117,   118,
     119,     0,   120,     0,     0,     0,     0,     0,   123,   124,
     125,     0,     0,     0,   126,     0,   127,   128,     0,     0,
       0,   131,     0,   132,     0,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,     0,     0,   144,   145,
     146,     0,   390,   148,   149,   150,   151,   152,   153,   154,
     155,   504,   157,   505,   159,   506,   507,   162,   163,   164,
     165,   166,   167,   508,   169,   509,   510,   511,   512,   174,
     175,   513,   514,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,     0,   191,   192,   193,
       0,   194,   195,   196,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,     1,     0,
       0,     0,     0,     0,     0,     0,     2,     0,     0,     0,
       6,     7,     0,     0,   474,     0,     0,     0,   387,   388,
       0,    12,    13,    14,   475,    16,    17,    18,   476,    20,
     477,    22,   478,   479,   480,   389,    27,   481,    29,    30,
       0,    31,    32,    33,    34,   482,    36,    37,    38,    39,
      40,    41,    42,   483,     0,    44,   484,    46,   485,   486,
      49,   487,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,   488,   489,    66,     0,    67,
      68,    69,   490,     0,    72,    73,    74,     0,     0,   491,
      76,     0,     0,     0,     0,    78,   492,    80,   493,   494,
      83,    84,     0,     0,     0,     0,     0,     0,     0,     0,
      89,    90,    91,    92,     0,    93,     0,     0,     0,   495,
      95,    96,   496,   497,     0,     0,     0,     0,     0,     0,
      99,   100,   101,     0,   103,   104,   105,     0,     0,     0,
       0,     0,     0,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   498,   117,   118,   499,     0,     0,     0,
       0,     0,     0,     0,   500,   501,   125,     0,     0,     0,
     126,     0,   127,   502,     0,     0,     0,   131,     0,   132,
       0,   133,   134,   135,   136,   503,   138,   139,   140,   141,
     142,   143,     0,     0,   144,   145,     0,     0,   390,   148,
     149,   150,   151,   152,   153,   154,   155,   504,   157,   505,
     159,   506,   507,   162,   163,   164,   165,   166,   167,   508,
     169,   509,   510,   511,   512,   174,   175,   513,   514,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,     0,   191,   192,   193,     0,   194,   195,   196,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,     1,     0,     0,     0,     0,     0,
       0,     0,     2,     0,     0,     0,     6,     7,     0,     0,
     474,     0,     0,     0,   387,   388,     0,    12,    13,    14,
     523,    16,    17,    18,   476,   524,   525,    22,   478,   479,
     480,   389,    27,   481,    29,    30,     0,    31,    32,    33,
      34,   526,    36,   527,   528,    39,    40,    41,    42,   483,
       0,    44,   529,    46,   485,   486,    49,   487,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,   488,   489,    66,     0,    67,    68,    69,   530,     0,
      72,    73,    74,     0,     0,   491,    76,     0,     0,     0,
       0,    78,   492,    80,   493,   494,    83,    84,     0,     0,
       0,     0,     0,     0,     0,     0,    89,    90,    91,    92,
       0,    93,     0,     0,     0,   495,    95,    96,   496,   497,
       0,     0,     0,     0,     0,     0,    99,   100,   101,     0,
     103,   104,   105,     0,     0,     0,     0,     0,     0,   110,
     111,     0,     0,     0,     0,   112,   113,   114,   115,   498,
     117,   118,   499,     0,     0,     0,     0,     0,     0,     0,
     500,   501,   125,     0,     0,     0,   126,     0,   127,   502,
       0,     0,     0,   131,     0,   132,     0,   133,   134,   135,
     136,   503,   138,   139,   140,   141,   142,   143,     0,     0,
     144,   145,     0,     0,   390,   148,   149,   150,   151,   152,
     153,   154,   155,   504,   531,   505,   159,   506,   507,   162,
     163,   164,   165,   166,   167,   508,   169,   509,   510,   511,
     512,   174,   175,   513,   514,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,     0,   191,
     192,   193,     0,   194,   195,   196,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     552,     0,     0,     0,     0,     0,     0,     0,     6,     7,
       0,     0,   763,     0,     0,     0,   387,   388,     0,    12,
      13,    14,   523,    16,    17,    18,   476,   524,   525,    22,
     478,   479,   480,   389,    27,   481,    29,    30,     0,    31,
      32,    33,    34,   526,    36,   527,   528,    39,    40,    41,
      42,   483,     0,    44,   529,    46,   485,   486,    49,   487,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,   488,   489,    66,     0,    67,    68,    69,
     530,     0,    72,    73,    74,     0,     0,   491,    76,     0,
       0,     0,     0,    78,   492,    80,   493,   494,    83,    84,
       0,     0,     0,     0,     0,     0,     0,     0,    89,    90,
      91,    92,     0,    93,     0,     0,     0,   495,    95,    96,
     496,   497,     0,     0,     0,     0,     0,     0,    99,   100,
     101,     0,   103,   104,   105,     0,     0,     0,     0,     0,
       0,   110,   111,     0,     0,     0,     0,   112,   113,   114,
     115,   498,   117,   118,   499,     0,     0,     0,     0,     0,
       0,     0,   500,   501,   125,     0,     0,     0,   126,   764,
     127,   502,     0,     0,     0,     0,     0,   132,     0,   133,
     134,   135,   136,   503,   138,   139,   140,   141,   142,   143,
       0,     0,   144,   145,     0,     0,   390,   148,   149,   150,
     151,   152,   153,   154,   155,   504,   531,   505,   159,   506,
     507,   162,   163,   164,   165,   166,   167,   508,   169,   509,
     510,   511,   512,   174,   175,   513,   514,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
       0,   191,   192,   193,     0,   194,   195,   196,   197,   198,
     199,     0,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   552,     0,     0,     0,     0,     0,     0,     0,
       6,     7,     0,     0,   474,     0,     0,     0,   387,   388,
       0,    12,    13,    14,   523,    16,    17,    18,   476,   524,
     525,    22,   478,   479,   480,   389,    27,   481,    29,    30,
       0,    31,    32,    33,    34,   526,    36,   527,   528,    39,
      40,    41,    42,   483,     0,    44,   529,    46,   485,   486,
      49,   487,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,   488,   489,    66,     0,    67,
      68,    69,   530,     0,    72,    73,    74,     0,     0,   491,
      76,     0,     0,     0,     0,    78,   492,    80,   493,   494,
      83,    84,     0,     0,     0,     0,     0,     0,     0,     0,
      89,    90,    91,    92,     0,    93,     0,     0,     0,   495,
      95,    96,   496,   497,     0,     0,     0,     0,     0,     0,
      99,   100,   101,     0,   103,   104,   105,     0,     0,     0,
       0,     0,     0,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   498,   117,   118,   499,     0,     0,     0,
       0,     0,     0,     0,   500,   501,   125,     0,     0,     0,
     126,     0,   127,   502,     0,     0,     0,     0,     0,   132,
       0,   133,   134,   135,   136,   503,   138,   139,   140,   141,
     142,   143,     0,     0,   144,   145,     0,     0,   390,   148,
     149,   150,   151,   152,   153,   154,   155,   504,   531,   505,
     159,   506,   507,   162,   163,   164,   165,   166,   167,   508,
     169,   509,   510,   511,   512,   174,   175,   513,   514,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,     0,   191,   192,   193,     0,   194,   195,   196,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   555,   556,     0,     0,     0,     0,
       6,     7,     0,     0,   474,     0,     0,     0,   387,   388,
       0,    12,    13,    14,   523,    16,    17,    18,   476,   524,
     525,    22,   478,   479,   480,   389,    27,   481,    29,    30,
       0,    31,    32,    33,    34,   526,    36,   527,   528,    39,
      40,    41,    42,   483,     0,    44,   529,    46,   485,   486,
      49,   487,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,   488,   489,    66,     0,    67,
      68,    69,   530,     0,    72,    73,    74,     0,     0,   491,
      76,     0,     0,     0,     0,    78,   492,    80,   493,   494,
      83,    84,     0,     0,     0,     0,     0,     0,     0,     0,
      89,    90,    91,    92,     0,    93,     0,     0,     0,   495,
      95,    96,   496,   497,     0,     0,     0,     0,     0,     0,
      99,   100,   101,     0,   103,   104,   105,     0,     0,     0,
       0,     0,     0,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   498,   117,   118,   499,     0,     0,     0,
       0,     0,     0,     0,   500,   501,   125,     0,     0,     0,
     126,     0,   127,   502,     0,     0,     0,     0,     0,   132,
       0,   133,   134,   135,   136,   503,   138,   139,   140,   141,
     142,   143,     0,     0,   144,   145,     0,     0,   390,   148,
     149,   150,   151,   152,   153,   154,   155,   504,   531,   505,
     159,   506,   507,   162,   163,   164,   165,   166,   167,   508,
     169,   509,   510,   511,   512,   174,   175,   513,   514,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,     0,   191,   192,   193,     0,   194,   195,   196,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,     6,     7,     0,     0,   474,     0,
       0,     0,   387,   388,     0,    12,    13,    14,   475,    16,
      17,    18,   476,    20,   477,    22,   478,  1094,   480,   389,
      27,   481,    29,    30,     0,    31,    32,    33,    34,   482,
      36,    37,    38,    39,    40,    41,    42,   483,     0,    44,
     484,    46,   485,   486,    49,   487,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,   488,
     489,    66,     0,    67,    68,    69,   490,     0,    72,    73,
      74,     0,     0,   491,    76,     0,     0,     0,     0,    78,
     492,    80,   493,   494,    83,    84,     0,     0,     0,     0,
       0,     0,     0,     0,    89,    90,    91,    92,     0,    93,
       0,     0,     0,   495,    95,    96,   496,   497,     0,     0,
       0,     0,     0,     0,    99,   100,   101,     0,   103,   104,
    1095,     0,     0,     0,  1096,     0,     0,   110,   111,     0,
       0,     0,     0,   112,   113,   114,   115,   498,   117,   118,
     499,     0,     0,     0,     0,     0,     0,     0,   500,   501,
     125,     0,     0,     0,   126,  1500,   127,   502,     0,     0,
       0,  1501,     0,   132,     0,   133,   134,   135,   136,   503,
     138,   139,   140,   141,   142,   143,     0,     0,  1097,   145,
       0,     0,   390,   148,   149,   150,   151,   152,   153,   154,
     155,   504,   157,   505,   159,   506,   507,   162,   163,   164,
     165,   166,   167,   508,   169,   509,   510,   511,   512,   174,
     175,   513,   514,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,     0,   191,   192,   193,
       0,   194,   195,   196,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,     6,     7,
       0,     0,   474,     0,     0,     0,   387,   388,     0,    12,
      13,    14,   523,    16,    17,    18,   476,   524,   525,    22,
     478,   479,   480,   389,    27,   481,    29,    30,     0,    31,
      32,    33,    34,   526,    36,   527,   528,    39,    40,    41,
      42,   483,     0,    44,   529,    46,   485,   486,    49,   487,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,   488,   489,    66,     0,    67,    68,    69,
     530,     0,    72,    73,    74,     0,     0,   491,    76,     0,
       0,     0,     0,    78,   492,    80,   493,   494,    83,    84,
       0,     0,     0,     0,     0,     0,     0,     0,    89,    90,
      91,    92,     0,    93,     0,     0,     0,   495,    95,    96,
     496,   497,     0,     0,     0,     0,     0,     0,    99,   100,
     101,     0,   103,   104,   105,     0,     0,     0,     0,     0,
       0,   110,   111,     0,     0,     0,     0,   112,   113,   114,
     115,   498,   117,   118,   499,     0,     0,     0,     0,     0,
       0,     0,   500,   501,   125,     0,     0,     0,   126,   734,
     127,   502,     0,     0,     0,   735,     0,   132,     0,   133,
     134,   135,   136,   503,   138,   139,   140,   141,   142,   143,
       0,     0,   144,   145,     0,     0,   390,   148,   149,   150,
     151,   152,   153,   154,   155,   504,   531,   505,   159,   506,
     507,   162,   163,   164,   165,   166,   167,   508,   169,   509,
     510,   511,   512,   174,   175,   513,   514,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
       0,   191,   192,   193,     0,   194,   195,   196,   197,   198,
     199,     0,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,     6,     7,     0,     0,   474,     0,     0,     0,
     387,   388,     0,    12,    13,    14,   523,    16,    17,    18,
     476,   524,   525,    22,   478,   479,   480,   389,    27,   481,
      29,    30,     0,    31,    32,    33,    34,   526,    36,   527,
     528,    39,    40,    41,    42,   483,     0,    44,   529,    46,
     485,   486,    49,   487,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,   488,   489,    66,
       0,    67,    68,    69,   530,     0,    72,    73,    74,     0,
       0,   491,    76,     0,     0,     0,     0,    78,   492,    80,
     493,   494,    83,    84,     0,     0,     0,     0,     0,     0,
       0,     0,    89,    90,    91,    92,     0,    93,     0,     0,
       0,   495,    95,    96,   496,   497,     0,     0,     0,     0,
       0,     0,    99,   100,   101,     0,   103,   104,   105,     0,
       0,     0,     0,     0,     0,   110,   111,     0,     0,     0,
       0,   112,   113,   114,   115,   498,   117,   118,   499,     0,
       0,     0,     0,     0,     0,     0,   500,   501,   125,     0,
       0,     0,   126,   781,   127,   502,     0,     0,     0,   782,
       0,   132,     0,   133,   134,   135,   136,   503,   138,   139,
     140,   141,   142,   143,     0,     0,   144,   145,     0,     0,
     390,   148,   149,   150,   151,   152,   153,   154,   155,   504,
     531,   505,   159,   506,   507,   162,   163,   164,   165,   166,
     167,   508,   169,   509,   510,   511,   512,   174,   175,   513,
     514,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,     0,   191,   192,   193,     0,   194,
     195,   196,   197,   198,   199,     0,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,     6,     7,     0,     0,
     474,     0,     0,     0,   387,   388,     0,    12,    13,    14,
     475,    16,    17,    18,   476,    20,   477,    22,   478,  1094,
     480,   389,    27,   481,    29,    30,     0,    31,    32,    33,
      34,   482,    36,    37,    38,    39,    40,    41,    42,   483,
       0,    44,   484,    46,   485,   486,    49,   487,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,   488,   489,    66,     0,    67,    68,    69,   490,     0,
      72,    73,    74,     0,     0,   491,    76,     0,     0,     0,
       0,    78,   492,    80,   493,   494,    83,    84,  1423,     0,
       0,     0,     0,     0,     0,     0,    89,    90,    91,    92,
       0,    93,     0,     0,     0,   495,    95,    96,   496,   497,
       0,     0,     0,     0,     0,     0,    99,   100,   101,     0,
     103,   104,  1095,     0,     0,     0,  1096,     0,     0,   110,
     111,     0,     0,     0,     0,   112,   113,   114,   115,   498,
     117,   118,   499,     0,     0,     0,     0,     0,     0,     0,
     500,   501,   125,     0,     0,     0,   126,     0,   127,   502,
       0,     0,     0,     0,     0,   132,     0,   133,   134,   135,
     136,   503,   138,   139,   140,   141,   142,   143,     0,     0,
    1097,   145,     0,     0,   390,   148,   149,   150,   151,   152,
     153,   154,   155,   504,   157,   505,   159,   506,   507,   162,
     163,   164,   165,   166,   167,   508,   169,   509,   510,   511,
     512,   174,   175,   513,   514,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,     0,   191,
     192,   193,     0,   194,   195,   196,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
       6,     7,     0,     0,   474,     0,     0,     0,   387,   388,
       0,    12,    13,    14,   475,    16,    17,    18,   476,    20,
     477,    22,   478,  1094,   480,   389,    27,   481,    29,    30,
       0,    31,    32,    33,    34,   482,    36,    37,    38,    39,
      40,    41,    42,   483,     0,    44,   484,    46,   485,   486,
      49,   487,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,   488,   489,    66,     0,    67,
      68,    69,   490,     0,    72,    73,    74,     0,     0,   491,
      76,     0,     0,     0,     0,    78,   492,    80,   493,   494,
      83,    84,  1554,     0,     0,     0,     0,     0,     0,     0,
      89,    90,    91,    92,     0,    93,     0,     0,     0,   495,
      95,    96,   496,   497,     0,     0,     0,     0,     0,     0,
      99,   100,   101,     0,   103,   104,  1095,     0,     0,     0,
    1096,     0,     0,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   498,   117,   118,   499,     0,     0,     0,
       0,     0,     0,     0,   500,   501,   125,     0,     0,     0,
     126,     0,   127,   502,     0,     0,     0,     0,     0,   132,
       0,   133,   134,   135,   136,   503,   138,   139,   140,   141,
     142,   143,     0,     0,  1097,   145,     0,     0,   390,   148,
     149,   150,   151,   152,   153,   154,   155,   504,   157,   505,
     159,   506,   507,   162,   163,   164,   165,   166,   167,   508,
     169,   509,   510,   511,   512,   174,   175,   513,   514,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,     0,   191,   192,   193,     0,   194,   195,   196,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,     6,     7,     0,     0,   474,     0,
       0,     0,   387,   388,     0,    12,    13,    14,   475,    16,
      17,    18,   476,    20,   477,    22,   478,  1094,   480,   389,
      27,   481,    29,    30,     0,    31,    32,    33,    34,   482,
      36,    37,    38,    39,    40,    41,    42,   483,     0,    44,
     484,    46,   485,   486,    49,   487,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,   488,
     489,    66,     0,    67,    68,    69,   490,     0,    72,    73,
      74,     0,     0,   491,    76,     0,     0,     0,     0,    78,
     492,    80,   493,   494,    83,    84,  1558,     0,     0,     0,
       0,     0,     0,     0,    89,    90,    91,    92,     0,    93,
       0,     0,     0,   495,    95,    96,   496,   497,     0,     0,
       0,     0,     0,     0,    99,   100,   101,     0,   103,   104,
    1095,     0,     0,     0,  1096,     0,     0,   110,   111,     0,
       0,     0,     0,   112,   113,   114,   115,   498,   117,   118,
     499,     0,     0,     0,     0,     0,     0,     0,   500,   501,
     125,     0,     0,     0,   126,     0,   127,   502,     0,     0,
       0,     0,     0,   132,     0,   133,   134,   135,   136,   503,
     138,   139,   140,   141,   142,   143,     0,     0,  1097,   145,
       0,     0,   390,   148,   149,   150,   151,   152,   153,   154,
     155,   504,   157,   505,   159,   506,   507,   162,   163,   164,
     165,   166,   167,   508,   169,   509,   510,   511,   512,   174,
     175,   513,   514,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,     0,   191,   192,   193,
       0,   194,   195,   196,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,     6,     7,
       0,     0,   474,     0,     0,     0,   387,   388,     0,    12,
      13,    14,   475,    16,    17,    18,   476,    20,   477,    22,
     478,  1094,   480,   389,    27,   481,    29,    30,     0,    31,
      32,    33,    34,   482,    36,    37,    38,    39,    40,    41,
      42,   483,     0,    44,   484,    46,   485,   486,    49,   487,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,   488,   489,    66,     0,    67,    68,    69,
     490,     0,    72,    73,    74,     0,     0,   491,    76,     0,
       0,     0,     0,    78,   492,    80,   493,   494,    83,    84,
       0,     0,     0,     0,     0,     0,     0,     0,    89,    90,
      91,    92,     0,    93,     0,     0,     0,   495,    95,    96,
     496,   497,     0,     0,     0,     0,     0,     0,    99,   100,
     101,     0,   103,   104,  1095,     0,     0,     0,  1096,     0,
       0,   110,   111,     0,     0,     0,     0,   112,   113,   114,
     115,   498,   117,   118,   499,     0,     0,     0,     0,     0,
       0,     0,   500,   501,   125,     0,     0,     0,   126,     0,
     127,   502,     0,     0,     0,     0,     0,   132,     0,   133,
     134,   135,   136,   503,   138,   139,   140,   141,   142,   143,
       0,     0,  1097,   145,     0,     0,   390,   148,   149,   150,
     151,   152,   153,   154,   155,   504,   157,   505,   159,   506,
     507,   162,   163,   164,   165,   166,   167,   508,   169,   509,
     510,   511,   512,   174,   175,   513,   514,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
       0,   191,   192,   193,     0,   194,   195,   196,   197,   198,
     199,     0,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,     6,     7,     0,     0,   474,     0,     0,     0,
     387,   388,     0,    12,    13,    14,   475,    16,    17,    18,
     476,    20,   477,    22,   478,  1094,   480,   389,    27,   481,
      29,    30,     0,    31,    32,    33,    34,   482,    36,    37,
      38,    39,    40,    41,    42,   483,     0,    44,   484,    46,
     485,   486,    49,   487,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,   488,   489,    66,
       0,    67,    68,    69,   490,     0,    72,    73,    74,     0,
       0,   491,    76,     0,     0,     0,     0,    78,   492,    80,
     493,   494,    83,    84,     0,     0,     0,     0,     0,     0,
       0,     0,    89,    90,    91,    92,     0,    93,     0,     0,
       0,   495,    95,    96,   496,   497,     0,     0,     0,     0,
       0,     0,    99,   100,   101,     0,   103,   104,  1095,     0,
       0,     0,  1096,     0,     0,   110,   111,     0,     0,     0,
       0,   112,   113,   114,   115,   498,   117,   118,   499,     0,
       0,     0,     0,     0,     0,     0,   500,   501,   125,     0,
       0,     0,   126,     0,   127,   502,     0,     0,     0,     0,
       0,   132,     0,   133,   134,   135,   136,   503,   138,   139,
     140,   141,   142,   143,     0,     0,   144,   145,     0,     0,
     390,   148,   149,   150,   151,   152,   153,   154,   155,   504,
     157,   505,   159,   506,   507,   162,   163,   164,   165,   166,
     167,   508,   169,   509,   510,   511,   512,   174,   175,   513,
     514,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,     0,   191,   192,   193,     0,   194,
     195,   196,   197,   198,   199,     0,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,     6,     7,     0,     0,
     474,     0,     0,     0,   387,   388,     0,    12,    13,    14,
     523,    16,    17,    18,   476,   524,   525,    22,   478,   479,
     480,   389,    27,   481,    29,    30,     0,    31,    32,    33,
      34,   526,    36,   527,   528,    39,    40,    41,    42,   483,
       0,    44,   529,    46,   485,   486,    49,   487,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,   488,   489,    66,     0,    67,    68,    69,   530,     0,
      72,    73,    74,     0,     0,   491,    76,     0,     0,     0,
       0,    78,   492,    80,   493,   494,    83,    84,     0,     0,
       0,     0,     0,     0,     0,     0,    89,    90,    91,    92,
       0,    93,     0,     0,     0,   495,    95,    96,   496,   497,
       0,     0,     0,     0,     0,     0,    99,   100,   101,     0,
     103,   104,   105,     0,     0,     0,     0,     0,     0,   110,
     111,     0,     0,     0,     0,   112,   113,   114,   115,   498,
     117,   118,   499,     0,     0,     0,     0,     0,     0,     0,
     500,   501,   125,     0,     0,     0,   126,     0,   127,   502,
       0,     0,     0,     0,     0,   132,     0,   133,   134,   135,
     136,   503,   138,   139,   140,   141,   142,   143,     0,     0,
     144,   145,     0,     0,   390,   148,   149,   150,   151,   152,
     153,   154,   155,   504,   531,   505,   159,   506,   507,   162,
     163,   164,   165,   166,   167,   508,   169,   509,   510,   511,
     512,   174,   175,   513,   514,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,     0,   191,
     192,   193,     0,   194,   195,   196,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
       6,     7,     0,     0,   474,     0,     0,     0,   387,   388,
       0,    12,    13,    14,     0,    16,    17,    18,   476,     0,
       0,    22,   478,   479,     0,   389,    27,   481,    29,    30,
       0,    31,    32,    33,    34,     0,    36,     0,     0,    39,
      40,    41,    42,   483,     0,    44,     0,    46,     0,     0,
      49,   487,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,   488,   489,    66,     0,    67,
      68,    69,     0,     0,    72,    73,    74,     0,     0,   491,
      76,     0,     0,     0,     0,    78,   492,    80,   493,   494,
      83,    84,     0,     0,     0,     0,     0,     0,     0,     0,
      89,    90,    91,    92,     0,    93,     0,     0,     0,   495,
      95,    96,   496,   497,     0,     0,     0,     0,     0,     0,
      99,   100,   101,     0,   103,   104,     0,     0,     0,     0,
       0,     0,     0,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   498,   117,   118,   499,     0,     0,     0,
       0,     0,     0,     0,   500,   501,   125,     0,     0,     0,
     126,     0,   127,   502,     0,     0,     0,     0,     0,   132,
       0,   133,   134,   135,   136,   503,   138,   139,   140,   141,
     142,   143,     0,     0,     0,   145,     0,     0,   390,   148,
     149,   150,   151,   152,   153,   154,   155,   504,     0,   505,
     159,   506,   507,   162,   163,   164,   165,   166,   167,   508,
     169,   509,   510,   511,   512,   174,   175,     0,   514,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,     0,   191,   192,   193,     0,   194,   195,   196,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,   130,   177,     3,     4,     5,     0,   298,   642,     3,
       4,     5,   397,     3,     4,     5,   877,   878,     3,     4,
       5,   797,   878,   758,   325,    71,   594,   595,   246,    10,
     247,   741,  1163,   396,   993,   770,   956,   865,   278,    85,
     643,   644,   645,   646,   269,   262,  1303,  1304,  1009,   784,
    1246,  1230,   826,   914,   741,  1031,    71,   592,   593,  1080,
     409,   115,   108,    34,   449,   450,    34,   898,   575,   687,
      54,    27,     8,     1,   120,     1,   122,   115,    28,  1518,
     914,   592,   593,   594,   595,   434,     1,   948,  1259,   596,
       3,     4,     5,   600,     1,   622,  1336,   624,   625,     1,
     627,    43,   629,     1,    92,   144,   106,     1,   457,   970,
     637,   638,   106,   104,   970,    97,    53,   139,    55,    61,
      25,   106,   983,    94,    92,    97,    94,   983,   104,    92,
      91,    97,    25,    51,    35,    36,   115,    38,    39,   114,
     104,    27,   144,    92,   104,    27,   104,   127,    94,    25,
      94,   107,   119,   393,   107,    56,    37,   104,   115,   133,
      97,    42,    43,    92,   133,   121,   155,   221,   143,   128,
     115,   103,   150,   144,    31,   153,   144,    58,   147,    60,
      61,   156,   134,   150,   173,   920,   153,   179,    69,   170,
     146,    48,   124,   106,   150,   144,   187,   153,   150,   328,
     192,   183,     5,   428,   109,   184,     9,  1464,   126,   110,
     139,   183,   153,   193,    95,   190,   109,   183,   174,   180,
     166,   185,   182,   197,   110,  1664,   183,   185,   187,   213,
      92,   270,   270,   109,   104,  1096,   172,   184,   183,  1159,
     240,   976,   184,   243,  1375,   233,   240,   982,   270,   243,
     304,  1027,  1080,  1081,  1213,   231,   157,   548,  1437,   187,
     210,   187,  1096,   831,   832,   975,  1227,   251,   270,  1440,
     233,   157,   187,    94,  1250,   157,    43,  1517,   278,    46,
     187,   104,   900,  1259,   278,   187,   973,   333,   975,   187,
     336,  1312,  1123,   187,   829,   830,    92,    27,   538,   270,
     256,    94,   270,   249,   250,   104,   252,  1168,   995,   253,
     254,   248,   819,   698,   184,   216,   104,   120,   333,   122,
     104,   336,   671,   269,   261,   278,   263,   130,   104,   104,
     104,   125,   126,    31,   861,   281,   103,   274,   275,   276,
     221,   278,    94,   280,  1205,   166,   104,   150,   104,  1205,
      48,   576,   214,   215,   150,   401,   402,   258,  1615,   405,
     153,   184,   104,   409,   155,   104,   153,   229,  1229,   415,
     610,   756,   589,  1229,   592,   593,   422,   107,   104,   104,
       5,  1577,   173,   104,     9,   184,    92,   127,   434,  1520,
     104,   121,   144,   393,   440,   118,   184,   443,   165,   393,
     184,   150,   104,   752,   153,   451,   755,   181,   184,   184,
    1667,   457,   458,   459,   460,   221,   146,   223,    94,   465,
     150,   217,   218,   153,    94,   181,   184,   473,   249,   250,
      25,   252,  1167,    92,   110,   435,   153,   437,   259,     9,
     393,   435,   184,   437,   174,   184,    27,   437,   269,   104,
     435,    46,   437,   193,  1374,   104,    26,   206,   184,   184,
     281,   461,   104,   184,  1440,   150,   466,   461,   153,  1179,
     184,  1650,   466,   519,   144,   266,   461,   153,    73,   181,
     139,   466,   273,  1344,  1312,   725,   439,   533,  1344,  1620,
     104,   104,   283,  1321,   447,   120,   542,   122,  1066,  1067,
    1068,  1188,   865,   456,  1332,   130,   104,   260,   214,   215,
     463,   464,  1286,     9,   109,   166,  1290,    43,   271,   472,
      46,   206,   435,   229,   437,   150,   107,   104,   574,   184,
      26,   894,   661,   662,  1665,   184,   921,   922,   538,   157,
     121,   926,   184,   543,   538,     9,    10,   198,   461,   543,
     120,    77,   122,   466,    71,  1066,  1067,  1068,   543,     9,
      10,   131,   104,   104,  1425,   146,   104,  1428,    85,  1425,
     184,   184,  1428,   958,     9,    10,   104,   103,   911,    92,
     150,   581,  1541,   104,   824,   538,   184,   581,   150,   104,
     923,   108,   592,   593,   594,   595,   104,   550,   592,   593,
     594,   595,   104,   120,   989,   122,   587,   184,   993,   562,
     610,   829,   141,   213,   104,  1576,   610,  1748,   835,  1750,
     104,     9,    10,   150,   120,   671,   122,   580,   581,   260,
     543,   144,   197,    94,   153,   131,   100,   155,  1769,   165,
     271,   206,   184,   184,   173,   691,   184,   174,   694,   110,
     100,   251,    65,   181,   150,   173,   120,    70,   122,    52,
     181,   190,  1438,  1491,    57,   100,   181,  1443,   581,   715,
     120,    40,   122,   181,   720,   721,    45,   195,   145,   181,
    1390,    50,    75,    40,   150,   120,   150,   122,    45,  1323,
     154,   181,   153,    50,   153,   162,   742,   181,   744,    68,
     150,    94,   115,   145,   154,   658,   752,   171,   174,   755,
     663,    68,   100,   759,  1726,   150,   153,  1080,  1081,   154,
     162,   171,   115,    52,  1292,   725,    92,   191,    57,   155,
     163,   725,   120,    40,   122,   115,   171,  1598,    45,  1600,
    1752,   191,  1598,    50,  1600,   209,   179,   173,   748,   150,
     796,  1763,   153,    92,   748,   964,   191,   966,   748,   209,
     134,    68,   150,   748,   103,    94,   154,  1058,   134,   195,
    1631,    94,   725,   139,   209,  1631,   150,    23,   778,   779,
     826,  1082,   179,   171,   778,   779,    32,   110,  1564,   296,
     153,    97,  1568,   778,   779,   192,   165,    97,   305,   168,
    1661,   221,   848,   191,   110,  1661,   226,  1016,   165,  1018,
     110,   168,  1052,    59,   183,  1676,   333,  1678,   265,   336,
    1676,   209,  1678,  1208,   824,   272,   183,   221,  1213,   223,
     824,   877,   878,   879,   880,   748,   789,   790,   791,   208,
     793,   153,  1642,  1643,    93,   266,   244,   245,  1482,  1483,
      97,   208,   273,   150,   103,   166,   153,   119,   165,   840,
      97,   168,   283,   110,   113,   778,   779,   119,   914,   267,
    1646,    97,  1475,   110,   134,   124,   183,    97,   119,   139,
    1615,  1056,   928,  1683,   110,   402,  1061,   198,   405,  1689,
     110,   134,   409,   274,   275,   276,   139,    52,   415,   280,
     664,   208,    57,   667,   115,   422,   670,   335,   150,   955,
     119,   153,   340,   119,  1299,   226,   115,   434,   964,   151,
     966,   153,   119,   440,   970,   119,   443,   217,   218,   219,
     228,   150,   230,   228,   451,   230,   119,   983,   188,   189,
     457,   458,   459,   460,   297,   298,   297,   298,   465,  1312,
     288,   289,  1586,  1587,   125,   126,   473,   119,  1321,   640,
     641,   647,   648,   879,   880,   649,   650,  1207,   119,  1332,
    1016,   119,  1018,   284,   285,   286,   287,   288,   150,   290,
     291,   292,   293,   294,  1508,  1509,   153,   212,   299,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,   221,
     115,   239,   519,   238,   238,   150,   153,    25,     0,   104,
     187,  1011,   164,    90,    49,   246,   533,  1011,   196,    98,
     151,    99,  1407,  1657,   118,   542,  1011,   153,    46,  1075,
     142,   181,   181,    27,    46,   181,   149,    55,   243,   115,
     295,   295,   290,   301,   184,  1285,   115,   150,   281,     1,
    1096,   281,  1052,   115,   139,    73,   104,   574,  1052,    77,
     184,   153,   150,   150,   139,   181,  1066,  1067,  1068,   153,
     129,   153,  1066,  1067,  1068,    33,   150,    16,   137,   138,
     153,   140,   153,  1468,  1065,   153,   153,   153,   210,   148,
     108,   109,   110,   152,    27,   154,   187,   227,  1011,   242,
     159,   184,     3,   167,   115,   165,   187,    69,   227,   167,
      92,    92,    92,   146,   104,   104,    27,   176,   157,   157,
     124,   129,   243,   296,   139,   181,  1079,   115,  1491,   129,
     181,   184,  1178,   104,   184,  1181,    92,    94,    43,    94,
     199,   200,   201,   202,   203,   204,    92,   184,   166,   150,
    1196,   181,   184,   184,   671,   184,  1541,   181,   221,  1205,
     139,   233,   187,    31,   167,   115,   129,   139,    92,    27,
     115,   223,  1172,  1219,   283,   150,   296,   694,  1172,  1419,
     198,   124,  1172,  1229,   115,   144,   251,  1172,   115,    92,
     181,   129,   194,   157,   129,    94,   150,   115,   715,    97,
     144,    97,   150,   720,   721,   181,    33,  1207,   226,   139,
     187,  1257,   181,  1207,    27,   115,   153,   153,  1218,   153,
     242,   150,    77,   104,  1218,   742,   104,   744,  1218,   255,
     257,  1277,   153,  1218,   153,   752,   282,  1237,   755,   153,
    1286,   264,   759,  1237,  1290,    27,   141,  1237,    27,   283,
      27,   141,  1237,   223,   303,   233,  1256,   223,   223,  1172,
     144,   187,  1256,   284,   184,   124,   284,   285,   286,   287,
     288,  1256,   290,   291,   292,   293,   294,   184,   184,   796,
     184,   299,   300,   144,  1284,  1285,   115,   144,    75,   115,
    1284,  1285,   104,   139,   181,   184,   184,   194,  1344,  1539,
      97,   129,     7,   183,   187,  1218,   229,   229,   233,   826,
    1550,  1551,   229,  1553,   229,   115,   283,   103,   103,   184,
    1560,   144,    76,    27,  1237,  1371,   279,    27,  1281,  1282,
    1283,   848,   184,   184,   247,   247,   184,   104,   254,   181,
     268,   144,   167,  1256,    94,   144,   181,   123,   123,   183,
     183,  1397,  1398,   183,   150,    92,    27,   167,    94,   183,
     877,   878,   879,   880,   181,   181,   181,   277,    52,    92,
     184,  1284,   144,   184,   183,   284,   183,  1423,    92,  1425,
     115,    27,  1428,   262,   104,   193,   104,   115,   194,   221,
     115,    92,   183,  1439,    92,   193,   115,   914,  1444,  1639,
     193,   221,   115,   183,    91,   183,   180,   115,   302,  1649,
     193,   928,   115,  1459,   183,   183,   302,   150,   115,  1419,
     290,   183,   115,   115,   184,  1419,   302,   184,   303,   303,
     195,   284,   221,   115,   303,   240,   697,  1677,   955,   243,
     915,   243,   428,  1126,   984,   246,  1168,   964,   432,   966,
    1620,  1665,   827,   970,  1178,  1308,   981,   761,  1306,  1197,
    1400,  1071,  1303,   533,  1219,  1224,   983,  1227,   621,  1232,
     673,  1711,   321,  1250,  1689,   797,   620,  1683,   880,  1654,
    1160,   966,  1125,  1287,  1286,  1277,  1321,   438,  1332,   438,
    1491,  1081,  1325,  1488,  1090,  1735,   947,  1363,  1148,  1016,
    1511,  1018,  1322,    -1,  1744,    -1,    -1,    -1,  1554,    -1,
    1556,    -1,  1558,    -1,    -1,    -1,    -1,    -1,    -1,  1565,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1539,
      -1,    -1,    -1,    -1,    -1,  1539,    -1,    -1,    -1,    -1,
    1550,  1551,  1598,  1553,  1600,    -1,  1550,  1551,  1075,  1553,
    1560,    -1,    -1,    -1,    -1,  1740,  1560,    -1,    -1,    -1,
    1616,    -1,    -1,  1619,    -1,    -1,    -1,    -1,    -1,  1096,
      -1,    -1,    -1,  1758,    -1,  1631,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1641,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1652,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1661,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1669,    -1,  1578,    -1,    -1,  1674,    -1,
    1676,    -1,  1678,    -1,    -1,    -1,    -1,    -1,    -1,  1639,
      -1,    -1,    -1,  1596,    -1,  1639,    -1,    -1,    -1,  1649,
      -1,    -1,  1698,    -1,    -1,  1649,    -1,    -1,    -1,    -1,
      -1,  1178,  1708,    -1,  1181,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1677,  1724,  1196,
      -1,    -1,    -1,  1677,    -1,  1731,    -1,    -1,  1205,    -1,
      -1,  1737,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1746,    -1,  1219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1756,  1711,  1229,    -1,    -1,    -1,  1762,  1711,    -1,    -1,
      -1,  1767,    -1,    -1,    -1,    -1,   566,   567,    -1,   569,
     570,   571,   572,    -1,    -1,  1735,    -1,    -1,    -1,   579,
    1257,  1735,    -1,    -1,  1744,    -1,    -1,    -1,    -1,    -1,
    1744,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,
    1277,    -1,   602,    35,    36,    -1,    38,    39,    -1,  1286,
     610,   611,    -1,  1290,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1344,    -1,   669,
      -1,    -1,    -1,   673,    -1,    -1,   108,   109,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1371,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   717,    -1,    -1,
    1397,  1398,    -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1423,    -1,  1425,    -1,
      -1,  1428,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     760,    -1,  1439,    -1,    -1,    -1,   198,  1444,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1459,    -1,   216,   785,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   226,   795,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     850,    -1,   284,   285,   286,   287,   288,    -1,   290,   291,
     292,   293,   294,    -1,    -1,    -1,    -1,   299,   300,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1554,    -1,  1556,
      -1,  1558,    -1,    -1,    -1,    -1,    -1,    -1,  1565,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   916,    -1,    -1,    -1,
      -1,  1598,    -1,  1600,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1616,
      -1,    -1,  1619,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   953,  1631,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1641,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   972,    -1,    -1,  1652,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1661,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1669,    -1,   994,    -1,    -1,  1674,    -1,  1676,
      -1,  1678,    -1,    -1,    -1,  1005,  1006,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1020,  1698,    -1,  1023,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1708,    -1,    -1,    -1,    -1,    -1,  1037,  1038,  1039,
      -1,  1041,  1042,  1043,  1044,  1045,  1046,  1724,  1048,  1049,
      -1,    -1,    -1,    -1,  1731,    -1,    -1,    -1,    -1,    -1,
    1737,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1746,
      -1,  1071,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1756,
      -1,    -1,    -1,    -1,    -1,  1762,    -1,    -1,    -1,    -1,
    1767,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1183,    -1,  1185,    -1,  1187,    -1,    -1,
    1190,    -1,    -1,    -1,    -1,  1195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1207,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1216,    -1,    -1,    -1,
      -1,    -1,  1222,  1223,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1306,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1384,    -1,    -1,    -1,  1388,    -1,
      -1,    -1,  1392,    -1,  1394,    -1,  1396,    -1,    -1,    -1,
      -1,    -1,  1402,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1410,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1418,  1419,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1436,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1447,  1448,  1449,
    1450,  1451,    -1,  1453,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1527,    -1,  1529,
      -1,    -1,  1532,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1540,    -1,    -1,    -1,    -1,  1545,  1546,    -1,    -1,    -1,
      -1,    -1,    -1,  1553,    -1,    -1,    -1,  1557,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1623,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1635,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1677,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1706,    -1,    -1,    -1,
      -1,  1711,    -1,    -1,    -1,    -1,  1716,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    -1,  1734,    19,    20,    21,    22,    23,
      24,    25,  1742,    27,    -1,    -1,    -1,    31,    32,    -1,
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
     304,   305,   306,   307,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    20,    21,    22,    23,    24,    25,    -1,
      27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    92,    93,    94,    95,    96,
      97,    98,    99,    -1,    -1,   102,   103,    -1,    -1,    -1,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    -1,    -1,    -1,   121,    -1,   123,   124,   125,   126,
      -1,   128,    -1,    -1,    -1,   132,   133,   134,   135,   136,
      -1,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,   146,
     147,   148,   149,   150,    -1,    -1,   153,   154,   155,   156,
     157,    -1,    -1,    -1,    -1,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,   171,    -1,   173,   174,    -1,    -1,
     177,   178,   179,    -1,   181,    -1,   183,    -1,   185,   186,
      -1,   188,   189,   190,    -1,   192,    -1,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,    -1,    -1,
     207,   208,   209,    -1,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,    -1,   256,
     257,   258,    -1,   260,   261,   262,   263,   264,   265,    -1,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    24,    25,    -1,    27,    -1,    -1,    -1,
      31,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      -1,    92,    93,    94,    95,    96,    97,    98,    99,    -1,
      -1,   102,   103,    -1,    -1,    -1,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    -1,    -1,    -1,
     121,    -1,   123,   124,   125,   126,    -1,   128,    -1,    -1,
      -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,    -1,
      -1,    -1,   143,   144,   145,   146,   147,   148,   149,   150,
      -1,    -1,   153,   154,   155,   156,   157,    -1,    -1,    -1,
      -1,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
     171,    -1,   173,   174,    -1,    -1,   177,   178,   179,    -1,
     181,    -1,   183,    -1,   185,   186,    -1,   188,   189,   190,
      -1,   192,    -1,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,    -1,    -1,   207,   208,   209,    -1,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,    -1,   256,   257,   258,    -1,   260,
     261,   262,   263,   264,   265,    -1,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    92,    93,    94,
      95,    96,    97,    98,    99,    -1,    -1,   102,   103,    -1,
      -1,    -1,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,    -1,    -1,    -1,   121,    -1,   123,   124,
     125,   126,    -1,   128,    -1,    -1,    -1,   132,   133,   134,
     135,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,
     145,   146,   147,   148,   149,   150,    -1,    -1,   153,   154,
     155,   156,   157,    -1,    -1,    -1,    -1,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,   171,    -1,   173,   174,
      -1,    -1,   177,   178,   179,    -1,   181,    -1,   183,    -1,
     185,   186,    -1,   188,   189,   190,    -1,   192,    -1,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
      -1,    -1,   207,   208,   209,    -1,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,   256,   257,   258,    -1,   260,   261,   262,   263,   264,
     265,    -1,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    24,    25,    -1,    27,    -1,
      -1,    -1,    31,    32,    -1,    34,    35,    36,    37,    38,
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
     179,    -1,   181,    -1,   183,    -1,   185,   186,    -1,   188,
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
     299,   300,   301,   302,   303,   304,   305,   306,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    24,    25,    -1,    27,    -1,    -1,    -1,    31,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,    -1,    -1,   102,
     103,    -1,    -1,    -1,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,    -1,    -1,   121,    -1,
     123,   124,   125,   126,    -1,   128,    -1,    -1,    -1,   132,
     133,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,
     143,   144,   145,   146,   147,   148,   149,   150,    -1,    -1,
     153,   154,   155,   156,   157,    -1,    -1,    -1,    -1,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,   171,    -1,
     173,   174,    -1,    -1,   177,   178,   179,    -1,    -1,    -1,
     183,    -1,   185,   186,    -1,   188,   189,   190,    -1,   192,
      -1,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,    -1,    -1,   207,   208,   209,    -1,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,    -1,   256,   257,   258,    -1,   260,   261,   262,
     263,   264,   265,    -1,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    20,    21,    22,    23,    24,    -1,    -1,
      27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    92,    93,    94,    95,    96,
      97,    98,    99,    -1,    -1,   102,   103,    -1,    -1,    -1,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    -1,    -1,    -1,   121,    -1,   123,   124,   125,   126,
      -1,   128,    -1,    -1,    -1,   132,   133,   134,   135,   136,
      -1,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,   146,
     147,   148,   149,   150,    -1,    -1,   153,   154,   155,   156,
     157,    -1,    -1,    -1,    -1,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,   171,    -1,   173,   174,    -1,    -1,
     177,   178,   179,    -1,    -1,    -1,   183,   184,   185,   186,
      -1,   188,   189,   190,    -1,   192,    -1,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,    -1,    -1,
     207,   208,   209,    -1,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,    -1,   256,
     257,   258,    -1,   260,   261,   262,   263,   264,   265,    -1,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    24,    25,    -1,    27,    -1,    -1,    -1,
      31,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      -1,    92,    93,    94,    95,    96,    97,    98,    99,    -1,
      -1,   102,   103,    -1,    -1,    -1,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    -1,    -1,    -1,
     121,    -1,   123,   124,   125,   126,    -1,   128,    -1,    -1,
      -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,    -1,
      -1,    -1,   143,   144,   145,   146,   147,   148,   149,   150,
      -1,    -1,   153,   154,   155,   156,   157,    -1,    -1,    -1,
      -1,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
     171,    -1,   173,   174,    -1,    -1,   177,   178,   179,    -1,
      -1,    -1,   183,    -1,   185,   186,    -1,   188,   189,   190,
      -1,   192,    -1,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,    -1,    -1,   207,   208,   209,    -1,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,    -1,   256,   257,   258,    -1,   260,
     261,   262,   263,   264,   265,    -1,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    92,    93,    94,
      95,    96,    97,    98,    99,    -1,    -1,   102,   103,    -1,
      -1,    -1,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,    -1,    -1,    -1,   121,    -1,   123,   124,
     125,   126,    -1,   128,    -1,    -1,    -1,   132,   133,   134,
     135,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,
     145,   146,   147,   148,   149,   150,    -1,    -1,   153,   154,
     155,   156,   157,    -1,    -1,    -1,    -1,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,   171,    -1,   173,   174,
      -1,    -1,   177,   178,   179,    -1,    -1,    -1,   183,    -1,
     185,   186,    -1,   188,   189,   190,    -1,   192,    -1,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
      -1,    -1,   207,   208,   209,    -1,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,   256,   257,   258,    -1,   260,   261,   262,   263,   264,
     265,    -1,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    24,    25,    -1,    27,    -1,
      -1,    -1,    31,    32,    -1,    34,    35,    36,    37,    38,
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
     299,   300,   301,   302,   303,   304,   305,   306,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    24,    25,    -1,    27,    -1,    -1,    -1,    31,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,    -1,    -1,   102,
     103,    -1,    -1,    -1,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,    -1,    -1,   121,    -1,
     123,   124,   125,   126,    -1,   128,    -1,    -1,    -1,   132,
     133,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,
     143,   144,   145,   146,   147,   148,   149,   150,    -1,    -1,
     153,   154,   155,   156,   157,    -1,    -1,    -1,    -1,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,   171,    -1,
     173,   174,    -1,    -1,   177,   178,   179,    -1,    -1,    -1,
     183,    -1,   185,   186,    -1,   188,   189,   190,    -1,   192,
      -1,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,    -1,    -1,   207,   208,   209,    -1,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,    -1,   256,   257,   258,    -1,   260,   261,   262,
     263,   264,   265,    -1,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    20,    21,    22,    23,    24,    -1,    -1,
      27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    92,    93,    94,    95,    96,
      97,    98,    99,    -1,    -1,   102,   103,    -1,    -1,    -1,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    -1,    -1,    -1,   121,    -1,   123,   124,   125,   126,
      -1,   128,    -1,    -1,    -1,   132,   133,   134,   135,   136,
      -1,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,   146,
     147,   148,   149,   150,    -1,    -1,   153,   154,   155,   156,
     157,    -1,    -1,    -1,    -1,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,   171,    -1,   173,   174,    -1,    -1,
     177,   178,   179,    -1,   181,    -1,   183,    -1,   185,   186,
      -1,   188,   189,   190,    -1,   192,    -1,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,    -1,    -1,
     207,   208,   209,    -1,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,    -1,   256,
     257,   258,    -1,   260,   261,   262,   263,   264,   265,    -1,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,
      31,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      -1,    92,    93,    94,    95,    96,    97,    98,    99,    -1,
      -1,   102,   103,    -1,    -1,    -1,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    -1,    -1,    -1,
     121,    -1,   123,   124,   125,   126,    -1,   128,    -1,    -1,
      -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,    -1,
      -1,    -1,   143,   144,   145,   146,   147,   148,   149,   150,
      -1,    -1,   153,   154,   155,   156,   157,    -1,    -1,    -1,
      -1,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
     171,    -1,   173,   174,    -1,    -1,   177,   178,   179,    -1,
      -1,    -1,   183,   184,   185,   186,    -1,   188,   189,   190,
      -1,   192,    -1,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,    -1,    -1,   207,   208,   209,    -1,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,    -1,   256,   257,   258,    -1,   260,
     261,   262,   263,   264,   265,    -1,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,    24,
      -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    92,    93,    94,
      95,    96,    97,    98,    99,    -1,    -1,   102,   103,    -1,
      -1,    -1,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,    -1,    -1,    -1,   121,    -1,   123,   124,
     125,   126,    -1,   128,    -1,    -1,    -1,   132,   133,   134,
     135,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,
     145,   146,   147,   148,   149,   150,    -1,    -1,   153,   154,
     155,   156,   157,    -1,    -1,    -1,    -1,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,   171,    -1,   173,   174,
      -1,    -1,   177,   178,   179,    -1,    -1,    -1,   183,   184,
     185,   186,    -1,   188,   189,   190,    -1,   192,    -1,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
      -1,    -1,   207,   208,   209,    -1,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,   256,   257,   258,    -1,   260,   261,   262,   263,   264,
     265,    -1,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    24,    25,    -1,    27,    -1,
      -1,    -1,    31,    32,    -1,    34,    35,    36,    37,    38,
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
     299,   300,   301,   302,   303,   304,   305,   306,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,    -1,    -1,   102,
     103,    -1,    -1,    -1,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,    -1,    -1,   121,    -1,
     123,   124,   125,   126,    -1,   128,    -1,    -1,    -1,   132,
     133,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,
     143,   144,   145,   146,   147,   148,   149,   150,    -1,    -1,
     153,   154,   155,   156,   157,    -1,    -1,    -1,    -1,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,   171,    -1,
     173,   174,    -1,    -1,   177,   178,   179,    -1,    -1,    -1,
     183,    -1,   185,   186,    -1,   188,   189,   190,    -1,   192,
      -1,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,    -1,    -1,   207,   208,   209,    -1,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,    -1,   256,   257,   258,    -1,   260,   261,   262,
     263,   264,   265,    -1,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    20,    21,    22,    23,    24,    -1,    -1,
      27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    92,    93,    94,    95,    96,
      97,    98,    99,    -1,    -1,   102,   103,    -1,    -1,    -1,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    -1,    -1,    -1,   121,    -1,   123,   124,   125,   126,
      -1,   128,    -1,    -1,    -1,   132,   133,   134,   135,   136,
      -1,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,   146,
     147,   148,   149,   150,    -1,    -1,   153,   154,   155,   156,
     157,    -1,    -1,    -1,    -1,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,   171,    -1,   173,   174,    -1,    -1,
     177,   178,   179,    -1,    -1,    -1,   183,    -1,   185,   186,
      -1,   188,   189,   190,    -1,   192,    -1,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,    -1,    -1,
     207,   208,   209,    -1,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,    -1,   256,
     257,   258,    -1,   260,   261,   262,   263,   264,   265,    -1,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,
      31,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      -1,    92,    93,    94,    95,    96,    97,    98,    99,    -1,
      -1,   102,   103,    -1,    -1,    -1,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    -1,    -1,    -1,
     121,    -1,   123,   124,   125,   126,    -1,   128,    -1,    -1,
      -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,    -1,
      -1,    -1,   143,   144,   145,   146,   147,   148,   149,   150,
      -1,    -1,   153,   154,   155,   156,   157,    -1,    -1,    -1,
      -1,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
     171,    -1,   173,   174,    -1,    -1,   177,   178,   179,    -1,
      -1,    -1,   183,    -1,   185,   186,    -1,   188,   189,   190,
      -1,   192,    -1,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,    -1,    -1,   207,   208,   209,    -1,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,    -1,   256,   257,   258,    -1,   260,
     261,   262,   263,   264,   265,    -1,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,    24,
      -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    92,    93,    94,
      95,    96,    97,    98,    99,    -1,    -1,   102,   103,    -1,
      -1,    -1,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,    -1,    -1,    -1,   121,    -1,   123,   124,
     125,   126,    -1,   128,    -1,    -1,    -1,   132,   133,   134,
     135,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,
     145,   146,   147,   148,   149,   150,    -1,    -1,   153,   154,
      -1,   156,   157,    -1,    -1,    -1,    -1,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,   171,    -1,    -1,    -1,
      -1,    -1,   177,   178,   179,    -1,    -1,    -1,   183,    -1,
     185,   186,    -1,   188,   189,   190,    -1,   192,    -1,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
      -1,    -1,   207,   208,   209,    -1,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,   256,   257,   258,    -1,   260,   261,   262,   263,   264,
     265,    -1,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    24,    -1,    -1,    27,    -1,
      -1,    -1,    31,    32,    -1,    34,    35,    36,    37,    38,
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
     149,   150,    -1,    -1,   153,   154,    -1,   156,   157,    -1,
      -1,    -1,    -1,   162,   163,   164,   165,   166,   167,   168,
     169,    -1,   171,    -1,    -1,    -1,    -1,    -1,   177,   178,
     179,    -1,    -1,    -1,   183,    -1,   185,   186,    -1,    -1,
      -1,   190,    -1,   192,    -1,   194,   195,   196,   197,   198,
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
     299,   300,   301,   302,   303,   304,   305,   306,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,
      23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      93,    94,    95,    -1,    97,    98,    99,    -1,    -1,   102,
     103,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     123,   124,   125,   126,    -1,   128,    -1,    -1,    -1,   132,
     133,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,
     143,   144,   145,    -1,   147,   148,   149,    -1,    -1,    -1,
      -1,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   177,   178,   179,    -1,    -1,    -1,
     183,    -1,   185,   186,    -1,    -1,    -1,   190,    -1,   192,
      -1,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,    -1,    -1,   207,   208,    -1,    -1,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,    -1,   256,   257,   258,    -1,   260,   261,   262,
     263,   264,   265,    -1,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    -1,    -1,    -1,    23,    24,    -1,    -1,
      27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    92,    93,    94,    95,    -1,
      97,    98,    99,    -1,    -1,   102,   103,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,   113,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   123,   124,   125,   126,
      -1,   128,    -1,    -1,    -1,   132,   133,   134,   135,   136,
      -1,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,    -1,
     147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,
     157,    -1,    -1,    -1,    -1,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     177,   178,   179,    -1,    -1,    -1,   183,    -1,   185,   186,
      -1,    -1,    -1,   190,    -1,   192,    -1,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,    -1,    -1,
     207,   208,    -1,    -1,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,    -1,   256,
     257,   258,    -1,   260,   261,   262,   263,   264,   265,    -1,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,
      -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    92,    93,    94,
      95,    -1,    97,    98,    99,    -1,    -1,   102,   103,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,
     125,   126,    -1,   128,    -1,    -1,    -1,   132,   133,   134,
     135,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,
     145,    -1,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   177,   178,   179,    -1,    -1,    -1,   183,   184,
     185,   186,    -1,    -1,    -1,    -1,    -1,   192,    -1,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
      -1,    -1,   207,   208,    -1,    -1,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,   256,   257,   258,    -1,   260,   261,   262,   263,   264,
     265,    -1,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      93,    94,    95,    -1,    97,    98,    99,    -1,    -1,   102,
     103,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     123,   124,   125,   126,    -1,   128,    -1,    -1,    -1,   132,
     133,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,
     143,   144,   145,    -1,   147,   148,   149,    -1,    -1,    -1,
      -1,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   177,   178,   179,    -1,    -1,    -1,
     183,    -1,   185,   186,    -1,    -1,    -1,    -1,    -1,   192,
      -1,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,    -1,    -1,   207,   208,    -1,    -1,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,    -1,   256,   257,   258,    -1,   260,   261,   262,
     263,   264,   265,    -1,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,    17,    18,    -1,    -1,    -1,    -1,
      23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      93,    94,    95,    -1,    97,    98,    99,    -1,    -1,   102,
     103,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     123,   124,   125,   126,    -1,   128,    -1,    -1,    -1,   132,
     133,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,
     143,   144,   145,    -1,   147,   148,   149,    -1,    -1,    -1,
      -1,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   177,   178,   179,    -1,    -1,    -1,
     183,    -1,   185,   186,    -1,    -1,    -1,    -1,    -1,   192,
      -1,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,    -1,    -1,   207,   208,    -1,    -1,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,    -1,   256,   257,   258,    -1,   260,   261,   262,
     263,   264,   265,    -1,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,    23,    24,    -1,    -1,    27,    -1,
      -1,    -1,    31,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    -1,    92,    93,    94,    95,    -1,    97,    98,
      99,    -1,    -1,   102,   103,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,   113,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   123,   124,   125,   126,    -1,   128,
      -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,
      -1,    -1,    -1,    -1,   143,   144,   145,    -1,   147,   148,
     149,    -1,    -1,    -1,   153,    -1,    -1,   156,   157,    -1,
      -1,    -1,    -1,   162,   163,   164,   165,   166,   167,   168,
     169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,   178,
     179,    -1,    -1,    -1,   183,   184,   185,   186,    -1,    -1,
      -1,   190,    -1,   192,    -1,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,    -1,    -1,   207,   208,
      -1,    -1,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,   256,   257,   258,
      -1,   260,   261,   262,   263,   264,   265,    -1,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,    23,    24,
      -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    92,    93,    94,
      95,    -1,    97,    98,    99,    -1,    -1,   102,   103,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,
     125,   126,    -1,   128,    -1,    -1,    -1,   132,   133,   134,
     135,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,
     145,    -1,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   177,   178,   179,    -1,    -1,    -1,   183,   184,
     185,   186,    -1,    -1,    -1,   190,    -1,   192,    -1,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
      -1,    -1,   207,   208,    -1,    -1,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,   256,   257,   258,    -1,   260,   261,   262,   263,   264,
     265,    -1,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,
      31,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      -1,    92,    93,    94,    95,    -1,    97,    98,    99,    -1,
      -1,   102,   103,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,   112,   113,   114,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   123,   124,   125,   126,    -1,   128,    -1,    -1,
      -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,    -1,
      -1,    -1,   143,   144,   145,    -1,   147,   148,   149,    -1,
      -1,    -1,    -1,    -1,    -1,   156,   157,    -1,    -1,    -1,
      -1,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   177,   178,   179,    -1,
      -1,    -1,   183,   184,   185,   186,    -1,    -1,    -1,   190,
      -1,   192,    -1,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,    -1,    -1,   207,   208,    -1,    -1,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,    -1,   256,   257,   258,    -1,   260,
     261,   262,   263,   264,   265,    -1,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,    23,    24,    -1,    -1,
      27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    92,    93,    94,    95,    -1,
      97,    98,    99,    -1,    -1,   102,   103,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,   113,   114,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   123,   124,   125,   126,
      -1,   128,    -1,    -1,    -1,   132,   133,   134,   135,   136,
      -1,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,    -1,
     147,   148,   149,    -1,    -1,    -1,   153,    -1,    -1,   156,
     157,    -1,    -1,    -1,    -1,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     177,   178,   179,    -1,    -1,    -1,   183,    -1,   185,   186,
      -1,    -1,    -1,    -1,    -1,   192,    -1,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,    -1,    -1,
     207,   208,    -1,    -1,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,    -1,   256,
     257,   258,    -1,   260,   261,   262,   263,   264,   265,    -1,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
      23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      93,    94,    95,    -1,    97,    98,    99,    -1,    -1,   102,
     103,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     123,   124,   125,   126,    -1,   128,    -1,    -1,    -1,   132,
     133,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,
     143,   144,   145,    -1,   147,   148,   149,    -1,    -1,    -1,
     153,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   177,   178,   179,    -1,    -1,    -1,
     183,    -1,   185,   186,    -1,    -1,    -1,    -1,    -1,   192,
      -1,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,    -1,    -1,   207,   208,    -1,    -1,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,    -1,   256,   257,   258,    -1,   260,   261,   262,
     263,   264,   265,    -1,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,    23,    24,    -1,    -1,    27,    -1,
      -1,    -1,    31,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    -1,    92,    93,    94,    95,    -1,    97,    98,
      99,    -1,    -1,   102,   103,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,   113,   114,   115,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   123,   124,   125,   126,    -1,   128,
      -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,
      -1,    -1,    -1,    -1,   143,   144,   145,    -1,   147,   148,
     149,    -1,    -1,    -1,   153,    -1,    -1,   156,   157,    -1,
      -1,    -1,    -1,   162,   163,   164,   165,   166,   167,   168,
     169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,   178,
     179,    -1,    -1,    -1,   183,    -1,   185,   186,    -1,    -1,
      -1,    -1,    -1,   192,    -1,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,    -1,    -1,   207,   208,
      -1,    -1,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,   256,   257,   258,
      -1,   260,   261,   262,   263,   264,   265,    -1,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,    23,    24,
      -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    92,    93,    94,
      95,    -1,    97,    98,    99,    -1,    -1,   102,   103,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,
     125,   126,    -1,   128,    -1,    -1,    -1,   132,   133,   134,
     135,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,
     145,    -1,   147,   148,   149,    -1,    -1,    -1,   153,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   177,   178,   179,    -1,    -1,    -1,   183,    -1,
     185,   186,    -1,    -1,    -1,    -1,    -1,   192,    -1,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
      -1,    -1,   207,   208,    -1,    -1,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,   256,   257,   258,    -1,   260,   261,   262,   263,   264,
     265,    -1,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,
      31,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      -1,    92,    93,    94,    95,    -1,    97,    98,    99,    -1,
      -1,   102,   103,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,   112,   113,   114,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   123,   124,   125,   126,    -1,   128,    -1,    -1,
      -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,    -1,
      -1,    -1,   143,   144,   145,    -1,   147,   148,   149,    -1,
      -1,    -1,   153,    -1,    -1,   156,   157,    -1,    -1,    -1,
      -1,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   177,   178,   179,    -1,
      -1,    -1,   183,    -1,   185,   186,    -1,    -1,    -1,    -1,
      -1,   192,    -1,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,    -1,    -1,   207,   208,    -1,    -1,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,    -1,   256,   257,   258,    -1,   260,
     261,   262,   263,   264,   265,    -1,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,    23,    24,    -1,    -1,
      27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    92,    93,    94,    95,    -1,
      97,    98,    99,    -1,    -1,   102,   103,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,   113,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   123,   124,   125,   126,
      -1,   128,    -1,    -1,    -1,   132,   133,   134,   135,   136,
      -1,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,    -1,
     147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,
     157,    -1,    -1,    -1,    -1,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     177,   178,   179,    -1,    -1,    -1,   183,    -1,   185,   186,
      -1,    -1,    -1,    -1,    -1,   192,    -1,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,    -1,    -1,
     207,   208,    -1,    -1,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,    -1,   256,
     257,   258,    -1,   260,   261,   262,   263,   264,   265,    -1,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
      23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,
      -1,    34,    35,    36,    -1,    38,    39,    40,    41,    -1,
      -1,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      -1,    54,    55,    56,    57,    -1,    59,    -1,    -1,    62,
      63,    64,    65,    66,    -1,    68,    -1,    70,    -1,    -1,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      93,    94,    -1,    -1,    97,    98,    99,    -1,    -1,   102,
     103,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     123,   124,   125,   126,    -1,   128,    -1,    -1,    -1,   132,
     133,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,
     143,   144,   145,    -1,   147,   148,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   177,   178,   179,    -1,    -1,    -1,
     183,    -1,   185,   186,    -1,    -1,    -1,    -1,    -1,   192,
      -1,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,    -1,    -1,    -1,   208,    -1,    -1,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,    -1,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,    -1,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,    -1,   256,   257,   258,    -1,   260,   261,   262,
     263,   264,   265,    -1,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,    11,    19,    20,    21,    22,    23,    24,    25,    27,
      31,    32,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    92,    93,    94,
      95,    96,    97,    98,    99,   102,   103,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   121,   123,
     124,   125,   126,   128,   132,   133,   134,   135,   136,   143,
     144,   145,   146,   147,   148,   149,   150,   153,   154,   155,
     156,   157,   162,   163,   164,   165,   166,   167,   168,   169,
     171,   173,   174,   177,   178,   179,   183,   185,   186,   188,
     189,   190,   192,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   207,   208,   209,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   256,   257,   258,   260,   261,   262,   263,   264,   265,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   322,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   343,
     344,   345,   346,   347,   348,   352,   353,   354,   358,   360,
     361,   363,   372,   375,   378,   379,   380,   382,   383,   384,
     385,   386,   388,   389,   391,   392,   393,   394,   395,   396,
     398,   399,   402,   403,   404,   405,   410,   412,   414,   415,
     420,   439,   442,   446,   449,   450,   455,   456,   457,   458,
     460,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     506,   507,   508,   522,   523,   525,   526,   527,   528,   529,
     530,   531,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   551,   552,   553,   554,   559,   560,   561,   562,
     563,   564,   567,   625,   627,   628,   629,    31,    32,    48,
     211,   381,   382,   383,   381,   381,   153,    35,    36,    38,
      39,    46,    55,    56,    73,    77,   108,   109,   110,   157,
     166,   198,   216,   226,   258,   284,   285,   286,   287,   288,
     290,   291,   292,   293,   294,   299,   300,   359,   360,   364,
     365,   366,   370,   371,   157,   150,   153,   150,   153,   150,
     153,    65,    70,   115,   407,   153,   367,   153,    23,    32,
      59,   115,   270,   419,   421,   422,   150,   153,   153,   153,
     115,   150,   153,   153,   153,    92,   150,   217,   218,   119,
     119,   119,   150,   153,    27,    37,    41,    43,    45,    46,
      47,    50,    58,    66,    69,    71,    72,    74,    88,    89,
      95,   102,   109,   111,   112,   132,   135,   136,   166,   169,
     177,   178,   186,   198,   220,   222,   224,   225,   232,   234,
     235,   236,   237,   240,   241,   490,   627,   628,   119,   115,
     390,   119,   119,    37,    42,    43,    58,    60,    61,    69,
      95,   221,   627,   115,   119,   119,   181,   381,   383,    47,
      71,    72,   115,   150,   184,   241,   402,   404,   414,   627,
     150,   119,    15,   626,   627,    17,    18,   627,   119,   119,
     119,   482,   150,    28,   210,   212,   221,   223,   153,   221,
     223,   221,   221,   226,   115,   109,   360,   238,   238,   239,
     153,   150,   385,   324,     0,   326,   327,    31,    48,   329,
     346,     1,   187,   323,   187,   323,   109,   361,   384,   402,
     104,   187,   104,   187,    40,    45,    50,    68,   165,   168,
     183,   208,   397,   406,   411,   412,   413,   427,   428,   432,
     164,    90,   129,   137,   138,   140,   148,   152,   154,   159,
     176,   199,   200,   201,   202,   203,   204,   474,   475,   246,
     155,   173,   195,   114,   143,   156,   190,   197,   206,   133,
     147,    49,   196,    98,    99,   155,   173,   473,   150,   479,
     482,   188,   189,   151,   494,   495,   490,   494,   490,   153,
     494,   118,   142,   153,   181,   181,   181,    27,   362,   497,
     625,   179,   192,   179,   192,   163,   179,   628,   627,   166,
     198,    46,   627,   149,   115,    43,    46,    77,   103,   165,
     626,   217,   218,   219,   297,   298,   243,   598,   627,   290,
     627,   295,   295,   297,   298,   301,   134,   139,   109,   364,
     284,   292,   371,   626,   382,   383,   184,   381,    43,    61,
     184,   547,   548,   402,   184,   190,   627,   281,   281,   416,
     417,   627,   115,   423,   115,   184,   368,   369,   150,   387,
     402,     1,   157,   625,   110,   157,   342,   625,   627,   115,
     139,   104,   402,    27,   184,   626,   627,   627,   440,   441,
     627,   382,   184,   402,   402,   549,   627,   382,   150,   150,
     402,   184,   190,   627,   627,   139,   440,   181,   181,   153,
     153,   153,   627,   150,   184,   183,    33,   510,   511,   512,
     402,     8,   172,    16,   402,   210,    27,   403,   403,   184,
     403,   403,   403,   403,   227,   565,   566,   627,   390,   109,
     187,   187,   403,   402,   383,   402,   242,   400,   401,   187,
     323,   187,   323,     3,   330,   346,   379,   330,   346,   379,
      31,   347,   379,   347,   379,   390,   390,   403,   115,   165,
     167,   167,   384,   403,   403,   457,   458,   460,   460,   460,
     460,   459,   460,   460,   460,    69,   464,   464,   463,   465,
     465,   465,   465,   466,   466,   467,   467,   227,    92,    92,
      92,   181,   402,   482,   482,   402,   495,   184,   403,   505,
     626,   146,   184,   505,   104,   184,   104,   104,   367,    27,
     628,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,   349,   350,   351,    92,   134,   139,   355,   356,   357,
     627,   157,   157,   349,   625,   124,   129,    53,    55,    97,
     248,   261,   263,   274,   275,   276,   278,   280,   599,   600,
     601,   602,   603,   604,   611,   617,   618,   243,    92,   233,
     374,   296,   627,   139,   403,   115,   627,   627,   129,   181,
     181,   184,   184,   181,   104,   184,   104,   184,   104,    34,
      92,    94,   144,   418,   419,   533,   627,    54,   213,   251,
     408,   409,   627,    92,   104,   184,   381,   184,   626,    94,
      43,   626,   625,    94,   139,   533,   627,   403,   422,   181,
     184,   184,   184,   184,   104,   185,   144,   533,   181,   184,
     184,   150,   181,   382,   382,   181,   104,   184,   104,   184,
     139,   533,   403,   185,   402,   402,   402,   627,   511,   512,
     127,   193,   181,   181,   128,   187,    92,   214,   215,   229,
      92,   214,   215,   229,    92,   233,   221,   104,   231,   139,
     390,   187,   184,    47,    71,    72,   241,   404,   414,   181,
     491,   571,   401,   346,    31,    31,   187,   323,   187,   110,
     627,   167,   403,   433,   434,   115,   429,   430,   460,   150,
     153,   256,   478,   497,   572,   575,   576,   577,   578,   579,
     583,   585,   587,   588,    46,   149,   153,   207,   534,   536,
     538,   539,   555,   556,   557,   558,   627,   534,   532,   538,
     532,   181,   182,   104,   184,   184,   497,   145,   162,   145,
     162,   134,   387,   367,   350,   129,   536,   357,   403,   533,
     625,   625,   125,   126,   625,   274,   275,   276,   280,   627,
     260,   271,   260,   271,    27,   283,    94,   110,   153,   605,
     608,   599,    37,    42,    58,    60,    69,    95,   221,   373,
     539,   288,   289,   223,   296,   305,   403,   627,    92,   374,
     296,   625,   150,   549,   550,   627,   549,   550,   115,   124,
     534,   115,   403,   144,   419,   144,    34,   144,   418,   419,
     144,   533,   251,    52,    57,    75,   115,   418,   424,   425,
     426,   409,   533,   534,   369,    92,   181,   194,   129,   341,
     625,   157,   129,    94,   341,   403,   139,   419,   150,   115,
     403,   403,   144,    97,   443,   444,   445,   447,   448,    97,
     451,   452,   453,   454,   382,   181,   181,   150,   549,   549,
     403,   139,   187,   403,   184,   184,   184,    33,   512,   127,
     193,     9,    10,   100,   120,   122,   150,   191,   507,   509,
     520,   521,   524,    27,   228,   230,   403,   403,   403,   228,
     230,   403,   403,   403,   403,   403,   403,   115,   403,   403,
     384,   153,   153,   153,   150,   183,   242,   568,   569,   153,
     206,   385,   187,   110,   379,   379,   379,   433,    93,   103,
     113,   124,   435,   436,   437,   438,   104,   627,   104,   402,
     572,   579,   150,   282,   461,   624,    94,   166,   249,   250,
     252,   259,   269,   281,   573,   574,   593,   594,   595,   596,
     619,   622,   255,   257,   580,   598,   264,   584,   620,   244,
     245,   267,   589,   590,   153,   153,   536,   153,   141,   173,
     190,   535,   141,   403,   134,   387,   551,   356,   283,    27,
      94,   110,   153,   612,    27,   605,   374,   535,   223,   223,
     480,   284,   303,   533,   373,   223,   187,   381,   184,   184,
     141,   184,   184,   417,   144,   418,   627,   403,   144,   403,
     124,   403,   144,   419,   144,   403,   144,   115,   115,   403,
     627,   426,    75,   534,   384,   403,   625,   104,   341,   403,
     139,   381,   441,   403,   403,   110,   444,   445,    97,   183,
     110,   445,   448,   115,   534,    97,   110,   452,    97,   110,
     454,   181,   381,   184,   184,   403,   194,   451,   129,   191,
     509,     7,   382,   627,   191,   520,   187,   229,   229,   229,
     229,   233,   566,   183,   402,   402,   402,   571,   569,   115,
     491,   625,   125,   126,   437,   438,   438,   434,   103,   431,
     430,   181,   184,   572,   586,   247,   213,   251,   265,   272,
     623,    94,   253,   254,   621,   247,   576,   623,   463,   593,
     577,   144,   279,   581,   582,   621,   283,   592,    76,   591,
     184,   190,   534,   537,   184,   184,   184,    27,   133,   197,
     614,   615,   616,    27,   613,   614,   268,   609,   104,   606,
     167,   627,   254,   374,   480,   181,   403,   144,   403,   144,
     418,   403,   144,   403,   403,   627,   627,   425,   403,   123,
     123,    94,   625,   403,   181,   183,   183,   403,   384,   403,
     183,   183,   627,   183,   115,   534,   115,   183,   115,   534,
     183,   181,   110,   512,   627,   191,   181,   512,   627,   403,
     403,   403,   403,   403,   403,   184,   184,   184,   150,   153,
     570,   627,   438,   625,   181,   465,    51,   126,   463,   463,
     266,   273,   283,   597,   597,   578,   150,   277,    92,   184,
     104,   184,   612,   612,   616,   104,   184,    27,   610,   621,
     607,   608,   184,   376,   377,   480,   115,   221,   304,   284,
     167,   403,   403,   144,   403,    52,   384,   403,   341,   403,
     384,    92,   384,   403,   627,   183,   627,   403,   627,   183,
     384,   115,    91,   180,   513,   512,   627,   193,   512,   194,
     451,   402,   115,   104,   184,   463,   463,   195,   402,   534,
     534,    92,    27,   262,   104,   104,   438,   533,   627,   115,
     221,   627,   376,   403,   115,   534,    92,   183,    92,   627,
       5,   130,   516,   517,   519,   521,    26,   131,   514,   515,
     518,   521,   193,   512,   193,   110,   181,   627,   115,   385,
     463,   181,   534,   608,   377,   438,   302,   627,   115,   221,
     627,   183,   534,   384,   403,   534,   183,    91,   130,   519,
     180,   131,   518,   193,   115,   104,   184,   627,   403,   302,
     627,   115,   384,   403,   183,   183,   627,   115,   570,   104,
     184,   290,   302,   627,   183,   627,   115,   385,   303,   403,
     303,   104,   184,   627,   480,   480,   115,   570,   184,   195,
     627,   385,   284,   184,   627,   570,   221,   115,   627,   303,
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
     377,   377,   378,   378,   378,   378,   379,   380,   380,   380,
     381,   381,   381,   382,   382,   383,   383,   384,   384,   384,
     384,   384,   384,   384,   384,   384,   384,   384,   384,   385,
     385,   386,   387,   388,   389,   389,   389,   389,   389,   390,
     390,   390,   390,   391,   392,   393,   394,   395,   395,   396,
     397,   398,   399,   400,   400,   401,   401,   401,   401,   402,
     402,   403,   403,   403,   403,   403,   403,   404,   404,   404,
     404,   404,   404,   404,   405,   406,   407,   407,   408,   408,
     408,   409,   409,   410,   410,   411,   412,   412,   412,   413,
     413,   413,   413,   413,   414,   414,   415,   416,   416,   417,
     417,   417,   417,   417,   417,   417,   417,   417,   417,   417,
     417,   418,   419,   420,   421,   421,   422,   422,   422,   422,
     423,   423,   424,   424,   424,   425,   425,   425,   426,   426,
     426,   427,   428,   429,   429,   430,   430,   431,   432,   432,
     433,   433,   434,   434,   435,   435,   435,   435,   435,   435,
     435,   436,   436,   437,   437,   438,   439,   439,   440,   440,
     441,   441,   442,   443,   443,   444,   445,   445,   446,   447,
     447,   448,   449,   449,   450,   450,   451,   451,   452,   452,
     453,   453,   454,   454,   455,   456,   456,   457,   457,   458,
     458,   458,   458,   458,   459,   458,   458,   458,   458,   460,
     460,   461,   461,   462,   462,   463,   463,   463,   464,   464,
     464,   464,   464,   465,   465,   465,   466,   466,   466,   467,
     467,   468,   468,   469,   469,   470,   470,   471,   471,   472,
     472,   472,   472,   473,   473,   473,   474,   474,   474,   474,
     474,   474,   475,   475,   475,   476,   476,   476,   476,   477,
     477,   478,   478,   479,   479,   479,   480,   480,   480,   480,
     481,   482,   482,   482,   483,   483,   484,   484,   484,   484,
     485,   485,   486,   486,   486,   486,   486,   486,   486,   487,
     487,   488,   488,   489,   489,   489,   489,   489,   490,   490,
     491,   491,   492,   492,   492,   493,   493,   493,   493,   494,
     494,   495,   496,   496,   496,   496,   496,   496,   496,   496,
     496,   496,   497,   497,   498,   498,   498,   499,   500,   500,
     501,   502,   503,   504,   504,   505,   505,   506,   506,   507,
     507,   507,   508,   508,   508,   508,   508,   508,   509,   509,
     510,   510,   511,   512,   512,   513,   513,   514,   514,   515,
     515,   515,   515,   516,   516,   517,   517,   517,   517,   518,
     518,   519,   519,   520,   520,   520,   520,   521,   521,   521,
     521,   522,   522,   523,   523,   524,   525,   525,   525,   525,
     525,   525,   526,   527,   527,   528,   528,   529,   530,   531,
     531,   532,   532,   533,   534,   534,   534,   535,   535,   535,
     536,   536,   536,   536,   536,   537,   537,   538,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   540,   541,   541,
     541,   542,   543,   544,   544,   544,   545,   545,   545,   545,
     545,   546,   547,   547,   547,   547,   547,   547,   547,   548,
     549,   550,   551,   552,   552,   553,   554,   555,   555,   556,
     557,   557,   558,   559,   559,   559,   560,   560,   560,   560,
     560,   560,   560,   560,   560,   560,   561,   561,   562,   562,
     563,   564,   565,   565,   566,   567,   568,   568,   569,   569,
     569,   569,   570,   571,   571,   572,   573,   573,   574,   574,
     575,   575,   576,   576,   577,   577,   578,   578,   579,   580,
     580,   581,   581,   582,   583,   583,   583,   584,   584,   585,
     586,   586,   587,   588,   588,   589,   589,   590,   590,   590,
     591,   591,   592,   592,   593,   593,   593,   593,   593,   594,
     595,   596,   597,   597,   597,   598,   598,   599,   599,   599,
     599,   599,   599,   599,   599,   600,   600,   600,   600,   601,
     601,   602,   603,   603,   604,   604,   604,   605,   605,   606,
     606,   607,   607,   608,   609,   609,   610,   610,   611,   611,
     611,   612,   612,   613,   613,   614,   614,   615,   615,   616,
     616,   617,   618,   618,   619,   619,   619,   620,   621,   621,
     621,   621,   622,   622,   623,   623,   624,   625,   626,   626,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   629,   629
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
       2,     3,    11,    14,    13,    22,     1,     1,     1,     0,
       1,     1,     0,     1,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     3,     3,     2,     3,     2,     3,     3,     4,     2,
       3,     4,     5,     5,     2,     4,     5,     3,     3,     2,
       2,     8,     3,     1,     2,     3,     7,    10,    13,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     1,     1,
       2,     4,     3,     5,     4,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     1,     4,     3,
       5,     4,     6,     4,     6,     5,     7,     4,     5,     5,
       6,     3,     3,     2,     1,     3,     4,     5,     3,     6,
       4,     5,     1,     2,     3,     1,     2,     1,     6,     3,
       3,     2,     3,     1,     3,     2,     3,     2,     3,     4,
       1,     3,     1,     2,     1,     1,     1,     2,     2,     2,
       3,     1,     1,     2,     2,     2,     5,     5,     1,     4,
       3,     4,     8,     1,     2,     3,     2,     3,     8,     1,
       2,     3,     8,    10,     8,    10,     1,     2,     4,     7,
       1,     2,     4,     7,     8,     1,     3,     1,     3,     1,
       3,     3,     3,     3,     0,     4,     3,     3,     3,     1,
       5,     0,     1,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       4,     1,     4,     1,     4,     1,     4,     1,     2,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     5,     5,     6,     3,
       4,     1,     2,     3,     2,     2,     1,     2,     2,     1,
       1,     1,     3,     3,     1,     1,     1,     2,     1,     2,
       2,     1,     2,     2,     2,     2,     2,     2,     2,     1,
       2,     2,     1,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     4,     1,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       1,     4,     4,     3,     4,     1,     3,     1,     1,     1,
       1,     1,     4,     5,     8,     9,     9,    10,     1,     2,
       1,     2,     6,     0,     1,     3,     3,     0,     1,     1,
       1,     2,     2,     0,     1,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     2,     3,     3,     2,     1,     1,     1,     1,
       1,     1,     4,     3,     7,     3,     7,     4,     4,     3,
       7,     1,     2,     2,     1,     2,     3,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     4,
       4,     3,     3,     3,     4,     4,     3,     4,     6,     4,
       6,     4,     3,     4,     6,     6,     4,     6,     6,     4,
       1,     2,     1,     1,     1,     3,     3,     1,     1,     4,
       5,     6,     3,     3,     3,     3,     5,     7,     7,     5,
       5,     5,     7,     7,     5,     5,     3,     3,     5,     7,
       5,     7,     1,     4,     3,     5,     1,     2,     3,     7,
      10,    13,     3,     1,     3,     2,     0,     1,     1,     2,
       1,     3,     1,     3,     1,     4,     1,     2,     3,     0,
       1,     0,     1,     4,     2,     3,     1,     0,     1,     4,
       0,     1,     2,     1,     3,     0,     1,     2,     2,     1,
       0,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     1,     1,     1,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     1,     1,     2,
       2,     3,     1,     2,     2,     5,     2,     1,     1,     0,
       2,     1,     3,     4,     0,     2,     0,     2,     4,     4,
       3,     2,     3,     1,     3,     0,     1,     1,     2,     2,
       2,     2,     1,     2,     2,     2,     2,     3,     2,     3,
       3,     4,     2,     2,     1,     1,     3,     1,     1,     1,
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
       1,     1,     1,     1,     1,     3,     1
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
       322,     0,    -1,   324,    -1,   307,   324,    -1,     1,     3,
      -1,   326,    -1,   325,   326,    -1,   327,    -1,   325,   327,
      -1,   211,   212,    27,   187,    -1,   211,   212,    27,   128,
      27,   187,    -1,   329,   187,   379,    -1,   346,   187,   379,
      -1,   329,   187,   346,   187,   379,    -1,   379,    -1,   329,
     323,   379,    -1,   346,   323,   379,    -1,   329,   187,   346,
     323,   379,    -1,   329,   323,   346,   187,   379,    -1,   328,
      -1,   328,   329,   187,    -1,   328,   346,   187,    -1,   328,
     329,   187,   346,   187,    -1,    32,   157,   626,   129,   625,
     187,    -1,   330,    -1,   329,   187,   330,    -1,   329,   323,
     330,    -1,   331,    -1,   339,    -1,   344,    -1,   345,    -1,
     353,    -1,   332,    -1,   333,    -1,   334,    -1,   335,    -1,
     336,    -1,   337,    -1,   338,    -1,   559,    -1,    31,    36,
     179,    -1,    31,    36,   192,    -1,    31,   110,   103,   625,
      -1,    31,    35,   625,    -1,    31,    38,   179,    -1,    31,
      38,   192,    -1,    31,    56,   166,    -1,    31,    56,   198,
      -1,    31,   110,   165,   124,   125,    -1,    31,   110,   165,
     124,   126,    -1,    31,    39,   179,   104,   145,    -1,    31,
      39,   179,   104,   162,    -1,    31,    39,   163,   104,   145,
      -1,    31,    39,   163,   104,   162,    -1,   340,    -1,   343,
      -1,    48,    23,     1,    -1,    48,    59,   625,    -1,    48,
      59,   342,   625,    -1,    48,    59,   625,    94,   341,    -1,
      48,    59,   342,   625,    94,   341,    -1,   625,    -1,   341,
     104,   625,    -1,   157,   626,   129,    -1,   110,    43,   157,
      -1,    48,    32,   625,    -1,    48,    32,   157,   626,   129,
     625,    -1,    48,    32,   625,    94,   341,    -1,    48,    32,
     157,   626,   129,   625,    94,   341,    -1,    31,   157,   626,
     129,   625,    -1,    31,   110,    43,   157,   625,    -1,    31,
     110,    46,   157,   625,    -1,   347,    -1,   346,   187,   347,
      -1,   346,   323,   347,    -1,   348,    -1,   352,    -1,   354,
      -1,   358,    -1,   363,    -1,   372,    -1,   375,    -1,   378,
      -1,    31,   110,    77,   349,    -1,    31,    77,   627,   349,
      -1,   350,    -1,   349,   350,    -1,   351,   129,   551,    -1,
      78,    -1,    86,    -1,    79,    -1,    80,    -1,    81,    -1,
      82,    -1,    87,    -1,    83,    -1,    84,    -1,    85,    -1,
      31,    55,   627,    27,    -1,    31,   258,   598,    -1,    31,
     108,   149,   355,    -1,    92,   536,   356,    -1,   356,    -1,
     357,    -1,   134,    -1,   134,   357,    -1,   139,   403,    -1,
      31,   359,   139,   403,    -1,    31,   359,   134,    -1,    31,
     359,   134,   139,   403,    -1,   109,   115,   627,    -1,   109,
     115,   627,   533,    -1,   360,   109,   115,   627,    -1,   360,
     109,   115,   627,   533,    -1,   361,    -1,   360,   361,    -1,
      25,    -1,    25,   153,   362,   184,    -1,   497,    -1,   362,
     104,   497,    -1,    31,   364,    -1,    31,   360,   364,    -1,
     365,    -1,   366,    -1,    46,   628,   367,   387,    -1,    46,
     628,   367,   134,    -1,    73,    46,   628,   367,   387,    -1,
      73,    46,   628,   367,   134,    -1,   153,   184,    -1,   153,
     368,   184,    -1,   153,   184,    92,   534,    -1,   153,   368,
     184,    92,   534,    -1,   369,    -1,   368,   104,   369,    -1,
     115,   627,    -1,   115,   627,   533,    -1,   371,    -1,   370,
     371,    -1,   285,    -1,   286,    -1,   287,    -1,   288,    -1,
     166,    -1,   198,    -1,   226,   298,    -1,   226,   297,    -1,
     299,   298,    -1,   299,   297,    -1,   290,    -1,   291,   290,
      -1,   294,   295,    -1,   293,   295,    -1,    31,   284,   627,
      -1,    31,   284,   627,   374,    -1,    31,   284,   627,    92,
     373,    -1,    31,   284,   627,    92,   373,   374,    -1,    31,
     370,   284,   627,    -1,    31,   370,   284,   627,   374,    -1,
      31,   370,   284,   627,    92,   373,    -1,    31,   370,   284,
     627,    92,   373,   374,    -1,   539,    -1,   539,   535,    -1,
     233,   289,   223,    -1,   233,   288,   223,    -1,    31,   292,
     627,   296,   223,   480,   167,   376,    -1,    31,   370,   292,
     627,   296,   223,   480,   167,   376,    -1,   377,    -1,   376,
     104,   377,    -1,   480,    -1,   480,   533,    -1,   480,   438,
      -1,   480,   533,   438,    -1,    31,   300,   301,   627,   296,
     284,   627,   115,   627,   302,   403,    -1,    31,   300,   301,
     627,   296,   284,   627,   221,   115,   627,   302,   290,   303,
     480,    -1,    31,   300,   301,   627,   296,   284,   627,   304,
     221,   115,   627,   302,   403,    -1,    31,   300,   301,   627,
     305,   303,   254,   284,   627,   221,   115,   627,   303,   480,
     195,   284,   627,   221,   115,   627,   303,   480,    -1,   380,
      -1,   382,    -1,   383,    -1,    -1,   382,    -1,   383,    -1,
      -1,   402,    -1,   383,   402,    -1,   384,    -1,   383,   384,
      -1,   385,    -1,   388,    -1,   391,    -1,   392,    -1,   393,
      -1,   394,    -1,   395,    -1,   396,    -1,   398,    -1,   450,
      -1,   446,    -1,   399,    -1,   150,   383,   181,    -1,   150,
     181,    -1,   150,   381,   181,    -1,   150,   381,   181,    -1,
     389,   187,    -1,   389,   104,   390,    -1,   109,   390,    -1,
     234,   109,   390,    -1,   360,   109,   390,    -1,   234,   360,
     109,   390,    -1,   115,   627,    -1,   115,   627,   533,    -1,
     115,   627,   139,   403,    -1,   115,   627,   533,   139,   403,
      -1,   115,   627,   139,   403,   187,    -1,   404,   187,    -1,
     237,   239,   403,   187,    -1,   240,   153,   402,   184,   384,
      -1,   235,   238,   187,    -1,   236,   238,   187,    -1,   414,
     397,    -1,   183,   384,    -1,    47,   153,   402,   184,   194,
     384,   123,   384,    -1,   241,   385,   400,    -1,   401,    -1,
     400,   401,    -1,   242,   571,   385,    -1,   242,   571,   153,
     115,   627,   184,   385,    -1,   242,   571,   153,   115,   627,
     104,   115,   627,   184,   385,    -1,   242,   571,   153,   115,
     627,   104,   115,   627,   104,   115,   627,   184,   385,    -1,
     403,    -1,   402,   104,   403,    -1,   405,    -1,   442,    -1,
     449,    -1,   455,    -1,   567,    -1,   404,    -1,   456,    -1,
     439,    -1,   560,    -1,   561,    -1,   563,    -1,   562,    -1,
     564,    -1,   414,   406,    -1,   183,   403,    -1,    65,   281,
      -1,    70,   281,    -1,   213,    -1,   251,    -1,    54,   251,
      -1,   408,   424,    75,   403,    -1,   408,    75,   403,    -1,
      45,   407,   423,   409,   409,    -1,    45,   407,   423,   409,
      -1,    40,   115,   627,    -1,   415,    -1,   420,    -1,   410,
      -1,   412,    -1,   427,    -1,   432,    -1,   428,    -1,   411,
      -1,   412,    -1,   414,   413,    -1,    45,   115,   416,    -1,
     417,    -1,   416,   104,   115,   417,    -1,   627,   144,   403,
      -1,   627,    34,   124,   144,   403,    -1,   627,   533,   144,
     403,    -1,   627,   533,    34,   124,   144,   403,    -1,   627,
     418,   144,   403,    -1,   627,    34,   124,   418,   144,   403,
      -1,   627,   533,   418,   144,   403,    -1,   627,   533,    34,
     124,   418,   144,   403,    -1,   627,   419,   144,   403,    -1,
     627,   533,   419,   144,   403,    -1,   627,   418,   419,   144,
     403,    -1,   627,   533,   418,   419,   144,   403,    -1,    94,
     115,   627,    -1,   270,   115,   627,    -1,    50,   421,    -1,
     422,    -1,   421,   104,   422,    -1,   115,   627,   139,   403,
      -1,   115,   627,   533,   139,   403,    -1,   419,   139,   403,
      -1,   115,   627,   533,   419,   139,   403,    -1,   115,   627,
     144,   403,    -1,   115,   627,   533,   144,   403,    -1,   425,
      -1,   115,   627,    -1,   115,   627,   425,    -1,   418,    -1,
     418,   426,    -1,   426,    -1,    57,   115,   627,    52,   115,
     627,    -1,    52,   115,   627,    -1,    57,   115,   627,    -1,
     208,   403,    -1,   168,   167,   429,    -1,   430,    -1,   429,
     104,   430,    -1,   115,   627,    -1,   115,   627,   431,    -1,
     103,   625,    -1,   165,   167,   433,    -1,    68,   165,   167,
     433,    -1,   434,    -1,   433,   104,   434,    -1,   403,    -1,
     403,   435,    -1,   436,    -1,   437,    -1,   438,    -1,   436,
     437,    -1,   436,   438,    -1,   437,   438,    -1,   436,   437,
     438,    -1,    93,    -1,   113,    -1,   124,   125,    -1,   124,
     126,    -1,   103,   625,    -1,    66,   115,   440,   185,   403,
      -1,   132,   115,   440,   185,   403,    -1,   441,    -1,   440,
     104,   115,   441,    -1,   627,   144,   403,    -1,   627,   533,
     144,   403,    -1,    71,   153,   402,   184,   443,   110,   183,
     403,    -1,   444,    -1,   443,   444,    -1,   445,   183,   403,
      -1,    97,   403,    -1,   445,    97,   403,    -1,    71,   153,
     402,   184,   447,   110,   183,   384,    -1,   448,    -1,   447,
     448,    -1,   445,   183,   384,    -1,    72,   153,   402,   184,
     451,   110,   183,   403,    -1,    72,   153,   402,   184,   451,
     110,   115,   627,   183,   403,    -1,    72,   153,   402,   184,
     453,   110,   183,   384,    -1,    72,   153,   402,   184,   451,
     110,   115,   627,   183,   384,    -1,   452,    -1,   451,   452,
      -1,    97,   534,   183,   403,    -1,    97,   115,   627,    92,
     534,   183,   403,    -1,   454,    -1,   453,   454,    -1,    97,
     534,   183,   384,    -1,    97,   115,   627,    92,   534,   183,
     384,    -1,    47,   153,   402,   184,   194,   403,   123,   403,
      -1,   457,    -1,   456,   164,   457,    -1,   458,    -1,   457,
      90,   458,    -1,   460,    -1,   460,   474,   460,    -1,   460,
     475,   460,    -1,   460,   129,   460,    -1,   460,   159,   460,
      -1,    -1,   460,   154,   459,   460,    -1,   460,   152,   460,
      -1,   460,   140,   460,    -1,   460,   138,   460,    -1,   462,
      -1,   462,   246,    69,   572,   461,    -1,    -1,   624,    -1,
     463,    -1,   463,   195,   463,    -1,   464,    -1,   463,   173,
     464,    -1,   463,   155,   464,    -1,   465,    -1,   464,   190,
     465,    -1,   464,   114,   465,    -1,   464,   143,   465,    -1,
     464,   156,   465,    -1,   466,    -1,   465,   197,   466,    -1,
     465,   206,   466,    -1,   467,    -1,   466,   147,   467,    -1,
     466,   133,   467,    -1,   468,    -1,   468,    49,   227,   534,
      -1,   469,    -1,   469,   196,    92,   534,    -1,   470,    -1,
     470,    98,    92,   532,    -1,   471,    -1,   471,    99,    92,
     532,    -1,   473,    -1,   472,   473,    -1,   173,    -1,   155,
      -1,   472,   173,    -1,   472,   155,    -1,   476,    -1,   480,
      -1,   477,    -1,   199,    -1,   204,    -1,   203,    -1,   202,
      -1,   201,    -1,   200,    -1,   148,    -1,   176,    -1,   137,
      -1,    74,   150,   382,   181,    -1,    74,   218,   150,   382,
     181,    -1,    74,   217,   150,   382,   181,    -1,    74,    92,
     549,   150,   382,   181,    -1,   478,   150,   181,    -1,   478,
     150,   402,   181,    -1,   479,    -1,   478,   479,    -1,   174,
     627,    16,    -1,   174,    17,    -1,   174,    18,    -1,   481,
      -1,   481,   482,    -1,   189,   482,    -1,   482,    -1,   188,
      -1,   483,    -1,   483,   188,   482,    -1,   483,   189,   482,
      -1,   484,    -1,   493,    -1,   485,    -1,   485,   494,    -1,
     488,    -1,   488,   494,    -1,   486,   490,    -1,   487,    -1,
     102,   119,    -1,   111,   119,    -1,    95,   119,    -1,   186,
     119,    -1,   112,   119,    -1,   136,   119,    -1,   135,   119,
      -1,   490,    -1,    96,   490,    -1,   489,   490,    -1,   117,
      -1,   169,   119,    -1,    88,   119,    -1,   178,   119,    -1,
     177,   119,    -1,    89,   119,    -1,   539,    -1,   491,    -1,
     627,    -1,   492,    -1,   190,    -1,    11,    -1,    19,    -1,
     496,    -1,   493,   494,    -1,   493,   153,   184,    -1,   493,
     153,   505,   184,    -1,   495,    -1,   494,   495,    -1,   151,
     402,   182,    -1,   497,    -1,   499,    -1,   500,    -1,   501,
      -1,   504,    -1,   506,    -1,   502,    -1,   503,    -1,   552,
      -1,   386,    -1,   498,    -1,   551,    -1,   107,    -1,   146,
      -1,   121,    -1,   115,   627,    -1,   153,   184,    -1,   153,
     402,   184,    -1,   116,    -1,   166,   150,   402,   181,    -1,
     198,   150,   402,   181,    -1,   628,   153,   184,    -1,   628,
     153,   505,   184,    -1,   403,    -1,   505,   104,   403,    -1,
     507,    -1,   525,    -1,   508,    -1,   522,    -1,   523,    -1,
     154,   627,   512,   127,    -1,   154,   627,   510,   512,   127,
      -1,   154,   627,   512,   193,   191,   627,   512,   193,    -1,
     154,   627,   512,   193,   509,   191,   627,   512,   193,    -1,
     154,   627,   510,   512,   193,   191,   627,   512,   193,    -1,
     154,   627,   510,   512,   193,   509,   191,   627,   512,   193,
      -1,   520,    -1,   509,   520,    -1,   511,    -1,   510,   511,
      -1,    33,   627,   512,   129,   512,   513,    -1,    -1,    33,
      -1,   180,   514,   180,    -1,    91,   516,    91,    -1,    -1,
     515,    -1,   131,    -1,   518,    -1,   515,   131,    -1,   515,
     518,    -1,    -1,   517,    -1,   130,    -1,   519,    -1,   517,
     130,    -1,   517,   519,    -1,    26,    -1,   521,    -1,     5,
      -1,   521,    -1,   507,    -1,    10,    -1,   524,    -1,   521,
      -1,     9,    -1,   120,    -1,   122,    -1,   150,   382,   181,
      -1,   209,    28,   210,    -1,   209,   210,    -1,   171,   626,
     172,    -1,   171,   626,     8,    -1,   100,     7,    -1,   526,
      -1,   527,    -1,   528,    -1,   529,    -1,   530,    -1,   531,
      -1,    41,   150,   381,   181,    -1,    20,   381,   181,    -1,
      43,   150,   402,   181,   150,   381,   181,    -1,    21,   381,
     181,    -1,    95,   150,   402,   181,   150,   381,   181,    -1,
      69,   150,   382,   181,    -1,    37,   150,   382,   181,    -1,
      22,   381,   181,    -1,    58,   150,   402,   181,   150,   381,
     181,    -1,   538,    -1,   538,   141,    -1,    92,   534,    -1,
     536,    -1,   536,   535,    -1,   207,   153,   184,    -1,   141,
      -1,   190,    -1,   173,    -1,   538,    -1,   539,    -1,   149,
     153,   184,    -1,   555,    -1,   558,    -1,   534,    -1,   537,
     104,   534,    -1,   627,    -1,   541,    -1,   547,    -1,   545,
      -1,   548,    -1,   546,    -1,   544,    -1,   543,    -1,   542,
      -1,   540,    -1,   221,   153,   184,    -1,    42,   153,   184,
      -1,    42,   153,   547,   184,    -1,    42,   153,   548,   184,
      -1,    69,   153,   184,    -1,    37,   153,   184,    -1,    58,
     153,   184,    -1,    58,   153,   626,   184,    -1,    58,   153,
      27,   184,    -1,    95,   153,   184,    -1,    95,   153,   627,
     184,    -1,    95,   153,   627,   104,   549,   184,    -1,    95,
     153,   190,   184,    -1,    95,   153,   190,   104,   549,   184,
      -1,    60,   153,   627,   184,    -1,    43,   153,   184,    -1,
      43,   153,   627,   184,    -1,    43,   153,   627,   104,   549,
     184,    -1,    43,   153,   627,   104,   550,   184,    -1,    43,
     153,   190,   184,    -1,    43,   153,   190,   104,   549,   184,
      -1,    43,   153,   190,   104,   550,   184,    -1,    61,   153,
     627,   184,    -1,   627,    -1,   627,   141,    -1,    27,    -1,
     553,    -1,   554,    -1,   627,   142,   146,    -1,    46,   367,
     387,    -1,   556,    -1,   557,    -1,    46,   153,   190,   184,
      -1,    46,   153,   184,    92,   534,    -1,    46,   153,   537,
     184,    92,   534,    -1,   153,   536,   184,    -1,    31,   216,
     217,    -1,    31,   216,   218,    -1,    31,   216,   219,    -1,
     222,   221,   403,   229,   403,    -1,   222,   221,   403,    92,
     228,   229,   403,    -1,   222,   221,   403,    92,   230,   229,
     403,    -1,   222,   221,   403,   214,   403,    -1,   222,   221,
     403,   215,   403,    -1,   222,   223,   403,   229,   403,    -1,
     222,   223,   403,    92,   228,   229,   403,    -1,   222,   223,
     403,    92,   230,   229,   403,    -1,   222,   223,   403,   214,
     403,    -1,   222,   223,   403,   215,   403,    -1,   220,   221,
     403,    -1,   220,   223,   403,    -1,   225,   221,   403,   233,
     403,    -1,   225,   226,   227,   221,   403,   233,   403,    -1,
     224,   221,   403,    92,   403,    -1,   232,   115,   565,   231,
     403,   183,   403,    -1,   566,    -1,   565,   104,   115,   566,
      -1,   627,   139,   403,    -1,   241,   150,   402,   181,   568,
      -1,   569,    -1,   568,   569,    -1,   242,   571,   570,    -1,
     242,   571,   153,   115,   627,   184,   570,    -1,   242,   571,
     153,   115,   627,   104,   115,   627,   184,   570,    -1,   242,
     571,   153,   115,   627,   104,   115,   627,   104,   115,   627,
     184,   570,    -1,   150,   402,   181,    -1,   491,    -1,   571,
     206,   491,    -1,   575,   573,    -1,    -1,   574,    -1,   593,
      -1,   574,   593,    -1,   576,    -1,   575,   259,   576,    -1,
     577,    -1,   576,   255,   577,    -1,   578,    -1,   577,   257,
     144,   578,    -1,   579,    -1,   256,   579,    -1,   583,   580,
     581,    -1,    -1,   598,    -1,    -1,   582,    -1,   279,   150,
     402,   181,    -1,   587,   584,    -1,   153,   572,   184,    -1,
     585,    -1,    -1,   620,    -1,   478,   150,   586,   181,    -1,
      -1,   572,    -1,   588,   589,    -1,   497,    -1,   150,   402,
     181,    -1,    -1,   590,    -1,   245,   591,    -1,   244,   592,
      -1,   267,    -1,    -1,    76,    -1,    -1,   283,    -1,   594,
      -1,   595,    -1,   596,    -1,   622,    -1,   619,    -1,   166,
      -1,   281,   463,   597,    -1,   250,   621,   597,    -1,   283,
      -1,   273,    -1,   266,    -1,   243,   599,    -1,   598,   243,
     599,    -1,   600,    -1,   601,    -1,   602,    -1,   617,    -1,
     603,    -1,   611,    -1,   604,    -1,   618,    -1,    97,   271,
      -1,    97,   260,    -1,   263,    -1,   278,    -1,   248,   271,
      -1,   248,   260,    -1,    55,   627,    27,    -1,   274,    -1,
      53,   274,    -1,   276,   605,    -1,   276,   153,   605,   606,
     184,    -1,    53,   276,    -1,   608,    -1,   110,    -1,    -1,
     104,   607,    -1,   608,    -1,   607,   104,   608,    -1,    94,
      27,   609,   610,    -1,    -1,   268,    27,    -1,    -1,   621,
     262,    -1,   275,   283,   612,   614,    -1,   275,   283,   110,
     614,    -1,    53,   275,   283,    -1,    94,    27,    -1,   153,
     613,   184,    -1,    27,    -1,   613,   104,    27,    -1,    -1,
     615,    -1,   616,    -1,   615,   616,    -1,   197,   612,    -1,
     133,   612,    -1,   261,    27,    -1,   280,    -1,    53,   280,
      -1,    94,   213,    -1,    94,   251,    -1,   252,   247,    -1,
     264,   621,   277,    -1,   253,   463,    -1,    94,   126,   463,
      -1,    94,    51,   463,    -1,   254,   463,   195,   463,    -1,
     269,   623,    -1,   249,   623,    -1,   272,    -1,   265,    -1,
     282,   247,   465,    -1,    27,    -1,    15,    -1,   627,    -1,
     628,    -1,    95,    -1,    37,    -1,    42,    -1,    43,    -1,
     149,    -1,    47,    -1,   221,    -1,    58,    -1,    60,    -1,
      61,    -1,    69,    -1,    72,    -1,    71,    -1,   207,    -1,
     240,    -1,   629,    -1,    23,    -1,   211,    -1,   124,    -1,
      36,    -1,   258,    -1,    35,    -1,   218,    -1,   217,    -1,
     143,    -1,    41,    -1,   256,    -1,   257,    -1,   271,    -1,
     260,    -1,   248,    -1,   282,    -1,   274,    -1,   276,    -1,
     275,    -1,   280,    -1,   252,    -1,   247,    -1,    76,    -1,
     213,    -1,   251,    -1,    51,    -1,   219,    -1,   232,    -1,
     299,    -1,   226,    -1,   199,    -1,   204,    -1,   203,    -1,
     202,    -1,   201,    -1,   200,    -1,    94,    -1,   108,    -1,
     109,    -1,   183,    -1,    45,    -1,    34,    -1,    65,    -1,
      70,    -1,    57,    -1,    52,    -1,    54,    -1,    75,    -1,
      40,    -1,   144,    -1,    50,    -1,   208,    -1,   167,    -1,
     168,    -1,   165,    -1,    68,    -1,    93,    -1,   113,    -1,
     125,    -1,   126,    -1,   103,    -1,    66,    -1,   132,    -1,
     185,    -1,    97,    -1,    92,    -1,   194,    -1,   123,    -1,
     164,    -1,    90,    -1,    49,    -1,   227,    -1,    98,    -1,
     195,    -1,   114,    -1,   156,    -1,   197,    -1,   147,    -1,
     133,    -1,    74,    -1,    99,    -1,   196,    -1,   148,    -1,
     179,    -1,   192,    -1,   157,    -1,   134,    -1,   128,    -1,
     163,    -1,   145,    -1,   162,    -1,    31,    -1,    38,    -1,
      56,    -1,   110,    -1,    39,    -1,    55,    -1,   212,    -1,
      48,    -1,    59,    -1,    32,    -1,    46,    -1,   270,    -1,
     246,    -1,   279,    -1,   281,    -1,   250,    -1,   264,    -1,
     277,    -1,   269,    -1,   249,    -1,   263,    -1,   278,    -1,
     268,    -1,   262,    -1,   261,    -1,   245,    -1,   244,    -1,
     267,    -1,   253,    -1,   254,    -1,   283,    -1,   273,    -1,
     272,    -1,   265,    -1,   225,    -1,   231,    -1,   228,    -1,
     222,    -1,   215,    -1,   214,    -1,   216,    -1,   233,    -1,
     223,    -1,   224,    -1,   230,    -1,   220,    -1,   229,    -1,
      64,    -1,    62,    -1,    73,    -1,   166,    -1,   198,    -1,
     239,    -1,   234,    -1,   237,    -1,   238,    -1,   235,    -1,
     236,    -1,   241,    -1,   242,    -1,    44,    -1,   243,    -1,
      63,    -1,   292,    -1,   290,    -1,   291,    -1,   296,    -1,
     297,    -1,   298,    -1,   293,    -1,   294,    -1,   295,    -1,
      77,    -1,    78,    -1,    79,    -1,    80,    -1,    81,    -1,
      82,    -1,    83,    -1,    84,    -1,    85,    -1,    86,    -1,
      87,    -1,   284,    -1,   285,    -1,   286,    -1,   287,    -1,
     288,    -1,   289,    -1,   300,    -1,   301,    -1,   302,    -1,
     303,    -1,   304,    -1,   305,    -1,   306,    -1,    88,    -1,
     102,    -1,   111,    -1,   169,    -1,   177,    -1,   186,    -1,
     135,    -1,    89,    -1,   112,    -1,   136,    -1,   178,    -1,
     625,   118,   626,    -1,    24,    -1
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
     628,   631,   635,   647,   662,   676,   699,   701,   703,   705,
     706,   708,   710,   711,   713,   716,   718,   721,   723,   725,
     727,   729,   731,   733,   735,   737,   739,   741,   743,   745,
     749,   752,   756,   760,   763,   767,   770,   774,   778,   783,
     786,   790,   795,   801,   807,   810,   815,   821,   825,   829,
     832,   835,   844,   848,   850,   853,   857,   865,   876,   890,
     892,   896,   898,   900,   902,   904,   906,   908,   910,   912,
     914,   916,   918,   920,   922,   925,   928,   931,   934,   936,
     938,   941,   946,   950,   956,   961,   965,   967,   969,   971,
     973,   975,   977,   979,   981,   983,   986,   990,   992,   997,
    1001,  1007,  1012,  1019,  1024,  1031,  1037,  1045,  1050,  1056,
    1062,  1069,  1073,  1077,  1080,  1082,  1086,  1091,  1097,  1101,
    1108,  1113,  1119,  1121,  1124,  1128,  1130,  1133,  1135,  1142,
    1146,  1150,  1153,  1157,  1159,  1163,  1166,  1170,  1173,  1177,
    1182,  1184,  1188,  1190,  1193,  1195,  1197,  1199,  1202,  1205,
    1208,  1212,  1214,  1216,  1219,  1222,  1225,  1231,  1237,  1239,
    1244,  1248,  1253,  1262,  1264,  1267,  1271,  1274,  1278,  1287,
    1289,  1292,  1296,  1305,  1316,  1325,  1336,  1338,  1341,  1346,
    1354,  1356,  1359,  1364,  1372,  1381,  1383,  1387,  1389,  1393,
    1395,  1399,  1403,  1407,  1411,  1412,  1417,  1421,  1425,  1429,
    1431,  1437,  1438,  1440,  1442,  1446,  1448,  1452,  1456,  1458,
    1462,  1466,  1470,  1474,  1476,  1480,  1484,  1486,  1490,  1494,
    1496,  1501,  1503,  1508,  1510,  1515,  1517,  1522,  1524,  1527,
    1529,  1531,  1534,  1537,  1539,  1541,  1543,  1545,  1547,  1549,
    1551,  1553,  1555,  1557,  1559,  1561,  1566,  1572,  1578,  1585,
    1589,  1594,  1596,  1599,  1603,  1606,  1609,  1611,  1614,  1617,
    1619,  1621,  1623,  1627,  1631,  1633,  1635,  1637,  1640,  1642,
    1645,  1648,  1650,  1653,  1656,  1659,  1662,  1665,  1668,  1671,
    1673,  1676,  1679,  1681,  1684,  1687,  1690,  1693,  1696,  1698,
    1700,  1702,  1704,  1706,  1708,  1710,  1712,  1715,  1719,  1724,
    1726,  1729,  1733,  1735,  1737,  1739,  1741,  1743,  1745,  1747,
    1749,  1751,  1753,  1755,  1757,  1759,  1761,  1763,  1766,  1769,
    1773,  1775,  1780,  1785,  1789,  1794,  1796,  1800,  1802,  1804,
    1806,  1808,  1810,  1815,  1821,  1830,  1840,  1850,  1861,  1863,
    1866,  1868,  1871,  1878,  1879,  1881,  1885,  1889,  1890,  1892,
    1894,  1896,  1899,  1902,  1903,  1905,  1907,  1909,  1912,  1915,
    1917,  1919,  1921,  1923,  1925,  1927,  1929,  1931,  1933,  1935,
    1937,  1941,  1945,  1948,  1952,  1956,  1959,  1961,  1963,  1965,
    1967,  1969,  1971,  1976,  1980,  1988,  1992,  2000,  2005,  2010,
    2014,  2022,  2024,  2027,  2030,  2032,  2035,  2039,  2041,  2043,
    2045,  2047,  2049,  2053,  2055,  2057,  2059,  2063,  2065,  2067,
    2069,  2071,  2073,  2075,  2077,  2079,  2081,  2083,  2087,  2091,
    2096,  2101,  2105,  2109,  2113,  2118,  2123,  2127,  2132,  2139,
    2144,  2151,  2156,  2160,  2165,  2172,  2179,  2184,  2191,  2198,
    2203,  2205,  2208,  2210,  2212,  2214,  2218,  2222,  2224,  2226,
    2231,  2237,  2244,  2248,  2252,  2256,  2260,  2266,  2274,  2282,
    2288,  2294,  2300,  2308,  2316,  2322,  2328,  2332,  2336,  2342,
    2350,  2356,  2364,  2366,  2371,  2375,  2381,  2383,  2386,  2390,
    2398,  2409,  2423,  2427,  2429,  2433,  2436,  2437,  2439,  2441,
    2444,  2446,  2450,  2452,  2456,  2458,  2463,  2465,  2468,  2472,
    2473,  2475,  2476,  2478,  2483,  2486,  2490,  2492,  2493,  2495,
    2500,  2501,  2503,  2506,  2508,  2512,  2513,  2515,  2518,  2521,
    2523,  2524,  2526,  2527,  2529,  2531,  2533,  2535,  2537,  2539,
    2541,  2545,  2549,  2551,  2553,  2555,  2558,  2562,  2564,  2566,
    2568,  2570,  2572,  2574,  2576,  2578,  2581,  2584,  2586,  2588,
    2591,  2594,  2598,  2600,  2603,  2606,  2612,  2615,  2617,  2619,
    2620,  2623,  2625,  2629,  2634,  2635,  2638,  2639,  2642,  2647,
    2652,  2656,  2659,  2663,  2665,  2669,  2670,  2672,  2674,  2677,
    2680,  2683,  2686,  2688,  2691,  2694,  2697,  2700,  2704,  2707,
    2711,  2715,  2720,  2723,  2726,  2728,  2730,  2734,  2736,  2738,
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
    2980,  2982,  2984,  2986,  2988,  2990,  2992,  2994,  2996,  2998,
    3000,  3002,  3004,  3006,  3008,  3010,  3012,  3014,  3016,  3018,
    3020,  3022,  3024,  3026,  3028,  3030,  3032,  3034,  3036,  3038,
    3040,  3042,  3044,  3046,  3048,  3050,  3052,  3054,  3056,  3058,
    3060,  3062,  3064,  3066,  3068,  3070,  3072,  3074,  3076,  3078,
    3080,  3082,  3084,  3086,  3088,  3090,  3092,  3094,  3096,  3098,
    3100,  3102,  3104,  3106,  3108,  3110,  3112,  3114,  3116,  3118,
    3120,  3122,  3124,  3126,  3128,  3130,  3132,  3134,  3136,  3138,
    3140,  3142,  3144,  3146,  3148,  3150,  3152,  3154,  3156,  3158,
    3160,  3162,  3164,  3166,  3168,  3170,  3174
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,  1032,  1032,  1033,  1042,  1051,  1057,  1065,  1071,  1082,
    1087,  1095,  1102,  1109,  1118,  1125,  1133,  1141,  1149,  1160,
    1165,  1172,  1179,  1191,  1201,  1208,  1215,  1227,  1228,  1229,
    1230,  1231,  1236,  1237,  1238,  1239,  1240,  1241,  1242,  1245,
    1250,  1255,  1263,  1271,  1279,  1284,  1292,  1297,  1305,  1310,
    1318,  1325,  1332,  1339,  1349,  1351,  1354,  1364,  1369,  1377,
    1385,  1396,  1403,  1414,  1419,  1427,  1434,  1441,  1450,  1463,
    1471,  1478,  1488,  1495,  1502,  1513,  1514,  1515,  1516,  1517,
    1518,  1519,  1520,  1525,  1531,  1540,  1547,  1557,  1567,  1568,
    1569,  1570,  1571,  1572,  1573,  1574,  1575,  1576,  1581,  1589,
    1597,  1605,  1612,  1620,  1627,  1632,  1640,  1648,  1663,  1678,
    1696,  1701,  1709,  1717,  1728,  1733,  1742,  1747,  1757,  1762,
    1771,  1777,  1790,  1795,  1803,  1814,  1829,  1841,  1856,  1861,
    1866,  1871,  1879,  1886,  1897,  1902,  1912,  1918,  1928,  1932,
    1938,  1942,  1946,  1950,  1956,  1962,  1968,  1974,  1980,  1984,
    1990,  1996,  2003,  2011,  2019,  2027,  2035,  2047,  2061,  2075,
    2092,  2096,  2105,  2109,  2116,  2124,  2142,  2148,  2157,  2162,
    2169,  2176,  2187,  2197,  2207,  2217,  2235,  2255,  2260,  2265,
    2272,  2277,  2282,  2289,  2294,  2306,  2313,  2325,  2326,  2327,
    2328,  2329,  2330,  2331,  2333,  2334,  2335,  2336,  2337,  2342,
    2347,  2355,  2372,  2380,  2388,  2395,  2402,  2409,  2416,  2426,
    2438,  2451,  2463,  2479,  2487,  2495,  2503,  2518,  2523,  2531,
    2545,  2562,  2587,  2595,  2602,  2613,  2619,  2625,  2636,  2651,
    2656,  2671,  2672,  2673,  2674,  2675,  2676,  2681,  2682,  2685,
    2686,  2687,  2688,  2689,  2694,  2708,  2716,  2721,  2729,  2734,
    2739,  2747,  2756,  2768,  2778,  2791,  2799,  2800,  2801,  2806,
    2807,  2808,  2809,  2810,  2815,  2822,  2832,  2840,  2847,  2857,
    2867,  2877,  2887,  2897,  2907,  2917,  2927,  2938,  2947,  2957,
    2967,  2983,  2992,  3001,  3009,  3015,  3027,  3035,  3045,  3053,
    3065,  3071,  3082,  3084,  3088,  3096,  3100,  3105,  3109,  3113,
    3117,  3127,  3135,  3142,  3148,  3159,  3163,  3172,  3180,  3186,
    3196,  3202,  3212,  3216,  3226,  3232,  3238,  3244,  3253,  3262,
    3271,  3284,  3288,  3296,  3302,  3312,  3320,  3329,  3342,  3349,
    3361,  3365,  3377,  3384,  3390,  3399,  3406,  3412,  3423,  3430,
    3436,  3445,  3454,  3461,  3472,  3479,  3491,  3497,  3509,  3515,
    3526,  3532,  3543,  3549,  3560,  3569,  3573,  3582,  3586,  3594,
    3598,  3608,  3615,  3624,  3634,  3633,  3647,  3656,  3665,  3678,
    3682,  3695,  3698,  3705,  3709,  3718,  3722,  3726,  3735,  3739,
    3745,  3751,  3757,  3768,  3772,  3776,  3784,  3788,  3794,  3804,
    3808,  3818,  3822,  3832,  3836,  3846,  3850,  3860,  3864,  3872,
    3876,  3880,  3884,  3894,  3898,  3902,  3910,  3914,  3918,  3922,
    3926,  3930,  3938,  3942,  3946,  3954,  3958,  3962,  3966,  3977,
    3983,  3993,  3999,  4009,  4013,  4017,  4055,  4059,  4069,  4079,
    4092,  4101,  4111,  4115,  4124,  4128,  4137,  4143,  4151,  4157,
    4169,  4175,  4185,  4189,  4193,  4197,  4201,  4207,  4213,  4221,
    4225,  4233,  4237,  4248,  4252,  4256,  4262,  4266,  4280,  4284,
    4292,  4296,  4306,  4310,  4314,  4323,  4327,  4331,  4335,  4343,
    4349,  4359,  4367,  4371,  4375,  4379,  4383,  4387,  4391,  4395,
    4399,  4409,  4417,  4421,  4429,  4436,  4443,  4454,  4462,  4466,
    4474,  4482,  4490,  4544,  4548,  4561,  4567,  4577,  4581,  4589,
    4593,  4597,  4605,  4615,  4625,  4635,  4645,  4655,  4670,  4676,
    4687,  4693,  4704,  4715,  4717,  4721,  4726,  4736,  4739,  4746,
    4752,  4758,  4766,  4779,  4782,  4789,  4795,  4801,  4808,  4819,
    4823,  4833,  4837,  4847,  4851,  4855,  4860,  4869,  4875,  4881,
    4887,  4895,  4900,  4908,  4913,  4921,  4929,  4934,  4939,  4944,
    4949,  4954,  4963,  4971,  4975,  4992,  4996,  5004,  5012,  5020,
    5024,  5032,  5038,  5048,  5056,  5060,  5064,  5099,  5105,  5111,
    5121,  5125,  5129,  5133,  5137,  5144,  5150,  5160,  5168,  5172,
    5176,  5180,  5184,  5188,  5192,  5196,  5200,  5208,  5216,  5220,
    5224,  5234,  5242,  5250,  5254,  5258,  5266,  5270,  5276,  5282,
    5286,  5296,  5304,  5308,  5314,  5323,  5332,  5338,  5344,  5354,
    5371,  5378,  5393,  5429,  5433,  5441,  5449,  5461,  5465,  5473,
    5481,  5485,  5496,  5513,  5519,  5525,  5535,  5539,  5545,  5551,
    5555,  5561,  5565,  5571,  5577,  5584,  5594,  5599,  5607,  5613,
    5623,  5645,  5654,  5660,  5673,  5687,  5694,  5700,  5710,  5715,
    5720,  5730,  5744,  5752,  5758,  5776,  5785,  5788,  5795,  5800,
    5808,  5812,  5819,  5823,  5830,  5834,  5841,  5845,  5854,  5867,
    5870,  5878,  5881,  5889,  5897,  5905,  5909,  5917,  5920,  5928,
    5940,  5943,  5951,  5963,  5969,  5979,  5982,  5990,  5994,  5998,
    6006,  6009,  6017,  6020,  6028,  6032,  6036,  6040,  6044,  6052,
    6060,  6072,  6084,  6088,  6092,  6100,  6106,  6116,  6120,  6124,
    6128,  6132,  6136,  6140,  6144,  6152,  6156,  6160,  6164,  6172,
    6178,  6188,  6198,  6202,  6210,  6220,  6231,  6238,  6242,  6250,
    6253,  6260,  6265,  6274,  6284,  6287,  6295,  6298,  6306,  6315,
    6322,  6332,  6336,  6343,  6349,  6359,  6362,  6369,  6374,  6386,
    6394,  6406,  6414,  6418,  6426,  6430,  6434,  6442,  6450,  6454,
    6458,  6462,  6470,  6478,  6490,  6494,  6502,  6515,  6519,  6520,
    6533,  6534,  6535,  6536,  6537,  6538,  6539,  6540,  6541,  6542,
    6543,  6544,  6545,  6546,  6547,  6548,  6552,  6553,  6554,  6555,
    6556,  6557,  6558,  6559,  6560,  6561,  6562,  6563,  6564,  6565,
    6566,  6567,  6568,  6569,  6570,  6571,  6572,  6573,  6574,  6575,
    6576,  6577,  6578,  6579,  6580,  6581,  6582,  6583,  6584,  6585,
    6586,  6587,  6588,  6589,  6590,  6591,  6592,  6593,  6594,  6595,
    6596,  6597,  6598,  6599,  6600,  6601,  6602,  6603,  6604,  6605,
    6606,  6607,  6608,  6609,  6610,  6611,  6612,  6613,  6614,  6615,
    6616,  6617,  6618,  6619,  6620,  6621,  6622,  6623,  6624,  6625,
    6626,  6627,  6628,  6629,  6630,  6631,  6632,  6633,  6634,  6635,
    6636,  6637,  6638,  6639,  6640,  6641,  6642,  6643,  6644,  6645,
    6646,  6647,  6648,  6649,  6650,  6651,  6652,  6653,  6654,  6655,
    6656,  6657,  6658,  6659,  6660,  6661,  6662,  6663,  6664,  6665,
    6666,  6667,  6668,  6669,  6670,  6671,  6672,  6673,  6674,  6675,
    6676,  6677,  6678,  6679,  6680,  6681,  6682,  6683,  6684,  6685,
    6686,  6687,  6688,  6689,  6690,  6691,  6692,  6693,  6694,  6695,
    6696,  6697,  6698,  6699,  6700,  6701,  6702,  6703,  6704,  6705,
    6706,  6707,  6708,  6709,  6710,  6711,  6712,  6713,  6714,  6715,
    6716,  6717,  6718,  6719,  6720,  6721,  6722,  6723,  6724,  6725,
    6726,  6727,  6728,  6729,  6730,  6731,  6732,  6733,  6734,  6735,
    6736,  6737,  6738,  6739,  6740,  6741,  6742,  6743,  6744,  6745,
    6746,  6747,  6748,  6749,  6750,  6755,  6762
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
  const int xquery_parser::yylast_ = 13113;
  const int xquery_parser::yynnts_ = 309;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 584;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 321;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 575;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba

/* Line 1054 of lalr1.cc  */
#line 16470 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6766 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"


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

