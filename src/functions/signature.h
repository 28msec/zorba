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
#ifndef ZORBA_SIGNATURE_H
#define ZORBA_SIGNATURE_H

#include "zorbautils/checked_vector.h"

#include "common/shared_types.h"

#include "types/root_typemanager.h"
#include "store/api/item.h"

namespace zorba {

#define VARIADIC_SIG_SIZE 100

/*******************************************************************************
  
  By convention, argv[0]    = return type
                 argv[1]    = first input argument type
                 argv[2]    = second input argument type
                  ...       =  ...  

********************************************************************************/
  class signature_base: public SimpleRCObject {
  protected:
    bool variadic;
  public:
    signature_base () : variadic (false) {}
    signature_base (bool _variadic) : variadic (_variadic) {}
    bool is_variadic () const { return variadic; }
  };

class signature : public signature_base
{
public:
  store::Item_t            qname_p;
  checked_vector<xqtref_t> argv;

public:
  signature (store::Item_t name, xqtref_t arg1,
             bool variadic, xqtref_t return_type);
  signature(store::Item_t name,
            xqtref_t return_type);
  signature(store::Item_t name,
            xqtref_t arg1,
            xqtref_t return_type);
  signature(store::Item_t name,
            xqtref_t arg1,
            xqtref_t arg2,
            xqtref_t return_type);
  signature(store::Item_t name,
            xqtref_t arg1,
            xqtref_t arg2,
            xqtref_t arg3,
            xqtref_t return_type);
  signature(store::Item_t name,
            xqtref_t arg1,
            xqtref_t arg2,
            xqtref_t arg3,
            xqtref_t arg4,
            xqtref_t return_type);
  signature(store::Item_t name,
            const std::vector<xqtref_t>& argv,
            xqtref_t return_type);
  ~signature();

public:
  const store::Item_t& get_name() const            { return qname_p; }
  uint32_t arg_count() const {
    return is_variadic () ? VARIADIC_SIG_SIZE : argv.size() - 1;
  }

  xqtref_t const& operator[](int i) const { return argv [variadic ? 1 : (i + 1)]; }
  xqtref_t & operator[](int i)            { return argv [variadic ? 1 : (i + 1)]; }
  xqtref_t const& return_type() const     { return argv [0]; }
  xqtref_t & return_type()                { return argv [0]; }

};

} /* namespace zorba */
#endif  /* ZORBA_SIGNATURE_H */

