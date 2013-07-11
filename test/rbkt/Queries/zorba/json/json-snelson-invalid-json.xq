import module namespace jx = "http://zorba.io/modules/json-xml";

jx:json-to-xml('[ "ul",
            	[ "li", true],
                  [ "li",
                    {"href":"driving.html", "title":"Driving"},
                    "Second item"],
                  [ "li", null],
                  [ "li", -14e12]')
