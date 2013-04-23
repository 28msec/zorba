let $dt := xs:dateTime("2013-01-13T12:01:53+01:00")
let $dts := $dt cast as xs:dateTimeStamp
return
  $dts instance of xs:dateTimeStamp
