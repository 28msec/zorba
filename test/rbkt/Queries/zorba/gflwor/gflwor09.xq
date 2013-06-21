let $seq := for $i in 1 to 10 return <foo attribute="{$i}">{$i}</foo>
for $child in $seq[1]/node()
where not(fn:empty($child/text()))
let $name := fn:name($child)
return
  if (fn:count($seq/node()[fn:name(.) = $name]) eq 10) then $name else ()
