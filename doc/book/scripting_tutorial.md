# XQuery Scripting Tutorial

Zorba includes its own scripting capabilities. This page gives an overview of this feature.

## XQuery 3.0, XQuery Update Facility 1.0 (later 3.0)

All valid expressions from XQuery 3.0 as well as XQuery Update Facility 1.0 (with small adaptation changes for XQuery 3.0, anticipating XQUF 3.0) are allowed.

This means that you can write programs like:

```xquery
"Hello, World!"
```

or

```xquery
<current-time>{current-dateTime()}</current-time>
```

or the updating expression

```xquery
insert node <new-node/> into doc("file.xml")/root
```

and these programs have the exact same semantics as specified in XQuery 3.0 and XQuery Update Facility 1.0.

## Side effects
In XQuery 3.0 or XQUF 1.0, an expression never has any side effects other than constructing new nodes (not even updating expressions, which merely produce a pending update list).

Zorba Scripting programs may have side effects. Side effects can be made with statements. In a nutshell, statements can be recognized in that they use semi-colons -- just like in C++ or Java. And they can be written in a natural way -- just like in C++ or Java.

Statements are executed in the order in which they are written.

Let us take the following document `file.xml` as an example:

```xquery
<root><node/></root>
```

In the following XQuery Update query:

```xquery
delete node doc("file.xml")/root/node,
insert node doc("file.xml")/root/node into doc("file2.xml")/root
```

pending updates are accumulated against a given snapshot (the original document) and are only applied at the end. Both subexpressions see the same unaltered document

```xquery
<root><node/></root>
```

Now, consider the following scripting program, which consists of two statements (they have semi-colons):

```xquery
delete node doc("file.xml")/root/node;
insert node doc("file.xml")/root/node into doc("file2.xml")/root;
```

The first statement (delete) is executed against the original document:

```xquery
<root>
  <node/>
</root>
```

Its execution has the side effect of deleting the node named "node".
This means that the second statement (insert) will see the following document:

```xquery
<root></root>
```

As a result, nothing will be inserted into file2.xml, as

```xquery
doc("file.xml")/root/node
```

will evaluate to the empty sequence.

## Control flow

The control flow of statements can be controlled in a way very similar to that of imperative programming languages like C++ or Java (while retaining some XQuery spirit in the exact syntax).

### While statements

For example, Zorba Scripting introduces while loops. The following query:

```xquery
while (doc("file.xml")/root/*)
  delete node doc("file.xml")/root/*[1];
```

repeatedly deletes the first child of the root node, until it has no more children.

### Conditional statements

Zorba Scripting also allows using conditional or FLWOR statements. The following query:

```xquery
if (count(doc("file.xml")/root/*) > 2)
then
  delete node doc("file.xml")/root/*[1];
else
  insert node <node/> as last into doc("file.xml")/root;
```

deletes the first child of the root if it has more than two children, otherwise it inserts a new child. Mind the semi-colons in both the then and the else statement. This is a conditional statement. It has side effects. Both its then and else operands are statements. Both operands are required.

### FLWOR statements

Now, consider the following FLWOR statement:

```xquery
for $x in 1 to 5
return
  insert node <node>{$x}</node> as first into doc("file.xml")/root;
```

which works very much like a C++ for: for each value of $x between 1 and 5, a new node is inserted as the first child of the root. Each execution of the operand statement for a value of $x sees the previously inserted children. This means that the resulting document will look like:

```xquery
<root>
  <node>5</node>
  <node>4</node>
  <node>3</node>
  <node>2</node>
  <node>1</node>
  <node/>
</root>
```

### Other kinds of control flow statements

Zorba Scripting also defines switch statements, typeswitch statements and try-catch statements. It reuses the existing XQuery 3.0 syntax... but with semi-colons.

## Where to put the semi-colon?

Put in a nutshell: in control flow constructs, just like in C++, the semi-colons "stick" to the operands, not to the entire control flow construct. While conditional statements and FLWOR statements look a lot like conditional expressions and FLWOR expressions, they are different in that their operands are statements. They must use semi-colons. All of them.

