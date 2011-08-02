declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare function local:magic-trick() 
{
  exit returning ("magician's hat:", "rabbit");
  exit returning ("dead code"); 
};

declare %ann:sequential function local:professional-magician() 
{
  let $res := local:magic-trick()
  return
      exit returning $res;
};

local:professional-magician()

