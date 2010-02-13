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
#ifndef ZORBA_DECIMAL_FORMAT_H
#define ZORBA_DECIMAL_FORMAT_H

#include <vector>
#include "common/shared_types.h"

namespace zorba 
{

class DecimalFormat : public SimpleRCObject
{
public:
  typedef std::vector<std::pair<std::string, std::string> > param_vector_type;

protected:
  bool              theIsDefault;
  store::Item_t     theName;
  param_vector_type theParams;

public:  
  DecimalFormat(
        bool isDefault,
        const store::Item_t& qname,
        const param_vector_type& params);

  bool isDefault() const { return theIsDefault; }

  const store::Item* getName() const { return theName.getp(); }

  const param_vector_type* getParamVector() const { return &theParams; }
};


typedef rchandle<DecimalFormat> DecimalFormat_t;

} /* namespace zorba */
#endif /* ZORBA_DECIMAL_FORMAT_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