This is a conditional statement:

```xquery
if (count(doc("file.xml")/root/*) > 2)
then
  delete node doc("file.xml")/root/*[1];
else
  insert node <node/> as last into doc("file.xml")/root;
```

This is a conditional expression:

```xquery
if (count(doc("file.xml")/root/*) > 2)
then
  delete node doc("file.xml")/root/*[1]
else
  insert node <node/> as last into doc("file.xml")/root
```

The following is incorrect, because the then operand is an expression, whereas the else operand is a statement:

```xquery
if (count(doc("file.xml")/root/*) > 2)
then
  delete node doc("file.xml")/root/*[1]
else
  insert node <node/> as last into doc("file.xml")/root;
```

If you really want the semi-colon to be bound to the entire conditional construct, you need parentheses:

```xquery
(if (count(doc("file.xml")/root/*) > 2)
then
  delete node doc("file.xml")/root/*[1]
else
  insert node <node/> as last into doc("file.xml")/root);
```

For FLWOR statements too, the semi-colon "sticks" to the return statement. If you want to accumulate the updates instead, i.e., bind the semi-colon to the entire FLWOR construct, you need parentheses:

```xquery
(for $x in 1 to 5
return
  insert node <node>{$x}</node> as first into doc("file.xml")/root);
```

Note however than the order of insertion is no longer guaranteed.
Further explanations about expressions vs. statements are given further down on this page.

## Block statements

Like in C++, several statements can be concatenated and put inside a curly-braced block (just like expressions can be concatenated with commas and put inside parentheses!):

```xquery
{
  delete node doc("file.xml")/root/node;
  insert node doc("file.xml")/root/node into doc("file2.xml")/root;
}
```

Such blocks, which contain a series of statements, are themselves also statements and can be used wherever statements are allowed - for example in a conditional statement:

```xquery
if (doc("file.xml")/root/*)
then {
  delete node doc("file.xml")/root/node;
  insert node doc("file.xml")/root/node into doc("file2.xml")/root;
}
else
  insert node doc("file.xml")/root/node into doc("file2.xml")/root;
```

Keep in mind that semi-colons and curly braces work just like in C++ when you are dealing with statements.
Block statements can be empty:

```xquery
{}
```

Conditional statements (and while statements, FLWOR statements, block statements ...) are themselves statements and can also be concatenated with other statements:

```xquery
{
  do-some-initialization();
  if (doc("file.xml")/root/*)
  then {
    delete node doc("file.xml")/root/node;
  }
  else {}
  insert node doc("file.xml")/root/node into doc("file2.xml")/root;
}
```

Again, just like in C++, you get the idea.

## Variables

Zorba Scripting allows you to declare and assign variables.
An example is better than a thousand words, so here is a query which computes the first 100 integers in the Fibonacci sequence:

```xquery
variable $a as xs:integer := 0; (: this is a variable declaration statement :)
variable $b as xs:integer := 1;  
variable $c as xs:integer := $a + $b;
variable $fibseq as xs:integer* := ($a, $b);

while ($c < 100) { 
  $fibseq := ($fibseq, $c); (: this is a variable assignment statement :)
  $a := $b;
  $b := $c;
  $c := $a + $b;
}
```

Note that a main program does not need to be a block or a single statement: it can consist of several statements.

## Combining expressions and statements

### Differences between expressions and statements

Put shortly, an expression returns a sequence of items (and possibly a pending update list). A statements does not return anything. It does something. Sometimes, doing something might require getting a result from an expression. Sometimes, computing a result requires doing something. Sometimes, one might even want to both do something and return a result. This part explains how to mix statements and expressions.

### Expressions nested in statements

You already know that expressions can be put inside statements. We gave the example of a conditional expression inside a statement, using parentheses:

```xquery
(if (count(doc("file.xml")/root/*) > 2)
then
  delete node doc("file.xml")/root/*[1]
else
  insert node <node/> as last into doc("file.xml")/root);
```

