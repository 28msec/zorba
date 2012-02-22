declare construction strip; 
import schema namespace hats="http://www.w3.org/XQueryTest/hats" at "SchemaImport/hats.xsd"; 
declare variable $x as schema-element(hats:s) external :=
    <hats:abf> 
      <hats:a/> <hats:b/> <hats:b/> <hats:f/> <hats:f/> <hats:f/> 
    </hats:abf>;
$x
