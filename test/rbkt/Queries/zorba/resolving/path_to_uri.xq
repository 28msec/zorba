import module namespace file = "http://expath.org/ns/file";
declare variable $input-context as xs:string external;

fn:doc(fn:resolve-uri("test.xml"))
