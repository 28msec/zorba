

#ifndef XQP_STRING_RC_H
#define XQP_STRING_RC_H

#include "types/representations.h"

namespace xqp
{
	//Internal xqpString pool
	class StringTable {
	private:
		char** array;
		int* count;						//reference count array
		int size;								//maximum number of xqpStrings that can be stored
		int numStrings;		//number of xqpStrings

	public:
		StringTable(int tableSize);

	// this method adds a String to the pool and returns its index
	int addString(const char* ch);

	//this method return a char* to the the array of characters for the requested string
	char* getString(int index) const;

};
} /* namespace xqp */
#endif /* XQP_STRING_RC_H */
