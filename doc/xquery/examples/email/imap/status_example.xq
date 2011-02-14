(:~
 : This example shows how to use the status function of the http://www.zorba-xquery.com/modules/email/imap module.
 : Using the host information stored in the variable $local:host-info the status of the account of user imaptest on 
 : the mail.28msec.com server is retrieved as xml structure.
 :
 : The XML output of this script should look something like:
 :
 : <imaps:status xmlns:imaps="http://www.zorba-xquery.com/modules/email/imap">
 :   <messages>27</messages>
 :   <recent>0</recent>
 :   <unseen>5</unseen>
 :   <uidnext>77</uidnext>
 :   <uidvalidity>1285079359</uidvalidity>
 : </imaps:status>
 :
 :) 

import module namespace imap = 'http://www.zorba-xquery.com/modules/email/imap';
import schema namespace imaps = 'http://www.zorba-xquery.com/modules/email/imap';
import schema namespace email = 'http://www.zorba-xquery.com/modules/email/email';

declare variable $local:host-info as element(imaps:hostInfo) := (<imaps:hostInfo><hostName>mail.28msec.com/novalidate-cert</hostName><userName>imaptest</userName><password>cclient</password></imaps:hostInfo>);

let $status := imap:status($local:host-info, "INBOX")
return $status
