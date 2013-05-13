import module namespace uri = "http://www.zorba-xquery.com/modules/uri";

let $xml-uri-test := { "uri-test" : 
 [
   { 
     $uri:SCHEME : "http",
     $uri:PATH : "/"
   },
   { 
     $uri:SCHEME : "http",
     $uri:HOST : "www.zorba-xquery.com",
     $uri:PATH : "/"
   },
   {
     $uri:SCHEME : "http",
     $uri:HOST : "www.zorba-xquery.com",
     $uri:PATH : "/",
     $uri:QUERY : "abc=true"
   },
   {
     $uri:SCHEME : "http",
     $uri:PORT : 8080,
     $uri:HOST : "www.zorba-xquery.com",
     $uri:PATH : "/",
     $uri:QUERY : "abc=true"
   },
   {
     $uri:SCHEME : "http",
     $uri:PORT : 8080,
     $uri:HOST : "www.zorba-xquery.com",
     $uri:PATH : "/",
     $uri:USER-INFO : "user",
     $uri:QUERY : "abc=true"
   },
   {
     $uri:SCHEME : "http",
     $uri:PORT : 8080,
     $uri:HOST : "www.zorba-xquery.com",
     $uri:PATH : "/path1/path2",
     $uri:USER-INFO : "user",
     $uri:QUERY : "abc=true"
   },
   {
     $uri:SCHEME : "http",
     $uri:PORT : 8080,
     $uri:HOST : "www.zorba-xquery.com",
     $uri:PATH : "/path1/path2",
     $uri:USER-INFO : "user",
     $uri:QUERY : "abc=true&amp;bcd=false"
   },
   {
     $uri:SCHEME : "ftp",
     $uri:HOST : "ftp.is.co.za",
     $uri:PATH : "/rfc/rfc1808.txt"
   },
   {
     $uri:SCHEME : "http",
     $uri:PORT : 123,
     $uri:HOST : "[2001:6f8:9000:876:cccc:bbbb::]",
     $uri:PATH : "/test",
     $uri:USER-INFO : "thomas"
   },
   {
     $uri:SCHEME : "http",
     $uri:HOST : "a",
     $uri:PATH : "/b/c/g"
   },
   {
     $uri:SCHEME : "http",
     $uri:HOST : "a",
     $uri:PATH : "/b/c/g/"
   },
   {
     $uri:SCHEME : "http",
     $uri:HOST : "a",
     $uri:PATH : "/g"
   },
   {
     $uri:SCHEME : "http",
     $uri:HOST : "a",
     $uri:PATH : "/b/c/",
     $uri:QUERY : "y"
   },
   {
     $uri:SCHEME : "http",
     $uri:HOST : "a",
     $uri:PATH : "/b/c/g",
     $uri:QUERY : "y"
   },
   {
     $uri:SCHEME : "http",
     $uri:FRAGMENT : "s",
     $uri:HOST : "a",
     $uri:PATH : "/b/c/g"
   },
   {
     $uri:SCHEME : "http",
     $uri:FRAGMENT : "s",
     $uri:HOST : "a",
     $uri:PATH : "/b/c/g",
     $uri:QUERY : "y"
   },
   {
     $uri:SCHEME : "http",
     $uri:HOST : "a",
     $uri:PATH : "/b/c/;x"
   },
   {
     $uri:SCHEME : "http",
     $uri:HOST : "a",
     $uri:PATH : "/b/c/g;x"
   },
   {
     $uri:SCHEME : "http",
     $uri:FRAGMENT : "s",
     $uri:HOST : "a",
     $uri:PATH : "/b/c/g;x",
     $uri:QUERY : "y"
   },
   {
     $uri:SCHEME : "http",
     $uri:HOST : "a",
     $uri:PATH : "/b/c"
   },
   {
     $uri:SCHEME : "http",
     $uri:HOST : "a",
     $uri:PATH : "/b/c/"
   },
   {
     $uri:SCHEME : "http",
     $uri:HOST : "a",
     $uri:PATH : "/b"
   },
   {
     $uri:SCHEME : "http",
     $uri:HOST : "a",
     $uri:PATH : "/b/"
   },
   {
     $uri:SCHEME : "http",
     $uri:HOST : "a",
     $uri:PATH : "/b/g"
   },
   {
     $uri:SCHEME : "http",
     $uri:HOST : "a",
     $uri:PATH : "/"
   },
   {
     $uri:SCHEME : "http",
     $uri:HOST : "a",
     $uri:PATH : "/g"
   },
   {
     $uri:SCHEME : "http",
     $uri:HOST : "a",
     $uri:PATH : "/b/c/g;x=1/y"
   },
   {
     $uri:SCHEME : "http",
     $uri:HOST : "a",
     $uri:PATH : "/b/c/y"
   },
   {
     $uri:SCHEME : "http",
     $uri:FRAGMENT : "s/../x",
     $uri:HOST : "a",
     $uri:PATH : "/b/c/g"
   },
   {
     $uri:SCHEME : "http",
     $uri:HOST : "www.example.com",
     $uri:PATH : "/"
   },
   {
     $uri:SCHEME : "http",
     $uri:HOST : "www.example.com",
     $uri:PATH : "/dir/file"
   },
   {
     $uri:SCHEME : "http",
     $uri:HOST : "www.msb.de"
   },
   {
     $uri:SCHEME : "http",
     $uri:HOST : "www.msb.de",
     $uri:PATH : "/lib/helpers"
   },
   {
     $uri:SCHEME : "file",
     $uri:HOST : "localhost",
     $uri:PATH : "/Ãƒâ€¦ngstrÃƒÂ¶m/b/c"
   },
   {
     $uri:SCHEME : "file",
     $uri:OPAQUE-PART : "opaque-uri-part",
     $uri:FRAGMENT : "frag"
   },
   {
     $uri:SCHEME : "file",
     $uri:OPAQUE-PART : "text-file.txt"
   }
 ]
}

for $index in 1 to jn:size($xml-uri-test("uri-test"))
let $uri := $xml-uri-test("uri-test")($index)
return ( uri:serialize($uri), "
")

