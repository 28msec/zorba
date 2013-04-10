import module namespace xqxq = 'http://www.zorba-xquery.com/modules/xqxq';
variable $queryID := xqxq:prepare-main-module('declare variable $ext as element() external; $ext//b[@id = 131]/text()');
xqxq:bind-cast-variable( $queryID, xs:QName("ext"), '<a><b id="131">success</b><b id="2">foo</b></a>');
xqxq:evaluate($queryID)       