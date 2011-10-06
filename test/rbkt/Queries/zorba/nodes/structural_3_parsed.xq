import module namespace ref = "http://www.zorba-xquery.com/modules/node-structural-information";

declare function local:test-types($s-info)
{
  let $s-info2:=xs:anyURI(string($s-info))
  return
(
  ref:is-attribute($s-info2),
  ref:is-comment($s-info2),
  ref:is-document($s-info2),
  ref:is-element($s-info2),
  ref:is-processing-instruction($s-info2),
  ref:is-text($s-info2)
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
  <attr>{local:test-types(ref:node-structural-information($doc//attribute()))}</attr>
  <comm>{local:test-types(ref:node-structural-information($doc/comment()))}</comm>
  <docu>{local:test-types(ref:node-structural-information($doc))}</docu>
  <elem>{local:test-types(ref:node-structural-information($doc/element()))}</elem>
  <proc>{local:test-types(ref:node-structural-information($doc/processing-instruction()))}</proc>
  <text>{local:test-types(ref:node-structural-information($doc/text()))}</text>
</result>   
