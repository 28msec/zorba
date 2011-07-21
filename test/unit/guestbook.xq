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

declare %ann:sequential function guestbook:init() {
  ddl:create-collection($guestbook:entries);
};
