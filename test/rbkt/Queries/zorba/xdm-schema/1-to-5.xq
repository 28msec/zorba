import schema namespace xdm = "http://www.zorba-xquery.com/schemas/xdm";

validate strict {
  <xdm:sequence-of-items xmlns:xs="http://www.w3.org/2001/XMLSchema">
    <xdm:atomic-value type="xs:integer">1</xdm:atomic-value>
    <xdm:atomic-value type="xs:integer">2</xdm:atomic-value>
    <xdm:atomic-value type="xs:integer">3</xdm:atomic-value>
    <xdm:atomic-value type="xs:integer">4</xdm:atomic-value>
    <xdm:atomic-value type="xs:integer">5</xdm:atomic-value>
  </xdm:sequence-of-items>
}
