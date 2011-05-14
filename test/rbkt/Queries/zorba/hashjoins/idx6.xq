declare namespace l = "l";

declare variable $page as node()* := ();
declare variable $old_list as node()* := ();

declare function l:getLastPage($page as node()*) 
{
  let $pageNum := ($page//*:table)[last()]
  return if ($pageNum)
         then <test>-1</test>
         else <test>1</test>
};

variable $page := l:getLastPage($page);

for $rec in $page
  let $id := concat($rec/text(), "")
  let $old_rec := $old_list[id/text() eq $id]
return $rec
