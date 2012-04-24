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

%module zorba_api
%module(directors="1") zorba_api


TSRMLS_FETCH(); 

%include "std_string.i"
%include "std_pair.i"
%include "exception.i"

#ifndef SWIGRUBY
%include "std_vector.i"
#endif

%exception {
  try {
    $action
  }
  catch (zorba::XQueryException& e) {
    std::stringstream lStream;
    lStream << e;
    SWIG_exception(SWIG_RuntimeError, lStream.str().c_str());
  }
  catch (zorba::ZorbaException& e) {
    std::stringstream lStream;
    lStream << e;
    SWIG_exception(SWIG_RuntimeError, lStream.str().c_str());
  }
}

#ifndef SWIGRUBY
namespace std {
  %template(StringPairVector) vector< pair<string, string> >;
  %template(StringPair) pair<string, string>;
  %template(StringVector) vector< string >;
}
#endif

%{  // Implementations


#include <string>
#include <sstream>
#include <zorba/zorba.h>
#include <zorba/store_manager.h>
#include <zorba/zorba_exception.h>
#include <zorba/diagnostic_handler.h>
#include <zorba/options.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/serializer.h>

  class CompilerHints;
  class DiagnosticHandler;
  class Store;
  class Zorba;
  class Iterator;

  class DynamicException;
  class DocumentManager;
  class XQueryException;
  class SerializationException;
  class StaticException;
  class SystemException;
  class TypeException;
  class UserException;
  class ZorbaException;
  class XmlDataManager;

  #include "SerializationOptions.h"
  #include "TypeIdentifier.h"
  #include "Item.h"
  #include "Iterator.h"
  #include "DynamicContext.h"
  #include "StaticContext.h"
  #include "XQuery.h"
  #include "ItemFactory.h"
  #include "Zorba.h"
  #include "ItemSequence.h"
  #include "Collection.h"
  #include "CollectionManager.h"
  #include "DocumentManager.h"
  #include "XmlDataManager.h"
%}

#ifndef SWIGRUBY
namespace std {
  %template(ItemVector) vector<Item>; 
}
#endif

/* %include "various.i" required for mapping to Java byte[]*/

//%include "ZorbaStreamProxy.i"
%include "SerializationOptions.i"
%include "TypeIdentifier.i"
%include "Item.i"
%include "Iterator.i"
%include "DynamicContext.i"
%include "CompilerHints.i"
%include "StaticContext.i"
%include "XQuery.i"
%include "Store.i"
%include "Exceptions.i"
%include "DiagnosticHandler.i"
%include "Zorba.i"
%include "ItemFactory.i"
%include "ItemSequence.i"
%include "Collection.i"
%include "CollectionManager.i"
%include "DocumentManager.i"
%include "XmlDataManager.i"
