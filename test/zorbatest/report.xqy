declare variable $svnLog := fn:doc ("svn_log.xml");
declare variable $failures := fn:doc ("acceptance_failures.xml")//failure;
declare variable $rev external;
declare variable $now external;
declare variable $lastrev external;
declare variable $lastdate external;

<html>
<head>
<title>Integration report for Zorba revision { $rev }</title>
<style>
table {{ border-collapse: collapse; }}
td, th {{ border: solid black 1px; padding: 0.5em; }}
</style>
</head>

<body>
<h1>Integration report for Zorba revision { $rev }</h1>
{ if (fn:count ($failures)) then
<div><h2>Acceptance failures</h2>
<table summary="Acceptance failures">
<tr><th rowspan="2">Test name</th><th colspan="2">Actual</th><th colspan="2">Expected</th></tr>
<tr><th>Code</th><th>Message</th><th>Code</th><th>Message</th></tr>
{ for $f in $failures return
<tr>
<td>{fn:data ($f/@test)}</td>
<td>{$f/code/actual}</td><td>{$f/text/actual}</td>
<td>{$f/code/expected}</td><td>{$f/text/expected}</td>
</tr>
}
</table>
</div>
else <p>All tests passed.</p>
}

<h2>About this report</h2>
<p>This report was created on { $now } for Zorba revision { $rev }. The last report was created on { $lastdate } for revision { $lastrev }. Since then, the following authors have committed changes: { fn:distinct-values ($svnLog//author) }.</p>
<table summary="changes">
<tr><th>Author</th><th>Date</th><th>Message</th></tr>
{ for $entry in $svnLog//logentry return <tr><td>{$entry/author}</td><td>{$entry/date}</td><td>{$entry/msg}</td></tr> }
</table>

</body>
</html>
