<?php
//Try to load the extension if it's not already loaded.
if(!extension_loaded('zorba_api')) {
  $zorbaExtNotLoaded = "Zorba extension couldn't loaded";
  if(function_exists('dl')) {
    if(strtolower(substr(PHP_OS, 0, 3)) === 'win') {
      if(!dl('zorba_api.dll')) {
        throw new Exception($zorbaExtNotLoaded);
      }  
    } else {
      $suffix = "so";
      if(PHP_SHLIB_SUFFIX === 'PHP_SHLIB_SUFFIX' || PHP_SHLIB_SUFFIX === 'dylib') {
        $suffix = PHP_SHLIB_SUFFIX;
      }
      if(!dl('zorba_api.'.$suffix)) {
        if(!dl('libzorba_api.'.$suffix)) {
          throw new Exception($zorbaExtNotLoaded);
        }
      }
    }
  } else {
    throw new Exception($zorbaExtNotLoaded);
  }
}

class DynamicContext{
  public $_cPtr=null;

  public function __set($var, $value) {
    $r =  DynamicContext___set($this->_cPtr, $var, $value);
    return $r;

  }

  public function __isset($var) {
    $r =  DynamicContext___isset($this->_cPtr, $var);
    return $r;

  }

  public function __get($var) {
    $r =  DynamicContext___get($this->_cPtr, $var);
    return $r;

  }

  public function setVariable($aNamespace, $aLocalname, $arg3) {
    $r =  DynamicContext_setVariable($this->_cPtr, $aNamespace, $aLocalname, $arg3);
    return $r;

  }

  public function setContextItem($arg1) {
    $r =  DynamicContext_setContextItem($this->_cPtr, $arg1);
    return $r;

  }

  public function __construct($ptr) {
  	$this->_cPtr = $ptr;
  }

}

class Item{
  public $_cPtr=null;

  public function __set($var, $value) {
    $r =  Item___set($this->_cPtr, $var, $value);
    return $r;

  }

  public function __isset($var) {
    $r =  Item___isset($this->_cPtr, $var);
    return $r;

  }

  public function __get($var) {
    $r =  Item___get($this->_cPtr, $var);
    return $r;

  }

  static  public function createEmptyItem() {
    $r =  Item_createEmptyItem();
    return is_resource($r) ? new Item($r) : $r;

  }

  public function getStringValue() {
    $r =  Item_getStringValue($this->_cPtr);
    return $r;

  }

  public function serialize() {
    $r =  Item_serialize($this->_cPtr);
    return $r;

  }

  public function getAtomizationValue() {
    $r =  Item_getAtomizationValue($this->_cPtr);
    return is_resource($r) ? new IteratorImpl($r) : $r;

  }

  public function getAttributes() {
    $r =  Item_getAttributes($this->_cPtr);
    return is_resource($r) ? new IteratorImpl($r) : $r;

  }

  public function getBooleanValue() {
    $r =  Item_getBooleanValue($this->_cPtr);
    return $r;

  }

  public function getChildren() {
    $r =  Item_getChildren($this->_cPtr);
    return is_resource($r) ? new IteratorImpl($r) : $r;

  }

  public function getEBV() {
    $r =  Item_getEBV($this->_cPtr);
    return is_resource($r) ? new Item($r) : $r;

  }

  public function getIntValue() {
    $r =  Item_getIntValue($this->_cPtr);
    return $r;

  }

  public function getLocalName() {
    $r =  Item_getLocalName($this->_cPtr);
    return $r;

  }

  public function getNamespace() {
    $r =  Item_getNamespace($this->_cPtr);
    return $r;

  }

  public function getNodeName($aNodeName) {
    $r =  Item_getNodeName($this->_cPtr, $aNodeName);
    return $r;

  }

  public function getPrefix() {
    $r =  Item_getPrefix($this->_cPtr);
    return $r;

  }

  public function getType() {
    $r =  Item_getType($this->_cPtr);
    return is_resource($r) ? new Item($r) : $r;

  }

  public function getUnsignedIntValue() {
    $r =  Item_getUnsignedIntValue($this->_cPtr);
    return $r;

  }

  public function getNodeKind() {
    $r =  Item_getNodeKind($this->_cPtr);
    return $r;

  }

