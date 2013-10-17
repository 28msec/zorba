declare function local:remove-identifiers($node as node()) as node()
{
copy $node-clean:=$node
modify
(
for $identifier in ($node-clean//*:target/*:identifier/text())
return replace node $identifier with "REMOVED"
)
return $node-clean
};


declare variable $doc:=<pul:pending-update-list xmlns:pul="http://zorba.io/modules/store/pul/representation">
<pul:insertInto>
<pul:target>
<pul:identifier>8f901d4a-ca3f-11e0-8edf-9300a64ac3cd</pul:identifier>
</pul:target>
</pul:insertInto>
<pul:replaceNode>
<pul:target>
<pul:identifier>7f903564-ca3f-11e0-8edf-9300a64ac3cd</pul:identifier>
</pul:target>
</pul:replaceNode>
<pul:replaceNode>
<pul:target>
<pul:identifier>6f903564-ca3f-11e0-8edf-9300a64ac3cd</pul:identifier>
</pul:target>
</pul:replaceNode>
<pul:replaceNode>
<pul:target>
<pul:identifier>5f903564-ca3f-11e0-8edf-9300a64ac3cd</pul:identifier>
</pul:target>
</pul:replaceNode>
</pul:pending-update-list>;


<result>
{
local:remove-identifiers($doc)
}
</result>
