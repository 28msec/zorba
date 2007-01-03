/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: mangle_test.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "function_impl.h"

#include <iostream>
#include <string>
#include <vector>

#include "../types/builtin_types.h"
#include "../types/qname.h"
#include "../util/rchandle.h"
#include "../util/tokenbuf.h"

using namespace std;
namespace xqp {


string function_impl::decode_type(static_type_t t)
{
  switch (t) {
  case xs_string:             return "st";
  case xs_boolean:            return "bo";
  case xs_decimal:            return "de";
  case xs_float:              return "fl";
  case xs_double:             return "do";
  case xs_duration:           return "du";
  case xs_dateTime:           return "dt";
  case xs_time:               return "ti";
  case xs_date:               return "da";
  case xs_gYearMonth:         return "ym";
  case xs_gYear:              return "gy";
  case xs_gMonthDay:          return "md";
  case xs_gDay:               return "gd";
  case xs_gMonth:             return "gm";
  case xs_hexBinary:          return "hx";
  case xs_base64Binary:       return "64";
  case xs_anyURI:             return "au";
  case xs_QName:              return "qn";
  case xs_NOTATION:           return "no";
  case xs_untyped:            return "un";
  case xs_untypedAtomic:      return "ua";
  case xs_anyAtomicType:      return "aa";
  case xs_dayTimeDuration:    return "dd";
  case xs_yearMonthDuration:  return "yd";
  default:                    return "??";
  }
}

static_type_t function_impl::encode_type(string const& s)
{
  if (s=="st") return xs_string;
  if (s=="bo") return xs_boolean;
  if (s=="de") return xs_decimal;
  if (s=="fl") return xs_float;
  if (s=="do") return xs_double;
  if (s=="du") return xs_duration;
  if (s=="dt") return xs_dateTime;
  if (s=="ti") return xs_time;
  if (s=="da") return xs_date;
  if (s=="ym") return xs_gYearMonth;
  if (s=="gy") return xs_gYear;
  if (s=="md") return xs_gMonthDay;
  if (s=="gd") return xs_gDay;
  if (s=="gm") return xs_gMonth;
  if (s=="hx") return xs_hexBinary;
  if (s=="64") return xs_base64Binary;
  if (s=="au") return xs_anyURI;
  if (s=="qn") return xs_QName;
  if (s=="no") return xs_NOTATION;
  if (s=="un") return xs_untyped;
  if (s=="ua") return xs_untypedAtomic;
  if (s=="aa") return xs_anyAtomicType;
  if (s=="dd") return xs_dayTimeDuration;
  if (s=="yd") return xs_yearMonthDuration;
  return xs_string;
}

string function_impl::mangle(signature const& sig)
{
  ostringstream oss;
  sig.fname.put(oss) << '(';
  std::vector<static_type_t>::const_iterator it = sig.arg_v.begin();
  for (; it!=sig.arg_v.end(); ++it) {
    if (it!=sig.arg_v.begin()) oss << ',';
    oss << decode_type(*it);
  }
  oss << ')' << decode_type(sig.ret_type);
  return oss.str();
}


rchandle<signature> function_impl::demangle(string const& sig)
{
  enum demangle_state {
    prefix,
    name,
    nsuri,
    argv,
    retyp,
    exit
  };
  
  tokenbuf tokbuf(sig.c_str(),",([]):");
  tokenbuf::token_iterator it = tokbuf.begin();
	tokenbuf::token_iterator end = tokbuf.end();
	
	string fprefix;
	string fname;
	string uri;
	rchandle<signature> sig_h;
	
	for (uint32_t state = prefix; it!=end && state!=exit; ++it) {
  	string const& term  = *it;
  	cout << "term = " << term << endl;
  	switch (state) {
    	case prefix: {
      	fprefix = term;
      	state = name;
      	break;
    	}
    	case name: {
      	fname = term;
      	state = nsuri;
      	break;
    	}
    	case nsuri: {
      	uri = term;
      	sig_h = new signature(QName(QName::qn_func,fprefix,fname));
      	state = argv;
      	break;
    	}
    	case argv: {
      	sig_h->arg_v.push_back(encode_type(term));
      	if (it.get_delim()==")") { state = retyp; }
      	break;
    	}
    	case retyp: {
      	sig_h->ret_type = encode_type(term);
      	state = exit;
      	break;
    	}
    	default: {
      	cout << "Logic error: unrecognized state: " << state << endl;
      	break;
    	}
  	}
  }
  return sig_h;
}

} /* namespace xqp */
