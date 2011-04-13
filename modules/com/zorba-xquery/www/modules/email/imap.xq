(:~
 : This module provides functions for accessing and manipulating imap mailservers.
 :
 : @author Daniel Thomas
 : @library <a href="http://www.washington.edu/imap/">c‑client Library part of UW IMAP toolkit</a>
 :
 :)
module namespace imap = 'http://www.zorba-xquery.com/modules/email/imap';
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
 : @example ../doc/xquery/examples/email/imap/status_example.xq
 :)
declare function imap:status($host-info as element(imaps:hostInfo), $mailbox as xs:string) as element(imaps:status) {
  let $status := imap:status-impl(validate {$host-info}, $mailbox)
  let $status-sequence := fn:tokenize($status, ',')
  return
      validate {
        <imaps:status>
          <imaps:messages>{$status-sequence[1]}</imaps:messages>
          <imaps:recent>{$status-sequence[2]}</imaps:recent>
          <imaps:unseen>{$status-sequence[3]}</imaps:unseen>
          <imaps:uidnext>{$status-sequence[4]}</imaps:uidnext>
          <imaps:uidvalidity>{$status-sequence[5]}</imaps:uidvalidity>
        </imaps:status> 
      
      }
};

(:~
 : Creates a new mailbox for the given user.
 :
 : @param $host-info describes the IMAP host, username and password.
 : @param $mailbox-name is the name for the new mailbox.
 : @return true if the mailbox was created successfully.
 : @error If it wasn't possible to create a connection to the IMAP server.
 : @error If the passed credentials were rejected by the IMAP server.
 : @example ../doc/xquery/examples/email/imap/create_example.xq
 :)
declare %sequential function imap:create($host-info as element(imaps:hostInfo), $mailbox-name as xs:string)  as xs:boolean {
  imap:create-impl(validate {$host-info}, $mailbox-name) 
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
 : @example ../doc/xquery/examples/email/imap/delete_example.xq
 :)
declare %sequential function imap:delete($host-info as element(imaps:hostInfo), $mailbox-name as xs:string)  as xs:boolean {
  imap:delete-impl(validate {$host-info}, $mailbox-name)
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
 : @example ../doc/xquery/examples/email/imap/rename_example.xq
 :)
declare %sequential function imap:rename($host-info as element(imaps:hostInfo), $mailbox-old as xs:string, $mailbox-new as xs:string) as xs:boolean {
  imap:rename-impl(validate {$host-info}, $mailbox-old, $mailbox-new) 
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
 : @example ../doc/xquery/examples/email/imap/list_example.xq
 :)
declare function imap:list($host-info as element(imaps:hostInfo), $mailbox-ref as xs:string, $pattern as xs:string, $only-subscribed as xs:boolean) as element(imaps:mailbox)* {
  let $mailbox-sequence := imap:list-impl(validate {$host-info}, $mailbox-ref, $pattern, $only-subscribed)
  for $mailbox in $mailbox-sequence
  return
  validate {
    <imaps:mailbox>
      <imaps:hostName>{$host-info/imaps:hostName/text()}</imaps:hostName>
      <imaps:mailboxName>{fn:substring-after($mailbox, '}')}</imaps:mailboxName>
    </imaps:mailbox>
  }
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
 : @example ../doc/xquery/examples/email/imap/subscribe_example.xq
 :)
declare %sequential function imap:subscribe($host-info as element(imaps:hostInfo), $mailbox as xs:string) as xs:boolean {
  imap:subscribe-impl(validate {$host-info}, $mailbox)
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
 : @example ../doc/xquery/examples/email/imap/unsubscribe_example.xq
 :)
declare %sequential function imap:unsubscribe($host-info as element(imaps:hostInfo), $mailbox as xs:string) as xs:boolean {
  imap:unsubscribe-impl(validate {$host-info}, $mailbox)
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
 : @example ../doc/xquery/examples/email/imap/expunge_example.xq
 :) 
declare %sequential function imap:expunge($host-info as element(imaps:hostInfo), $mailbox as xs:string) as xs:boolean {
  imap:expunge-impl(validate {$host-info}, $mailbox)
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
 : @example ../doc/xquery/examples/email/imap/search_example.xq
 :)
declare function imap:search($host-info as element(imaps:hostInfo), $mailbox as xs:string, $criteria as xs:string, $uid as xs:boolean?) as xs:long*{
  imap:search-impl(validate {$host-info}, $mailbox, $criteria, $uid)
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
 : @example ../doc/xquery/examples/email/imap/copy_example.xq
 :)
