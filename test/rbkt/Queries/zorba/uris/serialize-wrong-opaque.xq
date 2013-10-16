import module namespace uri = "http://zorba.io/modules/uri";

let $wrong-opaque-json := 
   {
     "scheme" : "http",
     "opaque-part" : "myfile.xml",
     "path" : "d:/a/b/c"
   }

return uri:serialize($wrong-opaque-json)
