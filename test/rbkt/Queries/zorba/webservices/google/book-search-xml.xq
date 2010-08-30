import module namespace google = 'http://www.zorba-xquery.com/modules/webservices/google/books';

let $book := "C++ Programming"
let $start := 1
let $max := 10
let $response := google:book-search-xml($book,$start,$max)
return
  if(xs:string($response//*:totalResults) eq "0")
  then <test name="test-book-search-xml" succeed="false" message="Book search request is invalid." />
  else <test name="test-book-search-xml" succeed="true" message="Book search request is valid." />