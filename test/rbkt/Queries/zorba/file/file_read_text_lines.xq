import module namespace file = "http://expath.org/ns/file";

string-join(file:read-text-lines(fn:resolve-uri("mydata.xml")), '
')
