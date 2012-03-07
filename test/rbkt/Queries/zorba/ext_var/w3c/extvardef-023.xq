declare construction strip; 
import schema default element namespace "http://www.w3.org/XQueryTest/hats" at "SchemaImport/hats.xsd"; 
declare variable $x :=
  validate strict {
    <abf> 
      <a/> <b/> <b/> <f/> <f/> <f/> 
    </abf>};
$x
