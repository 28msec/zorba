# Command Line Utility

## Usage
`zorba [options] [-q Inline_Query ...]` or `zorba [options] -f [-q Query_File ...]`

## Help

Available options:

```
--timing, -t
Print timing information. In case of multiple queries the timing information is provided per each query. Both wallclock time and user time (which excludes I/O, network delays and other kernel waits) are shown.

--output-file, -o
Write the result to the given file.

--serialization-parameter, -z
Set serialization parameter in the form of a parameter=value pair (see http://www.w3.org/TR/xslt-xquery-serialization/#serparam, e.g.: -z method=xhtml -z doctype-system=DTD/xhtml1-strict.dtd -z indent=yes).

--serialize-html
Serialize the result as HTML.

--serialize-text
Serialize the result as Text.

--indent, -i
Indent output.

--print-query
Print the queries.

--print-errors-as-xml, -x
Print the errors as XML.

--byte-order-mark
Set the byte-order-mark for the serializer.

--omit-xml-declaration, -r
Omit the XML declaration from the result.

--base-uri
Set the base URI property of the static context.

--boundary-space
Set the boundary-space policy ('strip' or 'preserve') in the static context.

--default-collation
Add the given collation and set the value of the default collation in the static context to the given collation.

--construction-mode
Set the construction mode ('strip' or 'preserve') in the static context.

--ordering-mode
Set the ordering mode ('ordered' or 'unordered') in the static context.

--multiple, -m
Execute the given queries multiple times.

--query, -q
Query test or file URI (file://...)

--as-files, -f
Treat all -q arguments as file paths instead of URIs or inline queries. This option is deprecated and will be defaulted to true in the future, so any entry in the command line is going to be treated as files.

--external-variable, -e
Provide the value for a variable given a file (name=file) or a value (name:=value)

--context-item
Set the context item to the XML document in a given file.

--optimization-level
Optimization level for the query compiler (O0, O1 or O2 - default: O1)

--lib-module, -l
Query compiler option to treat the query as a library module. If this is set --compile-only option is also set to true.

--parse-only
Stop after parsing the query.

--compile-only
Only compile (don't execute)

--no-serializer
Do not serialize (discard) result.

--debug, -d
Launch the Zorba debugger server and connect to a DBGP-enabled debugger client.

--debug-host, -h
The host where the DBGP-enabled debugger client listens for connections. Defaults to: 127.0.0.1

--debug-port, -p
The port on which the DBGP-enabled debugger client listens for connections. Defaults to: 28028

--no-logo
Print no logo when starting.

--timeout
Specify a timeout in seconds. After the specified time, the execution of the query will be aborted.

--uri-path
URI path (list of directories) added to the built-in URI resolver, i.e. where to find modules/schemas to import.

--lib-path
Library path (list of directories) where Zorba will look for dynamic libraries (e.g., module external function implementations.

--module-path
Path (list of directories) to add to both the URI and Library paths.

--classpath
JVM classpath to be used by modules using Java implementations

--option
Set an XQuery option in the static context. The QName of the option is passed as a string in the notation by James Clark (i.e. {namespace}localname). For example, --option {http://zorba.io/}option=value

--trailing-nl
Output a trailing newline after the result of the query.

--stop-words
Mapping specifying a stop-words URI to another.

--thesaurus
Mapping specifying a thesaurus URI to another.

--serialize-plan, -s
Serialize and then load the query execution plan.

--compile-plan,
Do not execute the query; just compile it and save the execution plan in the file specified with the -o option.

--execute-plan
Do not compile the query; instead load the execution plan from the file specified by the -f -q options (or by any file specified without any other argument), and execute the loaded plan.

--disable-http-resolution
Do not use HTTP to resolve URIs
```

## Examples

### Execute inline queries
This example shows the use of `-t`, `--print-query` output options and `-i` execute option.

Zorba command:
```bash
zorba -t --print-query -q "1+1" -q "fn:concat('un', 'grateful')" -q "fn:matches('abracadabra', '^a.*a$')"
```

