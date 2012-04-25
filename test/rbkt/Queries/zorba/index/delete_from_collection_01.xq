
import module namespace seq = "http://www.foo.com/default" at "delete_form_collection.xqlib";

seq:init();

variable $foo := seq:index();

seq:reset();

variable $bar := seq:index();


$foo, $bar


(:

node = 0x82cd608

pul = 0x82ce838
collection pul = 0x82f0fd0


delta[0] = [0x82cd608, 0x82d5088]

:)
