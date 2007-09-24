zorba0.2-1
2007.05.04



zorba versioning conventions
----------------------------

2007.03.14

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

2007.09.12

The currently employed makefiles system can be used as described
below. 

To do a build, you need to run:

	make

in the root folder. This will compile all the objects currently in 
the project. As the makefiles are granular, with a file per 
folder, and you can run make in any of them. This will build the 
objects in that particular folder.

---- Begin: Note for Mac OS Users ----
Note that GNU make > 3.81 is needed in order to build Zorba.
With Mac OS Tiger only GNU make 3.80 is shipped.
The easiest way to install a newer make version is to use
Darwin Ports (http://darwinports.com/). Therefore, you
should use the Darwin Ports installer and
immediately after finishing the installation run "sudo port -d selfupdate".
If this was successfull you can simply install make
by typing "sudo port install gmake". This command
will install the latest make version and all its
dependencies. This will take a while. Finally, you can start building Zorba by
typing "gmake" in the Zorba root folder. For the rest of this manual,
you should always use gmake if make is used.
---- End: Note for Mac OS Users ----

        
The current test application -- query_exec -- can be compiled with:

	make query_exec

in the root folder, or
	
	make test

in the testing folder.  
    

Each Makefile in a folder has two variables: SOURCES and BINARIES. 
If you create a new .cpp file and want it compiled, add it to 
SOURCES.

	SOURCES = .... my_source.cpp

If you want an executable to be created, list it dependencies:

	my_test = my_test.cpp ../dom/dom_nodes.cpp ../dom/dom_qname.cpp etc

then add my_test to BINARIES

	BINARIES = ... my_test

The executable will be built when you'll invoke make with the "test" 
target.

	make test

The intermediary files can be deleted with:

	make clean


  
Known bugs
----------

2007.05.04

Clean build reched after essentially complete rewrite of the XML
storage interfaces.

2007.03.14

The xml_handler <-> item store interaction has residual bugs.
All items are stored, but the node binary structure has several
gaps.


2007.02.19

Type system is undergoing rewrite.  For the time being we use
the old code.
[The type system has now been completely replaced and is funcitoning
 correctly.]


2007.01.29

Build is clean, except for one residual error in 'function_impl'.
[Residual error was correctred.]


2007.01.27

Build is currently partially disabled pending conversion to the
in-memory node store.
[The conversion is now conplete; the build fully enabled.]


2007.01.25

Several of the unit test modules are showing an error
on exit.  The sequence of unit tests runs fine, but the module bails
out with a gnu/cygwin error message before exiting.  I suspect
'delete' applied inappropriately by some rchandle destructor.
[This suspicion was subsequently confirmed and the problem corrected.]


2007.01.18

There remain bugs in the autoconf setup.
Use 'build.sh' and the local 'Makefile.local' subsystem
for the time being.





 _____________________________
|                             |
| Current Status: 2007.05.04  |
|_____________________________|

2007.05.04

Complete rewrite of the storage interfaces and implementations.
Finally got back to a clean build state.  Testing of some basic
functions like 'doc', ',' can resume.

2007.03.14

- 'native_impl' has been completely removed, and the class we
retained migrted to 'store'. 
- Itemstore is written and unit tested.
- Integration of itemstore with xml_handler is in progress.
- We have found that the piccolo XML parser seems to compile
  effectively, and plan to use piccolo essentially as-is for the
  time being.
- 'node_values' was recast as 'nodes'
- 'qname_value' was folded into xs_primitive_values, where it belongs


2007.02.19

'Visitor' system developed and end-to-end testing begun.
We can run command-line test of (a few) individual queries
through parse -> normalize -> plan -> exec.
Implementation (-schema, -function lib) is at about 50%.

 
2007.01.29

Context interface conversion completed.  MMapped/RAM nodestore
unit testing started.  Nodestore code still in progress. The
Build is now usable, although the implementation is still only
at 30%.


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

2007.05.04 
                  
context
  XQuery static and dynamic context:

    context                      interface
    static_context               implementation of XQuery 1.0 static context
    dynmamic_context             implementation of XQuery 1.0 dynamic context
                             

exprtree
  XQuery expression tree:

    expr                         implementation: XQueryP expression nodes
    ft_expr                      implementation: XQuery Full-text expressions
    update_expr                  implementation: XQuery UPdate expressions
    expr_test                    implementation: expression tree syntax test
    parsenode_visitor            interface: parsenode -> expr conversion
    normalize_visitor            implementation: parsenode -> normalized expr tree


functions
  XQuery function libraries:

    function                     interface: XQuery 1st order functions and operators
    function_library             interface: XQuery library module, or std lib
    signature                    interface: XQuery function signature
    Sequences                    implementation: some sample sequence functions

  
  Proposed implementation order:
    XQuery semantic spec support functions and operators
    XQuery spec operators, Sequences, Constructors, Accessors,
    QName, Strings, Numerics, anyURI, Boolean, Casting, Notation,
    DurationsDatesTimes, Trace


listeners
  Pluggable error, logging, tracing facilities.

    trace_handler                stub interface: XQuery runtime trace callback
    error_handler                stub interface: XQUery runtime error callback


parser
  XQuery query parser:

    location.hh    }
    position.hh   }      ...     flex/bison infrastructure
    stack.hh      }
    xquery_parser.tab.c  }  ...  bison generated source files
    xquery_parser.tab.h  }
    xquery_scanner.yy.cpp  ...   flex generated output file

    parse_constants.h            definitions: common parse constants
    xquery_scanner.l             implementation: flex XQueryP scanner
    xquery_parser.y              implementation: flex XQueryP parser
    parsenodes.cpp               implementation: the parse tree
    symbol_table.cpp             implementation: scanenr parse table 
    xquery_driver.cpp            implementation: parser driver 
    xquery_test.cpp              implementation: top-level command-line query loop 


