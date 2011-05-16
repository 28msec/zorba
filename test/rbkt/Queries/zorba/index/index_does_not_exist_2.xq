import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace index_dml = "http://www.zorba-xquery.com/modules/store/static/indexes/dml";

import schema namespace news-schemas = "http://www.news.org/schemas" at "news-schema.xsd";

import module namespace news-data = "http://www.news.org/data" at "index_does_not_exist.xqlib";

ddl:create-collection($news-data:employees);

index_dml:probe-index-point-value($news-data:CityEmp, "Paris");
