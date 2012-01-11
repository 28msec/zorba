import module namespace np = "http://www.zorba-xquery.com/modules/node-position";

declare function local:test-types($s-info)
{
(
  np:is-attribute($s-info),
  np:is-comment($s-info),
  np:is-document($s-info),
  np:is-element($s-info),
  np:is-processing-instruction($s-info),
  np:is-text($s-info)
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
