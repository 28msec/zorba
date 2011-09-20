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

#include <iostream>
#include <sstream>
#include <assert.h>

#include <zorba/zorba.h>
#include <zorba/external_module.h>
#include <zorba/iterator.h>
#include <zorba/function.h>
#include <zorba/serialization_callback.h>
#include <zorba/store_manager.h>
#include <zorba/zorba_exception.h>

using namespace zorba;

bool
execution_plan_example_1(Zorba* aZorba)
{
  // the stringstream used for query materialization
  std::stringstream lExecutionPlan;

  // materialize a compiled query to a binary format
  {
    XQuery_t lQuery = aZorba->compileQuery("1+2"); 
    lQuery->saveExecutionPlan(lExecutionPlan, ZORBA_USE_BINARY_ARCHIVE);
    std::cout << lQuery << std::endl;
  }

  // read a compiled query from an input stream
  // and execute it
  {
    XQuery_t lQuery = aZorba->createQuery();
    lQuery->loadExecutionPlan(lExecutionPlan);
    std::cout << lQuery << std::endl;
  }

	return true;
}

class MySerializableExternalFunction : public NonContextualExternalFunction
{
  protected:
    const ExternalModule* theModule;

  public:
    MySerializableExternalFunction(const ExternalModule* aModule)
      : theModule(aModule) {}

    virtual String
    getURI() const { return theModule->getURI(); }

    virtual String
    getLocalName() const { return "bar1"; }

    virtual ItemSequence_t 
    evaluate(const ExternalFunction::Arguments_t& args) const
    {
        iv_t vec;
        for(int i = 0; i < 2; ++i) {
            Item lItem;
            Iterator_t iter = args[i]->getIterator();
            iter->open();
            while(iter->next(lItem)) {
                vec.push_back(lItem);
            }
            iter->close();
        }
        // transfer ownership of the IteratorBackedItemSequence to Zorba (using an auto_ptr)
        return ItemSequence_t(new IteratorBackedItemSequence(vec));
    }

  private:
    typedef std::vector<Item> iv_t;
    typedef iv_t::iterator ii_t;

    class IteratorBackedItemSequence : public ItemSequence {
          class InternalIterator : public Iterator
          {
          private:
            IteratorBackedItemSequence   *theItemSequence;
            ii_t m_i;
            ii_t m_end;
            bool is_open;
          public:
            InternalIterator(IteratorBackedItemSequence *item_sequence) : theItemSequence(item_sequence), is_open(false)
            {
            }

            virtual void open()
            {
              m_i = theItemSequence->m_vec.begin();
              m_end = theItemSequence->m_vec.end();
              is_open = true;
            }
            virtual void close()
            {
              is_open = false;
            }
            virtual bool isOpen() const
            {
              return is_open;
            }
            bool next(Item& val)
            {
              assert(is_open);
              if (m_i == m_end) {
                  return false;
              }
              val = *m_i;
              ++m_i;
              return true;
            }
          };
        public:
            IteratorBackedItemSequence(iv_t& vec)
                : m_vec(vec)
                 { }

            Iterator_t  getIterator() {return new InternalIterator(this);}
        private:
            iv_t m_vec;
    };
};

class MySerializableExternalModule : public ExternalModule
{
  protected:
    MySerializableExternalFunction* bar1;

  public:
    MySerializableExternalModule()
      : bar1(0) {}

    virtual ~MySerializableExternalModule()
    {
      delete bar1;
    }

    virtual String
    getURI() const { return "urn:foo"; }

    virtual ExternalFunction*
    getExternalFunction(const String& aLocalname)
    {
      if (aLocalname == "bar1") {
        if (!bar1) {
          bar1 = new MySerializableExternalFunction(this);
        } 
        return bar1;
      }
      return 0;
    }
};

class MySerializationCallback : public SerializationCallback 
{
protected:
  ExternalModule* theModule;

public:
  MySerializationCallback(ExternalModule* aModule)
    : theModule(aModule) {}

  ExternalModule*
  getExternalModule(const String& aURI) const { return theModule; }
};

bool
execution_plan_example_2(Zorba* aZorba)
{
  // the stringstream used for query materialization
  std::stringstream lExecutionPlan;

  MySerializableExternalModule lModule;

  {
    // materialize a compiled query to a binary format
    StaticContext_t sctx = aZorba->createStaticContext();
    sctx->registerModule(&lModule);

    std::ostringstream lText;
    lText << "declare namespace foo=\"urn:foo\";" << std::endl
      << "declare function foo:bar1($a1, $a2) external;" << std::endl
      << "foo:bar1((1,2,3), (4,5,6))" << std::endl;

    XQuery_t lQuery = aZorba->compileQuery(lText.str(), sctx); 

    lQuery->saveExecutionPlan(lExecutionPlan, ZORBA_USE_BINARY_ARCHIVE);

    std::cout << lQuery << std::endl;
  }

  // read a compiled query from an input stream
  // and execute it
  {
    MySerializationCallback lCallback(&lModule);

    XQuery_t lQuery = aZorba->createQuery();
    lQuery->loadExecutionPlan(lExecutionPlan, &lCallback);

    std::cout << lQuery << std::endl;
  }

	return true;
}

bool 
execution_plan_example_3(Zorba* aZorba)
{
  // the stringstream used for query materialization
  std::stringstream lExecutionPlan;

  {
    MySerializableExternalModule lModule;
    // materialize a compiled query to a binary format
    StaticContext_t sctx = aZorba->createStaticContext();
    sctx->registerModule(&lModule);

    std::ostringstream lText;
    lText << "declare namespace foo=\"urn:foo\";" << std::endl
      << "declare function foo:bar1($a1, $a2) external;" << std::endl
      << "foo:bar1((1,2,3), (4,5,6))" << std::endl;

    XQuery_t lQuery = aZorba->compileQuery(lText.str(), sctx); 

    lQuery->saveExecutionPlan(lExecutionPlan, ZORBA_USE_BINARY_ARCHIVE);

    std::cout << lQuery << std::endl;
  }

  // read a compiled query from an input stream
  // but forgot to register a SerializationCallback
  try {
    XQuery_t lQuery = aZorba->createQuery();
    lQuery->loadExecutionPlan(lExecutionPlan);

    std::cout << lQuery << std::endl;
  } catch (ZorbaException &e) {
    std::cerr << e << std::endl;
    return true;
  }

	return false;
}

int
execution_plans(int argc, char* argv[])
{
  void* lStore = zorba::StoreManager::getStore();
  Zorba *lZorba = Zorba::getInstance(lStore);

  bool res = false;

  std::cout << "executing example 1" << std::endl;
  res = execution_plan_example_1(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << "executing example 2" << std::endl;
  res = execution_plan_example_2(lZorba);
  if (!res) return 2; 
  std::cout << std::endl;

  std::cout << "executing example 3" << std::endl;
  res = execution_plan_example_3(lZorba);
  if (!res) return 3; 
  std::cout << std::endl;

  lZorba->shutdown();
  zorba::StoreManager::shutdownStore(lStore);
  return 0;
}


