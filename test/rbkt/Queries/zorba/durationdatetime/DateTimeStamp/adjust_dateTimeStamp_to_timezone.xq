let $dts := xs:dateTimeStamp("2013-01-13T12:01:53Z"),
    $tz  := xs:dayTimeDuration("PT2H")
return
  fn:adjust-dateTime-to-timezone($dts, $tz)
