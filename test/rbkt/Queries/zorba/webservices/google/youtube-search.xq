import module namespace google = 'http://www.zorba-xquery.com/modules/webservices/google/youtube';

let $developer-key := "AI39si4u9knclYuksr4Feac4SlxivnvnFTvlGrpXRlRs5d751FMuxnhzEhjNiIfF28Y-1nSNmJAqckg_qdH4ZG1S9iuLB4DYeQ"
let $search-term := "dramatic chipmunk"
let $response := google:youtube-search($developer-key,$search-term)
return
  if(empty($response))
  then <test name="test-youtube-search" succeed="false" message="Youtube search is incorrect." />
  else <test name="test-youtube-search" succeed="true" message="Youtube search is correct." />
