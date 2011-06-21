import module namespace pxq = "http://www.zorba-xquery.com/modules/project_xqdoc";

declare variable $modulesPath         as xs:string external;
declare variable $xqdocBuildPath      as xs:string external;

pxq:delete-XML-dir($xqdocBuildPath);

pxq:generate-xqdoc-XML($modulesPath,$xqdocBuildPath);
