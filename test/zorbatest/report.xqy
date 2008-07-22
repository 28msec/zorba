declare function local:maybe-doc ($name as xs:string, $tag as xs:string) as document-node () {
  if (doc-available ($name)) then doc ($name) else document { element { $tag } {} }
};
declare function local:maybe-doc ($name as xs:string) as document-node () {
  local:maybe-doc ($name, "root")
};

declare function local:parse-duration ($d as xs:string) as xs:dayTimeDuration {
  xs:time ($d) - xs:time ("00:00:00")
};

declare function local:percentage ($n as xs:double) as xs:string {
  concat (string (fn:round ($n * 100)), "%")
};

declare variable $now external;
declare variable $rev external;
declare variable $bldate external;
declare variable $blrev external;
declare variable $lastrev external;
declare variable $lastdate external;

declare variable $svnLog := doc ("svn_log.xml");
declare variable $acceptance_failed := local:maybe-doc ("acceptance_failures.xml")//failure;
declare variable $regress_progress := local:maybe-doc ("regressions.xml");
declare variable $bl_regress_progress := local:maybe-doc ("bl_regressions.xml");
declare variable $regress_cats := <root>
<cat name="regressions">{$regress_progress//regress}</cat>
<cat name="baseline-regressions">{$bl_regress_progress//regress}</cat>
<cat name="progressions">{$regress_progress//progress}</cat>
</root>;
declare variable $qtimes := local:maybe-doc ("worst_times.xml")//entry;
declare variable $qtimes_old := local:maybe-doc (concat ("../", $lastdate, "/worst_times.xml"))//entry;

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
<p>Contents:</p>
<ul>{
for $cat in $regress_cats/* let $cat_name := data ($cat/@name) return
if (count ($cat/*) > 0) then
<li><a href="#{$cat_name}">{$cat_name}</a></li>
else ()
}
<li><a href="#qtimes">Execution times</a></li>
<li><a href="#rterrors">Runtime errors</a></li>
</ul>

{ if (count ($acceptance_failed)) then
<div><h2>Acceptance failures</h2>
<table summary="Acceptance failures">
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
<a name="{$cat_name}"></a>
<h2>Category: {$cat_name} ({count ($cat/*)} tests)</h2>
<ul>{
for $x in $cat/* let $case := $x/case/text(), $since := $x/since return
if ($since) then <li><a href="../{$since/date}">{$case}</a> (r{$since/rev})</li>
else <li>{$case}</li>
}</ul>
</div>
else
<p>There were no { $cat_name }.</p>
}

<p>Also see the <a href="ctest/LastTestsFailed.log.gz">complete list of failed tests</a>.</p>

<a name="qtimes"></a>
<h2>Execution times</h2>
<table summary="Execution times">
<tr><th>Query</th><th>Time</th><th>Previous time</th><th>Change</th></tr>
{ for $qt in $qtimes
  let $tm := $qt/t/text()
  let $qtold := $qtimes_old [q eq $qt/q]
  let $tmold := $qtold/t/text()
  where $tmold gt "00:00:25"
  return <tr>
  <td>{$qt/q/text()}</td>
  <td>{$tm}</td>
  <td>{$tmold}</td>
  <td>{ let $d := local:parse-duration ($tmold) return
        (local:percentage ((local:parse-duration ($tm) - $d) div $d),
        "+/-", local:percentage (xs:dayTimeDuration ("PT0.5S") div $d))
  }</td>
</tr> }
</table>

<a name="rterrors"></a>
<h2>Runtime errors</h2>

{ doc ("errors.xml") }

</body>
</html>
