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
  catch (zorba::QueryException& e) {
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
#include <simplestore/simplestore.h>
#include <string>
#include <sstream>
#include <iostream>
#include <zorba/exception.h>
#include <zorba/error_handler.h>
#include <zorba/options.h>

  class CompilerHints;
  class DynamicException;
  class ErrorHandler;
  class Item;
  class ResultIterator;
  class XQuery;
  class QueryException;
  class SystemException;
  class SerializationException;
  class StaticContext;
  class StaticException;
  class Store;
  class TypeException;
  class UserException;
  class Zorba;
  class ZorbaException;

  %}



%include "XQuery.i"
%include "Store.i"
%include "XmlDataManager.i"
%include "Exceptions.i"
%include "ErrorHandler.i"
%include "CompilerHints.i"
%include "StaticContext.i"
%include "Zorba.i"


