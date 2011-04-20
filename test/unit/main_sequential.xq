import module namespace http = "http://nonamespace.com" at "file:///${CMAKE_CURRENT_BINARY_DIR}/main_sequential.xqlib";

import schema namespace https = 'http://expath.org/ns/http-client';

let $request := <https:request method="GET" href="blubb"/>
let $href := "blubb"
let $bodies := ()
return
  if (http:check-params($request, $href, $bodies))
  then
    block
    {
      declare $req := ();
      declare $result := 
                      http:bar((),
                                                "",
                                                ());
      "blubb";
    }
  else 
    ();

