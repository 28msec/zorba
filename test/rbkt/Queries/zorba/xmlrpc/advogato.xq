import module namespace xmlrpc = "http://www.zorba-xquery.com/modules/xmlrpc";

block
{
  declare $sumprod := xmlrpc:invoke("http://www.advogato.org/XMLRPC", 
                                    "test.sumprod",
                                    (5, 7));

  declare $capitalize := xmlrpc:invoke("http://www.advogato.org/XMLRPC", 
                                       "test.capitalize",
                                       "HelloWorld");

  declare $strlen := xmlrpc:invoke("http://www.advogato.org/XMLRPC", 
                                   "test.strlen",
                                   "HelloWorld");

  declare $guess := xmlrpc:invoke("http://www.advogato.org/XMLRPC", "test.guess");

  <results>
    <result id="sumprod">
  {$sumprod}
    </result>
    <result id="capitalize">
  {$capitalize}
    </result>
    <result id="strlen">
  {$strlen}
    </result>
    <result id="guess">
  {$guess}
    </result>
  </results>;
}

