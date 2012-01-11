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


#include <zorba/zorba.h>
#include <zorba/store_manager.h>

#include "diagnostics/errors.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/iterator_factory.h"
#include "store/api/index.h"

#include "store/naive/simple_store.h"
#include "store/naive/store_defs.h"

using namespace zorba;
using namespace zorba::store;


long theIndex1[][2] = 
{
  { 30, 86 },
  { 40,  4 },
  { 40, 14 },
  { 50, 59 },
  { 52, 10 },
  { 52, 20 },
  { 52, 30 },
  { 52, 30 }
};

ulong theNumIndexEntries = 8;


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


/*******************************************************************************

  usage ::= "test_index" LowKey? HighKey?
        
  LowKey ::= "-lk" NumColumns (ColumnSpec)+

  HighKey ::= "-hk" NumColumns (ColumnSpec)+

  NumColumns ::= any non-negative number

  ColumnSpec ::= (Value | "inf") ("t" | "f")

  Value ::= any integer value

  Note1: The number of ColumnSpecs in LowKey or HighKey spec must be equal to
         the NumColumns in that spec.

  Note2: The "t" and "f" flags in a ColumnSpec indicate whether the Value is
         to be included in the range or not.

  Examples:

  test_index
  test_index -lk 1 40 t -hk 1 50 f
  test_index -lk 1 40 t
  test_index -lk 1 40 f -hk 2 50 f 10 t

********************************************************************************/
int main(int argc, const char * argv[])
{
  //
  // Store initialization
  //
  simplestore::SimpleStore* store = StoreManager::getStore();

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
  ulong numColumns = 2;

  IndexSpecification spec(numColumns);
  spec.theIsUnique = false;
  spec.theIsSorted = true;
  spec.theIsTemp = false;
  spec.theIsThreadSafe = false;
  spec.theTimezone = 0;

  spec.theKeyTypes[0] = store->theSchemaTypeNames[simplestore::XS_INT];
  spec.theKeyTypes[0] = store->theSchemaTypeNames[simplestore::XS_INT];
  spec.theValueType = store->theSchemaTypeNames[simplestore::XS_STRING];

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
  IndexKey key(numColumns);
  Item_t value;

  for (ulong i = 0; i < theNumIndexEntries; i++)
  {
    std::ostringstream str;

    for (ulong j = 0; j < numColumns; j++)
    {
      key[j] = ints[theIndex1[i][j]];

      str << theIndex1[i][j] << " ";
    }

    xqpStringStore_t valuestr = new xqpStringStore(str.str());

    f->createString(value, valuestr);

    index->insert(key, value);
  }

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

