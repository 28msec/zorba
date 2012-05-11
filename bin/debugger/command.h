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
#ifndef ZORBA_DEBUGGER_COMMAND_H
#define ZORBA_DEBUGGER_COMMAND_H

#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <sstream>
#include <memory>
#include <typeinfo>

#include <zorba/config.h>

#include "command_arg.h"
#include "tuple.h"


namespace zorba { namespace debugger {
  
  class DebugClientParseException : public std::exception {
  };
  
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
    virtual ~UntypedCommand() {}
    virtual std::string getName() const = 0;
    virtual std::set<std::string> getAliases() const = 0;
    virtual std::string getDescription() const = 0;
    virtual void printHelp() const = 0;
    virtual bool execute(const std::vector<std::string>& args) = 0;
  };
  
  template<typename Func, typename Tuple, int CommandIdx>
  class Command : public UntypedCommand {
  public:
    Command(const std::string& aName, Func& aFunction, const std::string& aDescription)
      : theName(aName), theFunction(aFunction), theDescription(aDescription)
    {}

    Command(const std::string& aName, const std::set<std::string> aAliases, Func& aFunction, const std::string& aDescription)
      : theName(aName), theAliases(aAliases), theFunction(aFunction), theDescription(aDescription)
    {}

    ~Command();

  public:

    void
    addArgument(
      unsigned aId,
      const std::string& aFlags,
      CommandArgType<Tuple>* aType,
      const std::string& aDescription = "",
      bool isRequired = false);

    static void
    splitNames(
      const std::string& names,
      std::set<std::string>& set);

    virtual std::string
    getName() const
    {
      return theName;
    }

    virtual std::set<std::string> getAliases() const
    {
      return theAliases;
    }

    virtual std::string
    getDescription() const
    {
      return theDescription;
    }

    virtual void
    printHelp() const;

    virtual bool execute(const std::vector<std::string>& args)
    {
      CommandInstance<Func, Tuple, CommandIdx> instance(theFunction, theTuple);
      if (instance.parseArguments(args, theArgs)) {
        instance.execute();
        return true;
      }
      return false;
    }
  private:
    std::string theName;
    std::set<std::string> theAliases;
    Func& theFunction;
    Tuple theTuple;
    std::string theDescription;
    std::map<std::string, CommandArg<Tuple>*> theArgs;
  };

/*****************************************************************************/
/*****************************************************************************/

template<typename Func, typename Tuple, int CommandIdx>
Command<Func, Tuple, CommandIdx>::~Command()
{
  typedef std::map<std::string, CommandArg<Tuple>*> ArgType;
  for (typename ArgType::iterator i = theArgs.begin(); i != theArgs.end(); ++i) {
    delete i->second;
  }
}

template<typename Func, typename Tuple, int CommandIdx>
void
Command<Func, Tuple, CommandIdx>::printHelp() const
{
  std::cout << "Purpose: " << getDescription() << std::endl;

  typename std::map<std::string, CommandArg<Tuple>*>::const_iterator lIter = theArgs.begin();
  if (lIter == theArgs.end()) {
    std::cout << "This command has no arguments." << std::endl;
    std::cout << std::endl;
    return;
  }
  
  std::cout << "Arguments:" << std::endl << std::endl;
  for (; lIter != theArgs.end(); ++lIter) {
    std::cout << "  " << lIter->first << "\t" << lIter->second->getDescription() << std::endl;
  }
  std::cout << std::endl;
}

template<typename Func, typename Tuple, int CommandIdx>
void
Command<Func, Tuple, CommandIdx>::splitNames(const std::string& aNames, std::set<std::string>& aSet)
{
  std::string::size_type before = 0;
  std::string::size_type pos = aNames.find(" ", 0);
  while (pos != aNames.npos) {
    std::string lName = aNames.substr(before, pos);
    if (lName != "") {
      aSet.insert(lName);
    }
    before = pos + 1;
    pos = aNames.find(" ", before);
  }
  std::string lName = aNames.substr(before);
  if (lName != "") {
    aSet.insert(lName);
  }
}

template<typename Func, typename Tuple, int CommandIdx>
void
Command<Func, Tuple, CommandIdx>::addArgument(
  unsigned aId,
  const std::string& aFlags,
  CommandArgType<Tuple>* aType,
  const std::string& aDescription,
  bool isRequired)
{
  std::set<std::string> lNames;
  splitNames(aFlags, lNames);

  for (std::set<std::string>::iterator i = lNames.begin(); i != lNames.end(); ++i) {
    std::string toAdd = (i->size() == 1) ? "-" + *i : "--" + *i;
    CommandArg<Tuple>* lArg = new CommandArg<Tuple>(aId, aType, lNames, aDescription, isRequired);
    theArgs.insert(std::make_pair(toAdd, lArg));
  }
}

/*****************************************************************************/

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
  
  template<int CommandIdx, typename Tuple, typename Func>
  Command<Func, Tuple, CommandIdx>* createCommand(Tuple t,
                                                  const std::string& aName,
                                                  const std::set<std::string>& aAliases,
                                                  Func& aFunction,
                                                  const std::string& aDescription)
  {
    return new Command<Func, Tuple, CommandIdx>(aName, aAliases, aFunction, aDescription);
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
        std::cerr << "Error: Unknown option " << args[i] << std::endl;
        parseError = true;
        return false;
      }
      const CommandArg<Tuple>& arg = *(pos->second);
      std::auto_ptr<CommandArgInstance<Tuple> > instance;
      if (arg.isVoid()) {
        instance.reset(arg.parse("1"));
      } else {
        ++i;
        if (i >= size) {
          std::cerr << "Error: Missing value for argument " << args[i - 1] << std::endl;
          parseError = true;
          allSet = false;
          return false;
        }
        instance.reset(arg.parse(args[i]));
      }
      if (instance.get()) {
        instance->insertValue(theTuple);
      }
    }
    bool allSet = true;
    for (typename CArgType::const_iterator i = aCommandArgs.begin();
         i != aCommandArgs.end(); ++i)
    {
      if (i->second->isRequired() && !i->second->isSet(theTuple)) {
        std::cerr << "Error: Argument -" << i->second->getName() << " not set" << std::endl;
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

} // namespace zorba
} // namespace debugger

#endif // ZORBA_DEBUGGER_COMMAND_H
