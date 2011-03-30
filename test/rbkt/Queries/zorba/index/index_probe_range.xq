import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";

import schema namespace news-schemas = "http://www.news.org/schemas" at "news-schema.xsd";

import module namespace news-data = "http://www.news.org/data" at "index_does_not_exist.xqlib";

init:create-collection($news-data:employees);

init:create-index($news-data:CityEmp);

manip:probe-index-range-value($news-data:CityEmp,
                              100, (), true(), false(), true(), false());
