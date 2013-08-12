
import module namespace file = "http://expath.org/ns/file";

declare namespace ann = "http://zorba.io/annotations";

variable $http-content;
$http-content := file:read-text(resolve-uri("zorba2.html"));

fn:analyze-string($http-content, "(&lt;|&amp;lt;|<)(((a|link|area).+?href)|((script|img).+?src))=([""'])(.*?)\7")
