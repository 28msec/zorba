(:~
 : This example shows how to use the delete function of the http://www.zorba-xquery.com/modules/email/imap module.
 : Using the host information stored in the variable $local:host-info a new mailbox is created on  
 : the mail.28msec.com server for this account. Then this mailbox is deleted using the delete function.
 :
 : The output of this script should be 'true' as the deletion of the mailbox should be successful if a mailbox was really created.
 : This is actually the same example as for the create function.
 :) 

import module namespace imap = 'http://www.zorba-xquery.com/modules/email/imap';
import module namespace random = 'http://www.zorba-xquery.com/modules/random';
import schema namespace imaps = 'http://www.zorba-xquery.com/modules/email/imap';
import schema namespace email = 'http://www.zorba-xquery.com/modules/email/email';

declare default element namespace 'http://www.zorba-xquery.com/modules/email/imap';

declare variable $local:host-info as element(hostInfo) := (<hostInfo><hostName>mail.28msec.com/novalidate-cert</hostName><userName>imaptest</userName><password>cclient</password></hostInfo>);

declare variable $local:mailbox := concat("INBOX.", substring(random:uuid(), 0, 4));


let $creation_successfull := imap:create($local:host-info, $local:mailbox)
return imap:delete($local:host-info, $local:mailbox)
