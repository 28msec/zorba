import module namespace error = "http://www.example.com/error" at "error_03.xqlib";

declare namespace ddl = "http://zorba.io/modules/store/static/collections/ddl";


ddl:create($error:collection);
