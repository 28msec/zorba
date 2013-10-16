
import module namespace util = "http://zorba.io/modules/reflection";

<population>
{
for $i in fn:doc("gary_meta.xml")/data/file[@type = "xml"]
let $year := $i/@year,
    $xmlFile := concat($i/@path, $i/@name)
return <survey year="{$year}">
       {
       for $j in fn:doc($xmlFile)/data/record[1]
       let $unitid := $j/@unitid,
           $control := xs:integer($j/@control),
           $rControl := for $cond in doc("gary_control.xml")//condition[@year eq $year]
                        return util:eval($cond/@expression)
       return <inst unitid="{$unitid}" control="{$control}" rControl="{$rControl}" />
       }
       </survey>
}
</population>
