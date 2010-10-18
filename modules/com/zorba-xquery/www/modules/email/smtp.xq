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
 : This is a library module that provides functions for sending emails.
 :
 :
 : <ul>
 :   <li>Table of Contents 
 :     <ul>
 :       <li><a href="#intro_mail">1 Introduction</a></li>
 :       <li><a href="#mail_option_declaration">2 Configuring SMTP parameters</a></li>
 :       <li><a href="#examples">3 Examples</a></li>
 :         <ul>
 :         <li><a href="#example_text">3.1 Composing text messages</a></li>
 :         <ul>
 :           <li><a href="#example_1">3.1.1 Sending a text message</a></li>
 :           <li><a href="#example_2">3.1.2 Sending a message to multiple recipients</a></li>
 :           <li><a href="#example_3">3.1.3 Sending a message using CC and BCC</a></li>
 :         </ul>
 :         <li><a href="#example_mime">3.2 Composing mime messages</a></li>
 :         <ul>
 :           <li><a href="#example_4">3.2.1 Sending a text/html message</a></li>
 :           <li><a href="#example_5">3.2.2 Sending a image/gif message</a></li>
 :           <li><a href="#example_6">3.2.3 Sending a multipart/alternative message</a></li>
 :           <li><a href="#example_7">3.2.4 Sending a multipart/mixed message</a></li>
 :           <li><a href="#example_8">3.2.5 Sending a multipart/related message</a></li>
 :         </ul>
 :        </ul>
 :       <li><a href="#function_summary">4 Function Summary</a></li>
 :       <li><a href="#functions">4 Functions</a></li>
 :     </ul>
 :   </li>
 :   <li><a href="#apendix_naming">Appendix A: SMTP server naming conventions</a></li>
 :   <li><a href="#email_schema.xsd">Appendix B: email_schema.xsd</a></li>
 :   <li><a href="#mime_schema.xsd">Appendix C: mime_schema.xsd</a></li>
 : </ul>
 :
 :
 : <h2><a name="intro_mail">1 Introduction</a></h2>
 : <p>Currently, Zorba provides functions for sending mime messages. From all the possible
 : <a href="http://www.iana.org/assignments/media-types/" target="_blank">MIME Media Types</a>
 : Zorba currently has support for sending the following types of messages:</p>
 : <ul>
 : <li><a href="http://www.iana.org/assignments/media-types/text/" target="_blank">text</a> (plain, html)</li>
 : <li><a href="http://www.iana.org/assignments/media-types/multipart/" target="_blank">multipart</a> (alternative, mixed, related)</li>
 : <li><a href="http://www.iana.org/assignments/media-types/image/" target="_blank">image</a> (gif, jpeg, png, tiff)</li>
 : </ul>
 : <p>In other words you can send any combination of the followind types of messages:</p>
 : <ul>
 :   <li>textual messages, the character sets are <strong>not</strong> restricted to US-ASCII (amongst the most common mime types are text/plain, text/html)</li>
 :   <li>several body messages each one an alternative of the same information, for example one body part in text/plain and another one in text/html (the mime type is multipart/alternative)</li>
 :   <li>XHTML messages with embedded images (the mime type is multipart/related)</li>
 :   <li>messages with attachments (the mime type is multipart/mixed)</li>
 :   <li>Images (amongst the most common mime types are image/gif, image/jpeg, image/png, image/tiff)</li>
 : </ul>
 :
 :
 : <h2><a name="mail_option_declaration">2 Configuring SMTP parameters</a></h2>
 : The SMTP parameters have to be declared as options prior to calling the email functions:<br/><br/>
 : <pre class="fragment">
 : import module namespace smtp= 'http://www.zorba-xquery.com/modules/email/smtp';<br /><br />
 : declare option smtp:SMTPServer <span>"smtp.gmail.com:587/tls/novalidate-cert"</span>;<br />
 : declare option smtp:SMTPUser <span>"user"</span>;<br />
 : declare option smtp:SMTPPwd <span>"password"</span>;
 : </pre>
 : 
 : These is the meaning of each parameter: <br/>
 : <ul><li><strong>SMTPServer</strong></li>
 :  The SMTP server has to be specified as a string in the following form:
 : <tt>remote_system_name [":" port] [flags]</tt>. See <a href="http://www.zorba-xquery.com/doc/zorba-latest/zorba/xqdoc/xhtml/com/zorba-xquery/www/modules/email/smtp.html#apendix_naming">Appendix A: SMTP server naming conventions</a> for more details. For example:
 :  <ul>
 :    <li>smtp.gmail.com:587/tls/novalidate-cert</li>
 :    <li>[209.85.129.111]:587/tls/novalidate-cert</li>
 :  </ul>
 : <li><strong>SMTPUser</strong></li>
 :  The remote username used to authenticate to the SMTP server. <b>Note</b>: if you have specified a username in the SMTP server through <b>/user=</b> it will be overwritten by the one defined as SMTP username.
 : <li><strong>SMTPPwd</strong></li>
 :  The remote username password used to authenticate to the SMTP server.
 : </ul>
 : <h2><a name="examples">3 Examples</a></h2>
 : Note: in the examples below, we assume that you have an email account at
 : <strong>gmail.com</strong>, with the username "<strong>testUser</strong>" and the password "<strong>testPWD</strong>" <br /><br />
 :
 : <h3><a name="example_text">3.1 Composing text messages</a></h3><br />
 : We will be using these send signatures: <a href="#send-5">smtp:send</a> (for <a href="#example_3">Example 3</a>) and
 : <a href="#send-3">smtp:send</a> (for <a href="#example_1">Example 1</a> and <a href="#example_2">Example 2</a>). <br /><br />
 : <a name="example_1">3.1.1 Sending a text message:</a> <br />
 : <pre class="fragment">
 : import module namespace smtp = 'http://www.zorba-xquery.com/modules/email/smtp'; <br /><br />
 : declare option smtp:SMTPServer "smtp.gmail.com:587/tls/novalidate-cert";<br />
 : declare option smtp:SMTPUser "testUser";<br />
 : declare option smtp:SMTPPwd "testPWD";<br /><br />
 : smtp:send("user@example.com","subject:test message","it works")</pre><br />
 : <a name="example_2">3.1.2 Sending a message to multiple recipients:</a> <br />
 : <pre class="fragment">
 : import module namespace smtp = 'http://www.zorba-xquery.com/modules/email/smtp'; <br /><br />
 : declare option smtp:SMTPServer "smtp.gmail.com:587/tls/novalidate-cert";<br />
 : declare option smtp:SMTPUser "testUser";<br />
 : declare option smtp:SMTPPwd "testPWD";<br /><br />
 : smtp:send("user1 &lt;user1@example.com&gt;, user2 &lt;user2@example.com&gt;","subject:test message","it works")</pre><br />
 : <a name="example_3">3.1.3 Sending a message using CC and BCC:</a> <br />
 : <pre class="fragment">
 : import module namespace smtp = 'http://www.zorba-xquery.com/modules/email/smtp'; <br /><br />
 : declare option smtp:SMTPServer "smtp.gmail.com:587/tls/novalidate-cert";<br />
 : declare option smtp:SMTPUser "testUser";<br />
 : declare option smtp:SMTPPwd "testPWD";<br /><br />
 : smtp:send("","user1_cc &lt;user1_cc@example.com&gt;", "user1_bcc &lt;user1_bcc@example.com&gt;"
 : ,"subject:test message","it works")</pre><br />
 :
 : <h3><a name="example_mime">3.2 Composing mime messages</a></h3><br />
 : We will be using this send signature: <a href="#send-1">smtp:send</a>.<br />
 : In order to compose a mime message that can be sent with Zorba we have to create an .xml file and validate it using the schema provided below: <a href="#email_schema.xsd">Appendix B: email_schema.xsd</a>.<br /><br />
 : Then all we have to do is call Zorba command line in the following manner: <br />
 : <pre class="fragment">
 : zorba -f -q mime_query.xq -e input-context:=email_text_html.xml
 : </pre><br />
 : Where mime_query.xq looks like this:
 : <pre class="fragment">
 : import module namespace smtp = 'http://www.zorba-xquery.com/modules/email/smtp'; <br /><br />
 : declare option smtp:SMTPServer "smtp.gmail.com:587/tls/novalidate-cert";<br />
 : declare option smtp:SMTPUser "testUser";<br />
 : declare option smtp:SMTPPwd "testPWD";<br /><br />
 : declare variable $input-context external;<br /><br />
 : smtp:send(fn:doc($input-context))
 : </pre><br />
 : For your convenience we created some sample .xml's for the following types of mime messages:<br />
 : <a name="example_4">3.2.1 text/html message:</a>  <br />
 : <pre class="fragment">
 :  &lt;?xml version="1.0" encoding="UTF-8" ?&gt;<br /><br />
 : 
 : &lt;Message xmlns="http://www.zorba-xquery.org/email"<br />
 :   xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"<br />
 :   xsi:schemaLocation="email_schema.xsd"&gt;<br />
 :   &lt;from&gt;testUser@gmail.com&lt;/from&gt;<br />
 :   &lt;sender&gt;testUser@gmail.com&lt;/sender&gt;<br />
 :   &lt;replyTo&gt;testUser@gmail.com&lt;/replyTo&gt;<br />
 :   &lt;cc&gt;user1_cc &lt;user1_cc@example.com&gt;&lt;/cc&gt;<br />
 :   &lt;subject&gt;A text/html example&lt;/subject&gt;<br /><br />
 :     
 :   &lt;!-- mime:messageType --&gt;<br />
 :   &lt;content&gt;<br />
 :     &lt;contentType&gt;text/html&lt;/contentType&gt;<br />
 :     &lt;charset&gt;utf-8&lt;/charset&gt;<br />
 :     &lt;contentTransferEncoding&gt;ENC8BIT&lt;/contentTransferEncoding&gt;<br />
 :     &lt;body serialization="HTML"&gt;&amp;lt;!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN"&amp;gt;<br />
 :       &amp;lt;HTML&amp;gt;&amp;lt;HEAD&amp;gt;<br />
 :       &amp;lt;META HTTP-EQUIV="Content-Type" CONTENT="text/html; charset=ISO-8859-1"&amp;gt;<br />
 :       &amp;lt;BODY&amp;gt;&amp;lt;b&amp;gt;This is some HTML content&amp;lt;/b&amp;gt;&amp;lt;/BODY&amp;gt;<br />
 :       &amp;lt;/HTML&amp;gt;&lt;/body&gt;<br />
 :   &lt;/content&gt;<br />
 : &lt;/Message&gt;
 :</pre><br /><br />
 :
 : <a name="example_5">3.2.2 image/gif message:</a>  <br />
 : <pre class="fragment">
 :  &lt;?xml version="1.0" encoding="UTF-8" ?&gt;<br /><br />
 :
 : &lt;Message xmlns="http://www.zorba-xquery.org/email"<br />
 :   xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"<br />
 :   xsi:schemaLocation="email_schema.xsd"&gt;<br />
 :   &lt;from&gt;testUser@gmail.com&lt;/from&gt;<br />
 :   &lt;sender&gt;testUser@gmail.com&lt;/sender&gt;<br />
 :   &lt;replyTo&gt;testUser@gmail.com&lt;/replyTo&gt;<br />
 :   &lt;cc&gt;user1_cc &lt;user1_cc@example.com&gt;&lt;/cc&gt;<br />
 :   &lt;subject&gt;A image/gif example&lt;/subject&gt;<br /><br />
 :
 : &lt;content&gt;<br />
 : &lt;contentType&gt;image/gif&lt;/contentType&gt;<br />
 :  &lt;contentTransferEncoding&gt;ENCBASE64&lt;/contentTransferEncoding&gt;<br /><br />
 :
 :&lt;body serialization="base64"&gt;R0lGODlhDAAMAKIFAF5LAP/zxAAAANyuAP/gaP///wAAAAAAACH/C05FVFNDQVBFMi4wAwEAAAAh+QQFFAAFACwAAAAADAAMAAADKViz3BowyhWIEMRiQnW+WZeNYweQxCmeozpUKSCzK8q9qX3D+qA0wEICACH5BAUUAAUALAMABQADAAUAAAMGSEC82i8BACH5BAUUAAUALAQABQAGAAYAAAMLSLqw1E1BQKWLKwEAIfkEBRQABQAsAwAGAAMABQAAAwYIVKXNyiUAOw==&lt;/body&gt;<br />
 :&lt;/content&gt;<br /><br />
 :
 :&lt;/Message&gt;
 : </pre><br /><br />
 :
 : <a name="example_6">3.2.3 multipart/alternative message:</a>  <br />
 : <pre class="fragment">
 :  &lt;?xml version="1.0" encoding="UTF-8" ?&gt;<br /><br />
 :
 : &lt;Message xmlns="http://www.zorba-xquery.org/email"<br />
 :   xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"<br />
 :   xsi:schemaLocation="email_schema.xsd"&gt;<br />
 :   &lt;from&gt;testUser@gmail.com&lt;/from&gt;<br />
 :   &lt;sender&gt;testUser@gmail.com&lt;/sender&gt;<br />
 :   &lt;replyTo&gt;testUser@gmail.com&lt;/replyTo&gt;<br />
 :   &lt;cc&gt;user1_cc &lt;user1_cc@example.com&gt;&lt;/cc&gt;<br />
 :   &lt;subject&gt;A multipart/alternative example&lt;/subject&gt;<br /><br />
 :
 :   &lt;multipart&gt;<br />
 :   &lt;contentType&gt;multipart/alternative&lt;/contentType&gt;<br /><br />
 :
 :   &lt;multipart&gt;<br />
 :     &lt;contentType&gt;text/plain&lt;/contentType&gt;<br />
 :     &lt;charset&gt;us-ascii&lt;/charset&gt;<br />
 :     &lt;contentTransferEncoding&gt;ENC7BIT&lt;/contentTransferEncoding&gt;<br />
 :     &lt;body serialization="TEXT"&gt;This is the text version&lt;/body&gt;<br />
 :   &lt;/multipart&gt;<br /><br />
 :
 :   &lt;multipart&gt;<br />
 :     &lt;contentType&gt;text/html&lt;/contentType&gt;<br />
 :     &lt;body serialization="HTML"&gt;&amp;lt;!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN"&amp;gt;<br />
 :       &amp;lt;HTML&amp;gt;&amp;lt;HEAD&amp;gt;<br />
 :       &amp;lt;META HTTP-EQUIV="Content-Type" CONTENT="text/html; charset=ISO-8859-1"&amp;gt;<br />
 :       &amp;lt;BODY&amp;gt;&amp;lt;b&amp;gt;This is some HTML content&amp;lt;/b&amp;gt;&amp;lt;/BODY&amp;gt;<br />
 :       &amp;lt;/HTML&amp;gt;&lt;/body&gt;<br />
 :   &lt;/multipart&gt;<br /><br />
 :
 : &lt;/multipart&gt;<br /><br />
 : 
 :&lt;/Message&gt;
 :</pre><br /><br />
 :
 : <a name="example_7">3.2.4 multipart/mixed message:</a>  <br />
 : <pre class="fragment">
 :  &lt;?xml version="1.0" encoding="UTF-8" ?&gt;<br /><br />
 :
 : &lt;Message xmlns="http://www.zorba-xquery.org/email"<br />
 :   xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"<br />
 :   xsi:schemaLocation="email_schema.xsd"&gt;<br />
 :   &lt;from&gt;testUser@gmail.com&lt;/from&gt;<br />
 :   &lt;sender&gt;testUser@gmail.com&lt;/sender&gt;<br />
 :   &lt;replyTo&gt;testUser@gmail.com&lt;/replyTo&gt;<br />
 :   &lt;cc&gt;user1_cc &lt;user1_cc@example.com&gt;&lt;/cc&gt;<br />
 :   &lt;subject&gt;A multipart/mixed example&lt;/subject&gt;<br /><br />
 :
 :  &lt;multipart&gt;<br />
 :  &lt;contentType&gt;multipart/mixed&lt;/contentType&gt;<br /><br />
 :
 :  &lt;multipart&gt;<br />
 :   &lt;contentType&gt;text/plain&lt;/contentType&gt;<br />
 :    &lt;charset&gt;us-ascii&lt;/charset&gt;<br />
 :    &lt;contentTransferEncoding&gt;ENC7BIT&lt;/contentTransferEncoding&gt;<br />
 :    &lt;body serialization="TEXT"&gt;This is a simple text message&lt;/body&gt;<br />
 :  &lt;/multipart&gt;<br /><br />
 :
 :    &lt;multipart&gt;<br />
 :      &lt;contentType&gt;image/gif&lt;/contentType&gt;<br />
 :      &lt;name&gt;32B.gif&lt;/name&gt;<br />
 :      &lt;contentTransferEncoding&gt;ENCBASE64&lt;/contentTransferEncoding&gt;<br />
 :      &lt;Content-Disposition&gt;attachment&lt;/Content-Disposition&gt;<br />
 :      &lt;filename&gt;32B.gif&lt;/filename&gt;<br />
 :      &lt;X-Attachment-Id&gt;file0&lt;/X-Attachment-Id&gt;<br />
 :      &lt;body serialization="base64">R0lGODlhDAAMAKIFAF5LAP/zxAAAANyuAP/gaP///wAAAAAAACH/C05FVFNDQVBFMi4wAwEAAAAh+QQFFAAFACwAAAAADAAMAAADKViz3BowyhWIEMRiQnW+WZeNYweQxCmeozpUKSCzK8q9qX3D+qA0wEICACH5BAUUAAUALAMABQADAAUAAAMGSEC82i8BACH5BAUUAAUALAQABQAGAAYAAAMLSLqw1E1BQKWLKwEAIfkEBRQABQAsAwAGAAMABQAAAwYIVKXNyiUAOw==&lt;/body&gt;<br />
 :    &lt;/multipart&gt;<br /><br />
 :
 :  &lt;/multipart&gt;<br /><br />
 :
 :&lt;/Message&gt;<br />
 :</pre><br /><br />
 :
 : <a name="example_8">3.2.5 multipart/related message:</a>  <br />
 : <pre class="fragment">
 :  &lt;?xml version="1.0" encoding="UTF-8" ?&gt;<br /><br />
 :
 : &lt;Message xmlns="http://www.zorba-xquery.org/email"<br />
 :   xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"<br />
 :   xsi:schemaLocation="email_schema.xsd"&gt;<br />
 :   &lt;from&gt;testUser@gmail.com&lt;/from&gt;<br />
 :   &lt;sender&gt;testUser@gmail.com&lt;/sender&gt;<br />
 :   &lt;replyTo&gt;testUser@gmail.com&lt;/replyTo&gt;<br />
 :   &lt;to&gt;user1_to &lt;user1_to@example.com&gt;&lt;/to&gt;<br />
 :   &lt;subject&gt;A multipart/related example&lt;/subject&gt;<br /><br />
 :
 :  &lt;multipart&gt;<br />
 :   &lt;contentType&gt;multipart/related&lt;/contentType&gt;<br /><br />
 :
 :  &lt;multipart&gt;<br />
 :    &lt;contentType&gt;multipart/alternative&lt;/contentType&gt;<br />
 :    &lt;multipart&gt;<br />
 :      &lt;contentType&gt;text/plain&lt;/contentType&gt;<br />
 :      &lt;charset&gt;us-ascii&lt;/charset&gt;<br />
 :      &lt;contentTransferEncoding&gt;ENC7BIT&lt;/contentTransferEncoding&gt;<br />
 :      &lt;body serialization="TEXT"&gt; *this works* &lt;/body&gt;<br />
 :    &lt;/multipart&gt;<br />
 :    &lt;multipart&gt;<br />
 :      &lt;contentType&gt;text/html&lt;/contentType&gt;<br />
 :      &lt;charset&gt;utf-8&lt;/charset&gt;<br />
 :      &lt;contentTransferEncoding&gt;ENC8BIT&lt;/contentTransferEncoding&gt;<br />
 :      &lt;body serialization="HTML"&gt;<br />
 :        &amp;lt;img src="cid:338@goomoji.gmail"&amp;gt;<br />
 :        Hi,&amp;lt;br&amp;gt;<br />
 :        if you can see an image, it's good. &amp;lt;br&amp;gt;&amp;lt;br&amp;gt;<br />
 :        This email was sent with Zorba.<br />
 :      &lt;/body&gt;<br />
 :    &lt;/multipart&gt;<br />
 :  &lt;/multipart&gt;<br /><br />
 :
 :  &lt;multipart&gt;<br />
 :    &lt;contentType&gt;image/gif&lt;/contentType&gt;<br />
 :    &lt;name&gt;338.gif&lt;/name&gt;<br />
 :    &lt;contentTransferEncoding&gt;ENCBASE64&lt;/contentTransferEncoding&gt;<br />
 :    &lt;Content-ID&gt;&amp;lt;338@goomoji.gmail&amp;gt;&lt;/Content-ID&gt;<br />
 :    &lt;Content-Disposition&gt;inline&lt;/Content-Disposition&gt;<br />
 :    &lt;filename&gt;338.gif&lt;/filename&gt;<br />
 :    &lt;body serialization="base64"&gt;R0lGODlhDAAMAKIGAF5LAJh3AP/zxAAAANyuAP/gaP///wAAACH/C05FVFNDQVBFMi4wAwEAAAAh
 :      +QQFZAAGACwAAAAADAAMAAADJmi03CowyiWKvZeWMSy32rd1hYZh5gkSVQFY79q6saxm7A0qTW8k
 :      ACH5BAUUAAYALAIAAwAIAAYAAAMMWFOsvq/JSYMN07YEACH5BAUUAAYALAMABwAGAAMAAAMIGLq0
 :      QYVImAAAIfkEBRQABgAsAgACAAgABQAAAwtYU6y+r8k5g70lAQAh+QQFFAAGACwCAAIACAAFAAAD
 :      CVi6O+xQRUZrAgAh+QQFFAAGACwCAAIACAAFAAADC1hTrL6vyTmDvSUBACH5BAUUAAYALAIAAgAI
 :      AAUAAAMJWLo77FBFRmsCACH5BAUUAAYALAIAAgAIAAUAAAMLWFOsvq/JOYO9JQEAIfkEBRQABgAs
 :      AgACAAgABQAAAwlYujvsUEVGawIAIfkEBRQABgAsAgACAAgABQAAAwtYU6y+r8k5g70lAQAh+QQF
 :      FAAGACwCAAIACAAFAAADCVi6O+xQRUZrAgAh+QQFFAAGACwCAAIACAAFAAADC1hTrL6vyTmDvSUB
 :      ACH5BAUUAAYALAIAAgAIAAUAAAMJWLo77FBFRmsCACH5BAUUAAYALAMABwAGAAMAAAMHWLZWvs+9
 :      BAAh+QQFFAAGACwEAAcABAACAAADBAhVCpoAOw==&lt;/body&gt;<br />
 :  &lt;/multipart&gt;<br /><br />
 :
 :&lt;/multipart&gt;<br /><br />
 :
 :&lt;/Message&gt;<br />
 : </pre><br /><br />
 :
 : <h2><a name="apendix_naming">Appendix A: SMTP server naming conventions</a></h2>
 : This list is in fact section <em>III. Remote names</em> part of the UW IMAP toolkit, file <a href="http://www.washington.edu/imap/documentation/naming.txt.html" target="_blank">naming.txt</a>.<br />
 :
 : All names are in the form <br />
 :  <table border="1" cellpadding="0" cellspacing="0">
 : <tbody><tr>
 : <td colspan="2"><b>remote_system_name [":" port] [flags]</b></td></tr>
 : <tr><td colspan="2">where:  </td></tr>
 : <tr><td><b>remote_system_name</b> </td><td>Internet domain name or bracketed IP address of server.</td></tr>
 : <tr><td><b>port</b></td><td>optional TCP port number, default is the default port for that service.</td></tr>
 : <tr><td><b>flags</b></td><td>optional flags, one of the following:</td></tr>
 : <tr><td><b>/user=</b></td><td>remote user name for login on the server.</td></tr>
 : <tr><td><b>/anonymous</b></td><td>remote access as anonymous user.</td></tr>
 : <tr><td><b>/secure</b></td><td>do not transmit a plaintext password over the network.</td></tr>
 : <tr><td><b>/ssl</b></td><td>use the Secure Socket Layer to encrypt the session.</td></tr>
 : <tr><td><b>/validate-cert</b></td><td>validate certificates from TLS/SSL server (this is the default behavior).</td></tr>
 : <tr><td><b>/novalidate-cert</b></td><td>do not validate certificates from TLS/SSL server, needed if server uses self-signed certificates.</td></tr>
 : <tr><td><b>/tls</b></td><td>force use of start-TLS to encrypt the session, and reject connection to servers that do not support it.</td></tr>
 : <tr><td><b>/tls-sslv23</b> </td><td>use the depreciated SSLv23 client when negotiating TLS to the server. This is necessary with some broken servers which (incorrectly) think that TLS is just another way of doing SSL </td></tr>
 : <tr><td><b>/notls</b> </td><td>do not do start-TLS to encrypt the session, even with servers that support it  </td></tr>
 : <tr><td><b>/loser</b> </td><td>disable various protocol features and perform various client-side workarounds; for example, it disables the SEARCH command in IMAP and does client-side searching instead. The precise measures taken by <b>/loser</b> depend upon the protocol and are subject to change over time. <b>/loser</b> is intended for use with defective servers which do not implement the protocol specification correctly. It should be used only as a last resort since it will seriously degrade performance </td></tr>
 : </tbody></table>
 : For example: <br />
 : <ul>
 :   <li>smtp.gmail.com:587/tls/novalidate-cert</li>
 :   <li>[209.85.129.111]:587/tls/novalidate-cert</li>
 : </ul>
 :
 : <a name="email_schema.xsd">Appendix B: email_schema.xsd</a>: <br />
 : <pre class="fragment">&lt;?xml version="1.0" encoding="UTF-8"?&gt;<br />
 : &lt;schema xmlns="http://www.w3.org/2001/XMLSchema" targetNamespace="http://www.zorba-xquery.org/email"<br />
 :   xmlns:tns="http://www.zorba-xquery.org/email" <br />
 :   elementFormDefault="qualified"&gt;<br /><br />
 : 
 :   &lt;import namespace="http://www.zorba-xquery.org/mime" schemaLocation="mime_schema.xsd"/&gt;<br />
 :
 :   &lt;!--<br />
 :   MIME is expressed as XML by a simple set of transforms:<br /><br />
 : 
 :     * A MIME message is rooted in a tns:messageType element<br />
 :     * Each header is represented as a child element of the tns:envelope part of tns:messageType<br />
 :     * Each parameter of a header is represented as a child element of the header<br />
 :     * The body of a message is represented as a mime:bodyTypeChoice element<br />
 :     * The mime:Body of a multipart message contains multiple child mime:MULTIPART elements<br />
 :   --&gt;<br /><br />
 :
 :   &lt;!-- definition of simple elements --&gt;<br />
 :   &lt;simpleType name="emailAddressType"&gt;<br />
 :     &lt;restriction base="string"&gt;<br />
 :       &lt;pattern value="[^@]+@[^\.]+\..+"/&gt;<br />
 :     &lt;/restriction&gt;<br />
 :   &lt;/simpleType&gt;<br /><br />
 :
 :  &lt;!-- definition of complex elements --&gt;<br />
 :  &lt;complexType name="emailAddress" xmlns:mime="http://www.zorba-xquery.org/mime"&gt;<br />
 :    &lt;sequence&gt;<br />
 :      &lt;element name="name" type="string" maxOccurs="1" minOccurs="0"/&gt;<br />
 :      &lt;element name="email" type="tns:emailAddressType" maxOccurs="1" minOccurs="1"/&gt;<br />
 :    &lt;/sequence&gt;<br />
 :  &lt;/complexType&gt;<br /><br />
 :
 :  &lt;complexType name="recipientType" xmlns:mime="http://www.zorba-xquery.org/mime"&gt;<br />
 :    &lt;sequence&gt;<br />
 :      &lt;choice&gt;<br />
 :        &lt;element name="to" type="tns:emailAddress"/&gt;<br />
 :        &lt;element name="cc" type="tns:emailAddress"/&gt;<br />
 :        &lt;element name="bcc" type="tns:emailAddress"/&gt;<br />
 :      &lt;/choice&gt;<br />
 :    &lt;/sequence&gt;<br />
 :  &lt;/complexType&gt;<br /><br />
 :
 :  &lt;complexType name="envelopeType" xmlns:mime="http://www.zorba-xquery.org/mime"&gt;<br />
 :    &lt;sequence&gt;<br />
 :      &lt;element name="remail" type="string" maxOccurs="1" minOccurs="0"/&gt;<br />
 :      &lt;element name="date" type="dateTime" maxOccurs="1" minOccurs="0"/&gt;<br />
 :      &lt;element name="from" type="tns:emailAddress" maxOccurs="1" minOccurs="1"/&gt;<br />
 :      &lt;element name="sender" type="tns:emailAddress" maxOccurs="1" minOccurs="0"/&gt;<br />
 :      &lt;element name="replyTo" type="tns:emailAddress" maxOccurs="1" minOccurs="0"/&gt;<br />
 :      &lt;element name="subject" type="string" maxOccurs="1" minOccurs="0"/&gt;<br />
 :      &lt;element name="recipient" type="tns:recipientType" maxOccurs="unbounded" minOccurs="1"/&gt;<br />
 :      &lt;element name="messageId" type="string" maxOccurs="1" minOccurs="0"/&gt;<br />
 :    &lt;/sequence&gt;<br />
 :  &lt;/complexType&gt;<br /><br />
 :
 :  &lt;complexType name="messageType"&gt;<br />
 :    &lt;sequence&gt;<br />
 :      &lt;element name="envelope" type="tns:envelopeType" maxOccurs="1" minOccurs="1"/&gt;<br />
 :      &lt;element name="mimeVersion" type="string" maxOccurs="1" minOccurs="1" default="1.0"/&gt;<br />
 :      &lt;element name="nonMime" type="string" maxOccurs="1" minOccurs="0"/&gt;<br />
 :      &lt;element name="contentType" type="mime:contentType" maxOccurs="1" minOccurs="1"/&gt;<br />
 :      &lt;element name="body" type="mime:bodyTypeChoice" maxOccurs="unbounded" minOccurs="1"/&gt;<br />
 :    &lt;/sequence&gt;<br />
 :    &lt;attribute name="about" type="string" use="required"/&gt;<br />
 :  &lt;/complexType&gt;<br /><br />
 :
 :  &lt;element name="Message" type="tns:messageType"/&gt;<br />
 :&lt;/schema&gt;<br /></pre><br />
 :
 : <a name="mime_schema.xsd">Appendix C: mime_schema.xsd</a>: <br />
 : <pre class="fragment">&lt;?xml version="1.0" encoding="UTF-8"?&gt;<br />
 : &lt;schema xmlns="http://www.w3.org/2001/XMLSchema" targetNamespace="http://www.zorba-xquery.org/mime"<br />
 :         xmlns:mime="http://www.zorba-xquery.org/mime" elementFormDefault="qualified"&gt;<br /><br />
 : 
 :     &lt;!-- definition of simple elements --&gt;<br />
 :     &lt;simpleType name="contentTypeValue"&gt;<br />
 :       &lt;restriction base="string"&gt;<br />
 :         &lt;pattern value="[a-zA-Z]+/[a-zA-Z]+((\-|\+|\.)[a-zA-Z]+)*"/&gt;<br />
 :       &lt;/restriction&gt;<br />
 :     &lt;/simpleType&gt;<br /><br />
 :   
 :     &lt;simpleType name="cteType"&gt;<br />
 :       &lt;restriction base="string"&gt;<br />
 :         &lt;pattern value="ENC7BIT|ENC8BIT|ENCBINARY|ENCBASE64|ENCQUOTEDPRINTABLE|ENCOTHER"/&gt;<br />
 :       &lt;/restriction&gt;<br />
 :     &lt;/simpleType&gt;<br /><br />
 :   
 :     &lt;!-- definition of complex elements --&gt;<br />
 :     &lt;complexType name="contentType"&gt;<br />
 :       &lt;sequence&gt;<br />
 :         &lt;element name="value" type="mime:contentTypeValue" maxOccurs="1" minOccurs="1" default="text/plain"/&gt;<br />
 :         &lt;element name="charset" type="string" maxOccurs="1" minOccurs="1" default="us-ascii"/&gt;<br />
 :         &lt;element name="contentTransferEncoding" type="mime:cteType" maxOccurs="1" minOccurs="1" default="ENC7BIT"/&gt;<br />
 :       &lt;/sequence&gt;<br />
 :     &lt;/complexType&gt;<br /><br />
 : 
 :     &lt;complexType name="bodyType"&gt;<br />
 :       &lt;sequence&gt;<br />
 :         &lt;element name="body" type="string" maxOccurs="1" minOccurs="1"/&gt;<br />
 :       &lt;/sequence&gt;<br />
 :       &lt;attribute name="serialization" type="string" /&gt;<br />
 :     &lt;/complexType&gt;<br /><br />
 : 
 :     &lt;complexType name="messageType"&gt;<br />
 :       &lt;sequence><br />
 :         &lt;element name="contentType" type="mime:contentType" maxOccurs="1" minOccurs="1"/&gt;<br />
 :         &lt;element name="body" type="mime:bodyType" maxOccurs="1" minOccurs="1"/&gt;<br />
 :       &lt;/sequence&gt;<br />
 :     &lt;/complexType&gt;<br /><br />
 : 
 :     &lt;complexType name="bodyTypeChoice"&gt;<br />
 :       &lt;sequence&gt;<br />
 :         &lt;choice>&gt;<br />
 :           &lt;element name="body" type="mime:bodyType" maxOccurs="1" minOccurs="1"/&gt;<br />
 :           &lt;element name="multipart" type="mime:messageType" minOccurs="1" maxOccurs="unbounded"/&gt;<br />
 :         &lt;/choice&gt;<br />
 :       &lt;/sequence&gt;<br />
 :     &lt;/complexType&gt;<br /><br />
 : 
 : &lt;/schema&gt; <br /></pre><br />
 :
 : @author Sorin Nasoi
 :
 :)
