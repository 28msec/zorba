import module namespace http = "http://www.zorba-xquery.com/modules/http-client";
declare namespace h = "http://expath.org/ns/http-client";
declare namespace err = "http://expath.org/ns/error";

http:send-request(<h:request method="POST" href="http://www.google.com"><h:body src="http://www.zorba-xquery.com" media-type="html" method="xml"/></h:request>, (), ())

