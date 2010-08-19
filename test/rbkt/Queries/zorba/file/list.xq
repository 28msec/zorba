import module namespace file = "http://www.zorba-xquery.com/modules/file";

file:files(file:dir-of-base-uri(<a/>), "list\.xq$", fn:false())
