let $fileName := "de-üöäßÜÖÄ.xml"
let $path := fn:concat("xml_files/", $fileName)
return fn:doc($path)/data/text()
