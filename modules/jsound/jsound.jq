jsoniq version "1.0";


(:
 : Copyright 2006-2013 The FLWOR Foundation.
 :
 : Licensed under the Apache License, Version 2.0 (the "License");
 : you may not use this file except in compliance with the License.
 : You may obtain a copy of the License at
 :
 : http://www.apache.org/licenses/LICENSE-2.0
 :
 : Unless required by applicable law or agreed to in writing, software
 : distributed under the License is distributed on an "AS IS" BASIS,
 : WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 : See the License for the specific language governing permissions and
 : limitations under the License.
 :)

(:~
 : JSound simple validator
 : This is a JSONiq implemenation of the JSound (the schema for JSON) validator.
 :
 : @author Cezar Andrei
 :)

module namespace jsv = "http://jsound.io/modules/validate"; 

import module namespace jn = "http://jsoniq.org/functions";
import module namespace map = "http://jsound.io/modules/validate/map";

declare namespace an = "http://zorba.io/annotations";


declare %an:sequential function 
jsv:jsd-valid($jsd as object, $name as string, $ns as string,
  $instance as item) as boolean
{
  variable $jstypes := { "foo" : 5 };

  if( $jsd instance of object )
  then 
    if ( exists($jsd("$namespace")) and exists($jsd("$types")) )
    then
      if ( $jsd("$namespace") instance of string )
      then
        if ( $jsd("$namespace") eq $ns )
        then
          if ( $jsd("$types") instance of array )
          then
            jsv:check-types( $jstypes, $jsd("$types") ); 
          else
            fn:error(QName("jsdBADJSound"), 
              "Not a valid JSound doc: value of '$types' must be an array.");
        else
          fn:error(QName("jsdJSound"), 
            "Type namespace not matching document namespace.");
      else
        fn:error(QName("jsdBADJSound"), 
          "Not a valid JSound doc: value of '$namespace' must be a string.");
    else
      fn:error(QName("jsdBADJSound"), 
        "Not a valid JSound doc: must contain '$types' and '$namespace' keys.");
  else 
    fn:error(QName("jsdBADJSound"), 
      "The specified JSON document is not a valid JSound schema: top item not an object.");
      
  (: todo: validate all type refs :)
  
  jsv:validate-instance($jstypes, $name, $instance)
};

(: The check-xxx functions just checks if the JSound schema definitions are valid. :)

declare %an:sequential function
jsv:check-types($jstypes as object, $types as array) as boolean
{
  every $i in
    for $type in jn:members($types)
    return
      jsv:check-type($jstypes, $type)
  satisfies $i eq fn:true()
};


declare %an:sequential function
jsv:check-type($jstypes as object, $type as item) as boolean
{
  if( fn:trace($type, "check-type") instance of object )
  then 
    if ( exists($type("$kind")) and $type("$kind") instance of string )
    then
      switch( $type("$kind") )
      case "atomic" return jsv:check-atomic-type($jstypes, $type)
      case "object" return jsv:check-object-type($jstypes, $type)
      case "array"  return jsv:check-array-type ($jstypes, $type)
      case "union"  return jsv:check-union-type ($jstypes, $type)

      default return
        fn:error(QName("jsdBADJSound"), 
          "Not a valid JSound doc: type $kind unknown:" | $type("$kind") )

    else
      fn:error(QName("jsdBADJSound"), 
        "Not a valid JSound doc: type definition must contain '$kind' key with string value.")
  else 
    if( $type instance of string )
    then 
      jsv:check-ref-type($jstypes, $type)
    else
      fn:error(QName("jsdBADJSound"), 
        "Not a valid JSound doc: type item not an object."  )
};

declare %an:sequential function
jsv:check-atomic-type($jstypes as object, $type as object) as boolean
{
  if( exists($type("$baseType")) and $type("$baseType") instance of string )
  then
    jsv:save-type($jstypes, $type)
  else
    fn:error(QName("jsdBADJSound"), 
      "Not a valid JSound doc: atomic type definition must contain '$baseType' key with string value.")
      
  (: todo: add facets checks: length, min/max Inclusive/Exclusive, etc. :)
}; 


declare %an:sequential function
jsv:check-object-type($jstypes as object, $type as object) as boolean
{
  (: todo: check the reast of "object" type :)
  jsv:save-type($jstypes, $type);

  every $i in
    for $k in jn:keys($type("$content"))
    return
      if( exists($type("$content")($k)("$type")) )
      then
        jsv:check-type($jstypes, $type("$content")($k)("$type"))
      else
        fn:error(QName("jsdBADJSound"), 
          "Not a valid JSound doc: Key " | $k | " does not contain a $type definition.")
  satisfies $i eq fn:true()
};