  public function isAtomic() {
    $r =  Item_isAtomic($this->_cPtr);
    return $r;

  }

  public function isNaN() {
    $r =  Item_isNaN($this->_cPtr);
    return $r;

  }

  public function isNode() {
    $r =  Item_isNode($this->_cPtr);
    return $r;

  }

  public function isNull() {
    $r =  Item_isNull($this->_cPtr);
    return $r;

  }

  public function isPosOrNegInf() {
    $r =  Item_isPosOrNegInf($this->_cPtr);
    return $r;

  }

  public function __construct($ptr) {
  	$this->_cPtr = $ptr;
  }

}

class IteratorImpl{
  public $_cPtr=null;

  public function __set($var, $value) {
    $r =  Iterator___set($this->_cPtr, $var, $value);
    return $r;

  }

  public function __isset($var) {
    $r =  Iterator___isset($this->_cPtr, $var);
    return $r;

  }

  public function __get($var) {
    $r =  Iterator___get($this->_cPtr, $var);
    return $r;

  }

  public function open() {
    $r =  Iterator_open($this->_cPtr);
    return $r;

  }

  public function next($arg1) {
    $r =  Iterator_next($this->_cPtr, $arg1);
    return $r;

  }

  public function close() {
    $r =  Iterator_close($this->_cPtr);
    return $r;

  }

  public function destroy() {
    $r =  Iterator_destroy($this->_cPtr);
    return $r;

  }

  public function __construct($ptr) {
  	$this->_cPtr = $ptr;
  }

}

class XQuery{
  public $_cPtr=null;

  public function __set($var, $value) {
    $r =  XQuery___set($this->_cPtr, $var, $value);
    return $r;

  }

  public function __isset($var) {
    $r =  XQuery___isset($this->_cPtr, $var);
    return $r;

  }

  public function __get($var) {
    $r =  XQuery___get($this->_cPtr, $var);
    return $r;

  }

  public function execute() {
    $r =  XQuery_execute($this->_cPtr);
    return $r;

  }

  public function printPlanAsXML() {
    $r =  XQuery_printPlanAsXML($this->_cPtr);
    return $r;

  }

  public function printPlanAsDOT() {
    $r =  XQuery_printPlanAsDOT($this->_cPtr);
    return $r;

  }

  public function compile($aQuery, $aStaticContext=null) {
    switch(func_num_args()) {
    case 1: $r =  XQuery_compile($this->_cPtr, $aQuery);break;
    case 2: $r =  XQuery_compile($this->_cPtr, $aQuery, $aStaticContext);break;
    default: $r =  XQuery_compile($this->_cPtr, $aQuery, $aStaticContext);
    }
    return $r;

  }

  public function destroy() {
    $r =  XQuery_destroy($this->_cPtr);
    return $r;

  }

  public function iterator() {
    $r =  XQuery_iterator($this->_cPtr);
    return is_resource($r) ? new IteratorImpl($r) : $r;

  }

  public function getDynamicContext() {
    $r =  XQuery_getDynamicContext($this->_cPtr);
    return is_resource($r) ? new DynamicContext($r) : $r;

  }

  public function __construct($ptr) {
  	$this->_cPtr = $ptr;
  }

}

class Store{
  public $_cPtr=null;

  public function __set($var, $value) {
    $r =  Store___set($this->_cPtr, $var, $value);
    return $r;

  }

  public function __isset($var) {
    $r =  Store___isset($this->_cPtr, $var);
    return $r;

  }

  public function __get($var) {
    $r =  Store___get($this->_cPtr, $var);
    return $r;

  }

  public function __construct($ptr) {
  	$this->_cPtr = $ptr;
  }

}

class InMemoryStore extends Store{
  public $_cPtr=null;

  static  public function getInstance() {
    $r =  InMemoryStore_getInstance();
    return is_resource($r) ? new InMemoryStore($r) : $r;

  }

  static  public function shutdown($arg1) {
    $r =  InMemoryStore_shutdown($arg1);
    return $r;

  }

}

class DocumentManager{
  public $_cPtr=null;

  public function __set($var, $value) {
    $r =  DocumentManager___set($this->_cPtr, $var, $value);
    return $r;

  }

  public function __isset($var) {
    $r =  DocumentManager___isset($this->_cPtr, $var);
    return $r;

  }

