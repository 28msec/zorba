<?php
require_once 'Zorba/zorba_api_wrapper.php';

/**
 * The XQueryProcessor class allows to invoke
 * <a href="http://www.zorba-xquery.com">Zorba XQuery Processor</a>.  
 *
 * Instruction to install the extension can be found at <a href=""></a>.
 *
 * The following code snippet executes a small <em>Hello World</em> program:
 * <code>
 * <?php
 * require_once 'ZorbaXQueryProcessor.php';
 *
 * $xquery = new XQueryProcessor();
 *
 * $query = <<<'XQ'
 * declare variable $name external;
 *
 * <h1>Hello {$name}</h1>
 * XQ;
 *
 * $xquery->importQuery($query);
 *
 * $xquery->setVariable('name', 'World');
 *
 * echo $xquery->execute();
 * ?>
 * </code>
 */
class XQueryProcessor {

  private $store = null;
  private $zorba = null;
  private $query = null;
  private $variables = array();

  /**
   * Creates a Zorba instance.
   */
  public function __construct(){
    $this->store = InMemoryStore::getInstance();
    $this->zorba = Zorba::getInstance($this->store);
  }

  /**
   * Shutdowns Zorba instance.
   */
  public function __destruct() {
    $this->zorba->shutdown();
    InMemoryStore::shutdown($this->store);
  }

  /**
   * Import a query to execute.
   * For instance, the following code snippets imports and executes the query '1+1':
   * <code>
   * $xquery = new ZorbaXQueryProcessor();
   *
   * $xquery->importQuery('1+1');
   * 
   * echo $xquery->execute() . '\n';
   * </code>
   * In the following code snippet, the following code snippets imports and execute an <em>Hello World</em> query:
   * <code>
   * <?php
   * $xquery = new XQueryProcessor();
   *
   * $query = <<<'XQ'
   * let $world := 'World'
   * return <h1>Hello {$world}</h1>
   * XQ;
   *
   * $xquery->importQuery($query);
   *
   * echo $xquery->execute() . '\n';
   * ?>
   * </code>
   *  
   * @param $query Query to execute.
   * @return ZorbaXQueryProcessor instance.
   */ 
  public function importQuery($query) {
    $this->query = $query;
    return $this;
  }

  /**
   * Import a query to execute from its filename.
   * For instance, the following code snippet imports the query file named <em>hello_word.xq</em>:
   * <code>
   * $xquery = new ZorbaXQueryProcessor();
   *
   * $xquery->importQueryiFromURI('hello_world.xq');
   * 
   * echo $xquery->execute() . '\n';
   * </code>
   *
   * @param  $filename Filename of the query to execute.
   * @return ZorbaXQueryProcessor instance.
   */
  public function importQueryFromURI($filename) {
    $this->importQuery(file_get_contents($filename));
    return $this;
  }

  /**
   * Set value for an external variable.
   *
   * The following code snippet sets the value of the variable
   * <em>$i</em> with <em>1</em>.
   * <code>
   * $xquery = new ZorbaXQueryProcessor();
   * 
   * $query = <<<'XQ'
   * declare variable $i as xs:integer external;
   *
   * $i + 1
   * 'XQ';
   *
   * $xquery->importQuery($query);
   * $xquery->setVariable($i, 1);
   *
   * echo $xquery->execute() . '\n';
   * </code>
   *
   * The following code snippet sets the value of the variable <em>$i</em> in
   * the local namespace with the value <em>1</em>.
   * <code>
   * $xquery = new ZorbaXQueryProcessor();
   * 
   * $query = <<<'XQ'
   * declare variable $local:i as xs:integer external;
   *
   * $i + 1
   * 'XQ';
   *
   * $xquery->importQuery($query);
   * $xquery->setVariable("http://www.w3.org/2005/xquery-local-functions", $i, 1);
   *
   * echo $xquery->execute() . '\n';
   * </code>
   *
   * PHP types are converted to the following XML types:
   * - <b>string</b>: xs:string
   * - <b>float</b>: xs:float
   * - <b>long</b>: xs:long
   * - <b>integer</b>: xs:integer
   * - <b>boolean</b>: xs:boolean
   * - <b>DOMDocument</b>: document-node()    
   * 
   * @param string $namespace optional Namespace URI of the external variable.
   * @param string $name Local name of the external variable.
   * @param mixed  $value of the external variable.
   *
   * return ZorbaXQueryProcessor instance. 
   */
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
    return $this;
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
  
  /**
   * Parse an XML string to an XQuery Item.
   * 
   * @param $xml string XML string to parse.
   *
   * @return Item instance.
   */
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
  
  /**
   * Parse an XML document from its URI to an XQuery Item.
   * 
   * @param $uri string URI of the XML document to parse.
   *
   * @return Item instance.
   */
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
  
  /**
   * Execute the Query.
   *
   * @return Query result.
   */
  public function execute() {
    //Execute
    $query = $this->prepareQuery();
    $result = $query->execute();
    $query->destroy();
    return $result;
  }
  
  /**
   * Execute the query and store its results to 
   * the given URI.
   */
  public function executeToURI($uri) {
    $result = $this->execute();
    return file_put_contents($uri, $result);
  }
}
?>
