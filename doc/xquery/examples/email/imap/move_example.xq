(:~
 : This example shows how to use the move function of the http://www.zorba-xquery.com/modules/email/imap module.
 :
 : First we search for a message with the word move in the subject. When we have found such a message, we
 : use the move function to move it internally to the MoveFolder folder.
 : Then we check if there is such a message in the MoveFolder, before moving the message back into the INBOX folder.
 : 
 :) 

import module namespace imap = 'http://www.zorba-xquery.com/modules/email/imap';
import schema namespace imaps = 'http://www.zorba-xquery.com/modules/email/imap';
import schema namespace email = 'http://www.zorba-xquery.com/modules/email/email';

declare variable $local:host-info as element(imaps:hostInfo) := (<imaps:hostInfo><hostName>mail.28msec.com/novalidate-cert</hostName><userName>imaptest</userName><password>cclient</password></imaps:hostInfo>);

let $uids := imap:search($local:host-info, "INBOX", "SUBJECT move", true())
return
 (: if $uids are empty, then probably the message with subject move is already in the move folder and was not copied back last time :)
  if (empty($uids)) then
    let $uids-in-move := ($local:host-info, "INBOX.MoveFolder", true())
    return imap:move($local:host-info, "INBOX.MoveFolder", "INBOX", $uids-in-move, true())
  else
    let $sucessfully-moved := imap:move($local:host-info, "INBOX", "INBOX.MoveFolder", $uids, true())
    return imap:move($local:host-info, "INBOX.MoveFolder", "INBOX", $uids, true())
