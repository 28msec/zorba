(: test schema-type function with every node type :)

import module namespace schema = "http://www.zorba-xquery.com/modules/schema";

import schema namespace data = "http://www.zorba-xquery.com/schema/test/data" at "schema.xsd";

declare variable $items :=
    (
        document { <root id="main"><content><div>hello world</div></content></root>},
        <element attribute="false"><subelem>hello world</subelem></element>,
        attribute attribute { "hello world" },
        text { "hello text node" },
        processing-instruction pi { "process hello world" },
        comment { "useless comment" },

        (: validated items:)
        validate { document { <data:entry author="tom1" date="{current-date()}" time="{current-time()}">hello world1</data:entry> } },
        validate { <data:entry author="brad1" date="{current-date()}" time="{current-time()}">hello world1</data:entry> },
        validate { <data:age>1</data:age> },
        let $elem := validate { <data:simple data:simple="test" />  } return $elem/@data:simple
    );

<items>
{
    for $item at $pos in $items
    let $type := schema:schema-type($item)
    return 
        <item pos="{$pos}" nodeType="{$type}" />
}
</items>

