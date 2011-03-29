/*
 * Copyright 2006-2008 The FLWOR Foundation.
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
%include "std_string.i"
%include "exception.i"

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

%{  // Implementations

#include <zorba/zorba.h>
#include <zorba/store_manager.h>
#include <string>
#include <sstream>
#include <iostream>
#include <zorba/zorba_exception.h>
#include <zorba/error_handler.h>
#include <zorba/options.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/serializer.h>

  class CompilerHints;
  class ErrorHandler;
  class Item;
  class Iterator;
  class XQuery;
  class StaticContext;
  class Store;
  class Zorba;

  class DynamicException;
  class XQueryException;
  class SerializationException;
  class StaticException;
  class SystemException;
  class TypeException;
  class UserException;
  class ZorbaException;

  class URIResolverResult;
  class CollectionURIResolverResult;
  class DocumentURIResolverResult;
  class ModuleURIResolverResult;
  class SchemaURIResolverResult;
  class CollectionURIResolver;
  class DocumentURIResolver;
  class ModuleURIResolver;
  class SchemaURIResolver;
  %}



%include "XQuery.i"
%include "Store.i"
%include "XmlDataManager.i"
%include "Exceptions.i"
%include "ErrorHandler.i"
%include "CompilerHints.i"
%include "StaticContext.i"
%include "Resolvers.i"
%include "Zorba.i"


