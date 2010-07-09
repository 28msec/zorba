  import module namespace smtp = 'http://www.zorba-xquery.com/modules/email/smtp';

  declare option smtp:SMTPServer "smtp.gmail.com:587/tls/novalidate-cert";
  declare option smtp:SMTPUser "username";
  declare option smtp:SMTPPwd "password";

  smtp:send("user@server.com","this is a Zorba test message","it works...")
