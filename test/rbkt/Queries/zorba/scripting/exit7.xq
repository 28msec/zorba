

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare %ann:sequential function local:cook() as element(soup)
{
  exit returning "garbage";
};


local:cook()
