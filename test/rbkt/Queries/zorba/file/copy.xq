import module namespace file = "http://www.zorba-xquery.com/modules/file";

declare variable $zorbaPath as xs:string external;

let $fileSource := fn:concat($zorbaPath,fn:replace('/modules/com/zorba-xquery/www/modules/base64.xq','/',file:path-separator()))
let $fileDestination := fn:concat($zorbaPath,fn:replace('/build/test/rbkt/Queries/zorba/file','/',file:path-separator()))

return file:copy($fileSource,$fileDestination)