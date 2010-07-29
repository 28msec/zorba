(:~
 : Simple test module for the basic functions of the image library.
 : 
 : @author Daniel Thomas
 :)
import module namespace basic = 'http://www.zorba-xquery.com/modules/image/basic';
import module namespace file = 'http://www.zorba-xquery.com/modules/file';
import schema namespace image = 'http://www.zorba-xquery.com/modules/image/image';


declare variable $local:png as xs:base64Binary := file:read("images/bird.png");
declare variable $local:gif as xs:base64Binary := file:read("images/bird.gif");
declare variable $local:tiff as xs:base64Binary := file:read("images/bird.tiff");
declare variable $local:jpg as xs:base64Binary := file:read("images/bird.jpg");



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
  let $blank-gif := basic:create(xs:unsignedInt(10), xs:unsignedInt(20), image:imageType("GIF"))
  let $blank-png := basic:create(xs:unsignedInt(10), xs:unsignedInt(20), image:imageType("PNG"))
  let $blank-jpg := basic:create(xs:unsignedInt(10), xs:unsignedInt(20), image:imageType("JPEG"))
  let $blank-tiff := basic:create(xs:unsignedInt(10), xs:unsignedInt(20), image:imageType("TIFF"))
  let $ref-gif := file:read("images/blank.gif")
  let $ref-jpg := file:read("images/blank.jpg")
  let $ref-tiff := file:read("images/blank.tiff")
  let $ref-png := file:read("images/blank.png")
  return (($blank-gif eq $ref-gif) and ($blank-jpg eq $ref-jpg) and ($blank-tiff eq $ref-tiff) and ($blank-gif eq $ref-gif)) 
};

(:~
 : @return true if the basic:type function works.
 :)
declare function local:test-type() as xs:boolean {
    ((basic:type($local:png) eq image:imageType("PNG") and (basic:type($local:gif) eq image:imageType("GIF")) 
    and (basic:type($local:tiff) eq image:imageType("TIFF")) and (basic:type($local:jpg) eq image:imageType("JPEG"))))
};

(:~
 : @return true if the basic:convert function works.
 :)
declare function local:test-convert() as xs:boolean {
    let $png-to-jpeg := basic:convert($local:png, image:imageType("JPEG"))
    let $png-to-tiff := basic:convert($local:png, image:imageType("TIFF"))
    let $png-to-gif := basic:convert($local:png, image:imageType("GIF"))
    return (($png-to-jpeg eq $local:jpg) and ($png-to-tiff eq $local:tiff) and ($png-to-gif eq $local:gif))
};

(:~
 : @return true if the basic:compress function works.
 :)
declare sequential function local:test-compress() as xs:boolean {
    let $uncompressed := file:read("images/uncompressed.jpg")
    let $compressed := basic:compress($uncompressed, xs:int(20))
    let $compressed-ref := file:read("images/compressed.jpg") 
    return ($compressed eq $compressed-ref)
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



  (: If all went well ... make sure the world knows! :)  
  "SUCCESS";

};

local:main();



