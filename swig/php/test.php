<?php
require_once "zorba_api.php";

function example1( $zorba )
{
  $xquery = $zorba->compileQuery("1+2");
  echo $xquery->execute();
}

function example2( $zorba )
{
  $xquery = $zorba->compileQuery('(1,2,3,4,5)');
  $iter = $xquery->iterator();
  $iter->open();
  $item = S_Item::createEmptyItem();
  while ( $iter->next( $item ) )
  {
    print $item->getStringValue();
    print "\n";
  }
  $iter->close();
  $iter->destroy();
}

function example3( $zorba )
{
  try {
    $xquery = $zorba->compileQuery('1 div 0');
    echo $xquery->execute();
  } catch( S_DynamicException $e ) {
    echo $e->getMsg();
  }
}

$store = S_InMemoryStore_getInstance();
$zorba = S_Zorba::getInstance( $store );
print 'Example1:';
print "\n";
example1($zorba);
print "\n";
print "\n";

print 'Example2:';
print "\n";
example2($zorba);
print "\n";

print 'Example3:';
example3($zorba);
print "\n";

#$zorba->shutdown();
#S_InMemoryStore_shutdown($store);
?>
