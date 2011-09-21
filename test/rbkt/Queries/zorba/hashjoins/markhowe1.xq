
declare function local:filterRecord(
  $docRecord as element(),
  $configRecord as element()) as element() 
{
  if (not($configRecord/*)) then
      $docRecord
  else
      element
        { local-name($docRecord) }
        {
          for $match in $configRecord/*
          return 
            (for $docMatch in $docRecord/*[local-name() = local-name($match)]
             return local:filterRecord($docMatch, $match))
        }
};


local:filterRecord(<doc><c1><cc1/></c1></doc>,
                   <config><c1><cc1/></c1><c2/></config>)

