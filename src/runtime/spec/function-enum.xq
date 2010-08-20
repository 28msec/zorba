declare namespace zorba="http://www.zorba-xquery.com";

import module namespace util="http://www.zorba-xquery.com/zorba/util-functions";
import module namespace file = "http://www.zorba-xquery.com/modules/file";
import module namespace gen = "http://www.zorba-xquery.com/internal/gen" at "utils.xq";

declare variable $files as xs:string external;

let $funcs := distinct-values
  (
    for $sig in
      for $doc in tokenize($files,',')
      return file:read-xml($doc)//zorba:signature
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
