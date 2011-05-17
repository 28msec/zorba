(: testing defaults with empty serialization-parameters :)

import schema namespace ser = "http://www.w3.org/2010/xslt-xquery-serialization";

let $params :=
  <ser:serialization-parameters>
  </ser:serialization-parameters>
return
  fn:serialize(<a/>, $params)
