import module namespace x2h = "http://www.zorba-xquery.com/modules/xqdoc2xhtml/";

declare variable $modulePaths         as xs:string external;
declare variable $xhtmlRequisitesPath as xs:string external;
declare variable $xqdocBuildPath      as xs:string external;
declare variable $examplePath         as xs:string external;
declare variable $zorbaVersion        as xs:string external;

x2h:copy-xhtml-requisites($modulePaths,
                          $xhtmlRequisitesPath,
                          $xqdocBuildPath);

x2h:main($modulePaths,
                $xqdocBuildPath,
                $xhtmlRequisitesPath,
                $examplePath,
                $zorbaVersion);
