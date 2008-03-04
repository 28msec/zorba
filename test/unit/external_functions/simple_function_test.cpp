#include <vector>
#include <iostream>
#include "zorba/zorba_singlethread.h"
#include "zorba/external_function.h"

using namespace zorba;


class MySimpleExternalFunction : public StatelessExternalFunction
{
  public:
    virtual xqp_string
    getURI() const { return "urn:foo"; }

    virtual xqp_string
    getLocalName() const { return "bar"; }

    virtual ItemSequence_t 
    evaluate(const StatelessExternalFunction::Arguments_t& args) const 
    {
        iv_t vec;
        for(int i = 0; i < 2; ++i) {
            ItemSequence_t iseq = args[i];
            Item_t lItem;
            while((lItem = iseq->next()) != NULL) {
                vec.push_back(lItem);
            }
        }
        return new IteratorBackedItemSequence(vec);
    }

  private:
    typedef std::vector<Item_t> iv_t;
    typedef iv_t::iterator ii_t;

    class IteratorBackedItemSequence : public ItemSequence {
        public:
            IteratorBackedItemSequence(iv_t& vec)
                : m_vec(vec),
                m_i(m_vec.begin()),
                m_end(m_vec.end()) { }

            Item_t next()
            {
                if (m_i == m_end) {
                    return NULL;
                }
                Item_t val = *m_i;
                ++m_i;
                return val;
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
    virtual xqp_string
    getURI() const { return "urn:foo"; }

    virtual xqp_string
    getLocalName() const { return "bar2"; }

    virtual ItemSequence_t 
    evaluate(const StatelessExternalFunction::Arguments_t& args) const 
    {
        return new LazyConcatItemSequence(args);
    }

  private:
    class LazyConcatItemSequence : public ItemSequence {
        public:
            LazyConcatItemSequence(const StatelessExternalFunction::Arguments_t& args)
                : m_args(args),
                m_i(0) { }

            Item_t next()
            {
                Item_t i = NULL;
                while(m_i < m_args.size() && (i = m_args[m_i]->next()) == NULL) {
                    ++m_i;
                }
                return i;
            }
        private:
            StatelessExternalFunction::Arguments_t m_args;
            int m_i;
    };
};

bool
test_1()
{
	ZorbaSingleThread_t  zorba_factory = ZorbaSingleThread::getInstance();

	StaticQueryContext_t sctx = zorba_factory->createStaticContext();
  sctx->registerStatelessExternalFunction(new MySimpleExternalFunction());

	XQuery_t lQuery = zorba_factory->createQuery("declare namespace foo=\"urn:foo\"; declare function foo:bar($a1, $a2) external; foo:bar((1,2,3), (4,5,6))", sctx); 

	lQuery->initExecution();
  lQuery->serializeXML(std::cout);

	return true;
}

bool
test_2()
{
	ZorbaSingleThread_t  zorba_factory = ZorbaSingleThread::getInstance();

  try {
    StaticQueryContext_t sctx = zorba_factory->createStaticContext();
    sctx->registerStatelessExternalFunction(new MySimpleExternalFunction());
    sctx->registerStatelessExternalFunction(new MySimpleExternalFunction());
  } catch (ZorbaException &x)
  {
    return true;
  }

	return false;
}

bool test_3()
{
	ZorbaSingleThread_t  zorba_factory = ZorbaSingleThread::getInstance();

	StaticQueryContext_t sctx = zorba_factory->createStaticContext();
  sctx->registerStatelessExternalFunction(new MyLazySimpleExternalFunction());

	XQuery_t lQuery = zorba_factory->createQuery("declare namespace foo=\"urn:foo\"; declare function foo:bar2($a1, $a2) external; foo:bar2((1,2,3), (4,5,6))", sctx); 

	lQuery->initExecution();
  lQuery->serializeXML(std::cout);

	return true;
}

bool test_4()
{
	ZorbaSingleThread_t  zorba_factory = ZorbaSingleThread::getInstance();

	StaticQueryContext_t sctx = zorba_factory->createStaticContext();
  sctx->registerStatelessExternalFunction(new MyLazySimpleExternalFunction());

	XQuery_t lQuery = zorba_factory->createQuery("declare namespace foo=\"urn:foo\"; declare function foo:bar2($a1, $a2) external; let $s1 := (1,2,3) let $s2 := (4,5,6) for $x in 1 to 6 return (foo:bar2($s1, $s2)[7-$x])", sctx); 

	lQuery->initExecution();
  lQuery->serializeXML(std::cout);

	return true;
}

int simple_function_test(int argc, char* argv[])
{
  std::cout << std::endl  << "executing simple external function test 1" << std::endl;
	assert(test_1()); 
  std::cout << std::endl;

  std::cout << std::endl  << "executing simple external function test 2" << std::endl;
	assert(test_2()); 
  std::cout << std::endl;

  std::cout << std::endl  << "executing simple external function test 3" << std::endl;
	assert(test_3()); 
  std::cout << std::endl;

  std::cout << std::endl  << "executing simple external function test 4" << std::endl;
	assert(test_4()); 
  std::cout << std::endl;
  return 0;
}
