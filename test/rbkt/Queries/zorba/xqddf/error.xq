import module namespace error = "http://www.example.com/error" at "error.xqlib";

declare namespace ddl = "http://zorba.io/modules/store/static/collections/ddl";


ddl:create($error:coll);
