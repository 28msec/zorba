
declare updating function local:foo()
{
   variable $x := <a/>;

   insert node <b/> into $x
};


local:foo();

()


