(:~
 : This example shows how to use the fetch_uid function of the http://www.zorba-xquery.com/modules/email/imap module.
 :
 : First, the message sequence number of all  messages with the word flags in the subject is retrieved.
 : Then the fetch-uid function is used to get the unique identifier of the message associated with the first message sequence number returned from the search.
 :) 

import module namespace imap = 'http://www.zorba-xquery.com/modules/email/imap';
import schema namespace imaps = 'http://www.zorba-xquery.com/modules/email/imap';
import schema namespace email = 'http://www.zorba-xquery.com/modules/email/email';

declare default element namespace 'http://www.zorba-xquery.com/modules/email/imap';

declare variable $local:host-info as element(imaps:hostInfo) := (<imaps:hostInfo><hostName>mail.28msec.com/novalidate-cert</hostName><userName>imaptest</userName><password>cclient</password></imaps:hostInfo>);


let $uids as xs:long* := imap:search($local:host-info, "INBOX", "SUBJECT flags", false())
return imap:fetch-uid($local:host-info, "INBOX", $uids[1])
