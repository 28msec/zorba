
import module namespace util = "http://www.zorba-xquery.com/modules/reflection";

declare namespace evaltest="www.zorba-xquery.com/Test/eval";

declare function evaltest:test1($x)
{
  $x + 3
};

util:eval
(
'
import module namespace evaltest="www.zorba-xquery.com/Test/eval" at "evallib.xqlib";

evaltest:test1(3),
" ",
evaltest:test2(12)
'
)
