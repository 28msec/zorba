import module namespace xqxq = 'http://www.zorba-xquery.com/modules/xqxq';

variable $query-key := xqxq:prepare-main-module("insert node <child>Content</child> into /parent");
variable $xml := doc("context-item.xml");
xqxq:bind-context-item($query-key, $xml); 
xqxq:is-bound-context-item($query-key)
