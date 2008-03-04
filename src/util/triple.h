/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: triple.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_TRIPLE_H
#define XQP_TRIPLE_H

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
#endif /* XQP_TRIPLE_H */

