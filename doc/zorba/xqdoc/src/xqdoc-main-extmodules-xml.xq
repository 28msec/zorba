import module namespace pxq = "http://www.zorba-xquery.com/modules/project_xqdoc";

declare variable $modulePath         as xs:string external;
declare variable $xqdocBuildPath     as xs:string external;


pxq:generate-xqdoc-XML($modulePath,$xqdocBuildPath);
