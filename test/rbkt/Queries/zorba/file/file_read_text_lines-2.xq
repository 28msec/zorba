import module namespace file = "http://expath.org/ns/file";

file:read-text-lines(fn:resolve-uri("mydata.xml"))[1],
file:read-text-lines(fn:resolve-uri("mydata.xml"))[2]
