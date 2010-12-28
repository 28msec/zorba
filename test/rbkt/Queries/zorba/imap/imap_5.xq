(:~
 : Simple test module for checking basic imap functionalities. 
 : A host/username/password combination that will pass this test needs following:
 : 
 : @author Daniel Thomas
 :)
import module namespace imap = 'http://www.zorba-xquery.com/modules/email/imap';
import module namespace file = 'http://www.zorba-xquery.com/modules/file';
import module namespace smtp = 'http://www.zorba-xquery.com/modules/email/smtp'; 
import schema namespace email = 'http://www.zorba-xquery.com/modules/email/email';
import schema namespace imaps = 'http://www.zorba-xquery.com/modules/email/imap';

declare variable $local:sender-host-info as element(imaps:hostInfo) := (<imaps:hostInfo><hostName>smtp.gmail.com:587/tls/novalidate-cert</hostName><userName
>zorba.smtp.sender</userName><password>1openssl!</password></imaps:hostInfo>);

declare variable $local:receiver-host-info as element(imaps:hostInfo) := (<imaps:hostInfo><hostName>mail.28msec.com/novalidate-cert</hostName><userName>imaptest</userName><password>cclient</password></imaps:hostInfo>);



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
 : @return true if deleting a message previously sent works 
 :)
declare sequential function local:test-delete() as xs:boolean {
    let $complying-unique-ids as xs:long* := imap:search($local:receiver-host-info, "INBOX", "SUBJECT delete", true())
    (: if there are no emails to delete, then the send function of the smtp library is probably not working, or the expunge is working excellently ... :)
    return if (empty($complying-unique-ids)) then true()
           else
              let $all-flags-set as xs:boolean* := for $id in $complying-unique-ids return imap:set-flags($local:receiver-host-info, "INBOX", $id, <email:flags><deleted/></email:flags>, true())
              let $expunge-ok as xs:boolean := imap:expunge($local:receiver-host-info, "INBOX")
              return empty(imap:search($local:receiver-host-info, "INBOX", "SUBJECT delete", true()))    
                
};






declare sequential function local:main() as xs:string* {

  let $a := local:test-delete()
  return
    if (fn:not($a)) then
      exit returning local:error(("Sending a message and then deleting it by setting the delete flag and calling expunge failed."))
    else ();

 (: make sure to send an email, so that the next execution of this test has something to delete :)
 smtp:send($local:sender-host-info, 
      <email:message>
        <envelope>
          <date>2010-11-26T15:50:39-04:01</date>
          <subject>delete</subject> 
          <recipient><to><name>Test Account</name><email>imaptest@28msec.com</email></to></recipient> 
         </envelope>
        <body>
          <content contentType="text/plain" charset="UTF-8" contentTransferEncoding="ENC8BIT">
            Oh yeah
          </content>
        </body>
      </email:message>);

 (: If all went well ... make sure the world knows! :)  
  "SUCCESS"; 



};

local:main();



