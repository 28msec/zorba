import module namespace xqddf-test = "http://www.zorba-xquery.com/modules/xqddf/test" at "xqddf_prolog.xqlib";
import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";


init:create-collection($xqddf-test:ordered-collection, (<wb>1</wb>,<wb>2</wb>,<wb>3</wb>,<wb>4</wb>,<wb>5</wb>,<wb>6</wb>,<wb>7</wb>,<wb>8</wb>,<wb>9</wb>,<wb>10</wb>));


let $n := <a><b>bnm</b><c></c></a>
return manip:insert-nodes-before($xqddf-test:ordered-collection, 
                                manip:collection($xqddf-test:ordered-collection)[fn:string() eq "2"],
                                $n);
manip:collection($xqddf-test:ordered-collection);