  public function __get($var) {
    $r =  DocumentManager___get($this->_cPtr, $var);
    return $r;

  }

  public function put($aName, $aDoc) {
    $r =  DocumentManager_put($this->_cPtr, $aName, $aDoc);
    return $r;

  }

  public function remove($aName) {
    $r =  DocumentManager_remove($this->_cPtr, $aName);
    return $r;

  }

  public function document($aName) {
    $r =  DocumentManager_document($this->_cPtr, $aName);
    return is_resource($r) ? new Item($r) : $r;

  }

  public function isAvailableDocument($aName) {
    $r =  DocumentManager_isAvailableDocument($this->_cPtr, $aName);
    return $r;

  }

  public function __construct($ptr) {
  	$this->_cPtr = $ptr;
  }

}

class XmlDataManager{
  public $_cPtr=null;

  public function __set($var, $value) {
    $r =  XmlDataManager___set($this->_cPtr, $var, $value);
    return $r;

  }

  public function __isset($var) {
    $r =  XmlDataManager___isset($this->_cPtr, $var);
    return $r;

  }

  public function __get($var) {
    $r =  XmlDataManager___get($this->_cPtr, $var);
    return $r;

  }

  public function getDocumentManager() {
    $r =  XmlDataManager_getDocumentManager($this->_cPtr);
    return is_resource($r) ? new DocumentManager($r) : $r;

  }

  public function parseXML($aDoc) {
    $r =  XmlDataManager_parseXML($this->_cPtr, $aDoc);
    return is_resource($r) ? new IteratorImpl($r) : $r;

  }

  public function __construct($ptr) {
  	$this->_cPtr = $ptr;
  }

}

class ZorbaException{
  public $_cPtr=null;

  public function __set($var, $value) {
    $r =  ZorbaException___set($this->_cPtr, $var, $value);
    return $r;

  }

  public function __isset($var) {
    $r =  ZorbaException___isset($this->_cPtr, $var);
    return $r;

  }

  public function __get($var) {
    $r =  ZorbaException___get($this->_cPtr, $var);
    return $r;

  }

  public function __construct($ptr) {
  	$this->_cPtr = $ptr;
  }

  public function getDescription() {
    $r =  ZorbaException_getDescription($this->_cPtr);
    return $r;

  }

  public function getErrorCode() {
    $r =  ZorbaException_getErrorCode($this->_cPtr);
    return $r;

  }

  public function getFileLineNumber() {
    $r =  ZorbaException_getFileLineNumber($this->_cPtr);
    return $r;

  }

  public function getFileName() {
    $r =  ZorbaException_getFileName($this->_cPtr);
    return $r;

  }

  static  public function getErrorCodeAsString($aErrorCode) {
    $r =  ZorbaException_getErrorCodeAsString($aErrorCode);
    return $r;

  }

}

class XQueryException extends ZorbaException{
  public $_cPtr=null;

  public function getColumnBegin() {
    $r =  XQueryException_getColumnBegin($this->_cPtr);
    return $r;

  }

  public function getLineBegin() {
    $r =  XQueryException_getLineBegin($this->_cPtr);
    return $r;

  }

  public function getQueryURI() {
    $r =  XQueryException_getQueryURI($this->_cPtr);
    return $r;

  }

}

class CompilerHints{
  public $_cPtr=null;

  public function __set($var, $value) {
    $r =  CompilerHints___set($this->_cPtr, $var, $value);
    return $r;

  }

  public function __isset($var) {
    $r =  CompilerHints___isset($this->_cPtr, $var);
    return $r;

  }

  public function __get($var) {
    $r =  CompilerHints___get($this->_cPtr, $var);
    return $r;

  }

  public function getLibModule() {
    $r =  CompilerHints_getLibModule($this->_cPtr);
    return $r;

  }

  public function setLibModule($aLibModule) {
    $r =  CompilerHints_setLibModule($this->_cPtr, $aLibModule);
    return $r;

  }

  public function getOptimizationLevel() {
    $r =  CompilerHints_getOptimizationLevel($this->_cPtr);
    return $r;

  }

  public function setOptimizationLevel($aOptLevel) {
    $r =  CompilerHints_setOptimizationLevel($this->_cPtr, $aOptLevel);
    return $r;

  }

