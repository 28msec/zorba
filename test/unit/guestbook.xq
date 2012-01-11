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

module namespace guestbook = "http://www.28msec.com/templates/guestbook/guestbook";

import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";

declare namespace ann = "http://www.zorba-xquery.com/annotations"; 

declare %ann:ordered collection guestbook:entries as node()*;
declare variable $guestbook:entries as xs:QName := xs:QName("guestbook:entries");

declare %ann:sequential function guestbook:list() 
{  
  let $entries := dml:collection($guestbook:entries)
  let $num_entries := fn:count($entries)
  return 
    if($num_entries = 0)
    then    
      <div style="color:green;" class="entry"><b>No entries, yet.</b></div>
    else
      for $entry in $entries[position() gt $num_entries - 5]
      return  1
};

declare function guestbook:window() {
 let $x := 1 to 1000
 for tumbling window $w in $x
 start at $s when fn:true()
 end at $e when $e - $s eq 51
 return <window>{ $w }</window>
};


declare %ann:sequential function guestbook:init() {
  ddl:create($guestbook:entries);
};
