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
 : Module Overview: This library module provides the functions used to send emails.
 :
 : @author Sorin Nasoi
 : @version 0.1
 :)
module namespace smtp = "http://www.zorba-xquery.com/modules/email/smtp";

 (:~
  : function for sending email.
  :
  : @param $to Receiver(s) of the email. The formatting of this string must comply with RFC 2822.
  : @param $cc Receiver(s) of the email. The formatting of this string must comply with RFC 2822.
  : @param $bcc Receiver(s) of the email. The formatting of this string must comply with RFC 2822.
  : @param $subject Subject of the email to be sent. The formatting of this string must comply with RFC 2047.
  : @param $message Message to be sent.Each line should be separated with a LF (\n). Lines should not be larger than 70 characters.
  : @return Returns true if the email was set successfully, false otherwise.
  :
  : @error   XQP0021 If the SMTP server was not set in the static context an error is raised API0038_SMTP_SEVER_ERROR_SET_OPTION.
  : @error   XQP0021 If the $to, $cc, $bcc parameters are all empty an error is raised API0039_RECIPIENT_SET_OPTION.
  : @error   XQP0021 If the email could not be sent for some reason an error is raised API0040_MAIL_NOT_SENT.
  :)
declare function smtp:send( $to       as xs:string,
                            $cc       as xs:string,
                            $bcc      as xs:string,
                            $subject  as xs:string,
                            $message  as xs:string)  as xs:boolean
{
(:
      if( !hasRecipient )
{
        //TODO implement excenption handling via external_function_data
        std::stringstream lErrorMessage;
        lErrorMessage << "Recipient was not set; please set either one of To, Cc or Bcc.";
        throwError(lErrorMessage.str(), XQP0019_INTERNAL_ERROR);
}
  :)
  fn:true()
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
declare function smtp:send( $to       as xs:string,
                            $subject  as xs:string,
                            $message  as xs:string)  as xs:boolean
{
  smtp:send($to,'','',$subject,$message)
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
declare function smtp:send($arg as node()) as xs:boolean external;
