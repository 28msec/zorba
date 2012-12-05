import module namespace error = "http://www.example.com/error" at "error_01.xqlib";

declare namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";


ddl:create($error:collection);
