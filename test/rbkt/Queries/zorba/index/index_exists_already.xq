import module namespace ddl = "http://zorba.io/modules/store/static/collections/ddl";
import module namespace index_ddl = "http://zorba.io/modules/store/static/indexes/ddl";
import module namespace index_dml = "http://zorba.io/modules/store/static/indexes/dml";

import schema namespace news-schemas = "http://www.news.org/schemas" at "news-schema.xsd";

import module namespace news-data = "http://www.news.org/data" at "index_does_not_exist.xqlib";

ddl:create($news-data:employees);

index_ddl:create($news-data:CityEmp);

index_ddl:create($news-data:CityEmp);

index_dml:probe-index-point-value($news-data:CityEmp, "Paris");
