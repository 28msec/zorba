/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: spectrum_test.cpp,v 1.3 2006/11/01 17:56:20 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 Paul Pedersen.  All Rights Reserved.
 *
 *	Author: Paul Pedersen
 *
 */

#include "spectrum.h"

#include <stdlib.h>
#include <sys/time.h>
#include <iostream>
#include <sstream>

using namespace std;
using namespace xqp;

typedef std::vector<unsigned char> cvec_type;
typedef std::vector<unsigned char>::const_iterator cvec_iterator;
typedef std::vector<uint32_t> uvec_type;
typedef std::vector<uint32_t>::const_iterator uvec_iterator;

char alpha[] = { 'a','b','c','d','e','f',
								 'g','h','i','j','k','l',
								 'm','n','o','p','q','r',
								 's','t','u','v','w','x', 'y','z' };

char beta[]  = { 'A','B','C','D','E','F',
								 'G','H','I','J','K','L',
								 'M','N','O','P','Q','R',
								 'S','T','U','V','W','X', 'Y','Z' };

//logger log("blkdata");


int rnd(double scale)
{
	return (int)(scale*rand()/(RAND_MAX+1.0));
}

// a random string
void rnds(char* buf, int len)
{
	int sz = 1+rnd(len);
	for (int a=0; a<(sz-1); ++a) buf[a] = alpha[rnd(26)];
	buf[sz] = 0;
}

// a random char vector
void rndv(cvec_type& v, int len)
{
	int sz = 1+rnd(len);
	for (int a=0; a<(sz-1); ++a) v.push_back(alpha[rnd(26)]);
	v.push_back('\0');
}


void rnduv(uint32_t docid, vector<uint32_t>& v, int len)
{
	int sz = 1+rnd(len);
	v.push_back(docid);
	v.push_back(sz);
	for (int a=0; a<sz; ++a) v.push_back(rnd(100));
	for (int a=0; a<sz; ++a) v.push_back(rnd(10));
}


void rnduv(vector<uint32_t>& v, int len)
{
	int sz = 1+rnd(len);
	for (int a=0; a<sz; ++a) v.push_back(rnd(100));
	for (int a=0; a<sz; ++a) v.push_back(rnd(10));
}

string _timestamp()
{
  char buf[256];
  struct timeval tv;
  struct timezone tz;
  gettimeofday(&tv, &tz);
  size_t  sz = strftime(buf, 256, "%c", localtime(&tv.tv_sec));
  return string(buf, 0, sz);
}

int main(int argc, char* argv[])
{
	try {
		vector<blockid> idv;
		uint32_t docid = 1;

		// random insert,update,retrieve
		do {
			spectrum spec("specdata",6,28,12);
			//spec.setLogger(&log);
			for (uint32_t n=0; n<5000000; ++n) {
				if (n%10000==0) {
					cout << _timestamp() << endl;				
				}
				uint32_t r = rnd(10);
				switch (r) {

				// insert
				case 0: case 1: case 2: case 3: case 4: { 
					uvec_type uvec;
					for (uint32_t a=0; a<2000; ++a) {
						uvec_type uvec0;
						rnduv(docid++,uvec0,1<<(4+rnd(3)));	// random new value
						uvec.push_back(uvec0.size());
						for (uvec_iterator it = uvec0.begin(); it!=uvec0.end(); ++it) {
							uvec.push_back(*it);
						}
					}
	
					blockid id = spec.put((char *)&uvec.front(), 0, uvec.size() * 4);
					idv.push_back(id);
					break;
				}

				// update
				case 5: case 6: {	
					if (idv.size()==0) continue;	// nothing to update yet
	
					// pick a random id
					uint32_t k = rnd(idv.size());
					blockid id = idv[k];
					uvec_type uvec;			// new value
					for (uint32_t a=0; a<2000; ++a) {
						uvec_type uvec0;
						rnduv(docid++,uvec0,1<<(4+rnd(3)));	// random new value
						uvec.push_back(uvec0.size());
						for (uvec_iterator it = uvec0.begin(); it!=uvec0.end(); ++it) {
							uvec.push_back(*it);
						}
					}
	
					blockid new_id = spec.update(id,(char *)&uvec.front(),0,uvec.size() * 4);
					if (new_id!=id) {
						idv.erase(idv.begin()+k);
						idv.push_back(new_id);
					}
					break;
				}

				// retrieve
				case 7: case 8: case 9: case 10: {
					if (idv.size()==0) continue;	// nothing to retrieve yet
	
					// pick a random id
					uint32_t k = rnd(idv.size());
					blockid id = idv[k];
					cout << "--id = " << id << "\n";
	
					// pick up the old value
					char *buf = new char[1<<20];
					int n = spec.get(id, buf, 0, 1<<20);
					cout << "--output size = " << n << endl;
					if (n>0) {
						cout << string(buf,0,n) << endl;
					}
					break;
				}
				default: {
					cerr << "Logic error: illegal rnd() value = " << r << endl;
					continue;
				}
				}
			}
		} while (0);

	} catch (xqp_exception& e) {
		cerr << "Application exception: " << e.what() << '\t' << e.get_msg() << endl;
	} catch (exception& e) {
		cerr << "System exception: " << e.what() << endl;
	} catch (...) {
		cerr << "Unhandled exception\n";
	}
}

