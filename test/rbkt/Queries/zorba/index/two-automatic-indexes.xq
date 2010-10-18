(: this test exists to cover bug #3071677 "temporary index declared twice". :)
xquery version "1.0";

declare namespace xq="http://www.xqdoc.org/1.0";

declare function local:print-external-functions-invoked($function as element()) as element()*
{
  let $furis := for $x in distinct-values(for $f in $function/xq:invoked/xq:uri
                                          return string($f))
                order by string($x)
                return string($x)
  for $furi in $furis
  return
       <tr>
        <td valign="top">{$furi}</td>
        <td valign="top">
        {
        let $names := for $y in $function/xq:invoked[string(xq:uri)=$furi]
                      order by string($y/xq:name), xs:integer($y/xq:name/@arity)
                      return $y
        for $name in $names
        return 1
        }
        </td>
       </tr>
};


declare function local:print-internal-functions-invoked($function as element()) as element()*
{
  let $furis := for $x in distinct-values(for $f in $function/xq:invoked/xq:uri
                                          return string($f))
                order by string($x)
                return string($x)
  for $furi in $furis
  return
       <tr>
        <td valign="top">{$furi}</td>
        <td valign="top">
        {
        let $names := for $y in $function/xq:invoked[string(xq:uri)=$furi]
                      order by string($y/xq:name), xs:integer($y/xq:name/@arity)
                      return $y
        for $name in $names
        return 1
        }
        </td>
       </tr>
};


local:print-external-functions-invoked(<foo/>),
local:print-internal-functions-invoked(<bar/>)
