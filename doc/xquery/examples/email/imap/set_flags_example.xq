(:~
 : This example shows how to use the set-flags function of the http://www.zorba-xquery.com/modules/email/imap module.
 :
 : First, the unique identifier of all messages with the word flags in the subject is retrieved.
 : Then the flags of the first of the message associated to the first of the retrieved message identifiers  are set using the set-flags method.
 : The message will henceforth have exactly the flags that were set using the XML structure, so all flags that were associated with 
 : this message beforehand will only be present if they were set again. 
 :
 :) 

import module namespace imap = 'http://www.zorba-xquery.com/modules/email/imap';
import schema namespace imaps = 'http://www.zorba-xquery.com/modules/email/imap';
import schema namespace email = 'http://www.zorba-xquery.com/modules/email/email';

declare variable $local:host-info as element(imaps:hostInfo) := (<imaps:hostInfo><hostName>mail.28msec.com/novalidate-cert</hostName><userName>imaptest</userName><password>cclient</password></imaps:hostInfo>);


let $uids as xs:long* := imap:search($local:host-info, "INBOX", "SUBJECT flags", true())
return imap:set-flags($local:host-info, "INBOX", $uids[1], <email:flags><seen/><answered/></email:flags>, true())