runtime
  The XQueryP processor:

    content_handler              implementation: mod_xqp to libxqp.so bridge
    httpd.conf                   implementation: apache2 web server config for libxqp
    iterator                     implementation: the zorba runtime iterator interface
    expr_visitor                 interface: expr tree -> plan tree conversion
    plan_visitor                 implementation: expr tree -> plan tree conversion
    mod_xqp.c                    implementation: the zorba XQueryP apache module


store
  The XML storage data interface:

    itemstore                    implementation: basic linear blob item store
    qname_cache                  implementation: qname cache
    collation_resolver           interface: collation URI resolver
    collection_resolver          interface: collection URI resolver
    module_resolver              interface: module URI resolver
    schema_resolver              interface: schema URI resolver
    uri_resolver                 interface: URL resolver (should be renamed)
    xml_handler                  implementation: tagsoup-derived XML callback handler
    xml_scanner                  implementation: tagsoup-derived XML scanner
    scan_handler                 implementation: tagsoup-derived scan handler
    xml_term                     implementation: XML term
    character_entities           definitions: a big table of SGML character entities


types
  The Query item_type subsystem:

    typecodes.h                  interface: sequence type encoding
    fix_typecodes                implemetation: perl scrip tfor generating 'typecodes.h'
    sequence_type                implementation: the XQuery sequence type


util
  Shared general purpose utilities: hashing, sorting, etc.:

    Assert                       implementation: assertion templates
    URI                          implementation: apache-derived URI parsing module
    file                         implementation: file abstraction module
    fxarray                      implementation: flex array
    fxcharheap                   implementation: flex character heap
    fxvector                     implementation: flex vector
    hashfun                      implementation: 32 and 64-bit hash functions
    hashmap                      implementation: template hashmaps
    list                         implementation: template doubly-linked list
    mmfile                       implementation: memory-mapped file
    rchandle                     implementation: reference-counting pointer template
    rwlock                       implementation: reads-writers locking system
    sorter                       implementation: template quicksort functions
    tokenbuf                     implementation: tokenizer
    utf8_encoder                 implementation: utf-8 encoder
    xqp_exception                implementation: application exception classes


values
  The Query alue subsystem:

    values                       implementation: XQuery value base classes
    nodes                        implementation: XQuery nodes
    primitive_values             implementation: XQuery Schema primitive values
    ft_options                   implementation: XQuery Full-Text search options
    ft_selection                 implementation: XQuery Full-Text selection constraints
    ft_values                    implementation: XQuery Full-Text search specifier value
    update_values                implementation: XQuery update specifier value
    value_factory                interface: abstract value factory



