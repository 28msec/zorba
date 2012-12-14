
import module namespace seq = "http://www.foo.com/default" at "delete_from_collection_01.xqlib";

seq:init();

variable $foo := seq:index();

seq:reset();

variable $bar := seq:index();


$foo, $bar
