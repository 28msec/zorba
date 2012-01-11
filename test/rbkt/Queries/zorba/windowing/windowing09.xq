for $x in (1,2)
for sliding window $w in (1,2,3,1,2,3)
  start $s when $s eq $x
  end next $e when $e eq $x
return <w x="{$x}" s="{$s}" e="{$e}">{$w}</w>
