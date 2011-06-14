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
#ifndef ZORBA_ANNOTATION_API_H
#define ZORBA_ANNOTATION_API_H

#include <zorba/config.h>
#include <zorba/api_shared_types.h>
#include <zorba/smart_ptr.h>

namespace zorba {

class ZORBA_DLL_PUBLIC Annotation : public SmartObject
{
 public:
  /** \brief Destructor
   */
  virtual ~Annotation() {}
  
  /**
   *  Returns the QName of the annotation
   */
  virtual Item
  getQName() const = 0;

  /**
   *  Returns the number of literals that are associated with the annotation,
   *  e.g. for the annotation:
   *
   *      %annotation(Literal1, Literal2, ..., LiteralN)
   *
   *  the function will return N.
   */
  virtual unsigned int
  getLiteralsCount() const = 0;
  
  /**
   *  Returns the requested literal. E.g. for the annotation
   *
   *      %annotation(Literal1, Literal2, ..., LiteralN)
   *
   *  the function will return the i-th literal.
   */
  virtual Item
  getLiteral(unsigned int i) const = 0;
};

} /* namespace zorba */
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */

/* vim:set et sw=2 ts=2: */
