import module namespace np = "http://zorba.io/modules/node-position";

declare function local:test-types($s-info)
{
  let $s-info2:=xs:anyURI(string($s-info))
  return
(
  np:is-attribute($s-info2),
  np:is-comment($s-info2),
  np:is-document($s-info2),
  np:is-element($s-info2),
  np:is-processing-instruction($s-info2),
  np:is-text($s-info2)
)  
};

variable $doc:=
document 
{
  text{"text"},
  comment{"comment"},
  processing-instruction {"processing-instruction"}{"processing-instruction"},
  element {"element"}{attribute {"attribute"}{"attribute"}}
};


<result>
  <attr>{local:test-types(np:node-position($doc//attribute()))}</attr>
  <comm>{local:test-types(np:node-position($doc/comment()))}</comm>
  <docu>{local:test-types(np:node-position($doc))}</docu>
  <elem>{local:test-types(np:node-position($doc/element()))}</elem>
  <proc>{local:test-types(np:node-position($doc/processing-instruction()))}</proc>
  <text>{local:test-types(np:node-position($doc/text()))}</text>
</result>   
