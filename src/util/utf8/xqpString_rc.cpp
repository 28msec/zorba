#include "xqpString_rc.h"

namespace xqp
{
	/*start class stringTable */
	 StringTable::StringTable (int tableSize){
			size = tableSize;
			array = new char*[size];
			count = new int[size];
			numStrings = 0;
		}

	int StringTable::addString(const char* ch){
		if (0 == numStrings) {// if there is no string in the pool, add first
			array[0] = new char[strlen(ch)+1];
			strcpy(array[0], ch);
			numStrings++;
			return 0;
		}

		// if there are strings in the pool
		int i = 0;
		for (i; i < numStrings; i++) {// compares, if the String is already in the pool
			if (strcmp(ch, array[i]) == 0) {
				count[i]++;//if found increment the reference count and return the index
				return i;
			}
		}

		if (i == size) {
			return -1;
		}

		// if not, add String to the pool and return its index
		array[i] = new char[strlen(ch)+1];
		strcpy(array[i], ch);
		numStrings++;
		return numStrings-1;
	}

	char* StringTable::getString(int index) const {
		return array[index];
	}
/*end class stringTable */
}