declare %sequential function imap:copy($host-info as element(imaps:hostInfo), $mailbox-from as xs:string, $mailbox-to as xs:string, $messages as xs:long+, $uid as xs:boolean?) as xs:boolean {
  imap:copy-impl(validate {$host-info}, $mailbox-from, $mailbox-to, $messages, $uid, true());
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
 : @example ../doc/xquery/examples/email/imap/move_example.xq
 :)
declare %sequential function imap:move($host-info as element(imaps:hostInfo), $mailbox-from as xs:string, $mailbox-to as xs:string, $messages as xs:long+, $uid as xs:boolean?) as xs:boolean {
  imap:copy-impl(validate {$host-info}, $mailbox-from, $mailbox-to, $messages, $uid, false());
};

(:~
 : Fetches the envelope of a message. 
 :
 : @param $host-info describes the IMAP host, username and password.
 : @param $mailbox is the mailbox in which to search for the message.
 : @param $message-number is the message for which to fetch the envelope (depending on $uid either as message sequence number or unique identifier).
 : @param $uid defines if the passed $message-number should be interpreted as message sequence number (false, default) or unique identifier.
 : @return the envelope of the requested message.
 : @error If it wasn't possible to create a connection to the IMAP server.
 : @error If the passed credentials were rejected by the IMAP server.
 : @error If any of the specified mailbox does not exist.
 : @error If any of the passed message number does not exist.
 : @example ../doc/xquery/examples/email/imap/fetch_envelope_example.xq 
 :) 
declare function imap:fetch-envelope($host-info as element(imaps:hostInfo), $mailbox as xs:string, $message-number as xs:long, $uid as xs:boolean?) as element() { 
     validate {imap:fetch-envelope-impl( validate { $host-info }, $mailbox , $message-number, $uid )} 
};


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
 : @example ../doc/xquery/examples/email/imap/fetch_message_example.xq
 :)
declare function imap:fetch-message($host-info as element(imaps:hostInfo), $mailbox as xs:string, $message-number as xs:long, $uid as xs:boolean) as element(email:message) {
   validate {imap:fetch-message-impl(validate {$host-info}, $mailbox, $message-number, $uid)} 
}; 

(:~
 : Fetches the subject for a message.
 : Please note that this function only works with message sequence numbers, not with unique identifiers.
 : Only the first 30 characters of a subject are fetched. 
 :
 : @param $host-info describes the IMAP host, username and password.
 : @param $mailbox is the mailbox for which we want to get the subject of a message.
 : @param $message-number denotes the message for which we want the subject.
 : @return the subject of the specified message.
 : @error If it wasn't possible to create a connection to the IMAP server.
 : @error If the passed credentials were rejected by the IMAP server.
 : @error If any of the specified mailbox does not exist.
 : @error If any of the passed message number does not exist.
 : @example ../doc/xquery/examples/email/imap/fetch_subject_example.xq
 :)
declare function imap:fetch-subject($host-info as element(imaps:hostInfo), $mailbox as xs:string, $message-number as xs:long) as xs:string {
  imap:fetch-subject-impl(validate {$host-info}, $mailbox, $message-number)
};

(:~
 : Fetches the 'from' string of a message.
 : Please note that this function only words with message sequence numbers, not with unique identifiers.
 : Only the first 30 characters of a 'from' string are fetched.
 : 
 : @param $host-info describes the IMAP host, username and password.
 : @param $mailbox is the mailbox for which we want to get the 'from' string of a message.
 : @param $message-number denotes the message for which we want the 'from' string.
 : @return the 'from' string of the specified message.
 : @error If it wasn't possible to create a connection to the IMAP server.
 : @error If the passed credentials were rejected by the IMAP server.
 : @error If any of the specified mailbox does not exist.
 : @error If any of the passed message number does not exist.
 : @example ../doc/xquery/examples/email/imap/fetch_from_example.xq
 :)
declare function imap:fetch-from($host-info as element(imaps:hostInfo), $mailbox as xs:string, $message-number as xs:long) as xs:string
{
  imap:fetch-from-impl(validate {$host-info}, $mailbox, $message-number)
};


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
 : @error If the passed message number does not exist.
 : @example ../doc/xquery/examples/email/imap/fetch_uid_example.xq
 :)
