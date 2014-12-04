import module namespace file = "http://expath.org/ns/file";
variable $content := file:read-text(resolve-uri("nikkei225.xml"));

parse-xml($content)