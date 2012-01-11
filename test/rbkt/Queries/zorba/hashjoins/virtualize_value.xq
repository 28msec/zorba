import module namespace file = "http://expath.org/ns/file";

declare namespace f="f";
declare namespace v="v";

declare namespace xcr='http://xcruciate.co.uk';

declare variable $docName external := "combined_threads";

declare function f:nestedVirtualizedDirs(
    $id as xs:string,
    $depth as xs:integer,
    $currentDepth as xs:integer) as xs:string 
{
  if (($depth < $currentDepth) or ($id = '')) 
  then
    ''
  else
    concat(substring($id, 1, $currentDepth),
           '/',
           f:nestedVirtualizedDirs($id, $depth, $currentDepth + 1))
};


declare function f:filterRecord (
    $docRecord as element(),
    $configRecord as element(),
    $top as xs:boolean) as element()* 
{
  if (not($configRecord/*)) 
  then
    $docRecord 
  else if ($top) then
    element
       { local-name($docRecord)}
       { $docRecord/@*,
	       attribute v:path { f:nestedVirtualizedDirs(doc("thread.xml")/*[1]/@id, 4, 0) }, 
	       (for $match as element() in $configRecord/*
	        return (for $docMatch as element() in $docRecord/*
                  where local-name($docMatch) = local-name($match)
                  return f:filterRecord($docMatch, $match, false())))
       } 
  else
    element
       { local-name($docRecord)}
       { $docRecord/@*,
	       (for $match as element() in $configRecord/*
	        return (for $docMatch as element() in $docRecord/*
                  where local-name($docMatch) = local-name($match)
                  return f:filterRecord($docMatch, $match, false())))
       }
};


let $daemon_id := doc("config.xml")/xcr:config/@for

let $document := doc("config.xml")/xcr:config/xcr:daemon[@id = $daemon_id]/application/document[@name = $docName]

return f:filterRecord(doc("thread.xml")/*[1], $document, true())

