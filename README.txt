zorba0.1-1
2007.01.25



zorba versioning conventions
----------------------------

2007.01.16

'zorbaN.M-K' means:

	major version  = N
	minor version  = M
	patch release  = K

When nightly build and regression tests are up and running,
then K increment with each nightly build.  M increments as
new stable releases become available.  N increment when large
new subsystems are integrated into the product or major
reimplemetation occurs.



Building zorba
--------------

2007.01.16

build.sh
	Manually created make, using simple 'Makefile.local'
	scripts. A lot easier to use during initial development.
	Use this script for now, until autoconf gets adopted/debugged.

The root directory is
	$INSTALL/zorba/xquery.

setup.sh
  makes symbolic links needed by configure:
    install-sh, depcomp, missing
  
rebuild_autoconf
  Generates a file 'aclocal.m4' that contains macros for automake.
  Automake reads 'configure.ac' and the top-level 'Makefile.am', 
  interprets them, and for each 'Makefile.am' produces a 'Makefile.in'.
  Lastly, autoconf builds the 'configure' script.
  
configure
  Generated script that creates Makefiles
  

  
Known bugs
----------

2007.01.27

Build is currently partially disabled pending conversion to the
in-memory node store.


2007.01.25

Several of the unit test modules are showing an error
on exit.  The sequence of unit tests runs fine, but the module bails
out with a gnu/cygwin error message before exiting.  I suspect
'delete' applied inappropriately by some rchandle destructor.


2007.01.18

There remain bugs in the autoconf setup.
Use 'build.sh' and the local 'Makefile.local' subsystem
for the time being.





 _____________________________
|                             |
| Current Status: 2007.01.27  |
|_____________________________|
 

2007.01.27

The system is undergoing a big conversion:  in-memory node storage module
integration.  Much of the code is still local to my machine (pcp).

Added and tested a 'concat_iterator'.
In-memory node store uses a persistent array of encoded tree structures
and an auxiliary index which maps 'features' to offsets.

2007.01.25

Unit testing in the expression tree directory:
  expr_test looks good,
  eval_test is in progress
                
                   
2007.01.18
                 
The 'parser' subsystem is undergoing conversion to
include 'context'.  This requires modification to:
  xquery_driver.h,
  parsenodes.{h,cpp}
  xquery_parser.y                  
                  
'qname.{h,cpp} got moved from 'types' to 'values' under
a new name: 'qname_value.{h,cpp}'.          
     
zorba/xquery/native_impl/tree.{h,cpp} has been the focus of
a lot of activity.  This module will very likely move to
a separate location, either 'runtime', or it's own subdirectory
'xqom' (XQuery Object Model).

[note: this file migrated to values/node_values. (pcp,2007.01.27)]




Current Module List
-------------------

2007.01.27  
                  
context
	XQuery static and dynamic context:

		context											XQuery 1.0 static/dynamc context
		                            note: needs much more work

exprtree
	XQuery expression tree:

		expr												implementation: XQueryP expression nodes
		eval                        implementation: expression node eval methods, in progress
		ft_expr											implementation: XQuery Full-text expressions
		update_expr									implementation: XQuery UPdate expressions
		expr_test                   implementation: expression tree syntax test
		eval_test                   implementation: expression tree evaluator, in progress


functions
	XQuery function libraries:

	  function_impl               interface: XQuery 1st order functions and operators
	  function_library            interface: XQuery library module, or std lib
	  signature                   interface: XQuery function signature

	
	Proposed implementation order:
		XQuery semantic spec support functions and operators
		XQuery spec operators, Sequences, Constructors, Accessors,
		QName, Strings, Numerics, anyURI, Boolean, Casting, Notation,
		DurationsDatesTimes, Trace


listeners
	Pluggable error, logging, tracing facilities.

		trace_handler								stub interface: XQuery runtime trace callback
		error_handler								stub interface: XQUery runtime error callback


native_impl
	Micro-storage manager and XML parser:

		character_entities					definitions: a big table of SGML character entities
		sax2xml_ostream							stub implementation: (adapter) SAX to zorba xml_stream
		storage_manager							stub implementation: storage manager
		text_store									stub implementation: text store
		xml_store										stub implementation: XML store 
		node_store                  implementation: native mmfile persistent node storage
		spectrum										implementation: native block pool manager
		tree												implementation: node/item_iterator
		xml_loader									implementation: XML file loader
		xml_handler									implementation: tagsoup-derived XML callback handler
		xml_scanner									implementation: tagsoup-derived XML scanner
		scan_handler								implementation: tagsoup-derived scan handler
		html_scanner								implementation: tagsoup-derived HTML scanner
		xml_term										implementation: XML term


parser
	XQuery query parser:

		location.hh		}
		position.hh   }			...			flex/bison infrastructure
		stack.hh      }
		xquery_parser.tab.c	}	...		bison generated source files
		xquery_parser.tab.h	}
		xquery_scanner.yy.cpp	...		flex generated output file

		parse_constants.h						definitions: common parse constants
		xquery_scanner.l						implementation: flex XQueryP scanner
		xquery_parser.y							implementation: flex XQueryP parser
		parsenodes.cpp							implementation: the parse tree
		symbol_table.cpp						implementation: scanenr parse table 
		xquery_driver.cpp						implementation: parser driver 
		xquery_test.cpp							implementation: top-level command-line query loop 


runtime
	The XQueryP processor:

		content_handler							implementation: mod_xqp to libxqp.so bridge
		httpd.conf									implementation: apache2 web server config for libxqp
		iterator								    implementation: the zorba runtime iterator interface
		mod_xqp.c										implementation: the zorba XQueryP apache module


store
	The XML storage data interface:

		source											interface: abstract 'data source'
		collation_resolver					interface: collation URI resolver
		collection_resolver					interface: collection URI resolver
		module_resolver							interface: module URI resolver
		schema_resolver							interface: schema URI resolver
		uri_resolver								interface: URL resolver (should be renamed)
		xml_istream									interface: XML input stream
		xml_ostream									interface: XML output stream


types
	The Query item_type subsystem:

		base_types									implementation: top of the XQuery type hierarchy
		node_types									implementation: the XQuery node types
		sequence_type								implementation: the XQuery sequence type
		xs_primitive_types					stub implementation: the Schema atomic types


util
	Shared general purpose utilities: hashing, sorting, etc.:

		Assert											implementation: assertion templates
		URI													implementation: apache-derived URI parsing module
		file												implementation: file abstraction module
		fxarray											implementation: flex array
		fxcharheap									implementation: flex character heap
		fxvector										implementation: flex vector
		hashfun											implementation: 32 and 64-bit hash functions
		hashmap											implementation: template hashmaps
		list												implementation: template doubly-linked list
		mmfile											implementation: memory-mapped file
		rchandle										implementation: reference-counting pointer template
		rwlock											implementation: reads-writers locking system
		sorter											implementation: template quicksort functions
		tokenbuf										implementation: tokenizer
		utf8_encoder								implementation: utf-8 encoder
		xqp_exception								implementation: application exception classes


values
	The Query item_value subsystem:

		ft_options									implementation: XQuery Full-Text search options
		ft_selection								implementation: XQuery Full-Text selection constraints
		ft_values										implementation: XQuery Full-Text search specifier value
		node_values								  implementation: XQuery node value
		numeric											implementation: XQuery numeric value
		qname_value							  	implementation: XQuery QName
		update_values								implementation: XQuery update specifier value
		values											implementation: XQuery value base classes
		xs_primitive_values					implementation: XQuery primitive values

