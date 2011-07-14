module namespace cmd = 'http://www.zorba-xquery.com/examples/twitter/commands';

import module namespace client = 'http://www.zorba-xquery.com/examples/twitter/client';
import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace cli = 'http://www.zorba-xquery.com/examples/commandline';
import module namespace file = 'http://expath.org/ns/file';
import module namespace http = "http://www.zorba-xquery.com/modules/http-client";
import module namespace json = "http://www.zorba-xquery.com/modules/converters/json";

declare namespace ann = "http://www.zorba-xquery.com/annotations";
declare namespace output = 'http://www.w3.org/2010/xslt-xquery-serialization';

declare collection cmd:saved-tweets as node()*;

declare variable $cmd:collectionfile as xs:string := "likes.xml";

declare function cmd:nop($args as xs:string*) as xs:boolean {
  true()
};

declare function cmd:quit($args as xs:string*) as xs:boolean {
  false()
};

declare %ann:sequential %ann:nondeterministic function cmd:tweets($args as xs:string*) as xs:boolean {
  client:tweets();
  exit returning true();
};

declare %ann:sequential %ann:nondeterministic function cmd:like($args as xs:string*) as xs:boolean {
  variable $status := client:get-tweet($args[2]);
  dml:insert-nodes(xs:QName("cmd:saved-tweets"), $status);
  exit returning true();
};

declare %ann:sequential %ann:nondeterministic function cmd:likes($args as xs:string*) as xs:boolean
{
  cli:print-line(string-join(
      for $status in dml:collection(xs:QName("cmd:saved-tweets"))
      return string-join((
                              concat("Id: ", $status/id/text()),
                              concat("From User: ", $status/user/name/text()),
                              "",
                              $status/text/text()
                            ), $cli:endl)
    , concat($cli:endl, "=====================================================================", $cli:endl))
  );
  exit returning true();
};

declare %ann:sequential %ann:nondeterministic function cmd:search($args as xs:string*) as xs:boolean
{
  cli:print-line(string-join(
    for $status in dml:collection(xs:QName("cmd:saved-tweets"))
    where $status contains text { subsequence($args, 2) } using stemming
    return string-join((
                              concat("Id: ", $status/id/text()),
                              concat("From User: ", $status/user/name/text()),
                              "",
                              $status/text/text()
                            ), $cli:endl)
    , concat($cli:endl, "=====================================================================", $cli:endl)));
  exit returning true();
};

declare %ann:sequential %ann:nondeterministic function cmd:init-collection()
{
  ddl:create-collection(xs:QName("cmd:saved-tweets"));
  if (file:is-file($cmd:collectionfile)) then
    dml:insert-nodes(xs:QName("cmd:saved-tweets"), doc($cmd:collectionfile)//status);
  else ();
};

declare %ann:sequential function cmd:shutdown()
{
  variable $doc := <tweets>{dml:collection(xs:QName("cmd:saved-tweets"))}</tweets>;
  file:write($cmd:collectionfile, $doc,
     <output:serialization-parameters>
       <output:method value="xml"/>
     </output:serialization-parameters>);
};

declare %ann:sequential %ann:nondeterministic function cmd:translate($args as xs:string*) as xs:boolean
{
  variable $language := $args[2];
  variable $tweet := client:get-tweet($args[3]);
  variable $json := http:get-text(concat('https://ajax.googleapis.com/ajax/services/language/translate?v=1.0&amp;q=',
                                         encode-for-uri($tweet/text/text()),
                                         '&amp;langpair=%7C', $language));
  variable $resp := json:parse($json[2]);
  cli:print-line($resp//pair[@name = "translatedText"]/text());
  exit returning true();
};

