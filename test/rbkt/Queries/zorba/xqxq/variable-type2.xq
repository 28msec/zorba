import module namespace xqxq = 'http://www.zorba-xquery.com/modules/xqxq';

variable $queryID := xqxq:prepare-main-module('declare variable $ext as xs:integer external; $ext');

xqxq:variable-type($queryID, xs:QName('ext2'))