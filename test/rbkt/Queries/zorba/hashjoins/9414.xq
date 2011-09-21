declare function local:node-kind 
  ( $nodes as node()* )  as xs:string* {
       
 for $node in $nodes
 return
 if ($node instance of element()) then 'element'
 else if ($node instance of attribute()) then 'attribute'
 else if ($node instance of text()) then 'text'
 else if ($node instance of document-node()) then 'document-node'
 else if ($node instance of comment()) then 'comment'
 else if ($node instance of processing-instruction())
         then 'processing-instruction'
 else 'unknown'
 } ;

declare function local:match_filter_entry($qso_node, $filter_node)
{
	for $filter_entry in $filter_node/*
	return
		if (local:node-kind($filter_entry/node()) = "element") then
			local:match_filter_entry($qso_node/*[fn:local-name(.) eq fn:local-name($filter_entry)], $filter_entry)
		else
			$qso_node/*[fn:local-name(.) eq fn:local-name($filter_entry)] eq $filter_entry
};

let $qso :=
<qso>
<outstation>
<callsign>asdf</callsign>
<name></name>
</outstation>
<info>sdfsdfsdf</info>
</qso>
let $filter :=
<qso_filter>

</qso_filter>
return local:match_filter_entry($qso, $filter)