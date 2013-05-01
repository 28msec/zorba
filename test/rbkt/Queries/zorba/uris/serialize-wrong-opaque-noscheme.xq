import module namespace uri = "http://www.zorba-xquery.com/modules/uri";

let $wrong-opaque-noscheme-json := 
   {
     "opaque-part" : "myfile.xml"
   }

return uri:serialize($wrong-opaque-noscheme-json)
