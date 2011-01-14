(:~
 : This example uses the send function of the email/smtp module to send an email containing a simple text message with an image as attachement from a gmail account.
 : To make things really interesting, the image is made on the spot with the modules from the zorba imaging library.
 :)
import module namespace smtp = 'http://www.zorba-xquery.com/modules/email/smtp'; 

import module namespace basic = 'http://www.zorba-xquery.com/modules/image/basic';
import module namespace paint = 'http://www.zorba-xquery.com/modules/image/paint';
import schema namespace image = 'http://www.zorba-xquery.com/modules/image/image';

import schema namespace email = 'http://www.zorba-xquery.com/modules/email/email';
import schema namespace imaps = 'http://www.zorba-xquery.com/modules/email/imap';


(:~
 : This variable contains the information on the account from which the email should be sent.
 :) 
declare variable $local:sender-host-info as element(imaps:hostInfo) := (<imaps:hostInfo><hostName>smtp.gmail.com:587/tls/novalidate-cert</hostName><userName>zorba.smtp.sender</userName><password>1openssl!</password></imaps:hostInfo>); 

(: the send function takes the host info and a xml representation of the email to be sent as arguments, the schema describing the email xml can be found at http://www.zorba-xquery.com/modules/email/email. :) 

let $image as xs:base64Binary := paint:paint(basic:create(xs:unsignedInt(200), xs:unsignedInt(200), "GIF"), <image:text><origin><x>20</x><y>50</y></origin><text>Zorba really rocks.</text><font>Arial</font><font-size>14</font-size></image:text>)
return smtp:send($local:sender-host-info, 
      <email:message>
        <envelope>
          <date>2010-11-26T15:50:39-04:01</date>
          <subject>An important message</subject>
          <recipient><to><name>Test Account</name><email>imaptest@28msec.com</email></to></recipient>
         </envelope>
        <body>
          <multipart contentType="multipart/mixed" charset="UTF-8" contentTransferEncoding="ENC8BIT">
          <content contentType="text/plain" charset="UTF-8" contentTransferEncoding="ENC8BIT">
            Zorba really rocks. 
          </content>
          <content contentType="image/gif" charset="UTF-8" contentTransferEncoding="ENCBASE64">
            {$image}
          </content>
          </multipart>
        </body>
      </email:message>);
