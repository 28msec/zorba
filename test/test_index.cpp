

#include <zorba/zorba.h>
#include <simplestore/simplestore.h>

#include "zorbaerrors/errors.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/iterator_factory.h"
#include "store/api/index.h"

#include "store/naive/simple_store.h"
#include "store/naive/store_defs.h"

using namespace zorba;
using namespace zorba::store;


void parseKey(
    int argc,
    const char * argv[],
    int& arg,
    std::vector<long>& res,
    std::vector<bool>& incl)
{
  ulong numCols = atoi(argv[arg]);
  res.resize(numCols);
  incl.resize(numCols);
  arg++;
  ulong i;
  for (i = 0; i < numCols && arg < argc; i++, arg++)
  {
    res[i] = atoi(argv[arg]);

    arg++;

    if (*(argv[arg]) == 't')
    {
      incl[i] = true;
    }
    else if (*(argv[arg]) == 'f')
    {
      incl[i] = false;
    }
    else
    {
      std::cout << "bad usage" << std::endl;
      abort();
    }
  }

  if (i < numCols)
  {
    std::cout << "bad usage" << std::endl;
    abort();
  }
}


int main(int argc, const char * argv[])
{
  //
  // Store initialization
  //
  simplestore::SimpleStore* store = simplestore::SimpleStoreManager::getStore();

  store::ItemFactory* f = store->getItemFactory();
  store::IteratorFactory* iteFactory = store->getIteratorFactory();

  xqpStringStore_t uri(new xqpStringStore("test_index"));
   
  //
  // Create sorted index mapping a pair of integeres to an integer
  //
  ulong numKeyComps = 2;

  IndexSpecification spec;
  spec.theIsUnique = false;
  spec.theIsSorted = true;
  spec.theIsTemp = false;
  spec.theIsThreadSafe = false;
  spec.theTimezone = 0;
  spec.theCollations.resize(numKeyComps);

  spec.theKeyTypes.resize(numKeyComps);
  spec.theKeyTypes[0] = store->theSchemaTypeNames[simplestore::XS_INT];
  spec.theKeyTypes[0] = store->theSchemaTypeNames[simplestore::XS_INT];
  spec.theValueType = store->theSchemaTypeNames[simplestore::XS_INT];

  Index_t index = store->createIndex(uri, spec);

  //
  // Create items for all ints between 0 and N-1
  //
  //
  const ulong N = 100;
  Item_t ints[N];
  for (ulong i = 0; i < N; i++)
    f->createInt(ints[i], i);

  //
  // Populate the index
  //
  IndexKey key(2);
  Item_t value;

  key[0] = ints[30]; key[1] = ints[86]; value = ints[30];
  index->insert(key, value);

  key[0] = ints[40]; key[1] = ints[4]; value = ints[40];
  index->insert(key, value);

  key[0] = ints[50]; key[1] = ints[59]; value = ints[50];
  index->insert(key, value);

  key[0] = ints[40]; key[1] = ints[14]; value = ints[41];
  index->insert(key, value);

  //
  // Probe the index
  //
  std::vector<long> low_key;
  std::vector<long> high_key;
  std::vector<bool> low_incl;
  std::vector<bool> high_incl;

  int arg = 1;
  while (arg < argc)
  {
    if (strcmp(argv[arg], "-lk") == 0)
    {
      arg++;
      parseKey(argc, argv, arg, low_key, low_incl);
    }
    else if (strcmp(argv[arg], "-hk") == 0)
    {
      arg++;
      parseKey(argc, argv, arg, high_key, high_incl);
    }
    else
    {
      arg++;
    }
  }

  IndexProbeIterator* ite = iteFactory->createIndexProbeIterator(index);

  IndexKey* l_key = NULL;
  IndexKey* h_key = NULL;
  
  if (low_key.empty())
  {
    l_key = &IndexProbeIterator::theNegInfKey;
    low_incl.push_back(true);
  }
  else
  {
    l_key = new IndexKey(low_key.size());
    (*l_key)[0] = ints[low_key[0]];
  }

  if (high_key.empty())
  {
    h_key = &IndexProbeIterator::thePosInfKey;
    high_incl.push_back(true);
  }
  else
  {
    h_key = new IndexKey(high_key.size());
    (*h_key)[0] = ints[high_key[0]];
  }


  try
  {
    ite->init(*l_key, *h_key, low_incl[0], high_incl[0]);
    ite->open();

    std::cout << "Probing: low key =" << *l_key
              << " high key = " << *h_key << std::endl;
 
    store::Item* res = ite->next();
    while (res != NULL)
    {
      std::cout << res->getStringValue()->c_str() << std::endl;
      res = ite->next();
    }
  }
  catch(error::ZorbaError& e)
  {
    std::cout << e.theDescription << std::endl;
  }

  ite->close();
  delete ite;

  if (!low_key.empty())
    delete l_key;

  if (!high_key.empty())
    delete h_key;
  
  //
  // Shutdown
  //

  spec.clear();
  store->deleteIndex(uri);
  index = NULL;

  store->shutdown();
  return 0;

}



/*

  30  86  --> 30
  40   4  --> 40
  40  14  --> 41
  50  59  --> 50

 no args 

 -lk 1 10 t
 -lk 1 10 f
 -lk 1 30 t
 -lk 1 30 f
 -lk 1 31 t
 -lk 1 31 f
 -lk 1 40 t
 -lk 1 40 f
 -lk 1 50 t
 -lk 1 50 f
 -lk 1 60 t
 -lk 1 60 f

 -hk 1 10 t
 -hk 1 10 f
 -hk 1 30 t
 -hk 1 30 f
 -hk 1 40 t
 -hk 1 40 f
 -hk 1 49 t
 -hk 1 49 f
 -hk 1 50 t
 -hk 1 50 f
 -hk 1 60 t
 -hk 1 60 f


-lk 1 10 t -hk 1 10 t
-lk 1 10 t -hk 1 10 f
-lk 1 10 f -hk 1 10 t

-lk 1 10 f -hk 1 20 f
-lk 1 10 t -hk 1 20 t
-lk 1 10 f -hk 1 20 t
-lk 1 10 t -hk 1 20 f

-lk 1 10 f -hk 1 30 f
-lk 1 10 f -hk 1 30 t

-lk 1 30 t -hk 1 30 t

-lk 1 31 t -hk 1 33 t

-lk 1 32 t -hk 1 40 f
-lk 1 32 t -hk 1 40 t

-lk 1 40 t -hk 1 40 t

-lk 1 55 t -hk 1 60 f
-lk 1 55 t -hk 1 60 t
-lk 1 55 f -hk 1 60 f

 */
