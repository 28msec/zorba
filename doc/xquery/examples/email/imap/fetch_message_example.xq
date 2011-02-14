(:~
 : This example shows how to use the fetch-message function of the http://www.zorba-xquery.com/modules/email/imap module.
 : Using the host information stored in the variable $local:host-info first a message with the word test in the subject is searched for using 
 : the search function from the imap module.
 : Then the XML representation of the message corresponding to the first of the returned message sequence numbers is fetched. 
 :
 : The XML output of this script should look something like:
 :
 :  <email:message xmlns:email="http://www.zorba-xquery.com/modules/email/email">
 :      <envelope>
 :        <date>2011-02-14T13:07:38</date>
 :        <from><name>Daniel Thomas</name><email>thomas.daniel.james@gmail.com</email></from>
 :        <sender><name>Daniel Thomas</name><email>thomas.daniel.james@gmail.com</email></sender>
 :        <replyTo><name>Daniel Thomas</name><email>thomas.daniel.james@gmail.com</email></replyTo>
 :        <subject>test</subject><recipient><to><email>imaptest@28msec.com</email></to></recipient>
 :        <messageId>&lt;AANLkTinSujfq9-UgGDvX+RcOrhvQf5JTnTdwSLNTiqZ5@mail.gmail.com&gt;</messageId>
 :        <flags/>
 :      </envelope>
 :      <mimeVersion>1.0</mimeVersion>
 :      <body>
 :        <multipart contentType="multipart/alternative" charset="us-ascii" contentTransferEncoding="ENC7BIT">
 :          <content contentType="text/plain" charset="us-ascii" contentTransferEncoding="ENC8BIT">This is a test message&#xD;</content>
 :          <content contentType="text/html" charset="us-ascii" contentTransferEncoding="ENC8BIT">This is a test message&#xD;</content>
 :        </multipart>
 :      </body>
 :   </email:message>
 :) 

import module namespace imap = 'http://www.zorba-xquery.com/modules/email/imap';
import schema namespace imaps = 'http://www.zorba-xquery.com/modules/email/imap';
import schema namespace email = 'http://www.zorba-xquery.com/modules/email/email';

declare variable $local:host-info as element(imaps:hostInfo) := (<imaps:hostInfo><hostName>mail.28msec.com/novalidate-cert</hostName><userName>imaptest</userName><password>cclient</password></imaps:hostInfo>);

let $uid := imap:search($local:host-info, "INBOX", "SUBJECT test", false())[1] 
return imap:fetch-message($local:host-info, "INBOX", $uid, false())  
