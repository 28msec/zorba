(:~
 : This example shows how to use the unsubscribe function of the http://www.zorba-xquery.com/modules/email/imap module.
 : Using the host information stored in the variable $local:host-info the user imaptest is subscribed to the folder INBOX.Test on the account. 
 : After this, the user is unsubscribed from this folder using the unsubscribe function.
 :
 : Subscribing to a folder will make the folder visible for email clients that by default only list the subscribed folders.
 : This example is the same example as for the subscribe function.
 :
 :) 

import module namespace imap = 'http://www.zorba-xquery.com/modules/email/imap';
import schema namespace imaps = 'http://www.zorba-xquery.com/modules/email/imap';
import schema namespace email = 'http://www.zorba-xquery.com/modules/email/email';

declare variable $local:host-info as element(imaps:hostInfo) := (<imaps:hostInfo><hostName>mail.28msec.com/novalidate-cert</hostName><userName>imaptest</userName><password>cclient</password></imaps:hostInfo>);

let $successfully-subscribed := imap:subscribe($local:host-info, "INBOX.Test")
return imap:unsubscribe($local:host-info, "INBOX.Test")
