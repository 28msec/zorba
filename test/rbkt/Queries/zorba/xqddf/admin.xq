import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";
import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";
import module namespace index_ddl = "http://www.zorba-xquery.com/modules/store/static/indexes/ddl";
import module namespace index_dml = "http://www.zorba-xquery.com/modules/store/static/indexes/dml";
import module namespace ic_ddl = "http://www.zorba-xquery.com/modules/store/static/integrity_constraints/ddl";

import schema namespace news = "http://www.news.org/schemas" at "news-schema.xsd";

import module namespace news-data = "http://www.news.org/data" at "news-data.xqlib";

declare namespace ann = "http://www.zorba-xquery.com/annotations";


declare %ann:sequential function local:init() 
{
  ddl:create($news-data:employees);
  
  ddl:create($news-data:articles);
  
  ddl:create($news-data:months, (
    validate {<news:month name="Jan"></news:month>}, 
    validate {<news:month name="Dec"></news:month>}) );

  index_ddl:create($news-data:CityEmp);

  index_ddl:create($news-data:ArtCountEmp);

  ic_ddl:activate($news-data:UniqueId);

  ic_ddl:activate($news-data:AuthorName);

  ic_ddl:activate($news-data:ArticleEmployees);

  dml:insert-nodes($news-data:employees, 
    (
    validate {
    <news:employee id="100">
      <news:position kind="journalist"/>
      <news:name>Jim Gray</news:name>
      <news:station><news:city>Paris</news:city></news:station> 
    </news:employee> },

    validate {
    <news:employee id="200">
      <news:station><news:city>London</news:city></news:station>
    </news:employee> } 
    )
  );

  dml:insert-nodes($news-data:articles, 
    <articles>
      <empid>100</empid>
      <date>12/31/1999</date>
      <author><name>Jim Gray</name></author>
    </articles>
  );

  index_dml:refresh-index($news-data:ArtCountEmp);
};


declare %ann:sequential function local:do() 
{
    for $emp in dml:collection($news-data:employees)[.//news:position/@kind eq "journalist"]
    let $articles := for $art in dml:collection($news-data:articles)[.//author//name eq $emp/news:name]
                     order by $art//date
                     return $art
    return <result>{$emp}<articles>{$articles//title}</articles></result>,
    index_dml:probe-index-point-value($news-data:CityEmp, "Paris"),
    index_dml:probe-index-range-value($news-data:ArtCountEmp,
                                  100, (), true(), false(), true(), false())
};


declare %ann:sequential function local:done() 
{
    dml:delete-nodes(
      dml:collection($news-data:articles)[.//date lt "01/01/2000"]
    );
};


local:init(),
local:do(),
local:done()
