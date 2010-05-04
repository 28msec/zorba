declare function local:foo()
{
  for $e in <emp><name>me</name><salary>100</salary></emp>
  return
     copy $je := $e
     modify delete node $je/salary
     return $je
};

local:foo()
