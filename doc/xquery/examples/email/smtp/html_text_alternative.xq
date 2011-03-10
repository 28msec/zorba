(:~
 : This example uses the send function of the email/smtp module to send an email containing a html message and a text message from a gmail account.
 : If a email client does not support html email messages, it can safely use the text version.
 : Note the use of the serialize function which creates a string from a sequence of items comes in useful here to be able to create the html content as xml and then create a string out of it.
 :
 : Also, for a multipart/alternative message, the order is important. The message that should be most likely displayed first, the least likely last. 
 :)
import module namespace smtp = 'http://www.zorba-xquery.com/modules/email/smtp'; 
import module namespace serialize = 'http://www.zorba-xquery.com/modules/serialize';
import schema namespace email = 'http://www.zorba-xquery.com/modules/email/email';
import schema namespace imaps = 'http://www.zorba-xquery.com/modules/email/imap';

declare default element namespace 'http://www.zorba-xquery.com/modules/email/email';

(:~
 : This variable contains the information on the account from which the email should be sent.
 :) 
declare variable $local:sender-host-info as element(imaps:hostInfo) := (<imaps:hostInfo><imaps:hostName>smtp.gmail.com:587/tls/novalidate-cert</imaps:hostName><imaps:userName>zorba.smtp.sender</imaps:userName><imaps:password>1openssl!</imaps:password></imaps:hostInfo>); 



(: the send function takes the host info and a xml representation of the email to be sent as arguments, the schema describing the email xml can be found at http://www.zorba-xquery.com/modules/email/email. :) 


smtp:send($local:sender-host-info, 
      <message>
        <envelope>
          <date>2010-11-26T15:50:39-04:01</date>
          <subject>An important message</subject>
          <recipient><to><name>Test Account</name><email>imaptest@28msec.com</email></to></recipient>
          <recipient><cc><name>Myself</name><email>zorba.smtp.sender@gmail.com</email></cc></recipient>
         </envelope>
        <body>
          <multipart contentType="multipart/alternative" charset="UTF-8" contentTransferEncoding="ENC8BIT">
            <content contentType="text/plain" charset="UTF-8" contentTransferEncoding="ENC8BIT">
              Simple text version ... get yourself a nice and fancy email client.
            </content>
            <content contentType="text/html" charset="UTF-8" contentTransferEncoding="ENC8BIT">
            {  
              serialize:serialize(<html><head></head><body><h1>Zorba really rocks.</h1><p>XQuery brought to a new level</p></body></html>)
            } 
            </content>
          </multipart>  
        </body>
      </message>);
