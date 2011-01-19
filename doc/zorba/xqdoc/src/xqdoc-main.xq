import module namespace xqdoc2html = "http://www.zorba-xquery.com/modules/xqdoc2xhtml/";

declare variable $modulesPath         as xs:string external;
declare variable $xhtmlRequisitesPath as xs:string external;
declare variable $xqdocBuildPath      as xs:string external;
declare variable $examplePath         as xs:string external;
declare variable $zorbaVersion        as xs:string external;

(
xqdoc2html:copy-xhtml-requisites( $modulesPath,
                                  $xhtmlRequisitesPath,
                                  $xqdocBuildPath)
,
xqdoc2html:main($modulesPath,
                $xqdocBuildPath,
                $xhtmlRequisitesPath,
                $examplePath,
                $zorbaVersion)

)