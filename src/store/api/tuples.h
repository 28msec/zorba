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
#ifndef ZORBA_STORE_TUPLES_H
#define ZORBA_STORE_TUPLES_H

#include <zorba/config.h>
#include "common/shared_types.h"
#include "store/api/item.h"
#include "store/api/temp_seq.h"
#include "diagnostics/assert.h"

#include "zorbaserialization/serialization_engine.h"


namespace zorba {

namespace store {

/*******************************************************************************

  Stores a pointer that is a pointer to either a single item or a temp sequence

 *******************************************************************************/
class TupleField : public ::zorba::serialization::SerializeBaseClass
{
 public:
  typedef enum 
  {
    UNINITIALIZED,
    FIELD_TYPE_ITEM,
    FIELD_TYPE_SEQ,
  } tag_t;

public:
  TupleField();

  virtual ~TupleField();

  TupleField(const TupleField&);

  const TupleField& operator=(const TupleField&);

  tag_t getTag() const;

  void get(Item_t& item) const;
  void set(Item *item);

  void get(TempSeq_t& seq) const;
  void set(TempSeq *seq);

  void reset();

private:
  tag_t m_tag;
  void *m_data;

public:
  SERIALIZABLE_CLASS(TupleField)
  SERIALIZABLE_CLASS_CONSTRUCTOR(TupleField)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    SERIALIZE_ENUM(tag_t, m_tag)
    switch(m_tag)
    {
      case UNINITIALIZED:
        if(m_data)
        {
					throw ZORBA_EXCEPTION(
						zerr::ZCSE0010_ITEM_TYPE_NOT_SERIALIZABLE,
						ERROR_PARAMS( "TupleField" )
					);
        }
        if(!ar.is_serializing_out())
          m_data = NULL;
        break;
      case FIELD_TYPE_ITEM:
      {
        Item *ip = static_cast<Item *>(m_data);
        ar.set_is_temp_field_one_level(true);
        ar & ip;
        ar.set_is_temp_field_one_level(false);
        if(!ar.is_serializing_out())
        {
          m_data = (void*)ip;
          ip->addReference(ip->getSharedRefCounter() SYNC_PARAM2(ip->getRCLock()));
        }
      }break;
      case FIELD_TYPE_SEQ:
      {
        TempSeq *seq = static_cast<TempSeq *>(m_data);
        ar.set_is_temp_field_one_level(true);
        ar & seq;
        ar.set_is_temp_field_one_level(false);
        if(!ar.is_serializing_out())
        {
          m_data = (void*)seq;
          seq->addReference(seq->getSharedRefCounter() SYNC_PARAM2(seq->getRCLock()));
        }
      }break;
    }
  }
};


inline TupleField::TupleField()
  :
  m_tag(UNINITIALIZED),
  m_data(NULL)
{
}


inline TupleField::~TupleField()
{
  reset();
}


inline TupleField::TupleField(const TupleField& other) : ::zorba::serialization::SerializeBaseClass()
{
  switch(other.getTag()) 
  {
    case UNINITIALIZED:
      m_tag = UNINITIALIZED;
      m_data = NULL;
      break;

    case FIELD_TYPE_ITEM:
    {
      m_tag = FIELD_TYPE_ITEM;
      m_data = other.m_data;
      Item *ip = static_cast<Item *>(m_data);
      ip->addReference(ip->getSharedRefCounter() SYNC_PARAM2(ip->getRCLock()));
      break;
    }

    case FIELD_TYPE_SEQ:
    {
      m_tag = FIELD_TYPE_SEQ;
      m_data = other.m_data;
      TempSeq *tp = static_cast<TempSeq *>(m_data);
      tp->addReference(tp->getSharedRefCounter() SYNC_PARAM2(tp->getRCLock()));
      break;
    }

    default:
      ZORBA_ASSERT(false);
  }
}


inline const TupleField& TupleField::operator=(const TupleField& other)
{
  if (this != &other) 
  {
    switch(other.getTag()) 
    {
      case UNINITIALIZED:
        m_tag = UNINITIALIZED;
        m_data = NULL;
        break;

      case FIELD_TYPE_ITEM:
      {
        m_tag = FIELD_TYPE_ITEM;
        m_data = other.m_data;
        Item *ip = static_cast<Item *>(m_data);
        ip->addReference(ip->getSharedRefCounter() SYNC_PARAM2(ip->getRCLock()));
        break;
      }

      case FIELD_TYPE_SEQ:
      {
        m_tag = FIELD_TYPE_SEQ;
        m_data = other.m_data;
        TempSeq *tp = static_cast<TempSeq *>(m_data);
        tp->addReference(tp->getSharedRefCounter() SYNC_PARAM2(tp->getRCLock()));
        break;
      }

      default:
        ZORBA_ASSERT(false);
    }
  }
  return *this;
}


inline TupleField::tag_t TupleField::getTag() const
{
  return m_tag;
}


inline void TupleField::get(Item_t& item) const
{
  ZORBA_ASSERT(m_tag == FIELD_TYPE_ITEM || m_tag == UNINITIALIZED);
  Item *ip = static_cast<Item *>(m_data);
  item = ip;
}


inline void TupleField::set(Item *item)
{
  if (m_data == item) 
  {
    return;
  }

  reset();

  if (item != NULL) 
  {
    m_tag = FIELD_TYPE_ITEM;
    m_data = item;
    item->addReference(item->getSharedRefCounter() SYNC_PARAM2(item->getRCLock()));
  }
}

inline void TupleField::get(TempSeq_t& seq) const
{
  ZORBA_ASSERT(m_tag == FIELD_TYPE_SEQ || m_tag == UNINITIALIZED);
  TempSeq *seqp = static_cast<TempSeq *>(m_data);
  seq = seqp;
}


inline void TupleField::set(TempSeq *seq)
{
  if (m_data == seq) 
  {
    return;
  }

  reset();

  if (seq != NULL) 
  {
    m_tag = FIELD_TYPE_SEQ;
    m_data = seq;
    seq->addReference(seq->getSharedRefCounter() SYNC_PARAM2(seq->getRCLock()));
  }
}


inline void TupleField::reset()
{
  if (m_data == NULL) 
  {
    return;
  }
  ZORBA_ASSERT(m_tag != UNINITIALIZED);

  switch(m_tag) 
  {
    case FIELD_TYPE_ITEM:
    {
      Item *ip = static_cast<Item *>(m_data);
      ip->removeReference(ip->getSharedRefCounter() SYNC_PARAM2(ip->getRCLock()));
      break;
    }

    case FIELD_TYPE_SEQ:
    {
      TempSeq *seqp = static_cast<TempSeq *>(m_data);
      seqp->removeReference(seqp->getSharedRefCounter() SYNC_PARAM2(seqp->getRCLock()));
      break;
    }

    default:
      ZORBA_ASSERT(false);
  }

  m_tag = UNINITIALIZED;
  m_data = NULL;
}

}

}

#endif /* ZORBA_STORE_TUPLES_H */
/* vim:set et sw=2 ts=2: */
