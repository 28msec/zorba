(:~
  : Module Name: email
  : Module Version: 0.1
  : Date: October 29, 2009
  : Copyright:  2006-2009 The FLWOR Foundation. Licensed under the Apache License, Version 2.0.
  : Proprietary XQuery Extensions Used: None
  : XQuery Specification: January 2007
  : Module Overview: This library module provides the functions used to send emails.
  : @author Sorin Nasoi
  :)

module namespace email = "http://www.zorba-xquery.com/modules/email/smtp";

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
declare function email:mail($to       as xs:string,
                            $cc       as xs:string,
                            $bcc      as xs:string,
                            $subject  as xs:string,
                            $message  as xs:string)  as xs:boolean external;

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
declare function email:multipart($arg as node()) as xs:boolean external;