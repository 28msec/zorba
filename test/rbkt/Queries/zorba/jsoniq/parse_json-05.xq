(: parse plenty of multiple top-level items :)
import module namespace f = "http://expath.org/ns/file";

count(jn:parse-json(f:read-text(fn:resolve-uri("zips.json"))))
