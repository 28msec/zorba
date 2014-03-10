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
 : JSound (JSON schema) validator.
 :
 : @author Paul J. Lucas
 :)

module namespace jsd = "http://jsound.io/modules/jsound"; 

declare namespace jse = "http://jsound.io/errors";

declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "1.0";

(:===========================================================================:)

(:~
 : Annotates the given JSON object against the given JSound schema type.
 :
 : @param $jsd The JSound schema to use.
 : @param $type-name The name of the type in the schema to annotate against.
 : @param $item The JSON item to annotate.
 : @param $options The options to use:
 :  <dl>
 :    <dt><code>cast-atomic-values</code></dt>
 :      <dd>
 :        Whether to attempt to cast atomic values to the type specified by
 :        the schema;
 :        default: <code>false</code>.
 :        <p/>
 :        If <code>false</code> and the type of a value is not the type
 :        or subtype of the type
 :        specified by the schema,
 :        then the value is invalid.
 :        <p/>
 :        If <code>true</code> and the type of a value is not the type
 :        or subtype of the type
 :        specified by the schema,
 :        then an attempt will be made to cast the value to the specified type.
 :        If successful,
 :        the annotated value will be of the specified type;
 :        if unsuccessful,
 :        then the value is invalid.
 :      </dd>
 :  </dl>
 : @return Returns a (possibly annotated) version of <code>$item</code>.
 : If <code>$item</code> is valid against the schema,
 : the result will be a copy of <code>$item</code> with default values, if any,
 : filled in.
 : If <code>$item</code> is not valid,
 : the result will be a copy of <code>$item</code> except each invalid item
 : will be replaced by an object of the form:
 :  <pre>
 :    {
 :      "$invalid" : "true",
 :      "$expected" : type-name,
 :      "$value" : invalid-value,
 :      "$reason" : "reason the item is invalid"
 :    }
 :  </pre>
 : @error jse:DUPLICATE_PREFIX The prefix specified in the value of a
 : <code>$prefix</code> key of an <code>$imports</code> object has already been
 : used.
 : @error jse:DUPLICATE_TYPE The type name specified in the value of a
 : <code>$name</code> key of a type object has already been used.
 : @error jse:ILLEGAL_ARRAY_SIZE The value of a <code>$content</code> facet of
 : an array must be an array with exactly one element.
 : @error jse:ILLEGAL_BASE_TYPE
 : @error jse:ILLEGAL_FACET The given facet is illegal for the current kind of
 : object.
 : @error jse:ILLEGAL_FACET_VALUE The value for a given facet is illegal.
 : @error jse:ILLEGAL_KEY The given key is illegal for the current type or
 : field descriptor.
 : @error jse:ILLEGAL_NAMESPACE An explicit namespace given for the value of a
 : <code>$name</code> key must match the schema namespace.
 : @error jse:ILLEGAL_PREFIX The value given for the <code>$prefix</code> key
 : is illegal (must not contain a <code>':'</code>).
 : @error jse:ILLEGAL_SCHEMA The schema at the given <code>$location</code>
 : (if any) is illegal.
 : @error jse:ILLEGAL_TYPE The type of the value given for the
 : <code>$type</code> key is illegal.
 : @error jsr:INVALID_OPTION An option is invalid.
 : @error jse:MISSING_KEY A required key is missing.
 : @error jse:NEW_KEY_NOT_ALLOWED A derived object type contains a key not
 : present in one of its base types and the value of the <code>$open</code>
 : facet is false.
 : @error jse:SCHEMA_NOT_FOUND The schema specified by the given
 : <code>$namespace</code> (and possible <code>$location</code>) is not found.
 : @error jse:TYPE_MISMATCH The type of a value for a given key is not the
 : expected type.
 : @error jse:UNKNOWN_PREFIX The prefix given as part of a type name is
 : unknown.
 : @error jse:UNKNOWN_TYPE The type specified for the value of the
 : <code>$type</code> key is unknown.
 :)
declare function jsd:annotate( $jsd as object, $type-name as string,
                               $item as item, $options as object )
 as item external;

