declare function local:json($nodes as node()*)
{ 
  {
    "name": string($nodes//compoundname/text()),
    "description": $nodes//detaileddescription//*[local-name() ne "htmlonly"] ! string($$) 
  }
};

let $xml := doc("ft_tokenizer.xml")/doxygen
let $json := local:json($xml)
return serialize($json, ())
