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
 : @return true if the imap:suscribe function works.
 :)
declare sequential function local:test-suscribe() as xs:boolean {
  let $x := imap:subscribe($local:host-info, "INBOX.Test") 
  return local:exists-suscribed("INBOX.Test")
};

(:~
 : @return true if the imap:unsuscribe function works.
 :)
declare sequential function local:test-unsuscribe() as xs:boolean {
  let $x := imap:unsubscribe($local:host-info, "INBOX.Test")
  return local:not-exists-suscribed("INBOX.Test")
};

(:~
 : @return true if the imap:fetch-subject function works.
 :)
declare function local:test-fetch-subject() as xs:boolean {
  let $x := imap:fetch-subject($local:host-info, "INBOX", xs:long(1))
  return ($x eq "test")
};

(:~
 : @return true if the imap:fetch-from function works.
 :)
declare function local:test-fetch-from() as xs:boolean {
  let $x := imap:fetch-from($local:host-info, "INBOX", xs:long(1))
  return (fn:starts-with($x, "root"))
};



declare function local:exists-suscribed($mailbox as xs:string) as xs:boolean {
  let $list := imap:list($local:host-info, "", $mailbox, true())
  return not (empty($list))
};

declare function local:not-exists-suscribed($mailbox as xs:string) as xs:boolean {
   let $list := imap:list($local:host-info, "", $mailbox, true())
   return empty($list) 
};


declare sequential function local:main() as xs:string* {

  (: make very, very sure there is an INBOX.Test :)
  if (empty (imap:list($local:host-info, "", "INBOX.Test", false()))) then
    imap:create($local:host-info, "INBOX.Test")
  else ();
 

  let $a := local:test-suscribe()
  return
    if (fn:not($a)) then
      exit returning local:error(("Retrieving status of mailbox failed."))
    else ();
 
  (: make sure to unsuscribe from INBOX.test :) 
  
  let $b := local:test-unsuscribe()
  return
    if (fn:not($b)) then
      exit returning local:error(("Retrieving list of mailboxes failed."))
    else ();


  (: make very, very sure to delete INBOX.Test :) 
  if (not (empty (imap:list($local:host-info, "", "INBOX.Test", false())))) then
    imap:delete($local:host-info, "INBOX.Test")
  else ();
 

  let $c := local:test-fetch-subject()
  return
    if (fn:not($c)) then
      exit returning local:error(("Fetching subject of a message failed."))
    else ();
 

  let $d := local:test-fetch-from()
  return
    if (fn:not($d)) then
      exit returning local:error(("Fetching 'from' string of a message failed."))
    else ();

 
   
  (: If all went well ... make sure the world knows! :)  
  "SUCCESS";



};

local:main();



