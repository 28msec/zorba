import module namespace google = 'http://www.zorba-xquery.com/modules/webservices/google/books';

let $book := "C++ Programming"
let $start := 1
let $max := 10
let $response := google:ISBN($book,$start,$max)
return
  if(empty($response))
  then <test name="test-ISBN" succeed="false" message="ISBN is incorrect." />
  else <test name="test-ISBN" succeed="true" message="ISBN is correct." />