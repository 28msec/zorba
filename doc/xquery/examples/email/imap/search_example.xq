(:~
 : This example shows how to use the search function of the http://www.zorba-xquery.com/modules/email/imap module.
 : The mailbox INBOX of the user described by the $local:host-info variable is searched for messages that have the word test in their subject.
 : The search function returns a sequence of unique identifiers that comply with the search criteria (by setting the last argument to false() 
 : one would get message sequence numbers instead).
 :
 :) 

import module namespace imap = 'http://www.zorba-xquery.com/modules/email/imap';
import schema namespace imaps = 'http://www.zorba-xquery.com/modules/email/imap';
import schema namespace email = 'http://www.zorba-xquery.com/modules/email/email';

declare variable $local:host-info as element(imaps:hostInfo) := (<imaps:hostInfo><hostName>mail.28msec.com/novalidate-cert</hostName><userName>imaptest</userName><password>cclient</password></imaps:hostInfo>);


imap:search($local:host-info, "INBOX", "SUBJECT test", true())
