import schema namespace pul = "http://www.28msec.com/schemas/pul";

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
    <pul:nodes></pul:nodes>
  </pul:createCollection>
</pul:pending-update-list>
}