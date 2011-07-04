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
#include <zorba/config.h>
#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <sstream>
#include <memory>
#include <typeinfo>
#include "debug_client/tuple.h"

namespace zorba { namespace debugclient {
  
  class DebugClientParseException : public std::exception {
  };
  
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
    : theValue(aValue), theArg(aArg) {}
    virtual int get_index() const { return Idx; }
    virtual const CommandArg<Tuple>* get_arg() const { return theArg; }
    virtual void insertValue(Tuple& t)
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
  class CommandArgType {
  public:
    virtual CommandArgInstance<Tuple>* parse(const std::string& str,
                                             const CommandArg<Tuple>* arg) = 0;
    virtual bool isVoid() const = 0;
    virtual bool isSet(Tuple& t) const = 0;
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
        std::cerr << "Could not parse argument of type "
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
               const std::set<std::string>& aFlags,
               const std::string& aDescription,
               bool aIsRequired)
    : theId(aId),
    theType(aType),
    theFlags(aFlags),
    theDescription(aDescription),
    theIsRequired(aIsRequired)
    {
    }
    ~CommandArg() { delete theType; }
    unsigned get_id() const { return theId; }
    bool canHandle(const std::string& arg) const
    {
      if (theFlags.find(arg) != theFlags.end()) {
        return true;
      }
      return false;
    }
    CommandArgInstance<Tuple>* parse(const std::string& str) const
    {
      return theType->parse(str, this);
    }
    bool isVoid() const {
      return theType->isVoid();
    }
    bool isRequired() const { return theIsRequired; }
    std::string get_name() const {
      return *(theFlags.begin());
    }
    bool isSet(Tuple& t) const
    {
      return theType->isSet(t);
    }
  private:
    unsigned theId;
    CommandArgType<Tuple>* theType;
    std::set<std::string> theFlags;
    std::string theDescription;
    bool theIsRequired;
  };
}} // end namespace zorba

namespace std {
  
  /**
   * This is a helper split function
   */
  vector<string>& operator<< (vector<string>& vec, const string& str);
  
  set<string>& operator<< (set<string>& vec, const string& str);
} //end namespace std

namespace zorba { namespace debugclient {

  template<typename Func, typename Tuple, int CommandIdx>
  class CommandInstance
  {
  public:
    CommandInstance(Func& aFunction, Tuple aTuple)
    : theFunction(aFunction), theTuple(aTuple), allSet(false) {}
  public:
    virtual bool parseArguments(const std::vector<std::string>& args,
                                const std::map<std::string,
                                CommandArg<Tuple>* >& aCommandArgs);
    virtual void execute();
  private:
    Func& theFunction;
    Tuple theTuple;
    bool allSet;
    bool parseError;
  };
  
  class UntypedCommand {
  public:
    virtual std::string get_name() const = 0;
    virtual std::string get_description() const = 0;
    virtual bool execute(const std::vector<std::string>& args) = 0;
  };
  
  template<typename Func, typename Tuple, int CommandIdx>
  class Command : public UntypedCommand {
  public:
    Command(const std::string& aName, Func& aFunction, const std::string& aDescription)
      : theName(aName), theFunction(aFunction), theDescription(aDescription) {}
    ~Command();
  public:
    Command& operator() (unsigned aId,
                         const std::string& aFlags,
                         CommandArgType<Tuple>* aType,
                         const std::string& aDescription = "",
                         bool isRequired = false);
    virtual std::string get_name() const { return theName; }
    virtual std::string get_description() const { return theDescription; }
    virtual bool execute(const std::vector<std::string>& args)
    {
      CommandInstance<Func, Tuple, CommandIdx> instance(theFunction, theTuple);
      if (instance.parseArguments(args, theArgs))
        instance.execute();
      else
        return false;
      return true;
    }
  private:
    std::string theName;
    Func& theFunction;
    Tuple theTuple;
    std::string theDescription;
    std::map<std::string, CommandArg<Tuple>* > theArgs;
  };
  
