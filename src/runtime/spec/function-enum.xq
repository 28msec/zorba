declare namespace zorba="http://www.zorba-xquery.com";

import module namespace util="http://www.zorba-xquery.com/zorba/util-functions";

import module namespace gen = "http://www.zorba-xquery.com/internal/gen" at "utils.xq";

declare variable $file-list as xs:string external;

let $files as xs:string* := tokenize($file-list,';')

let $funcs := distinct-values(
                for $sig in for $doc in $files
                            return doc($doc)//zorba:signature
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
