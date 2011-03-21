import module namespace mailchimp = "http://www.zorba-xquery.com/modules/webservices/mailchimp";

let $endpoint-url := "http://us2.api.mailchimp.com/1.3/"
return
  mailchimp:login("zorbatest", "1qaz2wsx")
