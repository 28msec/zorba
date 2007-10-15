declare variable $svnLog := fn:doc ("svn_log.xml");
declare variable $failures := fn:doc ("acceptance_failures.xml")//failure;
declare variable $rev external;
declare variable $now external;
declare variable $lastrev external;
declare variable $lastdate external;

<html>
<head>
<title>Integration report for Zorba revision { $rev }</title>
<base href="https://fifthelement.inf.ethz.ch/zorba-test/snapshots/{$now}/" />
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
{ for $f in $failures let $name := fn:data ($f/@test) return
<tr>
<td><a href="test_results/{$name}/">{$name}</a></td>
<td>{$f/code/actual/text()}</td><td>{$f/text/actual/text()}</td>
<td>{$f/code/expected/text()}</td><td>{$f/text/expected/text()}</td>
</tr>
}
</table>
</div>
else <p>All tests passed.</p>
}

<h2>About this report</h2>

<p>This report was created on { $now } for Zorba revision { $rev }.
{ if ($lastdate) then
<span>
The <a href="../{ $lastdate }">last report</a> was created on { 
$lastdate } for revision { $lastrev }.
Since then, the following authors have committed changes:
<span id="committers">{ fn:distinct-values ($svnLog//author) }</span>.
</span>
else () }
</p>

{ if ($lastdate) then
<table summary="changes">
<tr><th>Author</th><th>Date</th><th>Message</th></tr>
{ for $entry in $svnLog//logentry return <tr><td class="author">{$entry/author/text()}</td><td>{$entry/date/text()}</td><td>{$entry/msg/text()}</td></tr> }
</table>
else () }

</body>
</html>
