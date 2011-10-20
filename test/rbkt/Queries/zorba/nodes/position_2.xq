import module namespace np = "http://www.zorba-xquery.com/modules/node-position";
import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

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
    np:child-of(np:node-position($x), np:node-position($x/b[1])),
    np:child-of(np:node-position($x), np:node-position($x/newb[1])),
    np:child-of(np:node-position($x), np:node-position($x/b[4]/c[1])),
    np:child-of(np:node-position($x/b[1]), np:node-position($x)),
    np:child-of(np:node-position($x/b[4]/c[1]), np:node-position($x)),    
    np:child-of(np:node-position($x), np:node-position($x)),
    np:child-of(np:node-position($x/b[1]), np:node-position($y)),
    np:child-of(np:node-position($xxx), np:node-position($yyy/b[1]))
  }
  </child-of>
  <attribute-of>
  {
    np:attribute-of(np:node-position($x/b[4]), np:node-position($x/b[4]/@attr)),
    np:attribute-of(np:node-position($x/b[4]), np:node-position($x/b[4]/c/@attr)),
    np:attribute-of(np:node-position($x/b[4]/@attr), np:node-position($x/b[4])),
    np:attribute-of(np:node-position($x/b[4]/c/@attr), np:node-position($x/b[4])),    
    np:attribute-of(np:node-position($x), np:node-position($x/b[1])),
    np:attribute-of(np:node-position($x), np:node-position($x/newb[1])),    
    np:attribute-of(np:node-position($x/b[4]/@attr), np:node-position($x/b[4]/@attr)),
    np:attribute-of(np:node-position($x/b[4]), np:node-position($y/b[4]/@attr)),
    np:attribute-of(np:node-position($xxx/b[4]), np:node-position($yyy/b[4]/@attr))
  }
  </attribute-of>
  <parent-of>
  { 
    np:parent-of(np:node-position($x/b[1]), np:node-position($x)),
    np:parent-of(np:node-position($x/newb[1]), np:node-position($x)),
    np:parent-of(np:node-position($x/b[4]/c[1]), np:node-position($x)),
    np:parent-of(np:node-position($x), np:node-position($x/b[1])),
    np:parent-of(np:node-position($x), np:node-position($x/b[4]/c[1])),        
    np:parent-of(np:node-position($x), np:node-position($x)),
    np:parent-of(np:node-position($x/b[1]), np:node-position($y)),
    np:parent-of(np:node-position($xxx/b[1]), np:node-position($yyy))
  }
  </parent-of>
  <preceding-in-document-order-of>
  {
    np:preceding-in-document-order-of(np:node-position($x/b[4]/@attr), np:node-position($x/b[1])),
    np:preceding-in-document-order-of(np:node-position($x/b[4]/c[1]), np:node-position($x/b[1])),
    np:preceding-in-document-order-of(np:node-position($x/b[4]/c[1]), np:node-position($x/b[4])),
    np:preceding-in-document-order-of(np:node-position($y), np:node-position($x)),
    np:preceding-in-document-order-of(np:node-position($x), np:node-position($y)),
    np:preceding-in-document-order-of(np:node-position($x), np:node-position($x)),
    np:preceding-in-document-order-of(np:node-position($x/b[1]), np:node-position($x/b[4]/@attr)),
    np:preceding-in-document-order-of(np:node-position($x/b[1]), np:node-position($x/b[4]/c[1])),
    np:preceding-in-document-order-of(np:node-position($x/b[4]), np:node-position($x/b[4]/c[1])),
    np:preceding-in-document-order-of(np:node-position($xxx/b[4]/@attr), np:node-position($yyy/b[1]))
  }
  </preceding-in-document-order-of>
  <following-in-document-order-of>
  { 
    np:following-in-document-order-of(np:node-position($x/b[1]), np:node-position($x/b[4]/@attr)),   
    np:following-in-document-order-of(np:node-position($x/b[1]), np:node-position($x/b[4]/c[1])),
    np:following-in-document-order-of(np:node-position($x/b[4]), np:node-position($x/b[4]/c[1])),
    np:following-in-document-order-of(np:node-position($x), np:node-position($y)),
    np:following-in-document-order-of(np:node-position($y), np:node-position($x)),
    np:following-in-document-order-of(np:node-position($x), np:node-position($x)),
    np:following-in-document-order-of(np:node-position($x/b[4]/@attr), np:node-position($x/b[1])),
    np:following-in-document-order-of(np:node-position($x/b[4]/c[1]), np:node-position($x/b[1])),
    np:following-in-document-order-of(np:node-position($x/b[4]/c[1]), np:node-position($x/b[4])),
    np:following-in-document-order-of(np:node-position($yyy/b[1]), np:node-position($xxx/b[4]/@attr))
  }
  </following-in-document-order-of>
  <level>
  {
    np:level(np:node-position(document {"x"})),
    np:level(np:node-position(element {"x"}{"x"})),    
    np:level(np:node-position($x)),
    np:level(np:node-position($x/b[1])),
    np:level(np:node-position($x/newb[1])),
    np:level(np:node-position($x/newb[2])),
    np:level(np:node-position($x/b/@attr)),
    np:level(np:node-position($x/b/c[1]))
  }
  </level>
  <sibling-of>
  {
    np:sibling-of(np:node-position($x/b[1]), np:node-position($x/b[2])),
    np:sibling-of(np:node-position($x/b[1]), np:node-position($x/newb[1])),
    np:sibling-of(np:node-position($x/b[2]), np:node-position($x/b[1])),
    np:sibling-of(np:node-position($x), np:node-position($x)),
    np:sibling-of(np:node-position($x/b/@attr), np:node-position($x/b/@attr2)),
    np:sibling-of(np:node-position($x/b/@attr2), np:node-position($x/b/@attr)),
    np:sibling-of(np:node-position($x/b[1]), np:node-position($y/b[2])),
    np:sibling-of(np:node-position($xxx/b[1]), np:node-position($yyy/b[2]))
  }  
  </sibling-of>
  <in-same-tree-of>
  {
    np:in-same-tree-of(np:node-position($x/b[1]), np:node-position($x/b[2])),
    np:in-same-tree-of(np:node-position($y/b[1]), np:node-position($y/b[2])),
    np:in-same-tree-of(np:node-position($x/b[1]), np:node-position($y/b[2])),
    np:in-same-tree-of(np:node-position($y/b[2]), np:node-position($x/b[1])),
    np:in-same-tree-of(np:node-position($xxx/b[1]), np:node-position($yyy/b[2]))    
  }
  </in-same-tree-of>
  <in-collection>
  {
    np:in-collection(np:node-position($xx/b)),
    np:in-collection(np:node-position($xx/b2)),
    np:in-collection(np:node-position($xx/b/bb)),
    np:in-collection(np:node-position($xx/b2/bb2)),
    np:in-collection(np:node-position($x)),
    np:in-collection(np:node-position($x/b[1])),
    np:in-collection(np:node-position($x/b/@attr)),
    np:in-collection(np:node-position($x/b/c[1]))
  }
  </in-collection>
  <in-same-collection>
  {
    np:in-same-collection-of(np:node-position($xx/b),np:node-position($xx/b)),
    np:in-same-collection-of(np:node-position($xx/b2),np:node-position($xx/b2)),
    np:in-same-collection-of(np:node-position($xx/b/bb),np:node-position($xx/b/bb)),
    np:in-same-collection-of(np:node-position($xx/b2/bb2),np:node-position($xx/b2/bb2)),
    np:in-same-collection-of(np:node-position($xx/b),np:node-position($yy/b)),
    np:in-same-collection-of(np:node-position($xx/b2),np:node-position($yy/b2)),
    np:in-same-collection-of(np:node-position($xx/b/bb),np:node-position($yy/b/bb)),
    np:in-same-collection-of(np:node-position($xx/b2/bb2),np:node-position($yy/b2/bb2)),    
    np:in-same-collection-of(np:node-position($x),np:node-position($x))    
  }
  </in-same-collection>
</result>    
 