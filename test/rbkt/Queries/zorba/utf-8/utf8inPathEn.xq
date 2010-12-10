let $fileName := "en-no_special_chars.xml"
let $path := fn:concat("xml_files/", $fileName)
return fn:doc($path)/data/text()
