import module namespace xqxq = 'http://www.zorba-xquery.com/modules/xqxq';
variable $queryID := xqxq:prepare-main-module('declare variable $ext external; $ext');
xqxq:bind-cast-variable( $queryID, xs:QName("ext2"), '2');
xqxq:evaluate($queryID)       