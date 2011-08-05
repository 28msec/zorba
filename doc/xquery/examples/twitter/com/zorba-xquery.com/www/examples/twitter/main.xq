(:
 : Copyright 2006-2009 The FLWOR Foundation.
 :
 : Licensed under the Apache License, Version 2.0 (the "License");
 : you may not use this file except in compliance with the License.
 : You may obtain a copy of the License at
 :
 : http://www.apache.org/licenses/LICENSE-2.0
 :
 : Unless required by applicable law or agreed to in writing, software
 : distributed under the License is distributed on an "AS IS" BASIS,
 : WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 : See the License for the specific language governing permissions and
 : limitations under the License.
:)

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

