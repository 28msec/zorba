let $fileName := "fr-éàèùâêîôûëïüÿçÉÀÈÙÂÊÎÔÛËÏÜŸÇ.xml"
let $path := fn:concat("xml_files/", $fileName)
return fn:doc($path)/data/text()
