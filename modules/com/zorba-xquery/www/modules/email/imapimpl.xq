(:~
 : This module is for internal use only. 
 : 
 :)
module namespace imap = 'http://www.zorba-xquery.com/modules/email/imapimpl';
import schema namespace imaps = 'http://www.zorba-xquery.com/modules/email/imap';
import schema namespace email = 'http://www.zorba-xquery.com/modules/email/email';


(:~
 : For internal use only.
 :
 : @param $host-info describes the IMAP host, username and password.
 : @param $mailbox specifies the mailbox for which we want to have the status.
 : @return the status of the specified mailbox as statusType.
 : @error If the status can not be read for any reason.
 :
 :)
declare %nondeterministic function imap:status($host-info as element(imaps:hostInfo), $mailbox as xs:string) as xs:string* external;
  
(:~
 : For internal use only. 
 :
 : @param $host-info describes the IMAP host, username and password.
 : @param $mailbox-name is the name for the new mailbox.
 : @return true if the mailbox was created successfully.
 : @error If it wasn't possible to create a connection to the IMAP server.
 : @error If the passed credentials were rejected by the IMAP server.
 :)
declare sequential function imap:create($host-info as element(imaps:hostInfo), $mailbox-name as xs:string)  as xs:boolean external; 

(:~
 : Deletes a mailbox for the given user.
 :
 : @param $host-info describes the IMAP host, username and password.
 : @param $mailbox-name is the name of the  mailbox to delete.
 : @return true if the mailbox was deleted successfully.
 : @error If it wasn't possible to create a connection to the IMAP server.
 : @error If the passed credentials were rejected by the IMAP server.
 :)
declare sequential function imap:delete($host-info as element(imaps:hostInfo), $mailbox-name as xs:string)  as xs:boolean external; 

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
declare sequential function imap:rename($host-info as element(imaps:hostInfo), $mailbox-old as xs:string, $mailbox-new as xs:string) as xs:boolean external; 

(:~
 : Lists IMAP folders for the specified user on the host that match the pattern. 
 :
 : @param $host-info describes the IMAP host, username and password.
 : @param $mailbox-ref is applied to pattern in an implementation dependent fashion to search for matching mailbox names. 
 : @param $pattern the pattern for mailboxes to look for (can include wildcards '*' and '%').
 : @param $only-suscribed when set to true, only mailboxes are listed to which the user is suscribed.
 : @return true it the mailbox was renamed successfully.
 : @error If it wasn't possible to create a connection to the IMAP server.
 : @error If the passed credentials were rejected by the IMAP server.
 :)
declare %nondeterministic function imap:list($host-info as element(imaps:hostInfo), $mailbox-ref as xs:string, $pattern as xs:string, $only-suscribed as xs:boolean) as xs:string* external;


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
declare sequential function imap:subscribe($host-info as element(imaps:hostInfo), $mailbox as xs:string) as xs:boolean external;


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
declare sequential function imap:unsubscribe($host-info as element(imaps:hostInfo), $mailbox as xs:string) as xs:boolean external;


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
declare sequential function imap:expunge($host-info as element(imaps:hostInfo), $mailbox as xs:string) as xs:boolean external;


(:~
 : Searches the mailbox for messages that match the given criteria.
 : 
 : @param $host-info describes the IMAP host, username and password.
 : @param $mailbox is the mailbox to search.
 : @param $criteria is the searching criteria.
 : @param $uid defines if unique identifiers or (default) sequence numbers should be returned.
 : @return Either the sequence of matching sequence numbers or the sequence of matching unique identifiers. 
 : @error If it wasn't possible to create a connection to the IMAP server.
 : @error If the passed credentials were rejected by the IMAP server.
 : @error If the specified mailbox does not exist.
 : @error If the syntax of the passed criteria is incorrect.  
 :)
declare %nondeterministic function imap:search($host-info as element(imaps:hostInfo), $mailbox as xs:string, $criteria as xs:string, $uid as xs:boolean?) as xs:long* external;


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
 : @param $copy if set to true, then messages are copied, if false then they are moved.
 : @return true if the messages were copied successfully.
 : @error If it wasn't possible to create a connection to the IMAP server.
 : @error If the passed credentials were rejected by the IMAP server.
 : @error If any of the specified mailbox does not exist.
 : @error If any of the passed message numbers don't exist.
 :)
declare sequential function imap:copy($host-info as element(imaps:hostInfo), $mailbox-from as xs:string, $mailbox-to as xs:string, $messages as xs:long+, $uid as xs:boolean?, $copy as xs:boolean) as xs:boolean external; 


