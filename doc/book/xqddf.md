# Data Definition Facility

Zorba has support for collections, indexes, and integrity constraints.
This is accomplished via a combination of new prolog declarations, new kinds of 
expressions or extensions to existing expressions,
and new built-in functions. Furthermore, both the static and the dynamic
contexts are extended with new components that store information about
collections, indexes, and integrity constraints. Collectively, all these
extensions are called the <strong>Data Definition Facility</strong>

\n \n As part of the implementation, Zorba includes new "built-in" modules
that contain the declarations of all the new built-in functions to manage (ddl)
and manipulate (dml) collections, indexes, and integrity constraints.


<ul>
  <li><a href="/modules/latest/zorba.io/modules/store/static/collections/dml">http://zorba.io/modules/store/static/collections/dml</a> (prefix: cdml)</li>
  <li><a href="/modules/latest/zorba.io/modules/store/static/collections/ddl">http://zorba.io/modules/store/static/collections/ddl</a> (prefix: cddl)</li>
  <li><a href="/modules/latest/zorba.io/modules/store/static/indexes/dml">http://zorba.io/modules/store/static/indexes/dml</a> (prefix: idml)</li>
  <li><a href="/modules/latest/zorba.io/modules/store/static/indexes/ddl">http://zorba.io/modules/store/static/indexes/ddl</a> (prefix: iddl)</li>
  <li><a href="/modules/latest/zorba.io/modules/store/static/integrity/constraints/dml">http://zorba.io/modules/store/static/integrity_constraints/dml</a> (prefix: icdml)</li>
  <li><a href="/modules/latest/zorba.io/modules/store/static/integrity/constraints/ddl">http://zorba.io/modules/store/static/integrity_constraints/ddl</a> (prefix: icddl)</li>
</ul>

As usual, these modules must be imported by any other module that wants to invoke any of the functions.

\section collections Collections

<h3><a name="collection">Collections</a></h3> A collection is defined as an ordered
set of documents that is disjoint from any other collection and is uniquely
identified by a QName. Furthermore, with respect to document order, the relative
order of two nodes belonging to different documents within the same collection
is defined to be the same as the relative position of their containing documents
within the collection. We will say that a node belongs to a collection if it is
inside a document that belongs to that collection.

\n \n Like a W3C collection, an <a href="#collection">collection</a> can be
viewed as a sequence of nodes: it is the sequence containing the root nodes of
the documents that belong to the collection (and as we will see later, the
function <a href="#cdml_collection"
title="cdml:collection">cdml:collection</a> returns exactly this sequence of
nodes). However, even when viewed as sequences of nodes, <a
href="#collection">collections</a> differ from W3C collections in the
following ways:

<ul>
  <li>They contain parent-less nodes only.</li>
  <li>They can not contain any duplicate nodes.</li>
  <li>Their nodes are in document order.</li>
  <li>A node can not be contained in more than one <a href="#collection">collection</a>.</li>
  <li>collections are identified by QNames, whereas W3C collections are
identified by URIs.</li>
</ul>

