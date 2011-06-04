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
#include "stdafx.h"

#include <zorba/item.h>

#include "annotation.h"
#include "store/api/item.h"
#include "system/globalenv.h"
#include "store/api/item_factory.h"
#include "diagnostics/assert.h"
#include "compiler/parser/parse_constants.h"
#include "zorbaserialization/serialization_engine.h"


namespace zorba
{
SERIALIZABLE_CLASS_VERSIONS(AnnotationLiteral)
END_SERIALIZABLE_CLASS_VERSIONS(AnnotationLiteral)

SERIALIZABLE_CLASS_VERSIONS(AnnotationInternal)
END_SERIALIZABLE_CLASS_VERSIONS(AnnotationInternal)

SERIALIZABLE_CLASS_VERSIONS(AnnotationList)
END_SERIALIZABLE_CLASS_VERSIONS(AnnotationList);

/*******************************************************************************

********************************************************************************/
AnnotationImpl::AnnotationImpl(const AnnotationInternal* annotation)
{
  theQName = annotation->getQName();

  for (unsigned int i=0; i<annotation->getLiteralsCount(); i++)
    theLiteralList.push_back(new AnnotationLiteral(annotation->getLiteral(i)));
}


Item AnnotationImpl::getQName() const
{
  Item lQName(theQName);
  return lQName;
}


unsigned int AnnotationImpl::getLiteralsCount() const
{
  return (unsigned int)theLiteralList.size();
}


Item AnnotationImpl::getLiteral(unsigned int i) const
{
  if (i >= theLiteralList.size())
    return Item(NULL);

  Item lItem(theLiteralList[i]->getLiteral());
  return lItem;
}


/*******************************************************************************

********************************************************************************/
AnnotationLiteral::AnnotationLiteral(const AnnotationLiteral* literal)
{
  if (literal != NULL)
    theLiteral = literal->getLiteral();
}

AnnotationLiteral::AnnotationLiteral(const StringLiteral* stringLiteral)
{
  ZORBA_ASSERT(stringLiteral != NULL);

  zstring temp = stringLiteral->get_strval();
  GENV_ITEMFACTORY->createString(theLiteral, temp);
}

AnnotationLiteral::AnnotationLiteral(const NumericLiteral* numericLiteral)
{
  ZORBA_ASSERT(numericLiteral != NULL);

  switch (numericLiteral->get_type())
  {
  case ParseConstants::num_integer:
    GENV_ITEMFACTORY->createInteger(theLiteral, numericLiteral->get<xs_integer>());
    break;

  case ParseConstants::num_decimal:
    GENV_ITEMFACTORY->createDecimal(theLiteral, numericLiteral->get<xs_decimal>());
    break;

  case ParseConstants::num_double:
    GENV_ITEMFACTORY->createDouble(theLiteral, numericLiteral->get<xs_double>());
    break;
  }
}

store::Item_t AnnotationLiteral::getLiteral() const
{
  return theLiteral;
}

void AnnotationLiteral::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theLiteral;
}


/*******************************************************************************

********************************************************************************/
AnnotationInternal::AnnotationInternal(const AnnotationParsenode* annotation)
{
  GENV_ITEMFACTORY->createQName(theQName,
                                zstring(),
                                annotation->get_qname()->get_prefix(),
                                annotation->get_qname()->get_localname());

  if (annotation->get_literals() != NULL)
  {
    for (unsigned int i=0; i<annotation->get_literals()->size(); i++)
    {
      exprnode* node = annotation->get_literals()->operator[](i).getp();

      StringLiteral* str = dynamic_cast<StringLiteral*>(node);
      if (str != NULL)
      {
        theLiteralList.push_back(new AnnotationLiteral(str));
        continue;
      }

      NumericLiteral* num = dynamic_cast<NumericLiteral*>(node);
      if (num != NULL)
      {
        theLiteralList.push_back(new AnnotationLiteral(num));
        continue;
      }
    }
  }
  else
  {
    rchandle<AnnotationLiteral> literal_h = new AnnotationLiteral((AnnotationLiteral*)NULL);
    GENV_ITEMFACTORY->createBoolean(literal_h->theLiteral, true);
    theLiteralList.push_back(literal_h);
  }
}


const store::Item* AnnotationInternal::getQName() const
{
  return theQName.getp();
}


unsigned int AnnotationInternal::getLiteralsCount() const
{
  return (unsigned int)theLiteralList.size();
}


const AnnotationLiteral* AnnotationInternal::getLiteral(unsigned int index) const
{
  if (index < theLiteralList.size())
    return theLiteralList[index];
  else
    return NULL;
}

void AnnotationInternal::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theQName;
  ar & theLiteralList;
}


/*******************************************************************************

********************************************************************************/
AnnotationList::AnnotationList(const AnnotationListParsenode* annotations)
{
  if (annotations != NULL)
  {
    for (unsigned int i = 0; i < annotations->size(); ++i)
    {
      if ((*annotations)[i] != NULL)
        theAnnotationList.push_back(new AnnotationInternal((*annotations)[i]));
    }
  }
}


const AnnotationInternal* AnnotationList::getAnnotation(unsigned int index) const
{
  if (index < theAnnotationList.size())
    return theAnnotationList[index];
  else
    return NULL;
}


void AnnotationList::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theAnnotationList;
}


} /* namespace zorba */
