import module namespace doc2html = "http://www.zorba-xquery.com/modules/internal/xqdoc-lib";

declare variable $modulesPath     as xs:string external;
declare variable $xqdocBuildPath  as xs:string external;
declare variable $indexHtmlPath   as xs:string external;

doc2html:main($modulesPath, $xqdocBuildPath, $indexHtmlPath)
