import module namespace uri = "http://zorba.io/modules/uri";

let $wrong-path-json := 
   {
     "scheme" : "file",
     "path" : "d:/a/b/c"
   }

return uri:serialize($wrong-path-json)
