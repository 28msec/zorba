import module namespace modns1 = "http://modns1" at "modules_diamond_nodes1.xqlib";
import module namespace modns2 = "http://modns2" at "modules_diamond_nodes2.xqlib";
declare namespace myns = "http://myns";

($modns1:x + modns2:g ()), $modns1:n is $modns2:n
