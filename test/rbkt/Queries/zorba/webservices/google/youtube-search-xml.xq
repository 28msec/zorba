import module namespace google = 'http://www.zorba-xquery.com/modules/webservices/google/youtube';

let $developer-key := "AI39si4u9knclYuksr4Feac4SlxivnvnFTvlGrpXRlRs5d751FMuxnhzEhjNiIfF28Y-1nSNmJAqckg_qdH4ZG1S9iuLB4DYeQ"
let $search-term := "dramatic chipmunk"
let $response := google:youtube-search-xml($developer-key, $search-term)

return
  if(xs:string($response/@status/data(.)) eq "200")
  then <test name="test-youtube-search-xml" succeed="true" message="Youtube search request is valid." />
  else <test name="test-youtube-search-xml" succeed="false" message="Youtube search request is invalid." />