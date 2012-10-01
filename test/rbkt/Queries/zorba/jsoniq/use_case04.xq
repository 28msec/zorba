import module namespace j = "http://jsoniq.org/functions";

let $satsDoc :=
  {
    "creator" : "Satellites plugin version 0.6.4",
    "satellites" : {
      "AAU CUBESAT" : {
        "tle1" : "1 27846U 03031G 10322.04074654  .00000056  00000-0  45693-4 0  8768",
        "visible" : fn:false()
      },
      "AJISAI (EGS)" : {
        "tle1" : "1 16908U 86061A 10321.84797408 -.00000083  00000-0  10000-3 0  3696",
        "visible" : fn:true()
      },
      "AKARI (ASTRO-F)" : {
        "tle1" : "1 28939U 06005A 10321.96319841  .00000176  00000-0  48808-4 0  4294",
        "visible" : fn:true()
      }
    }
  }
return 
{
  "visible" : [
     let $sats := $satsDoc("satellites")
     for $satName in j:keys($sats)
     let $satData := $sats($satName)
     where $satData("visible")
     return $satName
  ]
  ,
  "invisible" : [
     let $sats := $satsDoc("satellites")
     for $satName in j:keys($sats)
     let $satData := $sats($satName)
     where fn:not($satData("visible"))
     return $satName
  ]
}
