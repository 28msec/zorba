declare namespace w = "foo:bar";

for sliding window $Q{foo:bar}w in (1 to 10)
start $Q{foo:bar}s at $Q{foo:bar}x previous $Q{foo:bar}sp next $Q{foo:bar}sn when true()
end $Q{foo:bar}e at $Q{foo:bar}y previous $Q{foo:bar}ep next $Q{foo:bar}en when false() 
return <window>{
  string-join (
    for $w:w in ($w:w, $w:s, $w:x, $w:sp, $w:sn, $w:e, $w:y, $w:ep, $w:en)
    return string($w:w), " "
  )}</window>
