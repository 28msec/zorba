copy $x := <twelve/>, $y := <newnode/>
modify ((insert node <newchild/> into $y, insert node $y into $x))
return $x
