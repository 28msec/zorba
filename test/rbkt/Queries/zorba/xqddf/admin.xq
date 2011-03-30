import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";
import module namespace manip = "http://www.zorba-xquery.com/modules/store/static-collections/manipulation";

import schema namespace news = "http://www.news.org/schemas" at "news-schema.xsd";

import module namespace news-data = "http://www.news.org/data" at "news-data.xqlib";


declare sequential function local:init() 
{
  init:create-collection($news-data:employees);
  
  init:create-collection($news-data:articles);
  
  init:create-collection($news-data:months, (
    validate {<news:month name="Jan"></news:month>}, 
    validate {<news:month name="Dec"></news:month>}) );

  init:create-index($news-data:CityEmp);

  init:create-index($news-data:ArtCountEmp);

  init:activate-integrity-constraint($news-data:UniqueId);

  init:activate-integrity-constraint($news-data:AuthorName);

  init:activate-integrity-constraint($news-data:ArticleEmployees);

  manip:insert-nodes($news-data:employees, 
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

  manip:insert-nodes($news-data:articles, 
    (
    <articles>
      <empid>100</empid>
      <date>12/31/1999</date>
      <author><name>Jim Gray</name></author>
    </articles>
    )
  );

  manip:refresh-index($news-data:ArtCountEmp);
};


declare sequential function local:do() 
{
  block 
  {
    for $emp in manip:collection($news-data:employees)[.//news:position/@kind eq "journalist"]
    let $articles := for $art in manip:collection($news-data:articles)[.//author//name eq $emp/news:name]
                     order by $art//date
                     return $art
    return <result>{$emp}<articles>{$articles//title}</articles></result>
  },
  block 
  {
    manip:probe-index-point-value($news-data:CityEmp, "Paris")
  },
  block 
  {
    manip:probe-index-range-value($news-data:ArtCountEmp,
                                  100, (), true(), false(), true(), false())
  }
};


declare sequential function local:done() 
{
  block 
  {
    manip:delete-nodes($news-data:articles, 
      manip:collection($news-data:articles)[.//date lt "01/01/2000"]
    );
  }
};


local:init(),
local:do(),
local:done()
