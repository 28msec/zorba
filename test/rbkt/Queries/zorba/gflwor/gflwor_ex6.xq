
declare function local:format-date($date as xs:string) as xs:string
{ 
  try {
        let $date_ := xs:dateTime($date)
        let $day1 := day-from-dateTime($date_)
        let $day := if ($day1 lt 10) then concat('0', $day1) else $day1
        let $month1 := month-from-dateTime($date_)
        let $month := if ($month1 lt 10) then concat('0', $month1) else $month1
        let $year := year-from-dateTime($date_)
        let $hour1 := hours-from-dateTime($date_)
        let $hour := if ($hour1 lt 10) then concat('0', $hour1) else $hour1
        let $min1 := minutes-from-dateTime($date_)
        let $min := if ($min1 lt 10) then concat('0', $min1) else $min1
        return
            concat($year, '-', $month, '-', $day, ' ', $hour, ':', $min)
    } catch * {
        $date
    }
};

local:format-date("2004-05-12T18:17:15.125Z")
