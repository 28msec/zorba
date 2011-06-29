import module namespace x2h = "http://www.zorba-xquery.com/modules/xqdoc2xhtml/";

declare variable $modulesPath         as xs:string external;
declare variable $xhtmlRequisitesPath as xs:string external;
declare variable $xqdocBuildPath      as xs:string external;
declare variable $examplePath         as xs:string external;
declare variable $zorbaVersion        as xs:string external;



x2h:copy-xhtml-requisites($modulesPath,
                          $xhtmlRequisitesPath,
                          fn:trace($xqdocBuildPath,"Copy XHTML requisites in:"),
                          $examplePath);
                          

variable $indexHtmlPath as xs:string := 
fn:concat($xhtmlRequisitesPath, "/templates/main.html");

x2h:main( $modulesPath,
          $xqdocBuildPath,
          $indexHtmlPath,
          $examplePath,
          $zorbaVersion,
          $xhtmlRequisitesPath);
