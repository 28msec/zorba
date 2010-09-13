(:~
 : This module provides functions for accessing and manipulating imap mailservers.
 :
 : @author Daniel Thomas 
 :)
module namespace imap = 'http://www.zorba-xquery.com/modules/email/imap';
import module namespace imapimpl = 'http://www.zorba-xquery.com/modules/email/imapimpl';
import schema namespace imaps = 'http://www.zorba-xquery.com/modules/email/imap';
import schema namespace email = 'http://www.zorba-xquery.com/modules/email/email';


(:~
 : Returns the status of a given mailbox.
 : The status of a mailbox contains:
 : <ul>
 :  <li>messages: the number of messages in the mailbox</li>
 :  <li>recent: the number of messages flagged as recent</li>
 :  <li>unseen: the number of messages flagged as unseen</li>
 :  <li>uidnext: the next unique identifier that will be assigned to a message</li>
 :  <li>uidvalidity: a value that, together with the uidnext value forms a 64 bit number that must be unique for the server</li>
 : </ul>
 :
 : @param $host-info describes the IMAP host, username and password.
 : @param $mailbox specifies the mailbox for which we want to have the status.
 : @return the status of the specified mailbox as statusType.
 : @error If the status can not be read for any reason.
 :
 :)
declare function imap:status($host-info as element(imaps:hostInfoType), $mailbox as xs:string) as element(imaps:statusType) {
  let $status := imapimpl:status($host-info, $mailbox)
  let $status-sequence := fn:tokenize($status, ',')
  return
      <imaps:statusType>
          <imaps:messages>{$status-sequence[1]}</imaps:messages>
          <imaps:recent>{$status-sequence[2]}</imaps:recent>
          <imaps:unseen>{$status-sequence[3]}</imaps:unseen>
          <imaps:uidnext>{$status-sequence[4]}</imaps:uidnext>
          <imaps:uidvalidity>{$status-sequence[5]}</imaps:uidvalidity>
      </imaps:statusType> 
};

(:~
 : Creates a new mailbox for the given user.
 :
 : @param $host-info describes the IMAP host, username and password.
 : @param $mailbox-name is the name for the new mailbox.
 : @return true if the mailbox was created successfully.
 : @error If it wasn't possible to create a connection to the IMAP server.
 : @error If the passed credentials were rejected by the IMAP server.
 :)
declare sequential function imap:create($host-info as element(imaps:hostInfoType), $mailbox-name as xs:string)  as xs:boolean {
  imapimpl:create($host-info, $mailbox-name) 
};

(:~
 : Deletes a mailbox for the given user.
 :
 : @param $host-info describes the IMAP host, username and password.
 : @param $mailbox-name is the name of the  mailbox to delete.
 : @return true if the mailbox was deleted successfully.
 : @error If it wasn't possible to create a connection to the IMAP server.
 : @error If the passed credentials were rejected by the IMAP server.
 : @error If there is no mailbox with the specified name.
 :)
declare sequential function imap:delete($host-info as element(imaps:hostInfoType), $mailbox-name as xs:string)  as xs:boolean {
  imapimpl:delete($host-info, $mailbox-name)
};

(:~
 : Renames a mailbox.
 :
 : @param $host-info describes the IMAP host, username and password.
 : @param $mailbox-old is the name of the mailbox we want to rename.
 : @param $mailbox-new is the new name for the mailbox.
 : @return true it the mailbox was renamed successfully.
 : @error If it wasn't possible to create a connection to the IMAP server.
 : @error If the passed credentials were rejected by the IMAP server.
 : @error If there is no mailbox with with the specified name ($mailbox-old). 
 :)
declare sequential function imap:rename($host-info as element(imaps:hostInfoType), $mailbox-old as xs:string, $mailbox-new as xs:string) as xs:boolean {
  imapimpl:rename($host-info, $mailbox-old, $mailbox-new) 
};

(:~
 : Lists IMAP folders for the specified user on the host that match the pattern. 
 :
 : @param $host-info describes the IMAP host, username and password.
 : @param $mailbox-ref is applied to pattern in an implementation dependent fashion to search for matching mailbox names. 
 : @param $pattern the pattern for mailboxes to look for (can include wildcards '*' and '%').
 : @param $only-subscribed when set true, only mailboxes are listed to which the user is subscribed.
 : @return true it the mailbox was renamed successfully.
 : @error If it wasn't possible to create a connection to the IMAP server.
 : @error If the passed credentials were rejected by the IMAP server.
 :)
declare function imap:list($host-info as element(imaps:hostInfoType), $mailbox-ref as xs:string, $pattern as xs:string, $only-subscribed as xs:boolean) as element(imaps:mailboxType)* {
  let $mailbox-sequence := imapimpl:list($host-info, $mailbox-ref, $pattern, $only-subscribed)
  for $mailbox in $mailbox-sequence
  return
  <imaps:mailboxType>
    <imaps:hostName>{$host-info/imaps:hostName/text()}</imaps:hostName>
    <imaps:mailboxName>{fn:substring-after($mailbox, '}')}</imaps:mailboxName>
  </imaps:mailboxType>
};

(:~
 : Subscribes the user to the specified mailbox.
 : 
 : @param $host-info describes the IMAP host, username and password.
 : @param $mailbox is the mailbox the user wants to suscribe to.
 : @return true if the user was successfully subscribed to the mailbox.
 : @error If it wasn't possible to create a connection to the IMAP server.
 : @error If the passed credentials were rejected by the IMAP server.
 : @error If the specified mailbox does not exist.
 :)
declare sequential function imap:subscribe($host-info as element(imaps:hostInfoType), $mailbox as xs:string) as xs:boolean {
  imapimpl:subscribe($host-info, $mailbox)
};


