/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: unicode_decomposer.cpp,v 1.1.1.1 2006/10/09 06:58:37 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR FOundation.
 *
 */

#include "unicode_decomposer.h"

using namespace std;
namespace xqp {

bool unicode_decomposer::codetab_init = false;
int unicode_decomposer::codetab[16384];

unicode_decomposer::~unicode_decomposer()
{
}

unicode_decomposer::unicode_decomposer()
:
decompositionMap(hashmap<vector<unsigned short> >(4096, .6))
{
	if (!codetab_init) populate_codetab(); 
}


void unicode_decomposer::populate_codetab()
{
	codetab_init = true;
	for (unsigned i=0; i<16384; ++i) unicode_decomposer::codetab[i] = -1;
  for (unsigned i=0; i<1428; ++i) {
		unsigned x = decompositions[i].codepoint;
    unsigned h = (x*0x811c9dc5) % 16384;
		codetab[h] = i;
  }
}


bool unicode_decomposer::decompose(
  unsigned codepoint,
  vector<unsigned short>& decomposition)
{
  unsigned x = (codepoint*0x811c9dc5) % 16384;
	int i = unicode_decomposer::codetab[x]; 
	if (i==-1) return false;
	unsigned short c = 0;
  unsigned j = 0;
	while (true) {
    c = decompositions[i].decomposition[j++];
		if (c==0) break;
    decomposition.push_back(c);
  }
	return true;
}

}	/* namespace xqp */
