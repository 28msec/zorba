declare updating function 
             local:delete-subtree($p as element(part))
  {
      for $child in doc("part-list.xml")//part
      where $p/@partid eq $child/@partof
      return local:delete-subtree($child)
      ,
      do delete $p
  };

for $p in doc("part-tree.xml")//part[@name="car"]/part
return 
  local:delete-subtree($p)
