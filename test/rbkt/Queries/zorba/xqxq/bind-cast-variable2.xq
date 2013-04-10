import module namespace xqxq = 'http://www.zorba-xquery.com/modules/xqxq';
variable $queryID := xqxq:prepare-main-module('declare variable $ext as object() external; $ext("value")+1');
xqxq:bind-cast-variable( $queryID, xs:QName("ext"), '{ "value" : 1}');
xqxq:evaluate($queryID)       