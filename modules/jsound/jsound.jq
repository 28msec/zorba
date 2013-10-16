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
 : JSound simple validator.
 : This is a JSONiq implemenation of the JSound (the schema for JSON) validator.
 :
 : @author Cezar Andrei
 :)

module namespace jsv = "http://jsound.io/modules/validate"; 

import module namespace jn = "http://jsoniq.org/functions";
import module namespace map = "http://jsound.io/modules/validate/map";
import module namespace fetch = "http://zorba.io/modules/fetch";

declare namespace an = "http://zorba.io/annotations";
declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "1.0";

(:~ 
 : Validates the $instance JSON item against the JSound type with name $name
 : and namespace $ns, from the JSound schema definition $jsd.
 : 
 : @param $ns the namespace of the expected type
 : @param $name the name of the expected type
 : @param $instance the instance to be validated
 : @return true if the instance is valid, otherwise throws an error.
 : @error jsv:BadJSoundFormat If the schema is not a valid JSound schema
 : @error jsv:Invalid If the instance does not conform to the JSound schema
 : @error zerr:ZXQP0025 If the schema namespace URI cannot be resolved.
 : @error jn:JNDY0021 If the loaded schema is syntactically incorrect
 :)
declare %an:sequential function
jsv:jsd-valid($ns as string, $name as string, $instance as json-item)
  as boolean
{
  let $schemadoc := fetch:content($ns, "SCHEMA")
  let $jsd := jn:parse-json($schemadoc)
  return jsv:jsd-valid($jsd, $name, $ns, $instance)
};


(:~ 
 : Validates the $instance JSON item against the JSound type with name $name
 : and namespace $ns, from the JSound schema definition $jsd.
 : 
 : @param $jsd the JSound schema as a JSON object to be validated against
 : @param $name the name of the expected type
 : @param $ns the namespace of the expected type
 : @param $instance the instance to be validated
 : @return true if the instance is valid, otherwise throws an error.
 : @error jsv:BadJSoundFormat If the schema is not a valid JSound schema
 : @error jsv:Invalid If the instance does not conform to the JSound schema
<code>
  import module namespace jsv = "http://jsound.io/modules/validate"; 

  let $jsd :=
  {
   "$namespace" : "http://zorba.io/modules/images/",
   "$types" : [
    {
      "$name" : "line",
      "$kind" : "object",
      "$content" : 
      {
        "start" : 
        {
          "$type" : "integer"
        },
        "end" : 
        {
          "$type" : "integer"
        }
      }
    }  
   ]
  }

  let $instance := 
  {
    "start": 1,
    "end": 5
  }
  return
    jsv:jsd-valid($jsd, "line", "http://zorba.io/modules/images/", $instance)
</code>
 :)
declare %an:sequential function 
jsv:jsd-valid($jsd as object, $name as string, $ns as string,
  $instance as item) as boolean
{
  variable $jstypes := { "foo" : 5 };

  switch( false )
  case  $jsd instance of object  
  return
    fn:error(QName("jsv", "BadJSoundFormat"), 
      "The specified JSON document is not a valid JSound schema: top item not an object.");
      
  case exists($jsd("$namespace")) and exists($jsd("$types")) 
  return
    fn:error(QName("jsv", "BadJSoundFormat"), 
      "Not a valid JSound doc: must contain '$types' and '$namespace' keys.");
        
  case $jsd("$namespace") instance of string
  return
    fn:error(QName("jsv", "BadJSoundFormat"), 
      "Not a valid JSound doc: value of '$namespace' must be a string.");
  
  case $jsd("$namespace") eq $ns
  return
    fn:error(QName("jsv", "Invalid"), 
            "Requested type namespace not matching schema document namespace.");
  
  case $jsd("$types") instance of array
  return
    fn:error(QName("jsv", "BadJSoundFormat"), 
              "Not a valid JSound doc: value of '$types' must be an array.");
          
  default
  return 
    jsv:check-types( $jstypes, $jsd("$types") ); 
         
  (: todo: validate all type refs :)
  
  jsv:validate-instance($jstypes, $name, $instance)
};


(: The check-xxx functions just checks if the JSound schema definitions are valid. :)

