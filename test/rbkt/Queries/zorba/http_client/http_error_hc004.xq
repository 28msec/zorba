import module namespace http = 'http://expath.org/ns/http-client';

declare namespace err = 'http://expath.org/ns/error';

try {
  http:send-request(<http:request method="POST" href="http://www.google.com"><http:body src="http://www.zorba-xquery.com" media-type="html" method="xml"/></http:request>)
} catch err:HC004 {
  "ok"
}

