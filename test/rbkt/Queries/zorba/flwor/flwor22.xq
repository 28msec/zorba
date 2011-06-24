declare function local:parse-duration ($d as xs:string) as xs:dayTimeDuration {
  xs:time ($d) - xs:time ("00:00:00")
};

declare function local:percentage ($n as xs:double) as xs:string {
  concat (string (fn:round ($n * 100)), "%")
};

declare variable $buildtag external;
declare variable $now := "RIGHT NOW";
declare variable $rev := "12345";
declare variable $tests := <tests/>;
declare variable $tests_old := <tests_old/>;

<html>
<head>
<title>Integration report for Zorba</title>
<style>
table {{ border-collapse: collapse; }}
td, th {{ border: solid black 1px; padding: 0.5em; }}
</style>
</head>

<body>

<h2>About this report</h2>

<p><a href="../{ $now }">This report</a> was created on { $now } for Zorba revision { $rev }.
</p>

<a name="qtimes"></a>
<h2>Execution times</h2>
<table summary="Execution times">
<tr><th>Query</th><th>Time</th><th>Previous time</th><th>Change</th></tr>
{
  for $test in $tests
  let $testname := $test/Name/text()
  let $qt := $test/Results/NamedMeasurement[@name="Execution Time"]/Value/text()
  let $test_old := $tests_old[Name/text() eq $testname]
  let $qt_old := $tests_old/Results/NamedMeasurement[@name="Execution Time"]/Value/text()
  return <tr>
  <td>{$testname}</td>
  <td>{$qt}</td>
  <td>{$qt_old}</td>
  <td>{ let $d := xs:dayTimeDuration("PT1S") return
        (local:percentage ((xs:dayTimeDuration("PT1H") - $d) div $d),
        "+/-", local:percentage (xs:dayTimeDuration ("PT0.5S") div $d))
  }</td>
</tr> }
</table>

</body>
</html>
