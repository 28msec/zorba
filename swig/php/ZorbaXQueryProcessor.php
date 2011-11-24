<?php
require_once 'zorba_api_wrapper.php';

class ZorbaXQueryProcessor {

  private $store = null;
  private $zorba = null;
  private $query = null;
  private $variables = array();

  public function __construct(){
    $this->store = InMemoryStore::getInstance();
    $this->zorba = Zorba::getInstance($this->store);
  }

  public function __destruct() {
    $this->zorba->shutdown();
    InMemoryStore::shutdown($this->store);
  }

  public function getZorba() {
    return $this->zorba;  
  }
  
  public function importQuery($query) {
    $this->query = $query;
  }

  public function importQueryFromURI($filename) {
    $this->importQuery(file_get_contents($filename));
  }

  public function setVariable($arg1, $arg2) {
    $count = func_num_args();
    if($count == 2) {
      $name  = func_get_arg(0);
      $value = func_get_arg(1);
      $value = $this->getItem($value);
      $this->variables['_'][$name] = $value;
    } else {
      $ns  = func_get_arg(0);
      $name  = func_get_arg(1);
      $value = func_get_arg(2);
      $value = $this->getItem($value);
      $this->variables[$ns][$name] = $value;
    }
  }
  
  private function getItem($value) {
    
    $itemFactory = $this->zorba->getItemFactory();
    
    if($value instanceof Item) {
      //Do nothing
    } else if($value instanceof DOMDocument or $value instanceof SimpleXMLElement) { 
      $value = $this->parseXML($value->saveXML());
    } else if(is_string($value)) {
    $value = $itemFactory->createString($value);
    } else if(is_int($value)) {
      $value = $itemFactory->createInteger($value);
    } else if(is_bool($value)) {
      $value = $itemFactory->createBoolean($value);
    } else if(is_float($value)) {
      $value = $itemFactory->createFloat($value);
    } else if(is_long($value)) {
      $value = $itemFactory->createLong($value);
    } else  {
      throw new Exception("Unsupported variable type: ".gettype($value));
    }
    
    assert($value instanceof Item);
    
    return $value;
  }
  
  public function parseXML($xml)
  {
      $lDataManager = $this->zorba->getXmlDataManager();
    $lDocMgr = $lDataManager->getDocumentManager();
    $iter = $lDataManager->parseXML($xml);
    
    $iter->open();
    $doc = Item::createEmptyItem();
    
    $iter->next($doc);
    $iter->close();
    $iter->destroy();
    
    return $doc;  
  }
  
  public function parseXMLfromURI($uri)
  {
    $this->parseXML($uri);
  }

  private function prepareQuery() {
    if($this->query == null) {
      throw new Exception("No Query Imported");
    }
    //Compile Query
    $query = $this->zorba->compileQuery($this->query);
    //Set Variables
    $dctx = $query->getDynamicContext();
    foreach($this->variables as $ns => $variables){
      foreach($variables as $name => $value) {
        if($ns == "_") $ns = "";
        $param = $this->zorba->compileQuery(".");
        $param->getDynamicContext()->setContextItem($value);
        $dctx->setVariable($ns, $name, $param->iterator());
    }
    }
    return $query;
  }
  
  public function execute() {
    //Execute
    $query = $this->prepareQuery();
    $result = $query->execute();
    $query->destroy();
    return $result;
  }
  
  public function executeToXML() {
    $result = $this->execute();
    return str_replace('<?xml version="1.0" encoding="UTF-8"?>', '', $result);
  }

  public function executeToStream($stream) {
    $query = $this->prepareQuery();
    
    $it = $query->iterator();
    $it->open();
    
    $item = Item::createEmptyItem();
    
    while($it->next($item))
    {
      fwrite($stream, 
             trim(str_replace('<?xml version="1.0" encoding="UTF-8"?>', '', $item->serialize()))
      );
    }
    $it->close();
    $it->destroy();
    
    $query->destroy();
    
    return $result;
  }

  public function executeToURI($uri) {
    $result = $this->execute();
    return file_put_contents($uri, $result);
  }
}
?>
