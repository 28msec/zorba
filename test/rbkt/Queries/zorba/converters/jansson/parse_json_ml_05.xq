import module namespace json = "http://www.zorba-xquery.com/modules/convertors/json";
import schema namespace html-options="http://www.zorba-xquery.com/modules/convertors/json-options";

json:parse-ml(('
["ul",
  ["li",
  { "style" : "color:red" },
  "First Item"
  ],
  ["li",
  {
  "title" : "Some hover text.",
  "style" : "color:green"
  },
  "Second Item"
  ],
  ["li",
    ["span",
    { "class" : "code-example-third" },
    "Third"
    ],
  " Item"
  ]
]'))