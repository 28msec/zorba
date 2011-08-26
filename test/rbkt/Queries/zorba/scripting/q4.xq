
declare function local:handle()
{
  local:handle-method();

  if(true()) then
    ()
  else ()
};


declare %private function local:handle-method()
{
  true()
};


local:handle()
