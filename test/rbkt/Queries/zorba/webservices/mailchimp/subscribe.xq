import module namespace mailchimp = "http://www.zorba-xquery.com/modules/webservices/mailchimp";


let $apikey := mailchimp:login("zorbatest", "1qaz2wsx")
return block {
  mailchimp:list-subscribe($apikey, "bec9bff03b", "wcandillon@gmail.com", <array />, "html", true(), false(), true(), true());
}
