#pragma once

/*typedef struct{
	int 	quot;
	int 	rem;
} div_t ;*/

void wstrreverse(wchar_t* begin, wchar_t* end) ;
#ifndef WIN32
	void _itow(int value, wchar_t* str, int base) ;
#endif

