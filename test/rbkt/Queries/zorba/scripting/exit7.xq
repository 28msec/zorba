

declare namespace ann = "http://zorba.io/annotations";

declare %ann:sequential function local:cook() as element(soup)
{
  exit returning "garbage";
};


local:cook()
