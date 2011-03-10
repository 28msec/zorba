(:~
 : This example shows how to use the list function of the http://www.zorba-xquery.com/modules/email/imap module.
 : Using the host information stored in the variable $local:host-info the list function is used to list all folders
 : on the given account that match the pattern 'INBOX.Dr*'.
 :
 : The result should be something like (as XML structure):
 : 
 : <imaps:mailbox xmlns:imaps="http://www.zorba-xquery.com/modules/email/imap">
 :     <hostName/><mailboxName>INBOX.Drafts</mailboxName>
 : </imaps:mailbox> 
 : 
 : The parameters for the list function are interesting, the second parameter is defined being applied to the pattern in an implementation dependent fashion to search for 
 : matching mailbox names. At this point we haven't found an example where this could be useful or even usable, so for now it is best left to an empty string.
 : The fourth and last parameter lets you choose if only subscribed mailboxes should be considered for the search.
 :) 

import module namespace imap = 'http://www.zorba-xquery.com/modules/email/imap';
import schema namespace imaps = 'http://www.zorba-xquery.com/modules/email/imap';
import schema namespace email = 'http://www.zorba-xquery.com/modules/email/email';

declare default element namespace 'http://www.zorba-xquery.com/modules/email/imap';

declare variable $local:host-info as element(imaps:hostInfo) := (<imaps:hostInfo><hostName>mail.28msec.com/novalidate-cert</hostName><userName>imaptest</userName><password>cclient</password></imaps:hostInfo>);

let $list := imap:list($local:host-info, "", "INBOX.Dra*", false())
return $list
