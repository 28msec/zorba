import module namespace pxq = "http://www.zorba-xquery.com/modules/project_xqdoc";
import module namespace x2h = "http://www.zorba-xquery.com/modules/xqdoc2xhtml/";

declare variable $modulePaths         as xs:string external;
declare variable $xhtmlRequisitesPath as xs:string external;
declare variable $xqdocBuildPath      as xs:string external;
declare variable $examplePath         as xs:string external;
declare variable $zorbaVersion        as xs:string external;


pxq:generate-xqdoc-XML($modulePaths,$xqdocBuildPath);


x2h:copy-xhtml-requisites($modulePaths,
                          $xhtmlRequisitesPath,
                          fn:trace($xqdocBuildPath,"Copy XHTML requisites in:"));
                          

variable $indexHtmlPath as xs:string := 
fn:concat($xhtmlRequisitesPath, "/templates/main.html");

x2h:main( $modulePaths,
          $xqdocBuildPath,
          $indexHtmlPath,
          $zorbaVersion,
          $xhtmlRequisitesPath);
