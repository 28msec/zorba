xquery version "3.0";

 (:
  : Copyright 2006-2009 The FLWOR Foundation.
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
  :
  : <p>In order to enable JSON processing with XQuery, Zorba implements a set
  : of functions that open XQuery developers the door to process JSON
  : data. Specifically, this module provides two types of functions. Functions
  : to:
  : <ul>
  :   <li>parse JSON and convert it to XDM and</li>
  :   <li>serialize XDM in order to output JSON.</li>
  : </ul>
  : </p>
  :
  : <p>Both types of functions are available to parse and serialize two
  : types of XDM-JSON mappings:<ul><li>the first mapping called in this document 
  : <strong>simple XDM-JSON</strong> has been
  : <a href="http://john.snelson.org.uk/parsing-json-into-xquery">
  : proposed by John Snelson</a></li><li>the second mapping is called 
  : <a href="http://jsonml.org/">JsonML</a></li></ul>In the following, we
  : briefly describe both mappings.</p>
  : 
  : <h2>Simple XDM-JSON Mapping</h2>
  : <ul><li>In order to process JSON with XQuery, Zorba implements a mapping between
  : JSON and XML that was initially proposed by John Snelson in his article
  : <a href="http://snelson.org.uk/archives/2008/02/parsing_json_in.php#more"
  : target="_blank">Parsing JSON into XQuery</a></li></ul>
  :
  : <h2>JsonML Mapping</h2>
  : <ul>
  : <li><a href="http://jsonml.org" target="_blank">JSonML</a> (JSON Markup Language)
  : is an application of the JSON format.</li>
  : <li>The purpose of JSonML is to provide a compact format for transporting
  : XML-based markup as JSon. In contrast to the <strong>simple XDM-JSON</strong> mapping described above
  : <strong>JsonML</strong> allows a lossless conversion back and forth.</li></ul>
  :
  : @author Sorin Nasoi
  :
  : @see <a href="http://john.snelson.org.uk/parsing-json-into-xquery">Mapping proposed by John Snelson</a>
  : @see <a href="http://jsonml.org" target="_blank">JSonML</a>
  : @project data processing/data converters
  :
  :)
module namespace json = "http://www.zorba-xquery.com/modules/converters/json";

import module namespace schema = "http://www.zorba-xquery.com/modules/schema";

import schema namespace json-options = "http://www.zorba-xquery.com/modules/converters/json-options";

declare namespace err = "http://www.w3.org/2005/xqt-errors";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "2.0";

(:~
 : This function parses a JSON string and returns an XDM instance according
 : to either one of the mappings described above.
 :
 : @param $arg a sequence of valid JSON strings.
 : @param $options a set of name and value pairs that provide options
 :        to configure the JSON mapping process that have to be validated against the 
 :        "http://www.zorba-xquery.com/modules/converters/json-options" schema.
 : @return  a sequence of nodes according to either one of the mappings described above.
 : @error err:XQDY0027 if $options can not be validated against the json-options schema
 : @error json:ParseError if the JSON string passed as parameter is not
 :    valid JSON.
 : @example test_json/Queries/converters/jansson/parse_json_02.xq
 : @example test_json/Queries/converters/jansson/parse_json_ml_01.xq
 :)
declare function json:parse(
  $arg as xs:string?,
  $options as element(json-options:options)
) as element(*, xs:untyped)*
{
  let $validated-options := if(schema:is-validated($options)) then
                                $options
                              else
                                validate{$options} 
  return
    json:parse-internal($arg, $validated-options)
};

(:~
 : This function parses a JSON string and returns an XDM instance according
 : to simple XDM-JSON mapping described above.
 :
 : @param $arg a sequence of valid JSON strings.
 : @return a sequence of nodes according to Simple XDM-JSON mapping described above.
 : @error json:ParseError if the JSON string passed as parameter is not
 :    valid JSON.
 : @example test_json/Queries/converters/jansson/parse_json_11.xq
 :)
declare function json:parse(
  $arg as xs:string?
) as element(*, xs:untyped)*
{
  json:parse-internal($arg,
    validate {
      <options xmlns="http://www.zorba-xquery.com/modules/converters/json-options" >
        <json-param name="mapping" value="simple-json" />
      </options>
    }
  )
};

(:~
 : This function parses a JSON string and returns an XDM instance according
 : to JsonML mapping described above.
 :
 : @param $arg a sequence of valid JSON strings.
 : @return  a sequence of nodes according the JSON-ML mapping described above.
 : @error json:ParseError if the JSON string passed as parameter is not
 :    valid JSON.
 : @example test_json/Queries/converters/jansson/parse_json_ml_05.xq
 :)
declare function json:parse-ml(
  $arg as xs:string?
) as element(*, xs:untyped)*
{
  json:parse-internal($arg,
    validate {
      <options xmlns="http://www.zorba-xquery.com/modules/converters/json-options" >
        <json-param name="mapping" value="json-ml" type="array"/>
      </options>
    }
  )
};

declare %private function json:parse-internal(
  $html as xs:string,
  $options as item()?
) as element()* external;


(:~
 : The serialize function takes a sequence of nodes as parameter and
 : transforms each element into a valid JSON string according to one of the
 : mappings described above.
 :
 : @param $xml a sequence of nodes.
 : @param $options a set of name and value pairs that provide options
 :        to configure the JSON mapping process that have to be validated against the 
 :        "http://www.zorba-xquery.com/modules/converters/json-options" schema.
 : @return a JSON string.
 : @error err:XQDY0027 if $options can not be validated against the json-options schema
 : @error json:InvalidXDM if the input $xml is not a valid XDM
 :  representation of JSON or JSON ML.
 : @example test_json/Queries/converters/jansson/serialize_json_01.xq
 : @example test_json/Queries/converters/jansson/serialize_json_ml_01.xq
 :)
declare function json:serialize(
  $xml as item()*, 
  $options as element(json-options:options) 
) as xs:string
{
  let $validated-options := if(schema:is-validated($options)) then
                              $options
                            else
                              validate{$options} 
  return
    json:serialize-internal($xml, $validated-options)
};

(:~
 : The serialize function takes a sequence of nodes as parameter and
 : transforms each element into a valid JSON string according to the
 : Simple XDM-JSON mapping described above
 :
 : @param $xml a sequence of nodes.
 : @return a JSON string.
 : @error json:InvalidXDM if the input $xml is not a valid XDM
 :  representation of JSON or JSON ML.
 : @example test_json/Queries/converters/jansson/serialize_json_18.xq
 :)
declare function json:serialize(
  $xml as item()* 
) as xs:string
{
  json:serialize-internal($xml,
    validate {
      <options xmlns="http://www.zorba-xquery.com/modules/converters/json-options" >
        <json-param name="mapping" value="simple-json" />
      </options>
   }
 )
};

(:~
 : The serialize function takes a sequence of nodes as parameter and
 : transforms each element into a valid JSON string according to the
 : JsonML mapping described above.
 :
 : @param $xml a sequence of nodes.
 : @return a JSON string.
 : @error json:InvalidXDM if the input $xml is not a valid XDM
 :  representation of JSON or JSON ML.
 : @example test_json/Queries/converters/jansson/serialize_json_ml_04.xq
 :)
declare function json:serialize-ml(
  $xml as item()* 
) as xs:string
{
  json:serialize-internal($xml,
    validate {
      <options xmlns="http://www.zorba-xquery.com/modules/converters/json-options" >
       <json-param name="mapping" value="json-ml" type="array"/>
      </options>
   }
 )
};

declare %private function json:serialize-internal(
  $xml as item()*,
  $options as item()?
  ) as xs:string external;
