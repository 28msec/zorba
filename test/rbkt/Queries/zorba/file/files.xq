import module namespace file = "http://www.zorba-xquery.com/modules/file";

declare variable $modulesPath as xs:string external;

return fn:empty(file:files($modulesPath, "\.xq\.src$", fn:true()))