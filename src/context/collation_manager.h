
#ifndef ZORBA_UNICODE_COLLATION_MANAGER_26_NOV_2007
#define ZORBA_UNICODE_COLLATION_MANAGER_26_NOV_2007

#include <unicode/coll.h>
#include <map>

namespace zorba{

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

  char  tempkey[200];
	std::map<std::string, COLL_ELEM*>		coll_map;

private:
	const char*		computeKey(const char*  coll_string,
													::Collator::ECollationStrength coll_strength);
public:
	~CollationManager();

	::Collator		*getCollation(const char*  coll_string,
														::Collator::ECollationStrength coll_strength);
	void					removeReference(const char*  coll_string,
															::Collator::ECollationStrength coll_strength);
	static const COLLATION_DESCR* getHardcodedCollator(const char* URI);
};



}//end namespace zorba

#endif
