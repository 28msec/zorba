import module namespace http = "http://www.zorba-xquery.com/modules/http-client";

declare namespace err = "http://www.zorba-xquery.com/modules/error";

try {
  (:We need to test against localhost, since the patchqueue uses a proxy:)
  http:get("http://localhost:34297")
} catch err:HC001 {
  "ok"
}