  public function __construct($ptr) {
  	$this->_cPtr = $ptr;
  }

}

class StaticContext{
  public $_cPtr=null;

  public function __set($var, $value) {
    $r =  StaticContext___set($this->_cPtr, $var, $value);
    return $r;

  }

  public function __isset($var) {
    $r =  StaticContext___isset($this->_cPtr, $var);
    return $r;

  }

  public function __get($var) {
    $r =  StaticContext___get($this->_cPtr, $var);
    return $r;

  }

  public function __construct($ptr) {
  	$this->_cPtr = $ptr;
  }

  public function addColation($aURI) {
    $r =  StaticContext_addColation($this->_cPtr, $aURI);
    return $r;

  }

  public function addNamespace($aPrefix, $aURI) {
    $r =  StaticContext_addNamespace($this->_cPtr, $aPrefix, $aURI);
    return $r;

  }

  public function addReference() {
    $r =  StaticContext_addReference($this->_cPtr);
    return $r;

  }

  public function containsFunction($aFnNameUri, $aFnNameLocal, $arity) {
    $r =  StaticContext_containsFunction($this->_cPtr, $aFnNameUri, $aFnNameLocal, $arity);
    return $r;

  }

  public function createChildContext() {
    $r =  StaticContext_createChildContext($this->_cPtr);
    return is_resource($r) ? new StaticContext($r) : $r;

  }

  public function declareOption($aQName, $aOptionVal) {
    $r =  StaticContext_declareOption($this->_cPtr, $aQName, $aOptionVal);
    return $r;

  }

  public function disableFunction($aQName, $arity) {
    $r =  StaticContext_disableFunction($this->_cPtr, $aQName, $arity);
    return $r;

  }

  public function free() {
    $r =  StaticContext_free($this->_cPtr);
    return $r;

  }

  public function getBaseURI() {
    $r =  StaticContext_getBaseURI($this->_cPtr);
    return $r;

  }

  public function getBoundarySpacePolicy() {
    $r =  StaticContext_getBoundarySpacePolicy($this->_cPtr);
    return $r;

  }

  public function getConstructionMode() {
    $r =  StaticContext_getConstructionMode($this->_cPtr);
    return $r;

  }

  public function getCopyNamespacesMode($aPreserve, $aInherit) {
    $r =  StaticContext_getCopyNamespacesMode($this->_cPtr, $aPreserve, $aInherit);
    return $r;

  }

  public function getDefaultCollation() {
    $r =  StaticContext_getDefaultCollation($this->_cPtr);
    return $r;

  }

  public function getDefaultElementAndTypeNamespace() {
    $r =  StaticContext_getDefaultElementAndTypeNamespace($this->_cPtr);
    return $r;

  }

  public function getDefaultFunctionNamespace() {
    $r =  StaticContext_getDefaultFunctionNamespace($this->_cPtr);
    return $r;

  }

  public function getDefaultOrderForEmptySequences() {
    $r =  StaticContext_getDefaultOrderForEmptySequences($this->_cPtr);
    return $r;

  }

  public function getNamespaceURIByPrefix($aPrefix) {
    $r =  StaticContext_getNamespaceURIByPrefix($this->_cPtr, $aPrefix);
    return $r;

  }

  public function getOption($aQName, $aOptionValue) {
    $r =  StaticContext_getOption($this->_cPtr, $aQName, $aOptionValue);
    return $r;

  }

  public function getOrderingMode() {
    $r =  StaticContext_getOrderingMode($this->_cPtr);
    return $r;

  }

  public function getRefCount() {
    $r =  StaticContext_getRefCount($this->_cPtr);
    return $r;

  }

  public function getRevalidationMode() {
    $r =  StaticContext_getRevalidationMode($this->_cPtr);
    return $r;

  }

  public function getXPath1_0CompatibMode() {
    $r =  StaticContext_getXPath1_0CompatibMode($this->_cPtr);
    return $r;

  }

  public function loadProlog($aProlog, $hints) {
    $r =  StaticContext_loadProlog($this->_cPtr, $aProlog, $hints);
    return $r;

  }

  public function removeReference() {
    $r =  StaticContext_removeReference($this->_cPtr);
    return $r;

  }

