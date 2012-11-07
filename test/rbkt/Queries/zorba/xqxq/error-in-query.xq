import module namespace xqxq = 'http://www.zorba-xquery.com/modules/xqxq';

declare namespace op = 'http://www.zorba-xquery.com/options/features';
declare namespace f = 'http://www.zorba-xquery.com/features';
declare option op:enable 'f:hof';

declare function local:url-resolver($namespace as xs:string, $entity as xs:string) {
switch($entity)
case 'schema'
  return switch($namespace)
         case 'http://www.w3.org/XQueryTest' return doc('/tmp/atomic.xsd')
         default return ()
default return ()
};

variable $queryID := xqxq:prepare-main-module(
  "declare namespace foo='http://test';
   declare namespace foo='http://test';
   1",
   local:url-resolver#2, ());
xqxq:evaluate($queryID)
