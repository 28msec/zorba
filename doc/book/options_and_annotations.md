# Zorba Specific Options and Annotations

In XQuery, <a href="http://www.w3.org/TR/xquery-30/#id-option-declaration">options</a> and <a href="http://www.w3.org/TR/xquery-30/#id-annotations">annotations</a> can both be used to change the behavior of a particular implementation.
Options provide a way to affect the behavior of modules.
Annotations can be used to declare properties associated with functions, variables, collections, and indexes.
In the following, we present the Zorba specific options and annotations.
Also, we describe how they can be dealt with using the C++ API and the introspection module.

## Options

Options provide a way to affect the behavior of a particular XQuery module. 
They can be interpreted either by the XQuery processor itself or by the implementation of a particular module (i.e. an external function).

The syntax for declaring options in the prolog of an XQuery module is 

```
  OptionDecl     ::=    "declare" "option" QName StringLiteral
```

where QName is the name of the option and StringLiteral is the value that is assigned to this name.

For example, the following declaration disables scripting support in the module that contains the option declaration.

```xquery
  declare namespace op = "http://zorba.io/options/features";

  declare option op:disable "scripting";
```

### Available Options

Zorba provides a number of options which can be used to determine the behavior of a module.
The namespace for all such options starts with *http://zorba.io/options*.
An error is raised (`zerr:ZXQP0060`) if a module declares an option with a namespace that is equal to or starts with this namespace but the local name refers to an option that is not known to Zorba.

In the following, we describe the set of options available in Zorba.

### Enabling or Disabling Features

Zorba provides a couple of extensions to XQuery. For example, the scripting extension and the data definition facility are both features not defined by the W3C but available in Zorba.
The user can enable or disable any of these  extensions using an option declaration, respectively.
The URI of the names  of these options is *http://zorba.io/options/features*.
The local name to enable a feature is *enable* and to disable a feature  is *disable*, respectively.
As a value, any of these options allows  a comma separated list of feature names (QNames).

For example, to disable the scripting and data definition facility feature,
the following option declaration may be used:

```xquery
  declare namespace op = "http://zorba.io/options/features";
  declare namespace f = "http://zorba.io/features";

  declare option op:disable "f:scripting, f:ddl";
```

If a given feature doesn't specify a prefix, the name is resolved against the 
default feature namespace <tt>http://zorba.io/features</tt>. All 
Zorba specific features presented in the following are declared in this namespace.

<ul>
<li><b>scripting:</b> This local name can be used to enable or disable the 
Zorba Scripting Extension. Per default, the feature is enabled.
</li>
<li><b>ddl:</b> The <tt>ddl</tt> local name refers to the static
(language-level) Data Description Language portion of the \ref xqddf.
The feature is enabled by default.
</li>
<li><b>trace:</b> The 
<a href="http://www.w3.org/TR/xpath-functions-30/#func-trace">fn:trace</a> 
function can be used to retrieve an execution trace of a query. The local name
<tt>trace</tt> can be used to disable execution trace printing, i.e. calls to
fn:trace are eliminated. Per default, the feature is enabled.
</li>
<li><b>hof:</b> Higher-order functions will be introduced in the upcoming 
XQuery 3.0 recommendation. This feature is only partially implemented in Zorba.
Hence, it is disabled by default. However, the local name <tt>hof</tt> can be 
used to enable the feature if requested.
</li>
<li><b>dtd:</b> The local name <tt>dtd</tt> can be used to enable or disable 
DTD validation when parsing resources retrieved by 
<a href="http://www.w3.org/TR/xpath-functions-30/#func-doc">fn:doc</a>. DTD 
validation is disabled by default.
</li>
<li><b>http-uri-resolution:</b> When resolving URIs for schema and module
import statements, Zorba always first attempts to map the URI to a local
filesystem location (see \ref builtin_uri_resolver). As a fallback, Zorba
will then by default attempt to use HTTP, HTTPS, or FTP (depending on the
URI scheme) to download the resource from the internet. The local name
<tt>http-uri-resolution</tt> can be used to enable or disable this network
fallback. By default it is enabled.
\note Because XQuery options must appear in queries after import statements,
unfortunately the <tt>http-uri-resolution</tt> option can have no effect if
it is specified inside query text. It must be specified using the C++ API
or a Zorba command-line option. An error will be raised if this option is
specified inside query text to avoid confusion.
\note Also note that, unlike other features, this feature is always set or
unset Zorba-wide.
</ul>


