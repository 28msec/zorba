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

#include "api/annotationimpl.h"
#include "annotations/annotations.h"

namespace zorba
{

/*******************************************************************************

********************************************************************************/
AnnotationImpl::AnnotationImpl(AnnotationInternal* ann) 
  : theAnnotation(ann)
{
}

AnnotationImpl::~AnnotationImpl() {};

Item AnnotationImpl::getQName() const
{
  return theAnnotation->getQName();
}


unsigned int AnnotationImpl::getLiteralsCount() const 
{
  return theAnnotation->getNumLiterals();
}


Item AnnotationImpl::getLiteral(unsigned int i) const
{
  if (i >= theAnnotation->getNumLiterals())
    return Item(NULL);

  Item lItem(theAnnotation->getLiteral(i));
  return lItem;
}


} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
