(: For various reasons, importing a bad schema via HTTP can take :)
(: minutes to complete. This test should time out unless the :)
(: http-uri-resolution feature is disabled. :)
import schema "http://www.w3.org/" at "bogus2.xsd";
1
