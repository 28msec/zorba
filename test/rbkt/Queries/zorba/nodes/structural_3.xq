import module namespace ref = "http://www.zorba-xquery.com/modules/node-structural-information";

declare function local:test-types($s-info)
{
(
  ref:is-attribute($s-info),
  ref:is-comment($s-info),
  ref:is-document($s-info),
  ref:is-element($s-info),
  ref:is-processing-instruction($s-info),
  ref:is-text($s-info)
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
