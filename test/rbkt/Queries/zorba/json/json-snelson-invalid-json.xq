import module namespace json = "http://zorba.io/modules/json-xml";

json:parse('[ "ul",
            	[ "li", true],
                  [ "li",
                    {"href":"driving.html", "title":"Driving"},
                    "Second item"],
                  [ "li", null],
                  [ "li", -14e12]')