declare %private %an:sequential function
jsv:check-types($jstypes as object, $types as array) as boolean
{
  every $i in
    for $type in jn:members($types)
    return
      jsv:check-type($jstypes, $type )
  satisfies $i eq true
};


declare %private %an:sequential function
jsv:check-type($jstypes as object, $type as item) as boolean
{
  if( $type instance of object )
  then 
    if ( exists($type("$kind")) and $type("$kind") instance of string )
    then
      switch( $type("$kind") )
      case "atomic" return jsv:check-atomic-type($jstypes, $type)
      case "object" return jsv:check-object-type($jstypes, $type)
      case "array"  return jsv:check-array-type ($jstypes, $type)
      case "union"  return jsv:check-union-type ($jstypes, $type)

      default return
        fn:error(QName("jsv", "BadJSoundFormat"), 
          "Not a valid JSound doc: type $kind unknown:" || $type("$kind") )

    else
      fn:error(QName("jsv", "BadJSoundFormat"), 
        "Not a valid JSound doc: type definition must contain '$kind' key with string value.")
  else 
    if( $type instance of string )
    then 
      jsv:check-ref-type($jstypes, $type)
    else
      fn:error(QName("jsv", "BadJSoundFormat"), 
        "Not a valid JSound doc: type item not an object."  )
};


declare %private %an:sequential function
jsv:check-atomic-type($jstypes as object, $type as object) as boolean
{
  (: fn:trace( $type("$name"), "check-atomic-type"); :)
  
  if( exists($type("$baseType")) and $type("$baseType") instance of string )
  then
    jsv:save-type($jstypes, $type)
  else
    fn:error(QName("jsv", "BadJSoundFormat"), 
      "Not a valid JSound doc: atomic type definition must contain '$baseType' key with string value.")
      
  (: todo: add facets checks: length, min/max Inclusive/Exclusive, etc. :)
}; 


declare %private %an:sequential function
jsv:check-object-type($jstypes as object, $type as object) as boolean
{
  (: todo: check the reast of "object" type :)
  jsv:save-type($jstypes, $type);
  (: fn:trace( $type("$name"), "check-object-type"); :)

  if( exists($type("$content")) )
  then
    if( $type("$content") instance of object )
    then
      every $i in
        for $k in jn:keys($type("$content"))
        return
          if( $type("$content")($k) instance of object )
          then
            if( exists( $type("$content")($k)("$type")) )
            then
              jsv:check-type($jstypes, $type("$content")($k)("$type") )
            else
              if( exists( $type("$content")($k)("$kind")) )
              then
                jsv:check-type($jstypes, $type("$content")($k) )
              else
                fn:error(QName("jsv", "BadJSoundFormat"), 
                  "Not a valid JSound doc: Key  does not contain a $type definition.")
          else
            fn:error(QName("jsv", "BadJSoundFormat"), 
              "Not a valid JSound doc: Key " || $k || " in $content must have an object value.")
          
      satisfies $i eq true
    else
      fn:error(QName("jsv", "BadJSoundFormat"), 
              "Not a valid JSound doc: $content definion of object type must be an object.")
  else
    fn:error(QName("jsv", "BadJSoundFormat"), 
             "Not a valid JSound doc: Object type does not contain $content.")
};


declare %private %an:sequential function
jsv:check-array-type($jstypes as object, $type as object) as boolean
{
  (: fn:trace( $type("$name"), "check-array-type"); :)

  (: check all the contents :)
  let $content := $type("$content")
  let $checkContent :=
    if( empty($content) )
    then
      fn:error(QName("jsv", "BadJSoundFormat"), 
        "Not a valid JSound doc: $kind array must have a $content key.")
    else
      if( $content instance of array and jn:size($content) eq 1 )
      then      
      {
        jsv:save-type($jstypes, $type);

        typeswitch( $content(1) )
        case string return
          true
        case object return
            jsv:check-type($jstypes, $content(1))
        default return
          fn:error(QName("jsv", "BadJSoundFormat"), 
            "Not a valid JSound doc: for $kind array, $content[1] must be string or array.")  
      }
      else
        fn:error(QName("jsv", "BadJSoundFormat"), 
          "Not a valid JSound doc: for $kind array, $content must be an array of size 1.")
  
  let $checkMinLength :=
      if( fn:exists($type("$minLength")) )
      then
        if( $type("$minLength") instance of integer  )
        then true
        else fn:error(QName("jsv", "BadJSoundFormat"), 
                      "Not a valid JSound doc: for $kind array, $minLength must be an integer.")
      else true

  let $checkMaxLength :=
      if( fn:exists($type("$maxLength")) )
      then
        if( $type("$maxLength") instance of integer  )
        then true
        else fn:error(QName("jsv", "BadJSoundFormat"), 
                      "Not a valid JSound doc: for $kind array, $maxLength must be an integer.")
      else true
    
  return
    $checkContent and $checkMinLength and $checkMaxLength
};


