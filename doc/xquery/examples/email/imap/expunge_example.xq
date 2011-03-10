(:~
 : This example shows how to use the expunge function of the http://www.zorba-xquery.com/modules/email/imap module.
 : Using the host information stored in the variable $local:host-info first the search function is used to get
 : the unique id of the all messages with the word delete in its subject.
 : Then the delete flag is set on these messages using the set-flags method of the imap-module.
 : The call to expunge on the mailbox then deletes all messages that have the delete flag set.
 : 
 : This example is concluded by using the send function to send a new mail to the inbox to make sure that
 : there will be a message to delete next time the example is used.
 :) 

import module namespace imap = 'http://www.zorba-xquery.com/modules/email/imap';
import module namespace smtp = 'http://www.zorba-xquery.com/modules/email/smtp';
import schema namespace imaps = 'http://www.zorba-xquery.com/modules/email/imap';
import schema namespace email = 'http://www.zorba-xquery.com/modules/email/email';

declare default element namespace 'http://www.zorba-xquery.com/modules/email/email';

declare variable $local:host-info as element(imaps:hostInfo) := (<imaps:hostInfo><imaps:hostName>mail.28msec.com/novalidate-cert</imaps:hostName><imaps:userName>imaptest</imaps:userName><imaps:password>cclient</imaps:password></imaps:hostInfo>);

declare variable $local:sender-host-info as element(imaps:hostInfo) := (<imaps:hostInfo><imaps:hostName>smtp.gmail.com:587/tls/novalidate-cert</imaps:hostName><imaps:userName
>zorba.smtp.sender</imaps:userName><imaps:password>1openssl!</imaps:password></imaps:hostInfo>);

let $complying-unique-ids as xs:long* := imap:search($local:host-info, "INBOX", "SUBJECT delete", true())
    (: if there are no emails to delete, then the send function of the smtp library is probably not working, or the expunge is working excellently ... :)
    return if (empty($complying-unique-ids)) then true()
           else
              let $all-flags-set as xs:boolean* := for $id in $complying-unique-ids return imap:set-flags($local:host-info, "INBOX", $id, <email:flags><deleted/></email:flags>, true())
              let $expunge-ok as xs:boolean := imap:expunge($local:host-info, "INBOX")
              return empty(imap:search($local:host-info, "INBOX", "SUBJECT delete", true()));

smtp:send($local:sender-host-info,
      <message>
        <envelope>
          <date>2010-11-26T15:50:39-04:01</date>
          <subject>delete</subject>
          <recipient><to><name>Test Account</name><email>imaptest@28msec.com</email></to></recipient>
         </envelope>
        <body>
          <content contentType="text/plain" charset="UTF-8" contentTransferEncoding="ENC8BIT">
            Oh yeah
          </content>
        </body>
      </message>);