### Providing Optimizer Hints

Options can also be used to provide the Zorba optimizer with certain "hints".
All options used for this purpose have a QName whose namespace URI is
<tt>http://zorba.io/options/optimizer</tt>. For some hints, the
optimizer needs to know only whether the hint should be applied or not; no
additional information is required. For such hints, Zorba recognizes two 
options, whose local name is <tt>enable</tt> and <tt>disable</tt>, respectivaly,
and whose value is a comma separated list of hint names. 

Currently, Zorba recognizes only one optimizer hint, called the 
for-serialization-only hint. It is used to tell the optimizer that the only
operation that me be applied to the query result (i.e., to the sequence of 
items returned by the query) is serialization. With this knowledge, the 
optimizer may be able to apply optimizations that would not be possible
otherwise. For example, it may be able to avoid the copying of nodes that
are returned by an enclosed expression within a node constructor. 

The following query shows the usage of this hint. The query groups a number of
sale records by country, and prints the sales in each country within a \code <country> \endcode
tag whose name attribute gives the name of the associated country. The optimizer
can use the for-serialization-only hint to avoid copying the $sale nodes when
it constructs each of the new \code <country> \endcode nodes.

```xquery
declare namespace opt = "http://zorba.io/options/optimizer";

declare option opt:enable "for-serialization-only";

for $sale in doc("sales.xml")/sale
let $country := $sale/country
group by $country
return <country name={$country}>{$sale}</country>
```

The for-serialization-only hint can also be turned on or off via the use of the 
Zorba_CompilerHints struct in the C++ API. Using an option declaration to enable
or disable the hint overwrites the value stored in Zorba_CompilerHints. 


### Warnings in Zorba

Warnings are diagnostic messages that report constructions which are not 
inherently erroneous but which are risky or suggest there may have been an 
error. Analogous to errors, warnings are identified by QNames. Using options,
the user can control whether a particular warning (or all warnings) is (are) 
enabled, disabled, or treated as an error.

For example, given the following prolog, all warnings are treated as errors:

```xquery
  declare namespace op = "http://zorba.io/options/warnings";
  declare namespace w = "http://zorba.io/warnings";

  declare option op:error "w:all";
```

If a given warning doesn't specify a prefix, the name is resolved against the 
default warning namespace <tt>http://zorba.io/warnings</tt>. All 
Zorba specific warnings are defined in this namespace. A comprehensive list 
of warnings is contained at the end of the C++ header file diagnostic_list.h.

The following snippet causes the warning <tt>ZWST0002</tt> (warn for unknown 
annotations) to be suppressed:

```xquery
  declare namespace op = "http://zorba.io/options/warnings";

  declare option op:disable "ZWST0002";
```


#### Zorba Module Versioning

Zorba provides a way that allows the developer of a module to specify a version 
of his module without changing the target namespace. An importing module can 
specify restriction on the version of a module it wants to use. This allows 
developers to easily declare dependencies between particular versions of a 
module. In addition, a module can specify on which version of Zorba it depends.
Details about module versioning can be found at \ref mod_versioning.

The options to declare the module and zorba version are listed here for completeness.

To declare version 2.5 of a module that depends on version 2.0 of Zorba, the
following option declaration may be used.

```xquery
declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "2.5";
declare option ver:zorba-version "2.0";
```

### Introspecting Options in XQuery

In a module, the introspection module of Zorba can be used to get the value 
of an option that is declared.

Specifically, the following function retrieves the value of an option that 
is declared in the prolog of the module. The function returns the empty 
sequence if the option is not contained in the static context.

```xquery
declare function sctx:option($name as xs:QName) as xs:string? external;
```

### Options in Host Languages and External Functions

Besides declaring an option in the prolog of a module, options can also be 
declared or retrieved using the StaticContext representation in any of the 
language bindings (i.e. C++, C, PHP, Ruby, Python, or Java).

For instance, the C++ API provides the following two functions to retrieve 
the value of an option declared in a query and declare options to be used 
in a query, respectively.

<ul>
  <li> bool StaticContext::getOption( const Item& aQName, String& aOptionValue) const;
  <li> void StaticContext::declareOption( const Item& aQName, const String& aOptionValue);
</ul>

For example, the following code snippet depicts how the higher-order function 
feature can be enabled for all modules compiled with the given static context.