(:~
 : Annotates the given JSON object against the given JSound schema type
 : using the default options of:
 :  <dl>
 :    <dt><code>cast-atomic-values</code></dt>
 :      <dd><code>false</code></dd>
 :  </dl>
 :
 : @param $jsd The JSound schema to use.
 : @param $type-name The name of the type in the schema to annotate against.
 : @param $item The JSON item to annotate.
 : @return Returns a (possibly annotated) version of <code>$item</code>.
 : If <code>$item</code> is valid against the schema,
 : the result will be a copy of <code>$item</code> with default values, if any,
 : filled in.
 : If <code>$item</code> is not valid,
 : the result will be a copy of <code>$item</code> except each invalid item
 : will be replaced by an object of the form:
 :  <pre>
 :    {
 :      "$invalid" : "true",
 :      "$expected" : type-name,
 :      "$value" : invalid-value,
 :      "$reason" : "reason the item is invalid"
 :    }
 :  </pre>
 : @error jse:DUPLICATE_PREFIX The prefix specified in the value of a
 : <code>$prefix</code> key of an <code>$imports</code> object has already been
 : used.
 : @error jse:DUPLICATE_TYPE The type name specified in the value of a
 : <code>$name</code> key of a type object has already been used.
 : @error jse:ILLEGAL_ARRAY_SIZE The value of a <code>$content</code> facet of
 : an array must be an array with exactly one element.
 : @error jse:ILLEGAL_BASE_TYPE
 : @error jse:ILLEGAL_FACET The given facet is illegal for the current kind of
 : object.
 : @error jse:ILLEGAL_FACET_VALUE The value for a given facet is illegal.
 : @error jse:ILLEGAL_KEY The given key is illegal for the current type or
 : field descriptor.
 : @error jse:ILLEGAL_NAMESPACE An explicit namespace given for the value of a
 : <code>$name</code> key must match the schema namespace.
 : @error jse:ILLEGAL_PREFIX The value given for the <code>$prefix</code> key
 : is illegal (must not contain a <code>':'</code>).
 : @error jse:ILLEGAL_SCHEMA The schema at the given <code>$location</code>
 : (if any) is illegal.
 : @error jse:ILLEGAL_TYPE The type of the value given for the
 : <code>$type</code> key is illegal.
 : @error jse:MISSING_KEY A required key is missing.
 : @error jse:NEW_KEY_NOT_ALLOWED A derived object type contains a key not
 : present in one of its base types and the value of the <code>$open</code>
 : facet is false.
 : @error jse:SCHEMA_NOT_FOUND The schema specified by the given
 : <code>$namespace</code> (and possible <code>$location</code>) is not found.
 : @error jse:TYPE_MISMATCH The type of a value for a given key is not the
 : expected type.
 : @error jse:UNKNOWN_PREFIX The prefix given as part of a type name is
 : unknown.
 : @error jse:UNKNOWN_TYPE The type specified for the value of the
 : <code>$type</code> key is unknown.
 :)
declare function jsd:annotate( $jsd as object, $type-name as string,
                               $item as item )
  as item
{
  let $options := { "cast-atomic-values" : false }
  return jsd:annotate( $jsd, $type-name, $item, $options )
};

(:~
 : Validates the given JSON object against the given JSound schema type.
 :
 : @param $jsd The JSound schema to validate against.
 : @param $type-name The name of the type in the schema to validate against.
 : @param $item The JSON item to validate.
 : @param $options The options to use:
 :  <dl>
 :    <dt><code>cast-atomic-values</code></dt>
 :      <dd>
 :        Whether to attempt to cast atomic values to the type specified by
 :        the schema;
 :        default: <code>false</code>.
 :        <p/>
 :        If <code>false</code> and the type of a value is not the type
 :        or subtype of the type
 :        specified by the schema,
 :        then the value is invalid.
 :        <p/>
 :        If <code>true</code> and the type of a value is not the type
 :        or subtype of the type
 :        specified by the schema,
 :        then an attempt will be made to cast the value to the specified type.
 :        If successful,
 :        the annotated value will be of the specified type;
 :        if unsuccessful,
 :        then the value is invalid.
 :      </dd>
 :  </dl>
 : @return <code>true</code> only if <code>$item</code> is valid.
 : @error jse:DUPLICATE_PREFIX The prefix specified in the value of a
 : <code>$prefix</code> key of an <code>$imports</code> object has already been
 : used.
 : @error jse:DUPLICATE_TYPE The type name specified in the value of a
 : <code>$name</code> key of a type object has already been used.
 : @error jse:ILLEGAL_ARRAY_SIZE The value of a <code>$content</code> facet of
 : an array must be an array with exactly one element.
 : @error jse:ILLEGAL_BASE_TYPE
 : @error jse:ILLEGAL_FACET The given facet is illegal for the current kind of
 : object.
 : @error jse:ILLEGAL_FACET_VALUE The value for a given facet is illegal.
 : @error jse:ILLEGAL_KEY The given key is illegal for the current type or
 : field descriptor.
 : @error jse:ILLEGAL_NAMESPACE An explicit namespace given for the value of a
 : <code>$name</code> key must match the schema namespace.
 : @error jse:ILLEGAL_PREFIX The value given for the <code>$prefix</code> key
 : is illegal (must not contain a <code>':'</code>).
 : @error jse:ILLEGAL_SCHEMA The schema at the given <code>$location</code>
 : (if any) is illegal.
 : @error jse:ILLEGAL_TYPE The type of the value given for the
 : <code>$type</code> key is illegal.
 : @error jsr:INVALID_OPTION An option is invalid.
 : @error jse:MISSING_KEY A required key is missing.
 : @error jse:NEW_KEY_NOT_ALLOWED A derived object type contains a key not
 : present in one of its base types and the value of the <code>$open</code>
 : facet is false.
 : @error jse:SCHEMA_NOT_FOUND The schema specified by the given
 : <code>$namespace</code> (and possible <code>$location</code>) is not found.
 : @error jse:TYPE_MISMATCH The type of a value for a given key is not the
 : expected type.
 : @error jse:UNKNOWN_PREFIX The prefix given as part of a type name is
 : unknown.
 : @error jse:UNKNOWN_TYPE The type specified for the value of the
 : <code>$type</code> key is unknown.
 :)
