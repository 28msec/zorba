
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

<<<<<<< TREE
/* Line 311 of lalr1.cc  */
#line 87 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 293 of lalr1.cc  */
#line 87 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE


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



<<<<<<< TREE
/* Line 311 of lalr1.cc  */
#line 79 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
=======
/* Line 293 of lalr1.cc  */
#line 77 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
>>>>>>> MERGE-SOURCE


#include "xquery_parser.hpp"

/* User implementation prologue.  */

<<<<<<< TREE
/* Line 317 of lalr1.cc  */
#line 902 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 299 of lalr1.cc  */
#line 878 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

<<<<<<< TREE
/* Line 317 of lalr1.cc  */
#line 1018 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 299 of lalr1.cc  */
#line 978 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE

#include "compiler/parser/xquery_scanner.h"

#undef yylex
#define yylex driver.lexer->lex



<<<<<<< TREE
/* Line 317 of lalr1.cc  */
#line 109 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
=======
/* Line 299 of lalr1.cc  */
#line 107 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
>>>>>>> MERGE-SOURCE

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

<<<<<<< TREE
/* Line 380 of lalr1.cc  */
#line 178 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
#if YYERROR_VERBOSE
=======
/* Line 382 of lalr1.cc  */
#line 193 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
>>>>>>> MERGE-SOURCE

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
        case 110: /* "\"'DECIMAL'\"" */

/* Line 480 of lalr1.cc  */
<<<<<<< TREE
#line 900 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
#line 876 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
<<<<<<< TREE
#line 285 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
=======
#line 298 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
>>>>>>> MERGE-SOURCE
	break;
      case 124: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
<<<<<<< TREE
#line 899 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
#line 875 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
<<<<<<< TREE
#line 294 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
=======
#line 307 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
>>>>>>> MERGE-SOURCE
	break;
      case 149: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
<<<<<<< TREE
#line 898 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
#line 874 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
<<<<<<< TREE
#line 303 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 312 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 321 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 330 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 339 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 348 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 357 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 366 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 375 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 384 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 393 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 402 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 411 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 420 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 429 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 438 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 447 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 456 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 465 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 474 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 483 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 492 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 501 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 510 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 519 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
#line 316 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 325 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 334 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 343 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 352 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 361 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 370 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 379 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 388 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 397 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 406 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 415 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 424 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 433 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 442 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 451 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 460 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 469 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 478 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 487 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 496 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 505 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 514 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 523 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 532 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 899 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
<<<<<<< TREE
#line 528 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
=======
#line 541 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
>>>>>>> MERGE-SOURCE
	break;
      case 360: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
<<<<<<< TREE
#line 926 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
#line 899 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
<<<<<<< TREE
#line 537 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 546 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 555 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 564 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 573 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 582 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 591 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 600 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
#line 550 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 559 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 568 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 577 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 586 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 595 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 604 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 613 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 899 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
<<<<<<< TREE
#line 609 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 618 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 627 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 636 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 645 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 654 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 663 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 672 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
#line 622 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 631 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 640 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 649 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 658 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 667 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 676 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 685 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 899 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
<<<<<<< TREE
#line 681 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 690 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 699 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 708 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 717 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 726 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 735 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 744 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 753 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 762 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 771 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 780 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 789 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 798 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 807 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 816 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 825 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 834 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 843 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 852 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 861 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 888 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 897 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 906 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 924 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 951 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 960 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 969 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 978 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 987 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 996 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1005 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1014 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1023 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1032 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1041 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1050 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1059 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1068 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1077 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1086 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1095 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1104 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1113 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1122 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1131 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1140 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1149 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1158 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1167 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1176 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1185 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1194 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1203 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1212 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1221 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1230 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1239 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1248 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1257 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1266 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1275 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1284 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1293 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1302 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1311 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1320 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1329 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1338 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1347 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1356 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1365 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1374 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1383 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1392 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1401 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1410 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1419 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1428 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1437 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1446 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1455 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1464 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1473 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1482 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1491 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1500 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1509 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1518 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1527 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1536 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1545 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1554 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1563 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1572 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1581 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1590 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1599 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1608 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1617 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1626 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1635 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1644 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1653 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1662 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1671 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1680 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1689 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1698 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1707 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1716 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1725 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1734 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1743 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1752 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1761 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1770 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1779 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1788 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1797 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1806 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1815 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1824 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1833 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1842 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1851 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1860 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1869 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1878 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1887 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1896 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1905 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1914 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1923 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1932 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1941 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1950 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1959 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1968 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1977 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1986 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1995 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2004 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2013 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2022 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2031 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2040 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2049 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2058 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2067 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2076 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2085 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2094 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2103 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2112 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2121 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2130 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2139 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2148 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2157 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2166 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2175 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2184 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2193 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2202 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2211 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2220 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2229 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2238 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2247 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2256 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2265 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2274 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2283 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2292 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2301 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2310 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2319 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
#line 694 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 703 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 712 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 721 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 730 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 739 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 748 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 757 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 766 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 775 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 784 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 793 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 802 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 811 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 820 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 829 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 838 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 856 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 865 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 874 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 883 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 892 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 901 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 910 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 919 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 928 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 937 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 946 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 955 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 964 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 973 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 982 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 991 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1000 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1009 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1018 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1027 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1036 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1045 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1054 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1063 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1072 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1081 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1090 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1099 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1108 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1117 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1126 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1135 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1144 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1153 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1162 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1171 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1180 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1189 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1198 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1207 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1216 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1225 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1234 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1243 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1252 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1261 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1270 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1279 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1288 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1297 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1306 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1315 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1324 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1333 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1342 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1351 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1360 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1369 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1378 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1387 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1396 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1405 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1414 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1423 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1432 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1441 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1450 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1459 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1468 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1477 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1486 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1495 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1504 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1513 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1522 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1531 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1540 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1549 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1558 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1567 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1576 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1585 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1594 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1603 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1612 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1621 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1630 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1639 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1648 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1657 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1666 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1675 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1684 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1693 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1702 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1711 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1720 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1729 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1738 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1747 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1756 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1765 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1774 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1783 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1792 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1801 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1810 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1819 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1828 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1837 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1846 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1855 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1864 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1873 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1882 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1891 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1900 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1909 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1918 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1927 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1936 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1945 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1954 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1963 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1972 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1981 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1990 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1999 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2008 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2017 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2026 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2035 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2044 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2053 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2062 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2071 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2080 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2089 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2098 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2107 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2116 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2125 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2134 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2143 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2152 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2161 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2170 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2179 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2188 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2197 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2206 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2215 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2224 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2233 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2242 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2251 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2260 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2269 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2278 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2287 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2296 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2305 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2314 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2323 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2332 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 899 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
<<<<<<< TREE
#line 2328 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2337 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2346 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2355 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2364 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2373 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2382 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2391 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2400 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2409 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2418 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2427 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2436 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2445 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2454 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2463 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2472 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2481 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2490 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2499 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2508 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2517 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2526 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2535 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 610: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2544 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 611: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2553 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 612: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2562 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 616: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2571 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 619: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2580 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2589 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 624: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2598 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 625: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2607 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 626: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2616 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 627: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2625 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 628: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2634 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 629: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2643 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 630: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2652 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 631: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2661 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 632: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2670 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 633: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2679 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 634: /* "JSONSimpleObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2688 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 635: /* "JSONAccumulatorObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2697 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 636: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2706 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 637: /* "JSONPairList" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2715 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 638: /* "JSONInsertExpr" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2724 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 639: /* "JSONAppendExpr" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2733 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 640: /* "JSONDeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2742 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 641: /* "JSONRenameExpr" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2751 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 642: /* "JSONReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2760 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 649: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2769 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 650: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2778 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 651: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2787 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
=======
#line 2341 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2350 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2359 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2368 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2377 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2386 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2395 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2404 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2413 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2422 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2431 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2440 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2449 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2458 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2467 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2476 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2485 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2494 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2503 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2512 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2521 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2530 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2539 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2548 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2557 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2566 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2575 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2584 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 611: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2593 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 612: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2602 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 616: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2611 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 617: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2620 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 618: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2629 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 619: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2638 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2647 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 621: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2656 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 622: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2665 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 623: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2674 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 624: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2683 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 627: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2692 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 628: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2701 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 629: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2710 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
>>>>>>> MERGE-SOURCE
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
    
<<<<<<< TREE
/* Line 553 of lalr1.cc  */
#line 140 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 565 of lalr1.cc  */
#line 140 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

<<<<<<< TREE
/* Line 553 of lalr1.cc  */
#line 2872 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
=======
/* Line 565 of lalr1.cc  */
#line 2807 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
>>>>>>> MERGE-SOURCE

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

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1036 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 996 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1045 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1005 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 5:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1054 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1014 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 6:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1060 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1020 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 7:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1068 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1028 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 8:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1074 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1034 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 9:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1085 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1045 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 10:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1090 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1050 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 11:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1098 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1058 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 12:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1105 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1065 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 13:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1112 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1072 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 14:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1121 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1081 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 15:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1128 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1088 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 16:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1136 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1096 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 17:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1144 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1104 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 18:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1152 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1112 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 19:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1163 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1123 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 20:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1168 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1128 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 21:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1175 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1135 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 22:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1182 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1142 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 23:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1194 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1154 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 24:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1204 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1164 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 25:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1211 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1171 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 26:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1218 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1178 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      // error
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 40:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1253 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1213 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 41:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1258 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1218 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 42:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1266 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1226 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 43:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1274 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1234 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 44:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1282 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1242 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 45:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1287 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1247 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 46:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1295 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1255 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 47:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1300 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1260 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 48:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1308 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1268 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 49:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1313 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1273 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 50:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1321 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1281 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 51:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1328 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1288 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 52:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1335 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1295 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 53:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1342 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1302 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 56:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1357 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1317 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 57:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1367 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1327 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 58:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1372 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1332 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 59:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1380 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1340 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 60:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1388 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1348 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 61:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1399 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1359 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 62:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1406 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1366 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 63:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1417 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1377 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 64:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1422 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1382 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 65:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1430 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1390 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 66:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1437 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1397 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 67:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1444 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1404 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 68:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1453 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1413 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(8) - (4)].sval)),
                            SYMTAB((yysemantic_stack_[(8) - (6)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
    }
    break;

  case 69:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1466 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1426 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 70:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1474 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1434 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 71:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1481 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1441 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 72:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1491 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1451 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 73:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1498 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1458 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 74:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1505 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1465 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 83:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1528 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1488 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 84:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1534 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1494 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 85:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1543 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1503 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 86:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1550 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1510 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 87:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1560 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1520 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 88:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1569 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1529 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 89:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1570 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1530 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.strval) = "digit"; }
    break;

  case 90:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1571 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1531 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 91:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1572 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1532 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.strval) = "infinty"; }
    break;

  case 92:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1573 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1533 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.strval) = "minus-sign"; }
    break;

  case 93:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1574 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1534 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.strval) = "NaN"; }
    break;

  case 94:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1575 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1535 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 95:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1576 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1536 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.strval) = "percent"; }
    break;

  case 96:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1577 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1537 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.strval) = "per-mille"; }
    break;

  case 97:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1578 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1538 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.strval) = "zero-digit"; }
    break;

  case 98:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1584 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1544 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 99:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1592 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1552 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 100:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1600 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1560 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 101:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1608 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1568 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 102:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1615 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1575 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 103:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1623 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1583 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 104:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1630 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1590 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 105:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1635 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1595 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 106:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1643 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1603 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 107:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1651 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1611 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1666 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1626 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1681 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1641 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1699 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1659 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 111:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1704 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1664 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 112:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1712 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1672 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 113:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1720 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1680 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 114:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1731 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1691 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 115:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1736 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1696 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 116:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1745 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1705 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 117:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1750 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1710 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 118:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1757 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1717 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 119:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1762 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1722 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 120:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1772 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1732 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 121:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1777 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1737 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 122:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1786 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1746 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 123:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1792 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1752 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 124:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1805 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1765 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 125:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1810 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1770 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 126:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1818 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1778 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1829 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1789 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1844 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1804 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1856 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1816 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1871 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1831 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 131:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1876 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1836 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 132:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1881 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1841 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 133:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1886 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1846 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 134:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1894 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1854 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 135:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1901 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1861 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 136:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1872 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 137:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1877 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 138:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1927 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1887 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL);
    }
    break;

  case 139:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1934 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1894 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 140:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1941 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1901 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)),
                               0);
    }
    break;

  case 141:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1948 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1908 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 142:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1958 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1918 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 143:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1962 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1922 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 144:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1972 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1932 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                             (yysemantic_stack_[(8) - (6)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                             NULL);
    }
    break;

  case 145:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1980 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1940 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(9) - (4)].expr)),
                             (yysemantic_stack_[(9) - (7)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(9) - (9)].node)),
                             static_cast<AnnotationListParsenode*>((yysemantic_stack_[(9) - (2)].node)));
    }
    break;

  case 146:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1991 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1951 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 147:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 1997 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1957 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 148:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2006 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1966 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 149:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2011 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1971 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 150:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2018 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1978 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 151:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2025 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1985 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 152:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2037 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 1997 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 153:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2047 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2007 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 154:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2057 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2017 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 155:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2068 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2028 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

  case 156:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2084 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2044 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

  case 157:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2104 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2064 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 158:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2108 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2069 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 159:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2112 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2073 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 160:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2120 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2081 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 161:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2124 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2086 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 162:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2128 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2090 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 163:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2136 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2098 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2141 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2103 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 165:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2153 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2115 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 166:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2160 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2122 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 179:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2189 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2151 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 180:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2194 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2156 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 181:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2202 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2164 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

  case 182:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2219 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2181 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 183:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2227 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2189 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 184:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2235 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2197 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 185:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2242 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2204 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 186:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2249 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2211 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 187:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2259 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2221 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

  case 188:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2271 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2233 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

  case 189:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2284 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2246 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

  case 190:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2296 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2258 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

  case 191:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2312 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2274 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 192:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2320 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2282 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 193:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2328 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2290 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 194:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2336 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2298 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

  case 195:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2351 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2313 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 196:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2356 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2318 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 197:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2364 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2326 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

  case 198:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2378 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2340 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

  case 199:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2395 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2357 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

  case 200:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2420 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2382 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 201:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2428 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2390 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 202:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2435 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2397 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 203:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2446 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2408 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 204:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2456 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2418 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 205:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2461 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2423 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

  case 224:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2506 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2461 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

  case 225:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2520 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2475 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 226:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2528 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2483 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 227:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2533 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2488 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 228:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2541 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2496 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 229:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2546 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2501 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 230:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2551 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2506 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 231:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2559 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2514 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)),
                            (yysemantic_stack_[(4) - (4)].expr),
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 232:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2568 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2523 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            NULL,
                            (yysemantic_stack_[(3) - (3)].expr),
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 233:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2580 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2535 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

  case 234:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2590 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2545 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 235:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2603 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2558 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 244:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2627 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2582 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 245:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2634 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2589 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 246:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2644 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2599 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 247:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2652 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2607 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 248:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2659 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2614 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 249:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2669 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2624 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

  case 250:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2679 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2634 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

  case 251:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2689 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2644 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

  case 252:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2699 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2654 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

  case 253:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2709 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2664 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

  case 254:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2719 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2674 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

  case 255:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2729 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2684 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

  case 256:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2739 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2694 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

  case 257:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2750 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2705 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 258:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2759 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2714 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

  case 259:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2769 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2724 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

  case 260:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2779 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2734 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

  case 261:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2795 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2750 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 262:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2804 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2759 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 263:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2813 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2768 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 264:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2821 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2776 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 265:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2827 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2782 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 266:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2839 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2794 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 267:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2847 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2802 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 268:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2857 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2812 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 269:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2865 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2820 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 270:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2877 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2832 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 271:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2883 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2838 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 273:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2896 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2851 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 274:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2900 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2855 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 275:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2908 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2863 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 276:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2867 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 278:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2876 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 279:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2925 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2880 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 280:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2929 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2884 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 281:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2939 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2894 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 282:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2947 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2902 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 283:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2954 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2909 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 284:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2960 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2915 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 285:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2971 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2926 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 286:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2975 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2930 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 287:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2984 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2939 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 288:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2992 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2947 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 289:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 2998 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2953 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 290:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3008 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2963 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 291:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3014 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2969 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 292:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3024 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2979 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 293:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3028 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2983 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 294:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3038 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2993 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 295:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3044 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 2999 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 296:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3050 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3005 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 297:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3056 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3011 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 298:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3065 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3020 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 299:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3074 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3029 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 300:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3083 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3038 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 301:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3096 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3051 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 302:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3100 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3055 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 303:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3108 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3063 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 304:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3114 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3069 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 305:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3124 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3079 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 306:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3132 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3087 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 307:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3141 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3096 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 308:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3154 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3109 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 309:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3161 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3116 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 310:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3173 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3128 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 311:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3177 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3132 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

<<<<<<< TREE
=======
  case 307:

/* Line 690 of lalr1.cc  */
#line 3144 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 3151 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 3157 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 3166 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 3173 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

>>>>>>> MERGE-SOURCE
  case 312:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3189 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3179 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 313:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3196 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3190 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 314:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3202 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3197 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 315:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3211 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3203 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 316:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3218 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3212 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 317:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3224 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3221 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 318:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3235 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3228 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 319:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3242 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3239 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 320:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3248 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3246 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 321:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3257 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3258 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 322:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3266 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3264 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 323:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3273 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3276 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 324:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3284 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3282 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 325:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3291 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3293 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 326:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3303 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3299 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 327:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3309 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3310 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 328:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3321 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3316 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 329:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3327 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3327 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 330:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3338 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3336 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 331:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3344 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3340 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 332:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3355 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3349 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 333:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3361 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3353 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 334:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3372 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3361 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 335:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3381 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3385 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3394 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3398 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3406 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3410 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3365 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

  case 341:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3420 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3375 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 342:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3427 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3382 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 343:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3436 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3391 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 344:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3445 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3400 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 345:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3450 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3405 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 346:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3459 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3414 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 347:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3468 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3423 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 348:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3477 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3432 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 349:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3490 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3445 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 350:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3494 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3449 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

<<<<<<< TREE
=======
  case 346:

/* Line 690 of lalr1.cc  */
#line 3461 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 3465 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 3472 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 3476 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 3483 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

>>>>>>> MERGE-SOURCE
  case 351:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3506 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3487 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 352:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3510 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3496 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 353:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3517 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3500 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = NULL;
        }
    break;

  case 354:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3521 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3504 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 355:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3528 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3513 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 356:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3532 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3517 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 357:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3541 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3523 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 358:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3545 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3529 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 359:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3549 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3535 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 360:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3557 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3546 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 361:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3561 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3550 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 362:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3567 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3554 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 363:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3573 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3562 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 364:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3579 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3566 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 365:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3589 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3572 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 366:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3593 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3582 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 367:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3597 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3586 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 368:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3605 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3596 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 369:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3609 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3600 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 370:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3615 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3610 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 371:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3625 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3614 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 372:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3629 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3624 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 373:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3639 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3628 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 374:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3643 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3638 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 375:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3653 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3642 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 376:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3657 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3650 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 377:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3667 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3654 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 378:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3671 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3658 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 379:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3681 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3662 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 380:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3685 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3672 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 381:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3693 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3676 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 382:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3697 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3680 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 383:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3701 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3705 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3715 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3719 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3723 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3731 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3688 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 389:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3735 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3692 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 390:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3739 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3696 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 391:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3743 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3700 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 392:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3747 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3704 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 393:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3751 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3708 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 394:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3759 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3716 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 395:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3763 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3720 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 396:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3767 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3724 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 397:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3775 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3732 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 398:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3779 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3736 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 399:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3783 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3740 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 400:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3787 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3744 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 401:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3798 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3755 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 402:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3804 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3761 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 403:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3814 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3771 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 404:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3820 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3777 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 405:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3830 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3787 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 406:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3834 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3791 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 407:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3838 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3795 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 408:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3876 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3833 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 409:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3880 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3837 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 410:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3890 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3847 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 411:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3900 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3857 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 412:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3913 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3870 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = NULL;
    }
    break;

  case 413:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3922 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3879 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      AxisStep* as = dynamic_cast<AxisStep*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (as ?
            new RelativePathExpr(LOC((yyloc)),
                                 ParseConstants::st_slash,
                                 new ContextItemExpr( LOC((yyloc)), true ), (yysemantic_stack_[(1) - (1)].expr), true)
            :
            (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

<<<<<<< TREE
=======
  case 409:

/* Line 690 of lalr1.cc  */
#line 3889 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 3893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 3902 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 3906 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 3915 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

>>>>>>> MERGE-SOURCE
  case 414:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3932 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3921 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 415:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3936 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3929 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 416:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3945 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3935 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 417:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3949 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3947 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 418:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3958 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3953 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 419:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3964 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3963 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 420:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3972 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3967 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 421:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3978 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3971 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 422:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3990 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3975 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 423:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 3996 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3979 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 424:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4006 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3985 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 425:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4010 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3991 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 426:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4014 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 3999 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 427:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4018 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4003 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 428:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4022 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4011 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 429:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4028 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4015 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 430:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4034 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4026 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 431:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4042 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4030 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 432:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4046 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4034 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 433:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4054 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4040 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 434:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4058 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4044 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 435:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4069 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4058 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 436:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4073 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4062 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 437:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4077 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4070 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 438:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4083 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4074 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 439:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4087 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4084 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 440:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4101 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4088 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 441:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4105 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4092 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 442:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4113 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4096 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 443:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4117 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4105 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 444:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4127 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4109 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 445:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4131 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4113 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 446:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4135 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4117 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 447:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4139 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4125 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 448:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4148 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4131 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 449:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4152 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4141 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 450:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4156 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4149 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 451:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4160 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4153 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 452:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4168 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4157 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 453:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4174 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4161 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 454:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4184 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4165 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 455:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4192 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4169 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 456:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4196 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4173 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 457:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4200 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4177 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 458:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4204 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4181 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 459:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4208 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4191 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 460:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4212 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4199 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 461:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4216 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4203 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 462:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4220 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4224 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4228 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4233 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4237 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4241 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4245 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4253 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4257 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4265 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4211 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 472:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4272 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4218 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 473:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4279 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4225 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 474:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4290 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4236 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 475:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4298 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4244 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 476:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4302 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4248 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 477:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4310 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4256 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 478:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4318 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4264 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 479:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4326 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4272 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 480:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4380 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4326 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 481:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4384 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4330 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 482:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4397 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4343 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 483:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4403 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4349 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

<<<<<<< TREE
  case 484:

/* Line 678 of lalr1.cc  */
#line 4413 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4417 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4425 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4429 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4433 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4441 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
  case 475:

/* Line 690 of lalr1.cc  */
#line 4359 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 4363 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 4371 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 4375 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 4379 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 4387 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

  case 490:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4451 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4397 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

  case 491:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4461 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4407 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

  case 492:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4471 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4417 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

  case 493:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4481 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4427 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

  case 494:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4491 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4437 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

  case 495:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4506 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4452 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 496:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4512 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4458 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 497:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4523 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4469 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 498:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4529 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4475 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 499:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4540 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4486 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 502:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4557 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4503 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 503:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4562 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4508 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 504:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4571 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4517 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 505:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4575 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4521 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 506:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4582 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4528 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 507:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4588 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4534 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 508:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4594 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4540 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 509:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4602 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4548 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 510:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4614 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4560 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 511:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4618 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4564 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 512:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4625 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4571 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 513:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4631 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4577 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 514:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4637 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4583 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 515:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4644 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4590 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 516:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4655 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4601 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 517:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4659 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4605 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 518:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4669 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4615 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 519:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4673 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4619 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 520:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4683 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4629 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 521:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4687 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4633 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 522:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4691 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4637 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 523:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4696 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4642 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 524:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4705 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4651 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 525:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4711 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4657 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 526:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4717 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4663 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 527:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4723 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4669 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
        }
    break;

  case 528:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4731 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4677 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 529:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4736 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4682 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 530:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4744 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4690 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 531:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4749 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4695 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 532:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4757 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4703 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

<<<<<<< TREE
=======
  case 524:

/* Line 690 of lalr1.cc  */
#line 4711 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 4716 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 4721 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 4726 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 4731 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 4736 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 4745 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 4753 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 4757 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

>>>>>>> MERGE-SOURCE
  case 533:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4765 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4774 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 534:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4770 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4778 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 535:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4775 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4786 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 536:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4780 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4794 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 537:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4785 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4802 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 538:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4790 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4806 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 539:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4799 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4814 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 540:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4807 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4820 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 541:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4811 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4830 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 542:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4828 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4838 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 543:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4832 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4842 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 544:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4840 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4846 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 545:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4848 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4881 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 546:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4856 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4887 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 547:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4860 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 548:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4868 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4903 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 549:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4874 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4907 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 550:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4884 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4911 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 551:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4892 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4915 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 552:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4896 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4919 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 553:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4900 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4926 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 554:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4935 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4932 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 555:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4941 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4942 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 556:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4947 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4950 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 557:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4957 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4954 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 558:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4961 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4958 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 559:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4965 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4962 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 560:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4969 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4966 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 561:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4973 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4970 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 562:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4977 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4974 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 563:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4981 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4978 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 564:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4988 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4982 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 565:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 4994 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4990 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 566:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5004 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 4998 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 567:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5012 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5002 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 568:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5016 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5006 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 569:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5020 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5016 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 570:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5024 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5024 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 571:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5028 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5032 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 572:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5032 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5036 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 573:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5036 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5040 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 574:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5040 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5048 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 575:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5044 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5052 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 576:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5052 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5058 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 577:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5060 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5064 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 578:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5064 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5068 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 579:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5068 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5078 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 580:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5078 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5086 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 581:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5086 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5090 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 582:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5094 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5096 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 583:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5098 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5105 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 584:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5102 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5114 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 585:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5110 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5120 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 586:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5114 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5126 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 587:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5120 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5136 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 588:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5126 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5153 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 589:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5130 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5160 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 590:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5140 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5175 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 591:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5148 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5211 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 592:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5152 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5215 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 593:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5158 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5223 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 594:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5167 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5231 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 595:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5176 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5243 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 596:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5182 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5247 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 597:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5188 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5255 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 598:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5198 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5263 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 599:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5215 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5267 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 600:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5222 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5278 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 601:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5237 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5295 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 602:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5273 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5301 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 603:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5277 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5307 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 604:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5285 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5317 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 605:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5293 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5321 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 606:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5305 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5327 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 607:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5309 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5333 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 608:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5317 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5337 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 609:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5325 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5343 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 610:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5329 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5347 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 611:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5340 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5353 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 612:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5357 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5359 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 613:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5363 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5366 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 614:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5369 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5376 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 615:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5379 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5381 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 616:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5383 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5389 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5395 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5399 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5405 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5409 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5415 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5421 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5428 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5438 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5443 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5451 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5389 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 628:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5457 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5395 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 629:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5467 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5405 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 630:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5489 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5427 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 631:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5498 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5436 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 632:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5504 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5442 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 633:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5517 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5455 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 634:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5531 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5469 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 635:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5538 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5476 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 636:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5544 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5482 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 637:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5554 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5492 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 638:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5563 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5501 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 639:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5571 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5509 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 640:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5577 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5515 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 641:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5595 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5533 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 642:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5603 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5541 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 643:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5607 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5545 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 644:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5614 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5552 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 645:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5619 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5557 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 646:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5627 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5565 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 647:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5631 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5569 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 648:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5638 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5576 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 649:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5642 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5580 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 650:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5649 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5587 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 651:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5653 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5591 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 652:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5660 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5598 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 653:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5664 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5602 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 654:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5673 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5611 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

<<<<<<< TREE
=======
  case 644:

/* Line 690 of lalr1.cc  */
#line 5623 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 5627 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 5634 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 5638 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 5646 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 5654 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 5662 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 5666 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 5673 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 5677 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 5685 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

>>>>>>> MERGE-SOURCE
  case 655:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5685 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5696 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = NULL;
        }
    break;

  case 656:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5689 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5700 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 657:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5696 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5708 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = NULL;
        }
    break;

  case 658:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5700 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5720 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 659:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5708 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5726 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 660:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5716 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5735 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 661:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5724 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5739 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 662:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5728 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5747 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 663:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5735 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5751 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = NULL;
        }
    break;

  case 664:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5739 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5755 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 665:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5747 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5762 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 666:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5758 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5766 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = NULL;
        }
    break;

  case 667:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5762 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5773 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 668:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5770 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5777 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 669:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5782 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5785 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 670:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5788 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5789 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 671:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5797 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5793 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 672:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5801 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5797 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 673:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5809 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5801 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 674:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5813 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5809 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 675:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5817 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5817 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 676:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5824 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5829 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 677:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5828 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5841 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 678:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5835 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5845 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 679:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5839 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5849 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 680:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5847 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5857 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 681:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5851 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5863 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 682:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5855 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5873 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 683:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5859 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5877 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 684:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5863 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5881 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 685:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5871 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5885 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 686:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5879 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5889 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 687:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5891 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5893 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 688:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5903 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5897 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 689:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5907 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5901 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 690:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5911 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5919 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5925 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5935 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5939 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5943 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5947 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5951 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5955 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5959 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5963 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 5971 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5909 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 702:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5975 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5913 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 703:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5979 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5917 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 704:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5983 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5921 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 705:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5991 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5929 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 706:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 5997 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5935 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 707:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6007 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5945 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 708:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6017 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5955 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 709:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6021 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5959 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 710:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6029 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5967 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

  case 711:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6039 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5977 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

  case 712:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6050 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5988 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 713:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6057 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5995 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 714:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6061 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 5999 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = NULL;
        }
    break;

  case 715:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6068 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6006 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 716:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6072 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6010 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 717:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6079 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6017 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 718:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6084 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6022 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 719:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6093 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6031 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 720:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6102 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6040 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.sval) = NULL;
        }
    break;

  case 721:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6106 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6044 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 722:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6113 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6051 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = NULL;
        }
    break;

  case 723:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6117 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6055 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 724:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6125 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6063 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 725:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6134 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6072 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 726:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6141 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6079 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 727:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6151 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6089 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 728:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6155 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6093 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 729:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6162 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6100 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 730:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6168 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6106 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 731:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6177 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6115 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 732:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6181 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6119 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 733:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6188 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6126 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 734:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6193 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6131 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 735:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6205 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6143 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 736:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6213 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6151 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 737:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6225 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6163 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 738:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6233 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6171 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 739:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6237 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6175 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 740:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6245 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6183 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 741:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6249 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6187 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 742:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6253 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6191 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 743:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6261 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6199 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 744:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6269 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6207 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 745:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6273 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6211 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 746:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6277 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6215 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 747:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6281 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6219 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 748:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6289 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6227 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 749:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6297 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6235 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 750:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6309 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6247 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 751:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6313 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6251 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 752:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6321 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6259 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

