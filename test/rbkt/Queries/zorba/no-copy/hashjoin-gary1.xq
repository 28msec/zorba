declare namespace opt = "http://zorba.io/options/optimizer";

declare option opt:enable "for-serialization-only";


<institutions>
{
let $y := doc("../hashjoins/min_ic1980.xml")/ipeds[@year = 1980][@file = "ic1980"]/data
for $i in doc("../hashjoins/base.xml")/institutions/inst
let $unitid := $i/@unitid
return
    <inst unitid="{$unitid}" >
    {
    for $j in $i/year
    let $year := $j/@name
    return
      <year name="{$year}" >
      {
      for $k in $j/file
      let $file := $k/@name,
          $data := if (($year = 1980) and ($file = "ic1980"))
                   then $y[@unitid = $unitid]/@*
                   else ()
      return
        <file name="{$file}" >
        {
          $data
        }
        </file>
      }
      </year>
    }
    </inst>
}
</institutions>


(:


:)

