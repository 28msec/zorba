(:~
 : This example shows how to use the fetch-flags function of the http://www.zorba-xquery.com/modules/email/imap module.
 :
 : First, the unique identifier of all messages with the word flags in the subject is retrieved.
 : Then the flags of the message associated to the first of the retrieved message identifiers are retrieved using the fetch-flags method.
 : 
 : The resulting XML should look something like this:
 : 
 : <email:flags xmlns:email="http://www.zorba-xquery.com/modules/email/email">
 :     <seen/>
 :     <answered/>
 : </email:flags>
 : 
 :
 :) 

import module namespace imap = 'http://www.zorba-xquery.com/modules/email/imap';
import schema namespace imaps = 'http://www.zorba-xquery.com/modules/email/imap';
import schema namespace email = 'http://www.zorba-xquery.com/modules/email/email';

declare default element namespace 'http://www.zorba-xquery.com/modules/email/imap';

declare variable $local:host-info as element(imaps:hostInfo) := (<imaps:hostInfo><hostName>mail.28msec.com/novalidate-cert</hostName><userName>imaptest</userName><password>cclient</password></imaps:hostInfo>);


let $uids as xs:long* := imap:search($local:host-info, "INBOX", "SUBJECT flags", true())
return imap:fetch-flags($local:host-info, "INBOX", $uids[1], true())
