(:~
 : This example shows how to use the fetch_message_sequence_number function of the http://www.zorba-xquery.com/modules/email/imap module.
 :
 : First, the unique identifier of all  messages with the word flags in the subject is retrieved.
 : Then the fetch-message_sequence_number function is used to get the message sequence number of the message associated with the first 
 : unique identifier returned from the search.
 :) 

import module namespace imap = 'http://www.zorba-xquery.com/modules/email/imap';
import schema namespace imaps = 'http://www.zorba-xquery.com/modules/email/imap';
import schema namespace email = 'http://www.zorba-xquery.com/modules/email/email';

declare default element namespace 'http://www.zorba-xquery.com/modules/email/imap';

declare variable $local:host-info as element(imaps:hostInfo) := (<imaps:hostInfo><hostName>mail.28msec.com/novalidate-cert</hostName><userName>imaptest</userName><password>cclient</password></imaps:hostInfo>);


let $message-sequence-numbers as xs:long* := imap:search($local:host-info, "INBOX", "SUBJECT flags", true())
return imap:fetch-message-sequence-number($local:host-info, "INBOX", $message-sequence-numbers[1])
