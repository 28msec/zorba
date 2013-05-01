import module namespace uri = "http://www.zorba-xquery.com/modules/uri";

let $xml-uri-test := { "uri-test" : 
 [
   { 
     "scheme" : "http",
     "path" : "/"
   },
   { 
     "scheme" : "http",
     "host" : "www.zorba-xquery.com",
     "path" : "/"
   },
   {
     "scheme" : "http",
     "host" : "www.zorba-xquery.com",
     "path" : "/",
     "query" : "abc=true"
   },
   {
     "scheme" : "http",
     "port" : 8080,
     "host" : "www.zorba-xquery.com",
     "path" : "/",
     "query" : "abc=true"
   },
   {
     "scheme" : "http",
     "port" : 8080,
     "host" : "www.zorba-xquery.com",
     "path" : "/",
     "user-info" : "user",
     "query" : "abc=true"
   },
   {
     "scheme" : "http",
     "port" : 8080,
     "host" : "www.zorba-xquery.com",
     "path" : "/path1/path2",
     "user-info" : "user",
     "query" : "abc=true"
   },
   {
     "scheme" : "http",
     "port" : 8080,
     "host" : "www.zorba-xquery.com",
     "path" : "/path1/path2",
     "user-info" : "user",
     "query" : "abc=true&amp;bcd=false"
   },
   {
     "scheme" : "ftp",
     "host" : "ftp.is.co.za",
     "path" : "/rfc/rfc1808.txt"
   },
   {
     "scheme" : "http",
     "port" : 123,
     "host" : "[2001:6f8:9000:876:cccc:bbbb::]",
     "path" : "/test",
     "user-info" : "thomas"
   },
   {
     "scheme" : "http",
     "host" : "a",
     "path" : "/b/c/g"
   },
   {
     "scheme" : "http",
     "host" : "a",
     "path" : "/b/c/g/"
   },
   {
     "scheme" : "http",
     "host" : "a",
     "path" : "/g"
   },
   {
     "scheme" : "http",
     "host" : "a",
     "path" : "/b/c/",
     "query" : "y"
   },
   {
     "scheme" : "http",
     "host" : "a",
     "path" : "/b/c/g",
     "query" : "y"
   },
   {
     "scheme" : "http",
     "fragment" : "s",
     "host" : "a",
     "path" : "/b/c/g"
   },
   {
     "scheme" : "http",
     "fragment" : "s",
     "host" : "a",
     "path" : "/b/c/g",
     "query" : "y"
   },
   {
     "scheme" : "http",
     "host" : "a",
     "path" : "/b/c/;x"
   },
   {
     "scheme" : "http",
     "host" : "a",
     "path" : "/b/c/g;x"
   },
   {
     "scheme" : "http",
     "fragment" : "s",
     "host" : "a",
     "path" : "/b/c/g;x",
     "query" : "y"
   },
   {
     "scheme" : "http",
     "host" : "a",
     "path" : "/b/c"
   },
   {
     "scheme" : "http",
     "host" : "a",
     "path" : "/b/c/"
   },
   {
     "scheme" : "http",
     "host" : "a",
     "path" : "/b"
   },
   {
     "scheme" : "http",
     "host" : "a",
     "path" : "/b/"
   },
   {
     "scheme" : "http",
     "host" : "a",
     "path" : "/b/g"
   },
   {
     "scheme" : "http",
     "host" : "a",
     "path" : "/"
   },
   {
     "scheme" : "http",
     "host" : "a",
     "path" : "/g"
   },
   {
     "scheme" : "http",
     "host" : "a",
     "path" : "/b/c/g;x=1/y"
   },
   {
     "scheme" : "http",
     "host" : "a",
     "path" : "/b/c/y"
   },
   {
     "scheme" : "http",
     "fragment" : "s/../x",
     "host" : "a",
     "path" : "/b/c/g"
   },
   {
     "scheme" : "http",
     "host" : "www.example.com",
     "path" : "/"
   },
   {
     "scheme" : "http",
     "host" : "www.example.com",
     "path" : "/dir/file"
   },
   {
     "scheme" : "http",
     "host" : "www.msb.de"
   },
   {
     "scheme" : "http",
     "host" : "www.msb.de",
     "path" : "/lib/helpers"
   },
   {
     "scheme" : "file",
     "host" : "localhost",
     "path" : "/Ãƒâ€¦ngstrÃƒÂ¶m/b/c"
   },
   {
     "scheme" : "file",
     "opaque-part" : "opaque-uri-part",
     "fragment" : "frag"
   },
   {
     "scheme" : "file",
     "opaque-part" : "text-file.txt"
   }
 ]
}

for $index in 1 to jn:size($xml-uri-test("uri-test"))
let $uri := $xml-uri-test("uri-test")($index)
return ( uri:serialize($uri), "
")

