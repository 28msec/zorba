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

module namespace guestbook = "http://www.28msec.com/template/guestbook/guestbook";

declare namespace ann = "http://www.zorba-xquery.com/annotations"; 

import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
declare ordered collection guestbook:entries as node()*;
declare variable $guestbook:entries as xs:QName := xs:QName('guestbook:entries');

declare %ann:sequential function guestbook:add()
{
  dml:insert-nodes-last(
      $guestbook:entries,
      <entry author='blub' date='{fn:current-date()}' time='{fn:current-time()}'>
       test
      </entry>
  );
  exit returning guestbook:list();
};

declare %ann:sequential function guestbook:list() 
{  
  let $entries := dml:collection($guestbook:entries)
  let $num_entries := fn:count($entries)
  return 
    if($num_entries = 0)
    then    
      <div style='color:green;' class='entry'><b>No entries, yet.</b></div>
    else
      for $entry at $pos in $entries[position() gt $num_entries - 5]
      let $numbering := if ($num_entries lt 5) then $pos else $num_entries - ( 5 - $pos) 
      return 
        <div class='entry'>
          <b style='color:green;'>{fn:data($entry/@date)} -- {fn:data($entry/@time)}</b>{' '}<b>
             {fn:data($entry/@author)}</b><br/>
          <span style='float:left;color: #aaaaaa;'>{ $numbering  }</span>
          {$entry/text()}
        </div>
};