  public function resetTraceStream() {
    $r =  StaticContext_resetTraceStream($this->_cPtr);
    return $r;

  }

  public function setBaseURI($aBaseURI) {
    $r =  StaticContext_setBaseURI($this->_cPtr, $aBaseURI);
    return $r;

  }

  public function setBoundarySpacePolicy($aMode) {
    $r =  StaticContext_setBoundarySpacePolicy($this->_cPtr, $aMode);
    return $r;

  }

  public function setConstructionMode($aMode) {
    $r =  StaticContext_setConstructionMode($this->_cPtr, $aMode);
    return $r;

  }

  public function setCopyNamespacesMode($aPreserve, $aInherit) {
    $r =  StaticContext_setCopyNamespacesMode($this->_cPtr, $aPreserve, $aInherit);
    return $r;

  }

  public function setDefaultCollation($aURI) {
    $r =  StaticContext_setDefaultCollation($this->_cPtr, $aURI);
    return $r;

  }

  public function setDefaultElementAndTypeNamespace($aURI) {
    $r =  StaticContext_setDefaultElementAndTypeNamespace($this->_cPtr, $aURI);
    return $r;

  }

  public function setDefaultFunctionNamespace($aURI) {
    $r =  StaticContext_setDefaultFunctionNamespace($this->_cPtr, $aURI);
    return $r;

  }

  public function setDefaultOrderForEmptySequences($aMode) {
    $r =  StaticContext_setDefaultOrderForEmptySequences($this->_cPtr, $aMode);
    return $r;

  }

  public function setOrderingMode($aMode) {
    $r =  StaticContext_setOrderingMode($this->_cPtr, $aMode);
    return $r;

  }

  public function setRevalidationMode($aMode) {
    $r =  StaticContext_setRevalidationMode($this->_cPtr, $aMode);
    return $r;

  }

  public function setXPath1_0CompatibMode($aMode) {
    $r =  StaticContext_setXPath1_0CompatibMode($this->_cPtr, $aMode);
    return $r;

  }

  public function destroy() {
    $r =  StaticContext_destroy($this->_cPtr);
    return $r;

  }

}

class Zorba{
  public $_cPtr=null;

  public function __set($var, $value) {
    $r =  Zorba___set($this->_cPtr, $var, $value);
    return $r;

  }

  public function __isset($var) {
    $r =  Zorba___isset($this->_cPtr, $var);
    return $r;

  }

  public function __get($var) {
    $r =  Zorba___get($this->_cPtr, $var);
    return $r;

  }

  static  public function getInstance($arg1) {
    $r =  Zorba_getInstance($arg1);
    return is_resource($r) ? new Zorba($r) : $r;

  }

  public function createStaticContext() {
    $r =  Zorba_createStaticContext($this->_cPtr);
    return is_resource($r) ? new StaticContext($r) : $r;

  }

  public function createQuery() {
    $r =  Zorba_createQuery($this->_cPtr);
    return is_resource($r) ? new XQuery($r) : $r;

  }

  public function compileQuery($aStr, $aStaticContext=null) {
    switch(func_num_args()) {
    case 1: $r =  Zorba_compileQuery($this->_cPtr, $aStr);break;
    case 2: $r =  Zorba_compileQuery($this->_cPtr, $aStr, $aStaticContext);break;
    default: $r =  Zorba_compileQuery($this->_cPtr, $aStr, $aStaticContext);
    }
    return is_resource($r) ? new XQuery($r) : $r;

  }

  public function getItemFactory() {
    $r =  Zorba_getItemFactory($this->_cPtr);
    return is_resource($r) ? new ItemFactory($r) : $r;

  }

  public function getXmlDataManager() {
    $r =  Zorba_getXmlDataManager($this->_cPtr);
    return is_resource($r) ? new XmlDataManager($r) : $r;

  }

  public function shutdown() {
    $r =  Zorba_shutdown($this->_cPtr);
    return $r;

  }

  public function __construct($ptr) {
  	$this->_cPtr = $ptr;
  }

}

class ItemFactory{
  public $_cPtr=null;

  public function __set($var, $value) {
    $r =  ItemFactory___set($this->_cPtr, $var, $value);
    return $r;

  }