  class CommandLine {
  public:
    ~CommandLine();
  public:
    void execute();
    CommandLine& operator<< (UntypedCommand* aCommand);
  private:
    std::map<std::string, UntypedCommand*> theCommands;
  };
  
  template<typename Func, typename Tuple, int CommandIdx>
  Command<Func, Tuple, CommandIdx>::~Command()
  {
    typedef std::map<std::string, CommandArg<Tuple>* > ArgType;
    for (typename ArgType::iterator i = theArgs.begin(); i != theArgs.end(); ++i) {
      delete i->second;
    }
  }
    
 
  template<typename Func, typename Tuple, int CommandIdx>
  Command<Func, Tuple, CommandIdx>& 
  Command<Func, Tuple, CommandIdx>::operator() (unsigned aId,
                                    const std::string& aFlags,
                                    CommandArgType<Tuple>* aType,
                                    const std::string& aDescription,
                                    bool isRequired)
  {
    std::set<std::string> args;
    args << aFlags;
    for (std::set<std::string>::iterator i = args.begin(); i != args.end(); ++i) {
      std::string toAdd = (i->size() == 1) ? "-" + *i : "--" + *i;
      theArgs.insert(std::make_pair(toAdd,
                                    new CommandArg<Tuple>(aId,
                                                          aType,
                                                          args,
                                                          aDescription,
                                                          isRequired)
                                    )
                     );
    }
    return *this;
  }
  
  template<typename Tuple, typename T, int Idx>
  CommandArgType<Tuple>* createArgType(Tuple t)
  {
    return new TypedCommandArgType<T, Idx, Tuple>(false);
  }
  
  template<typename Tuple, typename T, int Idx>
  CommandArgType<Tuple>* createArgType(Tuple t,
                                       const T& aDefault)
  {
    return new TypedCommandArgType<T, Idx, Tuple>(aDefault, false);
  }
  
  template<int CommandIdx, typename Tuple, typename Func>
  Command<Func, Tuple, CommandIdx>* createCommand(Tuple t,
                                                  const std::string& aName,
                                                  Func& aFunction,
                                                  const std::string& aDescription)
  {
    return new Command<Func, Tuple, CommandIdx>(aName, aFunction, aDescription);
  }
  
  template<typename Func, typename Tuple, int CommandIdx>
  bool CommandInstance<Func, Tuple, CommandIdx>::
  parseArguments(const std::vector<std::string>& args,
                 const std::map<std::string, CommandArg<Tuple>* >& aCommandArgs)
  {
    typedef std::vector<std::string> ArgType;
    typedef std::map<std::string, CommandArg<Tuple>* > CArgType;
    ArgType::size_type size = args.size();
    for (ArgType::size_type i = 1; i < size; ++i) {
      typename CArgType::const_iterator pos = aCommandArgs.find(args[i]);
      if (pos == aCommandArgs.end()) {
        std::cerr << "Error: Unknown Argument " << args[i] << std::endl;
        parseError = true;
        return false;
      }
      const CommandArg<Tuple>& arg = *(pos->second);
      if (!arg.isVoid() && args[++i][0] == '-') {
        std::cerr << "Did not expect parameter for option " << args[i] << std::endl;
        return false;
      }
      std::auto_ptr<CommandArgInstance<Tuple> > instance;
      if (arg.isVoid()) {
        instance.reset(arg.parse("1"));
      } else {
        instance.reset(arg.parse(args[i]));
      }
      instance->insertValue(theTuple);
    }
    bool allSet = true;
    for (typename CArgType::const_iterator i = aCommandArgs.begin();
         i != aCommandArgs.end(); ++i)
    {
      if (i->second->isRequired() && !i->second->isSet(theTuple)) {
        std::cerr << "Error: Argument " << i->second->get_name() << " not set" << std::endl;
        allSet = false;
      }
    }
    return allSet;
  }
  
  template<typename Func, typename Tuple, int CommandIdx>
  void CommandInstance<Func, Tuple, CommandIdx>::execute()
  {
    theFunction.template handle<CommandIdx>(this->theTuple);
  }

}} // end of namespace zorba::debugclient
