import module namespace json = "http://www.zorba-xquery.com/modules/convertors/json";
import schema namespace html-options="http://www.zorba-xquery.com/modules/convertors/json-options";

json:parse(('
["table",
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
]'),<options xmlns="http://www.zorba-xquery.com/modules/convertors/json-options" >
              <jsonParam name="mapping" value="json-ml" />
            </options>)