module namespace smtp = "http://www.zorba-xquery.com/modules/email/smtp";

(:~
 : Send mail
 :
 : @param $to Receiver(s) of the email. The formatting of this string must comply with RFC 2822.
 : @param $cc Receiver(s) of the email. The formatting of this string must comply with RFC 2822.
 : @param $bcc Receiver(s) of the email. The formatting of this string must comply with RFC 2822.
 : @param $subject Subject of the email to be sent. The formatting of this string must comply with RFC 2047.
 : @param $body The message to be sent. Each line should be separated with a LF (\n). Lines should not be larger than 70 characters.
 : @return true if the email was set successfully, false otherwise.
 : @error XQP0021 If the SMTP server was not set in the static context an error is raised API0038_SMTP_SEVER_ERROR_SET_OPTION.
 : @error XQP0021 If the $to, $cc, $bcc parameters are all empty an error is raised API0039_RECIPIENT_SET_OPTION.
 : @error XQP0021 If the email could not be sent for some reason an error is raised API0040_MAIL_NOT_SENT.
 :)
declare sequential function smtp:send(
  $to       as xs:string?,
  $cc       as xs:string?,
  $bcc      as xs:string?,
  $subject  as xs:string?,
  $body     as xs:string
) as xs:boolean
{
  let $message :=
    <mail>
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
 : Send mail
 :
 : @param $to Receiver(s) of the email. The formatting of this string must comply with RFC 2822.
 : @param $subject Subject of the email to be sent. The formatting of this string must comply with RFC 2047.
 : @param $message Message to be sent.Each line should be separated with a LF (\n). Lines should not be larger than 70 characters.
 : @return true if the email was set successfully, false otherwise.
 : @error XQP0021 If the SMTP server was not set in the static context an error is raised API0038_SMTP_SEVER_ERROR_SET_OPTION.
 : @error XQP0021 If the $to, $cc, $bcc parameters are all empty an error is raised API0039_RECIPIENT_SET_OPTION.
 : @error XQP0021 If the email could not be sent for some reason an error is raised API0040_MAIL_NOT_SENT.
 :)
declare sequential function smtp:send(
  $to       as xs:string,
  $subject  as xs:string,
  $body     as xs:string
) as xs:boolean
{
  smtp:send($to, '', '', $subject, $body)
};

(:~
 : Send mail
 :
 : @param $arg Contains the envelope info (from, to, cc, bcc, subject) and the multipart message.
 : @return true if the email was set successfully, false otherwise.
 : @error XQP0021 If the SMTP server was not set in the static context an error is raised API0038_SMTP_SEVER_ERROR_SET_OPTION.
 : @error XQP0021 If the $to, $cc, $bcc parameters are all empty an error is raised API0039_RECIPIENT_SET_OPTION.
 : @error XQP0021 If the email could not be sent for some reason an error is raised API0040_MAIL_NOT_SENT.
 :)
declare sequential function smtp:send(
  $arg as node()
) as xs:boolean external;
