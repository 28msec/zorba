import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";

import schema namespace news = "http://www.news.org/schemas" at "news-schema.xsd";

import module namespace news-data = "http://www.news.org/data" at "news-data.xqlib";


declare sequential function local:init() 
{
  xqddf:create-collection($news-data:employees);
  
  xqddf:create-collection($news-data:articles);
  
  xqddf:create-collection($news-data:months, (
    validate {<news:month name="Jan"></news:month>}, 
    validate {<news:month name="Dec"></news:month>}) );

  xqddf:create-index($news-data:CityEmp);

  xqddf:create-index($news-data:ArtCountEmp);

  xqddf:activate-integrity-constraint($news-data:UniqueId);

  xqddf:activate-integrity-constraint($news-data:AuthorName);

  xqddf:activate-integrity-constraint($news-data:ArticleEmployees);

  xqddf:insert-nodes($news-data:employees, 
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

  xqddf:insert-nodes($news-data:articles, 
    (
    <articles>
      <empid>100</empid>
      <date>12/31/1999</date>
      <author><name>Jim Gray</name></author>
    </articles>
    )
  );

  xqddf:refresh-index($news-data:ArtCountEmp);
};


declare sequential function local:do() 
{
  block 
  {
    for $emp in xqddf:collection($news-data:employees)[.//news:position/@kind eq "journalist"]
    let $articles := for $art in xqddf:collection($news-data:articles)[.//author//name eq $emp/news:name]
                     order by $art//date
                     return $art
    return <result>{$emp}<articles>{$articles//title}</articles></result>
  },
  block 
  {
    xqddf:probe-index-point($news-data:CityEmp, "Paris")
  },
  block 
  {
    xqddf:probe-index-range($news-data:ArtCountEmp, 100, (), true(), false(), true(), false())
  }
};


declare sequential function local:done() 
{
  block 
  {
    xqddf:delete-nodes($news-data:articles, 
      xqddf:collection($news-data:articles)[.//date lt "01/01/2000"]
    );
  }
};


local:init(),
local:do(),
local:done()