  public function __isset($var) {
    $r =  ItemFactory___isset($this->_cPtr, $var);
    return $r;

  }

  public function __get($var) {
    $r =  ItemFactory___get($this->_cPtr, $var);
    return $r;

  }

  public function __construct($ptr) {
  	$this->_cPtr = $ptr;
  }

  public function createAnyURI($aURI) {
    $r =  ItemFactory_createAnyURI($this->_cPtr, $aURI);
    return is_resource($r) ? new Item($r) : $r;

  }

  public function createAttributeNode($aParent, $aNodeName, $aTypeName, $aTypedValue) {
    $r =  ItemFactory_createAttributeNode($this->_cPtr, $aParent, $aNodeName, $aTypeName, $aTypedValue);
    return is_resource($r) ? new Item($r) : $r;

  }

  public function createBase64Binary($aBinData_or_aStream, $aLength=null) {
    switch(func_num_args()) {
    case 1: $r =  ItemFactory_createBase64Binary($this->_cPtr, $aBinData_or_aStream);break;
    case 2: $r =  ItemFactory_createBase64Binary($this->_cPtr, $aBinData_or_aStream, $aLength);break;
    default: $r =  ItemFactory_createBase64Binary($this->_cPtr, $aBinData_or_aStream, $aLength);
    }
    return is_resource($r) ? new Item($r) : $r;

  }

  public function createBoolean($aValue) {
    $r =  ItemFactory_createBoolean($this->_cPtr, $aValue);
    return is_resource($r) ? new Item($r) : $r;

  }

  public function createByte($aByte) {
    $r =  ItemFactory_createByte($this->_cPtr, $aByte);
    return is_resource($r) ? new Item($r) : $r;

  }

  public function createDate($aDate_or_aYear, $aMonth=null, $aDay=null) {
    switch(func_num_args()) {
    case 1: $r =  ItemFactory_createDate($this->_cPtr, $aDate_or_aYear);break;
    case 2: $r =  ItemFactory_createDate($this->_cPtr, $aDate_or_aYear, $aMonth);break;
    case 3: $r =  ItemFactory_createDate($this->_cPtr, $aDate_or_aYear, $aMonth, $aDay);break;
    default: $r =  ItemFactory_createDate($this->_cPtr, $aDate_or_aYear, $aMonth, $aDay);
    }
    return is_resource($r) ? new Item($r) : $r;

  }

  public function createDateTime($aDateTimeValue_or_aYear, $aMonth=null, $aDay=null, $aHour=null, $aMinute=null, $aSecond=null, $aTimeZone_hours=null) {
    switch(func_num_args()) {
    case 1: $r =  ItemFactory_createDateTime($this->_cPtr, $aDateTimeValue_or_aYear);break;
    case 2: $r =  ItemFactory_createDateTime($this->_cPtr, $aDateTimeValue_or_aYear, $aMonth);break;
    case 3: $r =  ItemFactory_createDateTime($this->_cPtr, $aDateTimeValue_or_aYear, $aMonth, $aDay);break;
    case 4: $r =  ItemFactory_createDateTime($this->_cPtr, $aDateTimeValue_or_aYear, $aMonth, $aDay, $aHour);break;
    case 5: $r =  ItemFactory_createDateTime($this->_cPtr, $aDateTimeValue_or_aYear, $aMonth, $aDay, $aHour, $aMinute);break;
    case 6: $r =  ItemFactory_createDateTime($this->_cPtr, $aDateTimeValue_or_aYear, $aMonth, $aDay, $aHour, $aMinute, $aSecond);break;
    case 7: $r =  ItemFactory_createDateTime($this->_cPtr, $aDateTimeValue_or_aYear, $aMonth, $aDay, $aHour, $aMinute, $aSecond, $aTimeZone_hours);break;
    default: $r =  ItemFactory_createDateTime($this->_cPtr, $aDateTimeValue_or_aYear, $aMonth, $aDay, $aHour, $aMinute, $aSecond, $aTimeZone_hours);
    }
    return is_resource($r) ? new Item($r) : $r;

  }

  public function createDecimal($aValue) {
    $r =  ItemFactory_createDecimal($this->_cPtr, $aValue);
    return is_resource($r) ? new Item($r) : $r;

  }

