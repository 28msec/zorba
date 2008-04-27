/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef ZORBA_SORTER_H
#define ZORBA_SORTER_H

#include <utility>
#include <iostream>
#include <vector>

namespace zorba {

/*______________________________________________________________________
|  Template sorting:                                                    |
|                                                                       |
|  quicksort implemetation uses median-of-three pivot                   |
|  See, (e.g.) Section 8.1 in 'Algorithms':                             |
|  Cormen, Leiserson, Rivest, McGraw Hill (1992)                        |
|                                                                       |
|  The template parameter class T is assumed to satisfy:                |
|    (1) operator< is defined and used for ordering                     |
|    (2) the public field 'key' is defined                              |
|                                                                       |
|_______________________________________________________________________*/


template<class T>
void isort(
	vector<T>& v,
	uint32_t low,
	uint32_t high,
	bool ascending = false)
{
  for (uint32_t i=low+1; i<=high; ++i) {
		if (ascending) {
    	for (uint32_t j=i; j>low && v[j].key < v[j-1].key; --j) {
      	swap(v[j], v[j-1]);
			}
		}
		else {
    	for (uint32_t j=i; j>low && v[j].key > v[j-1].key; --j) {
      	swap(v[j], v[j-1]);
			}
		}
	}
}


template<class T>
T pivot(
	vector<T>& v,
	uint32_t low,
	uint32_t high)
{
  uint32_t i = (low+high)/2;
  if (v[i].key    < v[low].key) swap(v[low], v[i]);
  if (v[high].key < v[low].key) swap(v[low], v[high]);
  if (v[high].key < v[i].key)   swap(v[i],   v[high]);
	return v[i];
}


template<class T>
void qsort(
	vector<T>& v,
	uint32_t low,
	uint32_t high,
	bool ascending = false)
{
	if (v.size()==0) return;
  if ((high-low)<8) {
		isort(v, low, high, ascending);
		return;
	}
  T u = pivot(v, low, high);

  // divide
  uint32_t i = low-1;
  uint32_t j = high+1;
  for (;;) {
		if (ascending) {
    	do { ++i; } while (v[i].key < u.key);
		}
		else {	/* descending */
    	do { ++i; } while (v[i].key > u.key);
		}
		if (ascending) {
    	do { --j; } while (u.key < v[j].key);
		}
		else {	/* descending */ 
    	do { --j; } while (u.key > v[j].key);
		}

    if (j<=i) break;
    swap(v[i], v[j]);
  }

	// and conquer
  swap(v[i], v[high]);
  qsort(v,low, j, ascending);
  qsort(v, j+1, high, ascending);

}

}	/* namespace zorba */
#endif	/* ZORBA_SORTER_H */

