

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
    std::vector<bool>& incl,
    std::vector<bool>& inf)
{
  ulong numCols = atoi(argv[arg]);
  res.resize(numCols);
  incl.resize(numCols);
  inf.resize(numCols);

  arg++;
  ulong i;
  for (i = 0; i < numCols && arg < argc; i++, arg++)
  {
    if (strcmp(argv[arg], "inf") == 0)
    {
      inf[i] = true;
      incl[i] = false;
    }
    else
    {
      res[i] = atoi(argv[arg]);
      inf[i] = false;

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

  //
  // Parse args
  //
  std::vector<long> low_key;
  std::vector<bool> low_incl;
  std::vector<bool> low_inf;
  std::vector<long> high_key;
  std::vector<bool> high_incl;
  std::vector<bool> high_inf;

  int arg = 1;
  while (arg < argc)
  {
    if (strcmp(argv[arg], "-lk") == 0)
    {
      arg++;
      parseKey(argc, argv, arg, low_key, low_incl, low_inf);
    }
    else if (strcmp(argv[arg], "-hk") == 0)
    {
      arg++;
      parseKey(argc, argv, arg, high_key, high_incl, high_inf);
    }
    else
    {
      arg++;
    }
  }

  ulong high_size = high_key.size();
  ulong low_size = low_key.size();

  if (low_size < high_size)
  {
    low_key.resize(high_size);
    low_incl.resize(high_size);
    low_inf.resize(high_size);

    for (ulong i = low_size; i < high_size; i++)
    {
      low_incl[i] = false;
      low_inf[i] = true;
    }
  }
  else if (low_key.size() > high_key.size())
  {
    high_key.resize(low_size);
    high_incl.resize(low_size);
    high_inf.resize(low_size);

    for (ulong i = high_size; i < low_size; i++)
    {
      high_incl[i] = false;
      high_inf[i] = true;
    }
  }

  //
  // Create sorted index mapping a pair of integeres to an integer
  //
  ulong numKeyComps = 2;

  IndexSpecification spec(numKeyComps);
  spec.theIsUnique = false;
  spec.theIsSorted = true;
  spec.theIsTemp = false;
  spec.theIsThreadSafe = false;
  spec.theTimezone = 0;

  spec.theKeyTypes[0] = store->theSchemaTypeNames[simplestore::XS_INT];
  spec.theKeyTypes[0] = store->theSchemaTypeNames[simplestore::XS_INT];
  spec.theValueType = store->theSchemaTypeNames[simplestore::XS_INT];

  xqpStringStore_t uri(new xqpStringStore("test_index"));

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
  IndexProbeIterator* ite = iteFactory->createIndexProbeIterator(index);

  IndexBoxCondition_t cond = index->createBoxCondition();

  if (low_key.empty())
  {
    Item_t v = ints[0];

    cond->pushRange(v, v, false, false, false, false);
  }
  else
  {
    for (ulong i = 0; i < low_key.size(); i++)
    {
      Item_t l = ints[low_key[i]];
      Item_t h = ints[high_key[i]];

      cond->pushRange(l, h, !low_inf[i], !high_inf[i], low_incl[i], high_incl[i]);
    }
  }

  try
  {
    std::cout << "Probing condition : " << cond->toString() << std::endl;

    ite->init(cond);
    ite->open();
 
    store::Item_t res;
    bool more = ite->next(res);
    while (more)
    {
      std::cout << res->getStringValue()->c_str() << std::endl;
      more = ite->next(res);
    }
  }
  catch(error::ZorbaError& e)
  {
    std::cout << e.theDescription << std::endl;
  }

  ite->close();
  delete ite;

  cond = NULL;
  
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
