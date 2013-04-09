(: this query loads a results.xml file and reports the number of 'non applicable' tests grouped by feature :)
(: 
  sample usage (please note that base-uri has to be an absolute URI)
          
  ./zorba -f -q ../../test/fots_driver/tools/dependencies.xq
          -e pathFailures:=results.xml
          --base-uri "/home/spungi/work/zorba/repo/tmp/fix_fots_driver/build/test/fots/2011/QT3-test-suite/catalog.xml"
          -o driver_dependencies.xml
          --indent
 :)

  import module namespace file = "http://expath.org/ns/file";
  import schema namespace fots = "http://www.w3.org/2010/09/qt-fots-catalog" at "catalog-schema.xsd";
  
  declare default element namespace "http://www.w3.org/2010/09/qt-fots-catalog";
  
  declare variable $pathFailures external;
  declare variable $pathFOTSZorbaManifest external :=
    "../../../../../test/fots_driver/FOTSZorbaManifest.xml";

(:~
 : This function is actually written by Michael Kay, Saxonica 18 July 2011 and
 : is part of the http://dev.w3.org/cvsweb/2011/QT3-test-suite/tools/dependencies.xq
 :)
  declare function local:mk_dependencies($t as element(fots:test-case)) as element(fots:dependency)* {
    $t/fots:dependency | $t/../fots:dependency
  };

(:~
 : This function is actually written by Michael Kay, Saxonica 18 July 2011 and
 : is part of the http://dev.w3.org/cvsweb/2011/QT3-test-suite/tools/dependencies.xq
 :)
  declare function local:mk_FOTS_dependencies() as element(fots:dependency)* {
    let $test-sets := 
    for $s in doc('catalog.xml')/fots:catalog/fots:test-set
    let $uri := resolve-uri($s/@file, base-uri($s))
    return doc($uri)/*
      for $d in distinct-values($test-sets//fots:dependency/@type)
      return 
        <dependency type="{$d}"> {
          let $de := $test-sets//fots:dependency[@type = $d]
          for $v in distinct-values($de/@value)
          return 
             <value number-of-tests="{count($test-sets/fots:test-case[local:mk_dependencies(.)[@type = $d and @value = $v]])}">
               {$v}
             </value>
     }</dependency>
  };
  
  variable $failures := fn:parse-xml(file:read-text($pathFailures));
  variable $FOTSZorbaManifest := doc(resolve-uri($pathFOTSZorbaManifest));
  variable $notDefinedInZorba :=
      for $dep in local:mk_FOTS_dependencies()
      for $depval in $dep/value
      where empty($FOTSZorbaManifest/fots:test-suite-result/fots:dependency[@type=$dep/@type and @value=$depval])
      return <dependency type="{$dep/@type}" value="{$depval/text()}" />;
  
  <report number-of-tests="{count($failures/fots:test-cases/fots:test-set/fots:test-case[@result="n/a"])}" > {
   (for $d in distinct-values(data($failures/fots:test-cases/fots:test-set/fots:test-case[@result="n/a"]/@comment))
    let $failures := count($failures/fots:test-cases//fots:test-set//fots:test-case[@result="n/a" and @comment=$d])
    order by $failures descending, $d
    return
      <dependency number-of-tests="{$failures}" type="{$d}" />,
    if (empty($notDefinedInZorba))
    then <!-- There are no dependencies in FOTS that are not declared in FOTSZorbaManifest.xml -->
    else (<!-- Following dependency from FOTS is not defined in FOTSZorbaManifest.xml -->,
          $notDefinedInZorba)
    )
 }</report>