(:~
 : Unsubscribes the user from the specified mailbox.
 : 
 : @param $host-info describes the IMAP host, username and password.
 : @param $mailbox is the mailbox the user wants to unsuscribe from.
 : @return true if the user was successfully unsubscribed from the mailbox.
 : @error If it wasn't possible to create a connection to the IMAP server.
 : @error If the passed credentials were rejected by the IMAP server.
 : @error If the specified mailbox does not exist.
 :)
declare sequential function imap:unsubscribe($host-info as element(imaps:hostInfoType), $mailbox as xs:string) as xs:boolean {
  imapimpl:unsubscribe($host-info, $mailbox)
};

(:~
 : Permanently deletes all messages of the given mailbox that have the \Deleted flag set.
 : 
 : @param $host-info describes the IMAP host, username and password.
 : @param $mailbox is the mailbox for which all messages that have the \Deleted flag set should be permanently deleted.
 : @return true if the expunge was successfull.
 : @error If it wasn't possible to create a connection to the IMAP server.
 : @error If the passed credentials were rejected by the IMAP server.
 : @error If the specified mailbox does not exist.
 :) 
declare sequential function imap:expunge($host-info as element(imaps:hostInfoType), $mailbox as xs:string) as xs:boolean {
  imapimpl:expunge($host-info, $mailbox)
};

(:~
 : Searches a mailbox for messages that match the given criteria.
 : The criteria should be a string as defined in the RFC3501 (IMAP4rev1).
 : A valid example would be: 'FROM zorba@gmail.com OR NOT SUBJECT Bug'. 
 : Depending on the value of $uid, the function will either return matching sequence numbers or unique identifiers.
 :
 : @param $host-info describes the IMAP host, username and password.
 : @param $mailbox is the mailbox to search.
 : @param $criteria is the searching criteria.
 : @param $uid when set true, the the function returns the sequence of Unique Identifiers corresponding to the matching mails, when set false (which is default) the corresponding sequence numbers are returned. 
 : @return Either the sequence of matching sequence numbers or the sequence of matching unique identifiers.
 : @error If it wasn't possible to create a connection to the IMAP server.
 : @error If the passed credentials were rejected by the IMAP server.
 : @error If the specified mailbox does not exist.
 : @error If the syntax of the passed criteria is incorrect.  
 :)
declare function imap:search($host-info as element(imaps:hostInfoType), $mailbox as xs:string, $criteria as xs:string, $uid as xs:boolean?) as xs:long*{
  imapimpl:search($host-info, $mailbox, $criteria, $uid)
}; 

(:~
 : Copies messages between mailboxes.
 : Depending on the value of $uid, the messages are either specified through their sequence number or through their unique id.
 : Both mailboxes must exist.
 : 
 : @param $host-info describes the IMAP host, username and password.
 : @param $mailbox-from is the mailbox in which the messages reside.
 : @param $mailbox-to is the mailbox in to which the messages should be copied.
 : @param $messages are the messages to be copied, specified either by their sequence number or their unique id.
 : @param $uid defines if the passed $message numbers should be treated as sequence numbers or unique identifiers.
 : @return true if the messages were copied successfully.
 : @error If it wasn't possible to create a connection to the IMAP server.
 : @error If the passed credentials were rejected by the IMAP server.
 : @error If any of the specified mailbox does not exist.
 : @error If any of the passed message numbers don't exist.
 :)
declare sequential function imap:copy($host-info as element(imaps:hostInfoType), $mailbox-from as xs:string, $mailbox-to as xs:string, $messages as xs:long+, $uid as xs:boolean?) as xs:boolean {
  imapimpl:copy($host-info, $mailbox-from, $mailbox-to, $messages, $uid, true());
};

(:~
 : Moves messages between mailboxes.
 : Depending on the value of $uid, the messages are either specified through their sequence number or through their unique id.
 : Both mailboxes must exist.
 : 
 : @param $host-info describes the IMAP host, username and password.
 : @param $mailbox-from is the mailbox in which the messages reside.
 : @param $mailbox-to is the mailbox in to which the messages should be moved.
 : @param $messages are the messages to be copied, specified either by their sequence number or their unique id.
 : @param $uid defines if the passed $message numbers should be treated as sequence numbers or unique identifiers.
 : @return true if the messages were moved successfully.
 : @error If it wasn't possible to create a connection to the IMAP server.
 : @error If the passed credentials were rejected by the IMAP server.
 : @error If any of the specified mailbox does not exist.
 : @error If any of the passed message numbers don't exist.
 :)
declare sequential function imap:move($host-info as element(imaps:hostInfoType), $mailbox-from as xs:string, $mailbox-to as xs:string, $messages as xs:long+, $uid as xs:boolean?) as xs:boolean {
  imapimpl:copy($host-info, $mailbox-from, $mailbox-to, $messages, $uid, false());
};

(:~
 : Fetches the envelope of a message. 
 : Please note that this function works <b>only</b> with message sequence numbers, not with unique identifier numbers. 
 :
 : @param $host-info describes the IMAP host, username and password.
 : @param $mailbox is the mailbox in which to search for the message.
 : @param $message-number is the message for which to fetch the envelope (depending on $uid either as message sequence number or unique identifier).
 : @return the envelope of the requested message.
 : @error If it wasn't possible to create a connection to the IMAP server.
 : @error If the passed credentials were rejected by the IMAP server.
 : @error If any of the specified mailbox does not exist.
 : @error If any of the passed message number does not exist.
 :) 
declare function imap:fetch-envelope($host-info as element(imaps:hostInfoType), $mailbox as xs:string, $message-number as xs:long) as element() { 
  imapimpl:fetch-envelope($host-info , $mailbox , $message-number ) 
};

