(:~
 : This example shows how to use the rename function of the http://www.zorba-xquery.com/modules/email/imap module.
 : Using the host information stored in the variable $local:host-info a new mailbox is created on  
 : the mail.28msec.com server for this account. 
 : Then the rename function is used to change the name of this mailbox.
 :
 : The mailbox name is partly random (to make sure that there is no other mailbox with that name) and 
 : is subsequently deleted to make sure that the account is not swamped with useless mailboxes using 
 : the delete function of the imap module.
 : 
 : The output of this script should be 'true' as the deletion of the mailbox should be successful if a mailbox was really created and successfully renamed.
 :) 

import module namespace imap = 'http://www.zorba-xquery.com/modules/email/imap';
import module namespace random = 'http://www.zorba-xquery.com/modules/random';
import schema namespace imaps = 'http://www.zorba-xquery.com/modules/email/imap';
import schema namespace email = 'http://www.zorba-xquery.com/modules/email/email';

declare variable $local:host-info as element(imaps:hostInfo) := (<imaps:hostInfo><hostName>mail.28msec.com/novalidate-cert</hostName><userName>imaptest</userName><password>cclient</password></imaps:hostInfo>);

declare variable $local:mailbox as xs:string := concat("INBOX.", substring(random:uuid(), 0, 4));
declare variable $local:renamed-mailbox as xs:string := concat("INBOX.", substring(random:uuid(), 0, 5));

let $creation-successfull := imap:create($local:host-info, $local:mailbox)
let $rename-successfull := imap:rename($local:host-info, $local:mailbox, $local:renamed-mailbox)
return imap:delete($local:host-info, $local:renamed-mailbox)
