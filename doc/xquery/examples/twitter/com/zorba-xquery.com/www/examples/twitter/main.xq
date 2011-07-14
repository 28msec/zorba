module namespace main = 'http://www.zorba-xquery.com/examples/twitter/main';

import module namespace cli = 'http://www.zorba-xquery.com/examples/commandline';
import module namespace cmd = 'http://www.zorba-xquery.com/examples/twitter/commands';
import module namespace sctx = 'http://www.zorba-xquery.com/modules/introspection/sctx';
import module namespace reflection = "http://www.zorba-xquery.com/modules/reflection";
import module namespace client = 'http://www.zorba-xquery.com/examples/twitter/client';

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare %ann:sequential %ann:nondeterministic function main:main()
{
  variable $command as xs:string*;
  variable $funname as xs:QName;
  variable $continue as xs:boolean := fn:true();
  client:authenticate();
  cmd:init-collection();
  while ($continue) {
    cli:print("twitter> ");
    $command := tokenize(cli:get-line(), '\s');
    $funname := fn:QName('http://www.zorba-xquery.com/examples/twitter/commands',
                         concat('cmd:', ($command, "nop")[1]));
    if (sctx:function-arguments-count($funname) = 1) then
      $continue := reflection:invoke-sequential($funname, $command);
    else
      cli:print-line(concat("command not found: ", $command[1]));
  }
  cmd:shutdown();
};

