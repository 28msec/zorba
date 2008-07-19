/**
	
 * Ansi C "itoa" based on Kernighan & Ritchie's "Ansi C"
	
 * with slight modification to optimize for specific architecture:
	
 */
#ifndef WIN32
#include "itow.h"
#include "stdlib.h"

void wstrreverse(wchar_t* begin, wchar_t* end) {
	
	char aux;
	
	while(end>begin)
	
		aux=*end, *end--=*begin, *begin++=aux;
	
}
	

void _itow(int value, wchar_t* str, int base) {
	
	static wchar_t num[] = L"0123456789abcdefghijklmnopqrstuvwxyz";
	
	wchar_t* wstr=str;
	
	int sign;
	
	div_t res;
	

	
	// Validate base
	
	if (base<2 || base>35){ *wstr=L'\0'; return; }
	

	
	// Take care of sign
	
	if ((sign=value) < 0) value = -value;
	

	
	// Conversion. Number is reversed.
	
	do {
	
		res = div(value,base);
	
		*wstr++ = num[res.rem];
	
	}while(value=res.quot);
	
	if(sign<0) *wstr++='-';
	
	*wstr=L'\0';
	

	
	// Reverse string
	
	wstrreverse(str,wstr-1);
	
}

#endif