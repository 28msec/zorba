# Errors and Warnings

During the interaction with Zorba (e.g.through the C++ API) and the processing of programs, errors may be raised and warnings may be reported.
In this document, we describe how errors and warnings can be dealt with using Zorba's C++ API, XQuery, and JSONiq.

\section errors_warnings_errors Errors

Zorba may raise errors during the static analysis phase and the dynamic evaluation phase of a query.
Moreover, errors may be raised by any of the host language APIs.
Each such error is identified by a QName.
Most of the errors are defined by any of the XQuery specifications (e.g. XQuery 1.0 or 3.0, XQuery Update, or XQuery Full Text) and contained in the XPath and XQuery error namespace (http://www.w3.org/2005/xqt-errors).
In addition, Zorba defines a set of errors in the %http://zorba.io/errors namespace.

A full list of potential errors can be found in the diagnostic_list.h header (<tt>err</tt> and <tt>zerr</tt> namespaces) of the C++ API and in the following modules:

<ul>
  <li><a href="/modules/latest/zorba.io/errors">http://zorba.io/errors</a></li>
  <li><a href="/modules/latest/www.w3.org/2005/xqt-errors">http://www.w3.org/2005/xqt-errors</a></li>
</ul>

These modules declare one variable per error.
The name and value of the variable is the QName of the corresponding error.

\section errors_warnings_warnings Warnings

In addition to the errors mentioned in the previous section, Zorba may raise warnings during the static analysis phase of the query.
Warnings are diagnostic messages that report constructions which are not inherently erroneous but which are risky or suggest there may have been an error.
Like an error, a warning is identified by a QName whose namespace is %http://zorba.io/warnings.
A list of warnings can be found in the diagnostic_list.h header (zwarn namespace) of the C++ API and in the <a href="/modules/latest/zorba.io/warnings">http://zorba.io/warnings</a> module.

A warning can be enabled (i.e. will be reported), disabled (i.e. will not be reported), or turned into an error (i.e. an error with the same name will be raised) by specifying options in the static context that is used to compile the query (zorba::StaticContext::declareOption) or in the prolog of an XQuery module.

For example, given the following prolog of an XQuery module, all warnings are treated as errors:

\code
  declare namespace op = "http://zorba.io/options/warnings";
  declare namespace w = "http://zorba.io/warnings";

  declare option op:error "w:all";
\endcode

More information on how options can be used to configure warnings can be found in the \ref options_and_annotations documentation.


\section errors_warnings_cpp Errors and Warnings in the C++ API
In the C++ API, errors are reported using the exception classes: zorba::ZorbaException, zorba::XQueryException, and zorba::UserException.
Objects of type zorba::ZorbaException contain a description of the error.
Instances of the class zorba::XQueryException are raised during the static or dynamic analysis or evaluation phase, respectively.
They contain additional information about the source location of the problem in the program (i.e. zorba::XQueryException::source_uri(), zorba::XQueryException::source_line(), zorba::XQueryException::source_column(), zorba::XQueryException::source_line_end(), and zorba::XQueryException::source_column_end()).
Moreover, if the error occurs during the dynamic evaluation phase, the object carries the stack trace containing the names and source location of the invoked functions.
zorba::UserException is an zorba::XQueryException which is used to report errors that are raised by the <tt>fn:error()</tt> function.
In addition to the source location and stack trace, instances of this class may also carry an error object (if passed to <tt>fn:error</tt>).

In the C++ API, those objects are usually thrown and need to be caught (and handled) by the caller.
However, the API also provides a way to register a user-defined diagnostic handler (i.e. subclass of zorba::DiagnosticHandler) whose zorba::DiagnosticHandler::error (ZorbaException const & exception) function is invoked if an error occurs.

Please take a look at the C++ examples that show how to deal with errors and warnings in the C++ API (\ref errors_8cpp-example).

\section try_catch Try/Catch Expressions
The 
<a href="http://www.w3.org/TR/xquery-30/#id-try-catch">try/catch expression</a>
provides error handling for dynamic errors and type errors
raised during dynamic evaluation.
For example:

\include zorba/trycatch/trycatch_doc_example_01.xq

Within the \c catch expression,
a few implicit variables are defined.
Some of them
(e.g., <tt>\$err:code</tt>,
<tt>\$err:description</tt>,
and <tt>\$err:line-number</tt>)
are defined by the
<a href="http://www.w3.org/TR/xquery-30/#id-try-catch">XQuery</a>
specification.

Zorba defines additional implicit variables:

<table>
  <tr>
    <th>Variable</th>
    <th>Type</th>
    <th>Value</th>
  </tr>
  <tr>
    <td>\c $zerr:line-number-end</td>
    <td>\c xs:integer?</td>
    <td>
      The ending line number within the query where the error occurred.
    </td>
  </tr>
  <tr>
    <td>\c $zerr:column-number-end</td>
    <td>\c xs:integer?</td>
    <td>
      The ending column number within the query where the error occurred.
    </td>
  </tr>
  <tr>
    <td>\c $zerr:data-uri</td>
    <td>\c xs:string?</td>
    <td>
      The URI of the data file containing the error.
    </td>
  </tr>
  <tr>
    <td>\c $zerr:data-line-number</td>
    <td>\c xs:integer?</td>
    <td>
      The line number within the data file where the error occurred.
      The value \e may be approximate.
    </td>
  </tr>
  <tr>
    <td>\c $zerr:data-column-number</td>
    <td>\c xs:integer?</td>
    <td>
      The column number within the data file where the error occurred.
      The value \e may be approximate.
    </td>
  </tr>
  <tr>
    <td>\c $zerr:stack-trace</td>
    <td>\c item()?</td>
    <td>
      The function call stack-trace
      leading up to the error.
    </td>
  </tr>
</table>

where the \c zerr prefix
is bound to the namespace \c %http://zorba.io/errors
and "data file" refers to the file that data is being read from,
e.g., the result of reading XML (<tt>fn:doc</tt>) or JSON data.
For example, the query:

\code
declare namespace zerr = "http://zorba.io/errors";

declare function local:bar()
{
  1 div 0
};

declare function local:foo()
{
  local:bar()
};

try 
{
  local:foo()
} catch * {
  $zerr:stack-trace
}
\endcode

returns the following result:

\code
<stack xmlns="http://zorba.io/errors">
  <entry>
    <function namespace="http://www.w3.org/2005/xquery-local-functions" localname="bar" arity="0"/>
    <location name="filename.xq" line-begin="10" line-end="10" column-begin="3" column-end="14"/>
  </entry>
  <entry>
    <function namespace="http://www.w3.org/2005/xquery-local-functions" localname="foo" arity="0"/>
    <location name="filename.xq" line-begin="15" line-end="15" column-begin="3" column-end="14"/>
  </entry>
</stack>
\endcode