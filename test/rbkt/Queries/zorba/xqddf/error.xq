
import module namespace error = "http://www.example.com/error" at "error.xqlib";

declare namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";


init:create-collection($error:coll);