declare function imap:fetch-uid($host-info as element(imaps:hostInfo), $mailbox as xs:string, $message-number as xs:long) as xs:long
{
  imap:fetch-uid-impl(validate {$host-info}, $mailbox, $message-number)
};



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
 : @error If the passed message number does not exist.
 : @example ../doc/xquery/examples/email/imap/fetch_message_sequence_number_example.xq
 :)
declare function imap:fetch-message-sequence-number($host-info as element(imaps:hostInfo), $mailbox as xs:string, $message-number as xs:long) as xs:long
{
  imap:fetch-message-sequence-number-impl(validate {$host-info}, $mailbox, $message-number)
};


(:~
 : Fetches the flags of a message.
 :
 : @param $host-info describes the IMAP host, username and password.
 : @param $mailbox is the mailbox containing the specified message.
 : @param $message-number is either the message sequence number or the unique identifier of the message.
 : @param $uid defines if the message number shall be intepreted as message sequence number (default) or unique identifier.
 : @return the flags of the specified message.
 : @error If it wasn't possible to create a connection to the IMAP server.
 : @error If the passed credentials were rejected by the IMAP server.
 : @error If any of the specified mailbox does not exist.
 : @error If the passed message number does not exist.
 : @example ../doc/xquery/examples/email/imap/fetch_flags_example.xq
 :)
declare function imap:fetch-flags($host-info as element(imaps:hostInfo), $mailbox as xs:string, $message-number as xs:long, $uid as xs:boolean?) as element(email:flags) 
{
   validate {imap:fetch-flags-impl(validate{$host-info}, $mailbox, $message-number, $uid)} 
};
 


(:~
 : Sets the flags for a given message.
 : The flags are set AND unset according to the passed flagType.
 : Please note that the 'old' flag can not be set/unset and will be ignored. 
 :
 : @param $host-info describes the IMAP host, username and password.
 : @param $mailbox is the mailbox containing the specified message.
 : @param $message-number is either the message sequence number or the unique identifier of the message (depending on the value of $uid).
 : @param $flags defines which flags should be set for this message.
 : @param $uid defines if the message number shall be intepreted as message sequence number (default) or unique identifier.
 : @return true if the setting and unsetting of flags went well.
 : @error If it wasn't possible to create a connection to the IMAP server.
 : @error If the passed credentials were rejected by the IMAP server.
 : @error If any of the specified mailbox does not exist.
 : @error If the passed message number does not exist.
 : @example ../doc/xquery/examples/email/imap/set_flags_example.xq
 :)
declare %sequential function imap:set-flags($host-info as element(imaps:hostInfo), $mailbox as xs:string, $message-number as xs:long, $flags as element(email:flags), $uid as xs:boolean?) as xs:boolean {
    imap:set-flags-impl(validate{$host-info}, $mailbox, $message-number, validate{$flags}, $uid)
}; 


(:~
 : For internal use only.
 :
 : @param $host-info describes the IMAP host, username and password.
 : @param $mailbox specifies the mailbox for which we want to have the status.
 : @return the status of the specified mailbox as statusType.
 : @error If the status can not be read for any reason.
 :
 :)
declare %private %nondeterministic function imap:status-impl($host-info as element(imaps:hostInfo), $mailbox as xs:string) as xs:string* external;
  
(:~
 : For internal use only. 
 :
 : @param $host-info describes the IMAP host, username and password.
 : @param $mailbox-name is the name for the new mailbox.
 : @return true if the mailbox was created successfully.
 : @error If it wasn't possible to create a connection to the IMAP server.
 : @error If the passed credentials were rejected by the IMAP server.
 :)
declare %private %sequential function imap:create-impl($host-info as element(imaps:hostInfo), $mailbox-name as xs:string)  as xs:boolean external; 

(:~
 : Deletes a mailbox for the given user.
 :
 : @param $host-info describes the IMAP host, username and password.
 : @param $mailbox-name is the name of the  mailbox to delete.
 : @return true if the mailbox was deleted successfully.
 : @error If it wasn't possible to create a connection to the IMAP server.
 : @error If the passed credentials were rejected by the IMAP server.
 :)
