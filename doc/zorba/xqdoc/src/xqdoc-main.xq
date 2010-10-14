import module namespace doc2html = "http://www.zorba-xquery.com/modules/xqdoc2html" at "xqdoc-lib.xq";

declare variable $modulesPath     as xs:string external;
declare variable $xqdocBuildPath as xs:string external;
declare variable $indexHtmlPath  as xs:string external;

doc2html:main($modulesPath, $xqdocBuildPath, $indexHtmlPath)
