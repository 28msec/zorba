(: this query loads a rezults.xml file and reports the number of 'non applicable' tests grouped by feature :)
(: 
  sample usage
  ./zorba -f -q ../../test/fots_driver/tools/dependencies.xq
          -e pathFailures:=results_12_nov.xml
          -o driver_dependencies.xml
          --indent
:)

  import module namespace file = "http://expath.org/ns/file";
  
  declare default element namespace "http://www.w3.org/2010/09/qt-fots-catalog";
  declare namespace fots = "http://www.w3.org/2010/09/qt-fots-catalog";
  
  declare variable $pathFailures external;

  variable $failures := fn:parse-xml(file:read-text($pathFailures));
  
  <report> {
    for $d in distinct-values(data($failures/fots:test-cases/fots:test-set/fots:test-case[@result="not applicable"]/@comment))
    order by $d
    return
      <dependency type="{$d}"> {
        <value number-of-tests="{count($failures/fots:test-cases//fots:test-set//fots:test-case[@result="not applicable" and @comment=$d])}" />
      }</dependency>
 }</report>
 