import module namespace google = 'http://www.zorba-xquery.com/modules/webservices/google/youtube';

let $search-term := "politics"
let $response := google:youtube-category-search($search-term)
return
  if(empty($response))
  then <test name="test-youtube-category-search" succeed="false" message="Youtube category is incorrect." />
  else <test name="test-youtube-category-search" succeed="true" message="Youtube category is correct." />