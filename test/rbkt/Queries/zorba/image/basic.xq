(:~
 : Simple test module for the basic functions of the image library.
 : 
 : @author Daniel Thomas
 :)
import module namespace basic = 'http://www.zorba-xquery.com/modules/image/basic';
import module namespace basicschema = 'http://www.zorba-xquery.com/modules/image/basicschema';
import module namespace file = 'http://www.zorba-xquery.com/modules/file';
import module namespace err = 'http://www.zorba-xquery.com/modules/image/error';

declare variable $local:image-dir := fn:concat(file:dir-of-base-uri(<a/>), "images/");


declare variable $local:png as xs:base64Binary := file:read(concat($local:image-dir, "bird.png"));
declare variable $local:gif as xs:base64Binary := file:read(concat($local:image-dir, "bird.gif"));
declare variable $local:tiff as xs:base64Binary := file:read(concat($local:image-dir, "bird.tiff"));
declare variable $local:jpg as xs:base64Binary := file:read(concat($local:image-dir, "bird.jpg"));



(:~
 : Outputs a nice error message to the screen ...
 :
 : @param $messsage is the message to be displayed
 : @return The passed message but really very, very nicely formatted.
 :)
declare function local:error($messages as xs:string*) as xs:string* {
  "
************************************************************************
ERROR:
  Location:", file:path-to-full-path("."), "
  Cause:",
  $messages,
  "
************************************************************************
"
};

(:~
 : @return true if the basic:width function works.
 :)
declare function local:test-width() as xs:boolean {
   ((basic:width($local:png) = 134) and (basic:width($local:gif) = 134) and (basic:width($local:jpg) = 134) and (basic:width($local:tiff) = 134))

};

(:~
 : @return true if the basic:height function works.
 :)
declare function local:test-height() as xs:boolean {
  ((basic:height($local:png) = 160) and (basic:height($local:gif) = 160) and (basic:height($local:jpg) = 160) and (basic:height($local:tiff) = 160))

};

(:~
 : @return true if the basic:create function works.
 :)
declare function local:test-create() as xs:boolean {
  let $blank-gif := basic:create(xs:unsignedInt(10), xs:unsignedInt(20), "GIF")
  let $blank-png := basic:create(xs:unsignedInt(10), xs:unsignedInt(20), "PNG")
  let $blank-jpg := basic:create(xs:unsignedInt(10), xs:unsignedInt(20), "JPEG")
  let $blank-tiff := basic:create(xs:unsignedInt(10), xs:unsignedInt(20), "TIFF")
  let $ref-gif := file:read(concat($local:image-dir, "blank.gif"))
  let $ref-jpg := file:read(concat($local:image-dir, "blank.jpg"))
  let $ref-tiff := file:read(concat($local:image-dir, "blank.tiff"))
  let $ref-png := file:read(concat($local:image-dir, "blank.png"))
  return (basicschema:equals($blank-gif, $ref-gif) and basicschema:equals($blank-png, $ref-png) and basicschema:equals($blank-jpg, $ref-jpg) and basicschema:equals($blank-tiff, $ref-tiff))
};

(:~
 : @return true if the basic:type function works.
 :)
declare function local:test-type() as xs:boolean {
    ((basic:type($local:png) eq "PNG") and (basic:type($local:gif) eq "GIF") 
    and (basic:type($local:tiff) eq "TIFF") and (basic:type($local:jpg) eq "JPEG"))
};


(:~
 : @return true if the basic:convert function works.
 :) 
declare function local:test-convert() as xs:boolean {
    let $png-to-jpeg := basic:convert($local:png, "JPEG")
    let $png-to-tiff := basic:convert($local:png, "TIFF")
    let $png-to-gif := basic:convert($local:png, "GIF")
    return (basicschema:equals($png-to-jpeg, $local:jpg) and basicschema:equals($png-to-tiff, $local:tiff) and basicschema:equals($png-to-gif, $local:gif))
};

(:~
 : @return true if the basic:compress function works.
 :) 
declare function local:test-compress() as xs:boolean {
    let $uncompressed := file:read(concat($local:image-dir, "uncompressed.jpg"))
    let $compressed := basic:compress($uncompressed, xs:unsignedInt(20))
    let $compressed-ref := file:read(concat($local:image-dir, "compressed.jpg")) 
    return basicschema:equals($compressed, $compressed-ref)
};

(:~
 : @return true if the basicschema:equals function works.
 :)
declare function local:test-equals() as xs:boolean {
  (basicschema:equals($local:gif, $local:gif) and (not (basicschema:equals($local:gif, file:read(concat($local:image-dir, "manipulation/gamma1Bird.gif"))))))
};







declare sequential function local:main() as xs:string* {

  let $a := local:test-width()
  return
    if (fn:not($a)) then
      exit returning local:error(("Determining width of images failed"))
    else ();

  (: ==================================================================== :)

  let $b := local:test-height()
  return
    if (fn:not($b)) then
      exit returning local:error(("Determining height of images failed"))
    else ();

  (: ==================================================================== :)

  let $c := local:test-create()
  return
    if (fn:not($c)) then
      exit returning local:error(("Creation of images failed"))
    else ();

  (: ==================================================================== :) 

  let $d := local:test-type()
  return
    if (fn:not($d)) then
        exit returning local:error("Getting types of images failed")  
    else ();
  (: ==================================================================== :)
  
  let $e := local:test-convert()
  return
    if (fn:not($e)) then
        exit returning local:error("Conversion of images failed")  
    else ();    
  
  (: ==================================================================== :)
  
  let $f := local:test-compress()
  return
    if (fn:not($f)) then
        exit returning local:error("Compression of images failed")
    else ();   
  
  (: ==================================================================== :)

  let $g := local:test-equals()
  return 
    if (fn:not($g)) then
      exit returning local:error("Equals function not working properly")
    else ();  


  (: If all went well ... make sure the world knows! :)  
  "SUCCESS";

};

local:main();



