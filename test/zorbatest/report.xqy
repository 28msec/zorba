declare variable $svnLog := doc ("svn_log.xml");
declare variable $acceptance_failed := doc ("acceptance_failures.xml")//failure;
declare variable $regress_progress := doc ("regressions.xml");
declare variable $bl_regress_progress := doc ("bl_regressions.xml");
declare variable $regress_cats := <root>
<cat name="regressions">{$regress_progress//regress}</cat>
<cat name="baseline regressions">{$bl_regress_progress//regress}</cat>
<cat name="progressions">{$regress_progress//progress}</cat>
</root>;

declare variable $now external;
declare variable $rev external;
declare variable $bldate external;
declare variable $blrev external;
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
{ if (count ($acceptance_failed)) then
<div><h2>Acceptance acceptance_failed</h2>
<table summary="Acceptance acceptance_failed">
<tr><th rowspan="2">Test name</th><th colspan="2">Actual</th><th colspan="2">Expected</th></tr>
<tr><th>Code</th><th>Message</th><th>Code</th><th>Message</th></tr>
{ for $f in $acceptance_failed let $name := data ($f/@test) return
<tr>
<td><a href="test_results/{$name}/">{$name}</a></td>
<td>{$f/code/actual/text()}</td><td>{$f/text/actual/text()}</td>
<td>{$f/code/expected/text()}</td><td>{$f/text/expected/text()}</td>
</tr>
}
</table>
</div>
else <p>Acceptance tests passed or not run.</p>
}

<h2>About this report</h2>

<p><a href="../{ $now }">This report</a> was created on { $now } for Zorba revision { $rev }.
{ if ($lastdate) then
<span>
The <a href="../{ $lastdate }">previous report</a> was created on { 
$lastdate } for revision { $lastrev }.
Since then, the following authors have committed changes:
<span id="committers">{ distinct-values ($svnLog//author) }</span>.
</span>
else () }
</p>

{ if ($blrev) then
<p>The <a href="../{ $bldate }">baseline report</a> is for revision { $blrev }.
{ if (count ($bl_regress_progress//regress) = 0)
  then <span>The current report will become the new baseline since it has no baseline regressions.</span>
  else ()
}
</p>
else ()
}

{ if ($lastdate) then
<table summary="changes">
  <tr><th>Author</th><th>Revision</th><th>Date</th><th>Message</th></tr>
{ for $entry in $svnLog//logentry return <tr><td class="author">{$entry/author/text()}</td><td>{data ($entry/@revision)}</td><td>{$entry/date/text()}</td><td>{$entry/msg/text()}</td></tr> }
</table>
else () }

{ for $cat in $regress_cats/* let $cat_name := data ($cat/@name) return
if (count ($cat/*) > 0) then
<div>
<h2>Category: {$cat_name}</h2>
<ul>
{ for $x in $cat/* return <li>{$x/text()}</li> }
</ul>
</div>
else
<p>There were no { $cat_name }.</p>
}

<p>Also see the <a href="ctest/LastTestsFailed.log">complete list of failed tests</a>.</p>

<h2>Runtime errors</h2>

{ doc ("errors.xml") }

</body>
</html>
