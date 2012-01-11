<?php
require_once 'Zorba/zorba_api_wrapper.php';

class XQueryCompilerException extends Exception{}
class XQueryProcessorException extends Exception{}

/**
 * Iterate over a sequence of XQuery items.
 * This class implements the SPL Iterator interface.
 *
 * The following code snippet iterates over a small sequence of items.
 * <code>
 * <?php
 * require_once 'Zorba/XQueryProcessor.php';
 *
 * $xquery = new XQueryProcessor();
 * $xquery->importQuery('(1, 2, 3)');
 * 
 * $iterator = $xquery->getIterator();
 * foreach($it as $key => $value) {
 *   echo $value."\n";
 * }
 * ?>
 * </code>
 */
class XQueryIterator implements Iterator {

  private $xquery   = null;
  private $iterator = null;
  private $item     = null;
  private $position = 0;
  private $valid    = false;

  public function __construct(XQuery $xquery)
  {
	  $this->xquery = $xquery;
    $this->item = Item::createEmptyItem();
  }

  public function __destruct()
  {
    $this->xquery->destroy();
  }

  public function rewind()
  {
    if ($this->iterator != null) {
      $this->iterator->close();
      $this->iterator->destroy();
    }
    
    $this->position = 0;
    $this->iterator = $this->xquery->iterator(); 
    $this->iterator->open();
    $this->valid    = $this->iterator->next($this->item);
  }

  public function current()
  {
    return $this->item->serialize();
  }

  public function key()
  {
    return $this->position;
  }

  public function next()
  {
    ++$this->position;
    $this->valid = $this->iterator->next($this->item);
  }

  public function valid()
  {
    return $this->valid;
  }
}

/**
 * The XQueryProcessor class allows to invoke the
 * <a href="http://www.zorba-xquery.com">Zorba XQuery Processor</a>.  
 *
 * Instructions to install the extension can be found at <a href="http://www.zorba-xquery.com/site2/html/php.html">http://www.zorba-xquery.com/site2/html/php.html</a>.
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
   * Creates an XQueryProcessor instance.
   */
  public function __construct(){
    $this->store = InMemoryStore::getInstance();
    $this->zorba = Zorba::getInstance($this->store);
  }

  /**
   * Shuts down the XQueryProcessor instance.
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
   * The following code snippets imports and execute an <em>Hello World</em> query:
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
	if(!is_string($query)) {
		throw new XQueryProcessorException('The query parameter must be a string. For instance: XQueryProcessor->importQuery("1+1")');
	}
    $this->query = $query;
    return $this;
  }

  /**
   * Import a query to execute from a file with the given name.
   * For instance, the following code snippet imports the query file named <em>hello_word.xq</em>:
   * <code>
   * $xquery = new ZorbaXQueryProcessor();
   *
   * $xquery->importQueryFromURI('hello_world.xq');
   * 
   * echo $xquery->execute() . '\n';
   * </code>
   *
   * @param  $filename Filename containing the query to execute.
   * @return ZorbaXQueryProcessor instance.
   */
  public function importQueryFromURI($filename) {
    $ctx = null;
    if(func_num_args() == 2) {
      $ctx = func_get_arg(1);
    }
    $query = file_get_contents($filename, FILE_USE_INCLUDE_PATH, $ctx);
    $this->importQuery($query);
    return $this;
  }

  /**
   * Set a value for an external variable.
   *
   * The following code snippet sets the value of the variable
   * <em>$i</em> with <em>1</em> with type xs:integer.
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
   * the local namespace to the value <em>1</em>.
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
      $this->variables['_'][$name] = $value;
    } else {
      $ns  = func_get_arg(0);
      $name  = func_get_arg(1);
      $value = func_get_arg(2);
      $this->variables[$ns][$name] = $value;
    }
    return $this;
  } 
  
  /**
   * Execute the Query.
   *
   * @return Query result.
   */
  public function execute() {
    //Execute
    $query = $this->compile();
    $result = $query->execute();
    $query->destroy();
    return $result;
  }

  /**
   * Provide an intance of the SPL iterator to iterator over the 
   * sequence of items produced by the query result.
   *
   * @return XQueryIterator
   */
  public function getIterator() {
    return new XQueryIterator($this->compile());
  }

	/**
   * Internal method that creates an instance of the
   * XQuery class from the input parameters (importQuery and setVariable).
   *
   * @return XQuery compiled query.
	 */
	private function compile()
	{
	  if(!is_string($this->query)) {
		throw new XQueryCompilerException('No Query Imported. Use XQueryProcessor->importQuery($query).');
	  }
	  //Compile Query
	  $query = $this->zorba->compileQuery($this->query);
	  //Set Variables
	  $dctx = $query->getDynamicContext();
	  foreach($this->variables as $ns => $variables){
        foreach($variables as $name => $value) {
          if($ns == "_") $ns = "";
          $param = $this->zorba->compileQuery(".");
          $value = $this->getItem($value);
          $param->getDynamicContext()->setContextItem($value);
          $dctx->setVariable($ns, $name, $param->iterator());
	    }
      }
	  return $query;
	}

  /*
   * Converts a PHP value to an XQuery Item.
   * - DOMDocument & SimpleXMLElement: document-node()
   * - String: xs:string
   * - Integer: xs:integer
   * - Boolean: xs:boolean
   * - Float: xs:float
   * - Long: xs:long
   */  
	private function getItem($value) {
      $itemFactory = $this->zorba->getItemFactory();

      if($value instanceof DOMDocument or $value instanceof SimpleXMLElement) { 
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
        throw new XQueryCompilerException("Unsupported variable type: ".gettype($value));
      }

      assert($value instanceof Item);

      return $value;
    }

  /**
   * Parse an XML string to an XQuery Item.
   * This function is used internally only. 
   * @param $xml string XML string to parse.
   *
   * @return Item instance.
   */
  private function parseXML($xml)
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
}
?>
