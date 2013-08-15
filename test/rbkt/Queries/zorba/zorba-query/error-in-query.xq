import module namespace zq = 'http://zorba.io/modules/zorba-query';

declare namespace op = 'http://zorba.io/options/features';
declare namespace f = 'http://zorba.io/features';

declare function local:url-resolver($namespace as xs:string, $entity as xs:string) {
switch($entity)
case 'schema'
  return switch($namespace)
         case 'http://www.w3.org/XQueryTest' return doc('/tmp/atomic.xsd')
         default return ()
default return ()
};

variable $queryID := zq:prepare-main-module(
  "declare namespace foo='http://test';
   declare namespace foo='http://test';
   1",
   local:url-resolver#2, ());
zq:evaluate($queryID)