  public function createDecimalFromDouble($aValue) {
    $r =  ItemFactory_createDecimalFromDouble($this->_cPtr, $aValue);
    return is_resource($r) ? new Item($r) : $r;

  }

  public function createDecimalFromLong($aValue) {
    $r =  ItemFactory_createDecimalFromLong($this->_cPtr, $aValue);
    return is_resource($r) ? new Item($r) : $r;

  }

  public function createDouble($aValue) {
    $r =  ItemFactory_createDouble($this->_cPtr, $aValue);
    return is_resource($r) ? new Item($r) : $r;

  }

  public function createDuration($aValue_or_aYear, $aMonths=null, $aDays=null, $aHours=null, $aMinutes=null, $aSeconds=null) {
    switch(func_num_args()) {
    case 1: $r =  ItemFactory_createDuration($this->_cPtr, $aValue_or_aYear);break;
    case 2: $r =  ItemFactory_createDuration($this->_cPtr, $aValue_or_aYear, $aMonths);break;
    case 3: $r =  ItemFactory_createDuration($this->_cPtr, $aValue_or_aYear, $aMonths, $aDays);break;
    case 4: $r =  ItemFactory_createDuration($this->_cPtr, $aValue_or_aYear, $aMonths, $aDays, $aHours);break;
    case 5: $r =  ItemFactory_createDuration($this->_cPtr, $aValue_or_aYear, $aMonths, $aDays, $aHours, $aMinutes);break;
    case 6: $r =  ItemFactory_createDuration($this->_cPtr, $aValue_or_aYear, $aMonths, $aDays, $aHours, $aMinutes, $aSeconds);break;
    default: $r =  ItemFactory_createDuration($this->_cPtr, $aValue_or_aYear, $aMonths, $aDays, $aHours, $aMinutes, $aSeconds);
    }
    return is_resource($r) ? new Item($r) : $r;

  }

  public function createFloat($aValue) {
    $r =  ItemFactory_createFloat($this->_cPtr, $aValue);
    return is_resource($r) ? new Item($r) : $r;

  }

  public function createGDay($aValue_or_aDay) {
    $r =  ItemFactory_createGDay($this->_cPtr, $aValue_or_aDay);
    return is_resource($r) ? new Item($r) : $r;

  }

  public function createGMonth($aValue_or_aMonth) {
    $r =  ItemFactory_createGMonth($this->_cPtr, $aValue_or_aMonth);
    return is_resource($r) ? new Item($r) : $r;

  }

  public function createGMonthDay($aValue_or_aMonth, $aDay=null) {
    switch(func_num_args()) {
    case 1: $r =  ItemFactory_createGMonthDay($this->_cPtr, $aValue_or_aMonth);break;
    case 2: $r =  ItemFactory_createGMonthDay($this->_cPtr, $aValue_or_aMonth, $aDay);break;
    default: $r =  ItemFactory_createGMonthDay($this->_cPtr, $aValue_or_aMonth, $aDay);
    }
    return is_resource($r) ? new Item($r) : $r;

  }

  public function createGYear($aYear_or_aValue) {
    $r =  ItemFactory_createGYear($this->_cPtr, $aYear_or_aValue);
    return is_resource($r) ? new Item($r) : $r;

  }

  public function createGYearMonth($aValue_or_aYear, $aMonth=null) {
    switch(func_num_args()) {
    case 1: $r =  ItemFactory_createGYearMonth($this->_cPtr, $aValue_or_aYear);break;
    case 2: $r =  ItemFactory_createGYearMonth($this->_cPtr, $aValue_or_aYear, $aMonth);break;
    default: $r =  ItemFactory_createGYearMonth($this->_cPtr, $aValue_or_aYear, $aMonth);
    }
    return is_resource($r) ? new Item($r) : $r;

  }

  public function createHexBinary($aHexData, $aSize) {
    $r =  ItemFactory_createHexBinary($this->_cPtr, $aHexData, $aSize);
    return is_resource($r) ? new Item($r) : $r;

  }

  public function createInt($aInt) {
    $r =  ItemFactory_createInt($this->_cPtr, $aInt);
    return is_resource($r) ? new Item($r) : $r;

  }

  public function createInteger($aInteger) {
    $r =  ItemFactory_createInteger($this->_cPtr, (string)$aInteger);
    return is_resource($r) ? new Item($r) : $r;

  }

