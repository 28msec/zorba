(:~
 : This example uses the send function of the email/smtp module to send an email containing a html  message from a gmail account.
 : Also, this message is sent to with a cc to to the email adress from which it is sent.
 : Note the use of the serialize function which creates a string from a sequence of items comes in useful here to be able to create the html content as xml and then create a string out of it.
 :)
import module namespace smtp = 'http://www.zorba-xquery.com/modules/email/smtp'; 
import module namespace serialize = 'http://www.zorba-xquery.com/modules/serialize';
import schema namespace email = 'http://www.zorba-xquery.com/modules/email/email';
import schema namespace imaps = 'http://www.zorba-xquery.com/modules/email/imap';


(:~
 : This variable contains the information on the account from which the email should be sent.
 :) 
declare variable $local:sender-host-info as element(imaps:hostInfo) := (<imaps:hostInfo><hostName>smtp.gmail.com:587/tls/novalidate-cert</hostName><userName>zorba.smtp.sender</userName><password>1openssl!</password></imaps:hostInfo>); 



(: the send function takes the host info and a xml representation of the email to be sent as arguments, the schema describing the email xml can be found at http://www.zorba-xquery.com/modules/email/email. :) 


smtp:send($local:sender-host-info, 
      <email:message>
        <envelope>
          <date>2010-11-26T15:50:39-04:01</date>
          <subject>An important message</subject>
          <recipient><to><name>Test Account</name><email>imaptest@28msec.com</email></to></recipient>
          <recipient><cc><name>Myself</name><email>zorba.smtp.sender@gmail.com</email></cc></recipient>
         </envelope>
        <body>
          <content contentType="text/html" charset="UTF-8" contentTransferEncoding="ENC8BIT">
          { 
            serialize:serialize(<html><head></head><body><h1>Zorba really rocks.</h1><p>XQuery brought to a new level</p></body></html>)
          }   
          </content>
        </body>
      </email:message>);
