import module namespace np = "http://zorba.io/modules/node-position";
import module namespace ddl = "http://zorba.io/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/dynamic/collections/dml";

ddl:create(xs:QName("ddl:coll"),<dummy/>);
variable $xx:=dml:collection(xs:QName("ddl:coll"));

ddl:create(xs:QName("ddl:coll2"),<dummy/>);
variable $yy:=dml:collection(xs:QName("ddl:coll2"));

ddl:create(xs:QName("ddl:coll3"),doc("position.xml")/a);
variable $xxx:=dml:collection(xs:QName("ddl:coll3"));

ddl:create(xs:QName("ddl:coll4"),doc("position.xml")/a);
variable $yyy:=dml:collection(xs:QName("ddl:coll4"));

insert node <b/> into $xx;
insert node <bb/> into $xx/b;
insert node <b2/> into $xx;
insert node <bb2/> into $xx/b2;

insert node <b/> into $yy;
insert node <bb/> into $yy/b;
insert node <b2/> into $yy;
insert node <bb2/> into $yy/b2;

variable $x :=  doc("position.xml")/a;
insert node <newb><c/></newb> before $x/b[4];
insert node <newb><c/></newb> after $x/b[4];
variable $y :=  element {"x"}{$x}/*;

<result>
  <child-of>
  {
    np:child-of(xs:anyURI(string(np:node-position($x))), xs:anyURI(string(np:node-position($x/b[1])))),
    np:child-of(xs:anyURI(string(np:node-position($x))), xs:anyURI(string(np:node-position($x/newb[1])))),
    np:child-of(xs:anyURI(string(np:node-position($x))), xs:anyURI(string(np:node-position($x/b[4]/c[1])))),
    np:child-of(xs:anyURI(string(np:node-position($x/b[1]))), xs:anyURI(string(np:node-position($x)))),
    np:child-of(xs:anyURI(string(np:node-position($x/b[4]/c[1]))), xs:anyURI(string(np:node-position($x)))),    
    np:child-of(xs:anyURI(string(np:node-position($x))), xs:anyURI(string(np:node-position($x)))),
    np:child-of(xs:anyURI(string(np:node-position($x/b[1]))), xs:anyURI(string(np:node-position($y)))),
    np:child-of(xs:anyURI(string(np:node-position($xxx))), xs:anyURI(string(np:node-position($yyy/b[1]))))
  }
  </child-of>
  <attribute-of>
  {
    np:attribute-of(xs:anyURI(string(np:node-position($x/b[4]))), xs:anyURI(string(np:node-position($x/b[4]/@attr)))),
    np:attribute-of(xs:anyURI(string(np:node-position($x/b[4]))), xs:anyURI(string(np:node-position($x/b[4]/c/@attr)))),
    np:attribute-of(xs:anyURI(string(np:node-position($x/b[4]/@attr))), xs:anyURI(string(np:node-position($x/b[4])))),
    np:attribute-of(xs:anyURI(string(np:node-position($x/b[4]/c/@attr))), xs:anyURI(string(np:node-position($x/b[4])))),    
    np:attribute-of(xs:anyURI(string(np:node-position($x))), xs:anyURI(string(np:node-position($x/b[1])))),
    np:attribute-of(xs:anyURI(string(np:node-position($x))), xs:anyURI(string(np:node-position($x/newb[1])))),    
    np:attribute-of(xs:anyURI(string(np:node-position($x/b[4]/@attr))), xs:anyURI(string(np:node-position($x/b[4]/@attr)))),
    np:attribute-of(xs:anyURI(string(np:node-position($x/b[4]))), xs:anyURI(string(np:node-position($y/b[4]/@attr)))),
    np:attribute-of(xs:anyURI(string(np:node-position($xxx/b[4]))), xs:anyURI(string(np:node-position($yyy/b[4]/@attr))))    
  }
  </attribute-of>
  <parent-of>
  { 
    np:parent-of(xs:anyURI(string(np:node-position($x/b[1]))), xs:anyURI(string(np:node-position($x)))),
    np:parent-of(xs:anyURI(string(np:node-position($x/newb[1]))), xs:anyURI(string(np:node-position($x)))),
    np:parent-of(xs:anyURI(string(np:node-position($x/b[4]/c[1]))), xs:anyURI(string(np:node-position($x)))),
    np:parent-of(xs:anyURI(string(np:node-position($x))), xs:anyURI(string(np:node-position($x/b[1])))),
    np:parent-of(xs:anyURI(string(np:node-position($x))), xs:anyURI(string(np:node-position($x/b[4]/c[1])))),        
    np:parent-of(xs:anyURI(string(np:node-position($x))), xs:anyURI(string(np:node-position($x)))),
    np:parent-of(xs:anyURI(string(np:node-position($x/b[1]))), xs:anyURI(string(np:node-position($y)))),
    np:parent-of(xs:anyURI(string(np:node-position($xxx/b[1]))), xs:anyURI(string(np:node-position($yyy))))
  }
  </parent-of>
  <preceding-in-document-order-of>
  {
    np:preceding-in-document-order-of(xs:anyURI(string(np:node-position($x/b[4]/@attr))), xs:anyURI(string(np:node-position($x/b[1])))),
    np:preceding-in-document-order-of(xs:anyURI(string(np:node-position($x/b[4]/c[1]))), xs:anyURI(string(np:node-position($x/b[1])))),
    np:preceding-in-document-order-of(xs:anyURI(string(np:node-position($x/b[4]/c[1]))), xs:anyURI(string(np:node-position($x/b[4])))),
    np:preceding-in-document-order-of(xs:anyURI(string(np:node-position($y))), xs:anyURI(string(np:node-position($x)))),
    np:preceding-in-document-order-of(xs:anyURI(string(np:node-position($x))), xs:anyURI(string(np:node-position($y)))),
    np:preceding-in-document-order-of(xs:anyURI(string(np:node-position($x))), xs:anyURI(string(np:node-position($x)))),
    np:preceding-in-document-order-of(xs:anyURI(string(np:node-position($x/b[1]))), xs:anyURI(string(np:node-position($x/b[4]/@attr)))),
    np:preceding-in-document-order-of(xs:anyURI(string(np:node-position($x/b[1]))), xs:anyURI(string(np:node-position($x/b[4]/c[1])))),
    np:preceding-in-document-order-of(xs:anyURI(string(np:node-position($x/b[4]))), xs:anyURI(string(np:node-position($x/b[4]/c[1])))),
    np:preceding-in-document-order-of(xs:anyURI(string(np:node-position($xxx/b[4]/@attr))), xs:anyURI(string(np:node-position($yyy/b[1]))))
  }
  </preceding-in-document-order-of>
  <following-in-document-order-of>
  {
    np:following-in-document-order-of(xs:anyURI(string(np:node-position($x/b[1]))), xs:anyURI(string(np:node-position($x/b[4]/@attr)))),
    np:following-in-document-order-of(xs:anyURI(string(np:node-position($x/b[1]))), xs:anyURI(string(np:node-position($x/b[4]/c[1])))),
    np:following-in-document-order-of(xs:anyURI(string(np:node-position($x/b[4]))), xs:anyURI(string(np:node-position($x/b[4]/c[1])))),
    np:following-in-document-order-of(xs:anyURI(string(np:node-position($x))), xs:anyURI(string(np:node-position($y)))),
    np:following-in-document-order-of(xs:anyURI(string(np:node-position($y))), xs:anyURI(string(np:node-position($x)))),
    np:following-in-document-order-of(xs:anyURI(string(np:node-position($x))), xs:anyURI(string(np:node-position($x)))),
    np:following-in-document-order-of(xs:anyURI(string(np:node-position($x/b[4]/@attr))), xs:anyURI(string(np:node-position($x/b[1])))),
    np:following-in-document-order-of(xs:anyURI(string(np:node-position($x/b[4]/c[1]))), xs:anyURI(string(np:node-position($x/b[1])))),    
    np:following-in-document-order-of(xs:anyURI(string(np:node-position($x/b[4]/c[1]))), xs:anyURI(string(np:node-position($x/b[4])))),
    np:following-in-document-order-of(xs:anyURI(string(np:node-position($yyy/b[1]))), xs:anyURI(string(np:node-position($xxx/b[4]/@attr))))
  }
  </following-in-document-order-of>
  <level>
  {
    np:level(xs:anyURI(string(np:node-position(document {"x"})))),
    np:level(xs:anyURI(string(np:node-position(element {"x"}{"x"})))),
    np:level(xs:anyURI(string(np:node-position($x)))),
    np:level(xs:anyURI(string(np:node-position($x/b[1])))),
    np:level(xs:anyURI(string(np:node-position($x/newb[1])))),
    np:level(xs:anyURI(string(np:node-position($x/newb[2])))),
    np:level(xs:anyURI(string(np:node-position($x/b/@attr)))),
    np:level(xs:anyURI(string(np:node-position($x/b/c[1]))))
  }
  </level>
  <sibling-of>
  {
    np:sibling-of(xs:anyURI(string(np:node-position($x/b[1]))), xs:anyURI(string(np:node-position($x/b[2])))),
    np:sibling-of(xs:anyURI(string(np:node-position($x/b[1]))), xs:anyURI(string(np:node-position($x/newb[1])))),
    np:sibling-of(xs:anyURI(string(np:node-position($x/b[2]))), xs:anyURI(string(np:node-position($x/b[1])))),
    np:sibling-of(xs:anyURI(string(np:node-position($x))), xs:anyURI(string(np:node-position($x)))),
    np:sibling-of(xs:anyURI(string(np:node-position($x/b/@attr))), xs:anyURI(string(np:node-position($x/b/@attr2)))),
    np:sibling-of(xs:anyURI(string(np:node-position($x/b/@attr2))), xs:anyURI(string(np:node-position($x/b/@attr)))),
    np:sibling-of(xs:anyURI(string(np:node-position($x/b[1]))), xs:anyURI(string(np:node-position($y/b[2])))),
    np:sibling-of(xs:anyURI(string(np:node-position($xxx/b[1]))), xs:anyURI(string(np:node-position($yyy/b[2]))))
  }  
  </sibling-of>
  <in-same-tree-of>
  {
    np:in-same-tree-of(xs:anyURI(string(np:node-position($x/b[1]))), xs:anyURI(string(np:node-position($x/b[2])))),
    np:in-same-tree-of(xs:anyURI(string(np:node-position($y/b[1]))), xs:anyURI(string(np:node-position($y/b[2])))),
    np:in-same-tree-of(xs:anyURI(string(np:node-position($x/b[1]))), xs:anyURI(string(np:node-position($y/b[2])))),
    np:in-same-tree-of(xs:anyURI(string(np:node-position($y/b[2]))), xs:anyURI(string(np:node-position($x/b[1])))),
    np:in-same-tree-of(xs:anyURI(string(np:node-position($xxx/b[1]))), xs:anyURI(string(np:node-position($yyy/b[2]))))    
  }
  </in-same-tree-of>
  <in-collection>
  {
    np:in-collection(xs:anyURI(string(np:node-position($xx/b)))),
    np:in-collection(xs:anyURI(string(np:node-position($xx/b2)))),
    np:in-collection(xs:anyURI(string(np:node-position($xx/b/bb)))),
    np:in-collection(xs:anyURI(string(np:node-position($xx/b2/bb2)))),
    np:in-collection(xs:anyURI(string(np:node-position($x)))),
    np:in-collection(xs:anyURI(string(np:node-position($x/b[1])))),
    np:in-collection(xs:anyURI(string(np:node-position($x/b/@attr)))),
    np:in-collection(xs:anyURI(string(np:node-position($x/b/c[1]))))
  }
  </in-collection>
  <in-same-collection>
  {
    np:in-same-collection-of(xs:anyURI(string(np:node-position($xx/b))),xs:anyURI(string(np:node-position($xx/b)))),
    np:in-same-collection-of(xs:anyURI(string(np:node-position($xx/b2))),xs:anyURI(string(np:node-position($xx/b2)))),
    np:in-same-collection-of(xs:anyURI(string(np:node-position($xx/b/bb))),xs:anyURI(string(np:node-position($xx/b/bb)))),
    np:in-same-collection-of(xs:anyURI(string(np:node-position($xx/b2/bb2))),xs:anyURI(string(np:node-position($xx/b2/bb2)))),
    np:in-same-collection-of(xs:anyURI(string(np:node-position($xx/b))),xs:anyURI(string(np:node-position($yy/b)))),
    np:in-same-collection-of(xs:anyURI(string(np:node-position($xx/b2))),xs:anyURI(string(np:node-position($yy/b2)))),
    np:in-same-collection-of(xs:anyURI(string(np:node-position($xx/b/bb))),xs:anyURI(string(np:node-position($yy/b/bb)))),
    np:in-same-collection-of(xs:anyURI(string(np:node-position($xx/b2/bb2))),xs:anyURI(string(np:node-position($yy/b2/bb2)))),    
    np:in-same-collection-of(xs:anyURI(string(np:node-position($x))),xs:anyURI(string(np:node-position($x))))    
  }
  </in-same-collection>
</result>