<<<<<<< TREE
  case 753:

/* Line 678 of lalr1.cc  */
#line 6335 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 6339 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 6346 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 6351 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 6359 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 6364 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 6373 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 6381 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 6387 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 6397 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        static_cast<JSONPairList*>((yysemantic_stack_[(5) - (3)].node)),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 6403 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 6410 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 6417 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONDeleteExpr(LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), (yysemantic_stack_[(6) - (5)].expr));
        }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 6424 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONRenameExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 6431 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONReplaceExpr(LOC((yyloc)), (yysemantic_stack_[(10) - (5)].expr), (yysemantic_stack_[(10) - (7)].expr), (yysemantic_stack_[(10) - (10)].expr));
        }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 6438 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 6442 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 6446 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 6453 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 6460 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 6467 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 6484 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
  case 744:

/* Line 690 of lalr1.cc  */
#line 6277 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
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

  case 778:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6497 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6290 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 779:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6498 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6291 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 780:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6499 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6292 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 781:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6500 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6293 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 782:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6501 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6294 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 783:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6502 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6295 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 784:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6503 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6296 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 785:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6504 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6297 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 786:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6505 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6298 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 787:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6506 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6299 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 788:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6507 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6300 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 789:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6508 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6301 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 790:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6509 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6302 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 791:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6510 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6303 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 792:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6511 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6304 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 794:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6516 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6309 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 795:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6517 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6310 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 796:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6518 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6311 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 797:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6519 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6312 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 798:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6520 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6313 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 799:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6521 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6314 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 800:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6522 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6315 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 801:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6523 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6316 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 802:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6524 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6317 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 803:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6525 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6318 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 804:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6526 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6319 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 805:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6527 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6320 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 806:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6528 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6321 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 807:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6529 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6322 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 808:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6530 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6323 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 809:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6531 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6324 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 810:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6532 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6325 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 811:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6533 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6326 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 812:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6534 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6327 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 813:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6535 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6328 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 814:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6536 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6329 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 815:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6537 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6330 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 816:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6538 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6331 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 817:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6539 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6332 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 818:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6540 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6333 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 819:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6541 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6334 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 820:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6542 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6335 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 821:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6543 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6336 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 822:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6544 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6337 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 823:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6545 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6338 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 824:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6546 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6339 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 825:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6547 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6340 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 826:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6548 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6341 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 827:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6549 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6342 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 828:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6550 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6343 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 829:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6551 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6344 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 830:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6552 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6345 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 831:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6553 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6346 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 832:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6554 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6347 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 833:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6555 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6348 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 834:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6556 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6349 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 835:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6557 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6350 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 836:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6558 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6351 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 837:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6559 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6352 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 838:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6560 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6353 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 839:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6561 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6354 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 840:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6562 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6355 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 841:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6563 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6356 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 842:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6564 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6357 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 843:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6565 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6358 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 844:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6566 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6359 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 845:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6567 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6360 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 846:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6568 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6361 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 847:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6569 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6362 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 848:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6570 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6363 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 849:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6571 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6364 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 850:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6572 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6365 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 851:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6573 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6366 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 852:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6574 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6367 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 853:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6575 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6368 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 854:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6576 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6369 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 855:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6577 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6370 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 856:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6578 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6371 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 857:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6579 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6372 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 858:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6580 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6373 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 859:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6581 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6374 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 860:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6582 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6375 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 861:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6583 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6376 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 862:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6584 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6377 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 863:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6585 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6378 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 864:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6586 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6379 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 865:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6587 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6380 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 866:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6588 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6381 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 867:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6589 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6382 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 868:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6590 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6383 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 869:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6591 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6384 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 870:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6592 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6385 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 871:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6593 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6386 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 872:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6594 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6387 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 873:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6595 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6388 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 874:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6596 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6389 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 875:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6597 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6390 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 876:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6598 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6391 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 877:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6599 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6392 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 878:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6600 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6393 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 879:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6601 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6394 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 880:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6602 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6395 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 881:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6603 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6396 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 882:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6604 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6397 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 883:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6605 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6398 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 884:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6606 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6399 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 885:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6607 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6400 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 886:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6608 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6401 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 887:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6609 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6402 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 888:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6610 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6403 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 889:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6611 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6404 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 890:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6612 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6405 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 891:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6613 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6406 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 892:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6614 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6407 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 893:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6615 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6408 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 894:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6616 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6409 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 895:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6617 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6410 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 896:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6618 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6411 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 897:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6619 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6412 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 898:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6620 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6413 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 899:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6621 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6414 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 900:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6622 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6415 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 901:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6623 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6416 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 902:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6624 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6417 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 903:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6625 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6418 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 904:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6626 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6419 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 905:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6627 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6420 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 906:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6628 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6421 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 907:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6629 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6422 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 908:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6630 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6423 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 909:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6631 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6424 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 910:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6632 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6425 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 911:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6633 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6426 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 912:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6634 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6427 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 913:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6635 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6428 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 914:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6636 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6429 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 915:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6637 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6430 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 916:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6638 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6431 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 917:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6639 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6432 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 918:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6640 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6433 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 919:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6641 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6434 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 920:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6642 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6435 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 921:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6643 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6436 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 922:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6644 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6437 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 923:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6645 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6438 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 924:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6646 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6439 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 925:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6647 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6440 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 926:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6648 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6441 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 927:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6649 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6442 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 928:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6650 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6443 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 929:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6651 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6444 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 930:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6652 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6445 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 931:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6653 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6446 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 932:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6654 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6447 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 933:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6655 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6448 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 934:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6656 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6449 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 935:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6657 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6450 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 936:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6658 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6451 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 937:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6659 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6452 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 938:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6660 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6453 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 939:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6661 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6454 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 940:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6662 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6455 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 941:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6663 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6456 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 942:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6664 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6457 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 943:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6665 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6458 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 944:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6666 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6459 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 945:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6667 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6460 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 946:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6668 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6461 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 947:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6669 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6462 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 948:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6670 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6463 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 949:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6671 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6464 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 950:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6672 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6465 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 951:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6673 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6466 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 952:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6674 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6467 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 953:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6675 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6468 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 954:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6676 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6469 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 955:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6677 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6470 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 956:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6678 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6471 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 957:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6679 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6472 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 958:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6680 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6473 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 959:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6681 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6474 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 960:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6682 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6475 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 961:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6683 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6476 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 962:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6684 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6477 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 963:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6685 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6478 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 964:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6686 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6479 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 965:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6687 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6480 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 966:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6688 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6481 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 967:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6689 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6482 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 968:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6690 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6483 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 969:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6691 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6484 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 970:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6692 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6485 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 971:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6693 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6486 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 972:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6694 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6487 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 973:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6695 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6488 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 974:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6696 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6489 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 975:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6697 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6490 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 976:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6698 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6491 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 977:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6699 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6492 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 978:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6700 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6493 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 979:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6701 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6494 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 980:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6702 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6495 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 981:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6703 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6496 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 982:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6704 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6497 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 983:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6705 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6498 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 984:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6706 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6499 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 985:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6707 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6500 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 986:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6708 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6501 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 987:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6709 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6502 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 988:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6710 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6503 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 989:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6711 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6504 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 990:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6712 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6505 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 991:

<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 6713 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 690 of lalr1.cc  */
#line 6506 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

<<<<<<< TREE
  case 992:

/* Line 678 of lalr1.cc  */
#line 6714 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 993:

/* Line 678 of lalr1.cc  */
#line 6715 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 994:

/* Line 678 of lalr1.cc  */
#line 6716 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 995:

/* Line 678 of lalr1.cc  */
#line 6717 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 996:

/* Line 678 of lalr1.cc  */
#line 6718 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 997:

/* Line 678 of lalr1.cc  */
#line 6719 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 998:

/* Line 678 of lalr1.cc  */
#line 6720 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 999:

/* Line 678 of lalr1.cc  */
#line 6725 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
  case 960:

/* Line 690 of lalr1.cc  */
#line 6512 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
    {
          // EQName's namespace URI value is whitespace normalized according to the rules for the xs:anyURI type
          std::string uri = "\"" + SYMTAB((yysemantic_stack_[(3) - (1)].sval)) + "\"";
          std::string eqname = SYMTAB(driver.symtab.put_uri(uri.c_str(), uri.size())) + ":" + SYMTAB((yysemantic_stack_[(3) - (3)].sval));
          (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT(eqname.c_str())), true);
        }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 6518 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



