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
 : @return true if the imap:status function works.
 :)
declare function local:test-status() as xs:boolean {
    let $status := imap:status($local:host-info, "INBOX")
    return (xs:int($status/messages/text()) >= 2) 
};

(:~
 : @return true if the imap:list function works.
 :)
declare sequential function local:test-list() as xs:boolean {
    let $list := imap:list($local:host-info, "", "INBOX.Draft*", false())
    return ($list/mailboxName/text() eq  "INBOX.Drafts")
};


(:~
 : @return true if the imap:create function works.
 :)
declare sequential function local:test-create() as xs:boolean {
    imap:create($local:host-info, "INBOX.Test") 
};

(:~
 : @return true if the imap:create function works.
 :)
declare sequential function local:test-delete() as xs:boolean {
    imap:delete($local:host-info, "INBOX.Test") 
};


declare sequential function local:test-rename() as xs:boolean {
  imap:rename($local:host-info, "INBOX.Test", "INBOX.Test2")
};

(:~
 : Utility function which tests if the passed mailbox exists on the host.
 :)
declare function local:exists($mailbox as xs:string) as xs:boolean {
  let $list := imap:list($local:host-info, "", $mailbox, false())
  return not (empty($list))
};

declare function local:not-exists($mailbox as xs:string) as xs:boolean {
   let $list := imap:list($local:host-info, "", $mailbox, false())
   return empty($list) 
};


declare sequential function local:main() as xs:string* {

  let $a := local:test-status()
  return
    if (fn:not($a)) then
      exit returning local:error(("Retrieving status of mailbox failed."))
    else ();
  
  
  let $b := local:test-list()
  return
    if (fn:not($b)) then
      exit returning local:error(("Retrieving list of mailboxes failed."))
    else ();


    (: makes very, very sure there is no INBOX.Test :)
    if (local:exists("INBOX.Test")) then
      imap:delete($local:host-info, "INBOX.Test")
    else ();



  let $c := local:test-create()
  return
    if (fn:not($c)) then
      exit returning local:error(("Creating mailbox failed."))
    else (); 
  

  
   (: make very, very sure there is a  INBOX.Test :)
  if (local:not-exists("INBOX.Test")) then
    imap:create($local:host-info, "INBOX.Test")
  else ();

    
 
  let $d := local:test-delete()
  return
    if (fn:not($d)) then
      exit returning local:error(("Deleting mailbox failed."))
    else ();

  (: make very, very sure there is a INBOX.Test :)
  if (local:not-exists("INBOX.Test")) then
    imap:create($local:host-info, "INBOX.Test")
  else ();

  
  (: make very, very sure there is no  INBOX.Test2 :)
  if (local:exists("INBOX.Test2")) then
    imap:delete($local:host-info, "INBOX.Test2")
  else ();



  let $e := local:test-rename()
  return
     if (fn:not($e)) then
      exit returning local:error(("Renaming mailbox failed."))
     else ();

  (: makes very, very sure  to delete the INBOX.Test again :)
  if (local:exists("INBOX.Test")) then
    imap:delete($local:host-info, "INBOX.Test")
  else ();

  (: make very, very sure there is no  INBOX.Test2 :)
  if (local:exists("INBOX.Test2")) then
    imap:delete($local:host-info, "INBOX.Test2")
  else ();


  
   
  (: If all went well ... make sure the world knows! :)  
  "SUCCESS";



};

local:main();



