(:
 : Copyright 2006-2009 The FLWOR Foundation.
 :
 : Licensed under the Apache License, Version 2.0 (the "License");
 : you may not use this file except in compliance with the License.
 : You may obtain a copy of the License at
 :
 : http://www.apache.org/licenses/LICENSE-2.0
 :
 : Unless required by applicable law or agreed to in writing, software
 : distributed under the License is distributed on an "AS IS" BASIS,
 : WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 : See the License for the specific language governing permissions and
 : limitations under the License.
:)

(:~
  : Module Name: email<br/>
  : Module Version: 0.1<br/>
  : Date: October 29, 2009<br/>
  : Copyright:  2006-2009 The FLWOR Foundation. Licensed under the Apache License, Version 2.0.<br/>
  : Proprietary XQuery Extensions Used: None<br/>
  : XQuery Specification: January 2007<br/>
  : Module Overview: This library module provides the functions used to send emails.<br/>
  : @author Sorin Nasoi<br/><br/>
  :<ul>
  :  <li>Table of Contents 
  :    <ul>
  :      <li><a href="#intro_mail">1 Introduction</a></li>
  :      <li><a href="#configuring_mail">2 Configuring</a> 
  :        <ul>
  :          <li><a href="#mail_installation">2.1 Installation</a></li>
  :          <li><a href="#mail_option_declaration">2.2 Configuring SMTP parameters</a></li>
  :        </ul>
  :      </li>
  :      <li><a href="#function_summary">3 Function Summary</a></li>
  :      <li><a href="#functions">4 Functions</a> 
  :        <ul>
  :          <li><a href="#send-5">4.1 smtp:send($to as xs:string?, $cc as xs:string?, $bcc as xs:string?, $subject  as xs:string?, $body as xs:string) as xs:boolean</a></li>
  :          <li><a href="#send-3">4.2 smtp:send($to as xs:string, $subject as xs:string, $body as xs:string) as xs:boolean</a></li>
  :          <li><a href="#send-1">4.3 smtp:send($arg as node()) as xs:boolean</a></li>
  :        </ul>
  :      </li>
  :    </ul>
  :  </li>
  :  <li><a href="#apendix_naming">Appendix A: SMTP server naming conventions</a></li>
  :</ul>
  :<h2><a name="intro_mail">1 Introduction</a></h2>
  :Currently, Zorba provides functions for sending mime messages.<br/>
  :From all the possible <a href="http://www.iana.org/assignments/media-types/" target="_blank">MIME Media Types</a> zorba currently has support for sending the following types of messages:
  :<ul>
  :<li><a href="http://www.iana.org/assignments/media-types/text/" target="_blank">text</a> (plain, html)</li>
  :<li><a href="http://www.iana.org/assignments/media-types/multipart/" target="_blank">multipart</a> (alternative, mixed, related)</li>
  :<li><a href="http://www.iana.org/assignments/media-types/image/" target="_blank">image</a> (gif, jpeg, png, tiff)</li>
  :</ul>
  :In other words you can send any combination of the followind types of messages:
  :<ul>
  :  <li>textual messages, the character sets are <strong>not</strong> restricted to US-ASCII (amongst the most common mime types are text/plain, text/html)</li>
  :  <li>several body messages each one an alternative of the same information, for example one body part in text/plain and another one in text/html (the mime type is multipart/alternative)</li>
  :  <li>XHTML messages with embedded images (the mime type is multipart/related)</li>
  :  <li>messages with attachments (the mime type is multipart/mixed)</li>
  :  <li>Images (amongst the most common mime types are image/gif, image/jpeg, image/png, image/tiff)</li>
  :</ul>
  :<h2><a name="configuring_mail">2 Configuring</a></h2>
  :Zorba provides email support using the C-Client library part of <a href="http://www.washington.edu/imap/" target="_blank">UW IMAP toolkit</a>.<br/>
  :<h3><a name="mail_installation">2.1 Installation</a></h3>
  :<ul><li><strong>Unix/Linux/Mac OS</strong></li>
  :The easiest way is to install CClient library (for instance on Suse CClient is part of a package called 'imap-lib').<br/><br/>
  :If you want to get <a href="http://www.washington.edu/imap/" target="_blank">UW IMAP toolkit</a> and compile it yourself, 
  :make sure the name of the library is prefixed by 'lib' and suffixed with '.a' (for example libc-client.a on Linux/Unix or libc-client4.a on Mac OS).<br/>
  :After that is done recompile Zorba after setting:
  :<pre class="fragment">
  :-D CCLIENT_INCLUDE="path_to_imap_2007e\c-client"
  :-D CCLIENT_LIBRARY="path_to_imap_2007e\c-client\libc-client.a"
  :</pre>
  :
  :<li><strong>Windows</strong></li>
  :We suggest compiling <a href="http://www.washington.edu/imap/" target="_blank">UW IMAP toolkit</a> and rebuilding Zorba after setting the following 2 flags: <br/>
  :assuming the C-Client sources are under /home/user/imap-2007e, <br/>
  :<pre class="fragment">
  :-D CCLIENT_INCLUDE="path_to_imap_2007e\c-client"
  :-D CCLIENT_LIBRARY="path_to_imap_2007e\c-client\release\cclient.lib"
  :</pre>
  :</ul>
  :<h3><a name="mail_option_declaration">2.2 Configuring SMTP parameters</a></h3>
  :The SMTP parameters have to be declared as options prior to calling the email functions:<br/><br/>
  :<pre class="fragment">
  :import module namespace smtp= 'http://www.zorba-xquery.com/modules/email/smtp';<br /><br />
  :declare option smtp:SMTPServer <span>"smtp.gmail.com:587/tls/novalidate-cert"</span>;<br />
  :declare option smtp:SMTPUser <span>"user"</span>;<br />
  :declare option smtp:SMTPPwd <span>"password"</span>;<br />
  :</pre>
  :
  :These is the meaning of each parameter: <br/>
  :<ul><li><strong>SMTPServer</strong></li>
  : The SMTP server has to be specified as a string in the following form: <br/>
  : <em> remote_system_name [":" port] [flags] </em> <br/>
  : a complete list of usage see <a href="http://www.zorba-xquery.com/doc/zorba-latest/zorba/html/email.html#apendix_naming">Appendix A: SMTP server naming conventions</a>
  :For example: <br/>
  : <ul>
  :   <li>smtp.gmail.com:587/tls/novalidate-cert</li><br/>
  :   <li>[209.85.129.111]:587/tls/novalidate-cert</li><br/>
  : </ul>
  :<li><strong>SMTPUser</strong></li>
  : The remote username used to authenticate to the SMTP server. <br/>
  :Note: <br/>
  : If you have specified a username in the SMTP server through <b>/user=</b> it will be overwritten by the one defined as SMTP username.
  :<li><strong>SMTPPwd</strong></li>
  : The remote username password used to authenticate to the SMTP server. <br/>
  :</ul>
  :<h2><a name="apendix_naming">Appendix A: SMTP server naming conventions</a></h2>
  :This list is in fact section <em>III. Remote names</em> part of the UW IMAP toolkit, file <a href="http://www.washington.edu/imap/documentation/naming.txt.html" target="_blank">naming.txt</a>.<br />
  :
  :All names are in the form <br />
  : <table border="1" cellpadding="0" cellspacing="0">
  :<tbody><tr>
  :<td colspan="2"><b>remote_system_name [":" port] [flags]</b></td></tr>
  :<tr><td colspan="2">where:  </td></tr>
  :<tr><td><b>remote_system_name</b> </td><td>Internet domain name or bracketed IP address of server.</td></tr>
  :<tr><td><b>port</b></td><td>optional TCP port number, default is the default port for that service.</td></tr>
  :<tr><td><b>flags</b></td><td>optional flags, one of the following:</td></tr>
  :<tr><td><b>/user=</b></td><td>remote user name for login on the server.</td></tr>
  :<tr><td><b>/anonymous</b></td><td>remote access as anonymous user.</td></tr>
  :<tr><td><b>/secure</b></td><td>do not transmit a plaintext password over the network.</td></tr>
  :<tr><td><b>/ssl</b></td><td>use the Secure Socket Layer to encrypt the session.</td></tr>
  :<tr><td><b>/validate-cert</b></td><td>validate certificates from TLS/SSL server (this is the default behavior).</td></tr>
  :<tr><td><b>/novalidate-cert</b></td><td>do not validate certificates from TLS/SSL server, needed if server uses self-signed certificates.</td></tr>
  :<tr><td><b>/tls</b></td><td>force use of start-TLS to encrypt the session, and reject connection to servers that do not support it.</td></tr>
  :<tr><td><b>/tls-sslv23</b> </td><td>use the depreciated SSLv23 client when negotiating TLS to the server. This is necessary with some broken servers which (incorrectly) think that TLS is just another way of doing SSL </td></tr>
  :<tr><td><b>/notls</b> </td><td>do not do start-TLS to encrypt the session, even with servers that support it  </td></tr>
  :<tr><td><b>/loser</b> </td><td>disable various protocol features and perform various client-side workarounds; for example, it disables the SEARCH command in IMAP and does client-side searching instead. The precise measures taken by <b>/loser</b> depend upon the protocol and are subject to change over time. <b>/loser</b> is intended for use with defective servers which do not implement the protocol specification correctly. It should be used only as a last resort since it will seriously degrade performance </td></tr>
  :</tbody></table>
  :For example: <br />
  :<ul>
  :  <li>smtp.gmail.com:587/tls/novalidate-cert</li>
  :  <li>[209.85.129.111]:587/tls/novalidate-cert</li>
  :</ul>
  : 
  :)

