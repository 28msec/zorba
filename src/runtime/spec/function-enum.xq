declare namespace zorba="http://www.zorba-xquery.com";

import module namespace util="http://www.zorba-xquery.com/zorba/util-functions";

import module namespace gen = "http://www.zorba-xquery.com/internal/gen" at "utils.xq";

declare variable $file-list as xs:string external;

let $files as xs:string* := tokenize($file-list,';')
let $funcs := distinct-values(
                for $sig in for $doc in $files
                            return doc($doc)//zorba:signature
                return gen:function-kind($sig)
              )
return
  string-join ((
    gen:add-copyright(),
    gen:add-guard-open('ZORBA_FUNCTIONS_FUNCTION_CONSTS'),
    'namespace zorba{',
    $gen:indent, 'class FunctionConsts',
    '{',
    $gen:indent, 'public:',
    'typedef enum {',
     '  FN_UNKNOWN,',
     '#include "functions/function_consts.h"',
     for $func at $i in $funcs
     return concat (
      $gen:indent,
      $func,
      if ($i < fn:count($funcs)) then ',' else ''
     ),
    '} FunctionKind;',
    $gen:newline,
    'typedef enum ',
    '{ ',
    '  NO = 0,',
    '  YES,',
    '  PRESERVE',
    '} AnnotationValue;',
    $gen:newline,
    'typedef enum',
    '{',
    '  DoDistinct    = 1,   // Used by fn:zore-or-one and fn:exaclty-one ',
    '  SkipCodeGen   = 2,',
    '  hasFnNamespace = 4',
    '} AnnotationFlags;',
    '};',
    '} //namespace zorba',
    gen:add-guard-close()),
    $gen:newline
  ),
  $gen:newline
