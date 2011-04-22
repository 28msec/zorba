import module namespace mailchimp = "http://www.zorba-xquery.com/modules/webservices/mailchimp";


block 
{
  declare $apikey := mailchimp:login("zorbatest", "1qaz2wsx");

  mailchimp:list-subscribe($apikey,
                           "bec9bff03b", 
                           "wcandillon@gmail.com", 
                           <array />, 
                           "html", true(), false(), true(), true());
}
