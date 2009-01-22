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

#include <vector>
#include <iostream>
#include <sstream>

#include <zorba/zorba.h>
#include <zorba/external_function.h>
#include <simplestore/simplestore.h>


using namespace zorba;

class MySimpleExternalFunction : public StatelessExternalFunction
{
  public:
    virtual String
    getURI() const { return "urn:foo"; }

    virtual String
    getLocalName() const { return "bar"; }

    virtual ItemSequence_t 
    evaluate(const StatelessExternalFunction::Arguments_t& args) const 
    {
        iv_t vec;
        for(int i = 0; i < 2; ++i) {
            ItemSequence* iseq = args[i];
            Item lItem;
            while(iseq->next(lItem)) {
                vec.push_back(lItem);
            }
        }
        // transfer ownership of the IteratorBackedItemSequence to Zorba (using an auto_ptr)
        return ItemSequence_t(new IteratorBackedItemSequence(vec));
    }

  private:
    typedef std::vector<Item> iv_t;
    typedef iv_t::iterator ii_t;

    class IteratorBackedItemSequence : public ItemSequence {
        public:
            IteratorBackedItemSequence(iv_t& vec)
                : m_vec(vec),
                m_i(m_vec.begin()),
                m_end(m_vec.end()) { }

            bool next(Item& val)
            {
                if (m_i == m_end) {
                    return false;
                }
                val = *m_i;
                ++m_i;
                return true;
            }

        private:
            iv_t m_vec;
            ii_t m_i;
            ii_t m_end;
    };
};

class MyLazySimpleExternalFunction : public StatelessExternalFunction
{
  public:
    virtual String
    getURI() const { return "urn:foo"; }

    virtual String
    getLocalName() const { return "bar2"; }

    virtual ItemSequence_t 
    evaluate(const StatelessExternalFunction::Arguments_t& args) const 
    {
        // transfer ownership of the IteratorBackedItemSequence to Zorba (using an auto_ptr)
        return ItemSequence_t(new LazyConcatItemSequence(args));
    }

  private:
    class LazyConcatItemSequence : public ItemSequence {
        public:
            LazyConcatItemSequence(const StatelessExternalFunction::Arguments_t& args)
                : m_args(args),
                m_i(0) { }

            bool next(Item& i)
            {
                while(m_i < m_args.size() && !m_args[m_i]->next(i)) {
                    ++m_i;
                }
                return !i.isNull();
            }
        private:
            StatelessExternalFunction::Arguments_t m_args;
            size_t m_i;
    };
};

bool
func_example_1(Zorba* aZorba)
{
	StaticContext_t sctx = aZorba->createStaticContext();

  MySimpleExternalFunction lFunc;
  sctx->registerStatelessExternalFunction(&lFunc);

	XQuery_t lQuery = aZorba->compileQuery("declare namespace foo=\"urn:foo\"; declare function foo:bar($a1, $a2) external; foo:bar((1,2,3), (4,5,6))", sctx); 

  std::cout << lQuery << std::endl;

	return true;
}

bool
func_example_2(Zorba* aZorba)
{
  try {
    StaticContext_t lContext = aZorba->createStaticContext();

    MySimpleExternalFunction lFunc;
    
    lContext->registerStatelessExternalFunction(&lFunc);
    lContext->registerStatelessExternalFunction(&lFunc); // only allowed to register it once

  } catch (ZorbaException &e) {
    std::cerr << "some exception " << e << std::endl;
    return true;
  }

	return false;
}

bool 
func_example_3(Zorba* aZorba)
{
  StaticContext_t lContext = aZorba->createStaticContext();

  MyLazySimpleExternalFunction lFunc;
  
  lContext->registerStatelessExternalFunction(&lFunc);

	XQuery_t lQuery = aZorba->compileQuery("declare namespace foo=\"urn:foo\"; declare function foo:bar2($a1, $a2) external; foo:bar2((1,2,3), (4,5,6))", lContext); 

  std::cout << lQuery << std::endl;

	return true;
}

bool
func_example_4(Zorba* aZorba)
{
	StaticContext_t lContext = aZorba->createStaticContext();

  MyLazySimpleExternalFunction lFunc;
  
  lContext->registerStatelessExternalFunction(&lFunc);

	XQuery_t lQuery = aZorba->compileQuery("declare namespace foo=\"urn:foo\"; declare function foo:bar2($a1, $a2) external; let $s1 := (1,2,3) let $s2 := (4,5,6) for $x in 1 to 6 return (foo:bar2($s1, $s2)[7-$x])", lContext); 

  std::cout << lQuery << std::endl;

	return true;
}

class MyErrorReportingExternalFunction : public StatelessExternalFunction
{
  public:
    virtual String
    getURI() const { return "urn:foo"; }

    virtual String
    getLocalName() const { return "bar3"; }

    virtual ItemSequence_t 
    evaluate(const StatelessExternalFunction::Arguments_t& args) const 
    {
        // transfer ownership of the IteratorBackedItemSequence to Zorba (using an auto_ptr)
        return ItemSequence_t(new LazyErrorReportingItemSequence(this, args));
    }

  private:
    class LazyErrorReportingItemSequence : public ItemSequence {
      public:
          LazyErrorReportingItemSequence(const MyErrorReportingExternalFunction* func, const StatelessExternalFunction::Arguments_t& args)
              : m_func(func),
              m_args(args),
              m_i(0) { }

          bool next(Item& i)
          {
             if (!m_args[0]->next(i)) {
              throw createZorbaException(XPTY0004, "First argument must not be the empty sequence.", __FILE__, __LINE__);
             }
             return true;
          }
      private:
          const MyErrorReportingExternalFunction* m_func;
          StatelessExternalFunction::Arguments_t  m_args;
          size_t m_i;
    };
};

bool
func_example_5(Zorba* aZorba)
{
	StaticContext_t lContext = aZorba->createStaticContext();

  MyErrorReportingExternalFunction lFunc;
  
  lContext->registerStatelessExternalFunction(&lFunc);

  std::ostringstream lQueryStream;
  lQueryStream << "declare namespace foo=\"urn:foo\";" << std::endl
               << "declare function foo:bar3($a1) external;" << std::endl
               << "let $s1 := ()" << std::endl
               << "for $x in 1 to 6 return (foo:bar3($s1))" << std::endl;
    
	XQuery_t lQuery = aZorba->compileQuery(lQueryStream.str(), lContext); 

  try {
    std::cout << lQuery << std::endl;
  } catch (TypeException& te) {
    std::cerr << te << std::endl;
    return true;
  } catch (ZorbaException& ex) {
    std::cerr << ex << std::endl;
    return false; // type exception expected
  }

	return false;
}
int 
external_functions(int argc, char* argv[])
{
  simplestore::SimpleStore* lStore = simplestore::SimpleStoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore);
  bool res = false;

  std::cout << std::endl  << "executing simple external function test 1" << std::endl;
  res = func_example_1(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << std::endl  << "executing simple external function test 2" << std::endl;
  res = func_example_2(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << std::endl  << "executing simple external function test 3" << std::endl;
  res = func_example_3(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << std::endl  << "executing simple external function test 4" << std::endl;
  res = func_example_4(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << std::endl  << "executing simple external function test 5" << std::endl;
  res = func_example_5(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;
  
  lZorba->shutdown();
  simplestore::SimpleStoreManager::shutdownStore(lStore);
  return 0;
}
