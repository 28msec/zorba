(:~
 : This example shows how to use the copy function of the http://www.zorba-xquery.com/modules/email/imap module.
 :
 : First we search for a message with the word copy in the subject. When we have found this message, we
 : use the copy function to copy it internally to the CopyFolder folder.
 : This creates a new message in the copy folder with a own unique identifier and message sequence number.
 :) 

import module namespace imap = 'http://www.zorba-xquery.com/modules/email/imap';
import schema namespace imaps = 'http://www.zorba-xquery.com/modules/email/imap';
import schema namespace email = 'http://www.zorba-xquery.com/modules/email/email';

declare variable $local:host-info as element(imaps:hostInfo) := (<imaps:hostInfo><hostName>mail.28msec.com/novalidate-cert</hostName><userName>imaptest</userName><password>cclient</password></imaps:hostInfo>);

let $uids := imap:search($local:host-info, "INBOX", "SUBJECT copy2", true())
return imap:copy($local:host-info, "INBOX", "INBOX.CopyFolder", $uids, true())
