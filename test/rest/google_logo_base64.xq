(: Retreive the Google logo from thier homepage, and return it in base64-encoded form :)

import module namespace zorba-rest = "http://www.zorba-xquery.com/zorba/rest-functions";

zorba-rest:get("http://www.google.com/intl/en_ALL/images/logo.gif")
