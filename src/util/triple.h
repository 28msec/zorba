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
#ifndef ZORBA_TRIPLE_H
#define ZORBA_TRIPLE_H

namespace zorba {

template<class _T1, class _T2, class _T3>
class triple
{
public:
	_T1 first;            
	_T2 second;          
	_T3 third;          

public:
	triple() : first(), second(), third() { }

	triple(const _T1& _a, const _T2& _b, const _T3& _c)
	: first(_a), second(_b), third(_c) { }

	template<class _U1, class _U2, class _U3>
	triple(const triple<_U1, _U2, _U3>& _p)
	: first(_p.first), second(_p.second), third(_p.third) { }
};

template<class _T1, class _T2, class _T3>
inline bool operator==(
	const triple<_T1, _T2, _T3>& _x,
	const triple<_T1, _T2, _T3>& _y)
{
	return _x.first  == _y.first
			&& _x.second == _y.second
			&& _x.third  == _y.third;
}

template<class _T1, class _T2, class _T3>
inline bool operator<(
	const triple<_T1, _T2, _T3>& _x,
	const triple<_T1, _T2, _T3>& _y)
{
	return (_x.first < _y.first)
			|| ((_y.first == _x.first) && (_x.second < _y.second))
			|| ((_y.first == _x.first) && (_y.second == _x.second) && (_x.third < _y.third));
}

template<class _T1, class _T2, class _T3>
inline bool operator!=(
	const triple<_T1, _T2, _T3>& _x,
	const triple<_T1, _T2, _T3>& _y)
{
	return !(_x == _y);
}

template<class _T1, class _T2, class _T3>
inline bool operator>(
	const triple<_T1, _T2, _T3>& _x,
	const triple<_T1, _T2, _T3>& _y)
{
	return _y < _x;
}

template<class _T1, class _T2, class _T3>
inline bool operator<=(
	const triple<_T1, _T2, _T3>& _x,
	const triple<_T1, _T2, _T3>& _y)
{
	return !(_y < _x);
}

template<class _T1, class _T2, class _T3>
inline bool operator>=(
	const triple<_T1, _T2, _T3>& _x,
	const triple<_T1, _T2, _T3>& _y)
{
	return !(_x < _y);
}

template<class _T1, class _T2, class _T3>
inline triple<_T1, _T2, _T3>
make_triple(_T1 _x, _T2 _y, _T3 _z)
{
	return triple<_T1, _T2, _T3>(_x, _y, _z);
}

} /* namespace zorba */
#endif /* ZORBA_TRIPLE_H */

