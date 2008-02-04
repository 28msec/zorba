
#ifndef ZORBA_UNICODE_COLLATION_MANAGER_26_NOV_2007
#define ZORBA_UNICODE_COLLATION_MANAGER_26_NOV_2007

//#include "zorba_api.h"
#include <unicode/coll.h>
#include <map>
#include <unicode/coll.h>
#include "types/representations.h"

namespace xqp{

/*
	CollationManager is specific for each thread.
	Manages all created collators within one thread.
*/
class CollationManager
{
public:
	typedef struct
	{
		const char *coll_uri;
		const char *coll_string;
		::Collator::ECollationStrength coll_strength;
	}COLLATION_DESCR;

public:
	static const COLLATION_DESCR		default_collations [];
private:
	typedef struct
	{
		int		refcount;
		::Collator		*coll;
	}COLL_ELEM;

	std::map<std::string, COLL_ELEM*>		coll_map;

private:
	std::string		computeKey(std::string  coll_string,
													::Collator::ECollationStrength coll_strength);
public:
	~CollationManager();

	::Collator		*getCollation(std::string  coll_string,
														::Collator::ECollationStrength coll_strength);
	void					removeReference(std::string  coll_string,
															::Collator::ECollationStrength coll_strength);
	static const COLLATION_DESCR* getHardcodedCollator(std::string URI);
};



}//end namespace xqp

#endif
