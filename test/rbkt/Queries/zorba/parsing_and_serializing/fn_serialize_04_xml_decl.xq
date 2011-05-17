(: testing the omit-xml-declaration set to no :)

import schema namespace ser = "http://www.w3.org/2010/xslt-xquery-serialization";

let $params :=
  <ser:serialization-parameters>
    <ser:omit-xml-declaration value="no"/>
  </ser:serialization-parameters>
return
  fn:serialize(<a/>, $params)
