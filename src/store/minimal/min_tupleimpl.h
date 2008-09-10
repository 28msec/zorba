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
#ifndef ZORBA_STORE_TUPLEIMPL_H
#define ZORBA_STORE_TUPLEIMPL_H

#include <vector>
#include "store/api/tuples.h"
#include "store/api/item.h"

namespace zorba {

namespace storeminimal {

class TupleItem : public store::Item 
{
#ifdef ZORBA_FOR_ONE_THREAD_ONLY

 public:
   TupleItem(std::vector<zorba::store::TupleField>& fields)
     :
     store::Item(),
     m_fields(fields) { }

#else

  protected:
    SYNC_CODE(RCLock theRCLock;)

public:
    TupleItem(std::vector<zorba::store::TupleField>& fields)
      :
      store::Item(),
      m_fields(fields)
    {
      theRCLockPtr = &theRCLock; 
    }

#endif

  virtual ~TupleItem() { }

  bool isNode() const   { return false; }
  bool isAtomic() const { return false; }
  bool isPul() const    { return false; }
  bool isTuple() const  { return true; }

  virtual const std::vector<zorba::store::TupleField>& getTupleFields() const
  {
    return m_fields;
  }

  virtual int getTupleFieldCount() const
  {
    return m_fields.size();
  }

  virtual const zorba::store::TupleField& getTupleField(int index) const
  {
    return m_fields[index - 1];
  }

  store::Item* getType() const;

 private:
  std::vector<zorba::store::TupleField> m_fields;
};

}

}

#endif /* ZORBA_STORE_TUPLEIMPL_H */
/* vim:set ts=2 sw=2: */
