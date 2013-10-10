import module namespace np = "http://zorba.io/modules/node-position";

import module namespace ddl = "http://zorba.io/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/dynamic/collections/dml";

ddl:create(xs:QName("ddl:coll"),doc("position.xml")/a);
variable $xx:=dml:collection(xs:QName("ddl:coll"));

ddl:create(xs:QName("ddl:coll2"),doc("position.xml")/a);
variable $yy:=dml:collection(xs:QName("ddl:coll2"));


variable $x :=  doc("position.xml")/a;
insert node <newb><c/></newb> before $x/b[4];
insert node <newb><c/></newb> after $x/b[4];
variable $y :=  element {"x"}{$x}/*;

<result>
  <ancestor-of>
  {
    np:ancestor-of(xs:anyURI(string(np:node-position($x/b[1]))), xs:anyURI(string(np:node-position($x)))),
    np:ancestor-of(xs:anyURI(string(np:node-position($x/b[4]/c[1]))), xs:anyURI(string(np:node-position($x)))),
    np:ancestor-of(xs:anyURI(string(np:node-position($x))), xs:anyURI(string(np:node-position($x/b[1])))),
    np:ancestor-of(xs:anyURI(string(np:node-position($x))), xs:anyURI(string(np:node-position($x/b[4]/c[1])))),
    np:ancestor-of(xs:anyURI(string(np:node-position($x))), xs:anyURI(string(np:node-position($x)))),
    np:ancestor-of(xs:anyURI(string(np:node-position($x/b[1]))), xs:anyURI(string(np:node-position($y)))),
    np:ancestor-of(xs:anyURI(string(np:node-position($xx/b[1]))), xs:anyURI(string(np:node-position($yy))))
  }
  </ancestor-of>
  <following-sibling-of>
  {   
    np:following-sibling-of(xs:anyURI(string(np:node-position($x/b[1]))), xs:anyURI(string(np:node-position($x/b[2])))),
    np:following-sibling-of(xs:anyURI(string(np:node-position($x/b[1]))), xs:anyURI(string(np:node-position($x/newb[1])))),
    np:following-sibling-of(xs:anyURI(string(np:node-position($x/b[2]))), xs:anyURI(string(np:node-position($x/b[1])))),
    np:following-sibling-of(xs:anyURI(string(np:node-position($x))), xs:anyURI(string(np:node-position($x)))),
    np:following-sibling-of(xs:anyURI(string(np:node-position($x/b/@attr))), xs:anyURI(string(np:node-position($x/b/@attr2)))),
    np:following-sibling-of(xs:anyURI(string(np:node-position($x/b/@attr2))), xs:anyURI(string(np:node-position($x/b/@attr)))),
    np:following-sibling-of(xs:anyURI(string(np:node-position($x/b[1]))), xs:anyURI(string(np:node-position($y/b[2])))),
    np:following-sibling-of(xs:anyURI(string(np:node-position($xx/b[1]))), xs:anyURI(string(np:node-position($yy/b[2]))))
  }
  </following-sibling-of>
  <following-of>
  { 
    np:following-of(xs:anyURI(string(np:node-position($x/b[1]))), xs:anyURI(string(np:node-position($x/b[4]/c[1])))),
    np:following-of(xs:anyURI(string(np:node-position($x/b[4]))), xs:anyURI(string(np:node-position($x/b[4]/c[1])))),
    np:following-of(xs:anyURI(string(np:node-position($x/b[4]/c[1]))), xs:anyURI(string(np:node-position($x/b[1])))),
    np:following-of(xs:anyURI(string(np:node-position($x))), xs:anyURI(string(np:node-position($x)))),
    np:following-of(xs:anyURI(string(np:node-position($x/b[1]))), xs:anyURI(string(np:node-position($y/b[4]/c[1])))),
    np:following-of(xs:anyURI(string(np:node-position($xx/b[1]))), xs:anyURI(string(np:node-position($yy/b[4]/c[1]))))
  }
  </following-of>
  <descendant-of>
  {        
    np:descendant-of(xs:anyURI(string(np:node-position($x))), xs:anyURI(string(np:node-position($x/b[1])))),
    np:descendant-of(xs:anyURI(string(np:node-position($x))), xs:anyURI(string(np:node-position($x/b[4]/c[1])))),
    np:descendant-of(xs:anyURI(string(np:node-position($x))), xs:anyURI(string(np:node-position($x/b/@attr)))),
    np:descendant-of(xs:anyURI(string(np:node-position($x/b[1]))), xs:anyURI(string(np:node-position($x)))),
    np:descendant-of(xs:anyURI(string(np:node-position($x/b[4]/c[1]))), xs:anyURI(string(np:node-position($x)))),    
    np:descendant-of(xs:anyURI(string(np:node-position($x))), xs:anyURI(string(np:node-position($x)))),
    np:descendant-of(xs:anyURI(string(np:node-position($x))), xs:anyURI(string(np:node-position($y/b[1])))),
    np:descendant-of(xs:anyURI(string(np:node-position($xx))), xs:anyURI(string(np:node-position($yy/b[1]))))
  }
  </descendant-of>
  <in-subtree-of>
  {        
    np:in-subtree-of(xs:anyURI(string(np:node-position($x))), xs:anyURI(string(np:node-position($x/b[1])))),
    np:in-subtree-of(xs:anyURI(string(np:node-position($x))), xs:anyURI(string(np:node-position($x/b[4]/c[1])))),
    np:in-subtree-of(xs:anyURI(string(np:node-position($x))), xs:anyURI(string(np:node-position($x/b/@attr)))),
    np:in-subtree-of(xs:anyURI(string(np:node-position($x/b[1]))), xs:anyURI(string(np:node-position($x)))),
    np:in-subtree-of(xs:anyURI(string(np:node-position($x/b[4]/c[1]))), xs:anyURI(string(np:node-position($x)))),    
    np:in-subtree-of(xs:anyURI(string(np:node-position($x))), xs:anyURI(string(np:node-position($x)))),
    np:in-subtree-of(xs:anyURI(string(np:node-position($x))), xs:anyURI(string(np:node-position($y/b[1])))),
    np:in-subtree-of(xs:anyURI(string(np:node-position($xx))), xs:anyURI(string(np:node-position($yy/b[1]))))
  }
  </in-subtree-of>
  <preceding-sibling-of>
  { 
    np:preceding-sibling-of(xs:anyURI(string(np:node-position($x/b[2]))), xs:anyURI(string(np:node-position($x/b[1])))),
    np:preceding-sibling-of(xs:anyURI(string(np:node-position($x/b[4]))), xs:anyURI(string(np:node-position($x/newb[1])))),
    np:preceding-sibling-of(xs:anyURI(string(np:node-position($x/b[1]))), xs:anyURI(string(np:node-position($x/b[2])))),
    np:preceding-sibling-of(xs:anyURI(string(np:node-position($x))), xs:anyURI(string(np:node-position($x)))),
    np:preceding-sibling-of(xs:anyURI(string(np:node-position($x/b/@attr))), xs:anyURI(string(np:node-position($x/b/@attr2)))),
    np:preceding-sibling-of(xs:anyURI(string(np:node-position($x/b/@attr2))), xs:anyURI(string(np:node-position($x/b/@attr)))),
    np:preceding-sibling-of(xs:anyURI(string(np:node-position($x/b[2]))), xs:anyURI(string(np:node-position($y/b[1])))),
    np:preceding-sibling-of(xs:anyURI(string(np:node-position($xx/b[2]))), xs:anyURI(string(np:node-position($yy/b[1]))))
  }
  </preceding-sibling-of>
  <preceding-of>
  {
    np:preceding-of(xs:anyURI(string(np:node-position($x/b[4]/c[1]))), xs:anyURI(string(np:node-position($x/b[1])))),
    np:preceding-of(xs:anyURI(string(np:node-position($x/b[1]))), xs:anyURI(string(np:node-position($x/b[4]/c[1])))),
    np:preceding-of(xs:anyURI(string(np:node-position($x/b[4]))), xs:anyURI(string(np:node-position($x/b[4]/c[1])))),    
    np:preceding-of(xs:anyURI(string(np:node-position($x))), xs:anyURI(string(np:node-position($x)))),
    np:preceding-of(xs:anyURI(string(np:node-position($x/b[4]/c[1]))), xs:anyURI(string(np:node-position($y/b[1])))),
    np:preceding-of(xs:anyURI(string(np:node-position($xx/b[4]/c[1]))), xs:anyURI(string(np:node-position($yy/b[1]))))
  }
  </preceding-of>
</result>