<<<<<<< TREE
/* Line 678 of lalr1.cc  */
#line 11921 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
=======
/* Line 690 of lalr1.cc  */
#line 11564 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"
>>>>>>> MERGE-SOURCE
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
  const short int xquery_parser::yypact_ninf_ = -1450;
  const short int
  xquery_parser::yypact_[] =
  {
      3140, -1450, -1450, -1450,  4686,  4686,  4686, -1450, -1450,    -3,
      23, -1450,    58,    -4, -1450, -1450, -1450,   333, -1450, -1450,
   -1450,    48,   201,   647,   611,   207,   482,   150, -1450,   -29,
   -1450, -1450, -1450, -1450, -1450, -1450,   672, -1450,   541,   591,
   -1450, -1450, -1450, -1450,   633, -1450,   758, -1450,   707,   739,
   -1450,   101, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450,   702,   757, -1450, -1450,
   -1450, -1450,   511, 10557, -1450, -1450, -1450,   777, -1450, -1450,
   -1450,   787, -1450,   800,   803, -1450, -1450, 14642, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450,   810, -1450, -1450,   808,
     831, -1450, -1450, -1450, -1450, -1450, -1450, -1450,  3450,  6540,
    6849, 14642, -1450, -1450, -1450, -1450, -1450, -1450, -1450,   806,
   -1450, -1450,   846, 11449, -1450, 11751,   849,   856, -1450, -1450,
   -1450,   863, -1450,  9939, -1450, -1450, -1450, -1450, -1450, -1450,
     834, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,    71,
     771, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,   -76,
     832,   -33, -1450,     7,   -56, -1450, -1450, -1450, -1450, -1450,
   -1450,   871, -1450,   750,   751,   752, -1450, -1450,   838,   839,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450,  7158,  7467, -1450,   682, -1450, -1450, -1450,
   -1450, -1450,  4995,   998, -1450,  5304, -1450, -1450,   717,    80,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450,    82, -1450, -1450, -1450, -1450, -1450,
   -1450,   305, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
    4686, -1450, -1450, -1450, -1450,   216, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450,   892, -1450,   811, -1450, -1450, -1450,
     398, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,   835,
     908, -1450,   729,   755,   905,   476,   537,   621,   668, -1450,
     955,   809,   906,   907,  8703, -1450, -1450, -1450,   176, -1450,
   -1450, 10248, -1450,   756, -1450,   858, 10557, -1450,   858, 10557,
   -1450, -1450, -1450,   551, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450,   865,   855, -1450, -1450, -1450,
   -1450, -1450,   829, -1450,  4686,   830,   837,   475,   475,   986,
     173,   574,   588, 14929, 14642,   -15,   970, 14642,   866,   901,
     356, 11449,   735,   778, 14642, 14642,   721,   422,    53, -1450,
   -1450, -1450, 11449,  4686,   840,  4686,   110,  9012, 12633,   742,
     743, 14642,   904,     1,   875,  9012,  1028,    59,   196, 14642,
     913,   890,   926, -1450,  9012, 11153, 14642, 14642, 14642,  4686,
     847,  9012,  9012, 14642,  4686,   882,   883, -1450, -1450, -1450,
    9012, 12920,   884, -1450,   885, -1450, -1450, -1450, -1450,   886,
   -1450,   887, -1450, -1450, -1450, -1450, -1450,   891, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, 14642, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,   896,
   14642, -1450, -1450, -1450,   862,  3759,   918,   258,   893,   894,
     895, 14642,  4686, -1450,   899,   287, -1450,   547, -1450,    27,
    1013,  9012, -1450, -1450,   141, -1450, -1450, -1450,  1036, -1450,
   -1450, -1450, -1450,  9012,   841, -1450,  1032,  9012,  9012, 12050,
     870,  9012,  9012,  9012,  9012, 12050,  9012,   842,   844, 14642,
     872,   873,  9012,  9012,  3450,   821, -1450,   -43, -1450,   -65,
    9012, -1450, -1450, -1450, -1450,    58,   150,   105,   106,  1065,
    5613,  5613,  5922,  5922,   787, -1450, -1450,   892,   787, -1450,
    9012, -1450,   951,   611,   -29,   903,   909,   910,  4686,  9012,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,  9321,  9321,
    9321, -1450,  9321,  9321, -1450,  9321, -1450,  9321, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450,  9321,  9321,  1004,  9321,  9321,
    9321,  9321,  9321,  9321,  9321,  9321,  9321,  9321,  9321,  9321,
     845,   982,   983,   984, -1450, -1450, -1450,  7776, -1450, -1450,
    9939,  9939,  9012,   858, -1450, -1450,   858, -1450,  8085,   858,
     932,  8394, -1450, -1450, -1450,   151, -1450,   210, -1450, -1450,
   -1450, -1450, -1450, -1450,   975,   978,   207,  1058, -1450, -1450,
   14929,   857,   389, 14642,   929,   930,   857,   986,   964,   961,
   -1450, -1450, -1450,   133,   850,  1000,   798, 14642,   956,  9012,
     979, 14642, 14642, -1450,   971,   920,  4686, -1450,   921,   885,
     591, -1450,   915,   919,   280, -1450,   220,   221, -1450, -1450,
    1003, -1450,    34, 14642,    16, 14642,  1017,   319, -1450,  4686,
   -1450,   378, -1450, 11449,  1016,  1068, 11449,   986,  1018,    96,
   14642,  9012,   -29,   297,   928, -1450,   934,   935,   936,    28,
   -1450,    51,   942, -1450,   390,   404,   966, -1450,   943,  4686,
    4686,   309, -1450,   421,   430,   318,  9012,   115, -1450, -1450,
    9012,  9012, -1450,  9012,  9012,  9012, -1450,  9012, -1450,  9012,
   -1450, 14642,  1013, -1450,    45,   323, -1450, -1450, -1450,   354,
   -1450,    -8, -1450, -1450,   967,   976,   977,   980,   981,   972,
     865, -1450,   -12,   118,    92,    -5,  1023,   985,   900,   911,
     902,    39, -1450,   989, -1450, -1450,   947,   436,  4068,   461,
   10857,   821, -1450, -1450, -1450,   941,   717,   747,  1107,  1107,
   -1450, -1450,   111, -1450, -1450,   112, -1450,    47, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, 14642,   973,  9012,  1024, -1450,
   -1450, -1450,   908, -1450, -1450, -1450, -1450, -1450,  9321, -1450,
   -1450, -1450,    68, -1450,   537,   537,   344,   621,   621,   621,
     621,   668,   668, -1450, -1450, 14068, 14068, 14642, 14642, -1450,
     481, -1450, -1450,   314, -1450, -1450, -1450,   444, -1450, -1450,
     460,   475, -1450, -1450,   644,   645,   705, -1450,   207, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,   857,
   -1450,  1012, 14355,  1005,  9012, -1450, -1450, -1450,  1051,   986,
     986,   857, -1450,   833,   986,   641, 14642,   634,   636,  1117,
   -1450, -1450,   864,   585, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450,   133,   617,   922,   594,  9012,
   -1450, 14642,  1056,   853,   986, -1450, -1450, -1450, -1450,   999,
   14642, -1450, 14642, -1450,  1037,  1027, 14068,  1038,  9012,   -69,
    1010,    15,   557,   912, -1450, -1450,   650,    16,  1051, 14068,
    1040,  1066,   987,   962,  1029,   986,  1002,  1031,  1070,   986,
    9012,   -32, -1450, -1450, -1450,  1011, -1450, -1450, -1450, -1450,
    1049,  9012,  9012,  1021, -1450,  1069,  1072,  4686, -1450,   990,
     991,  1020, 14642, -1450, 14642, -1450,  9012,  1034,   988,  9012,
   -1450,  1059,   483,   497,   498,  1135, -1450,   237, -1450,    77,
   -1450, -1450,  1148, -1450,  9012,   719,  9012,  9012,  9012,   727,
    9012,  9012,  9012,  9012,  9012,  9012,  9012,  9012,  9012, 12050,
    1061,  9012,  9012, -1450,  6231,  1025,  1030,  1033,  1035,   811,
     648,   939, -1450,   184, -1450,  9012,   117,   126,    47,  5922,
    5922,  5922,  1105, -1450,  9012,   667,  1078, -1450, 14642,  1080,
   -1450, -1450,  9012,    68,   275,   578, -1450,   914,   185,   938,
     931, -1450, -1450,   778, -1450,   925,   496,  1041,  1043, 14355,
    1044,  1045,  1046,  1048,  1050, -1450,   556, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
    1052, -1450, -1450, -1450,  9012, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450,   715, -1450,  1163,   640, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450,   923, -1450, -1450,
    1164, -1450, -1450, -1450, -1450, -1450,   632,  1176, -1450,   699,
   -1450, -1450, -1450,   884,   201,   886,   541,   887,   891,   832,
   -1450,   556,  9630,   927,   916, -1450,  1051,   617,   993,  1019,
    4686,  1039,  1042,  1063,  1047,  1053, 14642,    29, -1450, 14642,
   -1450,  9012,  1067,  9012,  1085,  9012,   -23,  1073,  9012,  1075,
   -1450,  1098,  1099,  9012, 14642,   582,  1146, -1450, -1450, -1450,
   -1450, -1450, -1450, 14068, -1450,  4686,   986,  1118, -1450, -1450,
   -1450,   986,  1118, -1450,  9012,  1082,  4686, 14642, -1450, -1450,
    9012,  9012,   723, -1450,   246,   732, -1450, 13207,   753, -1450,
     760, -1450,  1054, -1450, -1450,  4686,  1055,  1057, -1450,  9012,
   -1450, -1450,  9012,  1060,  1069,  1127, -1450,  1096, -1450,   302,
   -1450, -1450,  1223, -1450, -1450,  4686, 14642, -1450,   563, -1450,
   -1450, -1450,  1062,  1064,  1001,  1007, -1450, -1450, -1450,  1009,
    1014, -1450, -1450, -1450,  1136, -1450, -1450,  1071, -1450,   995,
    1079, 14642,  1074, -1450, -1450,  9012,  9012,  9012,  4377,  6231,
   10857,   939, -1450, 10857, -1450, -1450,  1107,   332, -1450, -1450,
   -1450,  1078, -1450,   986, -1450,   836, -1450,   531,  1130, -1450,
    9012,  1131,  1024,   489,  1076, -1450,    68,   994, -1450, -1450,
     519, -1450,   646,   -20,  1006,    68,   646,  9321, -1450,   119,
   -1450, -1450, -1450, -1450, -1450, -1450,    68,  1100,   968,   850,
     -20, -1450, -1450,   963,  1172, -1450, -1450, -1450, 12346,  1081,
    1083,  1084,  1086,  1087,  1089,  1090, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,  1225,     4,
    1233,     4,   996,  1158, -1450,  1097, 14642,  1022, -1450, -1450,
    9630, -1450,  1088, -1450, -1450, -1450, -1450, -1450, -1450,  9012,
    1122, -1450, -1450,  9012, -1450,   554, -1450,  9012,  1134,  9012,
   -1450,  9012, 14642, 14642, -1450,   695, -1450,  9012, -1450,  1159,
    1160,  1188,   986,  1118, -1450,  9012,  1103, -1450, -1450, -1450,
    1102, -1450,   248,  9012,  4686,  1106,   261, -1450, 14642,  1108,
   13494,   233, -1450, 13781,  1110, -1450, -1450,  1114, -1450, -1450,
   -1450, -1450,  9012,   765,  1135, 14642,   566, -1450,  1115,  1135,
   14642, -1450, -1450, -1450,  9012,  9012,  9012,  9012,   974,  1197,
    9012,  9012, -1450,  9012,   508,   515,   523,   374, -1450, -1450,
   -1450, -1450, -1450,  1130, -1450, -1450, -1450,   986, -1450, -1450,
   -1450, -1450, -1450,  1116,  9321, -1450, -1450, -1450, -1450, -1450,
     240,  9321,  9321,   558, -1450,   938, -1450,   312, -1450,   931,
      68,  1149, -1450, -1450,  1092, -1450, -1450, -1450, -1450,  1207,
    1119, -1450,   534, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450,   361,   361, -1450,     4, -1450, -1450,   535, -1450,  1275,
     -20,  1211,  1123,  9630,     2,  1026,  1139, -1450, -1450,  9012,
   -1450,  9012,  1166, -1450,  9012, -1450, -1450, -1450,  1258, -1450,
   -1450,  6231,  9012,   986, -1450, -1450, -1450,  9012,  9012, -1450,
   -1450, -1450,  6231,  6231,  1220,  4686, 14642,  1129, 14642,  9012,
   14642,  1132,  6231, -1450,   277,    40,  1135, 14642, -1450,  1120,
    1135, -1450, -1450, -1450, -1450,  9012,  9012, -1450,  1133, -1450,
    1125,  1069,  1072,  9012, -1450, -1450, -1450, -1450,   621,  9321,
    9321,   344,   576, -1450, -1450, -1450, -1450, -1450, -1450,  9012,
   -1450, 14068, -1450, 14068,  1229, -1450, -1450, -1450,  1290, -1450,
   -1450, -1450,  1091,  1218, -1450, -1450,  1219, -1450,   761, 14642,
    1209,  1121, 14642,  9630, -1450, -1450,  9012, -1450,  1212, -1450,
   -1450,  1118, -1450, -1450, 14068, -1450, -1450,  1240,  9012,  1152,
   -1450,  1245,  6231, -1450, 14642,   239,   350, -1450,  1144,  1135,
   -1450,  1150, -1450, -1450,  1111,  6231,   774,   525,   344,   344,
    9321,   542, -1450, -1450, 14068, -1450, -1450,  1211,  9630, -1450,
    1130,  1093, 14642,  1230,  1126,  1219, -1450, 14642,  1165, 14068,
    4686, 14068,  1167, -1450, -1450,  1256,   325, -1450, -1450, -1450,
   -1450,  1169,   697, -1450, -1450, -1450,  1162, -1450,  9012,  1236,
   -1450,   344, -1450, -1450, -1450, -1450, -1450,  9012,  1101, 14642,
    1241, -1450,  4686,  1175, -1450, -1450,  1177,  9012, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, 14642, -1450,  1077,  1104,
   14642, -1450, -1450,  9012,  6231,  1179,  1112,  9012,  1113,  6231,
    9630, -1450,  9630, -1450,  1168,  1094, 14642,  1154,  1254, 14642,
    1124,  9630, -1450
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       159,   445,   446,   447,   162,   162,   162,   794,   999,   116,
     118,   601,   886,   895,   835,   799,   797,   779,   887,   890,
     842,   803,   780,   781,   834,   896,   783,   893,   864,   844,
     819,   839,   840,   891,   888,   838,   785,   894,   786,   787,
     935,   947,   934,   836,   855,   849,   788,   837,   790,   789,
     936,   873,   874,   841,   816,   957,   958,   959,   960,   961,
     962,   963,   964,   965,   966,   967,   981,   988,   863,   859,
     850,   830,   778,     0,   858,   866,   875,   982,   854,   471,
     831,   832,   889,   983,   989,   851,   868,     0,   477,   434,
     473,   861,   796,   852,   853,   882,   856,   872,   881,   987,
     990,   802,   843,   884,   472,   871,   877,   782,     0,     0,
       0,     0,   382,   869,   880,   885,   883,   862,   848,   937,
     846,   847,   984,     0,   381,     0,   985,   991,   878,   833,
     857,   986,   412,     0,   444,   879,   860,   867,   876,   870,
     938,   824,   829,   828,   827,   826,   825,   791,   845,     0,
     795,   892,   817,   926,   925,   927,   801,   800,   820,   932,
     784,   924,   929,   930,   921,   823,   865,   923,   933,   931,
     922,   821,   928,   942,   943,   940,   941,   939,   792,   944,
     945,   946,   912,   911,   898,   815,   808,   905,   901,   818,
     814,   913,   914,   804,   805,   798,   807,   910,   909,   906,
     902,   919,   920,   918,   908,   904,   897,   806,   917,   916,
     810,   812,   811,   903,   907,   899,   813,   900,   809,   915,
     968,   969,   970,   971,   972,   973,   949,   950,   948,   954,
     955,   956,   951,   952,   953,   822,   974,   975,   976,   977,
     978,   979,   980,     0,     0,   992,   993,   994,   997,   996,
     995,   998,   159,     0,     2,   159,     5,     7,    19,     0,
      24,    27,    32,    33,    34,    35,    36,    37,    38,    28,
      54,    55,    29,    30,     0,    72,    75,    76,    31,    77,
      78,     0,   114,    79,    80,    81,    82,    14,   156,   157,
     158,   165,   167,   464,   168,     0,   169,   170,   171,   172,
     173,   174,   175,   178,   163,   204,   211,   206,   238,   244,
       0,   236,   237,   213,   207,   177,   208,   176,   209,   212,
     335,   337,   339,   349,   351,   355,   357,   360,   365,   368,
     371,   373,   375,   377,     0,   379,   385,   387,     0,   403,
     386,   408,   411,   413,   416,   418,     0,   423,   420,     0,
     431,   441,   443,   417,   448,   455,   469,   456,   457,   458,
     461,   462,   459,   460,   484,   486,   487,   488,   485,   533,
     534,   535,   536,   537,   538,   440,   575,   567,   574,   573,
     572,   569,   571,   568,   570,   470,   463,   602,   603,    39,
     214,   215,   217,   216,   218,   210,   466,   467,   468,   465,
     220,   223,   219,   221,   222,   442,   777,   793,   886,   895,
     893,   795,     0,   160,   161,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   122,
     124,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   263,   264,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   436,   439,   426,
       0,     0,   779,   803,   781,   834,   896,   783,   844,   785,
     855,   788,   790,   789,   873,   981,   988,   778,   982,   832,
     983,   989,   856,   987,   990,   937,   984,   985,   991,   986,
     938,   932,   924,   930,   921,   821,   942,   943,   940,   792,
     944,   993,   432,   442,   777,   424,     0,   185,   425,   428,
     779,   780,   781,   785,   786,   787,   788,   778,   784,   474,
       0,   430,   429,   180,     0,     0,   204,     0,   783,   790,
     789,     0,   162,   753,   944,     0,   211,     0,   475,     0,
     500,     0,   435,   775,     0,   776,   406,   407,     0,   438,
     437,   427,   410,     0,     0,   529,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   755,     0,   757,     0,
       0,     3,     1,     6,     8,     0,     0,     0,     0,     0,
     159,   159,   159,   159,     0,   115,   166,   164,     0,   183,
       0,   192,     0,     0,     0,     0,     0,     0,     0,     0,
     197,   224,   243,   239,   245,   240,   242,   241,     0,     0,
       0,   396,     0,     0,   394,     0,   344,     0,   395,   388,
     393,   392,   391,   390,   389,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   384,   383,   380,     0,   404,   409,
       0,     0,     0,   419,   452,   422,   421,   433,     0,   449,
       0,     0,   540,   542,   546,     0,   120,     0,   774,    43,
      40,    41,    44,    45,     0,     0,     0,     0,    46,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     612,   613,   614,     0,    99,   138,     0,     0,   108,     0,
       0,     0,     0,   123,     0,     0,     0,   581,     0,     0,
       0,   577,     0,     0,     0,   591,     0,     0,   226,   227,
     246,   247,     0,     0,     0,     0,   130,     0,   134,   162,
     605,     0,    56,     0,    65,     0,     0,     0,    57,     0,
       0,     0,     0,     0,     0,   582,     0,     0,     0,     0,
     308,     0,     0,   580,     0,     0,     0,   599,     0,     0,
       0,     0,   585,     0,     0,   187,     0,     0,   181,   179,
       0,     0,   759,     0,     0,     0,   474,     0,   754,     0,
     476,   501,   500,   497,     0,     0,   531,   530,   405,     0,
     528,     0,   625,   626,   779,   781,   785,   788,   778,     0,
       0,   576,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   631,     0,   195,   196,     0,     0,     0,     0,
       0,   200,   201,   756,   758,     0,    20,     0,    21,     0,
       4,    25,     0,    11,    26,     0,    15,   886,    73,    12,
      74,    16,   186,   184,   205,     0,     0,     0,     0,   198,
     225,   281,   336,   338,   342,   348,   347,   346,     0,   343,
     340,   341,     0,   352,   359,   358,   356,   362,   363,   364,
     361,   366,   367,   370,   369,     0,     0,     0,     0,   401,
       0,   414,   415,     0,   453,   450,   482,     0,   604,   480,
       0,     0,   117,   119,     0,     0,     0,    98,     0,    88,
      90,    91,    92,    93,    95,    96,    97,    89,    94,    84,
      85,     0,     0,   104,     0,   100,   102,   103,   110,     0,
       0,    83,    42,     0,     0,     0,     0,     0,     0,     0,
     703,   708,     0,     0,   704,   738,   691,   693,   694,   695,
     697,   699,   698,   696,   700,     0,     0,     0,     0,     0,
     107,     0,   140,     0,     0,   545,   539,   578,   579,     0,
       0,   595,     0,   592,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   228,   229,     0,   234,   136,     0,
       0,   131,     0,     0,     0,     0,     0,     0,    58,     0,
       0,     0,   262,   268,   265,     0,   584,   583,   590,   598,
       0,     0,     0,     0,   544,     0,     0,     0,   397,     0,
       0,     0,     0,   588,     0,   586,     0,   188,     0,     0,
     760,     0,     0,     0,     0,   500,   498,     0,   489,     0,
     478,   479,     0,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   193,     0,   783,   790,   789,   944,     0,
       0,     0,   639,     0,   202,     0,     0,     0,     0,   159,
     159,   159,     0,   235,     0,   292,   288,   290,     0,   282,
     283,   345,     0,     0,     0,     0,   669,   353,   642,   646,
     648,   650,   652,   655,   662,   663,   671,   896,   782,     0,
     791,   997,   996,   995,   998,   372,   551,   557,   558,   561,
     606,   607,   562,   563,   768,   769,   770,   566,   374,   376,
     548,   378,   402,   454,     0,   451,   481,   121,    52,    53,
      50,    51,   127,   126,     0,    86,     0,     0,   105,   106,
     111,    70,    71,    48,    49,    69,   709,     0,   712,   739,
       0,   702,   701,   706,   705,   737,     0,     0,   714,     0,
     710,   713,   692,     0,     0,     0,     0,     0,     0,     0,
     139,   142,     0,     0,     0,   109,   112,     0,     0,     0,
     162,     0,     0,   599,     0,     0,     0,     0,   550,     0,
     249,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     230,     0,     0,     0,     0,   275,     0,   272,   277,   233,
     137,   132,   135,     0,   182,     0,     0,    67,    61,    64,
      63,     0,    59,   266,     0,     0,   162,     0,   306,   310,
       0,     0,     0,   313,     0,     0,   319,     0,     0,   326,
       0,   330,     0,   399,   398,   162,     0,     0,   189,     0,
     191,   307,     0,     0,     0,     0,   501,     0,   490,     0,
     524,   521,     0,   525,   526,     0,     0,   520,     0,   495,
     523,   522,     0,     0,     0,     0,   618,   619,   615,     0,
       0,   623,   624,   620,     0,   762,   629,     0,   627,     0,
       0,     0,     0,   633,   194,     0,     0,     0,     0,     0,
       0,   634,   635,     0,   203,   764,    22,     0,    13,    17,
      18,   289,   301,     0,   302,     0,   293,   294,   295,   296,
       0,   285,     0,     0,     0,   653,   666,     0,   350,   354,
       0,   685,     0,     0,     0,     0,     0,     0,   641,   643,
     644,   680,   681,   682,   684,   683,     0,     0,   657,   656,
       0,   660,   664,   678,   676,   675,   668,   672,     0,     0,
       0,     0,     0,     0,     0,     0,   554,   556,   555,   552,
     549,   483,   129,   128,    87,   101,   726,   707,     0,   731,
       0,   731,   720,   715,   143,     0,     0,     0,   113,   141,
       0,    23,     0,   596,   597,   600,   593,   594,   248,     0,
       0,   261,   253,     0,   257,     0,   251,     0,     0,     0,
     270,     0,     0,     0,   232,   273,   276,     0,   133,     0,
       0,    66,     0,    60,   267,     0,     0,   309,   311,   316,
       0,   314,     0,     0,     0,     0,     0,   320,     0,     0,
       0,     0,   327,     0,     0,   331,   400,     0,   589,   587,
     190,   761,     0,     0,   500,     0,     0,   532,     0,   500,
       0,   496,    10,   765,     0,     0,     0,     0,     0,     0,
       0,     0,   632,     0,     0,     0,     0,     0,   636,   640,
     305,   303,   304,   297,   298,   299,   291,     0,   286,   284,
     670,   661,   667,     0,     0,   740,   741,   751,   750,   749,
       0,     0,     0,     0,   742,   647,   748,     0,   645,   649,
       0,     0,   654,   658,     0,   679,   674,   677,   673,     0,
       0,   564,     0,   559,   611,   553,   772,   773,   771,   560,
     727,     0,     0,   725,   732,   733,   729,     0,   724,     0,
     722,     0,     0,     0,     0,     0,     0,   541,   250,     0,
     259,     0,     0,   255,     0,   258,   271,   279,   280,   274,
     231,     0,     0,     0,    62,   269,   547,     0,     0,   317,
     321,   315,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   543,     0,     0,   500,     0,   527,     0,
     500,   616,   617,   621,   622,     0,     0,   628,     0,   630,
       0,     0,     0,     0,   637,   300,   287,   665,   752,     0,
       0,   744,     0,   690,   689,   688,   687,   686,   651,     0,
     743,     0,   608,     0,     0,   736,   735,   734,     0,   728,
     721,   719,     0,   716,   717,   711,   144,   146,   148,     0,
       0,     0,     0,     0,   254,   252,     0,   260,     0,   199,
     334,    68,   312,   318,     0,   332,   328,     0,     0,     0,
     322,     0,     0,   324,     0,   510,   504,   499,     0,   500,
     491,     0,   763,   766,     0,     0,     0,     0,   746,   745,
       0,     0,   609,   565,     0,   730,   723,     0,     0,   150,
     149,     0,     0,     0,     0,   145,   256,     0,     0,     0,
       0,     0,     0,   518,   512,     0,   511,   513,   519,   516,
     506,     0,   505,   507,   517,   493,     0,   492,     0,     0,
     638,   747,   659,   610,   718,   147,   151,     0,     0,     0,
       0,   278,     0,     0,   325,   323,     0,     0,   503,   514,
     515,   502,   508,   509,   494,   767,     0,   152,     0,     0,
       0,   333,   329,     0,     0,     0,     0,     0,     0,     0,
       0,   154,     0,   153,     0,     0,     0,     0,     0,     0,
       0,     0,   155
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1450, -1450,  -233,  1137, -1450,  1128,  1138, -1450,  1145,  -542,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
    -986, -1450, -1450, -1450, -1450,  -230,  -565, -1450,   657,   -58,
   -1450, -1450, -1450, -1450, -1450,   209,   431, -1450, -1450,   -10,
    -164,   969, -1450,   948, -1450, -1450,  -629, -1450,   369, -1450,
     178, -1450,  -285,  -328, -1450,  -551, -1450,     5,    87,    49,
    -270,  -178, -1450,  -886, -1450, -1450,   257, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450,   540,    99,  1388,
       0, -1450, -1450, -1450, -1450,   387, -1450, -1450,  -291, -1450,
       8, -1450, -1450,   180,  -722,  -716, -1450, -1450,   630, -1450,
   -1450,   -35,   174, -1450, -1450, -1450,    60, -1450, -1450,   311,
      61, -1450, -1450,    66, -1302, -1450,   876,   162, -1450, -1450,
     158, -1004, -1450, -1450,   156, -1450, -1450, -1250, -1219, -1450,
     153, -1450, -1450,   789,   791, -1450,  -504,   770, -1450, -1450,
    -643,   307,  -641,   303,   304, -1450, -1450, -1450, -1450, -1450,
    1109, -1450, -1450, -1450, -1450,  -885,  -313, -1144, -1450,   -99,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450,   -36,  -818, -1450,
   -1450,   573,   211,  -535,  -402, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450,   740, -1450, -1007, -1450,   143, -1450,   622,  -809,
   -1450, -1450, -1450, -1450, -1450,  -309,  -300, -1167,  -957, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,   529,
    -752,  -802,   238,  -870, -1450,    69,  -867, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450,   992,  1008,  -229,   448,   276, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450,   120, -1450, -1450,   113, -1450,   116, -1056,
   -1450, -1450, -1450,    83,    73,   -95,   336, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
      78, -1450, -1450, -1450,   -86,   329,   478, -1450, -1450, -1450,
   -1450, -1450,   266, -1450, -1450, -1449, -1450, -1450, -1450,  -578,
   -1450,    46, -1450,  -108, -1450, -1450, -1450, -1450, -1317, -1450,
      95, -1450, -1450, -1450, -1450, -1450,   880, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450,  -392,  -375,    74,   933,
   -1450
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   253,   859,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
    1247,   767,   271,   272,   273,   274,   275,   276,   939,   940,
     941,   277,   278,   279,   945,   946,   947,   280,   437,   281,
     282,   695,   283,   439,   440,   441,   454,   757,   758,   284,
    1200,   285,  1666,  1667,   286,   287,   288,   544,   289,   290,
     291,   292,   293,   760,   294,   295,   527,   296,   297,   298,
     299,   300,   301,   630,   302,   303,   851,   852,   304,   305,
     556,   307,   631,   452,  1006,  1007,   308,   632,   309,   634,
     557,   311,   750,   751,  1235,   461,   312,   462,   463,   754,
    1236,  1237,  1238,   635,   636,  1109,  1110,  1518,   637,  1106,
    1107,  1346,  1347,  1348,  1349,   313,   779,   780,   314,  1262,
    1263,  1462,   315,  1265,  1266,   316,   317,  1268,  1269,  1270,
    1271,   318,   319,   320,   321,   888,   322,   323,  1358,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   655,   656,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   683,   684,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   917,   363,   364,   365,  1298,   812,   813,   814,
    1697,  1741,  1742,  1735,  1736,  1743,  1737,  1299,  1300,   366,
     367,  1301,   368,   369,   370,   371,   372,   373,   374,  1149,
    1001,  1135,  1399,  1136,  1552,  1137,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   786,  1212,   385,   386,
     387,   388,  1139,  1140,  1141,  1142,   389,   390,   391,   392,
     393,   394,   841,   842,   395,  1331,  1332,  1634,  1093,  1117,
    1368,  1369,  1118,  1119,  1120,  1121,  1122,  1378,  1542,  1543,
    1123,  1381,  1124,  1523,  1125,  1126,  1386,  1387,  1548,  1546,
    1370,  1371,  1372,  1373,  1646,   724,   966,   967,   968,   969,
     970,   971,  1190,  1572,  1663,  1191,  1570,  1661,   972,  1411,
    1567,  1563,  1564,  1565,   973,   974,  1374,  1382,  1533,  1375,
    1529,  1359,   396,   397,   398,   399,   547,   400,   401,   402,
     403,   404,  1143,  1144,  1145,  1146,  1248,   564,   405,   406,
     407
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       306,   595,   438,  1057,   306,   306,   306,  1115,   310,   412,
     415,   416,   310,   310,   310,   696,   696,  1021,   896,   633,
     616,   897,   898,   899,   900,   678,   611,   699,   608,  1033,
     999,  1264,  1092,  1252,   572,  1483,  1000,   522,  1138,  1138,
    1163,   613,   620,  1047,   829,  1514,  1515,   868,   870,  1472,
     837,  1224,  1297,   414,   414,   414,   719,  1354,  1415,   863,
     866,   869,   871,  1544,   620,   764,   768,   734,   861,   864,
     995,  1003,  1167,     9,    10,  1138,  1530,   926,  1221,     9,
      10,   609,  1065,   609,     9,    10,  1290,  1291,   698,   459,
     776,   413,   413,   413,   423,   419,   420,    11,   421,   422,
     423,   574,   801,   424,  1148,   423,   609,   609,   306,  1201,
    1254,   997,   609,   609,   424,   425,   310,   615,   609,   755,
    1669,   426,  1664,  1062,  1437,   997,   427,   426,   996,  1138,
     997,  1491,   426,  1695,   620,  1030,   884,   427,   885,   886,
    1561,   887,  1138,   889,   616,   996,  1080,   523,   577,   816,
     578,   890,   891,   417,   708,   739,   442,   545,   428,   429,
    1102,   539,  1225,   419,   420,   730,   421,   422,   586,   428,
     429,   430,   740,   587,   456,  1058,  1429,   473,    79,   418,
    1292,   998,  1063,   425,   457,   560,   709,   955,   756,   956,
     996,   581,    90,   582,  1218,   413,  1170,   565,  1032,   568,
    1293,   445,  1294,   460,  1562,  1066,  1067,  1241,   555,   559,
     458,  1635,  1069,   800,   810,  1360,  1031,   104,   431,   763,
    1068,  1112,  1030,  1696,  1113,   698,  1670,  1074,  1115,  1115,
    1295,   584,  1004,   957,   111,  1531,  1532,   579,  1020,  1337,
     460,  1059,   679,   460,  1733,   125,  1287,   854,  1290,   460,
    1229,   123,   306,  1662,   474,   306,  1240,   588,   921,  1390,
     310,  1466,  1138,   310,  1472,  1453,   633,   853,  1754,  1005,
     610,  1296,   612,  1081,   615,   616,  1576,   432,  1403,  1226,
     583,  1360,  1297,  1222,   575,  1227,   431,   460,  1361,   149,
     306,  1297,  1639,   868,   870,   856,   858,   741,   310,  1164,
    1522,  1099,  1101,  1049,    11,  1255,   460,  1336,  1671,   765,
     685,  1290,  1291,   687,   861,   864,   817,   921,   433,  1491,
     585,   475,   476,   618,  1073,   952,  1114,   990,   992,   677,
    1733,     9,    10,   434,  1290,  1070,  1071,  1328,   922,   731,
    1201,   435,   597,   599,   434,   432,  1463,   732,  1463,   436,
    1072,  1608,   435,   125,  1361,   700,   766,   446,   879,  1290,
     436,  1463,  1293,   453,  1294,   801,  1719,  1288,   701,  1640,
    1362,  1363,  1734,  1364,   857,  1018,  1138,   714,  1739,   715,
     862,   865,  1706,   958,  1111,    79,   433,   620,  1014,   617,
    1366,  1017,  1295,  1333,   620,  1694,   959,   923,   960,    90,
    1138,   714,  1367,   715,   620,  1292,   619,   991,   993,   961,
     962,   963,   996,   964,   306,   965,   620,   614,  1756,  1609,
     523,   620,   310,   523,   104,  1293,  1010,  1294,  1112,  1668,
     620,  1113,  1464,  1289,  1598,   716,  1362,  1363,   717,  1364,
     622,  1448,   802,   306,   623,   306,  1365,  1603,  1293,   624,
    1294,   310,   125,   310,  1418,  1295,  1366,  1408,  1769,   111,
    1046,   620,   717,  1609,   989,  1469,   616,   625,  1367,   306,
     659,  1115,   808,  1293,   306,  1294,   123,   310,  1295,  1297,
    1115,  1025,   310,   942,  1740,   620,   443,  1472,   660,   444,
    1116,  1115,   736,  1041,   736,  1430,  1485,   620,   707,  1153,
     718,   711,   659,  1295,    11,   565,  1011,  1060,   725,   726,
    1438,   620,  1092,   617,   149,  1509,   565,  1410,   736,  1157,
     660,  1138,   747,   736,   718,   752,   943,  1633,  1042,  1668,
     735,   944,   738,   769,   868,   870,   868,  1044,  1061,   565,
     777,   778,   781,   620,  1320,   306,   744,   787,  1338,  1339,
    1340,  1154,   306,   310,   761,   794,   782,  1171,  1172,   728,
     310,   788,  1175,   773,   729,  1013,   626,  1154,   620,   627,
     784,   785,  1290,  1291,  1668,  1290,  1291,  1035,   616,   791,
    1643,   911,   912,  1333,   628,    79,  1551,  1644,   620,   622,
     620,  1036,  1209,   623,   306,   438,   620,  1645,   624,    90,
     795,   414,   310,  1138,   620,   620,  1138,  1681,  1043,   629,
     306,   306,   306,   306,   781,   620,   625,  1045,   310,   310,
     310,   310,   620,  1084,   104,   806,  1096,  1466,   306,  1100,
     620,  1155,   620,   479,   659,  1231,   310,  1343,   455,   413,
    1232,  1653,  1658,   848,   617,  1091,  1793,  1156,  1794,   620,
     997,   996,   660,   830,   662,  1115,  1193,  1802,  1345,   830,
     815,  1194,   739,   843,   480,  1152,  1292,   481,  1607,  1292,
    1283,  1611,   819,  1520,   661,  1615,  1195,   449,  1196,   740,
    1619,  1187,   450,   663,  1284,  1285,  1293,  1197,  1294,  1293,
     622,  1294,   847,   849,   623,  1630,   664,   466,  1188,   624,
    1396,  1581,  1631,  1231,  1228,   682,  1290,   688,  1232,  1750,
    1632,  1116,  1116,  1582,  1198,   626,  1295,   625,   627,  1295,
     111,  1654,  1659,   111,  1537,  1739,  1752,  1233,  1408,   451,
     665,  1356,  1397,   809,   659,  1525,   306,   123,  1738,  1744,
     123,  1189,  1383,  1384,   310,  1409,   997,   467,  1231,  1398,
     605,   468,   660,  1232,   704,   125,   702,  1490,   629,   306,
    1617,  1211,  1342,  1214,  1012,  1385,   606,   310,  1234,   703,
     705,   868,  1526,  1343,  1710,   149,   910,   943,   149,  1738,
    1097,   913,   944,  1344,  1138,  1744,  1138,   948,  1410,   306,
     306,   997,  1158,  1160,  1345,  1187,   606,   310,   310,   633,
     447,   978,   678,   448,   668,   982,   983,  1698,   414,  1159,
    1161,  1701,  1188,  1276,  1324,  1277,   626,  1138,   669,   627,
    1293,   666,  1294,  1261,   477,   464,  1643,  1002,   465,  1008,
     667,  1772,  1261,  1644,  1329,   617,  1460,   565,   736,   736,
     565,  1199,  1162,  1645,  1022,  1465,   413,  1138,  1089,  1712,
    1295,  1713,  1402,  1470,  1451,   996,  1090,   438,   759,   629,
    1473,   640,  1138,   471,  1138,  1470,  1471,  1343,   759,   641,
     642,   872,   643,  1474,  1470,   873,  1039,  1040,  1614,   478,
     644,  1165,  1728,  1638,   645,  1055,   646,  1749,  1641,  1642,
    1746,   647,  1203,  1165,   914,   472,  1181,   914,  1183,   525,
     914,  1204,  1052,  1053,  1054,   526,   849,  1182,   648,  1184,
     595,   469,  1753,  1527,   470,  1334,  1720,  1176,  1177,  1178,
    1528,   686,   528,  1179,   523,   529,   689,  1763,   540,  1766,
     541,   649,   650,   651,   652,   653,   654,   929,   930,   931,
     932,   933,   934,   935,   936,   937,   938,   680,   681,  1103,
    1304,  1510,  1305,   542,  1116,   720,   721,   722,  1309,   561,
    1310,  1173,  1174,  1116,  1511,  1512,   894,   895,   562,   901,
     902,   569,   903,   904,  1116,  1449,  1150,  1150,   570,  1147,
    1147,  1147,  1147,  1655,  1656,   571,   576,   573,   580,   589,
     590,   591,   594,   592,   593,   600,  1708,  1709,   602,   620,
     639,   621,   638,   657,   658,   670,   524,   672,   671,   673,
     690,   691,   682,   692,   693,   698,  1147,   710,   712,   713,
     524,   694,   753,   723,   727,   748,   749,   737,   759,   762,
    1180,   770,   771,   772,   783,   789,   790,   306,   796,   800,
     444,   448,   465,   470,   524,   310,   798,   481,   811,   803,
     804,   805,   807,   818,   820,  1206,   524,   831,   524,   879,
    1594,   821,   844,   845,  1213,   850,  1213,  1751,   860,   875,
    1147,   876,   839,   840,   892,   905,   906,   907,   908,   877,
     878,   918,   924,  1147,  1089,   925,   736,   927,   438,   949,
     950,   953,  1090,   954,   976,   975,   977,   981,   979,   306,
     306,   306,   987,   984,   985,   986,   988,   310,   310,   310,
     994,  1009,  1015,  1016,  1019,  1026,   787,  1075,   787,  1037,
     443,  1027,  1028,  1029,  1272,  1636,  1034,  1038,  1064,   447,
     464,  1082,  1079,   469,   480,  1078,  1077,  1083,  1116,  1095,
    1098,  1076,  1108,  1104,  1166,   996,  1185,   944,  1202,  1186,
    1207,  1208,  1210,   830,  1217,  1216,  1219,  1223,   755,  1245,
    1243,  1246,  1249,  1250,  1256,  1230,  1251,  1257,  1260,  1261,
    1286,  1244,  1267,  1275,  1273,  1274,  1279,  1302,  1280,  1321,
    1282,  1325,  1351,  1330,   716,  1350,  1326,  1352,  1328,  1327,
    1377,  1380,    11,  1407,  1600,  1376,  1400,  1388,  1357,  1389,
    1391,  1392,  1393,  1147,  1394,  1412,  1395,  1425,  1406,  1421,
     306,  1353,  1435,  1416,  1433,  1422,  1442,  1443,   310,  1420,
    1439,  1417,  1441,  1447,  1455,  1452,  1423,  1470,  1484,  1424,
    1487,  1500,  1498,  1494,  1426,  1501,  1343,  1517,  1476,  1495,
    1427,  1496,  1478,  1524,  1479,   306,  1497,  1540,  1545,  1541,
    1547,  1493,  1492,   310,  1560,  1534,   306,  1482,  1499,   414,
    1503,  1456,  1566,  1521,   310,  1571,  1569,  1573,  1553,  1579,
    1554,  1555,  1577,  1556,  1557,   306,  1558,  1559,  1575,   524,
    1477,  1584,   524,   310,  1593,  1591,  1592,  1596,  1597,  1625,
     752,  1626,  1602,  1431,  1605,   306,  1612,   413,  1613,  1618,
    1637,  1651,  1649,   310,  1660,   414,  1652,  1187,  1445,  1673,
    1665,  1678,  1672,  1676,  1684,  1688,  1700,  1147,  1692,  1715,
    1704,  1679,  1705,  1714,   414,  1717,  1718,  1722,  1089,  1089,
    1727,   781,  1683,  1600,  1729,  1685,  1090,  1090,  1730,  1731,
    1745,  1147,  1693,   413,   736,  1723,  1747,  1748,  1759,  1768,
    1760,  1762,  1771,  1767,  1776,  1716,   706,   524,  1774,  1780,
     524,  1783,   413,  1784,   524,  1789,  1795,   524,   524,  1786,
    1489,  1650,  1799,   951,  1168,   524,  1405,   848,  1798,  1242,
    1796,   524,  1488,   603,   524,  1419,   733,   697,  1725,   601,
    1755,  1094,   524,   604,  1239,   843,  1428,  1757,   524,   524,
     524,   524,  1024,   607,   523,  1778,   524,   523,  1787,  1446,
    1589,  1516,  1519,  1513,   524,  1341,   797,  1790,  1792,  1457,
    1461,  1467,  1685,  1475,  1504,  1505,  1506,   882,   893,  1801,
     883,   920,  1486,  1773,  1056,  1449,  1770,  1151,   742,  1414,
    1215,  1502,  1404,   676,  1508,  1648,  1507,  1538,  1535,  1539,
    1355,  1647,  1379,  1192,   743,  1413,  1657,  1568,     0,   524,
    1764,  1536,  1147,   835,   306,     0,     0,     0,     0,     0,
       0,     0,   310,   524,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   524,     0,     0,     0,     0,     0,
    1574,     0,  1781,     0,     0,     0,   546,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1781,     0,  1587,  1588,     0,  1764,
       0,     0,   524,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1604,     0,  1147,     0,     0,  1147,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1616,
       0,     0,     0,     0,  1620,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1089,     0,     0,     0,     0,     0,     0,     0,  1090,
       0,     0,  1089,  1089,     0,   306,     0,     0,     0,     0,
    1090,  1090,  1089,   310,     0,     0,     0,     0,     0,     0,
    1090,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   928,     0,     0,   524,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     524,     0,     0,     0,   524,   524,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1687,     0,  1689,     0,  1691,     0,   524,     0,   524,     0,
       0,  1699,  1089,     0,     0,     0,   524,     0,     0,   524,
    1090,     0,     0,   524,     0,  1089,     0,     0,     0,     0,
       0,     0,     0,  1090,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1147,     0,  1147,     0,     0,
     306,     0,  1707,     0,     0,     0,     0,     0,   310,     0,
       0,     0,     0,  1721,   524,     0,  1724,     0,  1711,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1147,     0,
       0,     0,   306,     0,     0,     0,     0,     0,  1732,     0,
     310,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   524,  1089,     0,     0,     0,  1147,  1089,
       0,     0,  1090,     0,     0,     0,  1758,  1090,     0,     0,
       0,  1761,     0,  1147,     0,  1147,     0,     0,   524,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1779,     0,     0,     0,     0,   524,   524,
     524,   524,     0,     0,     0,     0,     0,     0,     0,     0,
    1785,     0,     0,     0,  1788,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1797,     0,     0,  1800,     0,   524,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   524,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   524,     0,     0,     0,     0,     0,
       0,     0,     0,   524,     0,   524,     0,     0,     0,   524,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     546,     0,   524,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   822,   823,     0,     0,   832,
     833,   834,   836,     0,   838,   524,     0,   524,     0,     0,
     846,     0,     0,     0,     0,     0,     0,     0,   855,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   874,     0,
       0,     0,     0,     0,     0,     0,   880,   881,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   524,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   524,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   916,     0,     0,   916,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   980,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   524,
       0,     0,   524,     0,     0,     0,     0,     0,     0,  1023,
       0,     0,     0,     0,     0,     0,     0,   524,     0,     0,
       0,     0,     0,     0,     0,     0,   524,     0,     0,     0,
       0,     0,     0,     0,  1048,     0,     0,     0,  1050,  1051,
     524,     0,     0,     0,     0,     0,     0,   880,     0,     0,
     524,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   524,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   524,     0,     0,     0,     0,     0,
       0,     0,     0,   524,     0,  1105,   524,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   524,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1169,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   524,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1205,     0,     0,
       0,     0,     0,     0,     0,   524,   524,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1220,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   524,     0,   524,     0,     0,   524,     0,  1253,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   524,  1258,
    1259,     0,     0,   524,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1278,     0,     0,  1281,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1303,     0,  1306,  1307,  1308,     0,  1311,  1312,
    1313,  1314,  1315,  1316,  1317,  1318,  1319,     0,     0,  1322,
    1323,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1335,     0,     0,     0,     0,     0,     0,
       0,     0,  1105,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   524,
       0,   524,  1401,   524,     0,     0,     0,     0,     0,     0,
     524,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   524,     0,   524,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   524,     0,     0,   524,     0,     0,     0,  1432,
       0,  1434,     0,  1436,     0,     0,  1440,   524,     0,     0,
       0,  1444,     0,     0,     0,     0,     0,   524,     0,     0,
       0,     0,     0,  1450,     0,     0,     0,     0,     0,     0,
       0,     0,  1454,     0,     0,     0,     0,   524,  1458,  1459,
       0,     0,     0,     0,     0,   524,     0,     0,     0,     0,
     524,     0,   524,     0,   524,     0,     0,  1480,     0,     0,
    1481,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   524,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   524,
       0,     0,     0,   524,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   524,
       0,     0,   524,     0,     0,     0,     0,     0,  1105,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1578,     0,     0,
       0,  1580,     0,     0,     0,  1583,     0,  1585,     0,  1586,
       0,     0,     0,     0,     0,  1590,     0,     0,     0,     0,
       0,     0,     0,  1595,     0,     0,     0,     0,     0,     0,
       0,  1599,  1601,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1450,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1621,  1622,  1623,  1624,     0,     0,  1627,  1628,
       0,  1629,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1674,     0,  1675,
       0,     0,  1677,     0,     0,     0,     0,     0,     0,     0,
    1680,     0,     0,     0,     0,  1682,  1601,     0,     0,     0,
       0,     0,     0,  1686,     0,     0,     0,  1690,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1702,  1703,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1726,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1686,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1765,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1775,     0,     0,     0,
       0,     0,     0,     0,     0,  1777,     0,     0,     0,     0,
    1782,     1,     2,     0,     0,  1765,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
       0,  1782,     0,    12,    13,  1791,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,    73,     0,
      74,    75,    76,     0,     0,    77,    78,     0,     0,     0,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,     0,     0,     0,    90,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,    96,    97,    98,    99,   100,
       0,     0,     0,     0,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   108,   109,     0,   110,   111,   112,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,     0,   123,     0,   124,   125,     0,     0,
     126,   127,   128,     0,     0,     0,   129,     0,   130,   131,
       0,   132,   133,   134,     0,   135,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,   149,     0,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
       0,   244,     0,   245,   246,   247,   248,   249,   250,   251,
     252,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
       0,     0,     0,   408,   409,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,   410,
      28,    29,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,    73,     0,
      74,    75,    76,     0,     0,    77,    78,     0,     0,     0,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,     0,     0,     0,    90,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,    96,    97,    98,    99,   100,
       0,     0,     0,     0,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   108,   109,     0,   110,   111,   112,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,     0,   123,     0,   124,   125,     0,     0,
     126,   127,   128,     0,   543,     0,   129,     0,   130,   131,
       0,   132,   133,   134,     0,   135,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,   149,     0,   411,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
       0,   244,     0,   245,   246,   247,   248,   249,   250,   251,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,     0,    11,     0,
       0,     0,   408,   409,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,   410,    28,
      29,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,     0,    74,
      75,    76,     0,     0,    77,    78,     0,     0,     0,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
       0,     0,     0,    90,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,    96,    97,    98,    99,   100,     0,
       0,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   108,   109,     0,   110,   111,   112,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,     0,   123,     0,   124,   125,     0,     0,   126,
     127,   128,     0,   799,     0,   129,     0,   130,   131,     0,
     132,   133,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   411,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,   408,   409,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,  1085,   410,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
    1086,  1087,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,   799,     0,   129,     0,   130,   131,     0,   132,
     133,   134,     0,   135,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
     149,     0,   411,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,  1088,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,     0,   244,
       0,   245,   246,   247,   248,   249,   250,   251,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     9,    10,     0,    11,     0,     0,     0,
     408,   409,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,  1085,   410,    28,    29,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,  1086,
    1087,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,     0,    74,    75,    76,
       0,     0,    77,    78,     0,     0,     0,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,     0,     0,
       0,    90,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,    96,    97,    98,    99,   100,     0,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     108,   109,     0,   110,   111,   112,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
       0,   123,     0,   124,   125,     0,     0,   126,   127,   128,
       0,   543,     0,   129,     0,   130,   131,     0,   132,   133,
     134,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   411,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
    1088,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,     0,   244,     0,
     245,   246,   247,   248,   249,   250,   251,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,     0,     0,     0,   408,
     409,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,   410,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,     0,    74,    75,    76,     0,
       0,    77,    78,     0,     0,     0,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,     0,     0,     0,
      90,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   108,
     109,     0,   110,   111,   112,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,     0,
     123,     0,   124,   125,     0,     0,   126,   127,   128,     0,
       0,     0,   129,     0,   130,   131,     0,   132,   133,   134,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,   149,     0,
     411,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,     0,   244,     0,   245,
     246,   247,   248,   249,   250,   251,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,     0,    11,     0,     0,     0,    12,    13,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,     0,    74,    75,    76,     0,     0,
      77,    78,     0,     0,     0,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,     0,     0,     0,    90,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
      96,    97,    98,    99,   100,     0,     0,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   108,   109,
       0,   110,   111,   112,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,     0,   123,
       0,   124,   125,     0,     0,   126,   127,   128,     0,     0,
       0,   129,     0,   130,   131,     0,   132,   133,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,    12,    13,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   108,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,     0,     0,
     129,     0,   130,   131,     0,   132,   133,   134,     0,   135,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,   149,     0,   411,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,     0,   244,     0,   245,   246,   247,
     248,   249,   250,   251,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     9,
      10,     0,    11,     0,     0,     0,    12,   409,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,     0,    74,    75,    76,     0,     0,    77,    78,
       0,     0,     0,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,     0,     0,     0,    90,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,    96,    97,
      98,    99,   100,     0,     0,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   108,   109,     0,   110,
     111,   112,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,     0,   123,     0,   124,
     125,     0,     0,   126,   127,   128,     0,     0,     0,   129,
       0,   130,   131,     0,   132,   133,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   411,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     0,   244,     0,   245,   246,   247,   248,
     249,   250,   251,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,     0,     0,     0,   867,   409,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,   410,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   108,   109,     0,   110,   111,
     112,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,     0,   124,   125,
       0,     0,   126,   127,   128,     0,     0,     0,   129,     0,
     130,   131,     0,   132,   133,   134,     0,   135,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,   149,     0,   411,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,     0,   244,     0,   245,   246,   247,   248,   249,
     250,   251,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     9,    10,     0,
      11,     0,     0,     0,   408,   409,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,  1085,
     410,    28,    29,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,  1086,  1087,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
       0,    74,    75,    76,     0,     0,    77,    78,     0,     0,
       0,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,     0,     0,     0,    90,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,    96,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   108,   109,     0,   110,   111,   112,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,   121,   122,     0,   123,     0,   124,   125,     0,
       0,   126,   127,   128,     0,     0,     0,   129,     0,   130,
     131,     0,   132,   133,   134,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,   149,     0,   411,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,  1088,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,     0,   244,     0,   245,   246,   247,   248,   249,   250,
     251,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     0,     0,     0,    11,
       0,     0,     0,   408,   409,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,   548,   410,
      28,    29,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,   549,   550,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,    73,     0,
      74,    75,    76,     0,     0,    77,    78,     0,     0,     0,
      79,    80,   499,    82,    83,    84,    85,    86,   551,    88,
      89,     0,     0,     0,    90,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,    96,    97,    98,    99,   100,
       0,     0,     0,     0,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   552,   109,     0,   110,   111,   112,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,     0,   123,     0,   124,   125,     0,     0,
     126,   127,   128,     0,     0,   553,   129,     0,   130,   131,
       0,   132,   133,   134,     0,   135,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,   149,     0,   411,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   516,   517,   518,
     176,   177,   519,   554,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
       0,   244,     0,   245,   246,   247,   248,   249,   250,   251,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     0,     0,     0,    11,     0,
       0,     0,   408,   409,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   548,   410,    28,
      29,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,   549,   550,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,     0,    74,
      75,    76,     0,     0,    77,    78,     0,     0,     0,    79,
      80,   499,    82,    83,    84,    85,    86,   551,    88,    89,
       0,     0,     0,    90,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,    96,    97,    98,    99,   100,     0,
       0,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   552,   109,     0,   110,   111,   112,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,     0,   123,     0,   124,   125,     0,     0,   126,
     127,   128,     0,     0,     0,   129,   558,   130,   131,     0,
     132,   133,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   411,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   516,   517,   518,   176,
     177,   519,   554,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   408,   409,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   548,   410,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     549,   550,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     499,    82,    83,    84,    85,    86,   551,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   552,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,   134,     0,   135,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
     149,     0,   411,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   516,   517,   518,   176,   177,
     519,   554,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   596,   244,
       0,   245,   246,   247,   248,   249,   250,   251,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     0,     0,     0,    11,     0,     0,     0,
     408,   409,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   548,   410,    28,    29,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,   549,
     550,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,     0,    74,    75,    76,
       0,     0,    77,    78,     0,     0,     0,    79,    80,   499,
      82,    83,    84,    85,    86,   551,    88,    89,     0,     0,
       0,    90,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,    96,    97,    98,    99,   100,     0,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     552,   109,     0,   110,   111,   112,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
       0,   123,     0,   124,   125,     0,     0,   126,   127,   128,
       0,     0,     0,   129,     0,   130,   131,     0,   132,   133,
     134,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   411,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   516,   517,   518,   176,   177,   519,
     554,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,     0,   244,   598,
     245,   246,   247,   248,   249,   250,   251,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     0,     0,     0,    11,     0,     0,     0,   408,
     409,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   548,   410,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,   549,   550,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,     0,    74,    75,    76,     0,
       0,    77,    78,     0,     0,     0,    79,    80,   499,    82,
      83,    84,    85,    86,   551,    88,    89,     0,     0,     0,
      90,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   552,
     109,     0,   110,   111,   112,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,     0,
     123,     0,   124,   125,     0,     0,   126,   127,   128,     0,
     909,     0,   129,     0,   130,   131,     0,   132,   133,   134,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,   149,     0,
     411,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   516,   517,   518,   176,   177,   519,   554,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,     0,   244,     0,   245,
     246,   247,   248,   249,   250,   251,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     0,     0,     0,    11,     0,     0,     0,   408,   409,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   548,   410,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,   549,   550,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,     0,    74,    75,    76,     0,     0,
      77,    78,     0,     0,     0,    79,    80,   499,    82,    83,
      84,    85,    86,   551,    88,    89,     0,     0,     0,    90,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
      96,    97,    98,    99,   100,     0,     0,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   552,   109,
       0,   110,   111,   112,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,     0,   123,
       0,   124,   125,     0,     0,   126,   127,   128,     0,     0,
       0,   129,   915,   130,   131,     0,   132,   133,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   411,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   516,   517,   518,   176,   177,   519,   554,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   408,   409,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   548,   410,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,   549,   550,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   499,    82,    83,    84,
      85,    86,   551,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   552,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,     0,     0,
     129,   919,   130,   131,     0,   132,   133,   134,     0,   135,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,   149,     0,   411,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   516,   517,   518,   176,   177,   519,   554,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,     0,   244,     0,   245,   246,   247,
     248,   249,   250,   251,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     0,
       0,     0,    11,     0,     0,     0,   408,   409,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,   485,
      25,   487,   410,    28,   488,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
     490,     0,    45,    46,    47,   492,   493,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,     0,    74,    75,    76,     0,     0,    77,    78,
       0,     0,     0,    79,    80,   499,    82,    83,    84,    85,
      86,   551,    88,    89,     0,     0,     0,    90,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   502,    97,
      98,    99,   100,     0,     0,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   552,   109,     0,   110,
     111,   674,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,     0,   123,     0,   675,
     125,     0,     0,   126,   127,   128,     0,     0,     0,   129,
       0,   130,   131,     0,   132,   133,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   411,   151,   152,
     153,   154,   155,   156,   157,   158,   511,   160,   512,   162,
     513,   514,   165,   166,   167,   168,   169,   170,   515,   172,
     516,   517,   518,   176,   177,   519,   520,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     0,   244,     0,   245,   521,   247,   248,
     249,   250,   251,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     0,
       0,    11,     0,     0,     0,   408,   409,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     548,   410,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,   549,   550,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   499,    82,    83,    84,    85,    86,
     551,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   552,   109,     0,   110,   111,
     112,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,     0,   124,   125,
       0,     0,   126,   127,   128,     0,     0,     0,   129,     0,
     130,   131,     0,   132,   133,   134,     0,   135,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,   149,     0,   411,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   516,
     517,   518,   176,   177,   519,   554,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,     0,   244,     0,   245,   246,   247,   248,   249,
     250,   251,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     0,     0,     0,
      11,     0,     0,     0,   408,   409,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,   485,    25,   487,
     410,    28,   488,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,   490,     0,
      45,    46,    47,   492,   493,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
       0,    74,    75,    76,     0,     0,    77,    78,     0,     0,
       0,    79,    80,   499,    82,    83,    84,    85,    86,   551,
      88,    89,     0,     0,     0,    90,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   502,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   552,   109,     0,   110,   111,   112,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,   121,   122,     0,   123,     0,   124,   125,     0,
       0,   126,   127,   128,     0,     0,     0,   129,     0,   130,
     131,     0,   132,   133,   134,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,   149,     0,   411,   151,   152,   153,   154,
     155,   156,   157,   158,   511,   160,   512,   162,   513,   514,
     165,   166,   167,   168,   169,   170,   515,   172,   516,   517,
     518,   176,   177,   519,   520,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,     0,   244,     0,   245,   521,   247,   248,   249,   250,
     251,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     0,     0,     0,    11,
       0,     0,     0,   408,   409,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,   485,    25,   487,   410,
      28,   488,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,   490,     0,    45,
      46,    47,   492,   493,    50,   494,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,    73,     0,
      74,    75,    76,     0,     0,    77,    78,     0,     0,     0,
      79,    80,   499,    82,    83,    84,    85,    86,   551,    88,
      89,     0,     0,     0,    90,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   502,    97,    98,    99,   100,
       0,     0,     0,     0,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   552,   109,     0,   110,   111,     0,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,     0,   123,     0,     0,     0,     0,     0,
     126,   127,   128,     0,     0,     0,   129,     0,   130,   131,
       0,   132,   133,   134,     0,   135,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,   149,     0,   411,   151,   152,   153,   154,   155,
     156,   157,   158,   511,   160,   512,   162,   513,   514,   165,
     166,   167,   168,   169,   170,   515,   172,   516,   517,   518,
     176,   177,   519,   520,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
       0,   244,     0,   245,   521,   247,   248,   249,   250,   251,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     0,     0,     0,    11,     0,
       0,     0,   408,   409,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,   485,    25,   487,   410,    28,
     488,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,   490,     0,    45,    46,
      47,   492,   493,    50,   494,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,     0,    74,
      75,    76,     0,     0,    77,    78,     0,     0,     0,    79,
      80,   499,    82,    83,    84,    85,    86,   551,    88,    89,
       0,     0,     0,    90,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   502,    97,    98,    99,   100,     0,
       0,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   552,   109,     0,   110,   111,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,     0,   123,     0,     0,     0,     0,     0,   126,
     127,   128,     0,     0,     0,   129,     0,   130,   131,     0,
       0,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   411,   151,   152,   153,   154,   155,   156,
     157,   158,   511,   160,   512,   162,   513,   514,   165,   166,
     167,   168,   169,   170,   515,   172,   516,   517,   518,   176,
     177,   519,   520,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   521,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   408,   409,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   485,    25,   487,   410,    28,   488,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,   490,     0,    45,    46,    47,
     492,   493,    50,   494,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     499,    82,    83,    84,    85,    86,   551,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   502,     0,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,     0,   106,
     107,   552,   109,     0,   110,   111,     0,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,     0,     0,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,     0,
       0,   134,     0,   135,     0,   136,     0,   138,     0,   140,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
     149,     0,   411,   151,   152,   153,   154,   155,   156,   157,
     158,   511,   160,   512,   162,   513,   514,   165,   166,   167,
     168,   169,   170,   515,   172,   516,   517,   518,   176,   177,
     519,   520,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,     0,   244,
       0,   245,   521,   247,   248,   249,   250,   251,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     0,     0,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
     408,   409,     0,    14,    15,    16,   482,    18,    19,    20,
     483,    22,   484,   485,   486,   487,   410,    28,   488,    30,
      31,     0,    32,    33,    34,    35,   489,    37,    38,    39,
      40,    41,    42,    43,   490,     0,    45,   491,    47,   492,
     493,    50,   494,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   495,   496,    68,
       0,    69,    70,    71,   497,     0,     0,    74,    75,    76,
       0,     0,   498,    78,     0,     0,     0,     0,    80,   499,
      82,   500,   501,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   502,    97,    98,   503,   504,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,   107,
       0,     0,     0,     0,     0,     0,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   505,   120,   121,   506,
       0,     0,     0,     0,     0,     0,     0,   507,   508,   128,
       0,     0,     0,   129,     0,   130,   509,     0,     0,     0,
     134,     0,   135,     0,   136,   137,   138,   139,   510,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,     0,
       0,   411,   151,   152,   153,   154,   155,   156,   157,   158,
     511,   160,   512,   162,   513,   514,   165,   166,   167,   168,
     169,   170,   515,   172,   516,   517,   518,   176,   177,   519,
     520,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     0,     0,     1,     2,
     245,   521,   247,   248,   249,   250,   251,     3,     0,     0,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
     408,   409,     0,    14,    15,    16,   530,    18,    19,    20,
     483,   531,   532,   485,   486,   487,   410,    28,   488,    30,
      31,     0,    32,    33,    34,    35,   533,    37,   534,   535,
      40,    41,    42,    43,   490,     0,    45,   536,    47,   492,
     493,    50,   494,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   495,   496,    68,
       0,    69,    70,    71,   537,     0,     0,    74,    75,    76,
       0,     0,   498,    78,     0,     0,     0,     0,    80,   499,
      82,   500,   501,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   502,    97,    98,   503,   504,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,   107,
       0,     0,     0,     0,     0,     0,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   505,   120,   121,   506,
       0,     0,     0,     0,     0,     0,     0,   507,   508,   128,
       0,     0,     0,   129,     0,   130,   509,     0,     0,     0,
     134,     0,   135,     0,   136,   137,   138,   139,   510,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,     0,
       0,   411,   151,   152,   153,   154,   155,   156,   157,   158,
     511,   538,   512,   162,   513,   514,   165,   166,   167,   168,
     169,   170,   515,   172,   516,   517,   518,   176,   177,   519,
     520,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     0,     0,     0,   563,
     245,   521,   247,   248,   249,   250,   251,     7,     8,     0,
       0,     0,   774,     0,     0,     0,   408,   409,     0,    14,
      15,    16,   530,    18,    19,    20,   483,   531,   532,   485,
     486,   487,   410,    28,   488,    30,    31,     0,    32,    33,
      34,    35,   533,    37,   534,   535,    40,    41,    42,    43,
     490,     0,    45,   536,    47,   492,   493,    50,   494,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   495,   496,    68,     0,    69,    70,    71,
     537,     0,     0,    74,    75,    76,     0,     0,   498,    78,
       0,     0,     0,     0,    80,   499,    82,   500,   501,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   502,    97,
      98,   503,   504,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,   107,     0,     0,     0,     0,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   505,   120,   121,   506,     0,     0,     0,     0,
       0,     0,     0,   507,   508,   128,     0,     0,     0,   129,
     775,   130,   509,     0,     0,     0,     0,     0,   135,     0,
     136,   137,   138,   139,   510,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,     0,     0,   411,   151,   152,
     153,   154,   155,   156,   157,   158,   511,   538,   512,   162,
     513,   514,   165,   166,   167,   168,   169,   170,   515,   172,
     516,   517,   518,   176,   177,   519,   520,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     0,     0,     0,   563,   245,   521,   247,   248,
     249,   250,   251,     7,     8,     0,     0,     0,     0,     0,
       0,     0,   408,   409,     0,    14,    15,    16,   530,    18,
      19,    20,   483,   531,   532,   485,   486,   487,   410,    28,
     488,    30,    31,     0,    32,    33,    34,    35,   533,    37,
     534,   535,    40,    41,    42,    43,   490,     0,    45,   536,
      47,   492,   493,    50,   494,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   495,
     496,    68,     0,    69,    70,    71,   537,     0,     0,    74,
      75,    76,     0,     0,   498,    78,     0,     0,     0,     0,
      80,   499,    82,   500,   501,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   502,    97,    98,   503,   504,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,   107,     0,     0,     0,     0,     0,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   505,   120,
     121,   506,     0,     0,     0,     0,     0,     0,     0,   507,
     508,   128,     0,     0,     0,   129,     0,   130,   509,     0,
       0,     0,     0,     0,   135,     0,   136,   137,   138,   139,
     510,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,     0,     0,   411,   151,   152,   153,   154,   155,   156,
     157,   158,   511,   538,   512,   162,   513,   514,   165,   166,
     167,   168,   169,   170,   515,   172,   516,   517,   518,   176,
     177,   519,   520,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     0,     0,
       0,     0,   245,   521,   247,   248,   249,   250,   251,   566,
     567,     0,     0,     0,     0,     7,     8,     0,     0,     0,
       0,     0,     0,     0,   408,   409,     0,    14,    15,    16,
     530,    18,    19,    20,   483,   531,   532,   485,   486,   487,
     410,    28,   488,    30,    31,     0,    32,    33,    34,    35,
     533,    37,   534,   535,    40,    41,    42,    43,   490,     0,
      45,   536,    47,   492,   493,    50,   494,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   495,   496,    68,     0,    69,    70,    71,   537,     0,
       0,    74,    75,    76,     0,     0,   498,    78,     0,     0,
       0,     0,    80,   499,    82,   500,   501,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   502,    97,    98,   503,
     504,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,   105,   106,   107,     0,     0,     0,     0,     0,     0,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     505,   120,   121,   506,     0,     0,     0,     0,     0,     0,
       0,   507,   508,   128,     0,     0,     0,   129,     0,   130,
     509,     0,     0,     0,     0,     0,   135,     0,   136,   137,
     138,   139,   510,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,     0,     0,   411,   151,   152,   153,   154,
     155,   156,   157,   158,   511,   538,   512,   162,   513,   514,
     165,   166,   167,   168,   169,   170,   515,   172,   516,   517,
     518,   176,   177,   519,   520,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       0,     0,     0,     0,   245,   521,   247,   248,   249,   250,
     251,     4,     5,     6,     7,     8,     0,     0,     0,    11,
       0,     0,     0,   408,   409,     0,    14,    15,    16,   824,
      18,    19,    20,    21,   531,   825,   485,    25,   487,   410,
      28,   488,    30,    31,     0,    32,    33,    34,    35,   826,
      37,   534,   535,    40,    41,    42,    43,   490,     0,    45,
     827,    47,   492,   493,    50,   494,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     495,   496,    68,     0,    69,    70,    71,   828,     0,     0,
      74,    75,    76,     0,     0,   498,    78,     0,     0,     0,
      79,    80,   499,    82,   500,   501,    85,    86,   551,    88,
       0,     0,     0,     0,    90,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   502,    97,    98,   503,   504,
       0,     0,     0,     0,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   552,   109,     0,   110,   111,     0,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   506,     0,   123,     0,     0,     0,     0,     0,
     507,   508,   128,     0,     0,     0,   129,     0,   130,   509,
       0,     0,     0,     0,     0,   135,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,   149,     0,   411,   151,   152,   153,   154,   155,
     156,   157,   158,   511,   538,   512,   162,   513,   514,   165,
     166,   167,   168,   169,   170,   515,   172,   516,   517,   518,
     176,   177,   519,   520,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
       0,   244,     0,   245,   521,   247,   248,   249,   250,   251,
       7,     8,     0,     0,     0,     0,     0,     0,     0,   408,
     409,     0,    14,    15,    16,   482,    18,    19,    20,   483,
      22,   484,   485,  1127,   487,   410,    28,   488,    30,    31,
       0,    32,    33,    34,    35,   489,    37,    38,    39,    40,
      41,    42,    43,   490,     0,    45,   491,    47,   492,   493,
      50,   494,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   495,   496,    68,     0,
      69,    70,    71,   497,     0,     0,    74,    75,    76,     0,
       0,   498,    78,     0,     0,     0,     0,    80,   499,    82,
     500,   501,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   502,    97,    98,   503,   504,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,  1128,     0,
       0,     0,  1129,     0,     0,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   505,   120,   121,   506,     0,
       0,     0,     0,     0,     0,     0,   507,   508,   128,     0,
       0,     0,   129,  1549,   130,   509,     0,     0,     0,  1550,
       0,   135,     0,   136,   137,   138,   139,   510,   141,   142,
     143,   144,   145,   146,     0,     0,  1130,   148,     0,     0,
     411,   151,   152,   153,   154,   155,   156,   157,   158,   511,
     160,   512,   162,   513,   514,   165,   166,   167,   168,   169,
     170,   515,   172,   516,   517,   518,   176,   177,   519,   520,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     0,     0,     7,     8,   245,
     521,   247,  1131,  1132,  1133,  1134,   408,   409,     0,    14,
      15,    16,   530,    18,    19,    20,   483,   531,   532,   485,
     486,   487,   410,    28,   488,    30,    31,     0,    32,    33,
      34,    35,   533,    37,   534,   535,    40,    41,    42,    43,
     490,     0,    45,   536,    47,   492,   493,    50,   494,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   495,   496,    68,     0,    69,    70,    71,
     537,     0,     0,    74,    75,    76,     0,     0,   498,    78,
       0,     0,     0,     0,    80,   499,    82,   500,   501,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   502,    97,
      98,   503,   504,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,   107,     0,     0,     0,     0,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   505,   120,   121,   506,     0,     0,     0,     0,
       0,     0,     0,   507,   508,   128,     0,     0,     0,   129,
     745,   130,   509,     0,     0,     0,   746,     0,   135,     0,
     136,   137,   138,   139,   510,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,     0,     0,   411,   151,   152,
     153,   154,   155,   156,   157,   158,   511,   538,   512,   162,
     513,   514,   165,   166,   167,   168,   169,   170,   515,   172,
     516,   517,   518,   176,   177,   519,   520,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     0,     0,     7,     8,   245,   521,   247,   248,
     249,   250,   251,   408,   409,     0,    14,    15,    16,   530,
      18,    19,    20,   483,   531,   532,   485,   486,   487,   410,
      28,   488,    30,    31,     0,    32,    33,    34,    35,   533,
      37,   534,   535,    40,    41,    42,    43,   490,     0,    45,
     536,    47,   492,   493,    50,   494,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     495,   496,    68,     0,    69,    70,    71,   537,     0,     0,
      74,    75,    76,     0,     0,   498,    78,     0,     0,     0,
       0,    80,   499,    82,   500,   501,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   502,    97,    98,   503,   504,
       0,     0,     0,     0,     0,     0,   101,   102,   103,     0,
     105,   106,   107,     0,     0,     0,     0,     0,     0,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   505,
     120,   121,   506,     0,     0,     0,     0,     0,     0,     0,
     507,   508,   128,     0,     0,     0,   129,   792,   130,   509,
       0,     0,     0,   793,     0,   135,     0,   136,   137,   138,
     139,   510,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,     0,     0,   411,   151,   152,   153,   154,   155,
     156,   157,   158,   511,   538,   512,   162,   513,   514,   165,
     166,   167,   168,   169,   170,   515,   172,   516,   517,   518,
     176,   177,   519,   520,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     7,     8,   245,   521,   247,   248,   249,   250,   251,
     408,   409,     0,    14,    15,    16,   482,    18,    19,    20,
     483,    22,   484,   485,  1127,   487,   410,    28,   488,    30,
      31,     0,    32,    33,    34,    35,   489,    37,    38,    39,
      40,    41,    42,    43,   490,     0,    45,   491,    47,   492,
     493,    50,   494,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   495,   496,    68,
       0,    69,    70,    71,   497,     0,     0,    74,    75,    76,
       0,     0,   498,    78,     0,     0,     0,     0,    80,   499,
      82,   500,   501,    85,    86,  1468,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   502,    97,    98,   503,   504,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,  1128,
       0,     0,     0,  1129,     0,     0,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   505,   120,   121,   506,
       0,     0,     0,     0,     0,     0,     0,   507,   508,   128,
       0,     0,     0,   129,     0,   130,   509,     0,     0,     0,
       0,     0,   135,     0,   136,   137,   138,   139,   510,   141,
     142,   143,   144,   145,   146,     0,     0,  1130,   148,     0,
       0,   411,   151,   152,   153,   154,   155,   156,   157,   158,
     511,   160,   512,   162,   513,   514,   165,   166,   167,   168,
     169,   170,   515,   172,   516,   517,   518,   176,   177,   519,
     520,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     0,     0,     7,     8,
     245,   521,   247,  1131,  1132,  1133,  1134,   408,   409,     0,
      14,    15,    16,   482,    18,    19,    20,   483,    22,   484,
     485,  1127,   487,   410,    28,   488,    30,    31,     0,    32,
      33,    34,    35,   489,    37,    38,    39,    40,    41,    42,
      43,   490,     0,    45,   491,    47,   492,   493,    50,   494,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,   495,   496,    68,     0,    69,    70,
      71,   497,     0,     0,    74,    75,    76,     0,     0,   498,
      78,     0,     0,     0,     0,    80,   499,    82,   500,   501,
      85,    86,  1606,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   502,
      97,    98,   503,   504,     0,     0,     0,     0,     0,     0,
     101,   102,   103,     0,   105,   106,  1128,     0,     0,     0,
    1129,     0,     0,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   505,   120,   121,   506,     0,     0,     0,
       0,     0,     0,     0,   507,   508,   128,     0,     0,     0,
     129,     0,   130,   509,     0,     0,     0,     0,     0,   135,
       0,   136,   137,   138,   139,   510,   141,   142,   143,   144,
     145,   146,     0,     0,  1130,   148,     0,     0,   411,   151,
     152,   153,   154,   155,   156,   157,   158,   511,   160,   512,
     162,   513,   514,   165,   166,   167,   168,   169,   170,   515,
     172,   516,   517,   518,   176,   177,   519,   520,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     0,     0,     7,     8,   245,   521,   247,
    1131,  1132,  1133,  1134,   408,   409,     0,    14,    15,    16,
     482,    18,    19,    20,   483,    22,   484,   485,  1127,   487,
     410,    28,   488,    30,    31,     0,    32,    33,    34,    35,
     489,    37,    38,    39,    40,    41,    42,    43,   490,     0,
      45,   491,    47,   492,   493,    50,   494,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   495,   496,    68,     0,    69,    70,    71,   497,     0,
       0,    74,    75,    76,     0,     0,   498,    78,     0,     0,
       0,     0,    80,   499,    82,   500,   501,    85,    86,  1610,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   502,    97,    98,   503,
     504,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,   105,   106,  1128,     0,     0,     0,  1129,     0,     0,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     505,   120,   121,   506,     0,     0,     0,     0,     0,     0,
       0,   507,   508,   128,     0,     0,     0,   129,     0,   130,
     509,     0,     0,     0,     0,     0,   135,     0,   136,   137,
     138,   139,   510,   141,   142,   143,   144,   145,   146,     0,
       0,  1130,   148,     0,     0,   411,   151,   152,   153,   154,
     155,   156,   157,   158,   511,   160,   512,   162,   513,   514,
     165,   166,   167,   168,   169,   170,   515,   172,   516,   517,
     518,   176,   177,   519,   520,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       0,     0,     7,     8,   245,   521,   247,  1131,  1132,  1133,
    1134,   408,   409,     0,    14,    15,    16,   482,    18,    19,
      20,   483,    22,   484,   485,  1127,   487,   410,    28,   488,
      30,    31,     0,    32,    33,    34,    35,   489,    37,    38,
      39,    40,    41,    42,    43,   490,     0,    45,   491,    47,
     492,   493,    50,   494,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,   495,   496,
      68,     0,    69,    70,    71,   497,     0,     0,    74,    75,
      76,     0,     0,   498,    78,     0,     0,     0,     0,    80,
     499,    82,   500,   501,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   502,    97,    98,   503,   504,     0,     0,
       0,     0,     0,     0,   101,   102,   103,     0,   105,   106,
    1128,     0,     0,     0,  1129,     0,     0,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   505,   120,   121,
     506,     0,     0,     0,     0,     0,     0,     0,   507,   508,
     128,     0,     0,     0,   129,     0,   130,   509,     0,     0,
       0,     0,     0,   135,     0,   136,   137,   138,   139,   510,
     141,   142,   143,   144,   145,   146,     0,     0,  1130,   148,
       0,     0,   411,   151,   152,   153,   154,   155,   156,   157,
     158,   511,   160,   512,   162,   513,   514,   165,   166,   167,
     168,   169,   170,   515,   172,   516,   517,   518,   176,   177,
     519,   520,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,     0,     0,     7,
       8,   245,   521,   247,  1131,  1132,  1133,  1134,   408,   409,
       0,    14,    15,    16,   482,    18,    19,    20,   483,    22,
     484,   485,  1127,   487,   410,    28,   488,    30,    31,     0,
      32,    33,    34,    35,   489,    37,    38,    39,    40,    41,
      42,    43,   490,     0,    45,   491,    47,   492,   493,    50,
     494,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,   495,   496,    68,     0,    69,
      70,    71,   497,     0,     0,    74,    75,    76,     0,     0,
     498,    78,     0,     0,     0,     0,    80,   499,    82,   500,
     501,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     502,    97,    98,   503,   504,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,  1128,     0,     0,
       0,  1129,     0,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   505,   120,   121,   506,     0,     0,
       0,     0,     0,     0,     0,   507,   508,   128,     0,     0,
       0,   129,     0,   130,   509,     0,     0,     0,     0,     0,
     135,     0,   136,   137,   138,   139,   510,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,     0,     0,   411,
     151,   152,   153,   154,   155,   156,   157,   158,   511,   160,
     512,   162,   513,   514,   165,   166,   167,   168,   169,   170,
     515,   172,   516,   517,   518,   176,   177,   519,   520,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,     0,     0,     7,     8,   245,   521,
     247,  1131,  1132,  1133,  1134,   408,   409,     0,    14,    15,
      16,   530,    18,    19,    20,   483,   531,   532,   485,   486,
     487,   410,    28,   488,    30,    31,     0,    32,    33,    34,
      35,   533,    37,   534,   535,    40,    41,    42,    43,   490,
       0,    45,   536,    47,   492,   493,    50,   494,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   495,   496,    68,     0,    69,    70,    71,   537,
       0,     0,    74,    75,    76,     0,     0,   498,    78,     0,
       0,     0,     0,    80,   499,    82,   500,   501,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   502,    97,    98,
     503,   504,     0,     0,     0,     0,     0,     0,   101,   102,
     103,     0,   105,   106,   107,     0,     0,     0,     0,     0,
       0,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   505,   120,   121,   506,     0,     0,     0,     0,     0,
       0,     0,   507,   508,   128,     0,     0,     0,   129,     0,
     130,   509,     0,     0,     0,     0,     0,   135,     0,   136,
     137,   138,   139,   510,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,     0,     0,   411,   151,   152,   153,
     154,   155,   156,   157,   158,   511,   538,   512,   162,   513,
     514,   165,   166,   167,   168,   169,   170,   515,   172,   516,
     517,   518,   176,   177,   519,   520,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,     0,     0,     7,     8,   245,   521,   247,   248,   249,
     250,   251,   408,   409,     0,    14,    15,    16,     0,    18,
      19,    20,   483,     0,     0,   485,   486,     0,   410,    28,
     488,    30,    31,     0,    32,    33,    34,    35,     0,    37,
       0,     0,    40,    41,    42,    43,   490,     0,    45,     0,
      47,     0,     0,    50,   494,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   495,
     496,    68,     0,    69,    70,    71,     0,     0,     0,    74,
      75,    76,     0,     0,   498,    78,     0,     0,     0,     0,
      80,   499,    82,   500,   501,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   502,    97,    98,   503,   504,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,     0,     0,     0,     0,     0,     0,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   505,   120,
     121,   506,     0,     0,     0,     0,     0,     0,     0,   507,
     508,   128,     0,     0,     0,   129,     0,   130,   509,     0,
       0,     0,     0,     0,   135,     0,   136,   137,   138,   139,
     510,   141,   142,   143,   144,   145,   146,     0,     0,     0,
     148,     0,     0,   411,   151,   152,   153,   154,   155,   156,
     157,   158,   511,     0,   512,   162,   513,   514,   165,   166,
     167,   168,   169,   170,   515,   172,   516,   517,   518,   176,
     177,     0,   520,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     0,     0,
       0,     0,   245,   521,   247,   248,   249,   250,   251
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,   179,    12,   812,     4,     5,     6,   892,     0,     4,
       5,     6,     4,     5,     6,   417,   418,   769,   661,   310,
     290,   662,   663,   664,   665,   338,   259,   419,   258,   781,
     752,  1035,   850,  1019,   133,  1285,   752,    73,   905,   906,
     926,   274,   107,   795,   579,  1347,  1348,   612,   613,  1268,
     585,    36,  1059,     4,     5,     6,   431,  1113,  1202,   610,
     611,   612,   613,  1380,   107,   457,   458,   442,   610,   611,
      36,    55,   942,    26,    27,   942,    96,   706,   147,    26,
      27,     1,    94,     1,    26,    27,     9,    10,    29,   118,
     465,     4,     5,     6,    47,    37,    38,    29,    40,    41,
      47,    30,   107,    56,   906,    47,     1,     1,   108,   976,
     142,    96,     1,     1,    56,    57,   108,   281,     1,   118,
     118,    74,  1571,   131,   147,    96,    79,    74,    94,   996,
      96,  1298,    74,    93,   107,   107,   640,    79,   642,   643,
     136,   645,  1009,   647,   414,    94,   107,    73,   224,     8,
     226,   655,   656,   156,   169,    45,   160,   108,   111,   112,
     113,    87,   147,    37,    38,   112,    40,    41,   224,   111,
     112,   113,    62,   229,    24,   130,   147,    76,   110,   156,
     103,   147,   190,    57,    34,   111,   201,    54,   187,    56,
      94,   224,   124,   226,   996,   108,   948,   123,   147,   125,
     123,   153,   125,   272,   200,   217,   218,  1009,   109,   110,
      60,  1513,    94,   121,   187,    96,   188,   149,   160,   160,
     232,   153,   107,   183,   156,    29,   224,   232,  1113,  1114,
     153,   224,   216,   100,   157,   255,   256,   313,   142,   113,
     272,   196,   341,   272,     5,   177,  1055,   312,     9,   272,
    1002,   174,   252,  1570,   153,   255,  1008,   313,   107,  1129,
     252,  1265,  1129,   255,  1483,  1251,   557,   310,  1717,   253,
     190,   194,   190,   234,   438,   545,  1420,   219,  1164,  1001,
     313,    96,  1289,   999,   213,  1001,   160,   272,   169,   212,
     290,  1298,    52,   858,   859,   190,   190,   187,   290,   928,
    1356,   190,   190,   188,    29,  1021,   272,   190,   306,   113,
     346,     9,    10,   349,   856,   857,   175,   107,   260,  1486,
     313,   220,   221,   107,   232,   717,   258,   107,   107,   153,
       5,    26,    27,   286,     9,   217,   218,   153,   187,   286,
    1207,   294,   243,   244,   286,   219,   100,   294,   100,   302,
     232,   118,   294,   177,   169,   182,   160,   156,   628,     9,
     302,   100,   123,   156,   125,   107,  1668,   130,   195,   129,
     251,   252,   133,   254,   607,   767,  1243,    45,    28,    47,
     610,   611,  1632,   250,   888,   110,   260,   107,   763,   290,
     271,   766,   153,   209,   107,   118,   263,   187,   265,   124,
    1267,    45,   283,    47,   107,   103,   190,   187,   187,   276,
     277,   278,    94,   280,   414,   282,   107,   112,  1720,   186,
     346,   107,   414,   349,   149,   123,   107,   125,   153,  1573,
     107,   156,   186,   196,   186,    79,   251,   252,   106,   254,
      42,  1243,   184,   443,    46,   445,   261,   186,   123,    51,
     125,   443,   177,   445,  1206,   153,   271,    96,   133,   157,
     142,   107,   106,   186,   184,  1267,   736,    69,   283,   469,
     158,  1356,   185,   123,   474,   125,   174,   469,   153,  1486,
    1365,   184,   474,    94,   134,   107,   153,  1706,   176,   156,
     892,  1376,   443,   184,   445,  1217,   194,   107,   424,   185,
     168,   427,   158,   153,    29,   431,   187,   184,   434,   435,
    1226,   107,  1330,   414,   212,  1333,   442,   156,   469,   921,
     176,  1388,   448,   474,   168,   451,   137,   153,   107,  1673,
     443,   142,   445,   459,  1099,  1100,  1101,   107,   184,   465,
     466,   467,   468,   107,  1079,   545,   447,   473,  1099,  1100,
    1101,   107,   552,   545,   455,   481,   469,   949,   950,   137,
     552,   474,   954,   464,   142,   187,   168,   107,   107,   171,
     471,   472,     9,    10,  1718,     9,    10,   187,   848,   480,
     268,   680,   681,   209,   186,   110,  1388,   275,   107,    42,
     107,   187,   984,    46,   594,   605,   107,   285,    51,   124,
     526,   552,   594,  1470,   107,   107,  1473,  1593,   187,   211,
     610,   611,   612,   613,   540,   107,    69,   187,   610,   611,
     612,   613,   107,   187,   149,   551,   856,  1631,   628,   862,
     107,   187,   107,   122,   158,    53,   628,   106,   156,   552,
      58,   107,   107,   594,   545,   184,  1790,   187,  1792,   107,
      96,    94,   176,   579,   117,  1540,    39,  1801,   127,   585,
     561,    44,    45,   589,   153,   184,   103,   156,  1470,   103,
     187,  1473,   573,   184,   198,  1484,    59,    66,    61,    62,
    1489,    96,    71,   146,   187,   187,   123,    70,   125,   123,
      42,   125,   593,   594,    46,   187,   159,   156,   113,    51,
     144,   147,   187,    53,   147,   154,     9,   156,    58,   184,
     187,  1113,  1114,  1435,    97,   168,   153,    69,   171,   153,
     157,   187,   187,   157,  1367,    28,   184,    77,    96,   118,
     193,   153,   176,   186,   158,   216,   736,   174,  1695,  1696,
     174,   156,   246,   247,   736,   113,    96,   156,    53,   193,
      33,   118,   176,    58,   166,   177,   182,   194,   211,   759,
     194,   990,    95,   992,   759,   269,    49,   759,   118,   195,
     182,  1336,   253,   106,   198,   212,   677,   137,   212,  1736,
      33,   682,   142,   116,  1651,  1742,  1653,   713,   156,   789,
     790,    96,   148,   148,   127,    96,    49,   789,   790,  1090,
     153,   727,  1115,   156,   136,   731,   732,  1616,   759,   165,
     165,  1620,   113,  1042,  1084,  1044,   168,  1684,   150,   171,
     123,   200,   125,   100,   122,   153,   268,   753,   156,   755,
     209,   134,   100,   275,   186,   736,   113,   763,   789,   790,
     766,   224,   137,   285,   770,   113,   759,  1714,   848,  1651,
     153,  1653,   137,   100,  1246,    94,   848,   867,   153,   211,
     100,   132,  1729,   156,  1731,   100,   113,   106,   153,   140,
     141,   614,   143,   113,   100,   618,   789,   790,   113,   122,
     151,   939,  1684,  1524,   155,   811,   157,   113,  1531,  1532,
    1699,   162,   298,   951,   683,   156,   262,   686,   262,   122,
     689,   307,   803,   804,   805,   118,   807,   273,   179,   273,
    1088,   153,  1714,   267,   156,  1093,  1668,   276,   277,   278,
     274,   348,   122,   282,   850,   122,   353,  1729,   118,  1731,
     122,   202,   203,   204,   205,   206,   207,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,   191,   192,   875,
     231,  1343,   233,   122,  1356,   220,   221,   222,   231,   153,
     233,   128,   129,  1365,   128,   129,   659,   660,   122,   666,
     667,   122,   668,   669,  1376,  1245,   907,   908,   122,   905,
     906,   907,   908,  1561,  1562,   122,   215,   153,   156,   118,
     240,   240,   153,   241,   156,   313,  1639,  1640,     0,   107,
      92,   190,   167,   248,    99,    50,    73,   101,   199,   102,
     145,   156,   154,   184,   184,    29,   942,    47,   152,   118,
      87,   184,   118,   245,   303,   283,   283,   187,   153,     1,
     956,   118,   142,   107,   187,   153,   153,  1037,   142,   121,
     156,   156,   156,   156,   111,  1037,   184,   156,    35,   156,
     156,   156,   153,    17,   213,   981,   123,   187,   125,  1329,
    1452,    29,   190,   190,   990,   244,   992,  1710,     3,   118,
     996,   168,   230,   229,    70,   230,    94,    94,    94,   170,
     170,   149,   107,  1009,  1084,   107,  1037,    29,  1098,   160,
     160,   127,  1084,   132,    94,   245,   298,   118,   142,  1099,
    1100,  1101,   187,   132,   184,   184,   187,  1099,  1100,  1101,
     107,    94,    96,    45,    96,   187,  1042,    94,  1044,   153,
     153,   187,   187,   187,  1037,  1517,   184,   184,   156,   153,
     153,   142,   230,   153,   153,   224,   236,   190,  1540,   198,
      33,   156,   118,   170,   132,    94,    29,   142,   226,   285,
      94,   298,   153,  1079,   127,   118,   118,   147,   118,   197,
      94,   132,   160,   132,   153,   253,    96,   118,   147,   100,
      35,   184,   100,   153,   184,   184,   142,    29,   190,   118,
     121,   156,  1108,   244,    79,   107,   156,   107,   153,   156,
     259,   266,    29,    29,  1464,   257,   144,   156,   284,   156,
     156,   156,   156,  1129,   156,    29,   156,   144,   285,   190,
    1210,  1112,   127,   286,   147,  1210,   118,   118,  1210,   226,
     147,   305,   147,    77,   142,   107,   187,   100,   132,   187,
       7,   236,    96,   232,   187,   156,   106,   106,   184,   232,
     187,   232,   187,   249,   187,  1245,   232,   147,   285,   281,
      78,   187,   190,  1245,    29,   249,  1256,   197,   187,  1210,
     186,  1256,    29,   187,  1256,   107,   270,   170,   187,   147,
     187,   187,   184,   187,   187,  1275,   187,   187,   256,   346,
    1275,   147,   349,  1275,    96,   126,   126,   184,   186,   315,
    1216,    94,   186,  1219,   186,  1295,   186,  1210,   184,   184,
     184,    94,   153,  1295,    29,  1256,   187,    96,  1234,   170,
     187,    53,   286,   147,    94,   186,   196,  1243,   186,    29,
     187,  1591,   197,    94,  1275,   107,   107,   118,  1328,  1329,
     118,  1257,  1602,  1603,    94,  1605,  1328,  1329,   186,    94,
     196,  1267,  1612,  1256,  1295,   224,   196,   236,   118,    93,
     224,   186,   183,   186,   118,   264,   423,   424,   196,   118,
     427,   186,  1275,   186,   431,   186,   198,   434,   435,   292,
    1296,   279,   118,   716,   943,   442,  1167,  1328,   224,  1010,
     286,   448,  1295,   255,   451,  1207,   438,   418,  1673,   252,
    1718,   851,   459,   255,  1007,  1321,  1216,   304,   465,   466,
     467,   468,   772,   258,  1330,   304,   473,  1333,   304,  1235,
    1445,  1350,  1352,  1347,   481,  1104,   540,   305,   305,  1257,
    1262,  1265,  1692,  1270,  1325,  1326,  1327,   638,   658,   305,
     639,   691,  1289,  1742,   812,  1705,  1736,   908,   446,  1201,
     992,  1321,  1166,   334,  1331,  1540,  1330,  1369,  1365,  1376,
    1114,  1537,  1123,   975,   446,  1189,  1564,  1411,    -1,   526,
    1730,  1366,  1388,   583,  1464,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1464,   540,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   551,    -1,    -1,    -1,    -1,    -1,
    1416,    -1,  1762,    -1,    -1,    -1,   108,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1784,    -1,  1442,  1443,    -1,  1789,
      -1,    -1,   589,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1468,    -1,  1470,    -1,    -1,  1473,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1485,
      -1,    -1,    -1,    -1,  1490,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1591,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1591,
      -1,    -1,  1602,  1603,    -1,  1605,    -1,    -1,    -1,    -1,
    1602,  1603,  1612,  1605,    -1,    -1,    -1,    -1,    -1,    -1,
    1612,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   710,    -1,    -1,   713,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     727,    -1,    -1,    -1,   731,   732,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1606,    -1,  1608,    -1,  1610,    -1,   753,    -1,   755,    -1,
      -1,  1617,  1692,    -1,    -1,    -1,   763,    -1,    -1,   766,
    1692,    -1,    -1,   770,    -1,  1705,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1705,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1651,    -1,  1653,    -1,    -1,
    1730,    -1,  1633,    -1,    -1,    -1,    -1,    -1,  1730,    -1,
      -1,    -1,    -1,  1669,   811,    -1,  1672,    -1,  1649,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1684,    -1,
      -1,    -1,  1762,    -1,    -1,    -1,    -1,    -1,  1694,    -1,
    1762,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   850,  1784,    -1,    -1,    -1,  1714,  1789,
      -1,    -1,  1784,    -1,    -1,    -1,  1722,  1789,    -1,    -1,
      -1,  1727,    -1,  1729,    -1,  1731,    -1,    -1,   875,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1759,    -1,    -1,    -1,    -1,   905,   906,
     907,   908,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1776,    -1,    -1,    -1,  1780,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1796,    -1,    -1,  1799,    -1,   942,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   956,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   981,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   990,    -1,   992,    -1,    -1,    -1,   996,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     552,    -1,  1009,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   577,   578,    -1,    -1,   581,
     582,   583,   584,    -1,   586,  1042,    -1,  1044,    -1,    -1,
     592,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   600,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   620,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   628,   629,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   688,    -1,    -1,   691,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   729,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1216,
      -1,    -1,  1219,    -1,    -1,    -1,    -1,    -1,    -1,   771,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1234,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1243,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   796,    -1,    -1,    -1,   800,   801,
    1257,    -1,    -1,    -1,    -1,    -1,    -1,   809,    -1,    -1,
    1267,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1296,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1321,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1330,    -1,   877,  1333,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1388,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   944,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1416,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   979,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1442,  1443,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   998,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1468,    -1,  1470,    -1,    -1,  1473,    -1,  1020,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1485,  1031,
    1032,    -1,    -1,  1490,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1046,    -1,    -1,  1049,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1064,    -1,  1066,  1067,  1068,    -1,  1070,  1071,
    1072,  1073,  1074,  1075,  1076,  1077,  1078,    -1,    -1,  1081,
    1082,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1095,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1606,
      -1,  1608,  1154,  1610,    -1,    -1,    -1,    -1,    -1,    -1,
    1617,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1651,    -1,  1653,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1669,    -1,    -1,  1672,    -1,    -1,    -1,  1221,
      -1,  1223,    -1,  1225,    -1,    -1,  1228,  1684,    -1,    -1,
      -1,  1233,    -1,    -1,    -1,    -1,    -1,  1694,    -1,    -1,
      -1,    -1,    -1,  1245,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1254,    -1,    -1,    -1,    -1,  1714,  1260,  1261,
      -1,    -1,    -1,    -1,    -1,  1722,    -1,    -1,    -1,    -1,
    1727,    -1,  1729,    -1,  1731,    -1,    -1,  1279,    -1,    -1,
    1282,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1759,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1776,
      -1,    -1,    -1,  1780,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1796,
      -1,    -1,  1799,    -1,    -1,    -1,    -1,    -1,  1350,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1429,    -1,    -1,
      -1,  1433,    -1,    -1,    -1,  1437,    -1,  1439,    -1,  1441,
      -1,    -1,    -1,    -1,    -1,  1447,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1455,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1463,  1464,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1482,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1494,  1495,  1496,  1497,    -1,    -1,  1500,  1501,
      -1,  1503,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1579,    -1,  1581,
      -1,    -1,  1584,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1592,    -1,    -1,    -1,    -1,  1597,  1598,    -1,    -1,    -1,
      -1,    -1,    -1,  1605,    -1,    -1,    -1,  1609,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1625,  1626,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1676,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1688,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1730,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1748,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1757,    -1,    -1,    -1,    -1,
    1762,    11,    12,    -1,    -1,  1767,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      -1,  1783,    -1,    33,    34,  1787,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    98,    -1,
     100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,    -1,    -1,    -1,   124,    -1,   126,   127,   128,   129,
      -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,   139,
      -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    -1,   156,   157,   158,   159,
     160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,
      -1,   191,   192,   193,    -1,   195,    -1,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,    -1,    -1,
     210,   211,   212,    -1,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,   258,   259,
     260,    -1,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
      -1,   311,    -1,   313,   314,   315,   316,   317,   318,   319,
     320,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    98,    -1,
     100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,    -1,    -1,    -1,   124,    -1,   126,   127,   128,   129,
      -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,   139,
      -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    -1,   156,   157,   158,   159,
     160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,
     180,   181,   182,    -1,   184,    -1,   186,    -1,   188,   189,
      -1,   191,   192,   193,    -1,   195,    -1,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,    -1,    -1,
     210,   211,   212,    -1,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,   258,   259,
     260,    -1,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
      -1,   311,    -1,   313,   314,   315,   316,   317,   318,   319,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    29,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    98,    -1,   100,
     101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      -1,    -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,
     131,    -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,   156,   157,   158,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,
     181,   182,    -1,   184,    -1,   186,    -1,   188,   189,    -1,
     191,   192,   193,    -1,   195,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,    -1,   210,
     211,   212,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,    -1,
     311,    -1,   313,   314,   315,   316,   317,   318,   319,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,   158,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,   184,    -1,   186,    -1,   188,   189,    -1,   191,
     192,   193,    -1,   195,    -1,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,    -1,    -1,   210,   211,
     212,    -1,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,   258,   259,   260,    -1,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,    -1,   311,
      -1,   313,   314,   315,   316,   317,   318,   319,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    29,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    98,    -1,   100,   101,   102,
      -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,    -1,    -1,
      -1,   124,    -1,   126,   127,   128,   129,    -1,   131,    -1,
      -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,   156,   157,   158,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,   184,    -1,   186,    -1,   188,   189,    -1,   191,   192,
     193,    -1,   195,    -1,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,    -1,    -1,   210,   211,   212,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,    -1,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,    -1,   311,    -1,
     313,   314,   315,   316,   317,   318,   319,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    98,    -1,   100,   101,   102,    -1,
      -1,   105,   106,    -1,    -1,    -1,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,    -1,    -1,    -1,
     124,    -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,
      -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   147,   148,   149,   150,   151,   152,   153,
     154,    -1,   156,   157,   158,   159,   160,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
     174,    -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,    -1,   188,   189,    -1,   191,   192,   193,
      -1,   195,    -1,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,    -1,    -1,   210,   211,   212,    -1,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,    -1,   311,    -1,   313,
     314,   315,   316,   317,   318,   319,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    97,    98,    -1,   100,   101,   102,    -1,    -1,
     105,   106,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    -1,    -1,    -1,   124,
      -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,
     135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,
      -1,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      -1,   156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,   189,    -1,   191,   192,   193,    -1,
     195,    -1,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,    -1,    -1,   210,   211,   212,    -1,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,    -1,   258,   259,   260,    -1,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,    -1,   311,    -1,   313,   314,
     315,   316,   317,   318,   319,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
     176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,   191,   192,   193,    -1,   195,
      -1,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,    -1,    -1,   210,   211,   212,    -1,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,    -1,   311,    -1,   313,   314,   315,
     316,   317,   318,   319,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    98,    -1,   100,   101,   102,    -1,    -1,   105,   106,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,   126,
     127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,
     137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,   156,
     157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,   174,    -1,   176,
     177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
      -1,   188,   189,    -1,   191,   192,   193,    -1,   195,    -1,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,    -1,    -1,   210,   211,   212,    -1,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
      -1,   258,   259,   260,    -1,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,    -1,   311,    -1,   313,   314,   315,   316,
     317,   318,   319,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      98,    -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,    -1,    -1,    -1,   124,    -1,   126,   127,
     128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,
     138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,
     148,   149,   150,   151,   152,   153,   154,    -1,   156,   157,
     158,   159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,   174,    -1,   176,   177,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,
     188,   189,    -1,   191,   192,   193,    -1,   195,    -1,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
      -1,    -1,   210,   211,   212,    -1,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
     258,   259,   260,    -1,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,    -1,   311,    -1,   313,   314,   315,   316,   317,
     318,   319,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    98,
      -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,
      -1,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,    -1,    -1,   124,    -1,   126,   127,   128,
     129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,
     139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,   156,   157,   158,
     159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,   174,    -1,   176,   177,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,
     189,    -1,   191,   192,   193,    -1,   195,    -1,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,    -1,
      -1,   210,   211,   212,    -1,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,   258,
     259,   260,    -1,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,    -1,   311,    -1,   313,   314,   315,   316,   317,   318,
     319,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    98,    -1,
     100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,    -1,    -1,    -1,   124,    -1,   126,   127,   128,   129,
      -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,   139,
      -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    -1,   156,   157,   158,   159,
     160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,
     180,   181,   182,    -1,    -1,   185,   186,    -1,   188,   189,
      -1,   191,   192,   193,    -1,   195,    -1,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,    -1,    -1,
     210,   211,   212,    -1,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,   258,   259,
     260,    -1,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
      -1,   311,    -1,   313,   314,   315,   316,   317,   318,   319,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    98,    -1,   100,
     101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      -1,    -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,
     131,    -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,   156,   157,   158,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,   187,   188,   189,    -1,
     191,   192,   193,    -1,   195,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,    -1,   210,
     211,   212,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,    -1,
     311,    -1,   313,   314,   315,   316,   317,   318,   319,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,   158,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,
     192,   193,    -1,   195,    -1,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,    -1,    -1,   210,   211,
     212,    -1,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,   258,   259,   260,    -1,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
      -1,   313,   314,   315,   316,   317,   318,   319,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    98,    -1,   100,   101,   102,
      -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,    -1,    -1,
      -1,   124,    -1,   126,   127,   128,   129,    -1,   131,    -1,
      -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,   156,   157,   158,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,   192,
     193,    -1,   195,    -1,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,    -1,    -1,   210,   211,   212,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,    -1,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,    -1,   311,   312,
     313,   314,   315,   316,   317,   318,   319,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    98,    -1,   100,   101,   102,    -1,
      -1,   105,   106,    -1,    -1,    -1,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,    -1,    -1,    -1,
     124,    -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,
      -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   147,   148,   149,   150,   151,   152,   153,
     154,    -1,   156,   157,   158,   159,   160,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
     174,    -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,
     184,    -1,   186,    -1,   188,   189,    -1,   191,   192,   193,
      -1,   195,    -1,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,    -1,    -1,   210,   211,   212,    -1,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,    -1,   311,    -1,   313,
     314,   315,   316,   317,   318,   319,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    97,    98,    -1,   100,   101,   102,    -1,    -1,
     105,   106,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    -1,    -1,    -1,   124,
      -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,
     135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,
      -1,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      -1,   156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,   187,   188,   189,    -1,   191,   192,   193,    -1,
     195,    -1,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,    -1,    -1,   210,   211,   212,    -1,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,    -1,   258,   259,   260,    -1,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,    -1,   311,    -1,   313,   314,
     315,   316,   317,   318,   319,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
     176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,   187,   188,   189,    -1,   191,   192,   193,    -1,   195,
      -1,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,    -1,    -1,   210,   211,   212,    -1,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,    -1,   311,    -1,   313,   314,   315,
     316,   317,   318,   319,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    98,    -1,   100,   101,   102,    -1,    -1,   105,   106,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,   126,
     127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,
     137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,   156,
     157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,   174,    -1,   176,
     177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
      -1,   188,   189,    -1,   191,   192,   193,    -1,   195,    -1,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,    -1,    -1,   210,   211,   212,    -1,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
      -1,   258,   259,   260,    -1,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,    -1,   311,    -1,   313,   314,   315,   316,
     317,   318,   319,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      98,    -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,    -1,    -1,    -1,   124,    -1,   126,   127,
     128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,
     138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,
     148,   149,   150,   151,   152,   153,   154,    -1,   156,   157,
     158,   159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,   174,    -1,   176,   177,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,
     188,   189,    -1,   191,   192,   193,    -1,   195,    -1,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
      -1,    -1,   210,   211,   212,    -1,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
     258,   259,   260,    -1,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,    -1,   311,    -1,   313,   314,   315,   316,   317,
     318,   319,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    98,
      -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,
      -1,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,    -1,    -1,   124,    -1,   126,   127,   128,
     129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,
     139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,   156,   157,   158,
     159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,   174,    -1,   176,   177,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,
     189,    -1,   191,   192,   193,    -1,   195,    -1,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,    -1,
      -1,   210,   211,   212,    -1,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,   258,
     259,   260,    -1,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,    -1,   311,    -1,   313,   314,   315,   316,   317,   318,
     319,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    98,    -1,
     100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,    -1,    -1,    -1,   124,    -1,   126,   127,   128,   129,
      -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,   139,
      -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    -1,   156,   157,    -1,   159,
     160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,   174,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,
      -1,   191,   192,   193,    -1,   195,    -1,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,    -1,    -1,
     210,   211,   212,    -1,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,   258,   259,
     260,    -1,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
      -1,   311,    -1,   313,   314,   315,   316,   317,   318,   319,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    98,    -1,   100,
     101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      -1,    -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,
     131,    -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,   156,   157,    -1,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,   174,    -1,    -1,    -1,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,
      -1,    -1,   193,    -1,   195,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,    -1,   210,
     211,   212,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,    -1,
     311,    -1,   313,   314,   315,   316,   317,   318,   319,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,    -1,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,   149,    -1,   151,
     152,   153,   154,    -1,   156,   157,    -1,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,
      -1,   193,    -1,   195,    -1,   197,    -1,   199,    -1,   201,
     202,   203,   204,   205,   206,   207,    -1,    -1,   210,   211,
     212,    -1,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,   258,   259,   260,    -1,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,    -1,   311,
      -1,   313,   314,   315,   316,   317,   318,   319,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    -1,    -1,   100,   101,   102,
      -1,    -1,   105,   106,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   127,   128,   129,    -1,   131,    -1,
      -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,    -1,   150,   151,   152,
      -1,    -1,    -1,    -1,    -1,    -1,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,
     193,    -1,   195,    -1,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,    -1,    -1,   210,   211,    -1,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,    -1,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,    -1,    -1,    11,    12,
     313,   314,   315,   316,   317,   318,   319,    20,    -1,    -1,
      -1,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    -1,    -1,   100,   101,   102,
      -1,    -1,   105,   106,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   127,   128,   129,    -1,   131,    -1,
      -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,    -1,   150,   151,   152,
      -1,    -1,    -1,    -1,    -1,    -1,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,
     193,    -1,   195,    -1,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,    -1,    -1,   210,   211,    -1,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,    -1,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,    -1,    -1,    -1,    16,
     313,   314,   315,   316,   317,   318,   319,    24,    25,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    -1,    -1,   100,   101,   102,    -1,    -1,   105,   106,
      -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,
     137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,    -1,   150,   151,   152,    -1,    -1,    -1,    -1,
      -1,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
     187,   188,   189,    -1,    -1,    -1,    -1,    -1,   195,    -1,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,    -1,    -1,   210,   211,    -1,    -1,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
      -1,   258,   259,   260,    -1,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,    -1,    -1,    -1,    16,   313,   314,   315,   316,
     317,   318,   319,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    -1,    -1,   100,
     101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,    -1,
     131,    -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,    -1,   150,
     151,   152,    -1,    -1,    -1,    -1,    -1,    -1,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,
      -1,    -1,    -1,    -1,   195,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,    -1,   210,
     211,    -1,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,    -1,    -1,
      -1,    -1,   313,   314,   315,   316,   317,   318,   319,    18,
      19,    -1,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    -1,
      -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,
     139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,
      -1,   150,   151,   152,    -1,    -1,    -1,    -1,    -1,    -1,
     159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,
     189,    -1,    -1,    -1,    -1,    -1,   195,    -1,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,    -1,
      -1,   210,   211,    -1,    -1,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,   258,
     259,   260,    -1,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
      -1,    -1,    -1,    -1,   313,   314,   315,   316,   317,   318,
     319,    21,    22,    23,    24,    25,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    -1,    -1,
     100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
      -1,    -1,    -1,    -1,   124,    -1,   126,   127,   128,   129,
      -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,   139,
      -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    -1,   156,   157,    -1,   159,
     160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,   174,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,
      -1,    -1,    -1,    -1,    -1,   195,    -1,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,    -1,    -1,
     210,   211,   212,    -1,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,   258,   259,
     260,    -1,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
      -1,   311,    -1,   313,   314,   315,   316,   317,   318,   319,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    -1,    -1,   100,   101,   102,    -1,
      -1,   105,   106,    -1,    -1,    -1,    -1,   111,   112,   113,
     114,   115,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,
      -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   147,   148,    -1,   150,   151,   152,    -1,
      -1,    -1,   156,    -1,    -1,   159,   160,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,   187,   188,   189,    -1,    -1,    -1,   193,
      -1,   195,    -1,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,    -1,    -1,   210,   211,    -1,    -1,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,    -1,    -1,    24,    25,   313,
     314,   315,   316,   317,   318,   319,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    -1,    -1,   100,   101,   102,    -1,    -1,   105,   106,
      -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,
     137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,    -1,   150,   151,   152,    -1,    -1,    -1,    -1,
      -1,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
     187,   188,   189,    -1,    -1,    -1,   193,    -1,   195,    -1,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,    -1,    -1,   210,   211,    -1,    -1,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
      -1,   258,   259,   260,    -1,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,    -1,    -1,    24,    25,   313,   314,   315,   316,
     317,   318,   319,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    -1,    -1,
     100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,
      -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,   139,
      -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,    -1,
     150,   151,   152,    -1,    -1,    -1,    -1,    -1,    -1,   159,
     160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,   187,   188,   189,
      -1,    -1,    -1,   193,    -1,   195,    -1,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,    -1,    -1,
     210,   211,    -1,    -1,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,   258,   259,
     260,    -1,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,    -1,
      -1,    24,    25,   313,   314,   315,   316,   317,   318,   319,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    -1,    -1,   100,   101,   102,
      -1,    -1,   105,   106,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   127,   128,   129,    -1,   131,    -1,
      -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,    -1,   150,   151,   152,
      -1,    -1,    -1,   156,    -1,    -1,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,
      -1,    -1,   195,    -1,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,    -1,    -1,   210,   211,    -1,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,    -1,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,    -1,    -1,    24,    25,
     313,   314,   315,   316,   317,   318,   319,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    -1,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,    -1,   150,   151,   152,    -1,    -1,    -1,
     156,    -1,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,   195,
      -1,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,    -1,    -1,   210,   211,    -1,    -1,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,    -1,    -1,    24,    25,   313,   314,   315,
     316,   317,   318,   319,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    -1,
      -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,
     139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,
      -1,   150,   151,   152,    -1,    -1,    -1,   156,    -1,    -1,
     159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,
     189,    -1,    -1,    -1,    -1,    -1,   195,    -1,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,    -1,
      -1,   210,   211,    -1,    -1,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,   258,
     259,   260,    -1,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
      -1,    -1,    24,    25,   313,   314,   315,   316,   317,   318,
     319,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    -1,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,    -1,   150,   151,
     152,    -1,    -1,    -1,   156,    -1,    -1,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,
      -1,    -1,    -1,   195,    -1,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,    -1,    -1,   210,   211,
      -1,    -1,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,   258,   259,   260,    -1,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,    -1,    -1,    24,
      25,   313,   314,   315,   316,   317,   318,   319,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    97,    -1,    -1,   100,   101,   102,    -1,    -1,
     105,   106,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,
     135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,
      -1,   146,   147,   148,    -1,   150,   151,   152,    -1,    -1,
      -1,   156,    -1,    -1,   159,   160,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,
     195,    -1,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,    -1,    -1,   210,   211,    -1,    -1,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,    -1,   258,   259,   260,    -1,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,    -1,    -1,    24,    25,   313,   314,
     315,   316,   317,   318,   319,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      -1,    -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
     128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,
     138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,
     148,    -1,   150,   151,   152,    -1,    -1,    -1,    -1,    -1,
      -1,   159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,
     188,   189,    -1,    -1,    -1,    -1,    -1,   195,    -1,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
      -1,    -1,   210,   211,    -1,    -1,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
     258,   259,   260,    -1,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,    -1,    -1,    24,    25,   313,   314,   315,   316,   317,
     318,   319,    33,    34,    -1,    36,    37,    38,    -1,    40,
      41,    42,    43,    -1,    -1,    46,    47,    -1,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    -1,    60,
      -1,    -1,    63,    64,    65,    66,    67,    -1,    69,    -1,
      71,    -1,    -1,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    -1,    -1,    -1,   100,
     101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,    -1,
     131,    -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,    -1,   150,
     151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,
      -1,    -1,    -1,    -1,   195,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,    -1,    -1,
     211,    -1,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,    -1,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,    -1,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,    -1,    -1,
      -1,    -1,   313,   314,   315,   316,   317,   318,   319
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
      84,    85,    86,    87,    88,    89,    90,    91,    92,    94,
      95,    96,    97,    98,   100,   101,   102,   105,   106,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     124,   126,   127,   128,   129,   131,   135,   136,   137,   138,
     139,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     156,   157,   158,   159,   160,   165,   166,   167,   168,   169,
     170,   171,   172,   174,   176,   177,   180,   181,   182,   186,
     188,   189,   191,   192,   193,   195,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   210,   211,   212,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   258,   259,   260,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   311,   313,   314,   315,   316,   317,
     318,   319,   320,   332,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   353,   354,   355,   356,   357,   358,   362,   363,   364,
     368,   370,   371,   373,   380,   382,   385,   386,   387,   389,
     390,   391,   392,   393,   395,   396,   398,   399,   400,   401,
     402,   403,   405,   406,   409,   410,   411,   412,   417,   419,
     421,   422,   427,   446,   449,   453,   456,   457,   462,   463,
     464,   465,   467,   468,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   504,   505,   506,   507,   508,   509,
     510,   511,   512,   514,   515,   516,   530,   531,   533,   534,
     535,   536,   537,   538,   539,   547,   548,   549,   550,   551,
     552,   553,   554,   555,   556,   559,   560,   561,   562,   567,
     568,   569,   570,   571,   572,   575,   633,   634,   635,   636,
     638,   639,   640,   641,   642,   649,   650,   651,    33,    34,
      49,   214,   388,   389,   390,   388,   388,   156,   156,    37,
      38,    40,    41,    47,    56,    57,    74,    79,   111,   112,
     113,   160,   219,   260,   286,   294,   302,   369,   370,   374,
     375,   376,   160,   153,   156,   153,   156,   153,   156,    66,
      71,   118,   414,   156,   377,   156,    24,    34,    60,   118,
     272,   426,   428,   429,   153,   156,   156,   156,   118,   153,
     156,   156,   156,    76,   153,   220,   221,   122,   122,   122,
     153,   156,    39,    43,    45,    46,    47,    48,    51,    59,
      67,    70,    72,    73,    75,    90,    91,    97,   105,   112,
     114,   115,   135,   138,   139,   169,   172,   180,   181,   189,
     201,   223,   225,   227,   228,   235,   237,   238,   239,   242,
     243,   314,   498,   649,   650,   122,   118,   397,   122,   122,
      39,    44,    45,    59,    61,    62,    70,    97,   224,   649,
     118,   122,   122,   184,   388,   390,   410,   637,    48,    72,
      73,   118,   153,   185,   243,   409,   411,   421,   187,   409,
     649,   153,   122,    16,   648,   649,    18,    19,   649,   122,
     122,   122,   490,   153,    30,   213,   215,   224,   226,   313,
     156,   224,   226,   313,   224,   313,   224,   229,   313,   118,
     240,   240,   241,   156,   153,   392,   310,   409,   312,   409,
     313,   334,     0,   336,   337,    33,    49,   339,   356,     1,
     190,   333,   190,   333,   112,   371,   391,   409,   107,   190,
     107,   190,    42,    46,    51,    69,   168,   171,   186,   211,
     404,   413,   418,   419,   420,   434,   435,   439,   167,    92,
     132,   140,   141,   143,   151,   155,   157,   162,   179,   202,
     203,   204,   205,   206,   207,   482,   483,   248,    99,   158,
     176,   198,   117,   146,   159,   193,   200,   209,   136,   150,
      50,   199,   101,   102,   158,   176,   481,   153,   487,   490,
     191,   192,   154,   502,   503,   498,   502,   498,   156,   502,
     145,   156,   184,   184,   184,   372,   505,   372,    29,   647,
     182,   195,   182,   195,   166,   182,   650,   649,   169,   201,
      47,   649,   152,   118,    45,    47,    79,   106,   168,   648,
     220,   221,   222,   245,   606,   649,   649,   303,   137,   142,
     112,   286,   294,   374,   648,   389,   390,   187,   389,    45,
      62,   187,   555,   556,   409,   187,   193,   649,   283,   283,
     423,   424,   649,   118,   430,   118,   187,   378,   379,   153,
     394,   409,     1,   160,   647,   113,   160,   352,   647,   649,
     118,   142,   107,   409,    29,   187,   648,   649,   649,   447,
     448,   649,   389,   187,   409,   409,   557,   649,   389,   153,
     153,   409,   187,   193,   649,   649,   142,   447,   184,   184,
     121,   107,   184,   156,   156,   156,   649,   153,   185,   186,
     187,    35,   518,   519,   520,   409,     8,   175,    17,   409,
     213,    29,   410,   410,    39,    45,    59,    70,    97,   504,
     649,   187,   410,   410,   410,   637,   410,   504,   410,   230,
     229,   573,   574,   649,   190,   190,   410,   409,   390,   409,
     244,   407,   408,   310,   312,   410,   190,   333,   190,   333,
       3,   340,   356,   386,   340,   356,   386,    33,   357,   386,
     357,   386,   397,   397,   410,   118,   168,   170,   170,   391,
     410,   410,   464,   465,   467,   467,   467,   467,   466,   467,
     467,   467,    70,   468,   472,   472,   471,   473,   473,   473,
     473,   474,   474,   475,   475,   230,    94,    94,    94,   184,
     409,   490,   490,   409,   503,   187,   410,   513,   149,   187,
     513,   107,   187,   187,   107,   107,   377,    29,   650,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,   359,
     360,   361,    94,   137,   142,   365,   366,   367,   649,   160,
     160,   359,   647,   127,   132,    54,    56,   100,   250,   263,
     265,   276,   277,   278,   280,   282,   607,   608,   609,   610,
     611,   612,   619,   625,   626,   245,    94,   298,   649,   142,
     410,   118,   649,   649,   132,   184,   184,   187,   187,   184,
     107,   187,   107,   187,   107,    36,    94,    96,   147,   425,
     426,   541,   649,    55,   216,   253,   415,   416,   649,    94,
     107,   187,   388,   187,   648,    96,    45,   648,   647,    96,
     142,   541,   649,   410,   429,   184,   187,   187,   187,   187,
     107,   188,   147,   541,   184,   187,   187,   153,   184,   389,
     389,   184,   107,   187,   107,   187,   142,   541,   410,   188,
     410,   410,   409,   409,   409,   649,   519,   520,   130,   196,
     184,   184,   131,   190,   156,    94,   217,   218,   232,    94,
     217,   218,   232,   232,   232,    94,   156,   236,   224,   230,
     107,   234,   142,   190,   187,    48,    72,    73,   243,   411,
     421,   184,   499,   579,   408,   198,   356,    33,    33,   190,
     333,   190,   113,   649,   170,   410,   440,   441,   118,   436,
     437,   467,   153,   156,   258,   486,   505,   580,   583,   584,
     585,   586,   587,   591,   593,   595,   596,    47,   152,   156,
     210,   316,   317,   318,   319,   542,   544,   546,   547,   563,
     564,   565,   566,   643,   644,   645,   646,   649,   542,   540,
     546,   540,   184,   185,   107,   187,   187,   505,   148,   165,
     148,   165,   137,   394,   377,   360,   132,   544,   367,   410,
     541,   647,   647,   128,   129,   647,   276,   277,   278,   282,
     649,   262,   273,   262,   273,    29,   285,    96,   113,   156,
     613,   616,   607,    39,    44,    59,    61,    70,    97,   224,
     381,   547,   226,   298,   307,   410,   649,    94,   298,   647,
     153,   557,   558,   649,   557,   558,   118,   127,   542,   118,
     410,   147,   426,   147,    36,   147,   425,   426,   147,   541,
     253,    53,    58,    77,   118,   425,   431,   432,   433,   416,
     541,   542,   379,    94,   184,   197,   132,   351,   647,   160,
     132,    96,   351,   410,   142,   426,   153,   118,   410,   410,
     147,   100,   450,   451,   452,   454,   455,   100,   458,   459,
     460,   461,   389,   184,   184,   153,   557,   557,   410,   142,
     190,   410,   121,   187,   187,   187,    35,   520,   130,   196,
       9,    10,   103,   123,   125,   153,   194,   515,   517,   528,
     529,   532,    29,   410,   231,   233,   410,   410,   410,   231,
     233,   410,   410,   410,   410,   410,   410,   410,   410,   410,
     504,   118,   410,   410,   391,   156,   156,   156,   153,   186,
     244,   576,   577,   209,   392,   410,   190,   113,   386,   386,
     386,   440,    95,   106,   116,   127,   442,   443,   444,   445,
     107,   649,   107,   409,   580,   587,   153,   284,   469,   632,
      96,   169,   251,   252,   254,   261,   271,   283,   581,   582,
     601,   602,   603,   604,   627,   630,   257,   259,   588,   606,
     266,   592,   628,   246,   247,   269,   597,   598,   156,   156,
     544,   156,   156,   156,   156,   156,   144,   176,   193,   543,
     144,   410,   137,   394,   559,   366,   285,    29,    96,   113,
     156,   620,    29,   613,   543,   488,   286,   305,   541,   381,
     226,   190,   388,   187,   187,   144,   187,   187,   424,   147,
     425,   649,   410,   147,   410,   127,   410,   147,   426,   147,
     410,   147,   118,   118,   410,   649,   433,    77,   542,   391,
     410,   647,   107,   351,   410,   142,   388,   448,   410,   410,
     113,   451,   452,   100,   186,   113,   452,   455,   118,   542,
     100,   113,   459,   100,   113,   461,   184,   388,   187,   187,
     410,   410,   197,   458,   132,   194,   517,     7,   389,   649,
     194,   528,   190,   187,   232,   232,   232,   232,    96,   187,
     236,   156,   574,   186,   409,   409,   409,   579,   577,   499,
     647,   128,   129,   444,   445,   445,   441,   106,   438,   437,
     184,   187,   580,   594,   249,   216,   253,   267,   274,   631,
      96,   255,   256,   629,   249,   584,   631,   471,   601,   585,
     147,   281,   589,   590,   629,   285,   600,    78,   599,   187,
     193,   542,   545,   187,   187,   187,   187,   187,   187,   187,
      29,   136,   200,   622,   623,   624,    29,   621,   622,   270,
     617,   107,   614,   170,   649,   256,   488,   184,   410,   147,
     410,   147,   425,   410,   147,   410,   410,   649,   649,   432,
     410,   126,   126,    96,   647,   410,   184,   186,   186,   410,
     391,   410,   186,   186,   649,   186,   118,   542,   118,   186,
     118,   542,   186,   184,   113,   520,   649,   194,   184,   520,
     649,   410,   410,   410,   410,   315,    94,   410,   410,   410,
     187,   187,   187,   153,   578,   445,   647,   184,   473,    52,
     129,   471,   471,   268,   275,   285,   605,   605,   586,   153,
     279,    94,   187,   107,   187,   620,   620,   624,   107,   187,
      29,   618,   629,   615,   616,   187,   383,   384,   488,   118,
     224,   306,   286,   170,   410,   410,   147,   410,    53,   391,
     410,   351,   410,   391,    94,   391,   410,   649,   186,   649,
     410,   649,   186,   391,   118,    93,   183,   521,   520,   649,
     196,   520,   410,   410,   187,   197,   458,   409,   471,   471,
     198,   409,   542,   542,    94,    29,   264,   107,   107,   445,
     541,   649,   118,   224,   649,   383,   410,   118,   542,    94,
     186,    94,   649,     5,   133,   524,   525,   527,   529,    28,
     134,   522,   523,   526,   529,   196,   520,   196,   236,   113,
     184,   471,   184,   542,   616,   384,   445,   304,   649,   118,
     224,   649,   186,   542,   391,   410,   542,   186,    93,   133,
     527,   183,   134,   526,   196,   410,   118,   410,   304,   649,
     118,   391,   410,   186,   186,   649,   292,   304,   649,   186,
     305,   410,   305,   488,   488,   198,   286,   649,   224,   118,
     649,   305,   488
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
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   331,   332,   332,   333,   334,   334,   334,   334,   335,
     335,   336,   336,   336,   336,   336,   336,   336,   336,   337,
     337,   337,   337,   338,   339,   339,   339,   340,   340,   340,
     340,   340,   341,   341,   341,   341,   341,   341,   341,   341,
     342,   342,   343,   344,   345,   345,   346,   346,   347,   347,
     348,   348,   348,   348,   349,   349,   349,   350,   350,   350,
     350,   351,   351,   352,   352,   353,   353,   353,   353,   354,
     355,   355,   356,   356,   356,   357,   357,   357,   357,   357,
     357,   357,   357,   358,   358,   359,   359,   360,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   362,   363,
     364,   365,   365,   366,   366,   366,   367,   368,   368,   368,
     369,   369,   369,   369,   370,   370,   371,   371,   371,   371,
     372,   372,   373,   373,   374,   374,   375,   375,   376,   376,
     377,   377,   377,   377,   378,   378,   379,   379,   380,   380,
     380,   380,   381,   381,   382,   382,   383,   383,   384,   384,
     384,   384,   385,   385,   385,   385,   386,   387,   387,   387,
     388,   388,   388,   389,   389,   390,   390,   391,   391,   391,
     391,   391,   391,   391,   391,   391,   391,   391,   391,   392,
     392,   393,   394,   395,   396,   396,   396,   397,   397,   397,
     397,   398,   399,   400,   401,   402,   402,   403,   404,   405,
     406,   407,   407,   408,   409,   409,   410,   410,   410,   410,
     410,   410,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   412,   413,   414,   414,   415,   415,
     415,   416,   416,   417,   417,   418,   419,   419,   419,   420,
     420,   420,   420,   420,   421,   421,   422,   423,   423,   424,
     424,   424,   424,   424,   424,   424,   424,   424,   424,   424,
     424,   425,   426,   427,   428,   428,   429,   429,   429,   429,
     430,   430,   431,   431,   431,   432,   432,   432,   433,   433,
     433,   434,   435,   436,   436,   437,   437,   438,   439,   439,
     440,   440,   441,   441,   442,   442,   442,   442,   442,   442,
     442,   443,   443,   444,   444,   445,   446,   446,   447,   447,
     448,   448,   449,   450,   450,   451,   452,   452,   453,   454,
     454,   455,   456,   456,   457,   457,   458,   458,   459,   459,
     460,   460,   461,   461,   462,   463,   463,   464,   464,   465,
     465,   465,   465,   465,   466,   465,   465,   465,   465,   467,
     467,   468,   468,   469,   469,   470,   470,   471,   471,   471,
     472,   472,   472,   472,   472,   473,   473,   473,   474,   474,
     474,   475,   475,   476,   476,   477,   477,   478,   478,   479,
     479,   480,   480,   480,   480,   481,   481,   481,   482,   482,
     482,   482,   482,   482,   483,   483,   483,   484,   484,   484,
     484,   485,   485,   486,   486,   487,   487,   487,   488,   488,
     488,   488,   489,   490,   490,   490,   491,   491,   492,   492,
     492,   492,   493,   493,   494,   494,   494,   494,   494,   494,
     494,   495,   495,   496,   496,   497,   497,   497,   497,   497,
     498,   498,   499,   499,   500,   500,   500,   500,   501,   501,
     501,   501,   502,   502,   503,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   505,
     505,   506,   506,   506,   507,   508,   508,   509,   510,   511,
     512,   512,   513,   513,   514,   514,   515,   515,   515,   516,
     516,   516,   516,   516,   516,   517,   517,   518,   518,   519,
     520,   520,   521,   521,   522,   522,   523,   523,   523,   523,
     524,   524,   525,   525,   525,   525,   526,   526,   527,   527,
     528,   528,   528,   528,   529,   529,   529,   529,   530,   530,
     531,   531,   532,   533,   533,   533,   533,   533,   533,   534,
     535,   535,   536,   536,   537,   538,   539,   539,   540,   540,
     541,   542,   542,   542,   543,   543,   543,   544,   544,   544,
     544,   544,   544,   544,   545,   545,   546,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   548,   549,   549,   549,
     550,   551,   552,   552,   552,   553,   553,   553,   553,   553,
     554,   555,   555,   555,   555,   555,   555,   555,   556,   557,
     558,   559,   560,   560,   561,   562,   563,   563,   564,   565,
     565,   566,   567,   567,   567,   568,   568,   568,   568,   568,
     568,   568,   568,   568,   568,   569,   569,   570,   570,   571,
     572,   573,   573,   574,   575,   576,   576,   577,   578,   579,
     579,   580,   581,   581,   582,   582,   583,   583,   584,   584,
     585,   585,   586,   586,   587,   588,   588,   589,   589,   590,
     591,   591,   591,   592,   592,   593,   594,   594,   595,   596,
     596,   597,   597,   598,   598,   598,   599,   599,   600,   600,
     601,   601,   601,   601,   601,   602,   603,   604,   605,   605,
     605,   606,   606,   607,   607,   607,   607,   607,   607,   607,
     607,   608,   608,   608,   608,   609,   609,   610,   611,   611,
     612,   612,   612,   613,   613,   614,   614,   615,   615,   616,
     617,   617,   618,   618,   619,   619,   619,   620,   620,   621,
     621,   622,   622,   623,   623,   624,   624,   625,   626,   626,
     627,   627,   627,   628,   629,   629,   629,   629,   630,   630,
     631,   631,   632,   633,   633,   634,   634,   635,   635,   636,
     637,   637,   638,   638,   639,   640,   641,   642,   643,   643,
     643,   644,   645,   646,   647,   648,   648,   649,   649,   649,
     649,   649,   649,   649,   649,   649,   649,   649,   649,   649,
     649,   649,   649,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   651
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
       2,     3,     4,     5,     1,     3,     2,     3,     3,     5,
       4,     6,     1,     2,     8,     9,     1,     3,     1,     2,
       2,     3,    11,    14,    13,    22,     1,     1,     1,     0,
       1,     1,     0,     1,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     3,     3,     2,     3,     2,     3,     2,     3,     4,
       5,     5,     2,     4,     5,     3,     3,     2,     2,     8,
       3,     1,     2,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
       5,     1,     3,     0,     1,     1,     3,     1,     3,     3,
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
       1,     1,     1,     1,     2,     2,     3,     1,     4,     4,
       3,     4,     1,     3,     1,     1,     1,     1,     1,     4,
       5,     8,     9,     9,    10,     1,     2,     1,     2,     6,
       0,     1,     3,     3,     0,     1,     1,     1,     2,     2,
       0,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     2,
       3,     3,     2,     1,     1,     1,     1,     1,     1,     4,
       3,     7,     3,     7,     4,     4,     3,     7,     1,     2,
       2,     1,     2,     3,     1,     1,     1,     1,     1,     3,
       3,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     4,     4,
       3,     3,     3,     4,     4,     3,     4,     6,     4,     6,
       4,     3,     4,     6,     6,     4,     6,     6,     4,     1,
       2,     1,     1,     1,     3,     3,     1,     1,     4,     5,
       6,     3,     3,     3,     3,     5,     7,     7,     5,     5,
       5,     7,     7,     5,     5,     3,     3,     5,     7,     5,
       7,     1,     4,     3,     5,     1,     2,     3,     3,     1,
       3,     2,     0,     1,     1,     2,     1,     3,     1,     3,
       1,     4,     1,     2,     3,     0,     1,     0,     1,     4,
       2,     3,     1,     0,     1,     4,     0,     1,     2,     1,
       3,     0,     1,     2,     2,     1,     0,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     1,
       1,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     1,     2,     2,     3,     1,     2,
       2,     5,     2,     1,     1,     0,     2,     1,     3,     4,
       0,     2,     0,     2,     4,     4,     3,     2,     3,     1,
       3,     0,     1,     1,     2,     2,     2,     2,     1,     2,
       2,     2,     2,     3,     2,     3,     3,     4,     2,     2,
       1,     1,     3,     2,     3,     2,     3,     2,     3,     3,
       3,     5,     5,     8,     5,     6,     8,    10,     1,     1,
       1,     3,     3,     3,     1,     1,     1,     1,     1,     1,
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
  "\"'updating'\"", "\"'validate'\"", "\"'type'\"", "\"'when'\"",
  "\"'word'\"", "\"'decimal-format'\"", "\"'decimal-separator'\"",
  "\"'grouping-separator'\"", "\"'infinity'\"", "\"'minus-sign'\"",
  "\"'NaN'\"", "\"'percent'\"", "\"'per-mille'\"", "\"'zero-digit'\"",
  "\"'digit'\"", "\"'pattern-separator'\"", "\"'ancestor'\"",
  "\"'ancestor-or-self'\"", "\"'and'\"", "\"'''\"", "\"'as'\"",
  "\"'ascending'\"", "\"'at'\"", "\"'attribute'\"", "\"'@'\"", "\"'||'\"",
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
  "\"'copy'\"", "\"'with'\"", "\"'break'\"", "\"'continue'\"",
  "\"'exit'\"", "\"'loop'\"", "\"'returning'\"", "\"'while'\"",
  "\"'try'\"", "\"'catch'\"", "\"'using'\"", "\"'all'\"", "\"'any'\"",
  "\"'contains'\"", "\"'content'\"", "\"'diacritics'\"", "\"'different'\"",
  "\"'distance'\"", "\"'end'\"", "\"'entire'\"", "\"'exactly'\"",
  "\"'from'\"", "\"'ftand'\"", "\"'ftnot'\"", "\"'not'\"",
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
  "\"'keys'\"", "\"'{|'\"", "\"'|}'\"", "\"'{['\"", "\"']}'\"",
  "\"'json'\"", "\"'append'\"", "\"'position'\"", "\"'object'\"",
  "\"'array'\"", "\"'json-item'\"", "\"'structured-item'\"",
  "\"'BOM_UTF8'\"", "RANGE_REDUCE", "SEQUENCE_TYPE_REDUCE",
  "ADDITIVE_REDUCE", "UNION_REDUCE", "INTERSECT_EXCEPT_REDUCE",
  "QVARINDECLLIST_REDUCE", "COMMA_DOLLAR", "UNARY_PREC", "STEP_REDUCE",
  "MULTIPLICATIVE_REDUCE", "$accept", "Module", "ERROR",
  "ModuleWithoutBOM", "VersionDecl", "MainModule", "LibraryModule",
  "ModuleDecl", "SIND_DeclList", "SIND_Decl", "Setter",
  "BoundarySpaceDecl", "DefaultCollationDecl", "BaseURIDecl",
  "ConstructionDecl", "OrderingModeDecl", "EmptyOrderDecl",
  "CopyNamespacesDecl", "Import", "SchemaImport", "URILiteralList",
  "SchemaPrefix", "ModuleImport", "NamespaceDecl", "DefaultNamespaceDecl",
  "VFO_DeclList", "VFO_Decl", "DecimalFormatDecl",
  "DecimalFormatParamList", "DecimalFormatParam", "DecimalFormatParamName",
  "OptionDecl", "FTOptionDecl", "CtxItemDecl", "CtxItemDecl2",
  "CtxItemDecl3", "CtxItemDecl4", "VarDecl", "VarNameAndType",
  "AnnotationList", "Annotation", "AnnotationLiteralList", "FunctionDecl",
  "FunctionDecl2", "FunctionDeclSimple", "FunctionDeclUpdating",
  "FunctionSig", "ParamList", "Param", "CollectionDecl",
  "CollectionTypeDecl", "IndexDecl", "IndexKeyList", "IndexKeySpec",
  "IntegrityConstraintDecl", "QueryBody", "StatementsAndOptionalExprTop",
  "StatementsAndOptionalExpr", "StatementsAndExpr", "Statements",
  "Statement", "BlockStatement", "BlockExpr",
  "EnclosedStatementsAndOptionalExpr", "VarDeclStatement",
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
  "StringConcatExpr", "opt_FTIgnoreOption", "RangeExpr", "AdditiveExpr",
  "MultiplicativeExpr", "UnionExpr", "IntersectExceptExpr",
  "InstanceofExpr", "TreatExpr", "CastableExpr", "CastExpr", "UnaryExpr",
  "SignList", "ValueExpr", "ValueComp", "NodeComp", "ValidateExpr",
  "ExtensionExpr", "Pragma_list", "Pragma", "PathExpr", "LeadingSlash",
  "RelativePathExpr", "StepExpr", "AxisStep", "ForwardStep", "ForwardAxis",
  "AbbrevForwardStep", "ReverseStep", "ReverseAxis", "NodeTest",
  "NameTest", "Wildcard", "FilterExpr", "PredicateList", "Predicate",
  "PrimaryExpr", "Literal", "NumericLiteral", "VarRef",
  "ParenthesizedExpr", "ContextItemExpr", "OrderedExpr", "UnorderedExpr",
  "FunctionCall", "ArgList", "Constructor", "DirectConstructor",
  "DirElemConstructor", "DirElemContentList", "DirAttributeList",
  "DirAttr", "OptionalBlank", "DirAttributeValue",
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
  "FTIgnoreOption", "JSONArrayConstructor", "JSONSimpleObjectUnion",
  "JSONAccumulatorObjectUnion", "JSONObjectConstructor", "JSONPairList",
  "JSONInsertExpr", "JSONAppendExpr", "JSONDeleteExpr", "JSONRenameExpr",
  "JSONReplaceExpr", "JSONTest", "JSONItemTest", "JSONObjectTest",
  "JSONArrayTest", "URI_LITERAL", "NCNAME", "QNAME", "FUNCTION_NAME",
  "EQNAME", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const xquery_parser::rhs_number_type
  xquery_parser::yyrhs_[] =
  {
       332,     0,    -1,   334,    -1,   320,   334,    -1,     1,     3,
      -1,   336,    -1,   335,   336,    -1,   337,    -1,   335,   337,
      -1,   214,   215,    29,   190,    -1,   214,   215,    29,   131,
      29,   190,    -1,   339,   190,   386,    -1,   356,   190,   386,
      -1,   339,   190,   356,   190,   386,    -1,   386,    -1,   339,
     333,   386,    -1,   356,   333,   386,    -1,   339,   190,   356,
     333,   386,    -1,   339,   333,   356,   190,   386,    -1,   338,
      -1,   338,   339,   190,    -1,   338,   356,   190,    -1,   338,
     339,   190,   356,   190,    -1,    34,   160,   648,   132,   647,
     190,    -1,   340,    -1,   339,   190,   340,    -1,   339,   333,
     340,    -1,   341,    -1,   349,    -1,   354,    -1,   355,    -1,
     363,    -1,   342,    -1,   343,    -1,   344,    -1,   345,    -1,
     346,    -1,   347,    -1,   348,    -1,   567,    -1,    33,    38,
     182,    -1,    33,    38,   195,    -1,    33,   113,   106,   647,
      -1,    33,    37,   647,    -1,    33,    40,   182,    -1,    33,
      40,   195,    -1,    33,    57,   169,    -1,    33,    57,   201,
      -1,    33,   113,   168,   127,   128,    -1,    33,   113,   168,
     127,   129,    -1,    33,    41,   182,   107,   148,    -1,    33,
      41,   182,   107,   165,    -1,    33,    41,   166,   107,   148,
      -1,    33,    41,   166,   107,   165,    -1,   350,    -1,   353,
      -1,    49,    24,     1,    -1,    49,    60,   647,    -1,    49,
      60,   352,   647,    -1,    49,    60,   647,    96,   351,    -1,
      49,    60,   352,   647,    96,   351,    -1,   647,    -1,   351,
     107,   647,    -1,   160,   648,   132,    -1,   113,    45,   160,
      -1,    49,    34,   647,    -1,    49,    34,   160,   648,   132,
     647,    -1,    49,    34,   647,    96,   351,    -1,    49,    34,
     160,   648,   132,   647,    96,   351,    -1,    33,   160,   648,
     132,   647,    -1,    33,   113,    45,   160,   647,    -1,    33,
     113,    47,   160,   647,    -1,   357,    -1,   356,   190,   357,
      -1,   356,   333,   357,    -1,   358,    -1,   362,    -1,   364,
      -1,   368,    -1,   373,    -1,   380,    -1,   382,    -1,   385,
      -1,    33,   113,    79,   359,    -1,    33,    79,   649,   359,
      -1,   360,    -1,   359,   360,    -1,   361,   132,   559,    -1,
      80,    -1,    88,    -1,    81,    -1,    82,    -1,    83,    -1,
      84,    -1,    89,    -1,    85,    -1,    86,    -1,    87,    -1,
      33,    56,   649,    29,    -1,    33,   260,   606,    -1,    33,
     111,   152,   365,    -1,    94,   544,   366,    -1,   366,    -1,
     367,    -1,   137,    -1,   137,   367,    -1,   142,   410,    -1,
      33,   369,   142,   410,    -1,    33,   369,   137,    -1,    33,
     369,   137,   142,   410,    -1,   112,   118,   649,    -1,   112,
     118,   649,   541,    -1,   370,   112,   118,   649,    -1,   370,
     112,   118,   649,   541,    -1,   371,    -1,   370,   371,    -1,
      26,    -1,    26,   156,   372,   187,    -1,    27,    -1,    27,
     156,   372,   187,    -1,   505,    -1,   372,   107,   505,    -1,
      33,   374,    -1,    33,   370,   374,    -1,   375,    -1,   376,
      -1,    47,   650,   377,   394,    -1,    47,   650,   377,   137,
      -1,    74,    47,   650,   377,   394,    -1,    74,    47,   650,
     377,   137,    -1,   156,   187,    -1,   156,   378,   187,    -1,
     156,   187,    94,   542,    -1,   156,   378,   187,    94,   542,
      -1,   379,    -1,   378,   107,   379,    -1,   118,   649,    -1,
     118,   649,   541,    -1,    33,   286,   649,    -1,    33,   286,
     649,    94,   381,    -1,    33,   370,   286,   649,    -1,    33,
     370,   286,   649,    94,   381,    -1,   547,    -1,   547,   543,
      -1,    33,   294,   649,   298,   226,   488,   170,   383,    -1,
      33,   370,   294,   649,   298,   226,   488,   170,   383,    -1,
     384,    -1,   383,   107,   384,    -1,   488,    -1,   488,   541,
      -1,   488,   445,    -1,   488,   541,   445,    -1,    33,   302,
     303,   649,   298,   286,   649,   118,   649,   304,   410,    -1,
      33,   302,   303,   649,   298,   286,   649,   224,   118,   649,
     304,   292,   305,   488,    -1,    33,   302,   303,   649,   298,
     286,   649,   306,   224,   118,   649,   304,   410,    -1,    33,
     302,   303,   649,   307,   305,   256,   286,   649,   224,   118,
     649,   305,   488,   198,   286,   649,   224,   118,   649,   305,
     488,    -1,   387,    -1,   389,    -1,   390,    -1,    -1,   389,
      -1,   390,    -1,    -1,   409,    -1,   390,   409,    -1,   391,
      -1,   390,   391,    -1,   392,    -1,   395,    -1,   398,    -1,
     399,    -1,   400,    -1,   401,    -1,   402,    -1,   403,    -1,
     405,    -1,   457,    -1,   453,    -1,   406,    -1,   153,   390,
     184,    -1,   153,   184,    -1,   153,   388,   184,    -1,   153,
     388,   184,    -1,   396,   190,    -1,   396,   107,   397,    -1,
     112,   397,    -1,   370,   112,   397,    -1,   118,   649,    -1,
     118,   649,   541,    -1,   118,   649,   142,   410,    -1,   118,
     649,   541,   142,   410,    -1,   118,   649,   142,   410,   190,
      -1,   411,   190,    -1,   239,   241,   410,   190,    -1,   242,
     156,   409,   187,   391,    -1,   237,   240,   190,    -1,   238,
     240,   190,    -1,   421,   404,    -1,   186,   391,    -1,    48,
     156,   409,   187,   197,   391,   126,   391,    -1,   243,   392,
     407,    -1,   408,    -1,   407,   408,    -1,   244,   579,   392,
      -1,   410,    -1,   409,   107,   410,    -1,   412,    -1,   449,
      -1,   456,    -1,   462,    -1,   575,    -1,   411,    -1,   463,
      -1,   446,    -1,   568,    -1,   569,    -1,   571,    -1,   570,
      -1,   572,    -1,   640,    -1,   638,    -1,   641,    -1,   642,
      -1,   639,    -1,   421,   413,    -1,   186,   410,    -1,    66,
     283,    -1,    71,   283,    -1,   216,    -1,   253,    -1,    55,
     253,    -1,   415,   431,    77,   410,    -1,   415,    77,   410,
      -1,    46,   414,   430,   416,   416,    -1,    46,   414,   430,
     416,    -1,    42,   118,   649,    -1,   422,    -1,   427,    -1,
     417,    -1,   419,    -1,   434,    -1,   439,    -1,   435,    -1,
     418,    -1,   419,    -1,   421,   420,    -1,    46,   118,   423,
      -1,   424,    -1,   423,   107,   118,   424,    -1,   649,   147,
     410,    -1,   649,    36,   127,   147,   410,    -1,   649,   541,
     147,   410,    -1,   649,   541,    36,   127,   147,   410,    -1,
     649,   425,   147,   410,    -1,   649,    36,   127,   425,   147,
     410,    -1,   649,   541,   425,   147,   410,    -1,   649,   541,
      36,   127,   425,   147,   410,    -1,   649,   426,   147,   410,
      -1,   649,   541,   426,   147,   410,    -1,   649,   425,   426,
     147,   410,    -1,   649,   541,   425,   426,   147,   410,    -1,
      96,   118,   649,    -1,   272,   118,   649,    -1,    51,   428,
      -1,   429,    -1,   428,   107,   429,    -1,   118,   649,   142,
     410,    -1,   118,   649,   541,   142,   410,    -1,   426,   142,
     410,    -1,   118,   649,   541,   426,   142,   410,    -1,   118,
     649,   147,   410,    -1,   118,   649,   541,   147,   410,    -1,
     432,    -1,   118,   649,    -1,   118,   649,   432,    -1,   425,
      -1,   425,   433,    -1,   433,    -1,    58,   118,   649,    53,
     118,   649,    -1,    53,   118,   649,    -1,    58,   118,   649,
      -1,   211,   410,    -1,   171,   170,   436,    -1,   437,    -1,
     436,   107,   437,    -1,   118,   649,    -1,   118,   649,   438,
      -1,   106,   647,    -1,   168,   170,   440,    -1,    69,   168,
     170,   440,    -1,   441,    -1,   440,   107,   441,    -1,   410,
      -1,   410,   442,    -1,   443,    -1,   444,    -1,   445,    -1,
     443,   444,    -1,   443,   445,    -1,   444,   445,    -1,   443,
     444,   445,    -1,    95,    -1,   116,    -1,   127,   128,    -1,
     127,   129,    -1,   106,   647,    -1,    67,   118,   447,   188,
     410,    -1,   135,   118,   447,   188,   410,    -1,   448,    -1,
     447,   107,   118,   448,    -1,   649,   147,   410,    -1,   649,
     541,   147,   410,    -1,    72,   156,   409,   187,   450,   113,
     186,   410,    -1,   451,    -1,   450,   451,    -1,   452,   186,
     410,    -1,   100,   410,    -1,   452,   100,   410,    -1,    72,
     156,   409,   187,   454,   113,   186,   391,    -1,   455,    -1,
     454,   455,    -1,   452,   186,   391,    -1,    73,   156,   409,
     187,   458,   113,   186,   410,    -1,    73,   156,   409,   187,
     458,   113,   118,   649,   186,   410,    -1,    73,   156,   409,
     187,   460,   113,   186,   391,    -1,    73,   156,   409,   187,
     458,   113,   118,   649,   186,   391,    -1,   459,    -1,   458,
     459,    -1,   100,   542,   186,   410,    -1,   100,   118,   649,
      94,   542,   186,   410,    -1,   461,    -1,   460,   461,    -1,
     100,   542,   186,   391,    -1,   100,   118,   649,    94,   542,
     186,   391,    -1,    48,   156,   409,   187,   197,   410,   126,
     410,    -1,   464,    -1,   463,   167,   464,    -1,   465,    -1,
     464,    92,   465,    -1,   467,    -1,   467,   482,   467,    -1,
     467,   483,   467,    -1,   467,   132,   467,    -1,   467,   162,
     467,    -1,    -1,   467,   157,   466,   467,    -1,   467,   155,
     467,    -1,   467,   143,   467,    -1,   467,   141,   467,    -1,
     468,    -1,   468,   248,    70,   580,   469,    -1,   470,    -1,
     470,    99,   468,    -1,    -1,   632,    -1,   471,    -1,   471,
     198,   471,    -1,   472,    -1,   471,   176,   472,    -1,   471,
     158,   472,    -1,   473,    -1,   472,   193,   473,    -1,   472,
     117,   473,    -1,   472,   146,   473,    -1,   472,   159,   473,
      -1,   474,    -1,   473,   200,   474,    -1,   473,   209,   474,
      -1,   475,    -1,   474,   150,   475,    -1,   474,   136,   475,
      -1,   476,    -1,   476,    50,   230,   542,    -1,   477,    -1,
     477,   199,    94,   542,    -1,   478,    -1,   478,   101,    94,
     540,    -1,   479,    -1,   479,   102,    94,   540,    -1,   481,
      -1,   480,   481,    -1,   176,    -1,   158,    -1,   480,   176,
      -1,   480,   158,    -1,   484,    -1,   488,    -1,   485,    -1,
     202,    -1,   207,    -1,   206,    -1,   205,    -1,   204,    -1,
     203,    -1,   151,    -1,   179,    -1,   140,    -1,    75,   153,
     389,   184,    -1,    75,   221,   153,   389,   184,    -1,    75,
     220,   153,   389,   184,    -1,    75,    76,   557,   153,   389,
     184,    -1,   486,   153,   184,    -1,   486,   153,   409,   184,
      -1,   487,    -1,   486,   487,    -1,   177,   649,    17,    -1,
     177,    18,    -1,   177,    19,    -1,   489,    -1,   489,   490,
      -1,   192,   490,    -1,   490,    -1,   191,    -1,   491,    -1,
     491,   191,   490,    -1,   491,   192,   490,    -1,   492,    -1,
     501,    -1,   493,    -1,   493,   502,    -1,   496,    -1,   496,
     502,    -1,   494,   498,    -1,   495,    -1,   105,   122,    -1,
     114,   122,    -1,    97,   122,    -1,   189,   122,    -1,   115,
     122,    -1,   139,   122,    -1,   138,   122,    -1,   498,    -1,
      98,   498,    -1,   497,   498,    -1,   120,    -1,   172,   122,
      -1,    90,   122,    -1,   181,   122,    -1,   180,   122,    -1,
      91,   122,    -1,   547,    -1,   499,    -1,   649,    -1,   500,
      -1,   193,    -1,    11,    -1,    12,    -1,    20,    -1,   504,
      -1,   501,   502,    -1,   501,   156,   187,    -1,   501,   156,
     513,   187,    -1,   503,    -1,   502,   503,    -1,   154,   409,
     185,    -1,   505,    -1,   507,    -1,   508,    -1,   509,    -1,
     512,    -1,   514,    -1,   510,    -1,   511,    -1,   560,    -1,
     393,    -1,   636,    -1,   633,    -1,   634,    -1,   635,    -1,
     506,    -1,   559,    -1,   110,    -1,   149,    -1,   124,    -1,
     118,   649,    -1,   156,   187,    -1,   156,   409,   187,    -1,
     119,    -1,   169,   153,   409,   184,    -1,   201,   153,   409,
     184,    -1,   650,   156,   187,    -1,   650,   156,   513,   187,
      -1,   410,    -1,   513,   107,   410,    -1,   515,    -1,   533,
      -1,   516,    -1,   530,    -1,   531,    -1,   157,   649,   520,
     130,    -1,   157,   649,   518,   520,   130,    -1,   157,   649,
     520,   196,   194,   649,   520,   196,    -1,   157,   649,   520,
     196,   517,   194,   649,   520,   196,    -1,   157,   649,   518,
     520,   196,   194,   649,   520,   196,    -1,   157,   649,   518,
     520,   196,   517,   194,   649,   520,   196,    -1,   528,    -1,
     517,   528,    -1,   519,    -1,   518,   519,    -1,    35,   649,
     520,   132,   520,   521,    -1,    -1,    35,    -1,   183,   522,
     183,    -1,    93,   524,    93,    -1,    -1,   523,    -1,   134,
      -1,   526,    -1,   523,   134,    -1,   523,   526,    -1,    -1,
     525,    -1,   133,    -1,   527,    -1,   525,   133,    -1,   525,
     527,    -1,    28,    -1,   529,    -1,     5,    -1,   529,    -1,
     515,    -1,    10,    -1,   532,    -1,   529,    -1,     9,    -1,
     123,    -1,   125,    -1,   153,   389,   184,    -1,   212,    30,
     213,    -1,   212,   213,    -1,   174,   648,   175,    -1,   174,
     648,     8,    -1,   103,     7,    -1,   534,    -1,   535,    -1,
     536,    -1,   537,    -1,   538,    -1,   539,    -1,    43,   153,
     389,   184,    -1,    21,   388,   184,    -1,    45,   153,   409,
     184,   153,   388,   184,    -1,    22,   388,   184,    -1,    97,
     153,   409,   184,   153,   388,   184,    -1,    70,   153,   389,
     184,    -1,    39,   153,   389,   184,    -1,    23,   388,   184,
      -1,    59,   153,   409,   184,   153,   388,   184,    -1,   546,
      -1,   546,   144,    -1,    94,   542,    -1,   544,    -1,   544,
     543,    -1,   210,   156,   187,    -1,   144,    -1,   193,    -1,
     176,    -1,   546,    -1,   547,    -1,   152,   156,   187,    -1,
     319,   156,   187,    -1,   563,    -1,   566,    -1,   643,    -1,
     542,    -1,   545,   107,   542,    -1,   649,    -1,   549,    -1,
     555,    -1,   553,    -1,   556,    -1,   554,    -1,   552,    -1,
     551,    -1,   550,    -1,   548,    -1,   224,   156,   187,    -1,
      44,   156,   187,    -1,    44,   156,   555,   187,    -1,    44,
     156,   556,   187,    -1,    70,   156,   187,    -1,    39,   156,
     187,    -1,    59,   156,   187,    -1,    59,   156,   648,   187,
      -1,    59,   156,    29,   187,    -1,    97,   156,   187,    -1,
      97,   156,   649,   187,    -1,    97,   156,   649,   107,   557,
     187,    -1,    97,   156,   193,   187,    -1,    97,   156,   193,
     107,   557,   187,    -1,    61,   156,   649,   187,    -1,    45,
     156,   187,    -1,    45,   156,   649,   187,    -1,    45,   156,
     649,   107,   557,   187,    -1,    45,   156,   649,   107,   558,
     187,    -1,    45,   156,   193,   187,    -1,    45,   156,   193,
     107,   557,   187,    -1,    45,   156,   193,   107,   558,   187,
      -1,    62,   156,   649,   187,    -1,   649,    -1,   649,   144,
      -1,    29,    -1,   561,    -1,   562,    -1,   649,   145,   149,
      -1,    47,   377,   394,    -1,   564,    -1,   565,    -1,    47,
     156,   193,   187,    -1,    47,   156,   187,    94,   542,    -1,
      47,   156,   545,   187,    94,   542,    -1,   156,   544,   187,
      -1,    33,   219,   220,    -1,    33,   219,   221,    -1,    33,
     219,   222,    -1,   225,   224,   410,   232,   410,    -1,   225,
     224,   410,    94,   231,   232,   410,    -1,   225,   224,   410,
      94,   233,   232,   410,    -1,   225,   224,   410,   217,   410,
      -1,   225,   224,   410,   218,   410,    -1,   225,   226,   410,
     232,   410,    -1,   225,   226,   410,    94,   231,   232,   410,
      -1,   225,   226,   410,    94,   233,   232,   410,    -1,   225,
     226,   410,   217,   410,    -1,   225,   226,   410,   218,   410,
      -1,   223,   224,   410,    -1,   223,   226,   410,    -1,   228,
     224,   410,   236,   410,    -1,   228,   229,   230,   224,   410,
     236,   410,    -1,   227,   224,   410,    94,   410,    -1,   235,
     118,   573,   234,   410,   186,   410,    -1,   574,    -1,   573,
     107,   118,   574,    -1,   649,   142,   410,    -1,   243,   153,
     409,   184,   576,    -1,   577,    -1,   576,   577,    -1,   244,
     579,   578,    -1,   153,   409,   184,    -1,   499,    -1,   579,
     209,   499,    -1,   583,   581,    -1,    -1,   582,    -1,   601,
      -1,   582,   601,    -1,   584,    -1,   583,   261,   584,    -1,
     585,    -1,   584,   257,   585,    -1,   586,    -1,   585,   259,
     147,   586,    -1,   587,    -1,   258,   587,    -1,   591,   588,
     589,    -1,    -1,   606,    -1,    -1,   590,    -1,   281,   153,
     409,   184,    -1,   595,   592,    -1,   156,   580,   187,    -1,
     593,    -1,    -1,   628,    -1,   486,   153,   594,   184,    -1,
      -1,   580,    -1,   596,   597,    -1,   505,    -1,   153,   409,
     184,    -1,    -1,   598,    -1,   247,   599,    -1,   246,   600,
      -1,   269,    -1,    -1,    78,    -1,    -1,   285,    -1,   602,
      -1,   603,    -1,   604,    -1,   630,    -1,   627,    -1,   169,
      -1,   283,   471,   605,    -1,   252,   629,   605,    -1,   285,
      -1,   275,    -1,   268,    -1,   245,   607,    -1,   606,   245,
     607,    -1,   608,    -1,   609,    -1,   610,    -1,   625,    -1,
     611,    -1,   619,    -1,   612,    -1,   626,    -1,   100,   273,
      -1,   100,   262,    -1,   265,    -1,   280,    -1,   250,   273,
      -1,   250,   262,    -1,    56,   649,    29,    -1,   276,    -1,
      54,   276,    -1,   278,   613,    -1,   278,   156,   613,   614,
     187,    -1,    54,   278,    -1,   616,    -1,   113,    -1,    -1,
     107,   615,    -1,   616,    -1,   615,   107,   616,    -1,    96,
      29,   617,   618,    -1,    -1,   270,    29,    -1,    -1,   629,
     264,    -1,   277,   285,   620,   622,    -1,   277,   285,   113,
     622,    -1,    54,   277,   285,    -1,    96,    29,    -1,   156,
     621,   187,    -1,    29,    -1,   621,   107,    29,    -1,    -1,
     623,    -1,   624,    -1,   623,   624,    -1,   200,   620,    -1,
     136,   620,    -1,   263,    29,    -1,   282,    -1,    54,   282,
      -1,    96,   216,    -1,    96,   253,    -1,   254,   249,    -1,
     266,   629,   279,    -1,   255,   471,    -1,    96,   129,   471,
      -1,    96,    52,   471,    -1,   256,   471,   198,   471,    -1,
     271,   631,    -1,   251,   631,    -1,   274,    -1,   267,    -1,
     284,   249,   473,    -1,   154,   185,    -1,   154,   409,   185,
      -1,   309,   310,    -1,   309,   409,   310,    -1,   311,   312,
      -1,   311,   409,   312,    -1,   153,   637,   184,    -1,   410,
     121,   410,    -1,   637,   107,   410,   121,   410,    -1,   225,
     313,   637,   232,   410,    -1,   225,   313,   410,   232,   410,
      96,   315,   410,    -1,   314,   313,   410,   198,   410,    -1,
     223,   313,   504,   156,   410,   187,    -1,   227,   313,   504,
     156,   410,   187,    94,   410,    -1,   228,   313,   229,   230,
     504,   156,   410,   187,   236,   410,    -1,   644,    -1,   645,
      -1,   646,    -1,   318,   156,   187,    -1,   316,   156,   187,
      -1,   317,   156,   187,    -1,    29,    -1,    16,    -1,   649,
      -1,   650,    -1,    97,    -1,    39,    -1,    44,    -1,    45,
      -1,   152,    -1,    48,    -1,   224,    -1,    59,    -1,    61,
      -1,    62,    -1,    70,    -1,    73,    -1,    72,    -1,   210,
      -1,   242,    -1,   651,    -1,    24,    -1,   214,    -1,   127,
      -1,    38,    -1,   260,    -1,    37,    -1,   221,    -1,   220,
      -1,   146,    -1,    43,    -1,   258,    -1,   259,    -1,   273,
      -1,   262,    -1,   250,    -1,   284,    -1,   276,    -1,   278,
      -1,   277,    -1,   282,    -1,   254,    -1,   249,    -1,    78,
      -1,   216,    -1,   253,    -1,    52,    -1,   222,    -1,   235,
      -1,   301,    -1,   229,    -1,   202,    -1,   207,    -1,   206,
      -1,   205,    -1,   204,    -1,   203,    -1,    96,    -1,   111,
      -1,   112,    -1,   186,    -1,    46,    -1,    36,    -1,    66,
      -1,    71,    -1,    58,    -1,    53,    -1,    55,    -1,    77,
      -1,    42,    -1,   147,    -1,    51,    -1,   211,    -1,   170,
      -1,   171,    -1,   168,    -1,    69,    -1,    95,    -1,   116,
      -1,   128,    -1,   129,    -1,   106,    -1,    67,    -1,   135,
      -1,   188,    -1,   100,    -1,    94,    -1,   197,    -1,   126,
      -1,   167,    -1,    92,    -1,    50,    -1,   230,    -1,   101,
      -1,   198,    -1,   117,    -1,   159,    -1,   200,    -1,   150,
      -1,   136,    -1,    75,    -1,    76,    -1,   102,    -1,   199,
      -1,   151,    -1,   182,    -1,   195,    -1,   160,    -1,   137,
      -1,   131,    -1,   166,    -1,   148,    -1,   165,    -1,    33,
      -1,    40,    -1,    57,    -1,   113,    -1,    41,    -1,    56,
      -1,   215,    -1,    49,    -1,    60,    -1,    34,    -1,    47,
      -1,   272,    -1,   248,    -1,   281,    -1,   283,    -1,   252,
      -1,   266,    -1,   279,    -1,   271,    -1,   251,    -1,   265,
      -1,   280,    -1,   270,    -1,   264,    -1,   263,    -1,   247,
      -1,   246,    -1,   255,    -1,   256,    -1,   285,    -1,   275,
      -1,   274,    -1,   269,    -1,   267,    -1,   268,    -1,   228,
      -1,   234,    -1,   231,    -1,   225,    -1,   218,    -1,   217,
      -1,   219,    -1,   236,    -1,   226,    -1,   227,    -1,   233,
      -1,   223,    -1,   232,    -1,    65,    -1,    63,    -1,    74,
      -1,   169,    -1,   201,    -1,   241,    -1,   239,    -1,   240,
      -1,   237,    -1,   238,    -1,   243,    -1,   244,    -1,   245,
      -1,    64,    -1,   294,    -1,   292,    -1,   293,    -1,   298,
      -1,   299,    -1,   300,    -1,   295,    -1,   296,    -1,   297,
      -1,    79,    -1,    80,    -1,    81,    -1,    82,    -1,    83,
      -1,    84,    -1,    85,    -1,    86,    -1,    87,    -1,    88,
      -1,    89,    -1,   286,    -1,   287,    -1,   288,    -1,   289,
      -1,   290,    -1,   291,    -1,   302,    -1,   303,    -1,   304,
      -1,   305,    -1,   306,    -1,   307,    -1,   308,    -1,    90,
      -1,   105,    -1,   114,    -1,   172,    -1,   180,    -1,   189,
      -1,   138,    -1,    91,    -1,   115,    -1,   139,    -1,   181,
      -1,   313,    -1,   314,    -1,   315,    -1,   318,    -1,   317,
      -1,   316,    -1,   319,    -1,    25,    -1
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
     473,   476,   480,   485,   491,   493,   497,   500,   504,   508,
     514,   519,   526,   528,   531,   540,   550,   552,   556,   558,
     561,   564,   568,   580,   595,   609,   632,   634,   636,   638,
     639,   641,   643,   644,   646,   649,   651,   654,   656,   658,
     660,   662,   664,   666,   668,   670,   672,   674,   676,   678,
     682,   685,   689,   693,   696,   700,   703,   707,   710,   714,
     719,   725,   731,   734,   739,   745,   749,   753,   756,   759,
     768,   772,   774,   777,   781,   783,   787,   789,   791,   793,
     795,   797,   799,   801,   803,   805,   807,   809,   811,   813,
     815,   817,   819,   821,   823,   826,   829,   832,   835,   837,
     839,   842,   847,   851,   857,   862,   866,   868,   870,   872,
     874,   876,   878,   880,   882,   884,   887,   891,   893,   898,
     902,   908,   913,   920,   925,   932,   938,   946,   951,   957,
     963,   970,   974,   978,   981,   983,   987,   992,   998,  1002,
    1009,  1014,  1020,  1022,  1025,  1029,  1031,  1034,  1036,  1043,
    1047,  1051,  1054,  1058,  1060,  1064,  1067,  1071,  1074,  1078,
    1083,  1085,  1089,  1091,  1094,  1096,  1098,  1100,  1103,  1106,
    1109,  1113,  1115,  1117,  1120,  1123,  1126,  1132,  1138,  1140,
    1145,  1149,  1154,  1163,  1165,  1168,  1172,  1175,  1179,  1188,
    1190,  1193,  1197,  1206,  1217,  1226,  1237,  1239,  1242,  1247,
    1255,  1257,  1260,  1265,  1273,  1282,  1284,  1288,  1290,  1294,
    1296,  1300,  1304,  1308,  1312,  1313,  1318,  1322,  1326,  1330,
    1332,  1338,  1340,  1344,  1345,  1347,  1349,  1353,  1355,  1359,
    1363,  1365,  1369,  1373,  1377,  1381,  1383,  1387,  1391,  1393,
    1397,  1401,  1403,  1408,  1410,  1415,  1417,  1422,  1424,  1429,
    1431,  1434,  1436,  1438,  1441,  1444,  1446,  1448,  1450,  1452,
    1454,  1456,  1458,  1460,  1462,  1464,  1466,  1468,  1473,  1479,
    1485,  1492,  1496,  1501,  1503,  1506,  1510,  1513,  1516,  1518,
    1521,  1524,  1526,  1528,  1530,  1534,  1538,  1540,  1542,  1544,
    1547,  1549,  1552,  1555,  1557,  1560,  1563,  1566,  1569,  1572,
    1575,  1578,  1580,  1583,  1586,  1588,  1591,  1594,  1597,  1600,
    1603,  1605,  1607,  1609,  1611,  1613,  1615,  1617,  1619,  1621,
    1624,  1628,  1633,  1635,  1638,  1642,  1644,  1646,  1648,  1650,
    1652,  1654,  1656,  1658,  1660,  1662,  1664,  1666,  1668,  1670,
    1672,  1674,  1676,  1678,  1680,  1683,  1686,  1690,  1692,  1697,
    1702,  1706,  1711,  1713,  1717,  1719,  1721,  1723,  1725,  1727,
    1732,  1738,  1747,  1757,  1767,  1778,  1780,  1783,  1785,  1788,
    1795,  1796,  1798,  1802,  1806,  1807,  1809,  1811,  1813,  1816,
    1819,  1820,  1822,  1824,  1826,  1829,  1832,  1834,  1836,  1838,
    1840,  1842,  1844,  1846,  1848,  1850,  1852,  1854,  1858,  1862,
    1865,  1869,  1873,  1876,  1878,  1880,  1882,  1884,  1886,  1888,
    1893,  1897,  1905,  1909,  1917,  1922,  1927,  1931,  1939,  1941,
    1944,  1947,  1949,  1952,  1956,  1958,  1960,  1962,  1964,  1966,
    1970,  1974,  1976,  1978,  1980,  1982,  1986,  1988,  1990,  1992,
    1994,  1996,  1998,  2000,  2002,  2004,  2006,  2010,  2014,  2019,
    2024,  2028,  2032,  2036,  2041,  2046,  2050,  2055,  2062,  2067,
    2074,  2079,  2083,  2088,  2095,  2102,  2107,  2114,  2121,  2126,
    2128,  2131,  2133,  2135,  2137,  2141,  2145,  2147,  2149,  2154,
    2160,  2167,  2171,  2175,  2179,  2183,  2189,  2197,  2205,  2211,
    2217,  2223,  2231,  2239,  2245,  2251,  2255,  2259,  2265,  2273,
    2279,  2287,  2289,  2294,  2298,  2304,  2306,  2309,  2313,  2317,
    2319,  2323,  2326,  2327,  2329,  2331,  2334,  2336,  2340,  2342,
    2346,  2348,  2353,  2355,  2358,  2362,  2363,  2365,  2366,  2368,
    2373,  2376,  2380,  2382,  2383,  2385,  2390,  2391,  2393,  2396,
    2398,  2402,  2403,  2405,  2408,  2411,  2413,  2414,  2416,  2417,
    2419,  2421,  2423,  2425,  2427,  2429,  2431,  2435,  2439,  2441,
    2443,  2445,  2448,  2452,  2454,  2456,  2458,  2460,  2462,  2464,
    2466,  2468,  2471,  2474,  2476,  2478,  2481,  2484,  2488,  2490,
    2493,  2496,  2502,  2505,  2507,  2509,  2510,  2513,  2515,  2519,
    2524,  2525,  2528,  2529,  2532,  2537,  2542,  2546,  2549,  2553,
    2555,  2559,  2560,  2562,  2564,  2567,  2570,  2573,  2576,  2578,
    2581,  2584,  2587,  2590,  2594,  2597,  2601,  2605,  2610,  2613,
    2616,  2618,  2620,  2624,  2627,  2631,  2634,  2638,  2641,  2645,
    2649,  2653,  2659,  2665,  2674,  2680,  2687,  2696,  2707,  2709,
    2711,  2713,  2717,  2721,  2725,  2727,  2729,  2731,  2733,  2735,
    2737,  2739,  2741,  2743,  2745,  2747,  2749,  2751,  2753,  2755,
    2757,  2759,  2761,  2763,  2765,  2767,  2769,  2771,  2773,  2775,
    2777,  2779,  2781,  2783,  2785,  2787,  2789,  2791,  2793,  2795,
    2797,  2799,  2801,  2803,  2805,  2807,  2809,  2811,  2813,  2815,
    2817,  2819,  2821,  2823,  2825,  2827,  2829,  2831,  2833,  2835,
    2837,  2839,  2841,  2843,  2845,  2847,  2849,  2851,  2853,  2855,
    2857,  2859,  2861,  2863,  2865,  2867,  2869,  2871,  2873,  2875,
    2877,  2879,  2881,  2883,  2885,  2887,  2889,  2891,  2893,  2895,
    2897,  2899,  2901,  2903,  2905,  2907,  2909,  2911,  2913,  2915,
    2917,  2919,  2921,  2923,  2925,  2927,  2929,  2931,  2933,  2935,
    2937,  2939,  2941,  2943,  2945,  2947,  2949,  2951,  2953,  2955,
    2957,  2959,  2961,  2963,  2965,  2967,  2969,  2971,  2973,  2975,
    2977,  2979,  2981,  2983,  2985,  2987,  2989,  2991,  2993,  2995,
    2997,  2999,  3001,  3003,  3005,  3007,  3009,  3011,  3013,  3015,
    3017,  3019,  3021,  3023,  3025,  3027,  3029,  3031,  3033,  3035,
    3037,  3039,  3041,  3043,  3045,  3047,  3049,  3051,  3053,  3055,
    3057,  3059,  3061,  3063,  3065,  3067,  3069,  3071,  3073,  3075,
    3077,  3079,  3081,  3083,  3085,  3087,  3089,  3091,  3093,  3095,
    3097,  3099,  3101,  3103,  3105,  3107,  3109,  3111,  3113,  3115,
    3117,  3119,  3121,  3123,  3125,  3127,  3129,  3131,  3133,  3135,
    3137,  3139,  3141,  3143,  3145,  3147,  3149,  3151,  3153,  3155,
    3157,  3159,  3161,  3163,  3165,  3167,  3169,  3171,  3173,  3175
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,  1034,  1034,  1035,  1044,  1053,  1059,  1067,  1073,  1084,
    1089,  1097,  1104,  1111,  1120,  1127,  1135,  1143,  1151,  1162,
    1167,  1174,  1181,  1193,  1203,  1210,  1217,  1229,  1230,  1231,
    1232,  1233,  1238,  1239,  1240,  1241,  1242,  1243,  1244,  1247,
    1252,  1257,  1265,  1273,  1281,  1286,  1294,  1299,  1307,  1312,
    1320,  1327,  1334,  1341,  1351,  1353,  1356,  1366,  1371,  1379,
    1387,  1398,  1405,  1416,  1421,  1429,  1436,  1443,  1452,  1465,
    1473,  1480,  1490,  1497,  1504,  1515,  1516,  1517,  1518,  1519,
    1520,  1521,  1522,  1527,  1533,  1542,  1549,  1559,  1569,  1570,
    1571,  1572,  1573,  1574,  1575,  1576,  1577,  1578,  1583,  1591,
    1599,  1607,  1614,  1622,  1629,  1634,  1642,  1650,  1665,  1680,
    1698,  1703,  1711,  1719,  1730,  1735,  1744,  1749,  1756,  1761,
    1771,  1776,  1785,  1791,  1804,  1809,  1817,  1828,  1843,  1855,
    1870,  1875,  1880,  1885,  1893,  1900,  1911,  1916,  1926,  1933,
    1940,  1947,  1957,  1961,  1971,  1979,  1990,  1996,  2005,  2010,
    2017,  2024,  2035,  2045,  2055,  2065,  2083,  2103,  2107,  2112,
    2119,  2123,  2128,  2135,  2140,  2152,  2159,  2171,  2172,  2173,
    2174,  2175,  2176,  2177,  2179,  2180,  2181,  2182,  2183,  2188,
    2193,  2201,  2218,  2226,  2234,  2241,  2248,  2258,  2270,  2283,
    2295,  2311,  2319,  2327,  2335,  2350,  2355,  2363,  2377,  2394,
    2419,  2427,  2434,  2445,  2455,  2460,  2475,  2476,  2477,  2478,
    2479,  2480,  2485,  2486,  2489,  2490,  2491,  2492,  2493,  2496,
    2497,  2498,  2499,  2500,  2505,  2519,  2527,  2532,  2540,  2545,
    2550,  2558,  2567,  2579,  2589,  2602,  2610,  2611,  2612,  2617,
    2618,  2619,  2620,  2621,  2626,  2633,  2643,  2651,  2658,  2668,
    2678,  2688,  2698,  2708,  2718,  2728,  2738,  2749,  2758,  2768,
    2778,  2794,  2803,  2812,  2820,  2826,  2838,  2846,  2856,  2864,
    2876,  2882,  2893,  2895,  2899,  2907,  2911,  2916,  2920,  2924,
    2928,  2938,  2946,  2953,  2959,  2970,  2974,  2983,  2991,  2997,
    3007,  3013,  3023,  3027,  3037,  3043,  3049,  3055,  3064,  3073,
    3082,  3095,  3099,  3107,  3113,  3123,  3131,  3140,  3153,  3160,
    3172,  3176,  3188,  3195,  3201,  3210,  3217,  3223,  3234,  3241,
    3247,  3256,  3265,  3272,  3283,  3290,  3302,  3308,  3320,  3326,
    3337,  3343,  3354,  3360,  3371,  3380,  3384,  3393,  3397,  3405,
    3409,  3419,  3426,  3435,  3445,  3444,  3458,  3467,  3476,  3489,
    3493,  3505,  3509,  3517,  3520,  3527,  3531,  3540,  3544,  3548,
    3556,  3560,  3566,  3572,  3578,  3588,  3592,  3596,  3604,  3608,
    3614,  3624,  3628,  3638,  3642,  3652,  3656,  3666,  3670,  3680,
    3684,  3692,  3696,  3700,  3704,  3714,  3718,  3722,  3730,  3734,
    3738,  3742,  3746,  3750,  3758,  3762,  3766,  3774,  3778,  3782,
    3786,  3797,  3803,  3813,  3819,  3829,  3833,  3837,  3875,  3879,
    3889,  3899,  3912,  3921,  3931,  3935,  3944,  3948,  3957,  3963,
    3971,  3977,  3989,  3995,  4005,  4009,  4013,  4017,  4021,  4027,
    4033,  4041,  4045,  4053,  4057,  4068,  4072,  4076,  4082,  4086,
    4100,  4104,  4112,  4116,  4126,  4130,  4134,  4138,  4147,  4151,
    4155,  4159,  4167,  4173,  4183,  4191,  4195,  4199,  4203,  4207,
    4211,  4215,  4219,  4223,  4227,  4232,  4236,  4240,  4244,  4252,
    4256,  4264,  4271,  4278,  4289,  4297,  4301,  4309,  4317,  4325,
    4379,  4383,  4396,  4402,  4412,  4416,  4424,  4428,  4432,  4440,
    4450,  4460,  4470,  4480,  4490,  4505,  4511,  4522,  4528,  4539,
    4550,  4552,  4556,  4561,  4571,  4574,  4581,  4587,  4593,  4601,
    4614,  4617,  4624,  4630,  4636,  4643,  4654,  4658,  4668,  4672,
    4682,  4686,  4690,  4695,  4704,  4710,  4716,  4722,  4730,  4735,
    4743,  4748,  4756,  4764,  4769,  4774,  4779,  4784,  4789,  4798,
    4806,  4810,  4827,  4831,  4839,  4847,  4855,  4859,  4867,  4873,
    4883,  4891,  4895,  4899,  4934,  4940,  4946,  4956,  4960,  4964,
    4968,  4972,  4976,  4980,  4987,  4993,  5003,  5011,  5015,  5019,
    5023,  5027,  5031,  5035,  5039,  5043,  5051,  5059,  5063,  5067,
    5077,  5085,  5093,  5097,  5101,  5109,  5113,  5119,  5125,  5129,
    5139,  5147,  5151,  5157,  5166,  5175,  5181,  5187,  5197,  5214,
    5221,  5236,  5272,  5276,  5284,  5292,  5304,  5308,  5316,  5324,
    5328,  5339,  5356,  5362,  5368,  5378,  5382,  5388,  5394,  5398,
    5404,  5408,  5414,  5420,  5427,  5437,  5442,  5450,  5456,  5466,
    5488,  5497,  5503,  5516,  5530,  5537,  5543,  5553,  5562,  5570,
    5576,  5594,  5602,  5606,  5613,  5618,  5626,  5630,  5637,  5641,
    5648,  5652,  5659,  5663,  5672,  5685,  5688,  5696,  5699,  5707,
    5715,  5723,  5727,  5735,  5738,  5746,  5758,  5761,  5769,  5781,
    5787,  5797,  5800,  5808,  5812,  5816,  5824,  5827,  5835,  5838,
    5846,  5850,  5854,  5858,  5862,  5870,  5878,  5890,  5902,  5906,
    5910,  5918,  5924,  5934,  5938,  5942,  5946,  5950,  5954,  5958,
    5962,  5970,  5974,  5978,  5982,  5990,  5996,  6006,  6016,  6020,
    6028,  6038,  6049,  6056,  6060,  6068,  6071,  6078,  6083,  6092,
    6102,  6105,  6112,  6116,  6124,  6133,  6140,  6150,  6154,  6161,
    6167,  6177,  6180,  6187,  6192,  6204,  6212,  6224,  6232,  6236,
    6244,  6248,  6252,  6260,  6268,  6272,  6276,  6280,  6288,  6296,
    6308,  6312,  6320,  6334,  6338,  6345,  6350,  6358,  6363,  6372,
    6380,  6386,  6396,  6402,  6409,  6416,  6423,  6430,  6437,  6441,
    6445,  6452,  6459,  6466,  6478,  6482,  6483,  6496,  6497,  6498,
    6499,  6500,  6501,  6502,  6503,  6504,  6505,  6506,  6507,  6508,
    6509,  6510,  6511,  6515,  6516,  6517,  6518,  6519,  6520,  6521,
    6522,  6523,  6524,  6525,  6526,  6527,  6528,  6529,  6530,  6531,
    6532,  6533,  6534,  6535,  6536,  6537,  6538,  6539,  6540,  6541,
    6542,  6543,  6544,  6545,  6546,  6547,  6548,  6549,  6550,  6551,
    6552,  6553,  6554,  6555,  6556,  6557,  6558,  6559,  6560,  6561,
    6562,  6563,  6564,  6565,  6566,  6567,  6568,  6569,  6570,  6571,
    6572,  6573,  6574,  6575,  6576,  6577,  6578,  6579,  6580,  6581,
    6582,  6583,  6584,  6585,  6586,  6587,  6588,  6589,  6590,  6591,
    6592,  6593,  6594,  6595,  6596,  6597,  6598,  6599,  6600,  6601,
    6602,  6603,  6604,  6605,  6606,  6607,  6608,  6609,  6610,  6611,
    6612,  6613,  6614,  6615,  6616,  6617,  6618,  6619,  6620,  6621,
    6622,  6623,  6624,  6625,  6626,  6627,  6628,  6629,  6630,  6631,
    6632,  6633,  6634,  6635,  6636,  6637,  6638,  6639,  6640,  6641,
    6642,  6643,  6644,  6645,  6646,  6647,  6648,  6649,  6650,  6651,
    6652,  6653,  6654,  6655,  6656,  6657,  6658,  6659,  6660,  6661,
    6662,  6663,  6664,  6665,  6666,  6667,  6668,  6669,  6670,  6671,
    6672,  6673,  6674,  6675,  6676,  6677,  6678,  6679,  6680,  6681,
    6682,  6683,  6684,  6685,  6686,  6687,  6688,  6689,  6690,  6691,
    6692,  6693,  6694,  6695,  6696,  6697,  6698,  6699,  6700,  6701,
    6702,  6703,  6704,  6705,  6706,  6707,  6708,  6709,  6710,  6711,
    6712,  6713,  6714,  6715,  6716,  6717,  6718,  6719,  6720,  6725
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
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 15248;
  const int xquery_parser::yynnts_ = 321;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 602;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 331;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 585;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

<<<<<<< TREE
/* Line 1054 of lalr1.cc  */
#line 16928 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6729 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
=======
/* Line 1136 of lalr1.cc  */
#line 16184 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 6522 "/Users/pjl/src/flwor/zorba/repo/feature-ft_module/zorba/src/compiler/parser/xquery_parser.y"
>>>>>>> MERGE-SOURCE


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

