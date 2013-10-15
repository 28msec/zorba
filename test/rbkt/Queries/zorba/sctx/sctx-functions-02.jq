jsoniq version "1.0";

import module namespace file = "http://expath.org/ns/file";
import module namespace sctx = "http://zorba.io/modules/sctx";

for $f in sctx:functions()
where exists( $f.annotations )
order by namespace-uri-from-QName($f.name),
         local-name-from-QName($f.name),
         $f.arity
return $f


(: vim:set syntax=xquery et sw=2 ts=2: :)
