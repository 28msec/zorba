import module namespace ref = "http://www.zorba-xquery.com/modules/node-structural-information";
import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

ddl:create(xs:QName("ddl:coll"),<dummy/>);
variable $xx:=dml:collection(xs:QName("ddl:coll"));

ddl:create(xs:QName("ddl:coll2"),<dummy/>);
variable $yy:=dml:collection(xs:QName("ddl:coll2"));

insert node <b/> into $xx;
insert node <bb/> into $xx/b;
insert node <b2/> into $xx;
insert node <bb2/> into $xx/b2;

insert node <b/> into $yy;
insert node <bb/> into $yy/b;
insert node <b2/> into $yy;
insert node <bb2/> into $yy/b2;

variable $x :=  doc("structural.xml")/a;
insert node <newb><c/></newb> before $x/b[4];
insert node <newb><c/></newb> after $x/b[4];
variable $y :=  element {"x"}{$x}/*;

<result>
  <child-of>
  {
    ref:child-of(xs:anyURI(string(ref:node-structural-information($x))), xs:anyURI(string(ref:node-structural-information($x/b[1])))),
    ref:child-of(xs:anyURI(string(ref:node-structural-information($x))), xs:anyURI(string(ref:node-structural-information($x/newb[1])))),
    ref:child-of(xs:anyURI(string(ref:node-structural-information($x))), xs:anyURI(string(ref:node-structural-information($x/b[4]/c[1])))),
    ref:child-of(xs:anyURI(string(ref:node-structural-information($x/b[1]))), xs:anyURI(string(ref:node-structural-information($x)))),
    ref:child-of(xs:anyURI(string(ref:node-structural-information($x/b[4]/c[1]))), xs:anyURI(string(ref:node-structural-information($x)))),    
    ref:child-of(xs:anyURI(string(ref:node-structural-information($x))), xs:anyURI(string(ref:node-structural-information($x)))),
    ref:child-of(xs:anyURI(string(ref:node-structural-information($x/b[1]))), xs:anyURI(string(ref:node-structural-information($y))))
  }
  </child-of>
  <attribute-of>
  {
    ref:attribute-of(xs:anyURI(string(ref:node-structural-information($x/b[4]))), xs:anyURI(string(ref:node-structural-information($x/b[4]/@attr)))),
    ref:attribute-of(xs:anyURI(string(ref:node-structural-information($x/b[4]))), xs:anyURI(string(ref:node-structural-information($x/b[4]/c/@attr)))),
    ref:attribute-of(xs:anyURI(string(ref:node-structural-information($x/b[4]/@attr))), xs:anyURI(string(ref:node-structural-information($x/b[4])))),
    ref:attribute-of(xs:anyURI(string(ref:node-structural-information($x/b[4]/c/@attr))), xs:anyURI(string(ref:node-structural-information($x/b[4])))),    
    ref:attribute-of(xs:anyURI(string(ref:node-structural-information($x))), xs:anyURI(string(ref:node-structural-information($x/b[1])))),
    ref:attribute-of(xs:anyURI(string(ref:node-structural-information($x))), xs:anyURI(string(ref:node-structural-information($x/newb[1])))),    
    ref:attribute-of(xs:anyURI(string(ref:node-structural-information($x/b[4]/@attr))), xs:anyURI(string(ref:node-structural-information($x/b[4]/@attr)))),
    ref:attribute-of(xs:anyURI(string(ref:node-structural-information($x/b[4]))), xs:anyURI(string(ref:node-structural-information($y/b[4]/@attr))))
  }
  </attribute-of>
  <parent-of>
  { 
    ref:parent-of(xs:anyURI(string(ref:node-structural-information($x/b[1]))), xs:anyURI(string(ref:node-structural-information($x)))),
    ref:parent-of(xs:anyURI(string(ref:node-structural-information($x/newb[1]))), xs:anyURI(string(ref:node-structural-information($x)))),
    ref:parent-of(xs:anyURI(string(ref:node-structural-information($x/b[4]/c[1]))), xs:anyURI(string(ref:node-structural-information($x)))),
    ref:parent-of(xs:anyURI(string(ref:node-structural-information($x))), xs:anyURI(string(ref:node-structural-information($x/b[1])))),
    ref:parent-of(xs:anyURI(string(ref:node-structural-information($x))), xs:anyURI(string(ref:node-structural-information($x/b[4]/c[1])))),        
    ref:parent-of(xs:anyURI(string(ref:node-structural-information($x))), xs:anyURI(string(ref:node-structural-information($x)))),
    ref:parent-of(xs:anyURI(string(ref:node-structural-information($x/b[1]))), xs:anyURI(string(ref:node-structural-information($y))))
  }
  </parent-of>
  <preceding-in-document-order-of>
  {
    ref:preceding-in-document-order-of(xs:anyURI(string(ref:node-structural-information($x/b[4]/@attr))), xs:anyURI(string(ref:node-structural-information($x/b[1])))),
    ref:preceding-in-document-order-of(xs:anyURI(string(ref:node-structural-information($x/b[4]/c[1]))), xs:anyURI(string(ref:node-structural-information($x/b[1])))),
    ref:preceding-in-document-order-of(xs:anyURI(string(ref:node-structural-information($x/b[4]/c[1]))), xs:anyURI(string(ref:node-structural-information($x/b[4])))),
    ref:preceding-in-document-order-of(xs:anyURI(string(ref:node-structural-information($y))), xs:anyURI(string(ref:node-structural-information($x)))),
    ref:preceding-in-document-order-of(xs:anyURI(string(ref:node-structural-information($x))), xs:anyURI(string(ref:node-structural-information($y)))),
    ref:preceding-in-document-order-of(xs:anyURI(string(ref:node-structural-information($x))), xs:anyURI(string(ref:node-structural-information($x)))),
    ref:preceding-in-document-order-of(xs:anyURI(string(ref:node-structural-information($x/b[1]))), xs:anyURI(string(ref:node-structural-information($x/b[4]/@attr)))),
    ref:preceding-in-document-order-of(xs:anyURI(string(ref:node-structural-information($x/b[1]))), xs:anyURI(string(ref:node-structural-information($x/b[4]/c[1])))),
    ref:preceding-in-document-order-of(xs:anyURI(string(ref:node-structural-information($x/b[4]))), xs:anyURI(string(ref:node-structural-information($x/b[4]/c[1]))))
  }
  </preceding-in-document-order-of>
  <following-in-document-order-of>
  {
    ref:following-in-document-order-of(xs:anyURI(string(ref:node-structural-information($x/b[1]))), xs:anyURI(string(ref:node-structural-information($x/b[4]/@attr)))),
    ref:following-in-document-order-of(xs:anyURI(string(ref:node-structural-information($x/b[1]))), xs:anyURI(string(ref:node-structural-information($x/b[4]/c[1])))),
    ref:following-in-document-order-of(xs:anyURI(string(ref:node-structural-information($x/b[4]))), xs:anyURI(string(ref:node-structural-information($x/b[4]/c[1])))),
    ref:following-in-document-order-of(xs:anyURI(string(ref:node-structural-information($x))), xs:anyURI(string(ref:node-structural-information($y)))),
    ref:following-in-document-order-of(xs:anyURI(string(ref:node-structural-information($y))), xs:anyURI(string(ref:node-structural-information($x)))),
    ref:following-in-document-order-of(xs:anyURI(string(ref:node-structural-information($x))), xs:anyURI(string(ref:node-structural-information($x)))),
    ref:following-in-document-order-of(xs:anyURI(string(ref:node-structural-information($x/b[4]/@attr))), xs:anyURI(string(ref:node-structural-information($x/b[1])))),
    ref:following-in-document-order-of(xs:anyURI(string(ref:node-structural-information($x/b[4]/c[1]))), xs:anyURI(string(ref:node-structural-information($x/b[1])))),    
    ref:following-in-document-order-of(xs:anyURI(string(ref:node-structural-information($x/b[4]/c[1]))), xs:anyURI(string(ref:node-structural-information($x/b[4]))))
  }
  </following-in-document-order-of>
  <level>
  {
    ref:level(xs:anyURI(string(ref:node-structural-information($x)))),
    ref:level(xs:anyURI(string(ref:node-structural-information($x/b[1])))),
    ref:level(xs:anyURI(string(ref:node-structural-information($x/newb[1])))),
    ref:level(xs:anyURI(string(ref:node-structural-information($x/newb[2])))),
    ref:level(xs:anyURI(string(ref:node-structural-information($x/b/@attr)))),
    ref:level(xs:anyURI(string(ref:node-structural-information($x/b/c[1]))))
  }
  </level>
  <sibling-of>
  {
    ref:sibling-of(xs:anyURI(string(ref:node-structural-information($x/b[1]))), xs:anyURI(string(ref:node-structural-information($x/b[2])))),
    ref:sibling-of(xs:anyURI(string(ref:node-structural-information($x/b[1]))), xs:anyURI(string(ref:node-structural-information($x/newb[1])))),
    ref:sibling-of(xs:anyURI(string(ref:node-structural-information($x/b[2]))), xs:anyURI(string(ref:node-structural-information($x/b[1])))),
    ref:sibling-of(xs:anyURI(string(ref:node-structural-information($x))), xs:anyURI(string(ref:node-structural-information($x)))),
    ref:sibling-of(xs:anyURI(string(ref:node-structural-information($x/b/@attr))), xs:anyURI(string(ref:node-structural-information($x/b/@attr2)))),
    ref:sibling-of(xs:anyURI(string(ref:node-structural-information($x/b/@attr2))), xs:anyURI(string(ref:node-structural-information($x/b/@attr)))),
    ref:sibling-of(xs:anyURI(string(ref:node-structural-information($x/b[1]))), xs:anyURI(string(ref:node-structural-information($y/b[2]))))
  }  
  </sibling-of>
  <in-same-tree-of>
  {
    ref:in-same-tree-of(xs:anyURI(string(ref:node-structural-information($x/b[1]))), xs:anyURI(string(ref:node-structural-information($x/b[2])))),
    ref:in-same-tree-of(xs:anyURI(string(ref:node-structural-information($y/b[1]))), xs:anyURI(string(ref:node-structural-information($y/b[2])))),
    ref:in-same-tree-of(xs:anyURI(string(ref:node-structural-information($x/b[1]))), xs:anyURI(string(ref:node-structural-information($y/b[2])))),
    ref:in-same-tree-of(xs:anyURI(string(ref:node-structural-information($y/b[2]))), xs:anyURI(string(ref:node-structural-information($x/b[1]))))    
  }
  </in-same-tree-of>
  <in-collection>
  {
    ref:in-collection(xs:anyURI(string(ref:node-structural-information($xx/b)))),
    ref:in-collection(xs:anyURI(string(ref:node-structural-information($xx/b2)))),
    ref:in-collection(xs:anyURI(string(ref:node-structural-information($xx/b/bb)))),
    ref:in-collection(xs:anyURI(string(ref:node-structural-information($xx/b2/bb2)))),
    ref:in-collection(xs:anyURI(string(ref:node-structural-information($x)))),
    ref:in-collection(xs:anyURI(string(ref:node-structural-information($x/b[1])))),
    ref:in-collection(xs:anyURI(string(ref:node-structural-information($x/b/@attr)))),
    ref:in-collection(xs:anyURI(string(ref:node-structural-information($x/b/c[1]))))
  }
  </in-collection>
  <in-same-collection>
  {
    ref:in-same-collection-of(xs:anyURI(string(ref:node-structural-information($xx/b))),xs:anyURI(string(ref:node-structural-information($xx/b)))),
    ref:in-same-collection-of(xs:anyURI(string(ref:node-structural-information($xx/b2))),xs:anyURI(string(ref:node-structural-information($xx/b2)))),
    ref:in-same-collection-of(xs:anyURI(string(ref:node-structural-information($xx/b/bb))),xs:anyURI(string(ref:node-structural-information($xx/b/bb)))),
    ref:in-same-collection-of(xs:anyURI(string(ref:node-structural-information($xx/b2/bb2))),xs:anyURI(string(ref:node-structural-information($xx/b2/bb2)))),
    ref:in-same-collection-of(xs:anyURI(string(ref:node-structural-information($xx/b))),xs:anyURI(string(ref:node-structural-information($yy/b)))),
    ref:in-same-collection-of(xs:anyURI(string(ref:node-structural-information($xx/b2))),xs:anyURI(string(ref:node-structural-information($yy/b2)))),
    ref:in-same-collection-of(xs:anyURI(string(ref:node-structural-information($xx/b/bb))),xs:anyURI(string(ref:node-structural-information($yy/b/bb)))),
    ref:in-same-collection-of(xs:anyURI(string(ref:node-structural-information($xx/b2/bb2))),xs:anyURI(string(ref:node-structural-information($yy/b2/bb2)))),    
    ref:in-same-collection-of(xs:anyURI(string(ref:node-structural-information($x))),xs:anyURI(string(ref:node-structural-information($x))))    
  }
  </in-same-collection>
</result>