declare %an:sequential function
jsv:check-array-type($jstypes as object, $type as object) as boolean
{
  (: check all the contents :)
  (: let $t := fn:trace($type, "Array type:") :)
  let $content := $type("$content")
  return
    if( empty($content) )
    then
      fn:error(QName("jsdBADJSound"), 
        "Not a valid JSound doc: $kind array must have a $content key.")
    else
      if( $content instance of array and jn:size($content) eq 1 )
      then      
      {
        jsv:save-type($jstypes, $type);

        typeswitch( $content(1) )
        case string return
          fn:true()
        case object return
            jsv:check-type($jstypes, $content(1))
        default return
          fn:error(QName("jsdBADJSound"), 
            "Not a valid JSound doc: for $kind array, $content[1] must be string or array.")  
      }
      else
        fn:error(QName("jsdBADJSound"), 
          "Not a valid JSound doc: for $kind array, $content must be an array of size 1.")
    
  (: Todo: check array facets :)
};


declare %an:sequential function
jsv:check-union-type($jstypes as object, $type as object) as boolean
{
  let $content := $type("$content")
  return
    if( empty($content) )
    then
      fn:error(QName("jsdBADJSound"), 
        "Not a valid JSound doc: $kind union must have a $content key.")
    else
      if( $content instance of array )
      then      
      {
        jsv:save-type($jstypes, $type);
        
        every $i in 
          for $c in jn:members($content)
          return
            typeswitch( $c )
            case string return
              fn:true()
            case object return
                jsv:check-type($jstypes, $c)
            default return
              fn:error(QName("jsdBADJSound"), 
                "Not a valid JSound doc: for $kind union, $content items must be strings or objects.")  
        satisfies $i eq fn:true()
      }
      else
        fn:error(QName("jsdBADJSound"), 
          "Not a valid JSound doc: for $kind union, $content must be an array.")
};


declare function
jsv:check-ref-type($jstypes as object, $type as string)
{
  switch( $type )
  case "string" return fn:true()
  case "integer" return fn:true()
  case "boolean" return fn:true()
  case "anyURI"  return fn:true()
  default return 
    fn:error(QName("NYI"), 
      "Type ref: not yet implemented: " | $type )
      
  (: todo: save all refs, check them at the end to see if they exist :)
  (: todo: apply resolution rules :)
};


declare %an:sequential function 
jsv:save-type($jstypes as object, $type as item)
{
  if( fn:exists( $type("$name") ) )
  then
    if( $type("$name") instance of string )
    then
      map:set-if-empty($jstypes, $type("$name"), $type)
    else
      fn:error(QName("jsdBADJSound"), 
          "Not a valid JSound doc: for $type, $name must be a string.")
  else
    ()
};





(: The validate-xxx functions actualy do the validation of the instance :)

declare function 
jsv:validate-instance($jstypes as object, $name as string, $instance as item)
 as boolean
{
  let $type := map:get($jstypes, $name)
  return
    if( exists($type) )
    then
      jsv:validate-type(fn:trace($type,"Type"), $instance)
    else
      fn:error(QName("jsdJSound"),
             "Requested type name not present in schema: " | $name)
};


declare function
jsv:validate-type($type as item, $instance as item) as boolean
{
  switch( $type("$kind") )
  case "atomic" return jsv:validate-atomic-type($type, $instance)
  case "object" return jsv:validate-object-type($type, $instance)
  case "array"  return jsv:validate-array-type($type, $instance)
  case "union"  return jsv:validate-union-type($type, $instance)

  default return 
    fn:error(QName("jsdBADJSound"), 
      "Not a valid JSound doc: type $kind unknown:" | $type("$kind") )
};


declare function
jsv:validate-type-ref($type as string, $instance as item) as boolean
{
  switch( fn:trace($type, "validate-type-ref type") )
  case "string" return
    if ( fn:trace($instance, "validate-type-ref instance") instance of string )
    then
      fn:true() 
    else
      fn:false()
  case "integer" return
    if ( $instance instance of integer or $instance instance of int )
    then
      fn:true()
    else
      fn:false()
  case "anyURI" return
    if ( $instance instance of anyURI )
    then
      fn:true()
    else
      fn:false()
  case "boolean" return
    if ( $instance instance of boolean )
    then
      fn:true()
    else
      fn:false()
      
  default return
    fn:error(QName("NYI"), 
      "Type ref: not yet implemented: " | $type )
};


