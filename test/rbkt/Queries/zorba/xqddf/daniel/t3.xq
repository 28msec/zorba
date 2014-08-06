import module namespace xqddf-test = "http://www.zorba-xquery.com/modules/xqddf/test" at "xqddf_prolog.xqlib";
import module namespace ddl = "http://zorba.io/modules/store/static/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/static/collections/dml";


ddl:create($xqddf-test:ordered-collection, (<wb>1</wb>,<wb>2</wb>,<wb>3</wb>,<wb>4</wb>,<wb>5</wb>,<wb>6</wb>,<wb>7</wb>,<wb>8</wb>,<wb>9</wb>,<wb>10</wb>));


let $n := <a><b>bnm</b><c></c></a>
return dml:insert-before($xqddf-test:ordered-collection, 
                         dml:collection($xqddf-test:ordered-collection)[fn:string() eq "2"],
                         $n);
dml:collection($xqddf-test:ordered-collection)
