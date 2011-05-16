(: testing defaults with empty serialization-parameters :)

let $params :=
  <serialization-parameters xmlns="http://www.w3.org/2010/xslt-xquery-serialization">
  </serialization-parameters>
return
  fn:serialize(<a/>, $params)
