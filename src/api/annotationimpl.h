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
#pragma once
#ifndef ZORBA_API_ANNOTATION_IMPL
#define ZORBA_API_ANNOTATION_IMPL

#include <vector>
#include <zorba/annotation.h>

#include "common/shared_types.h"

namespace zorba
{

class AnnotationInternal;
typedef rchandle<AnnotationInternal> AnnotationInternal_t;


/*******************************************************************************
  AnnotationImpl

  the class backing up the Annotation class from the Zorba API
********************************************************************************/
class AnnotationImpl : public Annotation
{
protected:
  
  AnnotationInternal_t  theAnnotation;

public:
  AnnotationImpl(AnnotationInternal* ann);

  ~AnnotationImpl();

  Item getQName() const;

  unsigned int getLiteralsCount() const; 

  Item getLiteral(unsigned int i) const;
};

} /* namespace zorba */
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
