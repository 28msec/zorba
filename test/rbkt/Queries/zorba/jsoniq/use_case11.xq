import module namespace j = "http://www.jsoniq.org/functions";

let $feed :=
{
  "encoding" : "UTF-8",

  "feed" : 
  {
    "author" : 
    [
      {
        "name" : { "$t" : "YouTube" },
        "uri" : { "$t" : "http://www.youtube.com/" }
      }
    ],

    "category" : 
    [
      {
        "scheme" : "http://schemas.google.com/g/2005#kind",
        "term" : "http://gdata.youtube.com/schemas/2007#video"
      }
    ],

    "entry" : 
    [
      {
        "app$control" : 
        {
          "yt$state" : 
          {
            "$t" : "Syndication of this video was restricted by its owner.",
            "name" : "restricted",
            "reasonCode" : "limitedSyndication"
          }
        },

        "author" : 
        [
                    {
                        "name" : {
                            "$t" : "beyonceVEVO"
                        },
                        "uri" : {
                            "$t" : "http://gdata.youtube.com/feeds/api/users/beyoncevevo"
                        }
                    }
        ]
      }
    ]
  }
}
return
   copy $out := $feed
   modify
      let $f := $out("feed")
      for $entry at $pos in j:members($f("entry"))
      where $entry("app$control")("yt$state")("name") = "restricted"
      return delete json ($f("entry"))($pos)
   return $out
