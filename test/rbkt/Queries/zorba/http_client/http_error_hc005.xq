import module namespace http = 'http://expath.org/ns/http-client';

declare namespace err = 'http://expath.org/ns/error';

try {
  http:send-request(<request/>)
} catch err:HC005 {
  try {
    http:send-request(<http:request/>)
  } catch err:HC005 {
    "ok"
  }
}

