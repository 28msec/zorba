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
 : This library module provides simple unit conversion operations.
 : The logic contained in this module is not specific to any particular XQuery implementation.
 :
 : @author Bruno Martins
 :)

module namespace conversion = "http://www.zorba-xquery.com/modules/data-cleaning/conversion";

import module namespace err  = "http://www.zorba-xquery.com/modules/data-cleaning/error";

declare namespace exref = "http://www.ecb.int/vocabulary/2002-08-01/eurofxref";

(:~
 : Unit conversion function, acting as a wrapper over the CuppaIT WebService.
 : <br/>
 : WebService documentation at http://www.cuppait.com/UnitConversionGateway-war/UnitConversion?format=XML
 :
 : <br/>
 : Example usage : <pre> conversion:unitconvert ( 1 , "Distance", "mile", "kilometer" ) </pre>
 : <br/>
 : Returns : <pre> 1.609344 </pre>
 :
 : @param $v The amount we wish to convert.
 : @param $t The type of metric (e.g., "Distance")
 : @param $m1 The source unit metric (e.g., "meter")
 : @param $m2 The target unit metric (e.g., "mile")
 : @return The value resulting from the conversion
 : @error Returns err:notsupported if the type of metric, the source unit or the target unit are not known to the service.
 : @see http://www.cuppait.com/UnitConversionGateway-war/UnitConversion?format=XML
 :)
declare function conversion:unitconvert ( $v as xs:double, $t as xs:string, $m1 as xs:string, $m2 as xs:string ) {
 let $url     := "http://www.cuppait.com/UnitConversionGateway-war/UnitConversion?format=XML"
 let $ctype   := concat("ctype=",$t)
 let $cfrom   := concat("cfrom=",$m1)
 let $cto     := concat("cto=",$m2)
 let $camount := concat("camount=",$v)
 let $par     := string-join(($url,$ctype,$cfrom,$cto,$camount),"&amp;")
 let $result  := doc($par)
 return if (matches(data($result),"-?[0-9]+(\.[0-9]+)?")) then data($result) 
        else fn:error($err:notsupported, data($result))
};

(:~
 : Place name to geospatial coordinates converter, acting as a wrapper over the Yahoo! geocoder service.
 :
 : @param $q Sequence os strings with the different parts (e.g., street, city, country, etc.) of the place name.
 : @return Pair of latitude and longitude coordinates.
 :)
declare function conversion:geocode ( $q as xs:string* ) as xs:double* {
 let $id   := ""
 let $url  := "http://where.yahooapis.com/geocode?q="
 let $q2   := string-join(for $i in $q return translate($i," ","+"),",")
 let $call := concat($url,$q2,"&amp;appid=",$id)
 let $doc  := doc($call)
 return    ( $doc//*:latitude/xs:double(text()) , $doc//*:longitude/xs:double(text()) )
};

(:~
 : Geospatial coordinates to place name converter, acting as a wrapper over the Yahoo! reverse geocoder service.
 :
 : @param $lat Geospatial latitude.
 : @param $lon Geospatial longitude.
 : @return Pair of latitude and longitude coordinates.
 :)
declare function conversion:reversegeocode ( $lat as xs:double, $lon as xs:double ) as xs:string* {
 let $id   := ""
 let $url  := "http://where.yahooapis.com/geocode?q="
 let $q    := concat($lat,",+",$lon) 
 let $call := concat($url,$q,"&amp;gflags=R&amp;appid=",$id)
 let $doc    := doc($call)
 return distinct-values(($doc//xs:string(*:country),
                         $doc//xs:string(*:state),
                         $doc//xs:string(*:county),
                         $doc//xs:string(*:city), 
                         $doc//xs:string(*:neighborhood),
                         $doc//xs:string(*:street),
                         $doc//xs:string(*:house)) )
};