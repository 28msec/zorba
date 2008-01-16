/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: signature.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: John Cowan,Paul Pedersen
 *
 */
 
#ifndef XQP_SIGNATURE_H
#define XQP_SIGNATURE_H

#include <string>
#include <vector>

#include "context/common.h"
#include "types/typesystem.h"
#include "store/api/item.h"

namespace xqp {

class context;
class Item;

#define VARIADIC_SIG_SIZE 100

/*******************************************************************************
  
  By convention, argv[0]    = return type
	               argv[1]    = first input argument type
                 argv[2]    = second input argument type
	                ...       =  ...  

********************************************************************************/
  class signature_base: public rcobject {
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
	Item_t qname_p;
	std::vector<TypeSystem::xqtref_t> argv;

public:
  signature (Item_t name, TypeSystem::xqtref_t arg1,
             bool variadic, TypeSystem::xqtref_t return_type);
	signature(Item_t name,
						TypeSystem::xqtref_t return_type);
	signature(Item_t name,
						TypeSystem::xqtref_t arg1,
						TypeSystem::xqtref_t return_type);
	signature(Item_t name,
						TypeSystem::xqtref_t arg1,
						TypeSystem::xqtref_t arg2,
						TypeSystem::xqtref_t return_type);
	signature(Item_t name,
						TypeSystem::xqtref_t arg1,
						TypeSystem::xqtref_t arg2,
						TypeSystem::xqtref_t arg3,
						TypeSystem::xqtref_t return_type);
	signature(Item_t name,
						TypeSystem::xqtref_t arg1,
						TypeSystem::xqtref_t arg2,
						TypeSystem::xqtref_t arg3,
						TypeSystem::xqtref_t arg4,
						TypeSystem::xqtref_t return_type);
	signature(Item_t name,
						const std::vector<TypeSystem::xqtref_t>& argv);
	~signature();

public:
	const Item_t& get_name() const            { return qname_p; }
	uint32_t arg_count() const {
    return is_variadic () ? VARIADIC_SIG_SIZE : argv.size() - 1;
  }

  TypeSystem::xqtref_t const& operator[](int i) const { return argv [variadic ? 1 : (i + 1)]; }
  TypeSystem::xqtref_t & operator[](int i)            { return argv [variadic ? 1 : (i + 1)]; }
  TypeSystem::xqtref_t const& return_type() const     { return argv [0]; }
  TypeSystem::xqtref_t & return_type()                { return argv [0]; }

};

} /* namespace xqp */
#endif  /* XQP_SIGNATURE_H */

