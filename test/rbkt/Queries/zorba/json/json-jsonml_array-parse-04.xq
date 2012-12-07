import module namespace json = "http://www.zorba-xquery.com/modules/converters/json";

let $json := '
  [ "ul",
    [ "li",
      { "style" : "color:red" },
      "First Item"
    ],
    [ "li",
      {
        "title" : "Some hover text.",
        "style" : "color:green"
      },
      "Second Item"
    ],
    [ "li",
      [ "span",
        { "class" : "code-example-third" },
        "Third"
      ],
      " Item"
    ]
  ]'
let $options :=
  <options xmlns="http://www.zorba-xquery.com/modules/converters/json-options">
    <json-format value="JsonML-array"/>
  </options>
return json:parse( $json, $options )

(: vim:se et sw=2 ts=2: :)
