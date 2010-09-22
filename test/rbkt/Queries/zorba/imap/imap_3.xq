(:~
 : Simple test module for checking basic imap functionalities. 
 : A host/username/password combination that will pass this test needs following:
 : 
 : * INBOX with at least 2 messages.
 : 
 :
 : @author Daniel Thomas
 :)
import module namespace imap = 'http://www.zorba-xquery.com/modules/email/imap';
import module namespace file = 'http://www.zorba-xquery.com/modules/file';
import schema namespace imaps = 'http://www.zorba-xquery.com/modules/email/imap';

(:~
 : Defines the host info including the name of the host, username and password for a specific user.
 :)
declare variable $local:host-info as element(imaps:hostInfo) := (<imaps:hostInfo><hostName>mail.28msec.com/novalidate-cert</hostName><userName>imaptest</userName><password>cclient</password></imaps:hostInfo>);



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
 : @return true if a search for ALL works.
 :)
declare function local:test-simple-search() as xs:boolean {
  let $x := imap:search($local:host-info, "INBOX", "ALL", false()) 
  return not(empty($x)) 
};


declare function local:test-search-subject() as xs:boolean {
  not(empty(imap:search($local:host-info, "INBOX", "SUBJECT test", false())))
};


declare sequential function local:main() as xs:string* {


  let $a := local:test-simple-search()
  return
    if (fn:not($a)) then
      exit returning local:error(("Searching for ALL failed ."))
    else ();


  let $b := local:test-search-subject()
  return
    if (fn:not($b)) then
      exit returning local:error(("Searching for word in SUBJECT failed."))
    else ();




   
  (: If all went well ... make sure the world knows! :)  
  "SUCCESS";



};

local:main();



