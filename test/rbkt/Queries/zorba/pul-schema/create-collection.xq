import schema namespace pul = "http://www.zorba-xquery.com/schemas/pul";

validate strict {
<pul:pending-update-list>
  <pul:createCollection xmlns:xqx="http://www.w3.org/2005/XQueryX">
    <pul:name xmlns:my="http://www.example.com/">my:collection</pul:name>
    <pul:type>
      <xqx:sequenceType>
        <xqx:anyItemType/>
        <xqx:occurrenceIndicator>*</xqx:occurrenceIndicator>
      </xqx:sequenceType>
    </pul:type>
    <pul:nodes>
      <xdm:element xmlns:xdm="http://www.zorba-xquery.com/schemas/xdm" xmlns:xs="http://www.w3.org/2001/XMLSchema" node-name="el" type-name="xs:untyped"/>
    </pul:nodes>
  </pul:createCollection>
</pul:pending-update-list>
}
