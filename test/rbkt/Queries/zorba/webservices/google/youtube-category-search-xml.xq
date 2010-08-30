import module namespace google = 'http://www.zorba-xquery.com/modules/webservices/google/youtube';

let $search-term := "politics"
let $response := google:youtube-category-search-xml($search-term)
return
  if(xs:string($response/@status/data(.)) eq "200")
  then <test name="test-youtube-category-search-xml" succeed="true" message="Youtube category request is valid." />
  else <test name="test-youtube-category-search-xml" succeed="false" message="Youtube category request is invalid." />
