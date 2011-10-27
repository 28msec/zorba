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
#pragma once
#ifndef ZORBA_DEBUGGER_COMMAND_ARG_H
#define ZORBA_DEBUGGER_COMMAND_ARG_H

#include <string>
#include <iostream>
#include <set>
#include <sstream>

#include "tuple.h"


namespace zorba { namespace debugger {

template<typename Tuple>
class CommandArg;

template<typename Tuple>
class CommandArgInstance {
  public:
    virtual int get_index() const = 0;
    virtual const CommandArg<Tuple>* get_arg() const = 0;
    virtual void insertValue(Tuple& t) = 0;
    virtual bool isSet(Tuple& t) const = 0;
};

template<typename T, int Idx, typename Tuple>
class TypedCommandArgInstance : public CommandArgInstance<Tuple>
{
  public:
    TypedCommandArgInstance(T aValue, const CommandArg<Tuple>* aArg)
      : theValue(aValue), theArg(aArg)
    {
    }

    virtual int
    get_index() const
    {
      return Idx;
    }

    virtual const CommandArg<Tuple>*
    get_arg() const
    {
      return theArg;
    }

    virtual void
    insertValue(Tuple& t)
    {
      ZORBA_TR1_NS::get<Idx>(t).first = true;
      ZORBA_TR1_NS::get<Idx>(t).second = theValue;
    }

    virtual bool isSet(Tuple& t) const
    {
      return ZORBA_TR1_NS::get<Idx>(t).first;
    }

  private:

    T theValue;
    const CommandArg<Tuple>* theArg;
};
  
template<typename Tuple>
class CommandArgType
{
  public:
    virtual CommandArgInstance<Tuple>*
    parse(
      const std::string& str,
      const CommandArg<Tuple>* arg) = 0;

    virtual bool
    isVoid() const = 0;
  
    virtual bool
    isSet(Tuple& t) const = 0;

    virtual ~CommandArgType() {}
};
  
  template<typename T, int Idx, typename Tuple>
  class TypedCommandArgType : public CommandArgType<Tuple> {
  public:
    typedef T Type;
  public: // implementation
    TypedCommandArgType(bool aIsVoid) : theIsVoid(aIsVoid) {}
    TypedCommandArgType(const T& aValue,
                        bool aIsVoid)
    : theDefault(aValue), theIsVoid(aIsVoid) {}
    virtual CommandArgInstance<Tuple>* parse(const std::string& str,
                                             const CommandArg<Tuple>* arg)
    {
      T aValue;
      std::stringstream stream(str);
      stream >> aValue;
      if (stream.fail()) {
        std::cerr << "Error: Could not parse value \"" << str << "\" as type "
          << typeid(T).name()
          << std::endl;
        return 0;
      }
      return new TypedCommandArgInstance<T, Idx, Tuple>(aValue, arg);
    }
    virtual bool isVoid() const { return theIsVoid; }
    virtual bool isSet(Tuple& t) const
    {
      return ZORBA_TR1_NS::get<Idx>(t).first;
    }
  private:
    TypedCommandArgType<T, Idx, Tuple>() {}
    T theDefault;
    bool theIsVoid;
  };

  template<typename Tuple>
  class CommandArg {
  public:
    CommandArg(unsigned aId,
               CommandArgType<Tuple>* aType,
               const std::set<std::string>& aNames,
               const std::string& aDescription,
               bool aIsRequired)
    : theId(aId),
    theType(aType),
    theNames(aNames),
    theDescription(aDescription),
    theIsRequired(aIsRequired)
    {
    }

    ~CommandArg()
    { 
      delete theType;
    }

    unsigned
    get_id() const
    {
      return theId;
    }

    bool
    canHandle(const std::string& arg) const
    {
      if (theNames.find(arg) != theNames.end()) {
        return true;
      }
      return false;
    }

    CommandArgInstance<Tuple>*
    parse(const std::string& str) const
    {
      return theType->parse(str, this);
    }

    bool
    isVoid() const
    {
      return theType->isVoid();
    }
    
    bool
    isRequired() const
    {
      return theIsRequired;
    }

    std::string
    get_name() const
    {
      return *(theNames.begin());
    }
    
    bool
    isSet(Tuple& t) const
    {
      return theType->isSet(t);
    }

  private:

    unsigned theId;
    CommandArgType<Tuple>* theType;
    std::set<std::string> theNames;
    std::string theDescription;
    bool theIsRequired;
  };

} // namespace zorba
} // namespace debugger

#endif // ZORBA_DEBUGGER_COMMAND_ARG_H
