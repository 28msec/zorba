let $next := max(doc("part-tree.xml")//@partid) + 1
  return
    do insert <part partid="{$next}" name="radio"/>
       into 
       doc("part-tree.xml")//part[@partid=0 and @name="car"]

