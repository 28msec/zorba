import module namespace json = "http://zorba.io/modules/json-xml";

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
  <options xmlns="http://zorba.io/modules/json-xml-options">
    <json-format value="JsonML-array"/>
  </options>
return json:parse( $json, $options )

(: vim:se et sw=2 ts=2: :)
