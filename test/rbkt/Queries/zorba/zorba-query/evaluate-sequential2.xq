import module namespace zq = 'http://zorba.io/modules/zorba-query';

variable $query-key := zq:prepare-main-module("insert node <child>Content</child> into /parent");
variable $xml := doc("context-item.xml");
zq:bind-context-item($query-key, $xml);  
zq:evaluate-sequential($query-key)