```cpp
zorba::StaticContext_t lContext = zorba->createStaticContext();

zorba::Item lEnable = zorba->getItemFactory()->createQName(
  "http://zorba.io/options/features", "", "enable");

lContext->declareOption(lEnable, "hof");

zorba::XQuery_t lQuery = zorba->compileQuery("1+1", lContext);
```

Declaring and retrieving the value of an option is particularly useful in 
external functions. The developer of an external function can retrieve the 
value of an option (from the static context passed to the function). This 
way, she can customize the behavior of her function.


## Annotations

In XQuery (starting with version 3.0) 
<a href="http://www.w3.org/TR/xquery-30/#id-annotations">annotations</a> may
be used to properties associated with functions and variables. Zorba also uses 
annotations for collections and indexes. Annotations are <tt>(QName, value)</tt>
pairs. The prefix of the QName is resolved using the statically known namespaces.
If no prefix is present, the name is the default function namespace.


### Available Annotations

### XQuery 3.0 Annotation

XQuery 3.0 itself defines two annotations: <tt>%fn:public</tt> and <tt>%fn:private</tt>.
Those annotations allow the user to declare a function or a variable as public
or private, respectively. A private variable or function is hidden from a module 
import. That is, it can not be used in the importing module.

For example, a function declared a module as follows, can not be used in a module
which imports the *mymodule* module:

```xquery
declare %private function mymodule:foo() { "foo" };
```


\subsubsection zorba_annotations Zorba Specific Annotations

Zorba provides a number of annotations that allow the user to define the 
semantics of functions, variables, collections, and indexes. All these 
annotations have the namespace <tt>http://zorba.io/annotations</tt>.


\paragraph deterministic_annotation Deterministic and Nondeterministic Functions

A deterministic function is a function that always evaluates to the same result 
if it is invoked multiple times with the same arguments during the evaluation 
of a <a href="/scripting-spec?anchor=id-snapshot-scope">snapshot</a>. In general, 
all functions defined by XQuery are deterministic. However, a module developer 
might develop a function (in a host language) which does not guarantee to be 
deterministic. For example, a function generating random numbers is clearly 
not deterministic. Knowing about this property is crucial for the query optimizer
to retain the semantics (e.g. caching would lead to incorrect results).

For this reason, Zorba provides two annotations (<tt>nondeterministic</tt> and
<tt>deterministic</tt>) that allow a developer to declare whether a function 
is deterministic or not.

As an example, the following snippet declares a nondeterministic random function.

\code
declare namespace an = "http://zorba.io/annotations";

declare %an:nondeterministic function random:random() as xs:integer external;
\endcode

If not specified otherwise, all functions are being treated as deterministic.
If some function invokes a nondeterministic function, the invoking function itself must also be declared as nondeterministc, otherwise zerr::ZXQP0040 is raised.


\paragraph sequential_annotation Sequential Functions

In XQuery 3.0, an expression never has any side effects other than constructing new nodes (not even updating expressions, which merely produce a pending update list).
Zorba Scripting programs may have side effects.
Side effects can be made with statements.
An expression is sequential if it contains statements that have side effects (updating some XML, assigning a variable in scope outside of the expression) or that affect the control flow (break, continue, exit returning), or if it invokes a sequential function.
Analogously to nondeterministic functions, the compiler needs to be able to infer if an expression is sequential.
In order to do so, Zorba provides the <tt>%an:sequential</tt> and <tt>%an:nonsequential</tt> annotations.
The <tt>%an:sequential</tt> annotation must be used to declare (external) functions that have side effects.
If non of these annotations is present, the default for a function is to be annotated as <tt>%an:nonsequential</tt>.
If a function invokes a sequential function but is itself not declared sequential (i.e. no annotation or <tt>%an:nonsequential</tt>), an error is raised (zerr:XSST0004).

For example, the <tt>http:post</tt> function of the http-client module is declared as sequential because invoking it might cause a side effect (e.g. a payment with paypal).

\code
declare %an:sequential function http:post(
  $href as xs:string,
  $body as item(),
  $content-type as xs:string) as item()+ { ... }
\endcode

\paragraph assignable_annotation Assignable and Nonassignale Variables
In plain XQuery without scripting, global variables (i.e. those declared in the prolog of a module) can not be assigned a value.
In scripting (i.e. if the scripting feature is enabled), however, values can be assigned to a variable.

In order to allow the developer to prevent variable assignments (even with scripting), Zorba provides the <tt>%an:nonassignable</tt> annotation.

For example, preventing a variable from being assigned in scripting mode could be done as follows:

