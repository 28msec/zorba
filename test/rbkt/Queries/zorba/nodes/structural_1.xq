import module namespace ref = "http://www.zorba-xquery.com/modules/node-information";


variable $x :=  doc("structural.xml")/a;
insert node <newb><c/></newb> before $x/b[4];
insert node <newb><c/></newb> after $x/b[4];
variable $y :=  element {"x"}{$x}/*;

<result>
  <ancestor-of>
  {
    ref:ancestor-of(ref:node-information($x/b[1]), ref:node-information($x)),
    ref:ancestor-of(ref:node-information($x/b[4]/c[1]), ref:node-information($x)),
    ref:ancestor-of(ref:node-information($x), ref:node-information($x/b[1])),
    ref:ancestor-of(ref:node-information($x), ref:node-information($x/b[4]/c[1])),
    ref:ancestor-of(ref:node-information($x), ref:node-information($x)),
    ref:ancestor-of(ref:node-information($x/b[1]), ref:node-information($y))
  }
  </ancestor-of>
  <following-sibling-of>
  {   
    ref:following-sibling-of(ref:node-information($x/b[1]), ref:node-information($x/b[2])),
    ref:following-sibling-of(ref:node-information($x/b[1]), ref:node-information($x/newb[1])),
    ref:following-sibling-of(ref:node-information($x/b[2]), ref:node-information($x/b[1])),
    ref:following-sibling-of(ref:node-information($x), ref:node-information($x)),
    ref:following-sibling-of(ref:node-information($x/b/@attr), ref:node-information($x/b/@attr2)),
    ref:following-sibling-of(ref:node-information($x/b/@attr2), ref:node-information($x/b/@attr)),
    ref:following-sibling-of(ref:node-information($x/b[1]), ref:node-information($y/b[2]))
  }
  </following-sibling-of>
  <following-of>
  { 
    ref:following-of(ref:node-information($x/b[1]), ref:node-information($x/b[4]/c[1])),
    ref:following-of(ref:node-information($x/b[4]), ref:node-information($x/b[4]/c[1])),
    ref:following-of(ref:node-information($x/b[4]/c[1]), ref:node-information($x/b[1])),
    ref:following-of(ref:node-information($x), ref:node-information($x)),
    ref:following-of(ref:node-information($x/b[1]), ref:node-information($y/b[4]/c[1]))
  }
  </following-of>
  <descendant-of>
  {        
    ref:descendant-of(ref:node-information($x), ref:node-information($x/b[1])),
    ref:descendant-of(ref:node-information($x), ref:node-information($x/b[4]/c[1])),
    ref:descendant-of(ref:node-information($x/b[1]), ref:node-information($x)),
    ref:descendant-of(ref:node-information($x/b[4]/c[1]), ref:node-information($x)),    
    ref:descendant-of(ref:node-information($x), ref:node-information($x)),
    ref:descendant-of(ref:node-information($x), ref:node-information($y/b[1]))
  }
  </descendant-of>
  <preceding-sibling-of>
  { 
    ref:preceding-sibling-of(ref:node-information($x/b[2]), ref:node-information($x/b[1])),
    ref:preceding-sibling-of(ref:node-information($x/b[4]), ref:node-information($x/newb[1])),
    ref:preceding-sibling-of(ref:node-information($x/b[1]), ref:node-information($x/b[2])),
    ref:preceding-sibling-of(ref:node-information($x), ref:node-information($x)),
    ref:preceding-sibling-of(ref:node-information($x/b/@attr), ref:node-information($x/b/@attr2)),
    ref:preceding-sibling-of(ref:node-information($x/b/@attr2), ref:node-information($x/b/@attr)),
    ref:preceding-sibling-of(ref:node-information($x/b[2]), ref:node-information($y/b[1]))
  }
  </preceding-sibling-of>
  <preceding-of>
  {
    ref:preceding-of(ref:node-information($x/b[4]/c[1]), ref:node-information($x/b[1])),
    ref:preceding-of(ref:node-information($x/b[1]), ref:node-information($x/b[4]/c[1])),
    ref:preceding-of(ref:node-information($x/b[4]), ref:node-information($x/b[4]/c[1])),    
    ref:preceding-of(ref:node-information($x), ref:node-information($x)),
    ref:preceding-of(ref:node-information($x/b[4]/c[1]), ref:node-information($y/b[1]))
  }
  </preceding-of>
</result>   
