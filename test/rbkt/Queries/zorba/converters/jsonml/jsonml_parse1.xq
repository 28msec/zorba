import module namespace jsonml = "http://www.zorba-xquery.com/zorba/json-ml-functions";

jsonml:parse(('[ "ul",
                  [ "li",
                    true],
                  [ "li",
                    {"href":"driving.html", "title":"Driving"},
                    "Second item"],
                  [ "li", null],
                  [ "li", -14]
                  ]', '["table",{"class":"maintable"},
                        ["tr",{"class":"odd"},
                        ["th",{},"Situation"],
                        ["th","Result"], ],
                        ["tr", {"class":"even"},
                        ["td",  ["a",  {"href":"driving.html", "title":"Driving"},"Driving"]],
                        ["td", "Busy"], ], ]'))
