jsoniq version "1.0";
import module namespace file = "http://expath.org/ns/file";
import module namespace xqxq = "http://zorba.io/modules/zorba-query";

declare namespace err = "http://www.w3.org/2005/xqt-errors";

declare variable $test-configuration-file as xs:string external;
declare variable $test-name as xs:string external;

variable $configuration := jn:parse-json(file:read-text($test-configuration-file));
variable $test-data :=
{|
  $configuration,
  { "test-name": $test-name }
|};

variable $test-dir := $configuration.testsDirectory || "/" || $test-name;

if (not(file:is-directory($test-dir)))
then
  error(QName("local:MISSING-TEST"), "Cannot find test " || $test-name || " in folder " || $test-dir);
else ();

variable $test-queries := 
  for $query in file:list($test-dir, false(), "*.jq")
  order by $query
  return $test-dir || "/" || $query;

for $query in $test-queries
let $query-source := file:read-text($query)
return
{
  variable $full-test-source :=
    "jsoniq version \"1.0\";" ||
    "import module namespace test = \"http://zorba.io/test-helper\" at \"file://" || 
      $configuration.baseDirectory || "/test-helper.jq\";" || 
    $query-source;

  variable $context := ();
  variable $context-name := fn:QName("http://zorba.io/test-helper", "context");
  variable $compiled-test := xqxq:prepare-main-module($full-test-source);
  xqxq:bind-variable($compiled-test, $context-name, $context);
  xqxq:bind-variable($compiled-test, fn:QName("http://zorba.io/test-helper", "configuration"), $configuration);
  xqxq:bind-variable($compiled-test, fn:QName("http://zorba.io/test-helper", "zorba-endpoint"), 
      "http://" || $configuration.serverEndpoint || ":" || $configuration.serverPort);
  
  try
  {
    trace("", "Running " || $query);
    
    if (xqxq:is-sequential($compiled-test))
    then xqxq:evaluate-sequential($compiled-test);
    else xqxq:evaluate($compiled-test);
  } 
  catch * 
  {    
    error(QName("local:TEST-FAILED"), $query || ": " || $err:description);
  }

  $context := xqxq:variable-value($compiled-test, $context-name);
}
