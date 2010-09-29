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

#include "annotation.h"
#include "store/api/item.h"
#include "system/globalenv.h"
#include "store/api/item_factory.h"


namespace zorba
{
SERIALIZABLE_CLASS_VERSIONS(Annotation)
END_SERIALIZABLE_CLASS_VERSIONS(Annotation)


SERIALIZABLE_CLASS_VERSIONS(AnnotationList)
END_SERIALIZABLE_CLASS_VERSIONS(AnnotationList)


Annotation::Annotation(const AnnotationParsenode* annotation)
{
  GENV_ITEMFACTORY->createQName(theQName,
    "",
    annotation->get_qname()->get_prefix()->c_str(),
    annotation->get_qname()->get_localname()->c_str());
}

store::Item* Annotation::getQName() const
{
  return theQName.getp();
}

void Annotation::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theQName;
}

AnnotationList::AnnotationList(const AnnotationListParsenode* annotations)
{
  if (annotations != NULL)
    for (unsigned int i=0; annotations != NULL && i<annotations->size(); i++)
      theAnnotationList.push_back(new Annotation(annotations->operator[](i)));
}

const Annotation* AnnotationList::getAnnotation(unsigned int index) const
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