declare %private %an:sequential function
jsv:check-union-type($jstypes as object, $type as object) as boolean
{
  (: fn:trace( $type("$name"), "check-union-type"); :)

  let $content := $type("$content")
  return
    if( empty($content) )
    then
      fn:error(QName("jsv", "BadJSoundFormat"), 
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
              true
            case object return
                jsv:check-type($jstypes, $c)
            default return
              fn:error(QName("jsv", "BadJSoundFormat"), 
                "Not a valid JSound doc: for $kind union, $content items must be strings or objects.")  
        satisfies $i eq true
      }
      else
        fn:error(QName("jsv", "BadJSoundFormat"), 
          "Not a valid JSound doc: for $kind union, $content must be an array.")
};


declare %private function
jsv:check-ref-type($jstypes as object, $type as string) as boolean
{
  switch( $type )
  case "string" return true
  case "integer" return true
  case "boolean" return true
  case "anyURI"  return true
  default return 
  {
    if( map:has-key($jstypes, $type) )
    then
      true
    else
     (: todo: save all refs, check them at the end to see if they exist :)
     true
  }

  (: todo: apply resolution rules :)
};


declare %private %an:sequential function 
jsv:save-type($jstypes as object, $type as item) as boolean
{  
  switch( false )
  case fn:exists( $type("$name") )
    return false
  case $type("$name") instance of string
    return fn:error(QName("jsv", "BadJSoundFormat"), 
                    "Not a valid JSound doc: for $type, $name must be a string.")
  case map:set-if-empty($jstypes, $type("$name"), $type)
    return fn:error(QName("jsv", "BadJSoundFormat"), 
          "Not a valid JSound doc: type '" || $type("$name") || "' already defined.")
  default return true()
};





(: The validate-xxx functions actualy do the validation of the instance :)


declare %private function 
jsv:validate-instance($jstypes as object, $name as string, $instance as item)
 as boolean
{
  let $type := map:get($jstypes, $name)
  return
    if( exists($type) )
    then
      jsv:validate-type($jstypes, $type, $instance)
    else
      fn:error(QName("jsv", "Invalid"),
             "Requested type name not present in schema: " || $name)
};


declare %private function
jsv:validate-type($jstypes as object, $type as item, $instance as item) as boolean
{
  switch( $type("$kind") )
  case "atomic" return jsv:validate-atomic-type($jstypes, $type, $instance)
  case "object" return jsv:validate-object-type($jstypes, $type, $instance)
  case "array"  return jsv:validate-array-type($jstypes, $type, $instance)
  case "union"  return jsv:validate-union-type($jstypes, $type, $instance)

  default return 
    fn:error(QName("jsv", "BadJSoundFormat"), 
      "Not a valid JSound doc: type $kind unknown:" || $type("$kind") )
};


