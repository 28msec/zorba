import module namespace util = "http://www.zorba-xquery.com/diagnostic/util" at "diagnostic_util.xq";

declare function local:declare-diagnostics( $doc ) as xs:string*
{
  for $namespace in $doc/diagnostic-list/namespace
  let $class :=
    switch ( data( $namespace/@prefix ) )
    case "err" return "XQueryErrorCode"
    case "zerr" return "ZorbaErrorCode"
    case "zwarn" return "ZorbaWarningCode"
    default return error()
  return
    if ($class eq "ZorbaWarningCode")
    then ()
    else
      string-join(
        (
          concat( $util:newline, "namespace ", $namespace/@prefix, " {" ),
          for $diagnostic in $namespace/diagnostic
          return 
            concat (
               util:begin_guard( $diagnostic ),
               $class, " ", $diagnostic/@code,
               if ( $diagnostic/@name )
               then concat( "_", $diagnostic/@name )
               else "",
               '( "', $diagnostic/@code, '" );',
               $util:newline,
               util:end_guard( $diagnostic )
            ),
          concat( "} // namespace ", $namespace/@prefix )
        ),
        concat( $util:newline, $util:newline )
      )
};


declare variable $input external;

string-join(
  ( util:copyright(), 
    '',
    '#include "stdafx.h"',
    '#include &lt;zorba/error_list.h>',
    '',
    'namespace zorba {',
    '',
    local:declare-diagnostics( $input ),
    '',
    '} // namespace zorba',
    '/*',
    ' * Local variables:',
    ' * mode: c++',
    ' * End:',
    ' */'
  ),
  $util:newline
),
$util:newline

(: vim:set syntax=xquery et sw=2 ts=2: :)


