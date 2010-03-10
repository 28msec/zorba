  import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";

  import schema namespace news-schemas = "http://www.news.org/schemas" at "news-schema.xsd";

  import module namespace news-data = "http://www.news.org/data" at "index_does_not_exist.xqlib";

  xqddf:create-collection($news-data:employees);

  xqddf:create-index($news-data:CityEmp);

  xqddf:probe-index-range($news-data:CityEmp, 100, (), true(), false(), true(), false());