Another example is the condition expression of a conditional statement, which is always an expression.

### Statements inside expressions: node constructors

There is one most prominent location where statements can be very useful.
If you remember PHP, it allows executing instructions, and declaratively outputing some HTML.
With Zorba Scripting, statements can be used in element constructors, giving it some PHP taste.
In the following example, the element constructor contains a series a statements followed by a single expression which constructs (and returns) the body of the page.

```xquery
<html xmlns="http://www.w3.org/1999/xhtml">
  <head>
    <title>Blog entry added</title>
  </head>
  {
    variable $user := replace($request/url, "^http://.*/([^/]+)/add$", "$1");
    variable $blog := collection()/micro-blog[@user = $user];

    if($blog) then {} else
      exit returning local:error("Unknown user");

    insert node
      <entry timestamp="{ current-dateTime() }">
        <text>{ data($request/param[@name = "text"]) }</text>
      </entry>
    as last into $blog;

    <body>
      <h1>Blog entry added for { $user }</h1>
      <p>{ data($request/param[@name = "text"]) }</p>
    </body>
  }
</html>
```

While it contains statements, the outer construct is still an expression (it returns a value: the HTML page), but it has side effects (updating the database...). Such an expression is called a sequential expression.

In short, an expression is sequential if it contains statements that have side effects (updating some XML, assigning a variable in scope outside of the expression) or that affect the control flow (break, continue, exit returning) - or if it calls a sequential function.

### Do-do-do-do-deliver

This pattern of having, in a block, several statements followed by a single expression is the most general way of using statements together with expressions. The main program is built that way: it can be a single expression, it can be several statements followed by a single expression, or it can be just several statements (in which case it is as if the final expression were empty).

A function body works exactly the same way. Note that if the body expression of a function is sequential, the function must be annotated as %sequential.

### Pitfall: block statements, block expressions

It is also possible to have several statements followed by an expression inside curly braces (with no node constructor). This is called a block expression.

Distinguishing block statements and block expressions is done by looking whether it ends with a statement or an expression.
As a rule of thumb, anything (valid) that ends neither with a semi-colon or a closing curly-brace is an expression. If there is no semi-colon or opening curly brace before the closing curly braces, it is also an expression. Which means you cannot concatenate something else after it!

As a last piece of advice, if the parser complains while you are writing a scripting program, there can be two main kind of errors: either you are trying to mix expressions and statements suboperands, which is not allowed (for example in a conditional statement or expression - **remember that the semi-colon sticks to an operand, not to the entire control flow construct**). Or if you got this right, it might be that you are trying to concatenate something after an expression. In both cases, **it is very likely that you wrote a block expression where you meant to use a block statement** (see criterion above). In this case, you probably just forgot a semi-colon.

XQuery is very powerful and expressive. As in C++, modularizing your programs in small functions will dramatically reduce development time while improving readability.

### Scripting Warnings
The compiler may report warnings to report scripting constructions which are not inherently erroneous but which are risky or suggest there may have been an error (also see [Errors and Warnings](errors_and_warnings.md]).

#### ZWST0004
This is a warning to draw attention to the fact that when FOR clauses or LET clauses that are nested inside FOR clauses have a sequential domain expression, then one can think of two different evaluation semantics of the corresponding FLWOR expression.
Both semantics are correct, but they are not equivalent.
Zorba adopts one of these semantics.
The warning is there to alert users who write such FLWOR expressions that what they may have in mind as the way these FLWORs will be evaluated may not be the same as the way Zorba actually evaluates them.

### Disabling Scripting Support 

By default, Zorba comes with support for scripting.
However, it might make sense to disable this feature.
For example, if you want to make sure that a module does not need any scripting features because it would not be compatible with other XQuery processors.

The following prolog option can be used to disable the scripting feature.

```xquery
  declare namespace op = "http://zorba.io/options/features";

  declare option op:disable "scripting";
```