declare function
jsv:validate-atomic-type($type as object, $instance as item) as boolean
{
  if ( exists($type("$baseType")) and $type("$baseType") instance of string )
  then
    switch( $type("$baseType") )
    case "integer" return
      if ( $instance instance of integer or $instance instance of int )
      then
        fn:true() and jsv:validate-enumeration($type, $instance)
      else
        fn:false()
        
    case "string" return
      if ( $instance instance of string )
      then
        fn:true() and jsv:validate-enumeration($type, $instance)
      else
        fn:false()
        
    case "anyURI" return
      if ( $instance instance of anyURI )
      then
        fn:true() and jsv:validate-enumeration($type, $instance)
      else
        fn:false()
        
    case "boolean" return
      if ( $instance instance of boolean )
      then
        fn:true() and jsv:validate-enumeration($type, $instance)
      else
        fn:false()
    
    default return
      fn:error(QName("NYI"), 
        "$baseType: not yet implemented" | $type("$baseType") )
  else
    fn:error(QName("jsdBADJSound"), 
      "Not a valid JSound doc: atomic type definition must contain '$baseType' key with string value.")
      
  (: todo: add facets checks: length, min/max Inclusive/Exclusive, etc. :)
};

declare function
jsv:validate-enumeration($type as object, $instance as item) as boolean
{
  variable $enum := $type("$enumeration");
  if( exists($enum) )
  then
    if( $enum instance of array )
    then
      some $v in jn:members($enum) satisfies $v eq $instance        
    else
      fn:error(QName("jsdBADJSound"), 
        "Not a valid JSound doc: the value of '$enumeration' must be an array.")
  else
    fn:true()
};

declare function
jsv:validate-object-type($type as object, $instance as item) as boolean
{ 
  variable $open := $type("$open");
  
  if( (not exists($open)) or (exists($open) and $open eq true()) )
  then
    (: object is open: i.e. extra keys alowed but all defined keys must be in the instance except the default ones :)
    (
      every $k in jn:keys($instance) satisfies 
        (: todo: check that all these keys if they exist must have the right item type :)
        let $ctype := $type("$content")($k)("$type")
        return     
          typeswitch( $ctype )
          case string return
            jsv:validate-type-ref($ctype, $instance($k) )
          case object return
            jsv:validate-type($ctype, $instance($k) )
          default return
            fn:error(QName("jsdBADJSound"), 
              "Not a valid JSound doc: for $kind object, $content $type must be string or array.")
    ) and (
      every $k in jn:keys($type("$content")) except jn:keys($instance) satisfies
        let $optional := $type("$content")($k)("$optional")
        return 
          if( exists($optional) and $optional eq fn:true() )
          then fn:true()
          else
            fn:error(QName("jsdJSound"), 
             "Required key not present in instance:" | $k)
    )
  else
    (: object is closed: i.e. all defined keys must be in the instance except the default ones, no extra keys alowed :)
    (
      every $k in jn:keys($instance) satisfies 
        (: todo: check that all these keys exist and have the right item type :)
        let $ctype := $type("$content")($k)("$type")
        return     
          typeswitch( $ctype )
          case string return
            jsv:validate-type-ref($ctype, $instance($k) )
          case object return
            jsv:validate-type($ctype, $instance($k) )
          default return
            fn:error(QName("jsdBADJSound"), 
              "Not a valid JSound doc: for $kind object, $content $type must be string or array.")
    ) and (
      every $k in jn:keys($type("$content")) except jn:keys($instance) satisfies
        let $optional := $type("$content")($k)("$optional")
        return 
          if( exists($optional) and $optional eq fn:true() )
          then fn:true()
          else
            fn:error(QName("jsdJSound"),
             "Required key not present in instance:" | $k)
    )
};

declare function
jsv:validate-array-type($type as object, $instance as item) as boolean
{
  if( $instance instance of array )
  then
    (: check all the contents :)
    (: let $t := fn:trace($type, "Array type:") :)
    let $content := $type("$content")
    return
        typeswitch( $content(1) )
        case string return
          every $i in jn:members($instance) satisfies jsv:validate-type-ref($content(1), $i)
        case object return
          every $i in jn:members($instance) satisfies jsv:validate-type($content(1), $i)
        default return
          fn:error(QName("jsdBADJSound"), 
            "Not a valid JSound doc: for $kind array, $content[1] must be string or array.")  
  else
    fn:error(QName("Invalid"), "Instance not an array." )
    
  (: check array facets :)
};


declare function
jsv:validate-union-type($type as object, $instance as item) as boolean
{
  fn:error(QName("NYI"), 
    "type $kind: union not yet implemented" )
};





