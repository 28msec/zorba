import schema namespace pul = "http://www.28msec.com/schemas/pul";

validate strict {
<pul:pending-update-list>
  <pul:insertIntoCollection>
    <pul:collection xmlns:p="http://www.28msec.com/templates/guestbook/guestbook">p:entries</pul:collection>
    <pul:nodes>
      <xdm:element xmlns:xdm="http://www.28msec.com/schemas/xdm" xmlns:xs="http://www.w3.org/2001/XMLSchema" node-name="el" type-name="xs:untyped"/>
    </pul:nodes>
  </pul:insertIntoCollection>
</pul:pending-update-list>
}