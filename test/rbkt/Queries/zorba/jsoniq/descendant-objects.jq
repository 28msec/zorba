jsoniq version "1.0";

declare function local:descendant-objects($i as json-item) as object*
{
 typeswitch($i)
 case object return (
     $i,
     for $k in keys($i)
     let $v := $i.$k
     where $v instance of json-item
     return local:descendant-objects($v)
   )
 case array return (
     for $v in $i()
     where $v instance of json-item
     return local:descendant-objects($v)
   )
 default return ()
};

let $o := (
  { "foo" : 42, "bar" : { "blub" : 23 } },
  { "foo" : 42, "bar" : { "42" : 23 } })
return
distinct-values($o ! local:descendant-objects($$) ! $$())
