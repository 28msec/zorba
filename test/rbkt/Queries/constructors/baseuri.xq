declare base-uri "http://x.com/root";

let $t0 := <t/>
let $t := <a><b xml:base="b"><c><d xml:base="http://y.com/">{$t0}</d></c></b></a>
for $n in ($t, $t//*) return base-uri ($n)