declare %private function
jsv:validate-type-ref($jstypes as object, $type as string, $instance as item) as boolean
{
  (: todo: check first between the defined types in $jstypes and then the build-in ones, this is per spec :)

  if( map:has-key($jstypes, $type) )
  then
    jsv:validate-type($jstypes, map:get($jstypes, $type), $instance)
  else
    switch( $type )
    case "string" return
      if ( $instance instance of string )
      then
        true 
      else
        fn:error(QName("jsv", "Invalid"), "Expected string value.")
    case "integer" return
      if ( $instance instance of integer or 
           $instance instance of int )
      then
        true
      else
        fn:error(QName("jsv", "Invalid"), "Expected integer value.")
    case "anyURI" return
      if ( $instance instance of anyURI )
      then
        true
      else
        fn:error(QName("jsv", "Invalid"), "Expected anyURI value.")
    case "boolean" return
      if ( $instance instance of boolean )
      then
        true
      else
        fn:error(QName("jsv", "Invalid"), "Expected boolean value.")
        
    default return
        fn:error(QName("jsv", "Invalid"), 
          fn:concat("Type ref not defined or a built-in type: ", $type) )
};


declare %private function
jsv:validate-atomic-type($jstypes as object, $type as object, $instance as item) as boolean
{
  (: fn:trace( $type("$name"), "validate-atomic-type"); :)
  (: todo: check first between the defined types in $jstypes and then the build-in ones, this is per spec :)

  if ( exists($type("$baseType")) and $type("$baseType") instance of string )
  then
    switch( $type("$baseType") )
    case "integer" return
      if ( $instance instance of integer or $instance instance of int )
      then
        jsv:validate-enumeration($jstypes, $type, $instance)
      else
        fn:error(QName("jsv", "Invalid"), "Expected integer or int value")

    case "string" return
      if ( $instance instance of string )
      then
        jsv:validate-enumeration($jstypes, $type, $instance)
      else
        fn:error( QName("jsv", "Invalid"), "Expected string value")

    case "anyURI" return
      if ( $instance instance of anyURI )
      then
        jsv:validate-enumeration($jstypes, $type, $instance)
      else
        fn:error(QName("jsv", "Invalid"), "Expected anyURI value")
        
    case "boolean" return
      if ( $instance instance of boolean )
      then
        jsv:validate-enumeration($jstypes, $type, $instance)
      else
        fn:error(QName("jsv", "Invalid"), "Expected boolean value")
    
    default return
      fn:error(QName("jsv", "NYI"), 
        "$baseType: not yet implemented" || $type("$baseType") )
  else
    fn:error(QName("jsv", "BadJSoundFormat"), 
      "Not a valid JSound doc: atomic type definition must contain '$baseType' key with string value.")
      
  (: todo: add facets checks: length, min/max Inclusive/Exclusive, etc. :)
};

declare %private function
jsv:validate-enumeration($jstypes as object, $type as object, $instance as item) as boolean
{
  variable $enum := $type("$enumeration");
  if( exists($enum) )
  then
    if( $enum instance of array )
    then
      if( some $v in jn:members($enum) satisfies $v eq $instance )
      then 
        true
      else
        fn:error(QName("jsv", "Invalid"), "Instance value not in the enumeration list.")
    else
      fn:error(QName("jsv", "BadJSoundFormat"), 
        "Not a valid JSound doc: the value of '$enumeration' must be an array.")
  else
    true
};

declare %private function
jsv:validate-object-type($jstypes as object, $type as object, $instance as item) as boolean
{ 
  (: fn:trace( $type("$name"), "validate-object-type"); :)
  
  variable $open := $type("$open");
  
  if ( $instance instance of object )
  then 
    if( (not exists($open)) or (exists($open) and $open eq true()) )
    then
      (: object is open: i.e. extra keys alowed but all defined keys must be in 
         the instance except the default and optional ones :)
      (
        every $k in jn:keys($instance) 
        satisfies 
          let $ctype := $type("$content")($k)("$type")
          return     
            typeswitch( $ctype )
            case string return
              jsv:validate-type-ref($jstypes, $ctype, $instance($k) )
            case object return
              jsv:validate-type($jstypes, $ctype, $instance($k) )
            default return
              fn:error(QName("jsv", "BadJSoundFormat"), 
                "Not a valid JSound doc: for $kind object, $content $type must be string or array.")
      ) and 
      (
        every $k in 
          jsv:value-except(jn:keys($type("$content")), jn:keys($instance))
        satisfies
          let $optional := $type("$content")($k)("$optional")
          return 
            if( exists($optional) and $optional eq true )
            then true
            else
              fn:error(QName("jsv", "Invalid"), 
                fn:concat("Required key not present in instance: ", $k) )
      )
    else
      (: object is closed: i.e. all defined keys must be in the instance except 
         the default ones, no extra keys alowed :)
      (
        every $k in jn:keys($instance) 
        satisfies 
          let $ctype := $type("$content")($k)("$type")
          return     
            typeswitch( $ctype )
            case string return
              jsv:validate-type-ref($jstypes, $ctype, $instance($k) )
            case object return
              jsv:validate-type($jstypes, $ctype, $instance($k) )
            default return
              fn:error(QName("jsv", "BadJSoundFormat"), 
                "Not a valid JSound doc: for $kind object, $content $type must be string or array.")
      ) and (
        every $k in (: jn:keys($type("$content")) except jn:keys($instance) :)
          jsv:value-except(jn:keys($type("$content")), jn:keys($instance)) 
        satisfies
          let $optional := $type("$content")($k)("$optional")
          return 
            if( exists($optional) and $optional eq true )
            then true
            else
              fn:error(QName("jsv", "Invalid"),
                fn:concat("Required key not present in instance: ", $k) )
      )
  else
    fn:error( QName("jsv", "Invalid"),
      fn:concat("Instance not an object specified by type: ", jsv:get-type-name($type)) )  
};

