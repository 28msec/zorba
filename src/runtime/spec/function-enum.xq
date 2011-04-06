declare namespace zorba="http://www.zorba-xquery.com";

import module namespace file = "http://www.zorba-xquery.com/modules/file";
import module namespace gen = "http://www.zorba-xquery.com/internal/gen" at "utils.xq";

declare variable $files as xs:string external;

declare variable $signatures := 
    for $doc in tokenize($files,',')
    return fn:parse-xml(file:read-text($doc))//zorba:signature;

let $funcs := 
    distinct-values(
                for $sig in $signatures
                return gen:function-kind($sig)
    )
return
  string-join(
    (
      gen:add-copyright(),
      for $func at $i in $funcs
      return concat($gen:indent, $func, ','),
      $gen:newline,
      $gen:newline
    ),
    $gen:newline)