Output:
```
Query number 1 :
1+1
<?xml version="1.0" encoding="UTF-8"?>
2
Number of executions = 1
Engine Startup Time     : 36.205 (user: 35.949) milliseconds
Average Compilation Time: 3.035 (user: 3.011) milliseconds
Average Execution Time  : 0.154 (user: 0.148) milliseconds
Average Loading Time    : 0.000 (user: 0.000) milliseconds
Average Unloading Time  : 23.080 (user: 9.798) milliseconds
Average Total Time      : 31.791 (user: 18.433) milliseconds

Query number 2 :
fn:concat('un', 'grateful')
<?xml version="1.0" encoding="UTF-8"?>
ungrateful
Number of executions = 1
Engine Startup Time     : 36.205 (user: 35.949) milliseconds
Average Compilation Time: 3.971 (user: 3.932) milliseconds
Average Execution Time  : 0.217 (user: 0.212) milliseconds
Average Loading Time    : 0.000 (user: 0.000) milliseconds
Average Unloading Time  : 27.641 (user: 14.319) milliseconds
Average Total Time      : 37.364 (user: 23.946) milliseconds

Query number 3 :
fn:matches('abracadabra', '^a.*a$')
<?xml version="1.0" encoding="UTF-8"?>
true
Number of executions = 1
Engine Startup Time     : 36.205 (user: 35.949) milliseconds
Average Compilation Time: 93.269 (user: 11.609) milliseconds
Average Execution Time  : 0.396 (user: 0.375) milliseconds
Average Loading Time    : 0.000 (user: 0.000) milliseconds
Average Unloading Time  : 32.478 (user: 19.128) milliseconds
Average Total Time      : 131.699 (user: 36.610) milliseconds

Engine Shutdown Time     : 0.007 (user: 0.007) milliseconds
```

## Execute update queries
The purpose of this example is to demonstrate the use of `-f` and `-e` execute options.

These are the files used in this example and their meaning:

| Filename | Description |
| -------- | ----------- |
| `works-mod.xml` | File that will be used as external variable. |
| `comandline_doc_example_2.xq` | This is an update query. For details please see below. |
| `comandline_doc_example_2-test.xq` | Query used to see the results of the update query. For details please see below. |

works-mod.xml:
```xml
<?xml version="1.0"?>
 <works>
  <employee name="Jane Doe 1" gender="female">
   <empnum>E1</empnum>
   <pnum>P1</pnum>
   <hours>40</hours>
  </employee>
  <employee name = "John Doe 2" gender="male">
   <empnum>E1</empnum>
   <pnum>P2</pnum>
   <hours>70</hours>
   <hours>20</hours>Text data from Employee[2]
  </employee>
 </works>
```

comandline_doc_example_2.xq :
```xquery
(: Name: comandline_doc_example_2 :)
(: Description: Evaluation of insert expression used with typeswitch expression where branch (a "case") is an updating expression. :)
(: All other branches return "fn:error()". :)

(: insert-start :)
declare variable $input-context external;
(: insert-end :)

typeswitch(xs:int(1))
 case $i as xs:int
    return (insert node <hours>30</hours> into $input-context/works[1]/employee[1])
 case $i as xs:double
    return fn:error(fn:QName('http://www.w3.org/2005/xqt-errors', 'err:FOER0000'))
 default
    return fn:error(fn:QName('http://www.w3.org/2005/xqt-errors', 'err:FOER0000'))
```

comandline_doc_example_2-test.xq :
```xquery
(: Name: comandline_doc_example_2-test :)
(: Description: Query to verify comandline_doc_example_2 :)

(: insert-start :)
declare variable $input-context external;
(: insert-end :)

$input-context/works[1]/employee[1]
```

Zorba command:
```bash
zorba -e input-context=works-mod.xml -f -q comandline_doc_example_2.xq -q comandline_doc_example_2-test.xq
```

Expected result:
```xml
<employee name="Jane Doe 1" gender="female">
   <empnum>E1</empnum>
   <pnum>P1</pnum>
   <hours>40</hours>
  <hours>30</hours></employee>
```