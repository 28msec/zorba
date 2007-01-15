/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *	$Id: storage_manager.h,v 1.3 2006/10/13 06:53:30 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 */

#ifndef XQP_STORAGE_MANAGER_H_
#define XQP_STORAGE_MANAGER_H_

#include <string>
#include "spectrum.h"


namespace xqp {
  

class storage_manager
{
protected:	// state
	std::string config_path;
	spectrum spec;

public:	// ctor,dtor

	storage_manager(const std::string& config_path);
	~storage_manager();

public:	// manipulators

	std::string get_config_path() const { return config_path; }


public:	// store interface

	int get(
		blockid id,
		char*	data_p);
		
	blockid put(
		const char* buf,
		uint32_t offset,
		uint32_t length);

};


}	/* namespace xqp */
#endif	/* XQP_STORAGE_MANAGER_H_ */