For brevity, in the remaining of this document we will use the term "collection" to
mean <a href="#collection">collection</a>. For backward compatibility with
the W3C XQuery specification, Zorba retains some basic support for W3C
collections (see <a href="../modules/latest/zorba.io/modules/store/dynamic/collections/w3c/dml">http://zorba.io/modules/store/dynamic/collections/w3c/dml</a> and <a href="/modules/latest/zorba.io/modules/store/dynamic/collections/w3c/ddl">http://zorba.io/modules/store/dynamic/collections/w3c/ddl</a>).
However, users are encouraged to use <a href="#collection">collections</a> instead.

Zorba supports five kinds of operations on collections: <a
href="#collection_declaration">collection declaration</a>, <a
href="#creating_collections">collection creation</a>, <a
href="#destroying_collections">collection deletion</a>, <a
href="#updating_collections">collection update</a>, and <a
href="#accessing_collections">node retrieval</a>. These are explained briefly in
the following simple example. Full details for each operation are provided in
the subsequent chapters.

\subsection collections_in_action Collections in action - A simple example

\n Let us assume an application that models a news organization. The application
models its data as XML documents grouped into collections of logically related
entities. In this example, we show how three such collections may be created and
used; the first collection contains employee data, the second contains news
articles, and the third contains information about the months of the year (e.g.,
the name, number of days, and fixed holidays for each month).

\n \n Before a collection can be created, it must be declared. A <strong>collection
declaration</strong> describes the collection by providing a unique name for it
and specifying certain properties (using XQuery Annotations) for the collection itself and for the
documents in the collection. As explained in \ref collection_declaration,
collections must be declared inside library modules. In terms of the XQuery
language, collection declarations become part of a module's static context.

\n \n In this example, the declarations are placed inside the <a
href="#lib_module_news_data_collections" title="news-data">"news-data"</a>
library module (shown below). The declarations assign the names
news-data:employees, news-data:articles, and news-data:months to the three
collections, respectively. Documents in both the employees and the months
collections are assumed to have a well-known structure, which is reflected in an
XML schema ("news-schema"). The schema declares two global elements for
employees and months respectively. Accordingly, the collection declarations for
employees and months specify that their root nodes are elements whose name and
type matches the name and type of the corresponding global element declarations
in "news-schema". In contrast, articles may come from various sources (including
external ones), and as a result, article documents do not have any particular
schema. Therefore, the declaration for the articles collection specifies node()
as the type of the root nodes. Both employee and article documents may be
updated during their lifetime. Instead, the months-related information is fixed
(can not change), so the nodes of the months collection are declared as
'%an:read-only-nodes'. Furthermore, the collection itself is declared '%an:const', meaning
that no months may be added to or deleted from this collection after it is
created and initialized. Finally, we want the order of the month documents
within their containing collection to be the same as the actual order of the
months within the year. To achieve this, we have to declare the collection as
"ordered", so that when we later insert the month documents in the collection,
the system will store and return them in the same order as their insertion
order. In contrast, the position of employees or articles inside their
respective collections does not have any special meaning for the application, so
the corresponding declarations do not specify any ordering property. This allows
the system to store and access the contents of these collections in what it
considers as the most optimal order.

<a name="lib_module_news_data_collections"
id="lib_module_news_data_collections"></a>
\code
  (: The "news-data" Library Module :)

  module namespace news-data = "http://www.news.org/data";

  import schema namespace news-schemas = "http://www.news.org/schemas";

  declare namespace an = "http://zorba.io/annotations";

  declare collection news-data:employees as schema-element(news-schema:employee)*;

  declare collection news-data:articles as node()*;

  declare %an:const %an:ordered %an:read-only-nodes collection news-data:months
    as schema-element(news-schema:month)*;

  declare variable $news-data:employees := xs:QName("news-data:employees");
  declare variable $news-data:articles := xs:QName("news-data:articles");
  declare variable $news-data:months := xs:QName("news-data:months");
\endcode

Having been declared, the collections can now be created. <strong>Collection
creation</strong> is illustrated by the "admin-script-1" script shown below.
First, the collection descriptions must be made visible to the script. This is
done by importing the <a href="#lib_module_news_data_collections"
title="news-data">"news-data"</a> library module that contains the collection
declarations. Then, the collections are created by calling the
cddl:create function. There are two versions of this function: the
first takes a QName as input and the second takes both a QName and a
node-producing expression. In the first version, an empty document container is
created by Zorba's storage system and registered inside a <strong>collections
table</strong> that maps collection names to document containers. In the second
version, the given expression is evaluated first, and (deep) copies are made of
the nodes in the result sequence. This way, a sequence of distinct documents is
produced. This is called the "insertion sequence". Then, as in the first version
of the function, the document container is created and registered. Finally, the
container is populated with the documents in the insertion sequence. In
"admin-script-1", this second version is used to create and initialize the
months collection. In fact, months must be initialized during creation because
it is a constant collection, so no documents can be added to it later. The
months are inserted in the collection in the order from January to December, and
since the collection was declared as '%an:ordered', this order is preserved by the
associated document container.

\code
  (: "admin-script-1" :)

  import module namespace cddl = "http://zorba.io/modules/store/static/collections/ddl";

  import module namespace news-data = "http://www.news.org/data";

  cddl:create($news-data:employees);

  cddl:create($news-data:articles);

  cddl:create($news-data:months, (<month name="Jan">...</month>, ..., <month name="Dec">...</month>));
\endcode

The next script ("user-script-1") shows how collections may be used. First the
necessary modules and schemas are imported. Next, the employees collection is
populated using the cdml:insert-nodes function. The first argument to this
function is the QName of a collection, and the second is a node-producing
expression (called the source expression). The QName is used to lookup the
collection declaration and the collection itself (i.e., its document container).
Then, the nodes produced by the source expression (source nodes) are copied and
the copies are added to the document container, making sure that the actual type
of each node matches the static type found in the collection declaration.
Copying the source nodes (and their sub-trees) guarantees that the nodes in the
insertion sequence are indeed parent-less nodes that do not belong to any other
collection already and are distinct from each other. Notice that the need to
validate the root nodes against the type specified in the collection declaration
is the reason why the "news-schema" must be imported, even though no type
defined by the schema is referenced explicitly in the query.

\n \n In this example, the employees collection is populated by a single call to the
cdml:insert-nodes function, whose source expression is a concatenation of
explicitly constructed documents. The articles collection is populated using the
cdml:insert-nodes function as well, but in a slightly different fashion: The
article documents are assumed to exist already, either as text files in the
local filesystem, or at various web sites. As a result, the articles collection
is populated via a concatenation of cdml:insert-function calls, each reading
and parsing a single XML document and inserting the generated XML tree in the
collection. Although there is one function call per article, the articles will
be inserted all together in an atomic (all-or-nothing) operation, when the ";"
at line 16 is processed. This is because, as explained in \ref
updating_collections, the cdml:insert-nodes function (and all other 
functions that create, delete, or update collections) is an //updating
function//, that is, rather than applying the insertion immediately, it produces
an updating primitive that becomes part of a pending updates list (PUL), which
is applied atomically when the next ";" appears in the program.

\n \n After populating the two collections, "user-script-1" runs a query expression
that uses the <a href="#cdml_collection"
title="cdml:collection">cdmlcdml:collection</a> function to access their root
nodes. The expression returns, for each journalist, the articles authored by
that journalist ordered by their date.

\n \n Finally, "user-script-1" uses the cdml:remove-nodes function to remove from the
articles collection all articles that were published before 2000. Like
cdml:insert-nodes, cdml:remove-nodes takes as input the QName of a collection
and a node-producing source expression. The source nodes must be parent-less
nodes that belong to the collection. The function looks up the collection
declaration and the collection container, and removes the source nodes from the
collection container.

\code
  (: "user-script-1":)

  import module namespace cdml = "http://zorba.io/modules/store/static/collections/dml";

  import module namespace http = "http://www.zorba-xquery.com/modules/http-client";

  import schema namespace news-schemas = "http://www.news.org/schemas";

  import module namespace news-data = "http://www.news.org/data";

  cdml:insert-nodes($news-data:employees, (<employee id="100">...</employee>, ..., <employee id="500">...</employee>));

  (
    cdml:insert-nodes($news-data:articles, doc("article1.xml")/article),
    cdml:insert-nodes($news-data:articles, http:get("http://www.reuters.com/article234.xhtml")//article),
    ....,
    cdml:insert-nodes($news-data:articles, doc("article100.xml")/article)
  );

  for $emp in cdml:collection($news-data:employees)[./position/@kind eq "journalist"]
  let $articles := for $art in cdml:collection($news-data:articles)[.//author//name eq $emp/name]
                   order by $art//date
                   return $art
  return <result>{$emp}<articles>{$articles//title}</articles></result>;

  cdml:delete-nodes(cdml:collection($news-data:articles)[.//date lt xs:date("01/01/2000")]);
\endcode

We conclude this example with the "admin-script-2" script, which simply destroys
the collections using the cddl:delete function. The function
de-registers the collection from the collections table, destroys all the
documents in the collection and all the indexes and integrity constraints
associated the collection, and finally destroys the document container itself.

\code
  (: admin-script2 :)

  import module namespace cddl = "http://zorba.io/modules/store/static/collections/ddl";

  import module namespace news-data = "http://www.news.org/data";

  cddl:delete($news-data:employees);

  cddl:delete($news-data:articles);

  cddl:delete($news-data:months);
\endcode

\subsection collection_declaration Collection Declaration

\code
  AnnotatedDecl
          ::= 'declare' ( CompatibilityAnnotation | Annotation )*
              ( VarDecl | FunctionDecl | CollectionDecl | IndexDecl | ICDecl )
  CollectionDecl ::= 'collection' EQName CollectionTypeDecl?

  CollectionTypeDecl ::= 'as' KindTest OccurrenceIndicator?
\endcode

Collections are defined by <strong>collection declaration statements</strong>,
which specify a unique name for a collection as a QName, a set of collection
annotations (see \ref collection_index_annotations), the collection's static type.
Syntactically, collection declarations are placed inside
module prologs. The Prolog syntax is extended accordingly, as shown above. An
additional constraint (not expressible syntactically) is that only library
modules may contain collection declarations [<a href="#ERRZDST0003"
title="zerr:ZDST0003">zerr:ZDST0003</a>]. This is because library modules can be
shared among queries, whereas if a collection was declared inside a main module,
then every other query that would like to use this collection would have to
redeclared it in its main module. Worse, allowing collection declarations in
"user" queries can lead to "data leaks": a collection declared and created by a
user query and not destroyed by the same query will be unknown to the rest of
the application, and may stay in the database indefinitely. In contrast, library
modules containing declarations are expected to be under the jurisdiction
of a system administrator who makes sure that queries see the data that they
must see, and no data inconsistencies or leaks can arise.

\n \n To accommodate collection declarations, Zorba extends the static context with a
component called the <strong>statically known collections</strong>. This is a
map whose entries associate an expanded QName with an implementation-dependent
representation of the information contained in a collection declaration with the
same QName. The effect of a collection declaration is to add an entry to the
statically known collections of the module containing the declaration. If the
expanded QName of the collection is equal (as defined by the eq operator) to the
expanded QName of another collection in the statically known collections of the
same module, a static error is raised [<a href="#ERRZDST0001"
title="zerr:ZDST0001">zerr:ZDST0001</a>]. Like variables and functions, the
statically known collections of a module that is imported by another module are
copied into the statically known collections of the importing module. It is a
static error [<a href="#ERRZDST0002" title="zerr:ZDST0002">zerr:ZDST0002</a>] if
the expanded QName of a collection declared in an imported module is equal (as
defined by the eq operator) to the expanded QName of a collection declared in
the importing module or in another imported module (even if the declarations are
consistent).

Zorba defines three categories of collection annotations:

<strong>update mode</strong> (with possible values '%an:const', '%an:mutable', '%an:append-only', or '%an:queue'),
<strong>ordering mode</strong> (with possible values '%an:ordered' or '%an:unordered'), and
<strong>document update mode</strong> (with possible values '%an:read-only-nodes' and '%an:mutable-nodes').

If not specified, the default values for update and ordering mode are '%an:mutable' and '%an:unordered', respectively.
The default value for the document update mode is '%an:mutable-nodes'.

\n \n It is a static error [err::XQST0106] if a collection declaration contains more than one value for the same property.
An <strong>ordered collection</strong> is a collection into which the ordering of documents is assumed to be meaningful for the application, and as a result, programmers can explicitly control the placement of documents via appropriate updating functions.
In contrast, the ordering of documents inside <strong>unordered collections</strong> is implementation dependent, but stable (see \ref accessing_collections for details).
A <strong>constant collection</strong> is one that is created with an initial set of documents and
does not allow any subsequent insertions to or deletions from this initial set.

\n \n An '%an:append-only' collection does not allow any deletions at all and restricts insertions to take place at the "end" only, i.e., all new documents must be inserted after all existing ones.
This implies a user-visible document ordering, and as a result, an '%an:append-only' collection must also be declared as '%an:ordered' [err:XQST0106].
A '%an:queue' collection forbids both insertions and deletions in/from the "middle"; only documents at
the front of the collection may be deleted, and new documents can be inserted only at the end of a collection.
Like '%an:append-only', '%an:queue' collections must be declared as '%an:ordered' [err:XQST0106].
If the document update mode of a collection is '%an:read-only-nodes' then an error is raised [<a href="#ERRZDDY0010" title="zerr:ZDDY0010">zerr:ZDDY0010</a>] every time a node of the collection appears as the target node of an updating expression; otherwise no such error is raised.

In addition to the annotations described above, a collection declaration also
specifies the <strong>collection static type</strong>, i.e., the static type for
the result of the <a href="#cdml_collection"
title="cdml:collection">cdml:collection</a> function. This is specified as a
sequence type that adheres to the syntax and semantics of a KindTest plus an
(optional) occurrence indicator. If no static type is specified, it is assumed
to be document-node(element(*, xs:untyped))*. The static type without the
occurrence indicator is the static type of the collection's root nodes.

\subsection creating_collections Creating Collections

\n As explained already, collections are just sets of parent-less XML trees (called
"documents"). In terms of the language, these sets
"live" in the dynamic context. In particular, the dynamic context is extended
with a component called the <strong>available collections</strong>. This is a
map whose entries associate the expanded QName of a collection with the
collection's document set. If an entry for a collection appears in the available
collections of a module, the collection is said to be available to that module.

\n \n In practice, the available collections component is implemented by the storage system of Zorba.
To begin with, each document set is implemented by some
appropriate data structure that acts as a document container. The description of
potential data structures is beyond the scope of this document, but the choice
will, in general, depend on the properties of the collection and the contained
documents. In addition to managing the document containers, the store maintains
a <strong>collections table</strong>, which maps collection names to document
containers. The collections table is accessible by all queries, so once an entry
is added to the table, the associated collection is assumed to be available to
every query and every module that participates in the execution of that query.

\n \n Creation of a collection involves creating an initially empty document container
and "registering" that container in the collections table. We provide two
functions for creating collections. Both are updating functions, so instead of
actually performing the updates, they generate pending update primitives that
become part of a pending update list (PUL) to be applied at a later time (see
\ref extensions_xquf_updates_routines). The functions and their associated
update primitives are described below:

\code
  declare updating function cdml:create_collection($collectionName as xs:QName)

  upd:createCollection($collectionName as xs:QName)
\endcode

The function is evaluated as follows:

  <ul>
  <li>If the given expanded QName does not identify a collection among the
statically known collections in the static context of the invoking module, an
error is raised [<a href="#ERRZDDY0001"
title="zerr:ZDDY0001">zerr:ZDDY0001</a>].</li>
  <li>If the given expanded QName identifies a collection that is available
already, an error is raised [<a href="#ERRZDDY0002"
title="zerr:ZDDY0002">zerr:ZDDY0002</a>].</li>
  <li>The result of the function is an empty XDM instance and a pending update
list that consists of a single update primitive:
upd:createCollection($collectionName).</li>
  </ul>

The update primitive is applied as follows:

  <ul>
  <li>An empty document container is created.</li>
  <li>A entry is added to the collections table. The entry maps the collection's
expanded QName to the document container.</li>
  </ul>

The second create function creates the collection and populates it
with an initial set of trees.

\code
  declare updating function cdml:create_collection($collectionName as xs:QName, $nodes as node()*)
\endcode

The function is evaluated as follows:

  <ul>
  <li>If the given expanded QName does not identify a collection among the
statically known collections in the static context of the invoking module, an
error is raised [<a href="#ERRZDDY0001"
title="zerr:ZDDY0001">zerr:ZDDY0001</a>].</li>
  <li>If the given expanded QName identifies a collection that is available
already, an error is raised [<a href="#ERRZDDY0002"
title="zerr:ZDDY0002">zerr:ZDDY0002</a>].</li>
  <li>The expression that is given as the second argument to the function call
is evaluated. The result of the evaluation is called the source sequence. If the
source sequence contains an item that is not a node, or a node whose actual type
does not match the root static type specified in the collection declaration, a
type error is raised [<a href="#ERRXDTY0001"
title="zerr:XDTY0001">zerr:XDTY0001</a>].</li>
  <li>Each of the nodes in the source sequence is copied as if it was a node
returned by an enclosed expression in a direct element constructor (see
http://www.w3.org/TR/xquery/#id-content). The construction and copy-namespaces
modes used during the copy operation are the ones in the static context of the
invoking module. Let $nodes be the sequence containing the copied nodes. Every
node in $nodes is a root (parent-less) node that does not belong to any
collection and is distinct from any other node in $nodes.</li>
  <li>The result of the function is an empty XDM instance and a pending update
list that consists of the following update primitives:
upd:createCollection($collectionName) and upd:insertNodesFirst($collectionName,
$nodes)</li>
  </ul>

The upd:createCollection primitive was described above. The upd:insertNodesFirst
will be described in \ref updating_collections, in the context of the
cdml:insert-nodes-first function.

\subsection accessing_collections Accessing Collections

To access the root nodes of a collection, the <strong><a
name="cdml_collection" id="cdml_collection"></a>cdml:collection</strong>
function is provided.

\code
  declare function cdml:collection($collectionName as xs:QName) as node()*
\endcode

The function is evaluated as follows:

  <ul>
  <li>If the given expanded QName does not identify a collection among the
statically known collections in the static context of the invoking module, an
error is raised [<a href="#ERRZDDY0001"
title="zerr:ZDDY0001">zerr:ZDDY0001</a>].</li>
  <li>If the given expanded QName does not identify a collection among the
available collections in the dynamic context of the invoking module, an error is
raised [<a href="#ERRZDDY0003" title="zerr:ZDDY0003">zerr:ZDDY0003</a>].</li>
  <li>The result of the function is a sequence consisting of the root nodes in
the collection. If the collection is declared as '%an:ordered', the ordering of the
nodes in the result will reflect the order into which nodes were inserted in the
collection by the node insertion functions (see \ref
updating_collections). If the collection is declared as '%an:unordered', the ordering
of the nodes in the result is implementation-dependent. In both cases, the nodes
in the sequence are, by definition, in document order. For unordered
collections, this document ordering is guaranteed to be stable within a query
snapshot (i.e., until the next time updates are applied). For ordered
collections, the document ordering is stable "forever" (i.e., two root nodes in
the collection will compare the same as long as the collection (and the nodes)
exist).</li>
  </ul>

Another non-updating function that accesses a collection implicitly, is
the index-of function:

\code
  declare function cdml:index_of($node as node()) as xs:integer
\endcode

The function is evaluated as follows:

  <ul>
  <li>If the given node is not a root node of a collection, an error is raised [<a href="#ERRZDDY0011"
title="zerr:ZDDY0011">zerr:ZDDY0011</a>].</li>
  <li>The result of this function is the position as xs:integer of the given
node within its collection.</li>
  </ul>

\subsection updating_collections Updating Collections

A <strong>collection update</strong> is an operation that either inserts or
deletes a number of root nodes (and their subtrees) to/from a collection. Zorba
provides five updating functions that insert root nodes, and another five updating functions that delete
root nodes. All of these functions are //updating functions// (in the
terminology of the XQUF). As a result, rather than applying the update
immediately, they produce an updating primitive that becomes part of a pending
updates list (PUL), which is applied atomically when the next ";" appears in a
script. The signature and semantics of each function and its associated update
primitive are described in this section. The order in which the various update
primitives are applied and constraints in how update primitives may be combined
in a PUL are described in \ref extensions_xquf_updates_routines.

\n \n In addition to the updating insert functions, Zorba also provides five 
sequential insert functions (i.e. cdml:apply-insert-nodes,
cdml:apply-insert-nodes-first, cdml:apply-insert-nodes-last,
cdml:apply-insert-nodes-before, cdml:apply-insert-nodes-after) .
These sequential counterparts apply the update primitive implicitly and return
the node that was inserted into the collection.
This is especially useful because nodes are copied before they are inserted into
a collection.

\code
  declare updating function cdml:insert-nodes($collectionName as xs:QName, $nodes as node()*)

  upd:insertIntoCollection($collectionName as xs:QName, $nodes as node()*)
\endcode

The insert-nodes function is evaluated as follows:

  <ul>
  <li>If the given expanded QName does not identify a collection among the
statically known collections in the static context of the invoking module, an
error is raised [<a href="#ERRZDDY0001"
title="zerr:ZDDY0001">zerr:ZDDY0001</a>].</li>
  <li>If the given expanded QName does not identify a collection among the
available collections in the dynamic context of the invoking module, an error is
raised [<a href="#ERRZDDY0003" title="zerr:ZDDY0003">zerr:ZDDY0003</a>].</li>
  <li>If the update mode of the collection is const, append-only, or queue, an
error is raised [<a href="#ERRZDDY0004" title="zerr:ZDDY0004">zerr:ZDDY0004</a>],
[<a href="#ERRZDDY0005" title="zerr:ZDDY0005">zerr:ZDDY0005</a>], or [<a
href="#ERRZDDY0006" title="zerr:ZDDY0006">zerr:ZDDY0006</a>], respectively.</li>
  <li>The expression that is given as the second argument to the function call
is evaluated. The result of the evaluation is called the source sequence. If the
source sequence contains an item that is not a node, or a node whose actual type
does not match the KindTest specified in the collection declaration, a type
error is raised [<a href="#ERRXDTY0001" title="zerr:XDTY0001">zerr:XDTY0001</a>].</li>
  <li>Each of the nodes in the source sequence is copied as if it was a node
returned by an enclosed expression in a direct element constructor (see
http://www.w3.org/TR/xquery/#id-content). The construction and copy-namespaces
modes used during the copy operation are the ones in the static context of the
invoking module. Let $nodes be the sequence containing the copied nodes. Every
node in $nodes is a parent-less root node that does not belong to any collection
and is distinct from any other node in $nodes.</li>
  <li>The result of the function is an empty XDM instance and a pending update
list that consists of a single update primitive:
upd:insertIntoCollection($collectionName, $nodes).</li>
  </ul>

The update primitive is applied as follows: 

  <ul>
  <li>The document container for the collection is found via the collections
table.</li>
  <li>The root nodes in $nodes are inserted into the container. If the
collection is an ordered one, then all the nodes are inserted next to each other
and in the same order as they appear in $nodes. The position of the first node
to be inserted is implementation-dependent. The relative positions of
pre-existing root nodes do not change as a result of the insertions. If the
collection is an unordered one, each node is inserted in some
implementation-dependent position. Furthermore, the relative positions of
pre-existing root nodes may change as a result of the insertions.</li>
  </ul>

\code
  declare updating function cdml:insert-nodes-first($collectionName as xs:QName, $nodes as node()*)

  upd:insertFirstIntoCollection($collectionName as xs:QName, $nodes as node()*)
\endcode

The insert-nodes-first function is evaluated as follows:

  <ul>
  <li>If the given expanded QName does not identify a collection among the
statically known collections in the static context of the invoking module, an
error is raised [<a href="#ERRZDDY0001"
title="zerr:ZDDY0001">zerr:ZDDY0001</a>].</li>
  <li>If the given expanded QName does not identify a collection among the
available collections in the dynamic context of the invoking module, an error is
raised [<a href="#ERRZDDY0003" title="zerr:ZDDY0003">zerr:ZDDY0003</a>].</li>
  <li>If the update mode of the collection is '%an:const', '%an:append-only', or '%an:queue', an
error is raised [<a href="#ERRZDDY0004" title="zerr:ZDDY0004">zerr:ZDDY0004</a>],
[<a href="#ERRZDDY0005" title="zerr:ZDDY0005">zerr:ZDDY0005</a>], or [<a
href="#ERRZDDY0006" title="zerr:ZDDY0006">zerr:ZDDY0006</a>], respectively.</li>
  <li>If the collection is '%an:unordered', an error is raised [<a href="#ERRZDDY0012"
title="zerr:ZDDY0012">zerr:ZDDY0012</a>].</li>
  <li>The expression that is given as the second argument to the function call
is evaluated. The result of the evaluation is called the source sequence. If the
source sequence contains an item that is not a node, or a node whose actual type
does not match the KindTest specified in the collection declaration, a type
error is raised [<a href="#ERRXDTY0001"
title="zerr:XDTY0001">zerr:XDTY0001</a>].</li>
  <li>Each of the nodes in the source sequence is copied as if it was a node
returned by an enclosed expression in a direct element constructor (see
http://www.w3.org/TR/xquery/#id-content). The construction and copy-namespaces
modes used during the copy operation are the ones in the static context of the
invoking module. Let $nodes be the sequence containing the copied nodes. Every
node in $nodes is a parent-less root node that does not belong to any collection
and is distinct from any other node in $nodes.</li>
  <li>The result of the function is an empty XDM instance and a pending update
list that consists of a single update primitive:
upd:insertFirstIntoCollection($collectionName, $nodes).</li>
  </ul>

The update primitive is applied as follows: 

  <ul>
  <li>The document container for the collection is found via the collections
table. </li>
  <li>The root nodes in $nodes are inserted at the "beginning" of the container.
Specifically, the first node is inserted at the first position, and the rest of the
nodes are inserted after the first one and in the same order as they appear in
$nodes.</li>
  </ul>

\code
  declare updating function cdml:insert-nodes-last($collectionName as xs:QName, $nodes as node()*)

  upd:insertLastIntoCollection($collectionName as xs:QName, $nodes as node()*)
\endcode

The insert-nodes-last function is evaluated the same way as the insert-nodes-first function except:

  <ul>
  <li>If the collection is '%an:append-only' or '%an:queue', the insertion is allowed (i.e.,
the errors ZDDY0005 or ZDDY0006 are not raised).</li>
  <li>The result of the function is an empty XDM instance and a pending update
list that consists of a single update primitive:
upd:insertLastIntoCollection($collectionName, $nodes).</li>
  </ul>

The update primitive is applied as follows: 

  <ul>
  <li>The document container for the collection is found via the collections table.</li>
  <li>The root nodes in $nodes are inserted at the "end" of the container.
Specifically, the first node is inserted after the last existing node, and rest
of the nodes are inserted after the first one and in the same order as they
appear in $nodes.</li>
  </ul>

\code
  declare updating function cdml:insert-nodes-before($collectionName as xs:QName, $target as node(), $nodes as node()*)

  upd:insertBeforeIntoCollection($collectionName as xs:QName, $target as node(), $nodes as node()*)
\endcode

The insert-nodes-before function is evaluated as follows:

  <ul>
  <li>If the given expanded QName does not identify a collection among the
statically known collections in the static context of the invoking module, an
error is raised [<a href="#ERRZDDY0001"
title="zerr:ZDDY0001">zerr:ZDDY0001</a>].</li>
  <li>If the given expanded QName does not identify a collection among the
available collections in the dynamic context of the invoking module, an error is
raised [<a href="#ERRZDDY0003" title="zerr:ZDDY0003">zerr:ZDDY0003</a>].</li>
  <li>If the update mode of the collection is '%an:const', '%an:append-only', or '%an:queue', an
error is raised [<a href="#ERRZDDY0004" title="zerr:ZDDY0004">zerr:ZDDY0004</a>],
[<a href="#ERRZDDY0005" title="zerr:ZDDY0005">zerr:ZDDY0005</a>], or [<a
href="#ERRZDDY0006" title="zerr:ZDDY0006">zerr:ZDDY0006</a>], respectively.</li>
  <li>If the collection is '%an:unordered', an error is raised [<a href="#ERRZDDY0012"
title="zerr:ZDDY0012">zerr:ZDDY0012</a>].</li>
  <li>The expression that appears as the second argument to the function call is
evaluated. The expression must return a single node, called the target node. If
the target node is not a root node that belongs to the collection, an error is
raised [<a href="#ERRZDDY0011" title="zerr:ZDDY0011">zerr:ZDDY0011</a>].</li>
  <li>The expression that is given as the third argument to the function call is
evaluated. The result of the evaluation is called the source sequence. If the
source sequence contains an item that is not a node, or a node whose actual type
does not match the KindTest specified in the collection declaration, a type
error is raised [<a href="#ERRXDTY0001"
title="zerr:XDTY0001">zerr:XDTY0001</a>].</li>
  <li>Each of the nodes in the source sequence is copied as if it was a node
returned by an enclosed expression in a direct element constructor (see
http://www.w3.org/TR/xquery/#id-content). The construction and copy-namespaces
modes used during the copy operation are the ones in the static context of the
invoking module. Let $nodes be the sequence containing the copied nodes. Every
node in $nodes is a parent-less root node that does not belong to any collection
and is distinct from any other node in $nodes.</li>
  <li>The result of the function is an empty XDM instance and a pending update
list that consists of a single update primitive:
upd:insertBeforeIntoCollection($collectionName, $target, $nodes).</li>
  </ul>

The update primitive is applied as follows: 

  <ul>
  <li>The document container for the collection is found via the collections
table.</li>
  <li>The root nodes in $nodes are inserted into the container before the given
target node. Specifically, if the target node is at position K, the first node
is inserted at position K, and rest of the nodes are inserted after the first
one and in the same order as they appear in $nodes. After the insertion, the
target node will at position K+N, where N is the number of nodes in $nodes.</li>
  </ul>

\code
  declare updating function cdml:insert-nodes-after($collectionName as xs:QName, $target as node(), $nodes as node()*)

  upd:insertAfterIntoCollection($collectionName as xs:QName, $target as node(), $nodes as node()*)
\endcode

The insert-nodes-after function is evaluated the same way as the insert-nodes-before function except:

  <ul>
  <li>The result of the function is an empty XDM instance and a pending update
list that consists of a single update primitive:
upd:insertAfterIntoCollection($collectionName, $target, $nodes).</li>
  </ul>

The update primitive is applied as follows: 

  <ul>
  <li>The document container for the collection is found via the collections table.</li>
  <li>The root nodes in $nodes are inserted into the container after the given
target node. Specifically, if the target node is at position K, the first node
is inserted at position K+1, and rest of the nodes are inserted after the first
one and in the same order as they appear in $nodes.</li>
  </ul>

\code
  declare updating function cdml:delete-nodes($nodes as xs:node()*)

  upd:deleteFromCollection($nodes as xs:node()*)
\endcode

The delete-nodes function is evaluated as follows:

  <ul>
  <li>The expression that appears as the first argument to the function call is
evaluated. The result of this evaluation is called the deletion sequence. If
there is any node in the deletion sequence that is not a root node belonging to
a collection, an error is raised [<a href="#ERRZDDY0011"
title="zerr:ZDDY0011">zerr:ZDDY0011</a>]. Let $nodes be the deletion
sequence.</li>
  <li>If the update mode of a collection of any node is '%an:const', '%an:append-only', or '%an:queue', an
error is raised [<a href="#ERRZDDY0004" title="zerr:ZDDY0004">zerr:ZDDY0004</a>],
[<a href="#ERRZDDY0007" title="zerr:ZDDY0007">zerr:ZDDY0007</a>], or [<a
href="#ERRZDDY009" title="zerr:ZDDY009">zerr:ZDDY009</a>], respectively.</li>
  <li>The result of the function is an empty XDM instance and a pending update
list that consists of a single update primitive:
upd:deleteFromCollection($nodes).</li>
  </ul>

The update primitive is applied as follows: 

  <ul>
  <li>The document container for the collection is found via the collections
table. </li>
  <li>Each document that is rooted at a node in $nodes is removed from the
container, if it is still there (earlier delete primitives in the same PUL may
have deleted the tree already). If there are no variables that are bound to any
of the document's nodes, the document is destroyed. Otherwise, the document will
be destroyed as soon as there are no variables bound to any of its nodes. </li>
  </ul>

\code
  declare updating function cdml:delete-nodes-first($collectionName as xs:QName, $number as xs:unsignedLong)
\endcode

The delete-nodes-first function is evaluated as follows:

  <ul>
  <li>If the given expanded QName does not identify a collection among the
statically known collections in the static context of the invoking module, an
error is raised [<a href="#ERRZDDY0001"
title="zerr:ZDDY0001">zerr:ZDDY0001</a>].</li>
  <li>If the given expanded QName does not identify a collection among the
available collections in the dynamic context of the invoking module, an error is
raised [<a href="#ERRZDDY0003" title="zerr:ZDDY0003">zerr:ZDDY0003</a>].</li>
  <li>If the update mode of the collection is const, or append-only, an error is
raised [<a href="#ERRZDDY0004" title="zerr:ZDDY0004">zerr:ZDDY0004</a>] or [<a
href="#ERRZDDY0007" title="zerr:ZDDY0007">zerr:ZDDY0007</a>] respectively.</li>
  <li>The expression that appears as the second argument to the function call is
evaluated, producing a single positive integer. Let $number be that
integer.</li>
  <li>If the collection has fewer than $number nodes, an error is raised [<a
href="#ERRZDDY0011" title="zerr:ZDDY0011">zerr:ZDDY0011</a>].</li>
  <li>Let $nodes be the sequence consisting of the first $number root nodes in
the collection.</li>
  <li>The result of the function is an empty XDM instance and a pending update
list that consists of a single update primitive:
upd:deleteFromCollection($collectionName, $nodes).</li>
  </ul>

\code
  declare updating function cdml:delete-node-first($collectionName as xs:QName)
\endcode

The delete-node-first function is a special case of the delete-nodes-first
function. Specifically, delete-node-first($collectionName) is equivalent to
delete-nodes-first($collectionName, 1).

\code
  declare updating function cdml:delete-nodes-last($collectionName as xs:QName, $number as xs:unsignedLong)
\endcode

The delete-nodes-last function is evaluated as follows:

  <ul>
  <li>If the given expanded QName does not identify a collection among the
statically known collections in the static context of the invoking module, an
error is raised [<a href="#ERRZDDY0001"
title="zerr:ZDDY0001">zerr:ZDDY0001</a>].</li>
  <li>If the given expanded QName does not identify a collection among the
available collections in the dynamic context of the invoking module, an error is
raised [<a href="#ERRZDDY0003" title="zerr:ZDDY0003">zerr:ZDDY0003</a>].</li>
  <li>If the update mode of the collection is const, append-only, or queue, an
error is raised [<a href="#ERRZDDY0004" title="zerr:ZDDY0004">zerr:ZDDY0004</a>],
[<a href="#ERRZDDY0007" title="zerr:ZDDY0007">zerr:ZDDY0007</a>], or [<a
href="#ERRZDDY009" title="zerr:ZDDY009">zerr:ZDDY009</a>], respectively.</li>
  <li>The expression that appears as the second argument to the function call is
evaluated, producing a single positive integer. Let $number be that
integer.</li>
  <li>If the collection has fewer than $number nodes, an error is raised [<a
href="#ERRZDDY0011" title="zerr:ZDDY0011">zerr:ZDDY0011</a>].</li>
  <li>Let $nodes be the sequence consisting of the last $number root nodes in
the collection.</li>
  <li>The result of the function is an empty XDM instance and a pending update
list that consists of a single update primitive:
upd:deleteFromCollection($collectionName, $nodes).</li>
  </ul>

\code
  declare updating function cdml:delete-node-last($collectionName as xs:QName)
\endcode

The delete-node-last function is a special case of the delete-nodes-lasst function.
Specifically, delete-node-last($collectionName) is equivalent to delete-nodes-last($collectionName, 1).


\subsection destroying_collections Destroying Collections

To destroy a collection, Zorba provides the <tt>delete</tt> updating function.
The function itself and its associated update primitive are described below.

\code
  declare updating function cddl:delete($collectionName as xs:QName)

  upd:deleteCollection($collectionName as xs :QName)
\endcode

The delete function is evaluated as follows:

  <ul>
  <li>If the given expanded QName does not identify a collection among the
statically known collections in the static context of the invoking module, an
error is raised [<a href="#ERRZDDY0001"
title="zerr:ZDDY0001">zerr:ZDDY0001</a>].</li>
  <li>If the given expanded QName does not identify a collection among the
available collections in the dynamic context of the invoking module, an error is
raised [<a href="#ERRZDDY0003" title="zerr:ZDDY0003">zerr:ZDDY0003</a>].</li>
  <li>The result of the function is an empty XDM instance and a pending update
list that consists of a single update primitive:
upd:deleteCollection($collectionName).</li>
  </ul>

The update primitive is applied as follows:

  <ul>
  <li>If there is any available index whose domain expression or any of its key
expressions reference the collection, an error is raised [<a href="#ERRZDDY0013"
title="zerr:ZDDY0013">zerr:ZDDY0013</a>].</li>
  <li>If there is any active integrity constraint on the collection, an error is
raised [<a href="#ERRZDDY0014" title="zerr:ZDDY0014">zerr:ZDDY0014</a>].</li>
  <li>If there is any in-scope variable that references any node in the
collection, an error is raised [<a href="#ERRZDDY0015"
title="zerr:ZDDY0015">zerr:ZDDY0015</a>].</li>
  <li>The document container for the collection is found via the collections
table.</li>
  <li>All documents in the container are destroyed.</li>
  <li>The container itself is destroyed.</li>
  <li>The entry mapping the collection name to its container is removed from the
collections table.</li>
  </ul>


\section indexes Indexes


\n Zorba supports two kinds of indexes, <strong>value indexes</strong> and 
<strong>general indexes</strong>. As shown in \ref indexes_in_action, value
indexes can be used to optimize queries involving value comparisons, whereas 
general indexes can be used to optimize queries involving
value and/or general comparisons. Although general indexes can handle both kinds of
comparisons, value indexes are more compact and efficient, and as a result, they
should be preferred over general indexes for data on which no general comparisons
are expected.

\n \n A value index is a set whose contents (called <strong>index entries</strong>) 
are defined by a "domain" expression and a number of "key" expressions. 
Informally, a value index is created by evaluating its domain expression first, 
resulting in a sequence of nodes (called the index <strong>domain sequence</strong>). 
Then, for each node D in the domain
sequence, the key expressions are evaluated with node D serving as their
context node. A key expression must not return more than one value. If a
value returned by a key expression is not atomic, it is converted to an atomic
value via atomization. Thus, if N is the number of key expressions, then for
each domain node, an associated <strong>key tuple</strong> of N atomic values
is constructed. The purpose of the index is to map key tuples to domain nodes. In
general, several domain nodes may produce the same key tuple. As a result, each
index entry is a pair consisting of a key tuple and the set of domain nodes that
produced the key tuple.

\n \n General comparison operators accept operands that are sequences potentially
containing more than one item. As a result, the main difference between value
and general indexes is the the later allow a key expression to return multiple
values with potentially different data types. On the other hand, for simplicity,
the current Zorba implementation restricts the number of key expressions for
general indexes to one expression only. 

\n \n Like value indexes, general indexes are sets of index entries, where each index
entry is a pair consisting of an atomic key value and the set of associated 
domain nodes. Informally, the set of entries for a general index is created 
by evaluating its domain expression first, resulting in a sequence of domain 
nodes. Then, for each node D in the domain sequence, the key expression is
evaluated with node D serving as its context node. A key expression may return
a sequence of arbitrary number of items, called the <strong>key sequence</strong>.
Items in the key sequence may have different data types. If an item in the key
sequence is a node, it is converted to one or more atomic values via atomization,
and the atomic values replace the node in the key sequence. If an item in the
key sequence has type xs:untypedAtomic, it is removed from the key sequence and
is cast to every other atomic built-in type. Then, for each successful cast,
the resulting atomic value is put into the key sequence. Thus, for each domain
node D, a key sequence is constructed that contains atomic values none of which
has type xs:untypedAtomic. For each value K in this key sequence, the pair
[K, D] is inserted in the index. If an entry for K exists already, D is inserted
in the associated set of domain nodes; otherwise a new index entry is created,
mapping K to the set { D }.

\n Zorba supports the following five operations on indexes:
<a href="#index_declaration">declaration</a>,
<a href="#index_creation">creation</a>,
<a href="#index_deletion">deletion</a>,
<a href="#index_probing">probing</a> and
<a href="#index_maintenance">maintenance</a>.
These are explained briefly in the following simple example. Full details for
each operation are provided in the subsections after the example.


\subsection indexes_in_action Indexes in action - A simple example


\n Let us consider the same news application we used in \ref collections_in_action.
In this example, we will show how to create and use indexes on the collections of
the news organization. First, let us assume that each employee has a city where
he/she is currently stationed at. We want to create an index that maps city
names to the employees that are stationed in those cities. The index will
contain one entry for each city where at least one employee is stationed in. Let
us also assume that we want to search for journalists based on the number of
articles they have written. For this, we will create an index that maps article
counts to the employees who are journalists and have produced that number of
articles. Finally, we want to be able to quickly find the manager of any given
employee. For this, we will create an index that maps employee ids to the
manager of the associated employee.

\n \n Before an index can be created, it must be declared. An <a href="#index_declaration">
index declaration</a> describes the index by providing its domain expression, 
its key expressions, and certain index properties (declared as annotations); it also specifies a name for 
referencing the index in subsequent operations. Like collections, indexes must 
be declared inside the prolog of library modules. In terms of the XQuery language,
index declarations become part of a module's static context.

\n \n In this example, the index declarations are placed inside the 
<a href="#lib_module_news_data_indexes">"news-data"</a> library
module shown below (same as the module we saw in \ref collections_in_action,
except for the additional index declarations). The first index declaration
assigns the name news-data:CityEmp to the index. It uses the "on nodes" and "by"
keywords to specify the domain and key expressions respectively. The "as"
keyword specifies a target atomic data type which the result of the key
expression must match with (after atomization). The index is declared as a
'%an:value-equality' index. This means that it can be used to find the employees in
a particular city, but not in a "range" of cities. In other words, the index is
not aware of any ordering among city names. Finally, the maintenance property of
the index is set to "automatically maintained" ('%an:automatic'). Briefly, an automatically
maintained index is one whose maintenance is the responsibility of Zorba rather
than the XQuery programmers. 

\n \n The second index declaration assigns the name
news-data:ArtCountEmp to the index. Its domain expression selects all employees
who are journalists. Its key expression computes the number of articles written
by the "current" journalist. This index is declared as a "value range" ('%an:value-range') index,
which means that it can be used to find journalists whose article count is
within a given range. Finally, the index is also declared as "manually
maintained" ('%an:manual'), which means that programmers must explicitly request that the index
be synchronized with the underlying data. 

\n \n The last index declaration assigns the name news-data:EmpMgr to the index. 
The index is declared as a '%an:general-equality' index, which, like '%an:value-equality'
means that the index does not maintain its keys in any order. The index key
expression selects, for each employee E, the ids of the employees managed by E. 
Notice that this set of ids may be empty. The index will contain an entry mapping 
the empty sequence to the employees who do not manage anybody. Notice also that 
no type declaration is required for the key expression. Typically, the employee 
ids will all be integers or strings or untypedAtomic. All of these cases can be 
handled by the news-data:EmpMgr index, as well as the not very likely scenario 
where different kinds of employees have ids of different data types.

<a name="lib_module_news_data_indexes" id="lib_module_news_data_indexes"></a>
\code
  (: The "news-data" Library Module :)

  module namespace news-data = "http://www.news.org/data";

  import module namespace cdml = "http://zorba.io/modules/store/static/collections/dml";

  import schema namespace news-schemas = "http://www.news.org/schemas";

  declare namespace an = "http://zorba.io/annotations";

  declare collection news-data:employees as schema-element(news-schema:employee)*;

  declare collection news-data:articles as node()*;

  declare %an:const %an:ordered %an:read-only-nodes collection news-data:months
    as schema-element(news-schema:month)*;

  declare %an:automatic %an:value-equality index news-data:CityEmp
    on nodes cdml:collection(xs:QName("news-data:employees"))/employee
    by .//station/city as xs:string;

  declare %an:manual %an:value-range index news-data:ArtCountEmp
    on nodes cdml:collection(xs:QName("news-data:employees"))/employee[./position/@kind eq "journalist"]
    by count(for $art in cdml:collection(xs:QName("news-data:articles"))//article
             where $art/empid = ./id
             return $art) as xs:integer;

  declare %an:automatic %an:general-equality index news-data:EmpMgr
    on nodes cdml:collection(xs:QName("news-data:employees"))/employee
    by ./manages//@empid;

  declare variable $news-data:employees := xs:QName("news-data:employees");
  declare variable $news-data:articles := xs:QName("news-data:articles");
  declare variable $news-data:months := xs:QName("news-data:months");
  declare variable $news-data:CityEmp := xs:QName("news-data:CityEmp");
  declare variable $news-data:ArtCountEmp := xs:QName("news-data:ArtCountEmp");
  declare variable $news-data:EmpMgr := xs:QName("news-data:EmpMgr");

\endcode

Having declared the indexes in a library module, they can now be created.
This is done by the <a href="#admin_script_3">"admin-script-3"</a> script shown below.
The script must first import the <a href="#lib_module_news_data_indexes">
"news-data"</a> module. As far as indexes are concerned, the
effect of this import is to create three entries in the static context of the main
module, mapping the index names to the index definitions (domain expression, key
specification, and properties). Then, the query creates the indexes by invoking
the <a href="#create_index">iddl:create</a> function, passing the name of the index as input.

\n \n Let us consider the creation of the CityEmp index (the process is the similar
for the ArtCountEmp and EmpMgr indexes). <a href="#index_creation">Index Creation</a> 
starts with retrieving the index definition from the static
context, using the index name. Then, an index container is created, whose
entries will be pairs associating a city name with a set of employees. Next, the
index container is populated using the process outlined earlier: The domain
expression is evaluated, and for each employee node E in the domain sequence,
the name of the city C where the employee is currently stationed in is retrieved
by evaluating the key expression, atomizing its result, and checking that the
atomic value matches the specified target type. Finally, the pair [E, C] is
inserted in the index: if an entry for C exists already, E is inserted in the
set associated with C; otherwise, an new entry is created mapping C to the set {
E }. The last step in index creation involves registering the index inside an
<strong>indexes table</strong> that maps index names to index containers. The
index container will remain registered until it is destroyed by a call to the <a
href="#delete_index">iddl:delete</a> function
(see the <a href="#admin_script_4">"admin-script-4"</a>
script below).

<a name="admin_script_3" id="admin_script_3"></a>
\code
  (: The "admin-script-3" script :)

  import module namespace iddf = "http://zorba.io/modules/store/static/indexes/ddl";

  import module namespace news-data = "http://www.news.org/data" at "news_data.xqlib";

  iddf:create($news-data:CityEmp);

  iddf:create($news-data:ArtCountEmp);

  iddf:create($news-data:EmpMgr);
\endcode

The next step in this example is to show how the index can be used to to
optimize query performance, which of course, is the primary motivation for
supporting indexes in any data-processing system. Zorba provides four functions
for <a href="#index_probing">index probing</a>:
<a href="#probe_index_point_value">idml:probe-index-point-value</a>, 
<a href="#probe_index_range_value">idml:probe-index-range-value</a>,
<a href="#probe_index_point_general">idml:probe-index-point-general</a>, and 
<a href="#probe_index_range_general">idml:probe-index-range-general</a>.
idml:probe-index-point-value is supported by all kind of indexes,
idml:probe-index-point-general is supported by general indexes (equality and range),
idml:probe-index-range-value is supported by value and general range indexes,
and idml:probe-index-range-general is supported by general range indexes only.

\n \n The <a href="#query_probe_1">"probe-1"</a> query illustrates the
use of idml:probe-index-point-value. The query returns the names of all employees
stationed in Paris. As shown, the idml:probe-index-point-value function takes the
index name and the keyword "Paris" as inputs. It uses the index name to find the
index container via the indexes tables, looks-up the entry for "Paris" inside
this container, and returns all the associated employee nodes.

\n \n The <a href="#query_probe_2">"probe-2"</a> query illustrates
index probing via the idml:probe-index-range-value function. The query returns all
journalists who have written at least 100 articles. As shown, the first
parameter of the idml:probe-index-range-value function is the index name, followed by
6 parameters per key expression. The 6 parameters specify a range of value for
the key values: the first 2 are the lower and upper values of the range, the
next two are booleans that specify whether the range does indeed have a lower
and/or upper bound, and the last 2 are also booleans that specify whether the
range is open or closed from below or above (i.e., whether the lower/upper bound
are included in the range or not).

\n \n The <a href="#query_probe_3">"probe-3"</a> query illustrates the use of
idml:probe-index-point-general. The query returns the managers of the employees 
whose id is of type string (or subtype) and its value is "100" or "200".
It will also return the managers of the employees whose id is of type untypedAtomic
and its value, when cast to string, is "100" or "200".

\n \n The <a href="#query_no_probe_1">"no-probe-1"</a>, <a href="#query_no_probe_2">
"no-probe-2"</a>, <a href="#query_no_probe_3">"no-probe-3"</a> queries return the
same results as <a href="#query_probe_1">"probe-1"</a>, <a href="#query_probe_2">
"probe-2"</a>, and <a href="#query_probe_3">"probe-3"</a>, respectively,
but without using any index. Normally, the performance of the probe queries will
be much better than that of the corresponding no-probe queries. This is because,
in general, indexes organize their entries in ways that make the execution of
the probe functions very efficient. Typically, some kind of a hash table (for
value equality indexes) or ordered tree (for value range indexes) data structure
is employed, and as we will see, Zorba support both kinds of indexes. So, for
example, the <a href="#query_probe_1">"probe-1"</a> query does
not have to access every entry in the index until it finds the one for Paris,
whereas the <a href="#query_no_probe_1">"no-probe-1"</a>
query has to access every employee in the collection and check his/her city.

\n \n People familiar with SQL and modern relational DBMSs would probably expect
the query optimizer to be able to automatically rewrite queries like 
<a href="#query_no_probe_1">"no-probe-1"</a> to queries like 
<a href="#query_probe_1">"probe-1"</a>.
The Zorba query optimizer does not yet detect index-related rewrites automatically.
Although, we do plan to offer automatic index-related rewrites 
in the near future, we also expect the probing functions to remain useful 
for manual rewrites because both the XQuery language and the kind of indexes 
that are allowed in Zorba can be much more complex than their relational 
counterparts.

<a name="query_probe_1" id="query_probe_1"></a>
\code
  (: The "probe-1" query :)

  import module namespace idml = "http://zorba.io/modules/store/static/indexes/dml";

  import module namespace news-data = "http://www.news.org/data" at "news_data.xqlib";

  idml:probe-index-point-value($news-data:CityEmp, "Paris")
\endcode

<a name="query_probe_2" id="query_probe_2"></a>
\code
  (: The "probe-2" query :)

  import module namespace idml = "http://zorba.io/modules/store/static/indexes/dml";

  import module namespace news-data = "http://www.news.org/data" at "news_data.xqlib";

  idml:probe-index-range-value($news-data:ArtCountEmp, 100, (), true, false, true, false)
\endcode

<a name="query_probe_3" id="query_probe_3"></a>
\code
  (: The "probe-3" query :)

  import module namespace idml = "http://zorba.io/modules/store/static/indexes/dml";

  import module namespace news-data = "http://www.news.org/data" at "news_data.xqlib";

  idml:probe-index-point-general($news-data:EmpMgr, ("100", "200"))
\endcode

<a name="query_no_probe_1" id="query_no_probe_1"></a>
\code
  (: The "no-probe-1" query :)

  import module namespace cdml = "http://zorba.io/modules/store/static/collections/dml";

  import module namespace news-data = "http://www.news.org/data" at "news_data.xqlib";

  cdml:collection($news-data:employees)/employee[.//station/city eq "Paris"]
\endcode

<a name="query_no_probe_2" id="query_no_probe_2"></a>
\code
  (: The "no-probe-2" query :)

  import module namespace cdml = "http://zorba.io/modules/store/static/collections/dml";

  import module namespace news-data = "http://www.news.org/data" at "news_data.xqlib";

  for $emp in cdml:collection($news-data:employees)/employee[./position/@kind eq "journalist"]
  where 100 le count(for $art in cdml:collection(xs:QName("news-data:articles"))//article
                     where $art/empid eq $emp/id
                     return $art)
  return $emp
\endcode

<a name="query_no_probe_3" id="query_no_probe_3"></a>
\code
  (: The "probe-3" query :)

  import module namespace cdml = "http://zorba.io/modules/store/static/collections/dml";

  import module namespace news-data = "http://www.news.org/data" at "news_data.xqlib";

  for $mgr in cdml:collection($news-data:employees)/employee
  where $mgr/manages//@empid = ("100", "200")
  return $mgr
\endcode

\n \n Now, let us consider what happens when the data on which an index is built gets
updated. In general, <a href="#index_maintenance">index maintenance</a> 
is the operation where the index contents are
updated so that they reflect the index definition with respect to the current
snapshot of the data. Zorba offers two maintenance modes: manual and
automatic. If an index is declared as '%an:manual', index maintenance
is done only when the function <a href="#refresh_index">idml:refresh-index</a> 
is invoked inside a query. Essentially, in manual mode
maintenance is in the control of the query programmers, and the index may become
stale between two consecutive calls to the <a href="#refresh_index">
idml:refresh-index</a> function. In contrast, if an
index is declared as '%an:automatic', Zorba guarantees that the index stays up-to-date at any given time.

\n \n In this example, the CityEmp index was declared as automatic. The <a
href="#query_index_maintenance">"index-maintenance"</a> query shown below transfers
the employee with id "007" from his current city, say Paris, to Beijing. Since
index CityEmp is automatic, after the update is applied, Zorba will initiate a
maintenance operation on the index, whereby the employee node will be removed
from the node set associated with Paris and inserted into the node set
associated with Beijing (if there is no other employee stationed in Beijing
already, an entry for it will be created first). Notice that although the index
is not explicitly referenced anywhere in this query, its definition must still
be available to the query because it is needed to perform the index maintenance.
In this example, the query imports the <a href="#lib_module_news_data_indexes"
title="news-data">"news-data"</a> module because it contains the declaration for
the employees collection, which is referenced by the query.  But the <a
href="#lib_module_news_data_indexes" title="news-data">"news-data"</a> module
contains the index declaration as well, so index maintenance can find the index
definition. In general, it is a best practice to declare an index in the same
module as the collections that are referenced by the index.

\n \n The ArtCountEmp index is more complex than the CityEmp index, so the system may
not be able to maintain it in an efficient way. Furthermore, the index contains
"statistical" information, so it may be acceptable if its contents are not
always in sync with the underlying data. For these reasons, the ArtCountEmp
index was declared as '%an:manual'.

<a name="query_index_maintenance" id="query_index_maintenance"></a>
\code
  (: The "index-maintenance" query :)

  import module namespace cdml = "http://zorba.io/modules/store/static/collections/dml";

  import module namespace news-data = "http://www.news.org/data" at "news_data.xqlib";

  replace node value cdml:collection($news-data:employees)/employee[@id eq "007"]//station/city
  with "Beijing"
\endcode

Finally, we conclude this example with a query that shows how to destroy an
index. As shown in <a href="#admin_script_4">"admin-script-4"</a> below,
<a href="#index_deletion">index deletion</a> is done via
the <a href="#delete_index">iddl:delete</a>
function. The function simply destroys the index container and removes the
mapping between the index name and the index container from the indexes table.
After the index is deleted, any query that tries to access the index will
receive an error.

<a name="admin_script_4" id="admin_script_4"></a>
\code
  (: The "admin-script-4" query :)

  import module namespace iddl = "http://zorba.io/modules/store/static/indexes/ddl";

  import module namespace news-data = "http://www.news.org/data" at "news_data.xqlib";

  iddl:delete($news-data:CityEmp);
\endcode


\subsection index_declaration Index Declaration


\code
  IndexDecl ::= 'index' IndexName
               'on' 'nodes' IndexDomainExpr
               'by' IndexKeySpec (',' IndexKeySpec)*

  IndexName ::= EQName

  IndexDomainExpr ::= PathExpr

  IndexKeySpec ::= IndexKeyExpr IndexKeyTypeDecl? IndexKeyCollation?

  IndexKeyExpr ::= PathExpr

  IndexKeyTypeDecl ::= 'as' AtomicType OccurrenceIndicator?

  AtomicType ::= EQName

  IndexKeyCollation ::= 'collation' URILiteral

  Note: the following annotations are accepted within the context of an index declaration:

     %an:unique, %an:nonunique,
     %an:value-range, %an:value-equality, 
     %an:general-range, %an:general-equality,
     %an:manual or %an:automatic

\endcode

Syntactically, each index is defined by an <a href="#index_declaration">
index declaration</a>, which specifies a unique name for the index 
as a QName, the index domain expression, a number of key specifications, and 
a set of index properties (given as annotations; see \ref collection_index_annotations).
The IndexDecl syntax shown above is common to both 
value indexes and general indexes. Whether an index is a value or a general 
index is determined by the value of the usage property, which is explained below.

\n \n Index declarations (for both value and general indexes) must be placed inside 
module prologs. The Prolog syntax is extended accordingly, as shown above. 
An additional constraint (not expressible syntactically) is that only library 
modules may contain index declarations  [<a href="#ERRZDST0023">zerr:ZDST0023</a>]. 
The reasons for this rule are the same as those for collections (see \ref 
collection_declaration). Furthermore, the qname of an index must have the same
namespace URI as the target namespace URI of the declaring library module
[<a href="#ERRZDST0036">zerr:ZDST0036</a>].

\n \n To accommodate index declarations, Zorba extends the static context with a 
component called the <strong>statically known indexes</strong>. This is a 
map whose entries associate an expanded QName with an implementation-dependent
representation of the information contained in an index declaration with the
same QName. Each index declaration adds an entry to the statically known indexes
of the module containing the declaration. If the expanded QName of the index is
equal to the expanded QName of another index in the statically known indexes 
of the same module, a static error is raised [<a href="#ERRZDST0021">zerr:ZDST0021</a>]. 
Like the statically known collections, the statically known indexes of 
a module that is imported by another module are copied into the statically 
known indexes of the importing module. It is a static error [<a href="#ERRZDST0022">
zerr:ZDST0022</a>] if the expanded QName of an index declared in an imported module
is equal to the expanded QName of an index declared in the importing module 
or in another imported module (even if the declarations are consistent).

\n \n Zorba defines three index properties which are syntactically expressed as annotations:
<strong>uniqueness</strong> (with possible values '%an:unique' or '%an:nonunique'),
<strong>usage</strong> (with possible values '%an:value-range', '%an:value-equality', '%an:general-range', or '%an:general-equality'), and 
<strong>maintenance mode</strong> (with possible values '%an:manual' or '%an:automatic').
The syntax allows the values for these properties to be listed in any order or not be specified at all.
If not specified, the default values for uniqueness, usage, and maintenance mode are '%an:nonunique', 
'%an:value-equality', and '%an:automatic', respectively.
It is a static error [zerr::XQST0106] if more than one value is listed in an index declaration for any of these properties.

\n \n The uniqueness property determines the kind of relationship between keys and
domain nodes: if the index is declared as '%an:unique', Zorba makes sure that the
relationship is one-to-one, that is, each index entry associates a key value
(or key tuple in the case of value indexs) with exactly one domain node. 
Otherwise, if the index is '%an:nonunique', multiple domain nodes may have the 
same key value, and as a result, each index entry associates a key with a 
set of domain nodes. In the current implementation, it is not allowed to declare
an index as unique if it is a general index whose IndexKeyTypeDecl is either absent
or specifies xs:anyAtomicType or xs:untypedAtomic as its atomic type 
[<a href="#ERRZDST0025">zerr:ZDST0025</a>].

\n \n The usage property specifies the kind of the index based on the query expressions 
that may be optimized by using the index. A <strong>value equality index</strong> 
can optimize expressions involving value equality predicates only. The 
<a href="#query_probe_1">"probe-1"</a> and <a href="#query_no_probe_1">
"no-probe-1"</a> queries in \ref indexes_in_action are an example of
such usage. As shown there, a value equality index supports the 
<a href="#probe_index_point_value">idml:probe-index-point-value</a> function.
A <strong>value range index</strong> can optimize expressions involving any kind
of value comparison. The <a href="#query_probe_2">"probe-2"</a> and <a
href="#query_no_probe_2">"no-probe-2"</a> queries in \ref indexes_in_action 
are an example of such usage. A value range index supports both the 
<a href="#probe_index_point_value">idml:probe-index-point-value</a> 
and the <a href="#probe_index_range_value">idml:probe-index-range-value</a>
functions. A <strong>general equality index</strong> can optimize expressions 
involving either value equality or general equality predicates. Finally, a 
<strong>general range index</strong> can optimize expressions involving any
kind of value or general comparison predicates. 

\n \n The maintenance mode specifies how index maintenance is done. The current Zorba
implementation offers two maintenance modes: '%an:manual' and '%an:automatic'. For a 
<strong>manual index</strong>, maintenance is done only when the function <a
href="#refresh_index">idml:refresh-index</a> (described in \ref index_maintenance)
is invoked inside a query. Essentially, in manual mode maintenance is in the
control of the query programmers, and the index may become stale between two
consecutive calls to the <a href="#refresh_index">idml:refresh-index</a>
function. In contrast, for an <strong>automatic index</strong>, Zorba guarantees
that the index stays up-to-date at any given time.

The index declaration syntax is very liberal with respect to the expressions
that can appear as domain or key expressions. However, the following semantic
restrictions are imposed on the domain expression and each of the
key expressions:

  <ul>
  <li>They must be deterministic expressions [<a href="#ERRZDST0028">
      zerr:ZDST0028</a>].</li>

  <li>They must be simple expressions (i.e., not updating or sequential)
      [<a href="#ERRZDST0033">zerr:ZDST0033</a>].</li>

  <li>They must not invoke any input functions other than <a href="#cdml_collection">
      cdml:collection</a> [<a href="#ERRZDST0029">zerr:ZDST0029</a>]. Moreover,
      the argument to each <a href="#cdml_collection">cdml:collection</a> 
      call must be a constant expression returning a QName
      value [<a href="#ERRZDST0030">zerr:ZDST0030</a>]. (A
      constant expression is an expression that doesn't access the dynamic
      context).</li>

  <li>They must not reference and variables other than the ones defined inside
      the expressions themselves [<a href="#ERRZDST0031">zerr:ZDST0031</a>].</li>

  <li>If the index is declared as '%an:automatic', an error is raised
      [<a href="#ERRZDST0034">zerr:ZDST0034</a>] if the domain and/or the key 
      expressions are too complex for Zorba to perform index maintenance in an 
      efficient manner (see \ref index_maintenance for details)</li>
  </ul>

Furthermore, the domain expression must satisfy the following additional
semantic restrictions:

  <ul>
  <li>Its context item, context position, and context size are considered
      undefined, and as a result they must not be referenced [<a href="#ERRZDST0032">
      zerr:ZDST0032</a>].</li>

  <li>It must generate a sequence of nodes [<a href="#ERRXDTY0010">
      zerr:XDTY0010</a>].</li>

  <li>Each node in the domain sequence must belong to a collection that appears
      in the available collections of the module that contains the index declaration
      [<a href="#ERRZDDY0020">zerr:ZDDY0020</a>].</li>

  <li>For general indexes only, the domain expression should not return any
      duplicate nodes [<a href="#ERRZDDY0028">zerr:ZDDY0028</a>]</li>
  </ul>

With each key expression, an index declaration associates a key type and a key
collation. The triplet IndexKeyExpr, IndexKeyTypeDecl, IndexKeyCollation is 
called a <strong>keyspec</strong>. For general indexes, the number of keyspecs 
must be exectly one [<a href="#ERRZDST0035">zerr:ZDST0035</a>]. The IndexKeyTypeDecl 
is optional for general indexes (in which case it is assumed to be xs:anyAtomicItem*), 
but is required for value indexes [<a href="#ERRZDST0027">zerr:ZDST0027</a>].  
The IndexKeyTypeDecl provides a sequence type that the atomized result of 
the associated key expression (for each domain node) must match with according 
to the rules of sequence type matching. For value indexes, the atomic type 
specified in IndexKeyTypeDecl must not be xs:anyAtomicType or xs:untypedAtomic 
[<a href="#ERRZDST0027">zerr:ZDST0027</a>]. Furthermore, for value indexes, 
the occurrence indicator must be either absent or equal to '?' 
[<a href="#ERRZDST0027">zerr:ZDST0027</a>]. Finally, if the index is a value 
range or general range index, an ordering must exist among the values in the 
type domain [<a href="#ERRZDST0027">zerr:ZDST0027</a>] (this rules excludes
the following atomic types and their subtypes: QName, NOTATION, 
hexBinary, hex64Binary, gYearMonth, gYear, gMonthDay, gMonth, and gDay). 

\n \n If the key type in a keyspec is xs:string (or subtype of), the IndexKeyCollation 
specifies the collation to use when comparing key values from this keyspec. If 
no collation is specified, the default collation from the static context of the 
declaring module is used.


\subsection index_creation Index Creation


\n As explained already, indexes are just sets of index entries, where an index 
entry maps a key item or a key tuple to a set of domain nodes (to be more
precise, an index entry contains some kind of "pointers" to nodes, not the 
nodes themselves). In terms of the XQuery language, indexes "live" in the 
dynamic context. In particular, Zorba extends the dynamic context with a 
component called the <strong>available indexes</strong>. This is a map whose 
entries associate the expanded QName of an index with the entry set for that 
index. 

\n \n In practice, the available indexes component is implemented by Zorba's storage
system. To begin with, each index is implemented by some appropriate
data structure that acts as an index entry container. The description of
potential data structures is beyond the scope of this document, but the typical
choices are either some sort of hash table(s) (for equality indexes) or some kind
of ordered tree(s) (for range indexes). To manage these containers, the 
store maintains an <strong>indexes table</strong>, which maps index names to 
index entry containers. The indexes table is accessible by all queries, so once 
an entry is added to the table, the associated index is assumed to be available 
to every query and every module that participates in the execution of that query.

Creation of an index involves creating an initially empty index entry container,
populating that container with the entries computed by the domain and key
expressions of the index, and "registering" that container in the indexes table.
All this is done by the <a href="#create_index">iddl:create</a> function 
that is described below. In fact, iddl:create is an updating function, 
so instead of actually creating the index, it generates a pending update 
primitive that becomes part of a pending update list (PUL) to be applied at a 
later time. The update primitive is also described below.

<a name="create_index" id="create_index"></a>
\code
  declare updating function iddl:create($indexName as xs:QName)

  upd:createIndex($indexName as xs:QName).
\endcode

The create function is evaluated as follows:

  <ul>
  <li>If the given expanded QName does not identify an index among the
statically known indexes in the static context of the invoking module, an error
is raised [<a href="#ERRZDDY0021">zerr:ZDDY0021</a>].</li>

  <li>If the given expanded QName identifies an index that is available
already, an error is raised [<a href="#ERRZDDY0022">zerr:ZDDY0022</a>].</li>

  <li>The result of the function is an empty XDM instance and a pending update
list that consists of a single update primitive:
upd:createIndex($indexName).</li>
  </ul>

The update primitive is applied as follows:

<ul>

<li>
An empty index entry container is created.
</li>

<li>
The domain expression is evaluated first. If the result of the domain expression 
contains an item that is not a node, an error is raised [<a href="#ERRXDTY0010">
zerr:XDTY0010</a>]. If the result of the domain expression contains any duplicate
nodes, then for value indexes, the duplicate nodes are removed, but for general 
indexes, an error is raised [<a href="#ERRZDDY0028">zerr:ZDDY0028</a>]. The result
of the domain expression after duplicate elimination is called the <strong>domain
sequence</strong>. If the domain sequence contains a node that does not belong to 
a collection, an error is raised [<a href="#ERRZDDY0020">zerr:ZDDY0020</a>].</li>

<li>
For each node D in the domain sequence, the IndexKeySpecs are evaluated in some 
implementation dependent order. An IndexKeySpec is evaluated as follows:
</li>

  <ul>
  <li>
  The key expression in the IndexKeySpec is evaluated, with D serving as its 
  context item.
  </li>

  <li>Atomization is applied to the result of the key expression.</li>

  <li>
  The result of atomization is matched against the associated IndexKeyTypeDecl,
  according to the rules of sequence type matching. If the type match fails, 
  an error is raised [<a href="#ERRXDTY0011">zerr:XDTY0011</a>]. 
  </li>

  <li>
  Duplicate values (which may arise in the case of general indexes only) are 
  eliminated from the atomized sequence.
  </li>
  </ul>

<li>
If the index is a value index:
</li>

  <ul>
  <li>
  The result of each IndexKeySpec is a single atomic item or the empty sequence.
  We call this result a <strong>key value</strong>.
  </li>

  <li>
  Let D<sub>i</sub> be the i-th domain node, and K<sub>ij</sub> be the key value
  computed for D<sub>i</sub> by the j-th IndexKeySpec (where the numbering of
  the IndexKeySpecs is done using their order of appearance in the index
  declaration). Let K<sub>i</sub> be the tuple [K<sub>i1</sub>, ...,
  K<sub>iM</sub>], where M is the number of IndexKeySpecs. The next step is to
  insert in the index a mapping from K<sub>i</sub> to D<sub>i</sub>. This step
  is performed for each node in the domain sequence. The order in which the
  domain sequence is processed is implementation dependent.
  </li>

  <li>
  If the index is declared as unique, the relationship between key
  tuples and domain nodes is one-to-one. In this case, if the index already
  contains an entry whose key tuple is equal to K<sub>i</sub>, an error is 
  raised [<a href="#ERRZDDY0024">zerr:ZDDY0024</a>]. Otherwise, the entry 
  [K<sub>i</sub>, D<sub>i</sub>] is inserted in the index container.
  </li>

  <li>
  If the index is non-unique, then if it already contains an entry whose key 
  tuple is equal to K<sub>i</sub>, D<sub>i</sub> is added to the set associated
  with K<sub>i</sub>. Otherwise, the entry [K<sub>i</sub>, { D<sub>i</sub> }] 
  is inserted in the index.
  </li>
  </ul>

<li>
If the index is a general index:
</li>

  <ul>
  <li>
  In the current implementation, there can be only one IndexKeySpec, but contrary
  to value indexes, the result of this IndexKeySpec may be a sequence of any
  number of atomic items, and the items may have different data types. We call 
  this sequence a <strong>key sequence</strong>, and each atomic item in it a 
  <strong>key item</strong> (the key sequence may also be the empty sequence).
  </li>

  <li>
  An error is raised [<a href="#ERRXDTY0012">zerr:XDTY0012</a>] if the index is 
  a range index and any of the key items has a type that is not xs:untypedAtomic 
  and for which no ordering relationship exists.
  </li>

  <li>
  In this step, an <strong>expanded key sequence</strong> is constructed for
  each domain node. If the atomic type specified in the IndexKeyTypeDecl is
  neither xs:untypedAtomic nor xs:anyAtomicType, the expanded key sequence 
  is the same as the original key sequence. Otherwise, let D<sub>i</sub> be 
  the i-th domain node, and K<sub>i</sub> be the key sequence computed for 
  D<sub>i</sub>. If any key item in K<sub>i</sub> has type xs:untypedAtomic, 
  the item is removed from K<sub>i</sub> and is cast to every primitive builtin 
  data type. For each successful cast, the resulting item is inserted back 
  into K<sub>i</sub>.
  </li>

  <li>
  The next step is to insert in the index a mapping from K<sub>ij</sub> to 
  D<sub>i</sub>, for each key item K<sub>ij</sub> in the expanded key sequence
  K<sub>i</sub>. This step is performed for each node in the domain sequence. 
  The order in which the domain sequence is processed is implementation 
  dependent.
  </li>

  <li>
  If the index is declared as unique, the relationship between key items and 
  domain nodes is one-to-one. In this case, if the index already contains an 
  entry whose key item is equal to K<sub>ij</sub>, an error is raised 
  [<a href="#ERRZDDY0024">zerr:ZDDY0024</a>]. Otherwise, the entry 
  [K<sub>ij</sub>, D<sub>i</sub>] is inserted in the index container.
  </li>

  <li>
  If the index is non-unique, then if it already contains an entry whose key
  K is equal to K<sub>ij</sub>, D<sub>i</sub> is added to the node set 
  associated with K. Otherwise, the entry [K<sub>ij</sub>, { D<sub>i</sub> }] 
  is inserted into the index.  
  </li>

  <li>
  The index maintains a "special" entry for all domain nodes whose key sequence
  is empty. All such nodes are inserted in the node set associated with this entry.
  </li>

  </ul>

<li>
A entry is added to the indexes table. The entry maps the expanded QName of
the index to the index entry container.
</li>
</ul>


\subsection index_deletion Index Deletion


To destroy an index, Zorba provides the delete updating function. The
function itself and its associated update primitive are described below.

<a name="delete_index" id="delete_index"></a>
\code
  declare updating function iddl:delete($indexName as xs :QName)

  upd:deleteIndex($indexName as xs:QName)
\endcode

The delete function is evaluated as follows:

<ul>
<li>
If the given expanded QName does not identify an index among the statically 
known indexes in the static context of the invoking module, an error is
raised [<a href="#ERRZDDY0021">zerr:ZDDY0021</a>].
</li>
<li>
If the given expanded QName does not identify an index among the available
indexes in the dynamic context of the invoking module, an error is raised [<a
href="#ERRZDDY0023">zerr:ZDDY0023</a>].
</li>
<li>
The result of the function is an empty XDM instance and a pending update
list that consists of a single update primitive: upd:deleteIndex($indexName).
</li>
</ul>

The update primitive is applied as follows:

<ul>
<li>The index entry container for the index is found via the indexes table.</li>
<li>All entries in the container are destroyed.</li>
<li>The container itself is destroyed.</li>
<li>The entry mapping the index name to the index entry container is removed
from the indexes table.</li>
</ul>


\subsection index_probing Index Probing


\n Probing an index means retrieving the domain nodes associated with a particular
search condition. Probing can be done via the xqddf functions 
idml:probe-index-point-value, idml:probe-index-point-general, 
idml:probe-index-range-value, or idml:probe-index-range-general.
For each of these functions, the first argument is a QName identifying an index.
The rest of the arguments specify the search condition. For all functions, the
index must exist in both the statically known indexes and the available indexes
of the invoking module; otherwise error <a href="#ERRZDDY0021">zerr:ZDDY0021</a>
or <a href="#ERRZDDY0023">zerr:ZDDY0023</a> is raised, 
respectively. All of the functions return their result sorted in document order 
and without duplicate nodes.


<strong>idml:probe-index-point-value</strong>


<a name="probe_index_point_value" id="probe_index_point_value"></a>
\code
  idml:probe-index-point-value($indexUri as xs:QName,
                               $key1     as xs:anyAtomicType?,
                               ...,
                               $keyM     as xs:anyAtomicType?) as node()*
\endcode

The probe-index-point-value function retrieves the domain nodes associated by 
value equality with a given <strong>search tuple</strong>. The search tuple 
consists of a number of <strong>search keys</strong>, where each search key 
is either an atomic item or the empty sequence. The result of this function 
is either an error or the set of domain nodes for which the following xquery 
expression returns true:

\code
$key1 eq $node/keyExpr1 and ... and $keyM eq $node/keyExprN
\endcode

where keyExpr-i is the expression specified in the i<sup>th</sup> keyspec 
of the index and N is the number of keyspecs for the index. Notice that this 
definition implies that if any of search keys is the empty sequence, the
result of the probe is also the empty sequence.

In addition to the errors that may be raised by the above expression, the
probe-index-point-value function may raise the following errors:

<ul>
<li>
 <a href="#ERRZDDY0021">zerr:ZDDY0021</a> or <a href="#ERRZDDY0023">zerr:ZDDY0023</a>,
if the index is not among the statically known indexes or the available indexes.
</li>
<li>
[<a href="#ERRZDDY0025">zerr:ZDDY0025</a>], if the number of search keys is not
equal to the number of keyspecs found in the index declaration.
</li>
<li>
[err:XPTY0004], if a non-empty search key is given, whose type does not match 
the sequence type specified in the corresponding keyspec.
</li>
</ul>


<strong>idml:probe-index-point-general</strong>


<a name="probe_index_point_general" id="probe_index_point_general"></a>
\code
  idml:probe-index-point-general($indexUri as xs:QName,
                                 $keys     as xs:anyAtomicType*) as node()*
\endcode

\n The probe-index-point-general function retrieves the domain nodes associated by 
general equality with a given <strong>search sequence</strong>. The search
sequence consists of an arbitrary number of <strong>search keys</strong>, where 
each search key is an atomic item. The function is supported by general indexes
only [<a href="#ERRZDDY0029">zerr:ZDDY0029</a>]. Its result is either an error 
or the set of domain nodes for which the following xquery expression returns true:

\code
$keys = $node/keyExpr
\endcode

where keyExpr is the expression specified in the keyspec of the index (remember
that for general indexes, there can be only one keyspec).

In addition to the errors that may be raised by the above expression, the
probe-index-point-value function may raise the following errors:

<ul>
<li>
 <a href="#ERRZDDY0021">zerr:ZDDY0021</a> or <a href="#ERRZDDY0023">zerr:ZDDY0023</a>,
if the index is not among the statically known indexes or the available indexes.
</li>
<li>
[<a href="#ERRZDDY0029">zerr:ZDDY0029</a>], if the index is not general.
</li>
<li>
[err:XPTY0004], if the search sequence contains a search key, whose type does 
not match the sequence type specified in the keyspec of the index.
</li>
</ul>


<strong>idml:probe-index-range-value</strong>


<a name="probe_index_range_value" id="probe_index_range_value"></a>
\code
  probe-index-range-value($indexUri            as xs:QName,
                          $lowerBound1         as xs:anyAtomicType?,
                          $upperBound1         as xs:anyAtomicType?,
                          $haveLowerBound1     as xs:boolean,
                          $haveUpperBound1     as xs:boolean,
                          $lowerBoundIncluded1 as xs:boolean,
                          $upperBoundIncluded1 as xs:boolean,
                          ....,
                          $lowerBoundM         as xs:anyAtomicType?,
                          $upperBoundM         as xs:anyAtomicType?,
                          $haveLowerBoundM     as xs:boolean,
                          $haveUpperBoundM     as xs:boolean,
                          $lowerBoundIncludedM as xs:boolean,
                          $upperBoundIncludedM as xs:boolean) as node()*
\endcode

The probe-index-range-value function retrieves the domain nodes associated by 
value order-comparison (operators le, lt, ge, gt) with a given <strong>search 
box</strong>. The search box is specified as a number M of <strong>rangespecs
</strong>, where each rangespec consists of six values. The number M must be 
greater than 0 and less than or equal to the number N of keyspecs found in the 
index declaration [<a href="#ERRZDDY0025">zerr:ZDDY0025</a>]. If M is less 
than N, then the "missing" rangespecs are assumed to have the following 
value: [(), (), false, false, false, false]. As a result, from now on, we
can assume that M is equal to N (Remember that for general indexes, there 
can be only one IndexKeySpec, and as a result, for general indexes, M = N = 1).

The i<sup>th</sup> rangespec corresponds to the i<sup>th</sup> keyspec, and 
specifies a search condition on the key values that are produced by evaluating
that keyspec for every domain node. Specifically, we define the i<sup>th</sup>
<strong>rangespec result</strong> as the set of domain nodes for which the 
following xquery expression returns true:

\code
if ($haveLowerBound-i and $haveUpperBound-i) then
  $lowerBound-i lop $node/keyExpr-i and $node/keyExpr-i uop $upperBound-i
else if ($haveLowerBound-i) then
  $lowerBound-i lop $node/keyExpr-i
else if ($haveUpperBound-i) then
  $node/keyExpr-i uop $upperBound-i
else
  fn:true()
\endcode

where keyExpr-i is the expression specified by the i<sup>th</sup> keyspec 
of the index, lop is either the le or the lt operator depending on whether 
$lowerBoundsIncluded-i is true or false, and uop is either the le or the 
lt operator depending on whether $upperBoundsIncluded-i is true or false.

The result of the probe-index-range-value function is either an error, or the
intersection of all the rangespec results. In addition to the errors that may 
be raised by a rangespec expression, the function may raise the following errors:

<ul>
<li>
 <a href="#ERRZDDY0021">zerr:ZDDY0021</a> or <a href="#ERRZDDY0023">zerr:ZDDY0023</a>,
if the index is not among the statically known indexes or the available indexes.
</li>
<li>
[<a href="#ERRZDDY0026">zerr:ZDDY0026</a>], if the index is not a range index.
</li>
<li>
[<a href="#ERRZDDY0025">zerr:ZDDY0025</a>], if the number of rangespecs passed 
as arguments is zero or greater than the number of keys declared for the index.
</li>
<li>
[err:XPTY0004], if $haveLowerBound-i is true and $lowerBound-i is an atomic 
item whose type does not match the sequence type specified by the i<sup>th</sup> 
keyspec, or $haveUpperBound-i is true and $upperBound-i is an atomic item 
whose type does not match the sequence type specified by the i<sup>th</sup> keyspec.
</li>
<li>
[<a href="#ERRZDDY0034">zerr:ZDDY0034</a>], if (a) the index is general (in which 
case there is only one rangespac), (b) the index is untyped, (c) there is both a
lower and an upper bound, and (d) if T1 and T2 are the types of the lower and 
upper bound, neither T1 is a subtype of T2 nor T2 is a subtype of T1.   
</li>
</ul>


<strong>idml:probe-index-range-general</strong>


<a name="probe_index_range_general" id="probe_index_range_general"></a>
\code
  probe-index-range-general($indexUri            as xs:QName,
                            $lowerBoundKeys      as xs:anyAtomicType*,
                            $upperBoundKeys      as xs:anyAtomicType*,
                            $haveLowerBound      as xs:boolean,
                            $haveUpperBound      as xs:boolean,
                            $lowerBoundIncluded  as xs:boolean,
                            $upperBoundIncluded  as xs:boolean) as node()*
\endcode

The probe-index-range-general function retrieves the domain nodes associated
by general order-comparison (operators <=, <, >=, >) with one or two
<strong>search sequences</strong>. Each search sequence consists of an 
arbitrary number of <strong>search keys</strong>, where each search key is 
an atomic item. This method is supported by general range indexes only 
[<a href="#ERRZDDY0030">zerr:ZDDY0030</a>]. Its result is either an error or
the set of domain nodes for which the following xquery expression returns true:

\code
if ($haveLowerBound and $haveUpperBound) then
  $lowerBoundKeys lop $node/keyExpr and $node/keyExpr uop $upperBoundKeys
else if ($haveLowerBound) then
  $lowerBoundKeys lop $node/keyExpr
else if ($haveUpperBound) then
  $node/keyExpr uop $upperBoundKeys
else
  fn:true()
\endcode

where keyExpr is the expression specified in the keyspec of the index,
lop is either the <= or the < operator depending on whether $lowerBoundsIncluded
is true or false, and uop is either the <= or the < operator depending on whether
$upperBoundsIncluded is true or false.

In addition to the errors that may be raised by the above expression, the
probe-index-point-value function may raise the following errors:

<ul>
<li>
 <a href="#ERRZDDY0021">zerr:ZDDY0021</a> or <a href="#ERRZDDY0023">zerr:ZDDY0023</a>,
if the index is not among the statically known indexes or the available indexes.
</li>
<li>
[<a href="#ERRZDDY0030">zerr:ZDDY0030</a>], if the index is not a general range index.
</li>
<li>
[err:XPTY0004], if $haveLowerBound is true and $lowerBoundKeys constains an
atomic item whose type does not match the sequence type specified by the index 
keyspec, or $haveUpperBound is true and $upperBoundKeys contains an atomic item 
whose type does not match the sequence type specified by the index keyspec.
</li>
</ul>

\subsection index_keys Retrieving Index Keys
In addition to probing an index, the <tt>idml</tt> module also provides a function that allows listing all the keys contained in an index.

\code
  idml:keys($indexName as xs:QName) as item()*
\endcode

This function returns a sequence of element nodes.
Each node in the sequence represents one key contained in the index and has the following structure:

\code
 <key xmlns="http://zorba.io/modules/store/static/indexes/dml">
   <attribute value="key_1"/>
   ...
   <attribute value="key_n"/>
 </key>
\endcode

The order of the attribute elements reflects the order of the key specifications in the declaration of the index.
Also, the types of the values of the attributes are the types of the keys as they are declared.
If a value attribute is not present, this means that the value of the corresponding key in the index is the empty sequence.

\subsection index_maintenance Index Maintenance

\n An index is said to be up-to-date if its content reflects the index definition
on the current data snapshot, i.e., the contents are the same as those that
would be produced if the
<a href="#create_index" title="idml:create">iddl:create</a>
function was invoked on the same index and with the same underlying data.
An index is said to be stale if it is not up-to-date. Indexes become stale when
documents in collections are updated or when documents are inserted/removed
in/from collections. <strong>Index Maintenance</strong> is the operation by
which stale index contents are updated so that the index becomes up-to-date.
Zorba offers two maintenance modes: manual and automatic.

\n \n If an index is declared as "automatically maintained" (i.e. '%an:automatic'), Zorba guarantees that
every time a PUL is applied, the index is made up-to-date before the 
upd:apply-updates function returns. Ideally, all indexes should be automatically
maintained, but in general, index maintenance can be a very expensive operation
performance-wise. As a result, Zorba will reject a declaration for an automatic
index if it determines that it cannot maintain the index in an "efficient" way.
The definition of efficiency with respect to index maintenance is implementation
dependent, but in general, it means that the index can be maintained in some
incremental way that is faster than simply re-creating the whole index from
scratch. However, even incremental maintenance can have a high cost, which
may make the manual mode described below the preferred choice.

\n \n If an index is declared as "manually maintained" (i.e. '%an:manual'), it is the responsibility of
the programmers to keep the index up-to-date. This can be done using the 
idml:refresh-index updating function described below. Since Zorba does not
take any maintenance action during PUL applications, manually maintained
indexes may become stale in between calls to the idml:refresh-index function.
Obviously, the manual mode must be used if an index cannot be maintained
automatically. However, even for automatically maintainable indexes, the
manual mode may be preferable if users can tolerate a stale index in return
for better performance during updates. 

<a name="refresh_index" id="refresh_index"></a>
\code
  declare updating function idml:refresh-index($indexName as xs:QName)

  upd:refreshIndex($indexName as xs:QName)
\endcode

The refresh-index function is evaluated as follows:

  <ul>
  <li>If the given expanded QName does not identify an index among the
statically
      known indexes in the static context of the invoking module, an error is 
      raised [<a href="#ERRZDDY0021">zerr:ZDDY0021</a>].</li>
  <li>If the given expanded QName does not identify an index among the available
      indexes in the dynamic context of the invoking module, an error is raised
      [<a href="#ERRZDDY0023">zerr:ZDDY0023</a>].</li>
  <li>The result of the function is an empty XDM instance and a pending update
      list that consists of a single update primitive:
upd:refreshIndex($indexName).</li>
  </ul>

The update primitive is applied as follows:

  <ul>
  <li>The index entry container for the index is found via the indexes
table.</li>
  <li>The container is made up-to-date in some implementation dependent way. In
      Zorba this is done by discarding the current contents and rebuilding
      the index from scratch (the same way as the
<a href="#create_index" title="iddl:create">iddl:create</a>
function populates an empty index container).</li>
  </ul>



\section integrity_constraints Integrity Constraints in Zorba 

\code
  ICDecl                ::=  'integrity' 'constraint' EQName (ICCollection | ICForeignKey)

  ICCollection          ::=  'on' 'collection' EQName
       ( ICCollSequence | ICCollSequenceUnique | ICCollNode )

  ICCollSequence        ::=  '\$' EQName 'check' ExprSingle

  ICCollSequenceUnique  ::=  'node' '\$' EQName 'check' 'unique' 'key' PathExpr

  ICCollNode            ::=  'foreach' 'node' '\$' EQName 'check' ExprSingle

  ICForeignKey          ::=  'foreign' 'key' ICForeignKeySource ICForeignKeyTarget

  ICForeignKeySource    ::=  'from' ICForeignKeyValues

  ICForeignKeyTarget    ::=  'to' ICForeignKeyValues

  ICForeignKeyValues    ::=  'collection' EQName 'node' '\$' QName 'key' PathExpr
\endcode


Analogously to collections and indexes, Zorba defines an additional extension to
XQuery library modules which allows the declaration of (static) integrity
constraints (ICs). Static ICs can be used to ensure that, in every moment in
time, all data which is stored in collections is accurate and consistent
according to the semantics of an application.
Note that Zorba doesn't define any dynamic integrity constraints which check
the validity of a particular update.
As in the relational world, Zorba defines several types of ICs:
<a href="#ic_entity_integrity" title="Entity">Entity</a>,
<a href="#ic_domain_integrity" title="Domain">Domain</a> and
<a href="#ic_referential_integrity" title="Referential">Referential</a> ICs.

\n \n <a href="#ic_entity_integrity" title="Entity">Entity</a> ICs check for the accuracy
and consistency of all nodes in a collection. For instance, a special case of
the Entity IC is the IC that checks for unique keys among all nodes in a
collection.
The <a href="#ic_domain_integrity" title="Domain">Domain</a> IC validates that
each node in a collection satisfies a given expression.
The <a href="#ic_referential_integrity" title="Referential">Referential</a> IC
is used to ensure a foreign key relationship between the nodes in two collections.

\n \n In this section, we describe how such ICs are declared in a library module and
how a particular IC can be (de-)activated. All ICs are described using examples
for the news application. Specifically, we declare ICs for the data stored in
the news-data:employees and the news-data:articles collections.

\subsection ic_declaration Declaration

\n As for collections and indexes, ICs must be declared before the user can
activate
them. An IC declaration specifies (1) the name of the IC for being used by
function
call to (de-)activate it (see next section), (2) the name of the collection(s)
whose
data should be validated, and (3) the expression(s) that guarantee the accuracy
and
consistency of the data. Analogously to indexes, ICs are declared inside the
prolog
of the library module that declares the collection(s) which is/are referenced by
the
IC.

<a name="ic_entity_integrity" id="ic_entity_integrity"></a>
\subsubsection ic_entity_integrity Entity Integrity
An Entity IC is used to state the uniqueness of a key among all nodes of a
collection. For example, the IC (named news-data:UniqueId) in the example below
states that the value of the id attribute of each employee is unique among all
other nodes in the news-data:employees collection.

\code
  declare integrity constraint news-data:UniqueId
    on collection news-data:employees
    node $id check unique key $id/@id;
\endcode

The name of the collection is specified after the "on collection" keyword. The
path expression following the "check unique key" keyword returns the value to be
checked for uniqueness. The result of this path expression must not be empty and
is wrapped to return an atomic value. The variable $id is successively bound to
each node of the news-data:employees collection and available in the check
expression.

<a name="ic_domain_integrity" id="ic_domain_integrity"></a>
\subsubsection ic_domain_integrity Domain Integrity
The Domain IC allows the user to specify constraints that a particular node in
a collection must satisfy. Domain ICs can be use in addition to XML Schema types
or if no XML schema is available.

With the following example, we want to make sure that the name of each author
of an article is not the zero length string. This can be particularly useful
since there is no XML schema for articles.

\code
  declare integrity constraint news-data:AuthorNames
    on collection news-data:article
    foreach node $article check fn:string-length($article/author/name) != 0;
\endcode

The name of the IC is news-data:AuthorNames and it is defined on nodes
belonging to the news-data:articles collection. The "foreach node" expression
specifies a variable (using a QName) which is bound to each node in the
collection. For each such node, the check expression is executed. For each node,
the boolean effective value of the result of this expression must be equal to
true.

<a name="ic_referential_integrity" id="ic_referential_integrity"></a>
\subsubsection ic_referential_integrity Referential Integrity

\n The Referential IC requires every value of a node in a collection to exist as
a value of another node in another collection. For example, in the database of
the news organization, we want to make sure that each article is maintained by
an (existing) employee. This can be done by declaring a so called foreign key
IC. In the following example, this IC is given the name
news-data:ArticleEmployees.

\code
  declare integrity constraint news-data:ArticleEmployees
    foreign key
      from collection news-data:articles node $x key $x/empid
      to   collection news-data:employees node $y key fn:data($y/@id);
\endcode

The QName following the "from collection" and "to collection" keywords specify
the source and destination collections, respectively. Each result of the key
expressions are wrapped to return an atomic value. For each atomic value in the
source collection, an atomic value in the sequence returned by the key
expression on the destination collection must exist. The IC is violated if this
is not the case for any node in the source collection. This semantics is
equivalent to the following XQuery expression.

\code
  every $x in idml:collection(xs:QName("news-data:articles"))
  satisfies
    some $y in idml:collection(xs:QName("news-data:employees"))
    satisfies $y/id eq $x//sale/empid
\endcode

\subsection ic_life_cycle Lifecycle Management

\n ICs can be checked manually (if requested by the user) or automatically on
updates
apply time, after validation and indexes are computed. In order to be checked
automatically, an IC needs to be active. ICs can be (de-)activated using the two
updating functions icddl:activate and
icddl:deactivate, respectively. Each function takes the
name of
the IC to (de-)activate as parameter. The flag indicating whether an IC is
active or
not is stored in the dynamic context.

\n \n Deactivating an IC might be useful if the corresponding check is expensive and,
hence, inconsistency of the data might be acceptable and only checked (and fixed
manually) from time to time. To check an IC manually, the Zorba defines an
updating
function called check-integrity-constraint which triggers the IC, identified by
a
QName passed as parameter, to be checked.

\n \n Similar to collections and indexes, the module declaring the integrity
constraints
(i.e. with namespace %http://www.news.org/data) can also declare variables whose
values are the QNames of the ICs. This allows their names to be easily
referenced by
subsequent expressions. For example, such a variable can be passed as a
parameter to
the activate in the importing admin-script module (see
above).
For the ICs from the section above, those variables are declared as follows:

\code
  declare variable $news-data:UniqueId := xs:QName("news-data:UniqueId");
  declare variable $news-data:AuthorName := xs:QName("news-data:AuthorNames");
  declare variable $news-data:ArticleEmployees := xs:QName("news-data:ArticleEmployees");
\endcode


\section extensions_xquf_updates_routines Extensions to the XQUF updates
routines

\subsection upd_merge_updates upd:mergeUpdates

\n The XQuery Update Facility specification lists a number of errors that may be
raised
by the upd:mergeUpdates routine. Zorba adds the following error conditions to
this list:

<ul>
<li>An error is raised [<a href="#ERRZDDY0016"
title="zerr:ZDDY0016">zerr:ZDDY0016</a>]
    if two or more upd:createCollection primitives having the same QName as
argument appear in the merged list.</li>
<li>An error is raised [<a href="#ERRZDDY0027"
title="zerr:ZDDY0027">zerr:ZDDY0027</a>]
    if two or more upd:createIndex primitives having the same QName as argument
appear in the merged list.</li>
</ul>


\subsection upr_apply_updates upd:applyUpdates


\section error_summary Appendix Error Summary

The prefix "zerr" is bound to the error namespace of Zorba, i.e. %http://zorba.io/errors .
The prefix "err" is bound to the general XQuery error namespace, i.e. http://www.w3.org/2005/xqt-errors .

<p>XQuery Data Definition Facility - Static Errors:</p>

<strong>
\n <a name="ERRZDST0001" id="ERRZDST0001"></a>zerr:ZDST0001, A collection with
name is already declared in the same module.

\n <a name="ERRZDST0002" id="ERRZDST0002"></a>zerr:ZDST0002, A collection with
name that is imported from module is already declared in the importing module.

\n <a name="ERRZDST0003" id="ERRZDST0003"></a>zerr:ZDST0003, A collection
declaration cannot appear in a main module.

\n <a name="ERRZDST0004" id="ERRZDST0004"></a>zerr:ZDST0004, The declaration for
collection specifies multiple values for the same property.

\n <a name="ERRZDST0005" id="ERRZDST0005"></a>zerr:ZDST0005, The declaration for
collection specifies conflicting property values.

\n <a name="ERRZDST0006" id="ERRZDST0006"></a>zerr:ZDST0006, The declaration for
collection contains an invalid property value.

\n <a name="ERRZDST0021" id="ERRZDST0021"></a>zerr:ZDST0021, An index with name is
already declared in the same module.

\n <a name="ERRZDST0022" id="ERRZDST0022"></a>zerr:ZDST0022, An index with name
that is imported from module /s is already declared in the importing module.

\n <a name="ERRZDST0023" id="ERRZDST0023"></a>zerr:ZDST0023, An index declaration
cannot appear in a main module.

\n <a name="ERRZDST0024" id="ERRZDST0024"></a>zerr:ZDST0024, The declaration for
index specifies multiple values for the same property.

\n <a name="ERRZDST0025" id="ERRZDST0025"></a>zerr:ZDST0025, The index cannot be
declared as unique.

\n <a name="ERRZDST0026" id="ERRZDST0026"></a>zerr:ZDST0026, The declaration for
index contains an invalid property value.

\n <a name="ERRZDST0027" id="ERRZDST0027"></a>zerr:ZDST0027, The index has an
invalid key type declaration.

\n <a name="ERRZDST0028" id="ERRZDST0028"></a>zerr:ZDST0028, The index has a non
deterministic definition.

\n <a name="ERRZDST0029" id="ERRZDST0029"></a>zerr:ZDST0029, The index references
a data source that is not a collection.

\n <a name="ERRZDST0030" id="ERRZDST0030"></a>zerr:ZDST0030, The index references
a collection with a non-const QName.

\n <a name="ERRZDST0031" id="ERRZDST0031"></a>zerr:ZDST0031, The index has free
variables in its definition.

\n <a name="ERRZDST0032" id="ERRZDST0032"></a>zerr:ZDST0032, The domain expression
of index references the context item.

\n <a name="ERRZDST0033" id="ERRZDST0033"></a>zerr:ZDST0033, The declaration of
index contains a non-simple expression.

\n <a name="ERRZDST0034" id="ERRZDST0034"></a>zerr:ZDST0034, Index cannot be
automatically maintained.

\n <a name="ERRZDST0036" id="ERRZDST0036"></a>zerr:ZDST0036, Index qname does not
have the same namespace URI as the target namespace of the declaring module.

\n <a name="ERRZDST0041" id="ERRZDST0041"></a>zerr:ZDST0041, An integrity
constraint with URI is declared already.

\n <a name="ERRZDST0042" id="ERRZDST0042"></a>zerr:ZDST0042, An integrity
constraint key has multiple values.

\n <a name="ERRZDST0043" id="ERRZDST0043"></a>zerr:ZDST0043, An integrity
constraint key has a non-atomic value.

\n <a name="ERRZDST0045" id="ERRZDST0045"></a>zerr:ZDST0045, The integrity
constraint cannot be declared in a main module.

\n <a name="ERRZDST0046" id="ERRZDST0046"></a>zerr:ZDST0046, The integrity
constraint with URI has free variables in its definition.

\n <a name="ERRZDST0047" id="ERRZDST0047"></a>zerr:ZDST0047, The integrity
constraint with URI references a data source that is not a collection among the
statically known collections.

\n <a name="ERRZDST0048" id="ERRZDST0048"></a>zerr:ZDST0048,The integrity
constraint with URI has a non deterministic definition.
</strong>

<p>XQuery Data Definition Facility - Type Errors:</p>

<strong>
\n <a name="ERRXDTY0001" id="ERRXDTY0001"></a>zerr:XDTY0001, Collection cannot
contain a node of certain type.

\n <a name="ERRXDTY0010" id="ERRXDTY0010"></a>zerr:XDTY0010, The domain expression
of index produces an item that is not a node.

\n <a name="ERRXDTY0011" id="ERRXDTY0011"></a>zerr:XDTY0011, The result of some
key expression of index does not match its declared type.
</strong>

<p>XQuery Data Definition Facility - Dynamic Errors:</p>

<strong>
\n <a name="ERRZDDY0001" id="ERRZDDY0001"></a>zerr:ZDDY0001, Collection is not
declared in the static context.

\n <a name="ERRZDDY0002" id="ERRZDDY0002"></a>zerr:ZDDY0002, Collection exists
already.

\n <a name="ERRZDDY0003" id="ERRZDDY0003"></a>zerr:ZDDY0003, Collection does not
exist.

\n <a name="ERRZDDY0004" id="ERRZDDY0004"></a>zerr:ZDDY0004, Cannot update const
collection.

\n <a name="ERRZDDY0005" id="ERRZDDY0005"></a>zerr:ZDDY0005, Illegal insert in
append-only collection.

\n <a name="ERRZDDY0006" id="ERRZDDY0006"></a>zerr:ZDDY0006, Illegal insert in
queue collection.

\n <a name="ERRZDDY0007" id="ERRZDDY0007"></a>zerr:ZDDY0007, Illegal delete from
append-only collection.

\n <a name="ERRZDDY0008" id="ERRZDDY0008"></a>zerr:ZDDY0008, Illegal delete from
queue collection.

\n <a name="ERRZDDY0009" id="ERRZDDY0009"></a>zerr:ZDDY0009, Not all the nodes to
delete are at the beginning of queue collection.

\n <a name="ERRZDDY0010" id="ERRZDDY0010"></a>zerr:ZDDY0010, Illegal update of
node in collection, whose nodes are read-only.

\n <a name="ERRZDDY0011" id="ERRZDDY0011"></a>zerr:ZDDY0011, Node is not contained
in collection.

\n <a name="ERRZDDY0012" id="ERRZDDY0012"></a>zerr:ZDDY0012, Illegal insert in
unordered collection.

\n <a name="ERRZDDY0013" id="ERRZDDY0013"></a>zerr:ZDDY0013, Cannot delete
collection because there are indexes that reference it.

\n <a name="ERRZDDY0014" id="ERRZDDY0014"></a>zerr:ZDDY0014, Cannot delete
collection because there are integrity constraints that reference it.

\n <a name="ERRZDDY0015" id="ERRZDDY0015"></a>zerr:ZDDY0015, Cannot delete
collection because there are references on its nodes.

<a name="ERRZDDY0016" id="ERRZDDY0016"></a>zerr:ZDDY0016, Cannot invoke the
create function multiple times with the same QName in the same
snapshot.

\n <a name="ERRZDDY0020" id="ERRZDDY0020"></a>zerr:ZDDY0020, The domain expression
of index produces nodes that are not in collection.

\n <a name="ERRZDDY0021" id="ERRZDDY0021"></a>zerr:ZDDY0021, Index is not declared
in the static context.

\n <a name="ERRZDDY0022" id="ERRZDDY0022"></a>zerr:ZDDY0022, Index exists already.

\n <a name="ERRZDDY0023" id="ERRZDDY0023"></a>zerr:ZDDY0023, Index does not exist.

\n <a name="ERRZDDY0024" id="ERRZDDY0024"></a>zerr:ZDDY0024, The uniqueness
property of index is violated.

\n <a name="ERRZDDY0025" id="ERRZDDY0025"></a>zerr:ZDDY0025, Invalid number of
arguments in probe of index.

\n <a name="ERRZDDY0026" id="ERRZDDY0026"></a>zerr:ZDDY0026, Index does not
support range probes.

<a name="ERRZDDY0027" id="ERRZDDY0027"></a>zerr:ZDDY0027, Cannot invoke the
create function multiple times with the same QName in the same snapshot.

<a name="ERRZDDY0030" id="ERRZDDY0030"></a>zerr:ZDDY0030, Index does not
support general range probes.

\n <a name="ERRZDDY0031" id="ERRZDDY0031"></a>zerr:ZDDY0031, An integrity
constraint with URI is not declared.

\n <a name="ERRZDDY0032" id="ERRZDDY0032"></a>zerr:ZDDY0032, An integrity
constraint with URI is not declared.

\n <a name="ERRZDDY0033" id="ERRZDDY0033"></a>zerr:ZDDY0033, Conditions for
integrity constraint were not met on collection.

\n <a name="ERRZDDY0034" id="ERRZDDY0034"></a>zerr:ZDDY0034, Index range-value
 probe has search keys with incompatible types
</strong>
