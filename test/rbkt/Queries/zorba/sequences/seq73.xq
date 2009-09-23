
declare function local:base64-decode($b as xs:base64Binary?) 
{
  let $str := string-to-codepoints($b cast as xs:string)
  let $c := ($str, subsequence((61, 61, 61), 1, count($str) mod 4)) 
  let $len := count($c)
  return
    let $table := (65 to 90, 
                   97 to 122,
                   48 to 57, 
                   43, 47) 
    for $ch at $p in $c
    where ($p mod 4 = 0) and (($p+3) le $len)
    return
      let $c0 := index-of($table, $ch)
      let $c1 := index-of($table, $c[$p + 1]) 
      let $byte0 := sum($c0 * 4, $c1 idiv 16) 
      return $byte0
};

let $x := <x>iVBORw0KGgoAAAANSUhEUgAAABAAAAANCAYAAACgu+4kAAAAAXNSR0IArs4c6QAAAAZiS0dEAP8A/wD/oL2nkwAAAAlwSFlzAAAN1wAADdcBQiibeAAAAAd0SU1FB9kFGxQWBljJo+cAAAI2SURBVCjPdZPPihRXHIW/6rkSmdEJsxAEgyvJUrIUfAUhK5dZ5RXyAHmPPEAWQkgeIEQQDa4ME/90yMSecbrbsqu7uqvurbp/f/e6aCGb5GzO6pxvcTjVd8/aGyFPHvSj73onegxZO++M997ovjUvn/468uh7CxT+Q9W9HxdfP3l48+cJoH1Eh0wfK7pQ2EXoA+hYig5l1wdptJdl79LybNU//u2bOz+o52+7SspN3rx+ya27d1GHhZMCx8AX7LkFqpI5KZmTmMqXPmXm3fWH375o76uyHSbeOd43DW6AKBVJQDLE/MkFQoIxFrSd0I6T8mGjrkxP01cKbw62u47q6BjtIGcIAjHtC4KAjzBEMLaiHWHZUE2nhfm0e6Uw7cG6WSPXbmAtkMHLnuoT2AhjAO1ga2FZw+yi0HQVul29VgxrtVp9jr51G6+hlH3QJbAeTIDeQWfhYlZY64ptqNhqwW3fnSv0+qCuj2mvfkaZQJJ/qSaAcbBqCs0m04WMSYIJibG1sD69VJi1ms+PWEwskHAJXCgMIbPrM7tdxvjMmBJjEmzKiI9Qf4DlT3NF16jzi0POQk2SCh8K1mWMyfhU8EnwkgmSkSgQAzgDq7eW4Y+1QrdqXp/wj1niXSGmQhIhJkEkITFAChA8RFvwOpNcxl/+DgyKoZ/Um0xd/40kv99PAiQPcdCk7oyw/ZO4OiVs/kLce0gb/LIBRBGHF7NF/YvYeobYc5K5JDQL7JslsAMsIP/3hY82jsqDmaWiHgAAAABJRU5ErkJggv8=</x>
let $y := xs:base64Binary($x)
return local:base64-decode($y)

