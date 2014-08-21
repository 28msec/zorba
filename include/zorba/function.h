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
#ifndef ZORBA_FUNCTION_API_H
#define ZORBA_FUNCTION_API_H

#include <cstddef>
#include <cassert>
#include <string>
#include <vector>
#include <map>

#include <zorba/config.h>
#include <zorba/item.h>
#include <zorba/api_shared_types.h>
#include <zorba/util/smart_ptr.h>

namespace zorba {

class ItemSequence;


/**************************************************************************//**
  The Function class represents a function that is callable from XQuery code,
  and it gives access to the various properties that are specified in the
  declaration of the function within a Prolog.

  Instances of Function are returned by the StaticContext::findFunctions()
  method. To be mopre precise, StaticContext::findFunctions() returns smart
  pointers to Function objects. These smart pointers must be destroyed before
  the StaticContext object they were obtained from is destroyed.

  Note: Builtin functions are not declared in the Prolog, but the same kind of
  properties exist for them as well. So, the Function class works for builtin
  functions as well.
*******************************************************************************/
class ZORBA_DLL_PUBLIC Function : public SmartObject
{
 public:
  /**
   * @return True if the function is sequential; false otherwise.
   */
  virtual bool
  isSequential() const = 0;

  /**
   * @return True if the function is updating; false otherwise.
   */
  virtual bool
  isUpdating() const = 0;

  /**
   * @return True if the function is private; false otherwise.
   */
  virtual bool
  isPrivate() const = 0;

  /**
   * @return True if the function is deterministic; false otherwise.
   */
  virtual bool
  isDeterministic() const = 0;

  /**
   *
   */
  virtual void
  getAnnotations(std::vector<Annotation_t>& annotations) const = 0;

  /**
   * @return The expanded QName of the function
   */
  virtual Item
  getQName() const = 0;

  /**
   * @return The namespace URI of the function QName
   */
  virtual String
  getURI() const = 0;

  /**
   * @return The local name of the function QName
   */
  virtual String
  getLocalName() const = 0;

  /**
   * @return The arity of the function. If the function is variadic (which is
   *         possible only for builtin functions), the result of this method
   *         is non-deterministic.
   */
  virtual size_t
  getArity() const = 0;

  /**
   * @return True if the function is variadic; false otherwise
   */
  virtual bool
  isVariadic() const = 0;

  /**
   * @return True if the function is an external one; false otherwise
   */
  virtual bool
  isExternal() const = 0;

  /**
   * @return True if the function implementation is written in XQuery (or
   *         equivalently, it is a non-external function with a Prolog
   *         declaration); false otherwise
   */
  virtual bool
  isXQuery() const = 0;

  /**
   * @return True if the function is a builtin one (not declared in any prolog);
   *         false otherwise
   */
  virtual bool
  isBuiltin() const = 0;
};


typedef std::map<std::string, Item> ProfileDataMap;


/**************************************************************************//**
  The ExternalFunction class serves as the base of subclasses that represent
  the implementation/body of external functions.

  Instances of ExternalFunction must provide an evaluate method that serves
  as the implementation of the function. During its evaluation, an external
  function may or may not need to access the static and/or dynamic context of
  the invoking XQuery module. If the function implementation does need to
  access either context, the function is referred to as "contextual"; otherwise,
  it is "non-contextual".
*******************************************************************************/
class ZORBA_DLL_PUBLIC ExternalFunction
{
public:
  typedef std::vector<ItemSequence*> Arguments_t;

  virtual ~ExternalFunction();

  /**
   * @return The namespace URI of the function QName
   */
  virtual String
  getURI() const = 0;

  /**
   * @return The local name of the function QName
   */
  virtual String
  getLocalName() const = 0;

  /**
   * @return True if the external function is contextual; false otherwise.
   */
  virtual bool
  isContextual() const = 0;

  virtual ProfileDataMap* getProfilingData() const { return NULL; }

protected:
  Item
  getItem( Arguments_t const &args, unsigned pos ) const;
};


/**************************************************************************//**
  The NonContextualExternalFunction class serves as the base of subclasses that
  represent the implementation of non contextual external functions.

  For each external function, an application must provide a concrete subclass
  of this class and "store" an instance of the subclass inside an ExternalModule
  object, as described <a href="../zorba/external_functions.html">
  here</a>.
*******************************************************************************/
class ZORBA_DLL_PUBLIC NonContextualExternalFunction : public ExternalFunction
{
 public:
  virtual ItemSequence_t
  evaluate(const Arguments_t&) const = 0;

  bool
  isContextual() const { return false; }
};


/**************************************************************************//**
  The ContextualExternalFunction class serves as the base of subclasses that
  represent the implementation of contextual external functions.

  For each external function, an application must provide a concrete subclass
  of this class and "store" an instance of the subclass inside an ExternalModule
  object, as described <a href="../zorba/external_functions.html">
  here</a>.
*******************************************************************************/
class ZORBA_DLL_PUBLIC ContextualExternalFunction : public ExternalFunction
{
 public:
  virtual ItemSequence_t
  evaluate(
      const Arguments_t&,
      const StaticContext*,
      const DynamicContext*) const = 0;

  bool
  isContextual() const { return true; }
};


} /* namespace zorba */
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
