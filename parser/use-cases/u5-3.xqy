for $pt in doc("part-tree.xml")//part[@name="car"]/part, 
    $pl in doc("part-list.xml")//part
where $pt/@partid eq $pl/@partid
return 
  do delete $pl
