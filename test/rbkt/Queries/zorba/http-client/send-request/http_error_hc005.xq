import module namespace http = "http://www.zorba-xquery.com/modules/http-client";
declare namespace h = "http://expath.org/ns/http-client";
declare namespace err = "http://expath.org/ns/error";

try {
  http:send-request(<h:request/>, (), ())
} catch err:HC005 {
  "ok"
}