declare function jsd:validate( $jsd as object, $type-name as string,
                               $item as item, $options as object )
 as boolean external;

(:~
 : Validates the given JSON object against the given JSound schema type
 : using the default options of:
 :  <dl>
 :    <dt><code>cast-atomic-values</code></dt>
 :      <dd><code>false</code></dd>
 :  </dl>
 :
 : @param $jsd The JSound schema to validate against.
 : @param $type-name The name of the type in the schema to validate against.
 : @param $item The JSON item to validate.
 : @return <code>true</code> only if <code>$item</code> is valid.
 : @error jse:DUPLICATE_PREFIX The prefix specified in the value of a
 : <code>$prefix</code> key of an <code>$imports</code> object has already been
 : used.
 : @error jse:DUPLICATE_TYPE The type name specified in the value of a
 : <code>$name</code> key of a type object has already been used.
 : @error jse:ILLEGAL_ARRAY_SIZE The value of a <code>$content</code> facet of
 : an array must be an array with exactly one element.
 : @error jse:ILLEGAL_BASE_TYPE
 : @error jse:ILLEGAL_FACET The given facet is illegal for the current kind of
 : object.
 : @error jse:ILLEGAL_FACET_VALUE The value for a given facet is illegal.
 : @error jse:ILLEGAL_KEY The given key is illegal for the current type or
 : field descriptor.
 : @error jse:ILLEGAL_NAMESPACE An explicit namespace given for the value of a
 : <code>$name</code> key must match the schema namespace.
 : @error jse:ILLEGAL_PREFIX The value given for the <code>$prefix</code> key
 : is illegal (must not contain a <code>':'</code>).
 : @error jse:ILLEGAL_SCHEMA The schema at the given <code>$location</code>
 : (if any) is illegal.
 : @error jse:ILLEGAL_TYPE The type of the value given for the
 : <code>$type</code> key is illegal.
 : @error jse:MISSING_KEY A required key is missing.
 : @error jse:NEW_KEY_NOT_ALLOWED A derived object type contains a key not
 : present in one of its base types and the value of the <code>$open</code>
 : facet is false.
 : @error jse:SCHEMA_NOT_FOUND The schema specified by the given
 : <code>$namespace</code> (and possible <code>$location</code>) is not found.
 : @error jse:TYPE_MISMATCH The type of a value for a given key is not the
 : expected type.
 : @error jse:UNKNOWN_PREFIX The prefix given as part of a type name is
 : unknown.
 : @error jse:UNKNOWN_TYPE The type specified for the value of the
 : <code>$type</code> key is unknown.
 :)
declare function jsd:validate( $jsd as object, $type-name as string,
                               $item as item )
  as boolean
{
  let $options := { "cast-atomic-values" : false }
  return jsd:validate( $jsd, $type-name, $item, $options )
};

(:===========================================================================:)

(: vim:set syntax=xquery et sw=2 ts=2: :)
