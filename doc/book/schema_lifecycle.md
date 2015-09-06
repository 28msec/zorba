# Schema Lifecycle

## Introduction
This page is a quick presentation on how to use Zorba with XMLSchema type 
information.

## Overview
Zorba supports <a href="http://www.w3.org/TR/xmlschema11-1/">W3C XML Schema 
(XSD) 1.1</a> including dateTimeStamp, +/-0, +/-INF. But due to the missing support 
from Xerces-C validation is still using only XSD 1.0, which is compatible with 
XSD 1.1 for the vast majority of the features with a few exceptions. Check out
 <a href="http://www.w3.org/TR/xmlschema11-1/#changes">the full list</a>.


## How to import a schema
In order to use XMLSchema type information in a query a schema file needs to be imported.
Note the URI must match the target namespace of schema file.

```xquery
import schema namespace r = "http://example" at "example.xsd";
```

For a full example see the example below.

Note: for simplicity, the examples on this page make use of the "at <filename>" 
clause of `import schema` to explicitly load a specific schema file.
However, when developing applications, it is usually better to omit this
 clause, and make use of Zorba's extensive URI-resolution mechanisms to load
 schema documents by URI. For details on this, see [URI resolvers](uriresolvers.md).

## Validate expression
Use validate expression to validate an untyped document against an XMLSchema.

```xquery
validate {$untypeDoc}
```

For a full example see the example below.

## Example 1

The script *example.xq*:
```xquery
import schema namespace r = "http://example" at "example.xsd";

import module namespace file = "http://expath.org/ns/file";

let $untypeDoc := fn:parse-xml(file:read-text("example.xml"))
let $validatedDoc := validate {$untypeDoc}
return
  $validatedDoc
```

Assuming there is an <tt>example.xsd</tt> file with this content:

```xml
<xs:schema xmlns:xs="http://www.w3.org/2001/XMLSchema" 
  targetNamespace="http://example" 
  xmlns="http://example"
  elementFormDefault="qualified" attributeFormDefault="unqualified">

  <xs:element name="a" type="TypeA"/>

  <xs:complexType name="TypeA">
    <xs:sequence>
      <xs:element name="b" maxOccurs="unbounded" type="xs:string"/>
    </xs:sequence>
  </xs:complexType>

</xs:schema>
```

And this *example.xml* instance XML document:

```xml
<a xmlns="http://example">
  <b>Hello world!</b>
</a>
```

Zorba can execute the query to get the result:
```bash
$ zorba --trailing-nl -i -f -q example.xq 
<?xml version="1.0" encoding="UTF-8"?>
<a xmlns="http://example">
  <b>Hello world!</b>
</a>
```

## Schema type name

Using the <a href="/modules/latest/www.zorba-xquery.com/modules/schema">schema module</a>
it is possible to find out the QName of a certain schema type.

The example can be adapted to the following:
```xquery
import schema namespace r = "http://example" at "example.xsd";

import module namespace file = "http://expath.org/ns/file";
import module namespace schema = "http://zorba.io/modules/schema";


let $untypeDoc := fn:parse-xml(file:read-text("example.xml"))
let $validatedDoc := validate {$untypeDoc}
return
  let $qname := schema:schema-type($validatedDoc/r:a)
  return
    (
      fn:prefix-from-QName($qname),
      fn:local-name-from-QName($qname),
      fn:namespace-uri-from-QName($qname)
    )
```

Output:
```bash
$ zorba --trailing-nl -i -f -q example.xq 
<?xml version="1.0" encoding="UTF-8"?>
TypeA http://example
```

## Validate using the C++ Zorba API
The C++ Zorba API can be used by an application to validate a document and 
later passed as a valid input into another query.

In the example below the loadProlog method on the static context was used to import the required schema file and than validate method was called to get the new validated item.

```cpp
  sc->loadProlog("import schema namespace s='http://test.org' at 'schema.xsd';", hints);
```

```cpp
  sc->validate(lChild, vItem);
```


## Example 2
```cpp
#include <iostream>
#include <sstream>

#include <zorba/zorba.h>
#include <zorba/store_manager.h>
#include <zorba/serializer.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/zorba_exception.h>

using namespace zorba;

void printItem(Item& lChild, String pre);
void printIter(Iterator_t lIter, String pre);


void printIter(Iterator_t lIter, String pre)
{
  lIter->open();
  Item lChild;
  while (lIter->next(lChild))
  {
    printItem(lChild, pre);
  }
  lIter->close();
}


void printItem(Item& lChild, String pre)
{
  Item lNodeName;
  lChild.getNodeName(lNodeName);
  std::cout << pre << "node " << lNodeName.getStringValue() <<
      "   -type " << lChild.getType().getStringValue() << std::endl;
  Iterator_t lAttrIter = lChild.getAttributes();

  lAttrIter->open();

  Item lAttr;
  while (lAttrIter->next(lAttr))
  {
    Item lNodeName;
    lAttr.getNodeName(lNodeName);
    std::cout << pre << "  @" << lNodeName.getStringValue() << "=" << lAttr.getStringValue() <<
        "   -type " << lAttr.getType().getStringValue() << std::endl;
  }
  lAttrIter->close();

  Iterator_t lChildIter = lChild.getChildren();
  printIter(lChildIter, pre + "  ");
}


bool example_12(Zorba* aZorba)
{
  // without validation
  String query = "<a xmlns='http://test.org'><b attr='1'/><b attr='2'/></a>";
  XQuery_t lQuery1 = aZorba->compileQuery(query);

  Iterator_t lIterator1 = lQuery1->iterator();
  printIter(lIterator1, "  ");


  //with validation
  XQuery_t lQuery2 = aZorba->compileQuery(query);
  Iterator_t lIterator2 = lQuery2->iterator();

  lIterator2->open();
  Item lChild;
  lIterator2->next(lChild);

  StaticContext_t sc = aZorba -> createStaticContext();
  const Zorba_CompilerHints_t hints;
  sc->loadProlog("import schema namespace s='http://test.org' at 'schema.xsd';", hints);

  Item vItem;
  std::cout << "Validate: " <<std::endl; std::cout.flush();
  bool vres = sc->validate(lChild, vItem);
  std::cout << "  res  : " << (vres ? "true" : "false") << std::endl; std::cout.flush();


  printItem(vItem, "  ");
  lIterator2->close();

  return true;
}

int main(int argc, char **argv)
{
  std::cout << "Start" << std::endl; std::cout.flush();

  void* lStore = StoreManager::getStore();
  Zorba *lZorba = Zorba::getInstance(lStore);

  bool res = false;


  std::cout << "executing example 12" << std::endl;
  res = example_12(lZorba);
  if (!res) return 1;
  std::cout << std::endl;


  lZorba->shutdown();
  StoreManager::shutdownStore(lStore);

  std::cout << "Done!" << std::endl; std::cout.flush();
  return 0;
}
```

Output:
```bash
Start
executing example 12
  node a   -type xs:anyType
    node b   -type xs:anyType
      @attr=1   -type xs:untypedAtomic
    node b   -type xs:anyType
      @attr=2   -type xs:untypedAtomic
Validate:
  res  : true
  node a   -type __AnonC2
    node b   -type __AnonC3
      @attr=1   -type xs:int
    node b   -type __AnonC3
      @attr=2   -type xs:int
```