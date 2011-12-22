declare namespace w = "foo:bar";

for sliding window $"foo:bar":w in (1 to 10)
start $"foo:bar":s at $"foo:bar":x previous $"foo:bar":sp next $"foo:bar":sn when true()
end $"foo:bar":e at $"foo:bar":y previous $"foo:bar":ep next $"foo:bar":en when false() 
return <window>{
  string-join (
    for $w:w in ($w:w, $w:s, $w:x, $w:sp, $w:sn, $w:e, $w:y, $w:ep, $w:en)
    return string($w:w), " "
  )}</window>
