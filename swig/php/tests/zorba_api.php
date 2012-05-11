<?php
/*
 * Copyright 2006-2012 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// Try to load our extension if it's not already loaded.
if (!extension_loaded("zorba_api")) {
  if (strtolower(substr(PHP_OS, 0, 3)) === 'win') {
    if (!dl('zorba_api.dll')) return;
  } else {
    // PHP_SHLIB_SUFFIX is available as of PHP 4.3.0, for older PHP assume 'so'.
    // It gives 'dylib' on MacOS X which is for libraries, modules are 'so'.
    if (PHP_SHLIB_SUFFIX === 'PHP_SHLIB_SUFFIX' || PHP_SHLIB_SUFFIX === 'dylib') {
      if (!dl('zorba_api.so')) return;
    } else {
      if (!dl('zorba_api.'.PHP_SHLIB_SUFFIX)) return;
    }
  }
}

class Item {
  public $_cPtr=null;

  static function createEmptyItem() {
    $r=Item_createEmptyItem();
    return is_resource($r) ? new Item($r) : $r;
  }

  function getStringValue() {
    return Item_getStringValue($this->_cPtr);
  }

  function __construct() {
    $this->_cPtr=new_Item();
  }
}

class Iterator {
  public $_cPtr=null;

  function open() {
    Iterator_open($this->_cPtr);
  }

  function next($arg1) {
    return Iterator_next($this->_cPtr,$arg1);
  }

  function close() {
    Iterator_close($this->_cPtr);
  }

  function destroy() {
    Iterator_destroy($this->_cPtr);
  }

  function __construct($cPtr) {
    $this->_cPtr=$cPtr;
  }

  public function __destruct() {
    $this->destroy();
  }
}

class XQuery {
  public $_cPtr=null;

  function execute() {
    return XQuery_execute($this->_cPtr);
  }

  function isUpdateQuery() {
    return XQuery_isUpdateQuery($this->_cPtr);
  }

  function applyUpdates() {
    XQuery_applyUpdates($this->_cPtr);
  }

  function destroy() {
    XQuery_destroy($this->_cPtr);
  }

  function iterator() {
    $r=XQuery_iterator($this->_cPtr);
    return is_resource($r) ? new Iterator($r) : $r;
  }

  function __construct($cPtr) {
    $this->_cPtr=$cPtr;
  }

  function __destruct() {
    $this->destroy();
  }
}

class Store {
  //public $_cPtr=null;

  //function __construct() {
  //  $this->_cPtr=new_Store();
  //}
}

class InMemoryStore extends Store {
  public $_cPtr=null;

  static function getInstance() {
    $r=InMemoryStore_getInstance();
    return is_resource($r) ? new InMemoryStore($r) : $r;
  }

  static function shutdown($arg1) {
    InMemoryStore_shutdown($arg1);
  }

  private function __construct($cPtr) {
    $this->_cPtr=$cPtr;
  }
}

class XmlDataManager {
  public $_cPtr=null;

  function loadDocument($aName,$aContent) {
    XmlDataManager_loadDocument($this->_cPtr,$aName,$aContent);
  }

  function deleteDocument($aName) {
    return XmlDataManager_deleteDocument($this->_cPtr,$aName);
  }

  function __construct($cPtr) {
    $this->_cPtr=$cPtr;
  }
}

class Zorba {
  public $_cPtr=null;

  static function getInstance($arg1) {
    $r=Zorba_getInstance($arg1->_cPtr);
    return is_resource($r) ? new Zorba($r) : $r;
  }

  function compileQuery($aStr) {
    $r=Zorba_compileQuery($this->_cPtr,$aStr);
    return is_resource($r) ? new XQuery($r) : $r;
  }

  function getXmlDataManager() {
    $r=Zorba_getXmlDataManager($this->_cPtr);
    return is_resource($r) ? new XmlDataManager($r) : $r;
  }

  function shutdown() {
    Zorba_shutdown($this->_cPtr);
  }

  private function __construct($cPtr) {
    $this->_cPtr=$cPtr;
  }
}
?>
