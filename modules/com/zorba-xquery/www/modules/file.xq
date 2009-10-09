module namespace file = "http://www.zorba-xquery.com/modules/file";

declare function file:readXML($uri as xs:string) as node() {1};

declare function file:readXML($uri as xs:string,
                              $tidy as xs:boolean,
                              $tidyOptions) as node() {1};

declare function file:readXHTML($uri as xs:string) as node() {1};

declare function file:readXHTML($uri as xs:string,
                                $tidy as xs:boolean,
                                $tidyOptions) as node() {1};

declare function file:readHTML($uri as xs:string,
                               $tidy as xs:boolean,
                               $tidyOptions) as xs:string {1};

declare function file:readText($uri as xs:string,
                               $content-type-hint as xs:string) as xs:string {1};

declare function file:read($uri as xs:string) as xs:base64Binary {1};

declare function file:write($uri as xs:string) as xs:integer {1};

declare function file:write($uri as xs:string,
                            $serializer-params) as xs:integer {1};

declare function file:copy($source as xs:string,
                           $target as xs:string) {1};

declare function file:copy($source as xs:string,
                           $target as xs:string, 
                           $overwrite as xs:boolean) {1};

declare function file:remove($file as xs:string) {1};

declare function file:mkdir($dir as xs:string) {1};

declare function file:rmdir ($dir as xs:string) {1};

declare function file:rmdir($dir as xs:string, 
                            $recursive as xs:boolean) {1};

declare function file:mkdirs($dir as xs:string) {1};

declare function file:isDirectory($dir as xs:string) as xs:boolean {1};

declare function file:isFile($file as xs:string) as xs:boolean {1};

declare function file:exists($fileOrDir as xs:string) as xs:boolean external;

declare function file:canRead($fileOrDir as xs:string) as xs:boolean {1};

declare function file:canWrite($fileOrDir as xs:string) as xs:boolean {1};

declare function file:createTempFile() as xs:anyURI {1};

declare function file:createTempFile($path as xs:string) as xs:anyURI {1};

declare function file:createTempFile($path as xs:string,
                                     $pattern as xs:string) as xs:anyURI {1};

declare function file:lastModified($fileOrDir as xs:string) as xs:dateTime {1};

declare function file:files() as xs:anyURI* {1};

declare function file:files($path as xs:string) as xs:anyURI* {1};

declare function file:files($path as xs:string,
                            $regexp as xs:string) as xs:anyURI* {1};