\code
declare namespace an = "http://zorba.io/annotations";

declare %an:nonassignable variable $var := 3;
\endcode

If a value is assigned to a nonassignable variable, the error <tt>XSST0007</tt> in the Zorba error namespace is raised.

\paragraph variadic_annotation Variadic Functions
A function annotated with the <tt>%an:variadic</tt> annotation is a function of indefinite arity, i.e. one that accepts a variable number of arguments.  

For example, the function to create an unordered map with an arbitrary number of key types (see module <a href="/modules/latest/zorba.io/modules/store/data-structures/unordered-map">http://zorba.io/modules/store/data-structures/unordered-map</a>) is declared as follow:

\code
declare %an:variadic %an:sequential function map:create(
  $name as xs:QName,
  $key-type as xs:QName) as empty-sequence() external;
\endcode


\paragraph streamable_annotation Streamable Strings

A function annotated with the <tt>streamable</tt> annotation is a function that may return an xs:string item whose content is streamed.
Such a string is called a streamable string.
They have the advantage that their contents does not need to be materialized in memory.
If a function consuming such a string is able to process the string in a streaming fashion, this allows for processing of strings with a virtually infinite length.

For example, the following XQuery code, reads a file from disk and returns the contents to the standard output of the calling process.
Because the file:read-text function is annotated using the <tt>streamable</tt> annotation, the file does not have to be materialized in memory.

\code
import module namespace file = "http://expath.org/ns/file";

file:read-text("big_file.txt")
\endcode

However, the disadvantage is that a streamable string can only be consumed exactly once.
If a streamable string is consumed more than once, an error is raised.
In order to enable multiple consumers of a streamable string, the materialize function of the string module (<a href="/modules/latest/zorba.io/modules/string">http://zorba.io/modules/string</a>) should be used to materialize the entire contents in an (regular) xs:string item.

\code
import module namespace file = "http://expath.org/ns/file";
import module namespace string = "http://zorba.io/modules/string";

let $x := string:materialize(file:read-text("myfile.txt")))
return ($x, $x)
\endcode

In this example, the <tt>file:read-text</tt> function returns a streamable string whose contents is used twice in the query.
In order to be able to use the value twice, the <tt>string:materialize</tt> function must be used to materialize the entire contents of the file <tt>myfile.txt</tt> in memory.
Otherwise, the error zerr:ZSTR0055 is raised.


\paragraph caching_annotation Caching Results of Functions

Caching of function results may improve performance when computationally 
expensive functions are invoked multiple times with the same arguments.

If the optimization level is O1 or higher, Zorba automatically caches results
of recursive, deterministic, and non-sequential functions whose parameter and 
return types are subtypes of xs:anyAtomicType. Specifically, if such a function
is called more than once with the same arguments, the result of the first call
will be cached and subsequent calls will return the cached value without 
re-evaluating the function.

For example, in the following recursive function computing a fibonacci number, 
each result is automatically cached and, hence, dramatically improves performance.

\include zorba/udf/udf-fib-rec.xq

Specifically, this optimization reduces the complexity of the function from
O(1.6^n) to O(n).

In order to explicitly disable function caching, the user can specify the 
<tt>%an:no-cache</tt> annotation.

In addition, the user can use the <tt>%an:cache</tt> annotation to cache the 
results of functions other than the ones that are automatically cached. However, 
this will only work if the function is not updating and its parameter and return
types are subtypes of xs:anyAtomicType; otherwise, Zorba will raise a warning 
(zwarn:ZWST0005) and simply ignore the %an:cache annotation.

Please note, that explicitly enforcing caching for sequential or nondeterministic
functions might not give the intended result. In such cases, Zorba will raise a
warning (zwarn:ZWST0006) but obey the %an:cache annotation.


\paragraph no_copy_rule_annotation Avoiding Node Copying in Node Constructors.

According to the XQuery specification, any nodes (and their subtrees) returned
by an enclosed expression appearing inside a node constructor must be copied,
and it is the copied subtrees that are then connected to the newly constructed
node. However, such copying is not always necessary. If no copying is done, then
some nodes will be "shared" by multiple trees. XML trees that do not contain
any shared nodes will be referred to as "stand-alone trees". 

Whether node copying is really necessary or not depends on the kind of operations 
that are going to be performed on the nodes and their associated trees after the 
node construction. For example, copying is necessary if any operations involving
node identity, document ordering, or reverse axis traversals are to be performed
on the newly constructed tree. Copying is also necessary if the relevant nodes may
be involved in a later update operation. The Zorba optimizer is able to analyze
the query expressions and determine automatically whether copying is required or not.
However, the optimizer needs some help from the user in the case of external
functions, because it cannot look into the operations of such functions. For this,
Zorba provides two annotations that users may annotate their external functions 
with in order to help the optimizer determine whether to copy nodes or not. 

<ul>
<li>
<b>%an:must-copy-input-nodes</b>. This annotation has an associated value, which
is a list of integer literals. The meaning of the annotation is the following:
If a number N appears in the value, then the function requires that any nodes
that are bound to the N-th parameter when the function is called, must belong to
standalone trees (because the function is going to perform on such nodes an 
operation that requires standalone trees). As a result of this information, the
optimizer makes sure that node copying is done during any node constructor whose
result (or any subtree of it) may be given as input to such an external function.
</li>
<li>
<b>%an:propagates-input-nodes</b>. This annotation has an associated value, which
is a list of integer literals. The meaning of the annotation is the following:
If a number N appears in the value, then the function may return to its caller
a node n that is bound to the N-th parameter, or a node in the subtree of n. This
annotation helps the optimizer determine whether nodes consumed by an expression
are coming from a node constructor, so that if the expression requires stand-alone
trees, then the optimizer will make sure that the relevant node constructor does
copy nodes.
</li>
</ul>

The absence of any of the above  annotations from an external function declaration
is treated as if the annotation was present with a value listing all the numbers 
between 1 and M, where M is the function arity.

\paragraph collection_index_annotations Annotations on Collections and Indexes

The \ref xqddf uses annotations to assign properties to collections and indexes.
For example, annotations can be used to specify that a collection is unordered or that an index is a value equality index.

The semantics of each of the annotations is given in the documentation about the XQuery Data Definition Facility.
However, for completeness, we also list all of the annotations here.

<ul>
  <li><b>%an:mutable, %an:queue, %an:append-only, %an:const</b> Determines whether a collection is mutable, queue (FIFO), append-only, or const (not mutable). The default annotation is mutable. </li>

  <li><b>%an:ordered, %an:unordered</b>  Annotations to specify whether the order of nodes in a collection must be preserved. The default is ordered.</li>

  <li><b>%an:read-only-nodes, %an:mutable-nodes</b> If a collection is annotated with read-only-nodes, the nodes in the collection can not be modified using the XQuery Update Facility. The default is %an:mutable-nodes.</li>

  <li><b>%an:unique, %an:nonunique</b> Unique indexes make sure that the relationship between index keys and values is one-to-one. The default is %an:nonunique.</li>

  <li><b>%an:value-equality, %an:value-range, %an:general-range, %an:general-equality</b> Determine whether the index is a value or general equality or value range index, respectively. The default is %an:value-equality.</li>

  <li><b>%an:automatic, %an:manual</b> If an index is declared as automatic, Zorba guarantees that the index is maintained automatically. The default is %an:manual.</li>

</ul>


\subsection annotations_introspection Introspecting Function Annotations

Analog to options, the introspection module of that comes with Zorba allows you to retrieve all annotations declared for a particular function.

\code
declare function sctx:function-annotations(
  $name as xs:QName,
  $arity as xs:integer) as xs:QName* external;
\endcode

\section pragma_introduction Extension Expressions

An extension expression consists of one or more pragmas, followed by an expression enclosed in curly braces.
A pragma might be used to modify the behavior or semantics of the expression enclosed in curly braces.
Pragmas are denoted by the delimiters (# and #), and consists of an identifying EQName.
Zorba recognizes pragmas having the namespace <tt>http://zorba.io/extensions</tt>.
Specifically, Zorba recognizes the following pragmas:

<ul>
  <li><b>no-copy</b> In order to indicate that a node that should be inserted into a collection does not need to be copied before inserting it. Not copying a node improves performance. However, the user needs to make sure that the node does not have a parent and is not modified in any other expression. For example, in the following example snippet, the node refered to by <tt>$n</tt> will not be copied before insertion into the collection.
\code
import module namespace db = "http://zorba.io/modules/store/dynamic/collections/dml";

declare namespace ext = "http://zorba.io/extensions";

let $n := <a/>
return (# ext:no-copy #) { $n is  db:apply-insert-last(xs:QName("local:bar"), $n) }
\endcode
  </li>
</ul>