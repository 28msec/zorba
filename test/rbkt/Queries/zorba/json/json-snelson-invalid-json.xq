import module namespace json = "http://www.zorba-xquery.com/modules/converters/json";

json:parse('[ "ul",
            	[ "li", true],
                  [ "li",
                    {"href":"driving.html", "title":"Driving"},
                    "Second item"],
                  [ "li", null],
                  [ "li", -14e12]')
