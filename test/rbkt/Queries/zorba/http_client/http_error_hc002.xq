import module namespace http = 'http://expath.org/ns/http-client';

declare namespace err = 'http://expath.org/ns/error';

try {
  http:send-request(<http:request method="GET" href="http://www.google.com/" override-media-type="text/xml"/>)
} catch err:HC002 {
  "ok"
}
