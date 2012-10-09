import module namespace refl = "http://www.zorba-xquery.com/modules/reflection";

declare namespace an = "http://www.zorba-xquery.com/annotations";


declare variable $local:account  := ();


declare function local:get-by-id($id as xs:string)
{
  ()
};

 
declare %an:sequential function local:validate() as xs:boolean 
{
  variable $uid := "user";
  
  if (true())
  then 
    let $account := local:get-by-id($uid)
    return 
      if (true())
      then
        if (true())
        then 
        {
          $local:account := $account;
          true()
        } 
        else ()
      else ()
  else ()
};


declare function local:index() 
{
  ()
};


refl:eval("local:index()")