  public function createLong($aLong) {
    $r =  ItemFactory_createLong($this->_cPtr, $aLong);
    return is_resource($r) ? new Item($r) : $r;

  }

  public function createNCName($aValue) {
    $r =  ItemFactory_createNCName($this->_cPtr, $aValue);
    return is_resource($r) ? new Item($r) : $r;

  }

  public function createNegativeInteger($aValue) {
    $r =  ItemFactory_createNegativeInteger($this->_cPtr, $aValue);
    return is_resource($r) ? new Item($r) : $r;

  }

  public function createNonNegativeInteger($aValue) {
    $r =  ItemFactory_createNonNegativeInteger($this->_cPtr, $aValue);
    return is_resource($r) ? new Item($r) : $r;

  }

  public function createNonPositiveInteger($aValue) {
    $r =  ItemFactory_createNonPositiveInteger($this->_cPtr, $aValue);
    return is_resource($r) ? new Item($r) : $r;

  }

  public function createPositiveInteger($aValue) {
    $r =  ItemFactory_createPositiveInteger($this->_cPtr, $aValue);
    return is_resource($r) ? new Item($r) : $r;

  }

  public function createQName($aNamespace_or_aQNameString, $aPrefix_or_aLocalname=null, $aLocalname=null) {
    switch(func_num_args()) {
    case 1: $r =  ItemFactory_createQName($this->_cPtr, $aNamespace_or_aQNameString);break;
    case 2: $r =  ItemFactory_createQName($this->_cPtr, $aNamespace_or_aQNameString, $aPrefix_or_aLocalname);break;
    case 3: $r =  ItemFactory_createQName($this->_cPtr, $aNamespace_or_aQNameString, $aPrefix_or_aLocalname, $aLocalname);break;
    default: $r =  ItemFactory_createQName($this->_cPtr, $aNamespace_or_aQNameString, $aPrefix_or_aLocalname, $aLocalname);
    }
    return is_resource($r) ? new Item($r) : $r;

  }

  public function createShort($aShort) {
    $r =  ItemFactory_createShort($this->_cPtr, $aShort);
    return is_resource($r) ? new Item($r) : $r;

  }

  public function createString($aString) {
    $r =  ItemFactory_createString($this->_cPtr, $aString);
    return is_resource($r) ? new Item($r) : $r;

  }

  public function createTextNode($parent, $content) {
    $r =  ItemFactory_createTextNode($this->_cPtr, $parent, $content);
    return is_resource($r) ? new Item($r) : $r;

  }

  public function createTime($aHour_or_aValue, $aMinute=null, $aSecond=null, $aTimeZone_hours=null) {
    switch(func_num_args()) {
    case 1: $r =  ItemFactory_createTime($this->_cPtr, $aHour_or_aValue);break;
    case 2: $r =  ItemFactory_createTime($this->_cPtr, $aHour_or_aValue, $aMinute);break;
    case 3: $r =  ItemFactory_createTime($this->_cPtr, $aHour_or_aValue, $aMinute, $aSecond);break;
    case 4: $r =  ItemFactory_createTime($this->_cPtr, $aHour_or_aValue, $aMinute, $aSecond, $aTimeZone_hours);break;
    default: $r =  ItemFactory_createTime($this->_cPtr, $aHour_or_aValue, $aMinute, $aSecond, $aTimeZone_hours);
    }
    return is_resource($r) ? new Item($r) : $r;

  }

  public function createUnsignedByte($aValue) {
    $r =  ItemFactory_createUnsignedByte($this->_cPtr, $aValue);
    return is_resource($r) ? new Item($r) : $r;

  }

  public function createUnsignedInt($aValue) {
    $r =  ItemFactory_createUnsignedInt($this->_cPtr, $aValue);
    return is_resource($r) ? new Item($r) : $r;

  }

  public function createUnsignedLong($aValue) {
    $r =  ItemFactory_createUnsignedLong($this->_cPtr, $aValue);
    return is_resource($r) ? new Item($r) : $r;

  }

  public function createUnsignedShort($aValue) {
    $r =  ItemFactory_createUnsignedShort($this->_cPtr, $aValue);
    return is_resource($r) ? new Item($r) : $r;

  }

}