(:~
 : Fetches the envelope of a message. 
 : 
 : @param $host-info describes the IMAP host, username and password.
 : @param $mailbox is the mailbox in which to search for the message.
 : @param $message-number is the message for which to fetch the envelope. 
 : @return the envelope of the requested message.
 : @error If it wasn't possible to create a connection to the IMAP server.
 : @error If the passed credentials were rejected by the IMAP server.
 : @error If any of the specified mailbox does not exist.
 : @error If any of the passed message number does not exist.
 :)
declare %nondeterministic function imap:fetch-envelope($host-info as element(imaps:hostInfo), $mailbox as xs:string, $message-number as xs:long) as element(email:envelope) external; 

(:~
 : Fetches a whole message.
 : 
 : @param $host-info describes the IMAP host, username and password.
 : @param $mailbox is the mailbox in which to search for the message.
 : @param $message-number is the message to fetch, denoted either by its sequence number or unique identifier.
 : @param $uid defines if the passed $message-number should be interpreted as sequence number (false, default) or unique identifier.
 : @return the message with the passed message number.
 : @error If it wasn't possible to create a connection to the IMAP server.
 : @error If the passed credentials were rejected by the IMAP server.
 : @error If any of the specified mailbox does not exist.
 : @error If any of the passed message number does not exist.
 :)
declare %nondeterministic function imap:fetch-message($host-info as element(imaps:hostInfo), $mailbox as xs:string, $message-number as xs:long, $uid as xs:boolean) as element() external; 

(:~
 : Fetches the subject for a message.
 : Please note that this function only works with message sequence numbers, not with unique identifiers.
 :
 : @param $host-info describes the IMAP host, username and password.
 : @param $mailbox is the mailbox for which we want to get the subject of a message.
 : @param $message-number denotes the message for which we want the subject.
 : @return the subject of the specified message.
 : @error If it wasn't possible to create a connection to the IMAP server.
 : @error If the passed credentials were rejected by the IMAP server.
 : @error If any of the specified mailbox does not exist.
 : @error If any of the passed message number does not exist.
 :)  
declare %nondeterministic function imap:fetch-subject($host-info as element(imaps:hostInfo), $mailbox as xs:string, $message-number as xs:long) as xs:string external;

(:~
 : Fetches the 'from' string of a message.
 : Please note that this function only words with message sequence numbers, not with unique identifiers.
 : Only the first 30 characters of a 'from' string are fetched.
 : 
 : @param $host-info describes the IMAP host, username and password. : @param $mailbox is the mailbox for which we want to get the 'from' string of a message.
 : @param $mailbox is the mailbox for which we want the 'from' string.
 : @param $message-number denotes the message for which we want the 'from' string. : 
 : @return the 'from' string of the specified message. 
 : @error If it wasn't possible to create a connection to the IMAP server.
 : @error If the passed credentials were rejected by the IMAP server.
 : @error If any of the specified mailbox does not exist.
 : @error If any of the passed message number does not exist. 
 :)
declare %nondeterministic function imap:fetch-from($host-info as element(imaps:hostInfo), $mailbox as xs:string, $message-number as xs:long) as xs:string external;

(:~
 : Fetches the unique identifier for a given message sequence number.
 :
 : @param $host-info describes the IMAP host, username and password.
 : @param $mailbox is the mailbox for which we want to get the unique identifier of a message sequence number.
 : @param $message-number is the message sequence number for which we want the unique identifier.
 : @return the unique identifier of the given message sequence number.
 : @error If it wasn't possible to create a connection to the IMAP server.
 : @error If the passed credentials were rejected by the IMAP server.
 : @error If any of the specified mailbox does not exist.
 : @error If any of the passed message number does not exist.
 :)
declare %nondeterministic function imap:fetch-uid($host-info as element(imaps:hostInfo), $mailbox as xs:string, $message-number as xs:long) as xs:long external;

(:~
 : Fetches the message sequence number for a given unique identifier.
 :
 : @param $host-info describes the IMAP host, username and password.
 : @param $mailbox is the mailbox for which we want to get the message sequence number of an unique identifier.
 : @param $message-number is the unique identifier for which we want the message sequence number.
 : @return the message sequence number of the of the given unique identifier.
 : @error If it wasn't possible to create a connection to the IMAP server.
 : @error If the passed credentials were rejected by the IMAP server.
 : @error If any of the specified mailbox does not exist.
 : @error If any of the passed message number does not exist. 
 :)
declare %nondeterministic function imap:fetch-message-sequence-number($host-info as element(imaps:hostInfo), $mailbox as xs:string, $message-number as xs:long) as xs:long external;
 
