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

#include <cstddef>
#include "api/functionimpl.h"
#include "api/zorbaimpl.h"
#include "api/unmarshaller.h"

#include "functions/function.h"
#include "diagnostics/xquery_diagnostics.h"
#include "annotations/annotations.h"
#include "api/annotationimpl.h"

namespace zorba 
{

bool FunctionImpl::isUpdating() const
{
  return theFunction->isUpdating();
}


bool FunctionImpl::isPrivate() const
{
  return theFunction->isPrivate();
}


bool FunctionImpl::isDeterministic() const
{
  return theFunction->isDeterministic();
}


bool FunctionImpl::isSequential() const
{
  return theFunction->isSequential();
}


void FunctionImpl::getAnnotations(std::vector<Annotation_t>& annotations) const
{
  annotations.clear();

  const AnnotationList* ann_list = theFunction->getAnnotationList();
  if (ann_list == NULL)
    return;

  try
  {
    for (unsigned int i = 0; i < ann_list->size(); ++i)
      annotations.push_back(new AnnotationImpl(ann_list->getAnnotation(i)));
  }
  catch (ZorbaException const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
  }
}


Item FunctionImpl::getQName() const
{
  try 
  {
    return theFunction->getName();
  } 
  catch (ZorbaException const& e) 
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
  }
  return Item();
}


String FunctionImpl::getURI() const
{
  try 
  {
    return Unmarshaller::newString(theFunction->getName()->getNamespace());
  } 
  catch (ZorbaException const& e) 
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
  }
  return String();
}


String FunctionImpl::getLocalName() const
{
  try 
  {
    return Unmarshaller::newString(theFunction->getName()->getLocalName());
  } 
  catch (ZorbaException const& e) 
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
  }
  return String();
}


size_t FunctionImpl::getArity() const
{
  return theFunction->getArity();
}


bool FunctionImpl::isVariadic() const
{
  return theFunction->isVariadic();
}


bool FunctionImpl::isExternal() const
{
  return static_cast<function*>(theFunction)->isExternal();
}


bool FunctionImpl::isXQuery() const
{
  return static_cast<function*>(theFunction)->isUdf();
}


bool FunctionImpl::isBuiltin() const
{
  return static_cast<function*>(theFunction)->isBuiltin();
}


} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
