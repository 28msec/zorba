import module namespace xqxq = 'http://www.zorba-xquery.com/modules/xqxq';
variable $queryID := xqxq:prepare-main-module('declare variable $ext as xs:integer* external; for $i in $ext return $i+1');
xqxq:bind-cast-variable( $queryID, xs:QName("ext"), ('1', '2'));
xqxq:evaluate($queryID)       