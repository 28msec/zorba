import schema namespace xdm = "http://www.zorba-xquery.com/schemas/xdm";

validate strict {
  <xdm:sequence-of-items xmlns:xs="http://www.w3.org/2001/XMLSchema">
    <xdm:element node-name="a" type-name="xs:untyped"/>
    <xdm:element node-name="b" type-name="xs:untyped"/>
    <xdm:element node-name="c" type-name="xs:untyped"/>
    <xdm:element node-name="d" type-name="xs:untyped"/>
    <xdm:element node-name="e" type-name="xs:untyped"/>
  </xdm:sequence-of-items>
}