module namespace smtp = "http://www.zorba-xquery.com/modules/email/smtp";

 (:~
  : function for sending email.
  :
  : @param $to Receiver(s) of the email. The formatting of this string must comply with RFC 2822.
  : @param $cc Receiver(s) of the email. The formatting of this string must comply with RFC 2822.
  : @param $bcc Receiver(s) of the email. The formatting of this string must comply with RFC 2822.
  : @param $subject Subject of the email to be sent. The formatting of this string must comply with RFC 2047.
  : @param $body The message to be sent. Each line should be separated with a LF (\n). Lines should not be larger than 70 characters.
  : @return Returns true if the email was set successfully, false otherwise.
  :
  : @error   XQP0021 If the SMTP server was not set in the static context an error is raised API0038_SMTP_SEVER_ERROR_SET_OPTION.
  : @error   XQP0021 If the $to, $cc, $bcc parameters are all empty an error is raised API0039_RECIPIENT_SET_OPTION.
  : @error   XQP0021 If the email could not be sent for some reason an error is raised API0040_MAIL_NOT_SENT.
  :)
declare sequential function smtp:send($to       as xs:string?,
                           $cc       as xs:string?,
                           $bcc      as xs:string?,
                           $subject  as xs:string?,
                           $body     as xs:string)  as xs:boolean
{
let $message := <mail>
                 <message>
                  <from/>
                  { if ($to) then <to>{$to}</to> else () }
                  { if ($cc) then <cc>{$cc}</cc> else () }
                  { if ($bcc) then <bcc>{$bcc}</bcc> else () }
                  { if ($subject) then <subject>{$subject}</subject> else () }
                  <content>
                    <contentType>text/plain</contentType>  
                    <charset>UTF-8</charset>
                    <contentTransferEncoding>ENC8BIT</contentTransferEncoding>
                    <body serialization="TEXT">{$body}</body>
                  </content>  
                 </message>
                </mail>

return smtp:send($message)
};

 (:~
  : function for sending email.
  :
  : @param $to Receiver(s) of the email. The formatting of this string must comply with RFC 2822.
  : @param $subject Subject of the email to be sent. The formatting of this string must comply with RFC 2047.
  : @param $message Message to be sent.Each line should be separated with a LF (\n). Lines should not be larger than 70 characters.
  : @return Returns true if the email was set successfully, false otherwise.
  :
  : @error   XQP0021 If the SMTP server was not set in the static context an error is raised API0038_SMTP_SEVER_ERROR_SET_OPTION.
  : @error   XQP0021 If the $to, $cc, $bcc parameters are all empty an error is raised API0039_RECIPIENT_SET_OPTION.
  : @error   XQP0021 If the email could not be sent for some reason an error is raised API0040_MAIL_NOT_SENT.
  :)
declare sequential function smtp:send($to       as xs:string,
                                      $subject  as xs:string,
                                      $body     as xs:string)  as xs:boolean
{
  smtp:send($to,'','',$subject,$body)
};


 (:~
  : function for sending email.
  :
  : @param $arg Contains the envelope info (from, to, cc, bcc, subject) and the multipart message.
  : @return Returns true if the email was set successfully, false otherwise.
  :
  : @error   XQP0021 If the SMTP server was not set in the static context an error is raised API0038_SMTP_SEVER_ERROR_SET_OPTION.
  : @error   XQP0021 If the $to, $cc, $bcc parameters are all empty an error is raised API0039_RECIPIENT_SET_OPTION.
  : @error   XQP0021 If the email could not be sent for some reason an error is raised API0040_MAIL_NOT_SENT.
  :)
declare sequential function smtp:send($arg as node()) as xs:boolean external;