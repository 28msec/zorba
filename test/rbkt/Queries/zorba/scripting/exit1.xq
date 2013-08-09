declare namespace ann = "http://zorba.io/annotations";

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

