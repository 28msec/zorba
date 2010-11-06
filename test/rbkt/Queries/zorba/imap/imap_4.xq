(:~
 : Simple test module for checking basic imap functionalities. 
 : A host/username/password combination that will pass this test needs following:
 : 
 : @author Daniel Thomas
 :)
import module namespace imap = 'http://www.zorba-xquery.com/modules/email/imap';
import module namespace file = 'http://www.zorba-xquery.com/modules/file';
import schema namespace email = 'http://www.zorba-xquery.com/modules/email/email';
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
 : @return true if fetching a message envelope works 
 :)
declare function local:test-fetch-envelope() as xs:boolean {
 (imap:fetch-envelope($local:host-info, "INBOX", xs:long(1), true())/email:from/email:name eq 'root')
};


(:~
 : @return true if fetching a message works 
 :)
declare function local:test-fetch-message() as xs:boolean {
  fn:contains(imap:fetch-message($local:host-info, "INBOX", xs:long(1), true())//email:content, 'test')
};



(:~
 : @return true if fetching a subject works 
 :)
declare function local:test-fetch-subject() as xs:boolean {
 (imap:fetch-subject($local:host-info, "INBOX", xs:long(1)) eq 'test')
};



(:~
 : @return true if fetching a 'from' works
 :)
declare function local:test-fetch-from() as xs:boolean {
  contains(imap:fetch-from($local:host-info, "INBOX", xs:long(1) ), 'root')
};  


declare function local:test-fetch-flags() as xs:boolean {
  deep-equal(imap:fetch-flags($local:host-info, "INBOX", xs:long(1), true())[1]/*[last()], <email:draft/>);

};

declare sequential function local:test-set-flags() as xs:boolean {
  imap:set-flags($local:host-info, "INBOX", xs:long(2), <email:flags><email:answered/></email:flags>, true());
  deep-equal(imap:fetch-flags($local:host-info, "INBOX", xs:long(2), true())[1]/*[last()], <email:answered/>);


 
};


declare sequential function local:main() as xs:string* {

  let $a := local:test-fetch-envelope()
  return
    if (fn:not($a)) then
      exit returning local:error(("Fetching the envelope of a message failed."))
    else ();

  let $b := local:test-fetch-message()
  return
    if (fn:not($b)) then
      exit returning local:error(("Fetching a message failed."))
    else ();


  let $c := local:test-fetch-subject()
  return
    if (fn:not($c)) then
      exit returning local:error(("Fetching a message subject failed."))
    else ();


  let $d := local:test-fetch-from()
  return
    if (fn:not($d)) then
      exit returning local:error(("Fetching a message 'from' failed."))
    else ();


  let $e := local:test-fetch-flags()
  return 
    if (fn:not($e)) then
      exit returning local:error(("Fetching flags failed"))
    else ();

  (: clear all flags for message 2 :)
 
  imap:set-flags($local:host-info, "INBOX", xs:long(2), <email:flags></email:flags>, true());


  let $f := local:test-set-flags()
  return 
    if (fn:not($f)) then
      exit returning local:error(("Setting flags failed"))
    else ();

    

 (: If all went well ... make sure the world knows! :)  
  "SUCCESS"; 



};

local:main();