declare %private %sequential function imap:delete-impl($host-info as element(imaps:hostInfo), $mailbox-name as xs:string)  as xs:boolean external; 


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
declare %private %sequential function imap:rename-impl($host-info as element(imaps:hostInfo), $mailbox-old as xs:string, $mailbox-new as xs:string) as xs:boolean external;

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
declare %private %nondeterministic function imap:list-impl($host-info as element(imaps:hostInfo), $mailbox-ref as xs:string, $pattern as xs:string, $only-suscribed as xs:boolean) as xs:string* external;


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
declare %private %sequential function imap:subscribe-impl($host-info as element(imaps:hostInfo), $mailbox as xs:string) as xs:boolean external;


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
declare %private %sequential function imap:unsubscribe-impl($host-info as element(imaps:hostInfo), $mailbox as xs:string) as xs:boolean external;


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
declare %private %sequential function imap:expunge-impl($host-info as element(imaps:hostInfo), $mailbox as xs:string) as xs:boolean external;


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
declare %private %nondeterministic function imap:search-impl($host-info as element(imaps:hostInfo), $mailbox as xs:string, $criteria as xs:string, $uid as xs:boolean?) as xs:long* external;


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
declare %private %sequential function imap:copy-impl($host-info as element(imaps:hostInfo), $mailbox-from as xs:string, $mailbox-to as xs:string, $messages as xs:long+, $uid as xs:boolean?, $copy as xs:boolean) as xs:boolean external;

(:~
 : Fetches the envelope of a message. 
 : 
 : @param $host-info describes the IMAP host, username and password.
 : @param $mailbox is the mailbox in which to search for the message.
 : @param $message-number is the message for which to fetch the envelope.
 : @param $uid defines if the passed $message-number should be interpreted as message sequence number (false, default) or unique identifier
 : @return the envelope of the requested message.
 : @error If it wasn't possible to create a connection to the IMAP server.
 : @error If the passed credentials were rejected by the IMAP server.
 : @error If any of the specified mailbox does not exist.
 : @error If any of the passed message number does not exist.
 :)
declare %private %nondeterministic function imap:fetch-envelope-impl($host-info as element(imaps:hostInfo), $mailbox as xs:string, $message-number as xs:long, $uid as xs:boolean?) as element(email:envelope) external;

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
declare %private %nondeterministic function imap:fetch-message-impl($host-info as element(imaps:hostInfo), $mailbox as xs:string, $message-number as xs:long, $uid as xs:boolean) as element() external;

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
declare %private %nondeterministic function imap:fetch-subject-impl($host-info as element(imaps:hostInfo), $mailbox as xs:string, $message-number as xs:long) as xs:string external;

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
declare %private %nondeterministic function imap:fetch-from-impl($host-info as element(imaps:hostInfo), $mailbox as xs:string, $message-number as xs:long) as xs:string external;

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
declare %private %nondeterministic function imap:fetch-uid-impl($host-info as element(imaps:hostInfo), $mailbox as xs:string, $message-number as xs:long) as xs:long external;

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
declare %private %nondeterministic function imap:fetch-message-sequence-number-impl($host-info as element(imaps:hostInfo), $mailbox as xs:string, $message-number as xs:long) as xs:long external;


(:~
 : Fetches the flags of a message.
 :
 : @param $host-info describes the IMAP host, username and password.
 : @param $mailbox is the mailbox containing the specified message.
 : @param $message-number is either the message sequence number or the unique identifier of the message.
 : @param $uid defines if the message number shall be intepreted as message sequence number (default) or unique identifier.
 : @return the flags of the specified message.
 : @error If it wasn't possible to create a connection to the IMAP server.
 : @error If the passed credentials were rejected by the IMAP server.
 : @error If any of the specified mailbox does not exist.
 : @error If the passed message number does not exist.
 :)
declare %private %nondeterministic function imap:fetch-flags-impl($host-info as element(imaps:hostInfo), $mailbox as xs:string, $message-number as xs:long, $uid as xs:boolean?) as element(email:flags) external;



(:~
 : Sets the flags for a given message.
 : The flags are set AND unset according to the passed flagType.
 :
 : @param $host-info describes the IMAP host, username and password.
 : @param $mailbox is the mailbox containing the specified message.
 : @param $message-number is either the message sequence number or the unique identifier of the message (depending on the value of $uid).
 : @param $flags defines which flags should be set for this message.
 : @param $uid defines if the message number shall be intepreted as message sequence number (default) or unique identifier.
 : @return true if the setting and unsetting of flags went well.
 : @error If it wasn't possible to create a connection to the IMAP server.
 : @error If the passed credentials were rejected by the IMAP server.
 : @error If any of the specified mailbox does not exist.
 : @error If the passed message number does not exist.
 :)
declare %private %sequential function imap:set-flags-impl($host-info as element(imaps:hostInfo), $mailbox as xs:string, $message-number as xs:long, $flags as element(email:flags), $uid as xs:boolean?) as xs:boolean external;

