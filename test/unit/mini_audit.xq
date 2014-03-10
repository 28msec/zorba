import module namespace refl = "http://zorba.io/modules/reflection";

declare namespace ann = "http://zorba.io/annotations";

declare %ann:sequential function local:create() 
{
  let $seq := for $i in 1 to 50 return <a>{$i}</a>
  return 
    insert nodes $seq into <b/>;
};


refl:eval-s("local:create()")