declare %private function
jsv:validate-array-type($jstypes as object, $type as object, $instance as item) as boolean
{
  (: fn:trace( $type("$name"), "validate-array-type"); :)

  if( $instance instance of array )
  then
    (: check all the contents :)
    let $content := $type("$content")
    let $validateContent :=
        typeswitch( $content(1) )
        case string return
          every $i in jn:members($instance) satisfies jsv:validate-type-ref($jstypes, $content(1), $i)
        case object return
          every $i in jn:members($instance) satisfies jsv:validate-type($jstypes, $content(1), $i)
        default return
          fn:error(QName("jsv", "BadJSoundFormat"), 
            "Not a valid JSound doc: for $kind array, $content[1] must be string or array.")  
    let $validateMinLength :=
      if( fn:exists($type("$minLength")) )
      then
        if ( $type("$minLength") le size($instance) )
        then true
        else fn:error(QName("jsv", "Invalid"), 
                      "Invalid array size, smaller then $minLength facet constraint.")
      else true
    let $validateMaxLength :=
      if( fn:exists($type("$maxLength")) )
      then
        if( $type("$maxLength") ge size($instance) )
        then true
        else fn:error(QName("jsv", "Invalid"), 
                      "Invalid array size, bigger than $maxLength facet constraint.")
      else true
    return
      $validateContent and $validateMinLength and $validateMaxLength
  else
    fn:error(QName("jsv", "Invalid"), 
      fn:concat("Instance not an array for type: ", jsv:get-type-name($type)) )
    
  (: check array facets :)
};


declare %private function
jsv:validate-union-type($jstypes as object, $type as object, $instance as item) as boolean
{
  let $content := $type("$content")
  return
    if( 
      some $i in 
        for $c in jn:members($content)
        return
          try
          {
            typeswitch( $c )
            case string return
              true
            case object return
                jsv:validate-type($jstypes, $c, $instance)
            default return
              fn:error(QName("jsv", "BadJSoundFormat"), 
                "Not a valid JSound doc: for $kind union, $content items must be strings or objects.")  
          }
          catch Invalid
          {
             false
          }
      satisfies $i eq true
    )
    then true
    else
      fn:error(QName("jsv", "Invalid"), 
        fn:concat("Instance not valid for union type: ", jsv:get-type-name($type)) )
};


(:---- Util functions ---------:)

declare %private function
jsv:get-type-name($type as object) as string
{
  let $name := $type("$name")
  return
    if ( exists($name) and $name instance of string )
    then
      $name
    else
      "N/A"
};


declare %private function 
jsv:value-except($arg1 as xs:anyAtomicType*, $arg2 as xs:anyAtomicType*)  
  as xs:anyAtomicType* 
{      
  (: fn:distinct-values( $arg1[ not($$ eq $arg2) ] ) :)
  fn:distinct-values(
    for $i in $arg1
    where not( some $x in $arg2 satisfies $i eq $x )
    return $i 
  )
};
