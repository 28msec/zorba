import module namespace jx = "http://zorba.io/modules/json-xml";

let $json := '["table",
{
"class" : "MyTable",
"style" : "background-color:yellow"
},
["tr",
["td",
{
"class" : "MyTD",
"style" : "border:1px solid black"
},
"#550758"
],
["td",
{
"class" : "MyTD",
"style" : "background-color:red"
},
"Example text here"
]
],
["tr",
["td",
{
"class" : "MyTD",
"style" : "border:1px solid black"
},
"#993101"
],
["td",
{
"class" : "MyTD",
"style" : "background-color:green"
},
"127624015"
]
],
["tr",
["td",
{
"class" : "MyTD",
"style" : "border:1px solid black"
},
"#E33D87"
],
["td",
{
"class" : "MyTD",
"style" : "background-color:blue"
},
"\u00A0",
["span",
{ "style" : "background-color:maroon" },
"\u00A9"
],
"\u00A0"
]
]
]'
let $options := { "json-format" : "JsonML-array" }
return jx:json-string-to-xml( $json, $options )

(: vim:se et sw=2 ts=2: :)
